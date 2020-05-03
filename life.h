#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Life : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Life(int x, int y);
    QPixmap get_img(){return life_;};
signals:

private:
    QPixmap life_;
};

#endif // LIFE_H
