#ifndef WASH_H
#define WASH_H

#include <QMainWindow>

namespace Ui {
class wash;
}

class wash : public QMainWindow
{
    Q_OBJECT

public:
    explicit wash(QWidget *parent = nullptr);
    ~wash();

private:
    Ui::wash *ui;
};

#endif // WASH_H
