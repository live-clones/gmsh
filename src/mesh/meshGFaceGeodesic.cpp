#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include "meshTriangulation.h"
#include "GFace.h"
#include "discreteFace.h"
//#include "MVertexRTree.h"

//#ifdef _HAVE_GEODESIC_ALGORITHM_EXACT
// FIXME ADD THAT CODE IN CONTRIB IF IT WORKS AS WELL AS PROMISED
//#include "/Users/CODES/VTP_source_code/stdafx.h"
//#include "/Users/CODES/VTP_source_code/geodesic_mesh.h"
#include "/Users/CODES/VTP_source_code/geodesic_algorithm_exact.h" 
//#endif

// HORRIBLE FIX !!!!!
double geodesic::m_time_consumed;          //how much time does the propagation step takes
unsigned geodesic::m_queue_max_size;                       //used for statistics
unsigned geodesic::m_windows_propagation; // how many time a window is propagated
unsigned geodesic::m_windows_wavefront; // the number of windows on the wavefront
unsigned geodesic::m_windows_peak; // the maximum number of windows, used to calculate the memory           // HORRIBLE FIX !!!!!


//if (!GFace2PolyMesh(gf->tag(), &pm))return false;

bool geodesicDistanceAllToAll(PolyMesh *pm, std::vector<std::map<PolyMesh::Vertex*,double> > &all){

  all.clear();
  auto temp = pm->vertices;
  for (auto v : temp) {
    std::map<PolyMesh::Vertex*,double> ls;
    PolyMesh::VertexOnFace vof;
    vof.he = v->he;
    vof.u = -1 ; // compute distance to v
    pm->exactGeodesicDistance (vof, ls, .3);
    all.push_back(ls);
    if (all.size() % 100 == 0){
      printf("%lu/%lu\r",all.size(),temp.size());
      fflush(stdout);
    }
    //    break;
  }
  printf("\n");
  return 0;
}

// we have distances from all to all #fixme it should only be done up to a certain distance
//                  
//                  
//                                P                  
//                 x-------------x
//                  \           /
//                   \    N    /
//                    \       /                         Q
//                     \     /
//                      \   /
//                        x
//                        M
//
//     we have distances from M an P to all other vertices, the issue
//     is to find distances from N to all vertices Q. 
//     Do not forget we talk about straighest distances
//     so we can assume to remain in the plane.
//     PQ and MQ are known and NM, NP and MP can be easily computed  
//     to compute dNQ -- > we know the four sides of a quadrilateral plus one of its
//     diagonals and we look for the other one
//     mu0 = arccos ((MQ^2 + MP^2 - PQ^2) / (2 MQ*MP)) 
//     mu1 = arccos ((MP^2 + MN^2 - NP^2) / (2 MN*MP)) 
//     NQ^2 = MQ^2 + MN^2 - 2 MQ*MN cos (mu0+mu1)

PolyMesh::Path backTrack(PolyMesh *pm, std::vector<std::map<PolyMesh::Vertex*,double> > &all,
			 const PolyMesh::VertexOnFace &_start, const PolyMesh::VertexOnFace &_end){  
  
  std::map<PolyMesh::Vertex*,double> d;
  std::map<PolyMesh::Vertex*,double> dM = all[_start.he->v->data];
  std::map<PolyMesh::Vertex*,double> dP = all[_start.he->next->v->data];
  for (auto v : pm->vertices){
    double PQ = dM[v];
    double MQ = dP[v];
    double MP = _start.he->l();
    SVector3 dx = _start.point() - _start.he->v->position;
    double MN = dx.norm();
    dx = _start.point() - _start.he->next->v->position;
    double NP = dx.norm();
    double mu0 = acos ((MQ*MQ + MP*MP - PQ*PQ) / (2*MQ*MP));
    double mu1 = acos ((MP*MP + MN*MN - NP*NP) / (2*MN*MP)); 
    double NQ = sqrt(MQ*MQ + MN*MN - 2*MQ*MN*cos (mu0+mu1));
    d[v] = NQ;
  }
  return pm->backTrack (_start, _end, d);
}

bool createGeodesicMesh (GFace *gf){
  PolyMesh*pm;
  printf("createGeodesicMesh %d\n",gf->tag());
  if (GFace2PolyMesh(gf->tag(), &pm))return false;
  std::vector<std::map<PolyMesh::Vertex*,double> > all;
  if (geodesicDistanceAllToAll(pm,all))return false;        
  delete pm;
  return true;
}

#endif
