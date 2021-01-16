// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "discreteRegion.h"
#include "GModelIO_GEO.h"
#include "Geo.h"

discreteRegion::discreteRegion(GModel *model, int num)
  : GRegion(model, num), _geometry(false)
{
  ::Volume *v = CreateVolume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(model->getGEOInternals()->Volumes, &v);
}

discreteRegion::discreteRegion(GModel *model)
  : GRegion(model, 0), _geometry(false)
{
}

int discreteRegion::createGeometry()
{
  if(l_faces.empty()) {
    Msg::Error("Discrete volume %d has no surfaces on its boundary", tag());
    return 1;
  }

  // we should check that the surfaces form one or more (closed) shell(s)
  _geometry = true;

  return 0;
}
