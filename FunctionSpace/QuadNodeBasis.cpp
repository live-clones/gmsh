#include "QuadNodeBasis.h"
#include "QuadReferenceSpace.h"
#include "Legendre.h"

using namespace std;

QuadNodeBasis::QuadNodeBasis(unsigned int order){
  /*
  // Reference Space //
  refSpace  = new QuadReferenceSpace;
  nRefSpace = refSpace->getNReferenceSpace();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  const vector<const vector<const vector<unsigned int>*>*>&
    faceV = refSpace->getAllFace();

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2;

  nVertex   = 4;
  nEdge     = 4 * (order - 1);
  nFace     =     (order - 1) * (order - 1);
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Legendre Polynomial //
  Polynomial* legendre = new Polynomial[order];
  Legendre::integrated(legendre, order);

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
  basis = new Polynomial**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    basis[s][0] = new Polynomial(lagrange[0]);
    basis[s][1] = new Polynomial(lagrange[1]);
    basis[s][2] = new Polynomial(lagrange[2]);
    basis[s][3] = new Polynomial(lagrange[3]);
  }

  // Edge Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nVertex;

    for(unsigned int e = 0; e < 4; e++){
      for(unsigned int l = 1; l < order; l++){
        basis[s][i] =
          new Polynomial(legendre[l].compose(lifting[(*(*edgeV[s])[e])[1]] -
                                             lifting[(*(*edgeV[s])[e])[0]])
                         *
                         (lagrange[(*(*edgeV[s])[e])[0]] +
                          lagrange[(*(*edgeV[s])[e])[1]]));

        i++;
      }
    }
  }

  // Face Based //

  // NB: We use (*(*faceV[s])[f])[]
  //     where f = 0, because triangles
  //     have only ONE face: the face '0'

  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nVertex + nEdge;

    for(unsigned int l1 = 1; l1 < order; l1++){
      for(unsigned int l2 = 1; l2 < order; l2++){
       basis[s][i] =
         new Polynomial(legendre[l1].compose(lifting[(*(*faceV[s])[0])[0]] -
                                             lifting[(*(*faceV[s])[0])[1]])
                         *

                        legendre[l2].compose(lifting[(*(*faceV[s])[0])[0]] -
                                             lifting[(*(*faceV[s])[0])[3]]));

        i++;
      }
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
      Polynomial* tmp;
      tmp = basis[s][i];
      basis[s][i] = new Polynomial(tmp->compose(mapX, mapY));
      delete tmp;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  */
}

QuadNodeBasis::~QuadNodeBasis(void){
  /*
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
  */
}
