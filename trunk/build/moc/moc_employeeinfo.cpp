/****************************************************************************
** Meta object code from reading C++ file 'employeeinfo.h'
**
** Created: Fri Sep 14 04:17:39 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Raqeeb/PRE/employeeinfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employeeinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmployeeInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      38,   13,   13,   13, 0x08,
      64,   13,   13,   13, 0x08,
      90,   13,   13,   13, 0x08,
     117,   13,   13,   13, 0x08,
     147,   13,   13,   13, 0x08,
     179,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EmployeeInfo[] = {
    "EmployeeInfo\0\0on_pbtnUpdate_clicked()\0"
    "on_pbtnAddLeave_clicked()\0"
    "on_pbtnDelLeave_clicked()\0"
    "on_pbtnAddBounce_clicked()\0"
    "on_pbtnDeleteBounce_clicked()\0"
    "on_pbtnAddRetribution_clicked()\0"
    "on_pbtnDelRetribution_clicked()\0"
};

void EmployeeInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EmployeeInfo *_t = static_cast<EmployeeInfo *>(_o);
        switch (_id) {
        case 0: _t->on_pbtnUpdate_clicked(); break;
        case 1: _t->on_pbtnAddLeave_clicked(); break;
        case 2: _t->on_pbtnDelLeave_clicked(); break;
        case 3: _t->on_pbtnAddBounce_clicked(); break;
        case 4: _t->on_pbtnDeleteBounce_clicked(); break;
        case 5: _t->on_pbtnAddRetribution_clicked(); break;
        case 6: _t->on_pbtnDelRetribution_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EmployeeInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EmployeeInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EmployeeInfo,
      qt_meta_data_EmployeeInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmployeeInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmployeeInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmployeeInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeeInfo))
        return static_cast<void*>(const_cast< EmployeeInfo*>(this));
    return QDialog::qt_metacast(_clname);
}

int EmployeeInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
