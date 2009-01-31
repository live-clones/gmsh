// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "meshGFace.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "GmshMessage.h"
#include "Numeric.h"

#define SQU(a)      ((a)*(a))

/*
   s4 +-----c3-----+ s3
      |            |
      |            |
     c4            c2
      |            |
      |            |
   s1 +-----c1-----+ s2
*/

// f(u,v) = (1-u) c4(v) + u c2(v) + (1-v) c1(u) + v c3(u)
//          - [ (1-u)(1-v) s1 + u(1-v) s2 + uv s3 + (1-u)v s4 ]
#define TRAN_QUA(c1,c2,c3,c4,s1,s2,s3,s4,u,v) \
   (1.-u)*c4+u*c2+(1.-v)*c1+v*c3-((1.-u)*(1.-v)*s1+u*(1.-v)*s2+u*v*s3+(1.-u)*v*s4)

// s1=s4=c4
// f(u,v) = u c2 (v) + (1-v) c1(u) + v c3(u) - u(1-v) s2 - uv s3
#define TRAN_TRI(c1,c2,c3,s1,s2,s3,u,v) u*c2+(1.-v)*c1+v*c3-(u*(1.-v)*s2+u*v*s3)

void findTransfiniteCorners(GFace *gf, std::vector<MVertex*> &corners)
{
  if(gf->meshAttributes.corners.size()){
    // corners have been specified explicitly
    for(unsigned int i = 0; i < gf->meshAttributes.corners.size(); i++)
      corners.push_back(gf->meshAttributes.corners[i]->mesh_vertices[0]);
  }
  else{
    // try to find the corners automatically
    std::list<GEdge*> fedges = gf->edges();
    GEdgeLoop el(fedges);
    for(GEdgeLoop::iter it = el.begin(); it != el.end(); it++)
      corners.push_back(it->getBeginVertex()->mesh_vertices[0]);
    
    // try reaaally hard for 3-sided faces
    if(corners.size() == 3){
      GEdge *first = 0, *last = 0;
      for(std::list<GEdge*>::iterator it = fedges.begin(); it != fedges.end(); it++){
        if(((*it)->getBeginVertex()->mesh_vertices[0] == corners[0] &&
            (*it)->getEndVertex()->mesh_vertices[0] == corners[1]) ||
           ((*it)->getBeginVertex()->mesh_vertices[0] == corners[1] &&
            (*it)->getEndVertex()->mesh_vertices[0] == corners[0])){
          first = *it;
        }
        if(((*it)->getBeginVertex()->mesh_vertices[0] == corners[2] &&
            (*it)->getEndVertex()->mesh_vertices[0] == corners[0]) ||
           ((*it)->getBeginVertex()->mesh_vertices[0] == corners[0] &&
            (*it)->getEndVertex()->mesh_vertices[0] == corners[2])){
          last = *it;
        }
      }
      if(first && last){
        if(first->mesh_vertices.size() != last->mesh_vertices.size()){
          std::vector<MVertex*> corners2(3);
          corners2[0] = corners[1];
          corners2[1] = corners[2];
          corners2[2] = corners[0];
          corners = corners2;
        }
      }
    }
  }
}

int MeshTransfiniteSurface(GFace *gf)
{
  if(gf->meshAttributes.Method != MESH_TRANSFINITE) return 0;

  Msg::StatusBar(2, true, "Meshing surface %d (transfinite)", gf->tag());

  std::vector<MVertex*> corners;
  findTransfiniteCorners(gf, corners);
  if(corners.size () != 3 && corners.size () != 4){
    Msg::Error("Surface %d is transfinite but has %d corners",
	       gf->tag(), corners.size());
    return 0;
  }

  std::vector<MVertex*> d_vertices;
  std::vector<int> indices;
  computeEdgeLoops(gf, d_vertices, indices);

  if(indices.size () != 2){
    Msg::Error("Surface %d is transfinite but has %d holes",
	       gf->tag(), indices.size() - 2);
    return 0;
  }

  // create a list of all boundary vertices, starting at the first
  // transfinite corner
  std::vector <MVertex *> m_vertices;
  unsigned int I;
  for(I = 0; I < d_vertices.size(); I++)
    if(d_vertices[I] == corners[0]) break;
  for(unsigned int j = 0; j < d_vertices.size(); j++)
    m_vertices.push_back(d_vertices[(I + j) % d_vertices.size()]);

  // make the ordering of the list consistent with the ordering of the
  // first two corners (if the second found corner is not the second
  // corner, just revert the list)
  bool revert = false;
  for(unsigned int i = 1; i < m_vertices.size(); i++){
    MVertex *v = m_vertices[i];
    if(v == corners[1] || v == corners[2] || 
       (corners.size() == 4 && v == corners[3])){
      if(v != corners[1]) revert = true;
      break;
    }
  }
  if(revert){
    std::vector <MVertex *> tmp;
    tmp.push_back(m_vertices[0]);
    for(int i = m_vertices.size() - 1; i > 0; i--)
      tmp.push_back(m_vertices[i]);
    m_vertices = tmp;
  }

  // get the indices of the interpolation corners as well as the u,v
  // coordinates of all the boundary vertices
  int iCorner = 0, N[4] = {0, 0, 0, 0};
  std::vector<double> U, V;
  for(unsigned int i = 0; i < m_vertices.size(); i++){
    MVertex *v = m_vertices[i];
    if(v == corners[0] || v == corners[1] || v == corners[2] || 
       (corners.size() == 4 && v == corners[3])){
      N[iCorner++] = i;   
      if(iCorner > 4){
        Msg::Error("Surface %d transfinite parameters are incoherent", gf->tag());
        return 0;
      }
    }
    SPoint2 param;
    reparamMeshVertexOnFace(v, gf, param);
    U.push_back(param[0]);
    V.push_back(param[1]);
  }

  int N1 = N[0], N2 = N[1], N3 = N[2], N4 = N[3];
  int L = N2 - N1, H = N3 - N2;
  if(corners.size () == 4){
    int Lb = N4 - N3, Hb = m_vertices.size() - N4;
    if(Lb != L || Hb != H){
      Msg::Error("Surface %d cannot be meshed using the transfinite algo", 
		 gf->tag());
      return 0;
    }
  }
  else{
    int Lb = m_vertices.size() - N3;      
    if(Lb != L){
      Msg::Error("Surface %d cannot be meshed using the transfinite algo %d != %d", 
		 gf->tag(), L, Lb);
      return 0;
    }      
  }
  
  std::vector<double> lengths_i, lengths_j;
  double L_i = 0, L_j = 0;
  lengths_i.push_back(0.);
  lengths_j.push_back(0.);
  for(int i = 0; i < L; i++){
    MVertex *v1 = m_vertices[i];
    MVertex *v2 = m_vertices[i + 1];
    L_i += v1->distance(v2);
    lengths_i.push_back(L_i);
  }
  for(int i = L; i < L + H; i++){
    MVertex *v1 = m_vertices[i];
    MVertex *v2 = m_vertices[i + 1];
    L_j += v1->distance(v2);
    lengths_j.push_back(L_j);
  }

  /*
      2L+H +------------+ L+H
           |            |
           |            |
           |            |
           |            |
   2L+2H+2 +------------+
           0            L
  */

  std::vector<std::vector<MVertex*> > &tab(gf->transfinite_vertices);
  tab.resize(L + 1);
  for(int i = 0; i <= L; i++) tab[i].resize(H + 1);

  if(corners.size () == 4){
    tab[0][0] = m_vertices[0];
    tab[L][0] = m_vertices[L];
    tab[L][H] = m_vertices[L+H];
    tab[0][H] = m_vertices[2*L+H];
    for (int i = 1; i < L; i++){
      tab[i][0] = m_vertices[i];
      tab[i][H] = m_vertices[2*L+H-i];
    }
    for(int i = 1; i < H; i++){
      tab[L][i] = m_vertices[L+i];
      tab[0][i] = m_vertices[2*L+2*H-i];
    }
  }
  else{
    tab[0][0] = m_vertices[0];
    tab[L][0] = m_vertices[L];
    tab[L][H] = m_vertices[L+H];
    // degenerated, only necessary for transfinite volume algo
    tab[0][H] = m_vertices[0]; 
    for (int i = 1; i < L; i++){
      tab[i][0] = m_vertices[i];
      tab[i][H] = m_vertices[2*L+H-i];
    }
    for(int i = 1; i < H;i++){
      tab[L][i] = m_vertices[L+i];
      // degenerated, only necessary for transfinite volume algo
      tab[0][i] = m_vertices[0];
    }
  }

  double UC1 = U[N1], UC2 = U[N2], UC3 = U[N3];
  double VC1 = V[N1], VC2 = V[N2], VC3 = V[N3];

  //create points using transfinite interpolation
  if(corners.size() == 4){
    double UC4 = U[N4];
    double VC4 = V[N4];
    for(int i = 1; i < L; i++){
      double u = lengths_i[i] / L_i;
      for(int j = 1; j < H; j++){ 
        double v = lengths_j[j] / L_j;
        int iP1 = N1 + i;
        int iP2 = N2 + j;
        int iP3 = N4 - i;
        int iP4 = (N4 + (N3 - N2) - j) % m_vertices.size();
        double Up = TRAN_QUA(U[iP1], U[iP2], U[iP3], U[iP4], UC1, UC2, UC3, UC4, u, v); 
        double Vp = TRAN_QUA(V[iP1], V[iP2], V[iP3], V[iP4], VC1, VC2, VC3, VC4, u, v); 
        GPoint gp = gf->point(SPoint2(Up, Vp));
        MFaceVertex *newv = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, Up, Vp);
        gf->mesh_vertices.push_back(newv);
        tab[i][j] = newv;
      }
    }
  }
  else{
    for(int i = 1; i < L; i++){
      double u = lengths_i[i] / L_i;
      for(int j = 1; j < H; j++){ 
        double v = lengths_j[j] / L_j;
        int iP1 = N1 + i;
        int iP2 = N2 + j;
        int iP3 = ((N3 + N2) - i) % m_vertices.size();
        double Up, Vp;
        if(gf->geomType() != GEntity::RuledSurface){
          Up = TRAN_TRI(U[iP1], U[iP2], U[iP3], UC1, UC2, UC3, u, v);
          Vp = TRAN_TRI(V[iP1], V[iP2], V[iP3], VC1, VC2, VC3, u, v);
        }
        else{
          // FIXME: to get nice meshes we would need to make the u,v
          // coords match with the (degenerate) coordinates of the
          // underlying ruled surface; so instead we just interpolate
          // in real space
          double xp = TRAN_TRI(m_vertices[iP1]->x(), m_vertices[iP2]->x(),       
                               m_vertices[iP3]->x(), m_vertices[N1]->x(),        
                               m_vertices[N2]->x(), m_vertices[N3]->x(), u, v);          
          double yp = TRAN_TRI(m_vertices[iP1]->y(), m_vertices[iP2]->y(),       
                               m_vertices[iP3]->y(), m_vertices[N1]->y(),        
                               m_vertices[N2]->y(), m_vertices[N3]->y(), u, v);          
          double zp = TRAN_TRI(m_vertices[iP1]->z(), m_vertices[iP2]->z(),       
                               m_vertices[iP3]->z(), m_vertices[N1]->z(),        
                               m_vertices[N2]->z(), m_vertices[N3]->z(), u, v);          
          // xp,yp,zp can be off the surface so we cannot use parFromPoint
          gf->XYZtoUV(xp, yp, zp, Up, Vp, 1.0, false);   
        }
        GPoint gp = gf->point(SPoint2(Up, Vp));
        MFaceVertex *newv = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, Up, Vp);
        gf->mesh_vertices.push_back(newv);
        tab[i][j] = newv;
      }
    }
  }  

  // should we apply the elliptic smoother?
  int numSmooth = 0;
  if(gf->meshAttributes.transfiniteSmoothing < 0 && CTX::instance()->mesh.nbSmoothing > 1)
    numSmooth = CTX::instance()->mesh.nbSmoothing;
  else if(gf->meshAttributes.transfiniteSmoothing > 0)
    numSmooth = gf->meshAttributes.transfiniteSmoothing;

  if(corners.size() == 4 && numSmooth){
    std::vector<std::vector<double> > u(L + 1), v(L + 1);
    for(int i = 0; i <= L; i++){
      u[i].resize(H + 1);
      v[i].resize(H + 1);
    }
    for(int i = 0; i <= L; i++){
      for(int j = 0; j <= H; j++){ 
        int iP1 = N1 + i;
        int iP2 = N2 + j;
        int iP3 = N4 - i;
        int iP4 = (N4 + (N3 - N2) - j) % m_vertices.size();
        if(j == 0)     { u[i][j] = U[iP1]; v[i][j] = V[iP1]; }
        else if(i == L){ u[i][j] = U[iP2]; v[i][j] = V[iP2]; }
        else if(j == H){ u[i][j] = U[iP3]; v[i][j] = V[iP3]; }
        else if(i == 0){ u[i][j] = U[iP4]; v[i][j] = V[iP4]; }
        else{
          tab[i][j]->getParameter(0, u[i][j]);
          tab[i][j]->getParameter(1, v[i][j]);
        }
      }
    }
    for(int IT = 0; IT < numSmooth; IT++){
      for(int i = 1; i < L; i++){
        for(int j = 1; j < H; j++){
          double alpha = 0.25 * (SQU(u[i][j + 1] - u[i][j - 1]) +
                                 SQU(v[i][j + 1] - v[i][j - 1])) ;
          double gamma = 0.25 * (SQU(u[i + 1][j] - u[i - 1][j]) +
                                 SQU(v[i + 1][j] - v[i - 1][j]));
          double beta = 0.0625 * 
            ((u[i + 1][j] - u[i - 1][j]) * (u[i][j + 1] - u[i][j - 1]) +
             (v[i + 1][j] - v[i - 1][j]) * (v[i][j + 1] - v[i][j - 1]));
          u[i][j] = 0.5 * 
            (alpha * (u[i + 1][j] + u[i - 1][j]) + 
             gamma * (u[i][j + 1] + u[i][j - 1]) -
             2. * beta * (u[i + 1][j + 1] - u[i - 1][j + 1] - 
                          u[i + 1][j - 1] + u[i - 1][j - 1])) / (alpha + gamma);
          v[i][j] = 0.5 * 
            (alpha * (v[i + 1][j] + v[i - 1][j]) + 
             gamma * (v[i][j + 1] + v[i][j - 1]) -
             2. * beta * (v[i + 1][j + 1] - v[i - 1][j + 1] - 
                          v[i + 1][j - 1] + v[i - 1][j - 1])) / (alpha + gamma);
        }
      }
    }
    for(int i = 1; i < L; i++){
      for(int j = 1; j < H; j++){
        GPoint p = gf->point(SPoint2(u[i][j], v[i][j]));
        tab[i][j]->x() = p.x();
        tab[i][j]->y() = p.y();
        tab[i][j]->z() = p.z();
        tab[i][j]->setParameter(0, u[i][j]);
        tab[i][j]->setParameter(1, v[i][j]);
      }
    }
  }

  // create elements
  if(corners.size() == 4){ 
    for(int i = 0; i < L ; i++){
      for(int j = 0; j < H; j++){
        MVertex *v1 = tab[i][j];
        MVertex *v2 = tab[i + 1][j];
        MVertex *v3 = tab[i + 1][j + 1];
        MVertex *v4 = tab[i][j + 1];
        if(gf->meshAttributes.recombine)
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        else if(gf->meshAttributes.transfiniteArrangement == 1 ||
                (gf->meshAttributes.transfiniteArrangement == 0 && 
                 ((i % 2 == 0 && j % 2 == 1) ||
                  (i % 2 == 1 && j % 2 == 0)))){
          gf->triangles.push_back(new MTriangle(v1, v2, v3));
          gf->triangles.push_back(new MTriangle(v3, v4, v1));
        }         
        else{
          gf->triangles.push_back(new MTriangle(v1, v2, v4));
          gf->triangles.push_back(new MTriangle(v4, v2, v3));
        }         
      }
    }
  }
  else{      
    for(int j = 0; j < H; j++){
      MVertex *v1 = tab[0][0];
      MVertex *v2 = tab[1][j];
      MVertex *v3 = tab[1][j + 1];
      gf->triangles.push_back(new MTriangle(v1, v2, v3));
    }
    for(int i = 1; i < L ; i++){
      for(int j = 0; j < H; j++){
        MVertex *v1 = tab[i][j];
        MVertex *v2 = tab[i + 1][j];
        MVertex *v3 = tab[i + 1][j + 1];
        MVertex *v4 = tab[i][j + 1];
        if(gf->meshAttributes.recombine)
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        else if(gf->meshAttributes.transfiniteArrangement == 1 ||
                (gf->meshAttributes.transfiniteArrangement == 0 && 
                 ((i % 2 == 0 && j % 2 == 1) ||
                  (i % 2 == 1 && j % 2 == 0)))){
          gf->triangles.push_back(new MTriangle(v1, v2, v3));
          gf->triangles.push_back(new MTriangle(v3, v4, v1));
        }         
        else{
          gf->triangles.push_back(new MTriangle(v1, v2, v4));
          gf->triangles.push_back(new MTriangle(v4, v2, v3));
        }         
      }
    }
  }

  gf->meshStatistics.status = GFace::DONE;
  return 1;
}
