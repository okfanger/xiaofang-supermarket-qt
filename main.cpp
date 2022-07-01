#include "startwidget.h"
#include "loginwidget.h"
#include <QApplication>
#include <sqlconnection.h>
int main(int argc, char *argv[])
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif
    QApplication a(argc, argv);
    createConnection();
//    MainWindow w;
//    w.show();
    startwidget w;
    w.show();
    loginwidget loginWidget;
    QObject::connect(&loginWidget, SIGNAL(hideWindow),&w,SLOT(receiveHide()));
    return a.exec();
}
