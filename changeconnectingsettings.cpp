#include "changeconnectingsettings.h"
#include "ui_changeconnectingsettings.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

ChangeConnectingSettings::ChangeConnectingSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeConnectingSettings)
{
    ui->setupUi(this);

    connect(ui->btnApply,&QPushButton::clicked, this, &ChangeConnectingSettings::slot_apply);
    connect(ui->btnCancel,&QPushButton::clicked, this, &ChangeConnectingSettings::slot_finish);

    setWindowTitle("Изменить настройки подключения к БД");

}

ChangeConnectingSettings::~ChangeConnectingSettings()
{
    delete ui;
}

void ChangeConnectingSettings::setSettings(const QString &host, const QString &userName, const QString &password, const QString &databaseName)
{
    if(!host.isEmpty())
    {
        ui->hostEdit->setText(host);
    }
    if(!userName.isEmpty())
    {
        ui->userNameEdit->setText(userName);
    }
    if(!password.isEmpty())
    {
        ui->passwordEdit->setText(password);
    }
    if(!databaseName.isEmpty())
    {
        ui->databasenameEdit->setText(databaseName);
    }
}

void ChangeConnectingSettings::slot_apply()
{
    QFile file("config.txt");

    file.open(QFile::WriteOnly | QFile::Truncate);
    QTextStream out(&file);
    out << HOST << '\t' << ui->hostEdit->text() << "\r\n";
    out << USER_NAME << '\t'<< ui->userNameEdit->text() << "\r\n";
    out << PASSWORD << '\t' << ui->passwordEdit->text() << "\r\n";
    out << DB_NAME << '\t' << ui->databasenameEdit->text() << "\r\n";

    file.close();
    close();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Перезапустите программу, чтобы\n"
                   "настройки применились");
    msgBox.exec();
    emit applySettings();
}

void ChangeConnectingSettings::slot_finish()
{
    close();
}






