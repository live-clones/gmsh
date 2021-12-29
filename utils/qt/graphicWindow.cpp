// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <QtGui>
#include <QSlider>
#include <QHBoxLayout>
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
