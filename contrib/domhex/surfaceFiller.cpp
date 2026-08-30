// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier Baudoin

#include <queue>
#include <stack>
#include "GmshConfig.h"
#include "Context.h"
#include "surfaceFiller.h"
#include "Field.h"
#include "GModel.h"
#include "OS.h"
#include "rtree.h"
#include "MVertex.h"
#include "MElement.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "intersectCurveSurface.h"
#include "pointInsertionRTreeTools.h"
#include "discreteFace.h"

// Here, we aim at producing a set of points that enables to generate a nice
// quad mesh

// assume a point on the surface, compute the 4 possible neighbors.
//
//              ^ t2
//              |
//              |
//             v2
//              |
//              |
//       v1-----+------v3 -------> t1
//              |
//              |
//             v4
//
// we aim at generating a rectangle with sizes size_1 and size_2 along t1 and t2

int __OK, __KO;

bool compute4neighbors(
  GFace *gf, // the surface
  MVertex *v_center, // the wertex for which we wnt to generate 4 neighbors
  SPoint2 &midpoint,
  SPoint2 newP[8], // look into other directions
  SMetric3 &metricField,// the mesh metric
  Field *f,
  double du,
  double dv,
  double mult)
{
  // we assume that v is on surface gf

  // get the parameter of the point on the surface
  reparamMeshVertexOnFace(v_center, gf, midpoint);

  midpoint = SPoint2(midpoint.x() + du,midpoint.y() + dv);

  SVector3 t1;
  double L;
  double X=v_center->x();
  double Y=v_center->y();
  double Z=v_center->z();
  int iter = 1;
  while (1){
    (*f)(X,Y,Z, t1, gf);
    L = t1.norm()*mult;
    // HOUSTON WE HAVE A PROBLEM
    if (L > 1.e10){
      double DU = ((double)rand()/RAND_MAX)*1.e-3*iter;
      double DV = ((double)rand()/RAND_MAX)*1.e-3*iter;
      GPoint pp = gf->point(DU+midpoint.x(),DV+midpoint.y());
      X = pp.x();
      Y = pp.y();
      Z = pp.z();
      iter++;
    }
    else break;
  }

  metricField = SMetric3(1. / (L * L));

  // get the unit normal at that point
  std::pair<SVector3, SVector3> der =
    gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
  SVector3 s1 = der.first;
  SVector3 s2 = der.second;
  SVector3 n = crossprod(s1, s2);
  n.normalize();
  t1 -= n*dot(t1,n);
  t1.normalize();

  double M = dot(s1, s1);
  double N = dot(s2, s2);
  double E = dot(s1, s2);

  // compute the first fundamental form i.e. the metric tensor at the point
  // M_{ij} = s_i \cdot s_j
  double metric[2][2] = {{M, E}, {E, N}};

  // compute the second direction t2 and normalize (t1,t2,n) is the tangent
  // frame
  SVector3 t2 = crossprod(n, t1);
  t2.normalize();

  // compute covariant coordinates of t1 and t2
  // t1 = a s1 + b s2 -->
  // t1 . s1 = a M + b E
  // t1 . s2 = a E + b N --> solve the 2 x 2 system
  // and get covariant coordinates a and b
  double rhs1[2] = {dot(t1, s1)*L, dot(t1, s2)*L}, covar1[2];
  bool singular = false;
  if(!sys2x2(metric, rhs1, covar1)) {
    Msg::Debug("surface filler: SINGULAR AT %g %g",midpoint.x(),midpoint.y());
    return false;
    covar1[1] = 1.0;
    covar1[0] = 0.0;
    singular = true;
  }
  double rhs2[2] = {dot(t2, s1)*L, dot(t2, s2)*L}, covar2[2];
  if(!sys2x2(metric, rhs2, covar2)) {
    Msg::Debug("surface filler: SINGULAR AT %g %g",midpoint.x(),midpoint.y());
    return false;
    covar2[0] = 1.0;
    covar2[1] = 0.0;
    singular = true;
  }

  // compute the corners of the box as well
  double LSQR = L ;
  SVector3 b1 = t1+t2;
  b1.normalize();
  SVector3 b2 = t1-t2;
  b2.normalize();

  double rhs3[2] = {dot(b1, s1)*LSQR, dot(b1, s2)*LSQR}, covar3[2];
  if(!sys2x2(metric, rhs3, covar3)) {
    covar3[1] = 1.e22;
    covar3[0] = 0.0;
    singular = true;
  }
  double rhs4[2] = {dot(b2, s1)*LSQR, dot(b2, s2)*LSQR}, covar4[2];
  if(!sys2x2(metric, rhs4, covar4)) {
    covar4[0] = 1.e22;
    covar4[1] = 0.0;
    singular = true;
  }


  double size_1 = sqrt (covar1[0]*covar1[0]+covar1[1]*covar1[1]);
  double size_2 = sqrt (covar2[0]*covar2[0]+covar2[1]*covar2[1]);


  double newPoint[8][2] = {{midpoint[0] - covar1[0],
			    midpoint[1] - covar1[1]},
			   {midpoint[0] - covar2[0],
			    midpoint[1] - covar2[1]},
			   {midpoint[0] + covar1[0],
			    midpoint[1] + covar1[1]},
			   {midpoint[0] + covar2[0],
			    midpoint[1] + covar2[1]},
			   {midpoint[0] - covar3[0],
			    midpoint[1] - covar3[1]},
			   {midpoint[0] - covar4[0],
			    midpoint[1] - covar4[1]},
			   {midpoint[0] + covar3[0],
			    midpoint[1] + covar3[1]},
			   {midpoint[0] + covar4[0],
			    midpoint[1] + covar4[1]}};

  SVector3 dirs[8]      = {t1 * (-1.0), t2 * (-1.0), t1 * (1.0), t2 * (1.0),
			   b1 * (-1.0), b2 * (-1.0), b1 * (1.0), b2 * (1.0) };
  SVector3 orthodirs[8] = {t2 * (-1.0), t1 * (-1.0), t2 * (1.0), t1 * (1.0),
			   b2 * (-1.0), b1 * (-1.0), b2 * (1.0), b1 * (1.0) };
  double   LS[8]   = {L,L,L,L,LSQR,LSQR,LSQR,LSQR};


  SPoint3 ppx (v_center->x(),v_center->y(),v_center->z());
  surfaceFunctorGFace ss(gf);
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
    GPoint pp = gf->point(newP[i]);
    SPoint3 px (pp.x(),pp.y(),pp.z());
    SVector3 test = px - ppx;
    double L2 = test.norm();
    double DIFF_ANG = fabs(dot(orthodirs[i],test)) / L2;
    double DIFF_L   = fabs(L2-LS[i]);
    if (singular || DIFF_L > .01*LS[i] || DIFF_ANG > .1){
      // if (0 && gf->geomType() == GEntity::DiscreteSurface){
      // 	discreteFace *df = dynamic_cast<discreteFace *>(gf);
      // 	double uv[2] = {newPoint[i][0], newPoint[i][1]};
      // 	GPoint qq = df->intersectionWithCircle(dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()),
      // 							 LS[i],uv);
      // 	if (qq.succeeded()){
      // 	  newPoint[i][0]=qq.u();
      // 	  newPoint[i][1]=qq.v();
      // 	}
      // }
      // else {
      curveFunctorCircle cf(dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()), LS[i]);
      double uvt[3] = {newPoint[i][0], newPoint[i][1], 0.0}; //
      if(intersectCurveSurface(cf, ss, uvt, size_1 * 1.e-6)) {
	__KO++;
	pp = gf->point(SPoint2(uvt[0], uvt[1]));
	px = SPoint3 (pp.x(),pp.y(),pp.z());
	test = px - ppx;
	L2 = test.norm();
	double DIFF_ANG2 = fabs(dot(orthodirs[i],test)) / L2;
	double DIFF_L2   = fabs(L2-LS[i]);
	newPoint[i][0]=uvt[0];
	newPoint[i][1]=uvt[1];
	if (DIFF_L2 <= DIFF_L && DIFF_ANG2 <= DIFF_ANG){
	}
	else{
	  Msg::Debug("Difficult to find a point %zu L %g vs %g (ps %12.5E) ",i,L,L2,DIFF_ANG2);
	}
      }
      else{
	SPoint3 p_test (v_center->x() + dirs[i].x() * LS[i],
			v_center->y() + dirs[i].y() * LS[i],
			v_center->z() + dirs[i].z() * LS[i]);
	pp = gf->closestPoint(p_test ,uvt);
	if (pp.succeeded()){
	  newPoint[i][0] = pp.u();
	  newPoint[i][1] = pp.v();
	}
	else
	  Msg::Debug("Face %d Impossible to intersect with a circle of radius %g",gf->tag(),L);
      }
    }
    else {
      __OK++;
    }
  }

  return true;
}

// at crossfield singularities, directions are undefined
// we draw a circle around
// static void createSingularPatches (GFace *gf, std::map<MVertex *, int> &s, Field *f, std::vector<MVertex*> &toInsert){

//   FILE *_f = fopen("patches.pos","w");
//   fprintf(_f,"View \"\"{\n");
//   for (std::map<MVertex *, int>::iterator it = s.begin();it != s.end() ; ++it){
//     SPoint2 midpoint;
//     SPoint2 newP[8];
//     SMetric3 metricField;
//     compute4neighbors(gf, it->first, midpoint, newP, metricField, f, 0, 0, it->second == 5 ? .25 : 1);
//     //the 8 points (I know, it's strange ...)
//     //                 2
//     //             7       6
//     //          1             3
//     //             4       5
//     //                 0

//     // get the unit normal at that point
//     std::pair<SVector3, SVector3> der =
//       gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
//     SVector3 s1 = der.first;
//     SVector3 s2 = der.second;
//     SVector3 n = crossprod(s1, s2);
//     n.normalize();

//     int loop [8] = {0,4,1,7,2,6,3,5};
//     SVector3 t0[8],t1[8];
//     GPoint p0[8];
//     std::vector<double> dots;
//     std::vector<SPoint3> pts;
//     for (int i=0;i<8;i++){
//       p0[i] = gf->point(newP[loop[i]]);
//       (*f)(p0[i].x(), p0[i].y(),p0[i].z(),t0[i], gf);
//       t0[i] -= n*dot(t0[i],n);
//       t0[i].normalize();
//       t1[i] = crossprod(n, t0[i]);
//       t1[i].normalize();
//     }
//     int nSamples = 30;
//     SPoint3 p(it->first->x(),it->first->y(),it->first->z());
//     for (int i=0;i<8;i++){
//       SVector3 t0i = t0[i];
//       SVector3 t1i = t1[i];
//       SVector3 t0n = t0[(i+1)%8];
//       SVector3 t1n = t1[(i+1)%8];
//       if (fabs(dot(t0i,t0n)) < fabs(dot(t0i,t1n))){
// 	SVector3 temp_ = t0n;
// 	t0n = t1n;
// 	t1n = temp_;
//       }
//       if (dot(t0i,t0n) < 0)t0n = t0n * (-1.0);
//       if (dot(t1i,t1n) < 0)t1n = t1n * (-1.0);

//       GPoint pi = p0[i];
//       GPoint pn = p0[(i+1)%8];
//       fprintf(_f,"SP(%g,%g,%g){%d};\n",
// 	      pi.x(),pi.y(),pi.z(),i);
//       for (int j=0;j<nSamples;j++){
// 	double xi = (double)j/(nSamples);
// 	SPoint3 pij (pi.x()*(1-xi)+pn.x()*xi,pi.y()*(1-xi)+pn.y()*xi,pi.z()*(1-xi)+pn.z()*xi);
// 	SVector3 vij = p-pij;
// 	pts.push_back (pij);
// 	vij.normalize();
// 	SVector3 v0 = t0i*(1-xi) + t0n*xi;
// 	SVector3 v1 = t1i*(1-xi) + t1n*xi;
// 	v0.normalize();
// 	v1.normalize();
// 	double dot0 = fabs(dot(v0,vij));
// 	double dot1 = fabs(dot(v1,vij));
// 	dots.push_back(std::max(dot0,dot1));
// 	fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",
// 		pij.x(),pij.y(),pij.z(),
// 		dot0*v0.x(),dot0*v0.y(),dot0*v0.z());
// 	fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",
// 		pij.x(),pij.y(),pij.z(),
// 		dot1*v1.x(),dot1*v1.y(),dot1*v1.z());
//       }
//     }

//     int nbMax = 0;
//     for (size_t i=0;i<pts.size();i++){
//       double V0 = dots[i];
//       double V1 = dots[(i+1)%pts.size()];
//       double V2 = dots[(i+2)%pts.size()];
//       if (V1 > V0 && V1 > V2){
// 	double uvt[2] = {0,0};
// 	GPoint pp = gf->closestPoint(pts[i] ,uvt);
// 	MFaceVertex *vv = new MFaceVertex (pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
// 	toInsert.push_back(vv);
// 	nbMax++;
//       }
//     }
//     if (nbMax == it-> second)printf("singularity %zu has a good set of %d sampling points\n",it->first->getNum(),nbMax);
//     else {
//       toInsert.resize(toInsert.size() - nbMax);
//       printf("singularity %zu has a bad set of %d vs %d sampling points\n",it->first->getNum(),nbMax,it->second);
//     }
//   }

//   fprintf(_f,"};\n");
//   fclose(_f);

// }



static bool outBounds(SPoint2 p, double minu, double maxu, double minv, double maxv){
  if (p.x() > maxu || p.x() <  minu || p.y() > maxv || p.y() <  minv){
    //    printf("OUT BOUND %g %g\n",p.x(),p.y());
    return true;

  }
  return false;
}

static bool inParametricDomain(GFace *gf, const SPoint2 &p)
{
  if(gf->getNativeType() == GEntity::GmshModel) {
    // The generic GFace::containsParam() only checks the rectangular UV
    // bounds. For built-in plane surfaces this includes holes and the parts of
    // the bounding rectangle outside trimmed loops, where PACK can otherwise
    // propagate indefinitely and sample unrelated values from a background
    // size field. gmshFace::containsPoint() performs the actual loop test.
    if(gf->geomType() == GEntity::Plane) {
      GPoint gp = gf->point(p);
      if(!gp.succeeded()) return false;
      return gf->containsPoint(SPoint3(gp.x(), gp.y(), gp.z()));
    }
    return true;
  }
  return gf->containsParam(p);
}

static bool close2sing(std::vector<MVertex*> &s, GFace *gf, SPoint2 p, Field *f){

  if (s.empty())return false;
  GPoint gp = gf->point(p);
  SVector3 t1;
  (*f)(gp.x(), gp.y(), gp.z(), t1, gf);
  double L = t1.norm();

  for (size_t i=0;i<s.size();i++){
    MVertex *v = s[i];
    double d = sqrt ((v->x()-gp.x())*(v->x()-gp.x())+
		     (v->y()-gp.y())*(v->y()-gp.y())+
		     (v->z()-gp.z())*(v->z()-gp.z()));
    if (d < FACTOR*L)return true;
  }
  return false;
}


static void findPhysicalGroupsForSingularities(GFace *gf,
                                               std::map<MVertex *, int> &temp)
{

  std::set<GVertex *, GEntityPtrLessThan> emb = gf->embeddedVertices();
  if (emb.empty())return;

  std::map<int, std::vector<GEntity *> > groups[4];
  gf->model()->getPhysicalGroups(groups);
  for(std::map<int, std::vector<GEntity *> >::iterator it = groups[0].begin();
      it != groups[0].end(); ++it) {
    std::string name = gf->model()->getPhysicalName(0, it->first);
    if(name == "SINGULARITY_OF_INDEX_THREE") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if (emb.find((GVertex*)it->second[j]) != emb.end()){
	  if(!it->second[j]->mesh_vertices.empty())
	    temp[it->second[j]->mesh_vertices[0]] = 3;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_FIVE") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if (emb.find((GVertex*)it->second[j]) != emb.end()){
	  if(!it->second[j]->mesh_vertices.empty())
	    temp[it->second[j]->mesh_vertices[0]] = 5;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_SIX") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if (emb.find((GVertex*)it->second[j]) != emb.end()){
	  if(!it->second[j]->mesh_vertices.empty())
	    temp[it->second[j]->mesh_vertices[0]] = 6;
	}
      }
    }
  }
}


// Keep the historical packing clearance in each local cross-field direction.
// With FACTOR = 0.7, the oriented exclusion cube has half-width 0.7 h.
static const double exclusionCubeFactor3D = FACTOR;

class surfacePointWithExclusionCube3D {
public:
  MVertex *_v;
  MVertex *_father;
  SPoint2 _uv;
  SVector3 _t1;
  SVector3 _t2;
  SVector3 _normal;
  double _size;
  SMetric3 _meshMetric;

  surfacePointWithExclusionCube3D(
    MVertex *v, const SPoint2 &uv, const SVector3 &t1,
    const SVector3 &t2, const SVector3 &normal, double size,
    const SMetric3 &meshMetric,
    surfacePointWithExclusionCube3D *father = nullptr)
    : _v(v), _father(father ? father->_v : nullptr), _uv(uv), _t1(t1),
      _t2(t2), _normal(normal), _size(size), _meshMetric(meshMetric)
  {
  }

  void minmax(double minimum[3], double maximum[3]) const
  {
    // The oriented cube is contained in this axis-aligned cube. Keeping the
    // exact region in the callback makes the R-tree conservative and cheap.
    const double radius = sqrt3 * exclusionCubeFactor3D * _size;
    minimum[0] = _v->x() - radius;
    minimum[1] = _v->y() - radius;
    minimum[2] = _v->z() - radius;
    maximum[0] = _v->x() + radius;
    maximum[1] = _v->y() + radius;
    maximum[2] = _v->z() + radius;
  }

  bool contains(const SPoint3 &point, MVertex *parent) const
  {
    if(_father == parent) return false;
    const SVector3 delta = point - _v->point();
    const double halfWidth = exclusionCubeFactor3D * _size;
    return std::abs(dot(delta, _t1)) < halfWidth &&
           std::abs(dot(delta, _t2)) < halfWidth &&
           std::abs(dot(delta, _normal)) < halfWidth;
  }
};

class surfaceCubeQuery3D {
public:
  SPoint3 point;
  MVertex *parent;
  bool tooClose;

  surfaceCubeQuery3D(const SPoint3 &point_, MVertex *parent_)
    : point(point_), parent(parent_), tooClose(false)
  {
  }
};

static bool surfaceCubeCallback3D(surfacePointWithExclusionCube3D *neighbour,
                                  void *context)
{
  surfaceCubeQuery3D *query =
    static_cast<surfaceCubeQuery3D *>(context);
  if(neighbour->contains(query->point, query->parent)) {
    query->tooClose = true;
    return false;
  }
  return true;
}

static bool inExclusionCube3D(
  MVertex *parent, const SPoint3 &point,
  RTree<surfacePointWithExclusionCube3D *, double, 3, double> &rtree)
{
  surfaceCubeQuery3D query(point, parent);
  double minimum[3] = {point.x(), point.y(), point.z()};
  double maximum[3] = {point.x(), point.y(), point.z()};
  rtree.Search(minimum, maximum, surfaceCubeCallback3D, &query);
  return query.tooClose;
}

static surfacePointWithExclusionCube3D *makeSurfaceCubePoint3D(
  GFace *gf, MVertex *vertex, Field *crossField, double multiplier,
  surfacePointWithExclusionCube3D *father = nullptr)
{
  SPoint2 uv;
  reparamMeshVertexOnFace(vertex, gf, uv);

  SVector3 t1;
  (*crossField)(vertex->x(), vertex->y(), vertex->z(), t1, gf);
  const double size = multiplier * t1.norm();
  if(!(size > 0.0) || !std::isfinite(size) || size > 1.e10)
    return nullptr;

  const std::pair<SVector3, SVector3> derivatives = gf->firstDer(uv);
  SVector3 normal = crossprod(derivatives.first, derivatives.second);
  if(!(normal.norm() > 0.0)) return nullptr;
  normal.normalize();
  t1 -= normal * dot(t1, normal);
  if(!(t1.norm() > 0.0)) return nullptr;
  t1.normalize();
  SVector3 t2 = crossprod(normal, t1);
  if(!(t2.norm() > 0.0)) return nullptr;
  t2.normalize();

  const SMetric3 metric(1.0 / (size * size));
  return new surfacePointWithExclusionCube3D(
    vertex, uv, t1, t2, normal, size, metric, father);
}

static MFaceVertex *projectSurfaceCandidate3D(
  GFace *gf, const surfacePointWithExclusionCube3D *parent,
  const SVector3 &direction)
{
  const SPoint3 center = parent->_v->point();
  const SPoint3 target = center + direction * parent->_size;
  const double initialGuess[2] = {parent->_uv.x(), parent->_uv.y()};
  const GPoint projected =
    gf->closestPointFromTrustedGuess(target, initialGuess);
  if(!projected.succeeded()) return nullptr;

  const SPoint2 uv(projected.u(), projected.v());
  const SPoint3 point(projected.x(), projected.y(), projected.z());
  const SVector3 displacement = point - center;
  const double length = displacement.norm();
  if(!(length > 0.25 * parent->_size) ||
     length > 1.75 * parent->_size)
    return nullptr;
  if(dot(displacement, direction) <= 0.25 * length) return nullptr;

  return new MFaceVertex(point.x(), point.y(), point.z(), gf, uv.x(), uv.y());
}

static void packingOfOrientedCubes3D(GFace *gf,
                                     std::vector<MVertex *> &packed,
                                     std::vector<SMetric3> &metrics)
{
  FieldManager *fields = gf->model()->getFields();
  if(fields->getBackgroundField() <= 0) {
    Msg::Error("3D surface packing requires a scaled cross field");
    return;
  }
  Field *crossField = fields->get(fields->getBackgroundField());
  if(!crossField || crossField->numComponents() != 3) {
    Msg::Error("3D surface packing requires a three-component scaled cross "
               "field");
    return;
  }

  std::set<MVertex *, MVertexPtrLessThan> boundaryVertices;
  for(unsigned int i = 0; i < gf->getNumMeshElements(); ++i) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); ++j) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() < 2) boundaryVertices.insert(vertex);
    }
  }

  std::queue<surfacePointWithExclusionCube3D *> fifo;
  std::vector<surfacePointWithExclusionCube3D *> points;
  RTree<surfacePointWithExclusionCube3D *, double, 3, double> rtree;
  const double globalMultiplier = 1.0;
  for(MVertex *vertex : boundaryVertices) {
    surfacePointWithExclusionCube3D *point = makeSurfaceCubePoint3D(
      gf, vertex, crossField, globalMultiplier);
    if(!point) continue;
    points.push_back(point);
    fifo.push(point);
    double minimum[3], maximum[3];
    point->minmax(minimum, maximum);
    rtree.Insert(minimum, maximum, point);
  }

  while(!fifo.empty()) {
    surfacePointWithExclusionCube3D *parent = fifo.front();
    fifo.pop();
    const SVector3 directions[4] = {parent->_t1 * -1.0,
                                    parent->_t2 * -1.0,
                                    parent->_t1,
                                    parent->_t2};
    for(const SVector3 &direction : directions) {
      MFaceVertex *candidate =
        projectSurfaceCandidate3D(gf, parent, direction);
      if(!candidate) continue;
      const SPoint3 candidatePoint = candidate->point();
      if(inExclusionCube3D(parent->_v, candidatePoint, rtree)) {
        delete candidate;
        continue;
      }
      double u = 0., v = 0.;
      if(!candidate->getParameter(0, u) ||
         !candidate->getParameter(1, v) ||
         !inParametricDomain(gf, SPoint2(u, v))) {
        delete candidate;
        continue;
      }
      surfacePointWithExclusionCube3D *point = makeSurfaceCubePoint3D(
        gf, candidate, crossField, globalMultiplier, parent);
      if(!point) {
        delete candidate;
        continue;
      }
      points.push_back(point);
      fifo.push(point);
      double minimum[3], maximum[3];
      point->minmax(minimum, maximum);
      rtree.Insert(minimum, maximum, point);
    }
  }

  FILE *debug = nullptr;
  if(Msg::GetVerbosity() == 99) {
    char filename[256];
    sprintf(filename, "points3d%d.pos", gf->tag());
    debug = Fopen(filename, "w");
    if(debug) fprintf(debug, "View \"3D packed points\"{\n");
  }
  for(surfacePointWithExclusionCube3D *point : points) {
    if(debug)
      fprintf(debug, "SP(%g,%g,%g){1};\n", point->_v->x(), point->_v->y(),
              point->_v->z());
    if(point->_v->onWhat() == gf) {
      packed.push_back(point->_v);
      metrics.push_back(point->_meshMetric);
    }
    delete point;
  }
  if(debug) {
    fprintf(debug, "};\n");
    fclose(debug);
  }
  Msg::Info("3D oriented-cube packing created %zu points on face %d",
            packed.size(), gf->tag());
}


void packingOfParallelograms(GFace *gf, std::vector<MVertex *> &packed,
                             std::vector<SMetric3> &metrics)
{

  if(CTX::instance()->mesh.quadqsPacking3D) {
    packingOfOrientedCubes3D(gf, packed, metrics);
    return;
  }

  //  printf("ALGO %d %d\n", CTX::instance()->mesh.algo2d,
  //  	 CTX::instance()->mesh.algo2d == ALGO_2D_QUAD_QUASI_STRUCT);

  FILE *f = NULL;
  FILE *f2 = NULL;
  if(Msg::GetVerbosity() == 99) {
    char ccc[256];
    sprintf(ccc, "points%d.pos", gf->tag());
    f = Fopen(ccc, "w");
    sprintf(ccc, "e_points%d.pos", gf->tag());
    f2 = Fopen(ccc, "w");
    if(f) fprintf(f, "View \"\"{\n");
    if(f2) fprintf(f2, "View \"\"{\n");
  }

  FieldManager *fields = gf->model()->getFields();
  Field *cross_field = NULL;
  SVector3 t1;
  double L;
  if(fields->getBackgroundField() > 0) {
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) {// we hae a true scaled cross fields !!
      Msg::Error ("Packing of Parallelograms require a scaled cross field");
      Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
      Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
      return;
    }
  }
  else {
    Msg::Error ("Packing of Parallelograms require a scaled cross field");
    Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
    Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
    return;
  }


  const bool goNonLinear = true;

  // get all the boundary vertices
  std::set<MVertex *, MVertexPtrLessThan> bnd_vertices;
  for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() < 2) bnd_vertices.insert(vertex);
    }
  }

  // Renormalize size map taking into account quantization...
  double globalMult = 1.0;

  // put boundary vertices in a fifo queue
  std::queue<surfacePointWithExclusionRegion *> fifo;
  std::vector<surfacePointWithExclusionRegion *> vertices;
  // put the RTREE
  RTree<surfacePointWithExclusionRegion *, double, 2, double> rtree;
  SMetric3 metricField(1.0);
  SPoint2 newp[8];
  std::set<MVertex *, MVertexPtrLessThan>::iterator it = bnd_vertices.begin();

  double maxu = -1.e22,minu = 1.e22;
  double maxv = -1.e22,minv = 1.e22;

  std::vector<MVertex*> singularities;
  for(; it != bnd_vertices.end(); ++it) {

    int NP = 0;
    SPoint2 midpoint;
    double du[4] = {0,0,0,0}, dv[4]= {0,0,0,0};

    //    printf("cop %d\n",(*it)->getNum());

    for (int i=0;i<2;i++){
      if (gf->periodic(i)){
	reparamMeshVertexOnFace(*it, gf, midpoint);
	Range<double> bnds = gf->parBounds(i);
	//	if (1 || midpoint[i] == bnds.low()){
	if (i == 0)
	  du[NP] =  bnds.high() -  bnds.low();
	else
	  dv[NP] =  bnds.high() -  bnds.low();
	NP++;
	//	}
	//	else if (midpoint[i] == bnds.high()){
	if (i == 0)
	  du[NP] =  -(bnds.high() -  bnds.low());
	else
	  dv[NP] =  -(bnds.high() -  bnds.low());
	NP++;
	//	}
      }
    }

    if (NP == 0)NP=1;

    for (int i=0;i<NP;i++){
      bool singular = !compute4neighbors(gf, *it, midpoint, newp, metricField, cross_field, du[i],dv[i],globalMult );
      //      printf("there %d %g %g\n",singular,du[i],dv[i]);
      if (!singular){
	surfacePointWithExclusionRegion *sp =
	  new surfacePointWithExclusionRegion(*it, newp, midpoint, metricField);
	minu = std::min(midpoint.x(),minu);
	maxu = std::max(midpoint.x(),maxu);
	minv = std::min(midpoint.y(),minv);
	maxv = std::max(midpoint.y(),maxv);
	vertices.push_back(sp);
	fifo.push(sp);
	double _min[2], _max[2];
	sp->minmax(_min, _max);
	rtree.Insert(_min, _max, sp);
      }
      else{
	singularities.push_back(*it);
	break;
      }
    }
  }

  __OK = 0;
  __KO = 0;

  while(!fifo.empty()) {
    //    printf("%d vertices in the domain\n",vertices.size());
    //    if (vertices.size() > 5000)break;
    surfacePointWithExclusionRegion *parent = fifo.front();
    fifo.pop();
    for(int i = 0; i < 4; i++) {
      if(!outBounds(parent->_p[i], minu, maxu, minv, maxv) &&
		 !inExclusionZone(parent->_v, parent->_p[i], rtree) &&
		 inParametricDomain(gf, parent->_p[i]) &&
		 !close2sing(singularities, gf, parent->_p[i], cross_field))
	{
	  GPoint gp = gf->point(parent->_p[i]);
	  MFaceVertex *v =
	    new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	  SPoint2 midpoint;
	  compute4neighbors(gf, v, midpoint, newp, metricField, cross_field,0, 0, globalMult);
	  surfacePointWithExclusionRegion *sp =
	    new surfacePointWithExclusionRegion(v, newp, midpoint, metricField, parent);
	  fifo.push(sp);
	  vertices.push_back(sp);
	  double _min[2], _max[2];
	  sp->minmax(_min, _max);
	  rtree.Insert(_min, _max, sp);
	}
      else{
	//	printf("%d %d\n", inExclusionZone(parent->_v, parent->_p[i], rtree), outBounds(parent->_p[i],minu,maxu,minv,maxv));
	if(Msg::GetVerbosity() == 99) {
	  GPoint gp = gf->point(parent->_p[i]);
	  MFaceVertex *v =
	    new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	  SPoint2 midpoint;
	  compute4neighbors(gf, v, midpoint, newp, metricField, cross_field, 0, 0 , globalMult);
	  surfacePointWithExclusionRegion *sp =
	    new surfacePointWithExclusionRegion(v, newp, midpoint, metricField,parent);
	  //	  if (!gf->containsParam(parent->_p[i]))
	  sp->print(f2, i);
	}
      }
    }
  }

  //  printf("%d %d\n",__OK,__KO);
  //  getchar();
  // add the vertices as additional vertices in the surface mesh
  for(unsigned int i = 0; i < vertices.size(); i++) {
    if (f)vertices[i]->print(f, i);
    if(vertices[i]->_v->onWhat() == gf) {
      packed.push_back(vertices[i]->_v);
      metrics.push_back(vertices[i]->_meshMetric);
      SPoint2 midpoint;
      reparamMeshVertexOnFace(vertices[i]->_v, gf, midpoint);
    }
    delete vertices[i];
  }
  if (f){
    fprintf(f2, "};");
    fclose(f2);
    fprintf(f, "};");
    fclose(f);
  }
}

/* OLD STUFF

   double uvt[3] = {newPoint[0], newPoint[1], 0.0};
  curveFunctorCircle cc(n2, n1, middle, d);
  surfaceFunctorGFace ss(gf);

  if(intersectCurveSurface(cc, ss, uvt, d * 1.e-8)) {
    // if(gf->containsParam(SPoint2(uvt[0], uvt[1]))) {
      newPoint[0] = uvt[0];
      newPoint[1] = uvt[1];
      return true;
    // }
  }


  surfaceFunctorGFace ss(gf); //
  SVector3 dirs[4] = {t1 * (-1.0), t2 * (-1.0), t1 * (1.0), t2 * (1.0)}; //
  for(int i = 0; i < 4; i++) { //
    double uvt[3] = {newPoint[i][0], newPoint[i][1], 0.0}; //

    curveFunctorCircle cf(
			  dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()),
			  L);
    if(intersectCurveSurface(cf, ss, uvt, size_1 * 1.e-2)) { //
      GPoint pp = gf->point(SPoint2(uvt[0], uvt[1]));
      double D =
	sqrt((pp.x() - v_center->x()) * (pp.x() - v_center->x()) +
	     (pp.y() - v_center->y()) * (pp.y() - v_center->y()) +
	     (pp.z() - v_center->z()) * (pp.z() - v_center->z()));
      double DP =
	sqrt((newPoint[i][0] - uvt[0]) * (newPoint[i][0] - uvt[0]) +
	     (newPoint[i][1] - uvt[1]) * (newPoint[i][1] - uvt[1]));
      double newErr = 100 * fabs(D - L) / (D + L);
      if(newErr < 1 && DP < .1) {
	newPoint[i][0] = uvt[0];
	newPoint[i][1] = uvt[1];
      }
      else {
	SPoint3 test (v_center->x() + dirs[i].x() * L,
		      v_center->y() + dirs[i].y() * L,
		      v_center->z() + dirs[i].z() * L);


	GPoint pp = gf->closestPoint(test,uvt);
	if (pp.succeeded()){
	  newPoint[i][0] = pp.u();
	  newPoint[i][1] = pp.v();
	}
	else return false;
      }
    }
    else {
      SPoint3 test (v_center->x() + dirs[i].x() * L,
		    v_center->y() + dirs[i].y() * L,
		    v_center->z() + dirs[i].z() * L);


      GPoint pp = gf->closestPoint(test,uvt);
      if (pp.succeeded()){
	newPoint[i][0] = pp.u();
	newPoint[i][1] = pp.v();
      }
      else return false;
    }
  }


  // return the four new vertices
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
  }
  return true;

 */
