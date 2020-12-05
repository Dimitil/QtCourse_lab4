#include "mypicture.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

MyPicture::MyPicture(QWidget *parent) : QWidget(parent)
{
    if (!m_MyPicture.load(":/pictures/Images_lab4/WomenAndDog.jpg"))
    {
        qDebug() << "MyPicture cannot load";
        exit(1);
    }
    m_scale = 1;
}


void MyPicture::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //double NewScale = 1-(m_scale/100.0);
    QPixmap pix = m_MyPicture;
    resize(pix.width(), pix.height());
    QRect source = QRect(pix.rect());
    QRect target = rect();
    if (rubberBand)
    {
        source = rubberBand ->geometry();
        target = source;
        target.moveTo(0,0);
    }
    painter.scale(m_scale, m_scale);
    painter.drawPixmap(target, pix, source);
    //QPixmap pix = m_MyPicture.scaled(size(), Qt::KeepAspectRatio);
    //painter.scale(NewScale, NewScale);
    //painter.drawPixmap(0, 0, pix);
    //QRectF source(0.0, 0.0, pix.width()*m_scale/100, pix.height()*m_scale/100);
    //QRectF target(50, 50, this->width()*m_scale/100,this->height()*m_scale/100);
    //painter.drawPixmap(target, pix, source);
}


void MyPicture::mousePressEvent(QMouseEvent *event)
{
    clickPos = event->pos();
    if (!rubberBand){
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    }
    rubberBand->setGeometry(QRect(clickPos, QSize()));
    rubberBand->show();
//    qDebug() << clickPos.x();
}


void MyPicture::mouseReleaseEvent(QMouseEvent *event)
{
    releasePos = event->pos();
    rubberBand->hide();
    update();
}

void MyPicture::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(clickPos, event->pos()).normalized());
}
