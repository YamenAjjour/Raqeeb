/****************************************************************************
** Meta object code from reading C++ file 'newsalary.h'
**
** Created: Fri Sep 14 04:17:38 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Raqeeb/PRE/newsalary.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newsalary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewSalary[] = {

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
      11,   10,   10,   10, 0x08,
      28,   10,   10,   10, 0x08,
      42,   10,   10,   10, 0x08,
      62,   56,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewSalary[] = {
    "NewSalary\0\0openFileDialog()\0displayData()\0"
    "dateChanged()\0index\0"
    "showDetailedUserDialog(QModelIndex)\0"
};

void NewSalary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewSalary *_t = static_cast<NewSalary *>(_o);
        switch (_id) {
        case 0: _t->openFileDialog(); break;
        case 1: _t->displayData(); break;
        case 2: _t->dateChanged(); break;
        case 3: _t->showDetailedUserDialog((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewSalary::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewSalary::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewSalary,
      qt_meta_data_NewSalary, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewSalary::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewSalary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewSalary::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewSalary))
        return static_cast<void*>(const_cast< NewSalary*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewSalary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
