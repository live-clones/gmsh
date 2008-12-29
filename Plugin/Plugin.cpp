// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Plugin.h"

PView *GMSH_Post_Plugin::getView(int index, PView *view)
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

PViewDataList *GMSH_Post_Plugin::getDataList(PView *view)
{
  if(!view) return 0;

  PViewDataList *data = dynamic_cast<PViewDataList*>(view->getData());
  if(data){
    return data;
  }
  else{
    // FIXME: do automatic data conversion here
    Msg::Error("This plugin can only be run on list-based datasets");
    return 0;
  }
}
