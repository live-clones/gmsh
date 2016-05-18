#ifndef _MESHGREGIONRELOCATEVERTEX_
#define _MESHGREGIONRELOCATEVERTEX_
#include <vector>
class GRegion;
class GFace;
void RelocateVertices (GRegion* region, double tol = 1.e-2);
void RelocateVertices (std::vector<GRegion*> &regions, double tol = 1.e-2);
void RelocateVertices (GFace*, int niter, double tol = 1.e-3);
#endif
