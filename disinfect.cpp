#include "disinfect.h"

Disinfect::Disinfect(int width, int height)
{
//    background_ = new QImage(":/assets/img/sick village.png");
//    * background_= background_->scaled(width,height);
//    this ->populate(width,height);
//    //emit LostTheMiniGame(this);
    background_.load(":/assets/img/sick village.png");
    background_ = background_.scaled(width, height);
    setPos(0,0);
    setPixmap(background_);
    this->populate(width,height);
}

void Disinfect::populate(int width, int height){
    int value=(qrand()%4)+3;
    for(int i=0; i<value; i++){
        int cell_w= qrand()%(width-100);
        int cell_h= qrand()%(height-100);
        cells_.push_back(new Corona(cell_w,cell_h));
    }
}

void Disinfect::mousePressEvent(QGraphicsSceneMouseEvent *event){
   emit LostTheMiniGame(this);
}



