// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "directions3D.h"
#include "GModel.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include <fstream>

/****************class Matrix****************/

Matrix::Matrix(){
  m11 = 1.0;
  m21 = 0.0;
  m31 = 0.0;
  m12 = 0.0;
  m22 = 1.0;
  m32 = 0.0;
  m13 = 0.0;
  m23 = 0.0;
  m33 = 1.0;
}

Matrix::~Matrix(){}

void Matrix::set_m11(double new_m11){
  m11 = new_m11;
}

void Matrix::set_m21(double new_m21){
  m21 = new_m21;
}

void Matrix::set_m31(double new_m31){
  m31 = new_m31;
}

void Matrix::set_m12(double new_m12){
  m12 = new_m12;
}

void Matrix::set_m22(double new_m22){
  m22 = new_m22;
}

void Matrix::set_m32(double new_m32){
  m32 = new_m32;
}

void Matrix::set_m13(double new_m13){
  m13 = new_m13;
}

void Matrix::set_m23(double new_m23){
  m23 = new_m23;
}

void Matrix::set_m33(double new_m33){
  m33 = new_m33;
}

double Matrix::get_m11(){
  return m11;
}

double Matrix::get_m21(){
  return m21;
}

double Matrix::get_m31(){
  return m31;
}

double Matrix::get_m12(){
  return m12;
}

double Matrix::get_m22(){
  return m22;
}

double Matrix::get_m32(){
  return m32;
}

double Matrix::get_m13(){
  return m13;
}

double Matrix::get_m23(){
  return m23;
}

double Matrix::get_m33(){
  return m33;
}

/****************class Frame_field****************/

Frame_field::Frame_field(){}

void Frame_field::init_model(){
  #if defined(HAVE_ANN)
  int index;
  MVertex* vertex;
  GFace* gf;
  GModel* model = GModel::current();
  GModel::fiter it;
  std::map<MVertex*,Matrix>::iterator it2;
  Matrix m;

  field.clear();
  random.clear();

  for(it=model->firstFace();it!=model->lastFace();it++)
  {
    gf = *it;
	init_face(gf);
  }

  duplicate = annAllocPts(field.size(),3);

  index = 0;
  for(it2=field.begin();it2!=field.end();it2++){
	vertex = it2->first;
	m = it2->second;
	duplicate[index][0] = vertex->x();
	duplicate[index][1] = vertex->y();
	duplicate[index][2] = vertex->z();
	random.push_back(std::pair<MVertex*,Matrix>(vertex,m));
	index++;
  }

  kd_tree = new ANNkd_tree(duplicate,field.size(),3);
  #endif
}

void Frame_field::init_face(GFace* gf){
  unsigned int i;
  int j;
  bool ok;
  SVector3 v1,v2,v3;
  MVertex* vertex;
  MElement* element;
  MElementOctree* octree;
  Matrix m;

  backgroundMesh::set(gf);
  octree = backgroundMesh::current()->get_octree();

  for(i=0;i<gf->getNumMeshElements();i++){
    element = gf->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  ok = translate(gf,octree,vertex,v1,v2);
	  if(ok){
	    v3 = crossprod(v1,v2);
	    v1.normalize();
	    v2.normalize();
	    v3.normalize();
	    m.set_m11(v1.x());
	    m.set_m21(v1.y());
	    m.set_m31(v1.z());
	    m.set_m12(v2.x());
	    m.set_m22(v2.y());
	    m.set_m32(v2.z());
	    m.set_m13(v3.x());
	    m.set_m23(v3.y());
	    m.set_m33(v3.z());
	    field.insert(std::pair<MVertex*,Matrix>(vertex,m));
	  }
	}
  }
}

bool Frame_field::inside_domain(MElementOctree* octree,double x,double y){
  MElement* element;
  element = (MElement*)octree->find(x,y,0.0,2,true);
  if(element!=NULL) return 1;
  else return 0;
}

double Frame_field::get_size(GFace* gf,double x,double y){
  double ratio;
  double uv[2];
  double tab[3];

  uv[0] = x;
  uv[1] = y;
  buildMetric(gf,uv,tab);
  ratio = 1.0/pow(tab[0]*tab[2]-tab[1]*tab[1],0.25);

  return ratio*backgroundMesh::current()->operator()(x,y,0.0);
}

bool Frame_field::translate(GFace* gf,MElementOctree* octree,MVertex* vertex,SVector3& v1,SVector3& v2){
  bool ok;
  double k;
  double size;
  double angle;
  double delta_x;
  double delta_y;
  double x,y;
  double x1,y1;
  double x2,y2;
  SPoint2 point;
  GPoint gp1;
  GPoint gp2;

  ok = true;
  k = 0.1;
  reparamMeshVertexOnFace(vertex,gf,point);
  x = point.x();
  y = point.y();
  size = get_size(gf,x,y);
  angle = backgroundMesh::current()->getAngle(x,y,0.0);

  delta_x = k*size*cos(angle);
  delta_y = k*size*sin(angle);

  x1 = x + delta_x;
  y1 = y + delta_y;
  x2 = x + delta_y;
  y2 = y - delta_x;

  if(!inside_domain(octree,x1,y1)){
    x1 = x - delta_x;
	y1 = y - delta_y;
	if(!inside_domain(octree,x1,y1)) ok = false;
  }
  if(!inside_domain(octree,x2,y2)){
    x2 = x - delta_y;
	y2 = y + delta_x;
	if(!inside_domain(octree,x2,y2)) ok = false;
  }

  if(ok){
	gp1 = gf->point(x1,y1);
	gp2 = gf->point(x2,y2);
    v1 = SVector3(gp1.x()-vertex->x(),gp1.y()-vertex->y(),gp1.z()-vertex->z());
    v2 = SVector3(gp2.x()-vertex->x(),gp2.y()-vertex->y(),gp2.z()-vertex->z());
  }
  else{
    v1 = SVector3(1.0,0.0,0.0);
	v2 = SVector3(0.0,1.0,0.0);
  }

  return ok;
}

Matrix Frame_field::search(double x,double y,double z){
  int val;
  double e;
  #if defined(HAVE_ANN)
  ANNpoint query;
  ANNidxArray indices;
  ANNdistArray distances;

  query = annAllocPt(3);
  query[0] = x;
  query[1] = y;
  query[2] = z;

  indices = new ANNidx[1];
  distances = new ANNdist[1];

  e = 0.0;
  kd_tree->annkSearch(query,1,indices,distances,e);
  val = indices[0];

  annDeallocPt(query);
  delete[] indices;
  delete[] distances;
  #endif

  return random[val].second;
}

void Frame_field::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL ("
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() << ")"
  << "{10, 20};\n";
}

void Frame_field::print_field1(){
  double k;
  SPoint3 p;
  SPoint3 p1,p2,p3,p4,p5,p6;
  MVertex* vertex;
  std::map<MVertex*,Matrix>::iterator it;
  Matrix m;

  k = 0.1;
  std::ofstream file("field1.pos");
  file << "View \"test\" {\n";

  for(it=field.begin();it!=field.end();it++){
    vertex = it->first;
	m = it->second;

	p = SPoint3(vertex->x(),vertex->y(),vertex->z());
	p1 = SPoint3(vertex->x()+k*m.get_m11(),vertex->y()+k*m.get_m21(),vertex->z()+k*m.get_m31());
	p2 = SPoint3(vertex->x()-k*m.get_m11(),vertex->y()-k*m.get_m21(),vertex->z()-k*m.get_m31());
	p3 = SPoint3(vertex->x()+k*m.get_m12(),vertex->y()+k*m.get_m22(),vertex->z()+k*m.get_m32());
	p4 = SPoint3(vertex->x()-k*m.get_m12(),vertex->y()-k*m.get_m22(),vertex->z()-k*m.get_m32());
	p5 = SPoint3(vertex->x()+k*m.get_m13(),vertex->y()+k*m.get_m23(),vertex->z()+k*m.get_m33());
	p6 = SPoint3(vertex->x()-k*m.get_m13(),vertex->y()-k*m.get_m23(),vertex->z()-k*m.get_m33());

	print_segment(p,p1,file);
	print_segment(p,p2,file);
	print_segment(p,p3,file);
	print_segment(p,p4,file);
	print_segment(p,p5,file);
	print_segment(p,p6,file);
  }

  file << "};\n";
}

void Frame_field::print_field2(){
  unsigned int i;
  int j;
  double k;
  SPoint3 p;
  SPoint3 p1,p2,p3,p4,p5,p6;
  MVertex* vertex;
  MElement* element;
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;
  Matrix m;

  k = 0.05;
  std::ofstream file("field2.pos");
  file << "View \"test\" {\n";

  for(it=model->firstRegion();it!=model->lastRegion();it++)
  {
    gr = *it;
	for(i=0;i<gr->getNumMeshElements();i++){
	  element = gr->getMeshElement(i);
	  for(j=0;j<element->getNumVertices();j++){
	    vertex = element->getVertex(j);
		if(vertex->onWhat()->dim()>2){
		  m = search(vertex->x(),vertex->y(),vertex->z());

		  p = SPoint3(vertex->x(),vertex->y(),vertex->z());
		  p1 = SPoint3(vertex->x()+k*m.get_m11(),vertex->y()+k*m.get_m21(),vertex->z()+k*m.get_m31());
		  p2 = SPoint3(vertex->x()-k*m.get_m11(),vertex->y()-k*m.get_m21(),vertex->z()-k*m.get_m31());
		  p3 = SPoint3(vertex->x()+k*m.get_m12(),vertex->y()+k*m.get_m22(),vertex->z()+k*m.get_m32());
		  p4 = SPoint3(vertex->x()-k*m.get_m12(),vertex->y()-k*m.get_m22(),vertex->z()-k*m.get_m32());
		  p5 = SPoint3(vertex->x()+k*m.get_m13(),vertex->y()+k*m.get_m23(),vertex->z()+k*m.get_m33());
		  p6 = SPoint3(vertex->x()-k*m.get_m13(),vertex->y()-k*m.get_m23(),vertex->z()-k*m.get_m33());

		  print_segment(p,p1,file);
		  print_segment(p,p2,file);
		  print_segment(p,p3,file);
		  print_segment(p,p4,file);
		  print_segment(p,p5,file);
		  print_segment(p,p6,file);
		}
	  }
	}
  }

  file << "};\n";
}

void Frame_field::clear(){
  field.clear();
  random.clear();
  #if defined(HAVE_ANN)
  delete duplicate;
  delete kd_tree;
  annClose();
  #endif
}

/****************static declarations****************/

std::map<MVertex*,Matrix> Frame_field::field;
std::vector<std::pair<MVertex*,Matrix> > Frame_field::random;
#if defined(HAVE_ANN)
ANNpointArray Frame_field::duplicate;
ANNkd_tree* Frame_field::kd_tree;
#endif
