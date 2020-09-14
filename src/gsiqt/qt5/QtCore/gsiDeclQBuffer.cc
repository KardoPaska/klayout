
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2020 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

/**
*  @file gsiDeclQBuffer.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include <QBuffer>
#include <QEvent>
#include <QMetaMethod>
#include <QObject>
#include <QThread>
#include "gsiQt.h"
#include "gsiQtCoreCommon.h"
#include "gsiDeclQtCoreTypeTraits.h"
#include <memory>

// -----------------------------------------------------------------------
// class QBuffer

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QBuffer::staticMetaObject);
}


//  Constructor QBuffer::QBuffer(QObject *parent)


static void _init_ctor_QBuffer_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QBuffer> ();
}

static void _call_ctor_QBuffer_1302 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ret.write<QBuffer *> (new QBuffer (arg1));
}


//  Constructor QBuffer::QBuffer(QByteArray *buf, QObject *parent)


static void _init_ctor_QBuffer_2812 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("buf");
  decl->add_arg<QByteArray * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_1);
  decl->set_return_new<QBuffer> ();
}

static void _call_ctor_QBuffer_2812 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QByteArray *arg1 = gsi::arg_reader<QByteArray * >() (args, heap);
  QObject *arg2 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ret.write<QBuffer *> (new QBuffer (arg1, arg2));
}


// bool QBuffer::atEnd()


static void _init_f_atEnd_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_atEnd_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<bool > ((bool)((QBuffer *)cls)->atEnd ());
}


// QByteArray &QBuffer::buffer()


static void _init_f_buffer_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QByteArray & > ();
}

static void _call_f_buffer_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QByteArray & > ((QByteArray &)((QBuffer *)cls)->buffer ());
}


// const QByteArray &QBuffer::buffer()


static void _init_f_buffer_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QByteArray & > ();
}

static void _call_f_buffer_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<const QByteArray & > ((const QByteArray &)((QBuffer *)cls)->buffer ());
}


// bool QBuffer::canReadLine()


static void _init_f_canReadLine_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_canReadLine_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<bool > ((bool)((QBuffer *)cls)->canReadLine ());
}


// void QBuffer::close()


static void _init_f_close_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<void > ();
}

static void _call_f_close_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QBuffer *)cls)->close ();
}


// const QByteArray &QBuffer::data()


static void _init_f_data_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QByteArray & > ();
}

static void _call_f_data_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<const QByteArray & > ((const QByteArray &)((QBuffer *)cls)->data ());
}


// bool QBuffer::open(QFlags<QIODevice::OpenModeFlag> openMode)


static void _init_f_open_3242 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("openMode");
  decl->add_arg<QFlags<QIODevice::OpenModeFlag> > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_f_open_3242 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QFlags<QIODevice::OpenModeFlag> arg1 = gsi::arg_reader<QFlags<QIODevice::OpenModeFlag> >() (args, heap);
  ret.write<bool > ((bool)((QBuffer *)cls)->open (arg1));
}


// qint64 QBuffer::pos()


static void _init_f_pos_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qint64 > ();
}

static void _call_f_pos_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<qint64 > ((qint64)((QBuffer *)cls)->pos ());
}


// bool QBuffer::seek(qint64 off)


static void _init_f_seek_986 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("off");
  decl->add_arg<qint64 > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_f_seek_986 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  qint64 arg1 = gsi::arg_reader<qint64 >() (args, heap);
  ret.write<bool > ((bool)((QBuffer *)cls)->seek (arg1));
}


// void QBuffer::setBuffer(QByteArray *a)


static void _init_f_setBuffer_1618 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("a");
  decl->add_arg<QByteArray * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setBuffer_1618 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QByteArray *arg1 = gsi::arg_reader<QByteArray * >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QBuffer *)cls)->setBuffer (arg1);
}


// void QBuffer::setData(const QByteArray &data)


static void _init_f_setData_2309 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("data");
  decl->add_arg<const QByteArray & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setData_2309 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = gsi::arg_reader<const QByteArray & >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QBuffer *)cls)->setData (arg1);
}


// void QBuffer::setData(const char *data, int len)


static void _init_f_setData_2390 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("data");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("len");
  decl->add_arg<int > (argspec_1);
  decl->set_return<void > ();
}

static void _call_f_setData_2390 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  int arg2 = gsi::arg_reader<int >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QBuffer *)cls)->setData (arg1, arg2);
}


// qint64 QBuffer::size()


static void _init_f_size_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<qint64 > ();
}

static void _call_f_size_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<qint64 > ((qint64)((QBuffer *)cls)->size ());
}


// static QString QBuffer::tr(const char *s, const char *c, int n)


static void _init_f_tr_4013 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c", true, "__null");
  decl->add_arg<const char * > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("n", true, "-1");
  decl->add_arg<int > (argspec_2);
  decl->set_return<QString > ();
}

static void _call_f_tr_4013 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  const char *arg2 = args ? gsi::arg_reader<const char * >() (args, heap) : gsi::arg_maker<const char * >() (__null, heap);
  int arg3 = args ? gsi::arg_reader<int >() (args, heap) : gsi::arg_maker<int >() (-1, heap);
  ret.write<QString > ((QString)QBuffer::tr (arg1, arg2, arg3));
}


// static QString QBuffer::trUtf8(const char *s, const char *c, int n)


static void _init_f_trUtf8_4013 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("s");
  decl->add_arg<const char * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("c", true, "__null");
  decl->add_arg<const char * > (argspec_1);
  static gsi::ArgSpecBase argspec_2 ("n", true, "-1");
  decl->add_arg<int > (argspec_2);
  decl->set_return<QString > ();
}

static void _call_f_trUtf8_4013 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  const char *arg2 = args ? gsi::arg_reader<const char * >() (args, heap) : gsi::arg_maker<const char * >() (__null, heap);
  int arg3 = args ? gsi::arg_reader<int >() (args, heap) : gsi::arg_maker<int >() (-1, heap);
  ret.write<QString > ((QString)QBuffer::trUtf8 (arg1, arg2, arg3));
}



namespace gsi
{

static gsi::Methods methods_QBuffer () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QBuffer::QBuffer(QObject *parent)\nThis method creates an object of class QBuffer.", &_init_ctor_QBuffer_1302, &_call_ctor_QBuffer_1302);
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QBuffer::QBuffer(QByteArray *buf, QObject *parent)\nThis method creates an object of class QBuffer.", &_init_ctor_QBuffer_2812, &_call_ctor_QBuffer_2812);
  methods += new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
  methods += new qt_gsi::GenericMethod ("atEnd", "@brief Method bool QBuffer::atEnd()\nThis is a reimplementation of QIODevice::atEnd", true, &_init_f_atEnd_c0, &_call_f_atEnd_c0);
  methods += new qt_gsi::GenericMethod ("buffer", "@brief Method QByteArray &QBuffer::buffer()\n", false, &_init_f_buffer_0, &_call_f_buffer_0);
  methods += new qt_gsi::GenericMethod ("buffer", "@brief Method const QByteArray &QBuffer::buffer()\n", true, &_init_f_buffer_c0, &_call_f_buffer_c0);
  methods += new qt_gsi::GenericMethod ("canReadLine", "@brief Method bool QBuffer::canReadLine()\nThis is a reimplementation of QIODevice::canReadLine", true, &_init_f_canReadLine_c0, &_call_f_canReadLine_c0);
  methods += new qt_gsi::GenericMethod ("close", "@brief Method void QBuffer::close()\nThis is a reimplementation of QIODevice::close", false, &_init_f_close_0, &_call_f_close_0);
  methods += new qt_gsi::GenericMethod (":data", "@brief Method const QByteArray &QBuffer::data()\n", true, &_init_f_data_c0, &_call_f_data_c0);
  methods += new qt_gsi::GenericMethod ("open", "@brief Method bool QBuffer::open(QFlags<QIODevice::OpenModeFlag> openMode)\nThis is a reimplementation of QIODevice::open", false, &_init_f_open_3242, &_call_f_open_3242);
  methods += new qt_gsi::GenericMethod ("pos", "@brief Method qint64 QBuffer::pos()\nThis is a reimplementation of QIODevice::pos", true, &_init_f_pos_c0, &_call_f_pos_c0);
  methods += new qt_gsi::GenericMethod ("seek", "@brief Method bool QBuffer::seek(qint64 off)\nThis is a reimplementation of QIODevice::seek", false, &_init_f_seek_986, &_call_f_seek_986);
  methods += new qt_gsi::GenericMethod ("setBuffer", "@brief Method void QBuffer::setBuffer(QByteArray *a)\n", false, &_init_f_setBuffer_1618, &_call_f_setBuffer_1618);
  methods += new qt_gsi::GenericMethod ("setData|data=", "@brief Method void QBuffer::setData(const QByteArray &data)\n", false, &_init_f_setData_2309, &_call_f_setData_2309);
  methods += new qt_gsi::GenericMethod ("setData", "@brief Method void QBuffer::setData(const char *data, int len)\n", false, &_init_f_setData_2390, &_call_f_setData_2390);
  methods += new qt_gsi::GenericMethod ("size", "@brief Method qint64 QBuffer::size()\nThis is a reimplementation of QIODevice::size", true, &_init_f_size_c0, &_call_f_size_c0);
  methods += gsi::qt_signal ("aboutToClose()", "aboutToClose", "@brief Signal declaration for QBuffer::aboutToClose()\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal<qint64 > ("bytesWritten(qint64)", "bytesWritten", gsi::arg("bytes"), "@brief Signal declaration for QBuffer::bytesWritten(qint64 bytes)\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal<QObject * > ("destroyed(QObject *)", "destroyed", gsi::arg("arg1"), "@brief Signal declaration for QBuffer::destroyed(QObject *)\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal<const QString & > ("objectNameChanged(const QString &)", "objectNameChanged", gsi::arg("objectName"), "@brief Signal declaration for QBuffer::objectNameChanged(const QString &objectName)\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal ("readChannelFinished()", "readChannelFinished", "@brief Signal declaration for QBuffer::readChannelFinished()\nYou can bind a procedure to this signal.");
  methods += gsi::qt_signal ("readyRead()", "readyRead", "@brief Signal declaration for QBuffer::readyRead()\nYou can bind a procedure to this signal.");
  methods += new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QBuffer::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
  methods += new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QBuffer::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
  return methods;
}

gsi::Class<QIODevice> &qtdecl_QIODevice ();

qt_gsi::QtNativeClass<QBuffer> decl_QBuffer (qtdecl_QIODevice (), "QtCore", "QBuffer",
  methods_QBuffer (),
  "@qt\n@brief Binding of QBuffer");


GSI_QTCORE_PUBLIC gsi::Class<QBuffer> &qtdecl_QBuffer () { return decl_QBuffer; }

}

