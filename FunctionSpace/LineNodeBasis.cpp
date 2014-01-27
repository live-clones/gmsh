#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "LineNodeBasis.h"

using namespace std;

LineNodeBasis::LineNodeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_LIN;
  dim  = 1;

  nVertex   = 2;
  nEdge     = (order - 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  // Legendre Polynomial //
  Polynomial* intLegendre = new Polynomial[order];
  Legendre::integrated(intLegendre, order);

  // Lagrange Polynomial //
  const Polynomial lagrange[2] =
    {
      Polynomial(Polynomial(0.5, 0, 0, 0) -
                 Polynomial(0.5, 1, 0, 0)),

      Polynomial(Polynomial(0.5, 0, 0, 0) +
                 Polynomial(0.5, 1, 0, 0)),
    };

  // Basis //
  basis = new Polynomial**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based //
  for(size_t s = 0; s < nOrientation; s++){
    basis[s][0] = new Polynomial(lagrange[0]);
    basis[s][1] = new Polynomial(lagrange[1]);
  }

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nVertex;

    for(size_t l = 1; l < order; l++){
      basis[s][i] =
        new Polynomial(intLegendre[l].compose(lagrange[edgeIdx[s][0][1]] -
                                              lagrange[edgeIdx[s][0][0]]));

      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] intLegendre;
}

LineNodeBasis::~LineNodeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
