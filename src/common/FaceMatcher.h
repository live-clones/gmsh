// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FACE_MATCHER_H
#define FACE_MATCHER_H

#include <algorithm>
#include <cstdint>
#include <vector>

// Finds the faces that are met an odd number of times - the skin of a set of
// 3D elements, when each element gives its faces (or of 2D elements, when
// each gives its edges). A face is told apart by its nodes, 2 or more (of type
// K: an identifier or an address) and a tag (the entity, so that the skin can
// be taken entity by entity); what gave it (of type Owner) and its number in it are
// kept for the faces that are left. A face met a second time is taken out of
// the table, which thus never holds more than the front between the elements
// seen and the others.
//
// Several matchers can work side by side, each on the faces share() gives
// it: a face goes to the same one whoever gives it.
template <class K, class Owner> class FaceMatcher {
private:
  // open addressing on a 64-bit hash of the face, which stands for it (as in
  // UniqueElementFilter: two faces with the same one are not to be expected);
  // 0 marks a free slot. The table grows with what is left in it, not with
  // what goes through it, so that it stays small.
  struct slot {
    std::uint64_t hash;
    Owner owner;
    std::uint8_t face;
  };
  std::vector<slot> _slots;
  std::size_t _mask, _count;
  static std::uint64_t _mix(std::uint64_t x)
  {
    x ^= x >> 32;
    x *= 0xff51afd7ed558ccdull;
    x ^= x >> 29;
    return x;
  }
  void _grow()
  {
    std::vector<slot> old;
    old.swap(_slots);
    _slots.assign(2 * old.size(), slot{0, Owner(), 0});
    _mask = _slots.size() - 1;
    for(auto &s : old) {
      if(!s.hash) continue;
      std::size_t i = s.hash & _mask;
      while(_slots[i].hash) i = (i + 1) & _mask;
      _slots[i] = s;
    }
  }

public:
  FaceMatcher() : _slots(1 << 12, slot{0, Owner(), 0}), _count(0)
  {
    _mask = _slots.size() - 1;
  }
  // which of n matchers gets the face
  static int share(const K *k, int numNodes, int n)
  {
    if(n <= 1) return 0;
    K kmin = std::min(k[0], k[1]);
    for(int a = 2; a < numNodes; a++) kmin = std::min(kmin, k[a]);
    return (int)((_mix((std::uint64_t)kmin) >> 20) % (std::uint64_t)n);
  }
  // The hash that stands for a face (k is sorted in place). Asking for the
  // faces of an element before adding them lets the misses of their slots
  // overlap.
  std::uint64_t hashOf(K *k, int numNodes, int tag) const
  {
    for(int a = 1; a < numNodes; a++)
      for(int b = a; b > 0 && k[b] < k[b - 1]; b--) std::swap(k[b], k[b - 1]);
    std::uint64_t h = ((std::uint64_t)(unsigned int)tag << 8) ^ numNodes;
    for(int a = 0; a < numNodes; a++)
      h = _mix(h * 0x9e3779b97f4a7c15ull ^ (std::uint64_t)k[a]);
    if(!h) h = 1;
#if defined(__GNUC__) || defined(__clang__)
    __builtin_prefetch(&_slots[h & _mask]);
#endif
    return h;
  }
  void add(std::uint64_t h, Owner owner, int face)
  {
    std::size_t i = h & _mask;
    while(_slots[i].hash) {
      if(_slots[i].hash == h) {
        // met a second time: take it out, moving back what it had pushed on
        std::size_t j = i;
        while(1) {
          j = (j + 1) & _mask;
          if(!_slots[j].hash) break;
          std::size_t home = _slots[j].hash & _mask;
          if(((j - home) & _mask) >= ((j - i) & _mask)) {
            _slots[i] = _slots[j];
            i = j;
          }
        }
        _slots[i].hash = 0;
        _count--;
        return;
      }
      i = (i + 1) & _mask;
    }
    _slots[i] = slot{h, owner, (std::uint8_t)face};
    if(2 * ++_count > _slots.size()) _grow();
  }
  // f(owner, face) for the faces that are left, in no particular order
  template <class F> void forEachLeft(F f) const
  {
    for(auto &s : _slots)
      if(s.hash) f(s.owner, (int)s.face);
  }
};

#endif
