#ifndef _HXT_TETOPTIDATE_
#define _HXT_TETOPTIDATE_

#include "stdint.h"

typedef struct {
  uint16_t creation;
  uint16_t check;
} HXTTetDate;

typedef struct {
  HXTTetDate* values;
  uint16_t current;
} HXTTetDates;




#endif