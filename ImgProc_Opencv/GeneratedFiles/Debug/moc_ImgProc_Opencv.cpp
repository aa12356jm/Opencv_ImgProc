/****************************************************************************
** Meta object code from reading C++ file 'ImgProc_Opencv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImgProc_Opencv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImgProc_Opencv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImgProc_Opencv_t {
    QByteArrayData data[9];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgProc_Opencv_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgProc_Opencv_t qt_meta_stringdata_ImgProc_Opencv = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ImgProc_Opencv"
QT_MOC_LITERAL(1, 15, 31), // "on_pushButton_OpenCamera_cliked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 29), // "on_pushButton_SnapShot_cliked"
QT_MOC_LITERAL(4, 78, 31), // "on_radioButton_ToGrayImg_cliked"
QT_MOC_LITERAL(5, 110, 37), // "on_radioButton_ToBlackWhiteIm..."
QT_MOC_LITERAL(6, 148, 28), // "on_radioButton_Filter_cliked"
QT_MOC_LITERAL(7, 177, 32), // "on_radioButton_Morphology_cliked"
QT_MOC_LITERAL(8, 210, 35) // "on_radioButton_EdgeDetection_..."

    },
    "ImgProc_Opencv\0on_pushButton_OpenCamera_cliked\0"
    "\0on_pushButton_SnapShot_cliked\0"
    "on_radioButton_ToGrayImg_cliked\0"
    "on_radioButton_ToBlackWhiteImg_cliked\0"
    "on_radioButton_Filter_cliked\0"
    "on_radioButton_Morphology_cliked\0"
    "on_radioButton_EdgeDetection_cliked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgProc_Opencv[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImgProc_Opencv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImgProc_Opencv *_t = static_cast<ImgProc_Opencv *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_OpenCamera_cliked(); break;
        case 1: _t->on_pushButton_SnapShot_cliked(); break;
        case 2: _t->on_radioButton_ToGrayImg_cliked(); break;
        case 3: _t->on_radioButton_ToBlackWhiteImg_cliked(); break;
        case 4: _t->on_radioButton_Filter_cliked(); break;
        case 5: _t->on_radioButton_Morphology_cliked(); break;
        case 6: _t->on_radioButton_EdgeDetection_cliked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ImgProc_Opencv::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImgProc_Opencv.data,
      qt_meta_data_ImgProc_Opencv,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImgProc_Opencv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgProc_Opencv::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImgProc_Opencv.stringdata0))
        return static_cast<void*>(const_cast< ImgProc_Opencv*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImgProc_Opencv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
