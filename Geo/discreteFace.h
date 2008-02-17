#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include "GModel.h"
#include "GFace.h"

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

class discreteFace : public GFace {
 public:
  discreteFace(GModel *model, int num) : GFace(model, num)
  {
#if !defined(HAVE_GMSH_EMBEDDED)
    Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
    Tree_Add(model->getGEOInternals()->Surfaces, &s);
#endif
    meshStatistics.status = GFace::DONE;    
  }
  virtual ~discreteFace() {}
  virtual GPoint point(double par1, double par2) const { throw; }
  virtual SPoint2 parFromPoint(const SPoint3 &p) const { throw; }
  virtual SVector3 normal(const SPoint2 &param) const { throw; }
  virtual GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const { throw; }
};

#endif

