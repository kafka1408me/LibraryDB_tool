#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sqlmodelwrapper.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ChangeConnectingSettings;
class MyLog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void dragEnterEvent(QDragEnterEvent* pe) override;
    void dropEvent(QDropEvent* pe) override;

    void createConnection();

public slots:
    bool readConfig();

    void slot_tableNameChanged(const QString& text);

    void slot_tryConnectToDB();

    void slot_toBase64();

    void slot_copyToBuffer();

    void slot_updateTable();

    void slot_deleteRows();

    void slot_insertRow();

    void slot_changeConfig();

    void sendMessageToLog(const QString& msg);

    void slot_connected(bool isConnected);

    void slot_saveTable();

    void slot_loadTable();

signals:
    void connected(bool);

    void connectFinished();

    void connectStart();

private:
    Ui::MainWindow *ui;
    SqlModelWrapper mySqlModel;
    ChangeConnectingSettings* changeConnectingSettings = nullptr;
    MyLog* myLog;
};
#endif // MAINWINDOW_H
