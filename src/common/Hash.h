// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HASH_H
#define HASH_H

#include "GmshConfig.h"

// FNV (Fowler–Noll–Vo) hashing parameters

#if defined(HAVE_64BIT_SIZE_T)
#define FNV_PRIME 1099511628211UL
#define FNV_OFFSET_BASIS 14695981039346656037UL
#else
#define FNV_PRIME 16777619UL
#define FNV_OFFSET_BASIS 2166136261UL
#endif

// Hash FNV1a implemented via for loop.  "key" has size "len" bytes.

inline size_t hash_FNV1a(const void *const key, const int len)
{
  const unsigned char *p = static_cast<const unsigned char *>(key);
  size_t hash = FNV_OFFSET_BASIS;
  for(int n = len; n--;) hash = (hash ^ static_cast<size_t>(*p++)) * FNV_PRIME;
  return hash;
}

// Hash FNV1a implemented via template-metaprogramming loop.  This should be
// used if the length N is known at compile time.  "key" has size "N" bytes.
// Use the entry point HashFNV1a<N>::eval(key).

template <int N> struct Hash1FNV1a {
  static size_t eval(size_t hash, const unsigned char *p)
  {
    return Hash1FNV1a<N - 1>::eval((hash ^ static_cast<size_t>(*p)) * FNV_PRIME,
                                   p + 1);
  }
};

template <> struct Hash1FNV1a<1> {
  static size_t eval(size_t hash, const unsigned char *p)
  {
    return (hash ^ static_cast<size_t>(*p)) * FNV_PRIME;
  }
};

// Entry point
template <int N> struct HashFNV1a {
  static size_t eval(const void *const key)
  {
    size_t hash = FNV_OFFSET_BASIS;
    return Hash1FNV1a<N>::eval(hash, static_cast<const unsigned char *>(key));
  }
};

// Mixing of a 64-bit value (the finalizer of splitmix64): every bit of the
// result depends on every bit of x, so that the high bits can be used too
inline std::size_t HashMix(std::size_t x)
{
  x ^= x >> 30;
  x *= 0xbf58476d1ce4e5b9ull;
  x ^= x >> 27;
  x *= 0x94d049bb133111ebull;
  x ^= x >> 31;
  return x;
}

#endif
