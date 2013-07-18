#include "LineEdgeBasis.h"
#include "LineReferenceSpace.h"
#include "Legendre.h"

using namespace std;

LineEdgeBasis::LineEdgeBasis(size_t order){
  // Reference Space //
  refSpace  = new LineReferenceSpace;
  nRefSpace = getReferenceSpace().getNReferenceSpace();

  const vector<vector<vector<size_t> > >&
    edgeIdx = refSpace->getEdgeNodeIndex();

  // Set Basis Type //
  this->order = order;

  type = 1;
  dim  = 1;

  nVertex   = 0;
  nEdge     = (order + 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const size_t orderPlus = order + 1;
  Polynomial* intLegendre = new Polynomial[orderPlus];

  vector<Polynomial> first(3);
  first[0] = Polynomial(-0.5, 0, 0, 0);
  first[1] = Polynomial( 0  , 0, 0, 0);
  first[2] = Polynomial( 0  , 0, 0, 0);

  vector<Polynomial> second(3);
  second[0] = Polynomial(+0.5, 0, 0, 0);
  second[1] = Polynomial( 0  , 0, 0, 0);
  second[2] = Polynomial( 0  , 0, 0, 0);

  const Polynomial x[2] = {
    Polynomial(-1, 1, 0, 0),
    Polynomial(+1, 1, 0, 0)
  };

  // Legendre Polynomial //
  Legendre::integrated(intLegendre, orderPlus);

  // Basis //
  basis = new vector<Polynomial>**[nRefSpace];

  for(size_t s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  basis[0][0] = new vector<Polynomial>(first);
  basis[1][0] = new vector<Polynomial>(second);

  // Edge Based (High Order) //
  for(size_t s = 0; s < nRefSpace; s++){
    size_t i = 1;

    for(size_t l = 1; l < orderPlus; l++){
      basis[s][i] =
        new vector<Polynomial>((intLegendre[l].compose
                                (x[edgeIdx[s][0][0]])).gradient());

      i++;
    }
  }

  // Free Temporary Space //
  delete[] intLegendre;
}

LineEdgeBasis::~LineEdgeBasis(void){
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
