// $Id: discreteFace.cpp,v 1.3 2008-07-03 17:06:02 geuzaine Exp $
//
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

#include "discreteFace.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Geo.h"
#  include "Message.h"
#endif

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
#endif
  meshStatistics.status = GFace::DONE;    
}

GPoint discreteFace::point(double par1, double par2) const 
{
  Msg::Error("Cannot evaluate point on discrete face");
  return GPoint();
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p) const
{
  Msg::Error("Cannot compute parametric coordinates on discrete face");
  return SPoint2();
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
  Msg::Error("Cannot evaluate normal on discrete face");
  return SVector3();
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
  Msg::Error("Cannot evaluate derivative on discrete face");
  return Pair<SVector3, SVector3>();
}
