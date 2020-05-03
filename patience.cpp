#include "patience.h"

Patience::Patience(int width, int height){
    img_.load(":/assets/img/patience_background.jpg");
    img_ = img_.scaled(width, height);
    setPos(0,0);
    setPixmap(img_);
}

void Patience::mousePressEvent(QGraphicsSceneMouseEvent *event){
   emit LostTheMiniGame(this);
}
