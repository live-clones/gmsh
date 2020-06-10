// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "discreteRegion.h"
#include "GModelIO_GEO.h"
#include "Geo.h"

discreteRegion::discreteRegion(GModel *model, int num) : GRegion(model, num)
{
  ::Volume *v = CreateVolume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(model->getGEOInternals()->Volumes, &v);
}

discreteRegion::discreteRegion(GModel *model) : GRegion(model, 0)
{
}
