#include "widget.h"
#include "treemodel.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    TreeModel *model = new TreeModel();
    ui->treeView->setModel(model);

 //Осталось соединить сигналы со слотами:

 connect(ui->treeView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),
         this, SLOT(updateActions(const QItemSelection&,const QItemSelection&)));

 connect(ui->insertRowAction,SIGNAL(clicked()),this,SLOT(insertRow()));
 connect(ui->removeRowAction,SIGNAL(clicked()),this,SLOT(removeRow()));
 connect(ui->insertChildAction,SIGNAL(clicked()),this,SLOT(insertChild()));
 connect(ui->Remove_button,SIGNAL(clicked()),this,SLOT(clear()));
 connect(ui->Fill,SIGNAL(clicked()),this,SLOT(Fill()));
 connect(ui->Refill, SIGNAL(clicked()), this, SLOT(refill()));
 connect(ui->UpdateDB, SIGNAL(clicked()), this, SLOT(UpdateDatabase()));



 //и обновить состояние кнопок:
 updateActions();
}

void Widget::check(QString IDLine, QString NameLine)
{
    int countID = 0;
    countID = Database.countID();

    QStringList ID = Database.take_id();

    if(IDLine =="" && NameLine == "")
        throw(0);
    if(IDLine == "0")
        throw(0);
    if(IDLine == "" && NameLine != "")
        throw(1);
    if(IDLine != "" && NameLine == ""){
        for(int count = 0; count < countID; count++){
            if(IDLine == ID.at(count)){
                throw(0);
            }
        }
        throw(2);
    }
    if(IDLine!="" && NameLine != ""){
        for(int count = 0; count < countID; count++){
            if(IDLine == ID.at(count)){
                throw(1);
            }
        }
    }

}

void Widget::insertTree(bool flag, QModelIndex index, QAbstractItemModel *model, QString IDLine, QString NameLine)
{
    bool ok;
    if(flag){
        Database.AddItem(IDLine.toInt(&ok, 10), NameLine);
        QModelIndex child;
        child = model->index(0, 0, index);
        model->setData(child, QVariant(IDLine), Qt::EditRole);
        child = model->index(0, 1, index);
        model->setData(child, QVariant(NameLine), Qt::EditRole);
    } else {
        Database.AddItem(IDLine.toInt(&ok, 10), NameLine);
        QModelIndex child;
        child= model->index(index.row()+1, 0, index.parent());
        model->setData(child, QVariant(IDLine), Qt::EditRole);
        child = model->index(index.row()+1, 1, index.parent());
        model->setData(child, QVariant(NameLine), Qt::EditRole);
    }
}

void Widget::insertChild()
{
    QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->treeView->model();

    if (model->columnCount(index) == 0){
        if (!model->insertColumn(0, index))
            return;
    }
    if (!model->insertRow(0, index))
        return;

    QString NameLine = ui->NameLine->text();
    QString IDLine = ui->IDLine->text();

    int id = 0;
    int countID = 0;
    countID = Database.countID();

    if(countID !=0){
    QStringList ID(Database.take_id());

    bool ok;
    id = ID.at(countID-1).toInt(&ok, 10)+1;
    }
    else
        id = 1;
    try{
        check(IDLine, NameLine);
        insertTree(true, index, model, IDLine, NameLine);
    }
    catch(int check){
        switch ( check ){
          case 0:
            insertTree(true, index, model, QString::number(id), "Default_" + QString::number(id));
            break;
          case 1:
            insertTree(true, index, model, QString::number(id), NameLine);
            break;
        case 2:
            insertTree(true, index, model, IDLine, "Default_" + IDLine);
            break;
        }
    }

    ui->treeView->selectionModel()->setCurrentIndex(model->index(0, 0, index),
    QItemSelectionModel::ClearAndSelect);
    updateActions();
}

void Widget::insertRow()
{
    QString IDLine = ui->IDLine->text();
    QString NameLine = ui->NameLine->text();

    int id = 0;
    int countID = 0;

    countID = Database.countID();
    QStringList ID(Database.take_id());

    bool ok;
    id = ID.at(countID-1).toInt(&ok, 10)+1;

    QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->treeView->model();
    if (!model->insertRow(index.row()+1, index.parent()))
        return;
    updateActions();
    try{
        check(IDLine, NameLine);

        insertTree(false, index, model, IDLine, NameLine);
    }
    catch(int check){
        switch ( check ){
          case 0:
            insertTree(false, index, model, QString::number(id), "Default_" + QString::number(id));
            break;
          case 1:
            insertTree(false, index, model, QString::number(id), NameLine);
            break;
          case 2:
            insertTree(false, index, model, IDLine, "Default_" + IDLine);
            break;
        }
    }
}

void Widget::removeRow()
{
    QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->treeView->model();

    bool ok;
    int RemoveID = model->data(model->index(index.row(), 0, index.parent())).toInt(&ok);

    if (model->removeRow(index.row(), index.parent())){
        Database.RemoveItem(RemoveID);
        updateActions();
    }
}

void Widget::clear()
{
    QModelIndex parentIndex = ui->treeView->selectionModel()->currentIndex().parent();
    QAbstractItemModel *model = ui->treeView->model();

    int countID = Database.countID();

    for(int i = 0; i < countID; i++){
    if (model->removeRow(0, parentIndex))
        updateActions();
    }
}

void Widget::Fill()
{
    int countID = 0;
    countID = Database.countID();

    if(countID!=0){
        QModelIndex index = ui->treeView->selectionModel()->currentIndex();
        QAbstractItemModel *model = ui->treeView->model();

        QStringList ID(Database.take_id());
        QStringList Name(Database.take_Data());

        if (model->columnCount(index) == 0){
            if (!model->insertColumn(0, index))
               return;
        }
        if (!model->insertRow(0, index))
            return;

        QModelIndex child;
        child = model->index(0, 0, index);
        model->setData(child, QVariant(ID.at(0)), Qt::EditRole);
        child = model->index(0, 1, index);
        model->setData(child, QVariant(Name.at(0)), Qt::EditRole);

        for(int count = 2; count <= countID; count++){
            if (!model->insertRow(index.row()+count, index.parent()))
                return;
            QModelIndex child;
            child= model->index(index.row()+count, 0, index.parent());
            model->setData(child, QVariant(ID.at(count-1)), Qt::EditRole);
            child = model->index(index.row()+count, 1, index.parent());
            model->setData(child, QVariant(Name.at(count-1)), Qt::EditRole);
        }
    }
    else QMessageBox :: critical (this, "info", "Table is empty");
}

void Widget::refill()
{
    clear();
    Fill();
}

void Widget::UpdateDatabase()
{
    QModelIndex parentIndex = ui->treeView->selectionModel()->currentIndex().parent();
    QAbstractItemModel *model = ui->treeView->model();

    int countID = 0;
    countID = Database.countID();

    if(countID!=0){
        QStringList ID(Database.take_id());
        QStringList Name(Database.take_Data());

        QModelIndex ID_index;
        QModelIndex Name_index;

        for(int count = 0; count < model->rowCount(parentIndex); count++){
            ID_index = model->index(count, 0, parentIndex);
            Name_index = model->index(count, 1, parentIndex);

            if(ID.at(count) != model->data(ID_index, Qt::DisplayRole ||
                                           Name.at(count) != model->data(Name_index, Qt::DisplayRole))){

                if(ID.at(count) != model->data(ID_index, Qt::DisplayRole) &&
                        Name.at(count) == model->data(Name_index, Qt::DisplayRole)){
                    try{
                       check(model->data(ID_index, Qt::DisplayRole).toString(), "name");
                       Database.idUpdate(ID.at(count),
                                      model->data(ID_index, Qt::DisplayRole).toString());
                  } catch(int error) {
                        QMessageBox :: critical (this, "error id", "bad id");
                        model->setData(ID_index, QVariant(ID.at(count)), Qt::EditRole);
                    }
                }

                if(ID.at(count) == model->data(ID_index, Qt::DisplayRole) &&
                        Name.at(count) != model->data(Name_index, Qt::DisplayRole)){
                    bool ok;
                    Database.NameUpdate(model->data(ID_index, Qt::DisplayRole).toInt(&ok),
                                        model->data(Name_index, Qt::DisplayRole).toString());
                }
                if(ID.at(count) != model->data(ID_index, Qt::DisplayRole) &&
                                               Name.at(count) != model->data(Name_index, Qt::DisplayRole)){
                    try{
                       check(model->data(ID_index, Qt::DisplayRole).toString(), "name");
                       bool ok;
                       Database.idUpdate(ID.at(count),
                                      model->data(ID_index, Qt::DisplayRole).toString());
                       Database.NameUpdate(model->data(ID_index, Qt::DisplayRole).toInt(&ok),
                                           model->data(Name_index, Qt::DisplayRole).toString());
                  } catch(int error) {
                        QMessageBox :: critical (this, "error id", "bad id");
                        model->setData(ID_index, QVariant(ID.at(count)), Qt::EditRole);
                        model->setData(Name_index, QVariant(Name.at(count)), Qt::EditRole);
                    }
                }
            }
        }
    }
    updateActions();
}

void Widget::updateActions(const QItemSelection &selected,const QItemSelection &deselected)
{
    updateActions();
}

void Widget::updateActions()
{
 //Обновим состояние кнопок:
    bool hasSelection = !ui->treeView->selectionModel()->selection().isEmpty();

    bool hasCurrent = ui->treeView->selectionModel()->currentIndex().isValid();
    ui->insertRowAction->setEnabled(hasCurrent);

    if (hasCurrent){
        ui->treeView->closePersistentEditor(ui->treeView->selectionModel()->currentIndex());
        int row = ui->treeView->selectionModel()->currentIndex().row();
        int column = ui->treeView->selectionModel()->currentIndex().column();
        if (ui->treeView->selectionModel()->currentIndex().parent().isValid())
            this->setWindowTitle(tr("(row,col)=(%1,%2)").arg(row).arg(column));
        else
            this->setWindowTitle(tr("(row,col)=(%1,%2) ВЕРХ").arg(row).arg(column));
    }
}



