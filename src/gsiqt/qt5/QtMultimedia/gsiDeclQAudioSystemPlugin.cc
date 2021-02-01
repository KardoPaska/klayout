
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
*  @file gsiDeclQAudioSystemPlugin.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include <QAudioSystemPlugin>
#include <QAbstractAudioDeviceInfo>
#include <QAbstractAudioInput>
#include <QAbstractAudioOutput>
#include <QChildEvent>
#include <QEvent>
#include <QMetaMethod>
#include <QObject>
#include <QThread>
#include <QTimerEvent>
#include "gsiQt.h"
#include "gsiQtMultimediaCommon.h"
#include "gsiDeclQtMultimediaTypeTraits.h"
#include <memory>

// -----------------------------------------------------------------------
// class QAudioSystemPlugin

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QAudioSystemPlugin::staticMetaObject);
}


// QList<QByteArray> QAudioSystemPlugin::availableDevices(QAudio::Mode)


static void _init_f_availableDevices_c1520 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<const qt_gsi::Converter<QAudio::Mode>::target_type & > (argspec_0);
  decl->set_return<QList<QByteArray> > ();
}

static void _call_f_availableDevices_c1520 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const qt_gsi::Converter<QAudio::Mode>::target_type & arg1 = gsi::arg_reader<const qt_gsi::Converter<QAudio::Mode>::target_type & >() (args, heap);
  ret.write<QList<QByteArray> > ((QList<QByteArray>)((QAudioSystemPlugin *)cls)->availableDevices (qt_gsi::QtToCppAdaptor<QAudio::Mode>(arg1).cref()));
}


// QAbstractAudioDeviceInfo *QAudioSystemPlugin::createDeviceInfo(const QByteArray &device, QAudio::Mode mode)


static void _init_f_createDeviceInfo_3721 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<const QByteArray & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("mode");
  decl->add_arg<const qt_gsi::Converter<QAudio::Mode>::target_type & > (argspec_1);
  decl->set_return<QAbstractAudioDeviceInfo * > ();
}

static void _call_f_createDeviceInfo_3721 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = gsi::arg_reader<const QByteArray & >() (args, heap);
  const qt_gsi::Converter<QAudio::Mode>::target_type & arg2 = gsi::arg_reader<const qt_gsi::Converter<QAudio::Mode>::target_type & >() (args, heap);
  ret.write<QAbstractAudioDeviceInfo * > ((QAbstractAudioDeviceInfo *)((QAudioSystemPlugin *)cls)->createDeviceInfo (arg1, qt_gsi::QtToCppAdaptor<QAudio::Mode>(arg2).cref()));
}


// QAbstractAudioInput *QAudioSystemPlugin::createInput(const QByteArray &device)


static void _init_f_createInput_2309 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<const QByteArray & > (argspec_0);
  decl->set_return<QAbstractAudioInput * > ();
}

static void _call_f_createInput_2309 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = gsi::arg_reader<const QByteArray & >() (args, heap);
  ret.write<QAbstractAudioInput * > ((QAbstractAudioInput *)((QAudioSystemPlugin *)cls)->createInput (arg1));
}


// QAbstractAudioOutput *QAudioSystemPlugin::createOutput(const QByteArray &device)


static void _init_f_createOutput_2309 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<const QByteArray & > (argspec_0);
  decl->set_return<QAbstractAudioOutput * > ();
}

static void _call_f_createOutput_2309 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = gsi::arg_reader<const QByteArray & >() (args, heap);
  ret.write<QAbstractAudioOutput * > ((QAbstractAudioOutput *)((QAudioSystemPlugin *)cls)->createOutput (arg1));
}


// static QString QAudioSystemPlugin::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QAudioSystemPlugin::tr (arg1, arg2, arg3));
}


// static QString QAudioSystemPlugin::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QAudioSystemPlugin::trUtf8 (arg1, arg2, arg3));
}


//  base class cast for QObject

static void _init_f_QAudioSystemPlugin_as_QObject (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject *> ();
}

static void _call_f_QAudioSystemPlugin_as_QObject (const qt_gsi::GenericMethod *, void *cls, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<QObject *> ((QObject *)(QAudioSystemPlugin *)cls);
}

static void _init_f_QAudioSystemPlugin_as_const_QObject (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QObject *> ();
}

static void _call_f_QAudioSystemPlugin_as_const_QObject (const qt_gsi::GenericMethod *, void *cls, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QObject *> ((const QObject *)(const QAudioSystemPlugin *)cls);
}

//  base class cast for QAudioSystemFactoryInterface

static void _init_f_QAudioSystemPlugin_as_QAudioSystemFactoryInterface (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QAudioSystemFactoryInterface *> ();
}

static void _call_f_QAudioSystemPlugin_as_QAudioSystemFactoryInterface (const qt_gsi::GenericMethod *, void *cls, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<QAudioSystemFactoryInterface *> ((QAudioSystemFactoryInterface *)(QAudioSystemPlugin *)cls);
}

static void _init_f_QAudioSystemPlugin_as_const_QAudioSystemFactoryInterface (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QAudioSystemFactoryInterface *> ();
}

static void _call_f_QAudioSystemPlugin_as_const_QAudioSystemFactoryInterface (const qt_gsi::GenericMethod *, void *cls, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QAudioSystemFactoryInterface *> ((const QAudioSystemFactoryInterface *)(const QAudioSystemPlugin *)cls);
}


namespace gsi
{

static gsi::Methods methods_QAudioSystemPlugin () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
  methods += new qt_gsi::GenericMethod ("availableDevices", "@brief Method QList<QByteArray> QAudioSystemPlugin::availableDevices(QAudio::Mode)\nThis is a reimplementation of QAudioSystemFactoryInterface::availableDevices", true, &_init_f_availableDevices_c1520, &_call_f_availableDevices_c1520);
  methods += new qt_gsi::GenericMethod ("createDeviceInfo", "@brief Method QAbstractAudioDeviceInfo *QAudioSystemPlugin::createDeviceInfo(const QByteArray &device, QAudio::Mode mode)\nThis is a reimplementation of QAudioSystemFactoryInterface::createDeviceInfo", false, &_init_f_createDeviceInfo_3721, &_call_f_createDeviceInfo_3721);
  methods += new qt_gsi::GenericMethod ("createInput", "@brief Method QAbstractAudioInput *QAudioSystemPlugin::createInput(const QByteArray &device)\nThis is a reimplementation of QAudioSystemFactoryInterface::createInput", false, &_init_f_createInput_2309, &_call_f_createInput_2309);
  methods += new qt_gsi::GenericMethod ("createOutput", "@brief Method QAbstractAudioOutput *QAudioSystemPlugin::createOutput(const QByteArray &device)\nThis is a reimplementation of QAudioSystemFactoryInterface::createOutput", false, &_init_f_createOutput_2309, &_call_f_createOutput_2309);
  methods += new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QAudioSystemPlugin::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
  methods += new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QAudioSystemPlugin::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
  methods += new qt_gsi::GenericMethod ("asQObject", "@brief Delivers the base class interface QObject of QAudioSystemPlugin\nClass QAudioSystemPlugin is derived from multiple base classes. This method delivers the QObject base class aspect.", false, &_init_f_QAudioSystemPlugin_as_QObject, &_call_f_QAudioSystemPlugin_as_QObject);
  methods += new qt_gsi::GenericMethod ("asConstQObject", "@brief Delivers the base class interface QObject of QAudioSystemPlugin\nClass QAudioSystemPlugin is derived from multiple base classes. This method delivers the QObject base class aspect.\n\nUse this version if you have a const reference.", true, &_init_f_QAudioSystemPlugin_as_const_QObject, &_call_f_QAudioSystemPlugin_as_const_QObject);
  methods += new qt_gsi::GenericMethod ("asQAudioSystemFactoryInterface", "@brief Delivers the base class interface QAudioSystemFactoryInterface of QAudioSystemPlugin\nClass QAudioSystemPlugin is derived from multiple base classes. This method delivers the QAudioSystemFactoryInterface base class aspect.", false, &_init_f_QAudioSystemPlugin_as_QAudioSystemFactoryInterface, &_call_f_QAudioSystemPlugin_as_QAudioSystemFactoryInterface);
  methods += new qt_gsi::GenericMethod ("asConstQAudioSystemFactoryInterface", "@brief Delivers the base class interface QAudioSystemFactoryInterface of QAudioSystemPlugin\nClass QAudioSystemPlugin is derived from multiple base classes. This method delivers the QAudioSystemFactoryInterface base class aspect.\n\nUse this version if you have a const reference.", true, &_init_f_QAudioSystemPlugin_as_const_QAudioSystemFactoryInterface, &_call_f_QAudioSystemPlugin_as_const_QAudioSystemFactoryInterface);
  return methods;
}

gsi::Class<QObject> &qtdecl_QObject ();

qt_gsi::QtNativeClass<QAudioSystemPlugin> decl_QAudioSystemPlugin (qtdecl_QObject (), "QtMultimedia", "QAudioSystemPlugin_Native",
  methods_QAudioSystemPlugin (),
  "@hide\n@alias QAudioSystemPlugin");

GSI_QTMULTIMEDIA_PUBLIC gsi::Class<QAudioSystemPlugin> &qtdecl_QAudioSystemPlugin () { return decl_QAudioSystemPlugin; }

}


class QAudioSystemPlugin_Adaptor : public QAudioSystemPlugin, public qt_gsi::QtObjectBase
{
public:

  virtual ~QAudioSystemPlugin_Adaptor();

  //  [adaptor ctor] QAudioSystemPlugin::QAudioSystemPlugin(QObject *parent)
  QAudioSystemPlugin_Adaptor() : QAudioSystemPlugin()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [adaptor ctor] QAudioSystemPlugin::QAudioSystemPlugin(QObject *parent)
  QAudioSystemPlugin_Adaptor(QObject *parent) : QAudioSystemPlugin(parent)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [expose] bool QAudioSystemPlugin::isSignalConnected(const QMetaMethod &signal)
  bool fp_QAudioSystemPlugin_isSignalConnected_c2394 (const QMetaMethod &signal) const {
    return QAudioSystemPlugin::isSignalConnected(signal);
  }

  //  [expose] int QAudioSystemPlugin::receivers(const char *signal)
  int fp_QAudioSystemPlugin_receivers_c1731 (const char *signal) const {
    return QAudioSystemPlugin::receivers(signal);
  }

  //  [expose] QObject *QAudioSystemPlugin::sender()
  QObject * fp_QAudioSystemPlugin_sender_c0 () const {
    return QAudioSystemPlugin::sender();
  }

  //  [expose] int QAudioSystemPlugin::senderSignalIndex()
  int fp_QAudioSystemPlugin_senderSignalIndex_c0 () const {
    return QAudioSystemPlugin::senderSignalIndex();
  }

  //  [adaptor impl] QList<QByteArray> QAudioSystemPlugin::availableDevices(QAudio::Mode)
  QList<QByteArray> cbs_availableDevices_c1520_0(const qt_gsi::Converter<QAudio::Mode>::target_type & arg1) const
  {
    __SUPPRESS_UNUSED_WARNING (arg1);
    throw qt_gsi::AbstractMethodCalledException("availableDevices");
  }

  virtual QList<QByteArray> availableDevices(QAudio::Mode arg1) const
  {
    if (cb_availableDevices_c1520_0.can_issue()) {
      return cb_availableDevices_c1520_0.issue<QAudioSystemPlugin_Adaptor, QList<QByteArray>, const qt_gsi::Converter<QAudio::Mode>::target_type &>(&QAudioSystemPlugin_Adaptor::cbs_availableDevices_c1520_0, qt_gsi::CppToQtAdaptor<QAudio::Mode>(arg1));
    } else {
      throw qt_gsi::AbstractMethodCalledException("availableDevices");
    }
  }

  //  [adaptor impl] QAbstractAudioDeviceInfo *QAudioSystemPlugin::createDeviceInfo(const QByteArray &device, QAudio::Mode mode)
  QAbstractAudioDeviceInfo * cbs_createDeviceInfo_3721_0(const QByteArray &device, const qt_gsi::Converter<QAudio::Mode>::target_type & mode)
  {
    __SUPPRESS_UNUSED_WARNING (device);
    __SUPPRESS_UNUSED_WARNING (mode);
    throw qt_gsi::AbstractMethodCalledException("createDeviceInfo");
  }

  virtual QAbstractAudioDeviceInfo * createDeviceInfo(const QByteArray &device, QAudio::Mode mode)
  {
    if (cb_createDeviceInfo_3721_0.can_issue()) {
      return cb_createDeviceInfo_3721_0.issue<QAudioSystemPlugin_Adaptor, QAbstractAudioDeviceInfo *, const QByteArray &, const qt_gsi::Converter<QAudio::Mode>::target_type &>(&QAudioSystemPlugin_Adaptor::cbs_createDeviceInfo_3721_0, device, qt_gsi::CppToQtAdaptor<QAudio::Mode>(mode));
    } else {
      throw qt_gsi::AbstractMethodCalledException("createDeviceInfo");
    }
  }

  //  [adaptor impl] QAbstractAudioInput *QAudioSystemPlugin::createInput(const QByteArray &device)
  QAbstractAudioInput * cbs_createInput_2309_0(const QByteArray &device)
  {
    __SUPPRESS_UNUSED_WARNING (device);
    throw qt_gsi::AbstractMethodCalledException("createInput");
  }

  virtual QAbstractAudioInput * createInput(const QByteArray &device)
  {
    if (cb_createInput_2309_0.can_issue()) {
      return cb_createInput_2309_0.issue<QAudioSystemPlugin_Adaptor, QAbstractAudioInput *, const QByteArray &>(&QAudioSystemPlugin_Adaptor::cbs_createInput_2309_0, device);
    } else {
      throw qt_gsi::AbstractMethodCalledException("createInput");
    }
  }

  //  [adaptor impl] QAbstractAudioOutput *QAudioSystemPlugin::createOutput(const QByteArray &device)
  QAbstractAudioOutput * cbs_createOutput_2309_0(const QByteArray &device)
  {
    __SUPPRESS_UNUSED_WARNING (device);
    throw qt_gsi::AbstractMethodCalledException("createOutput");
  }

  virtual QAbstractAudioOutput * createOutput(const QByteArray &device)
  {
    if (cb_createOutput_2309_0.can_issue()) {
      return cb_createOutput_2309_0.issue<QAudioSystemPlugin_Adaptor, QAbstractAudioOutput *, const QByteArray &>(&QAudioSystemPlugin_Adaptor::cbs_createOutput_2309_0, device);
    } else {
      throw qt_gsi::AbstractMethodCalledException("createOutput");
    }
  }

  //  [adaptor impl] bool QAudioSystemPlugin::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QAudioSystemPlugin::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QAudioSystemPlugin_Adaptor, bool, QEvent *>(&QAudioSystemPlugin_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QAudioSystemPlugin::event(arg1);
    }
  }

  //  [adaptor impl] bool QAudioSystemPlugin::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QAudioSystemPlugin::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QAudioSystemPlugin_Adaptor, bool, QObject *, QEvent *>(&QAudioSystemPlugin_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QAudioSystemPlugin::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] void QAudioSystemPlugin::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QAudioSystemPlugin::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QAudioSystemPlugin_Adaptor, QChildEvent *>(&QAudioSystemPlugin_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QAudioSystemPlugin::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QAudioSystemPlugin::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QAudioSystemPlugin::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QAudioSystemPlugin_Adaptor, QEvent *>(&QAudioSystemPlugin_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QAudioSystemPlugin::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QAudioSystemPlugin::disconnectNotify(const QMetaMethod &signal)
  void cbs_disconnectNotify_2394_0(const QMetaMethod &signal)
  {
    QAudioSystemPlugin::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const QMetaMethod &signal)
  {
    if (cb_disconnectNotify_2394_0.can_issue()) {
      cb_disconnectNotify_2394_0.issue<QAudioSystemPlugin_Adaptor, const QMetaMethod &>(&QAudioSystemPlugin_Adaptor::cbs_disconnectNotify_2394_0, signal);
    } else {
      QAudioSystemPlugin::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QAudioSystemPlugin::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QAudioSystemPlugin::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QAudioSystemPlugin_Adaptor, QTimerEvent *>(&QAudioSystemPlugin_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QAudioSystemPlugin::timerEvent(arg1);
    }
  }

  gsi::Callback cb_availableDevices_c1520_0;
  gsi::Callback cb_createDeviceInfo_3721_0;
  gsi::Callback cb_createInput_2309_0;
  gsi::Callback cb_createOutput_2309_0;
  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_2394_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QAudioSystemPlugin_Adaptor::~QAudioSystemPlugin_Adaptor() { }

//  Constructor QAudioSystemPlugin::QAudioSystemPlugin(QObject *parent) (adaptor class)

static void _init_ctor_QAudioSystemPlugin_Adaptor_1302 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("parent", true, "0");
  decl->add_arg<QObject * > (argspec_0);
  decl->set_return_new<QAudioSystemPlugin_Adaptor> ();
}

static void _call_ctor_QAudioSystemPlugin_Adaptor_1302 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args ? gsi::arg_reader<QObject * >() (args, heap) : gsi::arg_maker<QObject * >() (0, heap);
  ret.write<QAudioSystemPlugin_Adaptor *> (new QAudioSystemPlugin_Adaptor (arg1));
}


// QList<QByteArray> QAudioSystemPlugin::availableDevices(QAudio::Mode)

static void _init_cbs_availableDevices_c1520_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<const qt_gsi::Converter<QAudio::Mode>::target_type & > (argspec_0);
  decl->set_return<QList<QByteArray> > ();
}

static void _call_cbs_availableDevices_c1520_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const qt_gsi::Converter<QAudio::Mode>::target_type & arg1 = args.read<const qt_gsi::Converter<QAudio::Mode>::target_type & > (heap);
  ret.write<QList<QByteArray> > ((QList<QByteArray>)((QAudioSystemPlugin_Adaptor *)cls)->cbs_availableDevices_c1520_0 (arg1));
}

static void _set_callback_cbs_availableDevices_c1520_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_availableDevices_c1520_0 = cb;
}


// void QAudioSystemPlugin::childEvent(QChildEvent *)

static void _init_cbs_childEvent_1701_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QChildEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_childEvent_1701_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QChildEvent *arg1 = args.read<QChildEvent * > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QAudioSystemPlugin_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}


// QAbstractAudioDeviceInfo *QAudioSystemPlugin::createDeviceInfo(const QByteArray &device, QAudio::Mode mode)

static void _init_cbs_createDeviceInfo_3721_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<const QByteArray & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("mode");
  decl->add_arg<const qt_gsi::Converter<QAudio::Mode>::target_type & > (argspec_1);
  decl->set_return<QAbstractAudioDeviceInfo * > ();
}

static void _call_cbs_createDeviceInfo_3721_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = args.read<const QByteArray & > (heap);
  const qt_gsi::Converter<QAudio::Mode>::target_type & arg2 = args.read<const qt_gsi::Converter<QAudio::Mode>::target_type & > (heap);
  ret.write<QAbstractAudioDeviceInfo * > ((QAbstractAudioDeviceInfo *)((QAudioSystemPlugin_Adaptor *)cls)->cbs_createDeviceInfo_3721_0 (arg1, arg2));
}

static void _set_callback_cbs_createDeviceInfo_3721_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_createDeviceInfo_3721_0 = cb;
}


// QAbstractAudioInput *QAudioSystemPlugin::createInput(const QByteArray &device)

static void _init_cbs_createInput_2309_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<const QByteArray & > (argspec_0);
  decl->set_return<QAbstractAudioInput * > ();
}

static void _call_cbs_createInput_2309_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = args.read<const QByteArray & > (heap);
  ret.write<QAbstractAudioInput * > ((QAbstractAudioInput *)((QAudioSystemPlugin_Adaptor *)cls)->cbs_createInput_2309_0 (arg1));
}

static void _set_callback_cbs_createInput_2309_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_createInput_2309_0 = cb;
}


// QAbstractAudioOutput *QAudioSystemPlugin::createOutput(const QByteArray &device)

static void _init_cbs_createOutput_2309_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("device");
  decl->add_arg<const QByteArray & > (argspec_0);
  decl->set_return<QAbstractAudioOutput * > ();
}

static void _call_cbs_createOutput_2309_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QByteArray &arg1 = args.read<const QByteArray & > (heap);
  ret.write<QAbstractAudioOutput * > ((QAbstractAudioOutput *)((QAudioSystemPlugin_Adaptor *)cls)->cbs_createOutput_2309_0 (arg1));
}

static void _set_callback_cbs_createOutput_2309_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_createOutput_2309_0 = cb;
}


// void QAudioSystemPlugin::customEvent(QEvent *)

static void _init_cbs_customEvent_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_customEvent_1217_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QEvent *arg1 = args.read<QEvent * > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QAudioSystemPlugin_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}


// void QAudioSystemPlugin::disconnectNotify(const QMetaMethod &signal)

static void _init_cbs_disconnectNotify_2394_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const QMetaMethod & > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_disconnectNotify_2394_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QMetaMethod &arg1 = args.read<const QMetaMethod & > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QAudioSystemPlugin_Adaptor *)cls)->cbs_disconnectNotify_2394_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_2394_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_disconnectNotify_2394_0 = cb;
}


// bool QAudioSystemPlugin::event(QEvent *)

static void _init_cbs_event_1217_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QEvent * > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_event_1217_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QEvent *arg1 = args.read<QEvent * > (heap);
  ret.write<bool > ((bool)((QAudioSystemPlugin_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_event_1217_0 = cb;
}


// bool QAudioSystemPlugin::eventFilter(QObject *, QEvent *)

static void _init_cbs_eventFilter_2411_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QObject * > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("arg2");
  decl->add_arg<QEvent * > (argspec_1);
  decl->set_return<bool > ();
}

static void _call_cbs_eventFilter_2411_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QObject *arg1 = args.read<QObject * > (heap);
  QEvent *arg2 = args.read<QEvent * > (heap);
  ret.write<bool > ((bool)((QAudioSystemPlugin_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}


// exposed bool QAudioSystemPlugin::isSignalConnected(const QMetaMethod &signal)

static void _init_fp_isSignalConnected_c2394 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const QMetaMethod & > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_fp_isSignalConnected_c2394 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QMetaMethod &arg1 = gsi::arg_reader<const QMetaMethod & >() (args, heap);
  ret.write<bool > ((bool)((QAudioSystemPlugin_Adaptor *)cls)->fp_QAudioSystemPlugin_isSignalConnected_c2394 (arg1));
}


// exposed int QAudioSystemPlugin::receivers(const char *signal)

static void _init_fp_receivers_c1731 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("signal");
  decl->add_arg<const char * > (argspec_0);
  decl->set_return<int > ();
}

static void _call_fp_receivers_c1731 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const char *arg1 = gsi::arg_reader<const char * >() (args, heap);
  ret.write<int > ((int)((QAudioSystemPlugin_Adaptor *)cls)->fp_QAudioSystemPlugin_receivers_c1731 (arg1));
}


// exposed QObject *QAudioSystemPlugin::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QObject * > ((QObject *)((QAudioSystemPlugin_Adaptor *)cls)->fp_QAudioSystemPlugin_sender_c0 ());
}


// exposed int QAudioSystemPlugin::senderSignalIndex()

static void _init_fp_senderSignalIndex_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_fp_senderSignalIndex_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<int > ((int)((QAudioSystemPlugin_Adaptor *)cls)->fp_QAudioSystemPlugin_senderSignalIndex_c0 ());
}


// void QAudioSystemPlugin::timerEvent(QTimerEvent *)

static void _init_cbs_timerEvent_1730_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<QTimerEvent * > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_timerEvent_1730_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QTimerEvent *arg1 = args.read<QTimerEvent * > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QAudioSystemPlugin_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QAudioSystemPlugin_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}


namespace gsi
{

gsi::Class<QAudioSystemPlugin> &qtdecl_QAudioSystemPlugin ();

static gsi::Methods methods_QAudioSystemPlugin_Adaptor () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QAudioSystemPlugin::QAudioSystemPlugin(QObject *parent)\nThis method creates an object of class QAudioSystemPlugin.", &_init_ctor_QAudioSystemPlugin_Adaptor_1302, &_call_ctor_QAudioSystemPlugin_Adaptor_1302);
  methods += new qt_gsi::GenericMethod ("availableDevices", "@hide", true, &_init_cbs_availableDevices_c1520_0, &_call_cbs_availableDevices_c1520_0);
  methods += new qt_gsi::GenericMethod ("availableDevices", "@brief Virtual method QList<QByteArray> QAudioSystemPlugin::availableDevices(QAudio::Mode)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_availableDevices_c1520_0, &_call_cbs_availableDevices_c1520_0, &_set_callback_cbs_availableDevices_c1520_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QAudioSystemPlugin::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("createDeviceInfo", "@hide", false, &_init_cbs_createDeviceInfo_3721_0, &_call_cbs_createDeviceInfo_3721_0);
  methods += new qt_gsi::GenericMethod ("createDeviceInfo", "@brief Virtual method QAbstractAudioDeviceInfo *QAudioSystemPlugin::createDeviceInfo(const QByteArray &device, QAudio::Mode mode)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_createDeviceInfo_3721_0, &_call_cbs_createDeviceInfo_3721_0, &_set_callback_cbs_createDeviceInfo_3721_0);
  methods += new qt_gsi::GenericMethod ("createInput", "@hide", false, &_init_cbs_createInput_2309_0, &_call_cbs_createInput_2309_0);
  methods += new qt_gsi::GenericMethod ("createInput", "@brief Virtual method QAbstractAudioInput *QAudioSystemPlugin::createInput(const QByteArray &device)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_createInput_2309_0, &_call_cbs_createInput_2309_0, &_set_callback_cbs_createInput_2309_0);
  methods += new qt_gsi::GenericMethod ("createOutput", "@hide", false, &_init_cbs_createOutput_2309_0, &_call_cbs_createOutput_2309_0);
  methods += new qt_gsi::GenericMethod ("createOutput", "@brief Virtual method QAbstractAudioOutput *QAudioSystemPlugin::createOutput(const QByteArray &device)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_createOutput_2309_0, &_call_cbs_createOutput_2309_0, &_set_callback_cbs_createOutput_2309_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QAudioSystemPlugin::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QAudioSystemPlugin::disconnectNotify(const QMetaMethod &signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0, &_set_callback_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QAudioSystemPlugin::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QAudioSystemPlugin::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("*isSignalConnected", "@brief Method bool QAudioSystemPlugin::isSignalConnected(const QMetaMethod &signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_isSignalConnected_c2394, &_call_fp_isSignalConnected_c2394);
  methods += new qt_gsi::GenericMethod ("*receivers", "@brief Method int QAudioSystemPlugin::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
  methods += new qt_gsi::GenericMethod ("*sender", "@brief Method QObject *QAudioSystemPlugin::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
  methods += new qt_gsi::GenericMethod ("*senderSignalIndex", "@brief Method int QAudioSystemPlugin::senderSignalIndex()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_senderSignalIndex_c0, &_call_fp_senderSignalIndex_c0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QAudioSystemPlugin::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
  return methods;
}

gsi::Class<QAudioSystemPlugin_Adaptor> decl_QAudioSystemPlugin_Adaptor (qtdecl_QAudioSystemPlugin (), "QtMultimedia", "QAudioSystemPlugin",
  methods_QAudioSystemPlugin_Adaptor (),
  "@qt\n@brief Binding of QAudioSystemPlugin");

}

