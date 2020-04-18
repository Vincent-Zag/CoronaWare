#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    QPixmap qp_title("/home/vincent/Documents/CSCI3010/HW5/WarioWare/assets/img/title_image.png");
    ui->title_image->setPixmap(qp_title);
    QPixmap qp_gif("/home/vincent/Documents/CSCI3010/HW5/WarioWare/assets/img/dancing_wario.gif");
    ui->wario_gif->setPixmap(qp_gif);


    QMovie *wario_dance = new QMovie("/home/vincent/Documents/CSCI3010/HW5/WarioWare/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

