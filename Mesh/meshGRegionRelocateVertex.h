#ifndef _MESHGREGIONRELOCATEVERTEX_
#define _MESHGREGIONRELOCATEVERTEX_
#include <vector>
class GRegion;
class GFace;
class MElement;
void RelocateVertices (GRegion* region, int niter, double tol = 1.e-2);
void RelocateVertices (std::vector<GRegion*> &regions, int niter, double tol = 1.e-2);
void RelocateVertices (GFace*, int niter, double tol = 1.e-3);
void _relocateVertexGolden(MVertex *ver, const std::vector<MElement*> &lt,  double relax, double tol= 1.e-2);

#endif
