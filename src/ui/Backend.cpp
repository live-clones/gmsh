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

  std::vector<std::string> Backend::FileFormat::patterns() const
  {
    std::vector<std::string> out;
    std::string all = pattern;
    for(char &c : all)
      if(c == ';' || c == '\t') c = ' ';
    std::size_t at = 0;
    while(at < all.size()) {
      std::size_t end = all.find(' ', at);
      std::string one =
        all.substr(at, end == std::string::npos ? std::string::npos : end - at);
      at = end == std::string::npos ? all.size() : end + 1;
      if(one.empty()) continue;
      if(one == "*.*") one = "*";
      std::size_t open = one.find('{'), close = one.find('}');
      if(open == std::string::npos || close == std::string::npos ||
         close < open) {
        out.push_back(one);
        continue;
      }
      std::string head = one.substr(0, open), tail = one.substr(close + 1);
      std::string inside = one.substr(open + 1, close - open - 1);
      std::size_t k = 0;
      while(true) {
        std::size_t comma = inside.find(',', k);
        out.push_back(head +
                      inside.substr(k, comma == std::string::npos ?
                                         std::string::npos :
                                         comma - k) +
                      tail);
        if(comma == std::string::npos) break;
        k = comma + 1;
      }
    }
    return out;
  }

} // namespace Ui
