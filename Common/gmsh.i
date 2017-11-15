%module gmsh

// "int &outTag" in function arguments is replaced by an append of outTag to the
// value returned by the function
%include typemaps.i
%apply int &OUTPUT { int &outTag };

// handle gracefully the arguments of gmshInitialize
%include argcargv.i
%apply (int ARGC, char **ARGV) { (int argc, char **argv) }

%{
  #include "gmsh.h"
%}

%include std_string.i
%include std_vector.i
%include std_pair.i

%template() std::pair<int, int>;
%template(IntVector) std::vector<int>;
%template(IntVectorVector) std::vector<std::vector<int> >;
%template(DoubleVector) std::vector<double>;
%template(StringVector) std::vector<std::string>;
%template(PairVector) std::vector<std::pair<int, int> >;
%template(PairVectorVector) std::vector<std::vector<std::pair<int, int> > >;

%include "gmsh.h"
