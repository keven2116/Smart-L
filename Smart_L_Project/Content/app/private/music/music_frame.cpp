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
    PaihangBang_Init();
    translations();
    connect(ui->return_Btn,SIGNAL(clicked()),this,SIGNAL(signal_return()));
}

Music_Frame::~Music_Frame()
{
    delete ui;
}
void Music_Frame::PaihangBang_Init()
{
    phb_widget = new PaiHangBangWidget(this);
    ui->Switch_wdiget->addWidget(phb_widget);
    ui->Switch_wdiget->setCurrentWidget(phb_widget);
    qDebug() << ui->Switch_wdiget->currentIndex();
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
