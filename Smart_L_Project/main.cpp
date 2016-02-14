#include "main_widget.h"
#include "Content/app/private/login/login.h"
#include <QApplication>
#include <QTranslator>
#include <QPointer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(QString(":/qm/home_zh_CN"));
    a.installTranslator(&translator);

    Main_Widget w;
    //Login w;
    w.show();

    return a.exec();
}
