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
    int GetLives(){return lives_;};
    void RemoveLife(){lives_--;};
    QPixmap get_img(){return life_;};
signals:

private:
    QPixmap life_;
    int lives_ = 0;
};

#endif // LIFE_H
