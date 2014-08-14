#include "tray_menu.h"
#include <QtGui>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QWidget>
#include <QSize>


QString days;

Tray_Menu::Tray_Menu(QWidget *parent) :
    QSystemTrayIcon(parent)
{
    Create_Action();
    translateLanguage();
}
void Tray_Menu::Create_Action()
{
    this->setIcon(QIcon(":/logo/logo"));
    days = "0 3 1 6 ";
    tray_menu_keven = new QMenu();
    tray_menu_keven_two = new QMenu();
    Up_Widget = new QWidget();
    Action_Up = new QWidgetAction(tray_menu_keven); //Up
    Up_label = new QLabel();
    Bottom_label = new QLabel();
    /* * * * * * * * * * * * * * * * * * * * */
    Action_Open = new QAction(this);
    Action_Login = new QAction(this);
    Action_Dai = new QAction(this);
    Action_information = new QAction(this);
    ACtion_Device = new QAction(this);
    Action_Setting = new QAction(this);
    Action_quit = new QAction(this);
    Action_Update = new QAction(this);
    Action_Download = new QAction(this);

    Up_label->setFixedSize(136,35);
    Bottom_label->setFixedSize(136,35);
    //Add ICON
    Action_Open->setIcon(QIcon(":/TrayMenu/open"));
    Action_Setting->setIcon(QIcon(":/TrayMenu/setting"));
    tray_menu_keven_two->setIcon(QIcon(":/TrayMenu/update"));
    Action_Login->setIcon(QIcon(":/TrayMenu/login"));
    Action_quit->setIcon(QIcon(":/TrayMenu/quit"));
    Action_Update->setIcon(QIcon(":/TrayMenu/update_mgr"));
    Up_label->setStyleSheet("font:11pt; color:white;");
    Bottom_label->setStyleSheet("font:22pt;color:white;");

    Up_label->setAlignment(Qt::AlignBottom);
    Bottom_label->setAlignment(Qt::AlignLeft|Qt::AlignBottom);
    /*layout */

    QVBoxLayout *uP_Layout = new QVBoxLayout();
    uP_Layout->addWidget(Up_label,Qt::AlignLeft);
    uP_Layout->addWidget(Bottom_label,Qt::AlignLeft);
    uP_Layout->addSpacing(0);
    uP_Layout->setContentsMargins(0,0,0,0);

    Up_Widget->setLayout(uP_Layout);
    Action_Up->setDefaultWidget(Up_Widget);

    //添加菜单项
//    tray_menu_keven->addAction(Action_Up);
    tray_menu_keven->addSeparator();
    tray_menu_keven->addAction(Action_Open);
    tray_menu_keven->addAction(Action_Login);
    tray_menu_keven->addSeparator();
    tray_menu_keven->addAction(Action_Dai);
    tray_menu_keven->addAction(Action_information);
    tray_menu_keven->addAction(ACtion_Device);
    tray_menu_keven->addAction(Action_Setting);
    tray_menu_keven->addSeparator();
    tray_menu_keven->addMenu(tray_menu_keven_two);
    tray_menu_keven->addAction(Action_quit);
    tray_menu_keven_two->addAction(Action_Update);
    tray_menu_keven_two->addAction(Action_Download);

    _image.load(":/skin/24");
    Up_Widget->setAutoFillBackground(true);
    QPalette pal(Up_Widget->palette());
    pal.setBrush(QPalette::Window,
    QBrush(_image.scaled(Up_Widget->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    Up_Widget->setPalette(pal);

    connect(Action_quit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(Action_Open,SIGNAL(triggered()),this,SIGNAL(emit_open()));
    this->setContextMenu(tray_menu_keven);
}
void Tray_Menu::translateLanguage()
{
    this->setToolTip(tr("Main Menu"));
    Up_label->setText(tr("desk small go on your cpmputer"));
    Bottom_label->setText(days + tr("days"));
    Action_Open->setText(tr("Open"));
    Action_Dai->setText(tr("Action_Dai"));
    Action_information->setText(tr("Action_information"));
    ACtion_Device->setText(tr("ACtion_Device"));
    Action_Setting->setText(tr("Setting"));
    tray_menu_keven_two->setTitle(tr("Update"));
    Action_Update->setText(tr("Program Update"));
    Action_Login->setText(tr("UserLogin"));
    Action_quit->setText(tr("quit"));
    Action_Download->setText(tr("Download"));
}
