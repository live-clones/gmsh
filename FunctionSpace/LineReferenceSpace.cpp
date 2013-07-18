#include <sstream>
#include "LineReferenceSpace.h"

using namespace std;

LineReferenceSpace::LineReferenceSpace(void){
  // Vertex Definition //
  nVertex = 2;

  // Edge Definition //
  refEdgeNodeIdx.resize(1);    // One Edge per Line
  refEdgeNodeIdx[0].resize(2); // Two Nodes per Edge

  refEdgeNodeIdx[0][0] = 0;
  refEdgeNodeIdx[0][1] = 1;

  // Face Definition //
  refFaceNodeIdx.clear(); // No Face in Line

  init();
}

LineReferenceSpace::~LineReferenceSpace(void){
}

string LineReferenceSpace::toLatex(void) const{
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

         << "\\begin{longtable}{c}" << endl << endl;

  for(size_t s = 0; s < nRefSpace; s++){
    stream << "\\begin{tikzpicture}" << endl

           << "\\node[vertex] (n0) at(0, 0) {$" << refSpaceNodeId[s][0] << "$};"
           << endl
           << "\\node[vertex] (n1) at(3, 0) {$" << refSpaceNodeId[s][1] << "$};"
           << endl
           << endl

           << "\\path[line]"
           << " (n" << orderedEdgeNodeIdx[s][0][0] << ")"
           << " -- "
           << " (n" << orderedEdgeNodeIdx[s][0][1] << ");"
           << endl

           << "\\end{tikzpicture} \\\\ \\\\" << endl << endl;
  }

  stream << "\\end{longtable}" << endl
         << "\\end{document}"  << endl;

  return stream.str();
}
