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
    int GetLives(){return lives_;};
    void SetLife(int x, int y);

private:
    int lives_;
    int score_;
    QTimer *time_;
    QPixmap life_;
    QPixmap time_hand_;
};

#endif // GAMEMANAGEMENT_H
