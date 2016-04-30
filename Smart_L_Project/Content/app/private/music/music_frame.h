#ifndef MUSIC_FRAME_H
#define MUSIC_FRAME_H

#include <QWidget>
#include <QFile>
#include <QButtonGroup>
#include <QMediaPlayer>
#include "PaiHangBang/paihangbangwidget.h"

namespace Ui {
class Music_Frame;
}

class Music_Frame : public QWidget
{
    Q_OBJECT

public:
    explicit Music_Frame(QWidget *parent = 0);
    ~Music_Frame();
    void Music_frame_layout_Init();
    void Play_Init();
    void PaihangBang_Init();
    void Reset_Play_Default();
    void translations();
signals:
    void signal_return();
private:
    Ui::Music_Frame *ui;
    /**/
    QButtonGroup *Top_Btn_Group;
    PaiHangBangWidget *phb_widget;
    /*Music*/
    QMediaPlayer *player;
    QTimer *timer;
 private slots:
    void Top_Btn_Switch(int id);
    void Music_Play(QString url);
    void Play_Kuwo_Music(QString id, QString SongName);
    void Get_PlayInfo();
    void Player_StateChanged_Handle(QMediaPlayer::State state);
    void Play_Btn_Click();
    void Seek(int p);
    void setDuration(qint64);
};

#endif // MUSIC_FRAME_H
