#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "corona.h"
#include <QTime>
#include <QTimer>
#include <QMovie>
#include <QMediaPlayer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // the QGraphicsView is the UI element that contains the
    // scene that we will actually get to draw on.
    QGraphicsView * view = ui->graphicsView;

    // scene is a QGraphicsScene pointer field of the PlotWindow class
    // this makes our lives easier by letting us easily access it
    // from other functions in this class.
    scene_ = new QGraphicsScene;
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    view->setScene(scene_);

    this->setStyleSheet("background-color: white;");
    QPixmap qp_title(":/assets/img/title_image.png");
    QGraphicsPixmapItem *title = scene_->addPixmap( qp_title );
    title->setPos(200,0);

    QMovie *wario_dance = new QMovie(":/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();
    ui->wario_gif->close();

    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/WarioWare, Inc. Super Smash Bros. Ultimate.mp3"));
    sound->play();

    Corona * c1 = new Corona(400,100);
    scene_->addItem(c1);

    connect(c1, &Corona::DeleteCell, this, &MainWindow::CoronaSelectedSlot);


//    QImage *img = new QImage(":/images/grass.png");
//        *img = img->scaled(100,100,Qt::KeepAspectRatioByExpanding);
//        QBrush bg_brush(*img);
//        scene ->setBackgroundBrush(bg_brush)



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CoronaSelectedSlot(Corona * c){

    scene_->removeItem(c);
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/Corona/scream.wav"));
    sound->play();
}

void MainWindow::Games(){
    scene_->clear();
    QImage *img = new QImage(":/assets/img/sick village.png");
    *img = img->scaled(ui->graphicsView->frameSize().width(),ui->graphicsView->frameSize().height());
    QBrush bg_brush(*img);
    scene_ ->setBackgroundBrush(bg_brush);
}

void MainWindow::on_startButton_clicked()
{
    qDebug() << "Clicked!";
    ui->startButton->close();
    this->Games();


}
