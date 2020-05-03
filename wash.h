#ifndef WASH_H
#define WASH_H

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

class Wash : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Wash(int width, int height);
    QPixmap get_img(){return img_;};
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void WashSelected(Wash * w);
private:
    QPixmap img_;
};

#endif // WASH_H
