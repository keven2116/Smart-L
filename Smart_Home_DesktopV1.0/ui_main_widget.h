/********************************************************************************
** Form generated from reading UI file 'main_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WIDGET_H
#define UI_MAIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Widget
{
public:
    QWidget *Title_Widget;
    QLabel *Title_label;
    QStackedWidget *Change_Widget;
    QWidget *Change_WidgetPage1_2;
    QWebView *Weather_View;
    QListWidget *Join_List;
    QTextBrowser *textBrowser;
    QWidget *Change_WidgetPage2_2;
    QWidget *Tree_Widget;
    QWidget *Change_WidgetPage3_2;
    QFrame *Weather_Frame;
    QLabel *City_Label;
    QPushButton *Switch_City;
    QLabel *Air_img_Label;
    QLabel *Today_Label;
    QLabel *Air_Label;
    QLabel *Degree_Label;
    QLabel *Air_quality__Label;
    QPushButton *More_Weather_Btn;
    QWidget *Change_WidgetPage4_2;
    QTextBrowser *Log_TextBrower;
    QPushButton *Start_Btn;
    QWidget *Change_WidgetPage5_2;
    QLabel *Monitor_Label;
    QWidget *Change_WidgetPage6_2;
    QTableWidget *Music_list;
    QSlider *Music_process;
    QPushButton *Pre_Btn;
    QPushButton *Next_Btn;
    QPushButton *Mute_Btn;
    QSlider *Volume_Process;
    QPushButton *File_Btn;
    QToolButton *Play_Btn;
    QLabel *Time_song;
    QLabel *Current_Time;
    QTabWidget *Music_Tab_Widget;
    QWidget *List_tab_1;
    QWidget *List_tab_2;
    QWidget *List_tab_3;
    QTableView *Native_List_View;
    QLabel *Song_Name_Label;
    QPushButton *Mode_Btn;
    QPushButton *Song_Word_Btn;
    QLineEdit *Search_Edit;
    QToolButton *Add_Btn;
    QToolButton *Manage_Btn;
    QToolButton *Find_Btn;
    QWidget *Change_WidgetPage7_2;
    QWidget *Change_WidgetPage8_2;
    QTabWidget *Base_Set_Widget;
    QWidget *tab1;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *tab2;
    QWidget *tab3;
    QWidget *tab4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *Bottom_Widget;
    QToolButton *Home_Btn;
    QToolButton *Device_Btn;
    QToolButton *Information_Btn;
    QToolButton *Contrl_Btn;
    QToolButton *Monitor_Btn;
    QToolButton *Music_Btn;
    QToolButton *Set_Btn;
    QToolButton *Qzon_Btn;

    void setupUi(QDialog *Main_Widget)
    {
        if (Main_Widget->objectName().isEmpty())
            Main_Widget->setObjectName(QStringLiteral("Main_Widget"));
        Main_Widget->resize(800, 600);
        Main_Widget->setStyleSheet(QStringLiteral(""));
        Title_Widget = new QWidget(Main_Widget);
        Title_Widget->setObjectName(QStringLiteral("Title_Widget"));
        Title_Widget->setGeometry(QRect(0, 0, 800, 40));
        Title_Widget->setStyleSheet(QLatin1String("background-color: rgb(106, 106, 106);\n"
"color:white;"));
        Title_label = new QLabel(Title_Widget);
        Title_label->setObjectName(QStringLiteral("Title_label"));
        Title_label->setGeometry(QRect(0, 0, 700, 40));
        Title_label->setMinimumSize(QSize(375, 40));
        Title_label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        Title_label->setFont(font);
        Title_label->setAlignment(Qt::AlignCenter);
        Change_Widget = new QStackedWidget(Main_Widget);
        Change_Widget->setObjectName(QStringLiteral("Change_Widget"));
        Change_Widget->setGeometry(QRect(0, 40, 800, 500));
        Change_Widget->setStyleSheet(QStringLiteral(""));
        Change_WidgetPage1_2 = new QWidget();
        Change_WidgetPage1_2->setObjectName(QStringLiteral("Change_WidgetPage1_2"));
        Weather_View = new QWebView(Change_WidgetPage1_2);
        Weather_View->setObjectName(QStringLiteral("Weather_View"));
        Weather_View->setGeometry(QRect(0, 0, 300, 160));
        Weather_View->setAutoFillBackground(false);
        Weather_View->setStyleSheet(QStringLiteral("background-color:transparent;"));
        Join_List = new QListWidget(Change_WidgetPage1_2);
        Join_List->setObjectName(QStringLiteral("Join_List"));
        Join_List->setGeometry(QRect(0, 400, 800, 100));
        Join_List->setStyleSheet(QStringLiteral(" background-color:transparent;"));
        Join_List->setFrameShape(QFrame::NoFrame);
        Join_List->setFrameShadow(QFrame::Plain);
        Join_List->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Join_List->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Join_List->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Join_List->setAutoScroll(true);
        Join_List->setAlternatingRowColors(true);
        Join_List->setIconSize(QSize(60, 60));
        Join_List->setTextElideMode(Qt::ElideLeft);
        Join_List->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        Join_List->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        Join_List->setMovement(QListView::Static);
        Join_List->setFlow(QListView::LeftToRight);
        Join_List->setProperty("isWrapping", QVariant(false));
        Join_List->setResizeMode(QListView::Adjust);
        Join_List->setLayoutMode(QListView::Batched);
        Join_List->setViewMode(QListView::ListMode);
        Join_List->setWordWrap(false);
        textBrowser = new QTextBrowser(Change_WidgetPage1_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(300, 0, 380, 160));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QStringLiteral("background-color:transparent;"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        Change_Widget->addWidget(Change_WidgetPage1_2);
        Change_WidgetPage2_2 = new QWidget();
        Change_WidgetPage2_2->setObjectName(QStringLiteral("Change_WidgetPage2_2"));
        Tree_Widget = new QWidget(Change_WidgetPage2_2);
        Tree_Widget->setObjectName(QStringLiteral("Tree_Widget"));
        Tree_Widget->setGeometry(QRect(0, 0, 800, 500));
        Change_Widget->addWidget(Change_WidgetPage2_2);
        Change_WidgetPage3_2 = new QWidget();
        Change_WidgetPage3_2->setObjectName(QStringLiteral("Change_WidgetPage3_2"));
        Weather_Frame = new QFrame(Change_WidgetPage3_2);
        Weather_Frame->setObjectName(QStringLiteral("Weather_Frame"));
        Weather_Frame->setGeometry(QRect(0, 0, 300, 90));
        Weather_Frame->setFrameShape(QFrame::Box);
        Weather_Frame->setFrameShadow(QFrame::Sunken);
        City_Label = new QLabel(Weather_Frame);
        City_Label->setObjectName(QStringLiteral("City_Label"));
        City_Label->setGeometry(QRect(0, 20, 60, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        City_Label->setFont(font2);
        City_Label->setAlignment(Qt::AlignCenter);
        Switch_City = new QPushButton(Weather_Frame);
        Switch_City->setObjectName(QStringLiteral("Switch_City"));
        Switch_City->setGeometry(QRect(0, 50, 60, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        Switch_City->setFont(font3);
        Switch_City->setFlat(true);
        Air_img_Label = new QLabel(Weather_Frame);
        Air_img_Label->setObjectName(QStringLiteral("Air_img_Label"));
        Air_img_Label->setGeometry(QRect(69, 25, 48, 48));
        Today_Label = new QLabel(Weather_Frame);
        Today_Label->setObjectName(QStringLiteral("Today_Label"));
        Today_Label->setGeometry(QRect(120, 20, 65, 25));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        Today_Label->setFont(font4);
        Air_Label = new QLabel(Weather_Frame);
        Air_Label->setObjectName(QStringLiteral("Air_Label"));
        Air_Label->setGeometry(QRect(120, 50, 65, 25));
        Air_Label->setFont(font);
        Degree_Label = new QLabel(Weather_Frame);
        Degree_Label->setObjectName(QStringLiteral("Degree_Label"));
        Degree_Label->setGeometry(QRect(190, 20, 60, 25));
        QFont font5;
        font5.setBold(false);
        font5.setWeight(50);
        Degree_Label->setFont(font5);
        Air_quality__Label = new QLabel(Weather_Frame);
        Air_quality__Label->setObjectName(QStringLiteral("Air_quality__Label"));
        Air_quality__Label->setGeometry(QRect(190, 50, 60, 25));
        Air_quality__Label->setFont(font5);
        More_Weather_Btn = new QPushButton(Weather_Frame);
        More_Weather_Btn->setObjectName(QStringLiteral("More_Weather_Btn"));
        More_Weather_Btn->setGeometry(QRect(265, 35, 25, 25));
        More_Weather_Btn->setIconSize(QSize(25, 25));
        More_Weather_Btn->setFlat(true);
        Change_Widget->addWidget(Change_WidgetPage3_2);
        Change_WidgetPage4_2 = new QWidget();
        Change_WidgetPage4_2->setObjectName(QStringLiteral("Change_WidgetPage4_2"));
        Log_TextBrower = new QTextBrowser(Change_WidgetPage4_2);
        Log_TextBrower->setObjectName(QStringLiteral("Log_TextBrower"));
        Log_TextBrower->setGeometry(QRect(0, 35, 800, 465));
        Log_TextBrower->setFont(font4);
        Log_TextBrower->setStyleSheet(QStringLiteral("background-color:transparent;"));
        Start_Btn = new QPushButton(Change_WidgetPage4_2);
        Start_Btn->setObjectName(QStringLiteral("Start_Btn"));
        Start_Btn->setGeometry(QRect(290, 0, 131, 35));
        Start_Btn->setStyleSheet(QStringLiteral("background-color: rgb(185, 185, 185);"));
        Start_Btn->setFlat(true);
        Change_Widget->addWidget(Change_WidgetPage4_2);
        Change_WidgetPage5_2 = new QWidget();
        Change_WidgetPage5_2->setObjectName(QStringLiteral("Change_WidgetPage5_2"));
        Monitor_Label = new QLabel(Change_WidgetPage5_2);
        Monitor_Label->setObjectName(QStringLiteral("Monitor_Label"));
        Monitor_Label->setGeometry(QRect(0, 0, 800, 500));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font6.setPointSize(20);
        Monitor_Label->setFont(font6);
        Monitor_Label->setAlignment(Qt::AlignCenter);
        Change_Widget->addWidget(Change_WidgetPage5_2);
        Change_WidgetPage6_2 = new QWidget();
        Change_WidgetPage6_2->setObjectName(QStringLiteral("Change_WidgetPage6_2"));
        Music_list = new QTableWidget(Change_WidgetPage6_2);
        if (Music_list->columnCount() < 1)
            Music_list->setColumnCount(1);
        QFont font7;
        font7.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font7);
        __qtablewidgetitem->setBackground(QColor(0, 0, 0, 0));
        Music_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        Music_list->setObjectName(QStringLiteral("Music_list"));
        Music_list->setGeometry(QRect(530, 0, 270, 360));
        Music_list->setStyleSheet(QLatin1String("selection-background-color:gray;\n"
"background-color:transparent;\n"
"\n"
""));
        Music_list->setFrameShape(QFrame::Panel);
        Music_list->setFrameShadow(QFrame::Raised);
        Music_list->setLineWidth(1);
        Music_list->setMidLineWidth(0);
        Music_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Music_list->horizontalHeader()->setDefaultSectionSize(270);
        Music_list->horizontalHeader()->setHighlightSections(false);
        Music_list->horizontalHeader()->setMinimumSectionSize(270);
        Music_list->verticalHeader()->setDefaultSectionSize(30);
        Music_list->verticalHeader()->setHighlightSections(true);
        Music_list->verticalHeader()->setMinimumSectionSize(30);
        Music_process = new QSlider(Change_WidgetPage6_2);
        Music_process->setObjectName(QStringLiteral("Music_process"));
        Music_process->setGeometry(QRect(0, 430, 800, 15));
        Music_process->setStyleSheet(QLatin1String(" QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; \n"
"     border-radius: 3px;\n"
" }"));
        Music_process->setOrientation(Qt::Horizontal);
        Pre_Btn = new QPushButton(Change_WidgetPage6_2);
        Pre_Btn->setObjectName(QStringLiteral("Pre_Btn"));
        Pre_Btn->setGeometry(QRect(290, 450, 50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/play/pre"), QSize(), QIcon::Normal, QIcon::Off);
        Pre_Btn->setIcon(icon);
        Pre_Btn->setIconSize(QSize(35, 35));
        Pre_Btn->setFlat(true);
        Next_Btn = new QPushButton(Change_WidgetPage6_2);
        Next_Btn->setObjectName(QStringLiteral("Next_Btn"));
        Next_Btn->setGeometry(QRect(440, 450, 50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/play/next"), QSize(), QIcon::Normal, QIcon::Off);
        Next_Btn->setIcon(icon1);
        Next_Btn->setIconSize(QSize(35, 35));
        Next_Btn->setFlat(true);
        Mute_Btn = new QPushButton(Change_WidgetPage6_2);
        Mute_Btn->setObjectName(QStringLiteral("Mute_Btn"));
        Mute_Btn->setGeometry(QRect(520, 461, 25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/play/volume_noraml"), QSize(), QIcon::Normal, QIcon::Off);
        Mute_Btn->setIcon(icon2);
        Mute_Btn->setIconSize(QSize(25, 35));
        Mute_Btn->setFlat(true);
        Volume_Process = new QSlider(Change_WidgetPage6_2);
        Volume_Process->setObjectName(QStringLiteral("Volume_Process"));
        Volume_Process->setGeometry(QRect(549, 470, 100, 10));
        Volume_Process->setStyleSheet(QLatin1String(" QSlider::handle:horizontal {\n"
"     background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; \n"
"     border-radius: 3px;\n"
" }"));
        Volume_Process->setMaximum(200);
        Volume_Process->setValue(30);
        Volume_Process->setOrientation(Qt::Horizontal);
        File_Btn = new QPushButton(Change_WidgetPage6_2);
        File_Btn->setObjectName(QStringLiteral("File_Btn"));
        File_Btn->setGeometry(QRect(0, 456, 35, 35));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/play/images/play/windows.png"), QSize(), QIcon::Normal, QIcon::Off);
        File_Btn->setIcon(icon3);
        File_Btn->setIconSize(QSize(35, 35));
        File_Btn->setFlat(true);
        Play_Btn = new QToolButton(Change_WidgetPage6_2);
        Play_Btn->setObjectName(QStringLiteral("Play_Btn"));
        Play_Btn->setGeometry(QRect(350, 440, 80, 55));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/play/player"), QSize(), QIcon::Normal, QIcon::Off);
        Play_Btn->setIcon(icon4);
        Play_Btn->setIconSize(QSize(50, 50));
        Play_Btn->setAutoRaise(true);
        Time_song = new QLabel(Change_WidgetPage6_2);
        Time_song->setObjectName(QStringLiteral("Time_song"));
        Time_song->setGeometry(QRect(90, 476, 35, 20));
        Current_Time = new QLabel(Change_WidgetPage6_2);
        Current_Time->setObjectName(QStringLiteral("Current_Time"));
        Current_Time->setGeometry(QRect(50, 476, 35, 20));
        Current_Time->setStyleSheet(QStringLiteral(""));
        Music_Tab_Widget = new QTabWidget(Change_WidgetPage6_2);
        Music_Tab_Widget->setObjectName(QStringLiteral("Music_Tab_Widget"));
        Music_Tab_Widget->setGeometry(QRect(0, 0, 530, 428));
        Music_Tab_Widget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{border: 0px;} QTabWidget::tab-bar{alignment:center;} QTabBar::tab{background:transparent; color:white; min-width:175px; min-height:35px;font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";}QTabBar::tab:hover{background:rgb(255, 255, 255, 100);}\n"
"QTabBar::tab:selected{border-color:white;background:white;color:green;}"));
        List_tab_1 = new QWidget();
        List_tab_1->setObjectName(QStringLiteral("List_tab_1"));
        Music_Tab_Widget->addTab(List_tab_1, QString());
        List_tab_2 = new QWidget();
        List_tab_2->setObjectName(QStringLiteral("List_tab_2"));
        Music_Tab_Widget->addTab(List_tab_2, QString());
        List_tab_3 = new QWidget();
        List_tab_3->setObjectName(QStringLiteral("List_tab_3"));
        Native_List_View = new QTableView(List_tab_3);
        Native_List_View->setObjectName(QStringLiteral("Native_List_View"));
        Native_List_View->setGeometry(QRect(0, 0, 525, 395));
        Native_List_View->setStyleSheet(QLatin1String("selection-background-color:white;\n"
"background-color:transparent;"));
        Native_List_View->setFrameShape(QFrame::NoFrame);
        Native_List_View->setSortingEnabled(false);
        Music_Tab_Widget->addTab(List_tab_3, QString());
        Song_Name_Label = new QLabel(Change_WidgetPage6_2);
        Song_Name_Label->setObjectName(QStringLiteral("Song_Name_Label"));
        Song_Name_Label->setGeometry(QRect(50, 456, 200, 20));
        Mode_Btn = new QPushButton(Change_WidgetPage6_2);
        Mode_Btn->setObjectName(QStringLiteral("Mode_Btn"));
        Mode_Btn->setGeometry(QRect(660, 460, 50, 30));
        Mode_Btn->setAutoDefault(true);
        Mode_Btn->setDefault(false);
        Mode_Btn->setFlat(false);
        Song_Word_Btn = new QPushButton(Change_WidgetPage6_2);
        Song_Word_Btn->setObjectName(QStringLiteral("Song_Word_Btn"));
        Song_Word_Btn->setGeometry(QRect(730, 460, 50, 30));
        Song_Word_Btn->setIconSize(QSize(35, 35));
        Search_Edit = new QLineEdit(Change_WidgetPage6_2);
        Search_Edit->setObjectName(QStringLiteral("Search_Edit"));
        Search_Edit->setGeometry(QRect(530, 360, 270, 25));
        Add_Btn = new QToolButton(Change_WidgetPage6_2);
        Add_Btn->setObjectName(QStringLiteral("Add_Btn"));
        Add_Btn->setGeometry(QRect(530, 400, 90, 28));
        Add_Btn->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:gray;\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/play/Plus"), QSize(), QIcon::Normal, QIcon::Off);
        Add_Btn->setIcon(icon5);
        Add_Btn->setIconSize(QSize(60, 25));
        Add_Btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Add_Btn->setAutoRaise(true);
        Manage_Btn = new QToolButton(Change_WidgetPage6_2);
        Manage_Btn->setObjectName(QStringLiteral("Manage_Btn"));
        Manage_Btn->setGeometry(QRect(620, 400, 90, 28));
        Manage_Btn->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:gray;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/play/manage"), QSize(), QIcon::Normal, QIcon::Off);
        Manage_Btn->setIcon(icon6);
        Manage_Btn->setIconSize(QSize(60, 20));
        Manage_Btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Manage_Btn->setAutoRaise(true);
        Find_Btn = new QToolButton(Change_WidgetPage6_2);
        Find_Btn->setObjectName(QStringLiteral("Find_Btn"));
        Find_Btn->setGeometry(QRect(710, 400, 90, 28));
        Find_Btn->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color:gray;"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/play/Search"), QSize(), QIcon::Normal, QIcon::Off);
        Find_Btn->setIcon(icon7);
        Find_Btn->setIconSize(QSize(60, 20));
        Find_Btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Find_Btn->setAutoRaise(true);
        Change_Widget->addWidget(Change_WidgetPage6_2);
        Change_WidgetPage7_2 = new QWidget();
        Change_WidgetPage7_2->setObjectName(QStringLiteral("Change_WidgetPage7_2"));
        Change_Widget->addWidget(Change_WidgetPage7_2);
        Change_WidgetPage8_2 = new QWidget();
        Change_WidgetPage8_2->setObjectName(QStringLiteral("Change_WidgetPage8_2"));
        Base_Set_Widget = new QTabWidget(Change_WidgetPage8_2);
        Base_Set_Widget->setObjectName(QStringLiteral("Base_Set_Widget"));
        Base_Set_Widget->setGeometry(QRect(0, 20, 800, 430));
        Base_Set_Widget->setFont(font);
        Base_Set_Widget->setStyleSheet(QLatin1String("QTabWidget::pane{border: 0px;} QTabWidget::tab-bar{alignment:center;} QTabBar::tab{background:transparent; color:white; min-width:180px; min-height:20px;}QTabBar::tab:hover{background:rgb(255, 255, 255, 100);}\n"
"QTabBar::tab:selected{border-color:white;background:white;color:green;}"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 440, 100));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font8.setPointSize(10);
        groupBox->setFont(font8);
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QStringLiteral("QGroupBox::title{color:green;}"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 20, 300, 25));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 45, 300, 25));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 70, 300, 25));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/TrayMenu/images/TrayMenu/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        Base_Set_Widget->addTab(tab1, icon8, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        Base_Set_Widget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        Base_Set_Widget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QStringLiteral("tab4"));
        Base_Set_Widget->addTab(tab4, QString());
        pushButton_2 = new QPushButton(Change_WidgetPage8_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 460, 100, 30));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{border:0px solid lightgray; background:rgb(18,163,146);color:white;}\n"
"QPushButton:hover{border-color:green; background:transparent;}"));
        pushButton_2->setFlat(false);
        pushButton = new QPushButton(Change_WidgetPage8_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(690, 460, 100, 30));
        pushButton->setStyleSheet(QLatin1String("QPushButton{border:0px solid lightgray; background:rgb(18,163,146);color:white;}\n"
"QPushButton:hover{border-color:green; background:transparent;}"));
        Change_Widget->addWidget(Change_WidgetPage8_2);
        Bottom_Widget = new QWidget(Main_Widget);
        Bottom_Widget->setObjectName(QStringLiteral("Bottom_Widget"));
        Bottom_Widget->setGeometry(QRect(0, 540, 800, 60));
        Bottom_Widget->setStyleSheet(QLatin1String("QToolButton {color:white;background-color: rgb(60, 60, 60);}\n"
"QToolButton::hover{rgb(255,255,255)};"));
        Home_Btn = new QToolButton(Bottom_Widget);
        Home_Btn->setObjectName(QStringLiteral("Home_Btn"));
        Home_Btn->setGeometry(QRect(0, 0, 100, 60));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setWeight(75);
        Home_Btn->setFont(font9);
        Home_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/contentWidget/images/contentWidget/meun.png"), QSize(), QIcon::Normal, QIcon::Off);
        Home_Btn->setIcon(icon9);
        Home_Btn->setIconSize(QSize(36, 36));
        Home_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Home_Btn->setAutoRaise(true);
        Device_Btn = new QToolButton(Bottom_Widget);
        Device_Btn->setObjectName(QStringLiteral("Device_Btn"));
        Device_Btn->setGeometry(QRect(100, 0, 100, 60));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(60, 60, 60, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Device_Btn->setPalette(palette);
        Device_Btn->setFont(font9);
        Device_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/contentWidget/images/contentWidget/fans.png"), QSize(), QIcon::Normal, QIcon::Off);
        Device_Btn->setIcon(icon10);
        Device_Btn->setIconSize(QSize(36, 36));
        Device_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Device_Btn->setAutoRaise(true);
        Information_Btn = new QToolButton(Bottom_Widget);
        Information_Btn->setObjectName(QStringLiteral("Information_Btn"));
        Information_Btn->setGeometry(QRect(300, 0, 100, 60));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Information_Btn->setPalette(palette1);
        QFont font10;
        font10.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font10.setPointSize(10);
        font10.setBold(true);
        font10.setWeight(75);
        font10.setKerning(true);
        Information_Btn->setFont(font10);
        Information_Btn->setToolTipDuration(-1);
        Information_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/contentWidget/images/contentWidget/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        Information_Btn->setIcon(icon11);
        Information_Btn->setIconSize(QSize(36, 36));
        Information_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Information_Btn->setAutoRaise(true);
        Contrl_Btn = new QToolButton(Bottom_Widget);
        Contrl_Btn->setObjectName(QStringLiteral("Contrl_Btn"));
        Contrl_Btn->setGeometry(QRect(200, 0, 100, 60));
        Contrl_Btn->setFont(font9);
        Contrl_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/contentWidget/images/contentWidget/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        Contrl_Btn->setIcon(icon12);
        Contrl_Btn->setIconSize(QSize(36, 36));
        Contrl_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Contrl_Btn->setAutoRaise(true);
        Monitor_Btn = new QToolButton(Bottom_Widget);
        Monitor_Btn->setObjectName(QStringLiteral("Monitor_Btn"));
        Monitor_Btn->setGeometry(QRect(400, 0, 100, 60));
        Monitor_Btn->setFont(font9);
        Monitor_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/contentWidget/images/contentWidget/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        Monitor_Btn->setIcon(icon13);
        Monitor_Btn->setIconSize(QSize(36, 36));
        Monitor_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Monitor_Btn->setAutoRaise(true);
        Music_Btn = new QToolButton(Bottom_Widget);
        Music_Btn->setObjectName(QStringLiteral("Music_Btn"));
        Music_Btn->setGeometry(QRect(500, 0, 100, 60));
        Music_Btn->setFont(font9);
        Music_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/contentWidget/images/contentWidget/music.png"), QSize(), QIcon::Normal, QIcon::Off);
        Music_Btn->setIcon(icon14);
        Music_Btn->setIconSize(QSize(36, 36));
        Music_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Music_Btn->setAutoRaise(true);
        Set_Btn = new QToolButton(Bottom_Widget);
        Set_Btn->setObjectName(QStringLiteral("Set_Btn"));
        Set_Btn->setGeometry(QRect(700, 0, 100, 60));
        Set_Btn->setFont(font9);
        Set_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/contentWidget/images/contentWidget/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        Set_Btn->setIcon(icon15);
        Set_Btn->setIconSize(QSize(36, 36));
        Set_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Set_Btn->setAutoRaise(true);
        Qzon_Btn = new QToolButton(Bottom_Widget);
        Qzon_Btn->setObjectName(QStringLiteral("Qzon_Btn"));
        Qzon_Btn->setGeometry(QRect(600, 0, 100, 60));
        Qzon_Btn->setFont(font9);
        Qzon_Btn->setStyleSheet(QStringLiteral(""));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/contentWidget/images/contentWidget/yun.png"), QSize(), QIcon::Normal, QIcon::Off);
        Qzon_Btn->setIcon(icon16);
        Qzon_Btn->setIconSize(QSize(36, 36));
        Qzon_Btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Qzon_Btn->setAutoRaise(true);

        retranslateUi(Main_Widget);

        Change_Widget->setCurrentIndex(5);
        Music_Tab_Widget->setCurrentIndex(0);
        Base_Set_Widget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Main_Widget);
    } // setupUi

    void retranslateUi(QDialog *Main_Widget)
    {
        Main_Widget->setWindowTitle(QApplication::translate("Main_Widget", "Dialog", 0));
        Title_label->setText(QString());
#ifndef QT_NO_TOOLTIP
        Join_List->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        textBrowser->setHtml(QApplication::translate("Main_Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt; font-weight:600;\">Welcome User Home_Desk!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:10pt; font-weight:600;\"><br /></p></body></html>", 0));
        City_Label->setText(QString());
        Switch_City->setText(QString());
        Air_img_Label->setText(QString());
        Today_Label->setText(QString());
        Air_Label->setText(QString());
        Degree_Label->setText(QString());
        Air_quality__Label->setText(QString());
        More_Weather_Btn->setText(QString());
        Log_TextBrower->setPlaceholderText(QString());
        Start_Btn->setText(QApplication::translate("Main_Widget", "Start", 0));
        Monitor_Label->setText(QApplication::translate("Main_Widget", "Monitor Video", 0));
        QTableWidgetItem *___qtablewidgetitem = Music_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Main_Widget", "Start your music travl", 0));
        Pre_Btn->setText(QString());
        Next_Btn->setText(QString());
        Mute_Btn->setText(QString());
        File_Btn->setText(QString());
        Play_Btn->setText(QApplication::translate("Main_Widget", "play", 0));
        Time_song->setText(QApplication::translate("Main_Widget", "00:00", 0));
        Current_Time->setText(QApplication::translate("Main_Widget", "00:00|", 0));
        Music_Tab_Widget->setTabText(Music_Tab_Widget->indexOf(List_tab_1), QString());
        Music_Tab_Widget->setTabText(Music_Tab_Widget->indexOf(List_tab_2), QString());
        Music_Tab_Widget->setTabText(Music_Tab_Widget->indexOf(List_tab_3), QString());
        Song_Name_Label->setText(QApplication::translate("Main_Widget", "Welcome using smart music!", 0));
        Mode_Btn->setText(QString());
        Song_Word_Btn->setText(QString());
        Add_Btn->setText(QApplication::translate("Main_Widget", "...", 0));
        Manage_Btn->setText(QApplication::translate("Main_Widget", "...", 0));
        Find_Btn->setText(QApplication::translate("Main_Widget", "...", 0));
        groupBox->setTitle(QApplication::translate("Main_Widget", "Base_Setting", 0));
        checkBox->setText(QApplication::translate("Main_Widget", "Programe Start auto Run", 0));
        checkBox_2->setText(QApplication::translate("Main_Widget", "Programe Start auto Run", 0));
        checkBox_3->setText(QApplication::translate("Main_Widget", "Programe Start auto Run", 0));
        Base_Set_Widget->setTabText(Base_Set_Widget->indexOf(tab1), QString());
        Base_Set_Widget->setTabText(Base_Set_Widget->indexOf(tab2), QString());
        Base_Set_Widget->setTabText(Base_Set_Widget->indexOf(tab3), QString());
        Base_Set_Widget->setTabText(Base_Set_Widget->indexOf(tab4), QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Main_Widget", "default", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("Main_Widget", "default", 0));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Main_Widget", "sure", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("Main_Widget", "sure", 0));
        Home_Btn->setText(QApplication::translate("Main_Widget", "Home", 0));
        Device_Btn->setText(QApplication::translate("Main_Widget", "Device", 0));
        Information_Btn->setText(QApplication::translate("Main_Widget", "Information", 0));
        Contrl_Btn->setText(QApplication::translate("Main_Widget", "Contrl", 0));
        Monitor_Btn->setText(QApplication::translate("Main_Widget", "Monitor", 0));
        Music_Btn->setText(QApplication::translate("Main_Widget", "Music", 0));
#ifndef QT_NO_TOOLTIP
        Set_Btn->setToolTip(QApplication::translate("Main_Widget", "<html><head/><body><p><img src=\":/card/Jobs\"/>Name\357\274\232Jobs<br/>Relations\357\274\232Friends<br/>Phone:010-10628532<br/>E-mail:Jobs@gmail.com</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Set_Btn->setText(QApplication::translate("Main_Widget", "Setting", 0));
        Qzon_Btn->setText(QApplication::translate("Main_Widget", "Qzon", 0));
    } // retranslateUi

};

namespace Ui {
    class Main_Widget: public Ui_Main_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WIDGET_H
