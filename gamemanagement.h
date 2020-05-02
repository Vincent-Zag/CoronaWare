#ifndef GAMEMANAGEMENT_H
#define GAMEMANAGEMENT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QTime>
#include <QTimer>
#include <QMovie>
#include <QMediaPlayer>
#include "life.h"
#include "timer.h"

class GameManagement: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    GameManagement();
    void DeleteLife();
    void Result(bool success);
    void ShowScore();
    void ShowTimer();
    void SetLife(int x, int y);
    int GetScore(){return score_;};
    Life *GetLife1(){return life1_;};
    Life *GetLife2(){return life2_;};
    Timer *GetTimer(int time){return timer_hands_[time];};
//public slots:
//    void ShowTimerSlot();

private:
    int score_;
    QTimer *time_;
    Life *life1_;
    Life *life2_;
    Timer *timer_hands_[6];
};

#endif // GAMEMANAGEMENT_H
