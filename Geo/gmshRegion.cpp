#include "gmshModel.h"
#include "gmshFace.h"
#include "gmshRegion.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"

extern Mesh *THEM;

gmshRegion::gmshRegion(GModel *m, ::Volume * volume)
  : GRegion(m, volume->Num), v(volume)
{
  Surface *s;
  int ori;
  for(int i = 0; i < List_Nbr(v->Surfaces); i++){
    List_Read(v->Surfaces, i, &s);
    List_Read(v->SurfacesOrientations, i, &ori);
    GFace *f = m->faceByTag(abs(s->Num));
    if(!f) throw;
    l_faces.push_back(f);
    l_dirs.push_back(ori);
  }
}

gmshRegion::gmshRegion(GModel *m, int num)
  : GRegion(m, num)
{
  v = Create_Volume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(THEM->Volumes, &v);
}

GEntity::GeomType gmshRegion::geomType() const
{
  switch (v->Typ){
  case MSH_VOLUME_DISCRETE : return DiscreteVolume;
  default : return Volume;
  }
}
