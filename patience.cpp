#include "patience.h"
#include "ui_patience.h"

patience::patience(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::patience)
{
    ui->setupUi(this);
}

patience::~patience()
{
    delete ui;
}
