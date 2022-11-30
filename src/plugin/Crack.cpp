// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Crack.h"
#include "GModel.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MEdge.h"
#include "Context.h"

StringXNumber CrackOptions_Number[] = {
  {GMSH_FULLRC, "Dimension", nullptr, 1.},
  {GMSH_FULLRC, "PhysicalGroup", nullptr, 1.},
  {GMSH_FULLRC, "OpenBoundaryPhysicalGroup", nullptr, 0.},
  {GMSH_FULLRC, "AuxiliaryPhysicalGroup", nullptr, 0},
  {GMSH_FULLRC, "NormalX", nullptr, 0.},
  {GMSH_FULLRC, "NormalY", nullptr, 0.},
  {GMSH_FULLRC, "NormalZ", nullptr, 1.},
  {GMSH_FULLRC, "NewPhysicalGroup", nullptr, 0},
  {GMSH_FULLRC, "DebugView", nullptr, 0}
};

extern "C" {
GMSH_Plugin *GMSH_RegisterCrackPlugin() { return new GMSH_CrackPlugin(); }
}

std::string GMSH_CrackPlugin::getHelp() const
{
  return "Plugin(Crack) creates a crack around the physical "
         "group `PhysicalGroup' of dimension `Dimension' (1 or 2), "
         "embedded in a mesh of dimension `Dimension' + 1. "
         "The plugin duplicates the nodes and the elements on "
         "the crack and stores them in a new discrete curve "
         "(`Dimension' = 1) or surface (`Dimension' = 2). The "
         "elements touching the crack on the positive side "
         "are modified to use the newly generated nodes."
         "If `OpenBoundaryPhysicalGroup' is given (> 0), its "
         "nodes are duplicated and the crack will be left "
         "open on that (part of the) boundary. Otherwise, the "
         "lips of the crack are sealed, i.e., its nodes are "
         "not duplicated. If `AuxiliaryPhysicalGroup' is given "
         "(> 0), its elements are considered in addition to those in "
         "`PhysicalGroup' for the logic that groups the elements "
         "into the positive and negative side of the crack. "
         "However, the nodes in `AuxiliaryPhysicalGroup' are not "
         "duplicated (unless they are also in `PhysicalGroup'). "
         "This can be useful to treat corner cases in non-trivial "
         "geometries. For 1D cracks, `NormalX', `NormalY' and "
         "`NormalZ' provide the reference normal of the surface "
         "in which the crack is supposed to be embedded. If "
         "`NewPhysicalGroup' is positive, use it as the tag of "
         "the newly created curve or surface; otherwise use "
         "`PhysicalGroup'.";
}

int GMSH_CrackPlugin::getNbOptions() const
{
  return sizeof(CrackOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CrackPlugin::getOption(int iopt)
{
  return &CrackOptions_Number[iopt];
}

class EdgeData {
public:
  EdgeData(MEdge e) : edge(e) {}
  MEdge edge;
  std::vector<MVertex *> data;
};

struct MEdgeDataLessThan
  : public std::binary_function<EdgeData, EdgeData, bool> {
  bool operator()(const EdgeData &e1, const EdgeData &e2) const
  {
    if(e1.edge.getMinVertex() < e2.edge.getMinVertex()) return true;
    if(e1.edge.getMinVertex() > e2.edge.getMinVertex()) return false;
    if(e1.edge.getMaxVertex() < e2.edge.getMaxVertex()) return true;
    return false;
  }
};

PView *GMSH_CrackPlugin::execute(PView *view)
{
  int dim = (int)CrackOptions_Number[0].def;
  int physical = (int)CrackOptions_Number[1].def;
  int open = (int)CrackOptions_Number[2].def;
  int aux = (int)CrackOptions_Number[3].def;
  SVector3 normal1d(CrackOptions_Number[4].def, CrackOptions_Number[5].def,
                    CrackOptions_Number[6].def);
  int newPhysical = (int)CrackOptions_Number[7].def;
  int debug = (int)CrackOptions_Number[8].def;

  if(dim != 1 && dim != 2) {
    Msg::Error("Crack dimension should be 1 or 2");
    return view;
  }

  GModel *m = GModel::current();
  std::map<int, std::vector<GEntity *> > groups[4];
  m->getPhysicalGroups(groups);
  std::vector<GEntity *> entities = groups[dim][physical];

  if(entities.empty()) {
    Msg::Error("Physical group %d (dimension %d) is empty", physical, dim);
    return view;
  }

  std::vector<GEntity *> openEntities;
  if(open > 0) {
    openEntities = groups[dim - 1][open];
    if(openEntities.empty()) {
      Msg::Error("Open boundary physical group %d (dimension %d) is empty",
                 open, dim - 1);
      return view;
    }
  }

  std::vector<GEntity *> auxEntities;
  if(aux > 0) {
    auxEntities = groups[dim][aux];
    if(auxEntities.empty()) {
      Msg::Warning("Auxiliary physical group %d (dimension %d) is empty",
                   aux, dim);
      return view;
    }
  }

  std::set<GEntity *> crackEntities;
  crackEntities.insert(entities.begin(), entities.end());
  crackEntities.insert(openEntities.begin(), openEntities.end());

  // get crack elements
  std::vector<MElement *> crackElements;
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
      crackElements.push_back(entities[i]->getMeshElement(j));

  // get internal crack nodes (and list of connected crack elements), as well as
  // and boundary nodes
  std::map<MVertex *, std::vector<MElement *> > crackVertices;
  std::set<MVertex *> bndVertices;
  if(dim == 1) {
    for(std::size_t i = 0; i < crackElements.size(); i++) {
      for(std::size_t j = 0; j < crackElements[i]->getNumVertices(); j++) {
        MVertex *v = crackElements[i]->getVertex(j);
        auto it = crackVertices.find(v);
        if(it == crackVertices.end())
          crackVertices[v] = {crackElements[i]};
        else
          it->second.push_back(crackElements[i]);
      }
      for(std::size_t j = 0; j < crackElements[i]->getNumPrimaryVertices();
          j++) {
        MVertex *v = crackElements[i]->getVertex(j);
        if(bndVertices.find(v) == bndVertices.end())
          bndVertices.insert(v);
        else
          bndVertices.erase(v);
      }
    }
  }
  else {
    std::set<EdgeData, MEdgeDataLessThan> bnd;
    for(std::size_t i = 0; i < crackElements.size(); i++) {
      for(std::size_t j = 0; j < crackElements[i]->getNumVertices(); j++) {
        MVertex *v = crackElements[i]->getVertex(j);
        auto it = crackVertices.find(v);
        if(it == crackVertices.end())
          crackVertices[v] = {crackElements[i]};
        else
          it->second.push_back(crackElements[i]);
      }
      for(int j = 0; j < crackElements[i]->getNumEdges(); j++) {
        EdgeData ed(crackElements[i]->getEdge(j));
        if(bnd.find(ed) == bnd.end()) {
          crackElements[i]->getEdgeVertices(j, ed.data);
          bnd.insert(ed);
        }
        else
          bnd.erase(ed);
      }
    }
    for(auto it = bnd.begin(); it != bnd.end(); it++)
      bndVertices.insert(it->data.begin(), it->data.end());
  }

  // compute the boundary nodes (if any) of the "OpenBoundary" physical group if
  // it's a curve
  std::set<MVertex *> bndVerticesFromOpenBoundary;
  for(std::size_t i = 0; i < openEntities.size(); i++) {
    if(openEntities[i]->dim() < 1) continue;
    for(std::size_t j = 0; j < openEntities[i]->getNumMeshElements(); j++) {
      MElement *e = openEntities[i]->getMeshElement(j);
      for(std::size_t k = 0; k < e->getNumPrimaryVertices(); k++) {
        MVertex *v = e->getVertex(k);
        if(bndVerticesFromOpenBoundary.find(v) ==
           bndVerticesFromOpenBoundary.end())
          bndVerticesFromOpenBoundary.insert(v);
        else
          bndVerticesFromOpenBoundary.erase(v);
      }
    }
  }

  if(bndVerticesFromOpenBoundary.size())
    Msg::Info("%u nodes on boundary of OpenBoundaryPhysicalGroup",
              bndVerticesFromOpenBoundary.size());

  // get open boundary nodes and remove them from boundary nodes (if they are
  // not on the "boundary of the open boundary" ;-)
  for(std::size_t i = 0; i < openEntities.size(); i++) {
    for(std::size_t j = 0; j < openEntities[i]->getNumMeshElements(); j++) {
      MElement *e = openEntities[i]->getMeshElement(j);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        MVertex *v = e->getVertex(k);
        if(bndVerticesFromOpenBoundary.find(v) ==
           bndVerticesFromOpenBoundary.end())
          bndVertices.erase(v);
      }
    }
  }
  for(auto it = bndVertices.begin(); it != bndVertices.end(); it++)
    crackVertices.erase(*it);

  // get auxiliary elements
  std::vector<MElement *> auxElements;
  for(std::size_t i = 0; i < auxEntities.size(); i++)
    for(std::size_t j = 0; j < auxEntities[i]->getNumMeshElements(); j++)
      auxElements.push_back(auxEntities[i]->getMeshElement(j));

  // add auxiliary elements to crackVertices if they are connected to the
  // vertex (see #1750)
  for(std::size_t i = 0; i < auxElements.size(); i++) {
    for(std::size_t j = 0; j < auxElements[i]->getNumVertices(); j++) {
      MVertex *v = auxElements[i]->getVertex(j);
      auto it = crackVertices.find(v);
      // vertex v is in crackVertices: add aux element to vector of connected
      // elements
      if(it != crackVertices.end())
        it->second.push_back(auxElements[i]);
    }
  }

  // compute elements on the positive side of the crack, and keep track of each
  // node in the element that leads to categorizing the element on this side
  // (this allows to handle the degenerate case where the same element touches
  // the same crack on both sides, with different nodes - cf. #1750)
  std::map<MElement *, std::vector<std::size_t> > oneside;
  std::vector<GEntity *> allentities;
  m->getEntities(allentities);
  for(std::size_t ent = 0; ent < allentities.size(); ent++) {
    if(crackEntities.find(allentities[ent]) != crackEntities.end()) continue;
    for(std::size_t i = 0; i < allentities[ent]->getNumMeshElements(); i++) {
      MElement *e = allentities[ent]->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto it = crackVertices.find(e->getVertex(j));
        if(it == crackVertices.end()) continue;
        // the element touches the crack by at least one node: determine if the
        // vector joining its barycenter to the barycenter of one of the
        // connected crack elements is not in the same direction as the normal
        // to the crack element; if the condition is fulfilled for one of the
        // connected crack elements, we consider the element lies on the
        // "positive side" of the crack
        SPoint3 b = e->barycenter();
        for(auto ce : it->second) {
          SVector3 dv = SVector3(b, ce->barycenter());
          SVector3 n;
          if(dim == 1)
            n = crossprod(normal1d, ce->getEdge(0).tangent());
          else
            n = ce->getFace(0).normal();
          if(dot(n, dv) < 0) {
            auto it2 = oneside.find(e);
            if(it2 == oneside.end())
              oneside[e] = {j};
            else {
              if(std::find(it2->second.begin(), it2->second.end(), j) ==
                 it2->second.end())
                it2->second.push_back(j);
            }
          }
        }
      }
    }
  }

  // create new crack entity

  // TODO: the new discrete entities do not have a consistent topology: we don't
  // specify their bounding points/curves
  //   a) This is easy to fix if there's no OpenBoundaryPhysicalGroup and
  //      we crack a *single* elementary entity
  //   b) If there is an open boundary, we need to create a new elementary
  //      entity on the boundary, and correctly classify the nodes on it...
  //      and we also need to create boundary elements
  //   c) If we crack a group made of multiple elementary entities we might
  //      want to create multiple cracked entities, and do the same as (b)
  //      for all internal seams
  //
  // In practice, c) is not crucial - the current approach simply creates a
  // single new surface/curve, which is probably fine as in solvers we won't use
  // the internal seams.

  GEdge *crackEdge = nullptr;
  GFace *crackFace = nullptr;
  if(dim == 1) {
    crackEdge =
      new discreteEdge(m, m->getMaxElementaryNumber(1) + 1, nullptr, nullptr);
    m->add(crackEdge);
  }
  else {
    crackFace = new discreteFace(m, m->getMaxElementaryNumber(2) + 1);
    m->add(crackFace);
  }
  GEntity *crackEntity =
    crackEdge ? (GEntity *)crackEdge : (GEntity *)crackFace;
  crackEntity->physicals.push_back(newPhysical ? newPhysical : physical);

  // duplicate internal crack nodes
  std::map<MVertex *, MVertex *> vxv;
  for(auto it = crackVertices.begin(); it != crackVertices.end(); it++) {
    MVertex *v = it->first;
    MVertex *newv = new MVertex(v->x(), v->y(), v->z(), crackEntity);
    crackEntity->mesh_vertices.push_back(newv);
    vxv[v] = newv;
  }

  // duplicate crack elements
  for(std::size_t i = 0; i < crackElements.size(); i++) {
    MElement *e = crackElements[i];
    std::vector<MVertex *> verts;
    e->getVertices(verts);
    for(std::size_t j = 0; j < verts.size(); j++) {
      if(vxv.count(verts[j])) verts[j] = vxv[verts[j]];
    }
    MElementFactory f;
    MElement *newe = f.create(e->getTypeForMSH(), verts, 0, e->getPartition());
    if(crackEdge && newe->getType() == TYPE_LIN)
      crackEdge->lines.push_back((MLine *)newe);
    else if(crackFace && newe->getType() == TYPE_TRI)
      crackFace->triangles.push_back((MTriangle *)newe);
    else if(crackFace && newe->getType() == TYPE_QUA)
      crackFace->quadrangles.push_back((MQuadrangle *)newe);
  }

  // replace vertices in elements on one side of the crack
  for(auto it = oneside.begin(); it != oneside.end(); it++) {
    MElement *e = it->first;
    for(auto i : it->second) {
      MVertex *v = e->getVertex(i);
      if(vxv.count(v))
        e->setVertex(i, vxv[v]);
      else
        Msg::Warning("Mesh node %lu not found in cracked nodes", v->getNum());
    }
  }

  if(debug) {
    std::map<int, std::vector<double> > d;
    for(auto e : oneside) {
      // 1: if node duplicated, 0: if node not duplicated
      std::vector<double> nodeDuplicated(e.first->getNumVertices(), 0.0);
      for(auto & node: e.second) nodeDuplicated[node] = 1.0;
      d[e.first->getNum()] = nodeDuplicated;
    }
    view = new PView("Positive-side elements and duplicated nodes (1: true, 0: false)",
                     "ElementNodeData", GModel::current(), d, 0, 1);
  }

  m->destroyMeshCaches();
  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}
