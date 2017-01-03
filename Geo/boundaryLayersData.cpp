// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "boundaryLayersData.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "OS.h"

#if !defined(HAVE_MESH) || !defined(HAVE_ANN)

BoundaryLayerField* getBLField(GModel *gm){ return 0; }
bool buildAdditionalPoints2D (GFace *gf ) { return false; }
bool buildAdditionalPoints3D (GRegion *gr) { return false; }
//void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]) {}
/*faceColumn BoundaryLayerColumns::getColumns(GFace *gf, MVertex *v1, MVertex *v2,
                                            MVertex *v3, int side)
{
  return faceColumn(BoundaryLayerData(),BoundaryLayerData(),BoundaryLayerData());
}
*/
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
      if (!fan){
	SVector3 x = N1[SIDE]*1.01+N2[SIDE];
	x.normalize();
	_dirs.push_back(x);
      }
      else if (fan){

	//	printf("fan \n");
	
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
      /*
      else {
	_dirs.push_back(N1[SIDE]);
	_dirs.push_back(N2[SIDE]);
	}
      */
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
  if (!blf->isEdgeBL(ge->tag())){
    GVertex *g0 = ge->getBeginVertex();
    GVertex *g1 = ge->getEndVertex();
    MVertex * v0 = g0->mesh_vertices[0];
    MVertex * v1 = g1->mesh_vertices[0];
    std::vector<MVertex*> invert;
    for(unsigned int i = 0; i < ge->mesh_vertices.size() ; i++)
      invert.push_back(ge->mesh_vertices[ge->mesh_vertices.size() - i - 1]);
    SVector3 t (v1->x()-v0->x(), v1->y()-v0->y(),v1->z()-v0->z());
    t.normalize();
    if (g0 == gv)
      _columns->addColumn(t, v0, ge->mesh_vertices);
    else if (g1 == gv)
      _columns->addColumn(t*-1.0, v1,invert);
  }
}

void getLocalInfoAtNode (MVertex *v, BoundaryLayerField *blf, double &hwall) {  
  hwall = blf->hwall_n;
  if (v->onWhat()->dim() == 0){
    hwall= blf->hwall (v->onWhat()->tag());    
  } 
  else if (v->onWhat()->dim() == 1){
    GEdge *ge = (GEdge*)v->onWhat();
    Range<double> bounds = ge->parBounds(0);
    double t_begin = bounds.low();
    double t_end = bounds.high();
    double t;
    v->getParameter(0,t);
    double hwall_beg = blf->hwall (ge->getBeginVertex()->tag());    
    double hwall_end = blf->hwall (ge->getEndVertex()->tag());    
    hwall = hwall_beg + (t-t_begin)/(t_end-t_begin) * (hwall_end - hwall_beg);
  } 
}


bool buildAdditionalPoints2D(GFace *gf)
{
  
  BoundaryLayerColumns *_columns = gf->getColumns();
  _columns->clearData();

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
	MVertex *first = *it;
	double hwall;
	getLocalInfoAtNode (first, blf, hwall);  
	std::vector<MVertex*> _column;
	SPoint2 par = gf->parFromPoint(SPoint3(first->x(),first->y(),first->z()));
	double L = hwall;
	while(1){
	  //	  printf("L = %g\n",L);
	  if (L > blf->thickness) break;
	  SPoint2 pnew  (par.x() + L * n.x(),
			 par.y() + L * n.y());
	  GPoint pp = gf->point(pnew);
	  MFaceVertex *_current = new MFaceVertex (pp.x(),pp.y(),pp.z(),gf,pnew.x(),pnew.y());
	  _current->bl_data = new MVertexBoundaryLayerData;
	  _column.push_back(_current);
	  int ith = _column.size() ;
	  L+= hwall * pow (blf->ratio, ith);
	}
	_columns->addColumn(n,*it, _column /*,_metrics*/);
      }
    }
  }

  // DEBUG STUFF
  char name[256];
  sprintf(name, "points_face_%d.pos", gf->tag());
  FILE *f = Fopen (name,"w");
  if(f){
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
  }
  // END OF DEBUG STUFF

  return 1;
}




#endif
