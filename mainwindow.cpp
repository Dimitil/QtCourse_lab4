#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator validator(1, 100);
    ui->lineEdit->setValidator(&validator);
    ui->lineEdit->setText("1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        emit signalCloseApp();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "ScaleApp, v1.0\n05.12.2020");
}
