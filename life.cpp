#include "life.h"

Life::Life(int x, int y){
    life_.load(":/assets/img/toilet paper.png");
    life_ = life_.scaled(100, 100);
    setPos(x,y);
    setPixmap(life_);
}
