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
    QPixmap pix = m_MyPicture.scaled(size(), Qt::KeepAspectRatio);
    QRectF source(m_x, m_y, width(), height());
    QRectF target(0, 0, width(), height());
    painter.scale(m_scale, m_scale);
    painter.drawPixmap (target, pix, source);
    //QPixmap pix = m_MyPicture.scaled(size(), Qt::KeepAspectRatio);
    //painter.scale(NewScale, NewScale);
    //painter.drawPixmap(0, 0, pix);
    //QRectF source(0.0, 0.0, pix.width()*m_scale/100, pix.height()*m_scale/100);
    //QRectF target(50, 50, this->width()*m_scale/100,this->height()*m_scale/100);
    //painter.drawPixmap(target, pix, source);
}


void MyPicture::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = (event->pos());
    m_y = pos.y();
    m_x = pos.x();
    //qDebug() << m_x << '\n'<< m_y;
}
