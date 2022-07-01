#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "buywidget.h"
#include "memberwidget.h"
#include "aboutus.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QWidget* tabWidgetList[3];
    const char* tabWidgetTitleList[3] = {"进货", "会员管理", "关于作者"};
};

#endif // MAINWINDOW_H
