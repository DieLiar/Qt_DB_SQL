#include "hud.h"
#include "ui_hud.h"
#include "addwindiw.h"
#include <QMessageBox>

#include <QDialog>

#include <QWidget>
#include <QtWidgets>
#include <QTreeWidget>

#include <QtSql>
#include <QSqlQuery>

#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

HUD::HUD(QWidget *parent) : QMainWindow(parent), ui(new Ui::HUD)
{
    ui->setupUi(this);

// ---------- SQL DataBase----------
    QSqlDatabase DBItem;
    DBItem = QSqlDatabase::addDatabase("QSQLITE");
    DBItem.setDatabaseName("C:\\Users\\pigin\\Documents\\qt\\Item_DataBase.db3");
    HUD:: Table_I = new QSqlQuery;
    DBItem.open();
    Table_I->exec("CREATE TABLE Item (id  INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT    NOT NULL);");
// ---------- Tree Widget ----------
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(2);
    QStringList DB;
    DB << tr("ID") << tr("Name");
    ui->treeWidget->setHeaderLabels(DB);
//---------- set current item/column NULL ----------
    currentItem = NULL;
    currentColumn = 0;
}

HUD::~HUD()
{
    delete ui;
    delete HUD:: Table_I;
}

void HUD::ClearTree(QTreeWidget * tree)
{
    tree->clear();
}

//=============== COUNT  ===============
int HUD::treeCount(QTreeWidget *tree, QTreeWidgetItem *parent = 0)
{
    tree->expandAll();
    int count = 0;
    if (parent == 0) {
        int topCount = tree->topLevelItemCount();
        for (int i = 0; i < topCount; i++) {
            QTreeWidgetItem *item = tree->topLevelItem(i);
            if (item->isExpanded()) {
                count += treeCount(tree, item);
            }
        }
        count += topCount;
    }

    else {
        int childCount = parent->childCount();
        for (int i = 0; i < childCount; i++) {
            QTreeWidgetItem *item = parent->child(i);
            if (item->isExpanded()) {
                count += treeCount(tree, item);
            }
        }
    count += childCount;
    }

    return count;
}
//=============== PRINT IN "console" ===============
void HUD:: print(QString str)
{
    HUD::ui->textEdit->insertPlainText(str + "\n");
}
//=============== FILL TREE FROM DataBase ===============
void HUD::FILL()
{
    Table_I->exec("SELECT * FROM Item");
    while (Table_I->next()) {
      QTreeWidgetItem *db_root = new QTreeWidgetItem();
      QString id = Table_I->value(0).toString();
      QString name = Table_I->value(1).toString();
      db_root->setText(0, id);
      db_root->setText(1, name);
      ui->treeWidget->addTopLevelItem(db_root);
     }
}
//=============== DELETE ITEM ===============
void HUD::DeleteItem (QTreeWidgetItem *currentItem)
{
    QTreeWidgetItem *parent = currentItem->parent();

    int index;

    if (parent) {
        index = parent->indexOfChild(ui->treeWidget->currentItem());
        delete parent->takeChild(index);
    }
    else {
        index = ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem());
        delete ui->treeWidget->takeTopLevelItem(index);
    }
}

void HUD::DBDeleteItem (QTreeWidgetItem *currentItem)
{
    QTreeWidgetItem *parent = currentItem->parent();

    QString str;
    int index;

    if (parent) {

        str = "DELETE FROM Item WHERE id = '" + currentItem->text(0) + "';";
        print(str);
        Table_I->exec(str);
        index = parent->indexOfChild(ui->treeWidget->currentItem());
        delete parent->takeChild(index);
    }
    else {
        str = "DELETE FROM Item WHERE id = '" + currentItem->text(0) + "';";
        print(str);
        Table_I->exec(str);
        index = ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem());
        delete ui->treeWidget->takeTopLevelItem(index); 
    }
}

//=============== check for valid line ===============
void HUD::check(QString name)
{
    if(name =="")
        throw("Line for edit is EMPTY");
    if(name == "0")
        throw("0 on Edit Line");
}
//=============== ADD ITEM ===============
void HUD::AddItem(int id, QString name)
{
    try{
        check(name);
        QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->treeWidget, ui->treeWidget->currentItem());
        newItem->setText (0, QString::number(id));
        newItem->setText (1, name);
        newItem->setExpanded(true);

        QString str = "INSERT INTO Item(id, Name) VALUES("+ QString::number(id) + ", '" + name + "');";
        print(str);
        Table_I->exec(str);


    }
    catch(const char * msg) {QMessageBox :: critical (this, "info", msg);}
}
//=============== ISERT ITEM ===============
void HUD::InsertItem (QTreeWidgetItem *parent, int id, QString name)
{
    try{
        check(name);
        if (parent->isExpanded()==false)
            parent->setExpanded(true);
        QTreeWidgetItem *newItem = new QTreeWidgetItem(parent, ui->treeWidget->currentItem());
        newItem->setText (0, QString::number(id));
        newItem->setText (1, name);
        newItem->setExpanded(true);

        QString str = "INSERT INTO Item(id, Name) VALUES("+ QString::number(id) + ", '" + name + "');";
        print(str);
        Table_I->exec(str);
    }
 catch(const char * msg) {QMessageBox :: critical (this, "info", msg);}
}
//=============== EDIT ITEM ===============
void HUD::EditItem(QTreeWidgetItem *currentItem, QString editText)
{
    Table_I->exec("SELECT * FROM Item");
    try{
        check(editText);
        QString str;

        str = "UPDATE Item SET Name = '" + editText + "' WHERE Name = '" + currentItem->text(1) + "';";

        HUD::ui->textEdit->insertPlainText(" | " + str + " | " + "\n");

        Table_I->exec(str);

        currentItem->setText(1, editText);
        QMessageBox :: information(this, "info", "ReName is complete");       
    }
    catch(const char * msg) {QMessageBox :: critical (this, "info", msg);}
}
//=============== Click ===============
void HUD::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
 currentItem = item;
 currentColumn = column;
}
//=============== INSERT in UI ===============
void HUD::on_input_clicked()
{
     if (currentItem) {
      QString NameAdd = ui->lineEdit->text();
      int IdAdd = treeCount (ui->treeWidget) + 1;
      InsertItem  (currentItem, IdAdd, NameAdd);
      }
     else {
      QString NameAdd = ui->lineEdit->text();
      int IdAdd = treeCount (ui->treeWidget) + 1;
      AddItem(IdAdd, NameAdd);
     }
     currentItem = NULL;
}
//=============== REMOVE in UI ===============
void HUD::on_remove_clicked()
{
    if (currentItem) {
      DeleteItem (currentItem);
      currentItem = NULL;
    }
}

void HUD::on_Delete_clicked()
{
    if (currentItem){
      DBDeleteItem (currentItem);
      currentItem = NULL;
    }

}
//=============== EDIT in UI ===============
void HUD::on_EditID_clicked()
{
    if (currentItem){
    QString editID = ui->EditLineID->text();
    EditItem(currentItem, editID);
    }
}
//=============== FILL DEFAULT TREE ===============

void HUD::on_actionFill_from_DataBase_triggered()
{
    FILL();
}
//=============== New Window ===============
void HUD::on_actionAdd_triggered()
{
    AddWindiw AW;
    AW.setModal(true);
    AW.exec();
    ui->statusbar->showMessage("opening...");
}

//=============== Info Button ===============
void HUD::on_info_clicked()
{
    if(currentItem){
        print("num of ID = " + QString::number(treeCount(ui->treeWidget)));
        QMessageBox :: information(this, "info about", "ID - " + currentItem->text(0) + " | Name - " + currentItem->text(1));
    }
}
void HUD::on_actionClear_Tree_triggered()
{
    ClearTree(ui->treeWidget);
}
void HUD::on_actionClear_DataBase_triggered()
{
    QString str = "DELETE FROM Item";
        print(str);
        Table_I->exec(str);
}
void HUD::on_actionDrop_Table_triggered()
{
    QString str = "DROP TABLE IF EXISTS Item";
    print(str);
    Table_I->exec(str);
}


void HUD::on_Refresh_clicked()
{
    ClearTree(ui->treeWidget);
    FILL();
}

