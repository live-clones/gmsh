// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "discreteRegion.h"
#include "MVertex.h"

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

void discreteRegion::setBoundFaces()
{

  //in case discrete region already exist
  //to modify to take into account appropriate faces
  for(GModel::fiter face = model()->firstFace(); face != model()->lastFace(); face++){
    l_faces.push_back(*face);
    (*face)->addRegion(this);
    printf("face %d \n", (*face)->tag());
  }


}
