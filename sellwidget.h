#ifndef SELLWIDGET_H
#define SELLWIDGET_H

#include <QWidget>

namespace Ui {
class sellwidget;
}

class sellwidget : public QWidget
{
    Q_OBJECT

public:
    explicit sellwidget(QWidget *parent = 0);
    ~sellwidget();

private:
    Ui::sellwidget *ui;
};

#endif // SELLWIDGET_H
