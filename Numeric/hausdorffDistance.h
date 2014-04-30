#ifndef _HAUSDORFF_DISTANCE_H_
#define _HAUSDORFF_DISTANCE_H_
#include <vector>
#include "SPoint3.h"
double hausdorffDistance (const std::vector<SPoint3> &P, 
			  const std::vector<SPoint3> &Q);
#endif
