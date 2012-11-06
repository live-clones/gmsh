#include "polynomialBasis.h"
#include "Exception.h"
#include "TriLagrangeBasis.h"

using namespace std;

TriLagrangeBasis::TriLagrangeBasis(int order){
  // Call polynomialBasis procedure //
  int tag;

  switch(order){
  case 1:
    tag = MSH_TRI_3;
    break;

  case 2:
    tag = MSH_TRI_6;
    break;

  case 3:
    tag = MSH_TRI_10;
    break;

  case 4:
    tag = MSH_TRI_15;
    break;

  case 5:
    tag = MSH_TRI_21;
    break;

  case 6:
    tag = MSH_TRI_28;
    break;

  case 7:
    tag = MSH_TRI_36;
    break;

  case 8:
    tag = MSH_TRI_45;
    break;

  case 9:
    tag = MSH_TRI_55;
    break;

  case 10:
    tag = MSH_TRI_66;
    break;
 
  default:
    throw Exception
      ("Can't instanciate an order %d Lagrangian Basis for a Triangle",
       order);
    
    break;
  }

  l     = polynomialBases::find(tag);
  point = new fullMatrix<double>(triPoint(order));
  
  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2; 

  nVertex = l->coefficients.size1();
  nEdge   = 0;
  nFace   = 0;
  nCell   = 0;

  nEdgeClosure = 0;
  nFaceClosure = 0;

  size = nVertex;
 

  // Basis (pure nodal) //
  node = new vector<Polynomial*>(nVertex);
  edge = new vector<vector<Polynomial*>*>(0);
  face = new vector<vector<Polynomial*>*>(0);
  cell = new vector<Polynomial*>(0);


  // Instanciate Polynomials //
  const int nMonomial = l->monomials.size1();

  for(int i = 0; i < nVertex; i++){
    Polynomial p = Polynomial(0, 0, 0, 0);
    
    for(int j = 0; j < nMonomial; j++)
      p = p + Polynomial(l->coefficients(i, j), // Coef 
			 l->monomials(j, 0),    // powerX
			 l->monomials(j, 1),    // powerY
			 0);                    // powerZ
    
    (*node)[i] = new Polynomial(p);
  }
}

TriLagrangeBasis::~TriLagrangeBasis(void){
  // Delete gmsh polynomial Basis //
  // --> no method to do so :-(
  //  --> erased ??

  // Vertex Based //
  for(int i = 0; i < nVertex; i++)
    delete (*node)[i];
  
  delete node;

  // Edge Based //
  for(int c = 0; c < nEdgeClosure; c++){
    for(int i = 0; i < nEdge; i++)
      delete (*(*edge)[c])[i];
    
    delete (*edge)[c];
  }
  
  delete edge;

  // Face Based //
  for(int c = 0; c < nFaceClosure; c++){
    for(int i = 0; i < nFace; i++)
      delete (*(*face)[c])[i];
    
    delete (*face)[c];
  }

  delete face;

  // Cell Based //
  for(int i = 0; i < nCell; i++)
    delete (*cell)[i];

  delete cell;

  // Delete Lagrange Points //
  delete point;
}

fullMatrix<double> TriLagrangeBasis::
triPoint(unsigned int order){
  unsigned int       nbPoints = (order + 1) * (order + 2) / 2;
  fullMatrix<double> point(nbPoints, 3);

  point(0, 0) = 0;
  point(0, 1) = 0;
  point(0, 2) = 0;

  if(order > 0){
    double dd = 1. / order;
    
    point(1, 0) = 1;
    point(1, 1) = 0;
    point(1, 2) = 0;
    
    point(2, 0) = 0;
    point(2, 1) = 1;
    point(2, 2) = 0;
    
    unsigned int index = 3;
    
    if(order > 1){
      double ksi = 0;
      double eta = 0;

      for(unsigned int i = 0; i < order - 1; i++, index++){
        ksi += dd;

        point(index, 0) = ksi;
        point(index, 1) = eta;
        point(index, 2) = 0;
      }

      ksi = 1.;

      for(unsigned int i = 0; i < order - 1; i++, index++){
        ksi -= dd;
        eta += dd;

        point(index, 0) = ksi;
        point(index, 1) = eta;
        point(index, 2) = 0;
      }

      eta = 1.;
      ksi = 0.;

      for(unsigned int i = 0; i < order - 1; i++, index++){
        eta -= dd;

        point(index, 0) = ksi;
        point(index, 1) = eta;
        point(index, 2) = 0;
      }

      if(order > 2){
        fullMatrix<double> inner = triPoint(order - 3);
        
	inner.scale(1. - 3. * dd);
        inner.add(dd);
        point.copy(inner, 0, nbPoints - index, 0, 2, index, 0);
      }
    }
  }

  return point;
}
