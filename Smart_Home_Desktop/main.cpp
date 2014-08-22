#include "main_widget.h"
#include <QApplication>
#include <QTranslator>
#include <QPointer>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(QString(":/qm/home_zh_CN.qm"));
    a.installTranslator(&translator);

    Main_Widget w;/*
    w = new Main_Widget();*/
    w.show();
//    qInstallMessageHandler(outputMessage);

    return a.exec();
}
