#include "memberwidget.h"
#include "ui_memberwidget.h"
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
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

void memberwidget::on_pushButton_2_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    // 删除该行
    memberModel->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        memberModel->revertAll();
    } else { // 否则提交，在数据库中删除该行
        memberModel->submitAll();
    }
}

void memberwidget::on_pushButton_5_clicked()
{
    memberModel->revertAll();
}

void memberwidget::on_pushButton_4_clicked()
{
    memberModel->database().transaction();
    if (memberModel->submitAll()){
        if (memberModel->database().commit()){
            QMessageBox::information(this, tr("tableModel"), tr("数据修改成功"));
        } else {
            memberModel->database().rollback();
            QMessageBox::warning(this, tr("tableModel"), tr("数据库错误：：%1").arg(memberModel->lastError().text()),
                                 QMessageBox::Ok);
        }
    }
}
void memberwidget::selectByFilter(){
    int gender = ui->comboBox->currentIndex();
    QString owner = ui->lineEdit->text();
    QString tel = ui->lineEdit_2->text();

    bool genderOn = gender != 0;
    bool ownerOn = !owner.isEmpty();
    bool telOn = !tel.isEmpty();

    QString querySQL = "1 = 1";

    if (genderOn) querySQL.append(QString(" and gender = '%1'").arg(gender == 1?"男":"女"));
    if (ownerOn) querySQL.append(QString(" and owner like '%%1%'").arg(owner));
    if (telOn) querySQL.append(QString(" and telphone like '%%1%'").arg(tel));

    memberModel->setFilter(querySQL);
    qDebug() <<"SQL语句："<<querySQL<<"\n";
    memberModel->select();
}

void memberwidget::on_comboBox_currentIndexChanged(int index)
{
    memberwidget::selectByFilter();
}

void memberwidget::on_lineEdit_textChanged(const QString &arg1)
{
    memberwidget::selectByFilter();
}

void memberwidget::on_lineEdit_2_textChanged(const QString &arg1)
{
    memberwidget::selectByFilter();
}
