#include "GModel.h"
#include "GFace.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "meshGFaceBoundaryLayers.h"
#include "Field.h"
/*
             |
             |   /
    +--------x /
              \
                \
                  \

*/


SVector3 interiorNormal (SPoint2 p1, SPoint2 p2, SPoint2 p3){
  
  SVector3 ez (0,0,1);
  SVector3 d (p1.x()-p2.x(),p1.y()-p2.y(),0);
  SVector3 h (p3.x()-0.5*(p2.x()+p1.x()),p3.y()-0.5*(p2.y()+p1.y()),0);
  SVector3 n = crossprod(d,ez);
  n.normalize();
  //  printf("%g %g\n",n.x(),n.y());
  if (dot(n,h) > 0)return n;
  return n*(-1.);
  
}

double computeAngle (GFace *gf, const MEdge &e1, const MEdge &e2, SVector3 &n1, SVector3 &n2){

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
  
  //  printf("a = %12.5e cos %12.5E sin %12.5E %g %g vs %g %g\n",a,cosa,n.z(),n1.x(),n1.y(),n2.x(),n2.y());
  return a;
}

void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3])
{
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));

  double res[2][2];
  
  double M[2][3] = {{der.first().x(),der.first().y(),der.first().z()},
		    {der.second().x(),der.second().y(),der.second().z()}};
  
  
  for (int i=0;i<3;i++){
    for (int l=0;l<3;l++){
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

BoundaryLayerColumns* buidAdditionalPoints2D (GFace *gf)
{
#if !defined(HAVE_ANN)
  return 0;
#else

  FieldManager *fields = gf->model()->getFields();
  if(fields->getBoundaryLayerField() <= 0){
    return 0;
  }
  Field *bl_field = fields->get(fields->getBoundaryLayerField());
  BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField*> (bl_field);
  
  if (!blf)return 0;

  double _treshold = blf->fan_angle * M_PI / 180 ;

  BoundaryLayerColumns * _columns = new BoundaryLayerColumns;

  // assume a field that i) gives us the closest point on one of the BL components
  // ii) Gives us mesh sizes in the 3 directions.  

  // build vertex to vertex connexions 
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> embedded_edges = gf->embeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(),embedded_edges.end());
  std::list<GEdge*>::iterator ite = edges.begin();
  std::set<MVertex*> _vertices;
  while(ite != edges.end()){
    for(unsigned int i = 0; i< (*ite)->lines.size(); i++){
      MVertex *v1 = (*ite)->lines[i]->getVertex(0);
      MVertex *v2 = (*ite)->lines[i]->getVertex(1);
      _columns->_non_manifold_edges.insert(std::make_pair(v1,v2));
      _columns->_non_manifold_edges.insert(std::make_pair(v2,v1));
      _vertices.insert(v1);
      _vertices.insert(v2);
    }
    ++ite;
  }

  //  printf("%d boundary points\n",_vertices.size());
  
  // assume that the initial mesh has been created i.e. that there exist
  // triangles inside the domain. Triangles are used to define
  // exterior normals 
  for (int i=0;i<gf->triangles.size();i++){
    SPoint2 p0,p1,p2;
    MVertex *v0 = gf->triangles[i]->getVertex(0);
    MVertex *v1 = gf->triangles[i]->getVertex(1);
    MVertex *v2 = gf->triangles[i]->getVertex(2);
    reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
    reparamMeshEdgeOnFace(v0, v2, gf, p0, p2);

    MEdge me01(v0,v1);
    SVector3 v01 = interiorNormal (p0,p1,p2);        
    _columns->_normals.insert(std::make_pair(me01,v01));

    MEdge me02(v0,v2);
    SVector3 v02 = interiorNormal (p0,p2,p1);        
    _columns->_normals.insert(std::make_pair(me02,v02));

    MEdge me21(v2,v1);
    SVector3 v21 = interiorNormal (p2,p1,p0);        
    _columns->_normals.insert(std::make_pair(me21,v21));
  }  

  // for all boundry points
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    std::vector<MVertex*> _connections;      
    std::vector<SVector3> _dirs;
    double LL;
    for ( std::multimap<MVertex*,MVertex*> :: iterator itm  = _columns->_non_manifold_edges.lower_bound(*it);
	  itm != _columns->_non_manifold_edges.upper_bound(*it); ++itm)
      _connections.push_back (itm->second);
    //    printf("point %d %d edegs connected\n",(*it)->getNum(),_connections.size());
    // Trailing edge : 3 edges incident to a vertex
    if (_connections.size() == 3){
      MEdge e1 (*it,_connections[0]);
      MEdge e2 (*it,_connections[1]);
      MEdge e3 (*it,_connections[2]);
      std::vector<SVector3> N1,N2,N3;
      for ( std::multimap<MEdge,SVector3,Less_Edge> :: iterator itm  = _columns->_normals.lower_bound(e1);
	    itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
      for ( std::multimap<MEdge,SVector3,Less_Edge> :: iterator itm  = _columns->_normals.lower_bound(e2);
	    itm != _columns->_normals.upper_bound(e2); ++itm) N2.push_back(itm->second);
      for ( std::multimap<MEdge,SVector3,Less_Edge> :: iterator itm  = _columns->_normals.lower_bound(e3);
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
      printf("%g %g vs %g %g\n",N1[0].x(),N1[0].y(),N1[1].x(),N1[1].y());
      printf("%g %g vs %g %g\n",N2[0].x(),N2[0].y(),N3[0].x(),N3[0].y());
      printf("%g %g vs %g %g\n",x1.x(),x1.y(),x2.x(),x2.y());
    }
    // STANDARD CASE, one vertex connected to two neighboring vertices
    if (_connections.size() == 2){
      MEdge e1 (*it,_connections[0]);
      MEdge e2 (*it,_connections[1]);
      LL = 0.5 * (e1.length() + e2.length()); 
      std::vector<SVector3> N1,N2;
      for ( std::multimap<MEdge,SVector3,Less_Edge> :: iterator itm  = _columns->_normals.lower_bound(e1);
	    itm != _columns->_normals.upper_bound(e1); ++itm) N1.push_back(itm->second);
      for ( std::multimap<MEdge,SVector3,Less_Edge> :: iterator itm  = _columns->_normals.lower_bound(e2);
	    itm != _columns->_normals.upper_bound(e2); ++itm) N2.push_back(itm->second);
      double LL;
      if (N1.size() == N2.size()){
	//	if (N1.size() > 1)printf("%d sides\n",N1.size());
	for (int SIDE = 0; SIDE < N1.size() ; SIDE++){	
	  // IF THE ANGLE IS GREATER THAN THRESHOLD, ADD DIRECTIONS !!
	  double angle = computeAngle (gf,e1,e2,N1[SIDE],N2[SIDE]);	
	  //	  if (N1.size() > 1)printf("angle = %g\n",angle);
	  if (angle < _treshold /*&& angle > - _treshold*/){
	    SVector3 x = N1[SIDE]*1.01+N2[SIDE];
	    x.normalize();
	    _dirs.push_back(x);
	  }
	  else if (angle >= _treshold){	  
	    int fanSize = angle /  _treshold;
	    //	    printf("ONE FAN HAS BEEN CREATED : %d %d %d %d ANGLE = %g | %g %g %g %g\n",e1.getVertex(0)->getNum(),
	    //		   e1.getVertex(1)->getNum(),e2.getVertex(0)->getNum(),e2.getVertex(1)->getNum(),
	    //		   angle/M_PI*180,N1[SIDE].x(),N1[SIDE].y(),N2[SIDE].x(),N2[SIDE].y());
	    // if the angle is greater than PI, than reverse the sense
	    double alpha1 = atan2(N1[SIDE].y(),N1[SIDE].x());
	    double alpha2 = atan2(N2[SIDE].y(),N2[SIDE].x());
	    double AMAX = std::max(alpha1,alpha2);
	    double AMIN = std::min(alpha1,alpha2);
	    MEdge ee[2];
	    if (alpha1 > alpha2){
	      //	    _dirs.push_back(N2[0]);
	      //	    _dirs.push_back(N1[0]);
	      ee[0] = e2;ee[1] = e1;
	      //	    printf("reversing the first and the last normal %g %g\n",alpha2,alpha1);
	    }
	    else {
	      //	    _dirs.push_back(N1[0]);
	      //	    _dirs.push_back(N2[0]);
	      ee[0] = e1;ee[1] = e2;
	      //	    printf("the first and the last normal are ok %g %g\n",alpha1,alpha2);
	    }
	    if ( AMAX - AMIN >= M_PI){
	      double temp = AMAX;
	      AMAX = AMIN + 2*M_PI;
	      AMIN = temp;
	      //	    printf("wrong part of the quadrant taken %g %g\n",AMIN,AMAX);
	      //	    fanSize = 0;
	      MEdge eee0 = ee[0];
	      ee[0] = ee[1];ee[1] = eee0;
	    }
	    _columns->addFan (*it,ee[0],ee[1],true);
	    
	    for (int i=-1; i<=fanSize; i++){
	      double t = (double)(i+1)/ (fanSize+1);
	      double alpha = t * AMAX + (1.-t)* AMIN;
	      //	    printf("%d %g %g %g %g\n",i,alpha,alpha1,alpha2,alpha2-alpha1);	    
	      SVector3 x (cos(alpha),sin(alpha),0);
	      x.normalize();
	      _dirs.push_back(x);
	    }	  
	  }
	}
      }
    }
    
    //    if (_dirs.size() > 1)printf("%d directions\n",_dirs.size());

    // now create the BL points 
    for (int DIR=0;DIR<_dirs.size();DIR++){
      SPoint2 p;
      SVector3 n = _dirs[DIR];   
      

      // < ------------------------------- > //
      //   N = X(p0+ e n) - X(p0)            //
      //     = e * (dX/du n_u + dX/dv n_v)   //
      // < ------------------------------- > //
      
      MVertex *current = *it;
      reparamMeshVertexOnFace(current,gf,p);
           
      int nbCol = 100;
      std::vector<MVertex*> _column;
      std::vector<SMetric3> _metrics;
      //      printf("start with point %g %g (%g %g)\n",current->x(),current->y(),p.x(),p.y()); 
      AttractorField *catt = 0;
      SPoint3 _close;
      double _current_distance;
      while(1){

	SMetric3 m;
	double metric[3];
	double l;
	(*bl_field)(current->x(),current->y(), current->z(), m, current->onWhat());      
	if (!catt){
	  catt = blf->current_closest;
	  _close = blf->_closest_point;
	  _current_distance = blf -> current_distance;
	}
	SPoint2 poffset  (p.x() + 1.e-8 * n.x(), 
			  p.y() + 1.e-8 * n.y());
	buildMeshMetric(gf, poffset, m, metric);	  
	const double l2 = n.x()*n.x()*metric[0] + 2*n.x()*n.y()*metric[1] + n.y()*n.y()*metric[2] ;
	l = 1./sqrt(l2); 
	//	  if (_dirs.size() > 1) printf("l = %g metric = %g %g %g dim %d tag %d \n",l,metric[0],metric[1],metric[2],current->onWhat()->dim(),current->onWhat()->tag());
	//	  printf("%g %g\n",l,LL);
	if (l >= blf->hfar){
	  //	    printf("stopping %g %g\n",l,LL);
	  break;
	}
	//	printf("%g %g %g \n",current->x(),current->y(),blf->current_distance);
	if (blf->current_closest != catt || blf -> current_distance <  _current_distance){
	  SVector3 aaa (_close- blf->_closest_point);
	  if (aaa.norm() > 8*blf->hwall_n || blf -> current_distance <  _current_distance){
	    printf("reaching the skelton %d\n", (int) _column.size());
	    delete _column[_column.size()-1];
	    _column.erase(--_column.end());
	    _metrics.erase(--_metrics.end());
	    if (_column.size()){
	      delete _column[_column.size()-1];
	      _column.erase(--_column.end());
	      _metrics.erase(--_metrics.end());
	    }
	    break;
	  }
	}
	if (blf -> current_distance > blf->thickness) break;
	catt = blf->current_closest;
	_close = blf->_closest_point;
	_current_distance = blf -> current_distance;
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
	if (_column.size() > nbCol)break; // FIXME
	p = pnew;
      }
      _columns->addColumn(n,*it, _column, _metrics);
    }
  }  
  // HERE WE SHOULD FILTER THE POINTS IN ORDER NOT TO HAVE POINTS THAT ARE TOO CLOSE 

  // DEBUG STUFF
  
  FILE *f = fopen ("test.pos","w");
  fprintf(f,"View \"\" {\n");
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end() ; ++it){
    MVertex *v = *it;
    for (int i=0;i<_columns->getNbColumns(v);i++){
      const BoundaryLayerData &data = _columns->getColumn(v,i);
      for (int j=0;j<data._column.size();j++){
	MVertex *blv = data._column[j];
	fprintf(f,"SP(%g,%g,%g){%d};\n",blv->x(),blv->y(),blv->z(),v->getNum());
      }
    }
  } 
  fprintf(f,"};\n");
  fclose (f);
  
  // END OF DEBUG STUFF

  return _columns;
#endif
}


void BoundaryLayerColumns::filterPoints() {
  std::map<MVertex*,MVertex*> tooclose;
}
