#include <sstream>

#include "HexReferenceSpace.h"
#include "MHexahedron.h"

using namespace std;

HexReferenceSpace::HexReferenceSpace(void){
  // Look if a serialized HexReferenceSpace is present in root //
  // If it does, load it                                       //
  // If not, create it and serialize it for an other time      //

  try{
    init(string("hex.refSpace"));
  }

  catch(std::exception& exception){
    initHex();
    serialize("hex.refSpace");
  }
}

void HexReferenceSpace::initHex(void){
  // Vertex Definition //
  nVertex = 8;

  // Edge Definition //
  const size_t nEdge = 12;
  refEdgeNodeIdx.resize(nEdge);

  for(size_t i = 0; i < nEdge; i++){
    refEdgeNodeIdx[i].resize(2); // Two Nodes per Edge
    refEdgeNodeIdx[i][0] = MHexahedron::edges_hexa(i, 0);
    refEdgeNodeIdx[i][1] = MHexahedron::edges_hexa(i, 1);
  }

  // Face Definition //
  size_t nFace = 6;
  refFaceNodeIdx.resize(nFace);

  for(size_t i = 0; i < nFace; i++){
    refFaceNodeIdx[i].resize(4);  // Four Nodes per Face
    refFaceNodeIdx[i][0] = MHexahedron::faces_hexa(i, 0);
    refFaceNodeIdx[i][1] = MHexahedron::faces_hexa(i, 1);
    refFaceNodeIdx[i][2] = MHexahedron::faces_hexa(i, 2);
    refFaceNodeIdx[i][3] = MHexahedron::faces_hexa(i, 3);
  }

  // Init All //
  init();
}

HexReferenceSpace::~HexReferenceSpace(void){
}

string HexReferenceSpace::toLatex(void) const{
  stringstream stream;

    stream << "\\documentclass{article}" << endl << endl
         << "\\begin{document}"        << endl

         << "\texttt{toLatex} not implemented" << endl

         << "\\end{document}"          << endl;

  return stream.str();
}
