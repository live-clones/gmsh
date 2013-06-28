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
#include "MEdge.h"
#include "boundaryLayersData.h"
#include "Field.h"
#include "OS.h"

SVector3 interiorNormal (SPoint2 p1, SPoint2 p2, SPoint2 p3)
{
  SVector3 ez (0,0,1);
  SVector3 d (p1.x()-p2.x(),p1.y()-p2.y(),0);
  SVector3 h (p3.x()-0.5*(p2.x()+p1.x()),p3.y()-0.5*(p2.y()+p1.y()),0);
  SVector3 n = crossprod(d,ez);
  n.normalize();
  if (dot(n,h) > 0)return n;
  return n*(-1.);
}

double computeAngle (GFace *gf, const MEdge &e1, const MEdge &e2,
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



*/
static void treat2Connections (GFace *gf, MVertex *_myVert, MEdge &e1, MEdge &e2,
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
      if (test) printf("angle %12.5E\n", 180*angle/M_PI);
      if (angle < _treshold /*&& angle > - _treshold*/){
	SVector3 x = N1[SIDE]*1.01+N2[SIDE];
	x.normalize();
	_dirs.push_back(x);
      }
      else if (angle >= _treshold){
	int fanSize = angle /  _treshold;
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
    }
  }
}

static void treat3Connections (GFace *gf, MVertex *_myVert, MEdge &e1,
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


bool buildAdditionalPoints2D (GFace *gf, BoundaryLayerColumns *_columns)
{
#if !defined(HAVE_ANN) || !defined(HAVE_MESH)
  return false;
#else
  //// GET THE FIELD THAT DEFINES THE DISTANCE FUNCTION
  FieldManager *fields = gf->model()->getFields();
  if(fields->getBoundaryLayerField() <= 0){
    return 0;
  }
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField*> (bl_field);

  if (!blf)return false;

  double _treshold = blf->fan_angle * M_PI / 180 ;

  //  BoundaryLayerColumns * _columns = new BoundaryLayerColumns;

  // assume a field that i) gives us the closest point on one of the BL components
  // ii) Gives us mesh sizes in the 3 directions.

  ///// build vertex to vertex connexions
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> embedded_edges = gf->embeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(),embedded_edges.end());
  std::list<GEdge*>::iterator ite = edges.begin();
  std::set<MVertex*> _vertices;
  std::set<MEdge,Less_Edge> allEdges;
  std::multimap<MVertex*,MVertex*> tangents;
  while(ite != edges.end()){
    // check if this edge generates a boundary layer
    if (blf->isEdgeBL ((*ite)->tag())){
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
  if (!_vertices.size())return false;

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
	// end of the BL
	if (Ts.size() == 1){
	  MEdge e2 (*it,Ts[0]);
	  SPoint2 p0,p1;
	  reparamMeshEdgeOnFace(*it,Ts[0], gf, p0, p1);
	  dirEndOfBL = SVector3(p1.x()-p0.x(),p1.y()-p0.y(),0);
	  dirEndOfBL.normalize();
	  endOfTheBL = true;
	  _columns->_normals.insert (std::make_pair(e2,dirEndOfBL));
	  treat2Connections (gf, *it,e1,e2, _treshold, _columns, _dirs, true);
	}
	else {
	  Msg::Error("Impossible BL Configuration");
	}
      }
      else if (N1.size() == 2){
	//	printf("%g %g --> %g %g \n",e1.getVertex(0)->x(),e1.getVertex(0)->y(),
	//	       e1.getVertex(1)->x(),e1.getVertex(1)->y());
	//	printf("N1.size = %d %g %g %g %g\n",N1.size(),N1[0].x(),N1[0].y(),N1[1].x(),N1[1].y());
	SPoint2 p0,p1;
	reparamMeshEdgeOnFace(*it,_connections[0], gf, p0, p1);

	int fanSize = M_PI /  _treshold;
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
	//	printf("%g %g --> %g %g\n",N1[0].x(),N1[0].y(),N1[1].x(),N1[1].y());
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

      if (endOfTheBL){
	printf("%g %g %d %d %g\n", (*it)->x(), (*it)->y(), DIR, (int)_dirs.size(),
               dot(n, dirEndOfBL));
      }
      if (endOfTheBL && dot(n,dirEndOfBL) > .99){
	printf( "coucou c'est moi\n");
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
	  (*bl_field)(current->x(),current->y(), current->z(), m, current->onWhat());
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
	  //	printf("pnew %g %g new point %g %g n %g %g\n",pnew.x(),pnew.y(),gp.x(),gp.y(),n.x(),n.y());
	  _metrics.push_back(m);
	  //	const double l = n[0]*m(0,0) +;
	  if ((int)_column.size() > nbCol) break; // FIXME
	  p = pnew;
	}
	//      if (_dirs.size() > 1)printf("adding column with %d nodes\n",_column.size());
	_columns->addColumn(n,*it, _column, _metrics);
      }
    }
  }
  // DEBUG STUFF

  FILE *f = Fopen ("test.pos","w");
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
#endif
}

