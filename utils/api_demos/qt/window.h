#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QSlider;
class GLWidget;

class Window : public QWidget
{
  Q_OBJECT
 private:
  GLWidget *glWidget;
  QSlider *xSlider;
 public:
  Window();
};

#endif
