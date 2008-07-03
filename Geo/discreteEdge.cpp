// $Id: discreteEdge.cpp,v 1.2 2008-07-03 17:06:02 geuzaine Exp $
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

#include "discreteEdge.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Geo.h"
#  include "Message.h"
#endif

discreteEdge::discreteEdge(GModel *model, int num) : GEdge(model, num, 0, 0) 
{
#if !defined(HAVE_GMSH_EMBEDDED)
  Curve *c = Create_Curve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
#endif
}

GPoint discreteEdge::point(double p) const 
{
  Msg::Error("Cannot evaluate point on discrete edge");
  return GPoint();
}

SVector3 discreteEdge::firstDer(double par) const 
{
  Msg::Error("Cannot evaluate derivative on discrete edge");
  return SVector3();
}

double discreteEdge::parFromPoint(const SPoint3 &pt) const 
{
  Msg::Error("Cannot compute parametric coordinate on discrete edge");
  return 0.;
}
