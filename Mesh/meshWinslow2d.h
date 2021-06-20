#ifndef _MESH_WINSLOW_2D_
#define _MESH_WINSLOW_2D_

#include <vector>
#include <unordered_map>
class GModel;
class GFace;
class Field;
class MQuadrangle;
class MVertex;
class SurfaceProjector;
// void meshWinslow2d (GModel * gm, int nIter=100);
void meshWinslow2d (GModel * gm, int nIter=100, Field *f = NULL, std::unordered_map<GFace*,SurfaceProjector*>* projectors = NULL);
void meshWinslow2d (GFace  * gf, int nIter=100, Field *f = NULL, bool remove = false);
void meshWinslow2d (GFace  * gf, const std::vector<MQuadrangle*>& quads, const std::vector<MVertex*>& freeVertices, int nIter=100, Field *f = NULL, bool remove = false);

#endif
