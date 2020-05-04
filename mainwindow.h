#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsItem>

#include "corona.h"
#include "patience.h"
#include "wash.h"
#include "disinfect.h"
#include "score.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Games();
private slots:
    // default slot that reacts to random button being clicked
    void CoronaSelectedSlot(Corona * c);
    void PatienceSelectedSlot(Patience * p);
    void WashSelectedSlot(Wash * w);
    void DisinfectGameSlot(Disinfect * d);


    void on_startButton_clicked();

    void ShowCountdownTimerSlot();

    void DisinfectGame();

    void CountGame();

    void PhasePassed();

    void PhaseFailed();

    void PatienceGame();

    void WashGame();

    void MainMenu();

    void RandomHelper();

    void on_continue_button_clicked();

    void ShowScore();

    void on_countradio1_clicked();

    void on_countradio2_clicked();

    void on_countradio3_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene_;
    QGraphicsScene *managementScene_;
    int height_;
    int width_;
    int repeat_ = 5;
    int amount_;
    int lives_=2;
    bool beat_;
    int corona_num_=0;
    int score_ = 0;
    std::string score_text_;
    QTimer *time_ = new QTimer(this);
};
#endif // MAINWINDOW_H
