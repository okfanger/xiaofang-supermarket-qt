#include "registerwidget.h"
#include "ui_registerwidget.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QCryptographicHash>  //md5加密的库
registerwidget::registerwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerwidget)
{
    ui->setupUi(this);
}

registerwidget::~registerwidget()
{
    delete ui;
}
// 注册
void registerwidget::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString repeatPassword = ui->lineEdit_3->text();

    if (username.isEmpty() || password.isEmpty() || repeatPassword.isEmpty()) { // 判空
        QMessageBox::warning(this, "警告", "三个文本框不能为空！", QMessageBox::Close);
    } else if(password != repeatPassword) {
        QMessageBox::warning(this, "警告", "两次输入的密码不一致！", QMessageBox::Close);
    } else {
        // 算通过了，进行数据库操作
        // md5 加密，确保数据库中的密码不明文存储
        QByteArray str = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
        QString encodePassword = str.toHex();

        QSqlQuery query;
        query.prepare("insert into user(username, password) values(?, ?)");
        query.bindValue(0, username);
        query.bindValue(1, encodePassword);
        if (!query.exec()) { // 如果执行失败，就操作
             qDebug() << Q_FUNC_INFO << query.lastError().text() << query.lastQuery();
        } else {
            QMessageBox::information(this,"提示", "注册成功！", QMessageBox::Close);
        }
    }
}
