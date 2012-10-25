#include "TetEdgeBasis.h"
#include "Legendre.h"

using namespace std;

TetEdgeBasis::TetEdgeBasis(int order){
  // Set Basis Type //
  this->order = order;
 
  type = 1;
  dim  = 3;

  nVertex = 0;
  nEdge   = 6 * (order + 1);
  nFace   = 4 * (order + 1) * (order - 1);
  nCell   =     (order + 1) * (order - 1) * (order - 2) / 2;

  nEdgeClosure = 2;
  nFaceClosure = 6;

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const int orderPlus     = order + 1;
  const int orderMinus    = order - 1;
  const int orderMinusTwo = order - 2;

  Polynomial  lagrange[4];

  Polynomial* legendre    = new Polynomial[orderMinus];
  Polynomial* sclLegendre = new Polynomial[orderMinus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinusTwo);
  Legendre::scaled(sclLegendre, orderMinusTwo);
  Legendre::intScaled(intLegendre, orderPlus);

  // Vertices definig Edges & Permutations //
  const int edgeV[2][6][2] = 
    {
      { {0, 1}, {1, 2}, {2, 0}, 
	{3, 0}, {3, 2}, {3, 1} },
      
      { {1, 0}, {2, 1}, {0, 2}, 
	{0, 3}, {2, 3}, {1, 3} }
    };

  // Vertices definig Faces & Permutations //
  const int faceV[6][4][3] = 
    {
      { {0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2} },
      { {2, 0, 1}, {1, 0, 3}, {3, 0, 2}, {1, 3, 2} },
      { {2, 1, 0}, {1, 3, 0}, {3, 2, 0}, {1, 2, 3} },
      { {1, 2, 0}, {3, 1, 0}, {2, 3, 0}, {2, 1, 3} },
      { {1, 0, 2}, {3, 0, 1}, {2, 0, 3}, {2, 3, 1} },
      { {0, 1, 2}, {0, 3, 1}, {0, 2, 3}, {3, 2, 1} },
    };
  
  // Basis //
  node = new vector<vector<Polynomial>*>(nVertex);
  edge = new vector<vector<vector<Polynomial>*>*>(2);
  face = new vector<vector<vector<Polynomial>*>*>(6);
  cell = new vector<vector<Polynomial>*>(nCell);

  (*edge)[0] = new vector<vector<Polynomial>*>(nEdge);
  (*edge)[1] = new vector<vector<Polynomial>*>(nEdge);

  (*face)[0] = new vector<vector<Polynomial>*>(nFace);
  (*face)[1] = new vector<vector<Polynomial>*>(nFace);
  (*face)[2] = new vector<vector<Polynomial>*>(nFace);
  (*face)[3] = new vector<vector<Polynomial>*>(nFace);
  (*face)[4] = new vector<vector<Polynomial>*>(nFace);
  (*face)[5] = new vector<vector<Polynomial>*>(nFace);


  // Lagrange //
  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - 
    Polynomial(1, 1, 0, 0) - 
    Polynomial(1, 0, 1, 0) -
    Polynomial(1, 0, 0, 1);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);

  lagrange[3] = 
    Polynomial(1, 0, 0, 1);

  
  // Edge Based (Nedelec) //
  for(int c = 0; c < 2; c++){
    for(int e = 0; e < 6; e++){
      vector<Polynomial> tmp = lagrange[edgeV[c][e][1]].gradient();
      
      tmp[0].mul(lagrange[edgeV[c][e][0]]);
      tmp[1].mul(lagrange[edgeV[c][e][0]]);
      tmp[2].mul(lagrange[edgeV[c][e][0]]);
      
      (*(*edge)[c])[e] = 
	new vector<Polynomial>(lagrange[edgeV[c][e][0]].gradient());
      
      (*(*edge)[c])[e]->at(0).mul(lagrange[edgeV[c][e][1]]);
      (*(*edge)[c])[e]->at(1).mul(lagrange[edgeV[c][e][1]]);
      (*(*edge)[c])[e]->at(2).mul(lagrange[edgeV[c][e][1]]);      
      
      (*(*edge)[c])[e]->at(0).sub(tmp[0]);
      (*(*edge)[c])[e]->at(1).sub(tmp[1]);
      (*(*edge)[c])[e]->at(2).sub(tmp[2]);
    }
  }
  

  // Edge Based (High Order) //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;

    for(int l = 1; l < orderPlus; l++){
      for(int e = 0; e < 6; e++){
	(*(*edge)[c])[i + 6] = 
	  new vector<Polynomial>
	  (intLegendre[l].compose
	   (lagrange[edgeV[c][e][0]] - lagrange[edgeV[c][e][1]],  
	    lagrange[edgeV[c][e][0]] + lagrange[edgeV[c][e][1]]).gradient());
	
	i++;
      }
    }
  }
  
  
  // Face Based //
  for(int c = 0; c < 6; c++){
    unsigned int i = 0;

    for(int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + l1 - 1 < orderMinus; l2++){
	for(int f = 0; f < 4; f++){
	  // Preliminary Type 1
	  Polynomial sum = 
	    lagrange[faceV[c][f][0]] +
	    lagrange[faceV[c][f][1]] +
	    lagrange[faceV[c][f][2]];	  
	  
	  Polynomial u = intLegendre[l1].compose
	    (lagrange[faceV[c][f][0]] - lagrange[faceV[c][f][1]],  
	     lagrange[faceV[c][f][0]] + lagrange[faceV[c][f][1]]);
	  
	  Polynomial v = lagrange[faceV[c][f][2]] * sclLegendre[l2].compose
	    (lagrange[faceV[c][f][2]] * 2 - sum, sum);
	  
	  // Preliminary Type 2
	  vector<Polynomial> gradU = u.gradient();
	  vector<Polynomial> gradV = v.gradient();

	  vector<Polynomial> vGradU(gradU);
	  vGradU[0].mul(v);
	  vGradU[1].mul(v);
	  vGradU[2].mul(v);

	  vector<Polynomial> uGradV(gradV);
	  uGradV[0].mul(u);
	  uGradV[1].mul(u);
	  uGradV[2].mul(u);

	  vector<Polynomial> subGradUV(vGradU);
	  subGradUV[0].sub(uGradV[0]);
	  subGradUV[1].sub(uGradV[1]);
	  subGradUV[2].sub(uGradV[2]);

	  // Preliminary Type 3
	  vector<Polynomial> gradL1 = lagrange[faceV[c][f][0]].gradient();
	  vector<Polynomial> gradL2 = lagrange[faceV[c][f][1]].gradient();

	  vector<Polynomial> l2GradL1(gradL1);
	  l2GradL1[0].mul(lagrange[faceV[c][f][1]]);
	  l2GradL1[1].mul(lagrange[faceV[c][f][1]]);
	  l2GradL1[2].mul(lagrange[faceV[c][f][1]]);

	  vector<Polynomial> l1GradL2(gradL2);
	  l1GradL2[0].mul(lagrange[faceV[c][f][0]]);
	  l1GradL2[1].mul(lagrange[faceV[c][f][0]]);
	  l1GradL2[2].mul(lagrange[faceV[c][f][0]]);

	  vector<Polynomial> subGradL1L2V(l2GradL1);
	  subGradL1L2V[0].sub(l1GradL2[0]);
	  subGradL1L2V[1].sub(l1GradL2[1]);
	  subGradL1L2V[2].sub(l1GradL2[2]);

	  subGradL1L2V[0].mul(v);
	  subGradL1L2V[1].mul(v);
	  subGradL1L2V[2].mul(v);
	  

	  // Type 1
	  (*(*face)[c])[i] = 
	    new vector<Polynomial>((u * v).gradient());
	  
	  i++;

	  // Type 2
	  (*(*face)[c])[i] =
	    new vector<Polynomial>(subGradUV);

	  i++;

	  // Type 3
	  if(l1 == 1){
	    (*(*face)[c])[i] =
	      new vector<Polynomial>(subGradL1L2V);
	    
	    i++;
	  }
	}
      }
    }
  }
  
  
  // Cell Based //
  Polynomial one(1, 0, 0, 0);

  unsigned int i = 0;

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
	(*cell)[i] = new vector<Polynomial>((u * v * w).gradient());
	i++;
	
	// Type 2 -- Part 1
	(*cell)[i] = new vector<Polynomial>(term1);
	i++;

	// Type 2 -- Part 2
	(*cell)[i] = new vector<Polynomial>(term2);
	i++;

	// Type 3
	if(l1 == 1){
	  (*cell)[i] = new vector<Polynomial>(subGradL1L2VW);
	  i++;
	}
      }
    }
  }


  // Free Temporary Sapce //
  delete[] legendre;
  delete[] sclLegendre;
  delete[] intLegendre;
}

TetEdgeBasis::~TetEdgeBasis(void){
  // Vertex Based //
  for(int i = 0; i < nVertex; i++)
    delete (*node)[i];
  
  delete node;


  // Edge Based //
  for(int c = 0; c < 2; c++){
    for(int i = 0; i < nEdge; i++)
      delete (*(*edge)[c])[i];
    
    delete (*edge)[c];
  }
  
  delete edge;


  // Face Based //
  for(int c = 0; c < 6; c++){
    for(int i = 0; i < nFace; i++)
      delete (*(*face)[c])[i];
    
    delete (*face)[c];
  }

  delete face;


  // Cell Based //
  for(int i = 0; i < nCell; i++)
    delete (*cell)[i];
  
  delete cell;
}
