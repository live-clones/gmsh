#include <sstream>
#include "QuadReferenceSpace.h"
#include "MQuadrangle.h"

using namespace std;

QuadReferenceSpace::QuadReferenceSpace(void){
  // Vertex Definition //
  nVertex = 4;

  // Edge Definition //
  const size_t nEdge = 4;
  refEdgeNodeIdx.resize(nEdge);

  for(size_t i = 0; i < nEdge; i++){
    refEdgeNodeIdx[i].resize(2); // Two Nodes per Edge
    refEdgeNodeIdx[i][0] = MQuadrangle::edges_quad(i, 0);
    refEdgeNodeIdx[i][1] = MQuadrangle::edges_quad(i, 1);
  }

  // Face Definition //
  refFaceNodeIdx.resize(1);    // One Face per Triangle
  refFaceNodeIdx[0].resize(4); // Four Nodes per Face

  refFaceNodeIdx[0][0] = 0;
  refFaceNodeIdx[0][1] = 1;
  refFaceNodeIdx[0][2] = 2;
  refFaceNodeIdx[0][3] = 3;

  // Init All //
  init();
}

QuadReferenceSpace::~QuadReferenceSpace(void){
}

string QuadReferenceSpace::toLatex(void) const{
  const size_t nRefSpace = refSpaceNodeId.size();
  stringstream stream;

  // stream << pTree->toLatex() << endl;
  // return stream.str();

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
           << "\\node[vertex] (n2) at(3, 3) {$" << refSpaceNodeId[s][2] << "$};"
           << endl
           << "\\node[vertex] (n3) at(0, 3) {$" << refSpaceNodeId[s][3] << "$};"
           << endl
           << endl;

    for(size_t e = 0; e < 4; e++)
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
