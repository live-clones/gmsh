#include "LineNodeBasis.h"
#include "LineReferenceSpace.h"
#include "Legendre.h"

using namespace std;

LineNodeBasis::LineNodeBasis(size_t order){
  // Reference Space //
  refSpace  = new LineReferenceSpace;
  nRefSpace = getReferenceSpace().getNReferenceSpace();

  const vector<vector<vector<size_t> > >&
    edgeIdx = refSpace->getEdgeNodeIndex();

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 1;

  nVertex   = 2;
  nEdge     = (order - 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  Polynomial* intLegendre = new Polynomial[order];

  const Polynomial x[2] = {
    Polynomial(+1, 1, 0, 0),
    Polynomial(-1, 1, 0, 0)
  };

  // Legendre Polynomial //
  Legendre::integrated(intLegendre, order);

  // Basis //
  basis = new Polynomial**[nRefSpace];

  for(size_t s = 0; s < nRefSpace; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based (Lagrange) //
  for(size_t s = 0; s < nRefSpace; s++){
    basis[s][0] =
      new Polynomial(Polynomial(0.5, 0, 0, 0) -
                     Polynomial(0.5, 1, 0, 0));

    basis[s][1] =
      new Polynomial(Polynomial(0.5, 0, 0, 0) +
                     Polynomial(0.5, 1, 0, 0));
  }

  // Edge Based //
  for(size_t s = 0; s < nRefSpace; s++){
    size_t i = nVertex;

    for(size_t l = 1; l < order; l++){
      basis[s][i] =
        new Polynomial(intLegendre[l].compose(x[edgeIdx[s][0][0]]));

      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] intLegendre;
}

LineNodeBasis::~LineNodeBasis(void){
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
