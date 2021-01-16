// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <QtGui>
#include <QtOpenGL>
#include <math.h>
#include "GLWidget.h"

GLWidget::GLWidget(QWidget *parent)
  : QGLWidget(parent)
{
  _ctx = new drawContext();
}

GLWidget::~GLWidget()
{
  makeCurrent();
  delete _ctx;
}

QSize GLWidget::minimumSizeHint() const
{
  return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
  return QSize(400, 400);
}

void GLWidget::setXRotation(int angle)
{
  emit xRotationChanged(angle);
  _ctx->addQuaternion(0.1, 0, 0, 0);
  updateGL();
}

void GLWidget::initializeGL()
{
}

void GLWidget::paintGL()
{
  glViewport(_ctx->viewport[0], _ctx->viewport[1],
             _ctx->viewport[2], _ctx->viewport[3]);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  _ctx->draw3d();
  _ctx->draw2d();
}

void GLWidget::resizeGL(int width, int height)
{
  _ctx->viewport[2] = width;
  _ctx->viewport[3] = height;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
}
