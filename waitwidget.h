#ifndef WAITWIDGET_H
#define WAITWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class WaitWidget;
}

class WaitWidget : public QFrame//QWidget
{
    Q_OBJECT

signals:
    void startCalculate();

public:
    explicit WaitWidget(QWidget *parent = nullptr);
    ~WaitWidget();

    void showWidget();

public slots:
    void slot_Rotate();

    void slot_close();

private:
    Ui::WaitWidget *ui;
    QPixmap pixWait;
    int degree = 0;
    QTimer* timer;
};

#endif // WAITWIDGET_H
