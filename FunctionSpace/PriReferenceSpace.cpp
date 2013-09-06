#include <sstream>
#include "PriReferenceSpace.h"
#include "MPrism.h"

using namespace std;

PriReferenceSpace::PriReferenceSpace(void){
  // Vertex Definition //
  nVertex = 6;

  // Edge Definition //
  const size_t nEdge = 9;
  refEdgeNodeIdx.resize(nEdge);

  for(size_t i = 0; i < nEdge; i++){
    refEdgeNodeIdx[i].resize(2); // Two Nodes per Edge
    refEdgeNodeIdx[i][0] = MPrism::edges_prism(i, 0);
    refEdgeNodeIdx[i][1] = MPrism::edges_prism(i, 1);
  }

  // Face Definition //
  size_t nFace = 5;
  refFaceNodeIdx.resize(nFace);

  for(size_t i = 0; i < nFace; i++){
    int fourthNodeIdx = MPrism::faces_prism(i, 3);

    if(fourthNodeIdx != -1)
      refFaceNodeIdx[i].resize(4);  // Four Nodes in this face
    else
      refFaceNodeIdx[i].resize(3);  // Three Nodes in this face

    refFaceNodeIdx[i][0] = MPrism::faces_prism(i, 0);
    refFaceNodeIdx[i][1] = MPrism::faces_prism(i, 1);
    refFaceNodeIdx[i][2] = MPrism::faces_prism(i, 2);

    if(fourthNodeIdx != -1)
      refFaceNodeIdx[i][3] = fourthNodeIdx;
  }

  // Init All //
  init();
}

PriReferenceSpace::~PriReferenceSpace(void){
}

string PriReferenceSpace::toLatex(void) const{
  stringstream stream;

  stream << "\\documentclass{article}" << endl << endl
         << "\\begin{document}"        << endl

         << "\texttt{toLatex} not implemented" << endl

         << "\\end{document}"          << endl;

  return stream.str();
}
