#include <sstream>
#include "PyrReferenceSpace.h"
#include "MPyramid.h"

using namespace std;

PyrReferenceSpace::PyrReferenceSpace(void){
  // Vertex Definition //
  nVertex = 5;

  // Edge Definition //
  const size_t nEdge = 8;
  refEdgeNodeIdx.resize(nEdge);

  for(size_t i = 0; i < nEdge; i++){
    refEdgeNodeIdx[i].resize(2); // Two Nodes per Edge
    refEdgeNodeIdx[i][0] = MPyramid::edges_pyramid(i, 0);
    refEdgeNodeIdx[i][1] = MPyramid::edges_pyramid(i, 1);
  }

  // Face Definition //
  size_t nFace = 5;
  refFaceNodeIdx.resize(nFace);

  for(size_t i = 0; i < nFace; i++){
    int fourthNodeIdx = MPyramid::faces_pyramid(i, 3);

    if(fourthNodeIdx != -1)
      refFaceNodeIdx[i].resize(4);  // Four Nodes in this face
    else
      refFaceNodeIdx[i].resize(3);  // Three Nodes in this face

    refFaceNodeIdx[i][0] = MPyramid::faces_pyramid(i, 0);
    refFaceNodeIdx[i][1] = MPyramid::faces_pyramid(i, 1);
    refFaceNodeIdx[i][2] = MPyramid::faces_pyramid(i, 2);

    if(fourthNodeIdx != -1)
      refFaceNodeIdx[i][3] = fourthNodeIdx;
  }

  // Init All //
  init();
}

PyrReferenceSpace::~PyrReferenceSpace(void){
}

string PyrReferenceSpace::toLatex(void) const{
  stringstream stream;

  stream << "\\documentclass{article}" << endl << endl
         << "\\begin{document}"        << endl

         << "\texttt{toLatex} not implemented" << endl

         << "\\end{document}"          << endl;

  return stream.str();
}
