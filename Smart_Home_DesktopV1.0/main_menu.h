#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMenu>

class Main_Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Main_Menu(QWidget *parent = 0);
    ~Main_Menu();
    void translateActions();

signals:
    void Sig_uniq();
    void Sig_sort();
    void Sig_download();

private:
    void Create_Actions_keven();
private:
    QAction *Action_uniq;   //列表去重
    QAction *Action_sort; //排序
    QAction *Action_download_list; //列表下载
    QAction *Action_rename_list; //列表重命名
    QAction *Action_delete_list; //列表删除
    QAction *Action_restore_listr; //列表重载
    QAction *Action_delete_choice; //删除选中
    QAction *Action_delete_error;//删除错误
    QAction *Action_clear_list;//清除列表
private slots:
//    void _360_Html();
//    void _Protect_360_Books();
//    void _Why_Free();
};

#endif // MAIN_MENU_H
