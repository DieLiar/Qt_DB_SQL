#include "addwindiw.h"
#include "ui_addwindiw.h"
#include <QMessageBox>

AddWindiw::AddWindiw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindiw)
{
    ui->setupUi(this);
}

AddWindiw::~AddWindiw()
{
    delete ui;
}

void AddWindiw::on_Add_clicked()
{
    QString Addedname = ui->AddNames->text();
    if(Addedname!=""){
    QMessageBox :: information(this, "info", " name add is complete");
    } else{
        QMessageBox :: critical (this, "info", " name is NULL");
    }
}


void AddWindiw::on_Close_clicked()
{
    QWidget::close();
}

