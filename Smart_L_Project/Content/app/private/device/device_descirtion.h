#ifndef DEVICE_DESCIRTION_H
#define DEVICE_DESCIRTION_H

#include <QTableView>
#include <QList>
#include <QStringList>
#include "devices_tablemodel.h"

/*视图*/
class Device_Descirtion : public QTableView
{
    Q_OBJECT
public:
    explicit Device_Descirtion(QWidget *parent = 0);
    void Init_View();
    void addRow_Dev(QStringList rowList);
    int Row_Count();

signals:
   // void Update_Devinfo(int row);
  //  void Stop_Update_Devinfo();
public slots:
    /*void Remove_Device();
    void Remove_All_Device();
    void Get_Changvalue();*/
private:
    void Init_Header();
    /*模型*/
    Devices_TableModel *model;
    QList <QStringList > dev_data_info_list;
    /*委托*/
};

#endif // DEVICE_DESCIRTION_H
