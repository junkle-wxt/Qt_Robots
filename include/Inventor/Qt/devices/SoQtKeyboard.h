#ifndef SOQT_KEYBOARD_H
#define SOQT_KEYBOARD_H

// src\Inventor\Qt\devices\SoQtKeyboard.h.  Generated from SoGuiKeyboard.h.in by configure.

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) by Kongsberg Oil & Gas Technologies.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Kongsberg Oil & Gas Technologies
 *  about acquiring a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg Oil & Gas Technologies, Bygdoy Alle 5, 0257 Oslo, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#include <Inventor/Qt/devices/SoQtDevice.h>

class SoKeyboardEvent;

// *************************************************************************

#define SO_QT_ALL_KEYBOARD_EVENTS SoQtKeyboard::ALL

class SOQT_DLL_API SoQtKeyboard : public SoQtDevice {
  SOQT_OBJECT_HEADER(SoQtKeyboard, SoQtDevice);

public:
  enum Events {
    KEY_PRESS = 0x01,
    KEY_RELEASE = 0x02,
    ALL_EVENTS = KEY_PRESS | KEY_RELEASE
  };

  SoQtKeyboard(int eventmask = ALL_EVENTS);
  virtual ~SoQtKeyboard(void);

  virtual void enable(QWidget * widget, SoQtEventHandler * handler, void * closure);
  virtual void disable(QWidget * widget, SoQtEventHandler * handler, void * closure);

  virtual const SoEvent * translateEvent(QEvent * event);

private:
  class SoQtKeyboardP * pimpl;
  friend class SoQtKeyboardP;
  friend class SoGuiKeyboardP;
};

// *************************************************************************

#endif // ! SOQT_KEYBOARD_H
