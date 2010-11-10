// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GPoint.h"
#include "Bindings.h"

void GPoint::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<GPoint>("GPoint");
  cb->setDescription("A GPoint.");
  methodBinding *cm;
  cm = cb->addMethod("x", (double (GPoint::*)() const) &GPoint::x);
  cm->setDescription("Return the x-coordinate.");
  cm = cb->addMethod("y", (double (GPoint::*)() const) &GPoint::y);
  cm->setDescription("Return the y-coordinate.");
  cm = cb->addMethod("z", (double (GPoint::*)() const) &GPoint::z);
  cm->setDescription("Return the z-coordinate.");

}
