#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 定义窗口
    tabWidgetList[0] = new sellwidget();
    tabWidgetList[1] = new buywidget();
    tabWidgetList[2] = new memberwidget();
    tabWidgetList[3] = new aboutus();

    // 循环加入页面
    for (int i=0;i<4;i++){
        ui->tabWidget->addTab(tabWidgetList[i], QString(tabWidgetTitleList[i]));
    }

    //设置默认页面
    ui->tabWidget->setCurrentIndex(2);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    qDebug() << "切换到了："<< index << endl;
}
