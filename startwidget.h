#ifndef STARTWIDGET_H
#define STARTWIDGET_H


#include <QWidget>
#include "loginwidget.h"
#include "registerwidget.h"
namespace Ui {
class startwidget;
}

class startwidget : public QWidget
{
    Q_OBJECT

public:
    explicit startwidget(QWidget *parent = 0);
    ~startwidget();

private:
    Ui::startwidget *ui;
    QWidget* loginWidget;
    QWidget* registerWidget;
};

#endif // STARTWIDGET_H
