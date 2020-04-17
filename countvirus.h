#ifndef COUNTVIRUS_H
#define COUNTVIRUS_H

#include <QMainWindow>

namespace Ui {
class CountVirus;
}

class CountVirus : public QMainWindow
{
    Q_OBJECT

public:
    explicit CountVirus(QWidget *parent = nullptr);
    ~CountVirus();

private:
    Ui::CountVirus *ui;
};

#endif // COUNTVIRUS_H
