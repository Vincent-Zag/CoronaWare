#include "wash.h"
#include "ui_wash.h"

wash::wash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wash)
{
    ui->setupUi(this);
}

wash::~wash()
{
    delete ui;
}
