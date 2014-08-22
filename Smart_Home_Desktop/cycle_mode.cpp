#include "cycle_mode.h"

Cycle_Mode::Cycle_Mode(QWidget *parent) :
    QMenu(parent)
{
    Create_Act_Cycle();
    translateActions();
}
Cycle_Mode::~Cycle_Mode()
{

}
void Cycle_Mode::Create_Act_Cycle()
{
    //Init Act
    Act_One_cycle = new QAction(this);
    Act_list_cycle = new QAction(this);
    Act_list_sequence = new QAction(this);
    Act_list_random = new QAction(this);
    //Set Ico ...

    //Add Act
    this->addAction(Act_One_cycle);
    this->addAction(Act_list_cycle);
    this->addAction(Act_list_sequence);
    this->addAction(Act_list_random);

    //connect
    QObject::connect(Act_One_cycle,SIGNAL(triggered()),this,SIGNAL(Sig_One_Cycle()));
    QObject::connect(Act_list_cycle,SIGNAL(triggered()),this,SIGNAL(Sig_List_Cycle()));
    QObject::connect(Act_list_sequence,SIGNAL(triggered()),this,SIGNAL(Sig_List_Seq_Cycle()));
    QObject::connect(Act_list_random,SIGNAL(triggered()),this,SIGNAL(Sig_List_Random_Cycle()));

    this->setStyleSheet("background-color:white;color:gray;");
}
void Cycle_Mode::translateActions()
{
    Act_One_cycle->setText(tr("Signal cycle"));
    Act_list_cycle->setText(tr("List Cycle"));
    Act_list_sequence->setText(tr("Sequence Cycle"));
    Act_list_random->setText(tr("Random Cycle"));
}
