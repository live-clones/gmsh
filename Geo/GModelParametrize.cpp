// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "GFace.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "GEdge.h"
#include "MLine.h"
#include "Context.h"
#include "GmshMessage.h"
#include "GModelParametrize.h"

#if defined(HAVE_MESH)
#include "meshPartition.h"
#endif

#if defined(HAVE_HXT)
extern "C" {
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_mean_values.h"
}
#endif

#if defined(HAVE_HXT)
static HXTStatus gmsh2hxt(int tag, const std::vector<MTriangle*> &t,
			  HXTMesh **pm,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *m;
  HXT_CHECK(hxtMeshCreate(context, &m));
  std::set<MVertex *> all;
  for(size_t i = 0; i < t.size(); i++) {
    all.insert(t[i]->getVertex(0));
    all.insert(t[i]->getVertex(1));
    all.insert(t[i]->getVertex(2));
  }
  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
    m->vertices.coord[4 * count + 0] = (*it)->x();
    m->vertices.coord[4 * count + 1] = (*it)->y();
    m->vertices.coord[4 * count + 2] = (*it)->z();
    m->vertices.coord[4 * count + 3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->triangles.num = m->triangles.size = t.size();
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.colors,
                             (m->triangles.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < t.size(); i++) {
    m->triangles.node[3 * i + 0] = v2c[t[i]->getVertex(0)];
    m->triangles.node[3 * i + 1] = v2c[t[i]->getVertex(1)];
    m->triangles.node[3 * i + 2] = v2c[t[i]->getVertex(2)];
    m->triangles.colors[i] = tag;
  }

  m->lines.num = m->lines.size = 0;

  *pm = m;
  return HXT_STATUS_OK;
}

static HXTStatus gmsh2hxt(GFace *gf, HXTMesh **pm,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  return gmsh2hxt (gf->tag(), gf->triangles, pm, v2c,c2v);
}

#endif

int computeDiscreteCurvatures(
  GModel *gm, std::map<MVertex *, std::pair<SVector3, SVector3> > &C)
{
#if defined(HAVE_HXT)
  C.clear();
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    HXTMesh *m;
    HXTEdges *edges;
    double *nodalCurvatures;
    double *crossField;
    std::map<MVertex *, int> v2c;
    std::vector<MVertex *> c2v;
    gmsh2hxt(*it, &m, v2c, c2v);
    HXT_CHECK(hxtEdgesCreate(m, &edges));
    HXT_CHECK(
      hxtCurvatureRusinkiewicz(m, &nodalCurvatures, &crossField, edges, false));
    for(size_t i = 0; i < m->vertices.num; i++) {
      MVertex *v = c2v[i];
      double *c = &nodalCurvatures[6 * i];
      SVector3 cMax(c[0], c[1], c[2]);
      SVector3 cMin(c[3], c[4], c[5]);
      std::pair<SVector3, SVector3> out = std::make_pair(cMax, cMin);
      C.insert(std::make_pair(v, out));
    }
    HXT_CHECK(hxtEdgesDelete(&edges));
    HXT_CHECK(hxtFree(&nodalCurvatures));
    HXT_CHECK(hxtFree(&crossField));
    HXT_CHECK(hxtMeshDelete(&m));
  }
#endif
  return 0;
}

void parametrizeAllGEdge(GModel *gm)
{
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    discreteEdge *de = dynamic_cast<discreteEdge *>(*it);
    if(de) de->createGeometry();
  }
}

int parametrizeAllGFace(GModel *gm,
                        std::map<MVertex *, std::pair<SVector3, SVector3> > *C)
{
  int result = 0;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    discreteFace *df = dynamic_cast<discreteFace *>(*it);
    if(df) result += parametrizeGFace(df, C);
  }
  return result;
}

int parametrizeGFace(discreteFace *gf,
                     std::map<MVertex *, std::pair<SVector3, SVector3> > *C)
{
#if defined(HAVE_HXT)
  int n = 1;
  if(gf->triangles.empty()) return 0;
  HXT_CHECK(hxtInitializeLinearSystems(&n, NULL));
  HXTMesh *m;
  HXTMeanValues *param;
  HXTEdges *edges;
  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;
  gmsh2hxt(gf, &m, v2c, c2v);
  //  double *nodalCurvatures;
  //  double *crossField;
  //  printf("A %d triangles\n",m->triangles.num);
  HXT_CHECK(hxtEdgesCreate(m, &edges));
  HXT_CHECK(hxtMeanValuesCreate(edges, &param));
  HXT_CHECK(hxtMeanValuesCompute(param));
  double *uvc = NULL;
  int nv, ne;
  HXT_CHECK(hxtMeanValuesGetData(param, NULL, NULL, &uvc, &nv, &ne, 1));
  gf->stl_vertices_uv.clear();
  gf->stl_vertices_uv.resize(nv);
  gf->stl_vertices_xyz.clear();
  gf->stl_vertices_xyz.resize(nv);
  gf->stl_curvatures.clear();
  if(C) gf->stl_curvatures.resize(2 * nv);
  gf->stl_normals.clear();
  gf->stl_normals.resize(nv);

  for(int iv = 0; iv < nv; iv++) {
    if(C) {
      MVertex *v = c2v[iv];
      std::map<MVertex *, std::pair<SVector3, SVector3> >::iterator it =
        C->find(v);
      if(it == C->end())
        Msg::Error("POINT %d NOT FOUND FOR COMPUTING CURVATURES", v->getNum());
      //      printf("%g %g
      //      %g\n",it->second.first.x(),it->second.first.y(),it->second.first.z());
      gf->stl_curvatures[2 * iv] = it->second.first;
      gf->stl_curvatures[2 * iv + 1] = it->second.second;
    }
    gf->stl_vertices_uv[iv] = SPoint2(uvc[2 * iv], uvc[2 * iv + 1]);

    gf->stl_vertices_xyz[iv] =
      SPoint3(m->vertices.coord[4 * iv + 0], m->vertices.coord[4 * iv + 1],
              m->vertices.coord[4 * iv + 2]);
    gf->stl_normals[iv] = SVector3(1, 0, 0);
  }
  gf->stl_triangles.clear();
  gf->stl_triangles.resize(3 * ne);
  for(int ie = 0; ie < ne; ie++) {
    gf->stl_triangles[3 * ie + 0] = m->triangles.node[3 * ie + 0];
    gf->stl_triangles[3 * ie + 1] = m->triangles.node[3 * ie + 1];
    gf->stl_triangles[3 * ie + 2] = m->triangles.node[3 * ie + 2];
  }
  //  printf("A\n");
  gf->fillVertexArray(false);
  HXT_CHECK(hxtMeshDelete(&m));
  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtFree(&uvc));
  //  printf("B\n");
#endif
  return 0;
}

int isTriangulationParametrizable(const std::vector<MTriangle *> &t, int Nmax,
                                  double ar, char *why)
{
#if defined(HAVE_HXT)
  int XX = (int)t.size();
  if(XX > Nmax) {
    sprintf(why,"too much triangles (%d vs. %d)",XX,Nmax);
    return XX / Nmax + 1;
  }
  std::set<MVertex *> v;
  std::map<MEdge, int, Less_Edge> e;
  double surf = 0;
  for(size_t i = 0; i < t.size(); ++i) {
    surf += t[i]->getVolume();
    for(int j = 0; j < 3; j++) {
      v.insert(t[i]->getVertex(j));
      std::map<MEdge, int, Less_Edge>::iterator it = e.find(t[i]->getEdge(j));
      if(it == e.end())
        e[t[i]->getEdge(j)] = 1;
      else
        it->second++;
    }
  }
  std::map<MEdge, int, Less_Edge>::iterator it = e.begin();
  std::vector<MEdge> _bnd;
  for(; it != e.end(); ++it) {
    if(it->second == 1) _bnd.push_back(it->first);
  }

  std::vector<std::vector<MVertex *> > vs;
  if(!SortEdgeConsecutive(_bnd, vs)) {
    // we have vertices adjacent to more than 2 model edges
    //    FILE *f = fopen("bug.pos","w");
    //    fprintf(f,"View\"\"{\n");
    //    for (size_t i=0;i<t.size();i++){
    //      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
    //	      t[i]->getVertex(0)->x(),t[i]->getVertex(0)->y(),t[i]->getVertex(0)->z(),
    //	      t[i]->getVertex(1)->x(),t[i]->getVertex(1)->y(),t[i]->getVertex(1)->z(),
    //	      t[i]->getVertex(2)->x(),t[i]->getVertex(2)->y(),t[i]->getVertex(2)->z(),
    //	      t[i]->getVertex(0)->getNum(),t[i]->getVertex(1)->getNum(),t[i]->getVertex(2)->getNum());
    //    }
    //    fprintf(f,"};\n");
    //    fclose(f);
    //    getchar();
    return 2;
  }

    double lmax = 0;
    for(size_t i = 0; i < vs.size(); i++) {
      double li = 0;
      for(size_t j = 1; j < vs[i].size(); j++) {
        li += distance(vs[i][j], vs[i][j - 1]);
      }
      lmax = std::max(li, lmax);
    }

  double poincare =
    t.size() - (2 * (v.size() - 1) - _bnd.size() + 2 * (vs.size() - 1));

  //  if(ar * lmax * lmax < 2 * M_PI * surf) {
  //    sprintf(why,"aspect ratio %12.5E is too large", surf *2 * M_PI/(ar * lmax * lmax) );
  //    return 2;
  //  }

  if (poincare != 0){
    sprintf(why,"poincare caracteristic %3g is not 0", poincare);
    return 2;
  }
  int n = 1;
  HXT_CHECK(hxtInitializeLinearSystems(&n, NULL));
  //  printf("%d triangles %d\n",t.size(),poincare);

  //        FILE *f = fopen("bug.pos","w");
  //    fprintf(f,"View\"\"{\n");
  //        for (size_t i=0;i<t.size();i++){
  //          fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
  //    	      t[i]->getVertex(0)->x(),t[i]->getVertex(0)->y(),t[i]->getVertex(0)->z(),
  //    	      t[i]->getVertex(1)->x(),t[i]->getVertex(1)->y(),t[i]->getVertex(1)->z(),
  //    	      t[i]->getVertex(2)->x(),t[i]->getVertex(2)->y(),t[i]->getVertex(2)->z(),
  //    	      t[i]->getVertex(0)->getNum(),t[i]->getVertex(1)->getNum(),t[i]->getVertex(2)->getNum());
  //        }
  //        fprintf(f,"};\n");
  //        fclose(f);

  HXTMesh *m;
  HXTMeanValues *param;
  HXTEdges *edges;
  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;
  gmsh2hxt(1,t, &m, v2c, c2v);
  HXT_CHECK(hxtEdgesCreate(m, &edges));
  HXT_CHECK(hxtMeanValuesCreate(edges, &param));
  HXT_CHECK(hxtMeanValuesCompute(param));
  double *uvc = NULL;
  int nv, ne;
  HXT_CHECK(hxtMeanValuesGetData(param, NULL, NULL, &uvc, &nv, &ne, 1));


  for (int ie=0;ie<ne;ie++){
    double u0 = uvc[2 * m->triangles.node[3 * ie + 0]+0];
    double v0 = uvc[2 * m->triangles.node[3 * ie + 0]+1];
    double u1 = uvc[2 * m->triangles.node[3 * ie + 1]+0];
    double v1 = uvc[2 * m->triangles.node[3 * ie + 1]+1];
    double u2 = uvc[2 * m->triangles.node[3 * ie + 2]+0];
    double v2 = uvc[2 * m->triangles.node[3 * ie + 2]+1];
    double det = fabs ((u1-u0)*(v2-v0)-(v1-v0)*(u2-u0));


    if (det < 1.e-12){
      HXT_CHECK(hxtMeshDelete(&m));
      HXT_CHECK(hxtEdgesDelete(&edges));
      HXT_CHECK(hxtFree(&uvc));
      sprintf(why,"parametrizat triangles are too small (%12.5E)", det);
      //      printf("coucou\n");
      return 2;
    }
  }

  HXT_CHECK(hxtMeshDelete(&m));
  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtFree(&uvc));
#endif
  return 1 ;
}

void makeMLinesUnique(std::vector<MLine *> &v)
{
  std::sort(v.begin(), v.end(), compareMLinePtr());
  v.erase(std::unique(v.begin(), v.end(), equalMLinePtr()), v.end());
}

class twoT {
public :
  MTriangle *_t1,*_t2;
  twoT (MTriangle *t1)
    :_t1(t1),_t2(NULL) {}
  MTriangle * other (MTriangle *t) const{
    if (t == _t1)return _t2;
    if (t == _t2)return _t1;
    Msg::Error("error in twoT");
    return NULL;
  }
};

static void makePartitionSimplyConnected (std::vector<MTriangle*> &t ,
					  std::vector<std::vector<MTriangle*> >&ts) {
  std::map<MEdge,twoT,Less_Edge> conn;
  for (size_t i=0; i<t.size(); i++){
    for (int j=0;j<3;j++){
      MEdge e = t[i]->getEdge(j);
      std::map<MEdge,twoT,Less_Edge>::iterator it = conn.find(e);
      twoT twt (t[i]);
      if (it == conn.end())conn.insert(std::make_pair(e,twt));
      else it->second._t2 = t[i];
    }
  }

  while (!t.empty()) {
    std::stack<MTriangle*> _s;
    _s.push(t[0]);
    std::set<MTriangle*> _touch;
    while (! _s.empty()){
      MTriangle *x = _s.top();
      _touch.insert(x);
      _s.pop();
      for (int j=0;j<3;j++){
	MEdge e = x->getEdge(j);
	std::map<MEdge,twoT,Less_Edge>::iterator it = conn.find(e);
	if (it->second._t2){
	  MTriangle *tt = it->second.other(x);
	  if (_touch.find(tt) == _touch.end())_s.push(tt);
	}
      }
    }
    std::vector<MTriangle *> _part;
    _part.insert(_part.begin(),_touch.begin(),_touch.end());
    ts.push_back(_part);
    std::vector<MTriangle*> _update;
    for (size_t i=0;i<t.size();i++)if (_touch.find(t[i]) == _touch.end()) _update.push_back(t[i]);
    t = _update;
  }
}

static void WHITES (char* n, int nw){
  for (int i=0;i<nw;i++)strcat(n," ");
}

void computeEdgeCut(GModel *gm, std::vector<MLine *> &cut,
                    int max_elems_per_cut)
{
  GModel m;

  Msg::Info("Splitting the %d triangulations of the model",gm->getNumFaces());

  // ----------------------------------------------------------------------------------
  // STUPID FIX
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    std::vector<MTriangle *> aa;
    for(size_t i = 0; i < (*it)->triangles.size(); i++) {
      if((*it)->triangles[i]->getVertex(0) ==
           (*it)->triangles[i]->getVertex(1) ||
         (*it)->triangles[i]->getVertex(0) ==
           (*it)->triangles[i]->getVertex(2) ||
         (*it)->triangles[i]->getVertex(1) ==
           (*it)->triangles[i]->getVertex(2)) {
        //	printf("TRIANGLE BAD %d %d
        //%d\n",(*it)->triangles[i]->getVertex(0)->getNum()
        //	       ,(*it)->triangles[i]->getVertex(1)->getNum()
        //	       ,(*it)->triangles[i]->getVertex(2)->getNum());
      }
      else
        aa.push_back((*it)->triangles[i]);
    }
    (*it)->triangles = aa;
  }
  // END STUPID FIX
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // ----------------------------------------------------------------------------------

  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    int part = 0;
    if((*it)->triangles.empty()) continue;
    std::vector<MVertex *> verts = (*it)->mesh_vertices;
    std::map<MTriangle *, int> global;
    std::map<MEdge, int, Less_Edge> cuts;
    std::stack<std::vector<MTriangle *> > partitions;
    std::stack<int>  _levels;
    partitions.push((*it)->triangles);
    _levels.push(0);
    (*it)->triangles.clear();

    while(!partitions.empty()) {
      int level = _levels.top();
      _levels.pop();
      (*it)->triangles = partitions.top();
      (*it)->mesh_vertices.clear();
      std::set<MVertex *> vs;
      for(size_t i = 0; i < (*it)->triangles.size(); ++i) {
        for(size_t j = 0; j < 3; ++j)
          vs.insert((*it)->triangles[i]->getVertex(j));
      }
      (*it)->mesh_vertices.insert((*it)->mesh_vertices.begin(), vs.begin(),
                                  vs.end());
      partitions.pop();
      char why[256];
      int np =
        isTriangulationParametrizable((*it)->triangles, max_elems_per_cut, 5.0, why);
      if (np > 1){
	char WH[256];
	WH[0] = '\0';
	WHITES (WH,level);
	Msg::Info("%sPartition (level %2d) with %7d triangles split in %d parts because %s",WH,
		  level,(*it)->triangles.size(),np,why);
      }
      if(np == 1) {
        for(size_t i = 0; i < (*it)->triangles.size(); i++)
          global[(*it)->triangles[i]] = part;
        part++;
      }
      else {
#if defined(HAVE_MESH)
        int *p = new int[(*it)->triangles.size()];
        if(!PartitionFace(*it, np, p)) {
          std::vector<MTriangle *> t[1000];
          for(size_t i = 0; i < (*it)->triangles.size(); i++)
            t[(*it)->triangles[i]->getPartition()].push_back(
              (*it)->triangles[i]);
          for(int i = 0; i < np; i++) {
	    std::vector<std::vector<MTriangle *> > ts;
	    makePartitionSimplyConnected (t[i],ts);
	    //	    printf("%d connected parts\n",ts.size());
	    for (size_t j=0;j<ts.size();j++){
	      _levels.push(level+1);
	      partitions.push(ts[j]);
	    }
	  }
        }
        delete[] p;
#else
        Msg::Error("Partitioning surface requires Mesh module");
#endif
      }
    }
    (*it)->triangles.clear();
    std::map<MTriangle *, int>::iterator it2 = global.begin();
    for(; it2 != global.end(); ++it2) {
      MTriangle *t = it2->first;
      (*it)->triangles.push_back(t);
      for(int i = 0; i < 3; i++) {
        MEdge ed = t->getEdge(i);
        std::map<MEdge, int, Less_Edge>::iterator it3 = cuts.find(ed);
        if(it3 == cuts.end())
          cuts[ed] = it2->second;
        else {
          if(it3->second != it2->second)
            cut.push_back(new MLine(ed.getVertex(0), ed.getVertex(1)));
        }
      }
    }
    (*it)->mesh_vertices = verts;
  }
  makeMLinesUnique(cut);
}

void computeNonManifoldEdges(GModel *gm, std::vector<MLine *> &cut,
                             bool addBoundary)
{
  std::map<MEdge, int, Less_Edge> m;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    for(size_t i = 0; i < (*it)->triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        std::map<MEdge, int, Less_Edge>::iterator it2 =
          m.find((*it)->triangles[i]->getEdge(j));
        if(it2 == m.end())
          m[(*it)->triangles[i]->getEdge(j)] = 1;
        else
          it2->second++;
      }
    }
  }
  {
    int countNM = 0, countBND = 0;
    std::map<MEdge, int, Less_Edge>::iterator it = m.begin();
    for(; it != m.end(); ++it) {
      if(it->second > 2) {
        cut.push_back(
          new MLine(it->first.getVertex(0), it->first.getVertex(1)));
        countNM++;
      }
      if(addBoundary && it->second == 1) {
        cut.push_back(
          new MLine(it->first.getVertex(0), it->first.getVertex(1)));
        countBND++;
      }
    }
    if(countNM + countBND > 0)
      Msg::Info(
        "Model has %d non manifold mesh edges and %d boundary mesh edges",
        countNM, countBND);
  }
  makeMLinesUnique(cut);
}

// todo...
void detectPlanarFaces(GModel *gm, std::vector<MLine *> &cut) {}
