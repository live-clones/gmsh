// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include <unordered_map>
#include "ShowNeighborElements.h"
#include "GModel.h"
#include "MElement.h"
#include "MVertex.h"
#include "Options.h"
#include "Context.h"
#include "GmshDefines.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

StringXNumber ShowNeighborElementsOptions_Number[] = {
  {GMSH_FULLRC, "NumLayers", nullptr, 1, ""},
  {GMSH_FULLRC, "Element1", nullptr, 0, ""},
  {GMSH_FULLRC, "Element2", nullptr, 0, ""},
  {GMSH_FULLRC, "Element3", nullptr, 0, ""},
  {GMSH_FULLRC, "Element4", nullptr, 0, ""},
  {GMSH_FULLRC, "Element5", nullptr, 0, ""}};

extern "C" {
GMSH_Plugin *GMSH_RegisterShowNeighborElementsPlugin()
{
  return new GMSH_ShowNeighborElementsPlugin();
}
}

int GMSH_ShowNeighborElementsPlugin::getNbOptions() const
{
  return sizeof(ShowNeighborElementsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ShowNeighborElementsPlugin::getOption(int iopt)
{
  return &ShowNeighborElementsOptions_Number[iopt];
}
std::string GMSH_ShowNeighborElementsPlugin::getHelp() const
{
  return "Plugin(ShowNeighborElements) sets visible the surface and volume "
         "elements `Element1', ..., `Element5' (numbers of elements, 0 for "
         "none) and `NumLayers' layers of elements around them: the "
         "elements of the same dimension that share a node with them, then "
         "those that share a node with these, and so on. The other surface and "
         "volume elements are set invisible.";
}

PView *GMSH_ShowNeighborElementsPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  int numLayers = static_cast<int>(ShowNeighborElementsOptions_Number[0].def);
  std::set<std::size_t> selected;
  for(int i = 1; i <= 5; i++) {
    std::size_t num = ShowNeighborElementsOptions_Number[i].def;
    if(num) selected.insert(num);
  }

  // the surface and volume elements around each node; hide all but the
  // selected ones
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  std::unordered_map<MVertex *, std::vector<MElement *> > around;
  std::vector<MElement *> layer;
  for(auto ent : entities) {
    if(ent->dim() < 2) continue;
    for(std::size_t i = 0; i < ent->getNumMeshElements(); i++) {
      MElement *e = ent->getMeshElement(i);
      bool sel = selected.count(e->getNum());
      e->setVisibility(sel);
      if(sel) layer.push_back(e);
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++)
        around[e->getVertex(k)].push_back(e);
    }
  }

  // each layer: the hidden elements of the same dimension sharing a node with
  // the previous one
  for(int l = 0; l < numLayers && layer.size(); l++) {
    std::vector<MElement *> next;
    for(auto e : layer) {
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++) {
        for(auto n : around[e->getVertex(k)]) {
          if(n->getVisibility() || n->getDim() != e->getDim()) continue;
          n->setVisibility(true);
          next.push_back(n);
        }
      }
    }
    layer.swap(next);
  }

  CTX::instance()->meshChanged();
#if defined(HAVE_OPENGL)
  drawContext::global()->draw();
#endif

  return nullptr;
}
