#include "TriLagrangeReferenceSpace.h"
#include "MTriangle.h"

using namespace std;

TriLagrangeReferenceSpace::TriLagrangeReferenceSpace(unsigned int order){
  /*
  // Vertex Definition //
  nVertex = 3;

  // Edge Definition //
  nEdge   = 3;
  refEdge = new size_t*[nEdge];

  for(size_t i = 0; i < nEdge; i++){
    refEdge[i]    = new size_t[2];
    refEdge[i][0] = MTriangle::edges_tri(i, 0);
    refEdge[i][1] = MTriangle::edges_tri(i, 1);
  }

  // Face Definition //
  nFace      = 1;
  refFace    = new size_t*[nFace];
  refFace[0] = new size_t[3];

  refFace[0][0] = 0;
  refFace[0][1] = 1;
  refFace[0][2] = 2;

  // Init ReferenceSpace //
  init();

  // Get Lagrange Node //
  nNodePerEdge = 3 * (order - 1) / nEdge;
  nNodePerFace =     (order - 1) * (order - 2) / 2 / nFace;
  nNodePerCell = 0;

  nNode =
    nVertex +
    nNodePerEdge * nEdge +
    nNodePerFace * nFace +
    nNodePerCell;

  getLagrangeNode();
  */
}

TriLagrangeReferenceSpace::~TriLagrangeReferenceSpace(void){
  /*
  // Delete Ref Edge //
  for(size_t i = 0; i < nEdge; i++)
    delete[] refEdge[i];

  delete[] refEdge;

  // Delete Ref Face //
  for(size_t i = 0; i < nFace; i++)
    delete[] refFace[i];

  delete[] refFace;
  */
}
