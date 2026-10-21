// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier
//   François Henrotte

#include <fstream>
#include "GModel.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunay.h"
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
  // Fill in a search tree with the boundary cross field of region gr
  unsigned int i;
  GFace *gf;
  std::vector<GFace *> faces;
  std::vector<GFace *>::iterator it;

  faces = gr->faces();

  field.clear();
  labels.clear();

  for(it = faces.begin(); it != faces.end(); it++) {
    gf = *it;
    init_face(gf);
  }

  fieldSearch.clear();
  for(i = 0; i < field.size(); i++)
    fieldSearch.points().push_back(field[i].first);
  fieldSearch.build();
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

  //  printf("face %d storage size %zu\n",gf->tag(), gf->storage1.size());

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
  std::size_t near[2];
  return search(x, y, z, near);
}

STensor3 Frame_field::search(double x, double y, double z,
                             std::size_t near[2], const std::size_t *hint)
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
  std::size_t indices[2];
  double distances[2];
  const SPoint3 p(x, y, z);
  std::size_t found = 0;
  if(hint && hint[0] < field.size() && hint[1] < field.size()) {
    // the 2 nearest points are not farther than the farthest of the 2 hints
    auto dist2 = [&p](const SPoint3 &q) {
      const double dx = p.x() - q.x(), dy = p.y() - q.y(), dz = p.z() - q.z();
      return dx * dx + dy * dy + dz * dz;
    };
    const double d2 =
      std::max(dist2(field[hint[0]].first), dist2(field[hint[1]].first));
    found = fieldSearch.nearestWithin(p, 2, indices, distances,
                                      d2 * (1. + 1.e-12) + 1.e-300);
  }
  if(found < 2) found = fieldSearch.nearest(p, 2, indices, distances);
  if(found < 2) {
    near[0] = near[1] = field.size();
    return STensor3(1.0);
  }
  near[0] = indices[0];
  near[1] = indices[1];
  index1 = indices[0];
  index2 = indices[1];
  distance1 = distances[0];
  distance2 = distances[1];

  if(fabs(sqrt(distance2) - sqrt(distance1)) < e2) {
    if(labels[index2] < labels[index1]) {
      return field[index2].second;
    }
    else {
      return field[index1].second;
    }
  }
  else {
    return field[index1].second;
  }
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
  field.clear();
  labels.clear();
  fieldSearch.clear();
  vertexSearch.clear();
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

      std::map<MVertex *, std::set<MVertex *> >::iterator it =
        vertex_to_vertices.find(pVertex);
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
      std::map<MVertex *, std::set<MElement *> >::iterator it =
        vertex_to_elements.find(pVertex);
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

  for(std::set<MVertex *>::const_iterator it = list.begin(); it != list.end();
      it++) {
    listVertices.push_back(*it);
  }
}

int Frame_field::buildSearchData(GEntity *ge, int dim)
{
  build_listVertices(ge, dim);
  int n = listVertices.size();
  vertexSearch.clear();
  for(int i = 0; i < n; i++)
    vertexSearch.points().push_back(listVertices[i]->point());
  vertexSearch.build();
  std::cout << "Search data for " << ge->tag() << "(" << dim << ") contains "
            << n << " vertices" << std::endl;
  return n;
}

void Frame_field::deleteSearchData()
{
  vertexSearch.clear();
}

int Frame_field::findNearestIndex(const SPoint3 &p)
{
  std::size_t index = vertexSearch.nearest(p);
  return index < vertexSearch.size() ? (int)index : 0;
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
    for(std::set<MElement *>::const_iterator iter = elements.begin();
        iter != elements.end(); iter++) {
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
    std::map<MVertex *, STensor3>::iterator iter = crossField.find(it->first);
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
  for(std::vector<GEdge *>::const_iterator it = edges.begin();
      it != edges.end(); it++) {
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

    std::map<MVertex *, STensor3>::iterator iter = crossField.find(pVertex);
    if(iter == crossField.end()) {
      std::cout << "This should not happen: cross not found 1" << std::endl;
      exit(1);
    }
    cross3D x(cross3D((*iter).second));
    STensor3 m = convert(cross3D(x.getFrst(), tangent));
    crossField[pVertex] = m;
  }

  // fills search data with the vertices of the contour (dim=1) of "gf"
  buildSearchData(gf, 1);

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

    std::map<MVertex *, STensor3>::iterator iter = crossField.find(pVertex0);
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

    // Find the index of the nearest cross on the contour, using vertexSearch
    int index = findNearestIndex(pVertex0->point());
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
  checkSearchData(gf, "zzz.pos");
  deleteSearchData();
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

  // Fills search data with the vertices of the surface (dim=2) of "gr"
  buildSearchData(gr, 2);
  for(unsigned int i = 0; i < gr->getNumMeshVertices(); i++) {
    MVertex *pVertex0 = gr->getMeshVertex(i);
    if(pVertex0->onWhat()->dim() != 3) continue;
    // Find the index of the nearest cross on the contour, using vertexSearch
    int index = findNearestIndex(pVertex0->point());
    MVertex *pVertex = listVertices[index];
    STensor3 m = crossField[pVertex];
    crossField.insert(std::pair<MVertex *, STensor3>(pVertex0, m));
  }
  deleteSearchData();
  buildSearchData(gr, 3);
}

STensor3 Frame_field::findCross(double x, double y, double z)
{
  int index = Frame_field::findNearestIndex(SPoint3(x, y, z));
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
  for(std::set<MVertex *>::const_iterator it = list.begin(); it != list.end();
      ++it) {
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
      for(unsigned int k = 0; k < v0vec.size(); k++) {
        V1.insert(v0vec[k]);
      }
      for(std::set<MVertex *>::iterator itSet = V1.begin(); itSet != V1.end();
          itSet++) {
        MVertex *vTmp = (*itSet);
        V2.insert(vTmp);
        v0vec = Neighbours[vTmp];
        for(unsigned int k = 0; k < v0vec.size(); k++) {
          V2.insert(v0vec[k]);
        }
      }
      for(std::set<MVertex *>::iterator itSet = V2.begin(); itSet != V2.end();
          itSet++) {
        MVertex *vTmp = (*itSet);
        V3.insert(vTmp);
        v0vec = Neighbours[vTmp];
        for(unsigned int k = 0; k < v0vec.size(); k++) {
          V3.insert(v0vec[k]);
        }
      }
      // we have all three set here, time to compute the smoothnesses for each
      // one
      std::vector<cross3D> C1;
      std::vector<cross3D> C2;
      std::vector<cross3D> C3;
      double S1 = 0.0;
      double S2 = 0.0;
      double S3 = 0.0;
      for(std::set<MVertex *>::iterator itSet = V1.begin(); itSet != V1.end();
          itSet++) {
        MVertex *vTmp = (*itSet);
        STensor3 tTmp = crossField[vTmp];
        cross3D cTmp = cross3D(tTmp);
        C1.push_back(cTmp);
      }
      for(std::set<MVertex *>::iterator itSet = V2.begin(); itSet != V2.end();
          itSet++) {
        MVertex *vTmp = (*itSet);
        STensor3 tTmp = crossField[vTmp];
        cross3D cTmp = cross3D(tTmp);
        C2.push_back(cTmp);
      }
      for(std::set<MVertex *>::iterator itSet = V3.begin(); itSet != V3.end();
          itSet++) {
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
    std::map<MVertex *, STensor3>::iterator itA = crossField.find(iter->first);
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

  for(std::multimap<MVertex *, MVertex *>::iterator it = v2v.lower_bound(v);
      it != v2v.upper_bound(v); ++it) {
    MVertex *nextV = it->second;
    if(touched.find(nextV) == touched.end()) {
      // compute dot product (N0,R0,A0) dot (Ni,Ri,Ai)^T
      // where N,R,A are the 3 directions
      std::map<MVertex *, STensor3>::iterator iter = crossField.find(nextV);
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
        for(int j = 0; j < 3; j++) {
          newmat(i, j) = nextCross(Id(i), j);
        }
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
    for(std::set<MVertex *>::iterator it = mySet.begin(); it != mySet.end();
        ++it) {
      v2v.insert(std::make_pair(v, *it));
    }
  }

  // recursive loop
  MVertex *beginV = gf->getMeshVertex(0);
  std::set<MVertex *> touched;
  std::map<MVertex *, STensor3>::iterator iter = crossField.find(beginV);
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

  for(std::map<MEdge, double, MEdgeLessThan>::iterator it = crossDist.begin();
      it != crossDist.end(); it++) {
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

void Frame_field::checkSearchData(GEntity *ge, const std::string &filename)
{
  std::ofstream file(filename.c_str());
  file << "View \"Nearest pairing\" {\n";
  for(unsigned int i = 0; i < ge->getNumMeshVertices(); i++) {
    MVertex *pVerta = ge->getMeshVertex(i);
    MVertex *pVertb = listVertices[findNearestIndex(pVerta->point())];
    double value = pVerta->distance(pVertb);
    file << "SL (" << pVerta->x() << ", " << pVerta->y() << ", " << pVerta->z()
         << ", " << pVertb->x() << ", " << pVertb->y() << ", " << pVertb->z()
         << ")"
         << "{" << value << "," << value << "};\n";
  }
  file << "};\n";
  file.close();
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
        std::map<MEdge, double, MEdgeLessThan>::iterator it =
          crossDist.find(pTet->getEdge(k));
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

// static declarations

std::vector<std::pair<SPoint3, STensor3> > Frame_field::field;
std::vector<int> Frame_field::labels;
std::map<MVertex *, STensor3> Frame_field::crossField;
std::map<MVertex *, double> Frame_field::crossFieldSmoothness;
std::map<MEdge, double, MEdgeLessThan> Frame_field::crossDist;
std::map<MVertex *, std::set<MVertex *> > Frame_field::vertex_to_vertices;
std::map<MVertex *, std::set<MElement *> > Frame_field::vertex_to_elements;
std::vector<MVertex *> Frame_field::listVertices;
SPoint3Search Frame_field::fieldSearch;
SPoint3Search Frame_field::vertexSearch;
