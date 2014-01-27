#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "TriNedelecBasis.h"

using namespace std;

TriNedelecBasis::TriNedelecBasis(void){
  // Set Basis Type //
  order = 0;

  type = TYPE_TRI;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 3;
  nFace     = 0;
  nCell     = 0;
  nFunction = 3;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  // Lagrange //
  const Polynomial lagrange[3] =
    {
      Polynomial(Polynomial(1, 0, 0, 0) -
                 Polynomial(1, 1, 0, 0) -
                 Polynomial(1, 0, 1, 0)),

      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0))
    };

  // Basis //
  basis = new vector<Polynomial>**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  for(size_t s = 0; s < nOrientation; s++){
    for(size_t e = 0; e < 3; e++){
      vector<Polynomial> tmp1 = lagrange[edgeIdx[s][e][1]].gradient();
      vector<Polynomial> tmp2 = lagrange[edgeIdx[s][e][0]].gradient();

      tmp1[0].mul(lagrange[edgeIdx[s][e][0]]);
      tmp1[1].mul(lagrange[edgeIdx[s][e][0]]);
      tmp1[2].mul(lagrange[edgeIdx[s][e][0]]);

      tmp2[0].mul(lagrange[edgeIdx[s][e][1]]);
      tmp2[1].mul(lagrange[edgeIdx[s][e][1]]);
      tmp2[2].mul(lagrange[edgeIdx[s][e][1]]);

      tmp2[0].sub(tmp1[0]);
      tmp2[1].sub(tmp1[1]);
      tmp2[2].sub(tmp1[2]);

      basis[s][e] = new vector<Polynomial>(tmp2);
    }
  }
}

TriNedelecBasis::~TriNedelecBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
