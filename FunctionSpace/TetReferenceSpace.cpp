#include <sstream>
#include "TetReferenceSpace.h"
#include "MTetrahedron.h"

using namespace std;

TetReferenceSpace::TetReferenceSpace(void){
  // Vertex Definition //
  nVertex = 4;

  // Edge Definition //
  const size_t nEdge = 6;
  refEdgeNodeIdx.resize(nEdge);

  for(size_t i = 0; i < nEdge; i++){
    refEdgeNodeIdx[i].resize(2); // Two Nodes per Edge
    refEdgeNodeIdx[i][0] = MTetrahedron::edges_tetra(i, 0);
    refEdgeNodeIdx[i][1] = MTetrahedron::edges_tetra(i, 1);
  }

  // Face Definition //
  size_t nFace = 4;
  refFaceNodeIdx.resize(nFace);

  for(size_t i = 0; i < nFace; i++){
    refFaceNodeIdx[i].resize(3);  // Three Nodes per Face
    refFaceNodeIdx[i][0] = MTetrahedron::faces_tetra(i, 0);
    refFaceNodeIdx[i][1] = MTetrahedron::faces_tetra(i, 1);
    refFaceNodeIdx[i][2] = MTetrahedron::faces_tetra(i, 2);
  }

  parallelFaceId.resize(nFace);

  for(size_t i = 0; i < nFace; i++)
    parallelFaceId[i] = -1; // Face i has no parallel face

  // Init All //
  init();
}

TetReferenceSpace::~TetReferenceSpace(void){
}

string TetReferenceSpace::toLatex(void) const{
  const size_t nRefSpace = refSpaceNodeId.size();
  stringstream stream;

  stream << "\\documentclass{article}" << endl << endl

         << "\\usepackage{longtable}"  << endl
         << "\\usepackage{tikz}"       << endl
         << "\\usetikzlibrary{arrows}" << endl << endl

         << "\\begin{document}"                                   << endl
         << "\\tikzstyle{vertex} = [circle, fill = black!25]"     << endl
         << "\\tikzstyle{line}   = [draw, thick, black, -latex']" << endl
         << endl

         << "\\begin{longtable}{ccc}" << endl << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "\\begin{tikzpicture}" << endl

           << "\\node[vertex] (n0) at(0, 0) {$" << refSpaceNodeId[s][0] << "$};"
           << endl
           << "\\node[vertex] (n1) at(3, 0) {$" << refSpaceNodeId[s][1] << "$};"
           << endl
           << "\\node[vertex] (n2) at(0, 3) {$" << refSpaceNodeId[s][2] << "$};"
           << endl
           << "\\node[vertex] (n3) at(1, 1) {$" << refSpaceNodeId[s][3] << "$};"
           << endl
           << endl;

    for(size_t e = 0; e < 6; e++)
      stream << "\\path[line]"
             << " (n" << orderedEdgeNodeIdx[s][e][0] << ")"
             << " -- "
             << " (n" << orderedEdgeNodeIdx[s][e][1] << ");"
             << endl;

    if((s + 1) % 3)
      stream << "\\end{tikzpicture} & "        << endl << endl;

    else
      stream << "\\end{tikzpicture} \\\\ \\\\" << endl << endl;
  }

  stream << "\\end{longtable}" << endl
         << "\\end{document}"  << endl;

  return stream.str();
}
