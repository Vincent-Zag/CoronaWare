#ifndef PATIENCE_H
#define PATIENCE_H

#include <QMainWindow>

namespace Ui {
class patience;
}

class patience : public QMainWindow
{
    Q_OBJECT

public:
    explicit patience(QWidget *parent = nullptr);
    ~patience();

private:
    Ui::patience *ui;
};

#endif // PATIENCE_H
