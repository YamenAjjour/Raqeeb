/****************************************************************************
** Meta object code from reading C++ file 'addleave.h'
**
** Created: Fri Sep 14 04:17:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Raqeeb/PRE/addleave.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addleave.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addLeave[] = {

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
      10,    9,    9,    9, 0x08,
      31,    9,    9,    9, 0x08,
      55,    9,    9,    9, 0x08,
      79,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_addLeave[] = {
    "addLeave\0\0on_pbtnAdd_clicked()\0"
    "on_pbtnAddEmp_clicked()\0on_pbtnRemEmp_clicked()\0"
    "on_pbtnSelectAll_clicked()\0"
};

void addLeave::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        addLeave *_t = static_cast<addLeave *>(_o);
        switch (_id) {
        case 0: _t->on_pbtnAdd_clicked(); break;
        case 1: _t->on_pbtnAddEmp_clicked(); break;
        case 2: _t->on_pbtnRemEmp_clicked(); break;
        case 3: _t->on_pbtnSelectAll_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData addLeave::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject addLeave::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addLeave,
      qt_meta_data_addLeave, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &addLeave::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *addLeave::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *addLeave::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addLeave))
        return static_cast<void*>(const_cast< addLeave*>(this));
    return QDialog::qt_metacast(_clname);
}

int addLeave::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
