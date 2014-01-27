#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "QuadNedelecBasis.h"

using namespace std;

QuadNedelecBasis::QuadNedelecBasis(void){
  // Set Basis Type //
  order = 0;

  type = TYPE_QUA;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 4;
  nFace     = 0;
  nCell     = 0;
  nFunction = 4;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  // Lagrange & Lifting //
  const Polynomial lagrange[4] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0)))
    };

  const Polynomial lifting[4] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0)))
    };

  // Basis //
  basis = new vector<Polynomial>**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  for(size_t s = 0; s < nOrientation; s++){
    for(size_t e = 0; e < 4; e++){

      Polynomial lambda = (lagrange[edgeIdx[s][e][0]] +
                           lagrange[edgeIdx[s][e][1]]) * 0.5;

      basis[s][e] =
        new vector<Polynomial>((lifting[edgeIdx[s][e][1]] -
                                lifting[edgeIdx[s][e][0]]).gradient());

      basis[s][e]->at(0).mul(lambda);
      basis[s][e]->at(1).mul(lambda);
      basis[s][e]->at(2).mul(lambda);
    }
  }

  // Mapping to Gmsh Quad //
  // x = (u + 1) / 2
  // y = (v + 1) / 2
  //
  // (x, y) = Zaglmayr Ref Quad
  // (u, v) = Gmsh     Ref Quad

  Polynomial  mapX(Polynomial(0.5, 1, 0, 0) +
                   Polynomial(0.5, 0, 0, 0));

  Polynomial  mapY(Polynomial(0.5, 0, 1, 0) +
                   Polynomial(0.5, 0, 0, 0));

  for(size_t s = 0; s < nOrientation; s++){
    for(size_t i = 0; i < nFunction; i++){
      vector<Polynomial>* old;
      vector<Polynomial>  nxt(3);

      old    = basis[s][i];
      nxt[0] = (*old)[0].compose(mapX, mapY);
      nxt[1] = (*old)[1].compose(mapX, mapY);
      nxt[2] = (*old)[2].compose(mapX, mapY);

      basis[s][i] = new vector<Polynomial>(nxt);
      delete old;
    }
  }
}

QuadNedelecBasis::~QuadNedelecBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
