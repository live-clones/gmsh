#include "discreteRegion.h"
#include "GModel.h"

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
