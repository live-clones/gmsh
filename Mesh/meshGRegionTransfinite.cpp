// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "meshGFace.h"
#include "GFace.h"
#include "GRegion.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "Context.h"
#include "GmshMessage.h"

/*  
  Transfinite volume meshes

                     a0   s0 s1  f0  s0 s1 s5 s4              s6      
   s7        s6      a1   s1 s2  f1  s1 s2 s6 s5              *       
     *-------*       a2   s3 s2  f2  s3 s2 s6 s7             /|\      
     |\s4    |\      a3   s0 s3  f3  s0 s3 s7 s4            / | \     
     | *-------* s5  a4   s4 s5  f4  s0 s1 s2 s3      s7/s4/  |s2\    
     | |   s2| |     a5   s5 s6  f5  s4 s5 s6 s7          *---*---* s5
  s3 *-|-----* |     a6   s7 s6                           |  / \  |   
      \|      \|     a7   s4 s7                           | /   \ |   
       *-------*     a8   s0 s4                           |/     \|   
 v w  s0       s1    a9   s1 s5                           *-------*     
  \|                 a10  s2 s6                  v w    s3/s0     s1    
   *--u              a11  s3 s7                   \|                 
                                                   *--u              
  Important limitations:

  - only works with 5- or 6-face volumes

  - the faces have to be meshed with the 2D transfinite algorithm

  - the definition of a 5-face volume has to follow the ordering given
    in the figure above (degenerescence has to be along s0,s4)
   
  - meshing a volume with prisms or tetrahedra assumes that the
    triangular mesh is consistent with the volume mesh: there is no
    coherence check in the volume algorithm to ensure that edges will
    match.
*/

#define CREATE_HEX new MHexahedron(tab[i    ][j    ][k    ], \
                                   tab[i + 1][j    ][k    ], \
                                   tab[i + 1][j + 1][k    ], \
                                   tab[i    ][j + 1][k    ], \
                                   tab[i    ][j    ][k + 1], \
                                   tab[i + 1][j    ][k + 1], \
                                   tab[i + 1][j + 1][k + 1], \
                                   tab[i    ][j + 1][k + 1])

#define CREATE_PRISM_1 new MPrism(tab[i    ][j    ][k    ], \
                                  tab[i + 1][j    ][k    ], \
                                  tab[i    ][j + 1][k    ], \
                                  tab[i    ][j    ][k + 1], \
                                  tab[i + 1][j    ][k + 1], \
                                  tab[i    ][j + 1][k + 1])

#define CREATE_PRISM_2 new MPrism(tab[i + 1][j + 1][k    ], \
                                  tab[i    ][j + 1][k    ], \
                                  tab[i + 1][j    ][k    ], \
                                  tab[i + 1][j + 1][k + 1], \
                                  tab[i    ][j + 1][k + 1], \
                                  tab[i + 1][j    ][k + 1])

#define CREATE_SIM_1 new MTetrahedron(tab[i    ][j    ][k    ], \
                                      tab[i + 1][j    ][k    ], \
                                      tab[i    ][j + 1][k    ], \
                                      tab[i    ][j    ][k + 1])

#define CREATE_SIM_2 new MTetrahedron(tab[i + 1][j    ][k    ], \
                                      tab[i    ][j + 1][k    ], \
                                      tab[i    ][j    ][k + 1], \
                                      tab[i + 1][j    ][k + 1])

#define CREATE_SIM_3 new MTetrahedron(tab[i    ][j    ][k + 1], \
                                      tab[i + 1][j    ][k + 1], \
                                      tab[i    ][j + 1][k    ], \
                                      tab[i    ][j + 1][k + 1])

#define CREATE_SIM_4 new MTetrahedron(tab[i + 1][j    ][k    ], \
                                      tab[i    ][j + 1][k    ], \
                                      tab[i + 1][j    ][k + 1], \
                                      tab[i + 1][j + 1][k    ])

#define CREATE_SIM_5 new MTetrahedron(tab[i    ][j + 1][k    ], \
                                      tab[i    ][j + 1][k + 1], \
                                      tab[i + 1][j    ][k + 1], \
                                      tab[i + 1][j + 1][k    ])

#define CREATE_SIM_6 new MTetrahedron(tab[i + 1][j    ][k + 1], \
                                      tab[i    ][j + 1][k + 1], \
                                      tab[i + 1][j + 1][k + 1], \
                                      tab[i + 1][j + 1][k    ])

static double transfiniteHex(double f1, double f2, double f3, double f4, 
                             double f5, double f6,
                             double c1, double c2, double c3, double c4, 
                             double c5, double c6, double c7, double c8, 
                             double c9, double c10, double c11, double c12,
                             double s1, double s2, double s3, double s4, 
                             double s5, double s6, double s7, double s8,
                             double u, double v, double w)
{
  return (1-u)*f4 + u*f2 + (1-v)*f1 + v*f3 + (1-w)*f5 + w*f6 -
    ((1-u)*(1-v)*c9 + (1-u)*v*c12 + u*(1-v)*c10 + u*v*c11) -
    ((1-v)*(1-w)*c1 + (1-v)*w*c5 + v*(1-w)*c3 + v*w*c7) -
    ((1-u)*(1-w)*c4 + (1-w)*u*c2 + w*(1-u)*c8 + u*w*c6) +
    (1-u)*(1-v)*(1-w)*s1 + u*(1-v)*(1-w)*s2 + u*v*(1-w)*s3 + (1-u)*v*(1-w)*s4 + 
    (1-u)*(1-v)*w*s5 + u*(1-v)*w*s6 + u*v*w*s7 + (1-u)*v*w*s8;
}

static MVertex *transfiniteHex(GRegion *gr, 
                               MVertex *f1, MVertex *f2, MVertex *f3, MVertex *f4, 
                               MVertex *f5, MVertex *f6,
                               MVertex *c1, MVertex *c2, MVertex *c3, MVertex *c4, 
                               MVertex *c5, MVertex *c6, MVertex *c7, MVertex *c8, 
                               MVertex *c9, MVertex *c10, MVertex *c11, MVertex *c12,
                               MVertex *s1, MVertex *s2, MVertex *s3, MVertex *s4, 
                               MVertex *s5, MVertex *s6, MVertex *s7, MVertex *s8,
                               double u, double v, double w)
{
  double x = transfiniteHex(f1->x(), f2->x(), f3->x(), f4->x(), f5->x(), f6->x(),
                            c1->x(), c2->x(), c3->x(), c4->x(), c5->x(), c6->x(),
                            c7->x(), c8->x(), c9->x(), c10->x(), c11->x(), c12->x(),
                            s1->x(), s2->x(), s3->x(), s4->x(), 
                            s5->x(), s6->x(), s7->x(), s8->x(),
                            u, v, w);
  double y = transfiniteHex(f1->y(), f2->y(), f3->y(), f4->y(), f5->y(), f6->y(),
                            c1->y(), c2->y(), c3->y(), c4->y(), c5->y(), c6->y(),
                            c7->y(), c8->y(), c9->y(), c10->y(), c11->y(), c12->y(),
                            s1->y(), s2->y(), s3->y(), s4->y(), 
                            s5->y(), s6->y(), s7->y(), s8->y(),
                            u, v, w);
  double z = transfiniteHex(f1->z(), f2->z(), f3->z(), f4->z(), f5->z(), f6->z(),
                            c1->z(), c2->z(), c3->z(), c4->z(), c5->z(), c6->z(),
                            c7->z(), c8->z(), c9->z(), c10->z(), c11->z(), c12->z(),
                            s1->z(), s2->z(), s3->z(), s4->z(), 
                            s5->z(), s6->z(), s7->z(), s8->z(),
                            u, v, w);
  return new MVertex(x, y, z, gr);
}

class GOrientedTransfiniteFace {
private:
  GFace *_gf;
  int _LL, _HH;
  int _permutation, _index;
  std::vector<MVertex*> _list;

public:
  GOrientedTransfiniteFace()
    : _gf(0), _LL(0), _HH(0), _permutation(-1), _index(-1)
  {
  }
  GOrientedTransfiniteFace(GFace *gf, std::vector<MVertex*> &corners)
    : _gf(gf), _LL(0), _HH(0), _permutation(-1), _index(-1)
  { 
    _LL = gf->transfinite_vertices.size() - 1;
    if(_LL <= 0) return;
    _HH = gf->transfinite_vertices[0].size() - 1;
    if(_HH <= 0) return;
    Msg::Debug("Face %d: L = %d  H = %d", gf->tag(), _LL, _HH);

    // get the corners of the transfinite volume interpolation
    std::vector<MVertex*> s(8);
    if(corners.size() == 8){
      for(int i = 0; i < 8; i++)
        s[i] = corners[i];
    }
    else if(corners.size() == 6){
      s[0] = corners[0]; s[1] = corners[1]; s[2] = corners[2]; s[3] = corners[0];
      s[4] = corners[3]; s[5] = corners[4]; s[6] = corners[5]; s[7] = corners[3];
    }
    else
      return;
    
    // get the corners of the transfinite surface mesh
    std::vector<MVertex*> c(4);
    if(_gf->meshAttributes.corners.empty() || 
       _gf->meshAttributes.corners.size() == 4){
      c[0] = _gf->transfinite_vertices[0][0];
      c[1] = _gf->transfinite_vertices[_LL][0];
      c[2] = _gf->transfinite_vertices[_LL][_HH];
      c[3] = _gf->transfinite_vertices[0][_HH];
    }
    else if(_gf->meshAttributes.corners.size() == 3){
      c[0] = _gf->transfinite_vertices[0][0];
      c[1] = _gf->transfinite_vertices[_LL][0];
      c[2] = _gf->transfinite_vertices[_LL][_HH];
      c[3] = _gf->transfinite_vertices[0][0];
    }
    else
      return;

    // map the surface mesh onto the canonical transfinite hexahedron
    int faces[] = {0, 1, 5, 4,   1, 2, 6, 5,   3, 2, 6, 7, 
                   0, 3, 7, 4,   0, 1, 2, 3,   4, 5, 6, 7};
    int permutations[] = {0, 1, 2, 3,   1, 2, 3, 0,   2, 3, 0, 1,   3, 0, 1, 2,
                          3, 2, 1, 0,   2, 1, 0, 3,   1, 0, 3, 2,   0, 3, 2, 1};
    for(int p = 0; p < 8; p++) {
      for(int f = 0; f < 6; f++) {
        if(s[faces[4 * f + 0]] == c[permutations[4 * p + 0]] &&
           s[faces[4 * f + 1]] == c[permutations[4 * p + 1]] &&
           s[faces[4 * f + 2]] == c[permutations[4 * p + 2]] &&
           s[faces[4 * f + 3]] == c[permutations[4 * p + 3]]) {
          _index = f;
          _permutation = p;
          break;
        }
      }
    }
    Msg::Debug("Found face index %d  (permutation = %d)", _index, _permutation);
    for(int i = 0; i <= _LL; i++)
      for(int j = 0; j <= _HH; j++)
        _list.push_back(_gf->transfinite_vertices[i][j]);
  }

  // returns the index of the face in the reference hexahedron
  int index() const { return _index; }

  // returns true if the face is recombined
  int recombined() const { return _gf->meshAttributes.recombine; }

  // returns the number or points in the transfinite mesh in both
  // parameter directions
  int getNumU(){ return (_permutation % 2) ? _HH + 1: _LL + 1; }
  int getNumV(){ return (_permutation % 2) ? _LL + 1: _HH + 1; }

  // returns the (i,j) vertex in the face, i and j being defined in
  // the coordinate system of the reference transfinite hexahedron
  MVertex *getVertex(int i, int j)
  {
    int index = -1, m = i, n = j, M = getNumU(), N = getNumV();
    switch (_permutation) {
    case 0: index = (n + N * m); break;
    case 1: index = (M * N - M * (n + 1) + m); break;
    case 2: index = (M * N - (n + N * m) - 1); break;
    case 3: index = (M + n * M - m - 1); break;
    case 4: index = (N + m * N - n - 1); break;
    case 5: index = (M * N - (m + M * n) - 1); break;
    case 6: index = (M * N - N * (m + 1) + n); break;
    case 7: index = (m + M * n); break;
    }
    MVertex *v = 0;
    if(index >= 0 && index < (int)_list.size()) v = _list[index];
    if(index < 0 || index >= (int)_list.size() || !v){
      Msg::Error("Wrong index in transfinite mesh of surface %d: "
          "m=%d n=%d M=%d N=%d perm=%d", _gf->tag(), m, n, M, N, _permutation);
      return _list[0];
    }
    return v;
  }
};

void findTransfiniteCorners(GRegion *gr, std::vector<MVertex*> &corners)
{
  if(gr->meshAttributes.corners.size()){
    // corners have been specified explicitly
    for(unsigned int i = 0; i < gr->meshAttributes.corners.size(); i++)
      corners.push_back(gr->meshAttributes.corners[i]->mesh_vertices[0]);
  }
  else{
    // try to find the corners automatically
    std::list<GFace*> faces = gr->faces();
    GFace *gf = 0;
    if(faces.size() == 6){
      // any face will do as a starting face
      gf = faces.front();
    }
    else if(faces.size() == 5){
      // we need to start with a triangular face
      for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
        if((*it)->edges().size() == 3 || (*it)->meshAttributes.corners.size() == 3){
          gf = *it;
          break;
        }
      }
    }
    if(gf){
      std::list<GEdge*> fedges = gf->edges();
      std::list<GEdge*> redges = gr->edges();
      for(std::list<GEdge*>::iterator it = fedges.begin(); it != fedges.end(); it++)
        redges.erase(std::find(redges.begin(), redges.end(), *it));
      findTransfiniteCorners(gf, corners);
      unsigned int N = corners.size();
      for(unsigned int i = 0; i < N; i++){
        for(std::list<GEdge*>::iterator it = redges.begin(); it != redges.end(); it++){
          if((*it)->getBeginVertex()->mesh_vertices[0] == corners[i]){
            corners.push_back((*it)->getEndVertex()->mesh_vertices[0]);
            break;
          }
          else if((*it)->getEndVertex()->mesh_vertices[0] == corners[i]){
            corners.push_back((*it)->getBeginVertex()->mesh_vertices[0]);
            break;
          }
        }
      }
    }
  }
}

int MeshTransfiniteVolume(GRegion *gr)
{
  if(gr->meshAttributes.Method != MESH_TRANSFINITE) return 0;

  Msg::StatusBar(2, true, "Meshing volume %d (transfinite)", gr->tag());

  std::list<GFace*> faces = gr->faces();
  if(faces.size() != 5 && faces.size() != 6){
    Msg::Error("Transfinite algorithm only available for 5- and 6-face volumes");
    return 0;
  }

  std::vector<MVertex*> corners;
  findTransfiniteCorners(gr, corners);
  if(corners.size() != 6 && corners.size() != 8){
    Msg::Error("Volume %d is transfinite but has %d corners",
               gr->tag(), corners.size());
    return 0;
  }
  
  std::vector<GOrientedTransfiniteFace> orientedFaces(6);
  for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); ++it){
    GOrientedTransfiniteFace f(*it, corners);
    if(f.index() < 0){
      Msg::Error("Incompatible surface %d in transfinite volume %d", 
                 (*it)->tag(), gr->tag());
      return 0;
    }
    orientedFaces[f.index()] = f;
  }

  int N_i = orientedFaces[4].getNumU();
  int N_j = orientedFaces[4].getNumV();
  int N_k = orientedFaces[1].getNumV();

  std::vector<double> lengths_i, lengths_j, lengths_k;
  double L_i = 0., L_j = 0., L_k = 0.;
  lengths_i.push_back(0.);
  lengths_j.push_back(0.);
  lengths_k.push_back(0.);
  for(int i = 0; i < N_i - 1; i++){
    MVertex *v1 = orientedFaces[4].getVertex(i, 0);
    MVertex *v2 = orientedFaces[4].getVertex(i + 1, 0);
    L_i += v1->distance(v2);
    lengths_i.push_back(L_i);
  }
  for(int i = 0; i < N_j - 1; i++){
    MVertex *v1 = orientedFaces[1].getVertex(i, 0);
    MVertex *v2 = orientedFaces[1].getVertex(i + 1, 0);
    L_j += v1->distance(v2);
    lengths_j.push_back(L_j);
  }
  for(int i = 0; i < N_k - 1; i++){
    MVertex *v1 = orientedFaces[1].getVertex(0, i);
    MVertex *v2 = orientedFaces[1].getVertex(0, i + 1);
    L_k += v1->distance(v2);
    lengths_k.push_back(L_k);
  }

  // create points using transfinite interpolation

  MVertex *s0 = orientedFaces[4].getVertex(0, 0);
  MVertex *s1 = orientedFaces[4].getVertex(N_i - 1, 0);
  MVertex *s2 = orientedFaces[4].getVertex(N_i - 1, N_j - 1);
  MVertex *s3 = orientedFaces[4].getVertex(0, N_j - 1);
  
  MVertex *s4 = orientedFaces[5].getVertex(0, 0);
  MVertex *s5 = orientedFaces[5].getVertex(N_i - 1, 0);
  MVertex *s6 = orientedFaces[5].getVertex(N_i - 1, N_j - 1);
  MVertex *s7 = orientedFaces[5].getVertex(0, N_j - 1);

  std::vector<std::vector<std::vector<MVertex*> > > &tab(gr->transfinite_vertices);
  tab.resize(N_i);
  for(int i = 0; i < N_i; i++){
    tab[i].resize(N_j);
    for(int j = 0; j < N_j; j++){
      tab[i][j].resize(N_k);
    }
  }

  for(int i = 0; i < N_i; i++) {
    double u = lengths_i[i] / L_i;

    for(int j = 0; j < N_j; j++) {
      double v = lengths_j[j] / L_j;

      MVertex *c0 = orientedFaces[4].getVertex(i, 0);
      MVertex *c1 = orientedFaces[4].getVertex(N_i - 1, j);
      MVertex *c2 = orientedFaces[4].getVertex(i, N_j - 1);
      MVertex *c3 = orientedFaces[4].getVertex(0, j);
      
      MVertex *c4 = orientedFaces[5].getVertex(i, 0);
      MVertex *c5 = orientedFaces[5].getVertex(N_i - 1, j);
      MVertex *c6 = orientedFaces[5].getVertex(i, N_j - 1);
      MVertex *c7 = orientedFaces[5].getVertex(0, j);
      
      MVertex *f4 = orientedFaces[4].getVertex(i, j);
      MVertex *f5 = orientedFaces[5].getVertex(i, j);

      for(int k = 0; k < N_k; k++) {
        double w = lengths_k[k] / L_k;

        MVertex *c8 = orientedFaces[0].getVertex(0, k);
        MVertex *c9 = orientedFaces[0].getVertex(N_i - 1, k);
        MVertex *c10 = orientedFaces[2].getVertex(N_i - 1, k);
        MVertex *c11 = orientedFaces[2].getVertex(0, k);

        MVertex *f0 = orientedFaces[0].getVertex(i, k);
        MVertex *f1 = orientedFaces[1].getVertex(j, k);
        MVertex *f2 = orientedFaces[2].getVertex(i, k);
        MVertex *f3;
        if(corners.size() == 8)
          f3 = orientedFaces[3].getVertex(j, k);
        else
          f3 = c8;

        if(i && j && k && i != N_i - 1 && j != N_j - 1 && k != N_k - 1) {
          MVertex *newv = transfiniteHex(gr, f0, f1, f2, f3, f4, f5,
                                         c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11,
                                         s0, s1, s2, s3, s4, s5, s6, s7,
                                         u, v, w);
          gr->mesh_vertices.push_back(newv);
          tab[i][j][k] = newv;
        }
        else if(!i) {
          tab[i][j][k] = f3;
        }
        else if(!j) {
          tab[i][j][k] = f0;
        }
        else if(!k) {
          tab[i][j][k] = f4;
        }
        else if(i == N_i - 1) {
          tab[i][j][k] = f1;
        }
        else if(j == N_j - 1) {
          tab[i][j][k] = f2;
        }
        else if(k == N_k - 1) {
          tab[i][j][k] = f5;
        }
      }
    }
  }

  // create elements

  if(faces.size() == 6) {
    for(int i = 0; i < N_i - 1; i++) {
      for(int j = 0; j < N_j - 1; j++) {
        for(int k = 0; k < N_k - 1; k++) {
          if(orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
             orientedFaces[2].recombined() && orientedFaces[3].recombined() && 
             orientedFaces[4].recombined() && orientedFaces[5].recombined()) {
            gr->hexahedra.push_back(CREATE_HEX);
          }
          else if(!orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
                  !orientedFaces[2].recombined() && orientedFaces[3].recombined() && 
                  orientedFaces[4].recombined() && orientedFaces[5].recombined()) {
            gr->prisms.push_back(new MPrism(tab[i    ][j    ][k    ],
                                            tab[i + 1][j    ][k    ],
                                            tab[i    ][j    ][k + 1],
                                            tab[i    ][j + 1][k    ],
                                            tab[i + 1][j + 1][k    ],
                                            tab[i    ][j + 1][k + 1]));
            gr->prisms.push_back(new MPrism(tab[i + 1][j    ][k + 1],
                                            tab[i    ][j    ][k + 1],
                                            tab[i + 1][j    ][k    ],
                                            tab[i + 1][j + 1][k + 1],
                                            tab[i    ][j + 1][k + 1],
                                            tab[i + 1][j + 1][k    ]));
          }
          else if(orientedFaces[0].recombined() && !orientedFaces[1].recombined() && 
                  orientedFaces[2].recombined() && !orientedFaces[3].recombined() && 
                  orientedFaces[4].recombined() && orientedFaces[5].recombined()) {
            gr->prisms.push_back(new MPrism(tab[i + 1][j    ][k    ],
                                            tab[i + 1][j + 1][k    ],
                                            tab[i + 1][j    ][k + 1],
                                            tab[i    ][j    ][k    ],
                                            tab[i    ][j + 1][k    ],
                                            tab[i    ][j    ][k + 1]));
            gr->prisms.push_back(new MPrism(tab[i + 1][j + 1][k + 1],
                                            tab[i + 1][j    ][k + 1],
                                            tab[i + 1][j + 1][k    ],
                                            tab[i    ][j + 1][k + 1],
                                            tab[i    ][j    ][k + 1],
                                            tab[i    ][j + 1][k    ]));
          }
          else if(orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
                  orientedFaces[2].recombined() && orientedFaces[3].recombined() && 
                  !orientedFaces[4].recombined() && !orientedFaces[5].recombined()) {
            gr->prisms.push_back(CREATE_PRISM_1);
            gr->prisms.push_back(CREATE_PRISM_2);
          }
          else if(!orientedFaces[0].recombined() && !orientedFaces[1].recombined() &&
                  !orientedFaces[2].recombined() && !orientedFaces[3].recombined() && 
                  !orientedFaces[4].recombined() && !orientedFaces[5].recombined()) {
            gr->tetrahedra.push_back(CREATE_SIM_1);
            gr->tetrahedra.push_back(CREATE_SIM_2);
            gr->tetrahedra.push_back(CREATE_SIM_3);
            gr->tetrahedra.push_back(CREATE_SIM_4);
            gr->tetrahedra.push_back(CREATE_SIM_5);
            gr->tetrahedra.push_back(CREATE_SIM_6);
          }
          else {
            Msg::Error("Wrong surface recombination in transfinite volume %d", gr->tag());
            return 0;
          }
        }
      }
    }
  }
  else if(faces.size() == 5) {
    for(int j = 0; j < N_j - 1; j++) {
      for(int k = 0; k < N_k - 1; k++) {
        if((orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
            orientedFaces[2].recombined() && orientedFaces[4].recombined() && 
            orientedFaces[5].recombined()) ||
           (orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
            orientedFaces[2].recombined() && !orientedFaces[4].recombined() && 
            !orientedFaces[5].recombined())) {
          gr->prisms.push_back(new MPrism(tab[0    ][j    ][k    ],
                                          tab[1    ][j    ][k    ],
                                          tab[1    ][j + 1][k    ],
                                          tab[0    ][j    ][k + 1],
                                          tab[1    ][j    ][k + 1],
                                          tab[1    ][j + 1][k + 1]));
        }
        else if(!orientedFaces[0].recombined() && !orientedFaces[1].recombined() && 
                !orientedFaces[2].recombined() && !orientedFaces[4].recombined() && 
                !orientedFaces[5].recombined()) {
          gr->tetrahedra.push_back(new MTetrahedron(tab[0    ][j    ][k    ],
                                                    tab[1    ][j    ][k    ],
                                                    tab[1    ][j + 1][k    ],
                                                    tab[0    ][j    ][k + 1]));
          gr->tetrahedra.push_back(new MTetrahedron(tab[1    ][j    ][k    ],
                                                    tab[1    ][j + 1][k    ],
                                                    tab[0    ][j    ][k + 1],
                                                    tab[1    ][j    ][k + 1]));
          gr->tetrahedra.push_back(new MTetrahedron(tab[0    ][j    ][k + 1],
                                                    tab[1    ][j + 1][k + 1],
                                                    tab[1    ][j    ][k + 1],
                                                    tab[1    ][j + 1][k    ]));
        }
        else {
          Msg::Error("Wrong surface recombination in transfinite volume %d", gr->tag());
          return 0;
        }
      }
    }
    for(int i = 1; i < N_i - 1; i++) {
      for(int j = 0; j < N_j - 1; j++) {
        for(int k = 0; k < N_k - 1; k++) {
          if(orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
             orientedFaces[2].recombined() && orientedFaces[4].recombined() &&
             orientedFaces[5].recombined()) {
            gr->hexahedra.push_back(CREATE_HEX);
          }
          else if(orientedFaces[0].recombined() && orientedFaces[1].recombined() && 
                  orientedFaces[2].recombined() && !orientedFaces[4].recombined() && 
                  !orientedFaces[5].recombined()) {
            gr->prisms.push_back(CREATE_PRISM_1);
            gr->prisms.push_back(CREATE_PRISM_2);
          }
          else if(!orientedFaces[0].recombined() && !orientedFaces[1].recombined() && 
                  !orientedFaces[2].recombined() && !orientedFaces[4].recombined() && 
                  !orientedFaces[5].recombined()) {
            gr->tetrahedra.push_back(CREATE_SIM_1);
            gr->tetrahedra.push_back(CREATE_SIM_2);
            gr->tetrahedra.push_back(CREATE_SIM_3);
            gr->tetrahedra.push_back(CREATE_SIM_4);
            gr->tetrahedra.push_back(CREATE_SIM_5);
            gr->tetrahedra.push_back(CREATE_SIM_6);
          }
          else {
            Msg::Error("Wrong surface recombination in transfinite volume %d", gr->tag());
            return 0;
          }
        }
      }
    }
  }

  return 1;
}
