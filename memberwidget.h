#ifndef MEMBERWIDGET_H
#define MEMBERWIDGET_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class memberwidget;
}

class memberwidget : public QWidget
{
    Q_OBJECT
public:
    explicit memberwidget(QWidget *parent = 0);
    ~memberwidget();



private slots:
    void on_pushButton_clicked();

private:
    Ui::memberwidget *ui;
    QSqlTableModel* memberModel;
    const char* tableColumnConfig[5] = {"编号", "持卡人", "性别", "手机号", "创建时间"};
    const int tableColumnWidth[5] = {27,33,33,69,135};
};

// 自定义表格内容



#endif // MEMBERWIDGET_H
