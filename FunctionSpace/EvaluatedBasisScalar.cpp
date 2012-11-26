#include "EvaluatedBasisScalar.h"

using namespace std;

EvaluatedBasisScalar::
EvaluatedBasisScalar(const BasisScalar& basis, 
		     const fullMatrix<double>& point){
  // Data //
  scalar = true;
  
  nVertex = basis.getNVertexBased();
  nEdge   = basis.getNEdgeBased();
  nFace   = basis.getNFaceBased();
  nCell   = basis.getNCellBased();

  nEdgeClosure = basis.getNEdgeClosure();
  nFaceClosure = basis.getNFaceClosure();

  nPoint = point.size1();


  // Alloc //
  // Node
  node = new vector<vector<double>*>(nVertex);

  for(unsigned int j = 0; j < nVertex; j++)
    (*node)[j] = new vector<double>(nPoint);

  // Edge
  edge = new vector<vector<vector<double>*>*>(nEdgeClosure);

  for(unsigned int i = 0; i < nEdgeClosure; i++){
    (*edge)[i] = new vector<vector<double>*>(nEdge);
    
    for(unsigned int j = 0; j < nEdge; j++)
      (*(*edge)[i])[j] = new vector<double>(nPoint);
  }

  // Face
  face = new vector<vector<vector<double>*>*>(nFaceClosure);

  for(unsigned int i = 0; i < nFaceClosure; i++){
    (*face)[i] = new vector<vector<double>*>(nFace);

    for(unsigned int j = 0; j < nFace; j++)
      (*(*face)[i])[j] = new vector<double>(nPoint);
  }  

  // Cell
  cell = new vector<vector<double>*>(nCell);

  for(unsigned int j = 0; j < nCell; j++)
    (*cell)[j] = new vector<double>(nPoint);


  // Evaluate //
  // Node
  for(unsigned int j = 0; j < nVertex; j++)
    for(unsigned int k = 0; k < nPoint; k++)
      (*(*node)[j])[k] = 
	basis.getNodeFunction(j).at(point(k, 0),
				    point(k, 1),
				    point(k, 2));

  // Edge
  for(unsigned int i = 0; i < nEdgeClosure; i++)
    for(unsigned int j = 0; j < nEdge; j++)
      for(unsigned int k = 0; k < nPoint; k++)
	(*(*(*edge)[i])[j])[k] = 
	  basis.getEdgeFunction(i, j).at(point(k, 0),
					 point(k, 1),
					 point(k, 2));
  
  // Face
  for(unsigned int i = 0; i < nFaceClosure; i++)
    for(unsigned int j = 0; j < nFace; j++)
      for(unsigned int k = 0; k < nPoint; k++)
	(*(*(*face)[i])[j])[k] = 
	  basis.getFaceFunction(i, j).at(point(k, 0),
					 point(k, 1),
					 point(k, 2));

  // Cell
  for(unsigned int j = 0; j < nCell; j++)
    for(unsigned int k = 0; k < nPoint; k++)
      (*(*cell)[j])[k] = 
	basis.getCellFunction(j).at(point(k, 0),
				    point(k, 1),
				    point(k, 2));
}

EvaluatedBasisScalar::~EvaluatedBasisScalar(void){
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
