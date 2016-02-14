#include "bottom_btn.h"

Bottom_Btn::Bottom_Btn(QWidget *parent) :
    QToolButton(parent)
{
}
void Bottom_Btn::Load_img(QString resouce_id,QString Name)
{
       QByteArray ba = Name.toLatin1();
   //    Bottom_weight = pixmap.width()/4;
    //   Bottom_height = pixmap.height();
       /*Keep img size setting style*/
       //setFixedSize(Bottom_weight,Bottom_height);
       setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
       setFixedSize(80,100);
       setAutoRaise(true);
       setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
       setIconSize(QSize(64,64));
       setIcon(QPixmap(resouce_id));
       setText(Name);
       setFont(QFont("楷体", 10, QFont::Normal));
   //    setToolTip(tr(ba.data()));  /*how update ts?*/
 //      setToolTip(Name);
}
void Bottom_Btn::Load_img_small(QString resouce_id,QString Name)
{
       QByteArray ba = Name.toLatin1();
   //    Bottom_weight = pixmap.width()/4;
    //   Bottom_height = pixmap.height();
       /*Keep img size setting style*/
       //setFixedSize(Bottom_weight,Bottom_height);
       setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
       setFixedSize(60,60);
       setAutoRaise(true);
       setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
       setIconSize(QSize(35,35));
       setIcon(QPixmap(resouce_id));
       setText(Name);
       setFont(QFont("楷体", 10, QFont::Normal));
   //    setToolTip(tr(ba.data()));  /*how update ts?*/
 //      setToolTip(Name);
}
void Bottom_Btn::Load_Beside_img(QString resouce_id, QString Name,int x,int y,int z)
{
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    setAutoRaise(true);
    if (0 != x && 0 != y)
        setFixedSize(x,y);
    setIconSize(QSize(z,z));
    setIcon(QPixmap(resouce_id));
    setText(Name);
}

void Bottom_Btn::Load_Bottom_img(QString resouce_id, QString Name,int x,int y,int z)
{
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setAutoRaise(true);
    setFixedSize(x,y);
    setIconSize(QSize(z,z));
    setIcon(QPixmap(resouce_id));
    setText(Name);
}
void Bottom_Btn::Load_img_lage(QString resouce_id,QString Name)
{
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    setAutoRaise(true);
    setFixedSize(200,80);
    setIconSize(QSize(32,32));
    setIcon(QPixmap(resouce_id));
    setText(Name);
}
