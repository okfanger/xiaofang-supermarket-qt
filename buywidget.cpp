#include "buywidget.h"
#include "ui_buywidget.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include "readonlydelegate.h"
buywidget::buywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buywidget)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("goods");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select();

    for (int i=0;i<4;i++){
        model->setHeaderData(i, Qt::Horizontal, tr(tableColumnConfig[i]));
    }
    ui->tableView->setModel(model);
    for (int i=0;i<4;i++){ ui->tableView->setColumnWidth(i, tableColumnWidth[i]); }
    ui->tableView->setItemDelegateForColumn(0, new ReadOnlyDelegate(this)); // 编号列不可修改
    ui->tableView->setItemDelegateForColumn(1, new ReadOnlyDelegate(this)); // 创建时间列不可修改
    ui->tableView->setItemDelegateForColumn(2, new ReadOnlyDelegate(this)); // 创建时间列不可修改
    ui->tableView->setItemDelegateForColumn(3, new ReadOnlyDelegate(this));
}
buywidget::~buywidget()
{
    delete ui;
}
//进货
void buywidget::on_pushButton_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    auto oldValue = model->record(curRow).value(QString("store")).toInt();
    auto newValue = oldValue + 1;
    model->setData(model->index(curRow, 3), QVariant(newValue));//重新设置当前单元格内容
}
//出货
void buywidget::on_pushButton_2_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    auto oldValue = model->record(curRow).value(QString("store")).toInt();
    auto newValue = (oldValue - 1>0)?oldValue - 1:0;
    model->setData(model->index(curRow, 3), QVariant(newValue));//重新设置当前单元格内容
}
