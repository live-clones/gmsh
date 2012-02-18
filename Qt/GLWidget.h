// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GLWIDGET_H_
#define _GLWIDGET_H_

#include <QGLWidget>
#include "Gmsh.h"
#include "drawContext.h"

class GLWidget : public QGLWidget
{
  Q_OBJECT
 private:
  drawContext *_ctx;
 public:
  GLWidget(QWidget *parent = 0);
  ~GLWidget();
  drawContext *getDrawContext(){ return _ctx; }
  QSize minimumSizeHint() const;
  QSize sizeHint() const;
 public slots:
  void setXRotation(int angle);
 signals:
  void xRotationChanged(int angle);
 protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int width, int height);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
};

#endif
