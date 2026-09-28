// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <algorithm>
#include <vector>
#include "sceneHost.h"
#include "OS.h"

namespace Scene {

  namespace {
    Host &_held()
    {
      static Host held;
      return held;
    }
  } // namespace

  void setHost(const Host &host) { _held() = host; }
  const Host &host() { return _held(); }

  namespace {
    struct pending {
      double due;
      std::function<void()> what;
    };
    std::vector<pending> &_pending()
    {
      static std::vector<pending> queue;
      return queue;
    }
  } // namespace

  void later(double seconds, std::function<void()> what)
  {
    _pending().push_back({TimeOfDay() + seconds, what});
  }

  void fireTimers()
  {
    double now = TimeOfDay();
    // what is due is taken off the queue before it runs: it may ask for more
    std::vector<pending> due, left;
    for(auto &p : _pending()) (p.due <= now ? due : left).push_back(p);
    _pending() = left;
    for(auto &p : due) p.what();
  }

  double nextTimer()
  {
    if(_pending().empty()) return -1.;
    double now = TimeOfDay(), least = 1e30;
    for(auto &p : _pending()) least = std::min(least, p.due - now);
    return least < 0. ? 0. : least;
  }

} // namespace Scene

#endif
