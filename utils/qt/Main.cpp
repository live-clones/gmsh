// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <QApplication>
#include <gmsh/GmshGlobal.h>
#include <gmsh/GmshMessage.h>
#include <gmsh/GModel.h>
#include <gmsh/CommandLine.h>
#include <gmsh/OpenFile.h>
#include <gmsh/Context.h>

#include "QGui.h"

int main(int argc, char *argv[])
{
  new GModel();
  GmshInitialize(argc, argv, true);

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
