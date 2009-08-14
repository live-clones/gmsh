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
