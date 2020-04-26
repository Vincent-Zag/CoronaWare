#include "life.h"

life::life(int x, int y){
    life_.load(":/assets/img/toilet paper.png");
    life_ = life_.scaled(100, 100);
    setPixmap(life_);
    setPos(x,y);
}
