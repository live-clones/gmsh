#include "LineNedelecBasis.h"
#include "LineReferenceSpace.h"

using namespace std;

LineNedelecBasis::LineNedelecBasis(void){
  // Reference Space //
  refSpace  = new LineReferenceSpace;
  nRefSpace = getReferenceSpace().getNReferenceSpace();

  const vector<vector<vector<size_t> > >&
    edgeIdx = refSpace->getEdgeNodeIndex();

  // Set Basis Type //
  order = 0;

  type = 1;
  dim  = 1;

  nVertex   = 0;
  nEdge     = 1;
  nFace     = 0;
  nCell     = 0;
  nFunction = 1;

  // Lagrange Polynomial //
  const Polynomial lagrange[2] =
    {
      Polynomial(Polynomial(0.5, 0, 0, 0) -
                 Polynomial(0.5, 1, 0, 0)),

      Polynomial(Polynomial(0.5, 0, 0, 0) +
                 Polynomial(0.5, 1, 0, 0)),
    };

  // Basis //
  basis = new vector<Polynomial>**[nRefSpace];

  for(size_t s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  for(size_t s = 0; s < nRefSpace; s++){
    vector<Polynomial> tmp1 = lagrange[edgeIdx[s][0][1]].gradient();
    vector<Polynomial> tmp2 = lagrange[edgeIdx[s][0][0]].gradient();

    tmp1[0].mul(lagrange[edgeIdx[s][0][0]]);
    tmp1[1].mul(lagrange[edgeIdx[s][0][0]]);
    tmp1[2].mul(lagrange[edgeIdx[s][0][0]]);

    tmp2[0].mul(lagrange[edgeIdx[s][0][1]]);
    tmp2[1].mul(lagrange[edgeIdx[s][0][1]]);
    tmp2[2].mul(lagrange[edgeIdx[s][0][1]]);

    tmp2[0].sub(tmp1[0]);
    tmp2[1].sub(tmp1[1]);
    tmp2[2].sub(tmp1[2]);

    basis[s][0] = new vector<Polynomial>(tmp2);
  }
}

LineNedelecBasis::~LineNedelecBasis(void){
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
