%module onelab
%{
#include "onelab.h"
onelab::server *onelab::server::_server = 0;
void modelName(const std::string &name, const std::string &wdir="");
int metamodel(const std::string &todo);
void setNumber(const std::string &name, const double value);
void setString(const std::string &name, const std::string &value);
double getNumber(const std::string &name);
std::string getString(const std::string &name);

%}
 
%include std_string.i

extern void modelName(const std::string &name, const std::string &wdir="");
extern int metamodel(const std::string &todo);
extern void setNumber(const std::string &name, const double value);
extern void setString(const std::string &name, const std::string &value);
extern double getNumber(const std::string &name);
extern std::string getString(const std::string &name);


