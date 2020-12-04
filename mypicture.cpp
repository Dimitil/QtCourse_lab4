#include "mypicture.h"
#include <QDebug>
#include <QPainter>

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
    //QPainter painter(this);
    //m_scale and drawpPixmap
}
