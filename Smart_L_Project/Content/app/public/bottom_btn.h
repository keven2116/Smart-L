#ifndef BOTTOM_BTN_H
#define BOTTOM_BTN_H

#include <QToolButton>

class Bottom_Btn : public QToolButton
{
    Q_OBJECT
public:
    explicit Bottom_Btn(QWidget *parent = 0);
    void Load_img(QString resouce_id,QString Name);  //load images  / 4
    void Load_img_small(QString resouce_id,QString Name);
    void Load_img_lage(QString resouce_id,QString Name);
    void Load_Beside_img(QString resouce_id, QString Name,int x,int y,int z);
    void Load_Bottom_img(QString resouce_id, QString Name,int x,int y,int z);
signals:

public slots:
private:
    QPixmap pixmap;
    int Bottom_weight;
    int Bottom_height;

};

#endif // BOTTOM_BTN_H
