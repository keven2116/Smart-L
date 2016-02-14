#include "about_us.h" 
#include "../../public/util.h"

AboutUsDialog::AboutUsDialog(QWidget *parent)
	: DropShadowWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(260,300);
    init();
}

void AboutUsDialog::init()
{
    Close_Btn = new Push_Btn();
    Close_Btn->Load_Pixmap_keven(":/SysButton/close");
    title_logo = new QLabel();
    title_logo->setPixmap(QPixmap(":/logo/logo"));


    Title_label = new QLabel();
    Title_label->setFixedSize(260,35);
    //Title_label->setStyleSheet("background-color: rgb(106, 106, 106); color:white;");

    top_layout = new QHBoxLayout();
    top_layout->addWidget(title_logo);
    top_layout->addWidget(Title_label);
    top_layout->addWidget(Close_Btn);
    top_layout->setMargin(0);
    top_layout->setSpacing(0);

    logo_label = new QLabel();
    copy_left = new QLabel();
    context_label = new QLabel();
    Version__Label = new QLabel();

 //   logo_label->setPixmap(QPixmap(":/logo/logo"));
    context_label->setWordWrap(true);
    Version__Label->setText(tr("Smart L 1.0"));
    Version__Label->setFont(QFont("楷体",16));
    Version__Label->setAlignment(Qt::AlignCenter);
    context_label->setText(tr("Link:") + "<a href = http://blog.csdn.net/ongoingcre>" + tr("http://blog.csdn.net/ongoingcre") + "</a>");
    context_label->setFont(QFont("楷体",10));
    copy_left->setStyleSheet("background-color: rgb(106, 106, 106);color:white");
    copy_left->setAlignment(Qt::AlignCenter);
    copy_left->setText(tr("Copyleft©2016 Ongoingcre.GPL/BSD"));
    copy_left->setFont(QFont("楷体",10));

    layout = new QVBoxLayout();
    layout->addLayout(top_layout);
    layout->addWidget(logo_label);
    layout->addStretch();
    layout->addWidget(Version__Label);
    layout->addStretch();
    layout->addWidget(context_label);
    layout->addSpacing(15);
    layout->addWidget(copy_left);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,10);
    this->setLayout(layout);

    connect(Close_Btn,SIGNAL(clicked()),this,SLOT(close()));
}
void AboutUsDialog::translateLanguage()
{

}

AboutUsDialog::~AboutUsDialog()
{

}

void AboutUsDialog::paintEvent(QPaintEvent *event)
{
    DropShadowWidget::paintEvent(event);
	QString skin_name = Util::getSkinName();
    int height = 35;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    //qDebug();
    painter.drawPixmap(QRect(0, 0, this->width(), this->height()), QPixmap(skin_name));
    painter.drawRect(QRect(0, height, this->width(), this->height()));

}
