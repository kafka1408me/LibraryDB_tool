#include "mainwindow.h"

#include <QApplication>
#include "waitwidget.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    WaitWidget* waitWidget = new WaitWidget;

    MainWindow w;

    QObject::connect(&w, &MainWindow::connectStart, waitWidget, &WaitWidget::showWidget);
    QObject::connect(&w, &MainWindow::connectFinished, waitWidget, &WaitWidget::slot_close);

//    waitWidget->showWidget();

    return a.exec();
}
