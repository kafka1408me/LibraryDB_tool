/********************************************************************************
** Form generated from reading UI file 'waitwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITWIDGET_H
#define UI_WAITWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaitWidget
{
public:
    QLabel *lblPleaseWait;
    QLabel *pix;

    void setupUi(QWidget *WaitWidget)
    {
        if (WaitWidget->objectName().isEmpty())
            WaitWidget->setObjectName(QString::fromUtf8("WaitWidget"));
        WaitWidget->resize(416, 204);
        WaitWidget->setMinimumSize(QSize(0, 0));
        WaitWidget->setMaximumSize(QSize(1000, 1000));
        lblPleaseWait = new QLabel(WaitWidget);
        lblPleaseWait->setObjectName(QString::fromUtf8("lblPleaseWait"));
        lblPleaseWait->setGeometry(QRect(10, 80, 161, 51));
        lblPleaseWait->setMinimumSize(QSize(151, 0));
        lblPleaseWait->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(9);
        lblPleaseWait->setFont(font);
        lblPleaseWait->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pix = new QLabel(WaitWidget);
        pix->setObjectName(QString::fromUtf8("pix"));
        pix->setGeometry(QRect(200, 15, 181, 161));

        retranslateUi(WaitWidget);

        QMetaObject::connectSlotsByName(WaitWidget);
    } // setupUi

    void retranslateUi(QWidget *WaitWidget)
    {
        WaitWidget->setWindowTitle(QApplication::translate("WaitWidget", "\320\237\320\276\320\264\320\276\320\266\320\264\320\270\321\202\320\265", nullptr));
        lblPleaseWait->setText(QApplication::translate("WaitWidget", "\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\277\320\276\320\264\320\276\320\266\320\264\320\270\321\202\320\265,\n"
" \320\277\320\276\320\272\320\260 \320\270\320\264\320\265\321\202 \320\277\320\276\320\277\321\213\321\202\320\272\320\260 \n"
"\321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217 \321\201 \320\261\320\260\320\267\320\276\320\271 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        pix->setText(QApplication::translate("WaitWidget", "\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\260 \321\207\320\260\321\201\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaitWidget: public Ui_WaitWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITWIDGET_H
