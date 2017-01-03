// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
  {GMSH_FULLRC, "NumLayers", NULL, 1},
  {GMSH_FULLRC, "Element1", NULL, 0},
  {GMSH_FULLRC, "Element2", NULL, 0},
  {GMSH_FULLRC, "Element3", NULL, 0},
  {GMSH_FULLRC, "Element4", NULL, 0},
  {GMSH_FULLRC, "Element5", NULL, 0}
};
extern "C"
{
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
  return "Plugin(ShowNeighborElements) allows to set visible some given elements "
      " and a layer of elements around them, the other being set invisible.";
}

// Execution
PView* GMSH_ShowNeighborElementsPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  _nLayers = static_cast<int>(ShowNeighborElementsOptions_Number[0].def);
  _nel1 = static_cast<int>(ShowNeighborElementsOptions_Number[1].def);
  _nel2 = static_cast<int>(ShowNeighborElementsOptions_Number[2].def);
  _nel3 = static_cast<int>(ShowNeighborElementsOptions_Number[3].def);
  _nel4 = static_cast<int>(ShowNeighborElementsOptions_Number[4].def);
  _nel5 = static_cast<int>(ShowNeighborElementsOptions_Number[5].def);

  for (GModel::fiter it = m->firstFace(); it != m->lastFace(); it++) {
    GFace *f = *it;
    _init(f);
    _showLayers(f, _nLayers);
  }

  for (GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++) {
    GRegion *r = *it;
    _init(r);
    _showLayers(r, _nLayers);
  }

#if defined(HAVE_OPENGL)
  CTX::instance()->mesh.changed = (ENT_ALL);
  drawContext::global()->draw();
#endif

  return NULL;
}

void GMSH_ShowNeighborElementsPlugin::_init(GEntity *ent)
{
  _vert2elem.clear();
  for (unsigned i = 0; i < ent->getNumMeshElements(); ++i) {
    MElement *el = ent->getMeshElement(i);
    if (el->getNum() == _nel1 ||
        el->getNum() == _nel2 ||
        el->getNum() == _nel3 ||
        el->getNum() == _nel4 ||
        el->getNum() == _nel5) {
      el->setVisibility(true);
      for (int k = 0; k < el->getNumVertices(); ++k) { // TODO only corner vertices?
        _vertices.insert(el->getVertex(k));
      }
    }
    else {
      el->setVisibility(false);
      for (int k = 0; k < el->getNumVertices(); ++k) { // TODO only corner vertices?
        _vert2elem.insert(std::make_pair(el->getVertex(k), el));
      }
    }
  }
}

void GMSH_ShowNeighborElementsPlugin::_showLayers(GEntity *ent, int nLayer)
{
//  std::pair<std::multimap<MVertex*, MElement*>::iterator,
//            std::multimap<MVertex*, MElement*>::iterator> lowUpBound;

  if (_vertices.empty() || nLayer < 1) return;

  std::set<MVertex*> &vert = _vertices;
//  _vertices.clear();
  std::map<MElement*, int> el2cnt;

  std::set<MVertex*>::iterator it;
  for (it = vert.begin(); it != vert.end(); ++it) {
    MVertex *v = *it;
    std::multimap<MVertex*, MElement*>::iterator ite, itstop;
    ite = _vert2elem.lower_bound(v);
    itstop = _vert2elem.upper_bound(v);
    for (; ite != itstop; ++ite) {
      MElement *el = ite->second;
      if (el2cnt.find(el) == el2cnt.end()) el2cnt[el] = 0;
      ++el2cnt[el];
//      el->setVisibility(true);
//      for (int k = 0; k < el->getNumVertices(); ++k) { // TODO only corner vertices?
//        _vertices.insert(el->getVertex(k));
//      }
    }
  }

  std::map<MElement*, int>::iterator it2;
  for (it2 = el2cnt.begin(); it2 != el2cnt.end(); ++it2) {
    if (it2->second && it2->second > 3-nLayer) {
      it2->first->setVisibility(true);
    }
  }

  //_showLayers(ent, nLayer-1);
}
