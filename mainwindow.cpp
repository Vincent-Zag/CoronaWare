#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "corona.h"
#include <QTime>
#include <QTimer>
#include <QMovie>
#include <QMediaPlayer>

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
    scene = new QGraphicsScene;
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    view->setScene(scene);

    this->setStyleSheet("background-color: white;");
    QPixmap qp_title(":/assets/img/title_image.png");
    QGraphicsPixmapItem *title = scene->addPixmap( qp_title );
    title->setPos(200,0);
    //setPixMap(qp_title)
    //ui->title_image->setPixmap(qp_title);
    //scene->addItem(setPixmap(qp_title));
    QPixmap qp_gif(":/assets/img/dancing_wario.gif");
    QGraphicsPixmapItem * wario = scene->addPixmap( qp_gif );
    wario->setPos(40,0);


    QMovie *wario_dance = new QMovie(":/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();

    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/WarioWare, Inc. Super Smash Bros. Ultimate.mp3"));
    sound->play();

    Corona * c1 = new Corona(400,400);
    scene->addItem(c1);


    //scene->clear();

//    QImage *img = new QImage(":/images/grass.png");
//        *img = img->scaled(100,100,Qt::KeepAspectRatioByExpanding);
//        QBrush bg_brush(*img);
//        scene ->setBackgroundBrush(bg_brush)



}

MainWindow::~MainWindow()
{
    delete ui;
}

