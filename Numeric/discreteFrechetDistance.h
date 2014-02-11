#ifndef _DISCRETE_FRECHET_DISTANCE_
#define _DISCRETE_FRECHET_DISTANCE_
#include <vector>
#include "SPoint3.h"
double discreteFrechetDistance (const std::vector<SPoint3> &P, 
				const std::vector<SPoint3> &Q);
#endif
