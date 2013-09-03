#include "HexNodeBasis.h"
#include "HexReferenceSpace.h"
#include "Legendre.h"

using namespace std;

HexNodeBasis::HexNodeBasis(size_t order){
   // Reference Space //
  refSpace  = new HexReferenceSpace;
  nRefSpace = getReferenceSpace().getNReferenceSpace();

  const vector<vector<vector<size_t> > >&
    edgeIdx = refSpace->getEdgeNodeIndex();

  const vector<vector<vector<size_t> > >&
    faceIdx = refSpace->getFaceNodeIndex();

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 3;

  nVertex   =  8;
  nEdge     = 12 * (order - 1);
  nFace     =  6 * (order - 1) * (order - 1);
  nCell     =      (order - 1) * (order - 1) * (order - 1);
  nFunction = nVertex + nEdge + nFace + nCell;

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
  basis = new Polynomial**[nRefSpace];

  for(size_t s = 0; s < nRefSpace; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based //
  for(size_t s = 0; s < nRefSpace; s++){
    basis[s][0] = new Polynomial(lagrange[0]);
    basis[s][1] = new Polynomial(lagrange[1]);
    basis[s][2] = new Polynomial(lagrange[2]);
    basis[s][3] = new Polynomial(lagrange[3]);
    basis[s][4] = new Polynomial(lagrange[4]);
    basis[s][5] = new Polynomial(lagrange[5]);
    basis[s][6] = new Polynomial(lagrange[6]);
    basis[s][7] = new Polynomial(lagrange[7]);
  }
  /*
  // Edge Based //

  for(int l = 1; l < order; l++){
    for(int e = 0; e < 12; e++){
      (*basis)[i] = new Polynomial(
        legendre[l].compose(lifting[edge1[e]] - lifting[edge2[e]]) *
        (*(*basis)[edge1[e]] + *(*basis)[edge2[e]]));

      i++;
    }
  }


  // Face Based (Preliminary) //
  // Points definig Faces
  const int face1[6] = {0, 3, 2, 1, 5, 4};
  const int face2[6] = {1, 7, 6, 0, 6, 7};
  const int face3[6] = {2, 6, 5, 4, 7, 3};
  const int face4[6] = {3, 2, 1, 5, 4, 0};

  // 'Xi' Functions
  for(int f = 0; f < 6; f++)
    xi[f]  = lifting[face1[f]] - lifting[face2[f]];

  // 'Eta' Functions
  for(int f = 0; f < 6; f++)
    eta[f] = lifting[face1[f]] - lifting[face4[f]];

  // 'Lambda' Functions
  for(int f = 0; f < 6; f++)
    lambda[f] =
      *(*basis)[face1[f]] +
      *(*basis)[face2[f]] +
      *(*basis)[face3[f]] +
      *(*basis)[face4[f]];


  // Face Based //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      for(int f = 0; f < 6; f++){
        (*basis)[i] = new Polynomial(
          legendre[l1].compose(xi[f])  *
          legendre[l2].compose(eta[f]) *
          lambda[f]);

        i++;
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

  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      for(int l3 = 1; l3 < order; l3++){
        (*basis)[i] =
          new Polynomial(legendre[l1].compose(px) *
                         legendre[l2].compose(py) *
                         legendre[l3].compose(pz));

        i++;
      }
    }
  }


  // Free Temporary Sapce //
  delete[] legendre;
  delete[] lifting;

  delete[] xi;
  delete[] eta;
  delete[] lambda;
*/
}

HexNodeBasis::~HexNodeBasis(void){
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(size_t i = 0; i < nRefSpace; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
