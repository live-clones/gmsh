// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "BackgroundMesh2D.h"
#include "BackgroundMeshTools.h"

#include "GmshMessage.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "Numeric.h"
#include "MLine.h"
#include "MTriangle.h"
#include "Field.h"
#include "OS.h"
#include "Context.h"
#include "meshGFaceOptimize.h"

#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#endif

class evalDiffusivityFunction : public simpleFunction<double> {
public:
  evalDiffusivityFunction(frameFieldBackgroundMesh2D *_bgm, double t = 0.95)
    : bgm(_bgm), threshold(t){};
  double operator()(double u, double v, double w) const
  {
    return ((bgm->get_smoothness(u, v) >= threshold) ? 1. : 1.e-3);
  }

private:
  frameFieldBackgroundMesh2D *bgm;
  const double threshold;
};

// TODO: move this fct ???
/* applies rotations of amplitude pi to set the
   angle in the first quadrant (in [0,pi/2[ ) */
void normalizeAngle(double &angle)
{
  if(angle < 0)
    while(angle < 0) angle += (M_PI * .5);
  else if(angle >= M_PI * .5)
    while(angle >= M_PI * .5) angle -= (M_PI * .5);
}

void backgroundMesh2D::create_face_mesh()
{
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return;
  }

  quadsToTriangles(face, 100000);

  // storing the initial mesh from GFace
  tempTR.clear();

  for(unsigned int i = 0; i < face->triangles.size(); i++)
    tempTR.push_back(new MTriangle(face->triangles[i]->getVertex(0),
                                   face->triangles[i]->getVertex(1),
                                   face->triangles[i]->getVertex(2)));

  // avoid computing curvatures on the fly : only on the
  // BGM computes once curvatures at each node
  //  Disable curvature control
  int CurvControl = CTX::instance()->mesh.lcFromCurvature;
  CTX::instance()->mesh.lcFromCurvature = 0;
  //  Create a background mesh
  bowyerWatson(face, 4000);
  //  Re-enable curv control if asked
  CTX::instance()->mesh.lcFromCurvature = CurvControl;

  // creates a copy of GFace's vertices and triangles
  create_mesh_copy();
}

MElementOctree *backgroundMesh2D::getOctree()
{
  if(!octree) {
    Msg::Debug("Rebuilding BackgroundMesh element octree");
    octree = new MElementOctree(elements);
  }
  return octree;
}

const MElement *backgroundMesh2D::getElement(unsigned int i) const
{
  return elements[i];
}

void backgroundMesh2D::reset(bool erase_2D3D)
{
  unset();

  // create face mesh - this was previously done for old backgroundmesh in
  // buildBackGroundMesh !
  create_face_mesh();

  // computes the mesh sizes at nodes
  if(CTX::instance()->mesh.lcFromPoints) { computeSizeField(); }
  else
    for(auto itv2 = _2Dto3D.begin(); itv2 != _2Dto3D.end(); ++itv2)
      sizeField[itv2->first] = CTX::instance()->mesh.lcMax;

  // ensure that other criteria are fullfilled
  updateSizes();

  if(erase_2D3D) {
    _3Dto2D.clear();
    _2Dto3D.clear();
  }
}

void backgroundMesh2D::unset()
{
  for(unsigned int i = 0; i < vertices.size(); i++) delete vertices[i];
  for(unsigned int i = 0; i < getNumMeshElements(); i++) delete elements[i];
  if(octree) delete octree;
  octree = nullptr;
}

void backgroundMesh2D::create_mesh_copy()
{
  // TODO: useful to extend it to other elements ???
  // std::set<SPoint2> myBCNodes;
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return;
  }
  for(unsigned int i = 0; i < face->triangles.size(); i++) {
    MTriangle *e = face->triangles[i];
    MVertex *news[3];
    for(int j = 0; j < 3; j++) {
      MVertex *v = e->getVertex(j);
      auto it = _3Dto2D.find(v);
      MVertex *newv = nullptr;
      if(it == _3Dto2D.end()) {
        SPoint2 p;
        reparamMeshVertexOnFace(v, face, p);
        newv =
          new MVertex(p.x(), p.y(), 0.0); // creates new vertex with xyz= u,v,0.
        vertices.push_back(newv);
        _3Dto2D[v] = newv;
        _2Dto3D[newv] = v;
        // if(v->onWhat()->dim()<2) myBCNodes.insert(p);
      }
      else {
        newv = it->second;
      }
      news[j] = newv;
    }
    elements.push_back(new MTriangle(news[0], news[1], news[2]));
  }
}

GPoint backgroundMesh2D::get_GPoint_from_MVertex(const MVertex *v) const
{
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return GPoint();
  }
  return face->point(SPoint2(v->x(), v->y()));
}

backgroundMesh2D::backgroundMesh2D(GFace *_gf, bool erase_2D3D)
  : BGMBase(2, _gf), sizeFactor(1.)
{
  reset(erase_2D3D);

  if(erase_2D3D) {
    // now, the new mesh has been copied in local in backgroundMesh2D, deleting
    // the mesh from GFace, back to the previous one !
    GFace *face = dynamic_cast<GFace *>(gf);
    if(!face)
      Msg::Error("Entity is not a face in background mesh");
    else
      face->triangles = tempTR;
  }
}

backgroundMesh2D::~backgroundMesh2D() { unset(); }

void backgroundMesh2D::propagateValues(DoubleStorageType &dirichlet,
                                       simpleFunction<double> &eval_diffusivity,
                                       bool in_parametric_plane)
{
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *_lsys = new linearSystemCSRGmm<double>;
  _lsys->setGmres(1);
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(_lsys);

  // fix boundary conditions
  for(auto itv = dirichlet.begin(); itv != dirichlet.end(); ++itv) {
    myAssembler.fixVertex(itv->first, 0, 1, itv->second);
  }

  // Number vertices
  std::set<MVertex *> vs;
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    delete _lsys;
    return;
  }
  for(unsigned int k = 0; k < face->triangles.size(); k++)
    for(int j = 0; j < 3; j++) vs.insert(face->triangles[k]->getVertex(j));
  for(unsigned int k = 0; k < face->quadrangles.size(); k++)
    for(int j = 0; j < 4; j++) vs.insert(face->quadrangles[k]->getVertex(j));

  std::map<MVertex *, SPoint3> theMap;
  if(in_parametric_plane) {
    for(auto it = vs.begin(); it != vs.end(); ++it) {
      SPoint2 p;
      reparamMeshVertexOnFace(*it, face, p);
      theMap[*it] = SPoint3((*it)->x(), (*it)->y(), (*it)->z());
      (*it)->setXYZ(p.x(), p.y(), 0.0);
    }
  }

  for(auto it = vs.begin(); it != vs.end(); ++it)
    myAssembler.numberVertex(*it, 0, 1);

  // Assemble
  laplaceTerm l(nullptr, 1, &eval_diffusivity);
  for(unsigned int k = 0; k < face->triangles.size(); k++) {
    MTriangle *t = face->triangles[k];
    SElement se(t);
    l.addToMatrix(myAssembler, &se);
  }

  // Solve
  if(myAssembler.sizeOfR()) { _lsys->systemSolve(); }

  // save solution
  for(auto it = vs.begin(); it != vs.end(); ++it) {
    myAssembler.getDofValue(*it, 0, 1, dirichlet[*it]);
  }

  if(in_parametric_plane) {
    for(auto it = vs.begin(); it != vs.end(); ++it) {
      SPoint3 p = theMap[(*it)];
      (*it)->setXYZ(p.x(), p.y(), p.z());
    }
  }
  delete _lsys;
#endif
}

void backgroundMesh2D::computeSizeField()
{
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return;
  }

  std::vector<GEdge *> const &e = face->edges();
  auto it = e.begin();
  DoubleStorageType sizes;

  for(; it != e.end(); ++it) {
    if(!(*it)->isSeam(face)) {
      for(unsigned int i = 0; i < (*it)->lines.size(); i++) {
        MVertex *v1 = (*it)->lines[i]->getVertex(0);
        MVertex *v2 = (*it)->lines[i]->getVertex(1);
        if(v1 != v2) {
          double d = std::sqrt((v1->x() - v2->x()) * (v1->x() - v2->x()) +
                               (v1->y() - v2->y()) * (v1->y() - v2->y()) +
                               (v1->z() - v2->z()) * (v1->z() - v2->z()));
          for(int k = 0; k < 2; k++) {
            MVertex *v = (*it)->lines[i]->getVertex(k);
            auto itv = sizes.find(v);
            if(itv == sizes.end())
              sizes[v] = std::log(d);
            else
              itv->second = 0.5 * (itv->second + std::log(d));
          }
        }
      }
    }
  }

  simpleFunction<double> ONE(1.0);
  propagateValues(sizes, ONE);

  auto itv2 = _2Dto3D.begin();
  for(; itv2 != _2Dto3D.end(); ++itv2) {
    MVertex const *const v_2D = itv2->first;
    MVertex *v_3D = itv2->second;
    sizeField[v_2D] = std::exp(sizes[v_3D]);
  }
}

inline double myAngle(const SVector3 &a, const SVector3 &b, const SVector3 &d)
{
  double cosTheta = dot(a, b);
  double sinTheta = dot(crossprod(a, b), d);
  return std::atan2(sinTheta, cosTheta);
}

void backgroundMesh2D::updateSizes()
{
  auto itv = sizeField.begin();
  for(; itv != sizeField.end(); ++itv) {
    SPoint2 p;
    MVertex const *const v = _2Dto3D[itv->first];
    double lc;
    if(v->onWhat()->dim() == 0) {
      lc = sizeFactor * BGM_MeshSize(v->onWhat(), 0, 0, v->x(), v->y(), v->z());
    }
    else if(v->onWhat()->dim() == 1) {
      double u;
      v->getParameter(0, u);
      lc = sizeFactor * BGM_MeshSize(v->onWhat(), u, 0, v->x(), v->y(), v->z());
    }
    else {
      GFace *face = dynamic_cast<GFace *>(gf);
      if(!face) {
        Msg::Error("Entity is not a face in background mesh");
        return;
      }
      reparamMeshVertexOnFace(v, face, p);
      lc =
        sizeFactor * BGM_MeshSize(face, p.x(), p.y(), v->x(), v->y(), v->z());
    }
    // printf("2D -- %g %g 3D -- %g %g\n",p.x(),p.y(),v->x(),v->y());
    itv->second = std::min(lc, itv->second);
    itv->second =
      std::max(itv->second, sizeFactor * CTX::instance()->mesh.lcMin);
    itv->second =
      std::min(itv->second, sizeFactor * CTX::instance()->mesh.lcMax);
  }
  // do not allow large variations in the size field
  // (Int. J. Numer. Meth. Engng. 43, 1143-1165 (1998) MESH GRADATION
  // CONTROL, BOROUCHAKI, HECHT, FREY)
  std::set<MEdge, MEdgeLessThan> edges;
  for(unsigned int i = 0; i < getNumMeshElements(); i++) {
    for(int j = 0; j < getElement(i)->getNumEdges(); j++) {
      edges.insert(getElement(i)->getEdge(j));
    }
  }
  const double _beta = 1.3;
  for(int i = 0; i < 0; i++) {
    auto it = edges.begin();
    for(; it != edges.end(); ++it) {
      MVertex *v0 = it->getVertex(0);
      MVertex *v1 = it->getVertex(1);
      MVertex *V0 = _2Dto3D[v0];
      MVertex *V1 = _2Dto3D[v1];
      auto s0 = sizeField.find(V0);
      auto s1 = sizeField.find(V1);
      if(s0->second < s1->second)
        s1->second = std::min(s1->second, _beta * s0->second);
      else
        s0->second = std::min(s0->second, _beta * s1->second);
    }
  }
}

frameFieldBackgroundMesh2D::frameFieldBackgroundMesh2D(GFace *_gf)
  : backgroundMesh2D(_gf, false)
{
  reset();

  // now, the new mesh has been copied in local in backgroundMesh2D, deleting
  // the mesh from GFace, back to the previous one !
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face)
    Msg::Error("Entity is not a face in background mesh");
  else
    face->triangles = tempTR;
}

frameFieldBackgroundMesh2D::~frameFieldBackgroundMesh2D() {}

void frameFieldBackgroundMesh2D::reset(bool erase_2D3D)
{
  // computes cross field
  simpleFunction<double> ONE(1.0);
  computeCrossField(ONE);
  computeSmoothness();

  //  evalDiffusivityFunction eval_diff(this);
  //  exportSmoothness("smoothness_iter_0.pos");
  //  for (int i=1;i<30;i++){
  //    computeCrossField(eval_diff);
  //    computeSmoothness();
  //
  //    stringstream ss;
  //    ss << "smoothness_iter_" << i << ".pos";
  //    exportSmoothness(ss.str());
  //
  //    stringstream sscf;
  //    sscf << "crossfield_iter_" << i << ".pos";
  //    exportCrossField(sscf.str());
  //  }

  if(erase_2D3D) {
    _3Dto2D.clear();
    _2Dto3D.clear();
  }
}

double frameFieldBackgroundMesh2D::get_smoothness(MVertex *v)
{
  return get_nodal_value(v, smoothness);
}

double frameFieldBackgroundMesh2D::get_smoothness(double u, double v)
{
  return get_field_value(u, v, 0., smoothness);
}

double frameFieldBackgroundMesh2D::angle(MVertex *v)
{
  return get_nodal_value(v, angles);
}

double frameFieldBackgroundMesh2D::angle(double u, double v)
{
  MElement *e = const_cast<MElement *>(findElement(u, v));
  if(!e) return -1000.0;
  std::vector<double> val = get_nodal_values(e, angles);
  std::vector<double> element_uvw = get_element_uvw_from_xyz(e, u, v, 0.);
  std::vector<double> cosvalues(e->getNumVertices()),
    sinvalues(e->getNumVertices());
  for(std::size_t i = 0; i < e->getNumVertices(); i++) {
    cosvalues[i] = std::cos(4 * val[i]);
    sinvalues[i] = std::sin(4 * val[i]);
  }
  double cos4 = e->interpolate(&cosvalues[0], element_uvw[0], element_uvw[1],
                               element_uvw[2], 1, order);
  double sin4 = e->interpolate(&sinvalues[0], element_uvw[0], element_uvw[1],
                               element_uvw[2], 1, order);
  double a = std::atan2(sin4, cos4) / 4.0;
  normalizeAngle(a);
  return a;
}

void frameFieldBackgroundMesh2D::computeCrossField(
  simpleFunction<double> &eval_diffusivity)
{
  angles.clear();

  DoubleStorageType _cosines4, _sines4;

  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return;
  }
  std::vector<GEdge *> const &e = face->edges();
  auto it = e.begin();

  for(; it != e.end(); ++it) {
    if(!(*it)->isSeam(face)) {
      for(unsigned int i = 0; i < (*it)->lines.size(); i++) {
        MVertex *v[2];
        v[0] = (*it)->lines[i]->getVertex(0);
        v[1] = (*it)->lines[i]->getVertex(1);
        SPoint2 p1, p2;
        reparamMeshEdgeOnFace(v[0], v[1], face, p1, p2);
        Pair<SVector3, SVector3> der = face->firstDer((p1 + p2) * .5);
        SVector3 t1 = der.first();
        SVector3 t2 = der.second();
        SVector3 n = crossprod(t1, t2);
        n.normalize();
        SVector3 d1(v[1]->x() - v[0]->x(), v[1]->y() - v[0]->y(),
                    v[1]->z() - v[0]->z());
        t1.normalize();
        d1.normalize();
        double _angle = myAngle(t1, d1, n);
        normalizeAngle(_angle);
        for(int i = 0; i < 2; i++) {
          auto itc = _cosines4.find(v[i]);
          auto its = _sines4.find(v[i]);
          if(itc != _cosines4.end()) {
            itc->second = 0.5 * (itc->second + std::cos(4 * _angle));
            its->second = 0.5 * (its->second + std::sin(4 * _angle));
          }
          else {
            _cosines4[v[i]] = std::cos(4 * _angle);
            _sines4[v[i]] = std::sin(4 * _angle);
          }
        }
      }
    }
  }

  propagateValues(_cosines4, eval_diffusivity, false);
  propagateValues(_sines4, eval_diffusivity, false);

  auto itv2 = _2Dto3D.begin();
  for(; itv2 != _2Dto3D.end(); ++itv2) {
    MVertex const *const v_2D = itv2->first;
    MVertex *v_3D = itv2->second;
    double angle = std::atan2(_sines4[v_3D], _cosines4[v_3D]) / 4.0;
    normalizeAngle(angle);
    angles[v_2D] = angle;
  }
}

void frameFieldBackgroundMesh2D::eval_crossfield(double u, double v,
                                                 STensor3 &cf)
{
  double quadAngle = angle(u, v);
  Pair<SVector3, SVector3> dirs =
    compute_crossfield_directions(u, v, quadAngle);
  SVector3 n = crossprod(dirs.first(), dirs.second());

  for(int i = 0; i < 3; i++) {
    cf(i, 0) = dirs.first()[i];
    cf(i, 1) = dirs.second()[i];
    cf(i, 2) = n[i];
  }

  //  SVector3 t1,t2,n;
  //  GFace *face = dynamic_cast<GFace*>(gf);
  //  Pair<SVector3, SVector3> der = face->firstDer(SPoint2(u,v));
  //  SVector3 s1 = der.first();
  //  SVector3 s2 = der.second();
  //  n = crossprod(s1,s2);
  //  n.normalize();
  //  s1.normalize();
  //  s2=crossprod(n,s1);
  //  t1 = s1 * cos(quadAngle) + s2 * sin(quadAngle) ;
  //  t1.normalize();
  //  t2 = crossprod(n,t1);
  //  for (int i=0;i<3;i++){
  //    cf(i,0) = t1[i];
  //    cf(i,1) = t2[i];
  //    cf(i,2) = n[i];
  //  }
}

void frameFieldBackgroundMesh2D::eval_crossfield(MVertex *vert, STensor3 &cf)
{
  SPoint2 parampoint;
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return;
  }
  reparamMeshVertexOnFace(vert, face, parampoint);
  return eval_crossfield(parampoint[0], parampoint[1], cf);
}

void frameFieldBackgroundMesh2D::computeSmoothness()
{
  smoothness.clear();

  // build vertex -> neighbors table
  std::multimap<MVertex *, MVertex *> vertex2vertex;
  for(auto it = beginelements(); it != endelements(); it++) {
    MElement *e = *it;
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      MVertex *current = e->getVertex(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        if(i == j) continue;
        MVertex *neighbor = e->getVertex(j);
        vertex2vertex.insert(std::make_pair(current, neighbor));
      }
    }
  }

  // compute smoothness
  for(auto it = beginvertices(); it != endvertices(); it++) {
    MVertex *v = *it;
    double angle_current = angle(v);
    // compare to all neighbors...
    std::pair<std::multimap<MVertex *, MVertex *>::iterator,
              std::multimap<MVertex *, MVertex *>::iterator>
      range = vertex2vertex.equal_range(v);
    double minangle, totalangle = 0.;
    int N = 0;
    for(auto itneighbor = range.first; itneighbor != range.second;
        itneighbor++) {
      N++;
      minangle = M_PI / 2;
      MVertex *v_nb = itneighbor->second;
      double angle_nb = angle(v_nb);
      // angle comparison...
      minangle = std::min(minangle, std::abs(angle_current - angle_nb));
      minangle =
        std::min(minangle, std::abs(angle_current - (angle_nb + M_PI / 2.)));
      minangle =
        std::min(minangle, std::abs(angle_current - (angle_nb - M_PI / 2.)));
      totalangle += minangle;
    }
    totalangle /= N;
    smoothness[v] = 1. - (totalangle / M_PI * 2);
  }
}

void frameFieldBackgroundMesh2D::exportCrossField(const std::string &filename)
{
  FILE *f = Fopen(filename.c_str(), "w");
  if(!f) {
    Msg::Error("Could not open file '%s'", filename.c_str());
    return;
  }
  fprintf(f, "View \"Cross Field\"{\n");
  std::vector<double> deltas(2);
  deltas[0] = 0.;
  deltas[1] = M_PI;

  for(auto it = beginvertices(); it != endvertices(); it++) {
    MVertex *v = *it;
    double angle_current = angle(v);
    GPoint p = get_GPoint_from_MVertex(v);
    for(int i = 0; i < 2; i++) {
      Pair<SVector3, SVector3> dirs = compute_crossfield_directions(
        v->x(), v->y(), angle_current + deltas[i]);
      fprintf(f, "VP(%g,%g,%g) {%g,%g,%g};\n", p.x(), p.y(), p.z(),
              dirs.first()[0], dirs.first()[1], dirs.first()[2]);
      fprintf(f, "VP(%g,%g,%g) {%g,%g,%g};\n", p.x(), p.y(), p.z(),
              dirs.second()[0], dirs.second()[1], dirs.second()[2]);
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

// returns the cross field as a pair of othogonal vectors (NOT in parametric
// coordinates, but real 3D coordinates)
Pair<SVector3, SVector3>
frameFieldBackgroundMesh2D::compute_crossfield_directions(double u, double v,
                                                          double angle_current)
{
  // get the unit normal at that point
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return Pair<SVector3, SVector3>(SVector3(), SVector3());
  }

  Pair<SVector3, SVector3> der = face->firstDer(SPoint2(u, v));
  SVector3 s1 = der.first();
  SVector3 s2 = der.second();
  SVector3 n = crossprod(s1, s2);
  n.normalize();

  SVector3 basis_u = s1;
  basis_u.normalize();
  SVector3 basis_v = crossprod(n, basis_u);

  // normalize vector t1 that is tangent to gf at uv
  SVector3 t1 =
    basis_u * std::cos(angle_current) + basis_v * std::sin(angle_current);
  t1.normalize();

  // compute the second direction t2 and normalize (t1,t2,n) is the tangent
  // frame
  SVector3 t2 = crossprod(n, t1);
  t2.normalize();

  return Pair<SVector3, SVector3>(SVector3(t1[0], t1[1], t1[2]),
                                  SVector3(t2[0], t2[1], t2[2]));
}

bool frameFieldBackgroundMesh2D::compute_RK_infos(double u, double v, double x,
                                                  double y, double z,
                                                  RK_form &infos)
{
  // check if point is in domain
  if(!inDomain(u, v)) return false;

  // get stored angle

  double angle_current = angle(u, v);

  // compute t1,t2: cross field directions

  // get the unit normal at that point
  GFace *face = dynamic_cast<GFace *>(gf);
  if(!face) {
    Msg::Error("Entity is not a face in background mesh");
    return false;
  }

  Pair<SVector3, SVector3> der = face->firstDer(SPoint2(u, v));
  SVector3 s1 = der.first();
  SVector3 s2 = der.second();
  SVector3 n = crossprod(s1, s2);
  n.normalize();
  SVector3 basis_u = s1;
  basis_u.normalize();
  SVector3 basis_v = crossprod(n, basis_u);
  // normalize vector t1 that is tangent to gf at uv
  SVector3 t1 =
    basis_u * std::cos(angle_current) + basis_v * std::sin(angle_current);
  t1.normalize();
  // compute the second direction t2 and normalize (t1,t2,n) is the tangent
  // frame
  SVector3 t2 = crossprod(n, t1);
  t2.normalize();

  // get metric

  double L = size(u, v);
  infos.metricField = SMetric3(1. / (L * L));
  FieldManager *fields = gf->model()->getFields();
  if(fields->getBackgroundField() > 0) {
    Field *f = fields->get(fields->getBackgroundField());
    if(!f->isotropic()) { (*f)(x, y, z, infos.metricField, gf); }
    else {
      L = (*f)(x, y, z, gf);
      infos.metricField = SMetric3(1. / (L * L));
    }
  }
  double M = dot(s1, s1);
  double N = dot(s2, s2);
  double E = dot(s1, s2);
  // compute the first fundamental form i.e. the metric tensor at the point
  // M_{ij} = s_i \cdot s_j
  double metric[2][2] = {{M, E}, {E, N}};

  // get sizes

  double size_1 = std::sqrt(1. / dot(t1, infos.metricField, t1));
  double size_2 = std::sqrt(1. / dot(t2, infos.metricField, t2));

  // compute covariant coordinates of t1 and t2 - cross field directions in
  // parametric domain
  double covar1[2], covar2[2];
  // t1 = a s1 + b s2 -->
  // t1 . s1 = a M + b E
  // t1 . s2 = a E + b N --> solve the 2 x 2 system
  // and get covariant coordinates a and b
  double rhs1[2] = {dot(t1, s1), dot(t1, s2)};
  bool singular = false;
  if(!sys2x2(metric, rhs1, covar1)) {
    Msg::Info("Argh surface %d %g %g %g -- %g %g %g -- %g %g", gf->tag(),
              s1.x(), s1.y(), s1.z(), s2.x(), s2.y(), s2.z(), size_1, size_2);
    covar1[1] = 1.0;
    covar1[0] = 0.0;
    singular = true;
  }
  double rhs2[2] = {dot(t2, s1), dot(t2, s2)};
  if(!sys2x2(metric, rhs2, covar2)) {
    Msg::Info("Argh surface %d %g %g %g -- %g %g %g", gf->tag(), s1.x(), s1.y(),
              s1.z(), s2.x(), s2.y(), s2.z());
    covar2[0] = 1.0;
    covar2[1] = 0.0;
    singular = true;
  }

  // transform the sizes with respect to the metric
  // consider a vector v of size 1 in the parameter plane
  // its length is sqrt (v^T M v) --> if I want a real size
  // of size1 in direction v, it should be sqrt(v^T M v) * size1
  double l1 = std::sqrt(covar1[0] * covar1[0] + covar1[1] * covar1[1]);
  double l2 = std::sqrt(covar2[0] * covar2[0] + covar2[1] * covar2[1]);

  covar1[0] /= l1;
  covar1[1] /= l1;
  covar2[0] /= l2;
  covar2[1] /= l2;

  double size_param_1 = size_1 / std::sqrt(M * covar1[0] * covar1[0] +
                                           2 * E * covar1[1] * covar1[0] +
                                           N * covar1[1] * covar1[1]);
  double size_param_2 = size_2 / std::sqrt(M * covar2[0] * covar2[0] +
                                           2 * E * covar2[1] * covar2[0] +
                                           N * covar2[1] * covar2[1]);
  if(singular) {
    size_param_1 = size_param_2 = std::min(size_param_1, size_param_2);
  }

  // filling form...

  infos.t1 = t1;
  infos.h.first = size_1;
  infos.h.second = size_2;
  infos.paramh.first = size_param_1;
  infos.paramh.second = size_param_2;
  infos.paramt1 = SPoint2(covar1[0], covar1[1]);
  infos.paramt2 = SPoint2(covar2[0], covar2[1]);
  infos.angle = angle_current;
  infos.localsize = L;
  infos.normal = n;

  return true;
}
