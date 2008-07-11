// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "discreteRegion.h"

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

discreteRegion::discreteRegion(GModel *model, int num) : GRegion(model, num)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  ::Volume *v = Create_Volume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(model->getGEOInternals()->Volumes, &v);
#endif
}
