// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  {GMSH_FULLRC, "NormalX", nullptr, 0.},
  {GMSH_FULLRC, "NormalY", nullptr, 0.},
  {GMSH_FULLRC, "NormalZ", nullptr, 1.}};

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
         "elements touching the crack on the ``negative'' side "
         "are modified to use the newly generated nodes."
         "If `OpenBoundaryPhysicalGroup' is given (> 0), its "
         "nodes are duplicated and the crack will be left "
         "open on that (part of the) boundary. Otherwise, the "
         "lips of the crack are sealed, i.e., its nodes are "
         "not duplicated. For 1D cracks, `NormalX', `NormalY' and "
         "`NormalZ' provide the reference normal of the surface "
         "in which the crack is supposed to be embedded.";
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
  SVector3 normal1d(CrackOptions_Number[3].def, CrackOptions_Number[4].def,
                    CrackOptions_Number[5].def);

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

  std::set<GEntity *> crackEntities;
  crackEntities.insert(entities.begin(), entities.end());
  crackEntities.insert(openEntities.begin(), openEntities.end());

  // get crack elements
  std::vector<MElement *> crackElements;
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
      crackElements.push_back(entities[i]->getMeshElement(j));

  // get internal crack nodes and boundary nodes
  std::set<MVertex *> crackVertices, bndVertices;
  if(dim == 1) {
    for(std::size_t i = 0; i < crackElements.size(); i++) {
      for(std::size_t j = 0; j < crackElements[i]->getNumVertices(); j++) {
        MVertex *v = crackElements[i]->getVertex(j);
        crackVertices.insert(v);
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
        crackVertices.insert(v);
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

  // compute elements on one side of the crack
  std::set<MElement *> oneside;
  std::vector<GEntity *> allentities;
  m->getEntities(allentities);
  for(std::size_t ent = 0; ent < allentities.size(); ent++) {
    if(crackEntities.find(allentities[ent]) != crackEntities.end()) continue;
    for(std::size_t i = 0; i < allentities[ent]->getNumMeshElements(); i++) {
      MElement *e = allentities[ent]->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        if(crackVertices.find(e->getVertex(j)) != crackVertices.end()) {
          // element touches the crack: find the closest crack element
          SPoint3 b = e->barycenter();
          double d = 1e200;
          MElement *ce = nullptr;
          for(std::size_t k = 0; k < crackElements.size(); k++) {
            double d2 = b.distance(crackElements[k]->barycenter());
            if(d2 < d) {
              d = d2;
              ce = crackElements[k];
            }
          }
          SVector3 dv = SVector3(e->barycenter(), ce->barycenter());
          SVector3 n;
          if(dim == 1)
            n = crossprod(normal1d, ce->getEdge(0).tangent());
          else
            n = ce->getFace(0).normal();
          if(dot(n, dv) < 0) { oneside.insert(e); }
        }
      }
    }
  }

  /*
  FILE *fp = fopen("debug.pos", "w");
  if(fp){
    fprintf(fp, "View \"Ele < 0\" {\n");
    for(auto it = oneside.begin(); it != oneside.end(); it++)
      (*it)->writePOS(fp, false, true, false, false, false, false);
    fprintf(fp, "};\n");
    fclose(fp);
  }
  */

  // create new crack entity

  // TODO: the new discrete entities do not have a consistent topology: we don't
  // specify their bounding points/curves
  //   a) This is easy to fix if there's no OpenBoundaryPhysicalGroup and
  //      we crack a *single* elementary entity
  //   b) If there is an open boundary, we need to create a new elementary
  //      entity on the boundary, and correctly classify the nodes on it...
  //      and we also need to create boundary elements
  //   c) If we crack a group made of multiple elementary entities we might
  //      want to create multiple crackes entities, and do the same as (b)
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
  crackEntity->physicals.push_back(physical);

  // duplicate internal crack nodes
  std::map<MVertex *, MVertex *> vxv;
  for(auto it = crackVertices.begin(); it != crackVertices.end(); it++) {
    MVertex *v = *it;
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
    MElement *e = *it;
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      if(vxv.count(e->getVertex(i))) e->setVertex(i, vxv[e->getVertex(i)]);
    }
  }

  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}
