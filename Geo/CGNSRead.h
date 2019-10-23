// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_READ_H
#define CGNS_READ_H

#include <vector>

#if defined(HAVE_LIBCGNS)


class MVertex;
class MElement;


double readScale();

int readZone(int cgIndexFile, int cgIndexBase, int iZone, int dim, double scale,
             std::vector<MVertex *> &allVert,
             std::map<int, std::vector<MElement *> > *allElt, int &nbEltTot);


#endif // HAVE_LIBCGNS

#endif // CGNS_READ_H
