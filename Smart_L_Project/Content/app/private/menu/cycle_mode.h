#ifndef CYCLE_MODE_H
#define CYCLE_MODE_H

#include <QMenu>

class Cycle_Mode : public QMenu
{
    Q_OBJECT
public:
    explicit Cycle_Mode(QWidget *parent = 0);
    ~Cycle_Mode();
    void translateActions();
    void Create_Act_Cycle();

signals:
    void Sig_One_Cycle();
    void Sig_List_Cycle();
    void Sig_List_Seq_Cycle();
    void Sig_List_Random_Cycle();

private:

private:
    QAction *Act_One_cycle;   //单曲循环
    QAction *Act_list_cycle; //列表循环
    QAction *Act_list_sequence; //顺序播放
    QAction *Act_list_random; //随机播放

};

#endif // CYCLE_MODE_H
