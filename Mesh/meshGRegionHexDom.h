
#ifndef MESH_GREGION_HEXDOM_H
#define MESH_GREGION_HEXDOM_H

#include <vector>

class GRegion;

int meshGRegionHexDom (std::vector<GRegion *> &regions);
void compute3DScaledCrossesFast ();
#endif
