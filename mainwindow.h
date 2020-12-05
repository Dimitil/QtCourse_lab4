#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signalValueChanged(int num);
    void signalCloseApp();

public slots:
    void slotValueChanged(const QString& str)
    {
        bool ok;
        int num;
        num=str.toInt(&ok);
        if (ok) {
            emit signalValueChanged(num);
        }
    }

    void slotResetScale()
    {
        emit signalValueChanged(0);
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_actionAbout_triggered();
};
#endif // MAINWINDOW_H
