// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "meshGRegionLocalMeshMod.h"
#include "GEntity.h"
#include "GRegion.h"
#include "GmshMessage.h"
#include "Numeric.h"

static int edges[6][2] =    {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
static int efaces[6][2] =   {{0,2},{0,1},{1,2},{0,3},{2,3},{1,3}};
//static int enofaces[6][2] = {{1,3},{2,3},{0,3},{1,2},{0,1},{0,2}};
//static int facesXedges[4][3] = {{0,1,3},{1,2,5},{0,2,4},{3,4,5}};
static int faces[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};
static int vnofaces[4] = {3,1,2,0};
static int vFac[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};

// as input, we give a tet and an edge, as return, we get
// all tets that share this edge and all vertices that are
// forming the outer ring of the cavity 
// we return true if the cavity is closed and false if it is open

void computeNeighboringTetsOfACavity(const std::vector<MTet4*> &cavity,
                                     std::vector<MTet4*> &outside)
{
  outside.clear();
  for (unsigned int i = 0; i < cavity.size(); i++){
    for (int j = 0; j < 4; j++){
      MTet4 * neigh = cavity[i]->getNeigh(j);
      if(neigh){
        bool found = false;
        for (unsigned int k = 0; k < outside.size(); k++){
          if(outside[k] == neigh){
            found = true;
            break;
          }
        }
        if(!found){
          for (unsigned int k = 0; k < cavity.size(); k++){
            if(cavity[k] == neigh){
              found = true;
            }
          }
        }
        if(!found)outside.push_back(neigh);
      }
    }
  }
}
                   
bool gmshBuildEdgeCavity(MTet4 *t, 
                         int iLocalEdge, 
                         MVertex **v1,MVertex **v2,
                         std::vector<MTet4*> &cavity,
                         std::vector<MTet4*> &outside,
                         std::vector<MVertex*> &ring)
{
  cavity.clear();
  ring.clear();

  *v1 = t->tet()->getVertex(edges[iLocalEdge][0]);
  *v2 = t->tet()->getVertex(edges[iLocalEdge][1]);

  MVertex *lastinring = t->tet()->getVertex(edges[5 - iLocalEdge][0]);
  ring.push_back(lastinring);
  cavity.push_back(t);

  while (1){
    MVertex *ov1 = t->tet()->getVertex(edges[5 - iLocalEdge][0]);
    MVertex *ov2 = t->tet()->getVertex(edges[5 - iLocalEdge][1]);
    int K = ov1 == lastinring ? 1 : 0;
    lastinring = ov1 == lastinring ? ov2 : ov1;
    // look in the 2 faces sharing this edge the one that has vertex 
    // ov2 i.e. edges[5-iLocalEdge][1]
    int iFace;
    int iFace1 = efaces[iLocalEdge][0];
    int iFace2 = efaces[iLocalEdge][1];
    if (faces[iFace1][0] == edges[5-iLocalEdge][K] ||
        faces[iFace1][1] == edges[5-iLocalEdge][K] ||
        faces[iFace1][2] == edges[5-iLocalEdge][K] ) iFace = iFace1;
    else if (faces[iFace2][0] == edges[5-iLocalEdge][K] ||
             faces[iFace2][1] == edges[5-iLocalEdge][K] ||
             faces[iFace2][2] == edges[5-iLocalEdge][K] ) iFace = iFace2;
    else { Msg::Error("Error of connexion"); return false; }
    t=t->getNeigh(iFace);
    if (!t) return false;
    if (t->isDeleted()){ Msg::Error("Weird!!"); return false; }
    if (t == cavity[0]) break;
    ring.push_back(lastinring);    
    cavity.push_back(t);
    iLocalEdge = -1;
    for (int i = 0; i < 6; i++){
      MVertex *a = t->tet()->getVertex(edges[i][0]);
      MVertex *b = t->tet()->getVertex(edges[i][1]);
      if ((a == *v1 && b == *v2) || (a == *v2 && b == *v1)){
        iLocalEdge = i;
        break;
      }
    }  
    if (iLocalEdge == -1){
      Msg::Error("loc = %d", iLocalEdge);
      return false;
    }
  }
  computeNeighboringTetsOfACavity (cavity,outside);
  return true;
}

typedef struct {
  int nbr_triangles ;           /* number of different triangles       */
  int (*triangles)[3] ;         /* triangles array                     */
  int nbr_trianguls ;           /* number of different triangulations  */
  int nbr_triangles_2 ;         /* number of triangles / triangulation */
  int (*trianguls)[5] ;         /* retriangulations array              */
} SwapPattern ;

void BuildSwapPattern3(SwapPattern *sc)
{
  static int trgl[][3] = { {0,1,2} };
  static int trgul[][5] = { {0,-1,-1,-1,-1} };

  sc->nbr_triangles = 1 ;
  sc->nbr_triangles_2 = 1 ;
  sc->nbr_trianguls = 1 ;
  sc->triangles = trgl ;
  sc->trianguls = trgul ;
}

void BuildSwapPattern4(SwapPattern *sc)
{
  static int trgl[][3] =
    { {0,1,2}, {0,2,3}, {0,1,3}, {1,2,3} };
  static int trgul[][5] = 
    { {0,1,-1,-1,-1}, {2,3,-1,-1,-1} };

  sc->nbr_triangles = 4 ;
  sc->nbr_triangles_2 = 2 ; 
  sc->nbr_trianguls = 2 ; 
  sc->triangles = trgl ;
  sc->trianguls = trgul ;
}

void BuildSwapPattern5(SwapPattern *sc)
{
  static int trgl[][3] = 
    { {0,1,2}, {0,2,3}, {0,3,4}, {0,1,4}, {1,3,4}, 
      {1,2,3}, {2,3,4}, {0,2,4}, {0,1,3}, {1,2,4} };
  static int trgul[][5] =
    { {0,1,2,-1,-1}, {3,4,5,-1,-1}, {0,6,7,-1,-1}, {2,5,8,-1,-1}, {3,6,9,-1,-1} };

  sc->nbr_triangles = 10 ;
  sc->nbr_triangles_2 = 3 ;
  sc->nbr_trianguls = 5 ;
  sc->triangles = trgl ;
  sc->trianguls = trgul ; 
}

void BuildSwapPattern6(SwapPattern *sc)
{
  static int trgl[][3] = 
    { {0,1,2}, {0,2,3}, {0,3,4}, {0,4,5}, {0,2,5}, {2,4,5}, {2,3,4}, {0,3,5},
      {3,4,5}, {0,2,4}, {2,3,5}, {1,2,3}, {0,1,3}, {0,1,5}, {1,4,5}, {1,3,4},
      {0,1,4}, {1,3,5}, {1,2,4}, {1,2,5} };
  static int trgul[][5] = 
    { {0,1,2,3,-1}, {0,4,5,6,-1}, {0,1,7,8,-1}, {0,3,6,9,-1}, {0,4,8,10,-1},
      {2,3,11,12,-1}, {11,13,14,15,-1}, {7,8,11,12,-1}, {3,11,15,16,-1},
      {8,11,13,17,-1}, {6,13,14,18,-1}, {3,6,16,18,-1}, {5,6,13,19,-1}, 
      {8,10,13,19,-1} };

  sc->nbr_triangles = 20 ; 
  sc->nbr_triangles_2 = 4 ; 
  sc->nbr_trianguls = 14 ; 
  sc->triangles = trgl ; 
  sc->trianguls = trgul ;
}

void BuildSwapPattern7(SwapPattern *sc)
{
  static int trgl[][3] = 
    { {0,1,2}, {0,2,3}, {0,3,4}, {0,4,5}, {0,5,6}, {0,3,6}, {3,5,6}, {3,4,5}, {0,4,6},
      {4,5,6}, {0,3,5}, {3,4,6}, {0,2,4}, {2,3,4}, {0,2,6}, {2,5,6}, {2,4,5}, {0,2,5},
      {2,4,6}, {2,3,5}, {2,3,6}, {0,1,3}, {1,2,3}, {0,1,4}, {1,3,4}, {0,1,6}, {1,5,6},
      {1,4,5}, {0,1,5}, {1,4,6}, {1,3,5}, {1,3,6}, {1,2,4}, {1,2,5}, {1,2,6} };
  static int trgul[][5] = 
    { {0,1,2,3,4}, {0,1,5,6,7}, {0,1,2,8,9}, {0,1,4,7,10}, {0,1,5,9,11}, {0,3,4,12,13},
      {0,13,14,15,16}, {0,8,9,12,13}, {0,4,13,16,17}, {0,9,13,14,18}, {0,7,14,15,19},
      {0,4,7,17,19}, {0,6,7,14,20}, {0,9,11,14,20}, {2,3,4,21,22}, {5,6,7,21,22},
      {2,8,9,21,22}, {4,7,10,21,22}, {5,9,11,21,22}, {3,4,22,23,24}, {22,24,25,26,27},
      {8,9,22,23,24}, {4,22,24,27,28}, {9,22,24,25,29}, {7,22,25,26,30}, {4,7,22,28,30},
      {6,7,22,25,31}, {9,11,22,25,31}, {3,4,13,23,32}, {13,25,26,27,32}, {8,9,13,23,32},
      {4,13,27,28,32}, {9,13,25,29,32}, {13,16,25,26,33}, {4,13,16,28,33},
      {13,15,16,25,34}, {9,13,18,25,34}, {7,19,25,26,33}, {4,7,19,28,33},
      {7,15,19,25,34}, {6,7,20,25,34}, {9,11,20,25,34} };

  sc->nbr_triangles = 35 ;
  sc->nbr_triangles_2 = 5 ;
  sc->nbr_trianguls = 42 ;
  sc->triangles = trgl ;
  sc->trianguls = trgul ;
}

bool gmshEdgeSwap(std::vector<MTet4 *> &newTets,
                  MTet4 *tet, 
                  int iLocalEdge,
                  const gmshQualityMeasure4Tet &cr)
{
  std::vector<MTet4*> cavity;
  std::vector<MTet4*> outside;
  std::vector<MVertex*> ring;
  MVertex *v1, *v2;

  bool closed = gmshBuildEdgeCavity(tet, iLocalEdge, &v1, &v2, cavity, outside, ring);

  if (!closed) return false;
  
  double volumeRef = 0.0;
  double tetQualityRef = 1;
  for(unsigned int i = 0; i < cavity.size(); i++){
    double vol = fabs(cavity[i]->tet()->getVolume());
    tetQualityRef = std::min(tetQualityRef,cavity[i]->getQuality());
    volumeRef += vol;
  }

  // build swap patterns

  SwapPattern sp;
  switch (ring.size()){
  case 3 : BuildSwapPattern3(&sp); break;
  case 4 : BuildSwapPattern4(&sp); break;
  case 5 : BuildSwapPattern5(&sp); break;
  case 6 : BuildSwapPattern6(&sp); break;
  case 7 : BuildSwapPattern7(&sp); break;
  default : return false;
  }

  // compute qualities of all tets that appear in the patterns
  double tetQuality1[100], tetQuality2[100];
  double volume1[100], volume2[100];
  for (int i = 0; i < sp.nbr_triangles; i++){
    int p1 = sp.triangles[i][0];
    int p2 = sp.triangles[i][1];
    int p3 = sp.triangles[i][2];   
    tetQuality1[i] = qmTet(ring[p1], ring[p2], ring[p3], v1, cr, &(volume1[i]));
    tetQuality2[i] = qmTet(ring[p1], ring[p2], ring[p3], v2, cr, &(volume2[i]));  
  }

  // look for the best triangulation, i.e. the one that maximize the
  // minimum element quality
  double minQuality[100];
  // for all triangulations
  for (int i = 0; i < sp.nbr_trianguls; i++){
    // for all triangles in a triangulation
    minQuality[i] = 1;
    double volume = 0;
    for (int j = 0; j < sp.nbr_triangles_2; j++){
      int iT = sp.trianguls[i][j];
      minQuality[i] = std::min(minQuality[i], tetQuality1[iT]);
      minQuality[i] = std::min(minQuality[i], tetQuality2[iT]);
      volume += (volume1[iT] + volume2[iT]);
    }
    // printf("config %3d qual %12.5E volume %12.5E\n",i,minQuality[i],volume);
    if (fabs(volume-volumeRef) > 1.e-10 * (volume+volumeRef)) minQuality[i] = -1;
  }

  int iBest = 0;
  double best = -1.0;
  for (int i = 0; i < sp.nbr_trianguls; i++){
    if(minQuality[i] > best){
      best = minQuality[i];
      iBest = i;
    }
  }

  // if there exist no swap that enhance the quality
  if (best <= tetQualityRef) return false;
  
  // we have the best configuration, so we swap
  // printf("outside size = %d\n",outside.size());

  // printf("a swap with %d tets reconnect %d tets cavity %d tets\n",
  // ring.size(),outside.size(),cavity.size());

  for (int j = 0; j < sp.nbr_triangles_2; j++){
    int iT = sp.trianguls[iBest][j];
    int p1 = sp.triangles[iT][0];
    int p2 = sp.triangles[iT][1];
    int p3 = sp.triangles[iT][2];  
    MVertex *pv1 = ring[p1];
    MVertex *pv2 = ring[p2];
    MVertex *pv3 = ring[p3];
    MTetrahedron *tr1 = new MTetrahedron(pv1, pv2, pv3, v1);
    MTetrahedron *tr2 = new MTetrahedron (pv3, pv2, pv1, v2);
    MTet4 *t41 = new MTet4(tr1, tetQuality1[iT]); 
    MTet4 *t42 = new MTet4(tr2, tetQuality2[iT]);
    t41->setOnWhat(cavity[0]->onWhat());
    t42->setOnWhat(cavity[0]->onWhat());
    outside.push_back(t41);
    outside.push_back(t42);
    newTets.push_back(t41);
    newTets.push_back(t42);
  }

  for(unsigned int i = 0; i < cavity.size(); i++) cavity[i]->setDeleted(true);
  
  connectTets(outside);

  return true;
}

bool gmshEdgeSplit(std::vector<MTet4 *> &newTets,
                   MTet4 *tet,
                   MVertex *newVertex,
                   int iLocalEdge,
                   const gmshQualityMeasure4Tet &cr)
{
  std::vector<MTet4*> cavity;
  std::vector<MTet4*> outside;
  std::vector<MVertex*> ring;
  MVertex *v1, *v2;

  bool closed = gmshBuildEdgeCavity(tet, iLocalEdge, &v1, &v2, cavity, outside, ring);
  if (!closed) return false;
  
  for(unsigned int j = 0; j < ring.size(); j++){
    MVertex *pv1 = ring[j];
    MVertex *pv2 = ring[(j + 1) % ring.size()];
    MTetrahedron *tr1 = new MTetrahedron(pv1, pv2, newVertex, v1);
    MTetrahedron *tr2 = new MTetrahedron(newVertex, pv2, pv1, v2);
    MTet4 *t41 = new MTet4(tr1, cr); 
    MTet4 *t42 = new MTet4(tr2, cr);
    t41->setOnWhat(cavity[0]->onWhat());
    t42->setOnWhat(cavity[0]->onWhat());
    outside.push_back(t41);
    outside.push_back(t42);
    newTets.push_back(t41);
    newTets.push_back(t42);
  }

  for(unsigned int i = 0; i < cavity.size(); i++) cavity[i]->setDeleted(true);
  
  connectTets(outside);

  return true;
}

// swap a face i.e. remove a face shared by 2 tets
bool gmshFaceSwap(std::vector<MTet4 *> &newTets,
                  MTet4 *t1, 
                  int iLocalFace,
                  const gmshQualityMeasure4Tet &cr)
{
  MTet4 *t2 = t1->getNeigh(iLocalFace);
  if (!t2) return false;
  if (t1->onWhat() != t2->onWhat()) return false;

  MVertex *v1 = t1->tet()->getVertex(vnofaces[iLocalFace]);
  MVertex *f1 = t1->tet()->getVertex(faces[iLocalFace][0]);
  MVertex *f2 = t1->tet()->getVertex(faces[iLocalFace][1]);
  MVertex *f3 = t1->tet()->getVertex(faces[iLocalFace][2]);
  MVertex *v2 = 0;
  for (int i = 0; i < 4; i++){
    MVertex *v = t2->tet()->getVertex(i);
    if (v != f1 && v != f2 && v != f3){
      v2 = v;
      break;
    }
  }
  if (!v2){
    Msg::Error("Impossible to swap face");
    return false;
  }

  // printf("%p %p -- %p %p %p\n",v1,v2,f1,f2,f3);

  double vol1 = fabs(t1->tet()->getVolume());
  double q1 = t1->getQuality();
  double vol2 = fabs(t2->tet()->getVolume());
  double q2 = t2->getQuality();
  
  double vol3;
  double q3 = qmTet(f1, f2, v1, v2, cr, &vol3);
  double vol4;
  double q4 = qmTet(f2, f3, v1, v2, cr, &vol4);
  double vol5;
  double q5 = qmTet(f3, f1, v1, v2, cr, &vol5);


  if (fabs(vol1 + vol2 - vol3 - vol4 - vol5) > 1.e-10 * (vol1 + vol2)) return false;
  if (std::min(q1, q2) > std::min(std::min(q3, q4), q5)) return false;
  // printf("%g %g %g\n",vol1 + vol2, vol3 + vol4 + vol5,vol1 + vol2 - vol3 - vol4 - vol5);
  // printf("qs = %g %g vs %g %g %g\n",q1,q2,q3,q4,q5);

  std::vector<MTet4*> outside;
  for(int i = 0; i < 4; i++){
    if(t1->getNeigh(i) && t1->getNeigh(i) != t2){
      bool found = false;
      for(unsigned int j = 0; j < outside.size(); j++){
        if(outside[j] == t1->getNeigh(i)) { found = true; break; }
      }
      if(!found) outside.push_back(t1->getNeigh(i));
    }    
  }
  for(int i = 0; i < 4; i++){
    if(t2->getNeigh(i) && t2->getNeigh(i) != t1){
      bool found = false;
      for(unsigned int j = 0; j < outside.size(); j++){
        if(outside[j] == t2->getNeigh(i)) { found = true; break; }
      }
      if(!found) outside.push_back(t2->getNeigh(i));
    }    
  }

  // printf("we have a face swap %d\n",outside.size());

  t1->setDeleted(true);
  t2->setDeleted(true);

  MTetrahedron *tr1 = new MTetrahedron(f1, f2, v1, v2);
  MTetrahedron *tr2 = new MTetrahedron(f2, f3, v1, v2);
  MTetrahedron *tr3 = new MTetrahedron(f3, f1, v1, v2);
  MTet4 *t41 = new MTet4(tr1, q3); 
  MTet4 *t42 = new MTet4(tr2, q4);
  MTet4 *t43 = new MTet4(tr3, q5); 
  t41->setOnWhat(t1->onWhat());
  t42->setOnWhat(t1->onWhat());
  t43->setOnWhat(t1->onWhat());
  outside.push_back(t41);
  outside.push_back(t42);
  outside.push_back(t43);
  newTets.push_back(t41);
  newTets.push_back(t42);  
  newTets.push_back(t43);  
  connectTets(outside);      
  return true;
}

void gmshBuildVertexCavity_recur(MTet4 *t, 
                                 MVertex *v, 
                                 std::vector<MTet4*> &cavity)
{
  // if (recur > 20)printf("oufti %d\n",recur);
  if(t->isDeleted()){
    Msg::Fatal("a deleted triangle is a neighbor of a non deleted triangle");
  }
  int iV = -1;
  for (int i = 0; i < 4; i++){
    if (t->tet()->getVertex(i) == v){
      iV = i;
      break;
    }
  }
  if (iV == -1){
    Msg::Fatal("trying to build a cavity of tets for a vertex that does not "
        "belong to this tet");
  }
  for (int i = 0; i < 3; i++){
    MTet4 *neigh = t->getNeigh(vFac[iV][i]);
    if (neigh){
      bool found = false;
      for(unsigned int j = 0; j < cavity.size(); j++){
        if(cavity[j] == neigh){
          found = true; 
          j = cavity.size();
        }
      }
      if(!found){
        cavity.push_back(neigh);
        gmshBuildVertexCavity_recur(neigh, v, cavity);
      }
    }
  }
}

// sliver removal by compound mesh modif postulate : the edge cannot
// be swopped so we split it, and then collapse the new vertex on
// another one (of course, not the other one on the unswappable edge)
// after that crap, the sliver is trashed

bool gmshSliverRemoval(std::vector<MTet4*> &newTets,
                       MTet4 *t, 
                       const gmshQualityMeasure4Tet &cr)
{
  std::vector<MTet4*> cavity;
  std::vector<MTet4*> outside;
  std::vector<MVertex*> ring;
  MVertex *v1, *v2;
  
  bool isClosed[6];  
  int nbSwappable = 0;
  int iSwappable = 0;
  for (int i = 0; i < 6; i++){
     isClosed[i] = gmshBuildEdgeCavity(t, i, &v1, &v2, cavity, outside, ring);    
     if (isClosed[i]){
       nbSwappable++;
       iSwappable = i;
     }
  }

  if (nbSwappable == 0){
    // all edges are on model edges or model faces, which means that 
    // nothing can be done
    return false;
  }
  else if (nbSwappable == 1){
    // classical case, the sliver has 5 edges on the boundary
    // try to swap first
    if (gmshEdgeSwap(newTets,t,iSwappable,QMTET_3))return true;
    // if it does not work, split, smooth and collapse
    MVertex *v1 = t->tet()->getVertex(edges[iSwappable][0]);
    MVertex *v2 = t->tet()->getVertex(edges[iSwappable][1]);
    MVertex *newv = new MVertex (0.5 * (v1->x() + v2->x()),
                                 0.5 * (v1->y() + v2->y()),
                                 0.5 * (v1->z() + v2->z()), t->onWhat());
    t->onWhat()->mesh_vertices.push_back(newv);

    if (!gmshEdgeSplit(newTets, t, newv, iSwappable, QMTET_ONE)) return false;
    for (int i = 0; i < 4; i++){
      if (newTets[newTets.size() - 1]->tet()->getVertex(i) == newv){
        gmshSmoothVertex(newTets[newTets.size() - 1], i, cr);
        gmshSmoothVertexOptimize (newTets[newTets.size() - 1], i, cr);
      }
    }
    
    for (unsigned int i = 0; i < newTets.size(); i++){
      MTet4 *new_t = newTets[i];
      if (!(new_t->isDeleted())){
        for (int j = 0; j < 6; j++){
          MVertex *va = new_t->tet()->getVertex(edges[j][0]);
          MVertex *vb = new_t->tet()->getVertex(edges[j][1]);
          if (va == newv &&
              (va != v1  && vb != v1 && va != v2  && vb != v2)){
            gmshCollapseVertex(newTets,new_t,edges[j][0],edges[j][1],cr);
          }
          else if (vb == newv &&
                   (va != v1  && vb != v1 && va != v2  && vb != v2)){
            gmshCollapseVertex(newTets,new_t,edges[j][1],edges[j][0],cr);
          }
        }
      }
    }
    return true;
  }
  else{
    for (int i = 0; i < 4; i++){
      gmshSmoothVertex(t, i, cr);
      gmshSmoothVertexOptimize(t, i, cr);
    }
  }
  return false;
}

bool gmshCollapseVertex(std::vector<MTet4 *> &newTets,
                        MTet4 *t, 
                        int iVertex,
                        int iTarget,
                        const gmshQualityMeasure4Tet &cr,
                        const gmshLocalMeshModAction action,
                        double *minQual)
{
  if(t->isDeleted()){
    Msg::Error("Impossible to collapse vertex");
    return false;
  }

  MVertex *v = t->tet()->getVertex(iVertex);
  MVertex *tg = t->tet()->getVertex(iTarget);

  if(v->onWhat()->dim() < 3) return false;
  if(tg->onWhat()->dim() < 3) return false;

  std::vector<MTet4*> cavity_v;
  std::vector<MTet4*> outside;
  cavity_v.push_back(t);
  gmshBuildVertexCavity_recur(t, v, cavity_v);

  std::vector<MTet4*> toDelete;
  std::vector<MTet4*> toUpdate;
  double volume = 0;
  double worst = 1.0;
  for(unsigned int i = 0; i < cavity_v.size(); i++){
    bool found = false;
    volume += fabs(cavity_v[i]->tet()->getVolume());
    double q = cavity_v[i]->getQuality();
    worst = std::min(worst,q);
    for (int j = 0; j < 4; j++){
      if (cavity_v[i]->tet()->getVertex(j) == tg)found=true;
    }
    if (found) toDelete.push_back(cavity_v[i]);
    else toUpdate.push_back(cavity_v[i]);
  }

  double x = v->x();
  double y = v->y();
  double z = v->z();
  v->x() = tg->x();
  v->y() = tg->y();
  v->z() = tg->z();

  double volume_update = 0;
  
  double worstAfter = 1.0;
  double newQuals[2000];
  if (toUpdate.size() >= 2000){
    Msg::Error("Impossible to collapse vertex");
    return false;
  }
  for (unsigned int i = 0; i < toUpdate.size(); i++){
    double vv;
    newQuals[i] = qmTet(toUpdate[i]->tet(),cr,&vv);
    worstAfter = std::min(worstAfter,newQuals[i]);
    volume_update += vv;
  }

  // printf("%12.5E %12.5E %12.5E %12.5E %d\n",
  // volume,volume_update,worstAfter,worst,toUpdate.size());

  if (fabs(volume-volume_update) > 1.e-10 * volume || worstAfter < worst){
    v->x() = x;
    v->y() = y;
    v->z() = z;
    return false;
  }
  if (action == GMSH_EVALONLY){
    *minQual = worstAfter;
    return true;
  }
  // ok we collapse
  computeNeighboringTetsOfACavity(cavity_v, outside);
  for (unsigned int i = 0; i < toUpdate.size(); i++){
    MTetrahedron *tr1 = new MTetrahedron 
      (toUpdate[i]->tet()->getVertex(0) == v ? tg : toUpdate[i]->tet()->getVertex(0),
       toUpdate[i]->tet()->getVertex(1) == v ? tg : toUpdate[i]->tet()->getVertex(1),
       toUpdate[i]->tet()->getVertex(2) == v ? tg : toUpdate[i]->tet()->getVertex(2),
       toUpdate[i]->tet()->getVertex(3) == v ? tg : toUpdate[i]->tet()->getVertex(3));
    MTet4 *t41 = new MTet4(tr1, cr); 
    t41->setOnWhat(cavity_v[0]->onWhat());
    t41->setQuality(newQuals[i]);
    outside.push_back(t41);
    newTets.push_back(t41);
  }
  for(unsigned int i = 0; i < cavity_v.size(); i++) cavity_v[i]->setDeleted(true);
  
  connectTets(outside);
  
  return true;
}

bool gmshSmoothVertex(MTet4 *t, 
                      int iVertex,
                      const gmshQualityMeasure4Tet &cr)
{
  if(t->isDeleted()){
    Msg::Error("Impossible to collapse vertex");
    return false;
  }
  if(t->tet()->getVertex(iVertex)->onWhat()->dim() < 3) return false;

  std::vector<MTet4*> cavity;
  cavity.push_back(t);
  gmshBuildVertexCavity_recur(t, t->tet()->getVertex(iVertex), cavity);
  
  double xcg = 0, ycg = 0, zcg = 0;
  double vTot = 0;
  double worst = 1.0;

  for(unsigned int i = 0 ; i < cavity.size(); i++){
    double volume = fabs(cavity[i]->tet()->getVolume());
    double q = cavity[i]->getQuality();
    worst = std::min(worst,q);
    xcg += 0.25 * (cavity[i]->tet()->getVertex(0)->x() +
                   cavity[i]->tet()->getVertex(1)->x() +
                   cavity[i]->tet()->getVertex(2)->x() +
                   cavity[i]->tet()->getVertex(3)->x()) * volume;
    ycg += 0.25 * (cavity[i]->tet()->getVertex(0)->y() +
                   cavity[i]->tet()->getVertex(1)->y() +
                   cavity[i]->tet()->getVertex(2)->y() +
                   cavity[i]->tet()->getVertex(3)->y()) * volume;
    zcg += 0.25 * (cavity[i]->tet()->getVertex(0)->z() +
                   cavity[i]->tet()->getVertex(1)->z() +
                   cavity[i]->tet()->getVertex(2)->z() +
                   cavity[i]->tet()->getVertex(3)->z()) * volume;    
    vTot += volume;
  }
  xcg /= (vTot);
  ycg /= (vTot);
  zcg /= (vTot);
  double volumeAfter = 0.0;

  double x = t->tet()->getVertex(iVertex)->x();
  double y = t->tet()->getVertex(iVertex)->y();
  double z = t->tet()->getVertex(iVertex)->z();

  t->tet()->getVertex(iVertex)->x() = xcg;
  t->tet()->getVertex(iVertex)->y() = ycg;
  t->tet()->getVertex(iVertex)->z() = zcg;
  double worstAfter = 1.0;
  double newQuals[2000];
  if (cavity.size() >= 2000){
    Msg::Error("Impossible to smooth vertex");
    return false;
  }
  for (unsigned int i = 0; i < cavity.size(); i++){
    double volume;
    newQuals[i] = qmTet(cavity[i]->tet(),cr,&volume);
    volumeAfter += volume;
    worstAfter = std::min(worstAfter,newQuals[i]);
  }

  if (fabs(volumeAfter-vTot) > 1.e-10 * vTot || worstAfter < worst){
    t->tet()->getVertex(iVertex)->x() = x;
    t->tet()->getVertex(iVertex)->y() = y;
    t->tet()->getVertex(iVertex)->z() = z;
    return false;//gmshSmoothVertexOptimize (t, iVertex, cr);
  }
  else{
    // restore new quality
    for(unsigned int i = 0; i < cavity.size(); i++){
      cavity[i]->setQuality(newQuals[i]);
    }    
    return true;
  }
}

struct smoothVertexData3D{
  MVertex *v;
  std::vector<MTet4 *> ts;
  double LC;
}; 

double smoothing_objective_function_3D(double X, double Y, double Z, 
                                       MVertex *v, std::vector<MTet4 *> &ts)
{
  const double oldX = v->x();
  const double oldY = v->y();
  const double oldZ = v->z();
  v->x() = X;
  v->y() = Y;
  v->z() = Z;

  std::vector < MTet4 * >::iterator it = ts.begin();
  std::vector < MTet4 * >::iterator ite = ts.end();
  double qMin = 1, vol;
  while(it != ite){
    qMin = std::min(qmTet((*it)->tet(), QMTET_2, &vol), qMin);
    ++it;
  }
  v->x() = oldX;
  v->y() = oldY;
  v->z() = oldZ;
  return -qMin;  
}

void deriv_smoothing_objective_function_3D(double *XYZ, double *dF,
                                           double &F, void *data)
{
  smoothVertexData3D *svd = (smoothVertexData3D*)data;
  MVertex *v = svd->v;
  const double LARGE = svd->LC * 1.e5;
  const double SMALL = 1. / LARGE;
  F = smoothing_objective_function_3D(XYZ[0], XYZ[1], XYZ[2], v, svd->ts);
  double F_X = smoothing_objective_function_3D
    (XYZ[0] + SMALL, XYZ[1], XYZ[2], v, svd->ts);
  double F_Y = smoothing_objective_function_3D
    (XYZ[0], XYZ[1] + SMALL, XYZ[2], v, svd->ts);
  double F_Z = smoothing_objective_function_3D
    (XYZ[0], XYZ[1], XYZ[2] + SMALL, v, svd->ts);
  dF[0] = (F_X - F) * LARGE;
  dF[1] = (F_Y - F) * LARGE;
  dF[2] = (F_Z - F) * LARGE;
}

double smooth_obj_3D(double *XYZ, void *data)
{
  smoothVertexData3D *svd = (smoothVertexData3D*)data;
  return smoothing_objective_function_3D(XYZ[0], XYZ[1], XYZ[2], svd->v, svd->ts); 
}

bool gmshSmoothVertexOptimize(MTet4 *t, 
                              int iVertex,
                              const gmshQualityMeasure4Tet &cr)
{
  if(t->tet()->getVertex(iVertex)->onWhat()->dim() < 3) return false;
  
  smoothVertexData3D vd;
  vd.ts.push_back(t);
  vd.v = t->tet()->getVertex(iVertex);
  vd.LC = 1.0; // WRONG
  gmshBuildVertexCavity_recur(t, t->tet()->getVertex(iVertex), vd.ts);

  double xyzopti[3] = {vd.v->x(), vd.v->y(), vd.v->z()};

  double val;
  minimize_N(3, smooth_obj_3D, deriv_smoothing_objective_function_3D, &vd, 4,
             xyzopti, val);

  double vTot = 0;

  for(unsigned int i = 0; i < vd.ts.size(); i++){
    double volume = fabs(vd.ts[i]->tet()->getVolume());
    vTot += volume;    
  }

  double volumeAfter = 0.0;

  double x = t->tet()->getVertex(iVertex)->x();
  double y = t->tet()->getVertex(iVertex)->y();
  double z = t->tet()->getVertex(iVertex)->z();

  t->tet()->getVertex(iVertex)->x() = xyzopti[0];
  t->tet()->getVertex(iVertex)->y() = xyzopti[1];
  t->tet()->getVertex(iVertex)->z() = xyzopti[2];

  double newQuals[2000];
  if(vd.ts.size() >= 2000){
    Msg::Error("Impossible to smooth vertex");
    return false;
  }
  for(unsigned int i = 0; i < vd.ts.size(); i++){
    double volume;
    newQuals[i] = qmTet(vd.ts[i]->tet(), cr, &volume);
    volumeAfter += volume;
  }

  if(fabs(volumeAfter-vTot) > 1.e-10 * vTot){
    t->tet()->getVertex(iVertex)->x() = x;
    t->tet()->getVertex(iVertex)->y() = y;
    t->tet()->getVertex(iVertex)->z() = z;
    return false;
  }
  else{
    // restore new quality
    for(unsigned int i = 0; i < vd.ts.size(); i++){
      vd.ts[i]->setQuality(newQuals[i]);
    }    
    return true;
  }
}

// Edge split sets ...
// Here, we only build a list of tets that are a subdivision
// of the given 
//static int edges[6][2] =    {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};

// the resulting triangles are 012 and 230 in vector res
// void splitPrism (std::vector<MTet4 *> &newTets,
//               std::vector<MVertex *> &steinerPoints,
//               MVertex* v1,
//               MVertex* v2,
//               MVertex* v3,
//               MVertex* v4,
//               MVertex* v5,
//               MVertex* v6, 
//               const gmshQualityMeasure4Tet &cr,
//               MVertex *res[4],
//               fs_cont &search, 
//               GFace *fakeFace){
// }

// void splitQuadFace (MVertex* newv1, 
//                  MVertex* newv2, 
//                  MVertex* v21, 
//                  MVertex* v11, 
//                  const gmshQualityMeasure4Tet &cr,
//                  MVertex *res[4],
//                  fs_cont &search, 
//                  GFace *fakeFace){
//   GFace* gfound = findInFaceSearchStructure (newv1,newv2,v11,search);
//   if (gfound){
//     res[0] = newv2;
//     res[1] = newv1;
//     res[2] = v11;
//     res[3] = v21;
//   }
//   else{
//     GFace* gfound = findInFaceSearchStructure (newv1,newv2,v21,search);
//     if (gfound){
//       res[0] = newv1;
//       res[1] = newv2;
//       res[2] = v21;
//       res[3] = v11;
//     }
//     // choose the best configuration
//     else{
//       double q1 = std::min(qmTri(newv1,newv2,v11,cr),qmTet(newv2,v11,v21,cr));
//       double q2 = std::min(qmTet(newv1,newv2,v21,cr),qmTet(newv1,v11,v21,cr));
//       if (q1 > q2){
//      res[0] = newv2;
//      res[1] = newv1;
//      res[2] = v11;
//      res[3] = v21;
//      MVertex *p1 = std::min(std::min(newv1,newv2),v11);
//      MVertex *p2 = std::min(std::min(newv2,v11),v21);
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p1, std::pair<MTriangle*,GFace*>(new MTriangle(newv1,newv2,v11),fakeFace)));          
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p2, std::pair<MTriangle*,GFace*>(new MTriangle(newv2,v11,v21),fakeFace)));    
//       }
//       else{
//      res[0] = newv1;
//      res[1] = newv2;
//      res[2] = v21;
//      res[3] = v11;
//      MVertex *p1 = std::min(std::min(newv1,newv2),v21);
//      MVertex *p2 = std::min(std::min(newv2,v11),v21);
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p1, std::pair<MTriangle*,GFace*>(new MTriangle(newv1,newv2,v21),fakeFace)));          
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p2, std::pair<MTriangle*,GFace*>(new MTriangle(newv1,v11,v21),fakeFace)));    
//       }
//     }
//   }    
// }
// void splitQuadFace (std::vector<MTet4 *> &newTets,
//                  std::vector<MVertex *> &steinerPoints,
//                  MVertex* newv1, 
//                  MVertex* newv2, 
//                  MVertex* v21, 
//                  MVertex* v11, 
//                  MVertex* other,
//                  const gmshQualityMeasure4Tet &cr,
//                  fs_cont &search, 
//                  GFace *fakeFace){
//   MTetrahedron *tr3,*tr4;
//   // now we look if there exists a face with the same vertices
//   GFace* gfound = findInFaceSearchStructure (newv1,newv2,v11,search);
//   if (gfound){
//     tr3 = new MTetrahedron ( newv1,newv2,v11,other);   
//     tr4 = new MTetrahedron ( newv2,v11,v21,other);     
//   }
//   else{
//     GFace* gfound = findInFaceSearchStructure (newv1,newv2,v21,search);
//     if (gfound){
//       tr3 = new MTetrahedron ( newv1,newv2,v21,other);         
//       tr4 = new MTetrahedron ( newv1,v11,v21,other);   
//     }
//     // choose the best configuration
//     else{
//       double vol;
//       double q1 = std::min(qmTet(newv1,newv2,v11,other,cr,vol),qmTet(newv2,v11,v21,other,cr,vol));
//       double q2 = std::min(qmTet(newv1,newv2,v21,other,cr,vol),qmTet(newv1,v11,v21,other,cr,vol));
//       if (q1 > q2){
//      tr3 = new MTetrahedron ( newv1,newv2,v11,other);          
//      tr4 = new MTetrahedron ( newv2,v11,v21,other);
//      MVertex *p1 = std::min(std::min(newv1,newv2),v11);
//      MVertex *p2 = std::min(std::min(newv2,v11),v21);
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p1, std::pair<MTriangle*,GFace*>(new MTriangle(newv1,newv2,v11),fakeFace)));          
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p2, std::pair<MTriangle*,GFace*>(new MTriangle(newv2,v11,v21),fakeFace)));    
//       }
//       else{
//      tr3 = new MTetrahedron ( newv1,newv2,v21,other);          
//      tr4 = new MTetrahedron ( newv1,v11,v21,other);    
//      MVertex *p1 = std::min(std::min(newv1,newv2),v21);
//      MVertex *p2 = std::min(std::min(newv2,v11),v21);
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p1, std::pair<MTriangle*,GFace*>(new MTriangle(newv1,newv2,v21),fakeFace)));          
//      search.insert ( std::pair<MVertex*,std::pair<MTriangle*,GFace*> > ( p2, std::pair<MTriangle*,GFace*>(new MTriangle(newv1,v11,v21),fakeFace)));    
//       }
//     }
//   }    
// }

// bool splitEdgesOfTet (std::vector<MTet4 *> &newTets,
//                    std::vector<MVertex *> &steinerPoints,
//                    MTet4 *t1,
//                    int nbEdges,
//                    int e[6], 
//                    MVertex* pts[6],
//                    const gmshQualityMeasure4Tet &cr,
//                    fs_cont &search, 
//                    GFace *fakeFace){
//   switch(nbEdges){
//   case 1 :
//     {
//       int iE = edges[0];
//       MVertex *newv = pts[0];
//       MVertex *v1 = t1->tet()->getVertex(e[iE][0]);
//       MVertex *v2 = t1->tet()->getVertex(e[iE][1]);
//       int oE = 5-iE;
//       MVertex *o1 = t1->tet()->getVertex(e[oE][0]);
//       MVertex *o2 = t1->tet()->getVertex(e[oE][1]);
//       MTetrahedron *tr1 = new MTetrahedron ( newv,v1,o1,o2);
//       MTetrahedron *tr2 = new MTetrahedron ( newv,v2,o2,o1);
//       MTet4 *t41 = new MTet4 (tr1,cr); 
//       MTet4 *t42 = new MTet4 (tr2,cr);
//       newTets.push_back(t41);
//       newTets.push_back(t42);
//       }
//     break;
//   case 2 :
//     {
//       int iE1 = edges[0];
//       int iE2 = edges[1];

//       MVertex *newv1 = pts[0];
//       MVertex *newv2 = pts[1];

//       MVertex *v11 = t1->tet()->getVertex(e[iE1][0]);
//       MVertex *v12 = t1->tet()->getVertex(e[iE1][1]);
//       MVertex *v21 = t1->tet()->getVertex(e[iE2][0]);
//       MVertex *v22 = t1->tet()->getVertex(e[iE2][1]);

//       if (iE1 == 5-iE2){ // two opposite edges
//      MTetrahedron *tr1 = new MTetrahedron ( newv1,newv2,v11,v21);
//      MTetrahedron *tr2 = new MTetrahedron ( newv1,newv2,v21,v12);
//      MTetrahedron *tr3 = new MTetrahedron ( newv1,newv2,v12,v22);
//      MTetrahedron *tr4 = new MTetrahedron ( newv1,newv2,v22,v11);
//      MTet4 *t41 = new MTet4 (tr1,cr); 
//      MTet4 *t42 = new MTet4 (tr2,cr);
//      MTet4 *t43 = new MTet4 (tr3,cr); 
//      MTet4 *t44 = new MTet4 (tr4,cr);
//      newTets.push_back(t41);
//      newTets.push_back(t42);
//      newTets.push_back(t43);
//      newTets.push_back(t44);
//       }
//       else{ //two adjacend edges
//      MVertex *vsame,*other=0;
//      if      (v11 == v21){vsame=v11; v11=v12; v21=v22;}
//      else if (v11 == v22){vsame=v11; v11=v12}
//      else if (v12 == v21){vsame=v12; v21=v22}
//      else if (v12 == v22){vsame=v12;}
//      else throw;
//      for (int i=0;i<4;i++){
//        if (vsame != t1->tet()->getVertex(i) && 
//            v11 != t1->tet()->getVertex(i) && 
//            v21 != t1->tet()->getVertex(i)){
//          other = t1->tet->getVertex(i);
//          break;
//        }
//      }
//      if (!other)throw;
//      MTetrahedron *tr1 = new MTetrahedron ( newv1,newv2,vsame,other);
//      splitQuadFace (newTets,steinerPoints,newv1,newv2,v21,v11,other,cr,search,fakeFace);
//       }
//     }
//     break;    
//   case 3 :
//     {
//       int iE1 = edges[0];
//       int iE2 = edges[1];
//       int iE3 = edges[2];
//       MVertex *newv1;
//       MVertex *newv2;
//       MVertex *newv3;
//       std::sort(edges,edges+3);
//       if (iE1 == edges[0])newv1=pts[0];
//       else if (iE2 == edges[0])newv1=pts[1];
//       else if (iE3 == edges[0])newv1=pts[2];
//       if (iE1 == edges[1])newv2=pts[0];
//       else if (iE2 == edges[1])newv2=pts[1];
//       else if (iE3 == edges[1])newv2=pts[2];
//       if (iE1 == edges[2])newv3=pts[0];
//       else if (iE2 == edges[2])newv3=pts[1];
//       else if (iE3 == edges[2])newv3=pts[2];
//       iE1 = edges[0];
//       iE2 = edges[1];
//       iE3 = edges[2];
//       // edges are sorted and points correspond

//       mVertex *v[4];
//       // the 3 edges coincide at one vertex
//       int config;
//       if (iE1 == 0 && iE2 == 1 && iE3 == 2){
//      config = 1; 
//      v[0] = t1->tet()->getVertex(0);
//      v[1] = t1->tet()->getVertex(1);
//      v[2] = t1->tet()->getVertex(2);
//      v[3] = t1->tet()->getVertex(3);
//       }      
//       else if (iE1 == 0 && iE2 == 3 && iE3 == 4){
//      config = 1; 
//      v[0] = t1->tet()->getVertex(1);
//      v[1] = t1->tet()->getVertex(0);
//      v[2] = t1->tet()->getVertex(2);
//      v[3] = t1->tet()->getVertex(3);
//       }      
//       else if (iE1 == 1 && iE2 == 3 && iE3 == 5){
//      config = 1; 
//      v[0] = t1->tet()->getVertex(2);
//      v[1] = t1->tet()->getVertex(0);
//      v[2] = t1->tet()->getVertex(1);
//      v[3] = t1->tet()->getVertex(3);
//       }      
//       else if (iE1 == 2 && iE2 == 4 && iE3 == 5){
//      config = 1; 
//      v[0] = t1->tet()->getVertex(3);
//      v[1] = t1->tet()->getVertex(0);
//      v[2] = t1->tet()->getVertex(1);
//      v[3] = t1->tet()->getVertex(2);
//       }
//       // three edges of the same face are cut
//       else if (iE1 == 0 && iE2 == 1 && iE3 == 3){
//      config = 2;
//      v[0] = t1->tet()->getVertex(3);
//      v[1] = t1->tet()->getVertex(1);
//      v[2] = t1->tet()->getVertex(0);
//      v[3] = t1->tet()->getVertex(2);      
//       }
//       else if (iE1 == 0 && iE2 == 2 && iE3 == 4){
//      config = 2;
//      v[0] = t1->tet()->getVertex(2);
//      v[1] = t1->tet()->getVertex(1);
//      v[2] = t1->tet()->getVertex(0);
//      v[3] = t1->tet()->getVertex(3);      
//       }
//       else if (iE1 == 1 && iE2 == 2 && iE3 == 5){
//      config = 2;
//      v[0] = t1->tet()->getVertex(1);
//      v[1] = t1->tet()->getVertex(2);
//      v[2] = t1->tet()->getVertex(0);
//      v[3] = t1->tet()->getVertex(3);      
//       }
//       else if (iE1 == 3 && iE2 == 4 && iE3 == 5){
//      config = 2;
//      v[0] = t1->tet()->getVertex(0);
//      v[1] = t1->tet()->getVertex(2);
//      v[2] = t1->tet()->getVertex(1);
//      v[3] = t1->tet()->getVertex(3);      
//       }
//       // the three edges for a kind of Z
//       else if (iE1 == 0 && iE2 == 3 && iE3 == 5){
//      config = 3;
//       }
      
//       if (config == 1){
//       }
//       else if (config == 2){
//       }
//       else{
//      throw; // for the moment.
//       }
//     }
//   default :
//     throw;
//   }
//   t1->setDeleted(true);
    

// }
  


// collapse
