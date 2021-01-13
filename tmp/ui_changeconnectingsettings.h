/********************************************************************************
** Form generated from reading UI file 'changeconnectingsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGECONNECTINGSETTINGS_H
#define UI_CHANGECONNECTINGSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeConnectingSettings
{
public:
    QGridLayout *gridLayout;
    QLabel *hostLbl;
    QLineEdit *hostEdit;
    QLabel *userNameLbl;
    QLineEdit *userNameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *databasenameLabel;
    QLineEdit *databasenameEdit;
    QPushButton *btnCancel;
    QPushButton *btnApply;

    void setupUi(QWidget *ChangeConnectingSettings)
    {
        if (ChangeConnectingSettings->objectName().isEmpty())
            ChangeConnectingSettings->setObjectName(QString::fromUtf8("ChangeConnectingSettings"));
        ChangeConnectingSettings->resize(390, 273);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChangeConnectingSettings->sizePolicy().hasHeightForWidth());
        ChangeConnectingSettings->setSizePolicy(sizePolicy);
        ChangeConnectingSettings->setMinimumSize(QSize(390, 273));
        ChangeConnectingSettings->setMaximumSize(QSize(390, 273));
        gridLayout = new QGridLayout(ChangeConnectingSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hostLbl = new QLabel(ChangeConnectingSettings);
        hostLbl->setObjectName(QString::fromUtf8("hostLbl"));

        gridLayout->addWidget(hostLbl, 0, 0, 1, 1);

        hostEdit = new QLineEdit(ChangeConnectingSettings);
        hostEdit->setObjectName(QString::fromUtf8("hostEdit"));

        gridLayout->addWidget(hostEdit, 0, 1, 1, 2);

        userNameLbl = new QLabel(ChangeConnectingSettings);
        userNameLbl->setObjectName(QString::fromUtf8("userNameLbl"));

        gridLayout->addWidget(userNameLbl, 1, 0, 1, 1);

        userNameEdit = new QLineEdit(ChangeConnectingSettings);
        userNameEdit->setObjectName(QString::fromUtf8("userNameEdit"));

        gridLayout->addWidget(userNameEdit, 1, 1, 1, 2);

        passwordLabel = new QLabel(ChangeConnectingSettings);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        passwordEdit = new QLineEdit(ChangeConnectingSettings);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        gridLayout->addWidget(passwordEdit, 2, 1, 1, 2);

        databasenameLabel = new QLabel(ChangeConnectingSettings);
        databasenameLabel->setObjectName(QString::fromUtf8("databasenameLabel"));

        gridLayout->addWidget(databasenameLabel, 3, 0, 1, 1);

        databasenameEdit = new QLineEdit(ChangeConnectingSettings);
        databasenameEdit->setObjectName(QString::fromUtf8("databasenameEdit"));

        gridLayout->addWidget(databasenameEdit, 3, 1, 1, 2);

        btnCancel = new QPushButton(ChangeConnectingSettings);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        sizePolicy.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy);
        btnCancel->setMinimumSize(QSize(131, 0));

        gridLayout->addWidget(btnCancel, 4, 1, 1, 1);

        btnApply = new QPushButton(ChangeConnectingSettings);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));
        btnApply->setMinimumSize(QSize(131, 0));

        gridLayout->addWidget(btnApply, 4, 2, 1, 1);


        retranslateUi(ChangeConnectingSettings);

        QMetaObject::connectSlotsByName(ChangeConnectingSettings);
    } // setupUi

    void retranslateUi(QWidget *ChangeConnectingSettings)
    {
        ChangeConnectingSettings->setWindowTitle(QApplication::translate("ChangeConnectingSettings", "Form", nullptr));
        hostLbl->setText(QApplication::translate("ChangeConnectingSettings", "host", nullptr));
        userNameLbl->setText(QApplication::translate("ChangeConnectingSettings", "username", nullptr));
        passwordLabel->setText(QApplication::translate("ChangeConnectingSettings", "password", nullptr));
        databasenameLabel->setText(QApplication::translate("ChangeConnectingSettings", "databasename", nullptr));
        btnCancel->setText(QApplication::translate("ChangeConnectingSettings", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        btnApply->setText(QApplication::translate("ChangeConnectingSettings", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeConnectingSettings: public Ui_ChangeConnectingSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGECONNECTINGSETTINGS_H
