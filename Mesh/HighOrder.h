// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _HIGH_ORDER_H_
#define _HIGH_ORDER_H_

#include "GModel.h"
#include "MFace.h"

// for each pair of vertices (an edge), we build a list of vertices
// that are the high order representation of the edge. The ordering of
// vertices in the list is supposed to be (by construction) consistent
// with the ordering of the pair.
typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MVertex*> > edgeContainer;

// for each face (a list of vertices) we build a list of vertices that
// are the high order representation of the face
// typedef std::map<std::vector<MVertex*>, std::vector<MVertex*>> faceContainer;
typedef std::map<MFace, std::vector<MVertex*>, Less_Face> faceContainer;

void SetOrder1(GModel *m);
void SetOrderN(GModel *m, int order, bool linear=true, bool incomplete=false);

#endif
