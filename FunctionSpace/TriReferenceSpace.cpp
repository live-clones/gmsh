#include <sstream>
#include "TriReferenceSpace.h"
#include "MTriangle.h"

using namespace std;

TriReferenceSpace::TriReferenceSpace(void){
  // Vertex Definition //
  nVertex = 3;

  // Edge Definition //
  nEdge   = 3;
  refEdge = new unsigned int*[nEdge];

  for(unsigned int i = 0; i < nEdge; i++){
    refEdge[i]    = new unsigned int[2];
    refEdge[i][0] = MTriangle::edges_tri(i, 0);
    refEdge[i][1] = MTriangle::edges_tri(i, 1); 
  }

  // Face Definition //
  nFace   = 0;
  refFace = NULL;
  
  // Init All //
  init();
}

TriReferenceSpace::~TriReferenceSpace(void){
  // Delete Ref Edge //
  for(unsigned int i = 0; i < nEdge; i++)
    delete[] refEdge[i];
  
  delete[] refEdge;
}

string TriReferenceSpace::toLatex(void) const{
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
	   << "\\node[vertex] (n2) at(0, 3) {$2$};" << endl << endl;

    for(unsigned int i = 0; i < 3; i++)
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
  TriReferenceSpace p;

  cout << p.toLatex() << endl;
  
  return 0;
}
*/
