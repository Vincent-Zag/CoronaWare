#include "wash.h"

Wash::Wash(int width, int height){
    img_.load(":/assets/img/handwash_background.jpg");
    img_ = img_.scaled(width, height);
    setPos(0,0);
    setPixmap(img_);
}

void Wash::mousePressEvent(QGraphicsSceneMouseEvent *event){
   emit LostTheMiniGame(this);
}
