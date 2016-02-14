#include "device_descirtion.h"
#include <QHeaderView>
#include <QScrollBar>
#include <QDebug>

Device_Descirtion::Device_Descirtion(QWidget *parent) :
    QTableView(parent)
{
    Init_View();
    model = new Devices_TableModel();
    this->setModel(model);
    Init_Header();
    model->setModalDatas(&dev_data_info_list);

    // model->setModalDatas(&dev_data_info_list);
    /*
    progressbar_delegate = new ProgressBarDelegate();
    this->setItemDelegate(progressbar_delegate);

    connect(model, &TableModel::updateCount, this, &TableView::updateCount);
    */
}
void Device_Descirtion::Init_View()
{
    //this->setColumnWidth(0,15);
    //this->setSelectionBehavior(QAbstractItemView::SelectRows);
    //this->horizontalHeader()->resizeSection(0,25); //设置表头第一列的宽度为25
    //this->horizontalHeader()->setDefaultSectionSize(155);
    this->horizontalHeader()->setSectionsClickable(false);  //设置表头不可点击
    this->horizontalHeader()->setStretchLastSection(true);  //设置充满宽度
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->verticalHeader()->setVisible(false); //隐藏垂直列表头
    this->setFrameShape(QFrame::NoFrame); //设置无边框
    this->setShowGrid(false);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选（Ctrl、Shift、  Ctrl+A都可以
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
   // this->horizontalHeader()->setFixedHeight(25); //设置表头的高度
    this->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
    this->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

    //设置水平、垂直滚动条样式
    this->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}" \
    "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}" \
    "QScrollBar::handle:hover{background:gray;}" \
    "QScrollBar::sub-line{background:transparent;}" \
    "QScrollBar::add-line{background:transparent;}");
    this->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}" \
    "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}" \
    "QScrollBar::handle:hover{background:gray;}" \
    "QScrollBar::sub-line{background:transparent;}" \
    "QScrollBar::add-line{background:transparent;}");
/*
    int rows = this->rowCount();
    qDebug() << "row---" << rows;
     for (int i = 0; i < rows; i++)
     {
           QTableWidgetItem *item = new QTableWidgetItem();
           item->setText("");
           item->setTextAlignment(Qt::AlignHCenter || Qt::AlignCenter);
           this->setItem(i, 0, item);
           this->item(i,0)->setCheckState( Qt::Unchecked);
     }

        QTableWidgetItem *item1 = new QTableWidgetItem();
        this->setItem(0,1,item1);
        this->item(0,1)->setCheckState( Qt::Unchecked);
*/
}
void Device_Descirtion::addRow_Dev(QStringList rowList)
{
    dev_data_info_list.append(rowList);
    model->refrushModel();
}

void Device_Descirtion::Init_Header()
{
    QStringList header;
    header << tr("Vendor Name") << tr("Device Name") << tr("Serail Number") << tr("State") << tr("Process");
    model->setHorizontalHeaderList(header);

}
int Device_Descirtion::Row_Count()
{
    return model->rowCount(QModelIndex());
}
