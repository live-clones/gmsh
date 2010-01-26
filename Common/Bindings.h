#ifndef _BINDINGS_H_
#define _BINDINGS_H_
#include <string>
#include <vector>
#include <typeinfo>

class methodBinding{
  std::string _description;
  std::vector<std::string> _argNames;
  public:
  inline const std::vector<std::string> &getArgNames()const{
    return _argNames;
  }
  void setArgNames(const char * arg1, ...);
  void setDescription(std::string description){_description=description;}
  inline const std::string getDescription() const {return _description;}
};



#if defined(HAVE_LUA)
#include "LuaBindings.h"
#else  //no bindings
#include "DummyBindings.h"
#endif


#endif
