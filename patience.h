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
    Patience(int width, int height);
    QPixmap get_img(){return img_;};
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void LostTheMiniGame(Patience * p);
private:
    QPixmap img_;
};

#endif // PATIENCE_H
