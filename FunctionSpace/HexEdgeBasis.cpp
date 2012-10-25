#include <vector>
#include "HexEdgeBasis.h"
#include "Legendre.h"

using namespace std;

HexEdgeBasis::HexEdgeBasis(int order){
  /*
  // Set Basis Type //
  this->order = order;
  
  type = 1;
  dim  = 3;

  nVertex =  0;
  nEdge   = 12                 * (order + 1);
  nFace   = 12         * order * (order + 1);
  nCell   =  3 * order * order * (order + 1);

  nEdgeClosure = 2;
  nFaceClosure = 8;

  size = 3 * (order + 2) * (order + 2) * (order + 1);

  // Alloc Temporary Space //
  const int  orderPlus      = order + 1;
  Polynomial* legendre      = new Polynomial[orderPlus];
  Polynomial* intLegendre   = new Polynomial[orderPlus];

  Polynomial* xi            = new Polynomial[6];
  Polynomial* eta           = new Polynomial[6];
  Polynomial* lambda        = new Polynomial[6];

  vector<Polynomial>* grXi  = new vector<Polynomial>[6];
  vector<Polynomial>* grEta = new vector<Polynomial>[6];

  Polynomial** iLegendreXi  = new Polynomial*[orderPlus];
  Polynomial** iLegendreEta = new Polynomial*[orderPlus];
  Polynomial** legendreXi   = new Polynomial*[orderPlus];
  Polynomial** legendreEta  = new Polynomial*[orderPlus];

  Polynomial* iLegendreX    = new Polynomial[orderPlus];
  Polynomial* iLegendreY    = new Polynomial[orderPlus];
  Polynomial* iLegendreZ    = new Polynomial[orderPlus];

  Polynomial* lagrange      = new Polynomial[8];
  Polynomial* lagrangeSum   = new Polynomial[12];

  Polynomial* lifting       = new Polynomial[8];
  Polynomial* liftingSub    = new Polynomial[12];


  // Legendre Polynomial //
  Legendre::integrated(intLegendre, orderPlus);
  Legendre::legendre(legendre, order);


  // Points definig Edges //
  int edge1[12] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3};
  int edge2[12] = {1, 2, 3, 0, 5, 6, 7, 4, 4, 5, 6, 7};


  // Lagrange // 
  lagrange[0] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lagrange[1] = 
    (Polynomial(1, 1, 0, 0))                          *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lagrange[2] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lagrange[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0))                          *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lagrange[4] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
     Polynomial(1, 0, 0, 1);

  lagrange[5] = 
    (Polynomial(1, 1, 0, 0))                          *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
     Polynomial(1, 0, 0, 1);

  lagrange[6] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0)) *
     Polynomial(1, 0, 0, 1);

  lagrange[7] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0))                          *
     Polynomial(1, 0, 0, 1);

  // Lagrange Sum //
  for(int i = 0; i < 12; i++)
    lagrangeSum[i] = lagrange[edge1[i]] + lagrange[edge2[i]];

    
  // Lifting //
  lifting[0] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[1] = 
    (Polynomial(1, 1, 0, 0))                          +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[2] = 
    (Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0))                          +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[4] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
     Polynomial(1, 0, 0, 1);

  lifting[5] = 
    (Polynomial(1, 1, 0, 0))                          +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
     Polynomial(1, 0, 0, 1);

  lifting[6] = 
    (Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0)) +
     Polynomial(1, 0, 0, 1);

  lifting[7] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0))                          +
     Polynomial(1, 0, 0, 1);

  // Lifting Sub //
  for(int i = 0; i < 12; i++)
    liftingSub[i] = lifting[edge1[i]] - lifting[edge2[i]];


  // Basis (temporary --- *no* const) //
  std::vector<std::vector<Polynomial>*> basis(size);


  // Edge Based (Nedelec) // 
  int i = 0; // Function Counter
  Polynomial oneHalf(0.5, 0, 0, 0);

  for(int e = 0; e < 12; e++){
    basis[i] = 
      new std::vector<Polynomial>((liftingSub[e]).gradient());
    
    basis[i]->at(0).mul(lagrangeSum[e]);
    basis[i]->at(1).mul(lagrangeSum[e]);
    basis[i]->at(2).mul(lagrangeSum[e]);

    basis[i]->at(0).mul(oneHalf);
    basis[i]->at(1).mul(oneHalf);
    basis[i]->at(2).mul(oneHalf);

    i++;
  }


  // Edge Based (High Order) //
  for(int l = 1; l < orderPlus; l++){
    for(int e = 0; e < 12; e++){
      basis[i] = 
	new std::vector<Polynomial>((intLegendre[l].compose(liftingSub[e]) * lagrangeSum[e]).gradient());
     
      i++;
    }
  }


  // Face Based (Preliminary) //
  // Points definig Faces
  int face1[6] = {0, 3, 2, 1, 5, 4};
  int face2[6] = {1, 7, 6, 0, 6, 7};
  int face3[6] = {2, 6, 5, 4, 7, 3};
  int face4[6] = {3, 2, 1, 5, 4, 0};

  // 'Xi' Functions
  for(int f = 0; f < 6; f++)
    xi[f]  = lifting[face1[f]] - lifting[face2[f]];

  // 'Eta' Functions
  for(int f = 0; f < 6; f++)
    eta[f] = lifting[face1[f]] - lifting[face4[f]];

  // 'Lambda' Functions
  for(int f = 0; f < 6; f++)
    lambda[f] = 
      lagrange[face1[f]] +
      lagrange[face2[f]] +
      lagrange[face3[f]] +
      lagrange[face4[f]];
  
  // Gradients
  for(int f = 0; f < 6; f++){
    grXi[f]  = xi[f].gradient();
    grEta[f] = eta[f].gradient();
  }

  // Compositions
  for(int l = 0; l < orderPlus; l++){
    iLegendreXi[l]  = new Polynomial[6];
    iLegendreEta[l] = new Polynomial[6]; 
 
    legendreXi[l]  = new Polynomial[6];   
    legendreEta[l] = new Polynomial[6];

    for(int f = 0; f < 6; f++){
      iLegendreXi[l][f]  = intLegendre[l].compose(xi[f]);
      iLegendreEta[l][f] = intLegendre[l].compose(eta[f]);
      
      legendreXi[l][f]   = legendre[l].compose(xi[f]);
      legendreEta[l][f]  = legendre[l].compose(eta[f]);
    }
  }
 

  // Face Based (Type 1) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      for(int f = 0; f < 6; f++){
	basis[i] = new std::vector<Polynomial>((iLegendreXi[l1][f]   * 
						iLegendreEta[l2][f]  *
						lambda[f]).gradient());

	 i++;
      }
    }
  }


  // Face Based (Type 2) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      for(int f = 0; f < 6; f++){
	basis[i] = new std::vector<Polynomial>(3);

	Polynomial tmp1 = 
	  legendreXi[l1][f]   * 
	  iLegendreEta[l2][f];
		       
	Polynomial tmp2 =
	  iLegendreXi[l1][f] *
	  legendreEta[l2][f];

	vector<Polynomial> gr1 = grXi[f];
	gr1[0].mul(tmp1);
	gr1[1].mul(tmp1);
	gr1[2].mul(tmp1);

	vector<Polynomial> gr2 = grEta[f];
	gr2[0].mul(tmp2);
	gr2[1].mul(tmp2);
	gr2[2].mul(tmp2);	
	
	basis[i]->at(0) = (gr1[0] - gr2[0]) * lambda[f];
	basis[i]->at(1) = (gr1[1] - gr2[1]) * lambda[f];
	basis[i]->at(2) = (gr1[2] - gr2[2]) * lambda[f];

	i++;
      }
    }
  }


  // Face Based (Type 3 -- Xi) //
  for(int l = 1; l < orderPlus; l++){
    for(int f = 0; f < 6; f++){
      Polynomial tmp = iLegendreEta[l][f] * lambda[f];
      
      basis[i] = new std::vector<Polynomial>(grXi[f]);
      
      basis[i]->at(0).mul(tmp);
      basis[i]->at(1).mul(tmp);
      basis[i]->at(2).mul(tmp);
      
      i++;   
    }
  }


  // Face Based (Type 3 -- Eta) //
  for(int l = 1; l < orderPlus; l++){
    for(int f = 0; f < 6; f++){
      Polynomial tmp = iLegendreXi[l][f] * lambda[f];
      
      basis[i] = new std::vector<Polynomial>(grEta[f]);
      
      basis[i]->at(0).mul(tmp);
      basis[i]->at(1).mul(tmp);
      basis[i]->at(2).mul(tmp);
      
      i++;   
    }
  }

  
  // Cell Based (Preliminary) //
  Polynomial px   = Polynomial(2, 1, 0, 0);
  Polynomial py   = Polynomial(2, 0, 1, 0);
  Polynomial pz   = Polynomial(2, 0, 0, 1);
  Polynomial zero = Polynomial(0, 0, 0, 0);
 
  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);
  pz = pz - Polynomial(1, 0, 0, 0);

  for(int l = 0; l < orderPlus; l++){
    iLegendreX[l] = intLegendre[l].compose(px);
    iLegendreY[l] = intLegendre[l].compose(py);
    iLegendreZ[l] = intLegendre[l].compose(pz);
  }


  // Cell Based (Type 1) //
  int cellStart  = i; // Type one cell base counter
  int cellNumber = 0;

  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      for(int l3 = 1; l3 < orderPlus; l3++){
	basis[i] = new std::vector<Polynomial>((iLegendreX[l1] * 
						iLegendreY[l2] *
						iLegendreZ[l3]).gradient());

	i++;
	cellNumber++;
      }
    }
  }
  

  // Cell Based (Type 2 -- First Part) //
  for(int j = 0; j < cellNumber; j++){
    basis[i] = new std::vector<Polynomial>(3);

    int off = j + cellStart;
 
    basis[i]->at(0) = basis[off]->at(0);
    basis[i]->at(1) = basis[off]->at(1) * Polynomial(-1, 0, 0, 0); 
    basis[i]->at(2) = basis[off]->at(2);

    i++;
  }


  // Cell Based (Type 2 -- Second Part) //
  for(int j = 0; j < cellNumber; j++){
    basis[i] = new std::vector<Polynomial>(3);

    int off = j + cellStart;

    basis[i]->at(0) = basis[off]->at(0);
    basis[i]->at(1) = basis[off]->at(1) * Polynomial(-1, 0, 0, 0); 
    basis[i]->at(2) = basis[off]->at(2) * Polynomial(-1, 0, 0, 0);

    i++;
  }


  // Cell Based (Type 3 -- First Part) //
  for(int l2 = 1; l2 < orderPlus; l2++){
    for(int l3 = 1; l3 < orderPlus; l3++){ 
      basis[i] = new std::vector<Polynomial>(3);

      basis[i]->at(0) = iLegendreY[l2] * iLegendreZ[l3];
      basis[i]->at(1) = zero;
      basis[i]->at(2) = zero;
      
      i++;
    }
  }


  // Cell Based (Type 3 -- Second Part) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l3 = 1; l3 < orderPlus; l3++){      
      basis[i] = new std::vector<Polynomial>(3);
      
      basis[i]->at(0) = zero;
      basis[i]->at(1) = iLegendreX[l1] * iLegendreZ[l3];
      basis[i]->at(2) = zero;
      
      i++;
    }
  }  


  // Cell Based (Type 3 -- Thrid Part) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      basis[i] = new std::vector<Polynomial>(3);
      
      basis[i]->at(0) = zero;
      basis[i]->at(1) = zero;
      basis[i]->at(2) = iLegendreX[l1] * iLegendreY[l2];
      
      i++;
    }
  }  


  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;

  delete[] lagrange;
  delete[] lagrangeSum;

  delete[] lifting;
  delete[] liftingSub;

  delete[] xi;
  delete[] eta;
  delete[] lambda;

  delete[] grXi;
  delete[] grEta;

  for(int l = 0; l < orderPlus; l++){
    delete[] iLegendreXi[l];
    delete[] iLegendreEta[l]; 
    delete[] legendreXi[l];   
    delete[] legendreEta[l];
  }

  delete[] iLegendreXi;
  delete[] iLegendreEta; 
  delete[] legendreXi;   
  delete[] legendreEta;

  delete[] iLegendreX;
  delete[] iLegendreY;
  delete[] iLegendreZ;

  
  // Set Basis //
  this->basis = new std::vector<const std::vector<Polynomial>*>
    (basis.begin(), basis.end());
  */
}

HexEdgeBasis::~HexEdgeBasis(void){
  /*
  for(int i = 0; i < size; i++)
    delete (*basis)[i];

  delete basis;
  */
}
