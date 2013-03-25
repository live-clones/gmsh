#include "TetNedelecBasis.h"
#include "TetReferenceSpace.h"

using namespace std;

TetNedelecBasis::TetNedelecBasis(void){
  // Reference Space //
  refSpace  = new TetReferenceSpace;
  nRefSpace = refSpace->getNPermutation();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  // Set Basis Type //
  this->order = 0;

  type = 1;
  dim  = 3;

  nVertex   = 0;
  nEdge     = 6;
  nFace     = 0;
  nCell     = 0;
  nFunction = 6;

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
  basis = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based (Nedelec) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    for(unsigned int e = 0; e < 6; e++){
      vector<Polynomial> tmp1 = lagrange[(*(*edgeV[s])[e])[1]].gradient();
      vector<Polynomial> tmp2 = lagrange[(*(*edgeV[s])[e])[0]].gradient();

      tmp1[0].mul(lagrange[(*(*edgeV[s])[e])[0]]);
      tmp1[1].mul(lagrange[(*(*edgeV[s])[e])[0]]);
      tmp1[2].mul(lagrange[(*(*edgeV[s])[e])[0]]);

      tmp2[0].mul(lagrange[(*(*edgeV[s])[e])[1]]);
      tmp2[1].mul(lagrange[(*(*edgeV[s])[e])[1]]);
      tmp2[2].mul(lagrange[(*(*edgeV[s])[e])[1]]);

      tmp2[0].sub(tmp1[0]);
      tmp2[1].sub(tmp1[1]);
      tmp2[2].sub(tmp1[2]);

      basis[s][e] = new vector<Polynomial>(tmp2);
    }
  }
}

TetNedelecBasis::~TetNedelecBasis(void){
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
