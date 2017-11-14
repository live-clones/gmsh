%module gmsh
%{
  #include "gmsh.h"
%}

%include std_string.i
%include std_vector.i

namespace std {
  %template(DoubleVector) vector<double>;
  %template(StringVector) vector<string>;
  %template(PairVector) vector<std::pair<int, int> >;
}

%include "gmsh.h"
