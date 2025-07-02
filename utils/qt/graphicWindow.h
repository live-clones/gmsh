// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _GRAPHIC_WINDOW_H_
#define _GRAPHIC_WINDOW_H_

#include <QWidget>
#include "GLWidget.h"

class QSlider;

class graphicWindow : public QWidget
{
  Q_OBJECT
 private:
  GLWidget *_glWidget;
  QSlider *_xSlider;
 public:
  graphicWindow();
  drawContext *getDrawContext(){ return _glWidget->getDrawContext(); }
};

#endif
