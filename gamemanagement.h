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
    void ShowTimer();
    void SetLife(int value);
    Life *GetLife1(){return life1_;};
    Life *GetLife2(){return life2_;};
    int GetLives(){return lives_;};
    Timer *GetTimer(int time){return timer_hands_[time];};

private:
    QTimer *time_;
    Life *life1_;
    Life *life2_;
    Timer *timer_hands_[6];
    int lives_= 2;
};

#endif // GAMEMANAGEMENT_H
