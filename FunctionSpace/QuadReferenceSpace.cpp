#include <sstream>
#include "QuadReferenceSpace.h"
#include "MQuadrangle.h"

using namespace std;

QuadReferenceSpace::QuadReferenceSpace(void){
  // Vertex Definition //
  nVertex = 4;

  // Edge Definition //
  nEdge   = 4;
  refEdge = new size_t*[nEdge];

  for(size_t i = 0; i < nEdge; i++){
    refEdge[i]    = new size_t[2];
    refEdge[i][0] = MQuadrangle::edges_quad(i, 0);
    refEdge[i][1] = MQuadrangle::edges_quad(i, 1);
  }

  // Face Definition //
  // Number of face
  nFace = 1;

  // Number of node per face
  nNodeInFace    = new size_t[nFace];
  nNodeInFace[0] = 4;

  // Reference Face
  refFace    = new size_t*[nFace];
  refFace[0] = new size_t[4];

  refFace[0][0] = 0;
  refFace[0][1] = 1;
  refFace[0][2] = 2;
  refFace[0][3] = 3;

  // Init All //
  init();
}

QuadReferenceSpace::~QuadReferenceSpace(void){
  // Delete Ref Edge //
  for(size_t i = 0; i < nEdge; i++)
    delete[] refEdge[i];

  delete[] refEdge;

  // Delete Ref Face //
  for(size_t i = 0; i < nFace; i++)
    delete[] refFace[i];

  delete[] refFace;
  delete[] nNodeInFace;
}

string QuadReferenceSpace::toLatex(void) const{
  const size_t   nPerm = pTree->getNPermutation();
  stringstream   stream;
  vector<size_t> perm(nVertex);

  stream << "\\documentclass{article}" << endl << endl

         << "\\usepackage{longtable}"  << endl
         << "\\usepackage{tikz}"       << endl
         << "\\usetikzlibrary{arrows}" << endl << endl

         << "\\begin{document}"                                   << endl
         << "\\tikzstyle{vertex} = [circle, fill = black!25]"     << endl
         << "\\tikzstyle{line}   = [draw, thick, black, -latex']" << endl << endl

         << "\\begin{longtable}{ccc}" << endl << endl;

  for(size_t p = 0; p < nPerm; p++){
    pTree->fillWithPermutation(p, perm);

    stream << "\\begin{tikzpicture}" << endl

           << "\\node[vertex] (n0) at(0, 0) {$" << perm[0] << "$};" << endl
           << "\\node[vertex] (n1) at(3, 0) {$" << perm[1] << "$};" << endl
           << "\\node[vertex] (n2) at(3, 3) {$" << perm[2] << "$};" << endl
           << "\\node[vertex] (n3) at(0, 3) {$" << perm[3] << "$};" << endl
           << endl;

    for(size_t i = 0; i < 4; i++)
      stream << "\\path[line]"
             << " (n" << (*(*(*edge)[p])[i])[0] << ")"
             << " -- "
             << " (n" << (*(*(*edge)[p])[i])[1] << ");"
             << endl;

    if((p + 1) % 3)
      stream << "\\end{tikzpicture} & "        << endl << endl;

    else
      stream << "\\end{tikzpicture} \\\\ \\\\" << endl << endl;
  }

  stream << "\\end{longtable}" << endl
         << "\\end{document}"  << endl;

  return stream.str();
}
