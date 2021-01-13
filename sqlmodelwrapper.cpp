#include "sqlmodelwrapper.h"
#include <QtSql>
#include <QJsonObject>
#include <QJsonDocument>
#include <QApplication>
#include <QMessageBox>

QString createTableFileName(const QString& tableName)
{
    QString dirPath = QApplication::applicationDirPath() + "/TableFiles";
    if(!QDir(dirPath).exists())
    {
        QDir().mkpath(dirPath);
    }

    auto date = QDateTime::currentDateTime();

    return dirPath  + "/" + QString(tableName+"_Table_File-%1.txt").arg(date.toString("dd-MM-yyyy-_hh-mm-ss"));
}

SqlModelWrapper::SqlModelWrapper(QObject* parent):
    QAbstractTableModel(parent)
{

}

QVariant SqlModelWrapper::data(const QModelIndex &index, int nRole) const
{
    if(!index.isValid())
    {
        return QVariant();
    }


    return (nRole == Qt::EditRole || nRole == Qt::DisplayRole)? rows.at(index.row()).at(index.column()) :QVariant();
}

bool SqlModelWrapper::setData(const QModelIndex &index, const QVariant &value, int nRole)
{
    if(index.isValid() && nRole == Qt::EditRole)
    {
        rows[index.row()][index.column()] = value;
        emit dataChanged(index, index);
        changed.insert({rows[index.row()][idField].toInt(), index.column()});
        return true;
    }
    return false;
}

int SqlModelWrapper::rowCount(const QModelIndex &) const
{
    return rows.size();
}

int SqlModelWrapper::columnCount(const QModelIndex &) const
{
    return fieldNames.size();
}

Qt::ItemFlags SqlModelWrapper::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(!index.isValid())
    {
        return flags;
    }

    if(!fieldNames.at(index.column()).contains("id"))
    {
        return (flags | Qt::ItemIsEditable);
    }
    return flags;
}

QVariant SqlModelWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    return (orientation == Qt::Horizontal) ? fieldNames.at(section) : QString::number(section);
}

bool SqlModelWrapper::removeRow(int row, const QModelIndex &parent)
{
    Q_UNUSED(parent)
    qDebug() << "Попытка удалить столбец " << row;
    int idNum = 0;
    for(int i = 0; i < fieldNames.size(); ++i)
    {
        if(fieldNames.at(i).contains("id"))
        {
            idNum = i;
            break;
        }
    }
    beginRemoveRows(QModelIndex(),row,row);
    deleted.insert(rows.at(row).at(idNum).toInt());
    rows.remove(row);
    endRemoveRows();
    qDebug() << "Удален столбец " << row;
    return true;
}

bool SqlModelWrapper::insertRow(int row, const QModelIndex &aparent)
{
    Q_UNUSED(aparent)
    QVariantList varList;
    beginInsertRows(QModelIndex(),row, row);
    for(int i = 0; i < fieldNames.size();++i)
    {
        varList.append(QVariant());
    }
    varList[idField] = createdCurrent;
    created.insert(createdCurrent--);
    rows.append(std::move(varList));
    endInsertRows();
    qDebug() << "Добавлен новый столбец " << row;
    return true;
}

void SqlModelWrapper::slot_query(const QString &queryStr)
{

    int oldSize = rows.size();

    bool removeRows = !rows.isEmpty();

    if(removeRows)
    {
        beginRemoveRows(QModelIndex(),0,oldSize-1);

        isNewTable = false;
        rows.clear();
        fieldNames.clear();
        changed.clear();
        deleted.clear();
        created.clear();
        createdCurrent = -1;

        endRemoveRows();
    }

    QSqlQuery query;
    if(query.exec(queryStr))
    {
        qDebug() << "Количество полученных записей = " << query.size();
        beginInsertRows(QModelIndex(), 0, query.size());
        QSqlRecord rec = query.record();
        const int countFields = rec.count();
        for(int i = 0; i < countFields; ++i)
        {
            fieldNames.append(rec.fieldName(i));
        }

        while(query.next())
        {
            QVariantList varList;
            varList.reserve(countFields);
            for(int i = 0; i < countFields; ++i)
            {
                varList.append(query.value(i));
            }
            rows.append(std::move(varList));
        }
        endInsertRows();
        emit  headerDataChanged(Qt::Horizontal, 0, countFields-1);

        for(int i = 0; i < fieldNames.size(); ++i)
        {
            if(fieldNames.at(i).contains("id"))
            {
                idField = i;
                break;
            }
        }
    }
    else
    {
        qDebug() << "query error: " << query.lastError();
    }
}

void SqlModelWrapper::slot_updateTable(const QString& tableName)
{
    if(!(!changed.isEmpty() || !deleted.isEmpty() || !created.isEmpty()))
    {
        return;
    }

    if(isNewTable)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setText("Это действие заменит текущие записи в БД таблицы "+tableName+
                       " на те, которые в таблице приложения. Продолжить? Обновление записей может занять некоторое время.\n"
                       "Если вы нажмете \'No\', из БД будет загружена актуальная таблица.");
        msgBox.addButton(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);

        int result = msgBox.exec();
        if(result != QMessageBox::Yes)
        {
            return;
        }

        QSqlQuery query;

        if(query.exec("TRUNCATE " + tableName))
        {
            qDebug() << "Таблица " << tableName << " очищена";
        }
        else
        {
            qDebug() << "Удаление данных из таблицы " << tableName << " завершилось неудачно:"
                     << query.lastError();
            return;
        }
    }


    qDebug() << "Отправка изменений в БД";

    QString fieldIdName = fieldNames.at(idField);

    QString queryStr = "UPDATE " + tableName + " SET %1=:data WHERE " + fieldIdName + "=:id";
    QString deleteStr = "DELETE FROM " + tableName + " WHERE "+ fieldIdName + "=:id";


    QString createStr = "INSERT INTO " + tableName + " (";
    QString valuesStr = "VALUES(";

    for(int i = 0; i < fieldNames.size(); ++i)
    {
        if(i == idField)
        {
            continue;
        }

        createStr += fieldNames[i];
        valuesStr += ":" + fieldNames[i];
        if(i == fieldNames.size()-1)
        {
            createStr += ")";
            valuesStr += ")";
        }
        else
        {
            createStr += ",";
            valuesStr += ",";
        }
    }
    createStr += " " + valuesStr;



    QList<QPair<int,int>> listChanged = changed.values();
    for(int i = 0, size = rows.size(); i < size; ++i)
    {
        const QVariantList& row = rows.at(i);
        int id = row.at(idField).toInt();

        if(created.contains(id))
        {
            QSqlQuery query;
            query.prepare(createStr);
            for(int j = 0; j < fieldNames.size(); ++j)
            {
                if(j == idField)
                {
                    continue;
                }
                query.bindValue(":" + fieldNames[j], row.at(j));
                qDebug() <<  fieldNames[j] << " " << row.at(j);
            }
            if(query.exec())
            {
                qDebug() << "SUCCESS insert query";
            }
            else
            {
                qDebug() << "ERROR insert query: " << query.lastQuery() << " " << query.lastError();
            }
        }
        else
        {
            for(int j = 0; j < listChanged.size(); ++j)
            {
                if(listChanged.at(j).first == id)
                {
                    QSqlQuery query;
                    query.prepare(queryStr.arg(fieldNames.at(listChanged.at(j).second)));
                    query.bindValue(":data", row.at(listChanged.at(j).second));
                    query.bindValue(":id", row.at(idField));

                    if(query.exec())
                    {
                        qDebug() << "SUCCESS update query";
                    }
                    else
                    {
                        qDebug() << "ERROR update query: " << query.lastQuery() << " " << query.lastError();
                    }
                }
            }
        }
    }

    for(auto id: deleted)
    {
        if(deleted.contains(id) && id > 0)
        {
            QSqlQuery query;
            query.prepare(deleteStr);
            query.bindValue(":id", id);

            if(query.exec())
            {
                qDebug() << "SUCCESS delete query";
            }
            else
            {
                qDebug() << "ERROR delete query: " << query.lastQuery() << " " << query.lastError();
            }
        }
    }

    changed.clear();
    deleted.clear();
    created.clear();
}

QString SqlModelWrapper::slot_saveTable(const QString& tableName)
{
    QString fileName = createTableFileName(tableName);
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);


    QJsonArray array;

    int id = -1;

    for(int i = 0; i < rows.size(); ++i)
    {
        QJsonObject obj;
        const QVariantList& row = rows.at(i);

        for(int j = 0; j < fieldNames.size(); ++j)
        {
            if(j == idField)
            {
                obj.insert(fieldNames[j], id--);
            }
            else
            {
                obj.insert(fieldNames[j], row.at(j).toJsonValue());
            }
        }
        array.append(obj);
    }

    QString _tableName = tableName + " \r\n";

    file.write(_tableName.toUtf8());

    for(int i = 0; i < fieldNames.size(); ++i)
    {
        QString str = fieldNames[i] + " ";
        file.write(str.toUtf8());
    }
    file.write(QString(" \r\n").toUtf8());

    file.write(QJsonDocument(array).toJson(QJsonDocument::Compact));
    file.close();

    return fileName;
}

bool SqlModelWrapper::slot_loadTable(const QString& fileName, const QString& tableName)
{
    QFile file(fileName);
    if(file.open(QFile::ReadOnly))
    {
        QStringList strList;
        QString str;
        if(!file.atEnd())
        {
            str = file.readLine();
            strList = str.split(regSpace);
            strList.removeAll(" ");

            if(strList.isEmpty())
            {
                qDebug() << "Отсутствует имя таблицы в файле " << fileName;
                return false;
            }

            QString tableNameInFile = strList.at(0);
            if(tableNameInFile != tableName)
            {
                qDebug() << "Выбран файл не той таблицы. Имя таблицы в файле: " << tableNameInFile <<"; а нужно: " << tableName;
                return false;
            }
        }

        if(!file.atEnd())
        {
            str = file.readLine();
            strList = str.split(regSpace);
            strList.removeAll(" ");
            strList.removeLast();
            fieldNames = strList;

            for(int i = 0; i < fieldNames.size(); ++i)
            {
                if(fieldNames[i].contains("id"))
                {
                    idField = i;
                    break;
                }
            }

            qDebug() << "Имена полей: " << fieldNames;
        }

        if(!file.atEnd())
        {
            str = file.readLine();
            QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());

            if(!doc.isArray())
            {
                qDebug() << "В файле "<< fileName << " отсутствует JsonArray";
                return false;
            }
            QJsonArray array = doc.array();

            if(array.isEmpty())
            {
                qDebug() << "JsonArray пустой";
                return false;
            }
            // Очистка модели
            int oldSize = rows.size();

            bool removeRows = !rows.isEmpty();

            if(removeRows)
            {
                beginRemoveRows(QModelIndex(),0,oldSize-1);

                rows.clear();

                endRemoveRows();
            }
            changed.clear();
            deleted.clear();
            created.clear();
            createdCurrent = -1;
            // Очистка модели

            QJsonObject obj;
            int inserted = 0;
            beginInsertRows(QModelIndex(), 0, array.size() - 1);
            for(auto j: array)
            {
                QVariantList row;

                obj = j.toObject();

                for(int i = 0; i < fieldNames.size(); ++i)
                {
                    auto value = obj.value(fieldNames[i]).toVariant();
                    if(i == idField)
                    {
                        created.insert(value.toInt());
                    }
                    row.append(value);
                }
                rows.append(row);

                ++inserted;
            }
            endInsertRows();

            isNewTable = true;

            return true;
        }

    }
    else
    {
        qDebug() << "Не удалось открыть файл " << fileName;
        return false;
    }
    return false;
}









