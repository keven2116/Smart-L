#include "main_widget.h"
#include <QDateTime>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QPoint>
#include <QTimer>
#include <QRect>
#include <QSize>
#include <QToolTip>
#include <QWidget>
#include <QtWebKit>
#include <QUrl>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonValue>
#include <QFileDialog>
#include <QDir>
#include <QStringList>
#include <QHeaderView>
#include <QMediaPlayer>
#include <QDebug>
#include <QVideoWidget>
#include <QMediaMetaData>

Main_Widget::Main_Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("Smart L");
    setWindowIcon(QIcon(":/logo/logo"));
    setFixedSize(900,600);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    /*up*/
    Top_Init();
    Bottom_Init();
    Index_Init();
    Vis_People_Init();
    Device_Info_Init();
    Smart_L_Init();
    translation();
    Top_Menu = new Main_Menu();
    //about = new About_me();
    a = new AboutUsDialog();
    connect(Menu_Btn,SIGNAL(clicked()),this,SLOT(show_MainMeun_widget_keven()));
    System_Menu = new Tray_Menu(this);
    connect(Top_Menu,SIGNAL(About_me_show()),this,SLOT(Show_About_Me()));
    connect(System_Menu,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
            SLOT(IcoIsActived_keven(QSystemTrayIcon::ActivationReason)));
    Main_Status = false;
    System_Menu->show();
}

Main_Widget::~Main_Widget()
{

}
void Main_Widget::Change_Skin(QString pic)
{
    QPixmap pixmap = QPixmap(":/skin/default").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
}
void Main_Widget::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/skin/default").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
}
void Main_Widget::show_MainMeun_widget_keven()
{
    QPoint p = rect().topRight();
    p.setX(p.x() - 125);
    p.setY(p.y() + 40);
    if (!Main_Status){
        Top_Menu->exec(this->mapToGlobal(p));
        Main_Status = true;
    }
    else
    {
        Main_Status = false;
    }
}
void Main_Widget::Show_About_Me()
{
   // about->show();
    a->show();
}
void Main_Widget::IcoIsActived_keven(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
  //      show_MAIN_widget();
        this->showNormal();
        break;
    case QSystemTrayIcon::DoubleClick:
 //       show_MAIN_widget();
        this->showNormal();
        break;
    default:
        break;
    }
}
void Main_Widget::mousePressEvent(QMouseEvent *e)
{
   Last_Point = e->globalPos();
}
void Main_Widget::mouseMoveEvent(QMouseEvent *e)
{
    int oldx = e->globalX() - Last_Point.x();
    int oldy = e->globalY() - Last_Point.y();
    Last_Point = e->globalPos();
    move(x() + oldx , y() + oldy);
  //  Timer_Show->start(10);
}
void Main_Widget::mouseReleaseEvent(QMouseEvent *e)
{
    int oldx = e->globalX() - Last_Point.x();
    int oldy = e->globalY() - Last_Point.y();
    move(x() + oldx , y() + oldy);
}
void Main_Widget::Top_Init()
{
    Close_Btn = new Push_Btn();
    Skin_Btn = new Push_Btn();
    Menu_Btn = new Push_Btn();
    Min_Btn = new Push_Btn();
   // Voice_Btn = new Push_Btn();

    Title_label = new QLabel();
  //  Top_widget = new QWidget();
    //Title_label->setFixedSize(780,40);
  //  Top_widget->setFixedSize(QSize(800,40));
    Skin_Btn->Load_Pixmap_keven(":/SysButton/skin");
    Menu_Btn->Load_Pixmap_keven(":/SysButton/menu");
    Min_Btn->Load_Pixmap_keven(":/SysButton/min");
    Close_Btn->Load_Pixmap_keven(":/SysButton/close");
    //Voice_Btn->Load_Pixmap_keven(":/SysButton/voice");

    Title_label->setFixedSize(900,40);
    Title_label->setStyleSheet("background-color:transparent;color:white;");
    layout_top = new QHBoxLayout();
    layout_top->addWidget(Title_label);
    layout_top->addWidget(Menu_Btn);
    layout_top->addWidget(Min_Btn);
    layout_top->addWidget(Skin_Btn);
    layout_top->addWidget(Close_Btn);
    layout_top->setContentsMargins(0,0,0,0);
    layout_top->setMargin(0);
    layout_top->setSpacing(0);
   // Top_widget->setLayout(layout_top);

    QTimer *timer = new QTimer(this);
    timer->setInterval(100);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(Close_Btn,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(Min_Btn,SIGNAL(clicked()),this,SLOT(showMinimized()));
}
void Main_Widget::Bottom_Init()
{
    Device_update_Btn = new Bottom_Btn();
    Device_Btn = new Bottom_Btn();
    Control_Btn = new Bottom_Btn();
    Vist_Btn = new Bottom_Btn();
    Monitor_Btn = new Bottom_Btn();
    Music_Btn = new Bottom_Btn();
    Update_Btn = new Bottom_Btn();
    More_Btn = new Bottom_Btn();

    Device_update_Btn->Load_img(":/index/device_display",tr("Device_update"));
    Music_Btn->Load_img(":/index/music_display",tr("Music"));
    Monitor_Btn->Load_img(":/index/video_display",tr("Monitor"));

    Device_Btn->Load_img_small(":/index/device",tr("Device"));
    Vist_Btn->Load_img_small(":/index/vist",tr("Vist"));
    Control_Btn->Load_img_small(":/index/control",tr("Control"));
    Update_Btn->Load_img_small(":/index/update",tr("Update"));
    More_Btn->Load_img_small(":/index/more",tr("More"));

    letf_layout = new QHBoxLayout();
    letf_layout->addWidget(Device_update_Btn);
    letf_layout->addWidget(Music_Btn);
    letf_layout->addWidget(Monitor_Btn);
    letf_layout->setMargin(0);
    letf_layout->setSpacing(25);
    letf_layout->setContentsMargins(30,50,10,10);

    righ_btn_layout = new QHBoxLayout();
    righ_btn_layout->addStretch(0);
    //righ_btn_layout->addStretch(0);
    righ_btn_layout->addWidget(Device_Btn,Qt::AlignRight);
    righ_btn_layout->addWidget(Vist_Btn,Qt::AlignRight);
    righ_btn_layout->addWidget(Control_Btn,Qt::AlignRight);
    righ_btn_layout->addWidget(Update_Btn,Qt::AlignRight);
    righ_btn_layout->addWidget(More_Btn,Qt::AlignRight);
    righ_btn_layout->setMargin(0);
    righ_btn_layout->setSpacing(20);
    righ_btn_layout->setContentsMargins(0,0,20,0);

    display_info = new QLabel();
    display_info->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    display_info->setText(tr("Welcome Using Smart L"));
    display_info->setFixedSize(400,60);
    //display_info->setFixedWidth(400);
    right_layout = new QVBoxLayout();
    right_layout->addWidget(display_info);
    right_layout->addStretch(0);
    right_layout->addLayout(righ_btn_layout);
    //right_layout->addStretch(0);
    right_layout->setMargin(0);
    right_layout->setSpacing(0);
    right_layout->setContentsMargins(0,0,0,10);

    layout_bttom = new QHBoxLayout();
    layout_bttom->addLayout(letf_layout);
    layout_bttom->addLayout(right_layout);
    layout_bttom->setMargin(0);
    layout_bttom->setSpacing(0);

    Bottom_widget = new QWidget();
    Bottom_widget->setFixedSize(900,160);
    Bottom_widget->setStyleSheet("background-color: white; color:black;");
    Bottom_widget->setLayout(layout_bttom);

    Btn_group = new QButtonGroup();
    Btn_group->addButton(Device_update_Btn,0);
    Btn_group->addButton(Device_Btn,1);
    Btn_group->addButton(Control_Btn,2);
    Btn_group->addButton(Vist_Btn,3);
    Btn_group->addButton(Monitor_Btn,4);
    Btn_group->addButton(Music_Btn,5);
    Btn_group->addButton(Update_Btn,6);
    Btn_group->addButton(More_Btn,7);

    connect(Btn_group,SIGNAL(buttonClicked(int)),this,SLOT(Btn_Switch(int)));
}
void Main_Widget::Btn_Switch(int id)
{
    switch (id)
    {
    case 0:
        home_widget->setCurrentWidget(Dev_Info_widget);
        qDebug() << "----------------------" << id;
        break;
    case 1:

        break;
    case 2:
        break;
    case 3:
        home_widget->setCurrentWidget(Vist_widget);
        break;
    case 4:
        home_widget->setCurrentWidget(nvr_dev);
        break;
    case 5:
        home_widget->setCurrentWidget(musicframe);
        break;
    case 6:
        break;
    case 7:
        break;
    }
}
void Main_Widget::Index_Init()
{
    welcome_widget = new QWidget();
    welcome_widget->setStyleSheet("background-color:transparent");
    index_layout = new QVBoxLayout();
    index_layout->addWidget(welcome_widget);
    index_layout->addWidget(Bottom_widget);
    index_layout->setSpacing(0);
    index_layout->setMargin(0);
}
void Main_Widget::Vis_People_Init()
{
    Visitor_List = new QListWidget();
    //Visitor_List->setFixedSize(900,360);
    Visitor_List->setSpacing(20);
    QDir dir;
    dir.setPath(":/join/");
    dir.setSorting(QDir::Time| QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    //qDebug("list.size = %d",list.size());
    int sizelen = list.size() ;
    int index;
    qDebug()<< "****" <<sizelen;
    //Join_Label = new QLabel();
    QString Join_Name,Smart_Action;
    Join_Name = tr("Stven\n");
    Smart_Action = "In";
    for( index = 1; index <= sizelen; index++)  //遍历目录添加图片到List
    {
  //      qDebug("size %d",list.size());
        QString path = QString(":/join/people_%1").arg(index);
        QPixmap objPixmap(path);
        QListWidgetItem *item = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(60,60))),Join_Name,Visitor_List);
        QString Link = QString(":/card/Name_") + QString::number(index,10);
        item->setToolTip("<html><head/><body><p><img src="+ Link +"/>Name："+
                         Join_Name +"<br/>Relations：Friends<br/>Phone:010-10628532<br/>E-mail:"+
                         Join_Name+"@gmail.com<br/>Action:"+
                         Smart_Action+"</p></body></html>");
        item->setText(Join_Name);
        Visitor_List->insertItem(index,item);
    }
    Vis_layout = new QVBoxLayout();
    Vis_layout->addWidget(Visitor_List);
    //Vis_layout->addWidget(Bottom_widget);
    Vis_layout->setSpacing(0);
    Vis_layout->setMargin(0);
}
void Main_Widget::Device_Info_Init()
{
  //  table_view = new TableView();
    dev_table = new Device_Descirtion();
    count_label = new QLabel();
    Totle_Label = new QLabel();
    QFont Totle("楷体",10);
    Totle_Label->setText(tr("Totle:"));
    Totle_Label->setFont(Totle);
    count_label->setFont(Totle);
    return_btn = new QPushButton();
    return_btn->setIcon(QIcon(":/sub/return"));
    return_btn->setFlat(true);
    return_btn->setIconSize(QSize(35,35));
    return_btn->setFixedSize(35,35);
    connect(return_btn,SIGNAL(clicked()),this,SLOT(return_index()));

    add_button = new QPushButton();
    add_button->setIcon(QIcon(":/sub/add"));
    add_button->setFlat(true);
    add_button->setIconSize(QSize(35,35));
    add_button->setFixedSize(35,35);
    connect(add_button, SIGNAL(clicked()), this, SLOT(add()));

    update_button = new QPushButton();
    update_button->setIcon(QIcon(":/sub/update"));
    update_button->setFlat(true);
    update_button->setIconSize(QSize(35,35));
    update_button->setFixedSize(35,35);

    delete_button = new QPushButton();
    delete_button->setIcon(QIcon(":/sub/delete"));
    delete_button->setFlat(true);
    delete_button->setIconSize(QSize(35,35));
    delete_button->setFixedSize(35,35);

  //  connect(delete_button, SIGNAL(clicked()), table_view, SLOT(remove()));

    clear_button = new QPushButton();
    clear_button->setIcon(QIcon(":/sub/delete_all"));
    clear_button->setIconSize(QSize(35,35));
    clear_button->setFlat(true);
    clear_button->setFixedSize(35,35);

    dev_table->setStyleSheet("background-color:transparent;");
    dev_table->horizontalHeader()->setStyleSheet("QHeaderView::section{background:white;}");
    QHBoxLayout *operate_layout = new QHBoxLayout();
    operate_layout->addWidget(return_btn);
    operate_layout->addStretch();
    operate_layout->addWidget(Totle_Label);
    operate_layout->addWidget(count_label);
    operate_layout->addSpacing(70);
    operate_layout->addWidget(add_button);
    operate_layout->addSpacing(40);
    operate_layout->addWidget(update_button);
    operate_layout->addSpacing(40);
    operate_layout->addWidget(delete_button);
    operate_layout->addSpacing(40);
    operate_layout->addWidget(clear_button);
    operate_layout->addStretch();
    operate_layout->addStretch();
    operate_layout->setContentsMargins(0, 0, 0 ,10);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(dev_table);
    main_layout->addLayout(operate_layout);
    main_layout->setContentsMargins(0, 0, 0, 0);
    Dev_Info_widget = new QWidget();
    Dev_Info_widget->setLayout(main_layout);
   // ui->Tree_Widget->setLayout(main_layout);
    // ui->Tree_Widget->setWindowOpacity(0);
    timer = new QTimer();
    timer->setInterval(1000);
    //connect(timer, SIGNAL(timeout()),dev_table, SLOT(changeValue()));
    connect(update_button, SIGNAL(clicked()), timer, SLOT(start()));
    connect(clear_button, SIGNAL(clicked()), timer, SLOT(stop()));
    //connect(clear_button, SIGNAL(clicked()), dev_table, SLOT(clear()));
    //connect(table_view, &TableView::updateCount, this, &Main_Widget::updateCount);
    //this->updateCount(0);
}
void Main_Widget::updateCount(int count)
{
    count_label->setText(QString("%1").arg(QString::number(count)));
}
void Main_Widget::add()
{
    int row_count = dev_table->Row_Count();
    for(int i = 0; i < 10; ++i)
    {
        QStringList row_list;
        row_list <<  QString("Device %1").arg(row_count++) << QString("%1KB").arg(i) << QString::number(0) << QString("%1KB/s").arg(i) << QString("08:08:08") << QString("uploading");
     //  row_list <<  QString("file : %1").arg(row_count++) << QString("%1KB").arg(i) << QString::number(0);
        dev_table->addRow_Dev(row_list);
    }
}
void Main_Widget::return_index()
{
    home_widget->setCurrentIndex(0);
}
void Main_Widget::Smart_L_Init()
{
    home_widget = new QStackedLayout();
 //   home_widget->setGeometry(0,100,800,500);
    //home_widget->setStyleSheet("background-color: red");
   // home_widget->setFixedSize(800,500);
    Vist_widget = new QWidget();
    Vist_widget->setFixedSize(900,560);
    Vist_widget->setLayout(Vis_layout);
    Index_widget = new QWidget();
    Index_widget->setFixedSize(900,560);
    Index_widget->setLayout(index_layout);

    musicframe = new Music_Frame();
    connect(musicframe,SIGNAL(signal_return()),this,SLOT(return_index()));

    nvr_dev = new Nvr_view();

    home_widget->addWidget(Index_widget);
    home_widget->addWidget(Vist_widget);
    home_widget->addWidget(Dev_Info_widget);
    home_widget->addWidget(musicframe);
    home_widget->addWidget(nvr_dev);
    home_widget->setContentsMargins(0,0,0,0);
    home_widget->setMargin(0);
    home_widget->setSpacing(0);
    home_widget->setCurrentWidget(Index_widget);
    //home_widget->setGeometry(QRect(0, 40, 800, 500));
    layout = new QVBoxLayout();
    layout->addLayout(layout_top);
    layout->addLayout(home_widget);
    //layout->addLayout(layout_bttom);
    layout->setMargin(0);  //去除默认的外边框
    layout->setSpacing(0);  //去除默认的空间间隔
    this->setLayout(layout);
}
void Main_Widget::updateTime()
{
    QDateTime now = QDateTime::currentDateTime();
    QString Now_Time = now.toString("yyyy" + tr("/") + "MM" + tr("-") + "dd" + tr("") + "  hh:mm" + "  dddd");
    Title_label->setText(Now_Time);
    Title_label->setFont(QFont("楷体", 10, QFont::Bold));
    Title_label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);
}
void Main_Widget::translation()
{
    //Voice_Btn->setToolTip(tr("Voice"));
    Skin_Btn->setToolTip(tr("Change Skin"));
    Close_Btn->setToolTip(tr("Close"));
    clear_button->setToolTip(tr("clear"));
    delete_button->setToolTip(tr("delete"));
    update_button->setToolTip(tr("update"));
    return_btn->setToolTip(tr("return"));
    add_button->setToolTip(tr("add"));

  //  Voice_Btn->setStyleSheet("color:black;");
    Skin_Btn->setStyleSheet("color:black;");
    Close_Btn->setStyleSheet("color:black;");
}
