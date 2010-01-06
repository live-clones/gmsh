#ifndef _BINDINGS_H_
#define _BINDINGS_H_
#include <string>
#include <list>
#include <typeinfo>
#include "GmshConfig.h"

class methodBinding{
  std::string _description;
  public:
  void setArgNames(std::string arg1, ...){}
  void setDescription(std::string description){_description=description;}
  inline const std::string getDescription() const {return _description;}
};

#if defined(HAVE_LUA)
#include "LuaBindings.h"
#else  //no bindings
#include "DummyBindings.h"
#endif


#endif
