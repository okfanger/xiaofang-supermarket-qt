#ifndef ADDMEMEBERWIDGET_H
#define ADDMEMEBERWIDGET_H

#include <QWidget>

namespace Ui {
class addmemeberwidget;
}

class addmemeberwidget : public QWidget
{
    Q_OBJECT

public:
    explicit addmemeberwidget(QWidget *parent = 0);
    ~addmemeberwidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addmemeberwidget *ui;
};

#endif // ADDMEMEBERWIDGET_H
