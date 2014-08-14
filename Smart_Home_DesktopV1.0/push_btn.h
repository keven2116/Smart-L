#ifndef PUSH_BTN_H
#define PUSH_BTN_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

class Push_Btn : public QPushButton
{
    Q_OBJECT
public:
    explicit Push_Btn(QWidget *parent = 0);
    ~Push_Btn();
    void Load_Pixmap_keven(QString pic_name_keven);  //load images  / 4

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:
    enum ButtonStatus{NORMAL,ENTER,PRESS,NOSTATUS};
    ButtonStatus status;
    QPixmap Pixmap_keven;
    int Btn_width_keven;
    int Btn_height_keven;
    bool Mouse_press_left_keven;


};

#endif // PUSH_BTN_H
