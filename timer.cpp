#include "timer.h"
#include <QDebug>

Timer::Timer(int x, int y, int image){
    switch(image){
        case 0 :
            timer_.load(":/assets/img/zero_timer.png");
            break;
        case 1 :
            timer_.load(":/assets/img/one_timer.png");
            break;
        case 2 :
            timer_.load(":/assets/img/two_timer.png");
            break;
        case 3 :
             timer_.load(":/assets/img/three_timer.png");
             break;
        case 4 :
             timer_.load(":/assets/img/four_timer.png");
             break;
        case 5 :
             timer_.load(":/assets/img/five_timer.png");
             break;
    }
    timer_ = timer_.scaled(100, 100);
    setPixmap(timer_);
    setPos(x,y);
}
