/********************************************************************************
** Form generated from reading UI file 'hud.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUD_H
#define UI_HUD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HUD
{
public:
    QAction *actionCreate;
    QAction *actionCreate_from;
    QAction *actionAdd;
    QAction *actionAdd_from;
    QAction *actionRemove;
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QPushButton *TEST;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *remove;
    QPushButton *input;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QPushButton *EditID;
    QLineEdit *EditLineID;
    QLabel *label_3;
    QPushButton *info;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HUD)
    {
        if (HUD->objectName().isEmpty())
            HUD->setObjectName("HUD");
        HUD->resize(1050, 560);
        actionCreate = new QAction(HUD);
        actionCreate->setObjectName("actionCreate");
        actionCreate_from = new QAction(HUD);
        actionCreate_from->setObjectName("actionCreate_from");
        actionAdd = new QAction(HUD);
        actionAdd->setObjectName("actionAdd");
        actionAdd_from = new QAction(HUD);
        actionAdd_from->setObjectName("actionAdd_from");
        actionRemove = new QAction(HUD);
        actionRemove->setObjectName("actionRemove");
        centralwidget = new QWidget(HUD);
        centralwidget->setObjectName("centralwidget");
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(290, 10, 741, 491));
        TEST = new QPushButton(centralwidget);
        TEST->setObjectName("TEST");
        TEST->setGeometry(QRect(20, 480, 80, 24));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 232, 134));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        remove = new QPushButton(layoutWidget);
        remove->setObjectName("remove");

        gridLayout->addWidget(remove, 4, 0, 1, 1);

        input = new QPushButton(layoutWidget);
        input->setObjectName("input");

        gridLayout->addWidget(input, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 210, 231, 78));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        EditID = new QPushButton(layoutWidget1);
        EditID->setObjectName("EditID");

        gridLayout_3->addWidget(EditID, 2, 0, 1, 1);

        EditLineID = new QLineEdit(layoutWidget1);
        EditLineID->setObjectName("EditLineID");

        gridLayout_3->addWidget(EditLineID, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        info = new QPushButton(centralwidget);
        info->setObjectName("info");
        info->setGeometry(QRect(20, 400, 80, 24));
        HUD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HUD);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1050, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        HUD->setMenuBar(menubar);
        statusbar = new QStatusBar(HUD);
        statusbar->setObjectName("statusbar");
        HUD->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionCreate);
        menuFile->addAction(actionCreate_from);
        menuFile->addSeparator();
        menuFile->addAction(actionAdd);
        menuFile->addAction(actionAdd_from);
        menuFile->addSeparator();
        menuFile->addAction(actionRemove);

        retranslateUi(HUD);

        QMetaObject::connectSlotsByName(HUD);
    } // setupUi

    void retranslateUi(QMainWindow *HUD)
    {
        HUD->setWindowTitle(QCoreApplication::translate("HUD", "HUD", nullptr));
        actionCreate->setText(QCoreApplication::translate("HUD", "Create", nullptr));
        actionCreate_from->setText(QCoreApplication::translate("HUD", "Create from...", nullptr));
        actionAdd->setText(QCoreApplication::translate("HUD", "Add", nullptr));
        actionAdd_from->setText(QCoreApplication::translate("HUD", "Add from...", nullptr));
        actionRemove->setText(QCoreApplication::translate("HUD", "Remove", nullptr));
        TEST->setText(QCoreApplication::translate("HUD", "Fill for Test", nullptr));
        remove->setText(QCoreApplication::translate("HUD", "Remove", nullptr));
        input->setText(QCoreApplication::translate("HUD", "Input", nullptr));
        label_2->setText(QCoreApplication::translate("HUD", "Name", nullptr));
        label->setText(QCoreApplication::translate("HUD", "ID", nullptr));
        EditID->setText(QCoreApplication::translate("HUD", "Edit", nullptr));
        label_3->setText(QCoreApplication::translate("HUD", "Edit ID or Name", nullptr));
        info->setText(QCoreApplication::translate("HUD", "Informations", nullptr));
        menuFile->setTitle(QCoreApplication::translate("HUD", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HUD: public Ui_HUD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUD_H
