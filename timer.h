#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QPixmap>

class timer : public QObject
{
    Q_OBJECT
public:
    explicit timer(QObject *parent = nullptr);
    timer(int x, int y);
signals:

private:
    int x_;
    int y_;
    QPixmap img_;
};

#endif // TIMER_H
