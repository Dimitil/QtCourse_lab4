#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>

class MyPicture : public QWidget
{
    Q_OBJECT
    QPixmap m_MyPicture;
    int m_scale;
    double m_x = 0.0;
    double m_y = 0.0;
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

    void slotResetXY() {
        m_x = 0.0;
        m_y = 0.0;
        repaint();
    }


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // MYPICTURE_H
