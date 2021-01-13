/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextEdit *logEdit;
    QGridLayout *gridLayout_3;
    QComboBox *tableName;
    QPushButton *changeConfigBtn;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QPushButton *btnDeleteRows;
    QPushButton *btnInsertRow;
    QTextEdit *textEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *pathLineEdit;
    QPushButton *btnToBase64;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QPushButton *btnCopyToBuffer;
    QLineEdit *base64LineEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnLoadTable;
    QPushButton *btnSaveTable;
    QPushButton *btnUpdateTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1176, 707);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(13);
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        logEdit = new QTextEdit(centralwidget);
        logEdit->setObjectName(QString::fromUtf8("logEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logEdit->sizePolicy().hasHeightForWidth());
        logEdit->setSizePolicy(sizePolicy);
        logEdit->setMinimumSize(QSize(291, 0));
        logEdit->setMaximumSize(QSize(291, 16777215));
        logEdit->setReadOnly(true);

        verticalLayout_2->addWidget(logEdit);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableName = new QComboBox(centralwidget);
        tableName->setObjectName(QString::fromUtf8("tableName"));

        gridLayout_3->addWidget(tableName, 0, 0, 1, 1);

        changeConfigBtn = new QPushButton(centralwidget);
        changeConfigBtn->setObjectName(QString::fromUtf8("changeConfigBtn"));

        gridLayout_3->addWidget(changeConfigBtn, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 2);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMinimumSize(QSize(601, 0));

        gridLayout_3->addWidget(tableView, 1, 0, 3, 4);

        btnDeleteRows = new QPushButton(centralwidget);
        btnDeleteRows->setObjectName(QString::fromUtf8("btnDeleteRows"));
        btnDeleteRows->setMinimumSize(QSize(250, 23));
        btnDeleteRows->setMaximumSize(QSize(169, 23));

        gridLayout_3->addWidget(btnDeleteRows, 1, 4, 1, 1);

        btnInsertRow = new QPushButton(centralwidget);
        btnInsertRow->setObjectName(QString::fromUtf8("btnInsertRow"));
        btnInsertRow->setMinimumSize(QSize(250, 23));
        btnInsertRow->setMaximumSize(QSize(169, 23));

        gridLayout_3->addWidget(btnInsertRow, 2, 4, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(250, 241));
        textEdit->setMaximumSize(QSize(200, 16777215));
        textEdit->setLineWidth(4);
        textEdit->setReadOnly(false);

        gridLayout_3->addWidget(textEdit, 3, 4, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 110));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(221, 41));
        label->setMaximumSize(QSize(221, 41));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pathLineEdit = new QLineEdit(widget);
        pathLineEdit->setObjectName(QString::fromUtf8("pathLineEdit"));

        gridLayout->addWidget(pathLineEdit, 0, 1, 1, 1);

        btnToBase64 = new QPushButton(widget);
        btnToBase64->setObjectName(QString::fromUtf8("btnToBase64"));
        btnToBase64->setMinimumSize(QSize(241, 23));
        btnToBase64->setMaximumSize(QSize(241, 23));

        gridLayout->addWidget(btnToBase64, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(47, 13));
        label_4->setMaximumSize(QSize(47, 13));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        btnCopyToBuffer = new QPushButton(widget);
        btnCopyToBuffer->setObjectName(QString::fromUtf8("btnCopyToBuffer"));
        btnCopyToBuffer->setMinimumSize(QSize(241, 23));
        btnCopyToBuffer->setMaximumSize(QSize(241, 23));

        gridLayout_2->addWidget(btnCopyToBuffer, 0, 2, 1, 1);

        base64LineEdit = new QLineEdit(widget);
        base64LineEdit->setObjectName(QString::fromUtf8("base64LineEdit"));
        base64LineEdit->setReadOnly(true);

        gridLayout_2->addWidget(base64LineEdit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_3->addWidget(widget, 4, 0, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 5, 0, 1, 2);

        btnLoadTable = new QPushButton(centralwidget);
        btnLoadTable->setObjectName(QString::fromUtf8("btnLoadTable"));

        gridLayout_3->addWidget(btnLoadTable, 5, 2, 1, 1);

        btnSaveTable = new QPushButton(centralwidget);
        btnSaveTable->setObjectName(QString::fromUtf8("btnSaveTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSaveTable->sizePolicy().hasHeightForWidth());
        btnSaveTable->setSizePolicy(sizePolicy1);
        btnSaveTable->setMinimumSize(QSize(146, 23));
        btnSaveTable->setMaximumSize(QSize(146, 23));

        gridLayout_3->addWidget(btnSaveTable, 5, 3, 1, 1);

        btnUpdateTable = new QPushButton(centralwidget);
        btnUpdateTable->setObjectName(QString::fromUtf8("btnUpdateTable"));
        btnUpdateTable->setMinimumSize(QSize(250, 40));
        btnUpdateTable->setMaximumSize(QSize(200, 40));

        gridLayout_3->addWidget(btnUpdateTable, 5, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1176, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "LOG", nullptr));
        changeConfigBtn->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \320\272 \320\221\320\224", nullptr));
        btnDeleteRows->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        btnInsertRow->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#ff0000;\">\320\222\320\235\320\230\320\234\320\220\320\235\320\230\320\225. \320\237\320\240\320\236\320\247\320\242\320\230\320\242\320\225!!!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#ff0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color"
                        ":#5500ff;\">\320\224\320\260\320\275\320\275\321\213\320\265 \320\262 \320\221\320\224 \320\274\320\265\320\275\321\217\321\216\321\202\321\201\321\217 \321\202\320\276\320\273\321\214\320\272\320\276 \320\277\320\276\321\201\320\273\320\265 \320\275\320\260\320\266\320\260\321\202\320\270\321\217 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 &quot;\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262 \320\221\320\224&quot; \320\270 \321\202\320\276\320\273\321\214\320\272\320\276 \320\264\320\273\321\217 \321\202\320\265\320\272\321\203\321\211\320\265\320\271 \321\202\320\260\320\261\320\273\320\270\321\206\321\213.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\225\321\201\320\273\320\270 \320\262\321\213 \320\270\320\267\320\274\320\265\320\275\320\270\320\273\320\270 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \320\272 \320\221\320\224, \320\277\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\321\202\320\270\321\202\320\265 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203, \321\207\321\202\320\276\320\261\321\213 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \321\201 \321\215\321\202\320\270\320\274\320\270 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260\320\274\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size"
                        ":9pt; color:#5500ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\233\320\276\320\263 \320\277\320\276\320\274\320\276\320\266\320\265\321\202 \320\276\321\202\321\201\320\273\320\265\320\266\320\270\320\262\320\260\321\202\321\214 \320\275\320\265\320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\201\320\276\320\261\321\213\321\202\320\270\321\217 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265. \320\225\321\201\320\273\320\270 \320\277\321\200\320\276\320\270\320\267\320\276\321\210\320\273\320\260 \320\276\321\210\320\270\320\261\320\272\320\260, \320\276\320\275\320\260 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\260 \320\262 \320\273\320\276\320\263\320\265. \320\233\320\276\320\263 \321\202\320\260\320\272\320\266\320\265 \320\262\321\213\320\262"
                        "\320\276\320\264\320\270\321\202\321\201\321\217 \320\262 \321\204\320\260\320\271\320\273 \320\262 \320\277\320\260\320\277\320\272\320\265 &quot;LogFiles&quot;.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\237\320\276\321\201\320\273\320\265 \320\276\321\202\320\277\321\200\320\260\320\262\320\272\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271 \320\262 \320\221\320\224 \321\202\320\260\320\261\320\273\320\270\321\206\320\260 \320\261\321\203\320\264\320\265\321\202 \320\277\320\265\321\200\320\265\320\267\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\260. \320\242\320\260\320\272 \320\262\321\213 \320\274\320\276\320\266\320\265\321\202"
                        "\320\265 \321\203\320\262\320\270\320\264\320\265\321\202\321\214, \320\277\321\200\320\270\320\274\320\265\320\275\320\270\320\273\320\270\321\201\321\214 \320\273\320\270 \320\262\320\260\321\210\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217. \320\225\321\201\320\273\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\275\320\265 \320\277\321\200\320\270\320\274\320\265\320\275\320\270\320\273\320\270\321\201\321\214, \320\277\320\276\321\201\320\274\320\276\321\202\321\200\320\270\321\202\320\265 \320\262 \320\273\320\276\320\263 - \321\202\320\260\320\274 \320\261\321\203\320\264\320\265\321\202 \320\262\321\213\320\262\320\265\320\264\320\265\320\275\320\260 \320\276\321\210\320\270\320\261\320\272\320\260.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; "
                        "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\237\321\200\320\270 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\270 \320\275\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270 user_id \320\270\320\273\320\270 book_id \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274 - \320\267\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \321\201\321\202\320\276\320\273\320\261\321\206\321\213 \320\275\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270 \320\270 \320\276\321\202\320\277\321\200\320\260\320\262\321\214\321\202\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262 \320\221\320\224. \320\225\321\201\320\273\320\270 \320\262\321\201\320\265 \321\201\320\264\320\265\320\273\320\260"
                        "\320\275\320\276 \320\262\320\265\321\200\320\275\320\276, id \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\201\321\217 \320\275\320\260 \320\277\320\276\320\273\320\276\320\266\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 (\321\202\320\276\320\273\321\214\320\272\320\276 \320\277\321\200\320\270 \320\262\321\201\321\202\320\260\320\262\320\272\320\265 \320\267\320\260\320\277\320\270\321\201\320\270 \320\262 \320\221\320\224 \320\274\320\276\320\266\320\275\320\276 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\203\320\275\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\271 id).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:"
                        "9pt; color:#ff0000;\">\320\232\320\220\320\232 \320\227\320\220\320\223\320\240\320\243\320\227\320\230\320\242\320\254 \320\232\320\220\320\240\320\242\320\230\320\235\320\232\320\243 \320\222 \320\221\320\220\320\227\320\243 \320\224\320\220\320\235\320\235\320\253\320\245</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\237\320\265\321\200\320\265\321\202\320\260\321\211\320\270\321\202\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 png \320\275\320\260 \320\276\320\272\320\275\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320"
                        "\270\320\267 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260, \321\207\321\202\320\276\320\261\321\213 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\277\321\203\321\202\321\214 \320\272 \321\215\321\202\320\276\320\274\321\203 \321\204\320\260\320\271\320\273\321\203. \320\235\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\321\214 \320\272 base64&quot;, \321\207\321\202\320\276\320\261\321\213 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 base64, \320\276\320\277\320\270\321\201\321\213\320\262\320\260\321\216\321\211\321\203\321\216 \321\204\320\260\320\271\320\273. \320\235\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320"
                        "\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260&quot;. \320\222\321\201\321\202\320\260\320\262\321\214\321\202\320\265 \320\262 \321\201\321\202\320\276\320\273\320\261\320\265\321\206 photo \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265 books.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\235\320\265 \320\267\320\260\320\261\321\203\320\264\321\214\321\202\320\265 \320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262 \320\221\320\224.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margi"
                        "n-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#ff0000;\">\320\241\320\236\320\245\320\240\320\220\320\235\320\225\320\235\320\230\320\225 \320\230 \320\227\320\220\320\223\320\240\320\243\320\227\320\232\320\220 \320\242\320\220\320\221\320\233\320\230\320\246\320\253 \320\230\320\227 \320\244\320\220\320\231\320\233\320\220</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#ff0000;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#ff0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\224\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320"
                        "\265\320\275\320\270\321\217 \321\202\320\265\320\272\321\203\321\211\320\265\320\271 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 \320\262 \321\204\320\260\320\271\320\273 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\262 \321\204\320\260\320\271\320\273&quot;. \320\244\320\260\320\271\320\273 \321\201\320\276\320\267\320\264\320\260\321\201\321\202\321\201\321\217 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270. \320\235\320\265 \320\274\320\265\320\275\321\217\320\271\321\202\320\265 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\265 \321\204\320\260\320\271\320\273\320\260! \320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\320\275\321\217\321\202\321\214 \320\274\320\276\320\266\320\275\320\276.</span></p>\n"
"<p style=\" margin"
                        "-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#5500ff;\">\320\224\320\273\321\217 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260&quot; \320\270 \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\275\320\265\320\265 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\321\213\320\271 \321\201 \320\277\320\276\320\274\320\276\321\211\321\214\321\216 \321\215\321\202\320\276\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213 \321\204\320\260\320\271\320\273. \320"
                        "\237\320\276\321\201\320\273\320\265 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 \320\276\321\202\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\321\203\320\271\321\202\320\265 \320\265\320\265 \320\277\321\200\320\270 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276\321\201\321\202\320\270 \320\262 \320\276\320\272\320\275\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217. \320\227\320\260\321\202\320\265\320\274 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262 \320\221\320\224&quot;. </span><span style=\" font-size:9pt; font-weight:600; color:#000000;\">\320\222 \321\215\321\202\320\276\320\274 \321\201\320\273\321\203\321\207\320\260\320\265 \321\202\320\265\320\272\321\203\321\211"
                        "\320\270\320\265 \320\267\320\260\320\277\320\270\321\201\320\270 \320\262 \320\221\320\224 \320\261\321\203\320\264\321\203\321\202 \320\267\320\260\320\274\320\265\320\275\320\265\320\275\321\213 \320\275\320\260 \320\264\320\260\320\275\320\275\321\213\320\265, \320\275\320\260\321\205\320\276\320\264\321\217\321\211\320\270\320\265\321\201\321\217 \320\262 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#5500ff;\"><br /></p></body></html>", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216\n"
"(\320\262\321\213 \321\202\320\260\320\272\320\266\320\265 \320\274\320\276\320\266\320\265\321\202\320\265 \320\277\320\265\321\200\320\265\321\202\320\260\321\211\320\270\321\202\321\214 \321\204\320\260\320\271\320\273\n"
" \320\275\320\260 \320\276\320\272\320\275\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217)", nullptr));
        btnToBase64->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\321\214 \320\272 base64", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "base64", nullptr));
        btnCopyToBuffer->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260", nullptr));
        btnLoadTable->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        btnSaveTable->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        btnUpdateTable->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262 \320\221\320\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
