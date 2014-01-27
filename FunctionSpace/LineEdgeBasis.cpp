#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "LineEdgeBasis.h"

using namespace std;

LineEdgeBasis::LineEdgeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_LIN;
  dim  = 1;

  nVertex   = 0;
  nEdge     = (order + 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  // Legendre Polynomial //
  const size_t orderPlus = order + 1;
  Polynomial* intLegendre = new Polynomial[orderPlus];

  Legendre::integrated(intLegendre, orderPlus);

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

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = 0;

    for(size_t l = 0; l < orderPlus; l++){
      // Nedelec
      if(l == 0){
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

        basis[s][i] = new vector<Polynomial>(tmp2);
      }

      // High Order
      else{
        basis[s][i] =
          new vector<Polynomial>
          ((intLegendre[l].compose(lagrange[edgeIdx[s][0][0]] -
                                   lagrange[edgeIdx[s][0][1]]).gradient()));
      }
      i++;
    }
  }

  // Free Temporary Space //
  delete[] intLegendre;
}

LineEdgeBasis::~LineEdgeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
