#include "tray_menu.h"
#include <QtGui>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QWidget>
#include <QSize>
#include <QDialog>


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

    tray_menu = new QMenu();
    tray_menu_update = new QMenu();
    Top_widget = new QWidget();
    Bottom_widget = new QWidget();

    Title_label = new QLabel();
    Title_label->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 170, 0, 255), stop:1 rgba(255, 255, 255, 255)); color:white;");
    Title_label->setFixedSize(200,60);
    Title_label->setAlignment(Qt::AlignCenter);

    QFont TitleFont("楷体", 12, QFont::Bold);
    Title_label->setText(tr("Welcome using Smart L"));
    Title_label->setFont(TitleFont);
    /* *middle* */
    Open_Btn = new Bottom_Btn();
    Information_Btn = new Bottom_Btn();
    Device_Status_Btn = new Bottom_Btn();
    Music_Btn = new Bottom_Btn();

    Open_Btn->Load_Bottom_img(":/TrayMenu/open",tr("open"),100,100,35);
    Information_Btn->Load_Bottom_img(":/TrayMenu/information",tr("information"),100,100,35);
    Device_Status_Btn->Load_Bottom_img(":/TrayMenu/device_status",tr("Status"),100,100,35);
    Music_Btn->Load_Bottom_img(":/TrayMenu/music",tr("Music"),100,100,45);

    Action_Top_widget = new QWidgetAction(tray_menu); //Up
    /*layout */
    middle_layout = new QGridLayout();
    middle_layout->addWidget(Open_Btn,0,0,Qt::AlignLeft);
    middle_layout->addWidget(Information_Btn,0,1,Qt::AlignLeft);
    middle_layout->addWidget(Device_Status_Btn,1,0,Qt::AlignLeft);
    middle_layout->addWidget(Music_Btn,1,1,Qt::AlignLeft);
    middle_layout->setContentsMargins(0,0,0,0);
    middle_layout->setMargin(0);
    middle_layout->setSpacing(0);

    menu_layout = new QVBoxLayout();
    menu_layout->addWidget(Title_label);
    menu_layout->addLayout(middle_layout);
    //menu_layout->setMargin(0);
    menu_layout->setContentsMargins(0,0,0,0);
    menu_layout->setSpacing(0);

    /*top*/
    Top_widget->setLayout(menu_layout);
    Top_widget->setStyleSheet("background-color:white");
    Action_Top_widget->setDefaultWidget(Top_widget);

    /*bottom*/
    Setting_Btn = new Bottom_Btn();
    Advancd_Btn = new Bottom_Btn();
    Quit_Btn = new Bottom_Btn();

    Setting_Btn->Load_Beside_img(":/TrayMenu/setting-hover",tr("set"),0,0,25);
    Advancd_Btn->Load_Beside_img(":/TrayMenu/advanced-hover",tr("advanced"),0,0,25);
    Quit_Btn->Load_Beside_img(":/TrayMenu/quit-hover",tr("quit"),0,0,25);

    A_update = new QAction(this);
    A_download = new QAction(this);

    tray_menu_update->setIcon(QIcon(":/TrayMenu/upgrade"));
    A_update->setIcon(QIcon(":/TrayMenu/update"));
    A_download->setIcon(QIcon(":/TrayMenu/downloader"));

    tray_menu_update->setTitle(tr("upgrade"));
    A_update->setText(tr("update"));
    A_download->setText(tr("downloader"));


    /*Switch init*/
    Switch_label_1 = new QLabel();
    Switch_label_2 = new QLabel();
    Switch_label_1->setText(tr("Speed"));
    //Switch_label_1->setAlignment(Qt::AlignCenter);
    Switch_label_1->setFixedSize(168 - 25 - 20,32);
    Switch_label_2->setText(tr("no"));
    Switch_label_2->setFixedSize(168 - 25 - 20,32);
    //Switch_label_2->setAlignment(Qt::AlignCenter);

    Switch_Btn_1 = new QPushButton();
    Switch_Btn_2 = new QPushButton();
    Switch_title_img_1 = new QPushButton();
    Switch_title_img_2 = new QPushButton();

    Switch_Btn_1->setIcon(QIcon(":/TrayMenu/switch_open"));
    Switch_Btn_1->setIconSize(QSize(32,32));
    Switch_Btn_1->setFlat(true);
    Switch_Btn_2->setIcon(QIcon(":/TrayMenu/switch_close"));
    Switch_Btn_2->setIconSize(QSize(32,32));
    Switch_Btn_2->setFlat(true);
    Switch_title_img_1->setFixedWidth(30);
    Switch_title_img_1->setIcon(QIcon(":/TrayMenu/speed"));
    Switch_title_img_1->setIconSize(QSize(20,20));
    Switch_title_img_1->setFlat(true);
    Switch_title_img_1->setDefault(true);
    Switch_title_img_2->setFixedWidth(30);
    Switch_title_img_2->setIcon(QIcon(":/TrayMenu/no"));
    Switch_title_img_2->setIconSize(QSize(20,20));
    Switch_title_img_2->setFlat(true);
    Switch_title_img_2->setDefault(true);
    Switch_title_img_2->setEnabled(true);

    switch_layout_1 = new QHBoxLayout();
    switch_layout_1->addWidget(Switch_title_img_1);
    switch_layout_1->addWidget(Switch_label_1);
    switch_layout_1->addWidget(Switch_Btn_1);
    switch_layout_1->setMargin(0);
    switch_layout_1->setSpacing(0);

    switch_layout_2 = new QHBoxLayout();
    switch_layout_2->addWidget(Switch_title_img_2);
    switch_layout_2->addWidget(Switch_label_2);
    switch_layout_2->addWidget(Switch_Btn_2);
    switch_layout_2->setMargin(0);
    switch_layout_2->setSpacing(0);

    /**/
    Action_Bottom_widget = new QWidgetAction(tray_menu);
    bottom_layout = new QHBoxLayout();
    bottom_layout->addWidget(Setting_Btn);
    bottom_layout->addWidget(Advancd_Btn);
    bottom_layout->addWidget(Quit_Btn);
    bottom_layout->setMargin(0);
    bottom_layout->setSpacing(0);

    bottom_layout_switch = new QVBoxLayout();
    bottom_layout_switch->addLayout(switch_layout_1);
    bottom_layout_switch->addLayout(switch_layout_2);
    bottom_layout_switch->addLayout(bottom_layout);
    bottom_layout_switch->setMargin(0);
    bottom_layout_switch->setSpacing(0);
    bottom_layout_switch->setContentsMargins(0,0,0,0);

    Bottom_widget->setLayout(bottom_layout_switch);
    //Bottom_widget->setStyleSheet("background-color:white;");
    Action_Bottom_widget->setDefaultWidget(Bottom_widget);
    //Action_Bottom_widget

    //添加菜单项
    tray_menu->setFixedWidth(200);
    tray_menu->addAction(Action_Top_widget);
    tray_menu->addSeparator();
    tray_menu->addMenu(tray_menu_update);
    tray_menu->addAction(Action_Bottom_widget);
    tray_menu_update->addAction(A_update);
    tray_menu_update->addAction(A_download);

    connect(Quit_Btn,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(Open_Btn,SIGNAL(clicked()),this,SIGNAL(emit_open()));

    this->setContextMenu(tray_menu);
}
void Tray_Menu::translateLanguage()
{
    this->setToolTip(tr("Smart L - connect everyone"));
    Switch_label_2->setToolTip(tr("test for smart"));
}
