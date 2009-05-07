// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteFace.h"
#include "MTriangle.h"
#include "MEdge.h"

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
#endif
  meshStatistics.status = GFace::DONE;    
}

void discreteFace::setBoundEdges(std::vector<discreteEdge*> discr_edges)
{

 printf("***** In discrete Face:  \n");

  printf("bound edges =%d \n", edges().size());

  for (std::vector<discreteEdge*>::iterator it = discr_edges.begin(); it != discr_edges.end(); it++) {
    l_edges.push_back(*it);
    l_dirs.push_back(1);
    (*it)->addFace(this);
    printf("add Face %d for edge %d\n",this->tag(), (*it)->tag() );
  }

  printf("bound edges =%d \n", edges().size());

//   std::list<MVertex*> mesh_vertices;
//   std::list<MVertex*> temp_vertices;
//   std::list<MEdge> bound_edges;
//   for (int iFace = 0; iFace  < getNumMeshElements() ; iFace++) {
//     std::vector<MVertex*> fv;
//     MElement *e = getMeshElement(iFace);
//     e->getFaceVertices(0, fv);
//     for (std::vector<MVertex*>::iterator it_fv = fv.begin(); it_fv != fv.end(); it_fv++) {
//       if (std::find(mesh_vertices.begin(), mesh_vertices.end(), *it_fv) == mesh_vertices.end())
// 	mesh_vertices.push_back(*it_fv);
//     }
//     for (int iEdge = 0; iEdge < e->getNumEdges(); iEdge++) {
//       MEdge tmp_edge =  e->getEdge(iEdge);
//       if (std::find(bound_edges.begin(),bound_edges.end(),tmp_edge) == bound_edges.end()) 
// 	bound_edges.push_back(tmp_edge);
//       elsex
// 	bound_edges.erase(std::find(bound_edges.begin(),bound_edges.end(),tmp_edge));
//     }
//   }
//   printf( "There are %d msh vertices and bound %d msh edges \n ",  mesh_vertices.size(), bound_edges.size());

  // for (std::list<MVertex *>::iterator mesh_vertex = mesh_vertices.begin(); mesh_vertex != mesh_vertices.end(); mesh_vertex++) {
  //  printf("mesh vertex on entity with tag %d\n", (*mesh_vertex)->onWhat()->tag());
  //}


//   std::list<GEdge*> adj_edges;
//   for (std::list<MEdge>::iterator be = bound_edges.begin(); be != bound_edges.end(); be++) {
//     MVertex *v0 = be->getVertex(0);
//     MVertex *v1 = be->getVertex(1);
//     printf("bound edge on entity with num=%d, tag %d (dim=%d) et num=%d tag %d (dim=%d) \n", v0->getNum(), v0->onWhat()->tag(), v0->onWhat()->dim(),v1->getNum(), v1->onWhat()->tag(), v0->onWhat()->dim());
//   }

  
  
    //exit(1);

}


GPoint discreteFace::point(double par1, double par2) const 
{
  Msg::Error("Cannot evaluate point on discrete face");
  return GPoint();
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p) const
{
  Msg::Error("Cannot compute parametric coordinates on discrete face");
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
