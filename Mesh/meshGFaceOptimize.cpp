// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stack>
#include "GmshConfig.h"
#include "meshGFaceOptimize.h"
#include "qualityMeasures.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Generator.h"
#include "Context.h"
#include "OS.h"
#include "SVector3.h"
#include "SPoint3.h"

#if defined(HAVE_BFGS)
#include "stdafx.h"
#include "optimization.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

#if defined(HAVE_BLOSSOM)
extern "C" int FAILED_NODE;
extern "C" struct CCdatagroup;
extern "C" int perfect_match
(int ncount, CCdatagroup *dat, int ecount,
 int **elist, int **elen, char *blo_filename,
 char *mat_filename, int just_fractional, int no_fractional,
 int use_all_trees, int partialprice,
 double *totalzeit) ;
#endif

static int diff2 (MElement *q1, MElement *q2)
{
  std::set<MVertex*> s;
  for (int i=0;i<4;i++)s.insert(q1->getVertex(i));
  for (int i=0;i<4;i++)if(s.find(q2->getVertex(i)) == s.end())return 1;
  return 0;
}

static int SANITY_(GFace *gf,MQuadrangle *q1, MQuadrangle *q2, int count){
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *e1 = gf->quadrangles[i];
    MQuadrangle *e2 = q1;
    if (!diff2(e1,e2)){
      return 0;
    }
    e2 = q2;
    if (!diff2(e1,e2)){
      return 0;
    }
  }
  return 1;
}

edge_angle::edge_angle(MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2)
  : v1(_v1), v2(_v2)
{
  if(!t2) angle = 0;
  else{
    double c1[3];
    double c2[3];
    double c3[3];
    {
      MVertex *p1 = t1->getVertex(0);
      MVertex *p2 = t1->getVertex(1);
      MVertex *p3 = t1->getVertex(2);
      double a[3] = {p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z()};
      double b[3] = {p1->x() - p3->x(), p1->y() - p3->y(), p1->z() - p3->z()};
      c1[2] = a[0] * b[1] - a[1] * b[0];
      c1[1] = -a[0] * b[2] + a[2] * b[0];
      c1[0] = a[1] * b[2] - a[2] * b[1];
    }
    {
      MVertex *p1 = t2->getVertex(0);
      MVertex *p2 = t2->getVertex(1);
      MVertex *p3 = t2->getVertex(2);
      double a[3] = {p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z()};
      double b[3] = {p1->x() - p3->x(), p1->y() - p3->y(), p1->z() - p3->z()};
      c2[2] = a[0] * b[1] - a[1] * b[0];
      c2[1] = -a[0] * b[2] + a[2] * b[0];
      c2[0] = a[1] * b[2] - a[2] * b[1];
    }
    norme(c1);
    norme(c2);
    prodve(c1, c2, c3);
    double cosa; prosca(c1, c2, &cosa);
    double sina = norme(c3);
    angle = atan2(sina, cosa);
  }
}

static void setLcsInit(MTriangle *t, std::map<MVertex*, double> &vSizes)
{
  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 3; j++){
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      vSizes[vi] = -1;
      vSizes[vj] = -1;
    }
  }
}

static void setLcs(MTriangle *t, std::map<MVertex*, double> &vSizes)
{
  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 3; j++){
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      double dx = vi->x() - vj->x();
      double dy = vi->y() - vj->y();
      double dz = vi->z() - vj->z();
      double l = sqrt(dx * dx + dy * dy + dz * dz);
      std::map<MVertex*,double>::iterator iti = vSizes.find(vi);
      std::map<MVertex*,double>::iterator itj = vSizes.find(vj);
      if(iti->second < 0 || iti->second > l) iti->second = l;
      if(itj->second < 0 || itj->second > l) itj->second = l;
    }
  }
}

void buildMeshGenerationDataStructures(GFace *gf,
                                       std::set<MTri3*, compareTri3Ptr> &AllTris,
                                       std::vector<double> &vSizes,
                                       std::vector<double> &vSizesBGM,
                                       std::vector<SMetric3> &vMetricsBGM,
                                       std::vector<double> &Us,
                                       std::vector<double> &Vs)
{
  std::map<MVertex*, double> vSizesMap;
  std::list<GEdge*> edges = gf->edges();

  for(unsigned int i = 0;i < gf->triangles.size(); i++)
    setLcsInit(gf->triangles[i], vSizesMap);

  for(unsigned int i = 0;i < gf->triangles.size(); i++)
    setLcs(gf->triangles[i], vSizesMap);

  // take care of embedded vertices
  {
    std::list<GVertex*> emb_vertx = gf->embeddedVertices();
    std::list<GVertex*>::iterator itvx = emb_vertx.begin();
    while(itvx != emb_vertx.end()){
      MVertex *v = *((*itvx)->mesh_vertices.begin());
      vSizesMap[v] = std::min(vSizesMap[v], (*itvx)->prescribedMeshSizeAtVertex());
      ++itvx;
    }
  }

  int NUM = 0;
  for(std::map<MVertex*, double>::iterator it = vSizesMap.begin();
       it != vSizesMap.end(); ++it){
    // FIXME: this vertex-stored indexing makes the optimization
    // routines not thread-safe (we cannot concurrently optimize two
    // surfaces that share an edge)
    it->first->setIndex(NUM++);
    vSizes.push_back(it->second);
    vSizesBGM.push_back(it->second);
    vMetricsBGM.push_back(SMetric3(it->second));
    SPoint2 param;
    reparamMeshVertexOnFace(it->first, gf, param);
    Us.push_back(param[0]);
    Vs.push_back(param[1]);
  }
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    double lc = 0.3333333333 * (vSizes[gf->triangles[i]->getVertex(0)->getIndex()] +
                                vSizes[gf->triangles[i]->getVertex(1)->getIndex()] +
                                vSizes[gf->triangles[i]->getVertex(2)->getIndex()]);
    AllTris.insert(new MTri3(gf->triangles[i], lc, 0, &Us, &Vs, gf));
  }
  gf->triangles.clear();
  connectTriangles(AllTris);
}

void transferDataStructure(GFace *gf, std::set<MTri3*, compareTri3Ptr> &AllTris,
                           std::vector<double> &Us, std::vector<double> &Vs)
{
  while (1) {
    if(AllTris.begin() == AllTris.end()) break;
    MTri3 *worst = *AllTris.begin();
    if(worst->isDeleted())
      delete worst->tri();
    else
      gf->triangles.push_back(worst->tri());
    delete worst;
    AllTris.erase(AllTris.begin());
  }

  // make sure all the triangles are oriented in the same way in
  // parameter space (it would be nicer to change the actual algorithm
  // to ensure that we create correctly-oriented triangles in the
  // first place)
  if(gf->triangles.size() > 1){
    double n1[3], n2[3];
    MTriangle *t = gf->triangles[0];
    MVertex *v0 = t->getVertex(0), *v1 = t->getVertex(1), *v2 = t->getVertex(2);
    normal3points(Us[v0->getIndex()], Vs[v0->getIndex()], 0.,
                  Us[v1->getIndex()], Vs[v1->getIndex()], 0.,
                  Us[v2->getIndex()], Vs[v2->getIndex()], 0., n1);
    for(unsigned int j = 1; j < gf->triangles.size(); j++){
      t = gf->triangles[j];
      v0 = t->getVertex(0); v1 = t->getVertex(1); v2 = t->getVertex(2);
      normal3points(Us[v0->getIndex()], Vs[v0->getIndex()], 0.,
                    Us[v1->getIndex()], Vs[v1->getIndex()], 0.,
                    Us[v2->getIndex()], Vs[v2->getIndex()], 0., n2);
      double pp; prosca(n1, n2, &pp);
      if(pp < 0) t->revert();
    }
  }
}

void buildVertexToTriangle(std::vector<MTriangle*> &eles, v2t_cont &adj)
{
  adj.clear();
  buildVertexToElement(eles,adj);
}

template <class T>
void buildEdgeToElement(std::vector<T*> &elements, e2t_cont &adj)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    T *t = elements[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge e = t->getEdge(j);
      e2t_cont::iterator it = adj.find(e);
      if(it == adj.end()){
        std::pair<MElement*, MElement*> one = std::make_pair(t, (MElement*)0);
        adj[e] = one;
      }
      else{
        it->second.second = t;
      }
    }
  }
}

void buildEdgeToElement(GFace *gf, e2t_cont &adj)
{
  adj.clear();
  buildEdgeToElement(gf->triangles, adj);
  buildEdgeToElement(gf->quadrangles, adj);
}

void buildEdgeToTriangle(std::vector<MTriangle*> &tris, e2t_cont &adj)
{
  adj.clear();
  buildEdgeToElement(tris, adj);
}

void buildEdgeToElements(std::vector<MElement*> &tris, e2t_cont &adj)
{
  adj.clear();
  buildEdgeToElement(tris, adj);
}

void buildListOfEdgeAngle(e2t_cont adj, std::vector<edge_angle> &edges_detected,
                          std::vector<edge_angle> &edges_lonly)
{
  e2t_cont::iterator it = adj.begin();
  for(; it != adj.end(); ++it){
    if(it->second.second)
      edges_detected.push_back(edge_angle(it->first.getVertex(0),
                                          it->first.getVertex(1),
                                          it->second.first, it->second.second));
    else
      edges_lonly.push_back(edge_angle(it->first.getVertex(0),
                                       it->first.getVertex(1),
                                       it->second.first, it->second.second));
  }
  std::sort(edges_detected.begin(), edges_detected.end());
}

void parametricCoordinates(MElement *t, GFace *gf, double u[4], double v[4],
                           MVertex *close = 0)
{
  for(int j = 0; j < t->getNumVertices(); j++){
    MVertex *ver = t->getVertex(j);
    SPoint2 param, dummy;
    if (!close) reparamMeshVertexOnFace(ver, gf, param);
    else reparamMeshEdgeOnFace(ver, close, gf, param, dummy);
    u[j] = param[0];
    v[j] = param[1];
  }
}

double surfaceFaceUV(MElement *t,GFace *gf, bool *concave = 0)
{
  double u[4],v[4];
  parametricCoordinates(t,gf,u,v);
  if (t->getNumVertices() == 3)
    return 0.5*fabs((u[1]-u[0])*(v[2]-v[0])-(u[2]-u[0])*(v[1]-v[0]));
  else {
    const double a1 =
      0.5*fabs((u[1]-u[0])*(v[2]-v[0])-(u[2]-u[0])*(v[1]-v[0])) +
      0.5*fabs((u[3]-u[2])*(v[0]-v[2])-(u[0]-u[2])*(v[3]-v[2])) ;
    const double a2 =
      0.5*fabs((u[2]-u[1])*(v[3]-v[1])-(u[3]-u[1])*(v[2]-v[1])) +
      0.5*fabs((u[0]-u[3])*(v[1]-v[3])-(u[1]-u[3])*(v[0]-v[3])) ;
    if (concave) *concave = fabs(a2-a1) > 1.e-10*(a2 + a1);
    return std::min(a2,a1);
  }
}

double surfaceTriangleUV(MVertex *v1, MVertex *v2, MVertex *v3,
                         const std::vector<double> &Us,
                         const std::vector<double> &Vs)
{
  const double v12[2] = {Us[v2->getIndex()] - Us[v1->getIndex()],
                         Vs[v2->getIndex()] - Vs[v1->getIndex()]};
  const double v13[2] = {Us[v3->getIndex()] - Us[v1->getIndex()],
                         Vs[v3->getIndex()] - Vs[v1->getIndex()]};
  return 0.5 * fabs (v12[0] * v13[1] - v12[1] * v13[0]);
}

int _removeFourTrianglesNodes(GFace *gf,bool replace_by_quads)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles,adj);
  v2t_cont :: iterator it = adj.begin();
  int n=0;
  std::set<MElement*> touched;
  while (it != adj.end()) {
    bool skip = false;
    double surfaceRef = 0;
    if(it->second.size() == 4) {
      const std::vector<MElement*> &lt = it->second;
      MVertex* edges[4][2];
      for(int i = 0; i < 4; i++) {
        if(touched.find(lt[i])!=touched.end() || lt[i]->getNumVertices()!=3){
          skip=true;
          break;
        }
        int j;
        surfaceRef += surfaceFaceUV(lt[i], gf);
        for(j = 0; j < 3; j++) {
          if(lt[i]->getVertex(j) == it->first) {
            edges[i][0] = lt[i]->getVertex((j+1)%3);
            edges[i][1] = lt[i]->getVertex((j+2)%3);
            break;
          }
        }
        if(j == 3)
          throw;
      }
      if(skip){
        it++;
        continue;
      }

      for(int i = 1; i < 3; i++) {
        for(int j = i + 1; j < 4; j++) {
          if(edges[j][0] == edges[i-1][1]){
            MVertex *buf[2]={edges[i][0],edges[i][1]};
            edges[i][0]=edges[j][0];
            edges[i][1]=edges[j][1];
            edges[j][0]=buf[0];
            edges[j][1]=buf[1];
            break;
          }
        }
      }
      if(edges[0][1] == edges[1][0] && edges[1][1] == edges[2][0] &&
         edges[2][1] == edges[3][0] && edges[3][1] == edges[0][0]) {
        if(replace_by_quads){
          gf->quadrangles.push_back(new MQuadrangle(edges[0][0], edges[1][0],
                                                    edges[2][0], edges[3][0]));
        }
        else{
          MTriangle *newt[4];
          double surf[4],qual[4];
          for(int i=0;i<4;i++){
            newt[i] = new MTriangle(edges[i][0],edges[(i+1)%4][0],edges[(i+2)%4][0]);
            surf[i] = surfaceFaceUV(newt[i],gf);
            qual[i] = qmTriangle(newt[i],QMTRI_RHO);
          }
          double q02=(fabs((surf[0]+surf[2]-surfaceRef)/surfaceRef)<1e-8) ?
            std::min(qual[0],qual[2]) : -1;
          double q13=(fabs((surf[1]+surf[3]-surfaceRef)/surfaceRef)<1e-8) ?
            std::min(qual[1],qual[3]) : -1;
          if(q02>q13 && q02 >0) {
            delete newt[1];
            delete newt[3];
            gf->triangles.push_back(newt[0]);
            gf->triangles.push_back(newt[2]);
          }
          else if (q13 >0) {
            delete newt[0];
            delete newt[2];
            gf->triangles.push_back(newt[1]);
            gf->triangles.push_back(newt[3]);
          }
          else {
            it++;
            continue;
          }
        }
        for(int i=0;i<4;i++) {
          touched.insert(lt[i]);
        }
        n++;
      }
    }
    it++;
  }
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    if(touched.find(gf->triangles[i]) == touched.end()){
      triangles2.push_back(gf->triangles[i]);
    }
    else {
      delete gf->triangles[i];
    }
  }
  gf->triangles = triangles2;
  Msg::Debug("%i four-triangles vertices removed",n);
  return n;
}

void removeFourTrianglesNodes(GFace *gf,bool replace_by_quads)
{
  while(_removeFourTrianglesNodes(gf,replace_by_quads));
}

/*

  +--------+
  |       /|
  |     /  |
  |    +   |
  |  /     |
  |/       |
  +--------+

*/

static int _removeTwoQuadsNodes(GFace *gf)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles,adj);
  buildVertexToElement(gf->quadrangles,adj);
  v2t_cont :: iterator it = adj.begin();
  std::set<MElement*>  touched;
  std::set<MVertex*>  vtouched;
  while (it != adj.end()) {
    bool skip=false;
    double surfaceRef=0;
    if(it->second.size()==2 && it->first->onWhat()->dim() == 2) {
      const std::vector<MElement*> &lt = it->second;
      MElement *q1 = it->second[0];
      MElement *q2 = it->second[1];
      if (q1->getNumVertices() == 4 &&
	  q2->getNumVertices() == 4 &&
	  touched.find(q1) == touched.end() && touched.find(q2) == touched.end()){
	touched.insert(q1);
	touched.insert(q2);
	int comm = 0;
	for (int i=0;i<4;i++){
	  if (q1->getVertex(i) == it->first){
	    comm = i;
	    break;
	  }
	}
	MVertex *v1 = q1->getVertex((comm+1)%4);
	MVertex *v2 = q1->getVertex((comm+2)%4);
	MVertex *v3 = q1->getVertex((comm+3)%4);
	MVertex *v4 = 0;
	for (int i=0;i<4;i++){
	  if (q2->getVertex(i) != v1 && q2->getVertex(i) != v2 &&
	      q2->getVertex(i) != v3 && q2->getVertex(i) != it->first){
	    v4 = q2->getVertex(i);
	    break;
	  }
	}
	if (!v4){
	  Msg::Error("BUG DISCOVERED IN _removeTwoQuadsNodes ,%p,%p,%p",v1,v2,v3);
	  q1->writePOS(stdout,true,false,false,false,false,false);
	  q2->writePOS(stdout,true,false,false,false,false,false);
	  return 0;
	}
	gf->quadrangles.push_back(new MQuadrangle(v1,v2,v3,v4));
	vtouched.insert(it->first);
      }
    }
    it++;
  }
  std::vector<MQuadrangle*> quadrangles2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    if(touched.find(gf->quadrangles[i]) == touched.end()){
      quadrangles2.push_back(gf->quadrangles[i]);
    }
    else {
      delete gf->quadrangles[i];
    }
  }
  gf->quadrangles = quadrangles2;

  std::vector<MVertex*> mesh_vertices2;
  for(unsigned int i = 0; i < gf->mesh_vertices.size(); i++){
    if(vtouched.find(gf->mesh_vertices[i]) == vtouched.end()){
      mesh_vertices2.push_back(gf->mesh_vertices[i]);
    }
    else {
      delete gf->mesh_vertices[i];
    }
  }
  gf->mesh_vertices = mesh_vertices2;

  return vtouched.size();
}

int removeTwoQuadsNodes(GFace *gf)
{
  int nbRemove = 0;
  while(1){
    int x = _removeTwoQuadsNodes(gf);
    if (!x)break;
    nbRemove += x;
  }
  Msg::Debug("%i two-quadrangles vertices removed",nbRemove);
  return nbRemove;
}

static bool _isItAGoodIdeaToCollapseThatVertex (GFace *gf,
						std::vector<MElement*> &e1,
						std::vector<MElement*> &e2,
						MElement *q,
						MVertex *v1,
						MVertex *v2,
						MVertex *v,
						double FACT){

  double surface_old = surfaceFaceUV(q,gf);
  double surface_new = 0;
  //  double worst_quality_old = q->etaShapeMeasure();
  //  double worst_quality_new = 1.0;

  double x = v->x();
  double y = v->y();
  double z = v->z();
  double uu,vv;
  v->getParameter(0,uu);
  v->getParameter(1,vv);
  //  SPoint2 p1,p2;
  //  reparamMeshEdgeOnFace(v1,v2,gf,p1,p2);
  //  SPoint2 p =(p1+p2)*0.5;
  //  GPoint gp = gf->point(p);
  //  v->setXYZ(gp.x(),gp.y(),gp.z());
  //  v->setParameter(0,p.x());
  //  v->setParameter(1,p.y());

  for (unsigned int j=0;j<e1.size();++j){
    surface_old += surfaceFaceUV(e1[j],gf);
    //    worst_quality_old = std::min(worst_quality_old,e1[j]-> etaShapeMeasure());
    for (int k=0;k<e1[j]->getNumVertices();k++){
      if (e1[j]->getVertex(k) == v1 && e1[j] != q)
	e1[j]->setVertex(k,v);
    }
    surface_new += surfaceFaceUV(e1[j],gf);
    //    worst_quality_new = std::min(worst_quality_new,e1[j]-> etaShapeMeasure());
    for (int k=0;k<e1[j]->getNumVertices();k++){
      if (e1[j]->getVertex(k) == v && e1[j] != q)
	e1[j]->setVertex(k,v1);
    }
  }

  for (unsigned int j=0;j<e2.size();++j){
    surface_old += surfaceFaceUV(e2[j],gf);
    //    worst_quality_old = std::min(worst_quality_old,e2[j]-> etaShapeMeasure());
    for (int k=0;k<e2[j]->getNumVertices();k++){
      if (e2[j]->getVertex(k) == v2 && e2[j] != q)
	e2[j]->setVertex(k,v);
    }
    surface_new += surfaceFaceUV(e2[j],gf);
    //    worst_quality_new = std::min(worst_quality_new,e2[j]-> etaShapeMeasure());
    for (int k=0;k<e2[j]->getNumVertices();k++){
      if (e2[j]->getVertex(k) == v && e2[j] != q)
	e2[j]->setVertex(k,v2);
    }
  }

  if ( fabs (surface_old - surface_new ) > 1.e-10 * surface_old) {
    //    ||       FACT*worst_quality_new <  worst_quality_old ) {

    v->setXYZ(x,y,z);
    v->setParameter(0,uu);
    v->setParameter(1,vv);
    return false;
  }

  return true;

}


static bool _isItAGoodIdeaToMoveThatVertex (GFace *gf,
					    const std::vector<MElement*> &e1,
					    MVertex *v1,
					    const SPoint2 &before,
					    const SPoint2 &after){

  double surface_old = 0;
  double surface_new = 0;

  double qualityNew[256];

  GPoint gp = gf->point(after);
  SPoint3 pafter  (gp.x(),gp.y(),gp.z());
  SPoint3 pbefore (v1->x(),v1->y(),v1->z());

  for (unsigned int j=0;j<e1.size();++j)
    surface_old += surfaceFaceUV(e1[j],gf);

  v1->setParameter(0,after.x());
  v1->setParameter(1,after.y());
  v1->setXYZ(pafter.x(),pafter.y(),pafter.z());

  for (unsigned int j=0;j<e1.size();++j){
    surface_new += surfaceFaceUV(e1[j],gf);
    qualityNew[j] = (e1[j]->getNumVertices() == 4) ? e1[j]->etaShapeMeasure() : e1[j]->gammaShapeMeasure();
    if (qualityNew[j] < 0.01)return false;
  }

  v1->setParameter(0,before.x());
  v1->setParameter(1,before.y());
  v1->setXYZ(pbefore.x(),pbefore.y(),pbefore.z());

  if ( (surface_new - surface_old)  > 1.e-10 * surface_old) {
    return false;
  }
  return true;
}


static int _quadWithOneVertexOnBoundary (GFace *gf,
					 std::set<MVertex*> &touched,
					 std::set<MElement*> &diamonds,
					 std::set<MVertex*> &deleted,
					 std::vector<MElement*> &e2,
					 std::vector<MElement*> &e4,
					 std::vector<MElement*> &e1,
					 MQuadrangle *q,
					 MVertex *v1,
					 MVertex *v2,
					 MVertex *v3,
					 MVertex *v4){
  //return 0;
  if (v1->onWhat()->dim() < 2 &&
      v2->onWhat()->dim() == 2 &&
      v3->onWhat()->dim() == 2 &&
      v4->onWhat()->dim() == 2 &&
      e2.size() < 5 &&
      e4.size() < 5 &&
       _isItAGoodIdeaToCollapseThatVertex (gf, e2, e4, q, v2, v4, v4,12.0)
	/* || _isItAGoodIdeaToCollapseThatVertex (gf, e2, e4, q, v2, v4, v2,12.0))*/){
    touched.insert(v1);
    touched.insert(v2);
    touched.insert(v3);
    touched.insert(v4);
    /*
    std::vector<MVertex*> line;
    for (int j=0;j<e1.size();j++){
      for (int k=0;k<e1[j]->getNumVertices();k++){
	if (e1[j]->getVertex(k) != v1 && e1[j] != q &&
	    e1[j]->getVertex(k)->onWhat()->dim() < 2){
	  line.push_back(e1[j]->getVertex(k));
	}
      }
    }
    // do not collapse if it's a corner
    if (line.size() == 2){
      if (fabs(angle3Vertices(line[0],v1,line[1]) - M_PI) > 3*M_PI/8.){
	//	printf("coucou %g\n",angle3Vertices(line[0],v1,line[1])*180./M_PI);
	return 0;
      }
    }
    */
    //    if (line.size() == 2)printf("caca\n");
    //    else printf("hohcozbucof\n");
    for (unsigned int j=0;j<e2.size();++j){
      for (int k=0;k<e2[j]->getNumVertices();k++){
	if (e2[j]->getVertex(k) == v2 && e2[j] != q)
	  e2[j]->setVertex(k,v4);
      }
    }
    diamonds.insert(q);
    deleted.insert(v2);
    return 1;
  }
  return 0;
}

static int  _countCommon(std::vector<MElement*> &a, std::vector<MElement*> &b) {
  int count = 0;
  for (unsigned int i=0;i<a.size();i++){
    for (unsigned int j=0;j<b.size();j++){
      if (a[i]==b[j])count++;
    }
  }
  return count;
}

// see paper from Bunin
//Guy Bunin (2006) Non-Local Topological Cleanup ,15th International Meshing Roundtable.
// this is our interpretation of the algorithm.


static std::vector<MVertex*> closestPathBetweenTwoDefects (v2t_cont &adj,
							   v2t_cont :: iterator it) {
  // get neighboring vertices
  std::stack<std::vector<MVertex*> > paths;

  std::vector<MVertex*> thisPath;
  thisPath.push_back(it->first);
  paths.push(thisPath);

  int depth = 0;
  while (1) {
    std::vector<MVertex*> path = paths.top();
    paths.pop();
    it = adj.find (path[path.size() - 1]);
    std::set<MVertex *> neigh;
    for (int i = 0; i < it->second.size(); i++){
      for (int j=0;j<4;j++){
	MEdge e = it->second[i]->getEdge(j);
	if (e.getVertex(0) == it->first) neigh.insert(e.getVertex(1));
	else if (e.getVertex(1) == it->first) neigh.insert(e.getVertex(0));
      }
    }
    //    printf("vertex with %d neighbors\n",neigh.size());
    for (std::set<MVertex *>::iterator itv = neigh.begin() ;
       itv != neigh.end(); ++itv){
      v2t_cont :: iterator itb = adj.find (*itv);
      if (std::find(path.begin(), path.end(), itb->first) == path.end()){
	if (itb->first->onWhat()->dim() == 2 && itb->second.size() != 4) {
	  // YEAH WE FOUND A PATH !!!!!
	  path.push_back(itb->first);
	  //	  printf("PATH : ");
	  //	  for (int i=0;i<path.size();i++){
	  //	    printf("%d ",path[i]->getNum());
	  //	  }
	  //	  printf("\n");
	  return path;
	}
	// no path, we create new possible paths
	else if (itb->first->onWhat()->dim() == 2){
	  std::vector<MVertex*> newPath = path;
	  newPath.push_back(itb->first);
	  paths.push(newPath);
	}
      }
    }
    if (depth++ > 10 || !paths.size()){
      std::vector<MVertex*> empty;
      return empty;
    }
  }
}

static MVertex * createNewVertex (GFace *gf, SPoint2 p){
  GPoint gp = gf->point(p);
  return new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
}
static std::vector<MVertex*> saturateEdge (GFace *gf, SPoint2 p1, SPoint2 p2, int n){
  std::vector<MVertex*> pts;
  for (int i=1;i<n;i++){
    SPoint2 p = p1 + (p2-p1)*((double)i/((double)(n)));
    pts.push_back(createNewVertex(gf,p));
  }
  return pts;
}

/*
  c4          N              c3
  +--------------------------+
  |       |      |    |      |
  |       |      |    |      |
  +--------------------------+  M
  |       |      |    |      |
  |       |      |    |      |
  +--------------------------+
 c1                          c2

             N

*/
#define TRAN_QUA(c1,c2,c3,c4,s1,s2,s3,s4,u,v) \
   (1.-u)*c4+u*c2+(1.-v)*c1+v*c3-((1.-u)*(1.-v)*s1+u*(1.-v)*s2+u*v*s3+(1.-u)*v*s4)

void  createRegularMesh (GFace *gf,
			 MVertex *v1, SPoint2 &c1,
			 std::vector<MVertex*> &e12, int sign12,
			 MVertex *v2, SPoint2 &c2,
			 std::vector<MVertex*> &e23, int sign23,
			 MVertex *v3, SPoint2 &c3,
			 std::vector<MVertex*> &e34, int sign34,
			 MVertex *v4, SPoint2 &c4,
			 std::vector<MVertex*> &e41, int sign41,
			 std::vector<MQuadrangle*> &q){
  int N = e12.size();
  int M = e23.size();

  //  printf("%d %d vs %d %d\n",e12.size(),e23.size(),e34.size(),e41.size());

  //create points using transfinite interpolation

  std::vector<std::vector<MVertex*> > tab(M+2);
  for(int i = 0; i <= M+1; i++) tab[i].resize(N+2);

  tab[0][0] = v1;
  tab[0][N+1] = v2;
  tab[M+1][N+1] = v3;
  tab[M+1][0] = v4;
  for (int i=0;i<N;i++){
    tab[0][i+1]   = sign12 > 0 ? e12 [i] : e12 [N-i-1];
    tab[M+1][i+1] = sign34 < 0 ? e34 [i] : e34 [N-i-1];
  }
  for (int i=0;i<M;i++){
    tab[i+1][N+1] = sign23 > 0 ? e23 [i] : e23 [M-i-1];
    tab[i+1][0] = sign41 < 0 ? e41 [i] : e41 [M-i-1];
  }

  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      double u = (double) (i+1)/ ((double)(N+1));
      double v = (double) (j+1)/ ((double)(M+1));
      MVertex *v12 = (sign12 >0) ? e12[i] : e12 [N-1-i];
      MVertex *v23 = (sign23 >0) ? e23[j] : e23 [M-1-j];
      MVertex *v34 = (sign12 <0) ? e34[i] : e34 [N-1-i];
      MVertex *v41 = (sign41 <0) ? e41[j] : e41 [M-1-j];
      //      printf("HOPLA %p %p %p %p\n",v12->onWhat(),v23->onWhat(),v34->onWhat(),v41->onWhat());
      SPoint2 p12; reparamMeshVertexOnFace(v12, gf, p12);
      SPoint2 p23; reparamMeshVertexOnFace(v23, gf, p23);
      SPoint2 p34; reparamMeshVertexOnFace(v34, gf, p34);
      SPoint2 p41; reparamMeshVertexOnFace(v41, gf, p41);
      double Up = TRAN_QUA(p12.x(), p23.x(), p34.x(), p41.x(),
			   c1.x(),c2.x(),c3.x(),c4.x(),u,v);
      double Vp = TRAN_QUA(p12.y(), p23.y(), p34.y(), p41.y(),
			   c1.y(),c2.y(),c3.y(),c4.y(),u,v);

      MVertex *vnew = createNewVertex (gf, SPoint2(Up,Vp));
      tab[j+1][i+1] = vnew;
    }
  }
  // create quads
  for (int i=0;i<=N;i++){
    for (int j=0;j<=M;j++){
      //MQuadrangle *qnew = new MQuadrangle (tab[j][i],tab[j+1][i],tab[j+1][i+1],tab[j][i+1]);
      MQuadrangle *qnew = new MQuadrangle (tab[j][i],tab[j][i+1],tab[j+1][i+1],tab[j+1][i]);
      //      printf("%p %p %p %p\n",tab[j][i],tab[j][i+1],tab[j+1][i+1],tab[j+1][i]);
      q.push_back(qnew);
    }
  }
}

void updateQuadCavity (GFace *gf,
		       v2t_cont &adj,
		       std::vector<MElement*> &oldq,
		       std::vector<MQuadrangle*> &newq){

  for (int i=0;i<oldq.size();i++){
    gf->quadrangles.erase(std::remove(gf->quadrangles.begin(),
				      gf->quadrangles.end(),oldq[i]));
    for (int j=0;j<4;j++){
      MVertex *v = oldq[i]->getVertex(j);
      v2t_cont :: iterator it = adj.find(v);
      if (it == adj.end())Msg::Error("cannot update a quad cavity");
      it->second.erase(std::remove(it->second.begin(),it->second.end(),oldq[i]));
      //      for (int k=0;k<it->second.size();++k){
      //	if (it->second[k] == oldq[i])printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARGH\n");
      //      }
    }
    //    delete oldq[i];
  }
  for (int i=0;i<newq.size();i++){
    gf->quadrangles.push_back(newq[i]);
    for (int j=0;j<4;j++){
      MVertex *v = newq[i]->getVertex(j);
      v2t_cont :: iterator it = adj.find(v);
      if (it != adj.end()){
	it->second.push_back((MElement*)newq[i]);
      }
      else{
	gf->mesh_vertices.push_back(v);
	std::vector<MElement*> vv;
	vv.push_back(newq[i]);
	adj[v] = vv;
      }
    }
  }
}


struct  quadBlob {
  GFace *gf;
  int maxCavitySize;
  v2t_cont &adj;
  std::vector<MElement*> quads;
  std::vector<MVertex*> nodes;
  std::vector<MVertex*> bnodes;
  static bool matricesDone;
  static fullMatrix<double> M3 ;
  static fullMatrix<double> M5 ;

  quadBlob(v2t_cont &a, std::vector<MVertex*> & path, GFace *g, int maxC) : adj(a),gf(g),maxCavitySize(maxC)
  {
    expand_blob(path);
  }
  inline bool inBlob(MElement* e) const {
    return std::find(quads.begin(), quads.end(), e) != quads.end();
  }
  inline bool inBoundary(MVertex *v, std::vector<MVertex*> &b) const {
    return std::find(b.begin(), b.end(), v) != b.end();
  }

  static void computeMatrices(){
    if (matricesDone)return;
    matricesDone = true;
    M3.resize(6,6);
    M5.resize(10,10);

    // compute M3
    M3.setAll(0);
    M5.setAll(0);
    M3(0,2) = M3(1,0) = M3(2,1) = -1.;
    M3(0,3+0) = M3(1,3+1) =M3(2,3+2) =1.;
    M3(3+0,0) = M3(3+1,1) =M3(3+2,2) =1.;
    M3(3+0,3+0) = M3(3+1,3+1) =M3(3+2,3+2) =1.;
    M3.invertInPlace();
    // compute M5
    M5(0,2) = M5(1,3) = M5(2,4) = M5(3,0) = M5(4,1) = -1;
    for (int i=0;i<5;i++){
      M5(5+i,5+i) = 1;
      M5(i,5+i) = M5(5+i,i) = 1;
    }
    M5.invertInPlace();
  }

  void expand_blob (std::vector<MVertex*> & path) {
    std::set<MElement*> e;
    e.insert(quads.begin(),quads.end());
    for (int i=0;i<path.size();i++){
      v2t_cont :: const_iterator it = adj.find(path[i]);
      e.insert(it->second.begin(),it->second.end());
    }
    quads.clear();
    quads.insert(quads.begin(),e.begin(),e.end());
    std::set<MVertex*> all;
    for (int i=0;i<quads.size();i++)
      for (int j=0;j<4;j++)
	all.insert(quads[i]->getVertex(j));
    nodes.clear();
    nodes.insert(nodes.begin(),all.begin(),all.end());
    bnodes.clear();
  }

  void buildBoundaryNodes(){
    bnodes.clear();
    for (int i=0;i<nodes.size();i++){
      v2t_cont :: const_iterator it = adj.find(nodes[i]);
      if (it->first->onWhat()->dim() < 2) bnodes.push_back(nodes[i]);
      else {
	bool found = false;
	for (int j=0;j<it->second.size();j++){
	  if (!inBlob(it->second[j])){
	    found = true;
	  }
	}
	if(found){
	  bnodes.push_back(nodes[i]);
	}
      }
    }
  }

  int topologicalAngle(MVertex*v) const {
    int typical = 0;
    v2t_cont :: const_iterator it = adj.find(v);
    int outside = 0;
    for (int j=0;j<it->second.size();j++)
      if (!inBlob(it->second[j]))outside++;

    if (v->onWhat()->dim() == 1)typical = 2;
    else if (v->onWhat()->dim() == 0)typical = 3;

    return outside - 2 + typical;
  }
  int construct_meshable_blob (int iter) {
    int blobsize = quads.size();
    //    printf("starting with a blob of size %d\n",blobsize);
    while(1){
      if(quads.size() > maxCavitySize)return 0;
      if(quads.size() >= gf->quadrangles.size())return 0;
      //      printBlob(102021120);
      buildBoundaryNodes();
      //      printf("blob has %d bnodes and %d nodes\n",bnodes.size(),nodes.size());
      int topo_convex_region = 1;
      for (int i=0; i<bnodes.size();i++){
	MVertex *v = bnodes[i];
	// do not do anything in boundary layers !!!
	if (v->onWhat()->dim() == 2){
	  MFaceVertex *fv = dynamic_cast<MFaceVertex*>(v);
	  if(fv && fv->bl_data) return 0;
	}
	//if (v->onWhat()->dim() == 2){
	  int topo_angle = topologicalAngle(v);
	  if (topo_angle < 0){
	    std::vector<MVertex*> vv; vv.push_back(v);
	    expand_blob(vv);
	    topo_convex_region = 0;
	  }
	  //	} // inside node
	  //	else {
	  //	  return 0;
	  //	}
      }// loop on boundatry nodes
      if (topo_convex_region){
	if (meshable(iter))return 1;
	else expand_blob(bnodes);
      }
      if (blobsize == quads.size())return 0;
      blobsize = quads.size();
    }// while 1
  }

  bool orderBNodes () {
    MVertex *v = 0;
    std::vector<MVertex*> temp;
    for (int i=0;i<bnodes.size();i++){
      if (topologicalAngle(bnodes[i]) > 0){
	v = bnodes[i];
	break;
      }
    }
    temp.push_back(v);
    //    if (!v)printf("aaaaaaaaaaaaaaaaaaargh\n");
    while(1){
      v2t_cont :: const_iterator it = adj.find(v);
      int ss = temp.size();
      for (int j=0;j<it->second.size();j++){
	bool found = false;
	for (int i=0;i<4;i++){
	  MEdge e = it->second[j]->getEdge(i);
	  if (e.getVertex(0) == v &&
	      inBoundary(e.getVertex(1),bnodes) &&
	      !inBoundary(e.getVertex(1),temp)) {
	    v = e.getVertex(1);
	    temp.push_back(e.getVertex(1));
	    found = true;
	    break;
	  }
	  else if (e.getVertex(1) == v &&
		   inBoundary(e.getVertex(0),bnodes) &&
		   !inBoundary(e.getVertex(0),temp)) {
	    v = e.getVertex(0);
	    temp.push_back(e.getVertex(0));
	    found = true;
	    break;
	  }
	}
	if (found)break;
      }
      if (temp.size() == ss)return false;
      //      printf("%d %d\n",temp.size(),bnodes.size());
      if (temp.size() == bnodes.size())break;
    }
    bnodes = temp;
    return true;
  }

  void printBlob(int iblob){
    char name[234];
    sprintf(name,"blob%d.pos",iblob);
    FILE *f = fopen(name,"w");
    fprintf(f,"View \"%s\" {\n",name);
    for (int i=0;i<quads.size();i++){
      quads[i]->writePOS(f,true,false,false,false,false,false);
    }
    for (int i=0;i<bnodes.size();i++){
      fprintf(f,"SP(%g,%g,%g) {%d};\n",
	      bnodes[i]->x(),
	      bnodes[i]->y(),
	      bnodes[i]->z(),topologicalAngle(bnodes[i]));
    }
    fprintf(f,"};\n");
    fclose(f);

  }

  void smooth (int);

  bool meshable (int iter) {
    int ncorners = 0;
    MVertex *corners[5];
    for (int i=0;i<bnodes.size();i++){
      if (topologicalAngle(bnodes[i]) > 0) ncorners ++;
      if (ncorners > 5)return false;
    }
    if (ncorners != 3 && ncorners != 4 && ncorners != 5){
      return false;
    }
    //    printf("a blob with %d corners has been found\n",ncorners);
    // look if it is possible to build a mesh with one defect only
    if (!orderBNodes () )return false;
    int side = -1;
    int count[5] = {0,0,0,0,0};
    for (int i=0;i<bnodes.size();i++){
      if (topologicalAngle(bnodes[i]) > 0){
	side++;
	corners[side] = (bnodes[i]);
      }
      else count[side]++;
    }
    /*

      This is the configuration for the 4 corners defect
      only the simple case is considered
     */
    if (ncorners == 4){
      if (count[0] != count[2] || count[1] != count[3]){
	//	printf("4 CORNERS : %d %d %d %d\n",count[0],count[1],count[2],count[3]);
	return 0;
      }
      int a1 = (int)count[0]+1;
      int a2 = (int)count[1]+1;
      MVertex *v0 = corners[0]; SPoint2 p0; reparamMeshVertexOnFace(v0, gf, p0);
      MVertex *v1 = corners[1]; SPoint2 p1; reparamMeshVertexOnFace(v1, gf, p1);
      MVertex *v2 = corners[2]; SPoint2 p2; reparamMeshVertexOnFace(v2, gf, p2);
      MVertex *v3 = corners[3]; SPoint2 p3; reparamMeshVertexOnFace(v3, gf, p3);

      std::vector<MVertex*> e0_1,e1_2,e2_3,e3_0;
      for (int i=0;i<a1-1;i++)e0_1.push_back(bnodes[i+1]);
      for (int i=0;i<a2-1;i++)e1_2.push_back(bnodes[i+1 + a1]);
      for (int i=0;i<a1-1;i++)e2_3.push_back(bnodes[i+1 + a1 + a2]);
      for (int i=0;i<a2-1;i++)e3_0.push_back(bnodes[i+1 + a1 + a2 + a1]);
      //      printf("%d bnodes last inserted %d a123 = %d %d \n",bnodes.size(),a2 + a1 + a2 + a1,a1,a2);
      std::vector<MQuadrangle*> q;
      createRegularMesh (gf,
			 v0,p0,
			 e0_1, +1,
			 v1,p1,
			 e1_2, +1,
			 v2,p2,
			 e2_3, +1,
			 v3,p3,
			 e3_0, +1,
			 q);
            printBlob(iter+10000);
      updateQuadCavity (gf,adj,quads,q);
      quads.clear();
      quads.insert(quads.begin(),q.begin(),q.end());
      //      printBlob(iter+20000);
      return 1;
      //      getchar();
    }
    else if (ncorners == 3){
      //      printBlob(iter);
      fullVector<double> rhs(6);
      fullVector<double> result(6);
      rhs(3) = count[0]+1.;
      rhs(4) = count[1]+1.;
      rhs(5) = count[2]+1.;
      rhs(0) = rhs(1) = rhs(2) = 0.;
      //      printf("%d %d %d\n",count[0],count[1],count[2]);
      M3.mult(rhs,result);
      //      printf("%g %g %g %g %g %g\n",result(0),result(1),result(2),result(3),result(4),result(5));
      int a1 = (int)result(0);
      int a2 = (int)result(1);
      int a3 = (int)result(2);
      if (a1 <= 0 || a2  <=0  || a3 <= 0)return false;
      MVertex *v0 = corners[0]; SPoint2 p0; reparamMeshVertexOnFace(v0, gf, p0);
      MVertex *v1 = corners[1]; SPoint2 p1; reparamMeshVertexOnFace(v1, gf, p1);
      MVertex *v2 = corners[2]; SPoint2 p2; reparamMeshVertexOnFace(v2, gf, p2);
      MVertex *v01 = bnodes[a1]; SPoint2 p01; reparamMeshVertexOnFace(v01, gf, p01);
      MVertex *v12 = bnodes[a1+a3+a2]; SPoint2 p12; reparamMeshVertexOnFace(v12, gf, p12);
      MVertex *v20 = bnodes[a1+a3+a2+a1+a3]; SPoint2 p20; reparamMeshVertexOnFace(v20, gf, p20);
      SPoint2 p012 = (p01+p12+p20)*(1./3.0); MVertex *v012 = createNewVertex (gf, p012);

      std::vector<MVertex*> e012_01 = saturateEdge (gf,p012,p01,a2);
      std::vector<MVertex*> e012_12 = saturateEdge (gf,p012,p12,a3);
      std::vector<MVertex*> e012_20 = saturateEdge (gf,p012,p20,a1);

      std::vector<MVertex*> e0_01,e01_1,e1_12,e12_2,e2_20,e20_0;
      for (int i=0;i<a1-1;i++)e0_01.push_back(bnodes[i+1]);
      for (int i=0;i<a3-1;i++)e01_1.push_back(bnodes[i+1 + a1]);
      for (int i=0;i<a2-1;i++)e1_12.push_back(bnodes[i+1 + a1 + a3]);
      for (int i=0;i<a1-1;i++)e12_2.push_back(bnodes[i+1 + a1 + a3 + a2]);
      for (int i=0;i<a3-1;i++)e2_20.push_back(bnodes[i+1 + a1 + a3 + a2 + a1 ]);
      for (int i=0;i<a2-1;i++)e20_0.push_back(bnodes[i+1 + a1 + a3 + a2 + a1 + a3]);
      //      printf("%d bnodes last inserted %d a123 = %d %d %d\n",bnodes.size(),a2 + a1 + a3 + a2 + a1 + a3,a1,a2,a3);
      std::vector<MQuadrangle*> q;
      createRegularMesh (gf,
			 v012,p012,
			 e012_01, +1,
			 v01,p01,
			 e0_01, -1,
			 v0,p0,
			 e20_0, -1,
			 v20,p20,
			 e012_20, -1,
			 q);

      createRegularMesh (gf,
			 v012,p012,
			 e012_20, +1,
			 v20,p20,
			 e2_20, -1,
			 v2,p2,
			 e12_2, -1,
			 v12,p12,
			 e012_12, -1,
			 q);

      createRegularMesh (gf,
			 v012,p012,
			 e012_12, +1,
			 v12,p12,
			 e1_12, -1,
			 v1,p1,
			 e01_1, -1,
			 v01,p01,
			 e012_01, -1,
			 q);


            printBlob(iter+110000);
      updateQuadCavity (gf,adj,quads,q);
      quads.clear();
      quads.insert(quads.begin(),q.begin(),q.end());
      //      printBlob(iter+20000);
      return 1;
      //      getchar();
    }
    /*

      This is the configuration for the 5 corners defect

                    v3
                    /\
            a4    /    \  a5
                /        \
         v34  /            \ v23
            / \    4      /  \
      a1  /    \        /      \  a3
        /        \    /          \
   v4  X    5     \  /      3     X v2
       \         /v01234\         /
   a5   \    /      |      \     / a4
   v40   \/     1   |   2      \/ v12
       a2 \         |          /
           X--------+---------X    a2
           v0      v01        v1
               a1       a3



     */
    else if (ncorners == 5){
      //      printBlob(iter);
      fullVector<double> rhs(10);
      fullVector<double> result(10);
      rhs(5) = count[0]+1.;
      rhs(6) = count[1]+1.;
      rhs(7) = count[2]+1.;
      rhs(8) = count[3]+1.;
      rhs(9) = count[4]+1.;
      rhs(0) = rhs(1) = rhs(2) = rhs(3) = rhs(4) = 0.;
      //      printf("%d %d %d\n",count[0],count[1],count[2]);
      M5.mult(rhs,result);
      //      printf("%g %g %g %g %g %g\n",result(0),result(1),result(2),result(3),result(4),result(5));
      int a1 = (int)result(0);
      int a2 = (int)result(1);
      int a3 = (int)result(2);
      int a4 = (int)result(3);
      int a5 = (int)result(4);
      if (a1 <= 0 || a2  <=0  || a3 <= 0 || a4 <= 0 || a5 <= 0)return false;
      MVertex *v0 = corners[0]; SPoint2 p0; reparamMeshVertexOnFace(v0, gf, p0);
      MVertex *v1 = corners[1]; SPoint2 p1; reparamMeshVertexOnFace(v1, gf, p1);
      MVertex *v2 = corners[2]; SPoint2 p2; reparamMeshVertexOnFace(v2, gf, p2);
      MVertex *v3 = corners[3]; SPoint2 p3; reparamMeshVertexOnFace(v3, gf, p3);
      MVertex *v4 = corners[4]; SPoint2 p4; reparamMeshVertexOnFace(v4, gf, p4);

      MVertex *v01 = bnodes[a1]; SPoint2 p01; reparamMeshVertexOnFace(v01, gf, p01);
      MVertex *v12 = bnodes[a1+a3+a2]; SPoint2 p12; reparamMeshVertexOnFace(v12, gf, p12);
      MVertex *v23 = bnodes[a1+a3+a2+a4+a3]; SPoint2 p23; reparamMeshVertexOnFace(v23, gf, p23);
      MVertex *v34 = bnodes[a1+a3+a2+a4+a3+a5+a4]; SPoint2 p34; reparamMeshVertexOnFace(v34, gf, p34);
      MVertex *v40 = bnodes[a1+a3+a2+a4+a3+a5+a4+a1+a5]; SPoint2 p40; reparamMeshVertexOnFace(v40, gf, p40);
      SPoint2 p01234 = (p01+p12+p23+p34+p40)*(1./5.0); MVertex *v01234 = createNewVertex (gf, p01234);

      std::vector<MVertex*> e01234_01 = saturateEdge (gf,p01234,p01,a2);
      std::vector<MVertex*> e01234_12 = saturateEdge (gf,p01234,p12,a3);
      std::vector<MVertex*> e01234_23 = saturateEdge (gf,p01234,p23,a4);
      std::vector<MVertex*> e01234_34 = saturateEdge (gf,p01234,p34,a5);
      std::vector<MVertex*> e01234_40 = saturateEdge (gf,p01234,p40,a1);

      std::vector<MVertex*> e0_01,e01_1,e1_12,e12_2,e2_23,e23_3,e3_34,e34_4,e4_40,e40_0;
      for (int i=0;i<a1-1;i++)e0_01.push_back(bnodes[i+1]);
      for (int i=0;i<a3-1;i++)e01_1.push_back(bnodes[i+1 + a1]);
      for (int i=0;i<a2-1;i++)e1_12.push_back(bnodes[i+1 + a1 + a3]);
      for (int i=0;i<a4-1;i++)e12_2.push_back(bnodes[i+1 + a1 + a3 + a2]);
      for (int i=0;i<a3-1;i++)e2_23.push_back(bnodes[i+1 + a1 + a3 + a2 + a4]);
      for (int i=0;i<a5-1;i++)e23_3.push_back(bnodes[i+1 + a1 + a3 + a2 + a4 + a3]);
      for (int i=0;i<a4-1;i++)e3_34.push_back(bnodes[i+1 + a1 + a3 + a2 + a4 + a3 + a5]);
      for (int i=0;i<a1-1;i++)e34_4.push_back(bnodes[i+1 + a1 + a3 + a2 + a4 + a3 + a5 + a4]);
      for (int i=0;i<a5-1;i++)e4_40.push_back(bnodes[i+1 + a1 + a3 + a2 + a4 + a3 + a5 + a4 + a1]);
      for (int i=0;i<a2-1;i++)e40_0.push_back(bnodes[i+1 + a1 + a3 + a2 + a4 + a3 + a5 + a4 + a1 + a5]);

      std::vector<MQuadrangle*> q;
      // 1
      createRegularMesh (gf,
			 v01234,p01234,
			 e01234_01, +1,
			 v01,p01,
			 e0_01, -1,
			 v0,p0,
			 e40_0, -1,
			 v40,p40,
			 e01234_40, -1,
			 q);

      // 2
      createRegularMesh (gf,
			 v01234,p01234,
			 e01234_12, +1,
			 v12,p12,
			 e1_12, -1,
			 v1,p1,
			 e01_1, -1,
			 v01,p01,
			 e01234_01, -1,
			 q);
      // 3
      createRegularMesh (gf,
			 v01234,p01234,
			 e01234_23, +1,
			 v23,p23,
			 e2_23, -1,
			 v2,p2,
			 e12_2, -1,
			 v12,p12,
			 e01234_12, -1,
			 q);

      // 4
      createRegularMesh (gf,
			 v01234,p01234,
			 e01234_34, +1,
			 v34,p34,
			 e3_34, -1,
			 v3,p3,
			 e23_3, -1,
			 v23,p23,
			 e01234_23, -1,
			 q);

      // 5
      createRegularMesh (gf,
			 v01234,p01234,
			 e01234_40, +1,
			 v40,p40,
			 e4_40, -1,
			 v4,p4,
			 e34_4, -1,
			 v34,p34,
			 e01234_34, -1,
			 q);

      // YES

            printBlob(iter+9910000);
      updateQuadCavity (gf,adj,quads,q);
      quads.clear();
      quads.insert(quads.begin(),q.begin(),q.end());
      //      printBlob(iter+20000);
      return 1;
      //      getchar();
    }
    return 0;
  }
};

bool quadBlob::matricesDone = false;
fullMatrix<double> quadBlob::M3;
fullMatrix<double> quadBlob::M5;

static int _defectsRemovalBunin(GFace *gf, int maxCavitySize)
{
  if (maxCavitySize == 0)return 0;
  v2t_cont adj;
  std::vector<MElement*> c;
  buildVertexToElement(gf->quadrangles, adj);
  quadBlob::computeMatrices();

  int iter = 0;
  //  printf("%d adj\n",adj.size());
  std::vector<MVertex*> defects;
  v2t_cont :: iterator it = adj.begin();
  double t1 = Cpu();
  while (it != adj.end()) {
    if (it->first->onWhat()->dim() == 2 && it->second.size() != 4) {
      defects.push_back(it->first);
    }
    ++it;
  }
  double t2 = Cpu();
  double C = (t2-t1);
  double A=0,B=0;
  for (int i=0;i<defects.size();i++){
    it = adj.find(defects[i]);
    if (it->first->onWhat()->dim() == 2 && it->second.size() != 4 && it->second.size() != 0) {
      double t3 = Cpu();
      std::vector<MVertex*> path = closestPathBetweenTwoDefects (adj,it);
      double t4 = Cpu();
      B += (t4-t3);
      if (path.size()){
	double t5 = Cpu();
	quadBlob blob(adj,path,gf, maxCavitySize);
	if(blob.construct_meshable_blob (iter)){
	  blob.smooth(2*(int)(sqrt((double)maxCavitySize)));
	  iter ++;
	  //	  if (iter > 0)break;
	}
	double t6 = Cpu();
	A += (t6-t5);
      }
    }
    ++it;
  }
  Msg::Debug("%i blobs remeshed %g %g %g",iter,A,B,C);

  return iter;
}

static int _splitFlatQuads(GFace *gf, double minQual)
{
  // if a vertex is adjacent to one only quad
  // and if thet quad is badly shaped, we split this
  // quad
  v2t_cont adj;
  buildVertexToElement(gf->triangles,adj);
  buildVertexToElement(gf->quadrangles,adj);
  v2t_cont :: iterator it = adj.begin();

  std::vector<MQuadrangle*> added_quadrangles;
  std::set<MElement*> deleted_quadrangles;
  while (it != adj.end()) {
    bool skip=false;
    double surfaceRef=0;
    // split that guy if too bad
    if(it->second.size()==1 && it->first->onWhat()->dim() < 2) {
      const std::vector<MElement*> &lt = it->second;
      MElement *e = lt[0];
      if (e->getNumVertices() == 4 && e->etaShapeMeasure() < minQual){
	int k=0;
	while(1){
	  if (e->getVertex(k) == it->first){
	    break;
	  }
	  k++;
	  if (k >= e->getNumVertices()) return -1;
	}
	MVertex *v1 = e->getVertex((k+0)%4);
	MVertex *v3 = e->getVertex((k+1)%4);
	MVertex *v2 = e->getVertex((k+2)%4);
	MVertex *v4 = e->getVertex((k+3)%4);
	SPoint2 pv1,pv2,pv3,pv4,pb1,pb2,pb3,pb4;
	reparamMeshEdgeOnFace (v1,v3,gf,pv1,pv3);
	reparamMeshEdgeOnFace (v1,v4,gf,pv1,pv4);
	reparamMeshEdgeOnFace (v1,v2,gf,pv1,pv2);
	pb1 = pv1 * (2./3.) + pv2 * (1./3.);
	pb2 = pv1 * (1./3.) + pv2 * (2./3.);
	pb3 = pv1 * (1./3.) + pv2 * (1./3.) + pv3 * (1./3.);
	pb4 = pv1 * (1./3.) + pv2 * (1./3.) + pv4 * (1./3.);
	GPoint gb1 = gf->point(pb1);
	GPoint gb2 = gf->point(pb2);
	GPoint gb3 = gf->point(pb3);
	GPoint gb4 = gf->point(pb4);
	MFaceVertex *b1 = new MFaceVertex ( gb1.x(),gb1.y(),gb1.z(),gf,gb1.u(), gb1.v());
	MFaceVertex *b2 = new MFaceVertex ( gb2.x(),gb2.y(),gb2.z(),gf,gb2.u(), gb2.v());
	MFaceVertex *b3 = new MFaceVertex ( gb3.x(),gb3.y(),gb3.z(),gf,gb3.u(), gb3.v());
	MFaceVertex *b4 = new MFaceVertex ( gb4.x(),gb4.y(),gb4.z(),gf,gb4.u(), gb4.v());
	deleted_quadrangles.insert(e);
	added_quadrangles.push_back(new MQuadrangle(v1,v3,b3,b1));
	added_quadrangles.push_back(new MQuadrangle(v3,v2,b2,b3));
	added_quadrangles.push_back(new MQuadrangle(v2,v4,b4,b2));
	added_quadrangles.push_back(new MQuadrangle(v4,v1,b1,b4));
	added_quadrangles.push_back(new MQuadrangle(b1,b3,b2,b4));
	gf->mesh_vertices.push_back(b1);
	gf->mesh_vertices.push_back(b2);
	gf->mesh_vertices.push_back(b3);
	gf->mesh_vertices.push_back(b4);
	break;
      }
    }
    ++it;
  }
  for (int i=0;i<gf->quadrangles.size();i++){
    if (deleted_quadrangles.find(gf->quadrangles[i]) == deleted_quadrangles.end()){
      added_quadrangles.push_back(gf->quadrangles[i]);
    }
    else {
      delete gf->quadrangles[i];
    }
  }
  gf->quadrangles = added_quadrangles;
  //  Msg::Debug("%i flat quads removed",deleted_quadrangles.size());
  //Msg::Info("%i flat quads removed",deleted_quadrangles.size());
 return deleted_quadrangles.size();
}

static int _removeDiamonds(GFace *gf)
{
  v2t_cont adj;
  //  buildVertexToElement(gf->triangles,adj);
  buildVertexToElement(gf->quadrangles,adj);
  std::set<MElement*> diamonds;
  std::set<MVertex*> touched;
  std::set<MVertex*> deleted;
  std::vector<MVertex*> mesh_vertices2;
  std::vector<MQuadrangle*> quadrangles2;

  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    touched.insert(gf->triangles[i]->getVertex(0));
    touched.insert(gf->triangles[i]->getVertex(1));
    touched.insert(gf->triangles[i]->getVertex(2));
  }

  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    MVertex *v1 = q->getVertex(0);
    MVertex *v2 = q->getVertex(1);
    MVertex *v3 = q->getVertex(2);
    MVertex *v4 = q->getVertex(3);
    v2t_cont::iterator it1 = adj.find(v1);
    v2t_cont::iterator it2 = adj.find(v2);
    v2t_cont::iterator it3 = adj.find(v3);
    v2t_cont::iterator it4 = adj.find(v4);
    if (touched.find(v1) == touched.end() &&
	touched.find(v2) == touched.end() &&
	touched.find(v3) == touched.end() &&
	touched.find(v4) == touched.end() ) {
      if (_quadWithOneVertexOnBoundary      (gf,touched,diamonds,deleted,it2->second,it4->second,it1->second,q,v1,v2,v3,v4)){}
      else if (_quadWithOneVertexOnBoundary (gf,touched,diamonds,deleted,it3->second,it1->second,it2->second,q,v2,v3,v4,v1)){}
      else if (_quadWithOneVertexOnBoundary (gf,touched,diamonds,deleted,it4->second,it2->second,it3->second,q,v3,v4,v1,v2)){}
      else if (_quadWithOneVertexOnBoundary (gf,touched,diamonds,deleted,it1->second,it3->second,it4->second,q,v4,v1,v2,v3)){}
      else if (v2->onWhat()->dim() == 2 &&
	       v4->onWhat()->dim() == 2 &&
	       v1->onWhat()->dim() == 2 &&
	       v3->onWhat()->dim() == 2 &&
	       it1->second.size() ==3 &&  it3->second.size() == 3 &&
	       _isItAGoodIdeaToCollapseThatVertex (gf, it1->second, it3->second, q, v1, v3, v3,10.)){
	touched.insert(v1);
	touched.insert(v2);
	touched.insert(v3);
	touched.insert(v4);
	for (unsigned int j=0;j<it1->second.size();++j){
	  for (int k=0;k<it1->second[j]->getNumVertices();k++){
	    if (it1->second[j]->getVertex(k) == v1 && it1->second[j] != q)
	      it1->second[j]->setVertex(k,v3);
	  }
	}
	deleted.insert(v1);
	diamonds.insert(q);
      }
      else if (0 && v2->onWhat()->dim() == 2 &&
	       v4->onWhat()->dim() == 2 &&
	       v1->onWhat()->dim() == 2 &&
	       v3->onWhat()->dim() == 2 &&
	       it1->second.size() ==3 &&  it3->second.size() == 3 &&
	       _isItAGoodIdeaToCollapseThatVertex (gf, it1->second, it3->second, q, v1, v3, v1,10.)){
	touched.insert(v1);
	touched.insert(v2);
	touched.insert(v3);
	touched.insert(v4);
	for (unsigned int j=0;j<it3->second.size();++j){
	  for (int k=0;k<it3->second[j]->getNumVertices();k++){
	    if (it3->second[j]->getVertex(k) == v3 && it3->second[j] != q)
	      it3->second[j]->setVertex(k,v1);
	  }
	}
	deleted.insert(v3);
	diamonds.insert(q);
      }
      else if (v1->onWhat()->dim() == 2 &&
	       v3->onWhat()->dim() == 2 &&
	       v2->onWhat()->dim() == 2 &&
	       v4->onWhat()->dim() == 2 &&
	       it2->second.size() == 3 && it4->second.size() == 3 &&
	       _isItAGoodIdeaToCollapseThatVertex (gf, it2->second, it4->second, q, v2, v4, v4,10.)){
	touched.insert(v1);
	touched.insert(v2);
	touched.insert(v3);
	touched.insert(v4);
	for (unsigned int j=0;j<it2->second.size();++j){
	  for (int k=0;k<it2->second[j]->getNumVertices();k++){
	    if (it2->second[j]->getVertex(k) == v2 && it2->second[j] != q)
	      it2->second[j]->setVertex(k,v4);
	  }
	}
	deleted.insert(v2);
	diamonds.insert(q);
      }
      else if (v1->onWhat()->dim() == 2 &&
	       v3->onWhat()->dim() == 2 &&
	       v2->onWhat()->dim() == 2 &&
	       v4->onWhat()->dim() == 2 &&
	       it2->second.size() == 3 && it4->second.size() == 3 &&
	       _isItAGoodIdeaToCollapseThatVertex (gf, it2->second, it4->second, q, v2, v4, v2,10.)){
	touched.insert(v1);
	touched.insert(v2);
	touched.insert(v3);
	touched.insert(v4);
	for (unsigned int j=0;j<it4->second.size();++j){
	  for (int k=0;k<it4->second[j]->getNumVertices();k++){
	    if (it4->second[j]->getVertex(k) == v4 && it4->second[j] != q)
	      it4->second[j]->setVertex(k,v2);
	  }
	}
	deleted.insert(v4);
	diamonds.insert(q);
      }
      else {
	quadrangles2.push_back(q);
      }
    }
    else{
      quadrangles2.push_back(q);
    }
  }
  gf->quadrangles = quadrangles2;

  for(unsigned int i = 0; i < gf->mesh_vertices.size(); i++){
    if(deleted.find(gf->mesh_vertices[i]) == deleted.end()){
      mesh_vertices2.push_back(gf->mesh_vertices[i]);
    }
    else {
      // FIXME : GMSH SOMETIMES CRASHES IF DELETED ....
      //      delete gf->mesh_vertices[i];
    }
  }

  gf->mesh_vertices = mesh_vertices2;

  return diamonds.size();
}

int removeDiamonds(GFace *gf){
  int nbRemove = 0;
  while(1){
    int x = _removeDiamonds(gf);
    if (!x)break;
    nbRemove += x;
  }
  Msg::Debug("%i diamond quads removed",nbRemove);
  return nbRemove;
}

int splitFlatQuads(GFace *gf, double q){
  int nbRemove = 0;
  while(1){
    int x = _splitFlatQuads(gf,q);
    if (!x)break;
    nbRemove += x;
  }
  Msg::Debug("%i flat quads removed",nbRemove);
  return nbRemove;
}

struct p1p2p3 {
  MVertex *p1,*p2;
};

#if defined(HAVE_BFGS)
// Callback function for BFGS

struct opti_data_vertex_relocation {
  const std::vector<MElement*> & e;
  MVertex *v;
  GFace *gf;
  double minq,eps;
  opti_data_vertex_relocation (const std::vector<MElement*> & _e, MVertex * _v, GFace *_gf) : e(_e), v(_v), gf(_gf)
  {
    minq = -2;
    eps = minq / (1. - minq);
  }
  double f() const {
    double val = 0.0;
    for (int i=0;i < e.size();i++){
      const double q = (e[i]->getNumVertices() == 4) ? e[i]->etaShapeMeasure() :
	e[i]->gammaShapeMeasure();
      const double dd = (1 + eps) * q - eps;
      const double  l = (dd>0) ? log (dd) : 1.e22;
      const double  m = (q-1);
      val += l * l + m*m;
    }
    return val;
  }
  void df(const double &F, const double &U, const double &V, double &dfdu, double &dfdv)  {
    const double eps = 1.e-6;
    set_(U+eps,V);
    const double FU = f();
    set_(U,V+eps);
    const double FV = f();
    set_(U,V);
    dfdu = -(F-FU)/eps;
    dfdv = -(F-FV)/eps;
  }
  void set_(double U, double V){
    GPoint gp = gf->point(U,V);
    v->x() = gp.x();
    v->y() = gp.y();
    v->z() = gp.z();
    v->setParameter(0,U);
    v->setParameter(1,V);
  }
};

void bfgs_callback_vertex_relocation (const alglib::real_1d_array& x, double& func, alglib::real_1d_array& grad, void* ptr) {
  opti_data_vertex_relocation* w = static_cast<opti_data_vertex_relocation*>(ptr);
  w->set_(x[0],x[1]);
  func = w->f();
  //  printf("F(%3.2f,%3.2f) = %12.5E\n",x[0],x[1],func);
  w->df(func,x[0],x[1],grad[0],grad[1]);
}

// use optimization
static void _relocateVertexOpti(GFace *gf, MVertex *ver,
				const std::vector<MElement*> &lt)
{
  // DOES NOT WORK AT ALL !!!
  return;
  if(ver->onWhat()->dim() != 2)return;
  printf("heyhey\n");
  //  printf ("optimizing vertex position with BFGS\n");
  // we optimize the local coordinates of the node
  alglib::ae_int_t dim = 2;
  alglib::ae_int_t corr = 2; // Num of corrections in the scheme in [3,7]
  alglib::minlbfgsstate state;
  alglib::real_1d_array x; // = "[0.5,0.5]";
  std::vector<double> initial_conditions(dim);
  opti_data_vertex_relocation data(lt,ver,gf);
  double U, V;
  ver->getParameter(0,U);
  ver->getParameter(1,V);
  initial_conditions[0] = U;
  initial_conditions[1] = V;
  x.setcontent(dim, &initial_conditions[0]);
  minlbfgscreate(2, corr, x, state);
  double epsg = 1.e-12;
  double epsf = 0.0;
  double epsx = 0.0;
  alglib::ae_int_t maxits = 10;
  minlbfgssetcond(state,epsg,epsf,epsx,maxits);
  minlbfgsoptimize(state, bfgs_callback_vertex_relocation,NULL,&data);
  alglib::minlbfgsreport rep;
  minlbfgsresults(state,x,rep);

  double minq = 0;
  for (int i=0;i < data.e.size();i++){
    const double q = (data.e[i]->getNumVertices() == 4) ? data.e[i]->etaShapeMeasure() :
      data.e[i]->gammaShapeMeasure();
    minq = std::min(q,minq);
  }
  if (minq < 0.01)data.set_(U,V);
  else printf("OKIDOKI\n");
  //  if (rep.terminationtype != 4){
  //    data.set_(U,V);
  //  }
  printf("heyhey -- end\n");
}
#endif

static void _relocateVertex(GFace *gf, MVertex *ver,
                            const std::vector<MElement*> &lt)
{
  double R;
  SPoint3 c;
  bool isSphere = gf->isSphere(R, c);

  if(ver->onWhat()->dim() != 2) return;
  MFaceVertex *fv = dynamic_cast<MFaceVertex*>(ver);
  if(fv->bl_data) return;

  double initu,initv;
  ver->getParameter(0, initu);
  ver->getParameter(1, initv);
  double cu = 0, cv = 0;
  double XX=0,YY=0,ZZ=0;
  double pu[4], pv[4];
  double fact  = 0.0;
  for(unsigned int i = 0; i < lt.size(); i++){
    parametricCoordinates(lt[i], gf, pu, pv, ver);
    double XCG=0,YCG=0,ZCG=0;
    for (int j=0;j<lt[i]->getNumVertices();j++){
      XCG += lt[i]->getVertex(j)->x();
      YCG += lt[i]->getVertex(j)->y();
      ZCG += lt[i]->getVertex(j)->z();
    }
    XX += XCG;
    YY += YCG;
    ZZ += ZCG;

    //    double D = 1./sqrt((XCG-ver->x())*(XCG-ver->x()) +
    //		    (YCG-ver->y())*(YCG-ver->y()) +
    //		    (ZCG-ver->z())*(ZCG-ver->z()) );
    double D = 1.0;
    for (int j=0;j<lt[i]->getNumVertices();j++){
      cu += pu[j]*D;
      cv += pv[j]*D;
    }
    fact += lt[i]->getNumVertices() * D;
  }
  SPoint2 newp ;
  if(fact != 0.0){
    SPoint2 before(initu,initv);
    SPoint2 after(cu / fact,cv / fact);
    if (isSphere){
      GPoint gp = gf->closestPoint(SPoint3(XX/fact, YY/fact, ZZ/fact), after);
      after = SPoint2(gp.u(),gp.v());
    }
    bool success = _isItAGoodIdeaToMoveThatVertex (gf,  lt, ver,before,after);

    if (success){
      ver->setParameter(0, after.x());
      ver->setParameter(1, after.y());
      GPoint pt = gf->point(after);
      if(pt.succeeded()){
	ver->x() = pt.x();
	ver->y() = pt.y();
	ver->z() = pt.z();
      }
    }
    else{
#if defined(HAVE_BFGS)
            _relocateVertexOpti(gf, ver, lt);
#endif
    }
  }
}

void quadBlob::smooth (int niter) {
  for (int i=0;i<niter;i++){
    for (int j=0;j<nodes.size();j++){
      v2t_cont::iterator it = adj.find(nodes[j]);
      _relocateVertex(gf, it->first, it->second);
    }
  }
}

void laplaceSmoothing(GFace *gf, int niter)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  for(int i = 0; i < niter; i++){
    v2t_cont::iterator it = adj.begin();
    while (it != adj.end()){
      _relocateVertex(gf, it->first, it->second);
      ++it;
    }
  }
}

int _edgeSwapQuadsForBetterQuality(GFace *gf)
{
  e2t_cont adj;
  //  buildEdgeToElement(gf->triangles, adj);
  buildEdgeToElement(gf, adj);

  std::vector<MQuadrangle*>created;
  std::set<MElement*>deleted;

  int COUNT = 0;

  for(e2t_cont::iterator it = adj.begin(); it!= adj.end(); ++it){
    if(it->second.second &&
       it->second.first->getNumVertices() == 4 &&
       it->second.second->getNumVertices() == 4){
      MVertex *v1 = it->first.getVertex(0);
      MVertex *v2 = it->first.getVertex(1);
      MElement *e1 = it->second.first;
      MElement *e2 = it->second.second;

      double worst_quality_old = std::min(e1->etaShapeMeasure(),e2->etaShapeMeasure());

      /*
      if (!diff2(e1,e2)){
	e1->writeMSH(stdout);
	e2->writeMSH(stdout);
	SANITY_(gf,3);
	Msg::Fatal("You found a BUG in the quad optimization routines of Gmsh Line %d of FILE %s (%p %p)",__LINE__,__FILE__,e1,e2);
      }
      */

      if (worst_quality_old < .3 && (
	  deleted.find(e1) == deleted.end() ||
	  deleted.find(e2) == deleted.end())){
	MVertex *v12=0,*v11=0,*v22=0,*v21=0;
	for (int i=0;i<4;i++){
	  MEdge ed = e1->getEdge(i);
	  if (ed.getVertex(0) == v1 && ed.getVertex(1) != v2)v11 = ed.getVertex(1);
	  if (ed.getVertex(1) == v1 && ed.getVertex(0) != v2)v11 = ed.getVertex(0);
	  if (ed.getVertex(0) == v2 && ed.getVertex(1) != v1)v12 = ed.getVertex(1);
	  if (ed.getVertex(1) == v2 && ed.getVertex(0) != v1)v12 = ed.getVertex(0);
	  ed = e2->getEdge(i);
	  if (ed.getVertex(0) == v1 && ed.getVertex(1) != v2)v21 = ed.getVertex(1);
	  if (ed.getVertex(1) == v1 && ed.getVertex(0) != v2)v21 = ed.getVertex(0);
	  if (ed.getVertex(0) == v2 && ed.getVertex(1) != v1)v22 = ed.getVertex(1);
	  if (ed.getVertex(1) == v2 && ed.getVertex(0) != v1)v22 = ed.getVertex(0);
	}
	if (!v11 || !v12 || !v21 || !v22){
	  Msg::Error("You found a BUG in the quad optimization routines of Gmsh Line %d of FILE %s",__LINE__,__FILE__);
	  return 0;
	}

	MQuadrangle *q1A = new MQuadrangle (v11,v22,v2,v12);
	MQuadrangle *q2A = new MQuadrangle (v22,v11,v1,v21);
	MQuadrangle *q1B = new MQuadrangle (v11,v12,v21,v1);
	MQuadrangle *q2B = new MQuadrangle (v21,v12,v2,v22);
	double worst_quality_A = std::min(q1A->etaShapeMeasure(),q2A->etaShapeMeasure());
	double worst_quality_B = std::min(q1B->etaShapeMeasure(),q2B->etaShapeMeasure());
	//	printf("worst_quality_old = %g worst_quality_A = %g worst_quality_B = %g\n",worst_quality_old,worst_quality_A,worst_quality_B);

	bool c1,c2,ca1,ca2,cb1,cb2;
	double old_surface = surfaceFaceUV(e1,gf) + surfaceFaceUV(e2,gf) ;
	double new_surface_A = surfaceFaceUV(q1A,gf,&ca1) + surfaceFaceUV(q2A,gf,&ca2) ;
	double new_surface_B = surfaceFaceUV(q1B,gf,&cb1) + surfaceFaceUV(q2B,gf,&cb2) ;

	if (!ca1 && !ca2 &&
	    fabs(old_surface - new_surface_A) < 1.e-10 * old_surface &&
	    0.8*worst_quality_A > worst_quality_old &&
	    0.8*worst_quality_A > worst_quality_B &&
	    SANITY_(gf,q1A,q2A,12121)){
	  deleted.insert(e1);
	  deleted.insert(e2);
	  created.push_back(q1A);
	  created.push_back(q2A);
	  delete q1B;
	  delete q2B;
	  //printf("edge swap performed -- 1\n");
	  COUNT++;
	}
	else if (!cb1 && !cb2 &&
		 fabs(old_surface - new_surface_B) < 1.e-10 * old_surface  &&
		 0.8*worst_quality_B > worst_quality_old &&
		 0.8*worst_quality_B > worst_quality_A &&
		 SANITY_(gf,q1B,q2B,12121)){
	  deleted.insert(e1);
	  deleted.insert(e2);
	  created.push_back(q1B);
	  created.push_back(q2B);
	  delete q1A;
	  delete q2A;
	  //printf("edge swap performed -- 2\n");
	  COUNT++;
	}
	else {
	  delete q1A;
	  delete q2A;
	  delete q1B;
	  delete q2B;
	}
      }
    }
    if (COUNT)break;
  }

  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    if(deleted.find(gf->quadrangles[i]) == deleted.end()){
      created.push_back(gf->quadrangles[i]);
    }
    else {
      delete gf->quadrangles[i];
    }
  }
  gf->quadrangles = created;
  return COUNT;
}

static int  edgeSwapQuadsForBetterQuality ( GFace *gf ) {
  int COUNT = 0;
  while(1){
    int k = _edgeSwapQuadsForBetterQuality (gf);
    COUNT += k;
    if (!k || COUNT > 10)break;
  }
  Msg::Debug("%i swap quads performed",COUNT);
  return COUNT;
}

static std::vector<MVertex*> computeBoundingPoints (const std::vector<MElement*> &lt,MVertex *v = 0){

  // get boundary edges
  std::set<MEdge,Less_Edge> edges;
  for (int i=0;i<lt.size();i++){
    for (int j=0;j<lt[i]->getNumEdges();j++){
      std::set<MEdge,Less_Edge>::iterator it = edges.find(lt[i]->getEdge(j));
      if (it == edges.end())
	edges.insert(lt[i]->getEdge(j));
      else
	edges.erase(it);
    }
  }
  std::set<MEdge,Less_Edge>::iterator it = edges.begin();
  std::list<MEdge> border;
  bool closed = true;
  for ( ; it != edges.end() ; ++it){
    if (it->getVertex(0) == v || it->getVertex(1) == v){
      closed = false;
    }
    else {
      border.push_back(*it);
    }
  }
  // we got all boundary edges
  std::list<MVertex *> oriented;
  {
    std::list<MEdge>::iterator itsz = border.begin();
    border.erase (itsz);
    oriented.push_back(itsz->getVertex(0));
    oriented.push_back(itsz->getVertex(1));
  }
  while (border.size()){
    std::list<MVertex*>::iterator itb = oriented.begin();
    std::list<MVertex*>::iterator ite = oriented.end(); ite--;
    std::list<MEdge>::iterator itx = border.begin();
    for (  ; itx != border.end() ; ++itx){
      MVertex *a  = itx->getVertex(0);
      MVertex *b  = itx->getVertex(1);
      if (a == *itb){
	oriented.push_front(b);
	break;
      }
      if (b == *itb){
	oriented.push_front(a);
	break;
      }
      if (a == *ite){
	oriented.push_back(b);
	break;
      }
      if (b == *ite){
	oriented.push_back(a);
	break;
      }
    }
    if (itx == border.end())Msg::Error ("error in quadrilateralization");
    border.erase (itx);
  }
  std::vector<MVertex*> result;
  result.insert(result.begin(),oriented.begin(),oriented.end());
  return result;
}


int postProcessExtraEdges (GFace *gf, std::vector<std::pair<MElement*,MElement*> > &toProcess){

  // some pairs of elements that should be recombined are not neighbor elements (see our paper)
  // so we recombine them in another way (adding a new node)


  Msg::Debug("%d extra edges to be processed",(int)toProcess.size());

  //  return 1;

  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);

  std::set<MElement*>deleted;

  for (int i=0; i<toProcess.size() ; i++){
    MElement *t1 = toProcess[i].first;
    MElement *t2 = toProcess[i].second;
    MVertex *common = 0;
    for (int j=0;j<3;j++){
      if (t1->getVertex(j) == t2->getVertex(0) ||
	  t1->getVertex(j) == t2->getVertex(1) ||
	  t1->getVertex(j) == t2->getVertex(2) ){
	common = t1->getVertex(j);
	break;
      }
    }
    //    printf("extra edge %d common vertex %p\n",i,common);
    if (common){
      deleted.insert(t1);
      deleted.insert(t2);
      v2t_cont :: iterator it = adj.find(common);
      if(it != adj.end()){
	const std::vector<MElement*> &lt = it->second;
	// simply swap one edge
	printf("%d elements surrounding the common vertex\n",(int)lt.size());
	if (lt.size() == 3){
	  std::vector<MVertex*> VERTS  = computeBoundingPoints (lt,common);
	  if (VERTS.size() != 5)return -1;
	  gf->quadrangles.push_back(new MQuadrangle(VERTS[0],VERTS[1],VERTS[2],common));
	  gf->quadrangles.push_back(new MQuadrangle(VERTS[2],VERTS[3],VERTS[4],common));
	  deleted.insert(lt[0]);
	  deleted.insert(lt[1]);
	  deleted.insert(lt[2]);
	}
	// create a new vertex
	else {
	  SPoint2 p;
	  bool success = reparamMeshVertexOnFace(it->first,gf, p);
	  MFaceVertex *newVertex = new MFaceVertex (it->first->x(),
						    it->first->y(),
						    it->first->z(),
						    gf,
						    p.x(),
						    p.y());
	  gf->mesh_vertices.push_back(newVertex);
	  int start1,start2;
	  int orientation1=1, orientation2=1;
	  for (int k=0;k<3;k++){
	    if (t1->getVertex(k) == it->first){
	      //	      if (t1->getVertex((k+1)%3)->onWhat()->dim
	      start1 = k;
	    }
	    if (t2->getVertex(k) == it->first)start2 = k;
	  }
	  /*
	    FIX THAT !!!!!
	    x--------x--------x
             \ t1   / \  t2  /
              \    /   \    /
               \  /     \  /
                \/       \/

	   */
	  MQuadrangle *q1;
	  if (orientation1)
	    q1 = new MQuadrangle(t1->getVertex(start1),
				 newVertex,
				 t1->getVertex((start1+1)%3),
				 t1->getVertex((start1+2)%3));
	  else
	    q1 = new MQuadrangle(newVertex,
				 t1->getVertex((start1+2)%3),
				 t1->getVertex((start1+1)%3),
				 t1->getVertex(start1));

	  MQuadrangle *q2;
	  if (orientation2)
	    q2 = new MQuadrangle(t2->getVertex(start2),
				 newVertex,
				 t2->getVertex((start2+1)%3),
				 t2->getVertex((start2+2)%3));
	  else
	    q2 = new MQuadrangle(newVertex,
				 t2->getVertex((start2+2)%3),
				 t2->getVertex((start2+1)%3),
				 t2->getVertex(start2));


	  std::vector<MElement*> newAdj;
	  newAdj.push_back(q1);
	  newAdj.push_back(q2);
	  for (int k=0;k<it->second.size();k++){
	    if (it->second[k]->getNumVertices() == 4){
	      newAdj.push_back(it->second[k]);
	      for (int vv=0;vv<4;vv++){
		if (it->first == it->second[k]->getVertex(vv))
		  it->second[k]->setVertex(vv,newVertex);
	      }
	    }
	  }
	  gf->quadrangles.push_back(q1);
	  gf->quadrangles.push_back(q2);
	  _relocateVertex(gf,newVertex,newAdj);
	}
      }
    }
  }

  {
    std::vector<MTriangle*>remained;
    for(unsigned int i = 0; i < gf->triangles.size(); i++){
      if(deleted.find(gf->triangles[i]) == deleted.end()){
	remained.push_back(gf->triangles[i]);
      }
      else {
	delete gf->triangles[i];
      }
    }
    gf->triangles = remained;
  }
  {
    std::vector<MQuadrangle*>remained;
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
      if(deleted.find(gf->quadrangles[i]) == deleted.end()){
	remained.push_back(gf->quadrangles[i]);
      }
      else {
	delete gf->quadrangles[i];
      }
    }
    gf->quadrangles = remained;
  }
  return 0;
}

bool edgeSwap(std::set<swapquad> &configs, MTri3 *t1, GFace *gf, int iLocalEdge,
              std::vector<MTri3*> &newTris, const swapCriterion &cr,
              const std::vector<double> &Us, const std::vector<double> &Vs,
              const std::vector<double> &vSizes, const std::vector<double> &vSizesBGM)
{
  MTri3 *t2 = t1->getNeigh(iLocalEdge);
  if(!t2) return false;

  MVertex *v1 = t1->tri()->getVertex(iLocalEdge == 0 ? 2 : iLocalEdge - 1);
  MVertex *v2 = t1->tri()->getVertex((iLocalEdge) % 3);
  MVertex *v3 = t1->tri()->getVertex((iLocalEdge + 1) % 3);
  MVertex *v4 = 0;
  for(int i = 0; i < 3; i++)
    if(t2->tri()->getVertex(i) != v1 && t2->tri()->getVertex(i) != v2)
      v4 = t2->tri()->getVertex(i);

  swapquad sq (v1, v2, v3, v4);
  if(configs.find(sq) != configs.end()) return false;
  configs.insert(sq);

  const double volumeRef = surfaceTriangleUV(v1, v2, v3, Us, Vs) +
    surfaceTriangleUV(v1, v2, v4, Us, Vs);

  MTriangle *t1b = new MTriangle(v2, v3, v4);
  MTriangle *t2b = new MTriangle(v4, v3, v1);
  const double v1b = surfaceTriangleUV(v2, v3, v4, Us, Vs);
  const double v2b = surfaceTriangleUV(v4, v3, v1, Us, Vs);
  const double volume = v1b + v2b;
  if(fabs(volume - volumeRef) > 1.e-10 * (volume + volumeRef) ||
      v1b < 1.e-8 * (volume + volumeRef) ||
      v2b < 1.e-8 * (volume + volumeRef)){
    delete t1b;
    delete t2b;
    return false;
  }

  switch(cr){
  case SWCR_QUAL:
    {
      const double triQualityRef = std::min(qmTriangle(t1->tri(), QMTRI_RHO),
                                            qmTriangle(t2->tri(), QMTRI_RHO));
      const double triQuality = std::min(qmTriangle(t1b, QMTRI_RHO),
                                         qmTriangle(t2b, QMTRI_RHO));
      if(triQuality < triQualityRef){
        delete t1b;
        delete t2b;
        return false;
      }
      break;
    }
  case SWCR_DEL:
    {
      double edgeCenter[2] ={(Us[v1->getIndex()] + Us[v2->getIndex()] + Us[v3->getIndex()] +
                              Us[v4->getIndex()]) * .25,
                             (Vs[v1->getIndex()] + Vs[v2->getIndex()] + Vs[v3->getIndex()] +
                              Vs[v4->getIndex()]) * .25};
      double uv4[2] ={Us[v4->getIndex()], Vs[v4->getIndex()]};
      double metric[3];
      buildMetric(gf, edgeCenter, metric);
      if(!inCircumCircleAniso(gf, t1->tri(), uv4, metric, Us, Vs)){
        delete t1b;
        delete t2b;
        return false;
      }
    }
    break;
  case SWCR_CLOSE:
    {
      double avg1[3] = {(v1->x() + v2->x()) *.5,(v1->y() + v2->y()) *.5,
                        (v1->z() + v2->z()) *.5};
      double avg2[3] = {(v3->x() + v4->x()) *.5,(v3->y() + v4->y()) *.5,
                        (v3->z() + v4->z()) *.5};

      GPoint gp1 = gf->point(SPoint2((Us[v1->getIndex()] + Us[v2->getIndex()]) * .5,
                                     (Vs[v1->getIndex()] + Vs[v2->getIndex()]) * .5));
      GPoint gp2 = gf->point(SPoint2((Us[v3->getIndex()] + Us[v4->getIndex()]) * .5,
                                     (Vs[v3->getIndex()] + Vs[v4->getIndex()]) * .5));
      double d1 = (avg1[0] - gp1.x()) * (avg1[0] - gp1.x()) + (avg1[1] - gp1.y()) *
        (avg1[1]-gp1.y()) + (avg1[2] - gp1.z()) * (avg1[2] - gp1.z());
      double d2 = (avg2[0] - gp2.x()) * (avg2[0] - gp2.x()) + (avg2[1] - gp2.y()) *
        (avg2[1] - gp2.y()) + (avg2[2] - gp2.z()) * (avg2[2] - gp2.z());
      if(d1 < d2){
        delete t1b;
        delete t2b;
        return false;
      }
    }
    break;
  default :
    Msg::Error("Unknown swapping criterion");
    return false;
  }

  std::list<MTri3*> cavity;
  for(int i = 0; i < 3; i++){
    if(t1->getNeigh(i) && t1->getNeigh(i) != t2){
      bool found = false;
      for(std::list<MTri3*>::iterator it = cavity.begin(); it != cavity.end(); it++){
        if(*it == t1->getNeigh(i)) found = true;
      }
      if(!found)cavity.push_back(t1->getNeigh(i));
    }
  }
  for(int i = 0; i < 3; i++){
    if(t2->getNeigh(i) && t2->getNeigh(i) != t1){
      bool found = false;
      for(std::list<MTri3*>::iterator it = cavity.begin(); it != cavity.end(); it++){
        if(*it == t2->getNeigh(i)) found = true;
      }
      if(!found)cavity.push_back(t2->getNeigh(i));
    }
  }
  double lc1 = 0.3333333333 * (vSizes[t1b->getVertex(0)->getIndex()] +
                               vSizes[t1b->getVertex(1)->getIndex()] +
                               vSizes[t1b->getVertex(2)->getIndex()]);
  double lcBGM1 = 0.3333333333 * (vSizesBGM[t1b->getVertex(0)->getIndex()] +
                                  vSizesBGM[t1b->getVertex(1)->getIndex()] +
                                  vSizesBGM[t1b->getVertex(2)->getIndex()]);
  double lc2 = 0.3333333333 * (vSizes[t2b->getVertex(0)->getIndex()] +
                               vSizes[t2b->getVertex(1)->getIndex()] +
                               vSizes[t2b->getVertex(2)->getIndex()]);
  double lcBGM2 = 0.3333333333 * (vSizesBGM[t2b->getVertex(0)->getIndex()] +
                                  vSizesBGM[t2b->getVertex(1)->getIndex()] +
                                  vSizesBGM[t2b->getVertex(2)->getIndex()]);
  MTri3 *t1b3 = new MTri3(t1b, Extend1dMeshIn2dSurfaces() ?
                          std::min(lc1, lcBGM1) : lcBGM1, 0, &Us, &Vs, gf);
  MTri3 *t2b3 = new MTri3(t2b, Extend1dMeshIn2dSurfaces() ?
                          std::min(lc2, lcBGM2) : lcBGM2, 0, &Us, &Vs, gf);

  cavity.push_back(t1b3);
  cavity.push_back(t2b3);
  t1->setDeleted(true);
  t2->setDeleted(true);
  connectTriangles(cavity);
  newTris.push_back(t1b3);
  newTris.push_back(t2b3);

  return true;
}

int edgeSwapPass(GFace *gf, std::set<MTri3*, compareTri3Ptr> &allTris,
                 const swapCriterion &cr,
                 const std::vector<double> &Us, const std::vector<double> &Vs,
                 const std::vector<double> &vSizes, const std::vector<double> &vSizesBGM)
{
  typedef std::set<MTri3*, compareTri3Ptr> CONTAINER;

  int nbSwapTot = 0;
  std::set<swapquad> configs;
  for(int iter = 0; iter < 1200; iter++){
    int nbSwap = 0;
    std::vector<MTri3*> newTris;
    for(CONTAINER::iterator it = allTris.begin(); it != allTris.end(); ++it){
      if(!(*it)->isDeleted()){
        for(int i = 0; i < 3; i++){
          if(edgeSwap(configs, *it, gf, i, newTris, cr, Us, Vs, vSizes, vSizesBGM)){
            nbSwap++;
            break;
          }
        }
      }
      else{
        delete *it;
        CONTAINER::iterator itb = it;
        ++it;
        allTris.erase(itb);
        if(it == allTris.end()) break;
      }
    }
    allTris.insert(newTris.begin(), newTris.end());
    nbSwapTot += nbSwap;
    if(nbSwap == 0) break;
  }
  return nbSwapTot;
}



inline double computeEdgeAdimLength(MVertex *v1, MVertex *v2, GFace *f,
                                    const std::vector<double> &Us,
                                    const std::vector<double> &Vs,
                                    const std::vector<double> &vSizes ,
                                    const std::vector<double> &vSizesBGM)
{
  const double edgeCenter[2] ={(Us[v1->getIndex()] + Us[v2->getIndex()]) * .5,
                               (Vs[v1->getIndex()] + Vs[v2->getIndex()]) * .5};
  GPoint GP = f->point (edgeCenter[0], edgeCenter[1]);

  const double dx1 = v1->x() - GP.x();
  const double dy1 = v1->y() - GP.y();
  const double dz1 = v1->z() - GP.z();
  const double l1 = sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
  const double dx2 = v2->x() - GP.x();
  const double dy2 = v2->y() - GP.y();
  const double dz2 = v2->z() - GP.z();
  const double l2 = sqrt(dx2 * dx2 + dy2 * dy2 + dz2 * dz2);
  if(Extend1dMeshIn2dSurfaces())
    return 2 * (l1 + l2) / (std::min(vSizes[v1->getIndex()], vSizesBGM[v1->getIndex()]) +
                            std::min(vSizes[v2->getIndex()], vSizesBGM[v2->getIndex()]));
  return 2 * (l1 + l2) / (vSizesBGM[v1->getIndex()] + vSizesBGM[v2->getIndex()]);
}


void computeNeighboringTrisOfACavity(const std::vector<MTri3*> &cavity,
                                     std::vector<MTri3*> &outside)
{
  outside.clear();
  for(unsigned int i = 0; i < cavity.size(); i++){
    for(int j = 0; j < 3; j++){
      MTri3 * neigh = cavity[i]->getNeigh(j);
      if(neigh){
        bool found = false;
        for(unsigned int k = 0; k < outside.size(); k++){
          if(outside[k] == neigh){
            found = true;
            break;
          }
        }
        if(!found){
          for(unsigned int k = 0; k < cavity.size(); k++){
            if(cavity[k] == neigh){
              found = true;
            }
          }
        }
        if(!found) outside.push_back(neigh);
      }
    }
  }
}

bool buildVertexCavity(MTri3 *t, int iLocalVertex, MVertex **v1,
                       std::vector<MTri3*> &cavity, std::vector<MTri3*> &outside,
                       std::vector<MVertex*> &ring)
{
  cavity.clear();
  ring.clear();

  *v1 = t->tri()->getVertex(iLocalVertex);

  MVertex *lastinring = t->tri()->getVertex((iLocalVertex + 1) % 3);
  ring.push_back(lastinring);
  cavity.push_back(t);

  while (1){
    int iEdge = -1;
    for(int i = 0; i < 3; i++){
      MVertex *v2  = t->tri()->getVertex((i + 2) % 3);
      MVertex *v3  = t->tri()->getVertex(i);
      if((v2 == *v1 && v3 == lastinring) ||
          (v2 == lastinring && v3 == *v1)){
        iEdge = i;
        t = t->getNeigh(i);
        if(t == cavity[0]) {
          computeNeighboringTrisOfACavity(cavity, outside);
          return true;
        }
        if(!t) return false;
        if(t->isDeleted()){
          Msg::Error("Impossible to build vertex cavity");
          return false;
        }
        cavity.push_back(t);
        for(int j = 0; j < 3; j++){
          if(t->tri()->getVertex(j) !=lastinring && t->tri()->getVertex(j) != *v1){
            lastinring = t->tri()->getVertex(j);
            ring.push_back(lastinring);
            j = 100;
          }
        }
        break;
      }
    }
    if(iEdge == -1) {
      Msg::Error("Impossible to build vertex cavity");
      return false;
    }
  }
}

// split one triangle into 3 triangles then apply edge swop (or not)
// will do better (faster) soon, just to test
void _triangleSplit (GFace *gf, MElement *t, bool swop = false)
{
  MVertex *v1 = t->getVertex(0);
  MVertex *v2 = t->getVertex(1);
  MVertex *v3 = t->getVertex(2);
  SPoint2 p1,p2,p3;

  reparamMeshEdgeOnFace(v1, v2, gf, p1,p2);
  reparamMeshEdgeOnFace(v1, v3, gf, p1,p3);

  SPoint2 np = (p1+p2+p3)*(1./3.0);

  GPoint gp = gf->point(np);

  MFaceVertex *fv = new MFaceVertex(gp.x(),gp.y(),gp.z(),
				    gf,np.x(),np.y());
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    if(gf->triangles[i] != t){
      triangles2.push_back(gf->triangles[i]);
    }
  }
  delete t;
  MTriangle *t1 = new MTriangle(v1,v2,fv);
  MTriangle *t2 = new MTriangle(v2,v3,fv);
  MTriangle *t3 = new MTriangle(v3,v1,fv);
  gf->triangles = triangles2;
  gf->triangles.push_back(t1);
  gf->triangles.push_back(t2);
  gf->triangles.push_back(t3);
  gf->mesh_vertices.push_back(fv);
}

struct RecombineTriangle
{
  MElement *t1, *t2;
  double angle;
  double cost_quality; //addition for class Temporary
  double cost_alignment; //addition for class Temporary
  double total_cost; //addition for class Temporary
  MVertex *n1, *n2, *n3, *n4;
  RecombineTriangle(const MEdge &me, MElement *_t1, MElement *_t2)
    : t1(_t1), t2(_t2)
  {
    n1 = me.getVertex(0);
    n2 = me.getVertex(1);

    if(t1->getVertex(0) != n1 && t1->getVertex(0) != n2) n3 = t1->getVertex(0);
    else if(t1->getVertex(1) != n1 && t1->getVertex(1) != n2) n3 = t1->getVertex(1);
    else if(t1->getVertex(2) != n1 && t1->getVertex(2) != n2) n3 = t1->getVertex(2);
    if(t2->getVertex(0) != n1 && t2->getVertex(0) != n2) n4 = t2->getVertex(0);
    else if(t2->getVertex(1) != n1 && t2->getVertex(1) != n2) n4 = t2->getVertex(1);
    else if(t2->getVertex(2) != n1 && t2->getVertex(2) != n2) n4 = t2->getVertex(2);

    double a1 = 180 * angle3Vertices(n1, n4, n2) / M_PI;
    double a2 = 180 * angle3Vertices(n4, n2, n3) / M_PI;
    double a3 = 180 * angle3Vertices(n2, n3, n1) / M_PI;
    double a4 = 180 * angle3Vertices(n3, n1, n4) / M_PI;
    angle = fabs(90. - a1);
    angle = std::max(fabs(90. - a2),angle);
    angle = std::max(fabs(90. - a3),angle);
    angle = std::max(fabs(90. - a4),angle);
	cost_quality = 1.0 - std::max(1.0 - angle/90.0,0.0); //addition for class Temporary
	cost_alignment = Temporary::compute_alignment(me,_t1,_t2); //addition for class Temporary
	total_cost = Temporary::compute_total_cost(cost_quality,cost_alignment); //addition for class Temporary
	total_cost = 100.0*cost_quality; //addition for class Temporary
  }
  bool operator < (const RecombineTriangle &other) const
  {
    //return angle < other.angle;
	return total_cost < other.total_cost; //addition for class Temporary
  }
};

static int _recombineIntoQuads(GFace *gf, int recur_level, bool cubicGraph = 1)
{
  int success = 1;

  std::set<MVertex*> emb_edgeverts;
  {
    std::list<GEdge*> emb_edges = gf->embeddedEdges();
    std::list<GEdge*>::iterator ite = emb_edges.begin();
    while(ite != emb_edges.end()){
      if(!(*ite)->isMeshDegenerated()){
        emb_edgeverts.insert((*ite)->mesh_vertices.begin(),
                             (*ite)->mesh_vertices.end() );
        emb_edgeverts.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
                             (*ite)->getBeginVertex()->mesh_vertices.end());
        emb_edgeverts.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
                             (*ite)->getEndVertex()->mesh_vertices.end());
      }
      ++ite;
    }
  }

  {
    std::list<GEdge*> _edges = gf->edges();
    std::list<GEdge*>::iterator ite = _edges.begin();
    while(ite != _edges.end()){
      if(!(*ite)->isMeshDegenerated()){
	if ((*ite)->isSeam(gf)){
	  emb_edgeverts.insert((*ite)->mesh_vertices.begin(),
			       (*ite)->mesh_vertices.end() );
	  emb_edgeverts.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
			       (*ite)->getBeginVertex()->mesh_vertices.end());
	  emb_edgeverts.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
			       (*ite)->getEndVertex()->mesh_vertices.end());
	}
      }
      ++ite;
    }
  }

  e2t_cont adj;
  buildEdgeToElement(gf->triangles, adj);

  std::vector<RecombineTriangle> pairs;
  std::map<MVertex*,std::pair<MElement*,MElement*> > makeGraphPeriodic;

  for(e2t_cont::iterator it = adj.begin(); it!= adj.end(); ++it){
    if(it->second.second &&
        it->second.first->getNumVertices() == 3 &&
        it->second.second->getNumVertices() == 3 &&
        (emb_edgeverts.find(it->first.getVertex(0)) == emb_edgeverts.end() ||
         emb_edgeverts.find(it->first.getVertex(1)) == emb_edgeverts.end())){
      pairs.push_back(RecombineTriangle(it->first,
                                     it->second.first,
                                     it->second.second));
    }
    else if (!it->second.second &&
	     it->second.first->getNumVertices() == 3){
      for (int i=0;i<2;i++){
	MVertex *v = it->first.getVertex(i);
	std::map<MVertex*,std::pair<MElement*,MElement*> > :: iterator itv = makeGraphPeriodic.find(v);
	if (itv == makeGraphPeriodic.end()){
	  makeGraphPeriodic[v] = std::make_pair(it->second.first,(MElement*)0);
	}
	else{
	  if ( itv->second.first !=  it->second.first)
	    itv->second.second = it->second.first;
	  else
	    makeGraphPeriodic.erase(itv);
	}
      }
    }
  }

  std::sort(pairs.begin(),pairs.end());
  std::set<MElement*> touched;
  std::vector<std::pair<MElement*,MElement*> > toProcess;

  if(CTX::instance()->mesh.algoRecombine == 1){
#if defined(HAVE_BLOSSOM)
    int ncount = gf->triangles.size();
    //    printf("COUCOU %d\n",ncount);
    if (ncount % 2 == 0) {
      int ecount =  cubicGraph ? pairs.size() + makeGraphPeriodic.size() : pairs.size();
      Msg::Info("Blossom: %d internal %d closed",(int)pairs.size(), (int)makeGraphPeriodic.size());
      //      Msg::Info("Cubic Graph should have ne (%d) = 3 x nv (%d) ",ecount,ncount);
      Msg::Debug("Perfect Match Starts %d edges %d nodes",ecount,ncount);
      std::map<MElement*,int> t2n;
      std::map<int,MElement*> n2t;
      for (unsigned int i=0;i<gf->triangles.size();++i){
	t2n[gf->triangles[i]] = i;
	n2t[i] = gf->triangles[i];
      }

      int *elist = new int [2*ecount];
      int *elen  = new int [ecount];
      for (int i=0;i<pairs.size();++i){
	elist[2*i]   = t2n[pairs[i].t1];
	elist[2*i+1] = t2n[pairs[i].t2];
	//elen [i] =  (int) pairs[i].angle;
	elen [i] = (int) pairs[i].total_cost; //addition for class Temporary
	double angle = atan2(pairs[i].n1->y()-pairs[i].n2->y(),
			     pairs[i].n1->x()-pairs[i].n2->x());

	double x = .5*(pairs[i].n1->x()+pairs[i].n2->x());
	double y = .5*(pairs[i].n1->y()+pairs[i].n2->y());
	double opti = atan2(y,x);
	//angle -= opti;
	while (angle < 0 || angle > M_PI/2){
	  if (angle < 0) angle += M_PI/2;
	  if (angle > M_PI/2) angle -= M_PI/2;
	}
	//elen [i] =  (int) 180. * fabs(angle-M_PI/4)/M_PI;

	int NB = 0;
	if (pairs[i].n1->onWhat()->dim() < 2)NB++;
	if (pairs[i].n2->onWhat()->dim() < 2)NB++;
	if (pairs[i].n3->onWhat()->dim() < 2)NB++;
	if (pairs[i].n4->onWhat()->dim() < 2)NB++;
	if (elen[i] >  gf->meshAttributes.recombineAngle && NB > 2) {elen[i] = 1000;}
      }

      if (cubicGraph){
	std::map<MVertex*,std::pair<MElement*,MElement*> > :: iterator itv = makeGraphPeriodic.begin();
	int CC = pairs.size();
	for ( ; itv != makeGraphPeriodic.end(); ++itv){
	  elist[2*CC]   = t2n[itv->second.first];
	  elist[2*CC+1] = t2n[itv->second.second];
	  elen [CC++] =  100000;
	}
      }

      double matzeit = 0.0;
      char MATCHFILE[256];
      sprintf(MATCHFILE,".face.match");
      if (perfect_match (ncount,
			 NULL,
			 ecount,
			 &elist,
			 &elen,
			 NULL,
			 MATCHFILE,
			 0,
			 0,
			 0,
			 0,
			 &matzeit)){
	if (recur_level < 20){
	  Msg::Warning("Perfect Match Failed in Quadrangulation, Applying Graph Splits");
	  std::set<MElement*> removed;
	  std::vector<MTriangle*> triangles2;
	  for (unsigned int i=0;i<pairs.size();++i){
	    RecombineTriangle &rt = pairs[i];
	    if ((rt.n1->onWhat()->dim() < 2 &&
		 rt.n2->onWhat()->dim() < 2) ||
		(recur_level > 10 && i < 10)
		){
	      if (removed.find(rt.t1) == removed.end() &&
		  removed.find(rt.t2) == removed.end() ){
		removed.insert(rt.t1);
		removed.insert(rt.t2);
		SPoint2 p1,p2;
		reparamMeshEdgeOnFace(rt.n1,rt.n2, gf, p1,p2);
		SPoint2 np = (p1+p2)*(1./2.0);
		GPoint gp = gf->point(np);
		MFaceVertex *newv = new MFaceVertex(gp.x(),gp.y(),gp.z(),
						    gf,np.x(),np.y());
		MTriangle *t1 = new MTriangle(rt.n1,rt.n4,newv);
		MTriangle *t2 = new MTriangle(rt.n4,rt.n2,newv);
		MTriangle *t3 = new MTriangle(rt.n2,rt.n3,newv);
		MTriangle *t4 = new MTriangle(rt.n3,rt.n1,newv);
		//MTriangle *t1 = new MTriangle(rt.n1,rt.n4,rt.n3);
		//	      MTriangle *t2 = new MTriangle(rt.n4,rt.n2,rt.n3);
		gf->mesh_vertices.push_back(newv);
		triangles2.push_back(t1);
		triangles2.push_back(t2);
		triangles2.push_back(t3);
		triangles2.push_back(t4);
	      }
	    }
	  }
	  if (removed.size() == 0) return _recombineIntoQuads(gf, 11);
	  for (int i=0;i<gf->triangles.size();++i){
	    if (removed.find(gf->triangles[i]) == removed.end())triangles2.push_back(gf->triangles[i]);
	    else delete gf->triangles[i];
	  }
	  gf->triangles=triangles2;
	  //	for (int i=0;i<tos.size();i++)_triangleSplit (gf,tos[i]);
	  //	  gf->model()->writeMSH("chplit.msh");
	  free(elist);
	  return _recombineIntoQuads(gf, recur_level+1);
	}
	else {
	  Msg::Error("Perfect Match Finally Failed in Quadrangulation, Try Something Else");
	  free(elist);
	  pairs.clear();
	}
      }
      else{
	// TEST
	for (int k=0;k<elist[0];k++){
	  int i1 = elist[1+3*k],i2 = elist[1+3*k+1],an=elist[1+3*k+2];
	  // FIXME !!
	  if (an == 100000 /*|| an == 1000*/){
	    toProcess.push_back(std::make_pair(n2t[i1],n2t[i2]));
	    Msg::Debug("Extra edge found in blossom algorithm, optimization will be required");
	  }
	  else{
	    MElement *t1 = n2t[i1];
	    MElement *t2 = n2t[i2];
	    touched.insert(t1);
	    touched.insert(t2);
	    int orientation = 0;
	    MVertex *other = 0;
	    for(int i = 0; i < 3; i++) {
	      if (t1->getVertex(0) != t2->getVertex(i) &&
		  t1->getVertex(1) != t2->getVertex(i) &&
		  t1->getVertex(2) != t2->getVertex(i)){
		other = t2->getVertex(i);
		break;
	      }
	    }
	    int start;
	    for(int i = 0; i < 3; i++) {
	      if (t2->getVertex(0) != t1->getVertex(i) &&
		  t2->getVertex(1) != t1->getVertex(i) &&
		  t2->getVertex(2) != t1->getVertex(i)){
		start=i;
		break;
	      }
	    }
	    MQuadrangle *q = new MQuadrangle(t1->getVertex(start),
					     t1->getVertex((start+1)%3),
					     other,
					     t1->getVertex((start+2)%3));
	    gf->quadrangles.push_back(q);
	  }
	}
	//	fclose(f);
	free(elist);
	pairs.clear();
	if (recur_level == 0)
	  Msg::Debug("Perfect Match Succeeded in Quadrangulation (%g sec)",matzeit);
	else
	  Msg::Info(" :-) Perfect Match Succeeded in Quadrangulation after Splits (%g sec)",matzeit);

      }
    }

#else
    Msg::Warning("Gmsh should be compiled with the Blossom IV code and CONCORDE in order to allow the Blossom optimization");
#endif
  }

  std::vector<RecombineTriangle>::iterator itp = pairs.begin();
  while(itp != pairs.end()){
    // recombine if difference between max quad angle and right
    // angle is smaller than tol
    //    printf("%g %g\n",gf->meshAttributes.recombineAngle,itp->angle);
    if(itp->angle < gf->meshAttributes.recombineAngle){
      MElement *t1 = itp->t1;
      MElement *t2 = itp->t2;
      if(touched.find(t1) == touched.end() &&
          touched.find(t2) == touched.end()){
        touched.insert(t1);
        touched.insert(t2);

        int orientation = 0;
        for(int i = 0; i < 3; i++) {
          if(t1->getVertex(i) == itp->n1) {
            if(t1->getVertex((i + 1) % 3) == itp->n2)
              orientation = 1;
            else
              orientation = -1;
            break;
          }
        }
        MQuadrangle *q;
        if(orientation < 0)
          q = new MQuadrangle(itp->n1, itp->n3, itp->n2, itp->n4);
        else
          q = new MQuadrangle(itp->n1, itp->n4, itp->n2, itp->n3);
        gf->quadrangles.push_back(q);
      }
    }
    ++itp;
  }

  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    if(touched.find(gf->triangles[i]) == touched.end()){
      triangles2.push_back(gf->triangles[i]);
    }
    else {
      delete gf->triangles[i];
    }
  }
  gf->triangles = triangles2;

  if (toProcess.size()) postProcessExtraEdges (gf,toProcess);
  return success;
}


void recombineIntoQuads(GFace *gf,
			bool topologicalOpti,
			bool nodeRepositioning)
{

  double t1 = Cpu();

  bool haveParam = true;
  bool saveAll = CTX::instance()->mesh.saveAll;
  if(gf->geomType() == GEntity::DiscreteSurface && !gf->getCompound())
    haveParam = false;

  // PLEASE DO NOT UNCOMMENT !!!! THIS IS SHIT
  //  if(haveParam && topologicalOpti)
  //    removeFourTrianglesNodes(gf, false);

  if (saveAll) gf->model()->writeMSH("before.msh");
  int success = _recombineIntoQuads(gf, 0);

  if (saveAll) gf->model()->writeMSH("raw.msh");
  if(haveParam && nodeRepositioning)
    laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing);

  // blossom-quad algo
  if(success && CTX::instance()->mesh.algoRecombine == 1){
    if(topologicalOpti){
      if(haveParam){
        if (saveAll) gf->model()->writeMSH("smoothed.msh");
        int COUNT = 0, ITER=0;
        char NAME[256];

	double tFQ=0,tTQ=0,tDI=0,tLA=0,tSW=0,tBU=0;
	double oldoptistatus[5] = {0,0,0,0,0};
	double optistatus[5] = {0,0,0,0,0};
        while(1){
	  double t6 = Cpu();
	  int maxCavitySize = CTX::instance()->mesh.bunin;
	  optistatus[4] = _defectsRemovalBunin(gf,maxCavitySize);
          if(optistatus[4] && saveAll){ sprintf(NAME,"iter%dB.msh",COUNT++); gf->model()->writeMSH(NAME); }
	  double t7 = Cpu();
	  double t1 = Cpu();
	  optistatus[0] = splitFlatQuads(gf, .3);
	  //	  printf("%d flat quads splittttouilled\n",w);
          if(optistatus[0] && saveAll){ sprintf(NAME,"iter%dSF.msh",COUNT++); gf->model()->writeMSH(NAME);}
	  double t2 = Cpu();
	  optistatus[1] = removeTwoQuadsNodes(gf);
          if(optistatus[1] && saveAll){ sprintf(NAME,"iter%dTQ.msh",COUNT++); gf->model()->writeMSH(NAME);}
	  double t3 = Cpu();
          optistatus[2] = removeDiamonds(gf);
          if(optistatus[2] && saveAll){ sprintf(NAME,"iter%dD.msh",COUNT++); gf->model()->writeMSH(NAME); }
	  double t4 = Cpu();
          laplaceSmoothing(gf,CTX::instance()->mesh.nbSmoothing);
	  double t5 = Cpu();
          optistatus[3] = edgeSwapQuadsForBetterQuality(gf);
	  //	  if (z) printf("%d swops !!\n",z);
          if(optistatus[3] && saveAll){ sprintf(NAME,"iter%dS.msh",COUNT++); gf->model()->writeMSH(NAME); }
	  tFQ += (t2-t1);
	  tTQ += (t3-t2);
	  tDI += (t4-t3);
	  tLA += (t5-t4);
	  tSW += (t6-t5);
	  tBU += (t7-t6);
          if (!(optistatus[0]+optistatus[1]+optistatus[2]+optistatus[3]+optistatus[4])) break;
	  bool theSame = true;
	  for (int i=0;i<5;i++){
	    if (optistatus[i] != oldoptistatus[i])theSame = false;
	      oldoptistatus[i] = optistatus[i];
	  }
	  if(theSame)break;
	  if (ITER++ >= 20)break;
        }
	printf("times = %4.3f %4.3f %4.3f %4.3f %4.3f %4.3f\n",tFQ,tTQ,tDI,tLA,tSW,tBU);
      }
      //      edgeSwapQuadsForBetterQuality(gf);
      //if(z){ sprintf(NAME,"iter%dS.msh",COUNT++); gf->model()->writeMSH(NAME); }
      //      removeTwoQuadsNodes(gf);
      if(haveParam) laplaceSmoothing(gf,CTX::instance()->mesh.nbSmoothing);
      //      for (int i=0;i<20;i++)_defectsRemovalBunin(gf);
      //      if(haveParam) laplaceSmoothing(gf,CTX::instance()->mesh.nbSmoothing);
    }
    double t2 = Cpu();
    Msg::Info("Blossom recombination algorithm completed (%g s)", t2 - t1);
    return;
  }

  // simple recombination algo
  _recombineIntoQuads(gf, 0);
  if(haveParam) laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing);
  _recombineIntoQuads(gf, 0);
  if(haveParam) laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing);

  if (saveAll) gf->model()->writeMSH("after.msh");

  double t2 = Cpu();
  Msg::Info("Simple recombination algorithm completed (%g s)", t2 - t1);
}

void quadsToTriangles(GFace *gf, double minqual)
{

  std::vector<MQuadrangle*> qds;
  for (int i=0;i<gf->quadrangles.size();i++){
    MQuadrangle *q = gf->quadrangles[i];
    if (q->etaShapeMeasure() < minqual){
      MTriangle *t11 = new MTriangle (q->getVertex(0),q->getVertex(1),q->getVertex(2));
      MTriangle *t12 = new MTriangle (q->getVertex(2),q->getVertex(3),q->getVertex(0));
      MTriangle *t21 = new MTriangle (q->getVertex(1),q->getVertex(2),q->getVertex(3));
      MTriangle *t22 = new MTriangle (q->getVertex(3),q->getVertex(0),q->getVertex(1));
      double qual1 = std::min(t11->gammaShapeMeasure(),t12->gammaShapeMeasure());
      double qual2 = std::min(t21->gammaShapeMeasure(),t22->gammaShapeMeasure());

      double surf1 = surfaceFaceUV(t11,gf) + surfaceFaceUV(t12,gf);
      double surf2 = surfaceFaceUV(t21,gf) + surfaceFaceUV(t22,gf);

      int option = 0;
      if (surf1 > surf2 * (1.+1.e-8))option = 2;
      else if (surf2 > surf1 * (1.+1.e-8))option = 1;

      if (option == 1 || (option == 0 && qual1 > qual2)){
	gf->triangles.push_back(t11);
	gf->triangles.push_back(t12);
	delete t21; delete t22;
      }
      else {
	gf->triangles.push_back(t21);
	gf->triangles.push_back(t22);
	delete t11; delete t12;
      }
      delete q;
    }
    else {
      qds.push_back(q);
    }
  }
  gf->quadrangles = qds;
}

double Temporary::w1,Temporary::w2,Temporary::w3;
std::vector<SVector3> Temporary::gradients;

Temporary::Temporary(){}

Temporary::~Temporary(){}

SVector3 Temporary::compute_gradient(MElement*element)
{
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  double x,y,z;
  MVertex*vertex1 = element->getVertex(0);
  MVertex*vertex2 = element->getVertex(1);
  MVertex*vertex3 = element->getVertex(2);
  x1 = vertex1->x();
  y1 = vertex1->y();
  z1 = vertex1->z();
  x2 = vertex2->x();
  y2 = vertex2->y();
  z2 = vertex2->z();
  x3 = vertex3->x();
  y3 = vertex3->y();
  z3 = vertex3->z();
  x = (x1+x2+x3)/3.0;
  y = (y1+y2+y3)/3.0;
  z = (z1+z2+z3)/3.0;
  return SVector3(0.0,1.0,0.0);
}

void Temporary::select_weights(double new_w1,double new_w2,double new_w3)
{
  w1 = new_w1;
  w2 = new_w2;
  w3 = new_w3;
}

double Temporary::compute_total_cost(double f1,double f2)
{
  double cost;
  cost = w1*f1 + w2*f2 + w3*f1*f2;
  return cost;
}

SVector3 Temporary::compute_normal(MElement*element)
{
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  double length;
  SVector3 vectorA;
  SVector3 vectorB;
  SVector3 normal;
  MVertex*vertex1 = element->getVertex(0);
  MVertex*vertex2 = element->getVertex(1);
  MVertex*vertex3 = element->getVertex(2);
  x1 = vertex1->x();
  y1 = vertex1->y();
  z1 = vertex1->z();
  x2 = vertex2->x();
  y2 = vertex2->y();
  z2 = vertex2->z();
  x3 = vertex3->x();
  y3 = vertex3->y();
  z3 = vertex3->z();
  vectorA = SVector3(x2-x1,y2-y1,z2-z1);
  vectorB = SVector3(x3-x1,y3-y1,z3-z1);
  normal = crossprod(vectorA,vectorB);
  length = norm(normal);
  return SVector3(normal.x()/length,normal.y()/length,normal.z()/length);
}

SVector3 Temporary::compute_other_vector(MElement*element)
{
  int number;
  double length;
  SVector3 normal;
  SVector3 gradient;
  SVector3 other_vector;
  number = element->getNum();
  normal = Temporary::compute_normal(element);
  gradient = Temporary::compute_gradient(element);//gradients[number];
  other_vector = crossprod(gradient,normal);
  length = norm(other_vector);
  return SVector3(other_vector.x()/length,other_vector.y()/length,other_vector.z()/length);
}

double Temporary::compute_alignment(const MEdge&_edge, MElement*element1, MElement*element2)
{
  int number;
  double scalar_productA,scalar_productB;
  double alignment;
  SVector3 gradient;
  SVector3 other_vector;
  SVector3 edge;
  MVertex*vertexA;
  MVertex*vertexB;
  number = element1->getNum();
  gradient = Temporary::compute_gradient(element1);//gradients[number];
  other_vector = Temporary::compute_other_vector(element1);
  vertexA = _edge.getVertex(0);
  vertexB = _edge.getVertex(1);
  edge = SVector3(vertexB->x()-vertexA->x(),vertexB->y()-vertexA->y(),vertexB->z()-vertexA->z());
  edge = edge * (1/norm(edge));
  scalar_productA = fabs(dot(gradient,edge));
  scalar_productB = fabs(dot(other_vector,edge));
  alignment = std::max(scalar_productA,scalar_productB) - sqrt(2.0)/2.0;
  alignment = alignment/(1.0-sqrt(2.0)/2.0);
  return alignment;
}

void Temporary::read_data(std::string file_name)
{
#if defined(HAVE_POST)
  int i,j,number;
  double x,y,z;
  MElement*element;
  PView*view;
  PViewData*data;
  PView::readMSH(file_name,-1);
  std::vector<PView*> list = PView::list;
  data = list[0]->getData();
  for(i = 0;i < data->getNumEntities(0);i++)
  {
    if(data->skipEntity(0,i)) continue;
    for(j = 0;j < data->getNumElements(0,i);j++)
	{
	  if(data->skipElement(0,i,j)) continue;
	  element = data->getElement(0,i,j);
	  number = element->getNum();
	  data->getValue(0,i,j,0,x);
	  data->getValue(0,i,j,1,y);
	  data->getValue(0,i,j,2,z);
	  gradients[number] = SVector3(x,y,z);
	}
  }
#endif
}

void Temporary::quadrilaterize(std::string file_name,double _w1,double _w2,double _w3)
{
  GFace*face;
  GModel*model = GModel::current();
  GModel::fiter iterator;
  gradients.resize(model->getNumMeshElements() + 1);
  w1 = _w1;
  w2 = _w2;
  w3 = _w3;
  Temporary::read_data(file_name);
  for(iterator = model->firstFace();iterator != model->lastFace();iterator++)
  {
    face = *iterator;
	_recombineIntoQuads(face,1,1);
  }
}
