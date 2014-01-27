#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "HexNodeBasis.h"

using namespace std;

HexNodeBasis::HexNodeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_HEX;
  dim  = 3;

  nVertex   =  8;
  nEdge     = 12 * (order - 1);
  nFace     =  6 * (order - 1) * (order - 1);
  nCell     =      (order - 1) * (order - 1) * (order - 1);
  nFunction = nVertex + nEdge + nFace + nCell;

   // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  const vector<vector<vector<size_t> > >&
    faceIdx = ReferenceSpaceManager::getFaceNodeIndex(type);

  // Legendre Polynomial //
  Polynomial* legendre = new Polynomial[order];
  Legendre::integrated(legendre, order);

  // Lagrange & Lifting //
  const Polynomial lagrange[8] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0))                          *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0))                          *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
                 (Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0))                          *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
                 (Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0)) *
                 (Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0))                          *
                 (Polynomial(1, 0, 0, 1)))
    };

  const Polynomial lifting[8] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0))                          +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0))                          +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
                 (Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0))                          +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
                 (Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0)) +
                 (Polynomial(1, 0, 0, 1))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0))                          +
                 (Polynomial(1, 0, 0, 1)))
    };

  // Basis //
  basis = new Polynomial**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based //
  for(size_t s = 0; s < nOrientation; s++){
    basis[s][0] = new Polynomial(lagrange[0]);
    basis[s][1] = new Polynomial(lagrange[1]);
    basis[s][2] = new Polynomial(lagrange[2]);
    basis[s][3] = new Polynomial(lagrange[3]);
    basis[s][4] = new Polynomial(lagrange[4]);
    basis[s][5] = new Polynomial(lagrange[5]);
    basis[s][6] = new Polynomial(lagrange[6]);
    basis[s][7] = new Polynomial(lagrange[7]);
  }

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex;

    for(size_t e = 0; e < 12; e++){
      for(size_t l = 1; l < order; l++){
        basis[s][i] =
          new Polynomial(legendre[l].compose(lifting[edgeIdx[s][e][1]] -
                                             lifting[edgeIdx[s][e][0]])
                         *
                         (lagrange[edgeIdx[s][e][0]] +
                          lagrange[edgeIdx[s][e][1]]));

        i++;
      }
    }
  }

  // Face Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex + nEdge;

    for(size_t f = 0; f < 6; f++){
      for(size_t l1 = 1; l1 < order; l1++){
        for(size_t l2 = 1; l2 < order; l2++){
          Polynomial sum =
            lagrange[faceIdx[s][f][0]] +
            lagrange[faceIdx[s][f][1]] +
            lagrange[faceIdx[s][f][2]] +
            lagrange[faceIdx[s][f][3]];

          basis[s][i] =
            new Polynomial(legendre[l1].compose(lifting[faceIdx[s][f][0]] -
                                                lifting[faceIdx[s][f][1]])  *

                           legendre[l2].compose(lifting[faceIdx[s][f][0]] -
                                                lifting[faceIdx[s][f][3]])  *
                           sum);
          i++;
        }
      }
    }
  }

  // Cell Based //
  Polynomial px = Polynomial(2, 1, 0, 0);
  Polynomial py = Polynomial(2, 0, 1, 0);
  Polynomial pz = Polynomial(2, 0, 0, 1);

  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);
  pz = pz - Polynomial(1, 0, 0, 0);

  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex + nEdge + nFace;

    for(size_t l1 = 1; l1 < order; l1++){
      for(size_t l2 = 1; l2 < order; l2++){
        for(size_t l3 = 1; l3 < order; l3++){
          basis[s][i] =
            new Polynomial(legendre[l1].compose(px) *
                           legendre[l2].compose(py) *
                           legendre[l3].compose(pz));

          i++;
        }
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

  Polynomial  mapZ(Polynomial(0.5, 0, 0, 1) +
                   Polynomial(0.5, 0, 0, 0));

  for(size_t s = 0; s < nOrientation; s++){
    for(size_t i = 0; i < nFunction; i++){
      Polynomial* tmp;
      tmp = basis[s][i];
      basis[s][i] = new Polynomial(tmp->compose(mapX, mapY, mapZ));
      delete tmp;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
}

HexNodeBasis::~HexNodeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
