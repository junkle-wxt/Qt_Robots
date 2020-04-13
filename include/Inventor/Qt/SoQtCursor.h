#ifndef SOQT_CURSOR_H
#define SOQT_CURSOR_H

// src\Inventor\Qt\SoQtCursor.h.  Generated from SoGuiCursor.h.in by configure.

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

#include <Inventor/SbLinear.h>
#include <Inventor/Qt/SoQtBasic.h>

class SOQT_DLL_API SoQtCursor {
public:
  static void initClass(void);

  struct CustomCursor {
    SbVec2s dim;
    SbVec2s hotspot;
    unsigned char * bitmap;
    unsigned char * mask;
  };


  // FIXME: add more default shapes. 20011119 pederb.
  enum Shape {
    CUSTOM_BITMAP = -1,
    DEFAULT = 0,
    BUSY,
    CROSSHAIR,
    UPARROW
  };
  
  SoQtCursor(void);
  SoQtCursor(const Shape shape);
  SoQtCursor(const CustomCursor * cc);
  SoQtCursor(const SoQtCursor & cursor);
  ~SoQtCursor();

  SoQtCursor & operator=(const SoQtCursor & c);

  Shape getShape(void) const;
  void setShape(const Shape shape);

  const CustomCursor & getCustomCursor(void) const;

  static const SoQtCursor & getZoomCursor(void);
  static const SoQtCursor & getPanCursor(void);
  static const SoQtCursor & getRotateCursor(void);
  static const SoQtCursor & getBlankCursor(void);
  
private:
  void commonConstructor(const Shape shape, const CustomCursor * cc);

  Shape shape;
  CustomCursor * cc;
};

#endif // ! SOQT_CURSOR_H
