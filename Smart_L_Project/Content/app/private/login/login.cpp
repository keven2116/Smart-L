#include "login.h"
#include <QtGui>

QString passwd_str;

Login::Login(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(400,300);
    //setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    setWindowTitle("Smart L");
    setWindowIcon(QIcon(":/logo/logo"));
    Resource_init();

    /*
    setStyleSheet("QToolButton {color:white;background-color: rgb(23, 197, 104);} \
                  QToolButton::hover{color:white;background-color: rgb(23, 209, 1);}; \
                ");*/
    Qrcode_Layout_init(); //二维码登录
    Login_layout_init();
    Bottom_menu_init();
    translation();
    Visable_qrocde = false;
    QString qss;
    QFile qssFile(":/qss/login");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qDebug() << "---\n";
        qss = QLatin1String(qssFile.readAll());
  //      qDebug() << qss;
        this->setStyleSheet(qss);
        qssFile.close();
    }
}
Login::~Login()
{

}
void Login::Resource_init()
{
    /*QString qss;
    QFile qssFile(SMART_RESOURCE);
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        setStyleSheet(qss);
        qssFile.close();
    }*/
#if 0
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    qDebug() << QStringLiteral("处理器掩码:") << systemInfo.dwActiveProcessorMask;
    qDebug() << QStringLiteral("处理器个数:") << systemInfo.dwNumberOfProcessors;
    qDebug() << QStringLiteral("处理器分页大小:") << systemInfo.dwPageSize;
    qDebug() << QStringLiteral("处理器类型:") << systemInfo.dwProcessorType;
    qDebug() << QStringLiteral("最大寻址单元:") << systemInfo.lpMaximumApplicationAddress;
    qDebug() << QStringLiteral("最小寻址单元:") << systemInfo.lpMinimumApplicationAddress;
    qDebug() << QStringLiteral("处理器等级:") << systemInfo.wProcessorLevel;
    qDebug() << QStringLiteral("处理器版本:") << systemInfo.wProcessorRevision;

    #define MB (1024 * 1024)
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx (&statex);
    qDebug() << QStringLiteral("物理内存使用率:") << statex.dwMemoryLoad;
    qDebug() << QStringLiteral("物理内存总量:") << statex.ullTotalPhys/MB;
    qDebug() << QStringLiteral("可用的物理内存:") << statex.ullAvailPhys/MB;
    qDebug() << QStringLiteral("系统页面文件大小:") << statex.ullTotalPageFile/MB;
    qDebug() << QStringLiteral("系统可用页面文件大小:") << statex.ullAvailPageFile/MB;
    qDebug() << QStringLiteral("虚拟内存总量:") << statex.ullTotalVirtual/MB;
    qDebug() << QStringLiteral("可用的虚拟内存:") << statex.ullAvailVirtual/MB;
    qDebug() << QStringLiteral("保留（值为0）:") << statex.ullAvailExtendedVirtual/MB;
#endif
}
void Login::mousePressEvent(QMouseEvent *e)
{
   Last_Point = e->globalPos();
}
void Login::mouseMoveEvent(QMouseEvent *e)
{
    int oldx = e->globalX() - Last_Point.x();
    int oldy = e->globalY() - Last_Point.y();
    Last_Point = e->globalPos();
    move(x() + oldx , y() + oldy);
  //  Timer_Show->start(10);
}
void Login::mouseReleaseEvent(QMouseEvent *e)
{
    int oldx = e->globalX() - Last_Point.x();
    int oldy = e->globalY() - Last_Point.y();
    move(x() + oldx , y() + oldy);
}
void Login::Login_layout_init()
{
    /*top*/
    Close_Btn = new Push_Btn();
    Min_Btn = new Push_Btn();
    Title_label = new QLabel();
    top_lable = new QLabel();
    top_img = new QMovie();  //Keep
    QFont TitleFont("楷体", 12, QFont::Bold);
    Title_label->setFixedSize(400,35);
    Title_label->setStyleSheet("background-color:rgb(23, 197, 104); color:white;");
    Min_Btn->Load_Pixmap_keven(":/SysButton/min");
    Close_Btn->Load_Pixmap_keven(":/SysButton/close");
    Title_label->setText(tr("Smart L"));
    Title_label->setFont(TitleFont);
    Title_label->setAlignment(Qt::AlignCenter);
    top_layout = new QHBoxLayout();
    top_layout->addWidget(Title_label);
    top_layout->addWidget(Min_Btn);
    top_layout->addWidget(Close_Btn);
    top_layout->setMargin(0);
    top_layout->setSpacing(0);

    /*middle*/
    User_Name = new QLineEdit();
    Passwd = new QLineEdit();
    Regiser_account = new QLabel();
    Forget_Passwd = new  QLabel();
    Auto_login = new QCheckBox();
    Remind_passwd = new QCheckBox();

    User_Name->setPlaceholderText(tr("Account"));
    User_Name->setFixedSize(150, 30);
    Passwd->setPlaceholderText(tr("Passwd"));
    Passwd->setEchoMode(QLineEdit::Password);
    Passwd->setFixedSize(150, 30);
    Regiser_account->setText("<a href = http://blog.csdn.net/ongoingcre>" + tr("Register") + "</a>");
    Regiser_account->setFixedSize(50,30);
    Forget_Passwd->setText("<a href = http://blog.csdn.net/ongoingcre>" + tr("Forget") + "</a>");
    Forget_Passwd->setFixedSize(50,30);
    Auto_login->setText(tr("Auto Login"));
    Auto_login->setFixedSize(100,30);
    Remind_passwd->setText(tr("Remind Passwd"));
    Remind_passwd->setFixedSize(100,30);
    //Regiser_account->setStyleSheet("background-color:red");

    middle_layout = new QGridLayout();
    middle_layout->addWidget(User_Name,0,0,Qt::AlignCenter);
    middle_layout->addWidget(Regiser_account,0,1,Qt::AlignRight);
    middle_layout->addWidget(Passwd,1,0,Qt::AlignCenter);
    middle_layout->addWidget(Forget_Passwd,1,1,Qt::AlignRight);
    middle_layout->addWidget(Auto_login,2,0,Qt::AlignCenter);
    middle_layout->addWidget(Remind_passwd,2,1,Qt::AlignCenter);
    //middle_layout->setMargin(0);
    middle_layout->setSpacing(25);
    middle_layout->setContentsMargins(100,75,80,15);
    middle_layout->setColumnStretch(6,1);


    /*bottom*/
    Login_Btn = new Bottom_Btn();
    Qrcode_Btn = new QPushButton();
    Qrcode_Btn->setFixedSize(35,25);
    Qrcode_Btn->setCursor(QCursor(Qt::PointingHandCursor));
    //Login_Btn->setFixedSize(200,35);
    Qrcode = new QLabel();
    Qrcode->setFixedSize(65,35);

    Login_Btn->Load_Beside_img("",tr("Login"),200,35,25);
    Login_Btn->setShortcut(Qt::Key_Enter);  //设置快捷键为Enter
    Login_Btn->setShortcut(QKeySequence::InsertParagraphSeparator); //回车快捷键
    Login_Btn->setFocus();
    QFont BottomFont("楷体", 10.5, QFont::Bold);
    Login_Btn->setFont(BottomFont);
    Qrcode_Btn->setIcon(QIcon(":/Mainmenu/qrcode"));
    Qrcode_Btn->setFlat(true);

    bottom_layout = new QHBoxLayout();
    //bottom_layout->addStretch(0);
    bottom_layout->addWidget(Login_Btn);
    bottom_layout->addWidget(Qrcode);
    bottom_layout->addWidget(Qrcode_Btn);
    bottom_layout->setMargin(0);
    bottom_layout->setSpacing(0);
    bottom_layout->setContentsMargins(100,0,0,15);
/**/
    page_1_login = new QWidget(this);
    page_1_login->setLayout(middle_layout);
    page_1_login->setStyleSheet("background-color:white");

    main_layout = new QStackedLayout();
    main_layout->addWidget(page_1_login);
    main_layout->addWidget(page_2_qrcode);
    main_layout->setMargin(0);
    main_layout->setSpacing(0);
    main_layout->setCurrentWidget(page_1_login);


    /*main layout*/
    layout = new QVBoxLayout(this);
    layout->addLayout(top_layout);
    layout->addLayout(main_layout);
    layout->addLayout(bottom_layout);
    //layout->addStretch(0);
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);


    /*自动补全*/
    QStringList word_list;
    word_list<<"admin"<<"user";
    m_completer = new QCompleter(word_list, this);
    m_completer->setCaseSensitivity(Qt::CaseInsensitive);
    User_Name->setCompleter(m_completer);
    /*SIGNAL TO SLOT*/
    connect(Close_Btn,SIGNAL(clicked()),this,SLOT(close()));
    connect(Regiser_account,SIGNAL(linkActivated(QString)),this,SLOT(OpenUrl(QString )));
    connect(Forget_Passwd,SIGNAL(linkActivated(QString)),this,SLOT(OpenUrl(QString )));
    connect(Login_Btn,SIGNAL(clicked()),this,SLOT(Login_response()));
    connect(Min_Btn,SIGNAL(clicked()),this,SLOT(hide()));
    connect(Qrcode_Btn,SIGNAL(clicked()),this,SLOT(Qrcode_Btn_clicked()));
}
void Login::Bottom_menu_init()
{
    Bottom_menu = new QMenu();
    A_open = new QAction(Bottom_menu);
    A_quit = new QAction(Bottom_menu);

    A_open->setIcon(QIcon(":/Mainmenu/open"));
    A_quit->setIcon(QIcon(":/Mainmenu/quit"));

    A_open->setText(tr("open"));
    A_quit->setText(tr("quit"));

    Bottom_menu->addAction(A_open);
    Bottom_menu->addSeparator();
    Bottom_menu->addAction(A_quit);

    Bottom_menu->setFixedSize(120,60);

    logon_tray = new QSystemTrayIcon(this);
    logon_tray->setContextMenu(Bottom_menu);
    logon_tray->setIcon(QIcon(":/logo/logo"));
    logon_tray->setToolTip(tr("Smart L"));
    connect(A_quit, SIGNAL(triggered()), qApp,SLOT(quit()));
    connect(A_open,SIGNAL(triggered()),this,SLOT(showNormal()));
    connect(logon_tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
            SLOT(IcoIsActived_trigger(QSystemTrayIcon::ActivationReason)));
    logon_tray->show();

}
void Login::IcoIsActived_trigger(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        this->showNormal();
        break;
    case QSystemTrayIcon::DoubleClick:
        this->showNormal();
        break;
    default:
        break;
    }
}
void Login::Qrcode_Btn_clicked()
{
 //   Qrcode_Btn->setIcon(QIcon(""));
    Visable_qrocde = !Visable_qrocde;
    switch (Visable_qrocde)
    {
        case true:
            Login_Btn->setText(tr("Return Login"));
            Qrcode_Btn->setIcon(QIcon(""));
            main_layout->setCurrentWidget(page_2_qrcode);
            break;
        case false:
            Login_Btn->setText(tr("Login"));
            Qrcode_Btn->setIcon(QIcon(":/Mainmenu/qrcode"));
            main_layout->setCurrentWidget(page_1_login);
            break;
    }
}
void Login::Qrcode_Layout_init()
{
    Head_label = new QLabel();
    qcode_label = new QLabel();
    Head_label->setFixedHeight(30);
    Head_label->setAlignment(Qt::AlignCenter);
    Head_label->setText(tr("using wechar scanning safe login.") + "<a href = http://blog.csdn.net/ongoingcre>" + tr("missing?") + "</a>");
//    qcode_label->setFixedSize(400,125);
    qcode_label->setPixmap(QPixmap(":/qcode/qrcode"));
//    qcode_label->setStyleSheet("background-color:red");
//    Head_label->setStyleSheet("background-color:red");
    Head_label->setAlignment(Qt::AlignCenter);
    qcode_Layout = new QHBoxLayout();
    qcode_Layout->addStretch(0);
    qcode_Layout->addWidget(qcode_label);
    qcode_Layout->addStretch(0);
    qcode_Layout->setMargin(0);
    qcode_Layout->setSpacing(0);
   // qcode_Layout->setContentsMargins(85,0,85,15);

    //free(layout);
    /*main layout*/
    layout_page_2 = new QVBoxLayout();
    layout_page_2->addWidget(Head_label);
    layout_page_2->addLayout(qcode_Layout);
    //layout->addStretch(0);
    layout_page_2->setMargin(0);
    layout_page_2->setSpacing(0);
    layout_page_2->setContentsMargins(0,25,0,0);
    page_2_qrcode = new QWidget(this);
    page_2_qrcode->setStyleSheet("background-color:white");
    page_2_qrcode->setLayout(layout_page_2);
    connect(Head_label,SIGNAL(linkActivated(QString)),this,SLOT(OpenUrl(QString )));

}
void Login::translation()
{
    Min_Btn->setToolTip(tr("min"));
    Close_Btn->setToolTip(tr("close"));
    Qrcode_Btn->setToolTip(tr("2 cord"));
    Regiser_account->setToolTip(tr("Register"));
    User_Name->setToolTip(tr("user:admin passwd:88888888"));

}
void Login::OpenUrl(QString url)
{
    QDesktopServices::openUrl(QUrl(url));
}
void Login::Login_response()
{
    if (Visable_qrocde){
        Qrcode_Btn_clicked();
        return;
    }
    bool Ret_Read;
    Ret_Read = Util::ReadInit(QString(":/config/default"),QString("default"),passwd_str);
    if(Ret_Read)
    {
        if (passwd_str.isEmpty()){
            return;
        }
        if(QString::compare(passwd_str, Passwd->text(), Qt::CaseInsensitive) == 0 &&
           QString::compare("admin", User_Name->text(), Qt::CaseInsensitive) == 0) {
            smart_l_client = new Main_Widget();
            smart_l_client->show();
            logon_tray->hide();
            this->close();
        }
    }
    else {
         qDebug() <<"Not Open ini file";
         return;
    }
}
