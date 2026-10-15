/**
 * @file dlsort.h
 * @brief Sorting Key-Value pairs
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */



#ifndef DL_SORT_H
#define DL_SORT_H

#define __DL_MK_SORTKV_HEADERS(prefix,typek,typev) \
  typev * prefix ## _countingsort_v(const typek * keys, const typev * vals, \
      typev * out, typek min, typev max, size_t n);

#define __DL_MK_SORTKV_FUNCS(prefix,typek,typev) \
  typev * prefix ## _countingsort_v(const typek * const keys, \
      const typev * const vals, typev * const out, const typek min, \
      const typek max, const size_t n) \
  { \
    size_t i; \
    const size_t size = (size_t)(max - min)+1; \
    size_t * counts = size_calloc(size+1); \
    /* avoid having to do offsets in each iteration */ \
    size_t * const start = counts - ((ssize_t)min); \
    for (i=0;i<n;++i) { \
      ++start[keys[i]]; \
    } \
    size ## _prefixsum_exc(counts,size+1); \
    for (i=0;i<n;++i) { \
      out[start[keys[i]]++] = vals[i]; \
    } \
    dl_free(counts); \
    return out; \
  }

#define DL_MK_SORTKV_HEADERS(prefix,typek,typev) \
  __DL_MK_SORTKV_HEADERS(prefix,typek,typev)

#define DL_MK_SORTKV_FUNCS(prefix,typek,typev) \
  __DL_MK_SORTKV_FUNCS(prefix,typek,typev)


#endif
