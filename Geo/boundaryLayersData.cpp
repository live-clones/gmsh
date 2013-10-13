// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GModel.h"
#include "GFace.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MEdge.h"
#include "boundaryLayersData.h"
#include "OS.h"

#if !defined(HAVE_MESH) || !defined(HAVE_ANN)

BoundaryLayerField* getBLField(GModel *gm){ return 0; }
bool buildAdditionalPoints2D (GFace *gf ) { return false; }
BoundaryLayerColumns * buildAdditionalPoints3D (GRegion *gr) { return 0; }
void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]) {}
faceColumn BoundaryLayerColumns::getColumns(GFace *gf, MVertex *v1, MVertex *v2,
                                            MVertex *v3, int side)
{
  return faceColumn(BoundaryLayerData(),BoundaryLayerData(),BoundaryLayerData());
}
edgeColumn BoundaryLayerColumns::getColumns(MVertex *v1, MVertex *v2 , int side)
{
  return edgeColumn(BoundaryLayerData(),BoundaryLayerData());
}
#else

#include "Field.h"

const int FANSIZE__ = 4;


/*
               ^  ni
               |
               |
      +-----------------+
               bi      /
                 bj  /
                   /\
                 /    \   nj
               /        Z
             +
*/

/*
static double solidAngle (SVector3 &ni, SVector3 &nj,
			  SPoint3  &bi, SPoint3  &bj)
{
  double cosa = dot (ni, nj);
  SVector3 bibj = bj - bi;
  SVector3 sina = crossprod ( ni , nj );
  double a = atan2(sina.norm(),cosa);
  double sign = dot (nj, bibj);
  return sign > 0 ? fabs (a) : -fabs(a);
}
*/

SVector3 interiorNormal(SPoint2 p1, SPoint2 p2, SPoint2 p3)
{
  SVector3 ez (0,0,1);
  SVector3 d (p1.x()-p2.x(),p1.y()-p2.y(),0);
  SVector3 h (p3.x()-0.5*(p2.x()+p1.x()),p3.y()-0.5*(p2.y()+p1.y()),0);
  SVector3 n = crossprod(d,ez);
  n.normalize();
  if (dot(n,h) > 0)return n;
  return n*(-1.);
}

double computeAngle(GFace *gf, const MEdge &e1, const MEdge &e2,
                    SVector3 &n1, SVector3 &n2)
{
  double cosa = dot(n1,n2);
  SPoint2 p0,p1,p2;
  MVertex *v11 = e1.getVertex(0);
  MVertex *v12 = e1.getVertex(1);
  MVertex *v21 = e2.getVertex(0);
  MVertex *v22 = e2.getVertex(1);
  MVertex *v0,*v1,*v2;
  if (v11 == v21){
    v0 = v12 ; v1 = v11 ; v2 = v22;
  }
  else if (v11 == v22){
    v0 = v12 ; v1 = v11 ; v2 = v21;
  }
  else if (v12 == v21){
    v0 = v11 ; v1 = v12 ; v2 = v22;
  }
  else if (v12 == v22){
    v0 = v11 ; v1 = v12 ; v2 = v21;
  }
  else throw;

  reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
  reparamMeshEdgeOnFace(v0, v2, gf, p0, p2);

  SVector3 t1 (p1.x()-p0.x(),p1.y()-p0.y(),0);
  SVector3 t2 (p2.x()-p1.x(),p2.y()-p1.y(),0);
  t1.normalize();
  t2.normalize();
  SVector3 n = crossprod(t1,t2);

  double sign = dot(t1,n2);

  double a = atan2 (n.z(),cosa);
  a = sign > 0 ? fabs(a) : -fabs(a);

  //  printf("a = %12.5e cos %12.5E sin %12.5E %g %g vs %g %g\n",
  //         a,cosa,n.z(),n1.x(),n1.y(),n2.x(),n2.y());
  return a;
}

void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3])
{
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));

  double res[2][2];

  double M[2][3] = {{der.first().x(),der.first().y(),der.first().z()},
		    {der.second().x(),der.second().y(),der.second().z()}};


  for (int i=0;i<2;i++){
    for (int l=0;l<2;l++){
      res[i][l] = 0;
      for (int j=0;j<3;j++){
	for (int k=0;k<3;k++){
	  res[i][l] += M[i][j]*m(j,k)*M[l][k];
	}
      }
    }
  }
  metric[0] = res[0][0];
  metric[1] = res[1][0];
  metric[2] = res[1][1];
}

const BoundaryLayerData & BoundaryLayerColumns::getColumn(MVertex *v, MFace f)
{
  int N = getNbColumns(v) ;
  if (N == 1) return getColumn(v, 0);
  if (isOnWedge (v)){
    GFace *gf = _inverse_classification[f];
    BoundaryLayerFanWedge3d w = getWedge(v);
    if (w.isLeft(gf))return getColumn(v, 0);
    if (w.isRight(gf))return getColumn(v, N-1);
    Msg::Error("Strange behavior for a wedge");
  }
  if (isCorner (v)){
    GFace *gf = _inverse_classification[f];
    BoundaryLayerFanCorner3d c = getCorner(v);
    int k = 0;
    for (unsigned int i=0;i<c._gf.size();i++){
      if (c._gf[i] == gf){
	return  getColumn(v, k);
      }
      k += (c._fanSize  - 1);
    }
  }
  static BoundaryLayerData error;
  return error;
}


faceColumn BoundaryLayerColumns::getColumns(GFace *gf, MVertex *v1, MVertex *v2,
                                            MVertex *v3, int side)
{
  //  printf("%d %d %d for vertex face %d\n",getNbColumns(v1),getNbColumns(v3),getNbColumns(v3),
  //	 gf->tag());
  int i1=-1,i2=-1,i3=-1;
  for (int i=0;i<getNbColumns(v1);i++){
    const BoundaryLayerData &d1 = getColumn(v1,i);
    if (std::find(d1._joint.begin(),d1._joint.end(),gf) != d1._joint.end()){
      i1 = i;
      //      printf("1 Yeah column %d among %d\n",i,d1._joint.size());
      break;
    }
  }
  for (int i=0;i<getNbColumns(v2);i++){
    const BoundaryLayerData &d2 = getColumn(v2,i);
    if (std::find(d2._joint.begin(),d2._joint.end(),gf) != d2._joint.end()){
      i2 = i;
      //      printf("2 Yeah column %d among %d\n",i,d2._joint.size());
      break;
    }
  }
  for (int i=0;i<getNbColumns(v3);i++){
    const BoundaryLayerData &d3 = getColumn(v3,i);
    if (std::find(d3._joint.begin(),d3._joint.end(),gf) != d3._joint.end()){
      i3 = i;
      //      printf("3 Yeah column %d among %d\n",i,d3._joint.size());
      break;
    }
  }

  return faceColumn(getColumn(v1,i1), getColumn(v2,i2), getColumn(v3,i3));
}

edgeColumn BoundaryLayerColumns::getColumns(MVertex *v1, MVertex *v2 , int side)
{
  Equal_Edge aaa;
  MEdge e(v1, v2);
  std::map<MVertex*,BoundaryLayerFan>::const_iterator it1 = _fans.find(v1);
  std::map<MVertex*,BoundaryLayerFan>::const_iterator it2 = _fans.find(v2);
  int N1 = getNbColumns(v1) ;
  int N2 = getNbColumns(v2) ;


  int nbSides = _normals.count(e);

  // if (nbSides != 1)printf("I'm here %d sides\n",nbSides);
  // Standard case, only two extruded columns from the two vertices
  if (N1 == 1 && N2 == 1) return edgeColumn(getColumn(v1,0),getColumn(v2,0));
  // one fan on
  if (nbSides == 1){
    if (it1 != _fans.end() && it2 == _fans.end() ){
      if (aaa(it1->second._e1,e))
	return edgeColumn(getColumn (v1,0),getColumn(v2,0));
      else
	return edgeColumn(getColumn (v1,N1-1),getColumn(v2,0));
    }
    if (it2 != _fans.end() && it1 == _fans.end() ){
      if (aaa(it2->second._e1,e))
	return edgeColumn(getColumn (v1,0),getColumn(v2,0));
      else
	return edgeColumn(getColumn (v1,0),getColumn(v2,N2-1));
    }
    if (it2 != _fans.end() && it1 != _fans.end() ){
      int c1, c2;
      if (aaa(it1->second._e1,e))
	c1 =  0;
      else
	c1 = N1-1;
      if (aaa(it2->second._e1,e))
	c2 =  0;
      else
	c2 = N2-1;
      return edgeColumn(getColumn (v1,c1),getColumn(v2,c2));
    }
    // fan on the right
    if (N1 == 1 || N2 == 2){
      const BoundaryLayerData & c10 = getColumn(v1,0);
      const BoundaryLayerData & c20 = getColumn(v2,0);
      const BoundaryLayerData & c21 = getColumn(v2,1);
      if (dot(c10._n,c20._n) > dot(c10._n,c21._n) ) return edgeColumn(c10,c20);
      else return edgeColumn(c10,c21);
    }
    // fan on the left
    if (N1 == 2 || N2 == 1){
      const BoundaryLayerData & c10 = getColumn(v1,0);
      const BoundaryLayerData & c11 = getColumn(v1,1);
      const BoundaryLayerData & c20 = getColumn(v2,0);
      if (dot(c10._n,c20._n) > dot(c11._n,c20._n) ) return edgeColumn(c10,c20);
      else return edgeColumn(c11,c20);
    }

    // Msg::Error ("Impossible Boundary Layer Configuration : "
    //             "one side and no fans %d %d", N1, N2);
    // FIXME WRONG
    return N1 ? edgeColumn (getColumn (v1,0),getColumn(v1,0)) :
      edgeColumn (getColumn (v2,0),getColumn(v2,0));
  }
  else if (nbSides == 2){
    int i1=0,i2=1,j1=0,j2=1;
    if (it1 != _fans.end()){
      i1 =  aaa(it1->second._e1,e) ? 0 : N1-1;
      i2 = !aaa(it1->second._e1,e) ? 0 : N1-1;
    }
    if (it2 != _fans.end()){
      j1 =  aaa(it2->second._e1,e) ? 0 : N2-1;
      j2 = !aaa(it2->second._e1,e) ? 0 : N2-1;
    }
    const BoundaryLayerData & c10 = getColumn(v1,i1);
    const BoundaryLayerData & c11 = getColumn(v1,i2);
    const BoundaryLayerData & c20 = getColumn(v2,j1);
    const BoundaryLayerData & c21 = getColumn(v2,j2);

    if (side == 0){
      if (dot(c10._n,c20._n) > dot(c10._n,c21._n) ) return edgeColumn(c10,c20);
      else return edgeColumn(c10,c21);
    }
    if (side == 1){
      if (dot(c11._n,c20._n) > dot(c11._n,c21._n) ) return edgeColumn(c11,c20);
      else return edgeColumn(c11,c21);
    }
  }

  Msg::Error("Not yet Done in BoundaryLayerData nbSides = %d, ",nbSides );
  static BoundaryLayerData error;
  static edgeColumn error2(error, error);
  return error2;
}

/*
static bool pointInFace (GFace *gf, double u, double v)
{
  return true;
}
*/

static void treat2Connections(GFace *gf, MVertex *_myVert, MEdge &e1, MEdge &e2,
                              double _treshold, BoundaryLayerColumns *_columns,
                              std::vector<SVector3> &_dirs, bool test = false)
{
  std::vector<SVector3> N1,N2;
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e1);
       itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e2);
       itm != _columns->_normals.upper_bound(e2); ++itm) N2.push_back(itm->second);
  if (test) printf("%d %d\n", (int)N1.size(), (int)N2.size());
  if (N1.size() == N2.size()){
    for (unsigned int SIDE = 0; SIDE < N1.size() ; SIDE++){
      // IF THE ANGLE IS GREATER THAN THRESHOLD, ADD DIRECTIONS !!
      double angle = computeAngle (gf,e1,e2,N1[SIDE],N2[SIDE]);
      //      if (test)
      //      printf("angle %12.5E\n", 180*angle/M_PI);
      if (angle < _treshold /*&& angle > - _treshold*/){
	SVector3 x = N1[SIDE]*1.01+N2[SIDE];
	x.normalize();
	_dirs.push_back(x);
      }
      else if (angle >= _treshold){

	if (USEFANS__){
	  int fanSize = FANSIZE__; //angle /  _treshold;
	  // if the angle is greater than PI, than reverse the sense
	  double alpha1 = atan2(N1[SIDE].y(),N1[SIDE].x());
	  double alpha2 = atan2(N2[SIDE].y(),N2[SIDE].x());
	  double AMAX = std::max(alpha1,alpha2);
	  double AMIN = std::min(alpha1,alpha2);
	  MEdge ee[2];
	  if (alpha1 > alpha2){
	    ee[0] = e2;ee[1] = e1;
	  }
	  else {
	    ee[0] = e1;ee[1] = e2;
	  }
	  if ( AMAX - AMIN >= M_PI){
	    double temp = AMAX;
	    AMAX = AMIN + 2*M_PI;
	    AMIN = temp;
	    MEdge eee0 = ee[0];
	    ee[0] = ee[1];ee[1] = eee0;
	  }
	  _columns->addFan (_myVert,ee[0],ee[1],true);
	  for (int i=-1; i<=fanSize; i++){
	    double t = (double)(i+1)/ (fanSize+1);
	    double alpha = t * AMAX + (1.-t)* AMIN;
	    SVector3 x (cos(alpha),sin(alpha),0);
	    x.normalize();
	    _dirs.push_back(x);
	  }
	}
	else {
	  _dirs.push_back(N1[SIDE]);
	  _dirs.push_back(N2[SIDE]);
	}
      }
    }
  }
}
// static void treat2Connections (GFace *gf, MVertex *_myVert, MEdge &e1, MEdge &e2,
//                                double _treshold, BoundaryLayerColumns *_columns,
//                                std::vector<SVector3> &_dirs, bool test = false)
// {
//   std::vector<SVector3> N1,N2;
//   for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
// 	 _columns->_normals.lower_bound(e1);
//        itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
//   for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
// 	 _columns->_normals.lower_bound(e2);
//        itm != _columns->_normals.upper_bound(e2); ++itm) N2.push_back(itm->second);
//   if (test) printf("%d %d\n", (int)N1.size(), (int)N2.size());
//   if (N1.size() == N2.size()){
//     for (unsigned int SIDE = 0; SIDE < N1.size() ; SIDE++){
//       // IF THE ANGLE IS GREATER THAN THRESHOLD, ADD DIRECTIONS !!
//       double angle = computeAngle (gf,e1,e2,N1[SIDE],N2[SIDE]);
//       //      if (test)
//       //      printf("angle %12.5E\n", 180*angle/M_PI);
//       if (angle < _treshold /*&& angle > - _treshold*/){
// 	SVector3 x = N1[SIDE]*1.01+N2[SIDE];
// 	x.normalize();
// 	_dirs.push_back(x);
//       }
//       else if (angle >= _treshold){
// 	_dirs.push_back(N1[SIDE]);
// 	_dirs.push_back(N2[SIDE]);
//       }
//     }
//   }
// }

static void treat3Connections(GFace *gf, MVertex *_myVert, MEdge &e1,
                              MEdge &e2, MEdge &e3, double _treshold,
                              BoundaryLayerColumns *_columns,
                              std::vector<SVector3> &_dirs)
{
  std::vector<SVector3> N1,N2,N3;
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e1);
       itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e2);
       itm != _columns->_normals.upper_bound(e2); ++itm) N2.push_back(itm->second);
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e3);
       itm != _columns->_normals.upper_bound(e3); ++itm) N3.push_back(itm->second);

  SVector3 x1,x2;
  if (N1.size() == 2){
  }
  else if (N2.size() == 2){
    std::vector<SVector3> temp = N1;
    N1.clear();
    N1 = N2;
    N2.clear();
    N2 = temp;
  }
  else if (N3.size() == 2){
    std::vector<SVector3> temp = N1;
    N1.clear();
    N1 = N3;
    N3.clear();
    N3 = temp;
  }
  else {
    Msg::Fatal("IMPOSSIBLE BL CONFIGURATION");
  }
  if (dot(N1[0],N2[0]) > dot(N1[0],N3[0])){
    x1 = N1[0]*1.01+N2[0];
    x2 = N1[1]*1.01+N3[0];
  }
  else {
    x1 = N1[1]*1.01+N2[0];
    x2 = N1[0]*1.01+N3[0];
  }
  x1.normalize();
  _dirs.push_back(x1);
  x2.normalize();
  _dirs.push_back(x2);
}

BoundaryLayerField *getBLField(GModel *gm)
{
  FieldManager *fields = gm->getFields();
  if(fields->getBoundaryLayerField() <= 0){
    return 0;
  }
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  return dynamic_cast<BoundaryLayerField*> (bl_field);
}

static bool isEdgeOfFaceBL(GFace *gf, GEdge *ge, BoundaryLayerField *blf)
{
  if (blf->isEdgeBL (ge->tag()))return true;
  /*
  std::list<GFace*> faces = ge->faces();
  for (std::list<GFace*>::iterator it = faces.begin();
       it != faces.end() ; ++it){
    if ((*it) == gf)return false;
  }
  for (std::list<GFace*>::iterator it = faces.begin();
       it != faces.end() ; ++it){
    if (blf->isFaceBL ((*it)->tag()))return true;
  }
  */
  return false;
}

static void getEdgesData(GFace *gf,
                         BoundaryLayerField *blf,
                         BoundaryLayerColumns *_columns,
                         std::set<MVertex*> &_vertices,
                         std::set<MEdge,Less_Edge> &allEdges,
                         std::multimap<MVertex*,MVertex*> &tangents)
{
  // get all model edges
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> embedded_edges = gf->embeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(),embedded_edges.end());

  // iterate on model edges
  std::list<GEdge*>::iterator ite = edges.begin();
  while(ite != edges.end()){
    // check if this edge generates a boundary layer
    if (isEdgeOfFaceBL (gf,*ite,blf)){
      for(unsigned int i = 0; i< (*ite)->lines.size(); i++){
	MVertex *v1 = (*ite)->lines[i]->getVertex(0);
	MVertex *v2 = (*ite)->lines[i]->getVertex(1);
	allEdges.insert(MEdge(v1,v2));
	_columns->_non_manifold_edges.insert(std::make_pair(v1,v2));
	_columns->_non_manifold_edges.insert(std::make_pair(v2,v1));
	_vertices.insert(v1);
	_vertices.insert(v2);
      }
    }
    else {
      MVertex *v1 = (*ite)->lines[0]->getVertex(0);
      MVertex *v2 = (*ite)->lines[0]->getVertex(1);
      MVertex *v3 = (*ite)->lines[(*ite)->lines.size() - 1]->getVertex(1);
      MVertex *v4 = (*ite)->lines[(*ite)->lines.size() - 1]->getVertex(0);
      tangents.insert (std::make_pair (v1,v2));
      tangents.insert (std::make_pair (v3,v4));
    }
    ++ite;
  }
}

static void getNormals(GFace *gf,
                       BoundaryLayerField *blf,
                       BoundaryLayerColumns *_columns,
                       std::set<MEdge,Less_Edge> &allEdges)
{
  // assume that the initial mesh has been created i.e. that there exist
  // triangles inside the domain. Triangles are used to define
  // exterior normals
  for (unsigned int i = 0; i < gf->triangles.size(); i++){
    SPoint2 p0,p1,p2;
    MVertex *v0 = gf->triangles[i]->getVertex(0);
    MVertex *v1 = gf->triangles[i]->getVertex(1);
    MVertex *v2 = gf->triangles[i]->getVertex(2);
    reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
    reparamMeshEdgeOnFace(v0, v2, gf, p0, p2);

    MEdge me01(v0,v1);
    if (allEdges.find(me01) != allEdges.end()){
      SVector3 v01 = interiorNormal (p0,p1,p2);
      _columns->_normals.insert(std::make_pair(me01,v01));
    }

    MEdge me02(v0,v2);
    if (allEdges.find(me02) != allEdges.end()){
      SVector3 v02 = interiorNormal (p0,p2,p1);
      _columns->_normals.insert(std::make_pair(me02,v02));
    }

    MEdge me21(v2,v1);
    if (allEdges.find(me21) != allEdges.end()){
      SVector3 v21 = interiorNormal (p2,p1,p0);
      _columns->_normals.insert(std::make_pair(me21,v21));
    }
  }
}

static void addColumnAtTheEndOfTheBL(GEdge *ge,
                                     GVertex *gv,
                                     BoundaryLayerColumns* _columns,
                                     BoundaryLayerField *blf)
{
  //  printf("coucou %d\n",ge->tag());
  if (!blf->isEdgeBL(ge->tag())){
    GVertex *g0 = ge->getBeginVertex();
    GVertex *g1 = ge->getEndVertex();
    //      printf("coucou 2 %d %d vs %d\n",g0->tag(),g1->tag(),gv->tag());
    MVertex * v0 = g0->mesh_vertices[0];
    MVertex * v1 = g1->mesh_vertices[0];
    std::vector<MVertex*> invert;
    std::vector<SMetric3> _metrics;
    for(unsigned int i = 0; i < ge->mesh_vertices.size() ; i++){
      invert.push_back(ge->mesh_vertices[ge->mesh_vertices.size() - i - 1]);
      _metrics.push_back(SMetric3(1.0));
    }
    SVector3 t (v1->x()-v0->x(), v1->y()-v0->y(),v1->z()-v0->z());
    t.normalize();
    if (g0 == gv){
      _columns->addColumn(t, v0, ge->mesh_vertices,_metrics);
    }
    else if (g1 == gv){
      _columns->addColumn(t*-1.0, v1,invert,_metrics);
    }
  }
}

bool buildAdditionalPoints2D(GFace *gf)
{
  BoundaryLayerColumns *_columns = gf->getColumns();

  _columns->_normals.clear();
  _columns->_non_manifold_edges.clear();
  _columns->_data.clear();

  // GET THE FIELD THAT DEFINES THE DISTANCE FUNCTION
  BoundaryLayerField *blf = getBLField (gf->model());

  if (!blf)return false;

  blf->setupFor2d(gf->tag());

  double _treshold = blf->fan_angle * M_PI / 180 ;

  std::set<MVertex*> _vertices;
  std::set<MEdge,Less_Edge> allEdges;
  std::multimap<MVertex*,MVertex*> tangents;

  getEdgesData ( gf, blf, _columns, _vertices , allEdges , tangents );

  if (!_vertices.size())return false;

  getNormals ( gf, blf, _columns, allEdges);

  // for all boundry points
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){

    bool endOfTheBL = false;
    SVector3 dirEndOfBL;
    std::vector<MVertex*> columnEndOfBL;

    std::vector<MVertex*> _connections;
    std::vector<SVector3> _dirs;
    // get all vertices that are connected  to that
    // vertex among all boundary layer vertices !

    for (std::multimap<MVertex*,MVertex*>::iterator itm =
           _columns->_non_manifold_edges.lower_bound(*it);
         itm != _columns->_non_manifold_edges.upper_bound(*it); ++itm)
      _connections.push_back (itm->second);

    // A trailing edge topology : 3 edges incident to a vertex
    if (_connections.size() == 3){
      MEdge e1 (*it,_connections[0]);
      MEdge e2 (*it,_connections[1]);
      MEdge e3 (*it,_connections[2]);
      treat3Connections (gf, *it,e1,e2,e3, _treshold, _columns, _dirs);
    }
    // STANDARD CASE, one vertex connected to two neighboring vertices
    else if (_connections.size() == 2){
      MEdge e1 (*it,_connections[0]);
      MEdge e2 (*it,_connections[1]);
      treat2Connections (gf, *it,e1,e2, _treshold, _columns, _dirs);
    }
    else if (_connections.size() == 1){
      MEdge e1 (*it,_connections[0]);
      std::vector<SVector3> N1;
      for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
             _columns->_normals.lower_bound(e1);
	    itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
      // one point has only one side and one normal : it has to be at the end of the BL
      // then, we have the tangent to the connecting edge

      //          *it          _connections[0]
      // --------- + -----------
      //   NO BL          BL

      if (N1.size() == 1){
	std::vector<MVertex*> Ts;
	for (std::multimap<MVertex*,MVertex*>::iterator itm =
	       tangents.lower_bound(*it);
	     itm != tangents.upper_bound(*it); ++itm) Ts.push_back(itm->second);
	// end of the BL --> let's add a column that correspond to the
	// model edge that lies after the end of teh BL
	if (Ts.size() == 1){
	  //	  printf("HERE WE ARE IN FACE %d %d\n",gf->tag(),Ts.size());
	  //	  printf("Classif dim %d %d\n",(*it)->onWhat()->dim(),Ts[0]->onWhat()->dim());
	  GEdge *ge = dynamic_cast<GEdge*>(Ts[0]->onWhat());
	  GVertex *gv = dynamic_cast<GVertex*>((*it)->onWhat());
	  if (ge && gv){
	    addColumnAtTheEndOfTheBL (ge,gv,_columns,blf);
	  }
	}
	else {
	  Msg::Error("Impossible BL Configuration -- One Edge -- Tscp.size() = %d",Ts.size());
	}
      }
      else if (N1.size() == 2){
	//	printf("%g %g --> %g %g \n",e1.getVertex(0)->x(),e1.getVertex(0)->y(),
	//	       e1.getVertex(1)->x(),e1.getVertex(1)->y());
      //	printf("N1.size = %d %g %g %g %g\n",N1.size(),N1[0].x(),N1[0].y(),N1[1].x(),N1[1].y());
	SPoint2 p0,p1;
	reparamMeshEdgeOnFace(*it,_connections[0], gf, p0, p1);

	int fanSize = FANSIZE__;//M_PI /  _treshold;
	double alpha1 = atan2(N1[0].y(),N1[0].x());
	double alpha2 = atan2(N1[1].y(),N1[1].x());
	double alpha3 = atan2(p1.y()-p0.y(),p1.x()-p0.x());
	double AMAX = std::max(alpha1,alpha2);
	double AMIN = std::min(alpha1,alpha2);
	if (alpha3 > AMAX){
	  AMIN += M_PI;
	  AMAX += M_PI;
	}
	if ( AMAX - AMIN >= M_PI){
	  double temp = AMAX;
	  AMAX = AMIN + 2*M_PI;
	  AMIN = temp;
	}
	_columns->addFan (*it,e1,e1,true);
	//       	printf("%g %g --> %g %g\n",N1[0].x(),N1[0].y(),N1[1].x(),N1[1].y());
	for (int i=-1; i<=fanSize; i++){
	  double t = (double)(i+1)/ (fanSize+1);
	  double alpha = t * AMAX + (1.-t)* AMIN;
	  SVector3 x (cos(alpha),sin(alpha),0);
	  //	  printf("%d %g %g %g\n",i,x.x(),x.y(),alpha);
	  x.normalize();
	  _dirs.push_back(x);
	}
      }
    }

    //    if (_dirs.size() > 1)printf("%d directions\n",_dirs.size());

    // now create the BL points
    for (unsigned int DIR=0;DIR<_dirs.size();DIR++){
      SPoint2 p;
      SVector3 n = _dirs[DIR];

      // < ------------------------------- > //
      //   N = X(p0+ e n) - X(p0)            //
      //     = e * (dX/du n_u + dX/dv n_v)   //
      // < ------------------------------- > //

      /*      if (endOfTheBL){
	printf("%g %g %d %d %g\n", (*it)->x(), (*it)->y(), DIR, (int)_dirs.size(),
               dot(n, dirEndOfBL));
      }
      */
      if (endOfTheBL && dot(n,dirEndOfBL) > .99){
	//	printf( "coucou c'est moi\n");
      }
      else {
	MVertex *current = *it;
	reparamMeshVertexOnFace(current,gf,p);

	int nbCol = 100;
	std::vector<MVertex*> _column;
	std::vector<SMetric3> _metrics;
	//      printf("start with point %g %g (%g %g)\n",current->x(),current->y(),p.x(),p.y());
	AttractorField *catt = 0;
	SPoint3 _close;
	//double _current_distance = 0.;
	while(1){

	  SMetric3 m;
	  double metric[3];
	  double l;
	  (*blf)(current->x(),current->y(), current->z(), m, current->onWhat());
	  if (!catt){
	    catt = blf->current_closest;
	    _close = blf->_closest_point;
	    //_current_distance = blf -> current_distance;
	  }
	  SPoint2 poffset  (p.x() + 1.e-12 * n.x(),
			    p.y() + 1.e-12 * n.y());
	  buildMeshMetric(gf, poffset, m, metric);
	  const double l2 = n.x()*n.x()*metric[0] + 2*n.x()*n.y()*metric[1] + n.y()*n.y()*metric[2] ;
	  l = 1./sqrt(l2);
	  if (l >= blf->hfar){
	    break;
	  }
	  if (blf -> current_distance > blf->thickness) break;
	  catt = blf->current_closest;
	  _close = blf->_closest_point;
	  //_current_distance = blf -> current_distance;
	  SPoint2 pnew  (p.x() + l * n.x(),
			 p.y() + l * n.y());
	  GPoint gp = gf->point (pnew);
	  MFaceVertex *_current = new MFaceVertex (gp.x(),gp.y(),gp.z(),gf,pnew.x(),pnew.y());
	  _current->bl_data = new MVertexBoundaryLayerData;
	  current = _current;
	  _column.push_back(current);
	  _metrics.push_back(m);
	  if ((int)_column.size() > nbCol) break; // FIXME
	  p = pnew;
	}
	_columns->addColumn(n,*it, _column, _metrics);
      }
    }
  }
  // DEBUG STUFF

  char name[256];
  sprintf(name,"points_face_%d.pos",gf->tag());
  FILE *f = Fopen (name,"w");
  fprintf(f,"View \"\" {\n");
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    MVertex *v = *it;
    for (int i=0;i<_columns->getNbColumns(v);i++){
      const BoundaryLayerData &data = _columns->getColumn(v,i);
      for (unsigned int j = 0; j < data._column.size(); j++){
	MVertex *blv = data._column[j];
	fprintf(f,"SP(%g,%g,%g){%d};\n",blv->x(),blv->y(),blv->z(),v->getNum());
      }
    }
  }
  fprintf(f,"};\n");
  fclose (f);

  // END OF DEBUG STUFF

  return 1;
}

static double angle_0_180(SVector3 &n1, SVector3 &n2)
{
  double cosa = dot(n1,n2)/(n1.norm()*n2.norm());
  if (cosa > 1.) cosa = 1.0;
  if (cosa < -1.) cosa = -1.0;
  return acos(cosa);
}

static void createBLPointsInDir(GRegion *gr,
                                MVertex *current,
                                BoundaryLayerField *blf,
                                SVector3 & n,
                                std::vector<MVertex*> &_column,
                                std::vector<SMetric3> &_metrics)
{
  SVector3 basis (current->x(),current->y(),current->z());
  double H = blf->hwall_n;
  double dist = H;
  while(dist < blf->thickness){
    SVector3 newp = basis + n * H;
    MVertex *_current = new MVertex (newp.x(),newp.y(),newp.z(),gr);
    //    gr->mesh_vertices.push_back(_current);
    _column.push_back(_current);
    H *=  blf->ratio;
    dist += H;
    basis = newp;
  }
}

static void createColumnsBetweenFaces(GRegion *gr,
                                      MVertex *myV,
                                      BoundaryLayerField *blf,
                                      BoundaryLayerColumns *_columns,
                                      std::set<GFace*> _gfaces,
                                      std::multimap<GFace*,MTriangle*> & _faces,
                                      std::map<MFace,SVector3,Less_Face> &_normals,
                                      double _treshold)
{
  SVector3 n[256];
  SPoint3 c[256];
  int count = 0;
  GFace *gfs[256];


  // generate datas per face;

  for( std::set<GFace*> ::iterator it = _gfaces.begin() ; it != _gfaces.end(); ++it){
    for (std::multimap<GFace*,MTriangle*>::iterator itm =
	   _faces.lower_bound(*it);
	 itm != _faces.upper_bound(*it); ++itm){

      n[count] += _normals[itm->second->getFace(0)];
      c[count] = itm->second->getFace(0).barycenter();
    }
    gfs[count] = *it;
    n[count].normalize();
    count ++;
  }

  // we throw a column per set of faces that have normals that are sufficiently close

  //  printf("vertex %d %d faces\n",myV->getNum(),count);

  std::set<int> done;
  for (int i=0;i<count;i++){
    if (done.find(i) == done.end()){
      SVector3 n1 = n[i];
      SPoint3 c1 = c[i];
      SVector3 avg = n1;
      std::vector<GFace*> joint;
      joint.push_back(gfs[i]);
      for (int j=i;j<count;j++){
	if (done.find(j) == done.end()){
	  SVector3 n2 = n[j];
	  SPoint3 c2 = c[j];
	  double angle = angle_0_180 (n1,n2);
	  double sign = dot((n1-n2),(c1-c2));
	  if (!(angle > _treshold && sign > 0)){
	    joint.push_back(gfs[j]);
	    avg += n2;
	    done.insert(j);
	  }
	}
      }
      if (joint.size()){
	std::vector<MVertex*> _column;
	std::vector<SMetric3> _metrics;
	avg.normalize();
	createBLPointsInDir (gr,myV,blf,avg,_column,_metrics);
	_columns->addColumn(avg,myV,  _column, _metrics, joint);
      }
      //      printf("adding one column for %d faces\n",joint.size());
    }
  }
}

/*
static bool createWedgeBetweenTwoFaces(bool testOnly,
                                       MVertex *myV,
                                       GFace *gf1, GFace *gf2,
                                       std::multimap<GFace*,MTriangle*> & _faces,
                                       std::map<MFace,SVector3,Less_Face> &_normals,
                                       double _treshold,
                                       std::vector<SVector3> &shoot)
{
  SVector3 n1,n2;
  SPoint3 c1,c2;
  for (std::multimap<GFace*,MTriangle*>::iterator itm =
	 _faces.lower_bound(gf1);
       itm != _faces.upper_bound(gf1); ++itm){
    n1 += _normals[itm->second->getFace(0)];
    c1 = itm->second->getFace(0).barycenter();
  }
  for (std::multimap<GFace*,MTriangle*>::iterator itm =
	 _faces.lower_bound(gf2);
       itm != _faces.upper_bound(gf2); ++itm){
    n2 += _normals[itm->second->getFace(0)];
    c2 = itm->second->getFace(0).barycenter();
  }
  n1.normalize();
  n2.normalize();
  // FIXME WRONG FOR INTERNAL CORNERS !!!
  double angle = angle_0_180 (n1,n2);
  double sign = dot((n1-n2),(c1-c2));
  if (angle > _treshold && sign > 0){
    if(testOnly)return true;
    int fanSize = FANSIZE__; //angle /  _treshold;
    for (int i=-1; i<=fanSize; i++){

      double ti = (double)(i+1)/ (fanSize+1);
      double angle_t = ti * angle;
      double cosA = cos (angle_t);
      double cosAlpha = dot(n1,n2);

      const double A = (1.- 2.*cosA*cosA) + cosAlpha*cosAlpha - 2 * cosAlpha*(1.-cosA*cosA);
      const double B = -2*(1.-cosA*cosA)*(1-cosAlpha);
      const double C = 1.-cosA*cosA;
      double DELTA = B*B-4*A*C;
      double t = 0.0;
      if (A == 0.0){
	t = -C / B;
      }
      else if (C != 0.0){
	if (DELTA < 0){
	  Msg::Error("this should not happen DELTA = %12.5E",DELTA);
	  DELTA = 0;
	}
	const double t1 = (-B+sqrt(DELTA))/(2.*A);
	const double t2 = (-B-sqrt(DELTA))/(2.*A);

	SVector3 x1 (n1*(1.-t1) + n2 * t2);
	SVector3 x2 (n1*(1.-t2) + n2 * t2);
	double a1 = angle_0_180 (n1,x1);
	double a2 = angle_0_180 (n1,x2);
	if (fabs(a1 - angle_t) < fabs(a2 - angle_t))t = t1;
	else t = t2;
      }
      SVector3 x (n1*(1.-t) + n2 * t);
      x.normalize();
      shoot.push_back(x);
    }
    return true;
  }
  else {
    if(testOnly)return false;
    SVector3 n = n1+n2;
    n.normalize();
    shoot.push_back(n);
    return false;
  }
}
*/

BoundaryLayerColumns *buildAdditionalPoints3D(GRegion *gr)
{
  BoundaryLayerField *blf = getBLField (gr->model());

  if (!blf)return 0;

  blf->setupFor3d();

  double _treshold = blf->fan_angle * M_PI / 180 ;

  BoundaryLayerColumns * _columns = new BoundaryLayerColumns;

  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator itf = faces.begin();
  std::set<MVertex*> _vertices;
  std::map<MFace,SVector3,Less_Face> _normals;
  std::map<MTriangle*,GFace*> _gfaces;

  // filter vertices : belong to BL and are classified on FACES
  while(itf != faces.end()){
    if (blf->isFaceBL((*itf)->tag())){
      //      printf("FACE %d is a boundary layer face %d triangles\n",(*itf)->tag(),
      //             (int)(*itf)->triangles.size());
      for(unsigned int i = 0; i< (*itf)->triangles.size(); i++){
	_gfaces[(*itf)->triangles[i]] = *itf;
	_columns->_inverse_classification [(*itf)->triangles[i]->getFace(0)] = *itf;
	for(unsigned int j = 0; j< 3; j++){
	  if ((*itf)->triangles[i]->getVertex(j)->onWhat()->dim() != 3){
	    _columns->_non_manifold_faces.insert
              (std::make_pair((*itf)->triangles[i]->getVertex(j),(*itf)->triangles[i]));
	    _vertices.insert((*itf)->triangles[i]->getVertex(j));
	    _normals [(*itf)->triangles[i]->getFace(0)] = SVector3(0,0,0);
	  }
	}
      }
    }
    ++itf;
  }
  //  printf("%d vertices \n", (int)_vertices.size());

  // assume that the initial mesh has been created i.e. that there exist
  // tetrahedra inside the domain. Tetrahedra are used to define
  // exterior normals
  for (unsigned int i=0;i<gr->tetrahedra.size();i++){
    for (int j=0;j<4;j++){
      MFace f = gr->tetrahedra[i]->getFace(j);
      std::map<MFace,SVector3,Less_Face>::iterator it = _normals.find(f);
      if (it != _normals.end()){
	MVertex *v0 = f.getVertex(0);
	MVertex *v1 = f.getVertex(1);
	MVertex *v2 = f.getVertex(2);
	MVertex *v3 = 0;
	for (int k=0;k<4;k++){
	  if (gr->tetrahedra[i]->getVertex(k) != v0 &&
	      gr->tetrahedra[i]->getVertex(k) != v1 &&
	      gr->tetrahedra[i]->getVertex(k) != v2 ){
	    v3 = gr->tetrahedra[i]->getVertex(k);
	  }
	}
	SVector3 v01 (v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
	SVector3 v02 (v2->x()-v0->x(),v2->y()-v0->y(),v2->z()-v0->z());
	SVector3 v03 (v3->x()-v0->x(),v3->y()-v0->y(),v3->z()-v0->z());
	SVector3 n = crossprod (v01,v02);
	double sign = dot(n,v03);
	n.normalize();
	if (sign > 0)it->second = n;
	else it->second = n*(-1.0);
	if (_columns->_normals3D.find(it->first) != _columns->_normals3D.end())
	  printf("aaaaaaaarghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n");
	_columns->_normals3D.insert(std::make_pair(it->first,it->second));
      }
    }
  }

  // for all boundry points
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    std::vector<MTriangle*> _connections;
    std::vector<SVector3> _dirs, _allDirs;
    std::list<GFace*> faces =  (*it)->onWhat()->faces();

    std::multimap<GFace*,MTriangle*> _faces;
    std::set<GFace*> _allGFaces;
    for (std::multimap<MVertex*,MTriangle*>::iterator itm =
           _columns->_non_manifold_faces.lower_bound(*it);
         itm != _columns->_non_manifold_faces.upper_bound(*it); ++itm){
      _connections.push_back (itm->second);
      _allDirs.push_back (_normals[itm->second->getFace(0)]);
      GFace *gf = _gfaces[itm->second];
      _faces.insert(std::make_pair(gf,itm->second));
      _allGFaces.insert(gf);
    }

    bool onSymmetryPlane = 0;
    if ((*it)->onWhat()->dim() != 2){
      std::list<GFace*> faces =  (*it)->onWhat()->faces();
      if (faces.size() != _allGFaces.size()){
	onSymmetryPlane = true;
      }
    }

    if (onSymmetryPlane){
      for ( std::list<GFace*>::iterator itf = faces.begin(); itf!= faces.end() ; ++itf){
	BoundaryLayerColumns* _face_columns = (*itf)->getColumns();
	int N = _face_columns->getNbColumns(*it);
	if (N == 1){
	  std::vector<GFace*> _joint;
	  _joint.insert(_joint.begin(),_allGFaces.begin(),_allGFaces.end());
	  const BoundaryLayerData & c = _face_columns->getColumn(*it,0);
	  _columns->addColumn(_allDirs[0],*it, c._column, c._metrics, _joint);
	}
	else if (N > 1){
	  Msg::Error ("Impossible connexion between face and region BLs");
	}
      }
    }
    else
      createColumnsBetweenFaces (gr,*it,blf,_columns,_allGFaces,_faces,_normals,_treshold);

  }

  // DEBUG STUFF

  FILE *f = fopen ("test3D.pos","w");
  fprintf(f,"View \"\" {\n");
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    MVertex *v = *it;
    for (int i=0;i<_columns->getNbColumns(v);i++){
      const BoundaryLayerData &data = _columns->getColumn(v,i);
      for (unsigned int j=0;j<data._column.size();j++){
	MVertex *blv = data._column[j];
	fprintf(f,"SP(%g,%g,%g){%d};\n",blv->x(),blv->y(),blv->z(),v->getNum());
      }
    }
  }
  fprintf(f,"};\n");
  fclose (f);

  // END OF DEBUG STUFF

  return _columns;
}

#endif
