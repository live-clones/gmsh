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
#include "GModel.h"
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

static std::vector<GEntity*> getSelectedEntities()
{
  // only return highest dimension matches
  std::vector<GEntity*> entities;
  if(FlGui::instance()->selectedRegions.size())
    for(unsigned int i = 0; i < FlGui::instance()->selectedRegions.size(); i++)
      entities.push_back(FlGui::instance()->selectedRegions[i]);
  else if(FlGui::instance()->selectedFaces.size())
    for(unsigned int i = 0; i < FlGui::instance()->selectedFaces.size(); i++)
      entities.push_back(FlGui::instance()->selectedFaces[i]);
  else if(FlGui::instance()->selectedEdges.size())
    for(unsigned int i = 0; i < FlGui::instance()->selectedEdges.size(); i++)
      entities.push_back(FlGui::instance()->selectedEdges[i]);
  else if(FlGui::instance()->selectedVertices.size())
    for(unsigned int i = 0; i < FlGui::instance()->selectedVertices.size(); i++)
      entities.push_back(FlGui::instance()->selectedVertices[i]);
  return entities;
}

static void highlightPhysicals(const std::vector<GEntity*> &entities)
{
  int dim = -1;
  std::set<int> phys;
  for(unsigned int i = 0; i < entities.size(); i++){
    phys.insert(entities[i]->physicals.begin(), entities[i]->physicals.end());
    dim = entities[i]->dim();
  }
  if(dim < 0) return;

  // color selected physicals
  std::map<int, std::vector<GEntity*> > groups[4];
  GModel::current()->getPhysicalGroups(groups);
  for(std::set<int>::iterator it = phys.begin(); it != phys.end(); it++)
    for(unsigned int j = 0; j < groups[dim][*it].size(); j++)
      groups[dim][*it][j]->setSelection(1);
  drawContext::global()->draw();
}

void inputRegion::_add_butt_cb(Fl_Widget *w, void *data)
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

  int dim = ENT_ALL; // TODO use onelab::region::dim

  Msg::StatusGl("Select entities\n[Press 'e' to end]");
  while(1){
    char ib = FlGui::instance()->selectEntity(dim);
    if(ib == 'l'){
      std::vector<GEntity*> selected = getSelectedEntities();
      highlightPhysicals(selected);
      std::set<std::string> current = b->value();
      for(unsigned int i = 0; i < selected.size(); i++){
        for(unsigned int j = 0; j < selected[i]->physicals.size(); j++)
          current.insert(num2str(selected[i]->physicals[j]));
      }
      b->value(current);
    }
    else if(ib == 'e' || ib == 'q'){
      break;
    }
  }
  Msg::StatusGl("");

  b->do_callback();

  GModel::current()->setSelection(0);
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, oldp);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, oldl);
  opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, olds);
  opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, oldv);
  drawContext::global()->draw();
}
