#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class timer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    timer();
    void setPos(int x, int y);
signals:

private:
    QPixmap timer_;
};

#endif // TIMER_H
