#include "discreteFace.h"
#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
#endif
  meshStatistics.status = GFace::DONE;    
}
