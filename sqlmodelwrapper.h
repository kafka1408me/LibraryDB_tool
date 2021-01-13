#ifndef SQLMODELWRAPPER_H
#define SQLMODELWRAPPER_H

#include <QAbstractTableModel>
#include <QVector>
#include <QSet>

const auto regSpace = QRegExp("\\s+");

class SqlModelWrapper: public QAbstractTableModel
{
    Q_OBJECT
public:
    SqlModelWrapper(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int nRole) const;

    bool setData(const QModelIndex& index, const QVariant& value, int nRole);

    int rowCount(const QModelIndex& = QModelIndex()) const;

    int columnCount(const QModelIndex&) const;

    Qt::ItemFlags flags(const QModelIndex& index) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    bool insertRow(int row, const QModelIndex &aparent = QModelIndex());

public slots:
    void slot_query(const QString& queryStr);

    void slot_updateTable(const QString& tableName);

    QString slot_saveTable(const QString &tableName);

    bool slot_loadTable(const QString &fileName, const QString &tableName);

private:
    QVector<QVariantList> rows;
    QStringList fieldNames;
    QSet<QPair<int, int>> changed;
    QSet<int> deleted;
    QSet<int> created;
    int idField;
    int createdCurrent = -1;
    bool isNewTable = false;

};

#endif // SQLMODELWRAPPER_H
