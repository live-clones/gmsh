#include "TriNedelecBasis.h"

TriNedelecBasis::TriNedelecBasis(void){
  // Set Basis Type //
  order = 1;

  type = 1;
  dim  = 2;

  nVertex = 0;
  nEdge   = 3;
  nFace   = 0;
  nCell   = 0;

  size = 3;

  // Lagrange //
  Polynomial lagrange[3];

  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);


  // Basis (temporary --- *no* const) //
  std::vector<std::vector<Polynomial>*>    basis(size);
  std::vector<std::vector<Polynomial>*> revBasis(size);


  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3){
    // Direct
    std::vector<Polynomial> tmp = lagrange[j].gradient();
    tmp[0].mul(lagrange[i]);
    tmp[1].mul(lagrange[i]);
    tmp[2].mul(lagrange[i]);

    basis[i] = new std::vector<Polynomial>(lagrange[i].gradient());

    basis[i]->at(0).mul(lagrange[j]);
    basis[i]->at(1).mul(lagrange[j]);
    basis[i]->at(2).mul(lagrange[j]);
   
    basis[i]->at(0).sub(tmp[0]);
    basis[i]->at(1).sub(tmp[1]);
    basis[i]->at(2).sub(tmp[2]);

    // Revert 
    std::vector<Polynomial> tmpR = lagrange[i].gradient();
    tmpR[0].mul(lagrange[j]);
    tmpR[1].mul(lagrange[j]);
    tmpR[2].mul(lagrange[j]);

    revBasis[i] = new std::vector<Polynomial>(lagrange[j].gradient());

    revBasis[i]->at(0).mul(lagrange[i]);
    revBasis[i]->at(1).mul(lagrange[i]);
    revBasis[i]->at(2).mul(lagrange[i]);
   
    revBasis[i]->at(0).sub(tmpR[0]);
    revBasis[i]->at(1).sub(tmpR[1]);
    revBasis[i]->at(2).sub(tmpR[2]);
  }


  // Set Basis //
  this->basis    = new std::vector<const std::vector<Polynomial>*>
    (basis.begin(), basis.end());

  this->revBasis = new std::vector<const std::vector<Polynomial>*>
    (revBasis.begin(), revBasis.end());
}

TriNedelecBasis::~TriNedelecBasis(void){
  for(int i = 0; i < size; i++)
    delete (*basis)[i];

  delete basis;

  for(int i = 0; i < size; i++)
    delete (*revBasis)[i];

  delete revBasis;
}
