%module gmsh
%include typemaps.i
// reference to int is appended to the returned values of the function
%apply int &OUTPUT { int &outTag };
%{
  #include "gmsh.h"
%}

%include std_string.i
%include std_vector.i
%include std_pair.i

%template() std::pair<int, int>;
%template(IntVector) std::vector<int>;
%template(DoubleVector) std::vector<double>;
%template(StringVector) std::vector<std::string>;
%template(PairVector) std::vector<std::pair<int, int> >;
%template(PairVectorVector) std::vector<std::vector<std::pair<int, int> > >;

%include "gmsh.h"
