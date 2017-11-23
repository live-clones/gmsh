%module gmsh

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
%template(DoubleVectorVector) std::vector<std::vector<double> >;
%template(StringVector) std::vector<std::string>;
%template(PairVector) std::vector<std::pair<int, int> >;
%template(PairVectorVector) std::vector<std::vector<std::pair<int, int> > >;

%include "gmsh.h"
