#include "devices_tablemodel.h"
QMap<int, Qt::CheckState>  check_state_map;
Devices_TableModel::Devices_TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    //check_state_map.insert(1,Qt::CheckState);
    //check_state_map.insert(0,Qt:);
    //check_state_map.clear();
}
/*设置横向表头内容*/
void Devices_TableModel::setHorizontalHeaderList(QStringList horizontalHeaderList)
{
    horizontal_header_list = horizontalHeaderList;\
}
/*设置纵向表头内容*/
void Devices_TableModel::setVerticalHeaderList(QStringList verticalHeaderList)
{
    vertical_header_list = verticalHeaderList;
}
/*返回行数*/
int Devices_TableModel::rowCount(const QModelIndex &parent) const
{
    if(vertical_header_list.size() > 0)
        return vertical_header_list.size();

    if(NULL == arr_row_list)
        return 0;
    else
        return arr_row_list->size();

}
/*返回列数*/
int Devices_TableModel::columnCount(const QModelIndex &parent) const
{

    if(horizontal_header_list.size() > 0)
        return horizontal_header_list.size();
    if(NULL == arr_row_list)
        return 0;
    else if(arr_row_list->size() < 1)
        return 0;
    else
        return arr_row_list->at(0).size();
}
/*返回一个项的任意角色的值，这个项被指定为QModelIndex*/
QVariant Devices_TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(NULL == arr_row_list)
        return QVariant();

    if(arr_row_list->size() < 1)
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignCenter | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        if(index.row() >= arr_row_list->size())
            return QVariant();
        if(index.column() >= arr_row_list->at(0).size())
            return QVariant();
        return arr_row_list->at(index.row()).at(index.column());
    }
    else if (role == Qt::CheckStateRole)
    {
        if(index.column() == 0)
        {
            if (check_state_map.contains(index.row()))
                return check_state_map[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked;
            return Qt::Unchecked;
        }
    }
/*
    switch(role)
    {
        case Qt::TextAlignmentRole:
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        break;
    case Qt::DisplayRole:
            return arr_row_list->at(index.row()).at(index.column());
        break;
    case Qt::CheckStateRole:
        if(index.column() == 0)
        {
            if (check_state_map.contains(index.row()))
                return check_state_map[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked;
            return Qt::Unchecked;
        }
        break;
    default:
        return QVariant();
        break;
    }
*/
    return QVariant();
}
/*返回表头名称,(行号或列号，水平或垂直，角色)*/
QVariant Devices_TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::CheckStateRole)
    {
           return Qt::Checked;
    }
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal) // shuiping biaotou
        {
            if(horizontal_header_list.size() > section)
                return horizontal_header_list[section];
            else
                return QVariant();
        }
        else
        {
            if(vertical_header_list.size() > section)
                return vertical_header_list[section]; // chuizhi biaotou
            else
                return QVariant();
        }
    }

    return QVariant();
}
/*/返回对一个项相关的操作的标识符（例如，是否可以编辑或者是否已选中等）*/
Qt::ItemFlags Devices_TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    if (index.column() == 0)
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;

    Qt::ItemFlags flag = QAbstractItemModel::flags(index);

    return flag;
}
/*全局内容*/
void Devices_TableModel::setModalDatas(QList< QStringList > *rowlist)
{
    arr_row_list = rowlist;
}
/*强制刷新模型*/
void Devices_TableModel::refrushModel()
{
    beginResetModel();
    endResetModel();

    emit Update_Devinfo(this->rowCount(QModelIndex()));
}
/*编辑一个项 */
bool Devices_TableModel::setData( const QModelIndex &index, const QVariant &value, int role )
{
        if(!index.isValid())
                return false;

        if (role == Qt::CheckStateRole && index.column() == 0)
        {
                check_state_map[index.row()] = (value == Qt::Checked ? Qt::Checked : Qt::Unchecked);
        }

        return true;
}
