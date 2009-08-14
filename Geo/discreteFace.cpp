// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteFace.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "Geo.h"

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;    
}


void discreteFace::findEdges(std::map<MEdge, std::vector<int>, Less_Edge > &map_edges)
{
  //find the boundary edges

  std::list<MEdge> bound_edges;
  for (unsigned int iFace = 0; iFace  < getNumMeshElements() ; iFace++) {
    std::vector<MVertex*> fv;
    MElement *e = getMeshElement(iFace);
    e->getFaceVertices(0, fv);
    for (int iEdge = 0; iEdge < e->getNumEdges(); iEdge++) {
      MEdge tmp_edge =  e->getEdge(iEdge);
      if (std::find(bound_edges.begin(),bound_edges.end(),tmp_edge) == bound_edges.end())       
        bound_edges.push_back(tmp_edge);
      else
        bound_edges.erase(std::find(bound_edges.begin(),bound_edges.end(),tmp_edge));
    }
  }
 
  //for the boundary edges, associate the tag of the current discrete face
  for (std::list<MEdge>::iterator itv = bound_edges.begin() ; itv != bound_edges.end() ; ++itv){
    std::map<MEdge, std::vector<int> , Less_Edge >::iterator itmap = map_edges.find(*itv);
    if (itmap == map_edges.end())   {
      std::vector<int> tagFaces; 
      tagFaces.push_back(this->tag());
      map_edges.insert(std::make_pair(*itv,tagFaces));   
    }
    else{
      std::vector<int> tagFaces = itmap->second;
      tagFaces.push_back(this->tag());
      itmap->second = tagFaces;
      //printf("addface %d %d\n", tagFaces[0], tagFaces[1]);
    }
 }

  //printf( "There are  %d bound msh edges \n ",  map_edges.size());
}

void discreteFace::setBoundEdges(std::vector<int> tagEdges)
{

  // printf("***** In discrete Face:  \n");

 for (std::vector<int>::iterator it = tagEdges.begin(); it != tagEdges.end(); it++) {
   GEdge *ge = GModel::current()->getEdgeByTag(abs(*it));
   l_edges.push_back(ge);
   l_dirs.push_back(1);
   ge->addFace(this);
   //printf("for Face %d add bound edge %d\n",this->tag(), ge->tag() );
 }

 //  printf("bound edges =%d \n", edges().size());
}

GPoint discreteFace::point(double par1, double par2) const 
{
  Msg::Error("Cannot evaluate point on discrete face");
  return GPoint();
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p) const
{

  //Msg::Error("Cannot compute parametric coordinates on discrete face");
  return SPoint2();
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
  Msg::Error("Cannot evaluate normal on discrete face");
  return SVector3();
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
  Msg::Error("Cannot evaluate derivative on discrete face");
  return Pair<SVector3, SVector3>();
}

void discreteFace::secondDer(const SPoint2 &param, 
                             SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  Msg::Error("Cannot evaluate derivative on discrete face");
}
