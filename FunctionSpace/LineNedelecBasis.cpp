#include "LineNedelecBasis.h"
#include "LineReferenceSpace.h"
#include "Legendre.h"

using namespace std;

LineNedelecBasis::LineNedelecBasis(void){
  // Reference Space //
  refSpace  = new LineReferenceSpace;
  nRefSpace = refSpace->getNPermutation();

  // Set Basis Type //
  order = 1;
  
  type = 1;
  dim  = 1;

  nVertex   = 0;
  nEdge     = 1;
  nFace     = 0;
  nCell     = 0;
  nFunction = 1;

  // Alloc Temporary Space //
  vector<Polynomial> first(3);
  first[0] = Polynomial(+0.5, 0, 0, 0);
  first[1] = Polynomial( 0  , 0, 0, 0);
  first[2] = Polynomial( 0  , 0, 0, 0);

  vector<Polynomial> second(3);
  second[0] = Polynomial(-0.5, 0, 0, 0);
  second[1] = Polynomial( 0  , 0, 0, 0);
  second[2] = Polynomial( 0  , 0, 0, 0);

  // Basis //
  basis = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Nedelec // 
  basis[0][0] = new vector<Polynomial>(first);
  basis[1][0] = new vector<Polynomial>(second);
}

LineNedelecBasis::~LineNedelecBasis(void){
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
