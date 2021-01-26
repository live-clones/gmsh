// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  {GMSH_FULLRC, "NumLayers", nullptr, 1},
  {GMSH_FULLRC, "Element1", nullptr, 0},
  {GMSH_FULLRC, "Element2", nullptr, 0},
  {GMSH_FULLRC, "Element3", nullptr, 0},
  {GMSH_FULLRC, "Element4", nullptr, 0},
  {GMSH_FULLRC, "Element5", nullptr, 0}};

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
  return "Plugin(ShowNeighborElements) sets visible some elements "
         "and a layer of elements around them, the other being set invisible.";
}

PView *GMSH_ShowNeighborElementsPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  _nLayers = static_cast<int>(ShowNeighborElementsOptions_Number[0].def);
  _nel1 = static_cast<int>(ShowNeighborElementsOptions_Number[1].def);
  _nel2 = static_cast<int>(ShowNeighborElementsOptions_Number[2].def);
  _nel3 = static_cast<int>(ShowNeighborElementsOptions_Number[3].def);
  _nel4 = static_cast<int>(ShowNeighborElementsOptions_Number[4].def);
  _nel5 = static_cast<int>(ShowNeighborElementsOptions_Number[5].def);

  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    GFace *f = *it;
    _init(f);
    _showLayers(f, _nLayers);
  }

  for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
    GRegion *r = *it;
    _init(r);
    _showLayers(r, _nLayers);
  }

#if defined(HAVE_OPENGL)
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
#endif

  return nullptr;
}

void GMSH_ShowNeighborElementsPlugin::_init(GEntity *ent)
{
  _vert2elem.clear();
  for(unsigned i = 0; i < ent->getNumMeshElements(); ++i) {
    MElement *el = ent->getMeshElement(i);
    if(el->getNum() == _nel1 || el->getNum() == _nel2 ||
       el->getNum() == _nel3 || el->getNum() == _nel4 ||
       el->getNum() == _nel5) {
      el->setVisibility(true);
      for(std::size_t k = 0; k < el->getNumVertices();
          ++k) { // TODO only corner vertices?
        _vertices.insert(el->getVertex(k));
      }
    }
    else {
      el->setVisibility(false);
      for(std::size_t k = 0; k < el->getNumVertices();
          ++k) { // TODO only corner vertices?
        _vert2elem.insert(std::make_pair(el->getVertex(k), el));
      }
    }
  }
}

void GMSH_ShowNeighborElementsPlugin::_showLayers(GEntity *ent, int nLayer)
{
  if(_vertices.empty() || nLayer < 1) return;

  std::set<MVertex *> &vert = _vertices;
  std::map<MElement *, int> el2cnt;

  for(auto it = vert.begin(); it != vert.end(); ++it) {
    MVertex *v = *it;
    auto ite = _vert2elem.lower_bound(v);
    auto itstop = _vert2elem.upper_bound(v);
    for(; ite != itstop; ++ite) {
      MElement *el = ite->second;
      if(el2cnt.find(el) == el2cnt.end()) el2cnt[el] = 0;
      ++el2cnt[el];
    }
  }

  for(auto it2 = el2cnt.begin(); it2 != el2cnt.end(); ++it2) {
    if(it2->second && it2->second > 3 - nLayer) {
      it2->first->setVisibility(true);
    }
  }
}
