#include "fourierModel.h"
#include "Message.h"

#if defined(HAVE_FOURIER_MODEL)

#include "model.h"

static model *FM = 0;

fourierModel::fourierModel(const std::string &name)
  : GModel(name)
{
  FM = new model(name);
  
  Msg(INFO, "Fourier model created: %d patches", FM->GetNumPatches());

  for(int i = 0; i < FM->GetNumPatches(); i++)
    add(new fourierFace(this, i));
}

fourierModel::~fourierModel()
{
  delete FM;
  FM = 0;
}

fourierFace::fourierFace(GModel *m, int num)
  : GFace(m, num)
{
  int M = 30, N = 30;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      GPoint p = point(i/(double)(M - 1), j/(double)(N - 1));
      mesh_vertices.push_back(new MVertex(p.x(), p.y(), p.z(), this));
    }
  }
  for(int i = 0; i < M - 1; i++){
    for(int j = 0; j < N - 1; j++){
      quadrangles.push_back(new MQuadrangle(mesh_vertices[i * M + j],
					    mesh_vertices[i * M + (j + 1)],
					    mesh_vertices[(i + 1) * M + (j + 1)],
					    mesh_vertices[(i + 1) * M + j]));
    }
  }
}

Range<double> fourierFace::parBounds(int i) const
{
  return Range<double>(0., 1.);
}
  
GPoint fourierFace::point(double par1, double par2) const
{
  double x, y, z;
  FM->GetPoint(tag(), par1, par2, x, y, z);
  return GPoint(x, y, z);
}

GPoint fourierFace::point(const SPoint2 &pt) const
{
  throw;
}

GPoint fourierFace::closestPoint(const SPoint3 & queryPoint)
{
  throw;
}
  
int fourierFace::containsPoint(const SPoint3 &pt) const
{
  throw;
}

int fourierFace::containsParam(const SPoint2 &pt) const
{
  throw;
}
  
SVector3 fourierFace::normal(const SPoint2 &param) const
{
  throw;
}

GEntity::GeomType fourierFace::geomType() const
{
  return GEntity::DiscreteSurface;
}

SPoint2 fourierFace::parFromPoint(const SPoint3 &) const
{
  throw;
}

#endif
