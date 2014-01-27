#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "TriNodeBasis.h"

using namespace std;

TriNodeBasis::TriNodeBasis(size_t order){
  // Set BasisTwo Type //
  this->order = order;

  type = TYPE_TRI;
  dim  = 2;

  nVertex   = 3;
  nEdge     = 3 * (order - 1);
  nFace     =     (order - 1) * (order - 2) / 2;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  const vector<vector<vector<size_t> > >&
    faceIdx = ReferenceSpaceManager::getFaceNodeIndex(type);

  // Legendre Polynomial //
  const int orderMinus = order - 1;

  Polynomial* legendre    = new Polynomial[order];
  Polynomial* intLegendre = new Polynomial[order];

  Legendre::legendre(legendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Lagrange Polynomial //
  const Polynomial lagrange[3] =
    {
      Polynomial(Polynomial(1, 0, 0, 0) -
                 Polynomial(1, 1, 0, 0) -
                 Polynomial(1, 0, 1, 0)),

      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0))
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
  }

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex;

    for(size_t e = 0; e < 3; e++){
      for(size_t l = 1; l < order; l++){
        basis[s][i] =
          new Polynomial(intLegendre[l].compose(lagrange[edgeIdx[s][e][1]] -
                                                lagrange[edgeIdx[s][e][0]]
                                                ,
                                                lagrange[edgeIdx[s][e][0]] +
                                                lagrange[edgeIdx[s][e][1]]));
        i++;
      }
    }
  }

  // Face Based //

  // NB: We use (*(*faceIdx[s])[f])[]
  //     where f = 0, because triangles
  //     have only ONE face: the face '0'
  const int orderMinusTwo = order - 2;

  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex + nEdge;

    for(int l1 = 1; l1 < orderMinus; l1++){
      for(int l2 = 0; l2 + l1 - 1 < orderMinusTwo; l2++){
        basis[s][i] =
          new Polynomial(intLegendre[l1].compose(lagrange[faceIdx[s][0][1]] -
                                                 lagrange[faceIdx[s][0][0]]
                                                 ,
                                                 lagrange[faceIdx[s][0][0]] +
                                                 lagrange[faceIdx[s][0][1]])
                         *

                         legendre[l2].compose((lagrange[faceIdx[s][0][2]] * 2)
                                              -
                                              Polynomial(1, 0, 0, 0))
                         *

                         lagrange[faceIdx[s][0][2]]);
        i++;
      }
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
}

TriNodeBasis::~TriNodeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
