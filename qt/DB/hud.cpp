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

HUD::HUD(QWidget *parent) : QMainWindow(parent), ui(new Ui::HUD)
{
    ui->setupUi(this);

// ---------- SQL DataBase----------
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("db_name.sqlite");

    if (!sdb.open())
        QMessageBox :: critical (this, "info", "Error open");

    QSqlQuery a_query;

    // DDL query
    QString str = "CREATE TABLE my_table ("
               "number integer PRIMARY KEY NOT NULL, "
               "address VARCHAR(255), "
               "age integer"
               ");";
       bool b = a_query.exec(str);
       if (!b) {
           QMessageBox :: critical (this, "info", "не удается создать таблицу");
       }

          QString str_insert = "INSERT INTO my_table(number, address, age) "
                  "VALUES (%1, '%2', %3);";
          str = str_insert.arg("14")
                  .arg("hello world str.")
                  .arg("37");
          b = a_query.exec(str);

       if (!b) {
           QMessageBox :: critical (this, "info", "данные не вставляются");
       }

       if (!a_query.exec("SELECT * FROM my_table")) {
           QMessageBox :: critical (this, "info", "селект не получается");

       }
       QSqlRecord rec = a_query.record();
       int number = 0, age = 0;
       QString address = "";

       while (a_query.next()) {
           number = a_query.value(rec.indexOf("number")).toInt();
           age = a_query.value(rec.indexOf("age")).toInt();
           address = a_query.value(rec.indexOf("address")).toString();

           qDebug() << "number is " << number
                     << ". age is " << age;
       }

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
}

//=============== FILL TREE ===============
void HUD::FILL()
{
//---------- Default parent & child ----------
        QTreeWidgetItem *db_root = new QTreeWidgetItem();
        db_root->setText(0, "01");
        db_root->setText(1, "root");

        QTreeWidgetItem *db_ch3 = new QTreeWidgetItem();
        db_ch3->setText(0, "03");
        db_ch3->setText(1, "child_3");
        db_root->addChild(db_ch3);
        QTreeWidgetItem *db_ch2 = new QTreeWidgetItem();
        db_ch2->setText(0, "02");
        db_ch2->setText(1, "child_2");
        db_root->addChild(db_ch2);
        QTreeWidgetItem *db_ch1 = new QTreeWidgetItem();
        db_ch1->setText(0, "01");
        db_ch1->setText(1, "child_1");
        db_root->addChild(db_ch1);

        ui->treeWidget->addTopLevelItem(db_root);

    //------------------
        QTreeWidgetItem *db_root2 = new QTreeWidgetItem();
        db_root2->setText(0, "01");
        db_root2->setText(1, "root_02");

        QTreeWidgetItem *db_ch4 = new QTreeWidgetItem();
        db_ch4->setText(0, "03");
        db_ch4->setText(1, "child_4");
        db_root2->addChild(db_ch4);
        QTreeWidgetItem *db_ch5 = new QTreeWidgetItem();
        db_ch5->setText(0, "02");
        db_ch5->setText(1, "child_5");
        db_root2->addChild(db_ch5);
        QTreeWidgetItem *db_ch6 = new QTreeWidgetItem();
        db_ch6->setText(0, "01");
        db_ch6->setText(1, "child_6");
        db_root2->addChild(db_ch6);

        ui->treeWidget->addTopLevelItem(db_root2);
     //------------------
        QTreeWidgetItem *db_ch_root1 = new QTreeWidgetItem();
        db_ch_root1->setText(0, "02");
        db_ch_root1->setText(1, "child_root_1");
        db_ch5->addChild(db_ch_root1);
        QTreeWidgetItem *db_ch_root2 = new QTreeWidgetItem();
        db_ch_root2->setText(0, "02");
        db_ch_root2->setText(1, "child_root_2");
        db_ch5->addChild(db_ch_root2);
        QTreeWidgetItem *db_ch_root3 = new QTreeWidgetItem();
        db_ch_root3->setText(0, "02");
        db_ch_root3->setText(1, "child_root_3");
        db_ch5->addChild(db_ch_root3);

    ui->treeWidget->addTopLevelItem(db_ch5);
}
//=============== DELETE ITEM ===============
void HUD::DeleteItem (QTreeWidgetItem *currentItem) {
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
//=============== check for valid line ===============
void HUD::check(QString id, QString name)
{
    if(id=="" || name =="")
        throw("Line for Name and/or ID is EMPTY");
    bool ok;
    if(id.toInt(&ok,  10) == false)
        throw("ID isn't number");

}

void HUD::check(QString name)
{
    if(name =="")
        throw("Line for edit is EMPTY");
    if(name == "0")
        throw("0 on Edit Line");
}
//=============== ADD ITEM ===============
void HUD::AddItem(QString id, QString name)
{
    try{
        check(id, name);
        QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->treeWidget, ui->treeWidget->currentItem());
        newItem->setText (0, id);
        newItem->setText (1, name);
        newItem->setExpanded(true);
        QMessageBox :: information(this, "info", " name ADD is complete");}
    catch(const char * msg) {QMessageBox :: critical (this, "info", msg);}
}
//=============== ISERT ITEM ===============
void HUD::InsertItem (QTreeWidgetItem *parent, QString id, QString name)
{
 try{
    check(id, name);

    if (parent->isExpanded()==false)
        parent->setExpanded(true);
    QTreeWidgetItem *newItem = new QTreeWidgetItem(parent, ui->treeWidget->currentItem());
    newItem->setText (0, id);
    newItem->setText (1, name);
    newItem->setExpanded(true);
    QMessageBox :: information(this, "info", "  name INSERT is complete");}
 catch(const char * msg) {QMessageBox :: critical (this, "info", msg);}
}
//=============== EDIT ITEM ===============
void HUD::EditItem(QTreeWidgetItem *currentItem, QString editText)
{
    bool ok;
    try{
        if(editText.toInt(&ok,  10)){
            currentItem->setText(0, editText);
            QMessageBox :: information(this, "info", "ReName is complete");

        }
        else
        {
            check(editText);
            currentItem->setText(1, editText);
            QMessageBox :: information(this, "info", "ReName is complete");
        }
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
      QString IdAdd = ui->lineEdit_2->text();
      InsertItem  (currentItem, IdAdd, NameAdd);
      }
     else {
      QString NameAdd = ui->lineEdit->text();
      QString IdAdd = ui->lineEdit_2->text();
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
//=============== EDIT in UI ===============
void HUD::on_EditID_clicked()
{
    if (currentItem){
    QString editID = ui->EditLineID->text();
    EditItem(currentItem, editID);
    }
}
//=============== FILL DEFAULT TREE ===============
void HUD::on_TEST_clicked()
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
    if(currentItem)
        QMessageBox :: information(this, "info about", "ID - " + currentItem->text(0) + " | Name - " + currentItem->text(1));
}

