// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


#include "Backend.h"

namespace Ui {

  namespace {

    // filled by constructors that run before main()
    struct Offering {
      std::vector<std::string> names;
      std::vector<Backend *(*)()> makers;
    };

    Offering &_offering()
    {
      static Offering it;
      return it;
    }

    std::string &_chosen()
    {
      static std::string it;
      return it;
    }

  } // namespace

  void offer(const char *name, Backend *(*make)())
  {
    if(!name || !make) return;
    Offering &it = _offering();
    for(std::size_t i = 0; i < it.names.size(); i++)
      if(it.names[i] == name) return; // said twice: the first one stands
    it.names.push_back(name);
    it.makers.push_back(make);
  }

  const std::vector<std::string> &offered() { return _offering().names; }

  Backend *make(const std::string &name)
  {
    Offering &it = _offering();
    if(it.names.empty()) return nullptr;
    if(name.empty()) {
      _chosen() = it.names[0];
      return it.makers[0]();
    }
    for(std::size_t i = 0; i < it.names.size(); i++)
      if(it.names[i] == name) {
        _chosen() = name;
        return it.makers[i]();
      }
    return nullptr;
  }

  const std::string &chosen() { return _chosen(); }

} // namespace Ui
