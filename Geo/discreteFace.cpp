// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
