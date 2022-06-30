#include "buywidget.h"
#include "ui_buywidget.h"

buywidget::buywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buywidget)
{
    ui->setupUi(this);
}

buywidget::~buywidget()
{
    delete ui;
}
