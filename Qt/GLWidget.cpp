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
  /*
  int dx = event->x() - lastPos.x();
  int dy = event->y() - lastPos.y();
  if (event->buttons() & Qt::LeftButton) {
    setXRotation(xRot + 8 * dy);
    setYRotation(yRot + 8 * dx);
  } else if (event->buttons() & Qt::RightButton) {
    setXRotation(xRot + 8 * dy);
    setZRotation(zRot + 8 * dx);
  }
  lastPos = event->pos();
  */
}
