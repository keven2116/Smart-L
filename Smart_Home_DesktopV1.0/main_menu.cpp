#include "main_menu.h"
#include <QDesktopServices>
#include <QUrl>

Main_Menu::Main_Menu(QWidget *widget) :
    QMenu(widget)
{
    Create_Actions_keven();
    translateActions();
}
Main_Menu::~Main_Menu()
{

}
void Main_Menu::Create_Actions_keven()
{
    //创建菜单项
    Action_uniq = new QAction(this);
    Action_sort = new QAction(this);
    Action_download_list = new QAction(this);
    Action_rename_list = new QAction(this);
    Action_delete_list = new QAction(this);
    Action_restore_listr = new QAction(this);
    Action_delete_choice = new QAction(this);
    Action_delete_error = new QAction(this);
    Action_clear_list = new QAction(this);

    //Set Ico
//    Action_uniq->setIcon(QIcon(":/mainMenu/setting"));
//    Action_sort->setIcon(QIcon(":/mainMenu/feature"));
//    Action_download_list->setIcon(QIcon(":/mainMenu/update"));
//    Action_rename_list->setIcon(QIcon(":/mainMenu/ent"));
//    Action_delete_list->setIcon(QIcon(":/mainMenu/help"));
//    Action_restore_listr->setIcon(QIcon(":/mainMenu/forum"));
//    Action_delete_choice->setIcon(QIcon(":/mainMenu/home"));
//    Action_delete_error->setIcon(QIcon(":/mainMenu/private"));
//    Action_clear_list->setIcon(QIcon(":/mainMenu/why_free"));

    //添加菜单项
    this->addAction(Action_uniq);
    this->addAction(Action_sort);
    this->addAction(Action_download_list);
    this->addSeparator();
    this->addAction(Action_rename_list);
    this->addAction(Action_delete_list);
    this->addAction(Action_restore_listr);
    this->addSeparator();
    this->addAction(Action_delete_choice);
    this->addAction(Action_delete_error);
    this->addAction(Action_clear_list);

    //设置信号连接
    QObject::connect(Action_uniq, SIGNAL(triggered()), this, SIGNAL(Sig_uniq()));
    QObject::connect(Action_sort, SIGNAL(triggered()), this, SIGNAL(Sig_sort()));
    QObject::connect(Action_download_list, SIGNAL(triggered()), this, SIGNAL(Sig_download()));
//    QObject::connect(Action_360_Html,SIGNAL(triggered()),this,SLOT(_360_Html()));
//    QObject::connect(Action_Free,SIGNAL(triggered()),this,SLOT(_Why_Free()));
//    QObject::connect(Action_Protect,SIGNAL(triggered()),this,SLOT(_Protect_360_Books()));

    this->setStyleSheet("background-color:white;color:gray;");
}
void Main_Menu::translateActions()
{
    this->setToolTip(tr("Main Menu"));
    Action_uniq->setText(tr("Current List uniq"));
    Action_sort->setText(tr("Song Sort"));
    Action_download_list->setText(tr("Download Current list all song"));
    Action_rename_list->setText(tr("Rename List"));
    Action_delete_list->setText(tr("Delete List"));
    Action_restore_listr->setText(tr("Restore List"));
    Action_delete_choice->setText(tr("Delete choice song"));
    Action_delete_error->setText(tr("Delete Error Song"));
    Action_clear_list->setText(tr("Clear Current List"));
}
//void Main_Menu::_360_Html()
//{
//    QDesktopServices::openUrl(QUrl("http://www.360.cn/"));
//}
//void Main_Menu::_Protect_360_Books()
//{
//    QDesktopServices::openUrl(QUrl("http://www.360.cn/privacy/v2/index.html"));
//}
//void Main_Menu::_Why_Free()
//{
//    QDesktopServices::openUrl(QUrl("http://se.360.cn/wel/whyFree.html"));
//}
