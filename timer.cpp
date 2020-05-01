#include "timer.h"
#include <QDebug>

Timer::Timer(int x, int y, int image){
    switch(image){
        case 1 :
            timer_.load(":/assets/img/zero_timer.png");
            qDebug() << "zero hand";
        case 2 :
            timer_.load(":/assets/img/one_timer.png");
            qDebug() << "one hand";
        case 3 :
            timer_.load(":/assets/img/two_timer.png");
            qDebug() << "two hand";
        case 4 :
             timer_.load(":/assets/img/three_timer.png");
             qDebug() << "three hand";
        case 5 :
             timer_.load(":/assets/img/four_timer.png");
             qDebug() << "four hand";
        case 6 :
             timer_.load(":/assets/img/five_timer.png");
             qDebug() << "five hand";
    }
    timer_ = timer_.scaled(100, 100);
    setPixmap(timer_);
    setPos(x,y);
}
