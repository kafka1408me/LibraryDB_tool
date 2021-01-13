#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QClipboard>
#include "changeconnectingsettings.h"
#include "MyLog.h"
#include <thread>
#include <QFileDialog>
#include <QApplication>

MainWindow* mainWindow = nullptr;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
#ifdef MSG_TYPE
    static QString myMsg("%1 : %2 : %3");
#else
    static QString myMsg("%1 : %2");
#endif

    QDateTime currentTime = QDateTime::currentDateTime();
    QString msgToSend;
    QString typeMsg("");

    bool isDebug = false;

    switch (type) {
    case QtDebugMsg:
    {
        isDebug = true;
#ifdef MSG_TYPE
        typeMsg = "DEBUG";
#endif
        break;
    }
#ifdef MSG_TYPE
    case QtInfoMsg:
    {
        typeMsg = "INFO";
        break;
    }
    case QtWarningMsg:
    {
        typeMsg = "WARING";
        break;
    }
    case QtCriticalMsg:
    {
        typeMsg = "CRITICAL";
        break;
    }
    case QtFatalMsg:
    {
        typeMsg = "FATAL";
        break;
    }
#else
    default:
        break;
#endif
    }
#ifdef MSG_TYPE
    msgToSend = myMsg.arg(currentTime.toString()).arg(typeMsg).arg(msg);
#else
    msgToSend = myMsg.arg(currentTime.toString()).arg(msg);
#endif
    if(!isDebug)
    {
        msgToSend += " " + QString(context.file) + " " + QString(context.line) + " " + QString(context.function);
    }
    mainWindow->sendMessageToLog(msgToSend);
}


QSqlDatabase db;

QString host;
QString dbName;
QString userName;
QString password;

void MainWindow::createConnection()
{
//    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName(dbName);

    db.setUserName(userName);
    db.setHostName(host);
    db.setPassword(password);

    bool isConnected = false;

    if(!db.open())
    {
        qDebug() << "Cannot open database: " << db.lastError();
    }
    else
    {
        qDebug() << "Opening database successful";
        isConnected = true;
    }
    emit connected(isConnected);
}

bool MainWindow::readConfig()
{
    QFile file("config.txt");

    bool success = false;

    if(file.open(QFile::ReadOnly))
    {

        while(!file.atEnd())
        {
            QString str = file.readLine();
            QStringList lst = str.split(regSpace);

            lst.removeAll(" ");
            if(lst.size() < 2)
            {
                break;
            }

            if(lst.at(0) == HOST)
            {
                host = lst[1];
            }
            else if(lst.at(0) == DB_NAME)
            {
                dbName = lst[1];
            }
            else if(lst.at(0) == USER_NAME)
            {
                userName = lst[1];
            }
            else if(lst.at(0) == PASSWORD)
            {
                password = lst[1];
            }
        }
        if(!host.isEmpty() && !dbName.isEmpty() && !userName.isEmpty() && !password.isEmpty())
        {
            success = true;
        }
        qDebug() << HOST << " " << host;
        qDebug() << DB_NAME << " " << dbName;
        qDebug() << USER_NAME << " " << userName;
        qDebug() << PASSWORD << " " << password;
        file.close();
    }

    return success;
}


QString createQuerySelectAll(const QString& tableName)
{
    return "SELECT * FROM " + tableName;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableName->addItems(QStringList() << "users" << "books");

    mainWindow = this;
    myLog = new MyLog(this);
    qInstallMessageHandler(myMessageOutput);
    changeConnectingSettings = new ChangeConnectingSettings;

    setWindowTitle("LibraryDB_Tool");

    connect(ui->tableName, &QComboBox::currentTextChanged, this, &MainWindow::slot_tableNameChanged);
    connect(ui->btnToBase64, &QPushButton::clicked, this, &MainWindow::slot_toBase64);
    connect(ui->btnCopyToBuffer, &QPushButton::clicked, this, &MainWindow::slot_copyToBuffer);
    connect(ui->pathLineEdit, &QLineEdit::textChanged, ui->base64LineEdit, &QLineEdit::clear);
    connect(ui->btnUpdateTable, &QPushButton::clicked, this, &MainWindow::slot_updateTable);
    connect(ui->btnDeleteRows, &QPushButton::clicked, this, &MainWindow::slot_deleteRows);
    connect(ui->btnInsertRow, &QPushButton::clicked, this, &MainWindow::slot_insertRow);
    connect(ui->changeConfigBtn, &QPushButton::clicked, this, &MainWindow::slot_changeConfig);
    connect(this, &MainWindow::connected, this, &MainWindow::slot_connected);
    connect(ui->btnSaveTable,  &QPushButton::clicked, this, &MainWindow::slot_saveTable);
    connect(ui->btnLoadTable, &QPushButton::clicked, this, &MainWindow::slot_loadTable);

    ui->tableView->setModel(&mySqlModel);

    db = QSqlDatabase::addDatabase("QPSQL");

    QTimer::singleShot(80, this, &MainWindow::slot_tryConnectToDB);

    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    QString myMsg("%1 : %2");
    QDateTime currentTime = QDateTime::currentDateTime();
    myLog->Log(myMsg.arg(currentTime.toString()).arg("FINISHED"));
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *pe)
{
    if(pe->mimeData()->hasFormat("text/uri-list"))
    {
        QList<QUrl> urlList = pe->mimeData()->urls();

        if(urlList.size() != 1)
        {
            return;
        }

        QString path = urlList[0].toLocalFile();
        int index = path.lastIndexOf('.');

        if(index != -1 && index != path.length()-1)
        {
            QString fileExtension = path.mid(index + 1).toLower();
            if(fileExtension != "png")
            {
                return;
            }
        }
        else
        {
            return;
        }
        qDebug() << "Перетаскивание разрешено";
        pe->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *pe)
{
    QList<QUrl> urlList = pe->mimeData()->urls();

    QString path = urlList[0].toLocalFile();

    ui->pathLineEdit->setText(path);
}

void MainWindow::slot_tableNameChanged(const QString &text)
{
    mySqlModel.slot_query(createQuerySelectAll(text));
}

void MainWindow::slot_tryConnectToDB()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Желаете изменить настройки подключения к БД?\n"
                   "Если хотите использовать существующие настройки, нажмите 'No'");
    msgBox.addButton(QMessageBox::StandardButton::Yes);
    msgBox.addButton(QMessageBox::StandardButton::No);

    int btnRes = msgBox.exec();

    if(btnRes == QMessageBox::StandardButton::Yes)
    {
        readConfig();
        slot_changeConfig();
        return;
    }


    bool isReadConfig = readConfig();

    if(!isReadConfig)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Отсутствует или поврежден файл \"config.txt\"\n"
                       "В этом файле должны храниться настройки для подключения к БД\n"
                       "Желаете создать этот файл?");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int result = msgBox.exec();
        qDebug() << "result = " << result;
        if(result == QMessageBox::Ok)
        {
            slot_changeConfig();
            return;
        }
        else
        {
            exit(-1);
        }
    }

    emit connectStart();

//    qApp->processEvents();

    std::thread thread(&MainWindow::createConnection, this);
    thread.detach();
}

void MainWindow::slot_toBase64()
{
    QPixmap pix(ui->pathLineEdit->text());

    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    pix.save(&buffer, "PNG");

    QString pixStr = buffer.data().toBase64();

    ui->base64LineEdit->setText(pixStr);

}

void MainWindow::slot_copyToBuffer()
{
    QClipboard* pcb = QApplication::clipboard();
    pcb->setText(ui->base64LineEdit->text());
}

void MainWindow::slot_updateTable()
{
    mySqlModel.slot_updateTable(ui->tableName->currentText());
    mySqlModel.slot_query(createQuerySelectAll(ui->tableName->currentText()));
}

void MainWindow::slot_deleteRows()
{
    int count = ui->tableView->selectionModel()->selectedRows().count();
    while (count)
    {
        mySqlModel.removeRow( ui->tableView->selectionModel()->selectedRows().at(0).row());
        count = ui->tableView->selectionModel()->selectedRows().count();
    }

}

void MainWindow::slot_insertRow()
{
    int row = mySqlModel.rowCount();
    mySqlModel.insertRow(row);
}

void MainWindow::slot_changeConfig()
{
    changeConnectingSettings->setSettings(host, userName, password, dbName);
    changeConnectingSettings->show();
}

void MainWindow::sendMessageToLog(const QString &msg)
{
    ui->logEdit->append(msg);
    myLog->Log(msg);
}

void MainWindow::slot_connected(bool isConnected)
{
    emit connectFinished();

    if(!isConnected)
    {

        qDebug() << "createConnection() failed";
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Ошибка подключения к БД");
        msgBox.setText("Не удалось подключиться к БД\n"
                       "Сообщение об ошибке: \n"  + db.lastError().text());

        //   qApp->exec();
        msgBox.exec();
        exit(-2);
    }
    connect(changeConnectingSettings, &ChangeConnectingSettings::applySettings, this, &MainWindow::readConfig);

    slot_tableNameChanged(ui->tableName->currentText());
    show();
}

void MainWindow::slot_saveTable()
{
    QString fileName = mySqlModel.slot_saveTable(ui->tableName->currentText());
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Таблица сохранена");
    msgBox.setText("Таблица " + ui->tableName->currentText() + " сохранена в файл:\n" + fileName);
    msgBox.exec();
}

void MainWindow::slot_loadTable()
{
    QString appDir = QApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    "Выберите файл, содержащий таблицу",
                                                    appDir,
                                                    "Text files (*.txt)");
    qDebug() << "Выбран файл " << fileName;

    bool result = mySqlModel.slot_loadTable(fileName, ui->tableName->currentText());

    QMessageBox msgBox;
    msgBox.setWindowTitle("Загрузка таблицы из файла");

    if(result)
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Таблица успешно загружена из файла");
    }
    else
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Не удалось загрузить таблицу из файла");
    }
    msgBox.exec();

}
