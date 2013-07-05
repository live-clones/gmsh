#include "QuadNedelecBasis.h"
#include "QuadReferenceSpace.h"
#include "Legendre.h"

using namespace std;

QuadNedelecBasis::QuadNedelecBasis(void){
  // Reference Space //
  refSpace  = new QuadReferenceSpace;
  nRefSpace = refSpace->getNReferenceSpace();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  // Set Basis Type //
  order = 0;

  type = 1;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 4;
  nFace     = 0;
  nCell     = 0;
  nFunction = 4;

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
  basis = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    for(unsigned int e = 0; e < 4; e++){

      Polynomial lambda = (lagrange[(*(*edgeV[s])[e])[0]] +
                           lagrange[(*(*edgeV[s])[e])[1]]) * 0.5;

      basis[s][e] =
        new vector<Polynomial>((lifting[(*(*edgeV[s])[e])[1]] -
                                lifting[(*(*edgeV[s])[e])[0]]).gradient());

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

  for(unsigned int s = 0; s < nRefSpace; s++){
    for(unsigned int i = 0; i < nFunction; i++){
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
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
