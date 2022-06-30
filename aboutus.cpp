#include "aboutus.h"
#include "ui_aboutus.h"

aboutus::aboutus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutus)
{
    ui->setupUi(this);
}

aboutus::~aboutus()
{
    delete ui;
}
