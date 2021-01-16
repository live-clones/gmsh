// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier François Henrotte

#include <fstream>
#include "GModel.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "MTetrahedron.h"
#include "directions3D.h"
#include "OS.h"
#include "cross3D.h"

#if defined(HAVE_SOLVER)
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"
#include "dofManager.h"
#include "laplaceTerm.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataList.h"
#endif

Frame_field::Frame_field() {}

void Frame_field::init_region(GRegion *gr)
{
#if defined(HAVE_ANN)
  // Fill in a ANN tree with the boundary cross field of region gr
  unsigned int i;
  GFace *gf;
  std::vector<GFace *> faces;
  std::vector<GFace *>::iterator it;

  Nearest_point::init_region(gr);

  faces = gr->faces();

  field.clear();
  labels.clear();

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;
    init_face(gf);
  }

  ANNpointArray duplicate = annAllocPts(field.size(), 3);

  for(i = 0; i < field.size(); i++) {
    duplicate[i][0] = field[i].first.x();
    duplicate[i][1] = field[i].first.y();
    duplicate[i][2] = field[i].first.z();
  }

  kd_tree = new ANNkd_tree(duplicate, field.size(), 3);
#endif
}

void Frame_field::init_face(GFace *gf)
{
  // Fills the auxiliary std::map "field" with a pair <SPoint3, STensor3>
  // for each vertex of the face gf.
  unsigned int i;
  SPoint3 point;
  SVector3 v1;
  SVector3 v2;
  SVector3 v3;
  STensor3 m(1.0);

  for(i = 0; i < gf->storage1.size(); i++) {
    point = gf->storage1[i];
    v1 = gf->storage2[i];
    v2 = gf->storage3[i];

    v1.normalize();
    v2.normalize();
    v3 = crossprod(v1, v2);
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
    field.push_back(std::pair<SPoint3, STensor3>(point, m));
    labels.push_back(gf->tag());
  }
}

STensor3 Frame_field::search(double x, double y, double z)
{
  // Determines the frame/cross at location (x,y,z)
  int index1;
  int index2;
  double distance1;
  double distance2;
  double e2;

  index1 = 0;
  index2 = 0;
  distance1 = 1000000.0;
  distance2 = 1000000.0;
  e2 = 0.000001;
#if defined(HAVE_ANN)
  ANNpoint query;
  ANNidxArray indices;
  ANNdistArray distances;

  if(field.size() <= 1) { return STensor3(1.0); }

  query = annAllocPt(3);
  query[0] = x;
  query[1] = y;
  query[2] = z;

  indices = new ANNidx[2];
  distances = new ANNdist[2];

  double e = 0.0;
  kd_tree->annkSearch(query, 2, indices, distances, e);
  index1 = indices[0];
  index2 = indices[1];
  distance1 = distances[0];
  distance2 = distances[1];

  annDeallocPt(query);
  delete[] indices;
  delete[] distances;
#endif

  if(fabs(sqrt(distance2) - sqrt(distance1)) < e2) {
    if(labels[index2] < labels[index1]) { return field[index2].second; }
    else {
      return field[index1].second;
    }
  }
  else {
    return field[index1].second;
  }
}

STensor3 Frame_field::combine(double x, double y, double z)
{
  // Determines the frame/cross at location (x,y,z)
  // Alternative to Frame_field::search
  bool ok;
  double val1, val2, val3;
  SVector3 vec, other;
  SVector3 vec1, vec2, vec3;
  SVector3 final1, final2;
  STensor3 m(1.0), m2(1.0);

  m = search(x, y, z);
  m2 = m;
  ok = Nearest_point::search(x, y, z, vec);
  vec.normalize();

  if(ok) {
    vec1 = SVector3(m.get_m11(), m.get_m21(), m.get_m31());
    vec2 = SVector3(m.get_m12(), m.get_m22(), m.get_m32());
    vec3 = SVector3(m.get_m13(), m.get_m23(), m.get_m33());

    val1 = fabs(dot(vec, vec1));
    val2 = fabs(dot(vec, vec2));
    val3 = fabs(dot(vec, vec3));

    if(val1 <= val2 && val1 <= val3) { other = vec1; }
    else if(val2 <= val1 && val2 <= val3) {
      other = vec2;
    }
    else {
      other = vec3;
    }

    final1 = crossprod(vec, other);
    final1.normalize();
    final2 = crossprod(vec, final1);
    final2.normalize();

    m2.set_m11(vec.x());
    m2.set_m21(vec.y());
    m2.set_m31(vec.z());
    m2.set_m12(final1.x());
    m2.set_m22(final1.y());
    m2.set_m32(final1.z());
    m2.set_m13(final2.x());
    m2.set_m23(final2.y());
    m2.set_m33(final2.z());
  }

  return m2;
}

void Frame_field::print_segment(const SPoint3 &p1, const SPoint3 &p2,
                                double val1, double val2, std::ofstream &file)
{
  file << "SL (" << p1.x() << ", " << p1.y() << ", " << p1.z() << ", " << p2.x()
       << ", " << p2.y() << ", " << p2.z() << ")"
       << "{" << val1 << "," << val2 << "};\n";
}

void Frame_field::print_field1()
{
  // Saves a file with the surface cross field contained in Frame_field.temp
  // Frame_field.temp is constructed by Frame_field::init_region
  unsigned int i;
  double k;
  double color1;
  double color2;
  SPoint3 point;
  SPoint3 p1, p2, p3, p4, p5, p6;
  STensor3 m(1.0);

  k = 0.05;
  std::ofstream file("frame1.pos");
  file << "View \"cross field\" {\n";
  color1 = 10.0;
  color2 = 20.0;

  for(i = 0; i < field.size(); i++) {
    point = field[i].first;
    m = field[i].second;

    p1 = SPoint3(point.x() + k * m.get_m11(), point.y() + k * m.get_m21(),
                 point.z() + k * m.get_m31());
    p2 = SPoint3(point.x() - k * m.get_m11(), point.y() - k * m.get_m21(),
                 point.z() - k * m.get_m31());
    p3 = SPoint3(point.x() + k * m.get_m12(), point.y() + k * m.get_m22(),
                 point.z() + k * m.get_m32());
    p4 = SPoint3(point.x() - k * m.get_m12(), point.y() - k * m.get_m22(),
                 point.z() - k * m.get_m32());
    p5 = SPoint3(point.x() + k * m.get_m13(), point.y() + k * m.get_m23(),
                 point.z() + k * m.get_m33());
    p6 = SPoint3(point.x() - k * m.get_m13(), point.y() - k * m.get_m23(),
                 point.z() - k * m.get_m33());

    print_segment(point, p1, color1, color2, file);
    print_segment(point, p2, color1, color2, file);
    print_segment(point, p3, color1, color2, file);
    print_segment(point, p4, color1, color2, file);
    print_segment(point, p5, color1, color2, file);
    print_segment(point, p6, color1, color2, file);
  }

  file << "};\n";
}

void Frame_field::print_field2(GRegion *gr)
{
  // Saves a file with the cross fields inside the given GRegion, excluding the
  // boundary.
  double const k = 0.05;
  std::ofstream file("frame2.pos");
  file << "View \"cross field\" {\n";
  double const color1 = 10.0;
  double const color2 = 20.0;

  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() > 2) {
        SPoint3 point = SPoint3(vertex->x(), vertex->y(), vertex->z());
        STensor3 m = search(vertex->x(), vertex->y(), vertex->z());

        SPoint3 p1(point.x() + k * m.get_m11(), point.y() + k * m.get_m21(),
                   point.z() + k * m.get_m31());
        SPoint3 p2(point.x() - k * m.get_m11(), point.y() - k * m.get_m21(),
                   point.z() - k * m.get_m31());
        SPoint3 p3(point.x() + k * m.get_m12(), point.y() + k * m.get_m22(),
                   point.z() + k * m.get_m32());
        SPoint3 p4(point.x() - k * m.get_m12(), point.y() - k * m.get_m22(),
                   point.z() - k * m.get_m32());
        SPoint3 p5(point.x() + k * m.get_m13(), point.y() + k * m.get_m23(),
                   point.z() + k * m.get_m33());
        SPoint3 p6(point.x() - k * m.get_m13(), point.y() - k * m.get_m23(),
                   point.z() - k * m.get_m33());

        print_segment(point, p1, color1, color2, file);
        print_segment(point, p2, color1, color2, file);
        print_segment(point, p3, color1, color2, file);
        print_segment(point, p4, color1, color2, file);
        print_segment(point, p5, color1, color2, file);
        print_segment(point, p6, color1, color2, file);
      }
    }
  }

  file << "};\n";
}

GRegion *Frame_field::test()
{
  GRegion *gr;
  GModel *model = GModel::current();
  gr = *(model->firstRegion());
  return gr;
}

void Frame_field::clear()
{
  Nearest_point::clear();
  field.clear();
  labels.clear();
#if defined(HAVE_ANN)
  delete kd_tree->thePoints();
  delete kd_tree;
  annClose();
#endif
#if defined(HAVE_ANN)
  if(annTree && annTree->thePoints()) delete annTree->thePoints();
  if(annTree) delete annTree;
#endif
}

// double max(const double a, const double b) { return (b>a)?b:a;}
double min(const double a, const double b) { return (b < a) ? b : a; }
double squ(const double a) { return a * a; }

int Frame_field::build_vertex_to_vertices(GEntity *gr, int onWhat,
                                          bool initialize)
{
  // build vertex to vertices data
  std::set<MVertex *> vertices;
  if(initialize) vertex_to_vertices.clear();
  for(unsigned int i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *pElem = gr->getMeshElement(i);
    unsigned int n = pElem->getNumVertices();
    for(unsigned int j = 0; j < n; j++) {
      MVertex *pVertex = pElem->getVertex(j);
      if(onWhat > 0 && pVertex->onWhat()->dim() != onWhat) continue;

      auto it = vertex_to_vertices.find(pVertex);
      if(it != vertex_to_vertices.end()) {
        for(unsigned int k = 1; k < n; k++)
          it->second.insert(pElem->getVertex((j + k) % n));
      }
      else {
        vertices.clear();
        for(unsigned int k = 1; k < n; k++)
          vertices.insert(pElem->getVertex((j + k) % n));
        vertex_to_vertices.insert(
          std::pair<MVertex *, std::set<MVertex *> >(pVertex, vertices));
      }
    }
  }
  return vertex_to_vertices.size();
}

int Frame_field::build_vertex_to_elements(GEntity *gr, bool initialize)
{
  std::set<MElement *> elements;
  if(initialize) vertex_to_elements.clear();
  for(unsigned int i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *pElem = gr->getMeshElement(i);
    unsigned int n = pElem->getNumVertices();
    for(unsigned int j = 0; j < n; j++) {
      MVertex *pVertex = pElem->getVertex(j);
      auto it = vertex_to_elements.find(pVertex);
      if(it != vertex_to_elements.end())
        it->second.insert(pElem);
      else {
        elements.clear();
        elements.insert(pElem);
        vertex_to_elements.insert(
          std::pair<MVertex *, std::set<MElement *> >(pVertex, elements));
      }
    }
  }
  return vertex_to_elements.size();
}

void Frame_field::build_listVertices(GEntity *gr, int dim, bool initialize)
{
  std::set<MVertex *> list;
  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *pElem = gr->getMeshElement(i);
    for(std::size_t j = 0; j < pElem->getNumVertices(); j++) {
      MVertex *pVertex = pElem->getVertex(j);
      if(pVertex->onWhat()->dim() == dim) list.insert(pVertex);
    }
  }
  if(initialize) listVertices.clear();

  for(auto it = list.begin(); it != list.end(); it++) {
    listVertices.push_back(*it);
  }
}

int Frame_field::buildAnnData(GEntity *ge, int dim)
{
  build_listVertices(ge, dim);
  int n = listVertices.size();
#if defined(HAVE_ANN)
  ANNpointArray annTreeData = annAllocPts(n, 3);
  for(int i = 0; i < n; i++) {
    MVertex *pVertex = listVertices[i];
    annTreeData[i][0] = pVertex->x();
    annTreeData[i][1] = pVertex->y();
    annTreeData[i][2] = pVertex->z();
  }
  annTree = new ANNkd_tree(annTreeData, n, 3);
#endif
  std::cout << "ANN data for " << ge->tag() << "(" << dim << ") contains " << n
            << " vertices" << std::endl;
  return n;
}

void Frame_field::deleteAnnData()
{
#if defined(HAVE_ANN)
  if(annTree && annTree->thePoints()) delete annTree->thePoints();
  if(annTree) delete annTree;
  annTree = nullptr;
#endif
}

int Frame_field::findAnnIndex(const SPoint3 &p)
{
  int index = 0;
#if defined(HAVE_ANN)
  ANNpoint query = annAllocPt(3);
  ANNidxArray indices = new ANNidx[1];
  ANNdistArray distances = new ANNdist[1];
  query[0] = p.x();
  query[1] = p.y();
  query[2] = p.z();
  double e = 0.;
  annTree->annkSearch(query, 1, indices, distances, e);
  annDeallocPt(query);
  index = indices[0];
  delete[] indices;
  delete[] distances;
#endif
  return index;
}

void Frame_field::initFace(GFace *gf)
{
  // align crosses of "gf" with the normal (average on neighbour elements)
  // at all vertices of the GFace gf
  build_vertex_to_elements(gf);
  for(std::map<MVertex *, std::set<MElement *> >::const_iterator it =
        vertex_to_elements.begin();
      it != vertex_to_elements.end(); it++) {
    std::set<MElement *> elements = it->second;
    SVector3 Area = SVector3(0, 0, 0);
    for(auto iter = elements.begin(); iter != elements.end(); iter++) {
      MElement *pElem = *iter;
      int n = pElem->getNumVertices();
      int i;
      for(i = 0; i < n; i++) {
        if(pElem->getVertex(i) == it->first) break;
        if(i == n - 1) {
          std::cout << "This should not happen" << std::endl;
          exit(1);
        }
      }
      SVector3 V0 = pElem->getVertex(i)->point();
      SVector3 V1 =
        pElem->getVertex((i + n - 1) % n)->point(); // previous vertex
      SVector3 V2 = pElem->getVertex((i + 1) % n)->point(); // next vertex
      Area += crossprod(V2 - V0, V1 - V0);
    }
    Area.normalize(); // average normal over neighbour face elements
    STensor3 m = convert(cross3D(Area));
    auto iter = crossField.find(it->first);
    if(iter == crossField.end())
      crossField.insert(std::pair<MVertex *, STensor3>(it->first, m));
    else
      crossField[it->first] = m;
  }

  std::cout << "Nodes in face = " << vertex_to_elements.size() << std::endl;

  // compute cumulative cross-data "vertices x elements" for the whole contour
  // of gf
  std::vector<GEdge *> const &edges = gf->edges();
  vertex_to_elements.clear();
  for(auto it = edges.begin(); it != edges.end(); it++) {
    build_vertex_to_elements(*it, false);
  }

  // align crosses of the contour of "gf" with the tangent to the contour
  for(std::map<MVertex *, std::set<MElement *> >::const_iterator it =
        vertex_to_elements.begin();
      it != vertex_to_elements.end(); it++) {
    MVertex *pVertex = it->first;
    std::set<MElement *> elements = it->second;
    if(elements.size() != 2) {
      std::cout << "The face has an open boundary" << std::endl;
      exit(1);
    }
    MEdge edg1 = (*elements.begin())->getEdge(0);
    MEdge edg2 = (*elements.rbegin())->getEdge(0);
    SVector3 tangent = edg1.scaledTangent() + edg2.scaledTangent();
    tangent.normalize();

    auto iter = crossField.find(pVertex);
    if(iter == crossField.end()) {
      std::cout << "This should not happen: cross not found 1" << std::endl;
      exit(1);
    }
    cross3D x(cross3D((*iter).second));
    STensor3 m = convert(cross3D(x.getFrst(), tangent));
    crossField[pVertex] = m;
  }

  // fills ANN data with the vertices of the contour (dim=1) of "gf"
  buildAnnData(gf, 1);

  std::cout << "Nodes on contour = " << vertex_to_elements.size() << std::endl;
  std::cout << "crossField = " << crossField.size() << std::endl;
  std::cout << "region = " << gf->getNumMeshVertices() << std::endl;

  // align crosses.scnd with the nearest cross of the contour
  // fixme: we have to rebuild the vertex_to_elements list
  // to have a working iterator oin the verticies of gf
  // The natural iterator  gf->getMeshVertex(i) seems not to work
  // when the option PackingOfParallelogram is on.
  build_vertex_to_elements(gf);
  for(std::map<MVertex *, std::set<MElement *> >::const_iterator it =
        vertex_to_elements.begin();
      it != vertex_to_elements.end(); it++) {
    // for(unsigned int i=0; i<gf->getNumMeshVertices(); i++){
    // MVertex* pVertex0 = gf->getMeshVertex(i);

    MVertex *pVertex0 = it->first;
    if(pVertex0->onWhat()->dim() != 2) continue;

    auto iter = crossField.find(pVertex0);
    cross3D y;
    if(iter == crossField.end()) {
      std::cout << "This should not happen: cross not found 2" << std::endl;
      std::cout << pVertex0->x() << "," << pVertex0->y() << "," << pVertex0->z()
                << std::endl;
      // exit(1);
      y = cross3D();
    }
    else
      y = cross3D((*iter).second); // local cross y.getFirst() is the normal

    // Find the index of the nearest cross on the contour, using annTree
    int index = findAnnIndex(pVertex0->point());
    MVertex *pVertex = listVertices[index]; // nearest vertex on contour
    iter = crossField.find(pVertex);
    if(iter == crossField.end()) {
      std::cout << "This should not happen: cross not found 3" << std::endl;
      exit(1);
    }
    cross3D x = cross3D(
      (*iter).second); // nearest cross on contour, x.getFrst() is the normal

    // STensor3 m = convert(cross3D(x.getFrst(),y.getScnd()));
    SVector3 v1 = y.getFrst();
    STensor3 m = convert(
      y.rotate(conj(x.rotationToOnSurf(y)))); // rotation around the normal
    SVector3 v2 = y.getFrst();
    if(fabs(angle(v1, v2)) > 1e-8) {
      std::cout << "This should not happen: rotation affected the normal"
                << std::endl;
      exit(1);
    }
    crossField[pVertex0] = m;
  }
  checkAnnData(gf, "zzz.pos");
  deleteAnnData();
}

void Frame_field::initRegion(GRegion *gr, int n)
{
  std::vector<GFace *> faces = gr->faces();
  for(std::vector<GFace *>::const_iterator iter = faces.begin();
      iter != faces.end(); iter++) {
    initFace(*iter);
    // smoothing must be done immediately because crosses on the contour
    // vertices are now initialized with the normal to THIS face.
    smoothFace(*iter, n);
  }

  // Fills ANN data with the vertices of the surface (dim=2) of "gr"
  buildAnnData(gr, 2);
  for(unsigned int i = 0; i < gr->getNumMeshVertices(); i++) {
    MVertex *pVertex0 = gr->getMeshVertex(i);
    if(pVertex0->onWhat()->dim() != 3) continue;
    // Find the index of the nearest cross on the contour, using annTree
    int index = findAnnIndex(pVertex0->point());
    MVertex *pVertex = listVertices[index];
    STensor3 m = crossField[pVertex];
    crossField.insert(std::pair<MVertex *, STensor3>(pVertex0, m));
  }
  deleteAnnData();
  buildAnnData(gr, 3);
}

STensor3 Frame_field::findCross(double x, double y, double z)
{
  int index = Frame_field::findAnnIndex(SPoint3(x, y, z));
  MVertex *pVertex = Frame_field::listVertices[index];
  return crossField[pVertex];
}

double Frame_field::findBarycenter(
  std::map<MVertex *, std::set<MVertex *> >::const_iterator iter, STensor3 &m0)
{
  double theta, gradient, energy;
  STensor3 m;
  SVector3 axis;
  bool debug = false;

  MVertex *pVertex0 = iter->first;
  std::set<MVertex *> list = iter->second;
  cross3D x(m0);
  if(debug)
    std::cout << "#  " << pVertex0->getNum() << " with " << list.size()
              << " neighbours" << std::endl;

  SVector3 T = SVector3(0.), dT;
  double temp = 0.;
  energy = 0;
  for(auto it = list.begin(); it != list.end(); ++it) {
    MVertex *pVertex = *it;
    if(pVertex->getNum() == pVertex0->getNum())
      std::cout << "This should not happen!" << std::endl;
    std::map<MVertex *, STensor3>::const_iterator itB =
      crossField.find(pVertex);
    if(itB == crossField.end()) { // not found
      std::cout << "This should not happen: cross not found 4" << std::endl;
      exit(1);
    }
    else
      m = itB->second;
    cross3D y(m);
    Qtn Rxy = x.rotationTo(y);

    MEdge edge(pVertex0, pVertex);
    theta = eulerAngleFromQtn(Rxy);
    gradient = theta / edge.length();
    energy += gradient * gradient;
    crossDist[edge] = theta;
    if(fabs(theta) > 1e-10) {
      axis = eulerAxisFromQtn(Rxy); // undefined if theta==0
      dT = axis * (theta / edge.length() / edge.length());
      T += dT;
    }
    temp += 1. / edge.length() / edge.length();
  }
  if(temp) T *= 1.0 / temp; // average rotation vector

  theta = T.norm();
  if(fabs(theta) > 1e-10) {
    axis = T;
    if(debug)
      std::cout << "-> " << pVertex0->getNum() << " : " << T << std::endl;
    Qtn R(axis.unit(), theta);
    x.rotate(R);
    m0 = convert(x);
  }
  return energy;
}

void Frame_field::buildSmoothness()
{
  GModel *m = GModel::current();
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  // pour commencer on va creer une map de connectique des Mvertex
  std::map<MVertex *, std::vector<MVertex *> > Neighbours;
  for(unsigned int i = 0; i < entities.size(); i++) {
    GEntity *eTmp = entities[i];
    for(unsigned int j = 0; j < eTmp->getNumMeshElements(); j++) {
      MElement *elem = eTmp->getMeshElement(j);
      for(std::size_t k = 0; k < elem->getNumVertices(); k++) {
        for(std::size_t l = k; l < elem->getNumVertices(); l++) {
          if(k != l) {
            MVertex *v1 = elem->getVertex(k);
            MVertex *v2 = elem->getVertex(l);
            Neighbours[v1].push_back(v2);
            Neighbours[v2].push_back(v1);
          }
        }
      }
    }
  }
  for(unsigned int i = 0; i < entities.size(); i++) {
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      // on va traiter chaque noeud
      std::set<MVertex *> V1;
      std::set<MVertex *> V2;
      std::set<MVertex *> V3;
      MVertex *v0 = entities[i]->mesh_vertices[j];
      V1.insert(v0);
      std::vector<MVertex *> v0vec = Neighbours[v0];
      for(unsigned int k = 0; k < v0vec.size(); k++) { V1.insert(v0vec[k]); }
      for(auto itSet = V1.begin(); itSet != V1.end(); itSet++) {
        MVertex *vTmp = (*itSet);
        V2.insert(vTmp);
        v0vec = Neighbours[vTmp];
        for(unsigned int k = 0; k < v0vec.size(); k++) { V2.insert(v0vec[k]); }
      }
      for(auto itSet = V2.begin(); itSet != V2.end(); itSet++) {
        MVertex *vTmp = (*itSet);
        V3.insert(vTmp);
        v0vec = Neighbours[vTmp];
        for(unsigned int k = 0; k < v0vec.size(); k++) { V3.insert(v0vec[k]); }
      }
      // we have all three set here, time to compute the smoothnesses for each
      // one
      std::vector<cross3D> C1;
      std::vector<cross3D> C2;
      std::vector<cross3D> C3;
      double S1 = 0.0;
      double S2 = 0.0;
      double S3 = 0.0;
      for(auto itSet = V1.begin(); itSet != V1.end(); itSet++) {
        MVertex *vTmp = (*itSet);
        STensor3 tTmp = crossField[vTmp];
        cross3D cTmp = cross3D(tTmp);
        C1.push_back(cTmp);
      }
      for(auto itSet = V2.begin(); itSet != V2.end(); itSet++) {
        MVertex *vTmp = (*itSet);
        STensor3 tTmp = crossField[vTmp];
        cross3D cTmp = cross3D(tTmp);
        C2.push_back(cTmp);
      }
      for(auto itSet = V3.begin(); itSet != V3.end(); itSet++) {
        MVertex *vTmp = (*itSet);
        STensor3 tTmp = crossField[vTmp];
        cross3D cTmp = cross3D(tTmp);
        C3.push_back(cTmp);
      }
      S1 = computeSetSmoothness(C1);
      S2 = computeSetSmoothness(C2);
      S3 = computeSetSmoothness(C3);
      double finalSmoothness = (9.0 * S1 + 3.0 * S2 + S3) / 13.0;
      crossFieldSmoothness[v0] = finalSmoothness;
    }
  }
}

double Frame_field::smoothFace(GFace *gf, int n)
{
  double energy = 0;
  build_vertex_to_vertices(gf, 2);
  build_vertex_to_vertices(gf, 0, false);
  for(int i = 0; i < n; i++) {
    energy = smooth();
    std::cout << "energy = " << energy << std::endl;
  }
  return energy;
}

double Frame_field::smoothRegion(GRegion *gr, int n)
{
  double energy = 0;
  build_vertex_to_vertices(gr, 3);
  // build_vertex_to_vertices(gr, 1, false);
  // build_vertex_to_vertices(gr, 0, false);
  for(int i = 0; i < n; i++) {
    energy = smooth();
    std::cout << "energy = " << energy << std::endl;
  }
  return energy;
}

double Frame_field::smooth()
{
  STensor3 m(1.0), m0(1.0);
  double enew, eold;

  double energy = 0;
  for(std::map<MVertex *, std::set<MVertex *> >::const_iterator iter =
        vertex_to_vertices.begin();
      iter != vertex_to_vertices.end(); ++iter) {
    // MVertex* pVertex0 = iter->first;
    SVector3 T(0, 0, 0);
    auto itA = crossField.find(iter->first);
    if(itA == crossField.end()) {
      std::cout << "This should not happen" << std::endl;
      exit(1);
    }
    else
      m0 = itA->second;

    m = m0;
    unsigned int NbIter = 0;
    enew = findBarycenter(iter, m); // initial energy in cell
    do {
      eold = enew;
      crossField[itA->first] = m;
      enew = findBarycenter(iter, m);
    } while((enew < eold) && (++NbIter < 10));
    energy += eold;
  }
  return energy;
}

void Frame_field::save(const std::vector<std::pair<SPoint3, STensor3> > &data,
                       const std::string &filename)
{
  const cross3D origin(SVector3(1, 0, 0), SVector3(0, 1, 0));
  SPoint3 p1;
  double k = 0.1;
  std::ofstream file(filename.c_str());
  file << "View \"cross field\" {\n";
  for(unsigned int i = 0; i < data.size(); i++) {
    SPoint3 p = data[i].first;
    STensor3 m = data[i].second;
    double val1 = eulerAngleFromQtn(cross3D(m).rotationTo(origin)), val2 = val1;
    p1 = SPoint3(p.x() + k * m.get_m11(), p.y() + k * m.get_m21(),
                 p.z() + k * m.get_m31());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() - k * m.get_m11(), p.y() - k * m.get_m21(),
                 p.z() - k * m.get_m31());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() + k * m.get_m12(), p.y() + k * m.get_m22(),
                 p.z() + k * m.get_m32());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() - k * m.get_m12(), p.y() - k * m.get_m22(),
                 p.z() - k * m.get_m32());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() + k * m.get_m13(), p.y() + k * m.get_m23(),
                 p.z() + k * m.get_m33());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() - k * m.get_m13(), p.y() - k * m.get_m23(),
                 p.z() - k * m.get_m33());
    print_segment(p, p1, val1, val2, file);
  }
  file << "};\n";
  file.close();
}

void Frame_field::recur_connect_vert(FILE *fi, int count, MVertex *v,
                                     STensor3 &cross,
                                     std::multimap<MVertex *, MVertex *> &v2v,
                                     std::set<MVertex *> &touched)
{
  if(touched.find(v) != touched.end()) return;
  touched.insert(v);

  count++;

  for(auto it = v2v.lower_bound(v); it != v2v.upper_bound(v); ++it) {
    MVertex *nextV = it->second;
    if(touched.find(nextV) == touched.end()) {
      // compute dot product (N0,R0,A0) dot (Ni,Ri,Ai)^T
      // where N,R,A are the 3 directions
      auto iter = crossField.find(nextV);
      STensor3 nextCross = iter->second;
      STensor3 nextCrossT = nextCross.transpose();
      STensor3 prod = cross.operator*=(nextCrossT);
      fullMatrix<double> mat(3, 3);
      prod.getMat(mat);

      // find biggest dot product
      fullVector<int> Id(3);
      Id(0) = Id(1) = Id(2) = 0;
      for(int j = 0; j < 3; j++) {
        double maxVal = 0.0;
        for(int i = 0; i < 3; i++) {
          double val = fabs(mat(i, j));
          if(val > maxVal) {
            maxVal = val;
            Id(j) = i;
          }
        }
      }

      // check
      if(Id(0) + Id(1) + Id(2) != 3 ||
         (Id(0) == 1 && Id(1) == 1 && Id(2) == 1)) {
        std::cout << "This should not happen: sum should be 0+1+2" << std::endl;
        printf("Id =%d %d %d \n", Id(0), Id(1), Id(2));
        return;
      }

      // create new cross
      fullMatrix<double> newmat(3, 3);
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) { newmat(i, j) = nextCross(Id(i), j); }
      }

      STensor3 newcross(0.0);
      newcross.setMat(newmat);
      crossField[iter->first] = newcross;

      // print info
      printf("************** COUNT = %d \n", count);
      if(Id(0) == 0 && Id(1) == 1 && Id(2) == 2)
        printf("orient OK Id=%d %d %d\n", Id(0), Id(1), Id(2));
      else {
        printf("change orientation  Id=%d %d %d \n", Id(0), Id(1), Id(2));
        cross.print("cross ");
        nextCross.print("nextCross ");
        prod.print("product");
        newcross.print("newcross");
      }

      if(fi)
        fprintf(fi, "SP(%g,%g,%g) {%g};\n", nextV->x(), nextV->y(), nextV->z(),
                (double)count);

      // continue recursion
      recur_connect_vert(fi, count, nextV, newcross, v2v, touched);
    }
  }
}

void Frame_field::continuousCrossField(GRegion *gr, GFace *gf)
{
  printf("continuous cross field \n");

  // start from a vertex of a face
  std::vector<GFace *> faces = gr->faces();
  bool foundFace = false;
  for(std::vector<GFace *>::const_iterator iter = faces.begin();
      iter != faces.end(); iter++) {
    if(*iter == gf) {
      foundFace = true;
      break;
    }
  }
  if(!foundFace) {
    std::cout << "This should not happen: face does not belong to region"
              << std::endl;
    exit(1);
  }

  // build connectivity
  build_vertex_to_vertices(gr, -1, true);
  std::multimap<MVertex *, MVertex *> v2v;
  for(std::map<MVertex *, std::set<MVertex *> >::const_iterator iter =
        vertex_to_vertices.begin();
      iter != vertex_to_vertices.end(); ++iter) {
    MVertex *v = iter->first;
    std::set<MVertex *> mySet = iter->second;
    for(auto it = mySet.begin(); it != mySet.end(); ++it) {
      v2v.insert(std::make_pair(v, *it));
    }
  }

  // recursive loop
  MVertex *beginV = gf->getMeshVertex(0);
  std::set<MVertex *> touched;
  auto iter = crossField.find(beginV);
  STensor3 bCross = iter->second;

  FILE *fi = Fopen("cross_recur.pos", "w");
  if(fi) {
    fprintf(fi, "View \"\"{\n");
    fprintf(fi, "SP(%g,%g,%g) {%g};\n", beginV->x(), beginV->y(), beginV->z(),
            0.0);
  }
  int count = 0;
  recur_connect_vert(fi, count, beginV, bCross, v2v, touched);
  if(fi) {
    fprintf(fi, "};\n");
    fclose(fi);
  }
  // printf("touched =%d vert =%d \n", touched.size(),
  // vertex_to_vertices.size());
}

void Frame_field::saveCrossField(const std::string &filename, double scale,
                                 bool full)
{
  const cross3D origin(SVector3(1, 0, 0), SVector3(0, 1, 0));
  SPoint3 p1;
  double k = scale;
  std::ofstream file(filename.c_str());
  file << "View \"cross field\" {\n";
  for(std::map<MVertex *, STensor3>::const_iterator it = crossField.begin();
      it != crossField.end(); it++) {
    SPoint3 p = it->first->point();
    STensor3 m = it->second;
    // double val1 = eulerAngleFromQtn(cross3D(m).rotationTo(origin))*180./M_PI,
    // val2=val1;
    double val1 = 1.0, val2 = 1.0;
    p1 = SPoint3(p.x() + k * m.get_m11(), p.y() + k * m.get_m21(),
                 p.z() + k * m.get_m31());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() - k * m.get_m11(), p.y() - k * m.get_m21(),
                 p.z() - k * m.get_m31());
    if(full) print_segment(p, p1, val1, val2, file);
    val1 = 2.0;
    val2 = 2.0;
    p1 = SPoint3(p.x() + k * m.get_m12(), p.y() + k * m.get_m22(),
                 p.z() + k * m.get_m32());
    print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() - k * m.get_m12(), p.y() - k * m.get_m22(),
                 p.z() - k * m.get_m32());
    if(full) print_segment(p, p1, val1, val2, file);
    val1 = 3.0;
    val2 = 3.0;
    p1 = SPoint3(p.x() + k * m.get_m13(), p.y() + k * m.get_m23(),
                 p.z() + k * m.get_m33());
    if(full) print_segment(p, p1, val1, val2, file);
    p1 = SPoint3(p.x() - k * m.get_m13(), p.y() - k * m.get_m23(),
                 p.z() - k * m.get_m33());
    if(full) print_segment(p, p1, val1, val2, file);
  }
  file << "};\n";
  file.close();
}

void Frame_field::save_dist(const std::string &filename)
{
  std::ofstream file(filename.c_str());
  file << "View \"Distance\" {\n";

  for(auto it = crossDist.begin(); it != crossDist.end(); it++) {
    MVertex *pVerta = it->first.getVertex(0);
    MVertex *pVertb = it->first.getVertex(1);
    double value = it->second * 180. / M_PI;
    if(it->first.length()) value /= it->first.length();
    file << "SL (" << pVerta->x() << ", " << pVerta->y() << ", " << pVerta->z()
         << ", " << pVertb->x() << ", " << pVertb->y() << ", " << pVertb->z()
         << ")"
         << "{" << value << "," << value << "};\n";
  }
  file << "};\n";
  file.close();
}

void Frame_field::checkAnnData(GEntity *ge, const std::string &filename)
{
#if defined(HAVE_ANN)
  std::ofstream file(filename.c_str());
  file << "View \"ANN pairing\" {\n";
  for(unsigned int i = 0; i < ge->getNumMeshVertices(); i++) {
    MVertex *pVerta = ge->getMeshVertex(i);
    MVertex *pVertb = listVertices[findAnnIndex(pVerta->point())];
    double value = pVerta->distance(pVertb);
    file << "SL (" << pVerta->x() << ", " << pVerta->y() << ", " << pVerta->z()
         << ", " << pVertb->x() << ", " << pVertb->y() << ", " << pVertb->z()
         << ")"
         << "{" << value << "," << value << "};\n";
  }
  file << "};\n";
  file.close();
#endif
}

void Frame_field::save_energy(GRegion *gr, const std::string &filename)
{
#if defined(HAVE_POST)
  MElement *pElem;
  const int order = 1;
  const int NumNodes = 4;

  PViewDataList *data = new PViewDataList();
  for(unsigned int i = 0; i < gr->getNumMeshElements(); i++) {
    pElem = gr->getMeshElement(i);
    MTetrahedron *pTet =
      new MTetrahedron(pElem->getVertex(0), pElem->getVertex(1),
                       pElem->getVertex(2), pElem->getVertex(3));
    // std::vector<double> *out = data->incrementList(1, TYPE_TET, NumNodes);
    std::vector<double> *out = data->incrementList(3, TYPE_TET, NumNodes);
    for(std::size_t j = 0; j < pTet->getNumVertices(); j++)
      out->push_back(pTet->getVertex(j)->x());
    for(std::size_t j = 0; j < pTet->getNumVertices(); j++)
      out->push_back(pTet->getVertex(j)->y());
    for(std::size_t j = 0; j < pTet->getNumVertices(); j++)
      out->push_back(pTet->getVertex(j)->z());
    for(std::size_t j = 0; j < pTet->getNumVertices(); j++) {
      double u, v, w;
      pTet->getNode(j, u, v, w);
      double sf[4], gsf[4][3];
      pTet->getShapeFunctions(u, v, w, sf, order);
      pTet->getGradShapeFunctions(u, v, w, gsf, order);
      double jac[3][3], inv[3][3];
      pTet->getJacobian(u, v, w, jac);
      inv3x3(jac, inv);
      SVector3 sum(0, 0, 0);
      for(int k = 0; k < pTet->getNumEdges(); k++) {
        int nod1 = pTet->edges_tetra(k, 0);
        int nod2 = pTet->edges_tetra(k, 1);
        double grd1[3], grd2[3];
        matvec(inv, gsf[nod1], grd1);
        matvec(inv, gsf[nod2], grd2);
        SVector3 esf = sf[nod1] * SVector3(grd2) - sf[nod2] * SVector3(grd1);
        auto it = crossDist.find(pTet->getEdge(k));
        sum += it->second * esf;
        // sum += (pTet->getVertex(nod2)->z() - pTet->getVertex(nod1)->z()) *
        // esf;
      }
      out->push_back(sum[0]);
      out->push_back(sum[1]);
      out->push_back(sum[2]);
      // out->push_back(sum.norm());
    }
    delete pTet;
  }
  data->setName("energy");
  // data->setFileName("energ.pos");
  data->writePOS(filename + ".pos");
  data->writeMSH(filename + ".msh");
  data->finalize();
#endif
}

Size_field::Size_field() {}

void Size_field::init_region(GRegion *gr)
{
#if defined(HAVE_ANN)

  GModel *model = GModel::current();

  std::vector<GFace *> faces = gr->faces();

  field.clear();
  field.reserve(faces.size());

  std::vector<GFace *>::iterator it;
  for(it = faces.begin(); it != faces.end(); it++) {
    GFace *gf = *it;

    for(std::size_t i = 0; i < gf->storage1.size(); i++) {
      SPoint3 point = gf->storage1[i];
      double const h = gf->storage4[i];

      field.push_back(std::pair<SPoint3, double>(point, h));
    }
  }

  ANNpointArray duplicate = annAllocPts(field.size(), 3);

  for(std::size_t i = 0; i < field.size(); i++) {
    duplicate[i][0] = field[i].first.x();
    duplicate[i][1] = field[i].first.y();
    duplicate[i][2] = field[i].first.z();
  }

  kd_tree = new ANNkd_tree(duplicate, field.size(), 3);

  boundary.clear();

  ANNpoint query = annAllocPt(3);
  ANNidxArray indices = new ANNidx[1];
  ANNdistArray distances = new ANNdist[1];

  int index = 0;
  double e = 0.0;

  for(it = faces.begin(); it != faces.end(); it++) {
    GFace *gf = *it;

    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *element = gf->getMeshElement(i);
      for(std::size_t j = 0; j < element->getNumVertices(); j++) {
        MVertex *vertex = element->getVertex(j);

        query[0] = vertex->x();
        query[1] = vertex->y();
        query[2] = vertex->z();

        kd_tree->annkSearch(query, 1, indices, distances, e);
        index = indices[0];

        boundary.insert(
          std::pair<MVertex *, double>(vertex, field[index].second));
      }
    }
  }

  octree = new MElementOctree(model);

  annDeallocPt(query);
  delete[] indices;
  delete[] distances;
#endif
}

void Size_field::solve(GRegion *gr)
{
#if defined(HAVE_SOLVER)

#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *system = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *system = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *system = new linearSystemFull<double>;
#endif

  size_t i;
  int count;
  int count2;
  double val;
  double volume;
  std::set<MVertex *> interior;
  std::set<MVertex *>::iterator it;
  std::map<MVertex *, double>::iterator it2;

  interior.clear();

  dofManager<double> assembler(system);

  count = 0;
  for(it2 = boundary.begin(); it2 != boundary.end(); it2++) {
    assembler.fixVertex(it2->first, 0, 1, it2->second);
    count++;
  }
  // printf("\n");
  // printf("number of boundary vertices = %d\n",count);

  for(i = 0; i < gr->tetrahedra.size(); i++) {
    interior.insert(gr->tetrahedra[i]->getVertex(0));
    interior.insert(gr->tetrahedra[i]->getVertex(1));
    interior.insert(gr->tetrahedra[i]->getVertex(2));
    interior.insert(gr->tetrahedra[i]->getVertex(3));
  }

  for(it = interior.begin(); it != interior.end(); it++) {
    it2 = boundary.find(*it);
    if(it2 == boundary.end()) { assembler.numberVertex(*it, 0, 1); }
  }

  for(i = 0; i < gr->tetrahedra.size(); i++) {
    gr->tetrahedra[i]->setVolumePositive();
  }

  count2 = 0;
  volume = 0.0;
  simpleFunction<double> ONE(1.0);
  laplaceTerm term(nullptr, 1, &ONE);
  for(i = 0; i < gr->tetrahedra.size(); i++) {
    SElement se(gr->tetrahedra[i]);
    term.addToMatrix(assembler, &se);
    count2++;
    volume = volume + gr->tetrahedra[i]->getVolume();
  }
  // printf("number of tetrahedra = %d\n",count2);
  // printf("volume = %f\n",volume);

  if(assembler.sizeOfR()) { system->systemSolve(); }

  for(it = interior.begin(); it != interior.end(); it++) {
    assembler.getDofValue(*it, 0, 1, val);
    boundary.insert(std::pair<MVertex *, double>(*it, val));
  }

  delete system;
#endif
}

double Size_field::search(double x, double y, double z)
{
  double u, v, w;
  double val;
  MElement *element;
  double temp1[3];
  double temp2[3];
  std::map<MVertex *, double>::iterator it1;
  std::map<MVertex *, double>::iterator it2;
  std::map<MVertex *, double>::iterator it3;
  std::map<MVertex *, double>::iterator it4;

  val = 1.0;

  element = (MElement *)octree->find(x, y, z, 3, true);

  if(element != nullptr) {
    temp1[0] = x;
    temp1[1] = y;
    temp1[2] = z;

    element->xyz2uvw(temp1, temp2);

    u = temp2[0];
    v = temp2[1];
    w = temp2[2];

    it1 = boundary.find(element->getVertex(0));
    it2 = boundary.find(element->getVertex(1));
    it3 = boundary.find(element->getVertex(2));
    it4 = boundary.find(element->getVertex(3));

    if(it1 != boundary.end() && it2 != boundary.end() &&
       it3 != boundary.end() && it4 != boundary.end()) {
      val = (it1->second) * (1.0 - u - v - w) + (it2->second) * u +
            (it3->second) * v + (it4->second) * w;
    }
  }

  return val;
}

void Size_field::print_field(GRegion *gr)
{
  size_t i;
  double min, max;
  // double x,y,z;
  double x1, y1, z1, h1;
  double x2, y2, z2, h2;
  double x3, y3, z3, h3;
  double x4, y4, z4, h4;
  std::map<MVertex *, double>::iterator it;
  std::map<MVertex *, double>::iterator it1;
  std::map<MVertex *, double>::iterator it2;
  std::map<MVertex *, double>::iterator it3;
  std::map<MVertex *, double>::iterator it4;

  min = 1000000000.0;
  max = -1000000000.0;

  for(it = boundary.begin(); it != boundary.end(); it++) {
    // x = (it->first)->x();
    // y = (it->first)->y();
    // z = (it->first)->z();

    if(it->second > max) { max = it->second; }

    if(it->second < min) { min = it->second; }

    // printf("x = %f, y = %f, z = %f, mesh size = %f\n",x,y,z,it->second);
  }

  // printf("\n");

  printf("min mesh size = %f\n", min);
  printf("max mesh size = %f\n", max);

  printf("total number of vertices = %zu\n", boundary.size());
  printf("\n");

  std::ofstream file("laplace.pos");
  file << "View \"test\" {\n";

  for(i = 0; i < gr->tetrahedra.size(); i++) {
    x1 = gr->tetrahedra[i]->getVertex(0)->x();
    y1 = gr->tetrahedra[i]->getVertex(0)->y();
    z1 = gr->tetrahedra[i]->getVertex(0)->z();
    it1 = boundary.find(gr->tetrahedra[i]->getVertex(0));

    x2 = gr->tetrahedra[i]->getVertex(1)->x();
    y2 = gr->tetrahedra[i]->getVertex(1)->y();
    z2 = gr->tetrahedra[i]->getVertex(1)->z();
    it2 = boundary.find(gr->tetrahedra[i]->getVertex(1));

    x3 = gr->tetrahedra[i]->getVertex(2)->x();
    y3 = gr->tetrahedra[i]->getVertex(2)->y();
    z3 = gr->tetrahedra[i]->getVertex(2)->z();
    it3 = boundary.find(gr->tetrahedra[i]->getVertex(2));

    x4 = gr->tetrahedra[i]->getVertex(3)->x();
    y4 = gr->tetrahedra[i]->getVertex(3)->y();
    z4 = gr->tetrahedra[i]->getVertex(3)->z();
    it4 = boundary.find(gr->tetrahedra[i]->getVertex(3));

    if(it1 != boundary.end() && it2 != boundary.end() &&
       it3 != boundary.end() && it4 != boundary.end()) {
      h1 = it1->second;
      h2 = it2->second;
      h3 = it3->second;
      h4 = it4->second;

      file << "SS (" << x1 << ", " << y1 << ", " << z1 << ", " << x2 << ", "
           << y2 << ", " << z2 << ", " << x3 << ", " << y3 << ", " << z3 << ", "
           << x4 << ", " << y4 << ", " << z4 << "){" << h1 << ", " << h2 << ", "
           << h3 << ", " << h4 << "};\n";
    }
  }

  file << "};\n";
}

GRegion *Size_field::test()
{
  GRegion *gr;
  GModel *model = GModel::current();

  gr = *(model->firstRegion());

  return gr;
}

void Size_field::clear()
{
  delete octree;
  field.clear();
  boundary.clear();
#if defined(HAVE_ANN)
  delete kd_tree->thePoints();
  delete kd_tree;
  annClose();
#endif
}

Nearest_point::Nearest_point() {}

void Nearest_point::init_region(GRegion *gr)
{
#if defined(HAVE_ANN)
  unsigned int i;
  int j;
  int gauss_num;
  double u, v;
  double x, y, z;
  double x1, y1, z1;
  double x2, y2, z2;
  double x3, y3, z3;
  MElement *element;
  GFace *gf;
  std::set<MVertex *> temp;
  std::vector<GFace *>::iterator it;
  std::set<MVertex *>::iterator it2;
  fullMatrix<double> gauss_points;
  fullVector<double> gauss_weights;

  gaussIntegration::getTriangle(8, gauss_points, gauss_weights);
  gauss_num = gauss_points.size1();

  std::vector<GFace *> faces = gr->faces();

  field.clear();
  vicinity.clear();
  temp.clear();

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;
    for(i = 0; i < gf->getNumMeshElements(); i++) {
      element = gf->getMeshElement(i);

      x1 = element->getVertex(0)->x();
      y1 = element->getVertex(0)->y();
      z1 = element->getVertex(0)->z();

      x2 = element->getVertex(1)->x();
      y2 = element->getVertex(1)->y();
      z2 = element->getVertex(1)->z();

      x3 = element->getVertex(2)->x();
      y3 = element->getVertex(2)->y();
      z3 = element->getVertex(2)->z();

      for(j = 0; j < gauss_num; j++) {
        u = gauss_points(j, 0);
        v = gauss_points(j, 1);

        x = T(u, v, x1, x2, x3);
        y = T(u, v, y1, y2, y3);
        z = T(u, v, z1, z2, z3);

        field.push_back(SPoint3(x, y, z));
        vicinity.push_back(element);
      }

      temp.insert(element->getVertex(0));
      temp.insert(element->getVertex(1));
      temp.insert(element->getVertex(2));
    }
  }

  for(it2 = temp.begin(); it2 != temp.end(); it2++) {
    x = (*it2)->x();
    y = (*it2)->y();
    z = (*it2)->z();
    // field.push_back(SPoint3(x,y,z));
    // vicinity.push_back(NULL);
  }

  ANNpointArray duplicate = annAllocPts(field.size(), 3);

  for(i = 0; i < field.size(); i++) {
    duplicate[i][0] = field[i].x();
    duplicate[i][1] = field[i].y();
    duplicate[i][2] = field[i].z();
  }

  kd_tree = new ANNkd_tree(duplicate, field.size(), 3);
#endif
}

bool Nearest_point::search(double x, double y, double z, SVector3 &vec)
{
  int index;
  bool val = false;
#if defined(HAVE_ANN)
  double e;
  double e2;
  SPoint3 found;
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
  kd_tree->annkSearch(query, 1, indices, distances, e);
  index = indices[0];

  annDeallocPt(query);
  delete[] indices;
  delete[] distances;

  if(vicinity[index] != nullptr) {
    found = closest(vicinity[index], SPoint3(x, y, z));
  }
  else {
    found = field[index];
  }

  e2 = 0.000001;

  if(fabs(found.x() - x) > e2 || fabs(found.y() - y) > e2 ||
     fabs(found.z() - z) > e2) {
    vec = SVector3(found.x() - x, found.y() - y, found.z() - z);
    vec.normalize();
    val = 1;
  }
  else {
    vec = SVector3(1.0, 0.0, 0.0);
    val = 0;
  }
#endif

  return val;
}

double Nearest_point::T(double u, double v, double val1, double val2,
                        double val3)
{
  return (1.0 - u - v) * val1 + u * val2 + v * val3;
}

// The following method comes from this page :
// gamedev.net/topic/552906-closest-point-on-triangle. It can also be found on
// this page : geometrictools.com/LibMathematics/Distance/Distance.html

SPoint3 Nearest_point::closest(MElement *element, const SPoint3 &point)
{
  SVector3 edge0 =
    SVector3(element->getVertex(1)->x() - element->getVertex(0)->x(),
             element->getVertex(1)->y() - element->getVertex(0)->y(),
             element->getVertex(1)->z() - element->getVertex(0)->z());
  SVector3 edge1 =
    SVector3(element->getVertex(2)->x() - element->getVertex(0)->x(),
             element->getVertex(2)->y() - element->getVertex(0)->y(),
             element->getVertex(2)->z() - element->getVertex(0)->z());
  SVector3 v0 = SVector3(element->getVertex(0)->x() - point.x(),
                         element->getVertex(0)->y() - point.y(),
                         element->getVertex(0)->z() - point.z());

  double a = dot(edge0, edge0);
  double b = dot(edge0, edge1);
  double c = dot(edge1, edge1);
  double d = dot(edge0, v0);
  double e = dot(edge1, v0);

  double det = a * c - b * b;
  double s = b * e - c * d;
  double t = b * d - a * e;

  if(s + t < det) {
    if(s < 0.0) {
      if(t < 0.0) {
        if(d < 0.0) {
          s = clamp(-d / a, 0.0, 1.0);
          t = 0.0;
        }
        else {
          s = 0.0;
          t = clamp(-e / c, 0.0, 1.0);
        }
      }
      else {
        s = 0.0;
        t = clamp(-e / c, 0.0, 1.0);
      }
    }
    else if(t < 0.0) {
      s = clamp(-d / a, 0.0, 1.0);
      t = 0.0;
    }
    else {
      double invDet = 1.0 / det;
      s *= invDet;
      t *= invDet;
    }
  }
  else {
    if(s < 0.0) {
      double tmp0 = b + d;
      double tmp1 = c + e;
      if(tmp1 > tmp0) {
        double numer = tmp1 - tmp0;
        double denom = a - 2.0 * b + c;
        s = clamp(numer / denom, 0.0, 1.0);
        t = 1.0 - s;
      }
      else {
        t = clamp(-e / c, 0.0, 1.0);
        s = 0.0;
      }
    }
    else if(t < 0.0) {
      if(a + d > b + e) {
        double numer = c + e - b - d;
        double denom = a - 2.0 * b + c;
        s = clamp(numer / denom, 0.0, 1.0);
        t = 1.0 - s;
      }
      else {
        s = clamp(-e / c, 0.0, 1.0);
        t = 0.0;
      }
    }
    else {
      double numer = c + e - b - d;
      double denom = a - 2.0 * b + c;
      s = clamp(numer / denom, 0.0, 1.0);
      t = 1.0 - s;
    }
  }

  return SPoint3(element->getVertex(0)->x() + s * edge0.x() + t * edge1.x(),
                 element->getVertex(0)->y() + s * edge0.y() + t * edge1.y(),
                 element->getVertex(0)->z() + s * edge0.z() + t * edge1.z());
}

double Nearest_point::clamp(double x, double min, double max)
{
  double val;

  val = x;

  if(val < min) { val = min; }
  else if(val > max) {
    val = max;
  }

  return val;
}

void Nearest_point::print_field(GRegion *gr)
{
  SVector3 vec;

  double const k = 0.05;
  std::ofstream file("nearest.pos");
  file << "View \"test\" {\n";

  for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
    MElement *element = gr->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      double x = vertex->x();
      double y = vertex->y();
      double z = vertex->z();
      bool const val = search(x, y, z, vec);
      if(val) {
        print_segment(
          SPoint3(x + k * vec.x(), y + k * vec.y(), z + k * vec.z()),
          SPoint3(x - k * vec.x(), y - k * vec.y(), z - k * vec.z()), file);
      }
    }
  }

  file << "};\n";
}

void Nearest_point::print_segment(const SPoint3 &p1, const SPoint3 &p2,
                                  std::ofstream &file)
{
  file << "SL (" << p1.x() << ", " << p1.y() << ", " << p1.z() << ", " << p2.x()
       << ", " << p2.y() << ", " << p2.z() << ")"
       << "{10, 20};\n";
}

GRegion *Nearest_point::test()
{
  GRegion *gr;
  GModel *model = GModel::current();

  gr = *(model->firstRegion());

  return gr;
}

void Nearest_point::clear()
{
  field.clear();
  vicinity.clear();
#if defined(HAVE_ANN)
  delete kd_tree->thePoints();
  delete kd_tree;
  annClose();
#endif
}

// static declarations

std::vector<std::pair<SPoint3, STensor3> > Frame_field::field;
std::vector<int> Frame_field::labels;
std::map<MVertex *, STensor3> Frame_field::crossField;
std::map<MVertex *, double> Frame_field::crossFieldSmoothness;
std::map<MEdge, double, MEdgeLessThan> Frame_field::crossDist;
std::map<MVertex *, std::set<MVertex *> > Frame_field::vertex_to_vertices;
std::map<MVertex *, std::set<MElement *> > Frame_field::vertex_to_elements;
std::vector<MVertex *> Frame_field::listVertices;
#if defined(HAVE_ANN)
ANNkd_tree *Frame_field::kd_tree;
ANNkd_tree *Frame_field::annTree;
#endif

std::vector<std::pair<SPoint3, double> > Size_field::field;
std::map<MVertex *, double> Size_field::boundary;
MElementOctree *Size_field::octree;
#if defined(HAVE_ANN)
ANNkd_tree *Size_field::kd_tree;
#endif

std::vector<SPoint3> Nearest_point::field;
std::vector<MElement *> Nearest_point::vicinity;
#if defined(HAVE_ANN)
ANNkd_tree *Nearest_point::kd_tree;
#endif
