// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteFace.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "Geo.h"
#include "GFaceCompound.h"
#include "Context.h"
#include "OS.h"

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

void discreteFace::setBoundEdges(std::vector<int> tagEdges)
{
  for (std::vector<int>::iterator it = tagEdges.begin(); it != tagEdges.end(); it++){
    GEdge *ge = GModel::current()->getEdgeByTag(*it);
    l_edges.push_back(ge);
    l_dirs.push_back(1);
    ge->addFace(this);
  }
}

void discreteFace::findEdges(std::map<MEdge, std::vector<int>, Less_Edge> &map_edges)
{
  std::set<MEdge, Less_Edge> bound_edges;
  for (unsigned int iFace = 0; iFace  < getNumMeshElements(); iFace++) {
    MElement *e = getMeshElement(iFace);
    for (int iEdge = 0; iEdge < e->getNumEdges(); iEdge++) {
      MEdge tmp_edge = e->getEdge(iEdge);
      std::set<MEdge, Less_Edge >::iterator itset = bound_edges.find(tmp_edge);
      if(itset == bound_edges.end())
        bound_edges.insert(tmp_edge);
      else
        bound_edges.erase(itset);
    }
  }

  // for the boundary edges, associate the tag of the discrete face
  for (std::set<MEdge, Less_Edge>::iterator itv = bound_edges.begin();
       itv != bound_edges.end(); ++itv){
    std::map<MEdge, std::vector<int>, Less_Edge >::iterator itmap = map_edges.find(*itv);
    if (itmap == map_edges.end()){
      std::vector<int> tagFaces;
      tagFaces.push_back(tag());
      map_edges.insert(std::make_pair(*itv, tagFaces));
    }
    else{
      std::vector<int> tagFaces = itmap->second;
      tagFaces.push_back(tag());
      itmap->second = tagFaces;
    }
  }
}

GPoint discreteFace::point(double par1, double par2) const
{
  Msg::Error("Cannot evaluate point on discrete face");
  return GPoint();
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface) const
{
  if (getCompound()){
    return getCompound()->parFromPoint(p);
  }
  else{
    Msg::Error("Cannot compute parametric coordinates on discrete face");
    return SPoint2();
  }
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
  if (getCompound()){
    return getCompound()->normal(param);
  }
  else{
    Msg::Error("Cannot evaluate normal on discrete face");
    return SVector3();
  }
}

double discreteFace::curvatureMax(const SPoint2 &param) const
{
  if (getCompound()){
    return getCompound()->curvatureMax(param);
  }
  else{
    Msg::Error("Cannot evaluate curvature on discrete face");
    return false;
  }
}

double discreteFace::curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                double *curvMax, double *curvMin) const
{
  if (getCompound()){
    return getCompound()->curvatures(param, dirMax, dirMin, curvMax, curvMin);
  }
  else{
    Msg::Error("Cannot evaluate curvatures and curvature directions on discrete face");
    return false;
  }
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
  if (getCompound()){
    return getCompound()->firstDer(param);
  }
  else{
    Msg::Error("Cannot evaluate derivative on discrete face");
    return Pair<SVector3, SVector3>();
  }
}

void discreteFace::secondDer(const SPoint2 &param,
                             SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  if (getCompound()){
    return getCompound()->secondDer(param, dudu, dvdv, dudv);
  }
  else{
    Msg::Error("Cannot evaluate second derivative on discrete face");
    return;
  }
}

void discreteFace::writeGEO(FILE *fp)
{
  fprintf(fp, "Discrete Face(%d) = {",tag());
  int count = 0;
  for (std::list<GEdge*>::iterator it = l_edges.begin();
       it != l_edges.end() ;++it){
    if (count == 0)fprintf(fp, "%d",(*it)->tag());    
    else fprintf(fp, ",%d",(*it)->tag());    
    count ++;
  }
  fprintf(fp, "};\n");    
}
