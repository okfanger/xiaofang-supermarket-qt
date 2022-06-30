#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QCryptographicHash>  //md5加密的库

loginwidget::loginwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwidget)
{
    ui->setupUi(this);
    mw = new mainwindow();
}

loginwidget::~loginwidget()
{
    delete ui;
}
// 登录
void loginwidget::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username.isEmpty() || password.isEmpty()) { // 判空
        QMessageBox::warning(this, "警告", "用户名或密码不能为空！", QMessageBox::Close);
    } else {
        // 算通过了，进行数据库操作
        // md5 加密，确保数据库中的密码不明文存储
        QByteArray str = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
        QString encodePassword = str.toHex();

        QSqlQuery query;
        query.prepare("select * from user where username = ? and password = ?");
        query.bindValue(0, username);
        query.bindValue(1, encodePassword);
        if (!query.exec()) { // 如果执行失败，就操作
             qDebug() << Q_FUNC_INFO << query.lastError().text() << query.lastQuery();
        } else if(query.next()) {
            QMessageBox::information(this,"提示", "登录成功！", QMessageBox::Close);
            this->hide();
            mw->show();
        } else {
            QMessageBox::warning(this,"提示", "用户名或密码错误", QMessageBox::Close);
        }
    }

}
