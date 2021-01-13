#include "waitwidget.h"
#include "ui_waitwidget.h"
#include <QTimer>
#include <QPainter>

WaitWidget::WaitWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::WaitWidget)
{
    ui->setupUi(this);
    pixWait = QPixmap(":/images/wait.png").scaled(ui->pix->size()*0.80, Qt::KeepAspectRatio);
    ui->pix->setPixmap(pixWait);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setFrameStyle(QFrame::Box | QFrame::Plain);
    QPalette pal;
    pal.setBrush(this->backgroundRole(), Qt::white);
    pal.setBrush(this->foregroundRole(), Qt::black);
    setPalette(pal);
    setAutoFillBackground(true);

//    setFixedSize(210, 271);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WaitWidget::slot_Rotate);
    timer->setInterval(250);
    timer->start();
}

WaitWidget::~WaitWidget()
{
    delete ui;
}

void WaitWidget::showWidget()
{
    show();
    setCursor(QCursor(Qt::WaitCursor));

}

void WaitWidget::slot_Rotate()
{

    static QPixmap rotatePixmap(pixWait.size()*2);
    rotatePixmap.fill(Qt::transparent);
    degree += 30;

    static const int w2 = rotatePixmap.size().width() / 2;
    static const int h2 = rotatePixmap.size().height() / 2;
    static const int w4 = w2/2;
    static const int h4 = h2/2;

    QPainter p(&rotatePixmap);
    p.setRenderHint(QPainter::Antialiasing); // сглаживание
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(w2, h2);
    p.rotate(degree); // градус
    p.translate(-w2, -h2);
    p.drawPixmap(w4, h4, pixWait);
    p.end();

    static float radius = (pixWait.width()/2)*(pixWait.width()/2) + (pixWait.height()/2)*(pixWait.height()/2);
    static QRect rect(pixWait.width() - pixWait.height()/1.65, pixWait.height() - radius, radius*2, radius*2);

 //   ui->pix->setPixmap(rotatePixmap.copy(rect));
    ui->pix->setPixmap(rotatePixmap);
}

void WaitWidget::slot_close()
{
    close();
    timer->stop();
    deleteLater();
}
