#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include "common.h"
#include "../../public/push_btn.h"
#include "drop_shadow_widget.h"

class AboutUsDialog : public DropShadowWidget
{
	Q_OBJECT

public:
	explicit AboutUsDialog(QWidget *parent = 0);
	~AboutUsDialog();
	void translateLanguage();
protected:
	void paintEvent(QPaintEvent *event);
private:
	void init();
    Push_Btn *Close_Btn;
    QLabel *title_logo,*Title_label,*logo_label,*context_label,*Version__Label,*copy_left;
    QHBoxLayout *top_layout;
    QVBoxLayout *layout;

};

#endif  //ABOUTUS_H
