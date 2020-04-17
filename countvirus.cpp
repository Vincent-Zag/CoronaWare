#include "countvirus.h"
#include "ui_countvirus.h"

CountVirus::CountVirus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountVirus)
{
    ui->setupUi(this);
}

CountVirus::~CountVirus()
{
    delete ui;
}
