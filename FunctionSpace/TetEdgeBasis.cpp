#include "TetEdgeBasis.h"
#include "TetReferenceSpace.h"
#include "Legendre.h"

using namespace std;

TetEdgeBasis::TetEdgeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new TetReferenceSpace;
  nRefSpace = refSpace->getNReferenceSpace();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  const vector<const vector<const vector<unsigned int>*>*>&
    faceV = refSpace->getAllFace();

  // Set Basis Type //
  this->order = order;
 
  type = 1;
  dim  = 3;

  nVertex   = 0;
  nEdge     = 6 * (order + 1);
  nFace     = 4 * (order + 1) * (order - 1);
  nCell     =     (order + 1) * (order - 1) * (order - 2) / 2;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const int orderPlus     = order + 1;
  const int orderMinus    = order - 1;
  const int orderMinusTwo = order - 2;

  Polynomial* legendre    = new Polynomial[orderMinus];
  Polynomial* sclLegendre = new Polynomial[orderMinus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinusTwo);
  Legendre::scaled(sclLegendre, orderMinusTwo);
  Legendre::intScaled(intLegendre, orderPlus);
  
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
  basis = new vector<vector<const vector<Polynomial>*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const vector<Polynomial>*>(nFunction);
    
  // Edge Based (Nedelec) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    for(int e = 0; e < 6; e++){
      vector<Polynomial> tmp1 = lagrange[(*(*edgeV[s])[e])[1]].gradient();
      vector<Polynomial> tmp2 = lagrange[(*(*edgeV[s])[e])[0]].gradient();

      tmp1[0].mul(lagrange[(*(*edgeV[s])[e])[0]]);
      tmp1[1].mul(lagrange[(*(*edgeV[s])[e])[0]]);
      tmp1[2].mul(lagrange[(*(*edgeV[s])[e])[0]]);
            
      tmp2[0].mul(lagrange[(*(*edgeV[s])[e])[1]]);
      tmp2[1].mul(lagrange[(*(*edgeV[s])[e])[1]]);
      tmp2[2].mul(lagrange[(*(*edgeV[s])[e])[1]]);      
      
      tmp1[0].sub(tmp2[0]);
      tmp1[1].sub(tmp2[1]);
      tmp1[2].sub(tmp2[2]);

      (*(*basis)[s])[e] = new vector<Polynomial>(tmp1);
    }
  }
  
  // Edge Based (High Order) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = 6;

    for(int l = 1; l < orderPlus; l++){
      for(int e = 0; e < 6; e++){
	(*(*basis)[s])[i] = 
	  new vector<Polynomial>
	  ((intLegendre[l].compose(lagrange[(*(*edgeV[s])[e])[0]] - 
				   lagrange[(*(*edgeV[s])[e])[1]]
				   ,
				   lagrange[(*(*edgeV[s])[e])[0]] + 
				   lagrange[(*(*edgeV[s])[e])[1]])).gradient());
	i++;
      }
    }
  }
  
  // Face Based (Preliminary) //
  unsigned int faceOffset = 0;

  // Sum
  Polynomial** sum;
  sum = new Polynomial*[nRefSpace];
  
  for(unsigned int s = 0; s < nRefSpace; s++){
    sum[s] = new Polynomial[4];
    
    for(unsigned int f = 0; f < 4; f++)
      sum[s][f] = 
	lagrange[(*(*faceV[s])[f])[0]] +
	lagrange[(*(*faceV[s])[f])[1]] +
	lagrange[(*(*faceV[s])[f])[2]];
  }

  // Polynomial u
  Polynomial*** u;
  u = new Polynomial**[nRefSpace];
  
  for(unsigned int s = 0; s < nRefSpace; s++){
    u[s] = new Polynomial*[orderPlus];
    
    for(int l = 0; l < orderPlus; l++){
      u[s][l] = new Polynomial[4];
      
      for(unsigned int f = 0; f < 4; f++)
	u[s][l][f] = 
	  intLegendre[l].compose(lagrange[(*(*faceV[s])[f])[0]] - 
				  lagrange[(*(*faceV[s])[f])[1]]
				  ,
				  lagrange[(*(*faceV[s])[f])[0]] + 
				  lagrange[(*(*faceV[s])[f])[1]]);
    }
  }
  
  // Polynomial v
  Polynomial*** v;
  v = new Polynomial**[nRefSpace];
  
  for(unsigned int s = 0; s < nRefSpace; s++){
    v[s] = new Polynomial*[orderMinus];
    
    for(int l = 0; l < orderMinus; l++){
      v[s][l] = new Polynomial[4];
      
      for(unsigned int f = 0; f < 4; f++)
	v[s][l][f] = 
	    lagrange[(*(*faceV[s])[f])[2]] * 
	    sclLegendre[l].compose
	  (lagrange[(*(*faceV[s])[f])[2]] * 2 - sum[s][f], sum[s][f]);
    }
  }

  // Face Based (Type 1) // 
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge;

    for(unsigned int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
	for(int f = 0; f < 4; f++){
	  
	  (*(*basis)[s])[i] = 
	    new vector<Polynomial>((u[s][l1][f] * v[s][l2][f]).gradient());
	  
	  i++;
	  
	  if(s == 0)
	    faceOffset++;
	}
      }
    }
  }

  // Face Based (Type 2) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge + faceOffset;

    for(unsigned int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
	for(int f = 0; f < 4; f++){	  
	  vector<Polynomial> gradU = u[s][l1][f].gradient();
	  vector<Polynomial> gradV = v[s][l2][f].gradient();

	  vector<Polynomial> vGradU(gradU);
	  vGradU[0].mul(v[s][l2][f]);
	  vGradU[1].mul(v[s][l2][f]);
	  vGradU[2].mul(v[s][l2][f]);

	  vector<Polynomial> uGradV(gradV);
	  uGradV[0].mul(u[s][l1][f]);
	  uGradV[1].mul(u[s][l1][f]);
	  uGradV[2].mul(u[s][l1][f]);

	  vector<Polynomial> subGradUV(vGradU);
	  subGradUV[0].sub(uGradV[0]);
	  subGradUV[1].sub(uGradV[1]);
	  subGradUV[2].sub(uGradV[2]);

	  (*(*basis)[s])[i] =
	    new vector<Polynomial>(subGradUV);

	  i++;
	}
      }
    }
  }

  // Face Based (Type 3) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge + faceOffset * 2;

    for(int l2 = 0; l2  < orderMinus; l2++){
      for(int f = 0; f < 4; f++){
	vector<Polynomial> gradL1 = lagrange[(*(*faceV[s])[f])[0]].gradient();
	vector<Polynomial> gradL2 = lagrange[(*(*faceV[s])[f])[1]].gradient();

	vector<Polynomial> l2GradL1(gradL1);
	l2GradL1[0].mul(lagrange[(*(*faceV[s])[f])[1]]);
	l2GradL1[1].mul(lagrange[(*(*faceV[s])[f])[1]]);
	l2GradL1[2].mul(lagrange[(*(*faceV[s])[f])[1]]);
	
	vector<Polynomial> l1GradL2(gradL2);
	l1GradL2[0].mul(lagrange[(*(*faceV[s])[f])[0]]);
	l1GradL2[1].mul(lagrange[(*(*faceV[s])[f])[0]]);
	l1GradL2[2].mul(lagrange[(*(*faceV[s])[f])[0]]);

	vector<Polynomial> subGradL1L2V(l2GradL1);
	subGradL1L2V[0].sub(l1GradL2[0]);
	subGradL1L2V[1].sub(l1GradL2[1]);
	subGradL1L2V[2].sub(l1GradL2[2]);

	subGradL1L2V[0].mul(v[s][l2][f]);
	subGradL1L2V[1].mul(v[s][l2][f]);
	subGradL1L2V[2].mul(v[s][l2][f]);
	  
	(*(*basis)[s])[i] =
	  new vector<Polynomial>(subGradL1L2V);
	
	i++;
      }
    }
  }
        
  // Cell Based //
  const Polynomial one(1, 0, 0, 0);
  
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge + nFace;

    for(int l1 = 1; l1 < orderMinus; l1++){
      for(int l2 = 0; l2 + l1 - 1 <  orderMinusTwo; l2++){
	for(int l3 = 0; l3 + l2 + l1 - 1 <  orderMinusTwo; l3++){
	  // Preliminary Type 1
	  Polynomial u = intLegendre[l1].compose
	    (lagrange[0] - lagrange[1],  
	     lagrange[0] + lagrange[1]);
	  
	  Polynomial v = lagrange[2] * sclLegendre[l2].compose
	    (lagrange[2] * 2 - (one - lagrange[3]), one - lagrange[3]);
	  
	  Polynomial w = lagrange[3] * legendre[l3].compose
	    (lagrange[3] * 2 - one);
	  
	  // Preliminary Type 2
	  vector<Polynomial> gradU = u.gradient();
	  vector<Polynomial> gradV = v.gradient();
	  vector<Polynomial> gradW = w.gradient();
	  
	  vector<Polynomial> vwGradU(gradU);
	  vwGradU[0].mul(v);
	  vwGradU[1].mul(v);
	  vwGradU[2].mul(v);
	  
	  vwGradU[0].mul(w);
	  vwGradU[1].mul(w);
	  vwGradU[2].mul(w);
	  
	  vector<Polynomial> uwGradV(gradV);
	  uwGradV[0].mul(u);
	  uwGradV[1].mul(u);
	  uwGradV[2].mul(u);
	  
	  uwGradV[0].mul(w);
	  uwGradV[1].mul(w);
	  uwGradV[2].mul(w);
	  
	  vector<Polynomial> uvGradW(gradW);
	  uvGradW[0].mul(u);
	  uvGradW[1].mul(u);
	  uvGradW[2].mul(u);
	  
	  uvGradW[0].mul(v);
	  uvGradW[1].mul(v);
	  uvGradW[2].mul(v);
	  
	  vector<Polynomial> term1(vwGradU);
	  term1[0].sub(uwGradV[0]);
	  term1[1].sub(uwGradV[1]);
	  term1[2].sub(uwGradV[2]);
	  
	  term1[0].add(uvGradW[0]);
	  term1[1].add(uvGradW[1]);
	  term1[2].add(uvGradW[2]);
	  
	  vector<Polynomial> term2(vwGradU);
	  term2[0].add(uwGradV[0]);
	  term2[1].add(uwGradV[1]);
	  term2[2].add(uwGradV[2]);
	  
	  term2[0].sub(uvGradW[0]);
	  term2[1].sub(uvGradW[1]);
	  term2[2].sub(uvGradW[2]);
	  
	  // Preliminary Type 3
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
	  
	  vector<Polynomial> subGradL1L2VW(l2GradL1);
	  subGradL1L2VW[0].sub(l1GradL2[0]);
	  subGradL1L2VW[1].sub(l1GradL2[1]);
	  subGradL1L2VW[2].sub(l1GradL2[2]);
	  
	  subGradL1L2VW[0].mul(v);
	  subGradL1L2VW[1].mul(v);
	  subGradL1L2VW[2].mul(v);
	  
	  subGradL1L2VW[0].mul(w);
	  subGradL1L2VW[1].mul(w);
	  subGradL1L2VW[2].mul(w);
	  
	  
	  // Type 1
	  (*(*basis)[s])[i] = new vector<Polynomial>((u * v * w).gradient());
	  i++;
	  
	  // Type 2 -- Part 1
	  (*(*basis)[s])[i] = new vector<Polynomial>(term1);
	  i++;
	  
	  // Type 2 -- Part 2
	  (*(*basis)[s])[i] = new vector<Polynomial>(term2);
	  i++;
	  
	  // Type 3
	  if(l1 == 1){
	    (*(*basis)[s])[i] = new vector<Polynomial>(subGradL1L2VW);
	    i++;
	  }
	}
      }
    }
  }
        
  // Free Temporary Space //
  // Legendre
  delete[] legendre;
  delete[] sclLegendre;
  delete[] intLegendre;

  // Sum
  for(unsigned int s = 0; s < nRefSpace; s++)
    delete[] sum[s];
  
  delete[] sum;
  
  // Polynomial u
  for(unsigned int s = 0; s < nRefSpace; s++){
    for(int l = 0; l < orderPlus; l++)
      delete[] u[s][l];

    delete[] u[s];
  }

  delete[] u;

  // Polynomial v
  for(unsigned int s = 0; s < nRefSpace; s++){
    for(int l = 0; l < orderMinus; l++)
      delete[] v[s][l];

    delete[] v[s];
  }

  delete[] v;
}

TetEdgeBasis::~TetEdgeBasis(void){
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

