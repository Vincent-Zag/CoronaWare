#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class life : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit life(QObject *parent = nullptr);
    life(int x, int y);
signals:

private:
    QPixmap life_;
};

#endif // LIFE_H
