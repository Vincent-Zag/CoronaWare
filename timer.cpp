#include "timer.h"

timer::timer(){
    timer_.load(":/assets/img/toilet paper.png");
    timer_ = timer_.scaled(100, 100);
    setPixmap(timer_);
    //setPos(x,y);
}
