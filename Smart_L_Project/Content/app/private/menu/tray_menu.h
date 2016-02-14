#ifndef TRAY_MENU_H
#define TRAY_MENU_H

#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QWidgetAction>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "../../public/bottom_btn.h"

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

    QMenu *tray_menu;
    QMenu *tray_menu_update;  //升级菜单

    Bottom_Btn *Open_Btn;        //打开
    Bottom_Btn *Information_Btn; //信息
    Bottom_Btn *Device_Status_Btn;  //设备状态
    Bottom_Btn *Music_Btn;    //音乐播放器

    QAction *A_update; //程序升级
    QAction *A_download; //程序下载管理

    Bottom_Btn *Setting_Btn;     //设置
    Bottom_Btn *Advancd_Btn;     //反馈意见
    Bottom_Btn *Quit_Btn;      //退出


    QLabel *Title_label;
    QGridLayout *middle_layout;
    QHBoxLayout *bottom_layout;
    QVBoxLayout *menu_layout;
    QWidget *Top_widget;
    QWidget *Bottom_widget;

    QWidgetAction *Action_Top_widget;
    QWidgetAction *Action_Bottom_widget;

    QHBoxLayout *switch_layout_1;
    QHBoxLayout *switch_layout_2;
    QVBoxLayout *bottom_layout_switch;
    QLabel *Switch_label_1,*Switch_label_2;
    QPushButton *Switch_title_img_1,*Switch_title_img_2,*Switch_Btn_1,*Switch_Btn_2;

    Bottom_Btn *t;
};

#endif // TRAY_MENU_H
