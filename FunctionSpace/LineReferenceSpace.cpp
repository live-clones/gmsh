#include <sstream>
#include "LineReferenceSpace.h"

using namespace std;

LineReferenceSpace::LineReferenceSpace(void){
  /*
  // Vertex Definition //
  nVertex = 2;

  // Edge Definition //
  nEdge   = 1;
  refEdge    = new size_t*[nEdge];
  refEdge[0] = new size_t[2];

  refEdge[0][0] = 0;
  refEdge[0][1] = 1;

  // Face Definition //
  nFace   = 0;
  refFace = NULL;

  // Init All //
  init();
  */
}

LineReferenceSpace::~LineReferenceSpace(void){
  /*
  // Delete Ref Edge //
  for(size_t i = 0; i < nEdge; i++)
    delete[] refEdge[i];

  delete[] refEdge;
  */
}

string LineReferenceSpace::toLatex(void) const{
  //const size_t nPerm = pTree->getNPermutation();
  stringstream stream;
  /*
  stream << "\\documentclass{article}" << endl << endl

         << "\\usepackage{longtable}"  << endl
         << "\\usepackage{tikz}"       << endl
         << "\\usetikzlibrary{arrows}" << endl << endl

         << "\\begin{document}"                                   << endl
         << "\\tikzstyle{vertex} = [circle, fill = black!25]"     << endl
         << "\\tikzstyle{line}   = [draw, thick, black, -latex']" << endl << endl

         << "\\begin{longtable}{c}" << endl << endl;

  for(size_t p = 0; p < nPerm; p++){
    stream << "\\begin{tikzpicture}" << endl

           << "\\node[vertex] (n0) at(0, 0) {$0$};" << endl
           << "\\node[vertex] (n1) at(3, 0) {$1$};" << endl << endl

           << "\\path[line]"
           << " (n" << (*(*(*edge)[p])[0])[0] << ")"
           << " -- "
           << " (n" << (*(*(*edge)[p])[0])[1] << ");"
           << endl

           << "\\end{tikzpicture} \\\\ \\\\" << endl << endl;
  }

  stream << "\\end{longtable}" << endl
         << "\\end{document}"  << endl;
  */
  return stream.str();
}
