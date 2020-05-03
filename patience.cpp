#include "patience.h"

Patience::Patience(int x, int y){
    img_.load(":/assets/img/patience_background.jpg");
    img_ = img_.scaled(1001, 561);
    setPos(x,y);
    setPixmap(img_);
}

void Patience::mousePressEvent(QGraphicsSceneMouseEvent *event){
   if(event->button() != Qt::NoButton){
        IsCorrect(0);
   }else{
        IsCorrect(1);
   }
}

bool Patience::IsCorrect(int moved){
    if (moved == 1){
        life_lost_ = true;
    }else{
        life_lost_ = false;
    }
}
