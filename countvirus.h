#ifndef COUNTVIRUS_H
#define COUNTVIRUS_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>
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
#include "disinfect.h"

//Reptile(std::string sound):
//Animal(sound + " rawr!")
//{}

class CountVirus: public Disinfect
{
    Q_OBJECT

public:
    CountVirus(int width, int height):
    Disinfect(width, height)
    {}

    QPixmap get_background(){return background_;};

    void populate(int width, int height) override;


};

#endif // DISINFECT_H
