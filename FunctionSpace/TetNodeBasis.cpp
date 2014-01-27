#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "TetNodeBasis.h"

using namespace std;

TetNodeBasis::TetNodeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_TET;
  dim  = 3;

  nVertex   = 4;
  nEdge     = 6 * (order - 1);
  nFace     = 2 * (order - 1) * (order - 2);
  nCell     =     (order - 1) * (order - 2) * (order - 3) / 6;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  const vector<vector<vector<size_t> > >&
    faceIdx = ReferenceSpaceManager::getFaceNodeIndex(type);

  // Alloc Temporary Space //
  const int orderMinus      = order - 1;
  const int orderMinusTwo   = order - 2;
  const int orderMinusThree = order - 3;

  Polynomial* legendre     = new Polynomial[order];
  Polynomial* sclLegendre  = new Polynomial[order];
  Polynomial* intLegendre  = new Polynomial[order];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinus);
  Legendre::scaled(sclLegendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Lagrange Polynomial //
  const Polynomial lagrange[4] =
    {
      Polynomial(Polynomial(1, 0, 0, 0) -
                 Polynomial(1, 1, 0, 0) -
                 Polynomial(1, 0, 1, 0) -
                 Polynomial(1, 0, 0, 1)),

      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0)),

      Polynomial(Polynomial(1, 0, 0, 1))
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
  }

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex;

    for(int e = 0; e < 6; e++){
      for(size_t l = 1; l < order; l++){
        basis[s][i] =
          new Polynomial(intLegendre[l].compose
                         (lagrange[edgeIdx[s][e][1]] -
                          lagrange[edgeIdx[s][e][0]]
                          ,
                          lagrange[edgeIdx[s][e][0]] +
                          lagrange[edgeIdx[s][e][1]]));
        i++;
      }
    }
  }

  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex + nEdge;

    for(int f = 0; f < 4; f++){
      for(int l1 = 1; l1 < orderMinus; l1++){
        for(int l2 = 0; l1 + l2 - 1 < orderMinusTwo; l2++){
          Polynomial sum =
            lagrange[faceIdx[s][f][0]] +
            lagrange[faceIdx[s][f][1]] +
            lagrange[faceIdx[s][f][2]];

          basis[s][i] =
            new Polynomial(intLegendre[l1].compose
                           (lagrange[faceIdx[s][f][1]] -
                            lagrange[faceIdx[s][f][0]]
                            ,
                            lagrange[faceIdx[s][f][0]] +
                            lagrange[faceIdx[s][f][1]])

                           *

                           lagrange[faceIdx[s][f][2]]
                           *
                           sclLegendre[l2].compose
                           (lagrange[faceIdx[s][f][2]] * 2 - sum, sum));
          i++;
        }
      }
    }
  }

  // Cell Based //
  const Polynomial oneMinusFour         = Polynomial(1, 0, 0, 0) - lagrange[3];
  const Polynomial twoThreeOneMinusFour = lagrange[2] * 2 - oneMinusFour;
  const Polynomial twoFourMinusOne      =
    lagrange[3] * 2 - Polynomial(1, 0, 0, 0);

  const Polynomial sub = lagrange[0] - lagrange[1];
  const Polynomial add = lagrange[0] + lagrange[1];

  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex + nEdge + nFace;

    for(int l1 = 1; l1 < orderMinusTwo; l1++){
      for(int l2 = 0; l2 + l1 - 1 < orderMinusThree; l2++){
        for(int l3 = 0; l3 + l2 + l1 - 1 < orderMinusThree; l3++){
          basis[s][i] =
            new Polynomial(intLegendre[l1].compose(sub, add)             *
                           lagrange[2]                                   *
                           sclLegendre[l2].compose(twoThreeOneMinusFour,
                                                   oneMinusFour)         *
                           lagrange[3]                                   *
                           legendre[l3].compose(twoFourMinusOne));
          i++;
        }
      }
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] sclLegendre;
  delete[] intLegendre;
}

TetNodeBasis::~TetNodeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
