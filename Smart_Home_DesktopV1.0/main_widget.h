#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QDialog>
#include <QPushButton>
#include "push_btn.h"
#include "tray_menu.h"
#include "table_view.h"
#include <QTimer>
#include <QPoint>
#include <QLabel>
#include <QNetworkReply>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "main_menu.h"
#include "cycle_mode.h"
#include "lrc_view.h"
namespace Ui {
class Main_Widget;
}

class Main_Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Main_Widget(QWidget *parent = 0);
    ~Main_Widget();
    void Out_Message(QtMsgType type,const QMessageLogContext &context,const QString &msg);
    void translation();
    void Show_Bottom();  //Bottom Show
    void Tree_Widget_Init();
    void List_People_Init();
    int Recv_Weather_Json_Data();
    void Set_ToolTip();
    void Search_Layout_Init(); //Init Search
    bool Main_Status,Cycle_Status;
private:
    Ui::Main_Widget *ui;
    Push_Btn *Close_Btn;
    Push_Btn *Skin_Btn;
    QPushButton *Voice_Btn;
    QPoint Normal_Point;
    QPoint Last_Point;
    QRect Desk_Rect;
    QTimer *Timer_Show;
    QTimer *Timer_Stay;
    QTimer *Timer_Close;
    Tray_Menu *System_Menu;
    bool Home_Btn;
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
    QMediaPlayer *player;
    QMediaPlaylist *playList;
    /**** Search List ****/
    QLabel *search_logo;
    QLineEdit *default_edit;
    QToolButton *search_Btn;
    //Other widget
    Main_Menu *MainMenu;
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
    int replay_Finished(QNetworkReply *);
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // MAIN_WIDGET_H
