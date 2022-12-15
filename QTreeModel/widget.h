#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QtWidgets>
#include <QFile>
#include <QDir>

#include "qsqlite.h"

namespace Ui { class Widget; }
class Widget : public QWidget, public QSQLITE{
    Q_OBJECT
    Ui::Widget *ui;

public:
    Widget(QWidget *parent = 0);

    QSQLITE Database;


    void updateActions();
    void check(QString IDLine, QString NameLine);


private slots:
    void insertChild();
    void insertRow();
    void removeRow();
    void insertTree(bool flag, QModelIndex index, QAbstractItemModel *model, QString IDLine, QString NameLine);
    void clear();
    void refill();
    void Fill();
    void UpdateDatabase();

public slots:
    void updateActions(const QItemSelection &,const QItemSelection &);
};
#endif // WIDGET_H
