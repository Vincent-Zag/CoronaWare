#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Timer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Timer(int x, int y, int image);
    QPixmap GetTimer(){return timer_;};
signals:

private:
    QPixmap timer_;
};

#endif // TIMER_H
