// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"
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
