#include "qsqlite.h"


QSQLITE::QSQLITE()
{
    QSqlDatabase DBItem;
    DBItem = QSqlDatabase::addDatabase("QSQLITE");


    QString pathPro = QDir::currentPath();
    QStringList pathPro_cut = pathPro.split("/", Qt::SkipEmptyParts);

    QString pathDatabase;

    foreach(QString str, pathPro_cut){
        pathDatabase.append(str);
        pathDatabase.append("\\");
    }
    pathDatabase.append("QTree_Item_DataBase.db3");


    DBItem.setDatabaseName(pathDatabase);
    Table_I = new QSqlQuery;
    DBItem.open();
    Table_I->exec("CREATE TABLE Item (id  INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT    NOT NULL);");
}

void QSQLITE::AddItem(int id, QString name)
{
    QString str = "INSERT INTO Item(id, Name) VALUES("+ QString::number(id) + ", '" + name + "');";
    Table_I->exec(str);
}

void QSQLITE::RemoveItem(int id)
{
    QString str = "DELETE FROM Item WHERE id = '" + QString::number(id) + "';";
    Table_I->exec(str);
}

void QSQLITE::idUpdate(QString old_id, QString new_id)
{
    QString exec = "UPDATE Item SET id = '" + new_id + "' WHERE id = '" + old_id + "';";
    Table_I->exec(exec);
}

void QSQLITE::NameUpdate(int id, QString Name)
{
    QString exec = "UPDATE Item SET Name = '" + Name + "' WHERE id = '" + QString::number(id) + "';";
    Table_I->exec(exec);
}

int QSQLITE::countID()
{
    int count = 0;
    Table_I->exec("SELECT * FROM Item");
    while (Table_I->next()){
        count++;}
    return count;
}

int QSQLITE::check()
{
    QString d;
    int count = 0;
    int *id_arr = new int[countID()];

    Table_I->exec("SELECT * FROM Item");
    while (Table_I->next()){
        int id = Table_I->value(0).toInt();
        id_arr[count] = id;
        count++;
    }
    return *id_arr;
}

QStringList QSQLITE::take_id()
{
    QStringList id;
    int IDcount = countID();
    if(IDcount!=0){
        int count = 0;
        Table_I->exec("SELECT * FROM Item");
        while (Table_I->next()){
            id<<(Table_I->value(0).toString());
            count++;
        }
    }
    return id;
}

QStringList QSQLITE::take_Data()
{
    QStringList data;
    int IDcount = countID();
    if(IDcount!=0){
        int count = 0;
        Table_I->exec("SELECT * FROM Item");
        while (Table_I->next()){

            data<<(Table_I->value(1).toString());
            count++;
        }
    }
    return data;
}













