// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "CommandLine.h"
#include "OpenFile.h"
#include "Context.h"
#include "QGui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  new GModel();
  GmshInitialize(argc, argv);

  OpenProject(GModel::current()->getFileName());
  for(unsigned int i = 1; i < CTX::instance()->files.size(); i++){
    if(CTX::instance()->files[i] == "-new"){
      GModel::current()->setVisibility(0);
      new GModel();
    }
    else
      MergeFile(CTX::instance()->files[i]);
  }

  QApplication app(argc, argv);
  QGui::instance(argc, argv);
  return app.exec();
}
