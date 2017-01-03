// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
#include "BackgroundMeshTools.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Generator.h"
#include "Context.h"
#include "OS.h"
#include "SVector3.h"
#include "SPoint3.h"
#include "robustPredicates.h"
#include "meshGRegionRelocateVertex.h"

#if defined(HAVE_BLOSSOM)
extern "C" struct CCdatagroup;
extern "C" int perfect_match
(int ncount, CCdatagroup *dat, int ecount,
 int **elist, int **elen, char *blo_filename,
 char *mat_filename, int just_fractional, int no_fractional,
 int use_all_trees, int partialprice,
 double *totalzeit) ;
#endif

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

static void setLcs(MTriangle *t, std::map<MVertex*, double> &vSizes, bidimMeshData & data)
{
  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 3; j++){
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      if (vi != data.equivalent(vj) && vj != data.equivalent(vi) ){
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
}

void buildMeshGenerationDataStructures(GFace *gf,
                                       std::set<MTri3*, compareTri3Ptr> &AllTris,
                                       bidimMeshData & data)
{
  std::map<MVertex*, double> vSizesMap;
  std::list<GEdge*> edges = gf->edges();

  for(unsigned int i = 0;i < gf->triangles.size(); i++)
    setLcsInit(gf->triangles[i], vSizesMap);
  std::map<MVertex*, double>::iterator itfind = vSizesMap.find(NULL);
  if (itfind!=vSizesMap.end()){
    std::cout << "***************************************** NULL" << std::endl;
    throw;
  }

  for(unsigned int i = 0;i < gf->triangles.size(); i++)
    setLcs(gf->triangles[i], vSizesMap, data);

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

  // take good care of embedded edges
  {
    std::list<GEdge*> embedded_edges = gf->embeddedEdges();
    std::list<GEdge*>::iterator ite = embedded_edges.begin();
    while(ite != embedded_edges.end()){
      if(!(*ite)->isMeshDegenerated()){
        for (unsigned int i = 0; i < (*ite)->lines.size(); i++)
          data.internalEdges.insert(MEdge((*ite)->lines[i]->getVertex(0),
                                          (*ite)->lines[i]->getVertex(1)));
      }
      ++ite;
    }
  }

  //  int NUM = 0;
  for(std::map<MVertex*, double>::iterator it = vSizesMap.begin();
       it != vSizesMap.end(); ++it){
    SPoint2 param;
    reparamMeshVertexOnFace(it->first, gf, param);
    data.addVertex (it->first, param[0], param[1], it->second, it->second);
  }
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    double lc = 0.3333333333 * (data.vSizes[data.getIndex(gf->triangles[i]->getVertex(0))] +
                                data.vSizes[data.getIndex(gf->triangles[i]->getVertex(1))] +
                                data.vSizes[data.getIndex(gf->triangles[i]->getVertex(2))]);
    AllTris.insert(new MTri3(gf->triangles[i], lc, 0, &data, gf));
  }
  gf->triangles.clear();
  connectTriangles(AllTris);
}

void computeEquivalences(GFace *gf, bidimMeshData & data)
{
  if (data.equivalence){
    std::vector<MTriangle*> newT;
    for (unsigned int i=0;i<gf->triangles.size();i++){
      MTriangle *t = gf->triangles[i];
      MVertex *v[3];
      for (int j=0;j<3;j++){
        v[j] = t->getVertex(j);
        std::map<MVertex* , MVertex*>::iterator it =  data.equivalence->find(v[j]);
        if (it != data.equivalence->end()){
          v[j] = it->second;
        }
      }
      if (v[0] != v[1] && v[0] != v[2] && v[2] != v[1])
        newT.push_back(new MTriangle (v[0],v[1],v[2]));
      delete t;
    }
    gf->triangles = newT;
  }
}

struct equivalentTriangle {
  MTriangle *_t;
  MVertex *_v[3];
  equivalentTriangle (MTriangle *t,  std::map<MVertex* , MVertex*>* equivalence)
    :_t(t) {
    for (int i=0;i<3;i++){
      MVertex *v = t->getVertex(i);
      std::map<MVertex* , MVertex*>::iterator it = equivalence->find(v);
      if (it == equivalence->end())_v[i] = v;
      else _v[i] = it->second;
    }
    std::sort (_v,_v+3);
  }
  bool operator < (const equivalentTriangle &other) const{
    for (int i=0;i<3;i++){
      if (other._v[i] > _v[i])return true;
      if (other._v[i] < _v[i])return false;
    }
    return false;
  }
};

bool computeEquivalentTriangles (GFace *gf,
                                 std::map<MVertex* , MVertex*>* equivalence)
{
  if (!equivalence)return false;
  std::vector<MTriangle*> WTF;
  if (!equivalence)return false;
  std::set<equivalentTriangle> eqTs;
  for (unsigned int i = 0; i < gf->triangles.size(); i++){
    equivalentTriangle et (gf->triangles[i],equivalence);
    std::set<equivalentTriangle>::iterator iteq = eqTs.find(et);
    if (iteq == eqTs.end())eqTs.insert(et);
    else {
      WTF.push_back(iteq->_t);
      WTF.push_back(gf->triangles[i]);
    }
  }

  if (WTF.size()){
    Msg::Info("%d triangles are equivalent", WTF.size());
    for (unsigned int i=0;i<WTF.size();i++){
    }
    return true;
  }
  return false;
}


void splitEquivalentTriangles(GFace *gf, bidimMeshData & data)
{
  computeEquivalentTriangles (gf,data.equivalence);
}


void transferDataStructure(GFace *gf, std::set<MTri3*, compareTri3Ptr> &AllTris,
                           bidimMeshData & data)
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
    int index0 = data.getIndex (v0);
    int index1 = data.getIndex (v1);
    int index2 = data.getIndex (v2);
    normal3points(data.Us[index0], data.Vs[index0], 0.,
                  data.Us[index1], data.Vs[index1], 0.,
                  data.Us[index2], data.Vs[index2], 0., n1);
    for(unsigned int j = 1; j < gf->triangles.size(); j++){
      t = gf->triangles[j];
      v0 = t->getVertex(0); v1 = t->getVertex(1); v2 = t->getVertex(2);
      index0 = data.getIndex (v0);
      index1 = data.getIndex (v1);
      index2 = data.getIndex (v2);
      normal3points(data.Us[index0], data.Vs[index0], 0.,
                    data.Us[index1], data.Vs[index1], 0.,
                    data.Us[index2], data.Vs[index2], 0., n2);
      double pp; prosca(n1, n2, &pp);
      if(pp < 0) t->reverse();
    }
  }
  splitEquivalentTriangles(gf, data);
  computeEquivalences(gf, data);
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

double surfaceFaceUV(MElement *t,GFace *gf, bool maximal = true)
{
  double u[4],v[4];
  parametricCoordinates(t,gf,u,v);
  //  printf("%g %g %g %g\n",u[0],u[1],u[2],u[3]);
  //  printf("%g %g %g %g\n",v[0],v[1],v[2],v[3]);
  if (t->getNumVertices() == 3)
    return 0.5*fabs((u[1]-u[0])*(v[2]-v[0])-(u[2]-u[0])*(v[1]-v[0]));
  else {
    const double a1 =
      0.5*fabs((u[1]-u[0])*(v[2]-v[0])-(u[2]-u[0])*(v[1]-v[0])) +
      0.5*fabs((u[3]-u[2])*(v[0]-v[2])-(u[0]-u[2])*(v[3]-v[2])) ;
    const double a2 =
      0.5*fabs((u[2]-u[1])*(v[3]-v[1])-(u[3]-u[1])*(v[2]-v[1])) +
      0.5*fabs((u[0]-u[3])*(v[1]-v[3])-(u[1]-u[3])*(v[0]-v[3])) ;
    return maximal ? std::max(a2,a1) : std::min(a2,a1);
  }
}

int _removeThreeTrianglesNodes(GFace *gf)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles,adj);
  v2t_cont :: iterator it = adj.begin();
  int n=0;
  std::set<MElement*> touched;
  while (it != adj.end()) {
    bool skip = false;
    if(it->second.size() == 3 && it->first->onWhat()->dim() == 2) {
      const std::vector<MElement*> &lt = it->second;
      std::set<MVertex*> vs;
      for(int i = 0; i < 3; i++) {
        if(touched.find(lt[i])!=touched.end() || lt[i]->getNumVertices()!=3){
          skip=true;
          break;
        }
        for(int j = 0; j < 3; j++) {
          if(lt[i]->getVertex(j) == it->first) {
            vs.insert(lt[i]->getVertex((j+1)%3));
            vs.insert(lt[i]->getVertex((j+2)%3));
            break;
          }
        }
      }
      if(skip){
        it++;
        continue;
      }
      std::set<MVertex*>::iterator itt = vs.begin();
      MVertex *v1 = *itt; ++itt;
      MVertex *v2 = *itt; ++itt;
      MVertex *v3 = *itt;
      MTriangle *newt = new MTriangle(v1,v2,v3);
      n++;
      gf->triangles.push_back(newt);
      for(int i=0;i<3;i++) {
        touched.insert(lt[i]);
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
  Msg::Debug("%i three-triangles vertices removed",n);
  return n;
}


void removeThreeTrianglesNodes(GFace *gf)
{
  while(_removeThreeTrianglesNodes(gf));
}

static int _removeTwoQuadsNodes(GFace *gf)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles,adj);
  buildVertexToElement(gf->quadrangles,adj);
  v2t_cont :: iterator it = adj.begin();
  std::set<MElement*>  touched;
  std::set<MVertex*>  vtouched;
  while (it != adj.end()) {
    if(it->second.size()==2 && it->first->onWhat()->dim() == 2) {
      MElement *q1 = it->second[0];
      MElement *q2 = it->second[1];
      if (q1->getNumVertices() == 4 &&
          q2->getNumVertices() == 4 &&
          touched.find(q1) == touched.end() && touched.find(q2) == touched.end()){
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
        MQuadrangle *q = new MQuadrangle(v1,v2,v3,v4);
        double s1 = surfaceFaceUV(q,gf);
        double s2 = surfaceFaceUV(q1,gf) + surfaceFaceUV(q2,gf);;
        if (s1 > s2){
          delete q;
        }
        else{
          touched.insert(q1);
          touched.insert(q2);
          gf->quadrangles.push_back(q);
          vtouched.insert(it->first);
        }
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

// collapse v1 & v2 to their middle and replace into e1 & e2
static bool _tryToCollapseThatVertex (GFace *gf,
                                      std::vector<MElement*> &e1,
                                      std::vector<MElement*> &e2,
                                      MElement *q,
                                      MVertex *v1,
                                      MVertex *v2)
{
  std::vector<MElement*> e = e1;
  e.insert(e.end(), e2.begin(), e2.end());

  double uu1,vv1;
  v1->getParameter(0,uu1);
  v1->getParameter(1,vv1);
  double x1 = v1->x();
  double y1 = v1->y();
  double z1 = v1->z();

  double uu2,vv2;
  v2->getParameter(0,uu2);
  v2->getParameter(1,vv2);
  double x2 = v2->x();
  double y2 = v2->y();
  double z2 = v2->z();

  // new position of v1 && v2
  GPoint pp = gf->point(0.5*(uu1+uu2),0.5*(vv1+vv2));
    //GPoint pp = gf->point(uu1,vv1);

  //  double surface_old = 0;
  //  double surface_new = 0;
  double worst_quality_old = 1.0;
  double worst_quality_new = 1.0;

  //  surface_old = surfaceFaceUV(q,gf,false);
  int count=0;
  for (unsigned int j=0;j<e.size();++j){
    if (e[j] != q){
      count++;
      //      surface_old += surfaceFaceUV(e[j],gf,false);
      worst_quality_old = std::min(worst_quality_old,e[j]-> etaShapeMeasure());
      v1->x() = pp.x();v1->y() = pp.y();v1->z() = pp.z();
      v1->setParameter(0,pp.u());v1->setParameter(1,pp.v());
      v2->x() = pp.x();v2->y() = pp.y();v2->z() = pp.z();
      v2->setParameter(0,pp.u());v2->setParameter(1,pp.v());
      //      surface_new += surfaceFaceUV(e[j],gf,false);
      worst_quality_new = std::min(worst_quality_new,e[j]-> etaShapeMeasure());
      v1->x() = x1;v1->y() = y1;v1->z() = z1;
      v1->setParameter(0,uu1);v1->setParameter(1,vv1);
      v2->x() = x2;v2->y() = y2;v2->z() = z2;
      v2->setParameter(0,uu2);v1->setParameter(1,vv2);
    }
  }

  //  printf("%d %g %g %g %g\n", count, surface_old, surface_new, worst_quality_old , worst_quality_new);

  if (worst_quality_new >  worst_quality_old ) {
    v1->x() = pp.x();v1->y() = pp.y();v1->z() = pp.z();
    v1->setParameter(0,pp.u());v1->setParameter(1,pp.v());
    for (unsigned int j=0;j<e.size();++j){
      if (e[j] != q){
        for (int k=0;k<4;k++){
          if (e[j]->getVertex(k) == v2){
            e[j]->setVertex(k,v1);
          }
        }
      }
    }
    return true;
  }
  return false;
}

static bool _isItAGoodIdeaToMoveThatVertex(GFace *gf,
                                           const std::vector<MElement*> &e1,
                                           MVertex *v1,
                                           const SPoint2 &before,
                                           const SPoint2 &after)
{
  double surface_old = 0;
  double surface_new = 0;

  GPoint gp = gf->point(after);
  if (!gp.succeeded())return false;
  SPoint3 pafter  (gp.x(),gp.y(),gp.z());
  SPoint3 pbefore (v1->x(),v1->y(),v1->z());

  double minq = 1.0;
  for (unsigned int j=0;j<e1.size();++j){
    surface_old += surfaceFaceUV(e1[j],gf,false);
    minq = std::min(e1[j]->etaShapeMeasure(),minq);
  }

  v1->setParameter(0,after.x());
  v1->setParameter(1,after.y());
  v1->setXYZ(pafter.x(),pafter.y(),pafter.z());

  double minq_new = 1.0;
  for (unsigned int j=0;j<e1.size();++j){
    surface_new += surfaceFaceUV(e1[j],gf,false);
    minq_new = std::min(e1[j]->etaShapeMeasure(),minq_new);
  }

  v1->setParameter(0,before.x());
  v1->setParameter(1,before.y());
  v1->setXYZ(pbefore.x(),pbefore.y(),pbefore.z());
  if ((1.+1.e-10)*surface_old < surface_new|| minq_new < minq) {
    return false;
  }
  return true;
}

static int _removeDiamonds(GFace *gf)
{
  v2t_cont adj;
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
      if (v1->onWhat()->dim() == 2 &&
          v2->onWhat()->dim() == 2 &&
          v3->onWhat()->dim() == 2 &&
          v4->onWhat()->dim() == 2 &&
          it1->second.size() ==3 &&  it3->second.size() == 3 &&
          _tryToCollapseThatVertex (gf, it1->second, it3->second,
                                      q, v1, v3)){
        touched.insert(v1);
        touched.insert(v2);
        touched.insert(v3);
        touched.insert(v4);
        deleted.insert(v3);
        diamonds.insert(q);
      }
      else if (v1->onWhat()->dim() == 2 &&
               v2->onWhat()->dim() == 2 &&
               v3->onWhat()->dim() == 2 &&
               v4->onWhat()->dim() == 2 &&
               it2->second.size() ==3 &&  it4->second.size() == 3 &&
               _tryToCollapseThatVertex (gf, it2->second, it4->second,
                                         q, v2, v4)){
        touched.insert(v1);
        touched.insert(v2);
        touched.insert(v3);
        touched.insert(v4);
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

int removeDiamonds(GFace *gf)
{
  int nbRemove = 0;
  while(1){
    int x = _removeDiamonds(gf);
    if (!x)break;
    nbRemove += x;
  }
  Msg::Debug("%i diamond quads removed",nbRemove);
  return nbRemove;
}

struct p1p2p3 {
  MVertex *p1,*p2;
};


void _relocateVertex(GFace *gf, MVertex *ver,
                     const std::vector<MElement*> &lt)
{
  if(ver->onWhat()->dim() != 2) return;
  MFaceVertex *fv = dynamic_cast<MFaceVertex*>(ver);
  if(fv && fv->bl_data) return;

  double initu, initv;
  ver->getParameter(0, initu);
  ver->getParameter(1, initv);

  // compute the vertices connected to that one
  std::map<MVertex*,SPoint2> pts;
  for(unsigned int i = 0; i < lt.size(); i++){
    for (int j=0;j<lt[i]->getNumEdges();j++){
      MEdge e = lt[i]->getEdge(j);
      SPoint2 param0, param1;
      if (e.getVertex(0) == ver){
        reparamMeshEdgeOnFace(e.getVertex(0), e.getVertex(1), gf, param0, param1);
        pts[e.getVertex(1)] = param1;
      }
      else if (e.getVertex(1) == ver){
        reparamMeshEdgeOnFace(e.getVertex(0), e.getVertex(1), gf, param0, param1);
        pts[e.getVertex(0)] = param0;
      }
    }
  }

  SPoint2 before(initu,initv);
  double metric[3];
  SPoint2 after(0,0);
  double COUNT = 0.0;
  // printf("weights :");
  for(std::map<MVertex*,SPoint2>::iterator it = pts.begin(); it != pts.end() ; ++it) {
    SPoint2  adj = it->second;
    SVector3 d(adj.x() - before.x(), adj.y() - before.y(), 0.0);
    d.normalize();
    buildMetric(gf, adj, metric);
    const double F = sqrt(metric[0]*d.x()*d.x() +
                          2*metric[1]*d.x()*d.y() +
                          metric[2]*d.y()*d.y());
    // printf("%g ",F);
    after += adj*F;
    COUNT += F;
    // double RATIO = lt[i]->getVolume()/pow(metric[0]*metric[2]-metric[1]*metric[1],0.5);
  }
  //  printf("\n");
  after *= (1.0/COUNT);
  double FACTOR = 1.0;
  const int MAXITER = 5;
  SPoint2 actual = before;
  for (int ITER = 0;ITER < MAXITER; ITER ++){
    SPoint2 trial = after * FACTOR + before * (1.-FACTOR);
    bool success = _isItAGoodIdeaToMoveThatVertex (gf,  lt, ver,actual,trial);
    if (success){
      GPoint pt = gf->point(trial);
      if(pt.succeeded()){
        actual = trial;
        ver->setParameter(0, trial.x());
        ver->setParameter(1, trial.y());
        ver->x() = pt.x();
        ver->y() = pt.y();
        ver->z() = pt.z();
      }
    }
    FACTOR /= 1.4;
  }
}

void getAllBoundaryLayerVertices (GFace *gf, std::set<MVertex*> &vs){
  //  return;
  vs.clear();
  BoundaryLayerColumns* _columns = gf->getColumns();
  if (!_columns)return;
  for ( std::map<MElement*,std::vector<MElement*> >::iterator it = _columns->_elemColumns.begin();
	it != _columns->_elemColumns.end();it++){
    std::vector<MElement *> &e = it->second;
    for (unsigned int i=0;i<e.size();i++){
      for (int j=0;j<e[i]->getNumVertices();j++){
	vs.insert(e[i]->getVertex(j));
      }
    }
  }
}

void laplaceSmoothing(GFace *gf, int niter, bool infinity_norm)
{
  if (!niter)return;
  std::set<MVertex*> vs;
  getAllBoundaryLayerVertices (gf, vs);
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  for(int i = 0; i < niter; i++){
    v2t_cont::iterator it = adj.begin();
    while (it != adj.end()){
      if (vs.find(it->first) == vs.end()){
	_relocateVertex(gf, it->first, it->second);
      }
      ++it;
    }
  }
}

bool edgeSwapDelProj (MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
{
  MTriangle t1(v1,v2,v3);
  MTriangle t2(v2,v1,v4);

  SVector3 n1 = t1.getFace(0).normal();
  SVector3 n2 = t2.getFace(0).normal();
  if (dot(n1,n2) <= 0) {
    //    printf("OLA !!!\n");
    return true;
  }
  return false;
}

bool edgeSwap(std::set<swapquad> &configs, MTri3 *t1, GFace *gf, int iLocalEdge,
              std::vector<MTri3*> &newTris, const swapCriterion &cr, bidimMeshData & data)
{
  MTri3 *t2 = t1->getNeigh(iLocalEdge);
  if(!t2) return false;

  MVertex *v1 = t1->tri()->getVertex(iLocalEdge == 0 ? 2 : iLocalEdge - 1);
  MVertex *v2 = t1->tri()->getVertex((iLocalEdge) % 3);
  MVertex *v3 = t1->tri()->getVertex((iLocalEdge + 1) % 3);
  MVertex *v4 = 0;

  std::set<MEdge,Less_Edge>::iterator it = data.internalEdges.find(MEdge(v1,v2));
  if (it != data.internalEdges.end())return false;


  for(int i = 0; i < 3; i++)
    if(t2->tri()->getVertex(i) != v1 && t2->tri()->getVertex(i) != v2)
      v4 = t2->tri()->getVertex(i);

  swapquad sq (v1, v2, v3, v4);
  if(configs.find(sq) != configs.end()) return false;
  configs.insert(sq);

  if (edgeSwapDelProj(v3,v4,v2,v1))return false;


  MTriangle *t1b = new MTriangle(v2, v3, v4);
  MTriangle *t2b = new MTriangle(v4, v3, v1);

  switch(cr){
  case SWCR_QUAL:
    {
      const double triQualityRef = std::min(qmTriangle::gamma(t1->tri()),
                                            qmTriangle::gamma(t2->tri()));
      const double triQuality = std::min(qmTriangle::gamma(t1b),
                                         qmTriangle::gamma(t2b));
      if (!edgeSwapDelProj(v1,v2,v3,v4)){
        if(triQuality < triQualityRef){
          delete t1b;
          delete t2b;
          return false;
        }
      }
      break;
    }
  case SWCR_DEL:
    {
      int index1 = data.getIndex(v1);
      int index2 = data.getIndex(v2);
      int index3 = data.getIndex(v3);
      int index4 = data.getIndex(v4);
      double edgeCenter[2] ={(data.Us[index1] + data.Us[index2] +
                              data.Us[index3] + data.Us[index4]) * .25,
                             (data.Vs[index1] + data.Vs[index2] +
                              data.Vs[index3] + data.Vs[index4]) * .25};
      double uv4[2] ={data.Us[index4], data.Vs[index4]};
      double metric[3];
      buildMetric(gf, edgeCenter, metric);
      if(!inCircumCircleAniso(gf, t1->tri(), uv4, metric, data)){
        delete t1b;
        delete t2b;
        return false;
      }
    }
    break;
  default :
    Msg::Error("Unknown swapping criterion");
    delete t1b;
    delete t2b;
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

  int i10 = data.getIndex(t1b->getVertex(0));
  int i11 = data.getIndex(t1b->getVertex(1));
  int i12 = data.getIndex(t1b->getVertex(2));

  int i20 = data.getIndex(t2b->getVertex(0));
  int i21 = data.getIndex(t2b->getVertex(1));
  int i22 = data.getIndex(t2b->getVertex(2));

  double lc1 = 0.3333333333 * (data.vSizes[i10] + data.vSizes[i11] +
                               data.vSizes[i12]);
  double lcBGM1 = 0.3333333333 * (data.vSizesBGM[i10] + data.vSizesBGM[i11] +
                                  data.vSizesBGM[i12]);

  double lc2 = 0.3333333333 * (data.vSizes[i20] + data.vSizes[i21] +
                               data.vSizes[i22]);
  double lcBGM2 = 0.3333333333 * (data.vSizesBGM[i20] + data.vSizesBGM[i21] +
                                  data.vSizesBGM[i22]);

  MTri3 *t1b3 = new MTri3(t1b, Extend1dMeshIn2dSurfaces() ?
                          std::min(lc1, lcBGM1) : lcBGM1, 0, &data, gf);
  MTri3 *t2b3 = new MTri3(t2b, Extend1dMeshIn2dSurfaces() ?
                          std::min(lc2, lcBGM2) : lcBGM2, 0, &data, gf);

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
		 const swapCriterion &cr,bidimMeshData & data)
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
	  if(edgeSwap(configs, *it, gf, i, newTris, cr, data)){
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

int edgeSwapPass2(GFace *gf, std::set<MTri3*, compareTri3Ptr> &allTris,
                 const swapCriterion &cr,bidimMeshData & data)
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
          if(edgeSwap(configs, *it, gf, i, newTris, cr, data)){
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




static int _recombineIntoQuads(GFace *gf, double minqual, bool cubicGraph = 1)
{
  // never recombine a face that is part of a compound!
  if(gf->getCompound()) return 0;
  if(gf->triangles.size() == 0) return 1;

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
        std::map<MVertex*,std::pair<MElement*,MElement*> > :: iterator itv =
          makeGraphPeriodic.find(v);
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

  if(CTX::instance()->mesh.algoRecombine != 0){
#if defined(HAVE_BLOSSOM)
    int ncount = gf->triangles.size();
    if (ncount % 2 != 0 && CTX::instance()->mesh.algoRecombine == 1) {
      Msg::Warning("Cannot apply Blosson: odd number of triangles (%d) in surface %d",
                   ncount, gf->tag());
    }
    if (ncount % 2 == 0) {
      int ecount =  cubicGraph ? pairs.size() + makeGraphPeriodic.size() : pairs.size();
      Msg::Info("Blossom: %d internal %d closed",
                (int)pairs.size(), (int)makeGraphPeriodic.size());
      //Msg::Info("Cubic Graph should have ne (%d) = 3 x nv (%d) ",ecount,ncount);
      Msg::Debug("Perfect Match Starts %d edges %d nodes",ecount,ncount);
      std::map<MElement*,int> t2n;
      std::map<int,MElement*> n2t;
      for (unsigned int i=0;i<gf->triangles.size();++i){
        t2n[gf->triangles[i]] = i;
        n2t[i] = gf->triangles[i];
      }
      //do not use new[] here, blossom will free it with free() and not with delete
      int *elist = (int*)malloc(sizeof(int) * 2 * ecount);
      int *elen  = (int*)malloc(sizeof(int) * ecount);
      for (unsigned int i = 0; i < pairs.size(); ++i){
        elist[2*i] = t2n[pairs[i].t1];
        elist[2*i+1] = t2n[pairs[i].t2];
        elen [i] =  (int) 1000*exp(-pairs[i].angle);
        int NB = 0;
        if (pairs[i].n1->onWhat()->dim() < 2) NB++;
        if (pairs[i].n2->onWhat()->dim() < 2) NB++;
        if (pairs[i].n3->onWhat()->dim() < 2) NB++;
        if (pairs[i].n4->onWhat()->dim() < 2) NB++;
        if (elen[i] > (int)1000*exp(.1) && NB > 2) { elen[i] = 5000; }
        else if (elen[i] >= 1000 && NB > 2) { elen[i] = 10000; }
      }

      if (cubicGraph){
        std::map<MVertex*, std::pair<MElement*, MElement*> >::iterator itv =
          makeGraphPeriodic.begin();
        int CC = pairs.size();
        for ( ; itv != makeGraphPeriodic.end(); ++itv){
          elist[2*CC] = t2n[itv->second.first];
          elist[2*CC+1] = t2n[itv->second.second];
          elen [CC++] = 100000;
        }
      }

      double matzeit = 0.0;
      char MATCHFILE[256];
      sprintf(MATCHFILE,".face.match");
      if(perfect_match(ncount, NULL, ecount, &elist, &elen, NULL, MATCHFILE,
                       0, 0, 0, 0, &matzeit)){
        Msg::Error("Perfect Match failed in Quadrangulation, try something else");
        free(elist);
        pairs.clear();
      }
      else{
        // TEST
        for (int k = 0; k < elist[0]; k++){
          int i1 = elist[1+3*k], i2 = elist[1+3*k+1], an=elist[1+3*k+2];
          // FIXME !
          if (an == 100000 /*|| an == 1000*/){
            // toProcess.push_back(std::make_pair(n2t[i1],n2t[i2]));
            // Msg::Warning("Extra edge found in blossom algorithm, optimization "
            //              "will be required");
          }
          else{
            MElement *t1 = n2t[i1];
            MElement *t2 = n2t[i2];
            touched.insert(t1);
            touched.insert(t2);
            MVertex *other = 0;
            for(int i = 0; i < 3; i++) {
              if (t1->getVertex(0) != t2->getVertex(i) &&
                  t1->getVertex(1) != t2->getVertex(i) &&
                  t1->getVertex(2) != t2->getVertex(i)){
                other = t2->getVertex(i);
                break;
              }
            }
            int start = 0;
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
        free(elist);
        pairs.clear();
        Msg::Debug("Perfect Match Succeeded in Quadrangulation (%g sec)", matzeit);
      }
    }

#else
    Msg::Warning("Gmsh should be compiled with the Blossom IV code and CONCORDE "
                 "in order to allow the Blossom optimization");
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

  if(CTX::instance()->mesh.algoRecombine != 1){
    quadsToTriangles(gf, minqual);
  }

  return success;
}

static double printStats(GFace *gf,const char *message)
{
  int nbBad=0;
  int nbInv=0;
  double Qav=0;
  double Qmin=1;
  for (unsigned int i=0;i<gf->quadrangles.size();i++){
    double Q = gf->quadrangles[i]->etaShapeMeasure() ;
    if (Q <= 0.0)nbInv ++;
    if (Q <= 0.1)nbBad ++;
    Qav += Q;
    Qmin = std::min(Q,Qmin);
  }
  Msg::Info("%s: %5d quads %5d triangles %1d invalid quads %2d quads with Q < 0.1 "
            "Avg Q = %5.3f Min Q %5.3f", message, gf->quadrangles.size(),
            gf->triangles.size(), nbInv, nbBad, Qav/gf->quadrangles.size(), Qmin);
  return Qmin;
}

void recombineIntoQuads(GFace *gf,
                        bool topologicalOpti,
                        bool nodeRepositioning,
                        double minqual,
                        bool firstpass)
{
  double t1 = Cpu();

  bool haveParam = true;
  bool saveAll = false; //CTX::instance()->mesh.saveAll;
  if(gf->geomType() == GEntity::DiscreteSurface && !gf->getCompound())
    haveParam = false;

  if (saveAll) gf->model()->writeMSH("before.msh");
  int success = _recombineIntoQuads(gf, minqual);

  if (saveAll) gf->model()->writeMSH("raw.msh");
  if(haveParam && nodeRepositioning){
    RelocateVertices (gf,CTX::instance()->mesh.nbSmoothing);
  }

  // blossom-quad algo
  if(success && CTX::instance()->mesh.algoRecombine != 0){
    if(topologicalOpti){
      if(haveParam){
        if (saveAll) gf->model()->writeMSH("smoothed.msh");
        int ITER=0;
        std::set<MEdge,Less_Edge> prioritory;
        int nbTwoQuadNodes = 1;
        int nbDiamonds = 1;
        while(nbTwoQuadNodes || nbDiamonds){
          nbTwoQuadNodes = removeTwoQuadsNodes(gf);
          nbDiamonds = removeDiamonds(gf) ;
          if(haveParam) RelocateVertices (gf,CTX::instance()->mesh.nbSmoothing);
          //          printStats (gf, "toto");
          if (ITER > 20) break;
          ITER ++;
        }
      }
    }
    quadsToTriangles(gf, minqual);
    if(haveParam)RelocateVertices (gf,CTX::instance()->mesh.nbSmoothing);

    double t2 = Cpu();
    char name[256];
    sprintf(name,"Blossom completed (%4.2f s)", t2 - t1);
    if (firstpass)printStats (gf, name);
    else printStats (gf, "Second pass               ");
    return;
  }

  // simple recombination algo
  for (int IT=0;IT<2;IT++){
    _recombineIntoQuads(gf, 0);
    if(haveParam)     RelocateVertices (gf,CTX::instance()->mesh.nbSmoothing);
  }

  if (saveAll) gf->model()->writeMSH("after.msh");

  double t2 = Cpu();
  Msg::Info("Simple recombination algorithm completed (%g s)", t2 - t1);
}

void quadsToTriangles(GFace *gf, double minqual)
{

  std::vector<MQuadrangle*> qds;
  std::map<MElement*, std::pair<MElement*,MElement*> > change;
  for (unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    if (q->gammaShapeMeasure() < minqual){
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
	change[q] = std::make_pair(t11,t12);
        delete t21; delete t22;
      }
      else {
        gf->triangles.push_back(t21);
        gf->triangles.push_back(t22);
	change[q] = std::make_pair(t21,t22);
        delete t11; delete t12;
      }
      delete q; // FIXME this makes gmsh to crash when creating BL with triangles
      // FIXED (JF)
    }
    else {
      qds.push_back(q);
    }
  }
  gf->quadrangles = qds;

  BoundaryLayerColumns* _columns = gf->getColumns();
  if (!_columns)return;
  for ( std::map<MElement*,std::vector<MElement*> >::iterator it = _columns->_elemColumns.begin();
	it != _columns->_elemColumns.end();it++){
    std::vector<MElement *> &e = it->second;
    std::vector<MElement *> eOld = e;
    e.clear();
    for (unsigned int i=0;i<eOld.size();i++){
      MElement *ee = eOld[i];
      std::map<MElement*, std::pair<MElement*,MElement*> >::iterator it2 = change.find(ee);
      if (it2 == change.end()){
	e.push_back(ee);
      }
      else {
	e.push_back(it2->second.first);
	e.push_back(it2->second.second);
      }
    }
  }


}
