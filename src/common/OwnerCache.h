// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OWNER_CACHE_H
#define OWNER_CACHE_H

#include <algorithm>
#include <map>
#include <vector>

// What is kept between frames for an object (a model, an entity, a view), in
// caches keyed by the object. Whatever every cache keeps for an object is
// dropped when the object is destroyed (its destructor calls
// OwnerCacheBase::release()), so that nothing is found for a new object that
// happens to be given the same address, and nothing has to be swept at every
// frame.
class OwnerCacheBase {
public:
  // drop what every cache keeps for the owner
  static void release(const void *owner)
  {
    for(auto c : _registry()) c->erase(owner);
  }
  virtual void erase(const void *owner) = 0;

protected:
  OwnerCacheBase() { _registry().push_back(this); }
  virtual ~OwnerCacheBase()
  {
    std::vector<OwnerCacheBase *> &r = _registry();
    r.erase(std::remove(r.begin(), r.end(), this), r.end());
  }

private:
  static std::vector<OwnerCacheBase *> &_registry()
  {
    static std::vector<OwnerCacheBase *> r;
    return r;
  }
};

template <class T> class OwnerCache : public OwnerCacheBase {
private:
  // never destroyed: at exit the owners, and what the data refers to (e.g.
  // the buffers of the graphics), may be gone already
  std::map<const void *, T> &_data = *new std::map<const void *, T>();

public:
  // what is kept for an owner, made empty if there is nothing yet
  T &operator[](const void *owner) { return _data[owner]; }
  // null if nothing is kept for it
  T *find(const void *owner)
  {
    auto it = _data.find(owner);
    return it == _data.end() ? nullptr : &it->second;
  }
  void erase(const void *owner) override { _data.erase(owner); }
  void clear() { _data.clear(); }
};

#endif
