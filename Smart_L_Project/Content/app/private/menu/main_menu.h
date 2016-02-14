#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMenu>

class Main_Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Main_Menu(QWidget *parent = 0);
    void translates();

signals:
    void Show_Setting_Dialog_keven();
    void Show_New_Charcter_keven();
    void About_me_show();

private:
    void menu_action_init();
    void menu_qss_init();
private:
    QAction *A_advanced;  //反馈意见
    QAction *A_setting;   //设置
    QAction *A_feature; //新版特性
    QAction *A_update; //检测更新
    QAction *A_help; //在线帮助
    QAction *A_about;//关于我
private slots:
    void _360_Html();
    void _Protect_360_Books();
    void _Why_Free();
};

#endif // MAIN_MENU_H
