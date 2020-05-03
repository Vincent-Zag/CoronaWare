//classes
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "corona.h"
#include "gamemanagement.h"
#include "life.h"
#include "countvirus.h"
#include "disinfect.h"
#include "wash.h"
#include "patience.h"

//qt libraries
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

    //setting height and width of graphics views
    height_ = ui->graphicsView->frameSize().height();
    width_ = ui->graphicsView->frameSize().width();

    //creating the game management
    GameManagement *board = new GameManagement();

    this->setStyleSheet("background-color: white;");
    QPixmap qp_title(":/assets/img/title_image.png");
    QGraphicsPixmapItem *title = scene_->addPixmap( qp_title );
    title->setPos(200,0);


// TODO LATER
//    QPixmap qp_gif(":/assets/img/dancing_wario.gif");
//    QGraphicsPixmapItem * wario = scene_->addPixmap( qp_gif );
//    wario->setPos(40,0);


    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/WarioWare, Inc. Super Smash Bros. Ultimate.mp3"));
    sound->play();


    Corona * c1 = new Corona(400,100);
    scene_->addItem(c1);

    connect(c1, &Corona::DeleteCell, this, &MainWindow::CoronaSelectedSlot);


    QMovie *wario_dance = new QMovie(":/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();
    ui->wario_gif->close();
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));
    QTimer *time_ = new QTimer(this);
    connect(time_,&QTimer::timeout,this,&MainWindow::ShowCountdownTimerSlot);
    time_->start(1000);

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
    ui->prompt_label->setStyleSheet("background-color:rgba(0,0,0,0%)");


    Life *life1 = board->GetLife1();
    managementScene_->addItem(life1);
    Life *life2 = board->GetLife2();
    managementScene_->addItem(life2);


    scene_->clear();
    Patience *patience_game = new Patience(0,0);
    scene_->addItem(patience_game);



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


void MainWindow::CoronaSelectedSlot(Corona * c){

    scene_->removeItem(c);
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/Corona/scream.wav"));
    sound->play();
}

void MainWindow::Games(){
    scene_->clear();
    QImage *img = new QImage(":/assets/img/sick village.png");
    *img = img->scaled(width_,height_);
    QBrush bg_brush(*img);
    scene_ ->setBackgroundBrush(bg_brush);
    //need to create a button for patience here
    //as well as a label to prompt patience...
}

void MainWindow::on_startButton_clicked()
{
    qDebug() << "Clicked!";
    ui->startButton->close();
    this->Games();
}

void MainWindow::PhasePassed(){
    GameManagement *board = new GameManagement();
    QMediaPlayer * sound = new QMediaPlayer();
    int num = RandomHelper();
    if (num == 1){
        sound->setMedia(QUrl("qrc:/assets/sound/Correct/win1.wav"));
    }else if(num == 2){
        sound->setMedia(QUrl("qrc:/assets/sound/Correct/correct.wav"));
    }else{
        sound->setMedia(QUrl("qrc:/assets/sound/Correct/cheering.wav"));
    }
    sound->play();
    board->SetScore(1);

}
int MainWindow::RandomHelper(){
    return qrand() % 3 +1;
}
void MainWindow::PhaseFailed(){
    GameManagement *board = new GameManagement();
    QMediaPlayer * sound = new QMediaPlayer();
    int num = RandomHelper();
    if (num == 1){
        sound->setMedia(QUrl("qrc:/assets/sound/Incorrect/booing.wav"));
    }else if(num == 2){
        sound->setMedia(QUrl("qrc:/assets/sound/Incorrect/incorrect.wav"));
    }else{
        sound->setMedia(QUrl("qrc:/assets/sound/Incorrect/lose.wav"));
    }
    sound->play();
    board->SetScore(-1);
}

void MainWindow::PatienceGame(){

}
