#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "corona.h"
#include "gamemanagement.h"
#include "life.h"
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
    qDebug() << "graphics item2 added";
    QGraphicsView * view2 = ui->graphicsView_2;

    // scene is a QGraphicsScene pointer field of the PlotWindow class
    // this makes our lives easier by letting us easily access it
    // from other functions in this class.
    scene_ = new QGraphicsScene;
    managementScene_ = new QGraphicsScene;
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    view->setScene(scene_);
    qDebug() << "setting rectangle bounds";
    view2->setSceneRect(0,0,view2->frameSize().width(),view2->frameSize().height());
    view2->setScene(managementScene_);

    this->setStyleSheet("background-color: white;");
    QPixmap qp_title(":/assets/img/title_image.png");
    QGraphicsPixmapItem *title = scene_->addPixmap( qp_title );
    title->setPos(200,0);
    //setPixMap(qp_title)
    //ui->title_image->setPixmap(qp_title);
    //scene->addItem(setPixmap(qp_title));
    QPixmap qp_gif(":/assets/img/dancing_wario.gif");
    QGraphicsPixmapItem * wario = scene_->addPixmap( qp_gif );
    wario->setPos(40,0);

    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/WarioWare, Inc. Super Smash Bros. Ultimate.mp3"));
    sound->play();
    //qDebug() << "adding corona";
    Corona * c1 = new Corona(400,400);
    scene_->addItem(c1);


    QMovie *wario_dance = new QMovie(":/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();
    //ui->wario_gif->close(); //closes on start of game
    //qDebug() << "test";
    GameManagement *board = new GameManagement();


    Life *life1 = board->GetLife1();
    managementScene_->addItem(life1);
    Life *life2 = board->GetLife2();
    managementScene_->addItem(life2);

    Timer *time0 = board->GetTimer(0);
    managementScene_->addItem(time0);
    Timer *time1 = board->GetTimer(1);
    managementScene_->addItem(time1);
    Timer *time2 = board->GetTimer(2);
    managementScene_->addItem(time2);
    Timer *time3 = board->GetTimer(3);
    managementScene_->addItem(time3);
    Timer *time4 = board->GetTimer(4);
    managementScene_->addItem(time4);
    Timer *time5 = board->GetTimer(5);
    managementScene_->addItem(time5);


    //scene->clear(); clears scene on game start

    //    QImage *img = new QImage(":/images/grass.png");
    //        *img = img->scaled(100,100,Qt::KeepAspectRatioByExpanding);
    //        QBrush bg_brush(*img);
    //        scene ->setBackgroundBrush(bg_brush)

    QImage *img = new QImage(":/assets/img/gamemanagement_background.jpeg");
    QBrush bg_brush(*img);
    managementScene_ ->setBackgroundBrush(bg_brush);

    //Game management Overhead Labels
    std::string score = "Score: "+ std::to_string(board->GetScore());
    QString qscore(score.c_str());
    ui->score_label->setStyleSheet("background-color:rgba(0,0,0,0%)");
    ui->time_label->setStyleSheet("background-color:rgba(0,0,0,0%)");
    ui->life_label->setStyleSheet("background-color:rgba(0,0,0,0%)");
    ui->score_label->setText(qscore);

}

MainWindow::~MainWindow()
{
    delete ui;
}

