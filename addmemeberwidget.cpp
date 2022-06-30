#include "addmemeberwidget.h"
#include "ui_addmemeberwidget.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
addmemeberwidget::addmemeberwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addmemeberwidget)
{
    ui->setupUi(this);
}

addmemeberwidget::~addmemeberwidget()
{
    delete ui;
}

// 添加会员
void addmemeberwidget::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString tel = ui->lineEdit_2->text();
    int gender = ui->comboBox->currentIndex();

    // 校验合法性
    if (name.isEmpty()||tel.isEmpty()||gender==0) {
        QMessageBox::warning(this,"提示", "表单不能为空！", QMessageBox::Close);
    } else {
        QString genderString = gender == 1 ? "男" : "女";
        QSqlQuery query;
        query.prepare("INSERT INTO member (id, owner, gender, telphone, create_time)\
         VALUES (null, ?, ?, ?, datetime('now','localtime'));");
        query.bindValue(0, name);
        query.bindValue(1, genderString);
        query.bindValue(2, tel);

        if (!query.exec()) { // 如果执行失败，就操作
             qDebug() << Q_FUNC_INFO << query.lastError().text() << query.lastQuery();
        } else {
            QMessageBox::information(this,"提示", "添加成功！", QMessageBox::Close);
            this->close();
        }
    }
}
