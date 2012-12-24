%module onelab
%{
#include "onelab.h"
onelab::server *onelab::server::_server = 0;
%}
 
%include std_string.i
%include std_vector.i
%include std_map.i
%template(OnelabNumberVector) std::vector<onelab::number>;
%template(OnelabStringVector) std::vector<onelab::string>;
%template(DoubleVector) std::vector<double>;
%template(StringVector) std::vector<std::string>;
%template(DoubleStringMap) std::map<double, std::string>;
%include "onelab.h"
