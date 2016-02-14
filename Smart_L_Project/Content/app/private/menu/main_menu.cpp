#include "main_menu.h"
#include <QDesktopServices>
#include <QFile>
#include <QUrl>

Main_Menu::Main_Menu(QWidget *widget) :
    QMenu(widget)
{
    menu_qss_init();
    menu_action_init();
    translates();
    setFixedWidth(125);

}
void Main_Menu::menu_qss_init()
{
    QString qss;
    QFile qssFile(":/qss/menu");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        setStyleSheet(qss);
        qssFile.close();
    }
}
void Main_Menu::menu_action_init()
{
    //创建菜单项
    A_advanced = new QAction(this);
    A_setting = new QAction(this);
    A_feature = new QAction(this);
    A_update = new QAction(this);
    A_help = new QAction(this);
    A_about = new QAction(this);

    //Set Ico
    A_advanced->setIcon(QIcon(":/Mainmenu/advanced"));
    A_setting->setIcon(QIcon(":/Mainmenu/setting"));
    A_feature->setIcon(QIcon(":/Mainmenu/feature"));
    A_update->setIcon(QIcon(":/Mainmenu/update"));
    A_help->setIcon(QIcon(":/Mainmenu/help"));
    A_about->setIcon(QIcon(":/Mainmenu/about"));

    //添加菜单项
    this->addAction(A_advanced);
    this->addAction(A_setting);
    this->addAction(A_update);
    this->addSeparator();
    this->addAction(A_feature);
    this->addAction(A_help);
    this->addAction(A_about);

    //设置信号连接
    QObject::connect(A_setting, SIGNAL(triggered()), this, SIGNAL(Show_Setting_Dialog_keven()));
    QObject::connect(A_feature, SIGNAL(triggered()), this, SIGNAL(Show_New_Charcter_keven()));
    QObject::connect(A_about, SIGNAL(triggered()), this, SIGNAL(About_me_show()));
    QObject::connect(A_help,SIGNAL(triggered()),this,SLOT(_360_Html()));
}
void Main_Menu::translates()
{
    this->setToolTip(tr("Main Menu"));
    A_advanced->setText(tr("Advanced"));
    A_setting->setText(tr("Setting"));
    A_update->setText(tr("Update"));
    A_feature->setText(tr("New Feature"));
    A_help->setText(tr("Help"));
    A_about->setText(tr("About Me"));
}
void Main_Menu::_360_Html()
{
    QDesktopServices::openUrl(QUrl("http://www.360.cn/"));
}
void Main_Menu::_Protect_360_Books()
{
    QDesktopServices::openUrl(QUrl("http://www.360.cn/privacy/v2/index.html"));
}
void Main_Menu::_Why_Free()
{
    QDesktopServices::openUrl(QUrl("http://se.360.cn/wel/whyFree.html"));
}
