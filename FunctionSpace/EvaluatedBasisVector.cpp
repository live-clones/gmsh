#include "Polynomial.h"
#include "EvaluatedBasisVector.h"

using namespace std;

EvaluatedBasisVector::
EvaluatedBasisVector(const BasisVector& basis, 
		     const fullMatrix<double>& point){
  // Data //
  scalar = false;
  
  nVertex = basis.getNVertexBased();
  nEdge   = basis.getNEdgeBased();
  nFace   = basis.getNFaceBased();
  nCell   = basis.getNCellBased();

  nEdgeClosure = basis.getNEdgeClosure();
  nFaceClosure = basis.getNFaceClosure();

  nPoint = point.size1();


  // Alloc //
  // Node
  node = new vector<vector<fullVector<double> >*>(nVertex);

  for(unsigned int j = 0; j < nVertex; j++)
    (*node)[j] = new vector<fullVector<double> >(nPoint);

  // Edge
  edge = new vector<vector<vector<fullVector<double> >*>*>(nEdgeClosure);

  for(unsigned int i = 0; i < nEdgeClosure; i++){
    (*edge)[i] = new vector<vector<fullVector<double> >*>(nEdge);
    
    for(unsigned int j = 0; j < nEdge; j++)
      (*(*edge)[i])[j] = new vector<fullVector<double> >(nPoint);
  }

  // Face
  face = new vector<vector<vector<fullVector<double> >*>*>(nFaceClosure);

  for(unsigned int i = 0; i < nFaceClosure; i++){
    (*face)[i] = new vector<vector<fullVector<double> >*>(nFace);

    for(unsigned int j = 0; j < nFace; j++)
      (*(*face)[i])[j] = new vector<fullVector<double> >(nPoint);
  }  

  // Cell
  cell = new vector<vector<fullVector<double> >*>(nCell);

  for(unsigned int j = 0; j < nCell; j++)
    (*cell)[j] = new vector<fullVector<double> >(nPoint);


  // Evaluate //
  // Node
  for(unsigned int j = 0; j < nVertex; j++)
    for(unsigned int k = 0; k < nPoint; k++)
      (*(*node)[j])[k] = 
	Polynomial::at(basis.getNodeFunction(j),
		       point(k, 0),
		       point(k, 1),
		       point(k, 2));

  // Edge
  for(unsigned int i = 0; i < nEdgeClosure; i++)
    for(unsigned int j = 0; j < nEdge; j++)
      for(unsigned int k = 0; k < nPoint; k++)
	(*(*(*edge)[i])[j])[k] = 
	  Polynomial::at(basis.getEdgeFunction(i, j),
			 point(k, 0),
			 point(k, 1),
			 point(k, 2));
  
  // Face
  for(unsigned int i = 0; i < nFaceClosure; i++)
    for(unsigned int j = 0; j < nFace; j++)
      for(unsigned int k = 0; k < nPoint; k++)
	(*(*(*face)[i])[j])[k] = 
	  Polynomial::at(basis.getFaceFunction(i, j),
			 point(k, 0),
			 point(k, 1),
			 point(k, 2));

  // Cell
  for(unsigned int j = 0; j < nCell; j++)
    for(unsigned int k = 0; k < nPoint; k++)
      (*(*cell)[j])[k] = 
	Polynomial::at(basis.getCellFunction(j),
		       point(k, 0),
		       point(k, 1),
		       point(k, 2));
}

EvaluatedBasisVector::~EvaluatedBasisVector(void){
  // Node //
  for(unsigned int j = 0; j < nVertex; j++)
    delete (*node)[j];

  delete node;

  // Edge //
  for(unsigned int i = 0; i < nEdgeClosure; i++){
    for(unsigned int j = 0; j < nEdge; j++)
      delete (*(*edge)[i])[j];

    delete (*edge)[i];
  }

  delete edge;

  // Face //
  for(unsigned int i = 0; i < nFaceClosure; i++){
    for(unsigned int j = 0; j < nFace; j++)
      delete (*(*face)[i])[j];

    delete (*face)[i];
  }  

  delete face;

  // Cell //
  for(unsigned int j = 0; j < nCell; j++)
    delete (*cell)[j];

  delete cell;
}
