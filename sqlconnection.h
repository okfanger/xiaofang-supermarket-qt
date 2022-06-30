#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#endif // SQLCONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("supermarket.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE member (id INTEGER PRIMARY KEY AUTOINCREMENT, owner VARCHAR (20), gender VARCHAR, telphone VARCHAR (20), create_time DATETIME);");
    query.exec("CREATE TABLE goods (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR (20), \"description\" TEXT, store INTEGER);");
    query.exec("CREATE TABLE user (id INTEGER PRIMARY KEY AUTOINCREMENT, username VARCHAR (20), \"password\" VARCHAR (1024));");

    query.exec("INSERT INTO member (id, owner, gender, telphone, create_time) VALUES (1, '小方', '男', '18547756279', '2019-08-26 10:12:00 000000');");
    query.exec("INSERT INTO goods (id, name, description, store) VALUES (1, '苹果', '好吃又好喝！', 99);");
//    query.exec("INSERT INTO user (id, username, password) VALUES (1, 'admin', '123456');");
    return true;
}
