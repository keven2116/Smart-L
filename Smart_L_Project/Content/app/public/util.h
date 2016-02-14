#ifndef UTIL_H
#define UTIL_H

//#include <QtGui>
#include <QString>
class Util
{
public:
    static bool WriteInit(QString path,QString user_key,QString user_value);
    static bool ReadInit(QString path,QString user_key,QString &user_value);
    static bool updateText(QString text, int max_width, QString &elided_text);
    static QString getSkinName();
};

#endif // UTIL_H
