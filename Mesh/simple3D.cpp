// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "simple3D.h"
#include "GModel.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "meshGRegion.h"
#include <queue>
#include <fstream>
#include "CenterlineField.h"
#include <algorithm>
#include "directions3D.h"

#if defined(HAVE_RTREE)
#include "rtree.h"
#endif

#define k1 0.7 //k1*h is the minimal distance between two nodes
#define k2 0.5 //k2*h is the minimal distance to the boundary
#define sqrt3 1.73205081

/*********definitions*********/

class Metric{
 private:
  double m11,m21,m31,m12,m22,m32,m13,m23,m33;
 public:
  Metric();
  ~Metric();
  void set_m11(double);
  void set_m21(double);
  void set_m31(double);
  void set_m12(double);
  void set_m22(double);
  void set_m32(double);
  void set_m13(double);
  void set_m23(double);
  void set_m33(double);
  double get_m11();
  double get_m21();
  double get_m31();
  double get_m12();
  double get_m22();
  double get_m32();
  double get_m13();
  double get_m23();
  double get_m33();
};

class Node{
 private:
  double h;
  Metric m;
  SPoint3 point;
 public:
  double min[3];
  double max[3];
  Node();
  Node(SPoint3);
  ~Node();
  void set_size(double);
  void set_metric(Metric);
  void set_point(SPoint3);
  double get_size();
  Metric get_metric();
  SPoint3 get_point();
};

class Wrapper{
 private:
  bool too_close;
  Node* spawn;
  Node* parent;
 public:
  Wrapper();
  Wrapper(Node*,Node*);
  ~Wrapper();
  void set_too_close(bool);
  void set_spawn(Node*);
  void set_parent(Node*);
  bool get_too_close();
  Node* get_spawn();
  Node* get_parent();
};

/*********functions*********/

double infinity_distance(SPoint3 p1,SPoint3 p2,Metric m){
  double distance;
  double x1,y1,z1;
  double x2,y2,z2;
  double a,b,c,d,e,f,g,h,i;

  a = m.get_m11();
  b = m.get_m21();
  c = m.get_m31();
  d = m.get_m12();
  e = m.get_m22();
  f = m.get_m32();
  g = m.get_m13();
  h = m.get_m23();
  i = m.get_m33();

  x1 = a*p1.x() + b*p1.y() + c*p1.z();
  y1 = d*p1.x() + e*p1.y() + f*p1.z();
  z1 = g*p1.x() + h*p1.y() + i*p1.z();

  x2 = a*p2.x() + b*p2.y() + c*p2.z();
  y2 = d*p2.x() + e*p2.y() + f*p2.z();
  z2 = g*p2.x() + h*p2.y() + i*p2.z();

  distance = std::max(std::max(fabs(x2-x1),fabs(y2-y1)),fabs(z2-z1));
  return distance;
}

bool rtree_callback(Node* neighbour,void* w){
  double h;
  double distance;
  Metric m;
  Node *spawn,*parent;
  Wrapper* wrapper;

  wrapper = static_cast<Wrapper*>(w);
  spawn = wrapper->get_spawn();
  parent = wrapper->get_parent();
  h = spawn->get_size();
  m = spawn->get_metric();

  if(neighbour!=parent){
    distance = infinity_distance(spawn->get_point(),neighbour->get_point(),m);
	if(distance<k1*h){
	  wrapper->set_too_close(1);
	  return false;
	}
  }

  return true;
}

/*********class Metric*********/

Metric::Metric(){
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

Metric::~Metric(){}

void Metric::set_m11(double new_m11){
  m11 = new_m11;
}

void Metric::set_m21(double new_m21){
  m21 = new_m21;
}

void Metric::set_m31(double new_m31){
  m31 = new_m31;
}

void Metric::set_m12(double new_m12){
  m12 = new_m12;
}

void Metric::set_m22(double new_m22){
  m22 = new_m22;
}

void Metric::set_m32(double new_m32){
  m32 = new_m32;
}

void Metric::set_m13(double new_m13){
  m13 = new_m13;
}

void Metric::set_m23(double new_m23){
  m23 = new_m23;
}

void Metric::set_m33(double new_m33){
  m33 = new_m33;
}

double Metric::get_m11(){
  return m11;
}

double Metric::get_m21(){
  return m21;
}

double Metric::get_m31(){
  return m31;
}

double Metric::get_m12(){
  return m12;
}

double Metric::get_m22(){
  return m22;
}

double Metric::get_m32(){
  return m32;
}

double Metric::get_m13(){
  return m13;
}

double Metric::get_m23(){
  return m23;
}

double Metric::get_m33(){
  return m33;
}

/*********class Node*********/

Node::Node(){}

Node::Node(SPoint3 new_point){
  point = new_point;
}

Node::~Node(){}

void Node::set_size(double new_h){
  h = new_h;
}

void Node::set_metric(Metric new_m){
  m = new_m;
}

void Node::set_point(SPoint3 new_point){
  point = new_point;
}

double Node::get_size(){
  return h;
}

Metric Node::get_metric(){
  return m;
}

SPoint3 Node::get_point(){
  return point;
}

/*********class Wrapper*********/

Wrapper::Wrapper(){
  too_close = 0;
}

Wrapper::Wrapper(Node* new_spawn,Node* new_parent){
  too_close = 0;
  spawn = new_spawn;
  parent = new_parent;
}

Wrapper::~Wrapper(){}

void Wrapper::set_too_close(bool new_too_close){
  too_close = new_too_close;
}

void Wrapper::set_spawn(Node* new_spawn){
  spawn = new_spawn;
}

void Wrapper::set_parent(Node* new_parent){
  parent = new_parent;
}

bool Wrapper::get_too_close(){
  return too_close;
}

Node* Wrapper::get_spawn(){
  return spawn;
}

Node* Wrapper::get_parent(){
  return parent;
}

/*********class Filler*********/

Filler::Filler(){}

Filler::~Filler(){}

void Filler::treat_model(){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
  {
    gr = *it;
	if(gr->getNumMeshElements()>0){
	  treat_region(gr);
	}
  }
}

void Filler::treat_region(GRegion* gr){
  #if defined(HAVE_RTREE)
  unsigned int i;
  int j;
  int count;
  bool ok;
  double x,y,z;
  SPoint3 point;
  Node *node,*spawn,*parent,*n1,*n2,*n3,*n4,*n5,*n6;
  MVertex* vertex;
  MElement* element;
  MElementOctree* octree;
  deMeshGRegion deleter;
  Wrapper wrapper;
  std::queue<Node*> fifo;
  std::vector<Node*> data;
  std::vector<Node*> garbage;
  std::vector<MVertex*> boundary_vertices;
  std::set<MVertex*> old_vertices;
  std::set<MVertex*>::iterator it;
  RTree<Node*,double,3,double> rtree;

  Frame_field::init_region(gr);
  octree = new MElementOctree(gr->model());

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  old_vertices.insert(vertex);
	}
  }

  for(it=old_vertices.begin();it!=old_vertices.end();it++){
	if((*it)->onWhat()->dim()<3){
	  boundary_vertices.push_back(*it);
	}
  }

  std::ofstream file("nodes.pos");
  file << "View \"test\" {\n";
  for(i=0;i<boundary_vertices.size();i++){
    x = boundary_vertices[i]->x();
    y = boundary_vertices[i]->y();
    z = boundary_vertices[i]->z();
    node = new Node(SPoint3(x,y,z));
	compute_parameters(node,gr);
	rtree.Insert(node->min,node->max,node);
	fifo.push(node);
	print_node(node,file);
  }
  file << "};\n";

  count = 1;
  while(!fifo.empty()){
    parent = fifo.front();
	fifo.pop();
	garbage.push_back(parent);
	
	n1 = new Node();
	n2 = new Node();
	n3 = new Node();
	n4 = new Node();
	n5 = new Node();
	n6 = new Node();
	offsprings(gr,octree,parent,n1,n2,n3,n4,n5,n6);
	
	data.clear();
	data.push_back(n1);
	data.push_back(n2);
	data.push_back(n3);
	data.push_back(n4);
	data.push_back(n5);
	data.push_back(n6);
	
	for(i=0;i<6;i++){
	  ok = 0;
	  spawn = data[i];
	  point = spawn->get_point();
	  x = point.x();
	  y = point.y();
	  z = point.z();
	  
	  if(inside_domain(octree,x,y,z)){
		compute_parameters(spawn,gr);
	    if(far_from_boundary(octree,spawn)){
		  wrapper.set_too_close(0);
		  wrapper.set_spawn(spawn);
		  wrapper.set_parent(parent);
		  rtree.Search(spawn->min,spawn->max,rtree_callback,&wrapper);
		  
		  if(!wrapper.get_too_close()){
		    fifo.push(spawn);
		    rtree.Insert(spawn->min,spawn->max,spawn);
			vertex = new MVertex(x,y,z,gr,0);
			new_vertices.push_back(vertex);
			ok = 1;
		  }
	    }
	  }
	  if(!ok) delete spawn;
	}
	printf("%d\n",count);
	count++;
  }

  deleter(gr);
  std::vector<GRegion*> regions;
  regions.push_back(gr);
  meshGRegion mesher(regions); //?
  mesher(gr); //?
  MeshDelaunayVolume(regions);

  delete octree;
  for(i=0;i<garbage.size();i++) delete garbage[i];
  for(i=0;i<new_vertices.size();i++) delete new_vertices[i];
  new_vertices.clear();
  Frame_field::clear();
  #endif
}

Metric Filler::get_metric(double x,double y,double z){
  Metric m;
  Matrix m2;

  m2 = Frame_field::search(x,y,z);

  m.set_m11(m2.get_m11());
  m.set_m21(m2.get_m21());
  m.set_m31(m2.get_m31());

  m.set_m12(m2.get_m12());
  m.set_m22(m2.get_m22());
  m.set_m32(m2.get_m32());

  m.set_m13(m2.get_m13());
  m.set_m23(m2.get_m23());
  m.set_m33(m2.get_m33());

  return m;
}

double Filler::get_size(double x,double y,double z){
  return 0.25;
}

double Filler::get_size(double x,double y,double z,GEntity* ge){
  double h;
  Field* field;
  FieldManager* manager;

  h = 0.25;
  manager = ge->model()->getFields();
  if(manager->getBackgroundField()>0){
    field = manager->get(manager->getBackgroundField());
	if(field){
	  h = (*field)(x,y,z,ge);
	}
  }

  return h;
}

bool Filler::inside_domain(MElementOctree* octree,double x,double y,double z){
  MElement* element;
  element = (MElement*)octree->find(x,y,z,3,true);
  if(element!=NULL) return 1;
  else return 0;
}

bool Filler::far_from_boundary(MElementOctree* octree,Node* node){
  double x,y,z;
  double h;
  SPoint3 point;
  MElement *e1,*e2,*e3,*e4,*e5,*e6;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  h = node->get_size();

  e1 = (MElement*)octree->find(x+k2*h,y,z,3,true);
  e2 = (MElement*)octree->find(x-k2*h,y,z,3,true);
  e3 = (MElement*)octree->find(x,y+k2*h,z,3,true);
  e4 = (MElement*)octree->find(x,y-k2*h,z,3,true);
  e5 = (MElement*)octree->find(x,y,z+k2*h,3,true);
  e6 = (MElement*)octree->find(x,y,z-k2*h,3,true);

  if(e1!=NULL && e2!=NULL && e3!=NULL && e4!=NULL && e5!=NULL && e6!=NULL) return 1;
  else return 0;
}

void Filler::compute_parameters(Node* node,GEntity* ge){
  double x,y,z;
  double h;
  Metric m;
  SPoint3 point;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  m = get_metric(x,y,z);
  h = get_size(x,y,z);

  node->set_size(h);
  node->set_metric(m);
  node->min[0] = x - sqrt3*h;
  node->min[1] = y - sqrt3*h;
  node->min[2] = z - sqrt3*h;
  node->max[0] = x + sqrt3*h;
  node->max[1] = y + sqrt3*h;
  node->max[2] = z + sqrt3*h;
}

void Filler::offsprings(GEntity* ge,MElementOctree* octree,Node* node,Node* n1,Node* n2,Node* n3,Node* n4,Node* n5,Node* n6){
  double x,y,z;
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  double x4,y4,z4;
  double x5,y5,z5;
  double x6,y6,z6;
  double h;
  double h1,h2,h3,h4,h5,h6;
  Metric m;
  SPoint3 point;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  h = node->get_size();
  m = node->get_metric();

  h1 = improvement(ge,octree,point,h,SVector3(m.get_m11(),m.get_m21(),m.get_m31()));
  x1 = x + h1*m.get_m11();
  y1 = y + h1*m.get_m21();
  z1 = z + h1*m.get_m31();

  h2 = improvement(ge,octree,point,h,SVector3(-m.get_m11(),-m.get_m21(),-m.get_m31()));
  x2 = x - h2*m.get_m11();
  y2 = y - h2*m.get_m21();
  z2 = z - h2*m.get_m31();

  h3 = improvement(ge,octree,point,h,SVector3(m.get_m12(),m.get_m22(),m.get_m32()));
  x3 = x + h3*m.get_m12();
  y3 = y + h3*m.get_m22();
  z3 = z + h3*m.get_m32();

  h4 = improvement(ge,octree,point,h,SVector3(-m.get_m12(),-m.get_m22(),-m.get_m32()));
  x4 = x - h4*m.get_m12();
  y4 = y - h4*m.get_m22();
  z4 = z - h4*m.get_m32();

  h5 = improvement(ge,octree,point,h,SVector3(m.get_m13(),m.get_m23(),m.get_m33()));
  x5 = x + h5*m.get_m13();
  y5 = y + h5*m.get_m23();
  z5 = z + h5*m.get_m33();

  h6 = improvement(ge,octree,point,h,SVector3(-m.get_m13(),-m.get_m23(),-m.get_m33()));
  x6 = x - h6*m.get_m13();
  y6 = y - h6*m.get_m23();
  z6 = z - h6*m.get_m33();

  *n1 = Node(SPoint3(x1,y1,z1));
  *n2 = Node(SPoint3(x2,y2,z2));
  *n3 = Node(SPoint3(x3,y3,z3));
  *n4 = Node(SPoint3(x4,y4,z4));
  *n5 = Node(SPoint3(x5,y5,z5));
  *n6 = Node(SPoint3(x6,y6,z6));
}

double Filler::improvement(GEntity* ge,MElementOctree* octree,SPoint3 point,double h_nearer,SVector3 direction){
  double x,y,z;
  double average;
  double h_farther;
  double coeffA,coeffB;

  x = point.x() + h_nearer*direction.x();
  y = point.y() + h_nearer*direction.y();
  z = point.z() + h_nearer*direction.z();
  if(inside_domain(octree,x,y,z)){
    h_farther = get_size(x,y,z);
  }
  else h_farther = h_nearer;

  coeffA = 1.0;
  coeffB = 0.2;
  if(h_farther>h_nearer){
    average = coeffA*h_nearer + (1.0-coeffA)*h_farther;
  }
  else{
    average = coeffB*h_nearer + (1.0-coeffB)*h_farther;
  }
  return average;
}

int Filler::get_nbr_new_vertices(){
  return new_vertices.size();
}

MVertex* Filler::get_new_vertex(int i){
  return new_vertices[i];
}

void Filler::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL ("
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() << ")"
  << "{10, 20};\n";
}

void Filler::print_node(Node* node,std::ofstream& file){
  double x,y,z;
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  double x4,y4,z4;
  double x5,y5,z5;
  double x6,y6,z6;
  double h;
  Metric m;
  SPoint3 point;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  h = node->get_size();
  m = node->get_metric();

  x1 = x + h*m.get_m11();
  y1 = y + h*m.get_m21();
  z1 = z + h*m.get_m31();

  x2 = x - h*m.get_m11();
  y2 = y - h*m.get_m21();
  z2 = z - h*m.get_m31();

  x3 = x + h*m.get_m12();
  y3 = y + h*m.get_m22();
  z3 = z + h*m.get_m32();

  x4 = x - h*m.get_m12();
  y4 = y - h*m.get_m22();
  z4 = z - h*m.get_m32();

  x5 = x + h*m.get_m13();
  y5 = y + h*m.get_m23();
  z5 = z + h*m.get_m33();

  x6 = x - h*m.get_m13();
  y6 = y - h*m.get_m23();
  z6 = z - h*m.get_m33();

  print_segment(SPoint3(x,y,z),SPoint3(x1,y1,z1),file);
  print_segment(SPoint3(x,y,z),SPoint3(x2,y2,z2),file);
  print_segment(SPoint3(x,y,z),SPoint3(x3,y3,z3),file);
  print_segment(SPoint3(x,y,z),SPoint3(x4,y4,z4),file);
  print_segment(SPoint3(x,y,z),SPoint3(x5,y5,z5),file);
  print_segment(SPoint3(x,y,z),SPoint3(x6,y6,z6),file);
}

/*********static declarations*********/

std::vector<MVertex*> Filler::new_vertices;
