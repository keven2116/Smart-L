#include "music_frame.h"
#include "ui_music_frame.h"
#include <QDebug>

Music_Frame::Music_Frame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Music_Frame)
{
    ui->setupUi(this);
    QString qss;
    QFile qssFile(":/qss/music_frame");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
   //     qDebug() << "---\n";
        qss = QLatin1String(qssFile.readAll());
  //      qDebug() << qss;
        this->setStyleSheet(qss);
        qssFile.close();
    }
    //contentListWidget = new ContentTabWidget(this);
    //connect(contentListWidget->paiHangBangWidget->musicListWidget,SIGNAL(playSignal(QString,QString)),playerWidget,SLOT(playKuwoMusic(QString,QString)));
    //connect(contentListWidget->souSuoWidget->musicListWidget,SIGNAL(playSignal(QString,QString)),playerWidget,SLOT(playKuwoMusic(QString,QString)));
    Music_frame_layout_Init();
    Play_Init();
    translations();
}

Music_Frame::~Music_Frame()
{
    delete ui;
}
void Music_Frame::Music_frame_layout_Init()
{
    /*Btn Group*/
    Top_Btn_Group = new QButtonGroup();
    Top_Btn_Group->addButton(ui->List_Btn,0);
    Top_Btn_Group->addButton(ui->Search_Btn,1);
    Top_Btn_Group->addButton(ui->Zhubo_Btn,2);
    Top_Btn_Group->addButton(ui->Paih_Btn,3);
    Top_Btn_Group->addButton(ui->Download_Btn,4);
    Top_Btn_Group->addButton(ui->New_music_Btn,5);
    connect(Top_Btn_Group,SIGNAL(buttonClicked(int)),this,SLOT(Top_Btn_Switch(int)));
    connect(ui->return_Btn,SIGNAL(clicked()),this,SIGNAL(signal_return()));
    PaihangBang_Init();

}
void Music_Frame::Play_Init()
{
    Reset_Play_Default();
    timer = new QTimer(this);
    player = new QMediaPlayer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Get_PlayInfo()));
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(Player_StateChanged_Handle(QMediaPlayer::State)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(setDuration(qint64)));
    connect(ui->Play_Btn,SIGNAL(clicked()),this,SLOT(Play_Btn_Click()));
    connect(ui->Music_process,SIGNAL(sliderMoved(int)),this,SLOT(Seek(int)));
}
void Music_Frame::PaihangBang_Init()
{
    phb_widget = new PaiHangBangWidget(this);
    ui->Switch_wdiget->insertWidget(3,phb_widget);
    connect(phb_widget->musicListWidget,SIGNAL(playSignal(QString,QString)),this,SLOT(Play_Kuwo_Music(QString,QString)));
    //ui->Switch_wdiget->setCurrentWidget(phb_widget);
    qDebug() << ui->Switch_wdiget->currentIndex();
    //connect(contentListWidget->paiHangBangWidget->musicListWidget,SIGNAL(playSignal(QString,QString)),playerWidget,SLOT(playKuwoMusic(QString,QString)));
}
void Music_Frame::Top_Btn_Switch(int id)
{
     ui->Switch_wdiget->setCurrentIndex(id);
     qDebug() << "***___*****" << id;
}
void Music_Frame::Reset_Play_Default()
{
    ui->current_time->setText("00:00");
    ui->current_time->setText("00:00");
    ui->Music_process->setValue(0);
}
void Music_Frame::translations()
{
    ui->return_Btn->setToolTip(tr("return"));
    ui->Lrc_Btn->setToolTip(tr("open lrc"));
    ui->Mode_Btn->setToolTip(tr("list cycle"));
    ui->Pre_Btn->setToolTip(tr("pre"));
    ui->Next_Btn->setToolTip(tr("next"));
    ui->Volume_Btn->setToolTip(tr("statc volume"));
}

void Music_Frame::Music_Play(QString url)
{
    player->setMedia(QUrl(url));
    qDebug() << url;
    player->play();
    ui->Play_Btn->setIcon(QIcon(":/play/player"));
}

void Music_Frame::Play_Kuwo_Music(QString id,QString songName)
{
    timer->stop();
    QString url("http://antiserver.kuwo.cn/anti.s?type=convert_url&response=url&format=mp3&rid="+id);

    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QEventLoop loop;
    QNetworkReply *reply = manager->get(QNetworkRequest(url));
    QObject::connect(reply,SIGNAL(finished()), &loop, SLOT(quit()));
    QTimer::singleShot(6*1000,&loop,SLOT(quit()));
    loop.exec();
    QString data = reply->readAll();
    this->Music_Play(data);
/*
    QFont font(songNameLbl->font());
    QFontMetrics fm(font);
    songNameLbl->setText(fm.elidedText(songName, Qt::ElideRight, songNameLbl->width()));*/
    timer->start(1000);
}

void Music_Frame::Get_PlayInfo()
{
    qint64 duration = player->duration();
    qint64 position = player->position();
    ui->Music_process->setMaximum(duration*1000/duration);
    int percent = position*1000/duration;
    ui->Music_process->setValue(percent);
    qDebug() << "-----" << duration;
    qDebug() << "-----" << position;
    qDebug() << "postion" << percent;
    qDebug() << "postion" << duration*1000/duration;

    QTime durationTime(0,0,0,0);
    durationTime = durationTime.addMSecs(duration);
    QString t1 = durationTime.toString("mm:ss");


    QTime positionTime(0,0,0,0);
    positionTime = positionTime.addMSecs(position);
    QString t2 = positionTime.toString("mm:ss");
    qDebug() << "-----" << t2;

    ui->current_time->setText(t2);
    ui->totle_time->setText(t1);
}

void Music_Frame::Player_StateChanged_Handle(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::PlayingState)
    {
        ui->Play_Btn->setIcon(QIcon(":/play/player"));
    }else if(state == QMediaPlayer::PausedState)
    {
        ui->Play_Btn->setIcon(QIcon(":/play/pause"));
    }else if(state == QMediaPlayer::StoppedState)
    {
        ui->Play_Btn->setIcon(QIcon(":/play/pause"));
        Reset_Play_Default();
    }
}
void Music_Frame::setDuration(qint64 dur)
{
    ui->Music_process->setRange(0,dur);
}
void Music_Frame::Play_Btn_Click()
{
    if(player->state() == QMediaPlayer::PlayingState)
    {
        player->pause();
    }else if(player->state() == QMediaPlayer::PausedState)
    {
        player->play();
    }
}
void Music_Frame::Seek(int p)
{
    player->setPosition(p*player->duration()/1000);
}
