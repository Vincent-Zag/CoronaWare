#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QTime>
#include <QTimer>
#include <QMovie>
#include <QMediaPlayer>

#include "corona.h"


Corona::Corona(int x, int y){
    x_=x;
    y_=y;
    img_.load(":/assets/img/corona virus.png");
    img_ = img_.scaled(100, 100);
    setPixmap(img_);
    setPos(x_,y_);
}

void Corona::mousePressEvent(QGraphicsSceneMouseEvent *event){
}
