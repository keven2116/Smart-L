#ifndef DEVICES_TABLEMODEL_H
#define DEVICES_TABLEMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QMap>

class Devices_TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit Devices_TableModel(QObject *parent = 0);

    void setHorizontalHeaderList(QStringList horizontalHeaderList); //设置横向表头内容
    void setVerticalHeaderList(QStringList verticalHeaderList); //设置纵向表头内容
    int rowCount(const QModelIndex &parent = QModelIndex()) const; //返回行数
    int columnCount(const QModelIndex &parent = QModelIndex()) const; //返回列数
    QVariant data(const QModelIndex &index, int role) const; //返回一个项的任意角色的值
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;  //返回表头名称,(行号或列号，水平或垂直，角色)
    Qt::ItemFlags flags(const QModelIndex &index) const; //返回对一个项相关的操作的标识符（例如，是否可以编辑或者是否已选中等）
    void refrushModel(); //强制刷新
    bool setData(const QModelIndex &index, const QVariant &value, int role); //编辑一个项
    //bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex()); //插入一行
    //bool insertColumns(int column, int count, const QModelIndex & parent = QModelIndex()); //插入一列
    void setModalDatas(QList< QStringList > *rowlist); //多行设置

signals:
    void Update_Devinfo(int count);
private:
    QStringList stringList;
    QStringList horizontal_header_list; //全局Header_List
    QStringList vertical_header_list;  //全局header list
    QList< QStringList > *arr_row_list;
private:

public slots:

};

#endif // DEVICES_TABLEMODEL_H
