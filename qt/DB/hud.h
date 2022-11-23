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

    void on_actionAdd_triggered();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_input_clicked();

    void on_remove_clicked();

    void on_TEST_clicked();

    void on_EditID_clicked();

    void on_info_clicked();

private:
    Ui::HUD *ui;

    int count;
    QTreeWidgetItem *currentItem; //текущий элемент, запоминается при клике в QTreeWidget
    int currentColumn; //номер столбца

    void check(QString id, QString name); //Проверка 2х полей editline
    void check(QString name); //Проверка поля editline
    void AddItem(QString id, QString name); //Добавление элемента в QTreeWidget
    void InsertItem (QTreeWidgetItem *parent, QString id, QString name); //Вставка элемента в QTreeWidget
    void EditItem(QTreeWidgetItem *currentItem, QString editText); //Изменение элемента в QTreeWidget
    void DeleteItem (QTreeWidgetItem *currentItem); //удаление элемента из QTreeWidget

    void FILL(); // Дефолтное заполнение для демонстрации
};
#endif // HUD_H
