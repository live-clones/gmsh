#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "LineNedelecBasis.h"

using namespace std;

LineNedelecBasis::LineNedelecBasis(void){
  // Set Basis Type //
  order = 0;

  type = TYPE_LIN;
  dim  = 1;

  nVertex   = 0;
  nEdge     = 1;
  nFace     = 0;
  nCell     = 0;
  nFunction = 1;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  // Lagrange Polynomial //
  const Polynomial lagrange[2] =
    {
      Polynomial(Polynomial(0.5, 0, 0, 0) -
                 Polynomial(0.5, 1, 0, 0)),

      Polynomial(Polynomial(0.5, 0, 0, 0) +
                 Polynomial(0.5, 1, 0, 0)),
    };

  // Basis //
  basis = new vector<Polynomial>**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  for(size_t s = 0; s < nOrientation; s++){
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
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
