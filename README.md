
![在这里插入图片描述](https://img-blog.csdnimg.cn/aec7872c240b44149940aa34eb859371.png)
Github: [https://github.com/okfanger/xiaofang-supermarket-qt](https://github.com/okfanger/xiaofang-supermarket-qt)
## 1. 项目速览
开发语言：QT 5.6.3
开发工具：QT Creator 4.0.3 (Community)
数据库：SQLite
耗时：一夜（23:00 ~ 第二天8:00）
## 2. 数据库表及记录
sqlconnection.h里`createDatabase()` 函数中已经包含有创建数据库的语句，并在main.cpp中执行。

```cpp
// sqlconnection.h
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
    return true;
}
```

```cpp
// main.cpp
int main(){
	...
    createConnection();
    ...
}
```


## 3. 主要功能
### 3.1 登录与注册

```cpp
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
//            emit hideWindow();
            mw->show();
        } else {
            QMessageBox::warning(this,"提示", "用户名或密码错误", QMessageBox::Close);
        }
    }
}
```

```cpp
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
```


### 3.2 主界面

```cpp
// mainwindow.h
...
private:
    Ui::MainWindow *ui;
    QWidget* tabWidgetList[3];
    const char* tabWidgetTitleList[3] = {"进货", "会员管理", "关于作者"};
```

```cpp
// mainwindow.cpp
...
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 定义窗口
    tabWidgetList[0] = new buywidget();
    tabWidgetList[1] = new memberwidget();
    tabWidgetList[2] = new aboutus();
    // 循环加入页面
    for (int i=0;i<3;i++){
        ui->tabWidget->addTab(tabWidgetList[i],QString(tabWidgetTitleList[i]));
    }
    //设置默认页面
    ui->tabWidget->setCurrentIndex(1);
}
...
```

### 3.3 会员管理
#### 3.3.1 增加信息（新）
```cpp
// 添加会员
void memberwidget::on_pushButton_3_clicked()
{
    addMemeberWidget->setWindowModality(Qt::ApplicationModal);
    addMemeberWidget->show(); // 另一个窗口
}
```

```cpp

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

```
#### 3.3.2 删除会员（删）

```cpp
// 删除
void memberwidget::on_pushButton_2_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    // 删除该行
    memberModel->removeRow(curRow);
    int ok = QMessageBox::warning(
                this,tr("删除当前行!"),
                tr("你确定删除当前行吗？"),
                QMessageBox::Yes,
                QMessageBox::No
            );
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        memberModel->revertAll();
    } else { // 否则提交，在数据库中删除该行
        memberModel->submitAll();
    }
}
```

#### 3.3.3 修改信息（改）
由于 `QSqlTableModel` 自带修改功能，所以我们所做的反而是禁止某些列的修改（比如ID，创建日期）。

```cpp
...
	// 编号列不可修改
    ui->tableView->setItemDelegateForColumn(0, new ReadOnlyDelegate(this)); 
    // 创建时间列不可修改
    ui->tableView->setItemDelegateForColumn(4, new ReadOnlyDelegate(this)); 
    // 修改时变为下拉列表
    ui->tableView->setItemDelegateForColumn(2, new GenderButtonDelegate(this)); 
```


#### 3.3.1 筛选（查）

```cpp
// 重置筛选条件
void memberwidget::on_pushButton_clicked()
{
    ui->comboBox->setCurrentIndex(0); // 性别下拉菜单调到空
    ui->lineEdit->clear(); // 清空文本框
    ui->lineEdit_2->clear();// 清空文本框
}
// 三条件筛选
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
```

### 3.4 进货出货
这个看一乐就行，主要是没时间做了。。。

```cpp
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
```
