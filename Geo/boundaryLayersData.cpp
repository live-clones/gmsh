// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <stack>
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
#include "BackgroundMesh.h"

#if !defined(HAVE_MESH) || !defined(HAVE_ANN)

BoundaryLayerField* getBLField(GModel *gm){ return 0; }
bool buildAdditionalPoints2D (GFace *gf ) { return false; }
bool buildAdditionalPoints3D (GRegion *gr) { return false; }
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

const BoundaryLayerData & BoundaryLayerColumns::getColumn(MVertex *v, MFace f) const
{
  int N = getNbColumns(v) ;
  if (N == 1) return getColumn(v, 0);
  std::map<MFace, GFace*, Less_Face>::const_iterator it = _inverse_classification.find(f);
  if (it != _inverse_classification.end()) {
    GFace *gf = it->second;
    for (int i=0;i<N;i++){
      const BoundaryLayerData & c = getColumn(v, i);
      if (std::find(c._joint.begin(),c._joint.end(),gf) != c._joint.end())return c;
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
                              BoundaryLayerColumns *_columns,
                              std::vector<SVector3> &_dirs, bool fan)
{
  std::vector<SVector3> N1,N2;
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e1);
       itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
  for (std::multimap<MEdge,SVector3,Less_Edge>::iterator itm =
	 _columns->_normals.lower_bound(e2);
       itm != _columns->_normals.upper_bound(e2); ++itm) N2.push_back(itm->second);
  if (N1.size() == N2.size()){
    for (unsigned int SIDE = 0; SIDE < N1.size() ; SIDE++){
      // IF THE ANGLE IS GREATER THAN THRESHOLD, ADD DIRECTIONS !!
      //      double angle = computeAngle (gf,e1,e2,N1[SIDE],N2[SIDE]);
      if (!fan){
	SVector3 x = N1[SIDE]*1.01+N2[SIDE];
	x.normalize();
	_dirs.push_back(x);
      }
      else if (fan){

	if (USEFANS__){
	  int fanSize = FANSIZE__;
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

static void treat3Connections(GFace *gf, MVertex *_myVert, MEdge &e1,
                              MEdge &e2, MEdge &e3,
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

    bool fan = (*it)->onWhat()->dim() == 0 && blf->isFanNode((*it)->onWhat()->tag());

    for (std::multimap<MVertex*,MVertex*>::iterator itm =
           _columns->_non_manifold_edges.lower_bound(*it);
         itm != _columns->_non_manifold_edges.upper_bound(*it); ++itm)
      _connections.push_back (itm->second);

    // A trailing edge topology : 3 edges incident to a vertex
    if (_connections.size() == 3){
      MEdge e1 (*it,_connections[0]);
      MEdge e2 (*it,_connections[1]);
      MEdge e3 (*it,_connections[2]);
      treat3Connections (gf, *it,e1,e2,e3, _columns, _dirs);
    }
    // STANDARD CASE, one vertex connected to two neighboring vertices
    else if (_connections.size() == 2){
      MEdge e1 (*it,_connections[0]);
      MEdge e2 (*it,_connections[1]);
      treat2Connections (gf, *it,e1,e2, _columns, _dirs, fan);
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

	int fanSize = FANSIZE__;
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


static bool createWedgeBetweenTwoFaces(MVertex *myV,
				       SVector3 n1, SVector3 n2,
                                       std::vector<SVector3> &shoot)
{
  double angle = angle_0_180 (n1,n2);
  int fanSize = FANSIZE__;
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



/*
  a "fanned" edge is one that opens a fan of element between the 2 faces
  it connects in the volume.

  fan start (end)
    --> at a symmetry plane or at an inflow/outflow bdry. This implies
    that the fan has a trace on this boundary
    --> at a corner where at least 3 incident model edges are "fanned"

  fan can also be doing a closed loop

  when looking at a model vertex, one can then have
     --> At least 3 fanned edges : this is a corner
     --> Two fanned edges : this is the passage of a fan
     --> A model vertex that has one single incident fanned edge is forbidden

  The algo that allows to build the topology of fans

     1) Compute fanned edges : use threshold angle between adjacent faces as
     user parameter
     2) If one model vertex is connected to one single fanned edge
          -) If the model vertex is in the symmetry plane --> OK
          -) If the number of incident edges is 2 --> add the second one as a fan
	  -) If more that 1 other edge is not fanned --> ask the user to choose
	  -) Repeat 2) until everything is OK
     3) Create sets of model faces that are NOT connected by fans and therefore that
     are considered as equivalent
*/

// return the edges connected to a vertex for this volume

struct fanTopology {
  std::set<GVertex*> corners;
  std::set<GVertex*> endings;
  std::set<GEdge*> fans;
  std::vector< std::set<GFace *> > groups;
  bool isFan (GEdge* ge) const {return fans.find(ge) != fans.end();}
  int getGroupNum (GFace *gf) const
  {
    for (unsigned int i=0; i< groups.size(); i++){
      if (std::find(groups[i].begin(),groups[i].end(),gf) != groups[i].end())return i;
    }
    return -1;
  }
  fanTopology (GRegion * gr, const std::set<GEdge*> &detectedFans, const std::set<GVertex*> &sym, BoundaryLayerField *blf );
};

static std::list<GEdge*> edges (GVertex* gv, GRegion* gr) {
  std::list<GEdge*> er  = gr->edges();
  std::list<GEdge*> ev  = gv->edges();
  std::list<GEdge*> e  ;

  for (std::list<GEdge*>::iterator ite = ev.begin() ; ite !=ev.end() ; ite++){
    if (std::find (er.begin(), er.end(), *ite) != er.end())e.push_back(*ite);
  }
  return e;
}

static GFace *otherSideOfEdge (GRegion * gr, GFace *gf, GEdge *ge)
{
  std::list<GFace*> fe = ge->faces();
  std::list<GFace*> fr = gr->faces();
  for (std::list<GFace*>::iterator it = fe.begin(); it != fe.end(); ++it){
    if ((*it) != gf && std::find(fr.begin(), fr.end(), *it) != fr.end())
      return *it;
  }
  //  printf("ouille autre cote de face %d par arerte %d dans region %d foireux\n",gf->tag(),ge->tag(),gr->tag());
  return 0;
}

fanTopology :: fanTopology (GRegion * gr, const std::set<GEdge*> &detectedFans, const std::set<GVertex*> &sym, BoundaryLayerField *blf )
{
  fans = detectedFans;
  endings = sym;
  std::list<GVertex*> vs = gr->vertices();
  while (1){
    unsigned int nb = fans.size();
    for (std::list<GVertex*>::iterator it  = vs.begin() ; it != vs.end(); it++){
      GVertex *gv = *it;
      std::list<GEdge*> e = edges (gv, gr);
      std::list<GEdge*> fe ;
      for (std::list<GEdge*>::iterator ite = e.begin() ; ite !=e.end() ; ite++)
	if (isFan(*ite))fe.push_back(*ite);
      if (fe.size() == 1){
	if (endings.find(gv) != endings.end()) continue;
	else if (e.size() == 2)fans.insert(e.begin(), e.end());
	else Msg::Fatal("Ensure that it is possible to find closed loops in BL fans !");
      }
    }
    if (nb == fans.size())break;
  }

  for (std::list<GVertex*>::iterator it  = vs.begin() ; it != vs.end(); it++){
    GVertex *gv = *it;
    std::list<GEdge*> e = edges (gv, gr);
    std::list<GEdge*> fe ;
    for (std::list<GEdge*>::iterator ite = e.begin() ; ite !=e.end() ; ite++)
      if (isFan(*ite))fe.push_back(*ite);
    //    printf("%d fans connected to vert %d\n",fe.size(),gv->tag(), e.size());
    if (fe.size() > 2)corners.insert(gv);
  }

  std::list<GFace*> fs = gr->faces();

  while (!fs.empty()) {
    GFace *gf = *fs.begin();
    std::set<GFace *> groupOfFaces;
    groupOfFaces.insert(gf);
    std::stack<GFace*> _stack;
    _stack.push(gf);
    //    printf("pushing %d\n",gf->tag());
    while(!_stack.empty()){
      gf = _stack.top();
      _stack.pop();
      std::list<GEdge*> ed = gf->edges();
      for (std::list<GEdge*>::iterator ite = ed.begin() ; ite !=ed.end() ; ite++){
	if (!isFan(*ite) && !blf->isEdgeBLSaved((*ite)->tag())){
	  GFace *otherSide = otherSideOfEdge (gr,gf,*ite);
	  if (otherSide && groupOfFaces.find(otherSide) == groupOfFaces.end()){
	    groupOfFaces.insert(otherSide);
	    _stack.push(otherSide);
	    //	    printf("pushing %d through %d\n",otherSide->tag(),(*ite)->tag());
	  }
	}
      }
    }
    groups.push_back(groupOfFaces);
    std::list<GFace*> fsb;
    for (std::list<GFace*>::iterator it = fs.begin() ; it != fs.end() ; it++){
      if (groupOfFaces.find(*it) == groupOfFaces.end())fsb.push_back(*it);
    }
    fs = fsb;
  }
}


static int createColumnsBetweenFaces(GRegion *gr,
				     MVertex *myV,
				     BoundaryLayerField *blf,
				     BoundaryLayerColumns *_columns,
				     std::set<GFace*> &_gfaces,
				     std::multimap<GFace*,MTriangle*> & _faces,
				     std::map<MFace,SVector3,Less_Face> &_normals,
				     fanTopology &ft)
{
  SVector3 n[256];
  SPoint3 c[256];
  int count = 0;
  GFace *gfs[256];

  // we compute normals per face using the surface mesh (we could try to use the
  // model but I doubt it'd be better, especially if the mesh is coarse
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

  // the topology of the fans is known
  // we look over all faces and look in which
  // group it lies in

  std::vector< std::vector<GFace*> > joints;

  std::multimap<int, GFace*> lGroup;
  std::map<GFace*, int> inv;
  std::set<int> gs;
  for (int i=0;i<count;i++) {
    inv[gfs[i]] = i;
    int iGroup = ft.getGroupNum (gfs[i]);
    gs.insert(iGroup);
    lGroup.insert(std::make_pair(iGroup,gfs[i]));
  }


  for (std::set<int>::iterator it = gs.begin(); it != gs.end() ; ++it){
    std::pair<std::multimap<int, GFace*>::iterator, std::multimap<int, GFace*>::iterator> range = lGroup.equal_range(*it);
    std::vector<GFace*> joint;
    for (std::multimap<int, GFace*>::iterator itm =  range.first ; itm !=  range.second ; itm++)
      joint.push_back(itm->second);
    joints.push_back(joint);
    SVector3 avg (0,0,0);
    for (unsigned int i=0;i<joint.size(); i++){
      avg += n[inv[joint[i]]];
    }
    std::vector<MVertex*> _column;
    std::vector<SMetric3> _metrics;
    avg.normalize();
    createBLPointsInDir (gr,myV,blf,avg,_column,_metrics);
    _columns->addColumn(avg,myV,  _column, _metrics, joint);
  }

  //  // DEBUG STUFF
  //  if (myV->onWhat()->dim() == 0 && myV->onWhat()->tag() == 6){
  //    printf("%d %d\n",gs.size(),joints.size());
  //  }


  // create wedges
  if (joints.size() > 1){
    for (unsigned int I = 0     ; I < joints.size() ; I++){
      const BoundaryLayerData & c0 = _columns->getColumn(myV, I);
      for (unsigned int J = I+1 ; J < joints.size() ; J++){
	const BoundaryLayerData & c1 = _columns->getColumn(myV, J);
	std::vector<SVector3> shoot;
	createWedgeBetweenTwoFaces(myV,c0._n,c1._n,shoot);
	for (unsigned int i=1;i<shoot.size()-1;i++){
	  std::vector<MVertex*> _column;
	  std::vector<SMetric3> _metrics;
	  createBLPointsInDir (gr,myV,blf,shoot[i],_column,_metrics);
	  _columns->addColumn(shoot[i] , myV,  _column, _metrics);
	}
      }
    }
  }
  // we have a corner : in a first step, only add one single
  // in the average direction
  if (joints.size() > 2){
  }

  return joints.size();
}

static void createColumnsOnSymmetryPlane(MVertex *myV,
                                         BoundaryLayerColumns *_columns,
                                         std::set<GFace*> &_allGFaces,
                                         std::list<GFace*> &faces,
                                         fanTopology &ft)
{
  // get all model faces for that vertex that have boundary layer columns attached
  for ( std::list<GFace*>::iterator itf = faces.begin(); itf!= faces.end() ; ++itf){
    BoundaryLayerColumns* _face_columns = (*itf)->getColumns();
    int N = _face_columns->getNbColumns(myV);
    if (N == 1){
      std::vector<GFace*> _joint;
      _joint.insert(_joint.begin(),_allGFaces.begin(),_allGFaces.end());
      const BoundaryLayerData & c = _face_columns->getColumn(myV,0);
      _columns->addColumn(c._n,myV, c._column, c._metrics, _joint);
    }
    else if (N > 1){
      if (_allGFaces.size() != 2){
	Msg::Fatal("cannot solve such a strange stuff in the BL");
      }
      //	  printf("%d columns\n",N);
      std::set<GFace*>::iterator itff = _allGFaces.begin();
      GFace *g1 = *itff ; ++itff; GFace *g2 = *itff;
      int sense = 1;
      std::vector<GFace*> _joint;

      const BoundaryLayerFan *fan = _face_columns->getFan(myV);

      if (fan){
	MVertex *v11 = fan->_e1.getVertex(0);
	MVertex *v12 = fan->_e1.getVertex(1);
	std::list<GEdge*> l1 = g1->edges();
	std::list<GEdge*> l2 = g2->edges();
	if (v11 == myV){
	  if (v12->onWhat()->dim() == 1){
	    GEdge *ge1 = (GEdge*)v12->onWhat();
	    //		printf("COUCOU %d %d %d\n",fan->sense,std::find(l1.begin(),l1.end(),ge1) != l1.end(),std::find(l2.begin(),l2.end(),ge1) != l2.end());
	    if (std::find(l1.begin(),l1.end(),ge1) != l1.end())sense = fan->sense;
	    else if (std::find(l2.begin(),l2.end(),ge1) != l2.end())sense = -fan->sense;
	    //else printf("strange1 %d %d \n");
	  }
	  else Msg::Error("Cannot choose between directions in a BL (dim = %d)",v12->onWhat()->dim());
	}
	else {
	  if (v11->onWhat()->dim() == 1){
	    GEdge *ge1 = (GEdge*)v11->onWhat();
	    if (std::find(l1.begin(),l1.end(),ge1) != l1.end())sense = fan->sense;
	    else if (std::find(l2.begin(),l2.end(),ge1) != l2.end())sense = -fan->sense;
	    //else printf("strange2 %d %d \n");
	  }
	  else Msg::Error("Cannot choose between directions in a BL");
	}
      }
      else{
	Msg::Error("No fan on the outgoing BL");
      }
      _joint.push_back(g1);
      const BoundaryLayerData & c0 = _face_columns->getColumn(myV,sense==1 ? 0 : N-1);
      _columns->addColumn(c0._n,myV, c0._column, c0._metrics,_joint);
      _joint.clear();
      _joint.push_back(g2);
      const BoundaryLayerData & cN = _face_columns->getColumn(myV,sense==1 ? N-1 : 0);
      _columns->addColumn(cN._n,myV, cN._column, cN._metrics,_joint);
      if (sense==1){
	for (int k=1;k<N-1;k++){
	  const BoundaryLayerData & c = _face_columns->getColumn(myV,k);
	  _columns->addColumn(c._n,myV, c._column, c._metrics);
	}
      }
      else {
	for (int k=N-2;k>0;k--){
	  const BoundaryLayerData & c = _face_columns->getColumn(myV,k);
	  _columns->addColumn(c._n,myV, c._column, c._metrics);
	}
      }
    }
  }
}

static bool preprocessVertex (MVertex *v,
			      std::map<MTriangle*,GFace*> &_gfaces,
			      BoundaryLayerColumns * _columns,
			      std::list<GFace*> &faces,
			      std::multimap<GFace*,MTriangle*> &_faces,
			      std::set<GFace*> &_allGFaces){
  faces =  v->onWhat()->faces();
  for (std::multimap<MVertex*,MTriangle*>::iterator itm =
	 _columns->_non_manifold_faces.lower_bound(v);
       itm != _columns->_non_manifold_faces.upper_bound(v); ++itm){
    GFace *gf = _gfaces[itm->second];
    _faces.insert(std::make_pair(gf,itm->second));
    _allGFaces.insert(gf);
  }

  bool onSymmetryPlane = false;
  if (v->onWhat()->dim() != 2)
    if (faces.size() != _allGFaces.size())
      onSymmetryPlane = true;
  return onSymmetryPlane;
}

bool buildAdditionalPoints3D(GRegion *gr)
{
  BoundaryLayerField *blf = getBLField (gr->model());

  if (!blf) return false;

  blf->setupFor3d();

  BoundaryLayerColumns *_columns = gr->getColumns();

  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator itf = faces.begin();
  std::set<MVertex*> _vertices;
  std::map<MFace,SVector3,Less_Face> _normals;
  std::map<MTriangle*,GFace*> _gfaces;

  // filter vertices : belong to BL and are classified on FACES
  while(itf != faces.end()){
    if (blf->isFaceBL((*itf)->tag())){
      //            printf("FACE %d is a boundary layer face %d triangles\n",(*itf)->tag(),
      //                   (int)(*itf)->triangles.size());
      for(unsigned int i = 0; i< (*itf)->triangles.size(); i++){
	_gfaces[(*itf)->triangles[i]] = *itf;
	_columns->_inverse_classification [(*itf)->triangles[i]->getFace(0)] = *itf;
	_normals [(*itf)->triangles[i]->getFace(0)] = SVector3(0,0,0);
	for(unsigned int j = 0; j< 3; j++){
	  if ((*itf)->triangles[i]->getVertex(j)->onWhat()->dim() != 3){
	    _columns->_non_manifold_faces.insert
              (std::make_pair((*itf)->triangles[i]->getVertex(j),(*itf)->triangles[i]));
	    _vertices.insert((*itf)->triangles[i]->getVertex(j));
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

  // look for all the wedges
  std::set<GEdge*> fans;
  std::set<GVertex*> fanNodes;
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    std::list<GFace*> faces;
    std::multimap<GFace*,MTriangle*> _faces;
    std::set<GFace*> _allGFaces;
    preprocessVertex (*it, _gfaces, _columns, faces, _faces, _allGFaces);
    if ((*it)->onWhat()->dim() == 0){
      GVertex *gv = static_cast<GVertex*>((*it)->onWhat());
      if (gv && blf->isFanNode(gv->tag())){
	fanNodes.insert(gv);
      }
    }
    else if ((*it)->onWhat()->dim() == 1){
      GEdge *ge = static_cast<GEdge*>((*it)->onWhat());
      if (ge && blf->isFan(ge->tag())){
	fans.insert(ge);
      }
    }
  }

  //  printf("STARTING ANALYSIS OF TOPOLOGY (%d fan nodes %d fan edges\n",fanNodes.size(),fans.size());

  fanTopology ft (gr, fans, fanNodes, blf);

  Msg::Info("BL Topology for region %d : %d FANS %d CORNERS %d GROUPS %d ENDINGS",
	    gr->tag(),ft.fans.size(),ft.corners.size(),ft.groups.size(),ft.endings.size());

  // for all boundry points
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    std::list<GFace*> faces;
    std::multimap<GFace*,MTriangle*> _faces;
    std::set<GFace*> _allGFaces;
    bool onSymmetryPlane = preprocessVertex (*it, _gfaces, _columns, faces, _faces, _allGFaces);

    if (onSymmetryPlane){
      // we have a 3D boundary layer that connects a 2D boundary layer
      // this is the tricky case
      createColumnsOnSymmetryPlane(*it,_columns, _allGFaces, faces, ft);
    }
    else {
      // internal columns (inside the volume)
      createColumnsBetweenFaces (gr,*it,blf,_columns,_allGFaces,_faces,_normals,ft);
    }
  }

  // DEBUG STUFF

  FILE *f = fopen ("POINTS3D.pos","w");
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

  return true;
}

#endif
