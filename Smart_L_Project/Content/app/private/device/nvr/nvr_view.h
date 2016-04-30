#ifndef NVR_VIEW_H
#define NVR_VIEW_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QMenu>

namespace Ui {
class Nvr_view;
}

class Nvr_view : public QWidget
{
    Q_OBJECT

public:
    explicit Nvr_view(QWidget *parent = 0);
    ~Nvr_view();
    void nvr_init();
    void nvr_menu_init();

private:
    Ui::Nvr_view *ui;
    QList<QLabel *> VideoLab;           //Channel Label List
    QList<QLayout *> VideoLay;          //Channel Layout List
    QMenu *menuStyle;                   //Menu Stytle
    QMenu *menu;                        //Menu
    QLabel *tempLab;                    //tmp Play Video Label
    bool Is_Max;                     //Is'nt Max?
private slots:
    void Change_Show_View(int index);   //Change Video view Style
    void Delete_Video_Signal();         //Delete Video
    void Snapshot_Video_View(int slot); // Snapshot Video
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // NVR_VIEW_H
