#include <set>
#include "meshGFaceLloyd.h"
#include "DivideAndConquer.h"
#include "GFace.h"
#include "MElement.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "Context.h"
#include "meshGFace.h"
#include "BackgroundMesh.h"

/*List of parameters to modify*/
//Line 76 : the variable "number" contains the number of points to remove.
//Line 165 : the variable "test" is printed by the script.
//Line 190 : the variable "angle" specifies the orientation of the mesh.
//Line 287 : the variable "num" contains the number of iteration of the bisection method
//used to find the fixed point.
//Line 447 : it is the function "optimize" that needs to be called by the script.
//Line 455 : put "lloyd(face)" in commentary to avoid calling the l1 lloyds method.
//Line 456 : put "recombineIntoQuads(face,1,1)" in commentary to avoid calling the quad 
//meshing method.
//Line 461 : the code below line 461 refers to Lua and might need to be removed.

void lloydAlgorithm::operator () (GFace *gf) 
{
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
  backgroundMesh::current()->print("bgm.pos", 0);

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
 
  triangulator.Voronoi();
  triangulator.initialize();
  int index,number,count,max;
  bool recent;
  number = 0; //This variable contains the number of points to remove.
  count = 0;
  max = 100000;
  for(int i=0;i<max;i++)
  {
    if(count>=number) break;
	index = (int)((triangulator.numPoints-1)*((double)rand()/(double)RAND_MAX));
	PointRecord& pt = triangulator.points[index];
	MVertex* v = (MVertex*)pt.data;
	if(v->onWhat()==gf && !triangulator.onHull(index)){
	  recent = triangulator.remove_point(index);
	  if(recent) count++;
	}
  }
  triangulator.remove_all();
	
  // compute the Voronoi diagram
  triangulator.Voronoi();
  //printf("hullSize = %d\n",triangulator.hullSize());
  triangulator.makePosView("LloydInit.pos");
  //triangulator.printMedialAxis("medialAxis.pos");
  
  // now do the Lloyd iterations
  int ITER = 0;
  while (1){
    // store the new coordinates there
    fullMatrix<double> cgs(triangulator.numPoints,2);
    // now iterate on internal vertices
    double ENERGY = 0.0;
    double criteria = 0.0;
    for (int i=0; i<triangulator.numPoints;i++){
      // get the ith vertex
      PointRecord &pt = triangulator.points[i];
      MVertex *v = (MVertex*)pt.data;
      if (v->onWhat() == gf && !triangulator.onHull(i)){
        // get the voronoi corners
        std::vector<SPoint2> pts;
        triangulator.voronoiCell (i,pts); 
        double E, A;
        SPoint2 p(pt.where.h,pt.where.v);
		for(int k=0;k<pts.size();k++){
		  rotate(p,pts[k]);
		}
		SPoint2 point = fixed_point(pts); //Fixed point for quad mesh generation
		unrotate(p,point);
		cgs(i,0) = point.x();
		cgs(i,1) = point.y();
        ENERGY += E;
	double d = sqrt((p.x()-cgs(i,0))*(p.x()-cgs(i,0))+
			(p.y()-cgs(i,1))*(p.y()-cgs(i,1)));
	criteria += d/A;
      }// if (v->onWhat() == gf)
      else {
      }
    }// for all points

    for(PointNumero i = 0; i < triangulator.numPoints; i++) {
      MVertex *v = (MVertex*)triangulator.points[i].data;
      if (v->onWhat() == gf && !triangulator.onHull(i)){
        triangulator.points[i].where.h = cgs(i,0);
        triangulator.points[i].where.v = cgs(i,1);
      }
    }

    Msg::Debug("GFace %d Lloyd-iter %d Inertia=%g Convergence=%g ", gf->tag(), 
               ITER++, ENERGY, criteria);
    if (ITER > ITER_MAX)break;

    // compute the Voronoi diagram
    triangulator.Voronoi();

    if (ITER % 10 == 0){
      char name[234];
      sprintf(name,"LloydIter%d.pos",ITER);
      triangulator.makePosView(name);
    }
  }
	
  // now create the vertices
  test = 0;
  std::vector<MVertex*> mesh_vertices;
  for (int i=0; i<triangulator.numPoints;i++){
    // get the ith vertex
    PointRecord &pt = triangulator.points[i];
    MVertex *v = (MVertex*)pt.data;
    if (v->onWhat() == gf && !triangulator.onHull(i)){
      GPoint gp = gf->point (pt.where.h,pt.where.v);
      MFaceVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
	  mesh_vertices.push_back(v);
	  test++;
    }
  }

  // destroy the mesh
  deMeshGFace killer;
  killer(gf);
  
  // put all additional vertices in the list of
  // vertices
  gf->_additional_vertices = mesh_vertices;
  // remesh the face with all those vertices in
  Msg::Info("Lloyd remeshing of face %d ", gf->tag());
  meshGFace mesher;
  mesher(gf);
  // assign those vertices to the face internal vertices
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(),
                           gf->_additional_vertices.begin(),  
                           gf->_additional_vertices.end());  
  // clear the list of additional vertices
  gf->_additional_vertices.clear();
}

double lloydAlgorithm::get_angle(double x,double y){
  double angle;
  angle = M_PI/4.0; //This variable specifies the orientation of the mesh.
  return angle;
}

//This function returns the a, b, c and d components of the rotation matrix.
void lloydAlgorithm::get_rotation(double x,double y,double& a,double& b,double& c,double& d){
  double angle;
  angle = get_angle(x,y);
  a = cos(angle);
  b = -sin(angle);
  c = sin(angle);
  d = cos(angle);
}

//This function returns the a, b, c and d components of the inverse rotation matrix.
void lloydAlgorithm::get_unrotation(double x,double y,double& _a,double& _b,double& _c,double& _d){
  double a,b,c,d;
  double det;
  get_rotation(x,y,a,b,c,d);
  det = 1.0/(a*d-b*c);
  _a = d/det;
  _b = -b/det;
  _c = -c/det;
  _d = a/det;
}

//This function rotates a vertice (point) belonging to a Voronoi cell.
//The angle is specified by the location of the generator, because we want all vertices
//of the Voronoi cell to be rotated by the same amount in case the orientation of the
//mesh is not constant.
//The generator itself is not rotated.
void lloydAlgorithm::rotate(SPoint2 generator,SPoint2& point){
  double x,y;
  double new_x,new_y;
  double a,b,c,d;
  get_rotation(generator.x(),generator.y(),a,b,c,d);
  x = point.x();
  y = point.y();
  new_x = a*x + b*y;
  new_y = c*x + d*y;
  point.setPosition(new_x,new_y);
}

//This function rotates a vertice (point) belonging to a Voronoi cell in the reverse direction.
//The angle is specified by the location of the generator, because we want all vertices
//of the Voronoi cell to be rotated by the same amount in case the orientation of the
//mesh is not constant.
//The generator itself is not rotated.
void lloydAlgorithm::unrotate(SPoint2 generator,SPoint2& point){
  double x,y;
  double new_x,new_y;
  double a,b,c,d;
  get_unrotation(generator.x(),generator.y(),a,b,c,d);
  x = point.x();
  y = point.y();
  new_x = a*x + b*y;
  new_y = c*x + d*y;
  point.setPosition(new_x,new_y);
}

//This function returns the fixed point of the voronoi cell specified in argument (polygon).
//It finds the bounding box of the voronoi cell and then it calls the function range in x and y.
SPoint2 lloydAlgorithm::fixed_point(const std::vector<SPoint2>& polygon){
  int i,num;
  double x,y;
  double x_min,y_min;
  double x_max,y_max;
  double solution_x,solution_y;
  SPoint2 point;
  x_min = 100000000.0;
  y_min = 100000000.0;
  x_max = -100000000.0;
  y_max = -100000000.0;
  num = polygon.size();
  for(i=0;i<num;i++){
	point = polygon[i];
    x = point.x();
	y = point.y();
	if(x < x_min) x_min = x;
	if(y < y_min) y_min = y;
	if(x > x_max) x_max = x;
	if(y > y_max) y_max = y;
  }
  solution_x = range(polygon,x_min,x_max,1);
  solution_y = range(polygon,y_min,y_max,0);
  return SPoint2(solution_x,solution_y);
}

//This function returns the x or y median of the Voronoi cell specified in argument (polygon).
//If direction = 1, the function will return the x median.
//If direction = 0, the function will return the y median.
//The variables u1 and u2 should be respectively equal to the minimum and the maximum of x or y,
//depending of the value of direction.
//This function uses the bisection method.
double lloydAlgorithm::range(const std::vector<SPoint2>& polygon,double u1,double u2,bool direction){
  int i,num;
  double mid,val;
  num = 16; //This variable specifies the number of iteration of the bisection method.
  for(i=0;i<num;i++){
	mid = 0.5*(u1 + u2);
	val = gradient(polygon,mid,direction);
	if(val >= 0) u2 = mid;
	else u1 = mid;
  }
  return 0.5*(u1 + u2);
}

//This function returns the x or y component of the l1 gradient of the voronoi cell
//specified in argument (polygon).
//If direction = 1, it will return the x component.
//If direction = 0, it will return the y component.
//The variable generator should be equal to the x or y component of the point to which the 
//voronoi cell belongs.
//x component = A1-A2, A1 : area of the left part, A2 : area of the right part
//y component = A3-A4, A3 : area of the lower part, A4 : area of the higher part
double lloydAlgorithm::gradient(const std::vector<SPoint2>& polygon,double generator,bool direction){
  int i,num,index1,index2;
  bool intersection,side;
  double areaA,areaB;
  SPoint2 p1,p2,solution;
  std::vector<bool> category;
  std::vector<SPoint2> new_polygon;
  std::vector<SPoint2> polygonA;
  std::vector<SPoint2> polygonB;
  num = polygon.size();
  for(i=0;i<num;i++){
	index1 = i;
	index2 = (i+1)%num;
	p1 = polygon[index1];
	p2 = polygon[index2];
	solution = line_intersection(p1,p2,generator,direction,intersection);
	if(intersection){
	  new_polygon.push_back(p1);
	  new_polygon.push_back(solution);
	  category.push_back(1);
	  category.push_back(0);	
	}
	else{
	  new_polygon.push_back(p1);
	  category.push_back(1);	
	}
  }
  num = new_polygon.size();
  for(i=0;i<num;i++){
	if(category[i]){
	  side = point_side(new_polygon[i],generator,direction);
	  if(side){
	    polygonA.push_back(new_polygon[i]);
	  }
	  else{
	    polygonB.push_back(new_polygon[i]);
	  }
	}
	else{
	  polygonA.push_back(new_polygon[i]);
	  polygonB.push_back(new_polygon[i]);
	}
  }
  areaA = polygon_area(polygonA);
  areaB = polygon_area(polygonB);
  return areaA-areaB;
}

//The point p is a vertice of a Voronoi cell.
//The variable generator contains the x or y component of the point to which
//the Voronoi cell belongs. If direction = 1, it will contain the x component,
//if direction = 0, it will contain the y component.
//If direction = 1, this function will return 1 if p is at the left of the generator
//and it will return 0 if p is at the right of the generator.
//If direction = 0, this function will return 1 if p is below the generator
//and it will return 0 if p is higher than the generator.
bool lloydAlgorithm::point_side(SPoint2 p,double generator,bool direction){
  if(direction){
    if(p.x()<=generator) return 1;
	else return 0;
  }
  else{
    if(p.y()<=generator) return 1;
	else return 0;
  }
}

//This function uses the Surveyors Formula to calculate the area of the Voronoi cell
//specified in argument (polygon).
double lloydAlgorithm::polygon_area(const std::vector<SPoint2>& polygon){
  int i;
  int num;
  double area;
  num = polygon.size();
  if(num<3) return 0.0;
  else{
    area = 0.0;
    for(i=0;i<num-1;i++){
	  area = area + 0.5*(polygon[i].x()*polygon[i+1].y() - polygon[i+1].x()*polygon[i].y());
    }
    area = area + 0.5*(polygon[num-1].x()*polygon[0].y() - polygon[0].x()*polygon[num-1].y());
    return fabs(area);
  }
}

//This function determines if there is an intersection between the segment p1-p2 and the
//infinite line passing through the generator, which is the point to which the Voronoi cell
//belongs.
//If there is an intersection, then the variable intersection will contain 1, otherwise it will
//contain 0. In that case, the point that the function returns is not imporant.
//If direction = 1, the variable generator will contain the x component, in that case,
//the infinite line will be vertical.
//If direction = 0, the variable generator will contain the y component, in that case,
//the infinite line will be horizontal. 
SPoint2 lloydAlgorithm::line_intersection(SPoint2 p1,SPoint2 p2,double generator,bool direction,bool& intersection){
  double x1,x2,solution_x;
  double y1,y2,solution_y;
  double u,e;
  x1 = p1.x();
  y1 = p1.y();
  x2 = p2.x();
  y2 = p2.y();
  e = 0.0000001;
  intersection = 0;
  if(direction){
	if(fabs(x1 - generator)<e){
	  intersection = 1;
	  return SPoint2(x1,y1);
	}
	else if(fabs(x2 - generator)<e){
	  intersection = 1;
	  return SPoint2(x2,y2);
	}
	else if((x1<generator && x2>generator)||(x1>generator && x2<generator)){
	  intersection = 1;
	  u = (generator-x1)/(x2-x1);
	  solution_x = generator;
	  solution_y = y1 + u*(y2-y1);
	  return SPoint2(solution_x,solution_y);
	}
  }
  else{
	if(fabs(y1 - generator)<e){
	  intersection = 1;
	  return SPoint2(x1,y1);
	}
	else if(fabs(y2 - generator)<e){
	  intersection = 1;
	  return SPoint2(x2,y2);
	}
	else if((y1<generator && y2>generator)||(y1>generator && y2<generator)){
	  intersection = 1;
	  u = (generator-y1)/(y2-y1);
	  solution_x = x1 + u*(x2-x1);
	  solution_y = generator;
	  return SPoint2(solution_x,solution_y);
	}
  }
  return SPoint2(0.0,0.0);
}

//This is the function called by the script.
double lloydAlgorithm::optimize(int max,int flag){
  GFace*face;
  GModel*model = GModel::current();
  GModel::fiter iterator;
  lloydAlgorithm lloyd(max,flag);
  for(iterator = model->firstFace();iterator != model->lastFace();iterator++)
  {
    face = *iterator;
	lloyd(face);
	recombineIntoQuads(face,1,1);
  }
  return lloyd.test;
}

#include "Bindings.h"
void lloydAlgorithm::registerBindings(binding *b){
  classBinding*cb = b->addClass<lloydAlgorithm>("lloydAlgorithm");
  cb->setDescription("This class is used to move the points according to lloyd algorithm.");
  methodBinding*cm;
  cm = cb->setConstructor<lloydAlgorithm>();
  cm->setDescription("This is the constructor.");
  cm = cb->addMethod("optimize",&lloydAlgorithm::optimize);
  cm->setDescription("This function moves the points.");
  cm->setArgNames("max","flag",NULL);
}
