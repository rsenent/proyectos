/****************************************************************************
** Meta object code from reading C++ file 'setup.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../setup_popup/setup.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_setup[] = {

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
       7,    6,    6,    6, 0x08,
      31,    6,    6,    6, 0x08,
      58,    6,    6,    6, 0x08,
      85,    6,    6,    6, 0x08,
     109,    6,    6,    6, 0x08,
     138,    6,  133,    6, 0x08,
     146,    6,  133,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_setup[] = {
    "setup\0\0on_pushButton_clicked()\0"
    "on_radioButton_3_clicked()\0"
    "on_radioButton_4_clicked()\0"
    "on_checkBox_2_clicked()\0on_checkBox_3_clicked()\0"
    "bool\0popup()\0impresoraDirecta()\0"
};

void setup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        setup *_t = static_cast<setup *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_radioButton_3_clicked(); break;
        case 2: _t->on_radioButton_4_clicked(); break;
        case 3: _t->on_checkBox_2_clicked(); break;
        case 4: _t->on_checkBox_3_clicked(); break;
        case 5: { bool _r = _t->popup();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->impresoraDirecta();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData setup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject setup::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_setup,
      qt_meta_data_setup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &setup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *setup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *setup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_setup))
        return static_cast<void*>(const_cast< setup*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int setup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
