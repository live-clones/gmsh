#include <set>
#include "meshGFaceLloyd.h"

#if defined(HAVE_BFGS)

#include "DivideAndConquer.h"
#include "GFace.h"
#include "MElement.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "Context.h"
#include "meshGFace.h"
#include "BackgroundMesh.h" 
#include <fstream>
#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"
#include "polynomialBasis.h"
#include "MElementOctree.h"



/****************fonction callback****************/
/*************************************************/

void callback(const alglib::real_1d_array& x,double& func,alglib::real_1d_array& grad,void* ptr){
  int i;
  int p;
  int num;
  int index;
  int dimension;
  int identificator;
  int iteration;
  int max;
  bool error1;
  bool error2;
  bool error3;
  bool inside;
  bool conformity;
  double energy;
  double start;
  double u;
  double v;
  SPoint2 val;
  GFace* gf;
  DocRecord* pointer;
  wrapper* w;
  MElementOctree* octree;
  lpcvt obj;
  std::vector<SVector3> gradients;
  	
  w = static_cast<wrapper*>(ptr);	
  p = w->get_p();
  dimension = w->get_dimension();
  gf = w->get_face();
  iteration = w->get_iteration();
  max = w->get_max();
  start = w->get_start();
  pointer = w->get_triangulator();
  octree = w->get_octree();
  num = pointer->numPoints;
  gradients.resize(num);
  error1 = 0;
  error2 = 0;
  error3 = 0;
	
  index = 0;
  for(i=0;i<num;i++){
	if(obj.interior(*pointer,gf,i)){
	  u = x[index];
	  v = x[index + dimension/2];
	  inside = domain_search(octree,u,v);
	  if(!inside) error1 = 1;
	  pointer->points[i].where.h = u;
	  pointer->points[i].where.v = v;
	  pointer->points[i].identificator = index;
	  index++;
	}
  }

  if(iteration>=max){
    error2 = 1;
  }
	
  if(!error1 && !error2){
    pointer->Voronoi();
	pointer->build_edges();
	conformity = pointer->delaunay_conformity(gf);
	if(!conformity) error3 = 1;
	pointer->clear_edges();
	if(!error3){
      val = obj.seed(*pointer,gf);
      pointer->concave(val.x(),val.y(),gf);
      obj.clip_cells(*pointer,gf);
      obj.swap();
	  obj.compute_parameters(gf,p);
      obj.get_gauss();
      obj.eval(*pointer,gradients,energy,p);
      func = energy;
	}
  }
	
  if(error1 || error2 || error3){
	energy = 1000000000.0;
	for(i=0;i<num;i++){
	  gradients[i] = SVector3(0.0,0.0,0.0);
	}
	func = energy;
  }

  if(error1){
    printf("Vertices outside domain.\n");
  }
	
  if(error2){
    printf("Oscillations.\n");
  }
	
  if(error3){
    printf("Boundary intersection.\n");
  }	
	
  if(start>0.0){
    printf("%d %.3f\n",iteration,100.0*(start-energy)/start);
  }
  else if(!error1 && !error2 && !error3){
    w->set_start(energy);
  }
  w->set_iteration(iteration+1);
  
  for(i=0;i<num;i++){
    if(obj.interior(*pointer,gf,i)){
	  identificator = pointer->points[i].identificator;
	  grad[identificator] = gradients[i].x();
	  grad[identificator + dimension/2] = gradients[i].y();
	}
  }	
}

bool domain_search(MElementOctree* octree,double x,double y){
  MElement* element;
	
  element = (MElement*)octree->find(x,y,0.0,2,true);
  if(element!=NULL) return 1;
  else return 0;
}



/****************class smoothing****************/

smoothing::smoothing(int param1,int param2){
  ITER_MAX = param1;
  NORM = param2;
}

void smoothing::optimize_face(GFace* gf){
  std::set<MVertex*> all;

  // get all the points of the face ...
  for (unsigned int i = 0; i < gf->getNumMeshElements(); i++){
    MElement *e = gf->getMeshElement(i);
    for (int j = 0;j<e->getNumVertices(); j++){
      MVertex *v = e->getVertex(j);
      //if (v->onWhat()->dim() < 2){
	all.insert(v);
	//}
    }
  }

  backgroundMesh::set(gf);	

  // Create a triangulator
  DocRecord triangulator(all.size());
  
  Range<double> du = gf->parBounds(0) ;
  Range<double> dv = gf->parBounds(1) ;

  const double LC2D = sqrt((du.high()-du.low())*(du.high()-du.low()) +
                           (dv.high()-dv.low())*(dv.high()-dv.low()));  

  //printf("Lloyd on face %d %d elements %d nodes LC %g\n", gf->tag(),
  //       gf->getNumMeshElements(), (int)all.size(), LC2D);

  int i = 0;
  for (std::set<MVertex*>::iterator it = all.begin(); it != all.end(); ++it){
    SPoint2 p;
    bool success = reparamMeshVertexOnFace(*it, gf, p);
    if (!success) {
      Msg::Error("Impossible to apply Lloyd to model face %d",gf->tag());
      Msg::Error("A mesh vertex cannot be reparametrized");
      return;
    }
    double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
      (double)RAND_MAX;
    double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
      (double)RAND_MAX;
    triangulator.x(i) = p.x() + XX;
    triangulator.y(i) = p.y() + YY;
    triangulator.data(i++) = (*it);
  }
 
  // compute the Voronoi diagram
  triangulator.Voronoi();
  //printf("hullSize = %d\n",triangulator.hullSize());
  triangulator.makePosView("LloydInit.pos");
  //triangulator.printMedialAxis("medialAxis.pos");
	
  int exponent;
  int num_interior;
  int index;
  double epsg;
  double epsf;
  double epsx;
  lpcvt obj;
  double initial_conditions[2*triangulator.numPoints];
  alglib::ae_int_t maxits;
  alglib::minlbfgsstate state;
  alglib::minlbfgsreport rep;
  alglib::real_1d_array x;
  wrapper w;
  MElementOctree* octree;
  
  exponent = NORM;
  epsg = 0;
  epsf = 0;
  epsx = 0;
  maxits = ITER_MAX;
	
  num_interior = 0;
  for(int i=0;i<triangulator.numPoints;i++){
   	if(obj.interior(triangulator,gf,i)){
	  num_interior++;
	}
  }

  index = 0;
  for(int i=0;i<triangulator.numPoints;i++){
	if(obj.interior(triangulator,gf,i)){
	  initial_conditions[index] = triangulator.points[i].where.h;
	  initial_conditions[index+num_interior] = triangulator.points[i].where.v;
	  index++;
	}
  }
	
  x.setcontent(2*num_interior,initial_conditions);

  octree = backgroundMesh::current()->get_octree();	
	
  w.set_p(exponent);
  w.set_dimension(2*num_interior);
  w.set_face(gf);
  w.set_max(2*ITER_MAX);
  w.set_triangulator(&triangulator);
  w.set_octree(octree);

  if(num_interior>1){
    minlbfgscreate(2*num_interior,4,x,state);
    minlbfgssetcond(state,epsg,epsf,epsx,maxits);
    minlbfgsoptimize(state,callback,NULL,&w);
    minlbfgsresults(state,x,rep);
  }

  /*lpcvt obj2;
  SPoint2 val = obj2.seed(triangulator,gf);
  triangulator.concave(val.x(),val.y(),gf);
  obj2.clip_cells(triangulator,gf);
  obj2.swap();
  obj2.compute_parameters(gf,exponent);
  obj2.get_gauss();
  obj2.write(triangulator,gf,6);*/	
	
  index = 0;
  for(i=0;i<triangulator.numPoints;i++){
	if(obj.interior(triangulator,gf,i)){
	  triangulator.points[i].where.h = x[index];
	  triangulator.points[i].where.v = x[index + num_interior];
	  index++;
	}
  }
  triangulator.Voronoi();	
	
  // now create the vertices
  std::vector<MVertex*> mesh_vertices;
  for (int i=0; i<triangulator.numPoints;i++){
    // get the ith vertex
    PointRecord &pt = triangulator.points[i];
    MVertex *v = (MVertex*)pt.data;
    if (v->onWhat() == gf && !triangulator.onHull(i)){
      GPoint gp = gf->point (pt.where.h,pt.where.v);
      MFaceVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
      mesh_vertices.push_back(v);
    }
  }

  // destroy the mesh
  deMeshGFace killer;
  killer(gf);
  
  // put all additional vertices in the list of
  // vertices
  gf->additionalVertices = mesh_vertices;
  // remesh the face with all those vertices in
  Msg::Info("Lloyd remeshing of face %d ", gf->tag());
  meshGFace mesher;
  mesher(gf);
  // assign those vertices to the face internal vertices
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(),
                           gf->additionalVertices.begin(),  
                           gf->additionalVertices.end());  
  // clear the list of additional vertices
  gf->additionalVertices.clear();  
}

void smoothing::optimize_model(){
  GFace*gf;
  GModel*model = GModel::current();
  GModel::fiter it;
	
  for(it=model->firstFace();it!=model->lastFace();it++)
  {
    gf = *it;
	if(gf->getNumMeshElements()>0 && gf->geomType()==GEntity::CompoundSurface){
	  optimize_face(gf);
	  recombineIntoQuads(gf,1,1);
	}
  }
}



/****************class lpcvt****************/

lpcvt::lpcvt(){}

lpcvt::~lpcvt(){}

double lpcvt::angle(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double x1,x2;
  double y1,y2;
  double product;
  double norm1,norm2;
  double angle;
  x1 = p2.x() - p1.x();
  y1 = p2.y() - p1.y();
  x2 = p3.x() - p1.x();
  y2 = p3.y() - p1.y();
  norm1 = sqrt(x1*x1 + y1*y1);
  norm2 = sqrt(x2*x2 + y2*y2);
  product = x1*x2 + y1*y2;
  angle = product/(norm1*norm2);
  angle = 180.0*myacos(angle)/M_PI;
  return angle;	
}

SVector3 lpcvt::normal(SPoint2 p1,SPoint2 p2){
  double x;
  double y;
  SVector3 val;
  x = p2.x() - p1.x();
  y = p2.y() - p1.y();
  val = SVector3(-y,x,0.0);
  return val;
}

SPoint2 lpcvt::mid(SPoint2 p1,SPoint2 p2){
  double x;
  double y;
  x = 0.5*(p1.x() + p2.x());
  y = 0.5*(p1.y() + p2.y());
  return SPoint2(x,y);
}

bool lpcvt::same_side(SPoint2 p1,SPoint2 p2,SPoint2 p3,SPoint2 p4){
  double x1,y1;
  double x2,y2;
  double x3,y3;
  double product1;
  double product2;
  x1 = p2.x()-p1.x();
  y1 = p2.y()-p1.y();
  x2 = p3.x()-p1.x();
  y2 = p3.y()-p1.y();
  x3 = p4.x()-p1.x();
  y3 = p4.y()-p1.y();
  product1 = x2*y1 - x1*y2;
  product2 = x3*y1 - x1*y3;
  if(product1>0.0 && product2>0.0){
    return 1;
  }
  else if(product1<0.0 && product2<0.0){
    return 1;
  }
  else return 0;
}

bool lpcvt::interior(DocRecord& triangulator,GFace* gf,int index){
  PointRecord& temp = triangulator.points[index];
  MVertex* vertex = (MVertex*)temp.data;
  if(vertex->onWhat()==gf && !triangulator.onHull(index)){
    return 1;
  }
  else return 0;
}

bool lpcvt::interior(DocRecord& triangulator,segment s1,segment s2,double angle,SPoint2 p){
  SPoint2 p1,p2,p3,p4;
  SPoint2 reference1,reference2;
  bool condition1,condition2;
  p1 = convert(triangulator,s1.get_index1());
  p2 = convert(triangulator,s1.get_index2());
  p3 = convert(triangulator,s2.get_index1());
  p4 = convert(triangulator,s2.get_index2());
  reference1 = convert(triangulator,s1.get_reference());
  reference2 = convert(triangulator,s2.get_reference());
  condition1 = same_side(p1,p2,reference1,p);
  condition2 = same_side(p3,p4,reference2,p);
  if(angle>=180.0){
	if(condition1 || condition2) return 1;
	else return 0;
  }
  else{
	if(condition1 && condition2) return 1;
	else return 0;
  }
}

bool lpcvt::invisible(DocRecord& triangulator,GFace* gf,int index){
  int i;
  int num;
  int index2;
  num = triangulator._adjacencies[index].t_length;
  for(i=0;i<num;i++){
    index2 = triangulator._adjacencies[index].t[i];
	if(interior(triangulator,gf,index2)){
	  return 0;
	}
  }
  return 1;
}

bool lpcvt::real(DocRecord& triangulator,int index1,int index2,int index3){
  return triangulator.contain(index1,index2,index3);
}

double lpcvt::triangle_area(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double area;
  double x1,y1;
  double x2,y2;
  x1 = p2.x() - p1.x();
  y1 = p2.y() - p1.y();
  x2 = p3.x() - p1.x();
  y2 = p3.y() - p1.y();
  area = 0.5*fabs(x1*y2 - x2*y1);
  return area;
}

bool lpcvt::sliver(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double area;
  double e;
  e = 0.000000001;
  area = triangle_area(p1,p2,p3);
  if(area<e) return 1;
  else return 0;
}

SPoint2 lpcvt::intersection(DocRecord& triangulator,segment s1,segment s2,SPoint2 p1,SPoint2 p2,bool &flag,SVector3& vec,segment& s){
  bool flag1;
  bool flag2;
  SPoint2 p3;
  SPoint2 p4;
  SPoint2 p5;
  SPoint2 p6;
  SPoint2 val1;
  SPoint2 val2;
  p3 = convert(triangulator,s1.get_index1());
  p4 = convert(triangulator,s1.get_index2());
  p5 = convert(triangulator,s2.get_index1());
  p6 = convert(triangulator,s2.get_index2());
  val1 = intersection(p3,p4,p1,p2,flag1);
  val2 = intersection(p5,p6,p1,p2,flag2);
  if(flag1){
	flag = 1;
	vec = normal(p3,p4);
	s = s1;
	return val1;
  }
  else if(flag2){
	flag = 1;
	vec = normal(p5,p6);
	s = s2;
	return val2;
  }
  else{
	flag = 0;
	vec = SVector3(0.0,0.0,0.0);
	s = segment(-1,-1,-1);
	return SPoint2(0.0,0.0);
  }
}

SPoint2 lpcvt::intersection(SPoint2 p1,SPoint2 p2,SPoint2 p3,SPoint2 p4,bool& flag){
  double x1,y1;
  double x2,y2;
  double x3,y3;
  double x4,y4;
  double ua,ub;
  double num_ua;
  double num_ub;
  double denom;
  double e;
  x1 = p1.x();
  y1 = p1.y();
  x2 = p2.x();
  y2 = p2.y();
  x3 = p3.x();
  y3 = p3.y();
  x4 = p4.x();
  y4 = p4.y();
  e = 0.00000000001;
  denom = (y4-y3)*(x2-x1) - (x4-x3)*(y2-y1);
  if(fabs(denom)<e){
    flag = 0;
	return SPoint2(0.0,0.0);
  }
  num_ua = (x4-x3)*(y1-y3) - (y4-y3)*(x1-x3);
  num_ub = (x2-x1)*(y1-y3) - (y2-y1)*(x1-x3);
  ua = num_ua/denom;
  ub = num_ub/denom;
  if(ua<=1.0 && ua>=0.0 && ub<=1.0 && ub>=0.0){
    flag = 1;
	return SPoint2(x1+ua*(x2-x1),y1+ua*(y2-y1));
  }
  else{
    flag = 0;
	return SPoint2(0.0,0.0);
  }
}

SPoint2 lpcvt::convert(DocRecord& triangulator,int index){
  SPoint2 p;
  double _p[2] = {triangulator.points[index].where.h,triangulator.points[index].where.v};
  p = SPoint2(_p[0],_p[1]);
  return p;
}

SPoint2 lpcvt::circumcircle(DocRecord& triangulator,int index1,int index2,int index3){
  double _C[2];
  SPoint2 C;
  double _x1[2] = {triangulator.points[index1].where.h,triangulator.points[index1].where.v};
  double _x2[2] = {triangulator.points[index2].where.h,triangulator.points[index2].where.v};
  double _x3[2] = {triangulator.points[index3].where.h,triangulator.points[index3].where.v};
  circumCenterXY(_x1,_x2,_x3,_C);
  C = SPoint2(_C[0],_C[1]);
  return C;
}

SPoint2 lpcvt::seed(DocRecord& triangulator,GFace* gf){
  int i;
  int j;
  int num;
  int index1;
  int index2;
  double x,y;
  SPoint2 x0,x1,x2;
		
  for(i=0;i<triangulator.numPoints;i++){
    if(interior(triangulator,gf,i)){
	  num = triangulator._adjacencies[i].t_length;
	  for(j=0;j<num;j++){
	    index1 = triangulator._adjacencies[i].t[j];
		index2 = triangulator._adjacencies[i].t[(j+1)%num];
		x0 = convert(triangulator,i);
		x1 = convert(triangulator,index1);
		x2 = convert(triangulator,index2);
		x = (x0.x() + x1.x() + x2.x())/3.0;
		y = (x0.y() + x1.y() + x2.y())/3.0;
		return SPoint2(x,y);
	  }
	}
  }
  return SPoint2(0.0,0.0);
}

void lpcvt::step1(DocRecord& triangulator,GFace* gf){
  int i;
  int j;
  int num;
  int index1,index2,index3;
  bool ok_triangle1,ok_triangle2;
  SPoint2 x0,x1,x2,x3;
  
  borders.resize(triangulator.numPoints);
  angles.resize(triangulator.numPoints);
  for(i=0;i<triangulator.numPoints;i++){
	angles[i] = 0.0;
  }
  temp.resize(triangulator.numPoints);
  
  for(i=0;i<triangulator.numPoints;i++){
    if(!interior(triangulator,gf,i) && !invisible(triangulator,gf,i)){
	  num = triangulator._adjacencies[i].t_length;
	  for(j=0;j<num;j++){
        index1 = triangulator._adjacencies[i].t[j];
	    index2 = triangulator._adjacencies[i].t[(j+1)%num];
	    index3 = triangulator._adjacencies[i].t[(j+2)%num];
		x0 = convert(triangulator,i);
		x1 = convert(triangulator,index1);
		x2 = convert(triangulator,index2);
		x3 = convert(triangulator,index3);
		ok_triangle1 = real(triangulator,i,index1,index2) && !sliver(x0,x1,x2);
		ok_triangle2 = real(triangulator,i,index2,index3) && !sliver(x0,x2,x3);
		if(ok_triangle1 && !ok_triangle2){
	      borders[i].add_segment(i,index2,index1);
		}
		else if(!ok_triangle1 && ok_triangle2){
	      borders[i].add_segment(i,index2,index3);
		}
		  
		if(ok_triangle1){
		  angles[i] = angles[i] + angle(x0,x1,x2);
		}
	  }
    }
  }
}

void lpcvt::step2(DocRecord& triangulator,GFace* gf){
  int i;
  int j;
  int num;
  int index1,index2;
  SPoint2 C;
  voronoi_vertex vertex;
  for(i=0;i<triangulator.numPoints;i++){
    if(interior(triangulator,gf,i)){
	  num = triangulator._adjacencies[i].t_length;
	  for(j=0;j<num;j++){
	    index1 = triangulator._adjacencies[i].t[j];
		index2 = triangulator._adjacencies[i].t[(j+1)%num];
		C = circumcircle(triangulator,i,index1,index2);
		vertex = voronoi_vertex(C);
		vertex.set_index1(i);
		vertex.set_index2(index1);
		vertex.set_index3(index2);
		temp[i].add_vertex(vertex);
	  }
	}
  }	
}

void lpcvt::step3(DocRecord& triangulator,GFace* gf){
  int i;
  int j;
  int num;
  double angle;
  bool ok_triangle1,ok_triangle2;
  bool is_inside,is_inside1,is_inside2;
  bool flag,flag1,flag2;
  SPoint2 x0,x1,x2,x3;
  SPoint2 C,C1,C2;
  SPoint2 val;
  SPoint2 first,second,median,any;
  SVector3 vec,vecA,vecB;
  segment s,s1,s2,s3,s4;
  voronoi_vertex vertex,vertex1,vertex2,vertex3;
  for(i=0;i<triangulator.numPoints;i++){
    if(!interior(triangulator,gf,i) && !invisible(triangulator,gf,i)){
	  num = triangulator._adjacencies[i].t_length;
	  s1 = borders[i].get_segment(0);
	  s2 = borders[i].get_segment(1);
	  angle = angles[i];
	  for(j=0;j<num;j++){
	    int index1 = triangulator._adjacencies[i].t[j];
		int index2 = triangulator._adjacencies[i].t[(j+1)%num];
		int index3 = triangulator._adjacencies[i].t[(j+2)%num];
		x0 = convert(triangulator,i);
		x1 = convert(triangulator,index1);
		x2 = convert(triangulator,index2);
		x3 = convert(triangulator,index3);
		ok_triangle1 = real(triangulator,i,index1,index2) && !sliver(x0,x1,x2);
		ok_triangle2 = real(triangulator,i,index2,index3) && !sliver(x0,x2,x3);
		if(ok_triangle1 && ok_triangle2){
		  C1 = circumcircle(triangulator,i,index1,index2);
		  C2 = circumcircle(triangulator,i,index2,index3);
		  is_inside1 = interior(triangulator,s1,s2,angle,C1);
		  is_inside2 = interior(triangulator,s1,s2,angle,C2);
		  if(is_inside1 && is_inside2){
			vertex = voronoi_vertex(C1);
			vertex.set_index1(i);
			vertex.set_index2(index1);
			vertex.set_index3(index2);
			temp[i].add_vertex(vertex);
		  }
		  else if(is_inside1){
		    val = intersection(triangulator,s1,s2,C1,C2,flag,vec,s);
			vertex1 = voronoi_vertex(C1);
			vertex1.set_index1(i);
			vertex1.set_index2(index1);
			vertex1.set_index3(index2);
			vertex2 = voronoi_vertex(val);
			vertex2.set_index1(i);
			vertex2.set_index2(index2);
			vertex2.set_normal(vec);
			temp[i].add_vertex(vertex1);
			temp[i].add_vertex(vertex2);
			flag = borders[index2].add_segment(s);
			if(flag){
			  fifo.push(index2);
			}
		  }
		  else if(is_inside2){
		    val = intersection(triangulator,s1,s2,C1,C2,flag,vec,s);
			vertex1 = voronoi_vertex(x0);
			vertex1.set_duplicate(1);
			vertex2 = voronoi_vertex(val);
			vertex2.set_index1(i);
			vertex2.set_index2(index2);
			vertex2.set_normal(vec);
			temp[i].add_vertex(vertex1);
			temp[i].add_vertex(vertex2);
			flag = borders[index2].add_segment(s);
			if(flag){
			  fifo.push(index2);
			}
		  }
		  else{
			any = intersection(triangulator,s1,s2,C1,C2,flag,vec,s);
			if(flag){
			  median = mid(x0,x2);
			  first = intersection(triangulator,s1,s2,C1,median,flag,vecA,s3);
			  second = intersection(triangulator,s1,s2,C2,median,flag,vecB,s4);
			  vertex1 = voronoi_vertex(x0);
			  vertex1.set_duplicate(1);
			  vertex2 = voronoi_vertex(first);
			  vertex2.set_index1(i);
			  vertex2.set_index2(index2);
			  vertex2.set_normal(vecA);
			  vertex3 = voronoi_vertex(second);
			  vertex3.set_index1(i);
			  vertex3.set_index2(index2);
			  vertex3.set_normal(vecB);
			  temp[i].add_vertex(vertex1);
			  temp[i].add_vertex(vertex2);
			  temp[i].add_vertex(vertex3);
			  flag1 = borders[index2].add_segment(s3);
			  flag2 = borders[index2].add_segment(s4);
			  if(flag1 || flag2){
			    fifo.push(index2);
			  }
			}
		  }
		}
		else if(ok_triangle1){
		  C = circumcircle(triangulator,i,index1,index2);
		  is_inside = interior(triangulator,s1,s2,angle,C);
		  if(is_inside){
		    val = mid(x0,x2);
			vertex1 = voronoi_vertex(C);
			vertex1.set_index1(i);
			vertex1.set_index2(index1);
			vertex1.set_index3(index2);
			vertex2 = voronoi_vertex(val);
			temp[i].add_vertex(vertex1);
			temp[i].add_vertex(vertex2);
		  }	  
		}
		else if(ok_triangle2){
		  C = circumcircle(triangulator,i,index2,index3);
		  is_inside = interior(triangulator,s1,s2,angle,C);
		  if(is_inside){
		    val = mid(x0,x2);
			vertex1 = voronoi_vertex(x0);
			vertex1.set_duplicate(1);
			vertex2 = voronoi_vertex(val);
			temp[i].add_vertex(vertex1);
			temp[i].add_vertex(vertex2);
		  }
		}
	  }
    }
  }
}

void lpcvt::step4(DocRecord& triangulator,GFace* gf){
  int i;
  int j;
  int num;
  int index;
  int start;
  int opposite;
  bool flag1,flag2;
  SPoint2 val;
  SPoint2 C1,C2;
  SPoint2 p1,p2;
  voronoi_vertex vertex1,vertex2;
  segment s;
  while(!fifo.empty()){
	index = fifo.front();
	fifo.pop();
	num = temp[index].get_number_vertices();
	if(interior(triangulator,gf,index)){
	  start = 0;
	}
	else start = 2;
	for(i=start;i<borders[index].get_number_segments();i++){
	  s = borders[index].get_segment(i);
	  p1 = convert(triangulator,s.get_index1());
	  p2 = convert(triangulator,s.get_index2());
	  for(j=0;j<num;j++){
		vertex1 = temp[index].get_vertex(j);
		vertex2 = temp[index].get_vertex((j+1)%num);
		C1 = vertex1.get_point();
		C2 = vertex2.get_point();
		val = intersection(C1,C2,p1,p2,flag1);
		if(flag1){
		  if(vertex1.get_index3()!=-1){
		    opposite = vertex1.get_index3();    
		  }
		  else if(vertex1.get_index2()!=-1){
		    opposite = vertex1.get_index2();
		  }
		  else if(vertex2.get_index2()!=-1){
		    opposite = vertex2.get_index2();
		  }
		  flag2 = borders[opposite].add_segment(s);
		  if(flag2){
			fifo.push(opposite);
		  }
		}
	  }
	}
  }
}

void lpcvt::step5(DocRecord& triangulator,GFace* gf){
  int i;
  int j;
  int k;
  int num;
  int start;
  int opposite;
  bool flag;
  SPoint2 p1,p2,p3,p4,reference,val;
  SVector3 n;
  segment s;
  voronoi_vertex vertex,vertex1,vertex2;
  voronoi_cell cell;
  for(i=0;i<triangulator.numPoints;i++){
    cell.clear();
	if(interior(triangulator,gf,i)){
	  start = 0;
	}
	else start = 2;
	for(j=start;j<borders[i].get_number_segments();j++){
	  s = borders[i].get_segment(j);
	  p3 = convert(triangulator,s.get_index1());
	  p4 = convert(triangulator,s.get_index2());
	  reference = convert(triangulator,s.get_reference());
	  n = normal(p3,p4);
	  num = temp[i].get_number_vertices();
	  for(k=0;k<num;k++){
	    vertex1 = temp[i].get_vertex(k);
		vertex2 = temp[i].get_vertex((k+1)%num);
		p1 = vertex1.get_point();
		p2 = vertex2.get_point();
		if(same_side(p3,p4,reference,p1)){
		  cell.add_vertex(vertex1);
		}
		val = intersection(p1,p2,p3,p4,flag);
		if(flag){
		  if(vertex1.get_index3()!=-1){
		    opposite = vertex1.get_index3();    
		  }
		  else if(vertex1.get_index2()!=-1){
		    opposite = vertex1.get_index2();
		  }
		  else if(vertex2.get_index2()!=-1){
		    opposite = vertex2.get_index2();
		  }
		  vertex = voronoi_vertex(val);
		  vertex.set_index1(i);
		  vertex.set_index2(opposite);
		  vertex.set_normal(n);
		  cell.add_vertex(vertex);
		}
	  }
	  temp[i].clear();
	  for(k=0;k<cell.get_number_vertices();k++){
	    temp[i].add_vertex(cell.get_vertex(k));
	  }
	  cell.clear();
	}
	num = temp[i].get_number_vertices();
	for(j=0;j<num;j++){
	  vertex = voronoi_vertex(convert(triangulator,i));
	  vertex.set_index1(i);
	  vertex1 = temp[i].get_vertex(j);
	  vertex2 = temp[i].get_vertex((j+1)%num);
	  if(!vertex1.get_duplicate() && !vertex2.get_duplicate()){
	    clipped.push_back(voronoi_element(vertex,vertex1,vertex2));
	  }
	}
  }
}

void lpcvt::clip_cells(DocRecord& triangulator,GFace* gf){
  step1(triangulator,gf);
  step2(triangulator,gf);
  step3(triangulator,gf);
  step4(triangulator,gf);
  step5(triangulator,gf);
}

void lpcvt::clear(){
  int i;
  for(i=0;i<fifo.size();i++){
    fifo.pop();
  }
  clipped.clear();
  borders.clear();
  angles.clear();
  temp.clear();
}

double lpcvt::total_area(){
  double total;
  SPoint2 p1,p2,p3;
  voronoi_vertex v1,v2,v3;
  std::list<voronoi_element>::iterator it;
  total = 0.0;
  for(it=clipped.begin();it!=clipped.end();it++){
    v1 = it->get_v1();
    v2 = it->get_v2();
    v3 = it->get_v3();
	p1 = v1.get_point();
	p2 = v2.get_point();
	p3 = v3.get_point();
	total = total + triangle_area(p1,p2,p3);
  }
  return total;
}

void lpcvt::print_voronoi1(){
  SPoint2 p1,p2,p3;
  voronoi_vertex v1,v2,v3;
  std::list<voronoi_element>::iterator it;
  std::ofstream file("voronoi1.pos");
  file << "View \"test\" {\n";
  for(it=clipped.begin();it!=clipped.end();it++){
    v1 = it->get_v1();
	v2 = it->get_v2();
	v3 = it->get_v3();
	p1 = v1.get_point();
	p2 = v2.get_point();
	p3 = v3.get_point();
	print_segment(p2,p3,file);
  }	
  file << "};\n";
}

void lpcvt::print_voronoi2(){
  int i;
  int j;
  int num;
  SPoint2 p1,p2;
  voronoi_vertex v1,v2;
  std::ofstream file("voronoi2.pos");
  file << "View \"test\" {\n";
  for(i=0;i<temp.size();i++){
    num = temp[i].get_number_vertices();
	for(j=0;j<num;j++){
	  v1 = temp[i].get_vertex(j);
	  v2 = temp[i].get_vertex((j+1)%num);
	  p1 = v1.get_point();
	  p2 = v2.get_point();
	  print_segment(p1,p2,file);
	}
  }
  file << "};\n";
}
	
void lpcvt::print_delaunay(DocRecord& triangulator){
  int i;
  int j;
  int num;
  int index1;
  int index2;
  SPoint2 x1,x2;
  std::ofstream file("delaunay.pos");
  file << "View \"test\" {\n";
  for(i=0;i<triangulator.numPoints;i++){
    num = triangulator._adjacencies[i].t_length;
	for(j=0;j<num;j++){
	  index1 = triangulator._adjacencies[i].t[j];
	  index2 = triangulator._adjacencies[i].t[(j+1)%num];
	  if(triangulator.contain(i,index1,index2)){
		x1 = convert(triangulator,index1);
		x2 = convert(triangulator,index2);
		print_segment(x1,x2,file);
	  }
	}
  }
  file << "};\n";
}

void lpcvt::print_segment(SPoint2 p1,SPoint2 p2,std::ofstream& file){
  file << "SL (" << p1.x() << ", " << p1.y() << ", 0, "
  << p2.x() << ", " << p2.y() << ", 0){"
  << "10, 20};\n";	
}

void lpcvt::compute_parameters(GFace* gf,int p){
  double h1,h2,h3;
  double rho1,rho2,rho3;
  double k;
  double ratio;
  double angle;
  double cosinus;
  double sinus;
  SPoint2 center;
  SPoint2 p1,p2,p3;
  voronoi_vertex v1,v2,v3;
  metric m;
  std::list<voronoi_element>::iterator it;
	
  k = 1.0;	
  for(it=clipped.begin();it!=clipped.end();it++){
    v1 = it->get_v1();
	v2 = it->get_v2();
	v3 = it->get_v3();
	p1 = v1.get_point();
	p2 = v2.get_point();
	p3 = v3.get_point();
	center = SPoint2((p1.x()+p2.x()+p3.x())/3.0,(p1.y()+p2.y()+p3.y())/3.0);
	ratio = get_ratio(gf,center);
	h1 = k*backgroundMesh::current()->operator()(p1.x(),p1.y(),0.0)*ratio;
	h2 = k*backgroundMesh::current()->operator()(p2.x(),p2.y(),0.0)*ratio;
	h3 = k*backgroundMesh::current()->operator()(p3.x(),p3.y(),0.0)*ratio;
	rho1 = it->compute_rho(h1,p);
	rho2 = it->compute_rho(h2,p);
	rho3 = it->compute_rho(h3,p);
	angle = -backgroundMesh::current()->getAngle(p1.x(),p1.y(),0.0);
	cosinus = cos(angle);
	sinus = sin(angle);
	m = metric(cosinus,-sinus,sinus,cosinus);
	v1.set_rho(rho1);
	v2.set_rho(rho2);
	v3.set_rho(rho3);
	it->set_v1(v1);
	it->set_v2(v2);
	it->set_v3(v3);
	it->deriv_rho(p);
	it->set_metric(m);
  }	
}

double lpcvt::get_ratio(GFace* gf,SPoint2 point){
  double val;
  double uv[2];
  double tab[3];
	
  uv[0] = point.x();
  uv[1] = point.y();
  buildMetric(gf,uv,tab);
  val = 1.0/pow(tab[0]*tab[2]-tab[1]*tab[1],0.25);
  return val;
}

void lpcvt::write(DocRecord& triangulator,GFace* gf,int p){
  int i;
  double energy;
  SVector3 grad;
  std::vector<SVector3> gradients(triangulator.numPoints);
	
  eval(triangulator,gradients,energy,p);
	
  std::ofstream file("gradient");
	
  for(i=0;i<triangulator.numPoints;i++){
    if(interior(triangulator,gf,i)){
	  grad = gradients[i];
	  file << grad.x() << "  ";
	  file << grad.y() << "  ";
	  file << "\n";
	}
  }
}

void lpcvt::eval(DocRecord& triangulator,std::vector<SVector3>& gradients,double& energy,int p){
  int i;
  int index;
  int index1;
  int index2;
  int index3;
  SPoint2 generator;
  SPoint2 C1,C2;
  SPoint2 p1,p2,p3;
  SVector3 grad1,grad2;
  SVector3 normal;
  voronoi_vertex v1,v2,v3;
  std::list<voronoi_element>::iterator it;
	
  for(i=0;i<gradients.size();i++){
    gradients[i] = SVector3(0.0,0.0,0.0);
  }
  energy = 0.0;
	
  for(it=clipped.begin();it!=clipped.end();it++){
    v1 = it->get_v1();
	v2 = it->get_v2();
	v3 = it->get_v3();
	generator = v1.get_point();
	C1 = v2.get_point();
	C2 = v3.get_point();
	index = v1.get_index1();
	energy = energy + F(*it,p);
	gradients[index] = gradients[index] + simple(*it,p);
	grad1 = dF_dC1(*it,p);
	grad2 = dF_dC2(*it,p);
	if(v2.get_index3()!=-1){
	  index1 = v2.get_index1();
	  index2 = v2.get_index2();
	  index3 = v2.get_index3();
	  p1 = convert(triangulator,index1);
	  p2 = convert(triangulator,index2);
	  p3 = convert(triangulator,index3);
	  gradients[index1] = gradients[index1] + inner_dFdx0(grad1,C1,p1,p2,p3);
	  gradients[index2] = gradients[index2] + inner_dFdx0(grad1,C1,p2,p1,p3);
	  gradients[index3] = gradients[index3] + inner_dFdx0(grad1,C1,p3,p1,p2);
	}
	else if(v2.get_index2()!=-1){
	  index1 = v2.get_index1();
	  index2 = v2.get_index2();
	  normal = v2.get_normal();
	  p1 = convert(triangulator,index1);
	  p2 = convert(triangulator,index2);
	  gradients[index1] = gradients[index1] + boundary_dFdx0(grad1,C1,p1,p2,normal);
	  gradients[index2] = gradients[index2] + boundary_dFdx0(grad1,C1,p2,p1,normal);
	}
	if(v3.get_index3()!=-1){
	  index1 = v3.get_index1();
	  index2 = v3.get_index2();
	  index3 = v3.get_index3();
	  p1 = convert(triangulator,index1);
	  p2 = convert(triangulator,index2);
	  p3 = convert(triangulator,index3);
	  gradients[index1] = gradients[index1] + inner_dFdx0(grad2,C2,p1,p2,p3);
	  gradients[index2] = gradients[index2] + inner_dFdx0(grad2,C2,p2,p1,p3);
	  gradients[index3] = gradients[index3] + inner_dFdx0(grad2,C2,p3,p1,p2);
	}
	else if(v3.get_index2()!=-1){
	  index1 = v3.get_index1();
	  index2 = v3.get_index2();
	  normal = v3.get_normal();
	  p1 = convert(triangulator,index1);
	  p2 = convert(triangulator,index2);
	  gradients[index1] = gradients[index1] + boundary_dFdx0(grad2,C2,p1,p2,normal);
	  gradients[index2] = gradients[index2] + boundary_dFdx0(grad2,C2,p2,p1,normal);
	}
  }
}

void lpcvt::swap(){
  voronoi_vertex vertex;
  std::list<voronoi_element>::iterator it;
  for(it=clipped.begin();it!=clipped.end();it++){
	if(J(it->get_v1().get_point(),it->get_v2().get_point(),it->get_v3().get_point())<0.0){
      vertex = it->get_v3();
	  it->set_v3(it->get_v2());
	  it->set_v2(vertex);
	}
  }
}

void lpcvt::get_gauss(){
  int order;
  order = 8;
  gaussIntegration::getTriangle(order,gauss_points,gauss_weights);
  gauss_num = gauss_points.size1();
}

double lpcvt::F(voronoi_element element,int p){
  int i;
  double u;
  double v;
  double x;
  double y;
  double energy;
  double weight;
  double rho;
  SPoint2 point,generator,C1,C2;
  voronoi_vertex v1,v2,v3;
  metric m;

  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  energy = 0.0;
  m = element.get_metric();
	
  for(i=0;i<gauss_num;i++){
	u = gauss_points(i,0);
	v = gauss_points(i,1);
    x = Tx(u,v,generator,C1,C2);
	y = Ty(u,v,generator,C1,C2);
	point = SPoint2(x,y);
	weight = gauss_weights(i,0);
	rho = element.get_rho(u,v);
	energy = energy + weight*rho*f(generator,point,m,p);
  }
  energy = J(generator,C1,C2)*energy;
  return energy;
}

SVector3 lpcvt::simple(voronoi_element element,int p){
  int i;
  double u;
  double v;
  double x;
  double y;
  double comp_x;
  double comp_y;
  double weight;
  double rho;
  double jacobian;
  SPoint2 point,generator,C1,C2;
  voronoi_vertex v1,v2,v3;
  metric m;

  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  jacobian = J(generator,C1,C2);
  m = element.get_metric();
  
  for(i=0;i<gauss_num;i++){
	u = gauss_points(i,0);
	v = gauss_points(i,1);
    x = Tx(u,v,generator,C1,C2);
	y = Ty(u,v,generator,C1,C2);
	point = SPoint2(x,y);
	weight = gauss_weights(i,0);
	rho = element.get_rho(u,v);
	comp_x = comp_x + weight*rho*df_dx(generator,point,m,p);
	comp_y = comp_y + weight*rho*df_dy(generator,point,m,p);
  }
  comp_x = jacobian*comp_x;
  comp_y = jacobian*comp_y; 
  return SVector3(comp_x,comp_y,0.0);
}

SVector3 lpcvt::dF_dC1(voronoi_element element,int p){
  int i;
  double u;
  double v;
  double x;
  double y;
  double comp_x;
  double comp_y;
  double weight;
  double rho;
  double drho_dx;
  double drho_dy;
  double jacobian;
  double distance;
  SPoint2 point,generator,C1,C2;
  voronoi_vertex v1,v2,v3;
  metric m;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  jacobian = J(generator,C1,C2);
  m = element.get_metric();
	
  for(i=0;i<gauss_num;i++){
	u = gauss_points(i,0);
	v = gauss_points(i,1);
    x = Tx(u,v,generator,C1,C2);
	y = Ty(u,v,generator,C1,C2);
	point = SPoint2(x,y);
	weight = gauss_weights(i,0);
	rho = element.get_rho(u,v);
	drho_dx = element.get_drho_dx();
	drho_dy = element.get_drho_dy();
	distance = f(point,generator,m,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,m,p)*u*jacobian;
	comp_x = comp_x + weight*rho*distance*(C2.y()-generator.y());
	comp_x = comp_x + weight*drho_dx*u*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,m,p)*u*jacobian;
	comp_y = comp_y + weight*rho*distance*(generator.x()-C2.x());
	comp_y = comp_y + weight*drho_dy*u*distance*jacobian;
  }		
  return SVector3(comp_x,comp_y,0.0);
}

SVector3 lpcvt::dF_dC2(voronoi_element element,int p){
  int i;
  double u;
  double v;
  double x;
  double y;
  double comp_x;
  double comp_y;
  double weight;
  double rho;
  double drho_dx;
  double drho_dy;
  double jacobian;
  double distance;
  SPoint2 point,generator,C1,C2;
  voronoi_vertex v1,v2,v3;
  metric m;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  jacobian = J(generator,C1,C2);
  m = element.get_metric();
	
  for(i=0;i<gauss_num;i++){
	u = gauss_points(i,0);
	v = gauss_points(i,1);
	x = Tx(u,v,generator,C1,C2);
	y = Ty(u,v,generator,C1,C2);
	point = SPoint2(x,y);
	weight = gauss_weights(i,0);
	rho = element.get_rho(u,v);
	drho_dx = element.get_drho_dx();
	drho_dy = element.get_drho_dy();
	distance = f(point,generator,m,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,m,p)*v*jacobian;
	comp_x = comp_x + weight*rho*distance*(generator.y()-C1.y());
	comp_x = comp_x + weight*drho_dx*v*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,m,p)*v*jacobian;
	comp_y = comp_y + weight*rho*distance*(C1.x()-generator.x());
	comp_y = comp_y + weight*drho_dy*v*distance*jacobian;
  }		
  return SVector3(comp_x,comp_y,0.0);
}

double lpcvt::f(SPoint2 p1,SPoint2 p2,metric m,int p){
  double x1;
  double y1;
  double x2;
  double y2;
  double val1;
  double val2;
  double val;
  double a;
  double b;
  double c;
  double d;
  
  x1 = p1.x();
  y1 = p1.y();
  x2 = p2.x();
  y2 = p2.y();
  a = m.get_a();
  b = m.get_b();
  c = m.get_c();
  d = m.get_d();
  val1 = a*x1 + b*y1 - a*x2 - b*y2;
  val2 = c*x1 + d*y1 - c*x2 - d*y2;
  val = pow_int(val1,p) + pow_int(val2,p);
  return val;
}

double lpcvt::df_dx(SPoint2 p1,SPoint2 p2,metric m,int p){
  double x1;
  double y1;
  double x2;
  double y2;
  double val1;
  double val2;
  double val;
  double a;
  double b;
  double c;
  double d;
  
  x1 = p1.x();
  y1 = p1.y();
  x2 = p2.x();
  y2 = p2.y();
  a = m.get_a();
  b = m.get_b();
  c = m.get_c();
  d = m.get_d();
  val1 = a*x1 + b*y1 - a*x2 - b*y2;
  val2 = c*x1 + d*y1 - c*x2 - d*y2;
  val = ((double)p)*pow_int(val1,p-1)*a + ((double)p)*pow_int(val2,p-1)*c;
  return val;
}

double lpcvt::df_dy(SPoint2 p1,SPoint2 p2,metric m,int p){
  double x1;
  double y1;
  double x2;
  double y2;
  double val1;
  double val2;
  double val;
  double a;
  double b;
  double c;
  double d;
  
  x1 = p1.x();
  y1 = p1.y();
  x2 = p2.x();
  y2 = p2.y();
  a = m.get_a();
  b = m.get_b();
  c = m.get_c();
  d = m.get_d();
  val1 = a*x1 + b*y1 - a*x2 - b*y2;
  val2 = c*x1 + d*y1 - c*x2 - d*y2;
  val = ((double)p)*pow_int(val1,p-1)*b + ((double)p)*pow_int(val2,p-1)*d;
  return val;
}

double lpcvt::Tx(double u,double v,SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = (1.0-u-v)*p1.x() + u*p2.x() + v*p3.x();
  return val;
}

double lpcvt::Ty(double u,double v,SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = (1.0-u-v)*p1.y() + u*p2.y() + v*p3.y();
  return val;
}

double lpcvt::J(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = (p2.x()-p1.x())*(p3.y()-p1.y()) - (p3.x()-p1.x())*(p2.y()-p1.y());
  return val;
}

SVector3 lpcvt::inner_dFdx0(SVector3 dFdC,SPoint2 C,SPoint2 x0,SPoint2 x1,SPoint2 x2){
  double det;
  double A[2][2];
  double B[2][2];
  double M[2][2];
  det = (x1.x()-x0.x())*(x2.y()-x0.y()) - (x1.y() - x0.y())*(x2.x() - x0.x());
  A[0][0] = (x2.y() - x0.y())/det;
  A[0][1] = -(x1.y() - x0.y())/det;
  A[1][0] = -(x2.x() - x0.x())/det; 
  A[1][1] = (x1.x() - x0.x())/det;
  B[0][0] = C.x() - x0.x();
  B[0][1] = C.y() - x0.y();
  B[1][0] = C.x() - x0.x();
  B[1][1] = C.y() - x0.y();
  M[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
  M[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
  M[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
  M[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
  return SVector3(dFdC.x()*M[0][0]+dFdC.y()*M[1][0],dFdC.x()*M[0][1]+dFdC.y()*M[1][1],0.0);
}

SVector3 lpcvt::boundary_dFdx0(SVector3 dFdC,SPoint2 C,SPoint2 x0,SPoint2 x1,SVector3 normal){
  fullMatrix<double> A(2,2);
  fullMatrix<double> B(2,2);
  fullMatrix<double> M(2,2);
  fullMatrix<double> _dFdC(1,2);
  fullMatrix<double> _val(1,2);
  A(0,0) = x1.x() - x0.x(); 
  A(0,1) = x1.y() - x0.y();
  A(1,0) = normal.x(); 
  A(1,1) = normal.y();
  A.invertInPlace();
  B(0,0) = C.x() - x0.x();
  B(0,1) = C.y() - x0.y();
  B(1,0) = 0.0;
  B(1,1) = 0.0;
  A.mult_naive(B,M);
  _dFdC(0,0) = dFdC.x();
  _dFdC(0,1) = dFdC.y();
  _dFdC.mult_naive(M,_val);
  return SVector3(_val(0,0),_val(0,1),0.0);	
}



/****************class metric****************/

metric::metric(double new_a,double new_b,double new_c,double new_d){
  a = new_a;
  b = new_b;
  c = new_c;
  d = new_d;
}

metric::metric(){}

metric::~metric(){}

void metric::set_a(double new_a){
  a = new_a;
}

void metric::set_b(double new_b){
  b = new_b;
}

void metric::set_c(double new_c){
  c = new_c;
}

void metric::set_d(double new_d){
  d = new_d;
}

double metric::get_a(){
  return a;
}

double metric::get_b(){
  return b;
}

double metric::get_c(){
  return c;
}

double metric::get_d(){
  return d;
}



/****************class voronoi_vertex****************/

voronoi_vertex::voronoi_vertex(SPoint2 new_point){
  point = new_point;
  index1 = -1;
  index2 = -1;
  index3 = -1;
  normal = SVector3(0.0,0.0,0.0);
  duplicate = 0;
}

voronoi_vertex::voronoi_vertex(){}

voronoi_vertex::~voronoi_vertex(){}

SPoint2 voronoi_vertex::get_point(){
  return point;
}

int voronoi_vertex::get_index1(){
  return index1;
}

int voronoi_vertex::get_index2(){
  return index2;
}

int voronoi_vertex::get_index3(){
  return index3;
}

SVector3 voronoi_vertex::get_normal(){
  return normal;
}

bool voronoi_vertex::get_duplicate(){
  return duplicate;
}

double voronoi_vertex::get_rho(){
  return rho;
}

void voronoi_vertex::set_point(SPoint2 new_point){
  point = new_point;
}

void voronoi_vertex::set_index1(int new_index1){
  index1 = new_index1;
}

void voronoi_vertex::set_index2(int new_index2){
  index2 = new_index2;
}

void voronoi_vertex::set_index3(int new_index3){
  index3 = new_index3;
}

void voronoi_vertex::set_normal(SVector3 new_normal){
  normal = new_normal;
}

void voronoi_vertex::set_duplicate(bool new_duplicate){
  duplicate = new_duplicate;
}

void voronoi_vertex::set_rho(double new_rho){
  rho = new_rho;
}



/****************class voronoi_element****************/

voronoi_element::voronoi_element(voronoi_vertex new_v1,voronoi_vertex new_v2,voronoi_vertex new_v3){
  v1 = new_v1;
  v2 = new_v2;
  v3 = new_v3;
}

voronoi_element::voronoi_element(){}

voronoi_element::~voronoi_element(){}

voronoi_vertex voronoi_element::get_v1(){
  return v1;
}

voronoi_vertex voronoi_element::get_v2(){
  return v2;
}

voronoi_vertex voronoi_element::get_v3(){
  return v3;
}

double voronoi_element::get_rho(double u,double v){
  double rho1;
  double rho2;
  double rho3;
  double rho;
	
  rho1 = v1.get_rho();
  rho2 = v2.get_rho();
  rho3 = v3.get_rho();
  rho = rho1*(1.0-u-v) + rho2*u + rho3*v;
  return rho;
}

double voronoi_element::get_drho_dx(){
  return drho_dx;
}

double voronoi_element::get_drho_dy(){
  return drho_dy;
}

metric voronoi_element::get_metric(){
  return m;
}

void voronoi_element::set_v1(voronoi_vertex new_v1){
  v1 = new_v1;
}

void voronoi_element::set_v2(voronoi_vertex new_v2){
  v2 = new_v2;
}

void voronoi_element::set_v3(voronoi_vertex new_v3){
  v3 = new_v3;
}

void voronoi_element::set_metric(metric new_m){
  m = new_m;
}

void voronoi_element::deriv_rho(int p){
  double rho1;
  double rho2;
  double rho3;
  double a;
  double b;
  double c;
  double d;
  double jacobian;
  double drho_du;
  double drho_dv;
  double du_dx;
  double dv_dx;
  double du_dy;
  double dv_dy;
  SPoint2 p1;
  SPoint2 p2;
  SPoint2 p3;
	
  rho1 = v1.get_rho();
  rho2 = v2.get_rho();
  rho3 = v3.get_rho();
  p1 = v1.get_point();
  p2 = v2.get_point();
  p3 = v3.get_point();
  a = p2.x() - p1.x();
  b = p3.x() - p1.x();
  c = p2.y() - p1.y();
  d = p3.y() - p1.y();
  jacobian = a*d-b*c;
  drho_du = rho2-rho1;
  drho_dv = rho3-rho1;
  du_dx = d/jacobian;
  dv_dx = -c/jacobian;
  du_dy = -b/jacobian;
  dv_dy = a/jacobian;
  drho_dx = drho_du*du_dx + drho_dv*dv_dx;
  drho_dy = drho_du*du_dy + drho_dv*dv_dy;
}

double voronoi_element::compute_rho(double h,int p){
  double rho;
  rho = pow_int(1.0/h,p+1);
  return rho;
}



/****************class voronoi_cell****************/

voronoi_cell::voronoi_cell(){}

voronoi_cell::~voronoi_cell(){}

int voronoi_cell::get_number_vertices(){
  return vertices.size();
}

voronoi_vertex voronoi_cell::get_vertex(int index){
  return vertices[index];
}

void voronoi_cell::add_vertex(voronoi_vertex vertex){
  vertices.push_back(vertex);
}

void voronoi_cell::clear(){
  vertices.clear();
}



/****************class segment****************/

segment::segment(int new_index1,int new_index2,int new_reference){
  index1 = new_index1;
  index2 = new_index2;
  reference = new_reference;
}

segment::segment(){}

segment::~segment(){}

int segment::get_index1(){
  return index1;
}

int segment::get_index2(){
  return index2;
}

int segment::get_reference(){
  return reference;
}

void segment::set_index1(int new_index1){
  index1 = new_index1;
}

void segment::set_index2(int new_index2){
  index2 = new_index2;
}

void segment::set_reference(int new_reference){
  reference = new_reference;
}

bool segment::equal(int index3,int index4){
  if(index1==index3 && index2==index4){
    return 1;
  }
  else if(index1==index4 && index2==index3){
    return 1;
  }
  else return 0;
}



/****************class list_segment****************/

segment_list::segment_list(){}

segment_list::~segment_list(){}

int segment_list::get_number_segments(){
  return segments.size();
}

segment segment_list::get_segment(int index){
  return segments[index];
}

bool segment_list::add_segment(int index1,int index2,int reference){
  int i;
  for(i=0;i<segments.size();i++){
	if(segments[i].equal(index1,index2)) return 0;
  }
  segments.push_back(segment(index1,index2,reference));
  return 1;
}

bool segment_list::add_segment(segment s){
  return add_segment(s.get_index1(),s.get_index2(),s.get_reference());
}



/****************class wrapper****************/

wrapper::wrapper(){
  iteration = 0;
  start = -100.0;
}

wrapper::~wrapper(){}

int wrapper::get_p(){
  return p;
}

void wrapper::set_p(int new_p){
  p = new_p;
}

int wrapper::get_dimension(){
  return dimension;
}

void wrapper::set_dimension(int new_dimension){
  dimension = new_dimension;
}

GFace* wrapper::get_face(){
  return gf;
}

void wrapper::set_face(GFace* new_gf){
  gf = new_gf;
}

int wrapper::get_iteration(){
  return iteration;
}

void wrapper::set_iteration(int new_iteration){
  iteration = new_iteration;
}

int wrapper::get_max(){
  return max;
}

void wrapper::set_max(int new_max){
  max = new_max;
}

double wrapper::get_start(){
  return start;
}

void wrapper::set_start(double new_start){
  start = new_start;
}

DocRecord* wrapper::get_triangulator(){
  return triangulator;
}

void wrapper::set_triangulator(DocRecord* new_triangulator){
  triangulator = new_triangulator;
}

MElementOctree* wrapper::get_octree(){
  return octree;
}

void wrapper::set_octree(MElementOctree* new_octree){
  octree = new_octree;
}

#endif
