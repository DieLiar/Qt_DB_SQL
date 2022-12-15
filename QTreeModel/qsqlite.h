#ifndef QSQLITE_H
#define QSQLITE_H

#include <QtSql>
#include <QSqlQuery>
#include <QFile>
#include <QDir>

class QSQLITE
{
private:
    QSqlQuery *Table_I;
    QSqlDatabase Item;

public:
    QSQLITE();

    void AddItem(int id, QString name);
    void RemoveItem(int id);
    void idUpdate(QString old_id, QString new_id);
    void NameUpdate(int id,QString Name);
    void ReFresh();
    void FILL();
    int check();
    int countID();

    QStringList take_Data();
    QStringList take_id();


};

#endif // QSQLITE_H
