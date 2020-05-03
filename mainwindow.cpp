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
    sound->setVolume(5);
    sound->play();


    Corona * c1 = new Corona(400,100);
    scene_->addItem(c1);

    connect(c1, &Corona::DeleteCell, this, &MainWindow::CoronaSelectedSlot);


    QMovie *wario_dance = new QMovie(":/assets/img/wario_dancing.gif");
    ui->wario_gif->setMovie(wario_dance);
    wario_dance->start();
    ui->wario_gif->close();
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));

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

    Wash *wash_game = new Wash(width_,height_);
    scene_->addItem(wash_game);

    lives_ = board->GetLives();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowCountdownTimerSlot(){
    GameManagement *board = new GameManagement();
    if (repeat_ == -1){
        repeat_ = 5;
        if(beat_){
            PhasePassed();
        }else{
            PhaseFailed();
        }
    }
    Timer *time = board->GetTimer(repeat_);
    managementScene_->addItem(time);
    repeat_--;
}

void MainWindow::CoronaSelectedSlot(Corona * c){

    scene_->removeItem(c);
    QMediaPlayer * sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/Corona/scream.wav"));
    sound->play();
}

void MainWindow::Games(){
    PatienceGame();
//    scene_->clear();
//    QImage *img = new QImage(":/assets/img/sick village.png");
//    *img = img->scaled(width_,height_);
//    QBrush bg_brush(*img);
//    scene_ ->setBackgroundBrush(bg_brush);
    //need to create a button for patience here
    //as well as a label to prompt patience...
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->close();
    QTimer *time_ = new QTimer(this);
    connect(time_,&QTimer::timeout,this,&MainWindow::ShowCountdownTimerSlot);
    time_->start(1000);
    this->Games();
}

void MainWindow::PhasePassed(){
    GameManagement *board = new GameManagement();
    QMediaPlayer * sound = new QMediaPlayer();
    QMediaPlayer * sound2 = new QMediaPlayer();
    QMediaPlayer * sound3 = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/Correct/win1.wav"));
    sound2->setMedia(QUrl("qrc:/assets/sound/Correct/correct.wav"));
    sound3->setMedia(QUrl("qrc:/assets/sound/Correct/cheering.wav"));
    sound->play();
    sound2->play();
    sound3->play();
    board->SetScore(1);
    std::string score = "Score: "+ std::to_string(board->GetScore());
    QString qscore(score.c_str());
    ui->score_label->setStyleSheet("background-color:rgba(0,0,0,0%)");
    ui->score_label->setText(qscore);
}

void MainWindow::PhaseFailed(){
    QMediaPlayer * sound = new QMediaPlayer();
    QMediaPlayer * sound2 = new QMediaPlayer();
    QMediaPlayer * sound3 = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/assets/sound/Incorrect/booing.wav"));
    sound2->setMedia(QUrl("qrc:/assets/sound/Incorrect/incorrect.wav"));
    sound3->setMedia(QUrl("qrc:/assets/sound/Incorrect/lose.wav"));
    sound->play();
    sound2->play();
    sound3->play();
}

void MainWindow::PatienceGame(){
    scene_->clear();
    managementScene_->clear();
    GameManagement *board = new GameManagement();
    Patience *patience_game = new Patience(width_,height_);

    connect(patience_game, &Patience::LostTheMiniGame, this, &MainWindow::PatienceSelectedSlot);

    scene_->addItem(patience_game);
    managementScene_->addItem(board);
    if (lives_ == 1){
        Life *life1 = board->GetLife1();
        managementScene_->addItem(life1);
    }else if(lives_ == 2){
        Life *life1 = board->GetLife1();
        managementScene_->addItem(life1);
        Life *life2 = board->GetLife2();
        managementScene_->addItem(life2);
    }
        beat_ = true;
}

void MainWindow::PatienceSelectedSlot(Patience * p){
    scene_->clear();
    managementScene_->clear();
    GameManagement *board = new GameManagement();
    QImage *img = new QImage(":/assets/img/cryguy.jpg");
    *img = img->scaled(width_,height_);
    QBrush bg_brush(*img);
    scene_ ->setBackgroundBrush(bg_brush);
    board->SetLife(-1);
    lives_ = board->GetLives();

    if (lives_ == 1){
        Life *life1 = board->GetLife1();
        managementScene_->addItem(life1);
    }
    beat_ = false;
}
