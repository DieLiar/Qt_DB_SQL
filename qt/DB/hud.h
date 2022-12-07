#ifndef HUD_H
#define HUD_H

#include <QMainWindow>
#include <QDialog>
#include <QTreeWidget>

#include <QWidget>
#include <QtWidgets>

#include <QtSql>


QT_BEGIN_NAMESPACE
namespace Ui { class HUD; }
QT_END_NAMESPACE

class HUD : public QMainWindow
{
    Q_OBJECT

public:
    HUD(QWidget *parent = nullptr);
    ~HUD();

private slots:

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_input_clicked();

    void on_info_clicked();

    void on_actionFill_from_DataBase_triggered();

    void on_actionClear_Tree_triggered();

    void on_actionClear_DataBase_triggered();

    void on_actionDrop_Table_triggered();

    void on_Delete_clicked();

    void on_Refresh_clicked();

    void on_actionCreate_2_triggered();

    void on_actionOpen_triggered();

    void on_actionClose_triggered();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::HUD *ui;

    QSqlQuery *Table_I;
    QSqlDatabase Item;

    int count;
    QTreeWidgetItem *currentItem; //текущий элемент, запоминается при клике в QTreeWidget
    int currentColumn; //номер столбца

    void check(QString name); //Проверка поля editline
    void AddItem(int id, QString name); //Добавление элемента в QTreeWidget
    void InsertItem (QTreeWidgetItem *parent, int id, QString name); //Вставка элемента в QTreeWidget
    void EditItem(QTreeWidgetItem *currentItem, QString editText); //Изменение элемента в QTreeWidget
    void DeleteItem (QTreeWidgetItem *currentItem); //удаление элемента из QTreeWidget
    void DBDeleteItem (QTreeWidgetItem *currentItem);
    int treeCount(QTreeWidget *, QTreeWidgetItem *);
    void ClearTree(QTreeWidget *);

    void connect(QString str);
    void FILL();
    void print(QString str);
    void check();
};
#endif // HUD_H
