#ifndef PATIENCE_H
#define PATIENCE_H

#include <QObject>
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

class Patience : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Patience(int x, int y);
    QPixmap get_img(){return img_;};
    bool IsCorrect(int moved);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPixmap img_;
    bool life_lost_;
};

#endif // PATIENCE_H
