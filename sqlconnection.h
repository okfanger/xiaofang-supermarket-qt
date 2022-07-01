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

    query.exec("INSERT INTO member (id, owner, gender, telphone, create_time) \
        VALUES (1, '小方', '男', '18547756666', '2019-08-20 13:12:00');");
    query.exec("INSERT INTO member (id, owner, gender, telphone, create_time) \
        VALUES (2, '小红', '女', '18547757777', '2022-03-24 14:12:10');");
    query.exec("INSERT INTO member (id, owner, gender, telphone, create_time) \
        VALUES (3, '小蓝', '女', '18547758888', '2013-01-26 16:12:44');");
    query.exec("INSERT INTO member (id, owner, gender, telphone, create_time) \
        VALUES (4, '胖虎', '男', '18547759999', '2011-08-11 09:12:51');");
    query.exec("INSERT INTO member (id, owner, gender, telphone, create_time) \
        VALUES (5, '大绿', '男', '18547750000', '2021-05-26 05:12:09');");


    query.exec("INSERT INTO goods (id, name, description, store)\
         VALUES (1, '苹果', '好吃又好喝！', 99);");
    query.exec("INSERT INTO goods (id, name, description, store)\
         VALUES (2, '苏打饼干', '营养餐早餐代餐点心休闲零食下午茶', 20);");
    query.exec("INSERT INTO goods (id, name, description, store)\
         VALUES (3, '雀巢脆脆鲨', '香浓酥脆巧克力威化，独立便携小包装，随食击退小饥饿。', 30);");
    query.exec("INSERT INTO goods (id, name, description, store)\
         VALUES (4, '百吉福', '满满一杯纯正芝士', 10);");
    query.exec("INSERT INTO goods (id, name, description, store)\
         VALUES (5, '每日鲜语鲜牛奶', '每日鲜语原生高品质鲜牛奶是中国高端鲜奶品牌。', 5);");

//    query.exec("INSERT INTO user (id, username, password) VALUES (1, 'admin', '123456');");
    return true;
}
