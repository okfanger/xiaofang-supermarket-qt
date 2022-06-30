#ifndef BUYWIDGET_H
#define BUYWIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlTableModel>
namespace Ui {
class buywidget;
}

class buywidget : public QWidget
{
    Q_OBJECT

public:
    explicit buywidget(QWidget *parent = 0);
    ~buywidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::buywidget *ui;
    QSqlTableModel* model;
    const char* tableColumnConfig[4] = {"编号", "商品名称", "描述", "库存"};
    const int tableColumnWidth[4] = {27,87,143,44};
};

#endif // BUYWIDGET_H
