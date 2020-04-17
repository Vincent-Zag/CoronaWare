#include "disinfect.h"
#include "ui_disinfect.h"

disinfect::disinfect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::disinfect)
{
    ui->setupUi(this);
}

disinfect::~disinfect()
{
    delete ui;
}
