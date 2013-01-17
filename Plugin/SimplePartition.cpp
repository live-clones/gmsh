// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "SimplePartition.h"
#include "GModel.h"
#include "MElement.h"
#include "MFace.h"
#include "MEdge.h"
#if defined(HAVE_MESH)
#include "meshPartition.h"
#endif

StringXNumber SimplePartitionOptions_Number[] = {
  {GMSH_FULLRC, "NumSlices", NULL, 4.},
  {GMSH_FULLRC, "Direction", NULL, 0.},
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
    "the value of `Direction' (0,1,2).";
}

int GMSH_SimplePartitionPlugin::getNbOptions() const
{
  return sizeof(SimplePartitionOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SimplePartitionPlugin::getOption(int iopt)
{
  return &SimplePartitionOptions_Number[iopt];
}

PView *GMSH_SimplePartitionPlugin::execute(PView *v)
{
  int numSlices = (int)SimplePartitionOptions_Number[0].def;
  int direction = (int)SimplePartitionOptions_Number[1].def;

  // partition the highest dimension elements in the current model (lower
  // dimension elements en boundaries cannot be tagged a priori: there are
  // special geometrical cases)
  GModel *m = GModel::current();
  SBoundingBox3d bbox = m->bounds();
  double pmin = bbox.min()[direction], pmax = bbox.max()[direction];
  int dim = m->getDim();
  std::vector<GEntity*> entities;
  m->getEntities(entities);
  std::map<int, std::set<MFace, Less_Face> > bndFaces;
  std::map<int, std::set<MEdge, Less_Edge> > bndEdges;
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    if(ge->dim() != dim) continue;
    for(int j = 0; j < ge->getNumMeshElements(); j++){
      MElement *e = ge->getMeshElement(j);
      double val = pmax;
      bool bnd = false;
      for(int k = 0; k < e->getNumVertices(); k++){
        MVertex *v = e->getVertex(k);
        val = std::min(val, v->point()[direction]);
        if(v->onWhat() && v->onWhat()->dim() != dim) bnd = true;
      }
      for(int p = 0; p < numSlices; p++){
        double p1 = pmin + p * (pmax - pmin) / numSlices;
        double p2 = pmin + (p + 1) * (pmax - pmin) / numSlices;
        if(val >= p1 && val < p2){
          e->setPartition(p + 1);
          if(bnd){
            for(int k = 0; k < e->getNumEdges(); k++)
              bndEdges[p + 1].insert(e->getEdge(k));
            for(int k = 0; k < e->getNumFaces(); k++)
              bndFaces[p + 1].insert(e->getFace(k));
          }
          break;
        }
      }
    }
  }
  m->recomputeMeshPartitions();

  // partition lower dimension elements
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    if(ge->dim() == dim) continue;
    for(int j = 0; j < ge->getNumMeshElements(); j++){
      MElement *e = ge->getMeshElement(j);
      if(e->getDim() == 2){
        MFace f = e->getFace(0);
        for(int p = 0; p < numSlices; p++){
          if(bndFaces[p + 1].find(f) != bndFaces[p + 1].end()){
            e->setPartition(p + 1);
            break;
          }
        }
      }
      else if(e->getDim() == 1){
        MEdge f = e->getEdge(0);
        for(int p = 0; p < numSlices; p++){
          if(bndEdges[p + 1].find(f) != bndEdges[p + 1].end()){
            e->setPartition(p + 1);
            break;
          }
        }
      }
    }
  }

  // create partition boundaries
#if defined(HAVE_MESH)
  CreatePartitionBoundaries(m, false, false);
#endif

  // renumber partition boundaries using the natural slicing order
  std::vector<std::pair<double, GFace*> > parFaces;
  std::vector<std::pair<double, GEdge*> > parEdges;
  m->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    if(ge->geomType() == GEntity::PartitionSurface ||
       ge->geomType() == GEntity::PartitionCurve){
      double val = pmax;
      for(int j = 0; j < ge->getNumMeshElements(); j++){
        MElement *e = ge->getMeshElement(j);
        for(int k = 0; k < e->getNumVertices(); k++){
          MVertex *v = e->getVertex(k);
          val = std::min(val, v->point()[direction]);
        }
      }
      if(ge->dim() == 2){
        GFace *gf = (GFace*)ge;
        parFaces.push_back(std::pair<double, GFace*>(val, gf));
        m->remove(gf);
      }
      else{
        GEdge *gc = (GEdge*)ge;
        parEdges.push_back(std::pair<double, GEdge*>(val, gc));
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

  return v;
}
