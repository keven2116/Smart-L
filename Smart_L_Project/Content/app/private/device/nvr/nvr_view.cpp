#include "nvr_view.h"
#include "ui_nvr_view.h"

Nvr_view::Nvr_view(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nvr_view)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint |
                         Qt::WindowMinMaxButtonsHint);
    this->setStyleSheet("background-color:transparent");
    ui->Nvr_tree->setStyleSheet("background-color:transparent");
    nvr_init();
    nvr_menu_init();
}

Nvr_view::~Nvr_view()
{
    delete ui;
}
void Nvr_view::nvr_init()
{
    VideoLab.append(ui->Video_Channel_1);
    VideoLab.append(ui->Video_Channel_2);
    VideoLab.append(ui->Video_Channel_3);
    VideoLab.append(ui->Video_Channel_4);
    VideoLab.append(ui->Video_Channel_5);
    VideoLab.append(ui->Video_Channel_6);
    VideoLab.append(ui->Video_Channel_7);
    VideoLab.append(ui->Video_Channel_8);
    VideoLab.append(ui->Video_Channel_9);
    VideoLab.append(ui->Video_Channel_10);
    VideoLab.append(ui->Video_Channel_11);
    VideoLab.append(ui->Video_Channel_12);
    VideoLab.append(ui->Video_Channel_13);
    VideoLab.append(ui->Video_Channel_14);
    VideoLab.append(ui->Video_Channel_15);
    VideoLab.append(ui->Video_Channel_16);

    VideoLay.append(ui->video_channel_layout_1);
    VideoLay.append(ui->video_channel_layout_2);
    VideoLay.append(ui->video_channel_layout_3);
    VideoLay.append(ui->video_channel_layout_4);

    for (int i = 0; i < 16; i++) {
        VideoLab[i]->installEventFilter(this);
        VideoLab[i]->setProperty("Video_Channel_", true);
        VideoLab[i]->setText(QString("通道%1").arg(i + 1));
    }
}
void Nvr_view::nvr_menu_init()
{
    menu = new QMenu(this);
    menu->setStyleSheet("font: 10pt \"微软雅黑\";");
    menu->addAction("删除当前视频", this, SLOT(Delete_Video_Signal()));
    menu->addAction("删除所有视频", this, SLOT(Delete_Video_Signal()));
    menu->addSeparator();
    menu->addAction("截图当前视频", this, SLOT(Snapshot_Video_View(int)));
    menu->addAction("截图所有视频", this, SLOT(Snapshot_Video_View(int)));
    menu->addSeparator();

    QMenu *menu1 = menu->addMenu("切换到1画面");
    menu1->addAction("通道1", this, SLOT(Change_Show_View()));
    menu1->addAction("通道2", this, SLOT(Change_Show_View()));
    menu1->addAction("通道3", this, SLOT(Change_Show_View()));
    menu1->addAction("通道4", this, SLOT(Change_Show_View()));
    menu1->addAction("通道5", this, SLOT(Change_Show_View()));
    menu1->addAction("通道6", this, SLOT(Change_Show_View()));
    menu1->addAction("通道7", this, SLOT(Change_Show_View()));
    menu1->addAction("通道8", this, SLOT(Change_Show_View()));
    menu1->addAction("通道9", this, SLOT(Change_Show_View()));
    menu1->addAction("通道10", this, SLOT(Change_Show_View()));
    menu1->addAction("通道11", this, SLOT(Change_Show_View()));
    menu1->addAction("通道12", this, SLOT(Change_Show_View()));
    menu1->addAction("通道13", this, SLOT(Change_Show_View()));
    menu1->addAction("通道14", this, SLOT(Change_Show_View()));
    menu1->addAction("通道15", this, SLOT(Change_Show_View()));
    menu1->addAction("通道16", this, SLOT(Change_Show_View()));

    QMenu *menu4 = menu->addMenu("切换到4画面");
    menu4->addAction("通道1-通道4", this, SLOT(Change_Show_View()));
    menu4->addAction("通道5-通道8", this, SLOT(Change_Show_View()));
    menu4->addAction("通道9-通道12", this, SLOT(Change_Show_View()));
    menu4->addAction("通道13-通道16", this, SLOT(Change_Show_View()));

    QMenu *menu9 = menu->addMenu("切换到9画面");
    menu9->addAction("通道1-通道9", this, SLOT(Change_Show_View()));
    menu9->addAction("通道8-通道16", this, SLOT(Change_Show_View()));

    menu->addAction("切换到16画面", this, SLOT(Change_Show_View()));
}
void Nvr_view::Delete_Video_Signal()
{

}
void Nvr_view::Snapshot_Video_View(int slot)
{

}
void Nvr_view::Change_Show_View(int slot)
{
   // removelayout();
  //  myApp::VideoType = "1";
    Is_Max = true;
    int index = 0;

    QAction *action = (QAction *)sender();
    QString name = action->text();
    if (name == "通道1") {
        index = 0;
    } else if (name == "通道2") {
        index = 1;
    } else if (name == "通道3") {
        index = 2;
    } else if (name == "通道4") {
        index = 3;
    } else if (name == "通道5") {
        index = 4;
    } else if (name == "通道6") {
        index = 5;
    } else if (name == "通道7") {
        index = 6;
    } else if (name == "通道8") {
        index = 7;
    } else if (name == "通道9") {
        index = 8;
    } else if (name == "通道10") {
        index = 9;
    } else if (name == "通道11") {
        index = 10;
    } else if (name == "通道12") {
        index = 11;
    } else if (name == "通道13") {
        index = 12;
    } else if (name == "通道14") {
        index = 13;
    } else if (name == "通道15") {
        index = 14;
    } else if (name == "通道16") {
        index = 15;
    }

   // change_video_1(index);
    //myApp::WriteConfig();
}
bool Nvr_view::eventFilter(QObject *obj, QEvent *event)
{
    /*
    QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);
    if ((event->type() == QEvent::MouseButtonDblClick) &&
            (MouseEvent->buttons() == Qt::LeftButton)) {
        QLabel *labDouble = qobject_cast<QLabel *>(obj);
        if (!video_max) {
            removelayout();
            video_max = true;
            VideoLay[0]->addWidget(labDouble);
            labDouble->setVisible(true);
        } else {
            video_max = false;
            ChangeVideoLayout();
        }

        labDouble->setFocus();
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        if (obj == ui->labFull) {
            screen_full();
            return true;
        } else if (obj == ui->labStart) {
            if (ui->labStart->text() == "启动轮询") {
                ui->labStart->setText("停止轮询");
            } else {
                ui->labStart->setText("启动轮询");
            }
            return true;
        } else if (obj == ui->labNVR) {
            frmNVR nvr;
            nvr.exec();
            LoadNVRIPC();
            return true;
        } else if (obj == ui->labIPC) {
            frmIPC ipc;
            ipc.exec();
            LoadNVRIPC();
            return true;
        } else if (obj == ui->labPollConfig) {
            frmPollConfig pollConfig;
            pollConfig.exec();
            return true;
        } else if (obj == ui->labVideoPlayBack) {
            myHelper::ShowMessageBoxError("功能暂未开放!");
            return true;
        } else if (obj == ui->labConfig) {
            frmConfig config;
            config.exec();
            ui->lab_Title->setText(myApp::AppTitle);
            this->setWindowTitle(myApp::AppTitle);
            return true;
        } else if (obj == ui->labExit) {
            on_btnMenu_Close_clicked();
            return true;
        } else if (obj == ui->labStyle) {
            menuStyle->exec(QPoint(myApp::DeskWidth - 135, 31));
            return true;
        } else if (MouseEvent->buttons() == Qt::RightButton) {
            tempLab = qobject_cast<QLabel *>(obj);
            menu->exec(QCursor::pos());
            return true;
        } else {
            tempLab = qobject_cast<QLabel *>(obj);
            ui->lab_Title->setText(QString("%1  当前选中[%2]").arg(myApp::AppTitle).arg(tempLab->text()));
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
    */
}
