#include <QtGui>
#include "glwidget.h"
#include "window.h"

Window::Window()
{
  glWidget = new GLWidget;
  
  xSlider = new QSlider(Qt::Vertical);
  xSlider->setRange(0, 360 * 16);
  xSlider->setSingleStep(16);
  xSlider->setPageStep(15 * 16);
  xSlider->setTickInterval(15 * 16);
  xSlider->setTickPosition(QSlider::TicksRight);
  xSlider->setValue(15 * 16);
  
  connect(xSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setXRotation(int)));
  connect(glWidget, SIGNAL(xRotationChanged(int)), xSlider, SLOT(setValue(int)));
  
  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->addWidget(glWidget);
  mainLayout->addWidget(xSlider);
  setLayout(mainLayout);

  setWindowTitle(tr("QtGmsh"));
}
