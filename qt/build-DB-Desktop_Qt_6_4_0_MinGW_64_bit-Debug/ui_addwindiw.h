/********************************************************************************
** Form generated from reading UI file 'addwindiw.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDIW_H
#define UI_ADDWINDIW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddWindiw
{
public:
    QGroupBox *AddGroupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *AddNames;
    QPushButton *Add;
    QPushButton *Close;

    void setupUi(QDialog *AddWindiw)
    {
        if (AddWindiw->objectName().isEmpty())
            AddWindiw->setObjectName("AddWindiw");
        AddWindiw->resize(454, 258);
        AddGroupBox = new QGroupBox(AddWindiw);
        AddGroupBox->setObjectName("AddGroupBox");
        AddGroupBox->setGeometry(QRect(30, 20, 391, 141));
        verticalLayout_2 = new QVBoxLayout(AddGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(AddGroupBox);
        label->setObjectName("label");

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        AddNames = new QLineEdit(AddGroupBox);
        AddNames->setObjectName("AddNames");

        gridLayout_4->addWidget(AddNames, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        Add = new QPushButton(AddGroupBox);
        Add->setObjectName("Add");

        verticalLayout_2->addWidget(Add);

        Close = new QPushButton(AddWindiw);
        Close->setObjectName("Close");
        Close->setGeometry(QRect(340, 220, 80, 24));

        retranslateUi(AddWindiw);

        QMetaObject::connectSlotsByName(AddWindiw);
    } // setupUi

    void retranslateUi(QDialog *AddWindiw)
    {
        AddWindiw->setWindowTitle(QCoreApplication::translate("AddWindiw", "Dialog", nullptr));
        AddGroupBox->setTitle(QCoreApplication::translate("AddWindiw", "Add", nullptr));
        label->setText(QCoreApplication::translate("AddWindiw", "Name", nullptr));
        Add->setText(QCoreApplication::translate("AddWindiw", "Add", nullptr));
        Close->setText(QCoreApplication::translate("AddWindiw", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWindiw: public Ui_AddWindiw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDIW_H
