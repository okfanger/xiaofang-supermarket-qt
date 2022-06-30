#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

namespace Ui {
class registerwidget;
}

class registerwidget : public QWidget
{
    Q_OBJECT

public:
    explicit registerwidget(QWidget *parent = 0);
    ~registerwidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registerwidget *ui;
};

#endif // REGISTERWIDGET_H
