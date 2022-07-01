#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class loginwidget;
}

class loginwidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginwidget(QWidget *parent = 0);
    ~loginwidget();

private slots:
    void on_pushButton_clicked();

signals:
    void hideWindow();

private:
    Ui::loginwidget *ui;
    QWidget* mw;
};

#endif // LOGINWIDGET_H
