// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DELAUNAY3D_H_
#define _DELAUNAY3D_H_

class MVertex;
class MTetrahedron;

void delaunayTriangulation(const int numThreads,
                           const int nptsatonce,
                           std::vector<MVertex*> &S,
                           std::vector<MTetrahedron*> &T);

#endif
