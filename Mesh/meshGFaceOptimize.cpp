// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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
#include "robustPredicates.h"

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

static int SANITY_(GFace *gf,MQuadrangle *q1, MQuadrangle *q2)
{
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

double surfaceTriangleUV(MVertex *v1, MVertex *v2, MVertex *v3,bidimMeshData & data)
{
  int index1 = data.getIndex(v1);
  int index2 = data.getIndex(v2);
  int index3 = data.getIndex(v3);
  const double v12[2] = {data.Us[index2] - data.Us[index1],
                         data.Vs[index2] - data.Vs[index1]};
  const double v13[2] = {data.Us[index3] - data.Us[index1],
                         data.Vs[index3] - data.Vs[index1]};
  return 0.5 * fabs (v12[0] * v13[1] - v12[1] * v13[0]);
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
    if(it->second.size() == 4 && it->first->onWhat()->dim() == 2) {
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

void removeThreeTrianglesNodes(GFace *gf)
{
  while(_removeThreeTrianglesNodes(gf));
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

static bool _isItAGoodIdeaToCollapseThatVertex (GFace *gf,
                                                std::vector<MElement*> &e1,
                                                std::vector<MElement*> &e2,
                                                MElement *q,
                                                MVertex *v1,
                                                MVertex *v2,
                                                MVertex *v,
                                                double FACT)
{
  double surface_old = surfaceFaceUV(q,gf);
  double surface_new = 0;
  double worst_quality_old = q->etaShapeMeasure();
  double worst_quality_new = 1.0;

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
    worst_quality_old = std::min(worst_quality_old,e1[j]-> etaShapeMeasure());
    for (int k=0;k<e1[j]->getNumVertices();k++){
      if (e1[j]->getVertex(k) == v1 && e1[j] != q)
        e1[j]->setVertex(k,v);
    }
    surface_new += surfaceFaceUV(e1[j],gf);
    worst_quality_new = std::min(worst_quality_new,e1[j]-> etaShapeMeasure());
    for (int k=0;k<e1[j]->getNumVertices();k++){
      if (e1[j]->getVertex(k) == v && e1[j] != q)
        e1[j]->setVertex(k,v1);
    }
  }

  for (unsigned int j=0;j<e2.size();++j){
    surface_old += surfaceFaceUV(e2[j],gf);
    worst_quality_old = std::min(worst_quality_old,e2[j]-> etaShapeMeasure());
    for (int k=0;k<e2[j]->getNumVertices();k++){
      if (e2[j]->getVertex(k) == v2 && e2[j] != q)
        e2[j]->setVertex(k,v);
    }
    surface_new += surfaceFaceUV(e2[j],gf);
    worst_quality_new = std::min(worst_quality_new,e2[j]-> etaShapeMeasure());
    for (int k=0;k<e2[j]->getNumVertices();k++){
      if (e2[j]->getVertex(k) == v && e2[j] != q)
        e2[j]->setVertex(k,v2);
    }
  }

  if ( fabs (surface_old - surface_new ) > 1.e-10 * surface_old ){
    //       ||       FACT*worst_quality_new <  worst_quality_old ) {

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


static bool _isItAGoodIdeaToMoveThoseVertices (GFace *gf,
                                               const std::vector<MElement*> &e1,
                                               std::vector<MVertex *>v,
                                               const std::vector<SPoint2> &before,
                                               const std::vector<SPoint2> &after)
{
  double surface_old = 0;
  double surface_new = 0;

  double umin=1.e22,umax=-1.e22,vmin=1.e22,vmax=-1.e22;

  for (unsigned int i=0; i<v.size();++i){
    umin = std::min(before[i].x(),umin);
    vmin = std::min(before[i].y(),vmin);
    umax = std::max(before[i].x(),umax);
    vmax = std::max(before[i].y(),vmax);
  }

  std::vector<SPoint3> pafter(v.size()), pbefore(v.size());
  for (unsigned int i=0; i<v.size();++i){
    if (after[i].x() > umax)return false;
    if (after[i].x() < umin)return false;
    if (after[i].y() > vmax)return false;
    if (after[i].y() < vmin)return false;
    GPoint gp = gf->point(after[i]);
    if (!gp.succeeded())return false;
    pafter[i] = SPoint3  (gp.x(),gp.y(),gp.z());
    pbefore[i] = SPoint3(v[i]->x(),v[i]->y(),v[i]->z());
  }

  for (unsigned int j=0;j<e1.size();++j)
    surface_old += surfaceFaceUV(e1[j],gf);

  for (unsigned int i=0; i<v.size();++i){
    if (v[i]->onWhat()->dim() == 2){
      v[i]->setParameter(0,after[i].x());
      v[i]->setParameter(1,after[i].y());
      v[i]->setXYZ(pafter[i].x(),pafter[i].y(),pafter[i].z());
    }
  }

  for (unsigned int j=0;j<e1.size();++j){
    surface_new += surfaceFaceUV(e1[j],gf);
  }

  for (unsigned int i=0; i<v.size();++i){
    if (v[i]->onWhat()->dim() == 2){
      v[i]->setParameter(0,before[i].x());
      v[i]->setParameter(1,before[i].y());
      v[i]->setXYZ(pbefore[i].x(),pbefore[i].y(),pbefore[i].z());
    }
  }

  //  if (fabs(surface_new-surface_old) > 1.e-10 * surface) {
  if (surface_new > 1.0001*surface_old) {
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
                                         MVertex *v4)
{
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

// see paper from Bunin Guy Bunin (2006) Non-Local Topological Cleanup ,15th
// International Meshing Roundtable. This is our interpretation of the
// algorithm.
static std::vector<MVertex*> closestPathBetweenTwoDefects (v2t_cont &adj,
                                                           v2t_cont :: iterator it)
{
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
    for (unsigned int i = 0; i < it->second.size(); i++){
      for (int j = 0; j < 4; j++){
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
          //          printf("PATH : ");
          //          for (int i=0;i<path.size();i++){
          //            printf("%d ",path[i]->getNum());
          //          }
          //          printf("\n");
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
  if (!gp.succeeded()) {
    printf("******* ARRG new vertex not created p=%g %g \n", p.x(), p.y());
    return NULL;
  }
  return new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
}
std::vector<MVertex*> saturateEdge (GFace *gf, SPoint2 p1, SPoint2 p2, int n){
  std::vector<MVertex*> pts;
  for (int i=1;i<n;i++){
    SPoint2 p = p1 + (p2-p1)*((double)i/((double)(n)));
    MVertex *v = createNewVertex(gf,p);
    if (!v){ pts.clear(); pts.resize(0); return pts;}
    pts.push_back(v);
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


void createRegularMesh (GFace *gf,
                         MVertex *v1, SPoint2 &c1,
                         std::vector<MVertex*> &e12, int sign12,
                         MVertex *v2, SPoint2 &c2,
                         std::vector<MVertex*> &e23, int sign23,
                         MVertex *v3, SPoint2 &c3,
                         std::vector<MVertex*> &e34, int sign34,
                         MVertex *v4, SPoint2 &c4,
                         std::vector<MVertex*> &e41, int sign41,
                         std::vector<MQuadrangle*> &q)
{
  int N = e12.size();
  int M = e23.size();

 char name3[234];
  sprintf(name3,"quadParam_%d.pos", gf->tag());
  FILE *f3 = Fopen(name3,"w");
  fprintf(f3,"View \"%s\" {\n",name3);

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
    tab[i+1][0]   = sign41 < 0 ? e41 [i] : e41 [M-i-1];
  }

  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      double u = (double) (i+1)/ ((double)(N+1));
      double v = (double) (j+1)/ ((double)(M+1));
      MVertex *v12 = (sign12 >0) ? e12[i] : e12 [N-1-i];
      MVertex *v23 = (sign23 >0) ? e23[j] : e23 [M-1-j];
      MVertex *v34 = (sign34 <0) ? e34[i] : e34 [N-1-i];
      MVertex *v41 = (sign41 <0) ? e41[j] : e41 [M-1-j];
      SPoint2 p12; reparamMeshVertexOnFace(v12, gf, p12);
      SPoint2 p23; reparamMeshVertexOnFace(v23, gf, p23);
      SPoint2 p34; reparamMeshVertexOnFace(v34, gf, p34);
      SPoint2 p41; reparamMeshVertexOnFace(v41, gf, p41);
      double Up = TRAN_QUA(p12.x(), p23.x(), p34.x(), p41.x(),
                           c1.x(),c2.x(),c3.x(),c4.x(),u,v);
      double Vp = TRAN_QUA(p12.y(), p23.y(), p34.y(), p41.y(),
                           c1.y(),c2.y(),c3.y(),c4.y(),u,v);
      fprintf(f3,"SP(%g,%g,%g) {%d};\n", Up, Vp, 0.0, 1);

      // printf("v1=%d v2=%d v3=%d v4=%d \n", v1->getNum(), v2->getNum(), v3->getNum(), v4->getNum());
      // printf("c1=%g %g, c2=%g %g, c3=%g %g, c4=%g,%g \n", c1.x(),c1.y(),c2.x(),c2.y(),c3.x(),c3.y(),c4.x(),c4.y());
      // printf("p1=%g %g, p2=%g %g, p3=%g %g, p4=%g,%g \n", p12.x(),p12.x(),p23.x(),p23.y(),p34.x(),p34.y(),p41.x(),p41.y());
      if ((p12.x() && p12.y() == -1.0) ||
          (p23.x() && p23.y() == -1.0) ||
          (p34.x() && p34.y() == -1.0) ||
          (p41.x() && p41.y() == -1.0)) {
        Msg::Error("Wrong param -1");
        fclose(f3);
        return;
      }

      MVertex *vnew = createNewVertex (gf, SPoint2(Up,Vp));
      tab[j+1][i+1] = vnew;
    }
  }
  // create quads
  for (int i=0;i<=N;i++){
    for (int j=0;j<=M;j++){
      MQuadrangle *qnew = new MQuadrangle (tab[j][i],tab[j][i+1],tab[j+1][i+1],tab[j+1][i]);
      q.push_back(qnew);
    }
  }

  fprintf(f3,"};\n");
  fclose(f3);

}

void updateQuadCavity (GFace *gf,
                       v2t_cont &adj,
                       std::vector<MElement*> &oldq,
                       std::vector<MQuadrangle*> &newq)
{
  for (unsigned int i = 0; i < oldq.size(); i++){
    gf->quadrangles.erase(std::remove(gf->quadrangles.begin(),
                                      gf->quadrangles.end(),oldq[i]));
    for (int j=0;j<4;j++){
      MVertex *v = oldq[i]->getVertex(j);
      v2t_cont :: iterator it = adj.find(v);
      if (it == adj.end())Msg::Error("cannot update a quad cavity");
      it->second.erase(std::remove(it->second.begin(),it->second.end(),oldq[i]));
    }
    //    delete oldq[i];
  }
  for (unsigned int i = 0; i < newq.size(); i++){
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
  int iBlob;
  v2t_cont &adj;
  std::vector<MElement*> quads;
  std::vector<MVertex*> nodes;
  std::vector<MVertex*> bnodes;
  static bool matricesDone;
  static fullMatrix<double> M3 ;
  static fullMatrix<double> M5 ;

  quadBlob(v2t_cont &a, std::vector<MVertex*> & path, GFace *g, int maxC)
    : gf(g),maxCavitySize(maxC),iBlob(0),adj(a)
  {
    expand_blob(path);
  }
  inline bool inBlob(MElement* e) const
  {
    return std::find(quads.begin(), quads.end(), e) != quads.end();
  }
  inline bool inBoundary(MVertex *v, std::vector<MVertex*> &b) const
  {
    return std::find(b.begin(), b.end(), v) != b.end();
  }
  inline void setBlobNumber(int number) { iBlob = number; }
  static void computeMatrices()
  {
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
  void expand_blob (std::vector<MVertex*> & path)
  {
    std::set<MElement*> e;
    e.insert(quads.begin(),quads.end());
    for (unsigned int i = 0; i < path.size(); i++){
      v2t_cont :: const_iterator it = adj.find(path[i]);
      e.insert(it->second.begin(),it->second.end());
    }
    quads.clear();
    quads.insert(quads.begin(),e.begin(),e.end());
    std::set<MVertex*> all;
    for (unsigned int i = 0; i < quads.size(); i++)
      for (int j = 0; j < 4; j++)
        all.insert(quads[i]->getVertex(j));
    nodes.clear();
    nodes.insert(nodes.begin(),all.begin(),all.end());
    bnodes.clear();
  }
  void buildBoundaryNodes()
  {
    bnodes.clear();
    for (unsigned int i = 0; i < nodes.size(); i++){
      v2t_cont :: const_iterator it = adj.find(nodes[i]);
      if (it->first->onWhat()->dim() < 2) bnodes.push_back(nodes[i]);
      else {
        bool found = false;
        for (unsigned int j = 0; j < it->second.size(); j++){
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
  int topologicalAngle(MVertex*v) const
  {
    int typical = 0;
    v2t_cont :: const_iterator it = adj.find(v);
    int outside = 0;
    for (unsigned int j = 0; j < it->second.size(); j++)
      if (!inBlob(it->second[j])) outside++;

    if (v->onWhat()->dim() == 1) typical = 2;
    else if (v->onWhat()->dim() == 0) typical = 3;

    return outside - 2 + typical;
  }
  int construct_meshable_blob (int iter)
  {
    int blobsize = quads.size();
    //printf("*** starting with a blob of size %d (ITER=%d)\n",blobsize, iter);
    while(1){
      if((int)quads.size() > maxCavitySize) return 0;
      if(quads.size() >= gf->quadrangles.size()) return 0;
      buildBoundaryNodes();
      int topo_convex_region = 1;
      for (unsigned int i = 0; i < bnodes.size(); i++){
        MVertex *v = bnodes[i];
        // do not do anything in boundary layers !!!
        if (v->onWhat()->dim() == 2){
          MFaceVertex *fv = dynamic_cast<MFaceVertex*>(v);
          if(fv && fv->bl_data) return 0;
        }
        int topo_angle = topologicalAngle(v);
        if (topo_angle < 0){
          std::vector<MVertex*> vv; vv.push_back(v);
          expand_blob(vv);
          topo_convex_region = 0;
        }
      }
      if (topo_convex_region){
        if (meshable(iter)) return 1;
        else expand_blob(bnodes);
      }
      if (blobsize == (int)quads.size()) return 0;
      blobsize = quads.size();
    }// while 1
  }
  bool orderBNodes ()
  {
    MVertex *v = 0;
    std::vector<MVertex*> temp;
    for (unsigned int i = 0; i < bnodes.size(); i++){
      if (topologicalAngle(bnodes[i]) > 0){
        v = bnodes[i];
        break;
      }
    }
    temp.push_back(v);

    //bool oriented = true;
    while(1){
      v2t_cont :: const_iterator it = adj.find(v);
      int ss = temp.size();
      std::vector<MElement*> elems = it->second;

      //EMI: try to orient BNodes the same as quad orientations
       for (unsigned int j = 0; j < elems.size(); j++){
                bool found  =false;
              if(inBlob(elems[j])){
                for (int i = 0; i < 4; i++){
                  MVertex *v0 = elems[j]->getVertex(i%4);
                  MVertex *v1 = elems[j]->getVertex((i+1)%4);
                  if (v0 == v && inBoundary(v1,bnodes) && !inBoundary(v1,temp)) {
                    v = v1;
                    temp.push_back(v1);
                    found = true;
                    break;
                  }
                }
       }
       if (found) break;
       }

       //JF this does not orient quads
      // for (int j=0;j<elems.size();j++){
      //         bool found = false;
      //         if(inBlob(elems[j])){
      //         for (int i=0;i<4;i++){
      //           MEdge e = elems[j]->getEdge(i);
      //           if (e.getVertex(0) == v &&
      //               inBoundary(e.getVertex(1),bnodes) &&
      //               !inBoundary(e.getVertex(1),temp)) {
      //             v = e.getVertex(1);
      //             temp.push_back(e.getVertex(1));
      //             found = true;
      //             break;
      //           }
      //            else if (e.getVertex(1) == v &&
      //                        inBoundary(e.getVertex(0),bnodes) &&
      //                        !inBoundary(e.getVertex(0),temp)) {
      //              v = e.getVertex(0);
      //              temp.push_back(e.getVertex(0));
      //              found = true;
      //              break;
      //            }
      //         }
      //         }
      //         if (found)break;
      // }

       if ((int)temp.size() == ss) return false;
      if (temp.size() == bnodes.size()) break;
    }

    //change orientation
    // bool oriented = false;
    // MVertex *vB1 = temp[0];
    // MVertex *vB2 = temp[1];
    // v2t_cont :: const_iterator it = adj.find(vB1);
    // for (int j=0;j<it->second.size();j++){
    //         for (int i=0;i<4;i++){
    //           MVertex *v0 = it->second[j]->getVertex(i%4);
    //           MVertex *v1 = it->second[j]->getVertex((i+1)%4);
    //           if (v0==vB1 && v1==vB2){oriented = true; break;}
    //         }
    //         if (oriented) break;
    // }
    // std::vector<MVertex*> temp2;
    // temp2.push_back(temp[0]);
    // if (!oriented) {
    //    std::reverse(temp.begin(), temp.end());
    //    for (int i = 0; i< temp.size()-1; i++) temp2.push_back(temp[i]);
    //    temp = temp2;
    // }

    bnodes = temp;
    return true;
  }
  void printBlob(int iter, int method)
  {
    if (!CTX::instance()->mesh.saveAll) return;
    char name[234];
    sprintf(name,"blob%d_%d_%d.pos", iBlob, iter, method);
    FILE *f = Fopen(name,"w");
    fprintf(f,"View \"%s\" {\n",name);
    for (unsigned int i = 0; i < quads.size(); i++){
      quads[i]->writePOS(f,true,false,false,false,false,false);
    }
    for (unsigned int i = 0; i < bnodes.size(); i++){
      fprintf(f,"SP(%g,%g,%g) {%d};\n",
              bnodes[i]->x(),
              bnodes[i]->y(),
              bnodes[i]->z(),topologicalAngle(bnodes[i]));
    }
    fprintf(f,"};\n");
    fclose(f);
  }
  void smooth (int);
  bool meshable (int iter)
  {
    int ncorners = 0;
    MVertex *corners[5] = {0, 0, 0, 0, 0};
    for (unsigned int i = 0; i < bnodes.size(); i++){
      if (topologicalAngle(bnodes[i]) > 0) ncorners ++;
      if (ncorners > 5) return false;
    }
    if (ncorners != 3 && ncorners != 4 && ncorners != 5){
      return false;
    }
    //printf("meshable blob with %d corners has been found\n",ncorners);

    // look if it is possible to build a mesh with one defect only
    if (!orderBNodes () )return false;
    int side = 0;
    int count[5] = {0,0,0,0,0};
    for (unsigned int i = 0; i < bnodes.size(); i++){
      if (topologicalAngle(bnodes[i]) > 0){
        corners[side] = (bnodes[i]);
        side++;
      }
      else count[side]++;
    }

    if (ncorners == 3){

      fullVector<double> rhs(6);
      fullVector<double> result(6);
      rhs(3) = count[0]+1.;
      rhs(4) = count[1]+1.;
      rhs(5) = count[2]+1.;
      rhs(0) = rhs(1) = rhs(2) = 0.;
      M3.mult(rhs,result);
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
      SPoint2 p012 = (p01+p12+p20)*(1./3.0);

      std::vector<MVertex*> e012_01 = saturateEdge (gf,p012,p01,a2);
      std::vector<MVertex*> e012_12 = saturateEdge (gf,p012,p12,a3);
      std::vector<MVertex*> e012_20 = saturateEdge (gf,p012,p20,a1);
      if (e012_01.size() == 0) return false;
      if (e012_12.size() == 0) return false;
      if (e012_20.size() == 0) return false;

      MVertex *v012 = createNewVertex (gf, p012);

      std::vector<MVertex*> e0_01,e01_1,e1_12,e12_2,e2_20,e20_0;
      for (int i=0;i<a1-1;i++)e0_01.push_back(bnodes[i+1]);
      for (int i=0;i<a3-1;i++)e01_1.push_back(bnodes[i+1 + a1]);
      for (int i=0;i<a2-1;i++)e1_12.push_back(bnodes[i+1 + a1 + a3]);
      for (int i=0;i<a1-1;i++)e12_2.push_back(bnodes[i+1 + a1 + a3 + a2]);
      for (int i=0;i<a3-1;i++)e2_20.push_back(bnodes[i+1 + a1 + a3 + a2 + a1 ]);
      for (int i=0;i<a2-1;i++)e20_0.push_back(bnodes[i+1 + a1 + a3 + a2 + a1 + a3]);

      std::vector<MQuadrangle*> q;
      createRegularMesh (gf,
                         v012,p012,
                         e012_20, +1,
                         v20,p20,
                         e20_0, +1,
                         v0,p0,
                         e0_01, +1,
                         v01,p01,
                         e012_01, -1,
                         q);

      createRegularMesh (gf,
                         v012,p012,
                         e012_12, +1,
                         v12,p12,
                         e12_2, +1,
                         v2,p2,
                         e2_20, +1,
                         v20,p20,
                         e012_20, -1,
                         q);

      createRegularMesh (gf,
                         v012,p012,
                         e012_01, +1,
                         v01,p01,
                         e01_1, +1,
                         v1,p1,
                         e1_12, +1,
                         v12,p12,
                         e012_12, -1,
                         q);

      printBlob(iter,3);
      updateQuadCavity (gf,adj,quads,q);
      quads.clear();
      quads.insert(quads.begin(),q.begin(),q.end());
      printBlob(iter,33);
      return 1;
    }
   /*
      This is the configuration for the 4 corners defect
      only the simple case is considered
   */
   else if (ncorners == 4){
      if (count[0] != count[2] || count[1] != count[3]){
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

      printBlob(iter,4);
      updateQuadCavity (gf,adj,quads,q);
      quads.clear();
      quads.insert(quads.begin(),q.begin(),q.end());
      printBlob(iter,44);
      return 1;
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
      printBlob(iter,5);
      fullVector<double> rhs(10);
      fullVector<double> result(10);
      rhs(5) = count[0]+1.;
      rhs(6) = count[1]+1.;
      rhs(7) = count[2]+1.;
      rhs(8) = count[3]+1.;
      rhs(9) = count[4]+1.;
      rhs(0) = rhs(1) = rhs(2) = rhs(3) = rhs(4) = 0.;
      M5.mult(rhs,result);
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
      SPoint2 p01234 = (p01+p12+p23+p34+p40)*(1./5.0);

      std::vector<MVertex*> e01234_01 = saturateEdge (gf,p01234,p01,a2);
      std::vector<MVertex*> e01234_12 = saturateEdge (gf,p01234,p12,a3);
      std::vector<MVertex*> e01234_23 = saturateEdge (gf,p01234,p23,a4);
      std::vector<MVertex*> e01234_34 = saturateEdge (gf,p01234,p34,a5);
      std::vector<MVertex*> e01234_40 = saturateEdge (gf,p01234,p40,a1);
      if (e01234_01.size() == 0) return false;
      if (e01234_12.size() == 0) return false;
      if (e01234_23.size() == 0) return false;
      if (e01234_34.size() == 0) return false;
      if (e01234_40.size() == 0) return false;

      MVertex *v01234 = createNewVertex (gf, p01234);

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
                         e01234_40, +1,
                         v40,p40,
                         e40_0, +1,
                         v0,p0,
                         e0_01, +1,
                         v01,p01,
                         e01234_01, -1,
                         q);
      // 2
      createRegularMesh (gf,
                         v01234,p01234,
                         e01234_01, +1,
                         v01,p01,
                         e01_1, +1,
                         v1,p1,
                         e1_12, +1,
                         v12,p12,
                         e01234_12, -1,
                         q);

       // 3
      createRegularMesh (gf,
                         v01234,p01234,
                         e01234_12, +1,
                         v12,p12,
                         e12_2, +1,
                         v2,p2,
                         e2_23, +1,
                         v23,p23,
                         e01234_23, -1,
                         q);

       // 4
      createRegularMesh (gf,
                         v01234,p01234,
                         e01234_23, +1,
                         v23,p23,
                         e23_3, +1,
                         v3,p3,
                         e3_34, +1,
                         v34,p34,
                         e01234_34, -1,
                         q);

      // 5
      createRegularMesh (gf,
                         v01234,p01234,
                         e01234_34, +1,
                         v34,p34,
                         e34_4, +1,
                         v4,p4,
                         e4_40, +1,
                         v40,p40,
                         e01234_40, -1,
                         q);

       printBlob(iter,55);
       updateQuadCavity (gf,adj,quads,q);
       quads.clear();
       quads.insert(quads.begin(),q.begin(),q.end());
       printBlob(iter,555);
      return 1;
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
  printf("ARGH\n");
  v2t_cont adj;
  std::vector<MElement*> c;
  buildVertexToElement(gf->quadrangles, adj);
  quadBlob::computeMatrices();

  int iter = 0;
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
  for (unsigned int i = 0; i < defects.size(); i++){
    it = adj.find(defects[i]);
    if (it->first->onWhat()->dim() == 2 && it->second.size() != 4 && it->second.size() != 0) {
      double t3 = Cpu();
      std::vector<MVertex*> path = closestPathBetweenTwoDefects (adj,it);
      double t4 = Cpu();
      B += (t4-t3);
      if (path.size()){
        double t5 = Cpu();
        quadBlob blob(adj,path,gf, maxCavitySize);
        blob.setBlobNumber(i);
        if(blob.construct_meshable_blob (iter)){
          blob.printBlob(iter,0);
          blob.smooth(2*(int)(sqrt((double)maxCavitySize)));
          iter ++;
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

// if a vertex (on boundary) is adjacent to one only quad
// and if that quad is badly shaped, we split this
// quad
static int _splitFlatQuads(GFace *gf, double minQual, std::set<MEdge,Less_Edge> &prioritory)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles,adj);
  buildVertexToElement(gf->quadrangles,adj);
  v2t_cont :: iterator it = adj.begin();

  std::vector<MQuadrangle*> added_quadrangles;
  std::set<MElement*> deleted_quadrangles;
  while (it != adj.end()) {
    // split that guy if too bad
    if(it->second.size()==1 && it->first->onWhat()->dim() == 1) {
      const std::vector<MElement*> &lt = it->second;
      MElement *e = lt[0];
      if (e->getNumVertices() == 4 && e->gammaShapeMeasure() < minQual){
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
	prioritory.insert(MEdge(v2,v3));
	prioritory.insert(MEdge(v3,v4));
        SPoint2 pv1,pv2,pv3,pv4,pb1,pb2,pb3,pb4;
        reparamMeshEdgeOnFace (v1,v3,gf,pv1,pv3);
        reparamMeshEdgeOnFace (v1,v4,gf,pv1,pv4);
        reparamMeshEdgeOnFace (v2,v4,gf,pv2,pv4);
        pb1 = pv1 * (2./3.) + pv2 * (1./3.);
        pb2 = pv1 * (1./3.) + pv2 * (2./3.);
        pb3 = pv1 * (1./3.) + pv2 * (1./3.) + pv3 * (1./3.);
        pb4 = pv1 * (1./3.) + pv2 * (1./3.) + pv4 * (1./3.);
        GPoint gb1 = gf->point(pb1);
        GPoint gb2 = gf->point(pb2);
        GPoint gb3 = gf->point(pb3);
        GPoint gb4 = gf->point(pb4);
        if (!gb1.succeeded())return -1;
        if (!gb2.succeeded())return -1;
        if (!gb3.succeeded())return -1;
        if (!gb4.succeeded())return -1;
        MFaceVertex *b1 = new MFaceVertex (gb1.x(),gb1.y(),gb1.z(),gf,gb1.u(), gb1.v());
        MFaceVertex *b2 = new MFaceVertex (gb2.x(),gb2.y(),gb2.z(),gf,gb2.u(), gb2.v());
        MFaceVertex *b3 = new MFaceVertex (gb3.x(),gb3.y(),gb3.z(),gf,gb3.u(), gb3.v());
        MFaceVertex *b4 = new MFaceVertex (gb4.x(),gb4.y(),gb4.z(),gf,gb4.u(), gb4.v());
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
  for (unsigned int i = 0; i < gf->quadrangles.size(); i++){
    if (deleted_quadrangles.find(gf->quadrangles[i]) == deleted_quadrangles.end()){
      added_quadrangles.push_back(gf->quadrangles[i]);
    }
    else {
      delete gf->quadrangles[i];
    }
  }
  gf->quadrangles = added_quadrangles;
  return deleted_quadrangles.size();
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
      if (_quadWithOneVertexOnBoundary      (gf,touched,diamonds,deleted,it2->second,
                                             it4->second,it1->second,q,v1,v2,v3,v4)){}
      else if (_quadWithOneVertexOnBoundary (gf,touched,diamonds,deleted,it3->second,
                                             it1->second,it2->second,q,v2,v3,v4,v1)){}
      else if (_quadWithOneVertexOnBoundary (gf,touched,diamonds,deleted,it4->second,
                                             it2->second,it3->second,q,v3,v4,v1,v2)){}
      else if (_quadWithOneVertexOnBoundary (gf,touched,diamonds,deleted,it1->second,
                                             it3->second,it4->second,q,v4,v1,v2,v3)){}
      else if (v1->onWhat()->dim() == 2 &&
               v2->onWhat()->dim() == 2 &&
               v3->onWhat()->dim() == 2 &&
               v4->onWhat()->dim() == 2 &&
               it1->second.size() ==3 &&  it3->second.size() == 3 &&
               _isItAGoodIdeaToCollapseThatVertex (gf, it1->second, it3->second,
                                                   q, v1, v3, v3,10.)){
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
               _isItAGoodIdeaToCollapseThatVertex (gf, it1->second, it3->second,
                                                   q, v1, v3, v1,10.)){
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
               _isItAGoodIdeaToCollapseThatVertex (gf, it2->second, it4->second,
                                                   q, v2, v4, v4,10.)){
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
               _isItAGoodIdeaToCollapseThatVertex (gf, it2->second, it4->second,
                                                   q, v2, v4, v2,10.)){
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

int splitFlatQuads(GFace *gf, double q, std::set<MEdge,Less_Edge> &prioritory)
{
  int nbRemove = 0;
  while(1){
    int x = _splitFlatQuads(gf,q, prioritory);
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

/*
static void sort_edges (std::vector<MEdge> &eds){

  std::list<MEdge> eds_sorted;
  eds_sorted.push_back(*eds.begin());
  eds.erase(eds.begin());

  while(!eds.empty()){
    MEdge first = (eds_sorted.front());
    MEdge last  = (eds_sorted.back());
    for (unsigned int i=0;i<eds.size();i++){
      MVertex *v1 = eds[i].getVertex(0);
      MVertex *v2 = eds[i].getVertex(1);
      bool found = true;
      // v1 -- v2 -- first
      if (first.getVertex(0) == v2) eds_sorted.push_front(MEdge(v1,v2));
      // v2 -- v1 -- first
      else if (first.getVertex(0) == v1) eds_sorted.push_front(MEdge(v2,v1));
      // last -- v1 -- v2
      else if (last.getVertex(1) == v1) eds_sorted.push_back(MEdge(v1,v2));
      // last -- v2 -- v1
      else if (last.getVertex(1) == v2) eds_sorted.push_back(MEdge(v2,v1));
      else found = false;
      if (found) {
        eds.erase(eds.begin() + i);
        break;
      }
    }
  }
  eds.insert(eds.begin(),eds_sorted.begin(),eds_sorted.end());
}
*/
//static int OPTI_NUMBER = 1;
struct opti_data_vertex_relocation {
  int nv;
  const std::vector<MElement*> & e;
  MVertex *v[4];
  bool movable[4];
  GFace *gf;
  opti_data_vertex_relocation (const std::vector<MElement*> & _e,
                               MVertex * _v, GFace *_gf)
    : nv(1),e(_e), gf(_gf)
  {
    v[0] = _v;
    movable[0] = true;
  }

  opti_data_vertex_relocation (const std::vector<MElement*> & _e,
                               MVertex * _v1, MVertex * _v2, MVertex * _v3, MVertex * _v4, GFace *_gf)
    : nv(4),e(_e), gf(_gf)
  {
    v[0] = _v1;
    v[1] = _v2;
    v[2] = _v3;
    v[3] = _v4;
    for (int i=0;i<4;i++){
      movable[i] = v[i]->onWhat()->dim() == 2;
    }
  }

  void print_cavity (char *name){
    FILE *f = Fopen(name,"w");
    fprintf(f,"View \"\"{\n");
    for (unsigned int i=0;i<e.size();++i){
      MElement *el = e[i];
      el->writePOS(f,false,false,true,false,false,false);
    }
    fprintf(f,"};");
    fclose (f);
  }

  /// quality measure for a quad

  double f() const
  {

    double val = 1.0;
    for (unsigned int i=0;i<e.size();++i){
      MElement *el = e[i];
      //      double m = log((el->gammaShapeMeasure()-minq)/(1.-minq));
      //      val += m*m;//el->gammaShapeMeasure();
      //      val =std::min(el->gammaShapeMeasure(),val);
      val -=  el->gammaShapeMeasure();
    }

    return val;
  }
  void df(const double &F, const double U[], const double V[], double dfdu[], double dfdv[])
  {
    const double eps = 1.e-6;
    for (int i=0;i<nv;i++){
      if (!set_(U[i]+eps,V[i],i)){
        for (int j=0;j<nv;j++)dfdu[j] = dfdv[j] = 0;
        return;
      }
      const double FU = f();
      set_(U[i],V[i]+eps,i);
      const double FV = f();
      set_(U[i],V[i],i);
      dfdu[i] = movable[i] ? -(F-FU)/eps : 0 ;
      dfdv[i] = movable[i] ? -(F-FV)/eps : 0;
    }
  }
  bool set_(double U, double V, int iv)
  {
    //    if (!movable[iv])return;
    //    printf("getting point of surface %d (%22.15E,%22.15E)\n",gf->tag(),U,V);
    if (!movable[iv])return true;
    GPoint gp = gf->point(U,V);
    if (!gp.succeeded()) return false;//Msg::Error("point not OK");
    v[iv]->x() = gp.x();
    v[iv]->y() = gp.y();
    v[iv]->z() = gp.z();
    v[iv]->setParameter(0,U);
    v[iv]->setParameter(1,V);
    return true;
  }
};

void bfgs_callback_vertex_relocation (const alglib::real_1d_array& x,
                                      double& func, alglib::real_1d_array& grad, void* ptr)
{
  opti_data_vertex_relocation* w = static_cast<opti_data_vertex_relocation*>(ptr);

  double u[4] ; for (int i=0;i<w->nv;i++)u[i] = x[2*i];
  double v[4] ; for (int i=0;i<w->nv;i++)v[i] = x[2*i+1];
  //  printf("hoplaboum !!!\n");
  for (int i=0;i<w->nv;i++) w->set_(u[i],v[i],i);
  func = w->f();
  //  printf("F(%3.2f,%3.2f) = %12.5E\n",x[0],x[1],func);
  double dfdu[4],dfdv[4];
  w->df(func,u,v,dfdu,dfdv);
  for (int i=0;i<w->nv;i++) {
    grad[2*i] = dfdu[i];
    grad[2*i+1] = dfdv[i];
  }
}


// use optimization for untangling one single quad
// take all neighboring quads and move all vertices
// when possible
static int _untangleQuad (GFace *gf, MQuadrangle *q,v2t_cont & adj)
{
  std::set<MElement*> all;

  int numU=0;
  for (int i=0;i<4;i++){
    std::vector<MElement*> &adji = adj[q->getVertex(i)];
    all.insert(adji.begin(),adji.end());
    // FIXME
    if (q->getVertex(i)->onWhat()->dim() == 2)numU ++;
  }
  if (numU == 0)return 0;
  std::vector<MElement*> lt;
  lt.insert(lt.begin(),all.begin(),all.end());

  double minq_old = 100.;
  for (unsigned int i = 0; i < lt.size(); i++){
    const double q = lt[i]->etaShapeMeasure();
    minq_old = std::min(q,minq_old);
  }
  //  printf("-------x--------x------------x-------------------\n");
  //  printf ("optimizing quadrangle (minq %12.5E) with BFGS\n",minq_old);


  alglib::ae_int_t dim = 8;
  alglib::ae_int_t corr = 2;
  alglib::minlbfgsstate state;
  alglib::real_1d_array x;
  std::vector<double> initial_conditions(8);
  opti_data_vertex_relocation data(lt,q->getVertex(0),q->getVertex(1),q->getVertex(2),q->getVertex(3),gf);

  //  char NNN[256];
  //  sprintf(NNN,"UNTANGLE_cavity_%d_before.pos",OPTI_NUMBER);
  //  data.print_cavity (NNN);

  double U[4],V[4];
  for (int i=0;i<4;i++){
    SPoint2 p;
    reparamMeshVertexOnFace(q->getVertex(i),gf, p);
    U[i] = p.x();
    V[i] = p.y();
    initial_conditions[2*i] = U[i];
    initial_conditions[2*i+1] = V[i];
  }
  x.setcontent(dim, &initial_conditions[0]);
  minlbfgscreate(8, corr, x, state);
  double epsg = 0.0;
  double epsf = 0.0;
  double epsx = 0.0;
  alglib::ae_int_t maxits = 12;
  minlbfgssetcond(state,epsg,epsf,epsx,maxits);
  minlbfgsoptimize(state, bfgs_callback_vertex_relocation,NULL,&data);
  alglib::minlbfgsreport rep;
  minlbfgsresults(state,x,rep);

  double minq = 100.;
  for (unsigned int i = 0; i < data.e.size(); i++){
    const double q = data.e[i]->gammaShapeMeasure();
    minq = std::min(q,minq);
  }
  //  printf("minq = %12.5E\n",minq);

  std::vector<SPoint2> before;for(int i=0;i<4;i++)before.push_back(SPoint2(U[i],V[i]));
  std::vector<SPoint2> after;
  for(int i=0;i<4;i++)
    if (q->getVertex(i)->onWhat()->dim() == 2)
      after.push_back(SPoint2(x[2*i],x[2*i+1]));
    else
      after.push_back(SPoint2(U[i],V[i]));
  std::vector<MVertex*> vs;for(int i=0;i<4;i++)vs.push_back(q->getVertex(i));
  bool success = _isItAGoodIdeaToMoveThoseVertices (gf,lt,vs,before,after);

  if (success){
    for (int i=0;i<4;i++)data.set_(x[2*i],x[2*i+1],i);
    //    sprintf(NNN,"UNTANGLE_cavity_%d_after.pos",OPTI_NUMBER++);
    //    data.print_cavity (NNN);
    return 1;
  }

  //  double minq_new = 100.;
  //  for (unsigned int i = 0; i < data.e.size(); i++){
  //    const double q = data.e[i]->gammaShapeMeasure();
  //    minq_new = std::min(q,minq_new);
  //  }

  // if (success) printf("YES %g %g\n",minq,minq_new);

  for (int i=0;i<4;i++)data.set_(U[i],V[i],i);
  return 0;
  //  return 0;
  //  else printf("OKIDOKI-UNTANGLE\n");
  return 1;
}


// use optimization
static int _relocateVertexOpti(GFace *gf, MVertex *ver,
			       const std::vector<MElement*> &lt)
{
  //  return;
  if(ver->onWhat()->dim() != 2)return 0;

  double minq_old = 100.;
  //  printf("------------------------------------------------\n");
  for (unsigned int i = 0; i < lt.size(); i++){
    const double q = lt[i]->gammaShapeMeasure();
    minq_old = std::min(q,minq_old);
    //    printf("Q(%d) = %12.5E\n",lt[i]->getNumVertices(),q);
  }

  //  printf ("optimizing vertex position (minq %12.5E) with BFGS\n",minq_old);
  // we optimize the local coordinates of the node
  alglib::ae_int_t dim = 2;
  alglib::ae_int_t corr = 2; // Num of corrections in the scheme in [3,7]
  alglib::minlbfgsstate state;
  alglib::real_1d_array x; // = "[0.5,0.5]";
  std::vector<double> initial_conditions(dim);
  opti_data_vertex_relocation data(lt,ver,gf);

  //  char NNN[256];
  //  sprintf(NNN,"cavity_%d_before.pos",OPTI_NUMBER);
  //  data.print_cavity (NNN);


  double U, V;
  ver->getParameter(0,U);
  ver->getParameter(1,V);
  initial_conditions[0] = U;
  initial_conditions[1] = V;
  x.setcontent(dim, &initial_conditions[0]);
  minlbfgscreate(2, corr, x, state);
  double epsg = 0.0;
  double epsf = 0.0;
  double epsx = 0.0;
  alglib::ae_int_t maxits = 10;
  minlbfgssetcond(state,epsg,epsf,epsx,maxits);
  minlbfgsoptimize(state, bfgs_callback_vertex_relocation,NULL,&data);
  alglib::minlbfgsreport rep;
  minlbfgsresults(state,x,rep);

  double minq = 100.;
  for (unsigned int i = 0; i < data.e.size(); i++){
    const double q = data.e[i]->gammaShapeMeasure();
    minq = std::min(q,minq);
  }
  //  printf("minq = %12.5E\n",minq);

  bool success = _isItAGoodIdeaToMoveThatVertex (gf,  lt, ver,SPoint2(U,V),SPoint2(x[0],x[1]));

  if (!success || minq < 0 || minq <= minq_old/2) data.set_(U,V,0);
  //  if (rep.terminationtype != 4){
  //    data.set_(U,V);
  //  }
  //  sprintf(NNN,"cavity_%d_after.pos",OPTI_NUMBER++);
  //  data.print_cavity (NNN);
  return success;
}
#endif

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
  //  printf("weights :");
  for(std::map<MVertex*,SPoint2>::iterator it = pts.begin(); it != pts.end() ; ++it) {
    SPoint2  adj = it->second;
    SVector3 d (adj.x()-before.x(),adj.y()-before.y(),0.0);
    d.normalize();
    buildMetric (gf,adj,metric);
    const double F = sqrt(metric[0]*d.x()*d.x() +
			  2*metric[1]*d.x()*d.y() +
			  metric[2]*d.y()*d.y());
    //    printf("%g ",F);
    after += adj*F;
    COUNT += F;
    //    //    double RATIO = lt[i]->getVolume()/pow(metric[0]*metric[2]-metric[1]*metric[1],0.5);
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

void quadBlob::smooth (int niter)
{
  for (int i = 0; i < niter; i++){
    for (unsigned int j = 0; j < nodes.size(); j++){
      v2t_cont::iterator it = adj.find(nodes[j]);
      _relocateVertex(gf, it->first, it->second);
    }
  }
}

void laplaceSmoothing(GFace *gf, int niter, bool infinity_norm)
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

int optiSmoothing(GFace *gf, int niter, bool infinity_norm)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  int N = 0;
  for(int i = 0; i < niter; i++){
    v2t_cont::iterator it = adj.begin();
    while (it != adj.end()){
      bool doit = false;
      for (unsigned int j=0;j<it->second.size();j++)
        if (it->second[j]->gammaShapeMeasure() < .05)
          doit = true;
      if (doit){
#if defined(HAVE_BFGS)
        N += _relocateVertexOpti(gf, it->first, it->second);
#endif
      }
      ++it;
    }
  }
  return N;
}

int untangleInvalidQuads(GFace *gf, int niter)
{
  // return 0;
  int N = 0;
#if defined(HAVE_BFGS)
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  for(int i = 0; i < niter; i++){
    for (unsigned int j=0;j<gf->quadrangles.size();j++){
      if (gf->quadrangles[j]->etaShapeMeasure() < 0.1){
        N += _untangleQuad (gf, gf->quadrangles[j], adj);
      }
    }
  }
#endif
  return N;
}

/*static int orientationOK (GFace *gf, MVertex *v1, MVertex *v2, MVertex *v3)
{
  SPoint2 p1, p2, p3;
  reparamMeshVertexOnFace(v1, gf, p1);
  reparamMeshVertexOnFace(v2, gf, p2);
  reparamMeshVertexOnFace(v3, gf, p3);
  if (robustPredicates::orient2d(p1, p2, p3) < 0) return true;
  return false;
}*/

static int allowSwap (GFace *gf, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
{
  SPoint2 p1,p2,p3,p4;
  reparamMeshVertexOnFace(v1, gf, p1);
  reparamMeshVertexOnFace(v2, gf, p2);
  reparamMeshVertexOnFace(v3, gf, p3);
  reparamMeshVertexOnFace(v4, gf, p4);
  if (robustPredicates::orient2d(p1, p2, p3) *
      robustPredicates::orient2d(p1, p2, p4) < 0 &&
      robustPredicates::orient2d(p3, p4, p1) *
      robustPredicates::orient2d(p3, p4, p2) > 0) return true;
  return false;
}

static double myShapeMeasure(MElement *e)
{
  return e->etaShapeMeasure();
}

int _edgeSwapQuadsForBetterQuality(GFace *gf, double eps, std::set<MEdge,Less_Edge> &prioritory)
{
  e2t_cont adj;
  //buildEdgeToElement(gf->triangles, adj);
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
      double worst_quality_old = std::min(myShapeMeasure(e1),myShapeMeasure(e2));
      bool P = prioritory.find(MEdge(v1,v2)) != prioritory.end();
      if (P)  worst_quality_old = 0.0;

      if ((v1->onWhat()->dim() != 2 || v2->onWhat()->dim() != 2) &&
	   worst_quality_old < eps && (
          deleted.find(e1) == deleted.end() ||
          deleted.find(e2) == deleted.end())){
        MVertex *v12=0,*v11=0,*v22=0,*v21=0;
        double rot1 = +1.0;
        double rot2 = +1.0;
        for (int i=0;i<4;i++){
          MEdge ed = e1->getEdge(i);
          if (ed.getVertex(0) == v1 && ed.getVertex(1) != v2) {rot1 = -1.0; v11 = ed.getVertex(1);}
          if (ed.getVertex(1) == v1 && ed.getVertex(0) != v2) v11 = ed.getVertex(0);
          if (ed.getVertex(0) == v2 && ed.getVertex(1) != v1) v12 = ed.getVertex(1);
          if (ed.getVertex(1) == v2 && ed.getVertex(0) != v1) {rot1 = -1.0; v12 = ed.getVertex(0);}
          ed = e2->getEdge(i);
          if (ed.getVertex(0) == v1 && ed.getVertex(1) != v2) v21 = ed.getVertex(1);
          if (ed.getVertex(1) == v1 && ed.getVertex(0) != v2) {rot2 = -1.0; v21 = ed.getVertex(0);}
          if (ed.getVertex(0) == v2 && ed.getVertex(1) != v1) {rot2 = -1.0; v22 = ed.getVertex(1);}
          if (ed.getVertex(1) == v2 && ed.getVertex(0) != v1) v22 = ed.getVertex(0);
        }
        if (!v11 || !v12 || !v21 || !v22){
          Msg::Error("Quad vertices are wrong (in edgeSwapQuads opti)");
          return 0;
        }
        if (rot1 != rot2){
          Msg::Error("Quads are not oriented the same (in edgeSwapQuads opti)");
          return 0;
        }

	// edges have to intersect
        MQuadrangle *q1A, *q2A, *q1B, *q2B;
        if (rot1 > 0.0 && rot2 > 0.0){
          q1A = new MQuadrangle (v11,v22,v2,v12);
          q2A = new MQuadrangle (v22,v11,v1,v21);
          q1B = new MQuadrangle (v11,v1, v21, v12);
          q2B = new MQuadrangle (v21,v22,v2,v12);
        }
        else if (rot1 < 0.0 && rot2 < 0.0){
          q1A = new MQuadrangle (v11,v12,v2,v22);
          q2A = new MQuadrangle (v22,v21,v1,v11);
          q1B = new MQuadrangle (v11,v12,v21,v1);
          q2B = new MQuadrangle (v21,v12,v2,v22);
        }
        else{
          Msg::Error("Something wrong in edgeSwapQuads opti");
          return 0;
        }
        double worst_quality_A = std::min(myShapeMeasure(q1A),myShapeMeasure(q2A));
        double worst_quality_B = std::min(myShapeMeasure(q1B),myShapeMeasure(q2B));

	bool PA = prioritory.find(MEdge(v11,v22)) == prioritory.end();
	bool PB = prioritory.find(MEdge(v12,v21)) == prioritory.end();

        double old_surface = surfaceFaceUV(e1,gf) + surfaceFaceUV(e2,gf) ;
        double new_surface_A = surfaceFaceUV(q1A,gf) + surfaceFaceUV(q2A,gf) ;
        double new_surface_B = surfaceFaceUV(q1B,gf) + surfaceFaceUV(q2B,gf) ;

	bool doA=false, doB=false;
	if (old_surface > new_surface_A)doA = true;
	if (old_surface > new_surface_B)doB = true;
	if ( worst_quality_A >  worst_quality_B){
	  if ( worst_quality_A > worst_quality_old && !doB) doA = true;
	}
	else{
	  if ( worst_quality_B > worst_quality_old && !doA) doB = true;
	}

	if(!allowSwap(gf,v1,v2,v11,v22)) doA = false;
	if(!allowSwap(gf,v1,v2,v21,v12)) doB = false;

	if (!PA)doA = false;
	if (!PB)doB = false;


        if (doA && SANITY_(gf,q1A,q2A)){
          deleted.insert(e1);
          deleted.insert(e2);
          created.push_back(q1A);
          created.push_back(q2A);
          delete q1B;
          delete q2B;
          COUNT++;
        }
        else if (doB && SANITY_(gf,q1B,q2B)){
          deleted.insert(e1);
          deleted.insert(e2);
          created.push_back(q1B);
          created.push_back(q2B);
          delete q1A;
          delete q2A;
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

static int  edgeSwapQuadsForBetterQuality (GFace *gf, double eps,  std::set<MEdge,Less_Edge> &prioritory)
{
  int COUNT = 0;
  while(1){
    int k = _edgeSwapQuadsForBetterQuality (gf, eps, prioritory);
    COUNT += k;
    if (!k || COUNT > 40)break;
  }
  Msg::Debug("%i swap quads performed",COUNT);
  return COUNT;
}

static std::vector<MVertex*> computeBoundingPoints (const std::vector<MElement*> &lt,
                                                    MVertex *v = 0)
{
  // get boundary edges
  std::set<MEdge,Less_Edge> edges;
  for (unsigned int i = 0; i < lt.size(); i++){
    for (int j = 0; j < lt[i]->getNumEdges(); j++){
      std::set<MEdge,Less_Edge>::iterator it = edges.find(lt[i]->getEdge(j));
      if (it == edges.end())
        edges.insert(lt[i]->getEdge(j));
      else
        edges.erase(it);
    }
  }
  std::set<MEdge,Less_Edge>::iterator it = edges.begin();
  std::list<MEdge> border;
  //bool closed = true;
  for ( ; it != edges.end() ; ++it){
    if (it->getVertex(0) == v || it->getVertex(1) == v){
      //closed = false;
    }
    else {
      border.push_back(*it);
    }
  }
  // we got all boundary edges
  std::list<MVertex *> oriented;
  {
    std::list<MEdge>::iterator itsz = border.begin();
    oriented.push_back(itsz->getVertex(0));
    oriented.push_back(itsz->getVertex(1));
    border.erase (itsz);
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

static MQuadrangle* buildNewQuad(MVertex *first,
				 MVertex *newV,
				 MElement *e,
				 const std::vector<MElement*> & E){
  int found[3] = {0,0,0};
  for (unsigned int i=0;i<E.size();i++){
    if (E[i] != e){
      for (int j=0;j<E[i]->getNumVertices();j++){
	MVertex *v = E[i]->getVertex(j);
	if (v == e->getVertex(0))found[0]=1;
	else if (v == e->getVertex(1))found[1]=1;
	else if (v == e->getVertex(2))found[2]=1;
      }
    }
  }
  int start = -1;
  int nextVertex=-1;
  for (int i=0;i<3;i++){
    if (e->getVertex(i) == first) start = i;
    if (!found[i])nextVertex = i ;
  }
  if (nextVertex == (start+1)%3){
    return new MQuadrangle (e->getVertex(start),
			    e->getVertex((start+1)%3),
			    e->getVertex((start+2)%3),
			    newV);
  }
  else{
    return new MQuadrangle (e->getVertex(start),
			    newV,
			    e->getVertex((start+1)%3),
			    e->getVertex((start+2)%3));
  }
}

int postProcessExtraEdges (GFace *gf, std::vector<std::pair<MElement*,MElement*> > &toProcess)
{
  // some pairs of elements that should be recombined are not neighbor elements (see our paper)
  // so we recombine them in another way (adding a new node)

  Msg::Debug("%d extra edges to be processed",(int)toProcess.size());

  //  return 1;

  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);

  std::set<MElement*>deleted;

  for (unsigned int i = 0; i < toProcess.size(); i++){
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
          reparamMeshVertexOnFace(it->first,gf, p);
          MFaceVertex *newVertex = new MFaceVertex (it->first->x(),
                                                    it->first->y(),
                                                    it->first->z(),
                                                    gf,
                                                    p.x(),
                                                    p.y());
          gf->mesh_vertices.push_back(newVertex);
          int start1 = 0,start2 = 0;
          for (int k=0;k<3;k++){
            if (t1->getVertex(k) == it->first){
              start1 = k;
            }
            if (t2->getVertex(k) == it->first){
	      start2 = k;
	    }
          }

          MQuadrangle *q1 =buildNewQuad(t1->getVertex(start1),newVertex,t1,it->second);
          MQuadrangle *q2 =buildNewQuad(t2->getVertex(start2),newVertex,t2,it->second);

          std::vector<MElement*> newAdj;
          newAdj.push_back(q1);
          newAdj.push_back(q2);
          for (unsigned int k = 0; k < it->second.size(); k++){
            if (it->second[k]->getNumVertices() == 4){
              newAdj.push_back(it->second[k]);
              for (int vv = 0; vv < 4; vv++){
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

bool edgeSwapDelProj (MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4){
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

  //  const double volumeRef = surfaceTriangleUV(v1, v2, v3, data) +
  //    surfaceTriangleUV(v1, v2, v4, data);

  MTriangle *t1b = new MTriangle(v2, v3, v4);
  MTriangle *t2b = new MTriangle(v4, v3, v1);

  //  const double v1b = surfaceTriangleUV(v2, v3, v4, data);
  //  const double v2b = surfaceTriangleUV(v4, v3, v1, data);
  //  const double volume = v1b + v2b;
  //  if(fabs(volume - volumeRef) > 1.e-10 * (volume + volumeRef) ||
  //      v1b < 1.e-8 * (volume + volumeRef) ||
  //      v2b < 1.e-8 * (volume + volumeRef)){
  //    delete t1b;
  //    delete t2b;
  //    return false;
  //  }

  switch(cr){
  case SWCR_QUAL:
    {
      const double triQualityRef = std::min(qmTriangle(t1->tri(), QMTRI_RHO),
                                            qmTriangle(t2->tri(), QMTRI_RHO));
      const double triQuality = std::min(qmTriangle(t1b, QMTRI_RHO),
                                         qmTriangle(t2b, QMTRI_RHO));
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
      double edgeCenter[2] ={(data.Us[index1] + data.Us[index2] + data.Us[index3] + data.Us[index4]) * .25,
                             (data.Vs[index1] + data.Vs[index2] + data.Vs[index3] + data.Vs[index4]) * .25};
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

  double lc1 = 0.3333333333 * (data.vSizes[i10] + data.vSizes[i11] + data.vSizes[i12]);
  double lcBGM1 = 0.3333333333 * (data.vSizesBGM[i10] + data.vSizesBGM[i11] + data.vSizesBGM[i12]);

  double lc2 = 0.3333333333 * (data.vSizes[i20] + data.vSizes[i21] + data.vSizes[i22]);
  double lcBGM2 = 0.3333333333 * (data.vSizesBGM[i20] + data.vSizesBGM[i21] + data.vSizesBGM[i22]);

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

// split one triangle into 3 triangles
void _triangleSplit (GFace *gf, MElement *t)
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

//used for meshGFaceRecombine development
int recombineWithBlossom(GFace *gf, double dx, double dy,
                         int *&elist, std::map<MElement*,int> &t2n)
{
#if defined(HAVE_BLOSSOM)
  int recur_level = 0;
  bool cubicGraph = 1;
#endif
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
  std::vector<std::pair<MElement*,MElement*> > toProcess;

  if(CTX::instance()->mesh.algoRecombine != 0){
#if defined(HAVE_BLOSSOM)
    int ncount = gf->triangles.size();
    if (ncount % 2 == 0) {
      int ecount =  cubicGraph ? pairs.size() + makeGraphPeriodic.size() : pairs.size();
      Msg::Info("Blossom: %d internal %d closed",(int)pairs.size(), (int)makeGraphPeriodic.size());
      //Msg::Info("Cubic Graph should have ne (%d) = 3 x nv (%d) ",ecount,ncount);
      Msg::Debug("Perfect Match Starts %d edges %d nodes",ecount,ncount);
      //std::map<MElement*,int> t2n;
      std::map<int,MElement*> n2t;
      for (unsigned int i=0;i<gf->triangles.size();++i){
        t2n[gf->triangles[i]] = i;
        n2t[i] = gf->triangles[i];
      }

      elist = new int [2*ecount];
      //int *elist = new int [2*ecount];
      int *elen  = new int [ecount];
      for (unsigned int i = 0; i < pairs.size(); ++i){
        elist[2*i]   = t2n[pairs[i].t1];
        elist[2*i+1] = t2n[pairs[i].t2];
        //elen [i] =  (int) pairs[i].angle;
        double angle = atan2(pairs[i].n1->y()-pairs[i].n2->y(),
                             pairs[i].n1->x()-pairs[i].n2->x());

        //double x = .5*(pairs[i].n1->x()+pairs[i].n2->x());
        //double y = .5*(pairs[i].n1->y()+pairs[i].n2->y());
        //double opti = atan2(y,x);
        //angle -= opti;
        while (angle < 0 || angle > M_PI/2){
          if (angle < 0) angle += M_PI/2;
          if (angle > M_PI/2) angle -= M_PI/2;
        }
        elen [i] =  (int) 180. * fabs(angle-M_PI/4)/M_PI;

        int NB = 0;
        if (pairs[i].n1->onWhat()->dim() < 2)NB++;
        if (pairs[i].n2->onWhat()->dim() < 2)NB++;
        if (pairs[i].n3->onWhat()->dim() < 2)NB++;
        if (pairs[i].n4->onWhat()->dim() < 2)NB++;
        if (elen[i] >  180 && NB > 2) {printf("angle %dE\n",elen[i]);elen[i] = 1000;}
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
      if (perfect_match (ncount, NULL, ecount, &elist, &elen, NULL, MATCHFILE,
                         0, 0, 0, 0, &matzeit)){
        Msg::Error("Didn't worked");
      }
      else {
        Msg::Info("imhere: with %d", elist[0]);
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

            MVertex *mv[4], *v[4];
            v[0] = t1->getVertex(start);
            v[1] = t1->getVertex((start+1)%3);
            v[2] = other;
            v[3] = t1->getVertex((start+2)%3);

            for (unsigned int i = 0; i < 4; ++i) {
              mv[i] = new MVertex(v[i]->x() + dx,
                                  v[i]->y() + dy,
                                  v[i]->z()      );
            }
            MQuadrangle *q = new MQuadrangle(mv[0], mv[1], mv[2], mv[3]);
            gf->quadrangles.push_back(q);
          }
        }
        //fclose(f);
        //free(elist);
        pairs.clear();
        if (recur_level == 0)
          Msg::Debug("Perfect Match Succeeded in Quadrangulation (%g sec)", matzeit);
        else
          Msg::Info(" :-) Perfect Match Succeeded in Quadrangulation after Splits (%g sec)",
                    matzeit);
      }
    }
#else
    Msg::Warning("Gmsh should be compiled with the Blossom IV code and CONCORDE "
                 "in order to allow the Blossom optimization");
#endif
  }

  if (toProcess.size()) postProcessExtraEdges (gf,toProcess);
  return success;
}

static int _recombineIntoQuads(GFace *gf, int recur_level, bool cubicGraph = 1)
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
  std::vector<std::pair<MElement*,MElement*> > toProcess;

  if(CTX::instance()->mesh.algoRecombine != 0){
#if defined(HAVE_BLOSSOM)
    int ncount = gf->triangles.size();
    if (ncount % 2 != 0) {
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

      int *elist = new int [2*ecount];
      int *elen  = new int [ecount];
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
        if (recur_level < 20){
          Msg::Warning("Perfect Match Failed in Quadrangulation, Applying Graph Splits");
          std::set<MElement*> removed;
          std::vector<MTriangle*> triangles2;
          for (unsigned int i=0;i<pairs.size();++i){
            RecombineTriangle &rt = pairs[i];
            if ((rt.n1->onWhat()->dim() < 2 && rt.n2->onWhat()->dim() < 2) ||
                (recur_level > 10 && i < 10)){
              if (removed.find(rt.t1) == removed.end() &&
                  removed.find(rt.t2) == removed.end() ){
                removed.insert(rt.t1);
                removed.insert(rt.t2);
                SPoint2 p1,p2;
                reparamMeshEdgeOnFace(rt.n1, rt.n2, gf, p1,p2);
                SPoint2 np = (p1+p2)*(1./2.0);
                GPoint gp = gf->point(np);
                MFaceVertex *newv = new MFaceVertex(gp.x(), gp.y(), gp.z(),
                                                    gf, np.x(), np.y());
                MTriangle *t1 = new MTriangle(rt.n1, rt.n4, newv);
                MTriangle *t2 = new MTriangle(rt.n4, rt.n2, newv);
                MTriangle *t3 = new MTriangle(rt.n2, rt.n3, newv);
                MTriangle *t4 = new MTriangle(rt.n3, rt.n1, newv);
                gf->mesh_vertices.push_back(newv);
                triangles2.push_back(t1);
                triangles2.push_back(t2);
                triangles2.push_back(t3);
                triangles2.push_back(t4);
              }
            }
          }
          if (removed.size() == 0) return _recombineIntoQuads(gf, 11);
          for (unsigned int i = 0; i < gf->triangles.size(); ++i){
            if (removed.find(gf->triangles[i]) ==
                removed.end())triangles2.push_back(gf->triangles[i]);
            else delete gf->triangles[i];
          }
          gf->triangles=triangles2;
          free(elist);
          return _recombineIntoQuads(gf, recur_level+1);
        }
        else {
          Msg::Error("Perfect Match failed in Quadrangulation, try something else");
          free(elist);
          pairs.clear();
        }
      }
      else{
        // TEST
        for (int k = 0; k < elist[0]; k++){
          int i1 = elist[1+3*k], i2 = elist[1+3*k+1], an=elist[1+3*k+2];
          // FIXME !
          if (an == 100000 /*|| an == 1000*/){
            toProcess.push_back(std::make_pair(n2t[i1],n2t[i2]));
            Msg::Warning("Extra edge found in blossom algorithm, optimization will be required");
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
        if (recur_level == 0)
          Msg::Debug("Perfect Match Succeeded in Quadrangulation (%g sec)", matzeit);
        else
          Msg::Info(" :-) Perfect Match Succeeded in Quadrangulation after Splits (%g sec)",
                    matzeit);

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

  if (toProcess.size()) postProcessExtraEdges (gf,toProcess);
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
  Msg::Info("%s : %5d quads %5d triangles %4d invalid quads %4d quads with Q < 0.1 "
            "Avg Q = %12.5E Min %12.5E", message, gf->quadrangles.size(), gf->triangles.size(),
            nbInv, nbBad, Qav/gf->quadrangles.size(), Qmin);
  return Qmin;
}

void recombineIntoQuads(GFace *gf,
                        bool topologicalOpti,
                        bool nodeRepositioning, 
			double minqual)
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
  int success = _recombineIntoQuads(gf, minqual);

  if (saveAll) gf->model()->writeMSH("raw.msh");
  printStats (gf, "BEFORE OPTIMIZATION");
  if(haveParam && nodeRepositioning){
    laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing);
  }
  // blossom-quad algo
  if(success && CTX::instance()->mesh.algoRecombine != 0){
    if(topologicalOpti){
      if(haveParam){
        if (saveAll) gf->model()->writeMSH("smoothed.msh");
        int ITER=0;
	//        int optistatus[6] = {0,0,0,0,0,0};
	std::set<MEdge,Less_Edge> prioritory;
	double exbad = -100;
        while(1){
	  //          int maxCavitySize = CTX::instance()->mesh.bunin;
	  //	  optistatus[0] = (ITERB == 1) ?splitFlatQuads(gf, .01, prioritory) : 0;
          //optistatus[1] = 
	  removeTwoQuadsNodes(gf);
	  //optistatus[4] = _defectsRemovalBunin(gf,36);
	  //optistatus[2] = 
	  removeDiamonds(gf) ;
	  if(haveParam)laplaceSmoothing(gf,CTX::instance()->mesh.nbSmoothing,true);
	  //optistatus[3] = 
	  edgeSwapQuadsForBetterQuality(gf,minqual, prioritory);
	  //optistatus[5] = 
	  optiSmoothing(gf,CTX::instance()->mesh.nbSmoothing,true);
	  //	  optistatus[5] = untangleInvalidQuads(gf, CTX::instance()->mesh.nbSmoothing);
	  double bad = printStats(gf, "IN OPTIMIZATION");
	  if (bad > minqual || exbad == bad) break;
	  exbad = bad;
	  if (ITER > 20) break;
	  ITER ++;
        }
      }
      if(haveParam) {
	laplaceSmoothing(gf,CTX::instance()->mesh.nbSmoothing, true);
	optiSmoothing(gf,CTX::instance()->mesh.nbSmoothing,true);
      }
      // untangleInvalidQuads(gf,CTX::instance()->mesh.nbSmoothing);
    }
    double t2 = Cpu();
    Msg::Info("Blossom recombination algorithm completed (%g s)", t2 - t1);
    quadsToTriangles(gf, minqual);
    if(haveParam) {
      laplaceSmoothing(gf,CTX::instance()->mesh.nbSmoothing);
    }
    // removeDiamonds(gf);
    // removeTwoQuadsNodes(gf);
    printStats (gf, "AFTER OPTIMIZATION");
    return;
  }

  // simple recombination algo
  _recombineIntoQuads(gf, 0);
  if(haveParam) laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing, true);
  _recombineIntoQuads(gf, 0);
  if(haveParam) laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing, true);

  if (saveAll) gf->model()->writeMSH("after.msh");

  double t2 = Cpu();
  Msg::Info("Simple recombination algorithm completed (%g s)", t2 - t1);
}

void quadsToTriangles(GFace *gf, double minqual)
{

  std::vector<MQuadrangle*> qds;
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

// class Temporary

double Temporary::w1,Temporary::w2,Temporary::w3;

std::vector<SVector3> Temporary::gradients;

Temporary::Temporary(){}

Temporary::~Temporary(){}

SVector3 Temporary::compute_gradient(MElement*element)
{
  /*double x1,y1,z1;
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
  z = (z1+z2+z3)/3.0;*/
  return SVector3(0.0,1.0,0.0);
}

void Temporary::select_weights(double new_w1, double new_w2, double new_w3)
{
  w1 = new_w1;
  w2 = new_w2;
  w3 = new_w3;
}

double Temporary::compute_total_cost(double f1, double f2)
{
  double cost;
  cost = w1*f1 + w2*f2 + w3*f1*f2;
  return cost;
}

SVector3 Temporary::compute_normal(MElement *element)
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

SVector3 Temporary::compute_other_vector(MElement *element)
{
  //int number;
  double length;
  SVector3 normal;
  SVector3 gradient;
  SVector3 other_vector;
  //number = element->getNum();
  normal = Temporary::compute_normal(element);
  gradient = Temporary::compute_gradient(element);//gradients[number];
  other_vector = crossprod(gradient,normal);
  length = norm(other_vector);
  return SVector3(other_vector.x()/length,other_vector.y()/length,other_vector.z()/length);
}

double Temporary::compute_alignment(const MEdge &_edge, MElement *element1,
                                    MElement *element2)
{
  //int number;
  double scalar_productA,scalar_productB;
  double alignment;
  SVector3 gradient;
  SVector3 other_vector;
  SVector3 edge;
  MVertex*vertexA;
  MVertex*vertexB;
  //number = element1->getNum();
  gradient = Temporary::compute_gradient(element1);//gradients[number];
  other_vector = Temporary::compute_other_vector(element1);
  vertexA = _edge.getVertex(0);
  vertexB = _edge.getVertex(1);
  edge = SVector3(vertexB->x()-vertexA->x(), vertexB->y()-vertexA->y(),
                  vertexB->z()-vertexA->z());
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
  PViewData*data;
  PView::readMSH(file_name,-1);
  data = PView::list[0]->getData();
  for(i = 0;i < data->getNumEntities(0);i++)
  {
    if(data->skipEntity(0,i)) continue;
	for(j = 0;j < data->getNumElements(0,i);j++){
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

void Temporary::quadrilaterize(std::string file_name, double _w1, double _w2, double _w3)
{
  GFace*face;
  GModel*model = GModel::current();
  GModel::fiter iterator;
  gradients.resize(model->getNumMeshElements() + 1);
  w1 = _w1;
  w2 = _w2;
  w3 = _w3;
  Temporary::read_data(file_name);
  for(iterator = model->firstFace();iterator != model->lastFace(); iterator++){
    face = *iterator;
    _recombineIntoQuads(face,1,1);
  }
}
