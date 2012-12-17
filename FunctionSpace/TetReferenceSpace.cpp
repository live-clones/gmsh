#include <sstream>
#include "TetReferenceSpace.h"
#include "MTetrahedron.h"

using namespace std;

TetReferenceSpace::TetReferenceSpace(void){
  // Vertex Definition //
  nVertex = 4;

  // Edge Definition //
  nEdge   = 6;
  refEdge = new unsigned int*[nEdge];

  for(unsigned int i = 0; i < nEdge; i++){
    refEdge[i]    = new unsigned int[2];
    refEdge[i][0] = MTetrahedron::edges_tetra(i, 0);
    refEdge[i][1] = MTetrahedron::edges_tetra(i, 1); 
  }
  
  // Face Definition //
  nFace   = 4;
  refFace = new unsigned int*[nFace];

  for(unsigned int i = 0; i < nFace; i++){
    refFace[i]    = new unsigned int[3];
    refFace[i][0] = MTetrahedron::faces_tetra(i, 0); 
    refFace[i][1] = MTetrahedron::faces_tetra(i, 1); 
    refFace[i][2] = MTetrahedron::faces_tetra(i, 2);
  }

  // Init All //
  init();
}

TetReferenceSpace::~TetReferenceSpace(void){
  // Delete Ref Edge //
  for(unsigned int i = 0; i < nEdge; i++)
    delete[] refEdge[i];
  
  delete[] refEdge;

  // Delete Ref Face //
  for(unsigned int i = 0; i < nFace; i++)
    delete[] refFace[i];
  
  delete[] refFace;
}

string TetReferenceSpace::toLatex(void) const{
  stringstream stream;

  stream << "\\documentclass{article}" << endl << endl
	 
	 << "\\usepackage{longtable}"  << endl
	 << "\\usepackage{tikz}"       << endl
	 << "\\usetikzlibrary{arrows}" << endl << endl

	 << "\\begin{document}"                                   << endl
	 << "\\tikzstyle{vertex} = [circle, fill = black!25]"     << endl
	 << "\\tikzstyle{line}   = [draw, thick, black, -latex']" << endl << endl

	 << "\\begin{longtable}{ccc}" << endl << endl;

  for(unsigned int p = 0; p < nPerm; p++){
    stream << "\\begin{tikzpicture}" << endl

	   << "\\node[vertex] (n0) at(0, 0) {$0$};" << endl
	   << "\\node[vertex] (n1) at(3, 0) {$1$};" << endl
	   << "\\node[vertex] (n2) at(0, 3) {$2$};" << endl 
	   << "\\node[vertex] (n3) at(1, 1) {$3$};" << endl << endl;

    for(unsigned int i = 0; i < 6; i++)
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

/*
#include <iostream>
int main(void){
  TetReferenceSpace p;

  cout << p.toLatex() << endl;
  
  return 0;
}
*/
