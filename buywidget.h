#ifndef BUYWIDGET_H
#define BUYWIDGET_H

#include <QWidget>

namespace Ui {
class buywidget;
}

class buywidget : public QWidget
{
    Q_OBJECT

public:
    explicit buywidget(QWidget *parent = 0);
    ~buywidget();

private:
    Ui::buywidget *ui;
};

#endif // BUYWIDGET_H
