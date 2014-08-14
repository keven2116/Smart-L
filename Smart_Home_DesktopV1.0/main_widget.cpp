#include "main_widget.h"
#include "ui_main_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
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

static int volume;
QString Now_Time;
Main_Widget::Main_Widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint*/);
    Close_Btn = new Push_Btn();
    Skin_Btn = new Push_Btn();
    Voice_Btn = new QPushButton();
    System_Menu = new Tray_Menu(this);
    //Manage widget init
    MainMenu = new Main_Menu();
    /**** MainMenu Sig recv and Handle ****/
    connect(MainMenu,SIGNAL(Sig_uniq()),this,SLOT(uniq_slot()));
    connect(MainMenu,SIGNAL(Sig_sort()),this,SLOT(sort_slot()));
    connect(MainMenu,SIGNAL(Sig_download()),this,SLOT(download_slot()));
    //system menu
    connect(System_Menu,SIGNAL(emit_open()),this,SLOT(show()));
    //Cycle widget init
    CycleMode = new Cycle_Mode();
    /**** CycleMode Sig recv and Handle****/
    connect(CycleMode,SIGNAL(Sig_One_Cycle()),this,SLOT(Signal_cycle_slot()));
    connect(CycleMode,SIGNAL(Sig_List_Cycle()),this,SLOT(List_cycle_slot()));
    connect(CycleMode,SIGNAL(Sig_List_Seq_Cycle()),this,SLOT(List_cycle_Sequence_slot()));
    connect(CycleMode,SIGNAL(Sig_List_Random_Cycle()),this,SLOT(Random_cycle_slot()));
    //Lrc_Show
    Lrc = new Lrc_View(this);
    connect(ui->Song_Word_Btn,SIGNAL(clicked()),this,SLOT(Show_Lrc()));

//    Voice_Btn->setIcon(QIcon(":/contentWidget/voice"));
//    Voice_Btn->setIconSize(QSize(35,35));
//    Voice_Btn->setFlat(true);
//    Voice_Btn->setAutoDefault(true);
//    Voice_Btn->setStyleSheet("border-image: url(:/contentWidget/voice.png);");
    Skin_Btn->Load_Pixmap_keven(":/SysButton/skin");
    Close_Btn->Load_Pixmap_keven(":/SysButton/close");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(ui->Title_label);
 //   layout->addWidget(Voice_Btn);
    layout->addWidget(Skin_Btn);
    layout->addWidget(Close_Btn);
    layout->setContentsMargins(0,0,0,0);
    ui->Title_Widget->setLayout(layout);


    QDateTime now = QDateTime::currentDateTime();
    Now_Time = now.toString("yyyy" + tr("-") + "MM" + tr("--") + "dd" + tr(" ") + "  hh:mm" + "  dddd");

    connect(Close_Btn,SIGNAL(clicked()),this,SLOT(hide()));
    Timer_Show = new QTimer(this);
    connect(Timer_Show,SIGNAL(timeout()),this,SLOT(My_Move()));
    Timer_Stay = new QTimer(this);
    connect(Timer_Stay,SIGNAL(timeout()),this,SLOT(My_Stay()));
    Timer_Close = new QTimer(this);
    connect(Timer_Close,SIGNAL(timeout()),this,SLOT(My_Close()));
    /*Weather from html*/
    QFile source(":/html/weather");
    source.open(QIODevice::ReadOnly);
    ui->Weather_View->setHtml(QString::fromUtf8(source.readAll().constData()));

    is_finished = false;
//    QPointer log_broswer;
//    log_broswer = new Main_Widget();
/**/
/**/
    /*hidden header*/
    QHeaderView *Tabel_Widget_Header = ui->Music_list->verticalHeader();
    Tabel_Widget_Header->setHidden(true);
    /*tablewidget*/
    ui->Music_list->horizontalHeader()->setStyleSheet("QHeaderView::section{background:transparent;}");
    ui->Music_list->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft|Qt::AlignTop);
    ui->Music_list->horizontalHeader()->setFixedHeight(35);
    ui->Music_list->closePersistentEditor(ui->Music_list->item(1,0));

    volume = 80;
    /**/
    playList = new QMediaPlaylist;
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    player = new QMediaPlayer;
    player->setPlaylist(playList);
    player->setVolume(volume);
    ui->Volume_Process->setValue(volume);
    ui->Music_process->setRange(0,0);
    /*three slots for */
  //  connect(ui->Music_process,SIGNAL(sliderMoved(int)),this,SLOT(setPosition(int))); //Music_Process
 //   connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(setPosition(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(setDuration(qint64)));
    connect(ui->Music_process,SIGNAL(sliderMoved(int)),this,SLOT(setplayposion(int)));

    connect(ui->Volume_Process,SIGNAL(sliderMoved(int)),this,SLOT(Set_Volume(int))); //Volume
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    connect(player,SIGNAL(metaDataChanged()),this,SLOT(Get_music_info()));
    connect(playList, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSongList(int)));
    connect(ui->Music_list,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(Select_Table_Widget(int)));

    //SIGNAL connect Other SIGNAL
    connect(ui->Manage_Btn,SIGNAL(clicked()),this,SLOT(Show_Meun_Manage()));
    connect(ui->Mode_Btn,SIGNAL(clicked()),this,SLOT(Show_Cycle_Widget()));
    List_People_Init();
    Tree_Widget_Init();
    Search_Layout_Init();
    translation();
    Recv_Weather_Json_Data();
    System_Menu->show();
    Main_Status = false;
    Cycle_Status = false;
  //  setWindowOpacity(0.5);
  //  Show_Bottom();
    /* - - */
    qDebug() << this->rect();
}
Main_Widget::~Main_Widget()
{
    delete ui;
}
void Main_Widget::translation()
{
    Voice_Btn->setToolTip(tr("Voice"));
    Skin_Btn->setToolTip(tr("Change Skin"));
    Close_Btn->setToolTip(tr("Close"));

    Voice_Btn->setStyleSheet("color:black;");
    Skin_Btn->setStyleSheet("color:black;");
    Close_Btn->setStyleSheet("color:black;");

    //Setting Tab Widget
    ui->Base_Set_Widget->addTab(ui->tab1,tr("Base Setting"));
    ui->Base_Set_Widget->addTab(ui->tab2,tr("User Setting"));
    ui->Base_Set_Widget->addTab(ui->tab3,tr("Advanced Setting"));
    ui->Base_Set_Widget->addTab(ui->tab4,tr("Improvement Plan"));
    //Music_Table Widget
    ui->Music_Tab_Widget->addTab(ui->List_tab_1,tr("Music Lrc"));
    ui->Music_Tab_Widget->addTab(ui->List_tab_2,tr("Music Radio"));
    ui->Music_Tab_Widget->addTab(ui->List_tab_3,tr("Native List"));

    ui->Add_Btn->setText(tr("Add"));
    ui->Manage_Btn->setText(tr("Manage"));
    ui->Find_Btn->setText(tr("Find"));

    ui->Add_Btn->setToolTip(tr("Add local song"));
    ui->Manage_Btn->setToolTip(tr("quick manage current list"));

    ui->Title_label->setText(Now_Time);

    ui->Switch_City->setText(tr("[Switch]"));
    Home_Btn = false;

}
void Main_Widget::Tree_Widget_Init()
{
    table_view = new TableView();
    count_label = new QLabel();
    Totle_Label = new QLabel();
    QFont Totle("楷体",10);
    Totle_Label->setText(tr("Totle:"));
    Totle_Label->setFont(Totle);
    count_label->setFont(Totle);
    add_button = new QPushButton();
    add_button->setIcon(QIcon(":/sub/add"));
    add_button->setIconSize(QSize(35,35));
    add_button->setFixedSize(35,35);
    add_button->setToolTip(tr("add"));
    connect(add_button, SIGNAL(clicked()), this, SLOT(add()));

    update_button = new QPushButton();
    update_button->setIcon(QIcon(":/sub/update"));
    update_button->setIconSize(QSize(35,35));
    update_button->setFixedSize(35,35);
    update_button->setToolTip(tr("update"));

    delete_button = new QPushButton();
    delete_button->setIcon(QIcon(":/sub/delete"));
    delete_button->setIconSize(QSize(35,35));
    delete_button->setFixedSize(35,35);
    delete_button->setToolTip(tr("delete"));
    connect(delete_button, SIGNAL(clicked()), table_view, SLOT(remove()));

    clear_button = new QPushButton();
    clear_button->setIcon(QIcon(":/sub/delete_all"));
    clear_button->setIconSize(QSize(35,35));
    clear_button->setFixedSize(35,35);
    clear_button->setToolTip(tr("clear"));

    table_view->setStyleSheet("background-color:transparent;");
    table_view->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    QHBoxLayout *operate_layout = new QHBoxLayout();
    operate_layout->addSpacing(20);
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
    operate_layout->setContentsMargins(0, 0, 0 ,0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(table_view);
    main_layout->addLayout(operate_layout);
    main_layout->setContentsMargins(0, 0, 0, 0);

    ui->Tree_Widget->setLayout(main_layout);
   // ui->Tree_Widget->setWindowOpacity(0);
    timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()),table_view, SLOT(changeValue()));
    connect(update_button, SIGNAL(clicked()), timer, SLOT(start()));
    connect(clear_button, SIGNAL(clicked()), timer, SLOT(stop()));
    connect(clear_button, SIGNAL(clicked()), table_view, SLOT(clear()));
    connect(table_view, &TableView::updateCount, this, &Main_Widget::updateCount);
    this->updateCount(0);
}
void Main_Widget::Search_Layout_Init()
{
    search_logo = new QLabel();
//    default_edit = new QLineEdit();
    search_Btn = new QToolButton();

    search_Btn->setToolTip(tr("Search"));
    ui->Search_Edit->setPlaceholderText(tr("Find Song"));
    search_logo->setStyleSheet("border-image: url(:/play/find);");
    search_logo->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    QIcon seach_ico = QIcon(":/play/find");
    search_Btn->setFixedSize(25,25);
    search_Btn->setIcon(seach_ico);
    search_Btn->setIconSize(QSize(25,25));
    search_Btn->setAutoRaise(true);
    search_Btn->setCursor(Qt::ArrowCursor);
    search_Btn->setStyleSheet("background:transparent;");

    search_logo->setFixedSize(25,25);

    QHBoxLayout *search_layout = new QHBoxLayout();
    search_layout->addWidget(search_logo);
    search_layout->addSpacing(150);
    search_layout->addWidget(search_Btn);
    search_layout->setContentsMargins(0,0,0,0);
    ui->Search_Edit->setLayout(search_layout);
    ui->Search_Edit->setTextMargins(search_logo->width(),0,search_Btn->width(),0);

}
void Main_Widget::add()
{
    int row_count = table_view->rowCount();
    for(int i = 0; i < 10; ++i)
    {
        QStringList row_list;
        row_list <<  QString("Device %1").arg(row_count++) << QString("%1KB").arg(i) << QString::number(0) << QString("%1KB/s").arg(i) << QString("08:08:08") << QString("uploading");
     //  row_list <<  QString("file : %1").arg(row_count++) << QString("%1KB").arg(i) << QString::number(0);
        table_view->addRow(row_list);
    }
}
void Main_Widget::updateCount(int count)
{
    count_label->setText(QString("%1").arg(QString::number(count)));
}
void Main_Widget::Show_Bottom()
{
    QDesktopWidget *deskTop = QApplication::desktop();
    Desk_Rect = deskTop->availableGeometry();
    Normal_Point.setX(Desk_Rect.width() - rect().width());
    Normal_Point.setY(Desk_Rect.height() - rect().height());
    move(Normal_Point.x(),768 - 1);
    show();
    Timer_Show->start(10);
}
void Main_Widget::My_Move()
{
    static int beginY = QApplication::desktop()->height();
    beginY--;
    move(Normal_Point.x(),beginY);
    if(beginY<=Normal_Point.y())
    {
        Timer_Show->stop();
        Timer_Stay->start(1000);
    }
}
void Main_Widget::My_Stay()
{
    static int timeCount = 0;
    timeCount++;
    if( timeCount >= 9)
    {
        Timer_Stay->stop();
        Timer_Close->start(200);
    }
}
void Main_Widget::My_Close()
{
    //    static double tran = 1.0;
    //    tran -= 0.1;
    //    if(tran <= 0.0)
    //    {
    //        Timer_Close->stop();
    //        emit hide();
    //    }
    //    else
    //        setWindowOpacity(tran);
}
/**** 重写 Mouse ****/
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
void Main_Widget::on_Home_Btn_clicked()
{
        ui->Change_Widget->setCurrentIndex(0);
}

void Main_Widget::on_Device_Btn_clicked()
{
        ui->Change_Widget->setCurrentIndex(1);
}
void Main_Widget::on_Contrl_Btn_clicked()
{
    ui->Change_Widget->setCurrentIndex(2);
}
void Main_Widget::List_People_Init()
{
    ui->Join_List->setIconSize(QSize(60,60));
//   // ui->Join_List->setResizeMode(QListView::Adjust);
//    ui->Join_List->setViewMode(QListView::IconMode);
//    ui->Join_List->setMovement(QListView::Static);
//    ui->Join_List->setFlow(QListView::LeftToRight);
   // ui->Join_List->setStyleSheet("border:0px solid;border-radius:30px;");
    ui->Join_List->setSpacing(20);
    QDir dir;
    dir.setPath(":/join/");
    dir.setSorting(QDir::Time| QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    qDebug("list.size = %d",list.size());
    int sizelen = list.size() ;
    int index;
    qDebug()<< "****" <<sizelen;
    Join_Label = new QLabel();
    QString Join_Name,Smart_Action;
    Join_Name = tr("Stven\n");
    Smart_Action = "IN";
    for( index = 1; index <= sizelen; index++)  //遍历目录添加图片到List
    {
        qDebug("size %d",list.size());
        QString path = QString(":/join/people_%1").arg(index);
        QPixmap objPixmap(path);
        QListWidgetItem *item = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(60,60))),Join_Name,ui->Join_List);
        QString Link = QString(":/card/Name_") + QString::number(index,10);
        item->setToolTip("<html><head/><body><p><img src="+ Link +"/>Name："+
                         Join_Name +"<br/>Relations：Friends<br/>Phone:010-10628532<br/>E-mail:"+
                         Join_Name+"@gmail.com<br/>Action:"+
                         Smart_Action+"</p></body></html>");
        item->setText(Join_Name);
        ui->Join_List->insertItem(index,item);
    }
}
void Main_Widget::Out_Message(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString message;
    switch(type)
    {
    case QtDebugMsg:
        message = QString(tr("Debug:"));
        break;
    case QtWarningMsg:
        message = QString(tr("Warnning:"));
        break;
    case QtCriticalMsg:
        message = QString(tr("Critical:"));
        break;
    case QtFatalMsg:
        message = QString(tr("Fatal"));
        break;
    }
    ui->Log_TextBrower->append(message.append(msg));
}
void Main_Widget::on_Start_Btn_clicked()
{
   // if(!is_finished)
 //   {
   //     for(int i = 0; i < 1000000; i++)
 //       {
//            QCoreApplication::processEvents();
//            qDebug() << QString("This is a Qt log browser").append(QString::number(i, 10));
    static int i;
            ui->Log_TextBrower->append(QString::number(i,10) + QString("This is a Qt log browser"));
            i++;
   //     }
  //      is_finished = true;
//    }

}
void Main_Widget::on_Information_Btn_clicked()
{
    ui->Change_Widget->setCurrentIndex(3);
}
void Main_Widget::on_Monitor_Btn_clicked()
{
    ui->Change_Widget->setCurrentIndex(4);
}
void Main_Widget::on_Music_Btn_clicked()
{
     ui->Change_Widget->setCurrentIndex(5);
     ui->Music_Tab_Widget->setCurrentIndex(0);
}
void Main_Widget::on_Set_Btn_clicked()
{
    ui->Change_Widget->setCurrentIndex(7);
}
int Main_Widget::Recv_Weather_Json_Data()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    //QNetworkRequest request;
   // request.setUrl(QUrl("http://www.weather.com.cn/data/sk/101010100.html"));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replay_Finished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.weather.com.cn/data/sk/101010100.html")));
    return 0;
}
int Main_Widget::replay_Finished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray Date = reply->readAll();
        QJsonParseError Json_Parse_Error;
        QJsonObject obj,obj1;
        QJsonDocument Json_Data = QJsonDocument::fromJson(Date,&Json_Parse_Error);
        if(Json_Parse_Error.error == QJsonParseError::NoError)
        {
            if(Json_Data.isObject())
            {
                qDebug()<<"OBject****";
                 obj = Json_Data.object();
                 obj1 = obj["weatherinfo"].toObject();
//                qDebug()<<"----"<<obj1.take("temp").toString();
//                if(obj1.contains("temp"))
//                {

//                    QJsonValue Normal_tmp = obj1.take("temp");
//                    qDebug()<<"******Tmp"<<Normal_tmp;
////                    if(Normal_tmp.isString())
////                    {
////                        qDebug()<<"******Tmp1";
//                        int tmp = Normal_tmp.toInt();
//                        qDebug()<<"******Tmp"<<tmp;
                        QString str_tmp = obj1.take("temp").toString();
                        ui->Degree_Label->setText(str_tmp);
//                        qDebug()<<"******Tmp"<<str_tmp;
//                    }
//                }
                if(obj.contains("weather"))
                {
                    QJsonValue weather = obj.take("weather");
                    if(weather.isString())
                    {
                        ui->Today_Label->setText(tr("Today ") + weather.toString());
                        qDebug()<<weather;
                    }
                }
                if(Json_Data.isArray())
                {
                    qDebug()<<"Array******";
                }
            }
        }
        qDebug()<<Date;
        return 0;
    }

    return -1;

}
void Main_Widget::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = QPixmap(":/skin/default").scaled(this->size());
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
}
void Main_Widget::on_File_Btn_clicked()
{
  /*diplay lrc and image*/
}
void Main_Widget::on_Add_Btn_clicked()
{
    QString initialName = QDir::homePath();
    QStringList pathList = QFileDialog::getOpenFileNames(this, tr("选择文件"), initialName, tr("*.mp3"));
    for(int i=0; i< pathList.size(); ++i) {
        QString path=QDir::toNativeSeparators(pathList.at(i));
        if(!path.isEmpty()) {
            playList->addMedia(QUrl::fromLocalFile(path));
            QString fileName = path.split("\\").last();
            int rownum = ui->Music_list->rowCount();
            int columnnum = ui->Music_list->columnCount();
            ui->Music_list->insertRow(rownum);
            ui->Music_list->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").first()));
            QPushButton *MvBtn = new QPushButton(this);
            MvBtn->setObjectName("Mv");
            MvBtn->setStyleSheet("QPushButton#someBtn { color: red; }");
            ui->Music_list->setCellWidget(rownum,columnnum,MvBtn);
            connect(MvBtn,SIGNAL(clicked()),this,SLOT(Show_Mv()));
//            ui->Music_list->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
//            ui->Music_list->setItem(rownum, 2, new QTableWidgetItem(path));
        }
    }
}
//Three friend slots setting slider
void Main_Widget::setPosition(qint64 position)
{
    //positionchanged doing.....
}
void Main_Widget::setDuration(qint64 dur)
{
    ui->Music_process->setRange(0,dur);
}
void Main_Widget::setplayposion(int position)
{
     player->setPosition(position);
}
//end three friend
void Main_Widget::positionChanged(qint64 position)
{
    ui->Music_process->setValue(position);
   // qDebug() << position;
//    int all_time = position/1000/60;
//    int all_time_1 = position/1000%60;
    QTime totalTime(0, (position / 60000) % 60, (position / 1000) % 60);
    QString str =  totalTime.toString("mm:ss");
    ui->Current_Time->setText(str + "/");

    if(!LrcMap.isEmpty()){
        qint64 perv = 0;
        qint64 next = 0;
        foreach (qint64 value, LrcMap.keys()) {
            if(position >= value ){
                perv = value;
            }
                else {
                    next = value;
                    break;
                }

        }
        QString current_lrc = LrcMap.value(perv);
         qDebug() << "...." << current_lrc;
        if(current_lrc.length() < 2){
            current_lrc = windowTitle();
        }
        if (current_lrc != Lrc->text())
        {
            Lrc->setText(current_lrc);
      //      qDebug() << "...." << current_lrc;
            qint64 intervalTime = next - perv;
            Lrc->Start_Lrc(intervalTime);
        }
    }
    /*
     *     // 获取当期时间对应的歌词
    if(!lrc_map.isEmpty()) {
        // 获取当前时间在歌词中的前后两个时间点
        qint64 previous = 0;
        qint64 later = 0;
        //keys()方法返回lrc_map列表
        foreach (qint64 value, lrc_map.keys()) {
            if (time >= value) {
                previous = value;
            } else {
                later = value;
                break;
            }
        }

        // 达到最后一行,将later设置为歌曲总时间的值
        if (later == 0)
            later = total_time_value;

        // 获取当前时间所对应的歌词内容
        QString current_lrc = lrc_map.value(previous);

//        // 没有内容时
//        if(current_lrc.length() < 2)
//            current_lrc = tr("简易音乐播放器");

        // 如果是新的一行歌词，那么重新开始显示歌词遮罩
        if(current_lrc != lrc->text()) {
            lrc->setText(current_lrc);
            top_label->setText(current_lrc);
            qint64 interval_time = later - previous;
            lrc->start_lrc_mask(interval_time);
        }
    } else {  // 如果没有歌词文件，则在顶部标签中显示歌曲标题
        top_label->setText(QFileInfo(media_object->
                                    currentSource().fileName()).baseName());
    }
    */
}
void Main_Widget::durationChanged(qint64 duration)
{
    ui->Music_process->setRange(0, duration);
//    qDebug() << "***"<< duration;
//    int all_time = duration/1000/60;
//    int all_time_1 = duration/1000%60;
//    ui->Time_song->setText(QString::number(all_time,10) + ":" + QString::number(all_time_1,10));
    QTime totalTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    QString str =  totalTime.toString("mm:ss");
    ui->Time_song->setText(str);
}

void Main_Widget::updateSongList(int i)
{
    ui->Music_list->selectRow(i);
    ui->Song_Name_Label->setText(tr("正在播放: %1").arg(ui->Music_list->item(i, 0)->text()));
    ui->Song_Name_Label->setToolTip(ui->Music_list->item(i,0)->text());
//   ui->Song_Name_Label->setText(ui->Music_list->currentItem()->text());
}
void Main_Widget::Get_music_info()
{
  //  QString Title = player->metaData(QMediaMetaData::Title).toString();
  //  QString Artist = player->metaData(QMediaMetaData::Author).toString();
  //  qDebug() << "Title:" << Title << "\n" << "Artist:" << Artist;
    Get_Status_info();
    Lrc->setText(windowTitle());
    int index = playList->currentIndex();
    if(index == -1){
        return;
    }
    ui->Music_list->selectRow(index);
    ui->Music_list->setFocus();

}
void Main_Widget::Get_Status_info()
{
    /*  StoppedState,
        PlayingState,
        PausedState
    */
    switch(player->state()){
    case QMediaPlayer::PlayingState:
    {
        QString filename = player->metaData(QMediaMetaData::Author).toString() +
                          "-" + player->metaData(QMediaMetaData::Title).toString();
        ResolveLrc(filename);
    }
        break;
    case QMediaPlayer::StoppedState:
    {
        Lrc->Stop_Lrc();
        Lrc->setText(tr("Welcome using new version desktop lrc"));
    }
        break;
    case QMediaPlayer::PausedState:
    {
        if(!LrcMap.isEmpty()){
            Lrc->Stop_Lrc();
        }
    }
        break;
    default:
        break;
    }
}
void Main_Widget::ResolveLrc(const QString &sourceFileName)
{
    LrcMap.clear();
    if(sourceFileName.isEmpty()){
        return;
    }
    QString lrc_filename = QDir::currentPath() + "/Lyric/" + sourceFileName + ".lrc";
    qDebug() << "*_lrc__*" << lrc_filename;
    QFile file(lrc_filename);
    if(!file.open(QIODevice::ReadOnly)){
        Lrc->setText(player->metaData(QMediaMetaData::Title).toString() + "-" +
                     player->metaData(QMediaMetaData::Author).toString() + tr("Not found lrc"));
        return;
    }
    QString allText = QTextCodec::codecForLocale()->toUnicode(file.readAll());
    file.close();
    QStringList lines = allText.split("\n");
    QRegExp rx("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");
    foreach(QString oneLine, lines) {
        QString temp = oneLine;
        qDebug() << "temp" << temp;
        temp.replace(rx, "");
        int pos = rx.indexIn(oneLine, 0);
        while (pos != -1) {
            QString cap = rx.cap(0);
            QRegExp regexp;
            regexp.setPattern("\\d{2}(?=:)");
            regexp.indexIn(cap);
            int minute = regexp.cap(0).toInt();
            regexp.setPattern("\\d{2}(?=\\.)");
            regexp.indexIn(cap);
            int second = regexp.cap(0).toInt();
            regexp.setPattern("\\d{2}(?=\\])");
            regexp.indexIn(cap);
            int millisecond = regexp.cap(0).toInt();
            qint64 totalTime = minute * 60000 + second * 1000 + millisecond * 10;
            LrcMap.insert(totalTime, temp);
            pos += rx.matchedLength();
            pos = rx.indexIn(oneLine, pos);
        }
    }
    if (LrcMap.isEmpty()) {
    Lrc->setText(QStringLiteral("歌词文件内容错误！"));
    return;
    }
}
void Main_Widget::Set_ToolTip()
{
    //Set ToolTip
}
void Main_Widget::on_Play_Btn_clicked()
{
    if(ui->Play_Btn->text() == "play")
    {
        player->play();
        ui->Play_Btn->setText("stop");
        ui->Play_Btn->setIcon(QIcon(":/play/pause"));
        ui->Play_Btn->setIconSize(QSize(50,50));

    }
    else
    {
        player->pause();
        ui->Play_Btn->setText("play");
        ui->Play_Btn->setIcon(QIcon(":/play/player"));
        ui->Play_Btn->setIconSize(QSize(50,50));
    }
}

void Main_Widget::on_Pre_Btn_clicked()
{
    int currentIndex = playList->currentIndex();
    if(--currentIndex < 0)
        currentIndex = 0;
    playList->setCurrentIndex(currentIndex);
    player->play();
}

void Main_Widget::on_Next_Btn_clicked()
{
    int currentIndex = playList->currentIndex();
    if(++currentIndex == playList->mediaCount())
        currentIndex = 0;
    playList->setCurrentIndex(currentIndex);
    player->play();
}
void Main_Widget::Set_Volume(int value)
{
    player->setVolume(value);
    volume = value;
}

void Main_Widget::on_Mute_Btn_clicked()
{
    if(player->volume() != 0)
    {
        volume = player->volume();
        qDebug()<<volume;
        this->Set_Volume(0);
        ui->Mute_Btn->setIcon(QIcon(":/play/volume_quit"));
        ui->Volume_Process->setValue(0);
    }
    else{
        this->Set_Volume(volume);
        qDebug()<<volume;
        ui->Mute_Btn->setIcon(QIcon(":/play/volume_normal"));
        ui->Volume_Process->setValue(volume);
    }
    ui->Mute_Btn->setIconSize(QSize(35,35));
}
void Main_Widget::Select_Table_Widget(int index)
{
    playList->setCurrentIndex(index);
    player->play();

    ui->Play_Btn->setIcon(QIcon(":/play/pause"));
    ui->Play_Btn->setIconSize(QSize(50, 50));
    ui->Play_Btn->setAutoRaise(true);
    qDebug() << "just 1>>>>>";
}
void Main_Widget::Show_Meun_Manage()
{
    QPoint p = rect().topRight();
    p.setX(p.x() - 130);
    p.setY(p.y() + 230);
    if (!Main_Status){
        MainMenu->exec(this->mapToGlobal(p));
        Main_Status = true;
    }
    else
    {
        Main_Status = false;
    }
}
void Main_Widget::Show_Cycle_Widget()
{
    QPoint p = rect().topRight();
    p.setX(p.x() - 120);
    p.setY(p.y() + 400);
    if(!Cycle_Status){
        CycleMode->exec(this->mapToGlobal(p));
        Cycle_Status = true;
    }
    else{
        Cycle_Status = false;
    }
}
/**** Main Menu Slot handle ****/
void Main_Widget::uniq_slot()
{

}
void Main_Widget::sort_slot()
{

}
void Main_Widget::download_slot()
{

}
/**** Cycle Menu Slot Handle****/
void Main_Widget::Signal_cycle_slot()
{
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    ui->Mode_Btn->setToolTip(tr("Signal Cycle"));
}
void Main_Widget::List_cycle_slot()
{
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    ui->Mode_Btn->setToolTip(tr("CurrentList Cycle"));
}
void Main_Widget::List_cycle_Sequence_slot()
{
    playList->setPlaybackMode(QMediaPlaylist::Sequential);
    ui->Mode_Btn->setToolTip(tr("Sequential Cycle"));
}
void Main_Widget::Random_cycle_slot()
{
    playList->setPlaybackMode(QMediaPlaylist::Random);
    ui->Mode_Btn->setToolTip(tr("Random Cycle"));
}
/**** About Lrc ****/
void Main_Widget::Show_Lrc()
{
    if(Lrc->isHidden()){
        Lrc->show();
    }else{
        Lrc->hide();
    }

}
void Main_Widget::Show_Mv()
{

}

