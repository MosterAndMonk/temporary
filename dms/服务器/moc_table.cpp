/****************************************************************************
** Meta object code from reading C++ file 'table.h'
**
** Created: Fri Jul 8 16:10:07 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "table.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'table.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Table[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      29,    6,    6,    6, 0x08,
      49,    6,    6,    6, 0x08,
      68,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Table[] = {
    "Table\0\0on_t_select_clicked()\0"
    "on_t_year_clicked()\0on_t_mon_clicked()\0"
    "on_t_day_clicked()\0"
};

void Table::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Table *_t = static_cast<Table *>(_o);
        switch (_id) {
        case 0: _t->on_t_select_clicked(); break;
        case 1: _t->on_t_year_clicked(); break;
        case 2: _t->on_t_mon_clicked(); break;
        case 3: _t->on_t_day_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Table::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Table::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Table,
      qt_meta_data_Table, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Table::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Table::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Table::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Table))
        return static_cast<void*>(const_cast< Table*>(this));
    return QWidget::qt_metacast(_clname);
}

int Table::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
