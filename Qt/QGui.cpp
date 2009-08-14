// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <QtGui>
#include <QWidget>
#include <QSlider>
#include "QGui.h"
#include "graphicWindow.h"

QGui::QGui(int argc, char **argv)
{
  _graphicWindow = new graphicWindow();
  _graphicWindow->show();
}

QGui *QGui::_instance = 0;

QGui *QGui::instance(int argc, char **argv)
{
  if(!_instance) _instance = new QGui(argc, argv);
  return _instance;
}

drawContext *QGui::getDrawContext()
{
  return _graphicWindow->getDrawContext();
}
