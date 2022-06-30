#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

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

private:
    Ui::loginwidget *ui;
    QWidget* mw;
};

#endif // LOGINWIDGET_H
