#include <QtGui>
#include "GLWidget.h"
#include "graphicWindow.h"

graphicWindow::graphicWindow()
{
  _glWidget = new GLWidget();
  
  _xSlider = new QSlider(Qt::Vertical);
  _xSlider->setRange(0, 360 * 16);
  _xSlider->setSingleStep(16);
  _xSlider->setPageStep(15 * 16);
  _xSlider->setTickInterval(15 * 16);
  _xSlider->setTickPosition(QSlider::TicksRight);
  _xSlider->setValue(15 * 16);
  
  connect(_xSlider, SIGNAL(valueChanged(int)), _glWidget, SLOT(setXRotation(int)));
  connect(_glWidget, SIGNAL(xRotationChanged(int)), _xSlider, SLOT(setValue(int)));
  
  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->addWidget(_glWidget);
  mainLayout->addWidget(_xSlider);
  setLayout(mainLayout);

  setWindowTitle(tr("QtGmsh"));
}
