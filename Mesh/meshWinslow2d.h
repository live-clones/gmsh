#ifndef _MESH_WINSLOW_2D_
#define _MESH_WINSLOW_2D_
class GModel;
class GFace;
class Field;
void meshWinslow2d (GModel * gm, int nIter=100, Field *f = NULL);
void meshWinslow2d (GFace  * gf, int nIter=100, Field *f = NULL);
#endif
