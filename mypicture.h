#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>

class MyPicture : public QWidget
{
    Q_OBJECT
    QPixmap m_MyPicture;
    int m_scale;
public:
    explicit MyPicture(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void slotScaleChanged(int newScale)
    {
        m_scale = newScale;
        repaint();
    }

};

#endif // MYPICTURE_H
