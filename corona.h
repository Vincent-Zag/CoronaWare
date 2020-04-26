#ifndef CORONA_H
#define CORONA_H

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

class Corona : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Corona(int x, int y);
    QPixmap get_img(){return img_;};


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void DeleteCell(Corona * c);

private:
    int x_;
    int y_;
    QPixmap img_;
};


#endif // CORONA_H
