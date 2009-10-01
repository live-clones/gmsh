// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <stdio.h>
#include <string.h>
#include "GmshConfig.h"
#include "Plugin.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

void (*GMSH_Plugin::draw)(void*) = 0;

void GMSH_Plugin::setDrawFunction(void (*fct)(void *))
{
#if defined(HAVE_OPENGL)
  draw = fct;
  int old = CTX::instance()->drawBBox;
  CTX::instance()->drawBBox = 1;
  if(CTX::instance()->fastRedraw){
    CTX::instance()->post.draw = 0;
    CTX::instance()->mesh.draw = 0;
  }
  drawContext::global()->draw();
  CTX::instance()->drawBBox = old;
  CTX::instance()->post.draw = 1;
  CTX::instance()->mesh.draw = 1;
#endif
}

void GMSH_Plugin::catchErrorMessage(char *errorMessage) const
{
  std::string str = getName() + "failed...";
  strcpy(errorMessage, str.c_str());
}

PView *GMSH_PostPlugin::executeRemote(PView *view)
{
  int j = -1, remoteIndex = -1;
  for(unsigned int i = 0; i < PView::list.size(); i++){
    if(PView::list[i]->getData()->isRemote()) j++;
    if(PView::list[i]->getNum() == view->getNum()){
      remoteIndex = j;
      break;
    }
  }
  if(remoteIndex < 0){
    Msg::Error("Unable to determine index of remote view");
    return view;
  }
  
  for(int i = 0; i < getNbOptions(); i++)
    if(getOption(i)->str == "iView") getOption(i)->def = remoteIndex;
  
  std::ostringstream sstream;
  for(int i = 0; i < getNbOptionsStr(); i++)
    sstream << "Plugin(" << getName() << ")." << getOptionStr(i)->str 
            <<  "= \"" << getOptionStr(i)->def << "\";\n";
  for(int i = 0; i < getNbOptions(); i++)
    sstream << "Plugin(" << getName() << ")." << getOption(i)->str 
            << "=" << getOption(i)->def << ";\n";
  sstream << "Plugin(" << getName() << ").Run;\n";
  
  std::string options = sstream.str();
  view->getData()->fillRemoteVertexArrays(options);
  return view;
}

PView *GMSH_PostPlugin::getView(int index, PView *view)
{
  if(index < 0)
    index = view ? view->getIndex() : 0;

  if(index >= 0 && index < (int)PView::list.size()){
    return PView::list[index];
  }
  else{
    Msg::Error("View[%d] does not exist", index);
    return 0;
  }
}

PViewDataList *GMSH_PostPlugin::getDataList(PView *view, bool showError)
{
  if(!view) return 0;

  PViewDataList *data = dynamic_cast<PViewDataList*>(view->getData());
  if(data)
    return data;
  else if(showError)
    Msg::Error("This plugin can only be run on list-based views (`.pos' files)");
  return 0;
}
