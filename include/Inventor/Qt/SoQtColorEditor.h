#ifndef COIN_SOQTCOLOREDITOR_H
#define COIN_SOQTCOLOREDITOR_H

// src\Inventor\Qt\SoQtColorEditor.h.  Generated from SoGuiColorEditor.h.in by configure.

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

#include <Inventor/Qt/nodes/SoGuiColorEditor.h>
#include <Inventor/Qt/SoQtRenderArea.h>

typedef void SoQtColorEditorCB(void * closure, const SbColor * color);
        
class SbColor;
class SoSFColor;
class SoMFColor;
class SoMFUInt32;

class SoQtColorEditor : public SoQtRenderArea {
  SOQT_OBJECT_HEADER(SoQtColorEditor, SoQtRenderArea);

public:
  SoQtColorEditor(QWidget * parent = NULL, const char * name = NULL, SbBool embed = TRUE);
  ~SoQtColorEditor(void);

  enum Sliders {
    NONE = SoGuiColorEditor::NONE, 
    INTENSITY = SoGuiColorEditor::INTENSITY,
    RGB = SoGuiColorEditor::RGB, 
    HSV = SoGuiColorEditor::HSV, 
    RGB_V = SoGuiColorEditor::RGB_V, 
    RGB_HSV = SoGuiColorEditor::RGB_HSV
  };
  
  enum UpdateFrequency {
    CONTINUOUS = SoGuiColorEditor::CONTINUOUS,
    AFTER_ACCEPT = SoGuiColorEditor::AFTER_ACCEPT
  };
  
  void attach(SoSFColor * color, SoBase * node = NULL);
  void attach(SoMFColor * color, int idx = 0, SoBase * node = NULL);
  void attach(SoMFUInt32 * color, int idx = 0, SoBase * node = NULL);
  void detach(void);
  SbBool isAttached(void) const;
  
  void addColorChangedCallback(SoQtColorEditorCB * cb, void * closure = NULL);
  void removeColorChangedCallback(SoQtColorEditorCB * cb, void * closure = NULL);
  
  void setColor(const SbColor & color);
  const SbColor & getColor(void) const;
  
  void setWYSIWYG(SbBool enable);
  SbBool isWYSIWYG(void) const;
  
  void setCurrentSliders(Sliders which);
  Sliders getCurrentSliders(void) const;
  
  void setUpdateFrequency(UpdateFrequency freq);
  UpdateFrequency getUpdateFrequency(void) const;

  SoGuiColorEditor * getEditor(void) const;

protected:
  virtual const char * getDefaultWidgetName(void) const;
  virtual const char * getDefaultTitle(void) const;
  virtual const char * getDefaultIconTitle(void) const;

private:
  void * internals;

};

#endif // !COIN_SOQTCOLOREDITOR_H
