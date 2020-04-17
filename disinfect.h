#ifndef DISINFECT_H
#define DISINFECT_H

#include <QMainWindow>

namespace Ui {
class disinfect;
}

class disinfect : public QMainWindow
{
    Q_OBJECT

public:
    explicit disinfect(QWidget *parent = nullptr);
    ~disinfect();

private:
    Ui::disinfect *ui;
};

#endif // DISINFECT_H
