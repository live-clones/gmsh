// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier François Henrotte

#include <queue>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include "simple3D.h"
#include "GModel.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "meshGRegion.h"
#include "directions3D.h"
#include "ThinLayer.h"
#include "Context.h"
#include "rtree.h"
#include "Field.h"
#include "Geo.h"
#include "gmshVertex.h"

#define k1 0.7 // k1*h is the minimal distance between two nodes
#define k2 0.5 // k2*h is the minimal distance to the boundary

/*********definitions*********/

class Metric {
private:
  double m11, m21, m31, m12, m22, m32, m13, m23, m33;

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

class Node {
private:
  int layer;
  int limit;
  double h;
  Metric m;
  SPoint3 point;

public:
  double min[3];
  double max[3];
  Node();
  Node(const SPoint3 &);
  ~Node();
  void set_layer(int);
  void set_limit(int);
  void set_size(double);
  void set_metric(const Metric &);
  void set_point(const SPoint3 &);
  int get_layer();
  int get_limit();
  double get_size();
  Metric get_metric();
  SPoint3 get_point();
};

class Wrapper {
private:
  bool ok;
  Node *individual;
  Node *parent;

public:
  Wrapper();
  Wrapper(Node *, Node *);
  ~Wrapper();
  void set_ok(bool);
  void set_individual(Node *);
  void set_parent(Node *);
  bool get_ok();
  Node *get_individual();
  Node *get_parent();
};

/*********functions*********/

double infinity_distance(const SPoint3 &p1, const SPoint3 &p2, Metric m)
{
  double distance;
  double x1, y1, z1;
  double x2, y2, z2;
  double a, b, c, d, e, f, g, h, i;

  a = m.get_m11();
  b = m.get_m21();
  c = m.get_m31();
  d = m.get_m12();
  e = m.get_m22();
  f = m.get_m32();
  g = m.get_m13();
  h = m.get_m23();
  i = m.get_m33();

  x1 = a * p1.x() + b * p1.y() + c * p1.z();
  y1 = d * p1.x() + e * p1.y() + f * p1.z();
  z1 = g * p1.x() + h * p1.y() + i * p1.z();

  x2 = a * p2.x() + b * p2.y() + c * p2.z();
  y2 = d * p2.x() + e * p2.y() + f * p2.z();
  z2 = g * p2.x() + h * p2.y() + i * p2.z();

  distance = std::max(std::max(fabs(x2 - x1), fabs(y2 - y1)), fabs(z2 - z1));
  return distance;
}

bool rtree_callback(Node *neighbour, void *w)
{
  double h;
  double distance;
  Metric m;
  Node *individual, *parent;
  Wrapper *wrapper;

  wrapper = static_cast<Wrapper *>(w);
  individual = wrapper->get_individual();
  parent = wrapper->get_parent();
  h = individual->get_size();
  m = individual->get_metric();

  if(neighbour != parent) {
    distance =
      infinity_distance(individual->get_point(), neighbour->get_point(), m);
    if(distance < k1 * h) {
      wrapper->set_ok(0);
      return false;
    }
  }

  return true;
}

/*********class Metric*********/

Metric::Metric()
{
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

Metric::~Metric() {}

void Metric::set_m11(double new_m11) { m11 = new_m11; }

void Metric::set_m21(double new_m21) { m21 = new_m21; }

void Metric::set_m31(double new_m31) { m31 = new_m31; }

void Metric::set_m12(double new_m12) { m12 = new_m12; }

void Metric::set_m22(double new_m22) { m22 = new_m22; }

void Metric::set_m32(double new_m32) { m32 = new_m32; }

void Metric::set_m13(double new_m13) { m13 = new_m13; }

void Metric::set_m23(double new_m23) { m23 = new_m23; }

void Metric::set_m33(double new_m33) { m33 = new_m33; }

double Metric::get_m11() { return m11; }

double Metric::get_m21() { return m21; }

double Metric::get_m31() { return m31; }

double Metric::get_m12() { return m12; }

double Metric::get_m22() { return m22; }

double Metric::get_m32() { return m32; }

double Metric::get_m13() { return m13; }

double Metric::get_m23() { return m23; }

double Metric::get_m33() { return m33; }

/*********class Node*********/

Node::Node() { limit = -1; }

Node::Node(const SPoint3 &new_point)
{
  point = new_point;
  limit = -1;
}

Node::~Node() {}

void Node::set_layer(int new_layer) { layer = new_layer; }

void Node::set_limit(int new_limit) { limit = new_limit; }

void Node::set_size(double new_h) { h = new_h; }

void Node::set_metric(const Metric &new_m) { m = new_m; }

void Node::set_point(const SPoint3 &new_point) { point = new_point; }

int Node::get_layer() { return layer; }

int Node::get_limit() { return limit; }

double Node::get_size() { return h; }

Metric Node::get_metric() { return m; }

SPoint3 Node::get_point() { return point; }

/*********class Wrapper*********/

Wrapper::Wrapper() { ok = 1; }

Wrapper::Wrapper(Node *new_individual, Node *new_parent)
{
  ok = 1;
  individual = new_individual;
  parent = new_parent;
}

Wrapper::~Wrapper() {}

void Wrapper::set_ok(bool new_ok) { ok = new_ok; }

void Wrapper::set_individual(Node *new_individual)
{
  individual = new_individual;
}

void Wrapper::set_parent(Node *new_parent) { parent = new_parent; }

bool Wrapper::get_ok() { return ok; }

Node *Wrapper::get_individual() { return individual; }

Node *Wrapper::get_parent() { return parent; }

/*********class Filler*********/

Filler::Filler() {}

Filler::~Filler() {}

void Filler::treat_model()
{
  GRegion *gr;
  GModel *model = GModel::current();
  GModel::riter it;

  for(it = model->firstRegion(); it != model->lastRegion(); it++) {
    gr = *it;
    if(gr->getNumMeshElements() > 0) {
      treat_region(gr);
    }
  }
}

void Filler::treat_region(GRegion *gr)
{
  int NumSmooth = CTX::instance()->mesh.smoothCrossField;
  if(NumSmooth && (gr->dim() == 3)) {
    double scale = gr->bounds().diag() * 1e-2;
    Frame_field::initRegion(gr, NumSmooth);
    Frame_field::saveCrossField("cross0.pos", scale);
    Frame_field::smoothRegion(gr, NumSmooth);
    Frame_field::saveCrossField("cross1.pos", scale);
  }

  int count;
  int limit;
  bool ok2;
  double x, y, z;
  SPoint3 point;
  Node *node, *individual, *parent;

  MElementOctree *octree;
  deMeshGRegion deleter;
  Wrapper wrapper;
  GFace *gf;
  //  std::vector<Node *> garbage;
  std::vector<MVertex *> boundary_vertices;
  std::set<MVertex *>::iterator it;
  std::vector<GFace *>::iterator it2;
  std::map<MVertex *, int>::iterator it3;
  RTree<Node *, double, 3, double> rtree;
  
  Frame_field::init_region(gr);
  Size_field::init_region(gr);
  Size_field::solve(gr);
  /*  {
    double scale = gr->bounds().diag() * 1e-2;
    Frame_field::saveCrossField("cross0.pos", scale);
    }*/
  
  octree = new MElementOctree(gr->model());
  //  garbage.clear();
  boundary_vertices.clear();
  new_vertices.clear();

  std::vector<GFace *> faces = gr->faces();
  std::map<MVertex *, int> limits;

  std::set<MVertex *> temp;

  for(it2 = faces.begin(); it2 != faces.end(); it2++) {
    gf = *it2;
    limit = code(gf->tag());
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *element = gf->getMeshElement(i);
      for(std::size_t j = 0; j < element->getNumVertices(); j++) {
        MVertex *vertex = element->getVertex(j);
        temp.insert(vertex);
        limits.insert(std::pair<MVertex *, int>(vertex, limit));
      }
    }
  }

  for(it = temp.begin(); it != temp.end(); it++) {
    if((*it)->onWhat()->dim() == 0) {
      boundary_vertices.push_back(*it);
    }
  }

  for(it = temp.begin(); it != temp.end(); it++) {
    if((*it)->onWhat()->dim() == 1) {
      boundary_vertices.push_back(*it);
    }
  }

  for(it = temp.begin(); it != temp.end(); it++) {
    if((*it)->onWhat()->dim() == 2) {
      boundary_vertices.push_back(*it);
    }
  }

  std::queue<Node *> fifo;

  for(std::size_t i = 0; i < boundary_vertices.size(); i++) {
    x = boundary_vertices[i]->x();
    y = boundary_vertices[i]->y();
    z = boundary_vertices[i]->z();

    node = new Node(SPoint3(x, y, z));
    compute_parameters(node, gr);
    node->set_layer(0);

    it3 = limits.find(boundary_vertices[i]);
    node->set_limit(it3->second);

    rtree.Insert(node->min, node->max, node);
    fifo.push(node);
  }

  //  printf("coucou3\n");

  count = 1;
  while(!fifo.empty()) {
    parent = fifo.front();
    fifo.pop();
    //    garbage.push_back(parent);

    if(parent->get_limit() != -1 &&
       parent->get_layer() >= parent->get_limit()) {
      continue;
    }

    if (count % 1000 == 0)Msg::Info("%d points inserted -- queue size %d",new_vertices.size(), fifo.size());
    
    std::vector<Node *> spawns(6);
    for(int i = 0; i < 6; i++) {
      spawns[i] = new Node();
    }

    create_spawns(gr, octree, parent, spawns);

    //    printf("creating 6 spawns\n");
    
    for(int i = 0; i < 6; i++) {
      ok2 = 0;
      individual = spawns[i];
      point = individual->get_point();
      x = point.x();
      y = point.y();
      z = point.z();

      if(inside_domain(octree, x, y, z)) {
	//	printf("%g %g %g inside domain\n",x,y,z);
        compute_parameters(individual, gr);
        individual->set_layer(parent->get_layer() + 1);
        individual->set_limit(parent->get_limit());

        if(far_from_boundary(octree, individual)) {
          wrapper.set_ok(1);
          wrapper.set_individual(individual);
          wrapper.set_parent(parent);
          rtree.Search(individual->min, individual->max, rtree_callback,
                       &wrapper);

          if(wrapper.get_ok()) {
            fifo.push(individual);
            rtree.Insert(individual->min, individual->max, individual);
            new_vertices.push_back(new MVertex(x, y, z, gr, 0));
            ok2 = 1;
            // print_segment(individual->get_point(),parent->get_point(),file);
          }
        }
      }

      if(!ok2) delete individual;
    }

    count++;
  }

  int option = CTX::instance()->mesh.algo3d;

  deleter(gr);

  std::vector<GVertex *> old_embedded = gr->embeddedVertices();
  std::vector<GVertex *> new_embedded;
  std::vector<Vertex *> new_vertex;

  // Cheat -- create embedded vertices....

  //  printf("coucou4\n");    


    FILE *f = fopen("new_points.pos","w");
    fprintf(f,"View \" \"{\n");
  
  for (auto v : new_vertices){
    Vertex *vv = new Vertex (v->x(),v->y(),v->z());
    new_vertex.push_back(vv);
    gmshVertex *newV = new gmshVertex(gr->model(), vv);
    newV->mesh_vertices.push_back(v);
    v->setEntity(gr);
    gr->mesh_vertices.push_back(v);
    gr->addEmbeddedVertex(newV);
        fprintf(f,"SP(%g,%g,%g){1,1};\n",v->x(),v->y(),v->z());
  }

    fprintf(f,"};\n");
    fclose(f);
  
  std::vector<GRegion *> regions;
  regions.push_back(gr);

  MeshDelaunayVolume(regions);

  gr->embeddedVertices() = old_embedded;
  
  CTX::instance()->mesh.algo3d = option;

  //  for(std::size_t i = 0; i < garbage.size(); i++) delete garbage[i];
  //  for(std::size_t i = 0; i < new_vertices.size(); i++) delete new_vertices[i];
  for(std::size_t i = 0; i < new_vertex.size(); i++) delete new_vertex[i];
  for(std::size_t i = 0; i < new_embedded.size(); i++) {new_embedded[i]->mesh_vertices.clear(); delete new_embedded[i];}

  delete octree;
  rtree.RemoveAll();
  Size_field::clear();
  Frame_field::clear();
}

Metric Filler::get_metric(double x, double y, double z)
{
  Metric m;
  STensor3 m2;
  if(CTX::instance()->mesh.smoothCrossField) {
    m2 = Frame_field::findCross(x, y, z);
  }
  else
    m2 = Frame_field::search(x, y, z);

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

Metric Filler::get_metric(double x, double y, double z, GEntity *ge)
{
  Metric m;
  SMetric3 temp;
  SVector3 v1, v2, v3;
  Field *field;
  FieldManager *manager;

  v1 = SVector3(1.0, 0.0, 0.0);
  v2 = SVector3(0.0, 1.0, 0.0);
  v3 = SVector3(0.0, 0.0, 1.0);

  manager = ge->model()->getFields();
  if(manager->getBackgroundField() > 0) {
    field = manager->get(manager->getBackgroundField());
    if(field) {
      (*field)(x, y, z, temp, ge);
    }
  }

  m.set_m11(v1.x());
  m.set_m21(v1.y());
  m.set_m31(v1.z());

  m.set_m12(v2.x());
  m.set_m22(v2.y());
  m.set_m32(v2.z());

  m.set_m13(v3.x());
  m.set_m23(v3.y());
  m.set_m33(v3.z());

  return m;
}

double Filler::get_size(double x, double y, double z)
{
  return Size_field::search(x, y, z);
}

double Filler::get_size(double x, double y, double z, GEntity *ge)
{
  double h;
  Field *field;
  FieldManager *manager;

  h = 1.0;
  manager = ge->model()->getFields();
  if(manager->getBackgroundField() > 0) {
    field = manager->get(manager->getBackgroundField());
    if(field) {
      h = (*field)(x, y, z, ge);
    }
  }

  return h;
}

bool Filler::inside_domain(MElementOctree *octree, double x, double y, double z)
{
  MElement *element;
  element = (MElement *)octree->find(x, y, z, 3, true);
  if(element != NULL)
    return 1;
  else
    return 0;
}

bool Filler::far_from_boundary(MElementOctree *octree, Node *node)
{
  return 1;
  double x, y, z;
  double h;
  SPoint3 point;
  MElement *e1, *e2, *e3, *e4, *e5, *e6;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  h = node->get_size();

  e1 = (MElement *)octree->find(x + k2 * h, y, z, 3, true);
  e2 = (MElement *)octree->find(x - k2 * h, y, z, 3, true);
  e3 = (MElement *)octree->find(x, y + k2 * h, z, 3, true);
  e4 = (MElement *)octree->find(x, y - k2 * h, z, 3, true);
  e5 = (MElement *)octree->find(x, y, z + k2 * h, 3, true);
  e6 = (MElement *)octree->find(x, y, z - k2 * h, 3, true);

  if(e1 != NULL && e2 != NULL && e3 != NULL && e4 != NULL && e5 != NULL &&
     e6 != NULL)
    return 1;
  else
    return 0;
}

void Filler::compute_parameters(Node *node, GEntity *ge)
{
  double x, y, z;
  double h;
  Metric m;
  SPoint3 point;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  m = get_metric(x, y, z);
  h = get_size(x, y, z);

  node->set_size(h);
  node->set_metric(m);
  node->min[0] = x - std::sqrt(3.0) * h;
  node->min[1] = y - std::sqrt(3.0) * h;
  node->min[2] = z - std::sqrt(3.0) * h;
  node->max[0] = x + std::sqrt(3.0) * h;
  node->max[1] = y + std::sqrt(3.0) * h;
  node->max[2] = z + std::sqrt(3.0) * h;
}

void Filler::create_spawns(GEntity *ge, MElementOctree *octree, Node *node,
                           std::vector<Node *> &spawns)
{
  double x, y, z;
  double x1, y1, z1;
  double x2, y2, z2;
  double x3, y3, z3;
  double x4, y4, z4;
  double x5, y5, z5;
  double x6, y6, z6;
  double h;
  Metric m;
  SPoint3 point;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  h = node->get_size();
  m = node->get_metric();
  double h1=h, h2=h, h3=h, h4=h, h5=h, h6=h;

  //  h1 = improvement(ge, octree, point, h,
  //                   SVector3(m.get_m11(), m.get_m21(), m.get_m31()));
  
  x1 = x + h1 * m.get_m11();
  y1 = y + h1 * m.get_m21();
  z1 = z + h1 * m.get_m31();

  //  h2 = improvement(ge, octree, point, h,
  //                   SVector3(-m.get_m11(), -m.get_m21(), -m.get_m31()));
  x2 = x - h2 * m.get_m11();
  y2 = y - h2 * m.get_m21();
  z2 = z - h2 * m.get_m31();

  //  h3 = improvement(ge, octree, point, h,
  //                   SVector3(m.get_m12(), m.get_m22(), m.get_m32()));
  x3 = x + h3 * m.get_m12();
  y3 = y + h3 * m.get_m22();
  z3 = z + h3 * m.get_m32();

  //  h4 = improvement(ge, octree, point, h,
  //                   SVector3(-m.get_m12(), -m.get_m22(), -m.get_m32()));
  x4 = x - h4 * m.get_m12();
  y4 = y - h4 * m.get_m22();
  z4 = z - h4 * m.get_m32();

  //  h5 = improvement(ge, octree, point, h,
  //                   SVector3(m.get_m13(), m.get_m23(), m.get_m33()));
  x5 = x + h5 * m.get_m13();
  y5 = y + h5 * m.get_m23();
  z5 = z + h5 * m.get_m33();

  //  h6 = improvement(ge, octree, point, h,
  //                   SVector3(-m.get_m13(), -m.get_m23(), -m.get_m33()));
  x6 = x - h6 * m.get_m13();
  y6 = y - h6 * m.get_m23();
  z6 = z - h6 * m.get_m33();

  *spawns[0] = Node(SPoint3(x1, y1, z1));
  *spawns[1] = Node(SPoint3(x2, y2, z2));
  *spawns[2] = Node(SPoint3(x3, y3, z3));
  *spawns[3] = Node(SPoint3(x4, y4, z4));
  *spawns[4] = Node(SPoint3(x5, y5, z5));
  *spawns[5] = Node(SPoint3(x6, y6, z6));
}

double Filler::improvement(GEntity *ge, MElementOctree *octree,
                           const SPoint3 &point, double h1,
                           const SVector3 &direction)
{
  double x, y, z;
  double average;
  double h2;
  double coeffA, coeffB;

  x = point.x() + h1 * direction.x();
  y = point.y() + h1 * direction.y();
  z = point.z() + h1 * direction.z();

  if(inside_domain(octree, x, y, z)) {
    h2 = get_size(x, y, z);
  }
  else
    h2 = h1;

  coeffA = 1.0;
  coeffB = 0.16;

  if(h2 > h1) {
    average = coeffA * h1 + (1.0 - coeffA) * h2;
  }
  else {
    average = coeffB * h1 + (1.0 - coeffB) * h2;
  }

  return average;
}

int Filler::code(int tag)
{
  int limit;
  std::string s;
  std::stringstream s2;

  limit = -1;
  s2 << tag;
  s = s2.str();

  if(s.length() >= 5) {
    if(s.at(0) == '1' && s.at(1) == '1' && s.at(2) == '1' && s.at(3) == '1' &&
       s.at(4) == '1') {
      limit = 0;
    }
    else if(s.at(0) == '2' && s.at(1) == '2' && s.at(2) == '2' &&
            s.at(3) == '2' && s.at(4) == '2') {
      limit = 1;
    }
  }

  return limit;
}

int Filler::get_nbr_new_vertices() { return new_vertices.size(); }

MVertex *Filler::get_new_vertex(int i) { return new_vertices[i]; }

void Filler::print_segment(const SPoint3 &p1, const SPoint3 &p2,
                           std::ofstream &file)
{
  file << "SL (" << p1.x() << ", " << p1.y() << ", " << p1.z() << ", " << p2.x()
       << ", " << p2.y() << ", " << p2.z() << ")"
       << "{10, 20};\n";
}

void Filler::print_node(Node *node, std::ofstream &file)
{
  double x, y, z;
  double x1, y1, z1;
  double x2, y2, z2;
  double x3, y3, z3;
  double x4, y4, z4;
  double x5, y5, z5;
  double x6, y6, z6;
  double h;
  Metric m;
  SPoint3 point;

  point = node->get_point();
  x = point.x();
  y = point.y();
  z = point.z();
  h = node->get_size();
  m = node->get_metric();

  x1 = x + k1 * h * m.get_m11();
  y1 = y + k1 * h * m.get_m21();
  z1 = z + k1 * h * m.get_m31();

  x2 = x - k1 * h * m.get_m11();
  y2 = y - k1 * h * m.get_m21();
  z2 = z - k1 * h * m.get_m31();

  x3 = x + k1 * h * m.get_m12();
  y3 = y + k1 * h * m.get_m22();
  z3 = z + k1 * h * m.get_m32();

  x4 = x - k1 * h * m.get_m12();
  y4 = y - k1 * h * m.get_m22();
  z4 = z - k1 * h * m.get_m32();

  x5 = x + k1 * h * m.get_m13();
  y5 = y + k1 * h * m.get_m23();
  z5 = z + k1 * h * m.get_m33();

  x6 = x - k1 * h * m.get_m13();
  y6 = y - k1 * h * m.get_m23();
  z6 = z - k1 * h * m.get_m33();

  print_segment(SPoint3(x, y, z), SPoint3(x1, y1, z1), file);
  print_segment(SPoint3(x, y, z), SPoint3(x2, y2, z2), file);
  print_segment(SPoint3(x, y, z), SPoint3(x3, y3, z3), file);
  print_segment(SPoint3(x, y, z), SPoint3(x4, y4, z4), file);
  print_segment(SPoint3(x, y, z), SPoint3(x5, y5, z5), file);
  print_segment(SPoint3(x, y, z), SPoint3(x6, y6, z6), file);
}

/*********static declarations*********/

std::vector<MVertex *> Filler::new_vertices;
