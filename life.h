#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QPixmap>

class life : public QObject
{
    Q_OBJECT
public:
    explicit life(QObject *parent = nullptr);
    life(int x, int y);
signals:

private:
    int x_;
    int y_;
    QPixmap img_;
};

#endif // LIFE_H
