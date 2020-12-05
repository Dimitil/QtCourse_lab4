#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>
#include <QRubberBand>

class MyPicture : public QWidget
{
    Q_OBJECT
    QPixmap m_MyPicture;
    int m_scale;
    QRubberBand* rubberBand= nullptr;
    QPoint clickPos;
    QPoint releasePos;
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
        m_scale = 1;
        clickPos = QPoint(0, 0);
        delete rubberBand;
        rubberBand = nullptr;
        repaint();
    }


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // MYPICTURE_H
