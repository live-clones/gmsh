// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETOPTIUTILS_H
#define HXT_TETOPTIUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetPartition.h"
#include "hxt_tetSync.h"
#include "hxt_tetQuality.h"

typedef struct {
  uint16_t creation;
  uint16_t check;
} HXTTetDate;


typedef struct {
  HXTTetDate* values;
  uint16_t current;
} HXTTetDates;


typedef struct {
  uint64_t attempt;
  uint64_t conflict;
  uint64_t success;
} Statistic;


typedef struct
{
  /*** located here ***/
  // list of deleted tet. Added when the cavity is created, removed when the cavity is filled
  HXTDeleted deleted;
  HXTPartition partition;
  Statistic stat;

  /*** located in shared structure ***/
  HXTTetQualities* quality;
  HXTTetDates* date;
  HXT2Sync* toSync;
  uint32_t numVerticesConstrained;

  struct {
    // special dates used by SPR
    uint64_t dateOfLastCheck;
    uint64_t dateOfLastCreation;

    // maximum number of nodes in the SPR search tree
    uint64_t maxSearchNodes;
  } SPR;
} ThreadLocal;


#ifdef __cplusplus
}
#endif

#endif
