#include <iostream>
#include "GFace.h"
#include "GEdge.h"
#include "MVertex.h"
#include "ParamCoord.h"

ParamCoordSurf::ParamCoordSurf(GEntity *ge)
{
  if ((ge->dim() == 2) && (ge->geomType() != GEntity::DiscreteSurface)) _gf = static_cast<GFace*>(ge);
  else std::cout << "ERROR: Using surface parametric coordinates with non-surface geometric entity" << std::endl;
}



SPoint3 ParamCoordSurf::getUvw(MVertex* vert)
{
  SPoint2 p;
  reparamMeshVertexOnFace(vert,_gf,p);
  return SPoint3(p[0],p[1],0.);
}



SPoint3 ParamCoordSurf::uvw2Xyz(MVertex* vert, const SPoint3 &uvw)
{
  GPoint gp = _gf->point(uvw[0],uvw[1]);
  return SPoint3(gp.x(),gp.y(),gp.z());
}



void ParamCoordSurf::gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw)
{
  Pair<SVector3,SVector3> der = _gf->firstDer(SPoint2(uvw[0],uvw[1]));
  gUvw[0] = gXyz.x() * der.first().x() + gXyz.y() * der.first().y() + gXyz.z() * der.first().z();
  gUvw[1] = gXyz.x() * der.second().x() + gXyz.y() * der.second().y() + gXyz.z() * der.second().z();
}



void ParamCoordSurf::gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
{
  Pair<SVector3,SVector3> der = _gf->firstDer(SPoint2(uvw[0],uvw[1]));
  std::vector<SPoint3>::iterator itUvw=gUvw.begin();
  for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
    (*itUvw)[0] = itXyz->x() * der.first().x() + itXyz->y() * der.first().y() + itXyz->z() * der.first().z();
    (*itUvw)[1] = itXyz->x() * der.second().x() + itXyz->y() * der.second().y() + itXyz->z() * der.second().z();
    itUvw++;
  }
}



SPoint3 ParamCoordParent::getUvw(MVertex* vert)
{

  GEntity *ge = vert->onWhat();
  if ((ge->geomType() == GEntity::DiscreteCurve) || (ge->geomType() == GEntity::DiscreteSurface))
    std::cout << "ERROR: using parent coordinates on discrete curve or surface" << std::endl;

  switch (ge->dim()) {
  case 1: {
    SPoint3 p(0.,0.,0.);
    reparamMeshVertexOnEdge(vert,static_cast<GEdge*>(ge),p[0]);
    return p;
    break;
  }
  case 2: {
    SPoint2 p;
    reparamMeshVertexOnFace(vert,static_cast<GFace*>(ge),p);
    return SPoint3(p[0],p[1],0.);
    break;
  }
  case 3: {
    return vert->point();
    break;
  }
  }

}



SPoint3 ParamCoordParent::uvw2Xyz(MVertex* vert, const SPoint3 &uvw)
{

  GEntity *ge = vert->onWhat();

  switch (ge->dim()) {
  case 1: {
    GPoint gp = static_cast<GEdge*>(ge)->point(uvw[0]);
    return SPoint3(gp.x(),gp.y(),gp.z());
    break;
  }
  case 2: {
    GPoint gp = static_cast<GFace*>(ge)->point(uvw[0],uvw[1]);
    return SPoint3(gp.x(),gp.y(),gp.z());
    break;
  }
  case 3: {
    return uvw;
    break;
  }
  }

}



void ParamCoordParent::gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw)
{

  GEntity *ge = vert->onWhat();

  switch (ge->dim()) {
  case 1: {
    SVector3 der = static_cast<GEdge*>(ge)->firstDer(uvw[0]);
    gUvw[0] = gXyz.x() * der.x() + gXyz.y() * der.y() + gXyz.z() * der.z();
    break;
  }
  case 2: {
    Pair<SVector3,SVector3> der = static_cast<GFace*>(ge)->firstDer(SPoint2(uvw[0],uvw[1]));
    gUvw[0] = gXyz.x() * der.first().x() + gXyz.y() * der.first().y() + gXyz.z() * der.first().z();
    gUvw[1] = gXyz.x() * der.second().x() + gXyz.y() * der.second().y() + gXyz.z() * der.second().z();
    break;
  }
  case 3: {
    gUvw = gXyz;
    break;
  }
  }

}



void ParamCoordParent::gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
{

  GEntity *ge = vert->onWhat();

  switch (ge->dim()) {
  case 1: {
    SVector3 der = static_cast<GEdge*>(ge)->firstDer(uvw[0]);
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      (*itUvw)[0] = itXyz->x() * der.x() + itXyz->y() * der.y() + itXyz->z() * der.z();
      itUvw++;
    }
    break;
  }
  case 2: {
    Pair<SVector3,SVector3> der = static_cast<GFace*>(ge)->firstDer(SPoint2(uvw[0],uvw[1]));
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      (*itUvw)[0] = itXyz->x() * der.first().x() + itXyz->y() * der.first().y() + itXyz->z() * der.first().z();
      (*itUvw)[1] = itXyz->x() * der.second().x() + itXyz->y() * der.second().y() + itXyz->z() * der.second().z();
      itUvw++;
    }
    break;
  }
  case 3: {
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      *itUvw = *itXyz;
      itUvw++;
    }
    break;
  }
  }

}

void ParamCoordParent::exportParamCoord(MVertex *v, const SPoint3 &uvw)
{
  for (int d = 0; d < v->onWhat()->dim(); ++d) {
    v->setParameter(d, uvw[d]);
  }
}
