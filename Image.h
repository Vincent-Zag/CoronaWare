#ifndef IMAGE_H
#define IMAGE_H
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


class Image: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    public:
        Image();
        QPixmap get_pixmap(){return * pixmap_;};
    private:
        QPixmap * pixmap_;
};


#endif // IMAGE_H
