#include "memberwidget.h"
#include "ui_memberwidget.h"
#include <QSqlRecord>
#include <QDebug>
#include "addmemeberwidget.h"
#include "genderbuttondelegate.h"
#include "readonlydelegate.h"
memberwidget::memberwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memberwidget)
{

    ui->setupUi(this);
    memberModel = new QSqlTableModel(this);
    addMemeberWidget = new addmemeberwidget();
    memberModel->setTable("member");
    memberModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    memberModel->select();

    for (int i=0;i<5;i++){
        memberModel->setHeaderData(i, Qt::Horizontal, tr(tableColumnConfig[i]));
    }

    ui->tableView->setModel(memberModel);
    for (int i=0;i<5;i++){ ui->tableView->setColumnWidth(i, tableColumnWidth[i]); }
    ui->tableView->setItemDelegateForColumn(0, new ReadOnlyDelegate(this)); // 编号列不可修改
    ui->tableView->setItemDelegateForColumn(4, new ReadOnlyDelegate(this)); // 创建时间列不可修改
    ui->tableView->setItemDelegateForColumn(2, new GenderButtonDelegate(this)); // 修改时变为下拉列表
}

memberwidget::~memberwidget()
{
    delete ui;
}

// 重置筛选条件
void memberwidget::on_pushButton_clicked()
{
    ui->comboBox->setCurrentIndex(0); // 性别下拉菜单调到空
    ui->lineEdit->clear(); // 清空文本框
    ui->lineEdit_2->clear();// 清空文本框
}

// 添加会员
void memberwidget::on_pushButton_3_clicked()
{
    addMemeberWidget->setWindowModality(Qt::ApplicationModal);
    addMemeberWidget->show();
}
