// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TAG_MAP_H
#define TAG_MAP_H

#include <cstddef>
#include <iterator>
#include <utility>
#include <vector>
#include "Hash.h"

// A map from tags (positive integers) to values, as a flat open-addressing
// table: (tag, value) slots, the tag 0 marking a free one, probed linearly
// from the mixed hash of the tag. For the caches of the mesh nodes and
// elements whose numbering is not dense: a lookup or an insertion costs a
// memory access or two and no allocation, unlike in a std::map. Iteration is
// in no particular order.
template <class V> class TagMap {
public:
  struct slot {
    std::size_t first;
    V second;
    operator std::pair<const std::size_t, V>() const
    { return std::pair<const std::size_t, V>(first, second); }
  };
  template <class S> class basic_iterator {
    S *_p, *_end;

  public:
    // (the traits, for the standard algorithms and containers, e.g. a
    // std::map built from a range of the entries)
    typedef std::forward_iterator_tag iterator_category;
    typedef S value_type;
    typedef std::ptrdiff_t difference_type;
    typedef S *pointer;
    typedef S &reference;
    basic_iterator(S *p, S *end) : _p(p), _end(end)
    {
      while(_p != _end && !_p->first) _p++;
    }
    S &operator*() const { return *_p; }
    S *operator->() const { return _p; }
    basic_iterator &operator++()
    {
      do {
        _p++;
      } while(_p != _end && !_p->first);
      return *this;
    }
    basic_iterator operator++(int)
    {
      basic_iterator it = *this;
      ++*this;
      return it;
    }
    bool operator==(const basic_iterator &o) const { return _p == o._p; }
    bool operator!=(const basic_iterator &o) const { return _p != o._p; }
  };
  typedef basic_iterator<slot> iterator;
  typedef basic_iterator<const slot> const_iterator;

private:
  std::vector<slot> _slots;
  std::size_t _mask = 0, _size = 0;

  std::size_t _probe(std::size_t tag) const
  {
    std::size_t s = HashMix(tag) & _mask;
    while(_slots[s].first && _slots[s].first != tag) s = (s + 1) & _mask;
    return s;
  }
  // room for one more at a load of three quarters at most
  void _grow()
  {
    std::vector<slot> old;
    old.swap(_slots);
    std::size_t cap = 16;
    while(3 * cap < 4 * (_size + 1)) cap <<= 1;
    _slots.assign(cap, slot{0, V()});
    _mask = cap - 1;
    for(auto &s : old)
      if(s.first) _slots[_probe(s.first)] = std::move(s);
  }

public:
  std::size_t size() const { return _size; }
  bool empty() const { return !_size; }
  void clear()
  {
    std::vector<slot>().swap(_slots);
    _mask = _size = 0;
  }
  iterator begin()
  { return iterator(_slots.data(), _slots.data() + _slots.size()); }
  iterator end()
  {
    return iterator(_slots.data() + _slots.size(),
                    _slots.data() + _slots.size());
  }
  const_iterator begin() const
  { return const_iterator(_slots.data(), _slots.data() + _slots.size()); }
  const_iterator end() const
  {
    return const_iterator(_slots.data() + _slots.size(),
                          _slots.data() + _slots.size());
  }
  iterator find(std::size_t tag)
  {
    if(_slots.empty()) return end();
    std::size_t s = _probe(tag);
    return _slots[s].first ?
             iterator(&_slots[s], _slots.data() + _slots.size()) :
             end();
  }
  const_iterator find(std::size_t tag) const
  {
    if(_slots.empty()) return end();
    std::size_t s = _probe(tag);
    return _slots[s].first ?
             const_iterator(&_slots[s], _slots.data() + _slots.size()) :
             end();
  }
  std::size_t count(std::size_t tag) const { return find(tag) != end(); }
  // room for n entries without growing
  void reserve(std::size_t n)
  {
    if(4 * n > 3 * _slots.size()) {
      std::size_t size = _size;
      _size = n - 1;
      _grow();
      _size = size;
    }
  }
  // insert tag with value, unless it is there: the value there and whether
  // it was inserted (one probe, where a count and an insertion would take
  // two)
  std::pair<V &, bool> insert(std::size_t tag, const V &value)
  {
    if(4 * (_size + 1) > 3 * _slots.size()) _grow();
    std::size_t s = _probe(tag);
    if(_slots[s].first) return {_slots[s].second, false};
    _slots[s].first = tag;
    _slots[s].second = value;
    _size++;
    return {_slots[s].second, true};
  }
  // the value of tag, inserted (default) if it is not there
  V &operator[](std::size_t tag)
  {
    if(4 * (_size + 1) > 3 * _slots.size()) _grow();
    std::size_t s = _probe(tag);
    if(!_slots[s].first) {
      _slots[s].first = tag;
      _size++;
    }
    return _slots[s].second;
  }
  // the entries of another map (e.g. a std::map)
  template <class M> TagMap &operator=(const M &m)
  {
    clear();
    for(auto &p : m) (*this)[p.first] = p.second;
    return *this;
  }
};

#endif
