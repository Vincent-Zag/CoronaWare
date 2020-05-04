#ifndef SCORE_H
#define SCORE_H

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



class Score : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Score(bool wario_dance, bool wario_unhappy, int cells, QColor color, bool happy, bool cheer, bool score_zero, int width, int height);

    void populate(int cells, int width, int height);

    QMovie * get_wariodance() {return wario_dance_;};
    QPixmap get_wariounhappy() {return wario_unhappy_;};
    std::vector<Corona *> get_cells(){return cells_;};
    QColor get_color() {return color_;};
    QMediaPlayer * get_sound() {return sound_;};
    QMediaPlayer * get_song() {return song_;};

private:
    QMovie * wario_dance_;
    QPixmap wario_unhappy_;
    std::vector<Corona *> cells_;
    QColor color_;
    QMediaPlayer * sound_;
    QMediaPlayer * song_;


};

class ScoreFactory {
public:

  static Score * GetGood(int width, int height){
    Score * Good= new Score(true,false,0, QColor(0,255,0), true, true, false, width, height);
    return Good;
  }


  static Score * GetMeh(int width, int height){
    Score * Meh= new Score(true,false,3, QColor(0,255,0), false, true, false, width, height);
    return Meh;
  }


  static Score * GetBad(int width, int height){
    Score * Bad= new Score(false,true,10, QColor(255,0,0), false, false, true, width, height);
    return Bad;
  }

};


#endif // SCORE_H
