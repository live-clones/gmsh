// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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
  {GMSH_FULLRC, "Dimension", NULL, 1.},
  {GMSH_FULLRC, "PhysicalGroup", NULL, 1.},
  {GMSH_FULLRC, "OpenBoundaryPhysicalGroup", NULL, 0.},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCrackPlugin()
  {
    return new GMSH_CrackPlugin();
  }
}

std::string GMSH_CrackPlugin::getHelp() const
{
  return "Plugin(Crack) creates a crack around the physical "
    "group `PhysicalGroup' of dimension `Dimension' (1 or 2). "
    "The plugin duplicates the vertices and the elements on "
    "the crack and stores them in a new discrete curve "
    "(`Dimension' = 1) or surface (`Dimension' = 2). The "
    "elements touching the crack on the negative side "
    "are modified to use the newly generated vertices."
    "If `OpenBoundaryPhysicalGroup' is given (> 0), its "
    "vertices are duplicated and the crack will be left "
    "open on that (part of the) boundary. Otherwise, the "
    "lips of the crack are sealed, i.e., its vertices are "
    "not duplicated.";
}

int GMSH_CrackPlugin::getNbOptions() const
{
  return sizeof(CrackOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CrackPlugin::getOption(int iopt)
{
  return &CrackOptions_Number[iopt];
}

class EdgeData{
public:
  EdgeData(MEdge e) : edge(e) {}
  MEdge edge;
  std::vector<MVertex*> data;
};

struct Less_EdgeData : public std::binary_function<EdgeData, EdgeData, bool> {
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

  if(dim != 1 && dim != 2){
    Msg::Error("Crack dimension should be 1 or 2");
    return view;
  }

  GModel *m = GModel::current();
  std::map<int, std::vector<GEntity*> > groups[4];
  m->getPhysicalGroups(groups);
  std::vector<GEntity*> entities = groups[dim][physical];

  if(entities.empty()){
    Msg::Error("Physical group %d (dimension %d) is empty", physical, dim);
    return view;
  }

  std::vector<GEntity*> openEntities;
  if(open > 0){
    openEntities = groups[dim - 1][open];
    if(openEntities.empty()){
      Msg::Error("Open boundary physical group %d (dimension %d) is empty",
                 open, dim - 1);
      return view;
    }
  }

  // get crack elements
  std::vector<MElement*> crackElements;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
      crackElements.push_back(entities[i]->getMeshElement(j));

  // get internal crack vertices and boundary vertices
  std::set<MVertex*> crackVertices, bndVertices;
  if(dim == 1){
    for(unsigned int i = 0; i < crackElements.size(); i++){
      for(int j = 0; j < crackElements[i]->getNumVertices(); j++){
        MVertex *v = crackElements[i]->getVertex(j);
        crackVertices.insert(v);
      }
      for(int j = 0; j < crackElements[i]->getNumPrimaryVertices(); j++){
        MVertex *v = crackElements[i]->getVertex(j);
        if(bndVertices.find(v) == bndVertices.end())
          bndVertices.insert(v);
        else
          bndVertices.erase(v);
      }
    }
  }
  else{
    std::set<EdgeData, Less_EdgeData> bnd;
    for(unsigned int i = 0; i < crackElements.size(); i++){
      for(int j = 0; j < crackElements[i]->getNumVertices(); j++){
        MVertex *v = crackElements[i]->getVertex(j);
        crackVertices.insert(v);
      }
      for(int j = 0; j < crackElements[i]->getNumEdges(); j++){
        EdgeData ed(crackElements[i]->getEdge(j));
        if(bnd.find(ed) == bnd.end()){
          crackElements[i]->getEdgeVertices(j, ed.data);
          bnd.insert(ed);
        }
        else
          bnd.erase(ed);
      }
    }
    for(std::set<EdgeData, Less_EdgeData>::iterator it = bnd.begin(); it != bnd.end(); it++)
      bndVertices.insert(it->data.begin(), it->data.end());
  }

  // get (forced) open boundary vertices and remove them from boundary vertices
  for(unsigned int i = 0; i < openEntities.size(); i++){
    for(unsigned int j = 0; j < openEntities[i]->getNumMeshElements(); j++){
      MElement *e = openEntities[i]->getMeshElement(j);
      for(int k = 0; k < e->getNumVertices(); k++){
        MVertex *v = e->getVertex(k);
        bndVertices.erase(v);
      }
    }
  }

  for(std::set<MVertex*>::iterator it = bndVertices.begin();
      it != bndVertices.end(); it++)
    crackVertices.erase(*it);

  // compute smoothed normals on crack vertices
  std::map<MVertex*, std::vector<MElement*> > vxe;
  for(unsigned int i = 0; i < crackElements.size(); i++){
    MElement *e = crackElements[i];
    for(int k = 0; k < e->getNumVertices(); k++)
      vxe[e->getVertex(k)].push_back(e);
  }
  std::map<MVertex*, SVector3> vxn;
  for(std::map<MVertex*, std::vector<MElement*> >::iterator it = vxe.begin();
      it != vxe.end(); it++){
    SVector3 n;
    for(unsigned int i = 0; i < it->second.size(); i++){
      if(dim == 1)
        n += it->second[i]->getEdge(0).normal();
      else
        n += it->second[i]->getFace(0).normal();
    }
    n.normalize();
    vxn[it->first] = n;
  }

  // compute elements on one side of the crack
  vxe.clear();
  std::vector<GEntity*> allentities;
  m->getEntities(allentities);
  for(unsigned int ent = 0; ent < allentities.size(); ent++){
    if(allentities[ent]->dim() != dim + 1) continue;
    for(unsigned int i = 0; i < allentities[ent]->getNumMeshElements(); i++){
      MElement *e = allentities[ent]->getMeshElement(i);
      for(int j = 0; j < e->getNumVertices(); j++){
        MVertex *v = e->getVertex(j);
        if(crackVertices.find(v) != crackVertices.end()){
          MVertex *vclose = 0;
          double d = 1e22;
          SVector3 dv;
          for(std::set<MVertex*>::iterator it = crackVertices.begin();
              it != crackVertices.end(); it++){
            MVertex *v = *it;
            double d2 = v->point().distance(e->barycenter());
            if(d2 < d){
              d = d2;
              vclose = v;
              dv = SVector3(e->barycenter(), vclose->point());
            }
          }
          if(dot(vxn[vclose], dv) < 0)
            vxe[v].push_back(e);
        }
      }
    }
  }

  // create new crack entity
  GEdge *crackEdge = 0;
  GFace *crackFace = 0;
  if(dim == 1){
    crackEdge = new discreteEdge(m, m->getMaxElementaryNumber(1) + 1, 0, 0);
    m->add(crackEdge);
  }
  else{
    crackFace = new discreteFace(m, m->getMaxElementaryNumber(2) + 1);
    m->add(crackFace);
  }
  GEntity *crackEntity = crackEdge ? (GEntity*)crackEdge : (GEntity*)crackFace;
  crackEntity->physicals.push_back(physical);

  // duplicate internal crack vertices
  std::map<MVertex*, MVertex*> vxv;
  for(std::set<MVertex*>::iterator it = crackVertices.begin();
      it != crackVertices.end(); it++){
    MVertex *v = *it;
    MVertex *newv = new MVertex(v->x(), v->y(), v->z(), crackEntity);
    crackEntity->mesh_vertices.push_back(newv);
    vxv[v] = newv;
  }

  // duplicate crack elements
  for(unsigned int i = 0; i < crackElements.size(); i++){
    MElement *e = crackElements[i];
    std::vector<MVertex*> verts;
    e->getVertices(verts);
    for(unsigned int j = 0; j < verts.size(); j++){
      if(vxv.count(verts[j]))
        verts[j] = vxv[verts[j]];
    }
    MElementFactory f;
    MElement *newe = f.create(e->getTypeForMSH(), verts, 0, e->getPartition());
    if(crackEdge && newe->getType() == TYPE_LIN)
      crackEdge->lines.push_back((MLine*)newe);
    else if(crackFace && newe->getType() == TYPE_TRI)
      crackFace->triangles.push_back((MTriangle*)newe);
    else if(crackFace && newe->getType() == TYPE_QUA)
      crackFace->quadrangles.push_back((MQuadrangle*)newe);
  }

  // replace vertices in elements on one side of the crack
  std::set<MElement*> eles;
  for(std::map<MVertex*, std::vector<MElement*> >::iterator it = vxe.begin();
      it != vxe.end(); it++){
    for(unsigned int i = 0; i < it->second.size(); i++)
      eles.insert(it->second[i]);
  }
  for(std::set<MElement*>::iterator it = eles.begin(); it != eles.end(); it++){
    MElement *e = *it;
    for(int i = 0; i < e->getNumVertices(); i++){
      if(vxv.count(e->getVertex(i)))
        e->setVertex(i, vxv[e->getVertex(i)]);
    }
  }

  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}
