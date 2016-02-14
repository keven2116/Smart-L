#include "util.h"
#include <QSettings>
#include <QDebug>
#include <QFontMetrics>
bool Util::WriteInit(QString path, QString user_key, QString user_value)
{
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }
    else
    {
        QSettings *config = new QSettings(path,QSettings::IniFormat);

        config->beginGroup("passwd");
        config->setValue(user_key,user_value);
        config->endGroup();

        return true;
    }
}
bool Util::ReadInit(QString path, QString user_key, QString &user_value)
{
    user_value = QString("");
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }
    else
    {
        QSettings *config = new QSettings(path,QSettings::IniFormat);
        user_value = config->value(QString("passwd/") + user_key).toString();
   //     qDebug() << user_value;
        return true;
    }
}
bool Util::updateText(QString text, int max_width, QString &elided_text)
{
    elided_text = QString("");
    if(text.isEmpty() || max_width <= 0)
    {
        return false;
    }

    QFont ft;
    QFontMetrics fm(ft);
    elided_text = fm.elidedText(text, Qt::ElideRight, max_width);

    return true;
}
QString Util::getSkinName()
{
    QString skin_name = (":/skin/default");
 //   bool is_read = Util::ReadInit(QString("./user.ini"), QString("skin"), skin_name);

    return skin_name;
}
