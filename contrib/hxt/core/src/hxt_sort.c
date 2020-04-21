// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_sort.h"


/***************************************
 *     for 1 value                     *
 ***************************************/
static inline uint64_t group1_get(uint64_t* val, const void* userData){
  HXT_UNUSED(userData);
  return *val;
}

HXTStatus group1_sort(uint64_t* val, const uint64_t n, const uint64_t max){
  HXTSORT64_UNIFORM(uint64_t, val, n, max, group1_get, NULL);
  return HXT_STATUS_OK;
}

/***************************************
 *     for 2 values                    *
 ***************************************/
static inline uint64_t group2_get_v0(HXTGroup2* pair, const void* userData){
  HXT_UNUSED(userData);
  return pair->v[0];
}

HXTStatus group2_sort_v0(HXTGroup2* pair, const uint64_t n, const uint64_t max){
  HXTSORT64_UNIFORM(HXTGroup2, pair, n, max, group2_get_v0, NULL);
  return HXT_STATUS_OK;
}

static inline uint64_t group2_get_v1(HXTGroup2* pair, const void* userData){
  HXT_UNUSED(userData);
  return pair->v[1];
}

HXTStatus group2_sort_v1(HXTGroup2* pair, const uint64_t n, const uint64_t max){
  HXTSORT64_UNIFORM(HXTGroup2, pair, n, max, group2_get_v1, NULL);
  return HXT_STATUS_OK;
}


/***************************************
 *     for 3 values                    *
 ***************************************/
static inline uint64_t group3_get_v0(HXTGroup3* triplet, const void* userData){
  HXT_UNUSED(userData);
  return triplet->v[0];
}

HXTStatus group3_sort_v0(HXTGroup3* triplet, const uint64_t n, const uint64_t max){
  HXTSORT64_UNIFORM(HXTGroup3, triplet, n, max, group3_get_v0, NULL);
  return HXT_STATUS_OK;
}

static inline uint64_t group3_get_v1(HXTGroup3* triplet, const void* userData){
  HXT_UNUSED(userData);
  return triplet->v[1];
}

HXTStatus group3_sort_v1(HXTGroup3* triplet, const uint64_t n, const uint64_t max){
  HXTSORT64_UNIFORM(HXTGroup3, triplet, n, max, group3_get_v1, NULL);
  return HXT_STATUS_OK;
}

static inline uint64_t group3_get_v2(HXTGroup3* triplet, const void* userData){
  HXT_UNUSED(userData);
  return triplet->v[2];
}

HXTStatus group3_sort_v2(HXTGroup3* triplet, const uint64_t n, const uint64_t max){
  HXTSORT64_UNIFORM(HXTGroup3, triplet, n, max, group3_get_v2, NULL);
  return HXT_STATUS_OK;
}