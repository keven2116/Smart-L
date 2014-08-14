#include "push_btn.h"
#include <QDebug>

Push_Btn::Push_Btn(QWidget *parent) :
    QPushButton(parent)
{
    status = NORMAL;
    Mouse_press_left_keven = false;
}
Push_Btn::~Push_Btn()
{

}
void Push_Btn::Load_Pixmap_keven(QString pic_name_keven)
{
    Pixmap_keven.load(pic_name_keven);
    Btn_width_keven = Pixmap_keven.width()/4;
    Btn_height_keven = Pixmap_keven.height();
    setFixedSize(Btn_width_keven,Btn_height_keven);
}
void Push_Btn::enterEvent(QEvent *)
{
    status = ENTER;
    update();
}
void Push_Btn::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
        Mouse_press_left_keven = true;
        status = PRESS;
        update();
    }
}
void Push_Btn::mouseReleaseEvent(QMouseEvent *)
{
    if (Mouse_press_left_keven)
    {
        Mouse_press_left_keven = false;
        status = ENTER;
        update();
        emit click();  //connect click
    }
}
void Push_Btn::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}
void Push_Btn::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),Pixmap_keven.copy(Btn_width_keven * status ,0,Btn_width_keven,Btn_height_keven));
}
