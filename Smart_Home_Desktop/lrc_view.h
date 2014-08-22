#ifndef LRC_VIEW_H
#define LRC_VIEW_H

#include <QLabel>

class Lrc_View : public QLabel
{
    Q_OBJECT
public:
    explicit Lrc_View(QWidget *parent = 0);
    void Start_Lrc(qint64 interval_time);
    void Stop_Lrc();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void contextMenuEvent(QContextMenuEvent *e);
private slots:
    void Timeout();
private:
    QLinearGradient linearGradient;
    QLinearGradient maskLinearGradient;
    QFont font;
    QTimer *timer;
    qreal lrcMaskWidth;
    // 歌词遮罩的增加的宽度
    qreal lrcMaskWidthInterval;
    QPoint offset;

};

#endif // LRC_VIEW_H
