#include "fourierModel.h"
#include "Message.h"
#include "Context.h"
#include "Views.h"

extern Context_T CTX;

#if defined(HAVE_FOURIER_MODEL)

#include "model.h"
#include "meshGFace.h"

static model *FM = 0;

class meshCartesian{
public:
  void operator() (GFace *gf)
  {  
    int M = (int)(30. / CTX.mesh.lc_factor), N = (int)(30. / CTX.mesh.lc_factor);
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
	MQuadrangle *q = new MQuadrangle(gf->mesh_vertices[i * N + j],
					 gf->mesh_vertices[(i + 1) * N + j],
					 gf->mesh_vertices[(i + 1) * N + (j + 1)],
					 gf->mesh_vertices[i * N + (j + 1)]);
	if(FM->GetOrientation(gf->tag()) < 0) q->revert();
	gf->quadrangles.push_back(q);
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
	  if(pou < 0.51)
	    e->setVisibility(0);
	}
      }
    }
    std::vector<MQuadrangle*> remaining;
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++)
      if(gf->quadrangles[i]->getVisibility()) 
	remaining.push_back(gf->quadrangles[i]);
      else
	delete gf->quadrangles[i];
    gf->quadrangles.clear();
    gf->quadrangles = remaining;
  }
};

void getOrderedBoundaryVertices(std::vector<MElement*> &elements, 
				std::vector<MVertex*> &boundary)
{
  typedef std::pair<MVertex*, MVertex*> vpair;
  std::map<vpair, vpair> edges;
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumEdges(); j++){
      MEdge e = elements[i]->getEdge(j);
      vpair p(e.getMinVertex(), e.getMaxVertex());
      if(edges.count(p)) edges.erase(p);
      else edges[p] = vpair(e.getVertex(0), e.getVertex(1));
    }
  }
  std::map<MVertex*, MVertex*> connect;
  for(std::map<vpair, vpair>::iterator it = edges.begin(); it != edges.end(); it++)
    connect[it->second.first] = it->second.second;
  boundary.push_back(connect.begin()->first);
  for(unsigned int i = 0; i < connect.size(); i++)
    boundary.push_back(connect[boundary[boundary.size() - 1]]);
}

void addElements(GFace *gf, std::vector<MElement*> &elements)
{
  for(unsigned int i = 0; i < gf->triangles.size(); i++)
    elements.push_back(gf->triangles[i]);
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++)
    elements.push_back(gf->quadrangles[i]);
}

bool isConnected(GFace *gf1, GFace *gf2)
{
  std::set<MVertex*> set;
  std::vector<MElement*> elements1, elements2;
  std::vector<MVertex*> boundary1, boundary2;
  addElements(gf1, elements1);
  addElements(gf2, elements2);
  getOrderedBoundaryVertices(elements1, boundary1);
  getOrderedBoundaryVertices(elements2, boundary2);

  for(unsigned int i = 0; i < boundary1.size(); i++)
    set.insert(boundary1[i]);
  for(unsigned int i = 0; i < boundary2.size(); i++){
    std::set<MVertex*>::iterator it = set.find(boundary2[i]);
    if(it != set.end()) return true;
  }
  return false;
}

void getIntersectingBoundaryParts(GFace *gf, std::vector<MElement*> &elements, int &start,
				  std::map<int, std::vector<MVertex*> > &parts)
{
  bool newpart = true;
  std::vector<MVertex*> vertices;
  getOrderedBoundaryVertices(elements, vertices);
  for(unsigned int i = 0; i < vertices.size() - 1; i++){
    MVertex *v = vertices[i];
    SPoint2 uv = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
    if(gf->containsParam(uv)){
      GPoint xyz = gf->point(uv);
      const double tol = 1.e-2; // need to adapt this w.r.t size of model
      if(fabs(xyz.x() - v->x()) < tol && 
	 fabs(xyz.y() - v->y()) < tol && 
	 fabs(xyz.z() - v->z()) < tol){
	if(newpart){
	  start++;
	  newpart = false;
	}
	v->setParameter(0, uv[0]);
	v->setParameter(1, uv[1]);
	parts[start].push_back(v);
      }
      else{
	newpart = true;
      }
    }
    else{
      newpart = true;
    }
  }
}

class createGrout{
public:
  void operator() (GFace *gf)
  {  
    if(gf->tag() > 1) return;
    printf("processing grout for face %d\n", gf->tag());

    GModel *m = gf->model();

    // need to find the disconnected parts in inside too!!!  then
    // we'll pair them with disconnected parts in outside (by looking
    // at the value of the POU)
    // Distinguish 2 cases: 
    // - patch with no hard edges and and no connections: we have a hole
    //   THIS IS WHAT WE ASSUME NOW
    // - patch with hard edges or connections: we don't have a hole, but
    //   we might have non-connected parts
    std::vector<MElement*> elements;

    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
      if(isConnected(gf, *it)){
	printf("face %d: mesh connected to %d\n", gf->tag(), (*it)->tag());
	addElements(*it, elements);
      }
    }
    int numinside = 0;
    std::map<int, std::vector<MVertex*> > inside;
    getIntersectingBoundaryParts(gf, elements, numinside, inside);

    printf("numinside = %d\n", numinside);

    int numoutside = 0;
    std::map<int, std::vector<MVertex*> > outside;
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
      if(!isConnected(gf, *it)){
	elements.clear();
	addElements(*it, elements);
	getIntersectingBoundaryParts(gf, elements, numoutside, outside);
      }
    }

    printf("numoutside = %d\n", numoutside);

    std::vector<MVertex*> hole, loop;
    
    if(numinside == 1){
      // create hole
      SPoint2 ic(0., 0.);
      for(unsigned int i = 0; i < inside[1].size(); i++){
	hole.push_back(inside[1][i]);
	double u, v;
	inside[1][i]->getParameter(0, u);
	inside[1][i]->getParameter(1, v);
	ic += SPoint2(u, v);
      }
      ic *= 1. / (double) inside[1].size(); 
      hole.push_back(hole[0]);

      // order exterior parts
      std::vector<std::pair<double, int> > angle;
      std::map<int, std::vector<MVertex*> >::iterator it = outside.begin();
      for(; it != outside.end(); it++){
	SPoint2 oc(0., 0.);
	for(unsigned int i = 0; i < it->second.size(); i++){
	  double u, v;
	  it->second[i]->getParameter(0, u);
	  it->second[i]->getParameter(1, v);
	  oc += SPoint2(u, v);
	}
	oc *= 1. / (double)it->second.size();
	double a = atan2(oc[1] - ic[1], oc[0] - ic[0]);
	angle.push_back(std::make_pair(a, it->first));
      }
      std::sort(angle.begin(), angle.end());
      
      // create exterior loop
      for(unsigned int i = 0; i < angle.size(); i++){
	for(unsigned int j = 0; j < outside[angle[i].second].size(); j++)
	  loop.push_back(outside[angle[i].second][j]);
      }
      loop.push_back(hole[0]);

      // mesh the grout
      fourierFace *grout = new fourierFace(gf, loop, hole);
      meshGFace mesh; 
      mesh(grout);
      for(unsigned int i = 0; i < grout->triangles.size(); i++)
	gf->triangles.push_back(grout->triangles[i]);
      for(unsigned int i = 0; i < grout->mesh_vertices.size(); i++)
	gf->mesh_vertices.push_back(grout->mesh_vertices[i]);
      delete grout;
    }
    else{

      Msg(WARNING, "Faces with no holes not implemented yet!");

    }

    // debug
    char name[256];
    sprintf(name, "aa%d.pos", gf->tag());
    FILE *fp = fopen(name, "w");
    fprintf(fp, "View \"aa\"{\n");
    for(unsigned int i = 0; i < hole.size(); i++){
      double x = hole[i]->x(), y = hole[i]->y(), z = hole[i]->z();
      // plot in parametric space:
      hole[i]->getParameter(0, x); hole[i]->getParameter(1, y); z = 0;
      fprintf(fp, "SP(%g,%g,%g){0};\n", x, y, z);
    }
    for(unsigned int i = 0; i < loop.size(); i++){
      double x = loop[i]->x(), y = loop[i]->y(), z = loop[i]->z();
      // plot in parametric space:
      loop[i]->getParameter(0, x); loop[i]->getParameter(1, y); z = 0;
      fprintf(fp, "SP(%g,%g,%g){%d};\n", x, y, z, i);
    }
    fprintf(fp, "};\n");    
    fclose(fp);
  }
};

class exportFourierFace{
public:
  void operator() (GFace *gf)
  {  
    Post_View *view = BeginView(1);
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
      MElement *e = gf->quadrangles[i];
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
    std::vector<MElement*> elements;
    std::vector<MVertex*> vertices;
    addElements(gf, elements);
    getOrderedBoundaryVertices(elements, vertices);
    for(unsigned int i = 0; i < vertices.size() - 1; i++){
      double x[2] = {vertices[i]->x(), vertices[i + 1]->x()};
      double y[2] = {vertices[i]->y(), vertices[i + 1]->y()};
      double z[2] = {vertices[i]->z(), vertices[i + 1]->z()};
      double val[2] = {10, 10};
      for(int j = 0; j < 2; j++) List_Add(view->SL, &x[j]);
      for(int j = 0; j < 2; j++) List_Add(view->SL, &y[j]);
      for(int j = 0; j < 2; j++) List_Add(view->SL, &z[j]);
      for(int j = 0; j < 2; j++) List_Add(view->SL, &val[j]);
      view->NbSL++;
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

  // mesh each face with quads
  std::for_each(firstFace(), lastFace(), meshCartesian());

  // compute partition of unity
  std::for_each(firstFace(), lastFace(), computePartitionOfUnity());

  // create grooves
  std::for_each(firstFace(), lastFace(), createGrooves());
  
  // create grout
  std::for_each(firstFace(), lastFace(), createGrout());

  // visualize as a post-pro view
  //std::for_each(firstFace(), lastFace(), exportFourierFace());

  CTX.mesh.changed = ENT_ALL;
}


fourierModel::~fourierModel()
{
  delete FM;
  FM = 0;
}

fourierEdge::fourierEdge(GModel *model, int num, GVertex *v1, GVertex *v2)
  : GEdge(model, num, v1, v2)
{
}

fourierFace::fourierFace(GModel *m, int num)
  : GFace(m, num)
{
  for(int i = 0; i < 4; i++){ _v[i] = 0; _e[i] = 0; }
  _discrete = 1;
}

fourierFace::fourierFace(GFace *f, std::vector<MVertex*> &loop, std::vector<MVertex*> &hole)
  : GFace(f->model(), f->tag())
{
  for(int i = 0; i < 4; i++){ _v[i] = 0; _e[i] = 0; }
  _discrete = 0;

  if(!loop.size()){
    Msg(GERROR, "No vertices in exterior loop");
    return; 
  }
  
  _v[0] = new fourierVertex(f->model(), loop[0]);
  _v[1] = new fourierVertex(f->model(), loop[loop.size() - 2]);
  _e[0] = new fourierEdge(f->model(), 1, _v[0], _v[1]);
  _e[0]->addFace(this);
  _e[1] = new fourierEdge(f->model(), 2, _v[1], _v[0]);
  _e[1]->addFace(this);
  for(unsigned int i = 1; i < loop.size() - 2; i++)
    _e[0]->mesh_vertices.push_back(loop[i]);

  l_edges.push_back(_e[0]); l_dirs.push_back(1);
  l_edges.push_back(_e[1]); l_dirs.push_back(1);

  if(hole.size()){
    _v[2] = new fourierVertex(f->model(), hole[0]);
    _v[3] = new fourierVertex(f->model(), hole[hole.size() - 2]);
    _e[2] = new fourierEdge(f->model(), 3, _v[2], _v[3]);
    _e[2]->addFace(this);
    _e[3] = new fourierEdge(f->model(), 4, _v[3], _v[2]);
    _e[3]->addFace(this);
    for(unsigned int i = 1; i < hole.size() - 2; i++)
      _e[2]->mesh_vertices.push_back(hole[i]);

    l_edges.push_back(_e[2]); l_dirs.push_back(1);
    l_edges.push_back(_e[3]); l_dirs.push_back(1);
  }
}

fourierFace::~fourierFace()
{
  if(!_discrete){
    // this face was just used temporarily for meshing, so don't
    // delete the mesh vertices or the mesh elements: they have been
    // transferred elsewhere
    for(int i = 0; i < 4; i++){ 
      if(_e[i]){
	_e[i]->mesh_vertices.clear();
	delete _e[i];
      }
    }
    for(int i = 0; i < 4; i++){ 
      if(_v[i]){
	_v[i]->mesh_vertices.clear();
	delete _v[i];
      }
    }
    triangles.clear();
    quadrangles.clear();
    mesh_vertices.clear();
    l_edges.clear();
  }
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
  return _discrete ? GEntity::DiscreteSurface : GEntity::Unknown;
}

SPoint2 fourierFace::parFromPoint(const SPoint3 &p) const
{
  double u, v;
  FM->GetParamFromPoint(tag(), p.x(), p.y(), p.z(), u, v);
  return SPoint2(u, v);
}

#endif
