#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QButtonGroup>
#include <QTimer>
#include <QPoint>
#include <QLabel>
#include "Content/app/public/push_btn.h"
#include "Content/app/public/bottom_btn.h"
#include "Content/app/private/menu/tray_menu.h"
#include "Content/app/private/menu/list_op_menu.h"
#include "Content/app/private/menu/main_menu.h"
#include "Content/app/private/menu/cycle_mode.h"
#include "Content/app/private/music/lrc/lrc_view.h"
#include "Content/app/private/device/device_descirtion.h"
#include "Content/app/private/about/about_us.h"
#include "Content/app/private/music/music_frame.h"
#include "Content/app/private/device/nvr/nvr_view.h"

class Main_Widget : public QWidget
{
    Q_OBJECT

public:
    Main_Widget(QWidget *parent = 0);
    ~Main_Widget();
    void Out_Message(QtMsgType type,const QMessageLogContext &context,const QString &msg);
    void translation();
    void Top_Init();
    void Bottom_Init();
    void Smart_L_Init();
    void Change_Skin(QString pic);
    void paintEvent(QPaintEvent *);
    void Index_Init();
    void Vis_People_Init();
    void Device_Info_Init();
    //int Recv_Weather_Json_Data();
    void Set_ToolTip();
    void Search_Layout_Init(); //Init Search
    bool Main_Status,Cycle_Status;
private:
    /*Top Btn*/
    Push_Btn *Close_Btn;
    Push_Btn *Skin_Btn;
    Push_Btn *Menu_Btn;
    Push_Btn *Min_Btn;
    QLabel *Title_label;
    /*Bottom Btn*/\
    QWidget *Bottom_widget;
    Bottom_Btn *Device_update_Btn;
    Bottom_Btn *Device_Btn;
    Bottom_Btn *Control_Btn;
    Bottom_Btn *Vist_Btn;
    Bottom_Btn *Monitor_Btn;
    Bottom_Btn *Music_Btn;
    Bottom_Btn *Update_Btn;
    Bottom_Btn *More_Btn;
    QLabel *display_info;
    QHBoxLayout *letf_layout;
    QVBoxLayout *right_layout;
    QHBoxLayout *righ_btn_layout;
    QHBoxLayout *layout_bttom;
    QButtonGroup *Btn_group;
    QHBoxLayout *layout_top;
    QVBoxLayout *layout;
    /*Center Layout*/
    QStackedLayout *home_widget;
    /*Index*/
    QLabel *check_number,*display_content,*diplay_sub_content;
    Bottom_Btn *Chcek_Btn;
    QWidget *Index_widget;
    QWidget *welcome_widget;
    QVBoxLayout *index_layout;
    /*Vistitor System*/
    QVBoxLayout *Vis_layout;
    QListWidget *Visitor_List;
    QWidget *Vist_widget;
    /*Decices Info*/
    Device_Descirtion *dev_table;
    //TableView *table_view;
    QLabel *Totle_Label;
    QLabel *count_label;
    QPushButton *return_btn;
    QPushButton *add_button;
    QPushButton *update_button;
    QPushButton *delete_button;
    QPushButton *clear_button;
    QTimer *timer;
    QWidget *Dev_Info_widget;
    /*Music Widget*/
    Music_Frame *musicframe;
    /**/
    QPoint Normal_Point;
    QPoint Last_Point;
    QRect Desk_Rect;
    QTimer *Timer_Show;
    QTimer *Timer_Stay;
    QTimer *Timer_Close;
    /*Menu*/
    Tray_Menu *System_Menu;
    Main_Menu *Top_Menu;

    //About_me *about;
    AboutUsDialog *a;

    /*Nvr*/
    Nvr_view *nvr_dev;




#if 0
    /************  Tree_Widget ***********/
    TableView *table_view;
    QLabel *Totle_Label;
    QLabel *count_label;
    QPushButton *add_button;
    QPushButton *update_button;
    QPushButton *delete_button;
    QPushButton *clear_button;
    QTimer *timer;
    /****** Join Label*****/
    QLabel *Join_Label;
    bool is_finished;
    QtMessageHandler outputMessage(QtMsgType type,const QMessageLogContext &context,const QString &msg);
    /****** mediaplay *****/
    /**** Search List ****/
    QLabel *search_logo;
    QLineEdit *default_edit;
    QToolButton *search_Btn;
    //Other widget
    List_Op_Menu *MainMenu;
    Cycle_Mode *CycleMode;
    //Lrc View
    Lrc_View *Lrc;
    QMap<qint64,QString> LrcMap;

private slots:
    void My_Move();
    void My_Stay();
    void My_Close();
    void on_Home_Btn_clicked();
    void on_Device_Btn_clicked();
    /*********** Tree_Widget slots*******/
    void add();
    void updateCount(int count);
    void on_Start_Btn_clicked();
    /*******TextBrower slots*******/
    void on_Information_Btn_clicked();
    void on_Monitor_Btn_clicked();
    void on_Set_Btn_clicked();
    void on_Contrl_Btn_clicked();
    void on_File_Btn_clicked();
    void on_Music_Btn_clicked();
    void paintEvent(QPaintEvent *);
    /*music */
 //   void on_Play_Btn_clicked();
    //three slots
    void setPosition(qint64);
    void setDuration(qint64);
    void setplayposion(int);
    //end three
    void positionChanged(qint64); //Display lrc
    void durationChanged(qint64); //Display move time
    void updateSongList(int);
    void on_Play_Btn_clicked();
    void on_Pre_Btn_clicked();
    void on_Next_Btn_clicked();
    void Set_Volume(int);
    void on_Mute_Btn_clicked();
    void Select_Table_Widget(int index);

    //Other Widget and Handle
    void Show_Meun_Manage();
    void uniq_slot();
    void sort_slot();
    void download_slot();
    //Cycle
    void Show_Cycle_Widget();
    void Signal_cycle_slot();
    void List_cycle_slot();
    void List_cycle_Sequence_slot();
    void Random_cycle_slot();
    //set Lrc
    void Show_Lrc();
    void ResolveLrc(const QString &sourceFileName);
    void Get_music_info(); //Get song info
    void Get_Status_info(); //Get player status
    //show mv
    void Show_Mv();
    void on_Add_Btn_clicked();
    /**end music**/
public slots:
    /*Json Slot*/
#endif
private slots:
    void Btn_Switch(int id);
    void IcoIsActived_keven(QSystemTrayIcon::ActivationReason reason);
    void show_MainMeun_widget_keven(); //mainmeun
    void Show_About_Me();
    /*Devcie Info*/
    void add();
    void updateCount(int count);
    void updateTime();
    /*PUBLIC slots*/
    void return_index();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MAIN_WIDGET_H
