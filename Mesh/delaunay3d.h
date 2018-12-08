// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _DELAUNAY3D_H_
#define _DELAUNAY3D_H_

class MVertex;
class MTetrahedron;

// tetrahedralize the vertices given in S; adds 8 new vertices at the end of S (the
// corners of an enclosing box)
void delaunayTriangulation(const int numThreads, const int nptsatonce,
                           std::vector<MVertex *> &S,
                           std::vector<MTetrahedron *> &T);

#endif
