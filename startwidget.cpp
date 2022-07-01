#include "startwidget.h"
#include "ui_startwidget.h"
#include "loginwidget.h"
#include "registerwidget.h"
startwidget::startwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startwidget)
{
    ui->setupUi(this);
    loginWidget = new loginwidget();
    registerWidget = new registerwidget();

    ui->tabWidget->addTab(loginWidget, QString("登录"));
    ui->tabWidget->addTab(registerWidget,QString("注册"));

    ui->tabWidget->setCurrentIndex(0);
}

startwidget::~startwidget()
{
    delete ui;

}

void startwidget::receiveHide(){
    this->hide();
}
