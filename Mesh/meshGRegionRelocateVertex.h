#ifndef _MESHGREGIONRELOCATEVERTEX_
#define _MESHGREGIONRELOCATEVERTEX_
#include <vector>
class GRegion;
void RelocateVertices (std::vector<GRegion*> &regions, double tol = 1.e-2);
#endif
