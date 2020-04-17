#ifndef CORONAVIRUS_H
#define CORONAVIRUS_H

#include <QObject>

class CoronaVirus : public QObject
{
    Q_OBJECT
public:
    explicit CoronaVirus(QObject *parent = nullptr);

signals:

};

#endif // CORONAVIRUS_H
