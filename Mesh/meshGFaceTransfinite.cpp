// $Id: meshGFaceTransfinite.cpp,v 1.29 2008-07-01 14:24:07 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "meshGFace.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "Message.h"
#include "Numeric.h"

extern Context_T CTX;

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

int MeshTransfiniteSurface(GFace *gf)
{
  if(gf->meshAttributes.Method != MESH_TRANSFINITE) return 0;

  Msg::StatusBar(2, true, "Meshing surface %d (transfinite)", gf->tag());

  std::vector <MVertex *> corners, d_vertices;
  std::vector <int> indices;

  for(unsigned int i = 0; i < gf->meshAttributes.corners.size(); i++)
    corners.push_back(gf->meshAttributes.corners[i]->mesh_vertices[0]);

  computeEdgeLoops(gf, d_vertices, indices);

  if(corners.size () != 3 && corners.size () != 4){
    Msg::Error("Surface %d is transfinite but has %d corners",
        gf->tag(), corners.size());
    return 0;
  }
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
  int iCorner = 0;
  int N[4] = {0, 0, 0, 0};
  std::vector<double> U;
  std::vector<double> V;
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
    if(v->onWhat()->dim() == 0){
      GVertex *gv = (GVertex*)v->onWhat();
      param = gv->reparamOnFace(gf, 1);
    }
    else if(v->onWhat()->dim() == 1){
      GEdge *ge = (GEdge*)v->onWhat();
      double UU;
      v->getParameter(0, UU);
      param = ge->reparamOnFace(gf, UU, 1);
    }
    else{
      double UU, VV;
      if(v->onWhat() == gf && v->getParameter(0, UU) && v->getParameter(1, VV))
        param = SPoint2(UU, VV);
      else
        param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
    }
    U.push_back(param.x());
    V.push_back(param.y());
  }

  int N1 = N[0];
  int N2 = N[1];
  int N3 = N[2];
  int N4 = N[3];

  int L = N2 - N1;
  int H = N3 - N2;

  if(corners.size () == 4){
    int Lb = N4 - N3;
    int Hb = m_vertices.size() - N4;
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
  
  std::vector<double> lengths_i;
  std::vector<double> lengths_j;
  double L_i = 0;
  double L_j = 0;
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

  double UC1 = U[N1];
  double UC2 = U[N2];
  double UC3 = U[N3];
  double VC1 = V[N1];
  double VC2 = V[N2];
  double VC3 = V[N3];

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

  // elliptic smoother (don't apply this by default)
  if(corners.size() == 4 && gf->geomType() == GEntity::Plane){
    int numSmooth = 0;
    if(gf->meshAttributes.transfiniteSmoothing < 0 && CTX.mesh.nb_smoothing > 1)
      numSmooth = CTX.mesh.nb_smoothing;
    else if(gf->meshAttributes.transfiniteSmoothing > 0)
      numSmooth = gf->meshAttributes.transfiniteSmoothing;
    for (int IT = 0; IT < numSmooth; IT++){
      for(int i = 1; i < L; i++){
        for(int j = 1; j < H; j++){
          MVertex *v11 = tab[i - 1][j - 1];
          MVertex *v12 = tab[i - 1][j    ];
          MVertex *v13 = tab[i - 1][j + 1];           
          MVertex *v21 = tab[i    ][j - 1];
          MVertex *v22 = tab[i    ][j    ];
          MVertex *v23 = tab[i    ][j + 1];
          MVertex *v31 = tab[i + 1][j - 1];
          MVertex *v32 = tab[i + 1][j    ];
          MVertex *v33 = tab[i + 1][j + 1];
          double alpha = 0.25 * (DSQR(v23->x() - v21->x()) +
                                 DSQR(v23->y() - v21->y()) +
                                 DSQR(v23->z() - v21->z()));
          double gamma = 0.25 * (DSQR(v32->x() - v12->x()) +
                                 DSQR(v32->y() - v12->y()) +
                                 DSQR(v32->z() - v12->z()));
          double beta = 0.0625 * ((v32->x() - v12->x()) * (v23->x() - v21->x()) +
                                  (v32->y() - v12->y()) * (v23->y() - v21->y()) +
                                  (v32->z() - v12->z()) * (v23->z() - v21->z()));
          v22->x() = 0.5 * (alpha * (v32->x() + v12->x()) + 
                            gamma * (v23->x() + v21->x()) -
                            2. * beta * (v33->x() - v13->x() - 
                                         v31->x() + v11->x())) / (alpha + gamma);
          v22->y() = 0.5 * (alpha * (v32->y() + v12->y()) +
                            gamma * (v23->y() + v21->y()) -
                            2. * beta * (v33->y() - v13->y() -
                                         v31->y() + v11->y())) / (alpha + gamma);
          v22->z() = 0.5 * (alpha * (v32->z() + v12->z()) +
                            gamma * (v23->z() + v21->z()) -
                            2. * beta * (v33->z() - v13->z() -
                                         v31->z() + v11->z())) / (alpha + gamma);
        }
      }
    }
    // recompute corresponding u,v coordinates (necessary e.g. for 2nd order algo)
    for(int i = 1; i < L; i++){
      for(int j = 1; j < H; j++){
        MVertex *v = tab[i][j];
        SPoint2 param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
        v->setParameter(0, param[0]);
        v->setParameter(1, param[1]);
      }
    }
  }

  if(corners.size() == 4){ 
    // create elements
    for(int i = 0; i < L ; i++){
      for(int j = 0; j < H; j++){
        MVertex *v1 = tab[i    ][j    ];
        MVertex *v2 = tab[i + 1][j    ];
        MVertex *v3 = tab[i + 1][j + 1];
        MVertex *v4 = tab[i    ][j + 1];
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
      MVertex *v1 = tab[0    ][0    ];
      MVertex *v2 = tab[1    ][j    ];
      MVertex *v3 = tab[1    ][j + 1];
      gf->triangles.push_back(new MTriangle(v1, v2, v3));
    }
    for(int i = 1; i < L ; i++){
      for(int j = 0; j < H; j++){
        MVertex *v1 = tab[i    ][j    ];
        MVertex *v2 = tab[i + 1][j    ];
        MVertex *v3 = tab[i + 1][j + 1];
        MVertex *v4 = tab[i    ][j + 1];
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
