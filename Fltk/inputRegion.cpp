// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <stdio.h>
#include "onelab.h"
#include "inputRegion.h"
#include "FlGui.h"
#include "drawContext.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "Options.h"
#include "GmshDefines.h"

static std::string num2str(int num)
{
  std::ostringstream tmp;
  tmp << num;
  return tmp.str();
}

void inputRegion::_region_butt_cb(Fl_Widget *w, void *data)
{
  inputRegion *b = (inputRegion*)data;
  
  int oldp = opt_geometry_points(0, GMSH_GET, 0);
  int oldl = opt_geometry_lines(0, GMSH_GET, 0);
  int olds = opt_geometry_surfaces(0, GMSH_GET, 0);
  int oldv = opt_geometry_volumes(0, GMSH_GET, 0);
  
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
  
  std::set<std::string> physicals = b->value();
  Msg::StatusBar(3, false, "Select entities\n[Press 'e' to end]");
  while(1){
    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l'){
      if(FlGui::instance()->selectedRegions.size()){
        for(unsigned int i = 0; i < FlGui::instance()->selectedRegions.size(); i++){
          GRegion *gr = FlGui::instance()->selectedRegions[i];
          for(unsigned int j = 0; j < gr->physicals.size(); j++)
            physicals.insert(num2str(gr->physicals[j]));
        }
      }
      if(FlGui::instance()->selectedFaces.size()){
        for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++){
          GFace *gr = FlGui::instance()->selectedFaces[i];
          for(unsigned int j = 0; j < gr->physicals.size(); j++)
            physicals.insert(num2str(gr->physicals[j]));
        }
      }
      if(FlGui::instance()->selectedEdges.size()){
        for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++){
          GEdge *gr = FlGui::instance()->selectedEdges[i];
          for(unsigned int j = 0; j < gr->physicals.size(); j++)
            physicals.insert(num2str(gr->physicals[j]));
        }
      }
      if(FlGui::instance()->selectedVertices.size()){
        for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++){
          GVertex *gr = FlGui::instance()->selectedVertices[i];
          for(unsigned int j = 0; j < gr->physicals.size(); j++)
            physicals.insert(num2str(gr->physicals[j]));
        }
      }
      b->value(physicals);
    }
    else if(ib == 'e' || ib == 'q'){
      break;
    }
  }
  Msg::StatusBar(3, false, "");

  b->do_callback();
  
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, oldp);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, oldl);
  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, olds);
  opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, oldv);
  drawContext::global()->draw();
}
