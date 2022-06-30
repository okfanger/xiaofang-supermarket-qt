#include "sellwidget.h"
#include "ui_sellwidget.h"

sellwidget::sellwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sellwidget)
{
    ui->setupUi(this);
}

sellwidget::~sellwidget()
{
    delete ui;
}
