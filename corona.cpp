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


Corona::Corona(int x, int y, QGraphicsScene * scene){
    this->scene_=scene;
    x_=x;
    y_=y;
//    img_.load(":/assets/img/corona virus.png");
//    img_ = img_.scaled(30, 30);
    QPixmap img(":/assets/img/corona virus.png");
    setPixmap(img);
    setPos(x, y);
}

void Corona::mousePressEvent(QGraphicsSceneMouseEvent *event){
    this->scene_->removeItem(this);
}
