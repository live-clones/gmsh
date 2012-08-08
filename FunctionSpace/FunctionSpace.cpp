#include "FunctionSpace.h"
#include "BasisGenerator.h"

using namespace std;

FunctionSpace::FunctionSpace(const GroupOfElement& goe, int basisType, int order){
  // Save GroupOfElement & Mesh //
  this->goe  = &goe;  
  this->mesh = &(goe.getMesh());

  // Get Geo Data (WARNING HOMOGENE MESH REQUIRED)//
  MElement& element = goe.get(0); 
  int elementType   = element.getType();
  int nVertex       = element.getNumVertices();
  int nEdge         = element.getNumEdges();
  int nFace         = element.getNumFaces();
 
  // Init Struct //
  type  = basisType;
  basis = BasisGenerator::generate(elementType, 
				   basisType, 
				   order);

  fPerVertex = basis->getNVertexBased() / nVertex;
  // NB: fPreVertex = 0 *or* 1

  if(nEdge)
    fPerEdge = basis->getNEdgeBased() / nEdge;
  else
    fPerEdge = 0;

  if(nFace)
    fPerFace = basis->getNFaceBased() / nFace;
  else
    fPerFace = 0;  
  
  fPerCell = basis->getNCellBased(); // We always got 1 cell 
}

FunctionSpace::~FunctionSpace(void){
  delete basis;
}

vector<Dof> FunctionSpace::getKeys(const MElement& elem) const{ 
  // Const_Cast //
  MElement& element = const_cast<MElement&>(elem);

  // Get Element Data //
  const int nVertex = element.getNumVertices();
  const int nEdge   = element.getNumEdges();
  const int nFace   = element.getNumFaces(); 

  vector<MVertex*> vertex(nVertex);
  vector<MEdge> edge(nEdge);
  vector<MFace> face(nFace);

  for(int i = 0; i < nVertex; i++)
    vertex[i] = element.getVertex(i);

  for(int i = 0; i < nEdge; i++)    
    edge[i] = element.getEdge(i);
  
  for(int i = 0; i < nFace; i++)
    face[i] = element.getFace(i);
  
  // Get FunctionSpace Data for this Element //
  const int nFVertex = getNFunctionPerVertex(element);
  const int nFEdge   = getNFunctionPerEdge(element);
  const int nFFace   = getNFunctionPerFace(element);
  const int nFCell   = getNFunctionPerCell(element);

  // Create Dof //
  const int nDofVertex = nFVertex * nVertex; 
  const int nDofEdge   = nFEdge   * nEdge;
  const int nDofFace   = nFFace   * nFace;
  const int nDofCell   = nFCell;

  int nDof = 
    nDofVertex + nDofEdge + nDofFace + nDofCell;

  vector<Dof> myDof(nDof);

  int it = 0;

  // Add Vertex Based Dof //
  for(int i = 0; i < nVertex; i++){
    for(int j = 0; j < nFVertex; j++){
      myDof[it].setDof(mesh->getGlobalId(*vertex[i]), j);
      it++;
    }
  }
  
  return myDof;
}

/*
#include "Polynomial.h"
#include "BasisScalar.h"
#include "fullMatrix.h"
#include "Mapper.h"
#include "Exception.h"
void FunctionSpace::
interpolateAtNodes(const MElement& elem, 
		   const vector<double>& coef,
		   std::vector<double>& nodeValue) const{
  // Check
  unsigned int wS = coef.size();
  unsigned int bS = basis->getSize();

  if(wS < bS)
    throw Exception
      ("Not enough coefs for interpolation:\nBasis: %d -- coefs: %d",
       bS, wS);

  if(wS > bS)
    throw Exception
      ("Too much coefs for interpolation:\nBasis: %d -- coefs: %d",
       bS, wS);

  // Get Nodes
  MElement& element = const_cast<MElement&>(elem);

  vector<MVertex*> node;
  element.getVertices(node);
  unsigned int N = node.size();

  // Get Functions
  const vector<Polynomial>& fun = 
    static_cast<const BasisScalar*>(basis)->getBasis();

  // Init some stuff
  fullMatrix<double> invJac(3, 3);
  fullVector<double> xyz(3);
  fullVector<double> origin(3);
  
  origin(0) = node[0]->x();
  origin(1) = node[0]->y();
  origin(2) = node[0]->z();

  // Interpolate
  for(unsigned int n = 0; n < N; n++){
    // Map from physical to reference space 
    xyz(0) = node[n]->x();
    xyz(1) = node[n]->y();
    xyz(2) = node[n]->z();

    element.getJacobian(xyz(0), xyz(1), xyz(2), invJac);
    invJac.invertInPlace();
    
    const fullVector<double> uvw = 
      Mapper::invMap(xyz, origin, invJac);

    printf("(%lf\t%lf\t%lf)\n", uvw(0), uvw(1), uvw(2));

    // Interpolate
    const int id = node[n]->getNum() - 1;

    for(unsigned int i = 0; i < bS; i++)
      nodeValue[id] += fun[i].at(uvw(0), uvw(1), uvw(2)) * coef[i];
  }
}
*/
