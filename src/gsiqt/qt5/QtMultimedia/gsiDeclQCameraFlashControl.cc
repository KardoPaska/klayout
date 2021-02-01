
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
*  @file gsiDeclQCameraFlashControl.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include <QCameraFlashControl>
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
// class QCameraFlashControl

//  get static meta object

static void _init_smo (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return<const QMetaObject &> ();
}

static void _call_smo (const qt_gsi::GenericStaticMethod *, gsi::SerialArgs &, gsi::SerialArgs &ret) 
{
  ret.write<const QMetaObject &> (QCameraFlashControl::staticMetaObject);
}


// QFlags<QCameraExposure::FlashMode> QCameraFlashControl::flashMode()


static void _init_f_flashMode_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QFlags<QCameraExposure::FlashMode> > ();
}

static void _call_f_flashMode_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QFlags<QCameraExposure::FlashMode> > ((QFlags<QCameraExposure::FlashMode>)((QCameraFlashControl *)cls)->flashMode ());
}


// void QCameraFlashControl::flashReady(bool)


static void _init_f_flashReady_864 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("arg1");
  decl->add_arg<bool > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_flashReady_864 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  bool arg1 = gsi::arg_reader<bool >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QCameraFlashControl *)cls)->flashReady (arg1);
}


// bool QCameraFlashControl::isFlashModeSupported(QFlags<QCameraExposure::FlashMode> mode)


static void _init_f_isFlashModeSupported_c3656 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("mode");
  decl->add_arg<QFlags<QCameraExposure::FlashMode> > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_f_isFlashModeSupported_c3656 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QFlags<QCameraExposure::FlashMode> arg1 = gsi::arg_reader<QFlags<QCameraExposure::FlashMode> >() (args, heap);
  ret.write<bool > ((bool)((QCameraFlashControl *)cls)->isFlashModeSupported (arg1));
}


// bool QCameraFlashControl::isFlashReady()


static void _init_f_isFlashReady_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_f_isFlashReady_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<bool > ((bool)((QCameraFlashControl *)cls)->isFlashReady ());
}


// void QCameraFlashControl::setFlashMode(QFlags<QCameraExposure::FlashMode> mode)


static void _init_f_setFlashMode_3656 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("mode");
  decl->add_arg<QFlags<QCameraExposure::FlashMode> > (argspec_0);
  decl->set_return<void > ();
}

static void _call_f_setFlashMode_3656 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QFlags<QCameraExposure::FlashMode> arg1 = gsi::arg_reader<QFlags<QCameraExposure::FlashMode> >() (args, heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QCameraFlashControl *)cls)->setFlashMode (arg1);
}


// static QString QCameraFlashControl::tr(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QCameraFlashControl::tr (arg1, arg2, arg3));
}


// static QString QCameraFlashControl::trUtf8(const char *s, const char *c, int n)


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
  ret.write<QString > ((QString)QCameraFlashControl::trUtf8 (arg1, arg2, arg3));
}


namespace gsi
{

static gsi::Methods methods_QCameraFlashControl () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("staticMetaObject", "@brief Obtains the static MetaObject for this class.", &_init_smo, &_call_smo);
  methods += new qt_gsi::GenericMethod (":flashMode", "@brief Method QFlags<QCameraExposure::FlashMode> QCameraFlashControl::flashMode()\n", true, &_init_f_flashMode_c0, &_call_f_flashMode_c0);
  methods += new qt_gsi::GenericMethod ("flashReady", "@brief Method void QCameraFlashControl::flashReady(bool)\n", false, &_init_f_flashReady_864, &_call_f_flashReady_864);
  methods += new qt_gsi::GenericMethod ("isFlashModeSupported?", "@brief Method bool QCameraFlashControl::isFlashModeSupported(QFlags<QCameraExposure::FlashMode> mode)\n", true, &_init_f_isFlashModeSupported_c3656, &_call_f_isFlashModeSupported_c3656);
  methods += new qt_gsi::GenericMethod ("isFlashReady?", "@brief Method bool QCameraFlashControl::isFlashReady()\n", true, &_init_f_isFlashReady_c0, &_call_f_isFlashReady_c0);
  methods += new qt_gsi::GenericMethod ("setFlashMode|flashMode=", "@brief Method void QCameraFlashControl::setFlashMode(QFlags<QCameraExposure::FlashMode> mode)\n", false, &_init_f_setFlashMode_3656, &_call_f_setFlashMode_3656);
  methods += new qt_gsi::GenericStaticMethod ("tr", "@brief Static method QString QCameraFlashControl::tr(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_tr_4013, &_call_f_tr_4013);
  methods += new qt_gsi::GenericStaticMethod ("trUtf8", "@brief Static method QString QCameraFlashControl::trUtf8(const char *s, const char *c, int n)\nThis method is static and can be called without an instance.", &_init_f_trUtf8_4013, &_call_f_trUtf8_4013);
  return methods;
}

gsi::Class<QMediaControl> &qtdecl_QMediaControl ();

qt_gsi::QtNativeClass<QCameraFlashControl> decl_QCameraFlashControl (qtdecl_QMediaControl (), "QtMultimedia", "QCameraFlashControl_Native",
  methods_QCameraFlashControl (),
  "@hide\n@alias QCameraFlashControl");

GSI_QTMULTIMEDIA_PUBLIC gsi::Class<QCameraFlashControl> &qtdecl_QCameraFlashControl () { return decl_QCameraFlashControl; }

}


class QCameraFlashControl_Adaptor : public QCameraFlashControl, public qt_gsi::QtObjectBase
{
public:

  virtual ~QCameraFlashControl_Adaptor();

  //  [adaptor ctor] QCameraFlashControl::QCameraFlashControl()
  QCameraFlashControl_Adaptor() : QCameraFlashControl()
  {
    qt_gsi::QtObjectBase::init (this);
  }

  //  [expose] bool QCameraFlashControl::isSignalConnected(const QMetaMethod &signal)
  bool fp_QCameraFlashControl_isSignalConnected_c2394 (const QMetaMethod &signal) const {
    return QCameraFlashControl::isSignalConnected(signal);
  }

  //  [expose] int QCameraFlashControl::receivers(const char *signal)
  int fp_QCameraFlashControl_receivers_c1731 (const char *signal) const {
    return QCameraFlashControl::receivers(signal);
  }

  //  [expose] QObject *QCameraFlashControl::sender()
  QObject * fp_QCameraFlashControl_sender_c0 () const {
    return QCameraFlashControl::sender();
  }

  //  [expose] int QCameraFlashControl::senderSignalIndex()
  int fp_QCameraFlashControl_senderSignalIndex_c0 () const {
    return QCameraFlashControl::senderSignalIndex();
  }

  //  [adaptor impl] bool QCameraFlashControl::event(QEvent *)
  bool cbs_event_1217_0(QEvent *arg1)
  {
    return QCameraFlashControl::event(arg1);
  }

  virtual bool event(QEvent *arg1)
  {
    if (cb_event_1217_0.can_issue()) {
      return cb_event_1217_0.issue<QCameraFlashControl_Adaptor, bool, QEvent *>(&QCameraFlashControl_Adaptor::cbs_event_1217_0, arg1);
    } else {
      return QCameraFlashControl::event(arg1);
    }
  }

  //  [adaptor impl] bool QCameraFlashControl::eventFilter(QObject *, QEvent *)
  bool cbs_eventFilter_2411_0(QObject *arg1, QEvent *arg2)
  {
    return QCameraFlashControl::eventFilter(arg1, arg2);
  }

  virtual bool eventFilter(QObject *arg1, QEvent *arg2)
  {
    if (cb_eventFilter_2411_0.can_issue()) {
      return cb_eventFilter_2411_0.issue<QCameraFlashControl_Adaptor, bool, QObject *, QEvent *>(&QCameraFlashControl_Adaptor::cbs_eventFilter_2411_0, arg1, arg2);
    } else {
      return QCameraFlashControl::eventFilter(arg1, arg2);
    }
  }

  //  [adaptor impl] QFlags<QCameraExposure::FlashMode> QCameraFlashControl::flashMode()
  QFlags<QCameraExposure::FlashMode> cbs_flashMode_c0_0() const
  {
    throw qt_gsi::AbstractMethodCalledException("flashMode");
  }

  virtual QFlags<QCameraExposure::FlashMode> flashMode() const
  {
    if (cb_flashMode_c0_0.can_issue()) {
      return cb_flashMode_c0_0.issue<QCameraFlashControl_Adaptor, QFlags<QCameraExposure::FlashMode> >(&QCameraFlashControl_Adaptor::cbs_flashMode_c0_0);
    } else {
      throw qt_gsi::AbstractMethodCalledException("flashMode");
    }
  }

  //  [adaptor impl] bool QCameraFlashControl::isFlashModeSupported(QFlags<QCameraExposure::FlashMode> mode)
  bool cbs_isFlashModeSupported_c3656_0(QFlags<QCameraExposure::FlashMode> mode) const
  {
    __SUPPRESS_UNUSED_WARNING (mode);
    throw qt_gsi::AbstractMethodCalledException("isFlashModeSupported");
  }

  virtual bool isFlashModeSupported(QFlags<QCameraExposure::FlashMode> mode) const
  {
    if (cb_isFlashModeSupported_c3656_0.can_issue()) {
      return cb_isFlashModeSupported_c3656_0.issue<QCameraFlashControl_Adaptor, bool, QFlags<QCameraExposure::FlashMode> >(&QCameraFlashControl_Adaptor::cbs_isFlashModeSupported_c3656_0, mode);
    } else {
      throw qt_gsi::AbstractMethodCalledException("isFlashModeSupported");
    }
  }

  //  [adaptor impl] bool QCameraFlashControl::isFlashReady()
  bool cbs_isFlashReady_c0_0() const
  {
    throw qt_gsi::AbstractMethodCalledException("isFlashReady");
  }

  virtual bool isFlashReady() const
  {
    if (cb_isFlashReady_c0_0.can_issue()) {
      return cb_isFlashReady_c0_0.issue<QCameraFlashControl_Adaptor, bool>(&QCameraFlashControl_Adaptor::cbs_isFlashReady_c0_0);
    } else {
      throw qt_gsi::AbstractMethodCalledException("isFlashReady");
    }
  }

  //  [adaptor impl] void QCameraFlashControl::setFlashMode(QFlags<QCameraExposure::FlashMode> mode)
  void cbs_setFlashMode_3656_0(QFlags<QCameraExposure::FlashMode> mode)
  {
    __SUPPRESS_UNUSED_WARNING (mode);
    throw qt_gsi::AbstractMethodCalledException("setFlashMode");
  }

  virtual void setFlashMode(QFlags<QCameraExposure::FlashMode> mode)
  {
    if (cb_setFlashMode_3656_0.can_issue()) {
      cb_setFlashMode_3656_0.issue<QCameraFlashControl_Adaptor, QFlags<QCameraExposure::FlashMode> >(&QCameraFlashControl_Adaptor::cbs_setFlashMode_3656_0, mode);
    } else {
      throw qt_gsi::AbstractMethodCalledException("setFlashMode");
    }
  }

  //  [adaptor impl] void QCameraFlashControl::childEvent(QChildEvent *)
  void cbs_childEvent_1701_0(QChildEvent *arg1)
  {
    QCameraFlashControl::childEvent(arg1);
  }

  virtual void childEvent(QChildEvent *arg1)
  {
    if (cb_childEvent_1701_0.can_issue()) {
      cb_childEvent_1701_0.issue<QCameraFlashControl_Adaptor, QChildEvent *>(&QCameraFlashControl_Adaptor::cbs_childEvent_1701_0, arg1);
    } else {
      QCameraFlashControl::childEvent(arg1);
    }
  }

  //  [adaptor impl] void QCameraFlashControl::customEvent(QEvent *)
  void cbs_customEvent_1217_0(QEvent *arg1)
  {
    QCameraFlashControl::customEvent(arg1);
  }

  virtual void customEvent(QEvent *arg1)
  {
    if (cb_customEvent_1217_0.can_issue()) {
      cb_customEvent_1217_0.issue<QCameraFlashControl_Adaptor, QEvent *>(&QCameraFlashControl_Adaptor::cbs_customEvent_1217_0, arg1);
    } else {
      QCameraFlashControl::customEvent(arg1);
    }
  }

  //  [adaptor impl] void QCameraFlashControl::disconnectNotify(const QMetaMethod &signal)
  void cbs_disconnectNotify_2394_0(const QMetaMethod &signal)
  {
    QCameraFlashControl::disconnectNotify(signal);
  }

  virtual void disconnectNotify(const QMetaMethod &signal)
  {
    if (cb_disconnectNotify_2394_0.can_issue()) {
      cb_disconnectNotify_2394_0.issue<QCameraFlashControl_Adaptor, const QMetaMethod &>(&QCameraFlashControl_Adaptor::cbs_disconnectNotify_2394_0, signal);
    } else {
      QCameraFlashControl::disconnectNotify(signal);
    }
  }

  //  [adaptor impl] void QCameraFlashControl::timerEvent(QTimerEvent *)
  void cbs_timerEvent_1730_0(QTimerEvent *arg1)
  {
    QCameraFlashControl::timerEvent(arg1);
  }

  virtual void timerEvent(QTimerEvent *arg1)
  {
    if (cb_timerEvent_1730_0.can_issue()) {
      cb_timerEvent_1730_0.issue<QCameraFlashControl_Adaptor, QTimerEvent *>(&QCameraFlashControl_Adaptor::cbs_timerEvent_1730_0, arg1);
    } else {
      QCameraFlashControl::timerEvent(arg1);
    }
  }

  gsi::Callback cb_event_1217_0;
  gsi::Callback cb_eventFilter_2411_0;
  gsi::Callback cb_flashMode_c0_0;
  gsi::Callback cb_isFlashModeSupported_c3656_0;
  gsi::Callback cb_isFlashReady_c0_0;
  gsi::Callback cb_setFlashMode_3656_0;
  gsi::Callback cb_childEvent_1701_0;
  gsi::Callback cb_customEvent_1217_0;
  gsi::Callback cb_disconnectNotify_2394_0;
  gsi::Callback cb_timerEvent_1730_0;
};

QCameraFlashControl_Adaptor::~QCameraFlashControl_Adaptor() { }

//  Constructor QCameraFlashControl::QCameraFlashControl() (adaptor class)

static void _init_ctor_QCameraFlashControl_Adaptor_0 (qt_gsi::GenericStaticMethod *decl)
{
  decl->set_return_new<QCameraFlashControl_Adaptor> ();
}

static void _call_ctor_QCameraFlashControl_Adaptor_0 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QCameraFlashControl_Adaptor *> (new QCameraFlashControl_Adaptor ());
}


// void QCameraFlashControl::childEvent(QChildEvent *)

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
  ((QCameraFlashControl_Adaptor *)cls)->cbs_childEvent_1701_0 (arg1);
}

static void _set_callback_cbs_childEvent_1701_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_childEvent_1701_0 = cb;
}


// void QCameraFlashControl::customEvent(QEvent *)

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
  ((QCameraFlashControl_Adaptor *)cls)->cbs_customEvent_1217_0 (arg1);
}

static void _set_callback_cbs_customEvent_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_customEvent_1217_0 = cb;
}


// void QCameraFlashControl::disconnectNotify(const QMetaMethod &signal)

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
  ((QCameraFlashControl_Adaptor *)cls)->cbs_disconnectNotify_2394_0 (arg1);
}

static void _set_callback_cbs_disconnectNotify_2394_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_disconnectNotify_2394_0 = cb;
}


// bool QCameraFlashControl::event(QEvent *)

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
  ret.write<bool > ((bool)((QCameraFlashControl_Adaptor *)cls)->cbs_event_1217_0 (arg1));
}

static void _set_callback_cbs_event_1217_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_event_1217_0 = cb;
}


// bool QCameraFlashControl::eventFilter(QObject *, QEvent *)

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
  ret.write<bool > ((bool)((QCameraFlashControl_Adaptor *)cls)->cbs_eventFilter_2411_0 (arg1, arg2));
}

static void _set_callback_cbs_eventFilter_2411_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_eventFilter_2411_0 = cb;
}


// QFlags<QCameraExposure::FlashMode> QCameraFlashControl::flashMode()

static void _init_cbs_flashMode_c0_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QFlags<QCameraExposure::FlashMode> > ();
}

static void _call_cbs_flashMode_c0_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QFlags<QCameraExposure::FlashMode> > ((QFlags<QCameraExposure::FlashMode>)((QCameraFlashControl_Adaptor *)cls)->cbs_flashMode_c0_0 ());
}

static void _set_callback_cbs_flashMode_c0_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_flashMode_c0_0 = cb;
}


// bool QCameraFlashControl::isFlashModeSupported(QFlags<QCameraExposure::FlashMode> mode)

static void _init_cbs_isFlashModeSupported_c3656_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("mode");
  decl->add_arg<QFlags<QCameraExposure::FlashMode> > (argspec_0);
  decl->set_return<bool > ();
}

static void _call_cbs_isFlashModeSupported_c3656_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QFlags<QCameraExposure::FlashMode> arg1 = args.read<QFlags<QCameraExposure::FlashMode> > (heap);
  ret.write<bool > ((bool)((QCameraFlashControl_Adaptor *)cls)->cbs_isFlashModeSupported_c3656_0 (arg1));
}

static void _set_callback_cbs_isFlashModeSupported_c3656_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_isFlashModeSupported_c3656_0 = cb;
}


// bool QCameraFlashControl::isFlashReady()

static void _init_cbs_isFlashReady_c0_0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<bool > ();
}

static void _call_cbs_isFlashReady_c0_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<bool > ((bool)((QCameraFlashControl_Adaptor *)cls)->cbs_isFlashReady_c0_0 ());
}

static void _set_callback_cbs_isFlashReady_c0_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_isFlashReady_c0_0 = cb;
}


// exposed bool QCameraFlashControl::isSignalConnected(const QMetaMethod &signal)

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
  ret.write<bool > ((bool)((QCameraFlashControl_Adaptor *)cls)->fp_QCameraFlashControl_isSignalConnected_c2394 (arg1));
}


// exposed int QCameraFlashControl::receivers(const char *signal)

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
  ret.write<int > ((int)((QCameraFlashControl_Adaptor *)cls)->fp_QCameraFlashControl_receivers_c1731 (arg1));
}


// exposed QObject *QCameraFlashControl::sender()

static void _init_fp_sender_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<QObject * > ();
}

static void _call_fp_sender_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<QObject * > ((QObject *)((QCameraFlashControl_Adaptor *)cls)->fp_QCameraFlashControl_sender_c0 ());
}


// exposed int QCameraFlashControl::senderSignalIndex()

static void _init_fp_senderSignalIndex_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<int > ();
}

static void _call_fp_senderSignalIndex_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<int > ((int)((QCameraFlashControl_Adaptor *)cls)->fp_QCameraFlashControl_senderSignalIndex_c0 ());
}


// void QCameraFlashControl::setFlashMode(QFlags<QCameraExposure::FlashMode> mode)

static void _init_cbs_setFlashMode_3656_0 (qt_gsi::GenericMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("mode");
  decl->add_arg<QFlags<QCameraExposure::FlashMode> > (argspec_0);
  decl->set_return<void > ();
}

static void _call_cbs_setFlashMode_3656_0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  QFlags<QCameraExposure::FlashMode> arg1 = args.read<QFlags<QCameraExposure::FlashMode> > (heap);
  __SUPPRESS_UNUSED_WARNING(ret);
  ((QCameraFlashControl_Adaptor *)cls)->cbs_setFlashMode_3656_0 (arg1);
}

static void _set_callback_cbs_setFlashMode_3656_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_setFlashMode_3656_0 = cb;
}


// void QCameraFlashControl::timerEvent(QTimerEvent *)

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
  ((QCameraFlashControl_Adaptor *)cls)->cbs_timerEvent_1730_0 (arg1);
}

static void _set_callback_cbs_timerEvent_1730_0 (void *cls, const gsi::Callback &cb)
{
  ((QCameraFlashControl_Adaptor *)cls)->cb_timerEvent_1730_0 = cb;
}


namespace gsi
{

gsi::Class<QCameraFlashControl> &qtdecl_QCameraFlashControl ();

static gsi::Methods methods_QCameraFlashControl_Adaptor () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QCameraFlashControl::QCameraFlashControl()\nThis method creates an object of class QCameraFlashControl.", &_init_ctor_QCameraFlashControl_Adaptor_0, &_call_ctor_QCameraFlashControl_Adaptor_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@hide", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*childEvent", "@brief Virtual method void QCameraFlashControl::childEvent(QChildEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_childEvent_1701_0, &_call_cbs_childEvent_1701_0, &_set_callback_cbs_childEvent_1701_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@hide", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("*customEvent", "@brief Virtual method void QCameraFlashControl::customEvent(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_customEvent_1217_0, &_call_cbs_customEvent_1217_0, &_set_callback_cbs_customEvent_1217_0);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@hide", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("*disconnectNotify", "@brief Virtual method void QCameraFlashControl::disconnectNotify(const QMetaMethod &signal)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_disconnectNotify_2394_0, &_call_cbs_disconnectNotify_2394_0, &_set_callback_cbs_disconnectNotify_2394_0);
  methods += new qt_gsi::GenericMethod ("event", "@hide", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("event", "@brief Virtual method bool QCameraFlashControl::event(QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_event_1217_0, &_call_cbs_event_1217_0, &_set_callback_cbs_event_1217_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@hide", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("eventFilter", "@brief Virtual method bool QCameraFlashControl::eventFilter(QObject *, QEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_eventFilter_2411_0, &_call_cbs_eventFilter_2411_0, &_set_callback_cbs_eventFilter_2411_0);
  methods += new qt_gsi::GenericMethod ("flashMode", "@hide", true, &_init_cbs_flashMode_c0_0, &_call_cbs_flashMode_c0_0);
  methods += new qt_gsi::GenericMethod ("flashMode", "@brief Virtual method QFlags<QCameraExposure::FlashMode> QCameraFlashControl::flashMode()\nThis method can be reimplemented in a derived class.", true, &_init_cbs_flashMode_c0_0, &_call_cbs_flashMode_c0_0, &_set_callback_cbs_flashMode_c0_0);
  methods += new qt_gsi::GenericMethod ("isFlashModeSupported", "@hide", true, &_init_cbs_isFlashModeSupported_c3656_0, &_call_cbs_isFlashModeSupported_c3656_0);
  methods += new qt_gsi::GenericMethod ("isFlashModeSupported", "@brief Virtual method bool QCameraFlashControl::isFlashModeSupported(QFlags<QCameraExposure::FlashMode> mode)\nThis method can be reimplemented in a derived class.", true, &_init_cbs_isFlashModeSupported_c3656_0, &_call_cbs_isFlashModeSupported_c3656_0, &_set_callback_cbs_isFlashModeSupported_c3656_0);
  methods += new qt_gsi::GenericMethod ("isFlashReady", "@hide", true, &_init_cbs_isFlashReady_c0_0, &_call_cbs_isFlashReady_c0_0);
  methods += new qt_gsi::GenericMethod ("isFlashReady", "@brief Virtual method bool QCameraFlashControl::isFlashReady()\nThis method can be reimplemented in a derived class.", true, &_init_cbs_isFlashReady_c0_0, &_call_cbs_isFlashReady_c0_0, &_set_callback_cbs_isFlashReady_c0_0);
  methods += new qt_gsi::GenericMethod ("*isSignalConnected", "@brief Method bool QCameraFlashControl::isSignalConnected(const QMetaMethod &signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_isSignalConnected_c2394, &_call_fp_isSignalConnected_c2394);
  methods += new qt_gsi::GenericMethod ("*receivers", "@brief Method int QCameraFlashControl::receivers(const char *signal)\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_receivers_c1731, &_call_fp_receivers_c1731);
  methods += new qt_gsi::GenericMethod ("*sender", "@brief Method QObject *QCameraFlashControl::sender()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_sender_c0, &_call_fp_sender_c0);
  methods += new qt_gsi::GenericMethod ("*senderSignalIndex", "@brief Method int QCameraFlashControl::senderSignalIndex()\nThis method is protected and can only be called from inside a derived class.", true, &_init_fp_senderSignalIndex_c0, &_call_fp_senderSignalIndex_c0);
  methods += new qt_gsi::GenericMethod ("setFlashMode", "@hide", false, &_init_cbs_setFlashMode_3656_0, &_call_cbs_setFlashMode_3656_0);
  methods += new qt_gsi::GenericMethod ("setFlashMode", "@brief Virtual method void QCameraFlashControl::setFlashMode(QFlags<QCameraExposure::FlashMode> mode)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_setFlashMode_3656_0, &_call_cbs_setFlashMode_3656_0, &_set_callback_cbs_setFlashMode_3656_0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@hide", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0);
  methods += new qt_gsi::GenericMethod ("*timerEvent", "@brief Virtual method void QCameraFlashControl::timerEvent(QTimerEvent *)\nThis method can be reimplemented in a derived class.", false, &_init_cbs_timerEvent_1730_0, &_call_cbs_timerEvent_1730_0, &_set_callback_cbs_timerEvent_1730_0);
  return methods;
}

gsi::Class<QCameraFlashControl_Adaptor> decl_QCameraFlashControl_Adaptor (qtdecl_QCameraFlashControl (), "QtMultimedia", "QCameraFlashControl",
  methods_QCameraFlashControl_Adaptor (),
  "@qt\n@brief Binding of QCameraFlashControl");

}

