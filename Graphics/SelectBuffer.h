// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SELECT_BUFFER_H_
#define _SELECT_BUFFER_H_

#include <vector>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

class MElement;

bool ProcessSelectionBuffer(int entityType, 
                            bool multipleSelection, bool meshSelection,
                            int x, int y, int w, int h, 
                            std::vector<GVertex*> &vertices,
                            std::vector<GEdge*> &edges,
                            std::vector<GFace*> &faces,
                            std::vector<GRegion*> &regions,
                            std::vector<MElement*> &elements);
char SelectEntity(int entityType,
                  std::vector<GVertex*> &vertices,
                  std::vector<GEdge*> &edges,
                  std::vector<GFace*> &faces,
                  std::vector<GRegion*> &regions,
                  std::vector<MElement*> &elements);
void HighlightEntity(GEntity *e);
void HighlightEntityNum(int v, int c, int s, int r);
void ZeroHighlightEntity(GEntity *e);
void ZeroHighlightEntityNum(int v, int c, int s, int r);
void ZeroHighlight();

#endif
