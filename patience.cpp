#include "patience.h"
#include "ui_patience.h"

patience::patience(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::patience)
{
    ui->setupUi(this);
    QPixmap qp(":/home/vincent/Documents/CSCI3010/HW5/WarioWare/assets/img/patience_background.png");
    ui->patience_background->setPixmap(qp);
}

patience::~patience()
{
    delete ui;
}
