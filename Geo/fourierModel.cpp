#include "fourierModel.h"
#include "Message.h"
#include "Context.h"
#include "Views.h"

extern Context_T CTX;

#if defined(HAVE_FOURIER_MODEL)

#include "model.h"

static model *FM = 0;

class meshFourierFace{
public:
  void operator() (GFace *gf)
  {  
    int M = 30, N = 30;
    for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
	double u = i/(double)(M - 1);
	double v = j/(double)(N - 1);
	GPoint p = gf->point(u, v);
	double pou;
	FM->GetPou(gf->tag(), u, v, pou);
	gf->mesh_vertices.push_back
	  (new MDataFaceVertex<double>(p.x(), p.y(), p.z(), gf, u, v, pou));
      }
    }
    for(int i = 0; i < M - 1; i++){
      for(int j = 0; j < N - 1; j++){
	gf->quadrangles.push_back(new MQuadrangle(gf->mesh_vertices[i * N + j],
						  gf->mesh_vertices[i * N + (j + 1)],
						  gf->mesh_vertices[(i + 1) * N + (j + 1)],
						  gf->mesh_vertices[(i + 1) * N + j]));
      }
    }
  }
};

class computePartitionOfUnity{
public:
  void operator() (GFace *gf)
  {  
    // we only normalize the partition of unity amongst patches that
    // overlap; we don't normalize across hard edges
    std::vector<int> overlaps;
    FM->GetNeighbor(gf->tag(), overlaps);
    for(unsigned int i = 0; i < gf->mesh_vertices.size(); i++){
      MVertex *v = gf->mesh_vertices[i];
      std::vector<std::pair<GFace*, SPoint2> > param;
      for(unsigned int j = 0; j < overlaps.size(); j++){
	GFace *gf2 = gf->model()->faceByTag(overlaps[j]);
	SPoint2 uv2 = gf2->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
	if(gf2->containsParam(uv2)){
	  GPoint xyz2 = gf2->point(uv2);
	  const double tol = 1.e-2; // need to adapt this w.r.t size of model
	  if(fabs(xyz2.x() - v->x()) < tol && 
	     fabs(xyz2.y() - v->y()) < tol && 
	     fabs(xyz2.z() - v->z()) < tol)
	    param.push_back(std::pair<GFace*, SPoint2>(gf2, uv2));
	}
      }
      if(param.empty()){
      	Msg(GERROR, "Vertex %d does not belong to any patch", v->getNum());
      }
      else{
	double allPou = 0.;
	for(unsigned int i = 0; i < param.size(); i++){
	  double u2 = param[i].second[0], v2 = param[i].second[1];
	  double pou2;
	  FM->GetPou(param[i].first->tag(), u2, v2, pou2);
	  allPou += pou2;
	}
	if(v->getData()){
	  double *pou = (double*)v->getData();
	  *pou = *pou / allPou;
	}
	else{
	  Msg(GERROR, "Vertex %d has no POU data", v->getNum());
	}
      }
    }
  }
};

class createGrooves{
public:
  void operator() (GFace *gf)
  {  
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
      MElement *e = gf->quadrangles[i];
      for(int j = 0; j < e->getNumVertices(); j++){
	void *data = e->getVertex(j)->getData();
	if(data){
	  double pou = *(double*)data;
	  if(pou < 0.51) e->setVisibility(0);
	}
      }
    }
  }
};

class createGrout{
public:
  void operator() (GFace *gf)
  {  
    printf("processing grout for face %d\n", gf->tag());

    std::vector<int> overlaps;
    FM->GetNeighbor(gf->tag(), overlaps);

    for(unsigned int j = 0; j < overlaps.size(); j++){
      GFace *gf2 = gf->model()->faceByTag(overlaps[j]);
      if(gf != gf2){
	
	
      }

    }
    
  }
};

class exportFourierFace{
public:
  void operator() (GFace *gf)
  {  
    Post_View *view = BeginView(1);
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
      MElement *e = gf->quadrangles[i];
      //if(!e->getVisibility()) continue;
      double x[4], y[4], z[4], val[4];
      for(int j = 0; j < 4; j++){
	MVertex *v = e->getVertex(j);
	x[j] = v->x();
	y[j] = v->y();
	z[j] = v->z();
	val[j] = *(double*)v->getData();
      }
      for(int j = 0; j < 4; j++) List_Add(view->SQ, &x[j]);
      for(int j = 0; j < 4; j++) List_Add(view->SQ, &y[j]);
      for(int j = 0; j < 4; j++) List_Add(view->SQ, &z[j]);
      for(int j = 0; j < 4; j++) List_Add(view->SQ, &val[j]);
      view->NbSQ++;
    }
    char name[1024], filename[1024];
    sprintf(name, "patch%d", gf->tag());
    sprintf(filename, "patch%d", gf->tag());
    EndView(view, 1, filename, name);
  }
};


fourierModel::fourierModel(const std::string &name)
  : GModel(name)
{
  FM = new model(name);
  
  Msg(INFO, "Fourier model created: %d patches", FM->GetNumPatches());

  // create one face per patch
  for(int i = 0; i < FM->GetNumPatches(); i++)
    add(new fourierFace(this, i));

  // mesh each face
  std::for_each(firstFace(), lastFace(), meshFourierFace());

  // compute partition of unity
  std::for_each(firstFace(), lastFace(), computePartitionOfUnity());

  // create grooves
  std::for_each(firstFace(), lastFace(), createGrooves());
  
  // create grout
  std::for_each(firstFace(), lastFace(), createGrout());

  // visualize as a post-pro view
  std::for_each(firstFace(), lastFace(), exportFourierFace());

  CTX.mesh.changed = ENT_ALL;
}


fourierModel::~fourierModel()
{
  delete FM;
  FM = 0;
}

fourierFace::fourierFace(GModel *m, int num)
  : GFace(m, num)
{
}

Range<double> fourierFace::parBounds(int i) const
{
  double min, max;
  FM->GetParamBounds(tag(), i, min, max);
  return Range<double>(min, max);
}
  
GPoint fourierFace::point(double par1, double par2) const
{
  double x, y, z;
  FM->GetPoint(tag(), par1, par2, x, y, z);
  return GPoint(x, y, z);
}

GPoint fourierFace::point(const SPoint2 &pt) const
{
  return point(pt[0], pt[1]);
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
  double umin, umax, vmin, vmax;
  FM->GetParamBounds(tag(), 0, umin, umax);
  FM->GetParamBounds(tag(), 1, vmin, vmax);
  const double tol = 1.e-6;
  if(pt[0] < umin - tol || pt[0] > umax + tol) return 0;
  if(pt[1] < vmin - tol || pt[1] > vmax + tol) return 0;
  return 1;
}
  
SVector3 fourierFace::normal(const SPoint2 &param) const
{
  throw;
}

GEntity::GeomType fourierFace::geomType() const
{
  return GEntity::DiscreteSurface;
}

SPoint2 fourierFace::parFromPoint(const SPoint3 &p) const
{
  double u, v;
  FM->GetParamFromPoint(tag(), p.x(), p.y(), p.z(), u, v);
  return SPoint2(u, v);
}

#endif
