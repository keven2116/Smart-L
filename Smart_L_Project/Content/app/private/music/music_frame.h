#ifndef MUSIC_FRAME_H
#define MUSIC_FRAME_H

#include <QWidget>
#include <QFile>
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
    void PaihangBang_Init();
    void translations();
signals:
    void signal_return();
private:
    Ui::Music_Frame *ui;
    PaiHangBangWidget *phb_widget;
};

#endif // MUSIC_FRAME_H
