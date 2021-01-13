#ifndef CHANGECONNECTINGSETTINGS_H
#define CHANGECONNECTINGSETTINGS_H

#include <QWidget>

#define HOST "host"
#define DB_NAME "databasename"
#define USER_NAME "username"
#define PASSWORD "password"

namespace Ui {
class ChangeConnectingSettings;
}

class ChangeConnectingSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeConnectingSettings(QWidget *parent = nullptr);
    ~ChangeConnectingSettings();

    void setSettings(const QString& host,
                     const QString& userName,
                     const QString& password,
                     const QString& databaseName);

signals:
    void applySettings();

public slots:
    void slot_apply();

    void slot_finish();

private:
    Ui::ChangeConnectingSettings *ui;
};

#endif // CHANGECONNECTINGSETTINGS_H
