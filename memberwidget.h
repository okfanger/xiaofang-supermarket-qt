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

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void selectByFilter();
private:
    Ui::memberwidget *ui;
    QSqlTableModel* memberModel;
    const char* tableColumnConfig[5] = {"编号", "持卡人", "性别", "手机号", "创建时间"};
    const int tableColumnWidth[5] = {27,33,33,69,135};

    QWidget* addMemeberWidget;
};

// 自定义表格内容



#endif // MEMBERWIDGET_H
