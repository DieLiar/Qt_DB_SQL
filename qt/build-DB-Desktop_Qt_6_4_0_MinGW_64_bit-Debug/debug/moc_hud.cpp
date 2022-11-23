/****************************************************************************
** Meta object code from reading C++ file 'hud.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DB/hud.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hud.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_HUD_t {
    uint offsetsAndSizes[24];
    char stringdata0[4];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[17];
    char stringdata5[5];
    char stringdata6[7];
    char stringdata7[17];
    char stringdata8[18];
    char stringdata9[16];
    char stringdata10[18];
    char stringdata11[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_HUD_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_HUD_t qt_meta_stringdata_HUD = {
    {
        QT_MOC_LITERAL(0, 3),  // "HUD"
        QT_MOC_LITERAL(4, 22),  // "on_actionAdd_triggered"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 25),  // "on_treeWidget_itemClicked"
        QT_MOC_LITERAL(54, 16),  // "QTreeWidgetItem*"
        QT_MOC_LITERAL(71, 4),  // "item"
        QT_MOC_LITERAL(76, 6),  // "column"
        QT_MOC_LITERAL(83, 16),  // "on_input_clicked"
        QT_MOC_LITERAL(100, 17),  // "on_remove_clicked"
        QT_MOC_LITERAL(118, 15),  // "on_TEST_clicked"
        QT_MOC_LITERAL(134, 17),  // "on_EditID_clicked"
        QT_MOC_LITERAL(152, 15)   // "on_info_clicked"
    },
    "HUD",
    "on_actionAdd_triggered",
    "",
    "on_treeWidget_itemClicked",
    "QTreeWidgetItem*",
    "item",
    "column",
    "on_input_clicked",
    "on_remove_clicked",
    "on_TEST_clicked",
    "on_EditID_clicked",
    "on_info_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_HUD[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    2,   57,    2, 0x08,    2 /* Private */,
       7,    0,   62,    2, 0x08,    5 /* Private */,
       8,    0,   63,    2, 0x08,    6 /* Private */,
       9,    0,   64,    2, 0x08,    7 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    0,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject HUD::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HUD.offsetsAndSizes,
    qt_meta_data_HUD,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_HUD_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HUD, std::true_type>,
        // method 'on_actionAdd_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_treeWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_input_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_remove_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_TEST_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EditID_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_info_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void HUD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HUD *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionAdd_triggered(); break;
        case 1: _t->on_treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->on_input_clicked(); break;
        case 3: _t->on_remove_clicked(); break;
        case 4: _t->on_TEST_clicked(); break;
        case 5: _t->on_EditID_clicked(); break;
        case 6: _t->on_info_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *HUD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HUD::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HUD.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HUD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
