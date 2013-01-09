#include "TriEdgeBasis.h"
#include "TriReferenceSpace.h"
#include "Legendre.h"

using namespace std;

TriEdgeBasis::TriEdgeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new TriReferenceSpace;
  nRefSpace = refSpace->getNPermutation();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  // Set Basis Type //
  this->order = order;
 
  type = 1;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 3 * (order + 1);
  nFace     = 0;
  nCell     = ((order - 1) * order + order - 1);
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Some Space //
  const int orderPlus  = order + 1;
  const int orderMinus = order - 1;

  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];
  Polynomial* u           = new Polynomial[orderPlus];
  Polynomial* v           = new Polynomial[orderPlus];

  // Legendre Polynomial //
  Legendre::legendre(legendre, order);
  Legendre::intScaled(intLegendre, orderPlus);

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
  basis = new vector<vector<const vector<Polynomial>*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const vector<Polynomial>*>(nFunction);

  // Edge Based (Nedelec) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    for(int e = 0; e < 3; e++){
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

      (*(*basis)[s])[e] = new vector<Polynomial>(tmp2);
    }
  }

  // Edge Based (High Order) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = 3;

    for(int l = 1; l < orderPlus; l++){
      for(int e = 0; e < 3; e++){
	(*(*basis)[s])[i] = 
	  new vector<Polynomial>
	  ((intLegendre[l].compose(lagrange[(*(*edgeV[s])[e])[0]] -
				   lagrange[(*(*edgeV[s])[e])[1]]
				   , 
				   lagrange[(*(*edgeV[s])[e])[1]] +
				   lagrange[(*(*edgeV[s])[e])[0]])).gradient());
	i++;
      }
    }
  }

  // Cell Based //

  // Preliminaries 
  const Polynomial p = lagrange[2] * 2 - Polynomial(1, 0, 0, 0);
  
  for(int l = 0; l < orderPlus; l++){
    u[l] = intLegendre[l].compose(lagrange[1] - lagrange[0], 
				  lagrange[0] + lagrange[1]);
    v[l] = legendre[l].compose(p);
    v[l].mul(lagrange[2]);
  }

  vector<Polynomial> gradL1 = lagrange[0].gradient();
  vector<Polynomial> gradL2 = lagrange[1].gradient();
  
  vector<Polynomial> l2GradL1(gradL1);
  l2GradL1[0].mul(lagrange[1]);
  l2GradL1[1].mul(lagrange[1]);
  l2GradL1[2].mul(lagrange[1]);
  
  vector<Polynomial> l1GradL2(gradL2);
  l1GradL2[0].mul(lagrange[0]);
  l1GradL2[1].mul(lagrange[0]);
  l1GradL2[2].mul(lagrange[0]);
  
  vector<Polynomial> subGradL1L2(l2GradL1);
  subGradL1L2[0].sub(l1GradL2[0]);
  subGradL1L2[1].sub(l1GradL2[1]);
  subGradL1L2[2].sub(l1GradL2[2]);

  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge;
  
    // Type 1
    for(unsigned int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
	vector<Polynomial> tmp1 = v[l2].gradient();
	vector<Polynomial> tmp2 = u[l1].gradient();

	tmp1[0].mul(u[l1]);
	tmp1[1].mul(u[l1]);
	tmp1[2].mul(u[l1]);

	tmp2[0].mul(v[l2]);
	tmp2[1].mul(v[l2]);
	tmp2[2].mul(v[l2]);
	
	tmp2[0].add(tmp1[0]);
	tmp2[1].add(tmp1[1]);
	tmp2[2].add(tmp1[2]);
	
	(*(*basis)[s])[i] = new vector<Polynomial>(tmp2);

	i++;
      }
    }
  
    // Type 2
    for(unsigned int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
	vector<Polynomial> tmp1 = v[l2].gradient();
	vector<Polynomial> tmp2 = u[l1].gradient();
	
	tmp1[0].mul(u[l1]);
	tmp1[1].mul(u[l1]);
	tmp1[2].mul(u[l1]);
	
	tmp2[0].mul(v[l2]);
	tmp2[1].mul(v[l2]);
	tmp2[2].mul(v[l2]);
	
	tmp2[0].sub(tmp1[0]);
	tmp2[1].sub(tmp1[1]);
	tmp2[2].sub(tmp1[2]);
	
	(*(*basis)[s])[i] = new vector<Polynomial>(tmp2);

	i++;
      }
    }

    // Type 3
    for(int l = 0; l < orderMinus; l++){
      vector<Polynomial> subGradL1L2V(subGradL1L2);
    
      subGradL1L2V[0].mul(v[l]);
      subGradL1L2V[1].mul(v[l]);
      subGradL1L2V[2].mul(v[l]);
      
      (*(*basis)[s])[i] = new vector<Polynomial>(subGradL1L2V);
      
      i++;
    }
  }  

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
  delete[] u;
  delete[] v;
}

TriEdgeBasis::~TriEdgeBasis(void){
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete (*(*basis)[i])[j];

    delete (*basis)[i];
  }

  delete basis;
}
