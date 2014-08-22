#ifndef TRAY_MENU_H
#define TRAY_MENU_H

#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include <QWidgetAction>

class Tray_Menu : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit Tray_Menu(QWidget *parent = 0);
    void translateLanguage();
signals:
    void emit_open();
private:
    void Create_Action();
private:

    QMenu *tray_menu_keven;
    QMenu *tray_menu_keven_two;  //升级菜单

    QAction *Action_Open;        //打开
    QAction *Action_Login;       //用户登录
    QAction *Action_Dai;    //待办事项
    QAction *Action_information; //信息
    QAction *ACtion_Device;  //设备状态
    QAction *Action_Setting;     //设置
    QAction *Action_quit;      //退出
    QAction *Action_Update; //程序升级
    QAction *Action_Download; //360 程序下载管理
    //上层
    QWidget *Up_Widget;
    QWidgetAction *Action_Up;
    QLabel *Up_label;  //顶层
    QLabel *Bottom_label; //天数
    QImage _image;
};

#endif // TRAY_MENU_H
