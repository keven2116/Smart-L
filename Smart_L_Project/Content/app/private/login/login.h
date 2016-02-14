#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QStandardItemModel>
#include <QCompleter>
#include <QMovie>
#include <QLineEdit>
#include <QDesktopServices>
#include <QDebug>
#include <QStackedLayout>
#include <QCheckBox>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include "../../public/bottom_btn.h"
#include "../../public/push_btn.h"
#include "../../public/util.h"
#include "main_widget.h"


#define SMART_RESOURCE ":/qss/login"
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void Login_layout_init();  // 基本布局初始化
    void Resource_init();      //整体qss
    void Bottom_menu_init();    //托盘类初始化
    void onEmailChoosed(const QString& email);
    void onTextChanged(const QString& str);
    void translation();
    void Qrcode_Layout_init(); //二维码登录布局初始化

private:
    /*Top*/
    QLabel *Title_label;
    Push_Btn *Min_Btn;
    Push_Btn *Close_Btn;
    QHBoxLayout *top_layout;
    QLabel *top_lable;
    QMovie *top_img;
    /*Middle*/
    QLineEdit *User_Name;
    QLineEdit *Passwd;
    QLabel *Regiser_account;
    QLabel *Forget_Passwd;
    QCheckBox *Auto_login;
    QCheckBox *Remind_passwd;
    QGridLayout *middle_layout;
    /*Bootom*/
    Bottom_Btn *Login_Btn;
    QPushButton *Qrcode_Btn;
    QLabel *Qrcode;
    QHBoxLayout *bottom_layout;
    QVBoxLayout *layout,*layout_page_2;

    QCompleter *m_completer;
    QPoint Last_Point;

    QMenu *Bottom_menu;
    QAction *A_quit;
    QAction *A_open;
    QSystemTrayIcon *logon_tray;

    /*main_widget*/
    Main_Widget *smart_l_client;

    bool Visable_qrocde;

    /*2 code logoin*/
    QLabel *Head_label,*qcode_label;
    QHBoxLayout *qcode_Layout;

    QStackedLayout *main_layout;
    QWidget *page_1_login,*page_2_qrcode,*page_3_loading;




protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
     void OpenUrl(QString );
     void Login_response();
     void Qrcode_Btn_clicked();
     void IcoIsActived_trigger(QSystemTrayIcon::ActivationReason reason);

};

#endif // LOGIN_H
