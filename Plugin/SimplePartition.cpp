// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "SimplePartition.h"
#include "GModel.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MFace.h"
#include "MEdge.h"
#include "mathEvaluator.h"
#if defined(HAVE_MESH)
#include "meshPartition.h"
#endif

StringXNumber SimplePartitionOptions_Number[] = {
  {GMSH_FULLRC, "NumSlices", NULL, 4.},
  {GMSH_FULLRC, "Direction", NULL, 0.},
  {GMSH_FULLRC, "CreateBoundaries", NULL, 1.},
};

StringXString SimplePartitionOptions_String[] = {
  {GMSH_FULLRC, "Mapping", NULL, "t"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSimplePartitionPlugin()
  {
    return new GMSH_SimplePartitionPlugin();
  }
}

std::string GMSH_SimplePartitionPlugin::getHelp() const
{
  return "Plugin(SimplePartition) partitions the current mesh into "
    "`NumSlices' slices, along the X-, Y- or Z-axis depending on "
    "the value of `Direction' (0,1,2). The plugin creates partition "
    "boundaries if `CreateBoundaries' is set.";
}

int GMSH_SimplePartitionPlugin::getNbOptions() const
{
  return sizeof(SimplePartitionOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SimplePartitionPlugin::getOption(int iopt)
{
  return &SimplePartitionOptions_Number[iopt];
}

int GMSH_SimplePartitionPlugin::getNbOptionsStr() const
{
  return sizeof(SimplePartitionOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_SimplePartitionPlugin::getOptionStr(int iopt)
{
  return &SimplePartitionOptions_String[iopt];
}

PView *GMSH_SimplePartitionPlugin::execute(PView *v)
{
  int numSlices = (int)SimplePartitionOptions_Number[0].def;
  int direction = (int)SimplePartitionOptions_Number[1].def;
  int createBoundaries = (int)SimplePartitionOptions_Number[2].def;
  std::vector<std::string> expr(1);
  expr[0] = SimplePartitionOptions_String[0].def;

  // partition the highest dimension elements in the current model (lower
  // dimension elements on boundaries cannot be tagged a priori: there are
  // special geometrical cases where this will fail)
  Msg::Info("Partitioning highest dimension elements");
  GModel *m = GModel::current();
  SBoundingBox3d bbox = m->bounds();
  double pmin = bbox.min()[direction], pmax = bbox.max()[direction];
  std::vector<double> pp(numSlices + 1);

  std::vector<std::string> variables(1);
  variables[0] = "t";
  mathEvaluator f(expr, variables);
  if(expr.empty()) return v;
  std::vector<double> values(1), res(1);
  for(int p = 0; p <= numSlices; p++){
    double t = values[0] = (double)p / (double)numSlices;
    if(f.eval(values, res)) t = res[0];
    pp[p] = pmin + t * (pmax - pmin);
  }
  int dim = m->getDim();
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  std::vector<std::set<MFace, Less_Face> > bndFaces(numSlices);
  std::vector<std::set<MEdge, Less_Edge> > bndEdges(numSlices);
  std::vector<std::set<MElement*> > cutElements(numSlices);
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    if(ge->dim() != dim) continue;
    for(unsigned int j = 0; j < ge->getNumMeshElements(); j++){
      MElement *e = ge->getMeshElement(j);
      double valmin = pmax;
      double valmax = pmin;
      bool bnd = false;
      for(int k = 0; k < e->getNumVertices(); k++){
        MVertex *v = e->getVertex(k);
        valmin = std::min(valmin, v->point()[direction]);
        valmax = std::max(valmax, v->point()[direction]);
        if(v->onWhat() && v->onWhat()->dim() != dim) bnd = true;
      }
      for(int p = 0; p < numSlices; p++){
        if(valmin >= pp[p] && valmin < pp[p + 1]){
          e->setPartition(p + 1);
          if(bnd){
            for(int k = 0; k < e->getNumEdges(); k++)
              bndEdges[p].insert(e->getEdge(k));
            for(int k = 0; k < e->getNumFaces(); k++)
              bndFaces[p].insert(e->getFace(k));
          }
          if(valmax >= pp[p + 1])
            cutElements[p].insert(e);
          break;
        }
      }
    }
  }
  m->recomputeMeshPartitions();

  // partition lower dimension elements
  Msg::Info("Partitioning lower dimension elements");
  std::set<MFace, Less_Face> allLowerDimFaces;
  std::set<MEdge, Less_Edge> allLowerDimEdges;
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    if(ge->dim() == dim) continue;
    for(unsigned int j = 0; j < ge->getNumMeshElements(); j++){
      MElement *e = ge->getMeshElement(j);
      if(e->getDim() == 2){
        MFace f = e->getFace(0);
        if(createBoundaries) allLowerDimFaces.insert(f);
        for(int p = 0; p < numSlices; p++){
          if(bndFaces[p].find(f) != bndFaces[p].end()){
            e->setPartition(p + 1);
            break;
          }
        }
      }
      else if(e->getDim() == 1){
        MEdge f = e->getEdge(0);
        if(createBoundaries) allLowerDimEdges.insert(f);
        for(int p = 0; p < numSlices; p++){
          if(bndEdges[p].find(f) != bndEdges[p].end()){
            e->setPartition(p + 1);
            break;
          }
        }
      }
    }
  }

  if(createBoundaries){
    Msg::Info("Creating partition boundaries");
#if 0 && defined(HAVE_MESH) // correct & general, but too slow
    CreatePartitionBoundaries(m, false, false);
    Msg::Info("Renumbering partition boundaries");
    std::vector<std::pair<double, GFace*> > parFaces;
    std::vector<std::pair<double, GEdge*> > parEdges;
    m->getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++){
      GEntity *ge = entities[i];
      if(ge->geomType() == GEntity::PartitionSurface ||
         ge->geomType() == GEntity::PartitionCurve){
        double valmin = pmax;
        for(int j = 0; j < ge->getNumMeshElements(); j++){
          MElement *e = ge->getMeshElement(j);
          for(int k = 0; k < e->getNumVertices(); k++){
            MVertex *v = e->getVertex(k);
            valmin = std::min(valmin, v->point()[direction]);
          }
        }
        if(ge->dim() == 2){
          GFace *gf = (GFace*)ge;
          parFaces.push_back(std::pair<double, GFace*>(valmin, gf));
          m->remove(gf);
        }
        else{
          GEdge *gc = (GEdge*)ge;
          parEdges.push_back(std::pair<double, GEdge*>(valmin, gc));
          m->remove(gc);
        }
      }
    }
    std::sort(parFaces.begin(), parFaces.end());
    for(unsigned int i = 0; i < parFaces.size(); i++){
      GFace *gf = parFaces[i].second;
      gf->setTag(-i-1);
      gf->setMeshMaster(-i-1);
      m->add(gf);
    }
    std::sort(parEdges.begin(), parEdges.end());
    for(unsigned int i = 0; i < parEdges.size(); i++){
      GEdge *ge = parEdges[i].second;
      ge->setTag(-i-1);
      ge->setMeshMaster(-i-1);
      m->add(ge);
    }
#else
    for(int p = 0; p < numSlices - 1; p++){
      std::vector<int> v2(2);
      v2[0] = p + 1;
      v2[1] = p + 2;
      if(dim == 2){
        // create partition edge
        partitionEdge *pe = new partitionEdge(m, -(p + 1), 0, 0, v2);
        m->add(pe);
        // compute boundary of cut surface elements
        std::set<MEdge, Less_Edge> myBndEdges;
        for(std::set<MElement*>::iterator it = cutElements[p].begin();
            it != cutElements[p].end(); it++){
          for(int i = 0; i < (*it)->getNumEdges(); i++){
            MEdge e = (*it)->getEdge(i);
            if(myBndEdges.find(e) == myBndEdges.end())
              myBndEdges.insert(e);
            else
              myBndEdges.erase(e);
          }
        }
        // keep edges whose vertices are all >= than the plane, but are not on a
        // curve of the original mesh
        for(std::set<MEdge, Less_Edge>::iterator it = myBndEdges.begin();
            it != myBndEdges.end(); it++){
          bool bnd = true;
          for(int j = 0; j < it->getNumVertices(); j++){
            if(it->getVertex(j)->point()[direction] < pp[p + 1]){
              bnd = false;
              break;
            }
          }
          if(bnd){
            if(allLowerDimEdges.find(*it) == allLowerDimEdges.end()){
              pe->lines.push_back(new MLine(it->getVertex(0), it->getVertex(1)));
            }
          }
        }
      }
      if(dim == 3){
        // create partition face
        partitionFace *pf = new partitionFace(m, -(p + 1), v2);
        m->add(pf);
        // compute boundary of cut elements
        std::set<MFace, Less_Face> myBndFaces;
        for(std::set<MElement*>::iterator it = cutElements[p].begin();
            it != cutElements[p].end(); it++){
          for(int i = 0; i < (*it)->getNumFaces(); i++){
            MFace f = (*it)->getFace(i);
            if(myBndFaces.find(f) == myBndFaces.end())
              myBndFaces.insert(f);
            else
              myBndFaces.erase(f);
          }
        }
        // keep faces whose vertices are all >= than the plane, but are not on a
        // surface of the original mesh
        for(std::set<MFace, Less_Face>::iterator it = myBndFaces.begin();
            it != myBndFaces.end(); it++){
          bool bnd = true;
          for(int j = 0; j < it->getNumVertices(); j++){
            if(it->getVertex(j)->point()[direction] < pp[p + 1]){
              bnd = false;
              break;
            }
          }
          if(bnd){
            if(allLowerDimFaces.find(*it) == allLowerDimFaces.end()){
              if (it->getNumVertices() == 3)
                pf->triangles.push_back
                  (new MTriangle(it->getVertex(0), it->getVertex(1), it->getVertex(2)));
              else
                pf->quadrangles.push_back
                  (new MQuadrangle(it->getVertex(0), it->getVertex(1),
                                   it->getVertex(2), it->getVertex(3)));
            }
          }
        }
      }
    }
#endif
  }

  return v;
}
