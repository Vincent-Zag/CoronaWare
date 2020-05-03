#include "disinfect.h"

Disinfect::Disinfect(int width, int height)
{
    background_ = new QImage(":/assets/img/sick village.png");
    * background_= background_->scaled(width,height);
    this ->populate(width,height);
}

void Disinfect::populate(int width, int height){
    int value=(qrand()%4)+3;
    for(int i=0; i<value; i++){
        int cell_w= qrand()%width;
        int cell_h= qrand()%height;
        cells_.push_back(new Corona(cell_w,cell_h));
        qDebug() <<"cell_w is"<< cell_w<<"cell_h is"<<cell_h;
    }
}



