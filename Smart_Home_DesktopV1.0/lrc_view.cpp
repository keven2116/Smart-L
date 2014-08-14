#include "lrc_view.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMenu>

Lrc_View::Lrc_View(QWidget *parent) :
    QLabel(parent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setText(tr("Welcome using Desktop Lrc"));
    setMaximumSize(800,70);
    setMinimumSize(800,70);
    linearGradient.setStart(0,10);
    linearGradient.setFinalStop(0, 40);
    linearGradient.setColorAt(0.1, QColor(14, 179, 255));
    linearGradient.setColorAt(0.5, QColor(114, 232, 255));
    linearGradient.setColorAt(0.9, QColor(14, 179, 255));

    maskLinearGradient.setStart(0, 10);
    maskLinearGradient.setFinalStop(0, 40);
    maskLinearGradient.setColorAt(0.1, QColor(150,194,29));
    maskLinearGradient.setColorAt(0.5, QColor(150,194,29));
    maskLinearGradient.setColorAt(0.9, QColor(150,194,29));

    font.setFamily("楷体");
    font.setBold(true);
    font.setPointSize(30);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Timeout()));
    lrcMaskWidth = 0;
    lrcMaskWidthInterval = 0;
  //  move(500,800);
}
void Lrc_View::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(font);
    painter.setPen(QColor(0,0,0,200));
    painter.drawText(1,1,800,60,Qt::AlignLeft,text());

    painter.setPen(QPen(linearGradient,0));
    painter.drawText(0,0,800,60,Qt::AlignLeft,text());

    painter.setPen(QPen(maskLinearGradient,0));
    painter.drawText(0,0,lrcMaskWidth,60,Qt::AlignLeft,text());
}
void Lrc_View::Start_Lrc(qint64 interval_time)
{
    qreal count = interval_time / 30;
    lrcMaskWidthInterval = 800 / count;
    lrcMaskWidth = 0;
    timer->start(30);
}
void Lrc_View::Stop_Lrc()
{
    timer->stop();
    lrcMaskWidth = 0;
    update();
}
//void Lrc_View::mousePressEvent(QMouseEvent *e)
//{
//    if(e->button() == Qt::LeftButton){
//        offset = e->globalPos() - frameGeometry().topLeft();
//    }
//}
//void Lrc_View::mouseMoveEvent(QMouseEvent *e)
//{
//    if(e->button() & Qt::LeftButton){
//        setCursor(Qt::PointingHandCursor);
//        move(e->globalPos() - offset);
//    }
//}
void Lrc_View::mousePressEvent(QMouseEvent *e)
{
    offset = e->globalPos();
}
void Lrc_View::mouseMoveEvent(QMouseEvent *e)
{
    int oldx = e->globalX() - offset.x();
    int oldy = e->globalY() - offset.y();
    offset = e->globalPos();
    setCursor(Qt::PointingHandCursor);
    move(x() + oldx , y() + oldy);
}
void Lrc_View::mouseReleaseEvent(QMouseEvent *e)
{
    int oldx = e->globalX() - offset.x();
    int oldy = e->globalY() - offset.y();
    move(x() + oldx , y() + oldy);
}
void Lrc_View::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu;
    menu.addAction(tr("Hide"),this,SLOT(hide()));
    menu.exec(e->globalPos());
}
void Lrc_View::Timeout()
{
    lrcMaskWidth += lrcMaskWidthInterval;
    update();
}
