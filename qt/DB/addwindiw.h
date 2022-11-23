#ifndef ADDWINDIW_H
#define ADDWINDIW_H

#include <QDialog>

namespace Ui {
class AddWindiw;
}

class AddWindiw : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindiw(QWidget *parent = nullptr);
    ~AddWindiw();

private slots:
    void on_Add_clicked();
    void on_Close_clicked();


private:
    Ui::AddWindiw *ui;
};

#endif // ADDWINDIW_H
