#ifndef COIN_SOGUIMATERIALEDITOR_H
#define COIN_SOGUIMATERIALEDITOR_H

// src\Inventor\Qt\nodes\SoGuiMaterialEditor.h.  Generated from MaterialEditor.h.in by configure.

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

#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFShort.h>
#include <Inventor/fields/SoSFNode.h>
#include <Inventor/nodekits/SoBaseKit.h>

class SoMaterial;
class SoGuiColorEditor;

typedef SoGuiColorEditor * SoGuiColorEditorOpenCB(void * closure);
typedef void SoGuiColorEditorCloseCB(void * closure, SoGuiColorEditor * editor);

class SoGuiMaterialEditor : public SoBaseKit {
  typedef SoBaseKit inherited;
  SO_KIT_HEADER(SoGuiMaterialEditor);
  SO_KIT_CATALOG_ENTRY_HEADER(root);

public:
  static void initClass(void);
  SoGuiMaterialEditor(void);
  
  enum UpdateFrequency {
    CONTINUOUS,
    AFTER_ACCEPT
  };

  SoSFNode material;
  SoSFShort index;
  SoSFEnum update;

  void setColorEditorCallbacks(SoGuiColorEditorOpenCB * open, SoGuiColorEditorCloseCB * close, void * closure);
  SoMaterial * getSphereMaterialNode(void) const;

protected:
  ~SoGuiMaterialEditor(void);

private:
  void * internals;

};

#endif // !COIN_SOGUIMATERIALEDITOR_H
