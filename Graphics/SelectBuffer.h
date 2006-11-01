#ifndef _SELECT_BUFFER_H_
#define _SELECT_BUFFER_H_
/*
 * Copyright (C) 1999-2006 Christophe Geuzaine <geuz@geuz.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of either:
 *
 * a) the GNU Library General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your
 * option) any later version; or
 *
 * b) the GL2PS License as published by Christophe Geuzaine, either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See either
 * the GNU Library General Public License or the GL2PS License for
 * more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library in the file named "COPYING.LGPL";
 * if not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 *
 * You should have received a copy of the GL2PS License with this
 * library in the file named "COPYING.GL2PS"; if not, I will be glad
 * to provide one.
 */

#include <vector>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

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

void HighlightEntity(GEntity *e, bool permanent=false);
void HighlightEntity(GVertex *v, GEdge *e, GFace *f, GRegion *r, bool permanent=false);
void HighlightEntityNum(int v, int c, int s, int r, bool permanant=false);
void ZeroHighlightEntity(GVertex *v, GEdge *c, GFace *s, GRegion *r);
void ZeroHighlightEntityNum(int v, int c, int s, int r);
void ZeroHighlight();

#endif
