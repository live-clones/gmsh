#include <sstream>

#include "TriReferenceSpace.h"
#include "MTriangle.h"

using namespace std;

TriReferenceSpace::TriReferenceSpace(void){
  // Vertex Definition //
  nVertex = 3;

  // Edge Definition //
  const size_t nEdge = 3;
  refEdgeNodeIdx.resize(nEdge);

  for(size_t i = 0; i < nEdge; i++){
    refEdgeNodeIdx[i].resize(2); // Two Nodes per Edge
    refEdgeNodeIdx[i][0] = MTriangle::edges_tri(i, 0);
    refEdgeNodeIdx[i][1] = MTriangle::edges_tri(i, 1);
  }

  // Face Definition //
  refFaceNodeIdx.resize(1);    // One Face per Triangle
  refFaceNodeIdx[0].resize(3); // Three Nodes per Face

  refFaceNodeIdx[0][0] = 0;
  refFaceNodeIdx[0][1] = 1;
  refFaceNodeIdx[0][2] = 2;

  // Init All //
  init();
}

TriReferenceSpace::~TriReferenceSpace(void){
}

string TriReferenceSpace::toLatex(void) const{
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
           << endl;

    for(size_t e = 0; e < 3; e++)
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
