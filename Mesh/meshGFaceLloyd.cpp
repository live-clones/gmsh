#include <set>
#include <fstream>

#include "GmshConfig.h"
#if defined(HAVE_BFGS)

#include "meshGFaceLloyd.h"
#include "DivideAndConquer.h"
#include "GFace.h"
#include "MElement.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "Context.h"
#include "meshGFace.h"
#include "BackgroundMesh.h"


/****************fonction callback****************/
/*************************************************/
class gradientCallback {
  DocRecord *_doc;
  int _p;
  GFace *_face;
  int _dimension;
  std::vector<SVector3> _gradients, _areaCentroids;
  std::vector<double> _energies, _areas;

  public :
  gradientCallback(DocRecord *doc, GFace *face, int dimension, int p){
    _doc = doc;
    _face = face;
    _dimension = dimension;
    _p = p;
    _gradients.resize(doc->numPoints);
    _areaCentroids.resize(doc->numPoints);
    _energies.resize(doc->numPoints);
    _areas.resize(doc->numPoints);
  }

  void compute(const alglib::real_1d_array& x,double& func,alglib::real_1d_array& grad)
  {
    int index = 0;
    for (int i = 0; i < _doc->numPoints; ++i) {
      PointRecord &pt = _doc->points[i];
      MVertex *v = (MVertex*) pt.data;
      if(v->onWhat() == _face && ! _doc->onHull(i)){
        _doc->points[i].where.h = x[index];
        _doc->points[i].where.v = x[index + _dimension/2];
        _doc->points[i].identificator = index;
        index++;
      }
    }
    _doc->Voronoi();
    lloydAlgorithm lloyd;
    lloyd.eval(*_doc, _face, _gradients, _energies, _areaCentroids, _areas, _p);
    func = lloyd.total_energy(_energies);
    printf("%f\n",1E18*func);

    for(int i = 0; i < _doc->numPoints; ++i){
      PointRecord &pt = _doc->points[i];
      MVertex *v = (MVertex*)pt.data;
      if(v->onWhat() == _face && !_doc->onHull(i)){
        int identificator = _doc->points[i].identificator;
        grad[identificator] = _gradients[i].x();
        grad[identificator + _dimension/2] = _gradients[i].y();
      }
    }	
  }

  static void Callback(const alglib::real_1d_array& x,double& func,alglib::real_1d_array& grad, void* ptr)
  {
    gradientCallback *cb = static_cast<gradientCallback *> (ptr);
    cb->compute(x, func, grad);
  }
};



/****************fonctions principales****************/
/*****************************************************/

void lloydAlgorithm::operator () (GFace *gf)
{
  std::set<MVertex*> all;

  for (unsigned int i = 0; i < gf->getNumMeshElements(); i++){
    MElement *e = gf->getMeshElement(i);
    for (int j = 0;j<e->getNumVertices(); j++){
      MVertex *v = e->getVertex(j);
	  all.insert(v);
    }
  }

  DocRecord triangulator(all.size());
  
  Range<double> du = gf->parBounds(0) ;
  Range<double> dv = gf->parBounds(1) ;

  const double LC2D = sqrt((du.high()-du.low())*(du.high()-du.low()) +
                           (dv.high()-dv.low())*(dv.high()-dv.low()));  

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
 
  triangulator.Voronoi();
  triangulator.initialize();
  int index,number,count,max;
  bool flag;
  number = 0;
  count = 0;
  max = 1000;
  for(int i=0;i<max;i++)
  {
    if(count>=number) break;
	index = (int)((triangulator.numPoints-1)*((double)rand()/(double)RAND_MAX));
	PointRecord& pt = triangulator.points[index];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(index)){
	  flag = triangulator.remove_point(index);
	  if(flag) count++;
	}
  }
  triangulator.remove_all();	
	
  /*triangulator.Voronoi();
  double delta;
  delta = 0.2;
  for(int i=0;i<triangulator.numPoints;i++){
    PointRecord& pt = triangulator.points[i];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  triangulator.points[i].where.h = delta + (1.0-2.0*delta)*((double)rand()/(double)RAND_MAX);
	  triangulator.points[i].where.v = delta + (1.0-2.0*delta)*((double)rand()/(double)RAND_MAX);
	}
  }*/	

  int exponent = 8;	
	
  triangulator.Voronoi();
  triangulator.makePosView("LloydInit.pos");
  	
  int num_interior;
  double initial_conditions[2*triangulator.numPoints];
  num_interior = 0;
  for(int i=0;i<triangulator.numPoints;i++){
    PointRecord& pt = triangulator.points[i];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  num_interior++;
	}
  }
  index = 0;
  for(int i=0;i<triangulator.numPoints;i++){
    PointRecord& pt = triangulator.points[i];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  initial_conditions[index] = triangulator.points[i].where.h;
	  initial_conditions[index+num_interior] = triangulator.points[i].where.v;
	  index++;
	}
  }
  alglib::real_1d_array x;
  x.setcontent(2*num_interior,initial_conditions);
  
  double epsg = 0;
  double epsf = 0;
  double epsx = 1e-4;
  alglib::ae_int_t maxits = 0;
  alglib::minlbfgsstate state;
  alglib::minlbfgsreport rep;
	
  minlbfgscreate(2*num_interior, 4, x, state);
  minlbfgssetcond(state, epsg, epsf, epsx, maxits);
  gradientCallback cb(&triangulator, gf, 2 * num_interior, exponent);
  minlbfgsoptimize(state, gradientCallback::Callback, NULL, &cb);
  minlbfgsresults(state, x, rep);
	
  index = 0;
  for(i=0;i<triangulator.numPoints;i++){
    PointRecord &pt = triangulator.points[i];
	MVertex *v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  triangulator.points[i].where.h = x[index];
	  triangulator.points[i].where.v = x[index + num_interior];
	  index++;
	}
  }
  triangulator.Voronoi();	
	
  test = 0;
  std::vector<MVertex*> mesh_vertices;
  for (int i=0; i<triangulator.numPoints;i++){
    PointRecord &pt = triangulator.points[i];
    MVertex *v = (MVertex*)pt.data;
    if (v->onWhat() == gf && !triangulator.onHull(i)){
      GPoint gp = gf->point (pt.where.h,pt.where.v);
      MFaceVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
      mesh_vertices.push_back(v);
	  test++;
    }
  }

  deMeshGFace killer;
  killer(gf);
  
  gf->additionalVertices = mesh_vertices;
  Msg::Info("Lloyd remeshing of face %d ", gf->tag());
  meshGFace mesher;
  mesher(gf);
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(),
                           gf->additionalVertices.begin(),  
                           gf->additionalVertices.end());  
  gf->additionalVertices.clear();  
}

double lloydAlgorithm::optimize(int max,int flag){
  GFace*face;
  GModel*model = GModel::current();
  GModel::fiter iterator;
  lloydAlgorithm lloyd(max,flag);
  for(iterator = model->firstFace();iterator != model->lastFace();iterator++)
  {
    face = *iterator;
	if(face->getNumMeshElements() > 0){
	  lloyd(face);
	  recombineIntoQuads(face,1,1);
	}
  }
  return lloyd.test;
}



/****************Calcul du gradient****************/
/**************************************************/

void lloydAlgorithm::eval(DocRecord& triangulator,GFace* gf,std::vector<SVector3>& gradients,std::vector<double>& energies,std::vector<SVector3>& area_centroids,std::vector<double>& areas,int p)
{
  int i;
  
  for(i=0;i<triangulator.numPoints;i++){
    gradients[i] = SVector3(0.0,0.0,0.0);
	energies[i] = 0.0;
    area_centroids[i] = SVector3(0.0,0.0,0.0);
	areas[i] = 0.0;
  }
	
  for(i=0;i<triangulator.numPoints;i++){
    PointRecord &pt = triangulator.points[i];
	MVertex *v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  bool is_inside1;
	  bool is_inside2;
	  bool flag;
	  int num = triangulator._adjacencies[i].t_length;
	  for(int j=0;j<num;j++){
	    int index3 = triangulator._adjacencies[i].t[j];
		int index2 = triangulator._adjacencies[i].t[(j+1)%num];
		int index1 = triangulator._adjacencies[i].t[(j+2)%num];
		double _x0[2] = {triangulator.points[i].where.h,triangulator.points[i].where.v};
		double _x1[2] = {triangulator.points[index1].where.h,triangulator.points[index1].where.v};
	    double _x2[2] = {triangulator.points[index2].where.h,triangulator.points[index2].where.v};
		double _x3[2] = {triangulator.points[index3].where.h,triangulator.points[index3].where.v};
		SPoint2 x0(_x0[0],_x0[1]);
		SPoint2 x1(_x1[0],_x1[1]);
		SPoint2 x2(_x2[0],_x2[1]);
		SPoint2 x3(_x3[0],_x3[1]);
		double _C1[2];
		double _C2[2];
		circumCenterXY(_x0,_x1,_x2,_C1);
		circumCenterXY(_x0,_x2,_x3,_C2);
		SPoint2 C1(_C1[0],_C1[1]);
		SPoint2 C2(_C2[0],_C2[1]);
		is_inside1 = inside_domain(C1.x(),C1.y());
		is_inside2 = inside_domain(C2.x(),C2.y());
		if(is_inside1 && is_inside2){
		  energies[i] = energies[i] + F(x0,C1,C2,p);
		  gradients[i] = gradients[i] + simple(x0,C1,C2,p);
		  area_centroids[i] = area_centroids[i] + area_centroid(x0,C1,C2);
		  areas[i] = areas[i] + triangle_area(x0,C1,C2);
		  SVector3 grad1 = dF_dC1(x0,C1,C2,p);
		  SVector3 grad2 = dF_dC2(x0,C1,C2,p);
		  gradients[i] = gradients[i] + inner_dFdx0(grad1,C1,x0,x1,x2);
		  gradients[index1] = gradients[index1] + inner_dFdx0(grad1,C1,x1,x0,x2);
		  gradients[index2] = gradients[index2] + inner_dFdx0(grad1,C1,x2,x0,x1);
		  gradients[i] = gradients[i] + inner_dFdx0(grad2,C2,x0,x2,x3);
		  gradients[index2] = gradients[index2] + inner_dFdx0(grad2,C2,x2,x0,x3);
		  gradients[index3] = gradients[index3] + inner_dFdx0(grad2,C2,x3,x0,x2);
		}
		else if(is_inside1){
		  SPoint2 first;
		  SPoint2 second;
		  SVector3 vecA;
		  SVector3 vecB;
		  first = boundary_intersection(C1,C2,flag,vecA);
		  second = boundary_intersection(x0,C2,flag,vecB);
		  energies[i] = energies[i] + F(x0,C1,first,p);
		  energies[i] = energies[i] + F(x0,first,second,p);
		  gradients[i] = gradients[i] + simple(x0,C1,first,p);
		  gradients[i] = gradients[i] + simple(x0,first,second,p);
		  area_centroids[i] = area_centroids[i] + area_centroid(x0,C1,first);
		  area_centroids[i] = area_centroids[i] + area_centroid(x0,first,second);
		  areas[i] = areas[i] + triangle_area(x0,C1,first);
		  areas[i] = areas[i] + triangle_area(x0,first,second);
		  SVector3 grad1 = dF_dC1(x0,C1,first,p);
		  SVector3 grad2 = dF_dC2(x0,C1,first,p);
		  SVector3 grad3 = dF_dC1(x0,first,second,p);
		  gradients[i] = gradients[i] + inner_dFdx0(grad1,C1,x0,x1,x2);
		  gradients[index1] = gradients[index1] + inner_dFdx0(grad1,C1,x1,x0,x2);
		  gradients[index2] = gradients[index2] + inner_dFdx0(grad1,C1,x2,x0,x1);
		  gradients[i] = gradients[i] + boundary_dFdx0(grad2,first,x0,x2,vecA);
		  gradients[index2] = gradients[index2] + boundary_dFdx0(grad2,first,x2,x0,vecA);
		  gradients[i] = gradients[i] + boundary_dFdx0(grad3,first,x0,x2,vecA);
		  gradients[index2] = gradients[index2] + boundary_dFdx0(grad3,first,x2,x0,vecA);
		}
		else if(is_inside2){
		  SPoint2 first;
		  SPoint2 second;
		  SVector3 vecA;
		  SVector3 vecB;
		  first = boundary_intersection(C1,C2,flag,vecA);
		  second = boundary_intersection(x0,C1,flag,vecB);
		  energies[i] = energies[i] + F(x0,second,first,p);
		  energies[i] = energies[i] + F(x0,first,C2,p);
		  gradients[i] = gradients[i] + simple(x0,second,first,p);
		  gradients[i] = gradients[i] + simple(x0,first,C2,p);
		  area_centroids[i] = area_centroids[i] + area_centroid(x0,second,first);
		  area_centroids[i] = area_centroids[i] + area_centroid(x0,first,C2);
		  areas[i] = areas[i] + triangle_area(x0,second,first);
		  areas[i] = areas[i] + triangle_area(x0,first,C2);
		  SVector3 grad1 = dF_dC2(x0,second,first,p);
		  SVector3 grad2 = dF_dC1(x0,first,C2,p);
		  SVector3 grad3 = dF_dC2(x0,first,C2,p);
		  gradients[i] = gradients[i] + inner_dFdx0(grad3,C2,x0,x2,x3);
		  gradients[index2] = gradients[index2] + inner_dFdx0(grad3,C2,x2,x0,x3);
		  gradients[index3] = gradients[index3] + inner_dFdx0(grad3,C2,x3,x0,x2);
		  gradients[i] = gradients[i] + boundary_dFdx0(grad2,first,x0,x2,vecA);
		  gradients[index2] = gradients[index2] + boundary_dFdx0(grad2,first,x2,x0,vecA);
		  gradients[i] = gradients[i] + boundary_dFdx0(grad1,first,x0,x2,vecA);
		  gradients[index2] = gradients[index2] + boundary_dFdx0(grad1,first,x2,x0,vecA);
		}
		else{
		  SPoint2 first;
		  SPoint2 second;
		  SPoint2 third;
		  SPoint2 fourth;
		  SPoint2 median;
		  SPoint2 any;
		  SVector3 vecA;
		  SVector3 vecB;
		  SVector3 vec;
		  any = boundary_intersection(C1,C2,flag,vec);
		  if(flag){
		    median = mid(x0,x2);
			first = boundary_intersection(median,C1,flag,vecA);
			second = boundary_intersection(median,C2,flag,vecB);
			third = boundary_intersection(x0,C1,flag,vec);
			fourth = boundary_intersection(x0,C2,flag,vec);
			energies[i] = energies[i] + F(x0,first,second,p);
			energies[i] = energies[i] + F(x0,third,first,p);
			energies[i] = energies[i] + F(x0,second,fourth,p);
			gradients[i] = gradients[i] + simple(x0,first,second,p);
			gradients[i] = gradients[i] + simple(x0,third,first,p);
			gradients[i] = gradients[i] + simple(x0,second,fourth,p);
			area_centroids[i] = area_centroids[i] + area_centroid(x0,first,second);
			area_centroids[i] = area_centroids[i] + area_centroid(x0,third,first);
			area_centroids[i] = area_centroids[i] + area_centroid(x0,second,fourth);
			areas[i] = areas[i] + triangle_area(x0,first,second);
			areas[i] = areas[i] + triangle_area(x0,third,first);
			areas[i] = areas[i] + triangle_area(x0,second,fourth);
			SVector3 grad1 = dF_dC1(x0,first,second,p);
			SVector3 grad2 = dF_dC2(x0,first,second,p);  
			SVector3 grad3 = dF_dC2(x0,third,first,p);  
			SVector3 grad4 = dF_dC1(x0,second,fourth,p);  
			gradients[i] = gradients[i] + boundary_dFdx0(grad1,first,x0,x2,vecA);
			gradients[index2] = gradients[index2] + boundary_dFdx0(grad1,first,x2,x0,vecA);  
			gradients[i] = gradients[i] + boundary_dFdx0(grad2,second,x0,x2,vecB);
			gradients[index2] = gradients[index2] + boundary_dFdx0(grad2,second,x2,x0,vecB);
			gradients[i] = gradients[i] + boundary_dFdx0(grad3,first,x0,x2,vecA);
			gradients[index2] = gradients[index2] + boundary_dFdx0(grad3,first,x2,x0,vecA);  
			gradients[i] = gradients[i] + boundary_dFdx0(grad4,second,x0,x2,vecB);
			gradients[index2] = gradients[index2] + boundary_dFdx0(grad4,second,x2,x0,vecB);
		  }
		  else{
		    first = boundary_intersection(x0,C1,flag,vec);
			second = boundary_intersection(x0,C2,flag,vec);
			energies[i] = energies[i] + F(x0,first,second,p);
			gradients[i] = gradients[i] + simple(x0,first,second,p);
			area_centroids[i] = area_centroids[i] + area_centroid(x0,first,second);
			areas[i] = areas[i] + triangle_area(x0,first,second);
		  }
	    }
	  }
	}
	else {
      double e = 0.00000001;
	  bool ok_triangle1;
	  bool ok_triangle2;
	  bool is_inside1;
	  bool is_inside2;
	  bool is_inside;
	  bool flag;
	  int num = triangulator._adjacencies[i].t_length;
	  for(int j=0;j<num;j++){
	    int index3 = triangulator._adjacencies[i].t[j];
		int index2 = triangulator._adjacencies[i].t[(j+1)%num];
		int index1 = triangulator._adjacencies[i].t[(j+2)%num];
		if(index1!=index2 && index1!=index3 && index2!=index3 && i!=index1 && i!=index2 && i!=index3){
		  double _x0[2] = {triangulator.points[i].where.h,triangulator.points[i].where.v};
		  double _x1[2] = {triangulator.points[index1].where.h,triangulator.points[index1].where.v};
		  double _x2[2] = {triangulator.points[index2].where.h,triangulator.points[index2].where.v};
		  double _x3[2] = {triangulator.points[index3].where.h,triangulator.points[index3].where.v};
		  SPoint2 x0(_x0[0],_x0[1]);
		  SPoint2 x1(_x1[0],_x1[1]);
		  SPoint2 x2(_x2[0],_x2[1]);
		  SPoint2 x3(_x3[0],_x3[1]);
		  ok_triangle1 = adjacent(triangulator,index1,index2) && triangle_area(x0,x1,x2)>e;
		  ok_triangle2 = adjacent(triangulator,index2,index3) && triangle_area(x0,x2,x3)>e;
		  if(ok_triangle1 && ok_triangle2){
		    double _C1[2];
			double _C2[2];
			circumCenterXY(_x0,_x1,_x2,_C1);
			circumCenterXY(_x0,_x2,_x3,_C2);
			SPoint2 C1(_C1[0],_C1[1]);
			SPoint2 C2(_C2[0],_C2[1]);
			is_inside1 = inside_domain(C1.x(),C1.y());
			is_inside2 = inside_domain(C2.x(),C2.y());
		    if(is_inside1 && is_inside2){
			  energies[i] = energies[i] + F(x0,C1,C2,p);
			  SVector3 grad1 = dF_dC1(x0,C1,C2,p);
			  SVector3 grad2 = dF_dC2(x0,C1,C2,p);
			  gradients[index1] = gradients[index1] + inner_dFdx0(grad1,C1,x1,x0,x2);
			  gradients[index2] = gradients[index2] + inner_dFdx0(grad1,C1,x2,x0,x1);
			  gradients[index2] = gradients[index2] + inner_dFdx0(grad2,C2,x2,x0,x3);
			  gradients[index3] = gradients[index3] + inner_dFdx0(grad2,C2,x3,x0,x2);
		    }
		    else if(is_inside1){
		      SPoint2 val;
			  SVector3 vec;
			  val = boundary_intersection(C1,C2,flag,vec);
			  energies[i] = energies[i] + F(x0,C1,val,p);
			  SVector3 grad1 = dF_dC1(x0,C1,val,p);
			  SVector3 grad2 = dF_dC2(x0,C1,val,p);
			  gradients[index1] = gradients[index1] + inner_dFdx0(grad1,C1,x1,x0,x2);
			  gradients[index2] = gradients[index2] + inner_dFdx0(grad1,C1,x2,x0,x1);
			  gradients[index2] = gradients[index2] + boundary_dFdx0(grad2,val,x2,x0,vec);
		    }
		    else if(is_inside2){
		      SPoint2 val;
			  SVector3 vec;
			  val = boundary_intersection(C1,C2,flag,vec);
			  energies[i] = energies[i] + F(x0,val,C2,p);
			  SVector3 grad1 = dF_dC1(x0,val,C2,p);
			  SVector3 grad2 = dF_dC2(x0,val,C2,p);
			  gradients[index2] = gradients[index2] + inner_dFdx0(grad2,C2,x2,x0,x3);
			  gradients[index3] = gradients[index3] + inner_dFdx0(grad2,C2,x3,x0,x2);
			  gradients[index2] = gradients[index2] + boundary_dFdx0(grad1,val,x2,x0,vec);
		    }
			else{
			  SPoint2 first;
			  SPoint2 second;
			  SPoint2 median;
			  SPoint2 any;
			  SVector3 vecA;
			  SVector3 vecB;
			  SVector3 vec;
			  any = boundary_intersection(C1,C2,flag,vec);
			  if(flag){
			    median = mid(x0,x2);
				first = boundary_intersection(median,C1,flag,vecA);
				second = boundary_intersection(median,C2,flag,vecB);
				energies[i] = energies[i] + F(x0,first,second,p);
				SVector3 grad1 = dF_dC1(x0,first,second,p);
				SVector3 grad2 = dF_dC2(x0,first,second,p);
				gradients[index2] = gradients[index2] + boundary_dFdx0(grad1,first,x2,x0,vecA);
				gradients[index2] = gradients[index2] + boundary_dFdx0(grad2,second,x2,x0,vecB);
			  }
			}
		  }
		  else if(ok_triangle1){
		    double _C[2];
		    circumCenterXY(_x0,_x1,_x2,_C);
			SPoint2 C(_C[0],_C[1]);
			is_inside = inside_domain(C.x(),C.y());
			if(is_inside){
			  SPoint2 val;
			  val = mid(x0,x2);
			  energies[i] = energies[i] + F(x0,C,val,p);
			  SVector3 grad1 = dF_dC1(x0,C,val,p);
			  gradients[index1] = gradients[index1] + inner_dFdx0(grad1,C,x1,x0,x2);
			}	  
		  }
		  else if(ok_triangle2){
		    double _C[2];
			circumCenterXY(_x0,_x2,_x3,_C);
			SPoint2 C(_C[0],_C[1]);
			is_inside = inside_domain(C.x(),C.y());
			if(is_inside){
			  SPoint2 val;
			  val = mid(x0,x2);
			  energies[i] = energies[i] + F(x0,val,C,p);
			  SVector3 grad1 = dF_dC2(x0,val,C,p);
			  gradients[index3] = gradients[index3] + inner_dFdx0(grad1,C,x3,x0,x2);
		    }
		  }
	    }
	  }
    }
  }
}

double lloydAlgorithm::total_energy(std::vector<double> energies){
  int i;
  double total;
  total = 0.0;
  for(i=0;i<energies.size();i++){
    total = total + energies[i];
  }
  return total;
}

SVector3 lloydAlgorithm::numerical(DocRecord& triangulator,GFace* gf,int index,int p){
  double x_original;
  double y_original;
  double energy_right;
  double energy_left;
  double energy_up;
  double energy_down;
  double comp_x;
  double comp_y;
  double e;
  std::vector<double> energies(triangulator.numPoints);
  std::vector<SVector3> gradients(triangulator.numPoints);
  std::vector<SVector3> area_centroids(triangulator.numPoints);
  std::vector<double> areas(triangulator.numPoints);
  e = 0.00001;
  x_original = triangulator.points[index].where.h;
  y_original = triangulator.points[index].where.v;
  
  triangulator.points[index].where.h = x_original + e;
  triangulator.points[index].where.v = y_original;
  eval(triangulator,gf,gradients,energies,area_centroids,areas,p);
  energy_right = total_energy(energies);

  triangulator.points[index].where.h = x_original - e;
  triangulator.points[index].where.v = y_original;
  eval(triangulator,gf,gradients,energies,area_centroids,areas,p);
  energy_left = total_energy(energies);
	
  triangulator.points[index].where.h = x_original;
  triangulator.points[index].where.v = y_original + e;
  eval(triangulator,gf,gradients,energies,area_centroids,areas,p);
  energy_up = total_energy(energies);
	
  triangulator.points[index].where.h = x_original;
  triangulator.points[index].where.v = y_original - e;
  eval(triangulator,gf,gradients,energies,area_centroids,areas,p);
  energy_down = total_energy(energies);
  
  comp_x = (energy_right - energy_left)/(2*e);	
  comp_y = (energy_up - energy_down)/(2*e);		
  
  triangulator.points[index].where.h = x_original;
  triangulator.points[index].where.v = y_original;	
	
  return SVector3(comp_x,comp_y,0.0);
}

void lloydAlgorithm::write(DocRecord& triangulator,GFace* gf,int p){
  int i;
  SVector3 grad1;
  SVector3 grad2;
  SVector3 ecart;
  std::vector<SVector3> gradients(triangulator.numPoints);
  std::vector<double> energies(triangulator.numPoints);
  std::vector<SVector3> area_centroids(triangulator.numPoints);
  std::vector<double> areas(triangulator.numPoints);
	
  eval(triangulator,gf,gradients,energies,area_centroids,areas,p);
  
  std::ofstream file("gradient");
  
  for(i=0;i<triangulator.numPoints;i++){
    PointRecord& pt = triangulator.points[i];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  grad1 = numerical(triangulator,gf,i,p);
	  grad2 = gradients[i];
	  ecart = grad1-grad2;
	  file << grad1.x() << "  ";
	  file << grad2.x() << "      ";
	  file << grad1.y() << "  ";
	  file << grad2.y() << "      ";
	  file << 100.0*ecart.norm()/grad1.norm() << " ";
	  file << "\n";
	}
  }
}

void lloydAlgorithm::write2(DocRecord& triangulator,GFace* gf){
  int i;
  SPoint2 generator;
  SVector3 grad1;
  SVector3 grad2;
  SVector3 ecart;
  std::vector<SVector3> gradients(triangulator.numPoints);
  std::vector<double> energies(triangulator.numPoints);
  std::vector<SVector3> area_centroids(triangulator.numPoints);
  std::vector<double> areas(triangulator.numPoints);
	
  eval(triangulator,gf,gradients,energies,area_centroids,areas,2);
	
  std::ofstream file("gradient2");
	
  for(i=0;i<triangulator.numPoints;i++){
    PointRecord& pt = triangulator.points[i];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(i)){
	  generator = SPoint2(triangulator.points[i].where.h,triangulator.points[i].where.v);
	  grad1 = analytical(generator,area_centroids[i],areas[i]);
	  grad2 = gradients[i];
	  ecart = grad1-grad2;
	  file << grad1.x() << "  ";
	  file << grad2.x() << "      ";
	  file << grad1.y() << "  ";
	  file << grad2.y() << "      ";
	  file << 100.0*ecart.norm()/grad1.norm() << " ";
	  file << "\n";
	}
  }
}

SVector3 lloydAlgorithm::analytical(SPoint2 generator,SVector3 area_centroid,double area){
  SVector3 _generator;
  SVector3 val;
  _generator = SVector3(generator.x(),generator.y(),0.0);
  val = 2.0*area*(_generator - (1.0/area)*area_centroid);
  return val;
}

SVector3 lloydAlgorithm::area_centroid(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double x;
  double y;
  double area;
  area = triangle_area(p1,p2,p3);
  x = (1.0/3.0)*(p1.x() + p2.x() + p3.x());
  y = (1.0/3.0)*(p1.y() + p2.y() + p3.y());
  return SVector3(area*x,area*y,0.0);
}



/****************Fonctions pour le calcul du gradient****************/
/********************************************************************/

double lloydAlgorithm::F(SPoint2 generator,SPoint2 C1,SPoint2 C2,int p){
  int i;
  int num;
  int order;
  double x;
  double y;
  double energy;
  SPoint2 point;
  fullMatrix<double> pts;
  fullMatrix<double> weights;
  order = 8;
  gaussIntegration::getTriangle(order,pts,weights);
  num = pts.size1();
  energy = 0.0;
  for(i=0;i<num;i++){
    x = Tx(pts(i,0),pts(i,1),generator,C1,C2);
	y = Ty(pts(i,0),pts(i,1),generator,C1,C2);
	point = SPoint2(x,y);
	energy = energy + weights(i,0)*f(generator,point,p);
  }
  energy = J(generator,C1,C2)*energy;
  return energy;
}

SVector3 lloydAlgorithm::simple(SPoint2 generator,SPoint2 C1,SPoint2 C2,int p){
  int i;
  int num;
  int order;
  double x;
  double y;
  double comp_x;
  double comp_y;
  SPoint2 point;
  fullMatrix<double> pts;
  fullMatrix<double> weights;
  order = 8;
  gaussIntegration::getTriangle(order,pts,weights);
  num = pts.size1();
  comp_x = 0.0;
  comp_y = 0.0;
  for(i=0;i<num;i++){
    x = Tx(pts(i,0),pts(i,1),generator,C1,C2);
	y = Ty(pts(i,0),pts(i,1),generator,C1,C2);
	point = SPoint2(x,y);
	comp_x = comp_x + weights(i,0)*df_dx(generator,point,p);
	comp_y = comp_y + weights(i,0)*df_dy(generator,point,p);
  }
  comp_x = J(generator,C1,C2)*comp_x;
  comp_y = J(generator,C1,C2)*comp_y; 
  return SVector3(comp_x,comp_y,0.0);
}

SVector3 lloydAlgorithm::dF_dC1(SPoint2 generator,SPoint2 C1,SPoint2 C2,int p){
  int i;
  int num;
  int order;
  double x;
  double y;
  double comp_x;
  double comp_y;
  SPoint2 point;
  fullMatrix<double> pts;
  fullMatrix<double> weights;
  order = 8;
  gaussIntegration::getTriangle(order,pts,weights);
  num = pts.size1();
  comp_x = 0.0;
  comp_y = 0.0;
  for(i=0;i<num;i++){
    x = Tx(pts(i,0),pts(i,1),generator,C1,C2);
    y = Ty(pts(i,0),pts(i,1),generator,C1,C2);
    point = SPoint2(x,y);
    comp_x = comp_x + weights(i,0)*df_dx(point,generator,p)*dTx_dp2x(pts(i,0),pts(i,1))*J(generator, C1, C2);
    comp_x = comp_x + weights(i,0)*f(point,generator,p)*dJ_dp2x(generator,C1,C2);
    comp_y = comp_y + weights(i,0)*df_dy(point,generator,p)*dTy_dp2y(pts(i,0),pts(i,1))*J(generator, C1, C2);
    comp_y = comp_y + weights(i,0)*f(point,generator,p)*dJ_dp2y(generator,C1,C2);
  }		
  return SVector3(comp_x,comp_y,0.0);
}

SVector3 lloydAlgorithm::dF_dC2(SPoint2 generator,SPoint2 C1,SPoint2 C2,int p){
  int i;
  int num;
  int order;
  double x;
  double y;
  double comp_x;
  double comp_y;
  SPoint2 point;
  fullMatrix<double> pts;
  fullMatrix<double> weights;
  order = 8;
  gaussIntegration::getTriangle(order,pts,weights);
  num = pts.size1();
  comp_x = 0.0;
  comp_y = 0.0;
  for(i=0;i<num;i++){
    x = Tx(pts(i,0),pts(i,1),generator,C1,C2);
	y = Ty(pts(i,0),pts(i,1),generator,C1,C2);
	point = SPoint2(x,y);
	comp_x = comp_x + weights(i,0)*df_dx(point,generator,p)*dTx_dp3x(pts(i,0),pts(i,1))*J(generator,C1,C2);
	comp_x = comp_x + weights(i,0)*f(point,generator,p)*dJ_dp3x(generator,C1,C2);
	comp_y = comp_y + weights(i,0)*df_dy(point,generator,p)*dTy_dp3y(pts(i,0),pts(i,1))*J(generator,C1,C2);
	comp_y = comp_y + weights(i,0)*f(point,generator,p)*dJ_dp3y(generator,C1,C2);
  }		
  return SVector3(comp_x,comp_y,0.0);
}

double lloydAlgorithm::f(SPoint2 p1,SPoint2 p2,int p){
  double val;
  val = exp(p1.x()-p2.x(),p) + exp(p1.y()-p2.y(),p);
  return val;
}

double lloydAlgorithm::df_dx(SPoint2 p1,SPoint2 p2,int p){
  double val;
  val = ((double)p)*exp(p1.x()-p2.x(),p-1);
  return val;
}

double lloydAlgorithm::df_dy(SPoint2 p1,SPoint2 p2,int p){
  double val;
  val = ((double)p)*exp(p1.y()-p2.y(),p-1);
  return val;
}

double lloydAlgorithm::L1(double u,double v){
  double val;
  val = 1.0-u-v;
  return val;
}

double lloydAlgorithm::dL1_du(){
  return -1.0;
}

double lloydAlgorithm::dL1_dv(){
  return -1.0;
}

double lloydAlgorithm::L2(double u,double v){
  double val;
  val = u;
  return val;
}

double lloydAlgorithm::dL2_du(){
  return 1.0;
}

double lloydAlgorithm::dL2_dv(){
  return 0.0;
}

double lloydAlgorithm::L3(double u,double v){
  double val;
  val = v;
  return val;
}

double lloydAlgorithm::dL3_du(){
  return 0.0;
}

double lloydAlgorithm::dL3_dv(){
  return 1.0;
}

double lloydAlgorithm::Tx(double u,double v,SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = L1(u,v)*p1.x() + L2(u,v)*p2.x() + L3(u,v)*p3.x();
  return val;
}

double lloydAlgorithm::dTx_dp1x(double u,double v){
  return L1(u,v);
}

double lloydAlgorithm::dTx_dp2x(double u,double v){
  return L2(u,v);
}

double lloydAlgorithm::dTx_dp3x(double u,double v){
  return L3(u,v);
}

double lloydAlgorithm::dTx_du(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL1_du()*p1.x() + dL2_du()*p2.x() + dL3_du()*p3.x();
  return val;
}

double lloydAlgorithm::dTx_dv(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL1_dv()*p1.x() + dL2_dv()*p2.x() + dL3_dv()*p3.x();
  return val;
}

double lloydAlgorithm::Ty(double u,double v,SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = L1(u,v)*p1.y() + L2(u,v)*p2.y() + L3(u,v)*p3.y();
  return val;
}

double lloydAlgorithm::dTy_dp1y(double u,double v){
  return L1(u,v);
}

double lloydAlgorithm::dTy_dp2y(double u,double v){
  return L2(u,v);
}

double lloydAlgorithm::dTy_dp3y(double u,double v){
  return L3(u,v);
}

double lloydAlgorithm::dTy_du(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL1_du()*p1.y() + dL2_du()*p2.y() + dL3_du()*p3.y();
  return val;
}

double lloydAlgorithm::dTy_dv(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL1_dv()*p1.y() + dL2_dv()*p2.y() + dL3_dv()*p3.y();
  return val;
}

double lloydAlgorithm::J(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dTx_du(p1,p2,p3)*dTy_dv(p1,p2,p3) - dTx_dv(p1,p2,p3)*dTy_du(p1,p2,p3);
  return val;
}

double lloydAlgorithm::dJ_dp1x(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL1_du()*dTy_dv(p1,p2,p3) - dL1_dv()*dTy_du(p1,p2,p3);
  return val;
}

double lloydAlgorithm::dJ_dp2x(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL2_du()*dTy_dv(p1,p2,p3) - dL2_dv()*dTy_du(p1,p2,p3);
  return val;
}

double lloydAlgorithm::dJ_dp3x(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dL3_du()*dTy_dv(p1,p2,p3) - dL3_dv()*dTy_du(p1,p2,p3);
  return val;
}

double lloydAlgorithm::dJ_dp1y(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dTx_du(p1,p2,p3)*dL1_dv() - dTx_dv(p1,p2,p3)*dL1_du();
  return val;
}

double lloydAlgorithm::dJ_dp2y(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dTx_du(p1,p2,p3)*dL2_dv() - dTx_dv(p1,p2,p3)*dL2_du();
  return val;
}

double lloydAlgorithm::dJ_dp3y(SPoint2 p1,SPoint2 p2,SPoint2 p3){
  double val;
  val = dTx_du(p1,p2,p3)*dL3_dv() - dTx_dv(p1,p2,p3)*dL3_du();
  return val;
}

SVector3 lloydAlgorithm::inner_dFdx0(SVector3 dFdC,SPoint2 C,SPoint2 x0,SPoint2 x1,SPoint2 x2){
  fullMatrix<double> A(2,2);
  fullMatrix<double> B(2,2);
  fullMatrix<double> M(2,2);
  fullMatrix<double> _dFdC(1,2);
  fullMatrix<double> _val(1,2);
  A(0,0) = x1.x() - x0.x(); 
  A(0,1) = x1.y() - x0.y();
  A(1,0) = x2.x() - x0.x(); 
  A(1,1) = x2.y() - x0.y();
  A.invertInPlace();
  B(0,0) = C.x() - x0.x();
  B(0,1) = C.y() - x0.y();
  B(1,0) = C.x() - x0.x();
  B(1,1) = C.y() - x0.y();
  A.mult_naive(B,M);
  _dFdC(0,0) = dFdC.x();
  _dFdC(0,1) = dFdC.y();
  _dFdC.mult_naive(M,_val);
  return SVector3(_val(0,0),_val(0,1),0.0);	
}

SVector3 lloydAlgorithm::boundary_dFdx0(SVector3 dFdC,SPoint2 C,SPoint2 x0,SPoint2 x1,SVector3 normal){
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

double lloydAlgorithm::exp(double a,int b)
{
  int i;
  double val = 1.0;
  for(i=0;i<b;i++){
    val = val*a;	
  }
  return val;
}



/****************Calcul des intersections****************/
/********************************************************/

SVector3 lloydAlgorithm::normal(SPoint2 p1,SPoint2 p2){
  double x;
  double y;
  SVector3 val;
  x = p2.x() - p1.x();
  y = p2.y() - p1.y();
  val = SVector3(-y,x,0.0);
  return val;
}

SPoint2 lloydAlgorithm::mid(SPoint2 p1,SPoint2 p2){
  double x;
  double y;
  x = 0.5*(p1.x() + p2.x());
  y = 0.5*(p1.y() + p2.y());
  return SPoint2(x,y);
}

void lloydAlgorithm::print_segment(SPoint2 p1,SPoint2 p2,std::ofstream& file){
  file << "SL (" << p1.x() << ", "
	             << p1.y() << ", 0, "
	             << p2.x() << ", "
	             << p2.y() << ", 0){" << "10, 20};\n";	
}

bool lloydAlgorithm::adjacent(const DocRecord& triangulator,int index1,int index2){
  int num = triangulator._adjacencies[index1].t_length;
  for(int i=0;i<num;i++){
    if(triangulator._adjacencies[index1].t[i] == index2){
	  return 1;
	}
  }
  return 0;
}

double lloydAlgorithm::triangle_area(SPoint2 p1,SPoint2 p2,SPoint2 p3){
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

SPoint2 lloydAlgorithm::boundary_intersection(SPoint2 p1,SPoint2 p2,bool& flag,SVector3& vec){
  int i;
  int num;
  bool flag2;
  SPoint2 p3;
  SPoint2 p4;
  SPoint2 val;
  boundary_edge edge;	
  num = get_number_boundary_edges();
  for(i=0;i<num;i++){
    edge = get_boundary_edge(i);
	p3 = edge.get_p1();
	p4 = edge.get_p2();
	val = intersection(p1,p2,p3,p4,flag2);
	if(flag2){
	  flag = 1;
	  vec = normal(p3,p4);
	  return val;
	}
  }
  flag = 0;
  vec = SVector3(0.0,0.0,0.0);
  return SPoint2(0.0,0.0);
}

bool lloydAlgorithm::inside_domain(double x,double y){
  if(x<=1.0 && x>=0.0 && y<=1.0 && y>=0.0){
    return 1;
  }
  else{
    return 0;
  }
}

int lloydAlgorithm::get_number_boundary_edges(){
  return 4;
}

boundary_edge lloydAlgorithm::get_boundary_edge(int i){
  if(i==0) return boundary_edge(SPoint2(0.0,0.0),SPoint2(1.0,0.0));
  else if(i==1) return boundary_edge(SPoint2(1.0,0.0),SPoint2(1.0,1.0));
  else if(i==2) return boundary_edge(SPoint2(1.0,1.0),SPoint2(0.0,1.0));
  else if(i==3) return boundary_edge(SPoint2(0.0,1.0),SPoint2(0.0,0.0));
}

SPoint2 lloydAlgorithm::intersection(SPoint2 p1,SPoint2 p2,SPoint2 p3,SPoint2 p4,bool& flag){
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
  e = 0.000001;
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
	return SPoint2(x1 + ua * (x2 - x1), y1 + ua * (y2 - y1));
  }
  else{
    flag = 0;
	return SPoint2(0.0,0.0);
  }
}

/****************Class boundary_edge****************/
boundary_edge::boundary_edge(SPoint2 new_p1, SPoint2 new_p2){
  p1 = new_p1;
  p2 = new_p2;
}

boundary_edge::boundary_edge(){}

boundary_edge::~boundary_edge(){}

SPoint2 boundary_edge::get_p1(){
  return p1;
}

SPoint2 boundary_edge::get_p2(){
  return p2;
}


#endif
