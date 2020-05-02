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
    QGraphicsView * view2 = ui->graphicsView_2;

    // scene is a QGraphicsScene pointer field of the PlotWindow class
    // this makes our lives easier by letting us easily access it
    // from other functions in this class.
    scene_ = new QGraphicsScene;
    managementScene_ = new QGraphicsScene;

    //setting rectangle  boudnaries for hte two scenes
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    view->setScene(scene_);
    view2->setSceneRect(0,0,view2->frameSize().width(),view2->frameSize().height());
    view2->setScene(managementScene_);
    //creating the game management
    GameManagement *board = new GameManagement();

    this->setStyleSheet("background-color: white;");
    QPixmap qp_title(":/assets/img/title_image.png");
    QGraphicsPixmapItem *title = scene_->addPixmap( qp_title );
    title->setPos(200,0);

    QPixmap qp_gif(":/assets/img/dancing_wario.gif");
    QGraphicsPixmapItem * wario = scene_->addPixmap( qp_gif );
    wario->setPos(40,0);

    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/WarioWare, Inc. Super Smash Bros. Ultimate.mp3"));
    sound->play();

    QMovie *wario_dance = new QMovie(":/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();


    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));
    QTimer *time_ = new QTimer(this);
    connect(time_,&QTimer::timeout,this,&MainWindow::ShowCountdownTimerSlot);
    time_->start(1000);


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
void MainWindow::ShowCountdownTimerSlot(){
    GameManagement *board = new GameManagement();
    if (repeat_ == -1){
        repeat_ = 5;
    }
    Timer *time = board->GetTimer(repeat_);
    managementScene_->addItem(time);
    repeat_--;
}


MainWindow::~MainWindow()
{
    delete ui;
}

