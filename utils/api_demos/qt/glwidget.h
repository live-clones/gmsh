#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include <gmsh/Gmsh.h>
#include <gmsh/drawContext.h>

class GLWidget : public QGLWidget
{
  Q_OBJECT
 private:
 public:
  static drawContext *_ctx;
  GLWidget(QWidget *parent = 0);
  ~GLWidget();
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
