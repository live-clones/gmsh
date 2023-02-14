#include "GmshConfig.h"

#if defined(HAVE_MESH)

#include "meshTriangulation.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertexRTree.h"

#include "/Users/geuzaine/src/gmsh/contrib/geodesic_matlab/src/geodesic_mesh.h"
#include "/Users/geuzaine/src/gmsh/contrib/geodesic_matlab/src/geodesic_algorithm_exact.h"

static  PolyMesh* createPolyMesh (GModel *gm, std::map<MVertex*, int> &trianglePositions) {
  const double eps = 1.e-8; //FIXME
  MVertexRTree pos(eps);
  PolyMesh *pm = new PolyMesh;

  int counter = 0;
  for (GModel::fiter fit = gm->firstFace() ; fit != gm->lastFace(); fit++){
    discreteFace *df = static_cast<discreteFace*>(*fit);
    if (!df) continue;
    for(std::size_t i = 0; i < df->_param.v3d.size(); i++)
      df->_param.v3d[i].setIndex(-1);
  }

  size_t faceCounter = 0;

  for (GModel::fiter fit = gm->firstFace() ; fit != gm->lastFace(); fit++){

    std::set<MVertex*> vs;
    for (auto t : (*fit)->triangles){
      vs.insert(t->getVertex(0));
      vs.insert(t->getVertex(1));
      vs.insert(t->getVertex(2));
    }
    discreteFace *df = static_cast<discreteFace*>(*fit);
    //-------------------------------------------------------------
    for (auto _v : vs){
      MFaceVertex *vk = dynamic_cast<MFaceVertex*> (_v);
      if (vk){
	double u,v,uloc,vloc;
	vk->getParameter(0,u);
	vk->getParameter(1,v);
	int tp = df->trianglePosition(u,v, uloc, vloc);
	//	printf("face %d vertex %d param %g %g triangle position %d parametric ? %d\n",
	//	       df->tag(),vk->getNum(),u,v,tp,vk->getParameter(0,u));
	trianglePositions[vk] = tp + faceCounter;
      }
      MEdgeVertex *ve = dynamic_cast<MEdgeVertex*> (_v);
      if (ve){
	GEdge *ge = dynamic_cast<GEdge*> (ve->onWhat());
	if (ge){
	  double epar;
	  ve->getParameter(0,epar);
	  SPoint2 p2 = ge->reparamOnFace(df, epar, 0);
	  double uloc,vloc;
	  int tp = df->trianglePosition(p2.x(),p2.y(), uloc, vloc);
	  trianglePositions[vk] = tp + faceCounter;
	}
      }
    }
    //-------------------------------------------------------------
    for(std::size_t i = 0; i < df->_param.t3d.size(); i++){
      for(std::size_t j = 0; j < 3; j++){
	MVertex *vv = pos.insert(df->_param.t3d[i].getVertex(j));
	if (!vv) vv = df->_param.t3d[i].getVertex(j);
	else df->_param.t3d[i].getVertex(j)->setIndex(vv->getIndex());
	//	else   printf("FOUND face %d t %lu v %lu %p\n",df->tag(),i,j,vv);
	if (vv->getIndex() == -1){
	  pm->vertices.push_back(new PolyMesh::Vertex(vv->x(), vv->y(), vv->z(), counter));
	  vv->setIndex(counter++);
	}
      }
    }
    faceCounter += df->_param.t3d.size();
  }

  for (GModel::fiter fit = gm->firstFace() ; fit != gm->lastFace(); fit++){
    discreteFace *df = static_cast<discreteFace*>(*fit);
    if (!df) continue;
    for(std::size_t i = 0; i < df->_param.t3d.size(); i++){
      PolyMesh::HalfEdge *he[3];
      for(std::size_t j = 0; j < 3; j++){
	PolyMesh::Vertex *vv = pm->vertices[df->_param.t3d[i].getVertex(j)->getIndex()];
	he[j] = new PolyMesh::HalfEdge(vv);
	pm->hedges.push_back(he[j]);
	vv->he = he[j];
      }
      PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
      pm->faces.push_back(ff);
      for(int j = 0; j < 3; j++) {
	he[j]->next = he[(j + 1) % 3];
	he[j]->prev = he[(j - 1 + 3) % 3];
	he[j]->f = ff;
      }
    }
  }

  HalfEdgePtrLessThan compare;
  std::sort(pm->hedges.begin(), pm->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(int i = 0; i < pm->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = pm->hedges[i];
    PolyMesh::HalfEdge *h1 = pm->hedges[i + 1];
    if(equal(h0, h1)) {
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
    }
  }

  return pm;
}

static PolyMesh* createPolyMesh (discreteFace *df) {
  const double eps = 1.e-8; //FIXME
  MVertexRTree pos(eps);

  PolyMesh *pm = new PolyMesh;

  //  printf("setting %lu indices to -1\n",df->_param.v3d.size());
  for(std::size_t i = 0; i < df->_param.v3d.size(); i++)
    df->_param.v3d[i].setIndex(-1);

  printf("unifyning %lu vertices\n",df->_param.v3d.size());
  int counter = 0;
  for(std::size_t i = 0; i < df->_param.t3d.size(); i++){
    for(std::size_t j = 0; j < 3; j++){
      MVertex *vv = pos.insert(df->_param.t3d[i].getVertex(j));
      if (!vv) vv = df->_param.t3d[i].getVertex(j);
      //      printf("%lu %lu %p\n",i,j,vv);
      if (vv->getIndex() == -1){
	pm->vertices.push_back(new PolyMesh::Vertex(vv->x(), vv->y(), vv->z(), counter));
	vv->setIndex(counter++);
      }
    }
  }
  //  printf("%lu vertices unified\n",pm->vertices.size());

  for(std::size_t i = 0; i < df->_param.t3d.size(); i++){
    PolyMesh::HalfEdge *he[3];
    for(std::size_t j = 0; j < 3; j++){
      PolyMesh::Vertex *vv = pm->vertices[df->_param.t3d[i].getVertex(j)->getIndex()];
      he[j] = new PolyMesh::HalfEdge(vv);
      pm->hedges.push_back(he[j]);
      vv->he = he[j];
    }
    PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
    pm->faces.push_back(ff);
    for(int j = 0; j < 3; j++) {
      he[j]->next = he[(j + 1) % 3];
      he[j]->prev = he[(j - 1 + 3) % 3];
      he[j]->f = ff;
    }
  }
  //  printf("%lu faces created\n",pm->faces.size());

  HalfEdgePtrLessThan compare;
  std::sort(pm->hedges.begin(), pm->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(size_t i = 0; i < pm->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = pm->hedges[i];
    PolyMesh::HalfEdge *h1 = pm->hedges[i + 1];
    if(equal(h0, h1)) {
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
    }
  }

  return pm;

}

static PolyMesh::VertexOnFace findVertexOnFace (PolyMesh *pm, MVertex *v, int pos){
  SVector3 P(v->x(), v->y(), v->z());
  PolyMesh::VertexOnFace vof;
  double minvol = 1.e22,_u = 1.e22,_v = 1.e22;
  const double eps = 1.e-8;
  vof.he = nullptr;

  int n = 0;
  size_t SIZE = pm->faces.size();
  if (pos < 0)pos = 0;
  //  pos = 0;
  for (size_t cc = 0 ; cc < SIZE ; cc ++){
    PolyMesh::Face *f = pm->faces[(cc+pos)%SIZE];
    auto he = f->he;
    auto v0 = he->v;
    auto v1 = he->next->v;
    auto v2 = he->next->next->v;
    auto d1 = v1->position - v0->position;
    auto d2 = v2->position - v0->position;
    auto d = P - v0->position;
    auto pv12 = crossprod(d1,d2);
    double vol = dot(pv12,d);
    minvol = std::min(minvol,fabs(vol));
    if (fabs(vol) < eps){
      double surf = pv12.norm();
      auto pv1 = crossprod(d,d1);
      auto pv2 = crossprod(d,d2);
      double surf1 = pv1.norm();
      double surf2 = pv2.norm();
      _u = surf2 / surf;
      _v = surf1 / surf;
      double x = (1-_u-_v)*v0->position.x()+_u*v1->position.x()+_v*v2->position.x();
      double y = (1-_u-_v)*v0->position.y()+_u*v1->position.y()+_v*v2->position.y();
      double z = (1-_u-_v)*v0->position.z()+_u*v1->position.z()+_v*v2->position.z();
      if (_u >= -eps && _v >= -eps && 1-_u-_v >= -eps){
	//	printf("found an element that is coplanar with point P(%g,%g,%g) uv(%g,%g) P'(%g,%g,%g)\n",
	//	       v->x(), v->y(), v->z(), _u, _v , x, y, z);
	double dd = sqrt((x-v->x())*(x-v->x())+
			 (y-v->y())*(y-v->y())+
			 (z-v->z())*(z-v->z()));
	if (dd < eps){
	  vof.he = he;
	  vof.u = _u;
	  vof.v = _v;
	  n++;
	  //	  printf("vertex %d after %d searches\n",v->getNum(),cc);
	  if (he)return vof;
	}
      }
    }
  }
  //  vof.he = nullptr;
  //  vof.u = 0;
  //  vof.v = 0;
  if (n < 1) printf("N %d MINVOL = %22.15E u = %22.15E v = %22.15E w = %22.15E\n",n,minvol,vof.u,vof.v,1.-vof.u-vof.v);
  return vof;

}


static void exactGeodesics (const PolyMesh::VertexOnFace &_start,
			    std::vector<PolyMesh::VertexOnFace> &incident_edges,
			    geodesic::Mesh &mesh, std::map<PolyMesh::Face*,int> &f2n,
			    int save_, FILE *f,
			    std::vector<std::vector<geodesic::SurfacePoint> > &paths){

  SVector3 p_start = _start.point();

  geodesic::SurfacePoint sp (&mesh.faces()[f2n[_start.he->f]],p_start.x(), p_start.y(), p_start.z(),geodesic::FACE);
  std::vector<geodesic::SurfacePoint> pts = {sp};

  std::vector<geodesic::SurfacePoint> _stop ;
  for (auto v : incident_edges){
    SVector3 p_end = v.point();
    geodesic::SurfacePoint spe (&mesh.faces()[f2n[v.he->f]],p_end.x(), p_end.y(), p_end.z(),geodesic::FACE);
    _stop.push_back(spe);
  }

  geodesic::GeodesicAlgorithmExact algorithm(&mesh);
  algorithm.propagate(pts,0,&_stop);

  //  printf("Vertex with %lu incident edges\n",incident_edges.size());

  for (auto v : incident_edges){
    SVector3 p_end = v.point();
    geodesic::SurfacePoint spe (&mesh.faces()[f2n[v.he->f]],p_end.x(), p_end.y(), p_end.z(),geodesic::FACE);
    std::vector<geodesic::SurfacePoint> path;
    algorithm.trace_back(spe, path);
    if (path.size() > 1){
      for (size_t i = 0; i< path.size()-1;i++){
	fprintf(f,"SL(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E){%d,%d};\n",
		path[i].x(),path[i].y(),path[i].z(),
		path[i+1].x(),path[i+1].y(),path[i+1].z(),_start.he->v->data,_start.he->v->data);
      }
    }
    else{
      Msg::Error("Impossible to trace back -- ");
    }
    paths.push_back(path);
  }
}

static void createGmshDiscreteEdgeRepresentation ( MEdge &ed ,
						   std::vector<geodesic::SurfacePoint>  &path)
{
  printf("edge %lu %lu : ",ed.getVertex(0)->getNum(),ed.getVertex(1)->getNum());
  for (auto sp : path){
    auto m_p = sp.base_element();
    auto point_type = m_p->type();
    if (point_type == geodesic::VERTEX){
      printf("v ");
    }
    else if (point_type == geodesic::EDGE){
      printf("e ");
    }
    else if (point_type == geodesic::FACE){
      printf("f ");
    }
  }
  printf("\n");
}




int makeMeshGeodesic (PolyMesh *pm, std::set<MEdge,MEdgeLessThan> &ed, int tag,
		      //		      std::map<MEdge,
		      std::map<MVertex*, int> *trianglePositions = nullptr){

  char name [245];
  sprintf(name,"Geodesics.pos");
  FILE *f = fopen (name, "w");
  fprintf(f,"View \"Geodesics\" {\n");


  std::map<PolyMesh::Vertex*,double> gc;
  std::map<PolyMesh::Vertex*,double> num;
  for (auto v : pm->vertices){
    gc[v] = v->gaussianCurvature();
    num[v] = v->data;
  }
  print__ ("GaussianCurvature.pos", pm, gc);
  print__ ("Num.pos", pm, num);

  geodesic::Mesh mesh;
  std::map<PolyMesh::Face*,int> f2n;
  {
    std::vector<double> _points;
    std::vector<unsigned> _faces;
    int num = 0;
    for (auto v : pm->vertices){
      _points.push_back(v->position.x());
      _points.push_back(v->position.y());
      _points.push_back(v->position.z());
      v->data = num++;
    }
    int nnn = 0;
    for (auto f : pm->faces){
      _faces.push_back(f->he->v->data);
      _faces.push_back(f->he->next->v->data);
      _faces.push_back(f->he->next->next->v->data);
      f2n[f] = nnn++;
    }
    mesh.initialize_mesh_data(_points, _faces);
  }

  //  double D = 0.0;
  PolyMesh::VertexOnFace _start;
  int counter = 0;

  std::vector<MEdge> tmp;
  tmp.insert(tmp.begin(),ed.begin(),ed.end());

  std::map<MVertex*,PolyMesh::VertexOnFace> v2p;
  for (size_t i=0 ; i<tmp.size() ; i++){
    MVertex *v0 = tmp[i].getMinVertex();
    MVertex *v1 = tmp[i].getMaxVertex();
    std::map<MVertex*,PolyMesh::VertexOnFace>::iterator it = v2p.find(v0);
    int pos0 = -1, pos1 = -1;
    if (trianglePositions){
      auto it0 = trianglePositions->find(v0);
      if (it0 != trianglePositions->end())pos0 = it0->second;
      auto it1 = trianglePositions->find(v1);
      if (it1 != trianglePositions->end())pos1 = it1->second;
    }
    if (it == v2p.end())v2p[v0] =  findVertexOnFace (pm, v0, pos0);
    it = v2p.find(v1);
    if (it == v2p.end())v2p[v1] =  findVertexOnFace (pm, v1, pos1);
  }

  Msg::Info("found all %lu vertices",tmp.size());

  std::vector<PolyMesh::VertexOnFace> _ends;
  std::vector<MEdge> _endsGmsh;
  std::map<MEdge, std::vector<geodesic::SurfacePoint>, MEdgeLessThan> edgeRepresentation;


  for (size_t i=0 ; i<tmp.size() ; i++){
    MVertex *v0 = tmp[i].getMinVertex();
    MVertex *v1 = tmp[i].getMaxVertex();
    //    printf("%d --> %d\n",v0->getNum(),v1->getNum());
    PolyMesh::VertexOnFace  _end = v2p[v1];
    //    D = std::max(16*v0->distance(v1),D);

    if (i == 0){
      _start = v2p[v0];
      if (_end.he){
	_endsGmsh.push_back(tmp[i]);
	_ends.push_back(_end);
      }
      else
	Msg::Error ("cannot find a vertex");
    }
    else if (i > 0 && v0 == tmp[i-1].getMinVertex()){
      if (_end.he){
	_ends.push_back(_end);
	_endsGmsh.push_back(tmp[i]);
      }
      else
	Msg::Error ("cannot find a vertex");
    }
    else {
      if (_start.he){
	std::vector<std::vector<geodesic::SurfacePoint> > paths;
	exactGeodesics (_start, _ends, mesh, f2n, counter++, f, paths);
	for (size_t kk = 0 ; kk < paths.size() ; kk++){
          if(kk < _endsGmsh.size()) {
            MEdge me = _endsGmsh[kk];
            edgeRepresentation [me] = paths[kk];
            createGmshDiscreteEdgeRepresentation (me,paths[kk]);
          }
          else{
            printf("oups\n");
          }
	}
      }
      _ends.clear();
      _endsGmsh.clear();
      if (_end.he)
	_ends.push_back(_end);
      else
	Msg::Error ("cannot find a vertex");
      _start = v2p[v0];
      //      D = 0.0;
    }
  }

  std::vector<std::vector<geodesic::SurfacePoint> > paths;
  exactGeodesics (_start, _ends, mesh, f2n, counter++, f, paths);
  for (size_t kk = 0 ; kk < paths.size() ; kk++){
    MEdge me = _endsGmsh[kk];
    createGmshDiscreteEdgeRepresentation (me,paths[kk]);
    edgeRepresentation [me] = paths[kk];
  }

  fprintf(f,"};\n");
  fclose(f);
  return 0;
}

int makeMeshGeodesic (GFace *gf) {

  discreteFace *df = static_cast<discreteFace *> (gf);
  if (!df)return -1;
  // FIXME
  //  if (df->tag() != 4)return -1;

  printf("creating polymesh for face %d\n",gf->tag());

  PolyMesh *pm = createPolyMesh (df);

  std::set<MEdge,MEdgeLessThan> ed;
  for (auto t : gf->triangles){
    ed.insert(t->getEdge(0));
    ed.insert(t->getEdge(1));
    ed.insert(t->getEdge(2));
  }

  makeMeshGeodesic (pm, ed, df->tag());

  delete pm;
  return 0;
}


int makeMeshGeodesic (GModel *gm) {
  std::map<MVertex*, int> trianglePositions;
  PolyMesh *pm = createPolyMesh (gm,trianglePositions);
  std::set<MEdge,MEdgeLessThan> ed;
  for (GModel::fiter fit = gm->firstFace() ; fit != gm->lastFace(); fit++){
    discreteFace *df = static_cast<discreteFace *> (*fit);
    if (!df) continue;
    for (auto t : df->triangles){
      ed.insert(t->getEdge(0));
      ed.insert(t->getEdge(1));
      ed.insert(t->getEdge(2));
    }
  }
  printf("all done %lu edges\n",ed.size());
  makeMeshGeodesic (pm, ed, 1, &trianglePositions);
  delete pm;
  return 0;
}


#endif
