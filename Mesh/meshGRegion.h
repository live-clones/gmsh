#ifndef _MESH_GREGION_H_
#define _MESH_GREGION_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <vector>

class GModel;
class GRegion;

// Create the mesh of the region
class meshGRegion {
 public :
  std::vector<GRegion*> &delaunay;
  meshGRegion(std::vector<GRegion*> &d) : delaunay(d) {}
  void operator () (GRegion *);
};

class meshGRegionExtruded {
 public :
  void operator () (GRegion *);
};

// Optimize the mesh of the region using gmsh's algo
class optimizeMeshGRegionGmsh {
 public :
  void operator () (GRegion *);
};

// Optimize the mesh of the region using netgen's algo
class optimizeMeshGRegionNetgen {
 public :
  void operator () (GRegion *);
};

// destroy the mesh of the region
class deMeshGRegion {
 public :
  void operator () (GRegion *);
};

// adapt the mesh of a region
class adaptMeshGRegion {
 public :
  void operator () (GRegion *);
};


void MeshDelaunayVolume(std::vector<GRegion*> &delaunay);
int MeshTransfiniteVolume(GRegion *gr);
int SubdivideExtrudedMesh(GModel *m);
void carveHole(GRegion *gr, int num, double distance, std::vector<int> &surfaces);

#endif
