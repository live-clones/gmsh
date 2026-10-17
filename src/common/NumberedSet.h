// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef NUMBERED_SET_H
#define NUMBERED_SET_H

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>
#include "Hash.h"

// A set of keys (mesh edges or faces) with a number each, in the order they
// were added: the entries are (key, number) pairs in a vector, and lookups go
// through an index over them, a flat open-addressing table built on the first
// lookup and kept up to date after that. Entries appended in bulk, e.g. from
// a file, are not checked for duplicates until the index is built: a file
// then costs no more than its reading, and a model that never looks anything
// up never builds the index. (The index holds at most 2^32 - 2 entries.)
template <class K, class Hash, class Equal> class NumberedSet {
public:
  typedef K key_type;
  typedef Hash hasher;
  typedef std::pair<K, std::size_t> value_type;
  typedef typename std::vector<value_type>::const_iterator const_iterator;
  static const std::size_t npos = (std::size_t)-1;

private:
  std::vector<value_type> _entries;
  // the hashes of the keys of the entries, 64 bits wide whatever the
  // word size (a slot holds their high half as a tag)
  typedef std::uint64_t hash_t;
  std::vector<hash_t> _hashes;
  std::size_t _maxNum = 0;
  // a slot of the index: the entry it points to plus one (0 if free), and
  // the hash of its key, so that probing an occupied slot that does not match
  // costs no access to the entry
  struct slot {
    std::uint32_t index, hash;
  };
  mutable std::vector<slot> _slots;
  mutable std::size_t _mask = 0;
  mutable bool _indexed = false;
  Hash _hash;
  Equal _equal;

  static std::uint32_t _tag(hash_t h) { return (std::uint32_t)(h >> 32); }
  hash_t _hashOf(const K &key) const
  {
    hash_t h = _hash(key);
    if(sizeof(std::size_t) < 8) h = HashMix(h); // (spread a 32-bit hash)
    return h;
  }
  // the slot of key, of hash h: the one holding an equal entry, or the free
  // one where it would go
  std::size_t _slot(const K &key, hash_t h) const
  {
    std::size_t s = h & _mask;
    while(_slots[s].index &&
          (_slots[s].hash != _tag(h) ||
           !_equal(_entries[_slots[s].index - 1].first, key)))
      s = (s + 1) & _mask;
    return s;
  }
  // (re)build the index over the entries, with room for n of them at a load
  // of one half at most, dropping the entries that duplicate an earlier one
  void _index(std::size_t n) const
  {
    std::size_t cap = 16;
    while(cap < 2 * (n + 1)) cap <<= 1;
    _slots.assign(cap, slot{0, 0});
    _mask = cap - 1;
    std::vector<value_type> &entries =
      const_cast<std::vector<value_type> &>(_entries);
    std::vector<hash_t> &hashes = const_cast<std::vector<hash_t> &>(_hashes);
    std::size_t kept = 0;
    for(std::size_t i = 0; i < entries.size(); i++) {
      hash_t h = hashes[i];
      std::size_t s = _slot(entries[i].first, h);
      if(_slots[s].index) continue; // a duplicate
      if(kept != i) {
        entries[kept] = std::move(entries[i]);
        hashes[kept] = h;
      }
      _slots[s] = slot{(std::uint32_t)++kept, _tag(h)};
    }
    entries.resize(kept);
    hashes.resize(kept);
    _indexed = true;
  }
  void _index() const { _index(_entries.size()); }

public:
  std::size_t size() const { return _entries.size(); }
  bool empty() const { return _entries.empty(); }
  const_iterator begin() const { return _entries.begin(); }
  const_iterator end() const { return _entries.end(); }
  const value_type &operator[](std::size_t i) const { return _entries[i]; }
  // make room for n entries (in the index too, if it is built)
  void reserve(std::size_t n)
  {
    _entries.reserve(n);
    _hashes.reserve(n);
    if(_indexed && 2 * (n + 1) > _slots.size()) _index(n);
  }
  // drop the entries from the n-th on
  void truncate(std::size_t n)
  {
    if(n >= _entries.size()) return;
    _entries.resize(n);
    _hashes.resize(n);
    _maxNum = 0;
    for(auto &e : _entries) _maxNum = std::max(_maxNum, e.second);
    _indexed = false;
  }
  void clear()
  {
    std::vector<value_type>().swap(_entries);
    std::vector<hash_t>().swap(_hashes);
    std::vector<slot>().swap(_slots);
    _maxNum = 0;
    _indexed = false;
  }
  // the largest number given so far
  std::size_t maxNumber() const { return _maxNum; }
  // build the index now: lookups by several threads at once need it built
  // (they are read-only once it is)
  void index() const
  {
    if(!_indexed) _index();
  }
  // the hash of a key, for the lookups below that take it
  hash_t hashOf(const K &key) const { return _hashOf(key); }
  // the index of the entry of key, npos if there is none
  std::size_t indexOf(const K &key, hash_t h) const
  {
    if(!_indexed) _index();
    std::size_t s = _slot(key, h);
    return _slots[s].index ? _slots[s].index - 1 : npos;
  }
  std::size_t indexOf(const K &key) const { return indexOf(key, _hashOf(key)); }
  const_iterator find(const K &key) const
  {
    std::size_t i = indexOf(key);
    return i == npos ? end() : begin() + i;
  }
  // add key, of hash h, with number num (the largest number so far plus one
  // if 0), or return the number it already has
  std::size_t add(K &&key, std::size_t num, hash_t h)
  {
    if(!_indexed) _index();
    std::size_t s = _slot(key, h);
    if(_slots[s].index) return _entries[_slots[s].index - 1].second;
    if(!num) num = _maxNum + 1;
    _maxNum = std::max(_maxNum, num);
    _entries.emplace_back(std::move(key), num);
    _hashes.push_back(h);
    _slots[s] = slot{(std::uint32_t)_entries.size(), _tag(h)};
    if(2 * (_entries.size() + 1) > _slots.size()) _index();
    return num;
  }
  std::size_t add(K &&key, std::size_t num = 0)
  {
    hash_t h = _hashOf(key);
    return add(std::move(key), num, h);
  }
  // append an entry without looking for a duplicate (see above)
  void append(K &&key, std::size_t num)
  {
    _maxNum = std::max(_maxNum, num);
    _hashes.push_back(_hashOf(key));
    _entries.emplace_back(std::move(key), num);
    _indexed = false;
  }
  // append n entries to be set with set(), e.g. by several threads at once;
  // returns the index of the first
  std::size_t append(std::size_t n)
  {
    std::size_t first = _entries.size();
    _entries.resize(first + n);
    _hashes.resize(first + n);
    _indexed = false;
    return first;
  }
  void set(std::size_t i, K &&key, std::size_t num)
  {
    _hashes[i] = _hashOf(key);
    _entries[i] = value_type(std::move(key), num);
  }
  // the largest number so far is kept by append(K, num); after set() it is
  // updated with
  void setMaxNumber(std::size_t num) { _maxNum = std::max(_maxNum, num); }
};

#endif
