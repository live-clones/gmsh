// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GFACE_H
#define GFACE_H

#include <list>
#include <string>
#include <vector>
#include <map>
#include "GmshDefines.h"
#include "GEntity.h"
#include "GPoint.h"
#include "GEdgeLoop.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "Pair.h"
#include "Numeric.h"
#include "boundaryLayersData.h"

class MElement;
class MTriangle;
class MQuadrangle;
class MPolygon;
class ExtrudeParams;

class GRegion;

// A model face.
class GFace : public GEntity {
protected:
  // edge loops might replace what follows (list of all the edges of
  // the face + directions)
  std::vector<GEdge *> l_edges;
  std::vector<int> l_dirs;
  GRegion *r1, *r2;
  mean_plane meanPlane;
  std::vector<GEdge *> embedded_edges;
  std::set<GVertex *, GEntityPtrLessThan> embedded_vertices;

  BoundaryLayerColumns _columns;

public: // this will become protected or private
  std::vector<GEdgeLoop> edgeLoops;

  // periodic counterparts of edges
  std::map<GEdge *, std::pair<GEdge *, int> > edgeCounterparts;

  // specify mesh master with transformation, deduce edgeCounterparts
  void setMeshMaster(GFace *master, const std::vector<double> &);

  // specify mesh master and edgeCounterparts, deduce transformation
  void setMeshMaster(GFace *master, const std::map<int, int> &);

  // align elements with mesh master
  void alignElementsWithMaster();

public:
  GFace(GModel *model, int tag);
  virtual ~GFace();

  // delete mesh data
  virtual void deleteMesh();

  // delete the geometry vertex arrays
  void deleteGeometryVertexArrays();

  // add/delete regions that are bounded by the face
  void addRegion(GRegion *r)
  {
    if(r == r1 || r == r2) return;
    r1 ? r2 = r : r1 = r;
  }
  void delRegion(GRegion *r)
  {
    if(r1 == r) r1 = r2;
    r2 = nullptr;
  }
  GRegion *getRegion(int const num) const { return num == 0 ? r1 : r2; }

  // get number of regions
  std::size_t numRegions() const { return (r1 != nullptr) + (r2 != nullptr); }

  std::list<GRegion *> regions() const
  {
    std::list<GRegion *> r;
    for(std::size_t i = 0; i < numRegions(); i++) r.push_back(getRegion(i));
    return r;
  }

  // is this entity an orphan?
  virtual bool isOrphan();

  // add embedded vertices/edges
  void addEmbeddedVertex(GVertex *v) { embedded_vertices.insert(v); }
  void addEmbeddedEdge(GEdge *e) { embedded_edges.push_back(e); }

  // edges that bound the face
  int delEdge(GEdge *edge);
  virtual std::vector<GEdge *> const &edges() const { return l_edges; }
  virtual std::vector<int> const &edgeOrientations() const { return l_dirs; }
  void set(const std::vector<GEdge *> &f) { l_edges = f; }
  void setOrientations(const std::vector<int> &f) { l_dirs = f; }
  void setEdge(GEdge *const f, int const orientation)
  {
    l_edges.push_back(f);
    l_dirs.push_back(orientation);
  }

  bool containsEdge(int const iEdge) const
  {
    for(auto it = l_edges.begin(); it != l_edges.end(); ++it)
      if((*it)->tag() == iEdge) return true;
    return false;
  }

  void setBoundEdges(const std::vector<int> &tagEdges);
  void setBoundEdges(const std::vector<int> &tagEdges,
                     const std::vector<int> &signEdges);

  // check if the surface mesh is planar in which case the normal is given
  bool normalToPlanarMesh(SVector3 &normal, bool orient = true) const;

  // direct access to embedded entities
  std::vector<GEdge *> &embeddedEdges() { return embedded_edges; }
  std::set<GVertex *, GEntityPtrLessThan> &embeddedVertices()
  {
    return embedded_vertices;
  }

  // get embedded entities; if force is not set, don't return them if the face
  // is part of a compound
  std::vector<GVertex *> getEmbeddedVertices(bool force = false) const;
  std::vector<GEdge *> getEmbeddedEdges(bool force = false) const;
  std::vector<MVertex *> getEmbeddedMeshVertices(bool force = false) const;

  // vertices that bound the face
  virtual std::vector<GVertex *> vertices() const;

  // dimension of the face (2)
  virtual int dim() const { return 2; }

  // returns the parent entity for partitioned entities
  virtual GEntity *getParentEntity() { return nullptr; }

  // set visibility flag
  virtual void setVisibility(char val, bool recursive = false);

  // set color
  virtual void setColor(unsigned int val, bool recursive = false);

  // compute the parameters UV from a point XYZ
  void XYZtoUV(double X, double Y, double Z, double &U, double &V, double relax,
               bool onSurface = true, bool convTestXYZ = false) const;

  // get the bounding box
  virtual SBoundingBox3d bounds(bool fast = false);

  // get the oriented bounding box
  virtual SOrientedBoundingBox getOBB();

  // compute the genus G of the surface
  virtual int genusGeom() const;
  virtual bool checkTopology() const { return true; }

  // return the point on the face corresponding to the given parameter
  virtual GPoint point(double par1, double par2) const = 0;
  virtual GPoint point(const SPoint2 &pt) const
  {
    return point(pt.x(), pt.y());
  }

  // if the mapping is a conforming mapping, i.e. a mapping that
  // conserves angles, this function returns the eigenvalue of the
  // metric at a given point this is a special feature for
  // stereographic mappings of the sphere that is used in 2D mesh
  // generation !
  virtual double getMetricEigenvalue(const SPoint2 &);

  // eigen values are absolute values and sorted from min to max of absolute
  // values eigen vectors are the COLUMNS of eigVec
  virtual void getMetricEigenVectors(const SPoint2 &param, double eigVal[2],
                                     double eigVec[4]) const;

  // return the parameter location on the face given a point in space
  // that is on the face
  virtual SPoint2 parFromPoint(const SPoint3 &, bool onSurface = true,
                               bool convTestXYZ = false) const;

  // true if the parameter value is interior to the face
  virtual bool containsParam(const SPoint2 &pt);

  // return the point on the face closest to the given point
  virtual GPoint closestPoint(const SPoint3 &queryPoint,
                              const double initialGuess[2]) const;

  // return the normal to the face at the given parameter location
  virtual SVector3 normal(const SPoint2 &param) const;

  // return the first derivate of the face at the parameter location
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const = 0;

  // compute the second derivates of the face at the parameter location
  virtual void secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
                         SVector3 &dudv) const = 0;

  // return the curvature computed as the divergence of the normal
  inline double curvature(const SPoint2 &param) const
  {
    return curvatureMax(param);
  }
  virtual double curvatureDiv(const SPoint2 &param) const;

  // return the maximum curvature at a point
  virtual double curvatureMax(const SPoint2 &param) const;

  // compute the min and max curvatures and the corresponding directions
  // return the max curvature
  virtual double curvatures(const SPoint2 &param, SVector3 &dirMax,
                            SVector3 &dirMin, double &curvMax,
                            double &curvMin) const;

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString(bool multline = false);

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // export in Python
  virtual void writePY(FILE *fp);

  // fill the crude representation cross
  virtual bool buildRepresentationCross(bool force = false);

  // build an STL triangulation (or do nothing if it already exists,
  // unless force=true)
  virtual bool buildSTLTriangulation(bool force = false);

  // fill the vertex array using an STL triangulation
  bool fillVertexArray(bool force = false);

  // store the STL triangulation as the mesh of the surface
  bool storeSTLAsMesh();

  // recompute the mean plane of the surface from a list of points
  void computeMeanPlane(const std::vector<MVertex *> &points);
  void computeMeanPlane(const std::vector<SPoint3> &points);

  // recompute the mean plane of the surface from its bounding vertices
  void computeMeanPlane();

  // get the mean plane info
  void getMeanPlaneData(double VX[3], double VY[3], double &x, double &y,
                        double &z) const;
  void getMeanPlaneData(double plan[3][3]) const;

  // types of elements
  virtual void getElementTypes(std::vector<int> &types) const
  {
    types.clear();
    types.push_back(TYPE_TRI);
    types.push_back(TYPE_QUA);
    types.push_back(TYPE_POLYG);
  };

  // get total/by-type number of elements in the mesh
  std::size_t getNumMeshElements() const;
  std::size_t getNumMeshElementsByType(const int familyType) const;
  std::size_t getNumMeshParentElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(std::size_t index) const;
  // get the element at the given index for a given familyType
  MElement *getMeshElementByType(const int familyType,
                                 const std::size_t index) const;

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  // for periodic faces, move parameters into the range chosen
  // for that face
  void moveToValidRange(SPoint2 &pt) const;

  // compute mesh statistics
  void computeMeshSizeFieldAccuracy(double &avg, double &max_e, double &min_e,
                                    int &nE, int &GS);

  // add points (and optionally normals) in vectors so that two
  // points are at most maxDist apart
  bool fillPointCloud(double maxDist, std::vector<SPoint3> *points,
                      std::vector<SPoint2> *uvpoints = nullptr,
                      std::vector<SVector3> *normals = nullptr);

  // tells if it's a sphere, and if it is, returns parameters
  virtual bool isSphere(double &radius, SPoint3 &center) const { return false; }

  // new interface for meshing
  virtual void mesh(bool verbose);

  struct {
    // do we recombine the triangles of the mesh?
    int recombine;
    // what is the treshold angle for recombination
    double recombineAngle;
    // is this surface meshed using a transfinite interpolation
    char method;
    // corners of the transfinite interpolation
    std::vector<GVertex *> corners;
    // all diagonals of the triangulation are left (-1), right (1) or
    // alternated starting at right (2) or left (-2)
    int transfiniteArrangement;
    // do we smooth (transfinite) mesh? (<0 to use default smoothing)
    int transfiniteSmoothing;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // reverse mesh orientation
    bool reverseMesh;
    // global mesh size constraint for the surface
    double meshSize, meshSizeFactor;
    // do we force the meshing algorithm (if != 0)
    int algorithm;
    // do we force calculation of mesh size from boundary (if >= 0)
    int meshSizeFromBoundary;
    // do we use a specific transfinite algorithm for 3-sided surfaces
    bool transfinite3;
  } meshAttributes;

  int getMeshingAlgo() const;
  void setMeshingAlgo(int val) { meshAttributes.algorithm = val; }
  void unsetMeshingAlgo() { meshAttributes.algorithm = 0; }
  int getMeshSizeFromBoundary() const;
  void setMeshSizeFromBoundary(int val)
  {
    meshAttributes.meshSizeFromBoundary = val;
  }
  virtual double getMeshSize() const { return meshAttributes.meshSize; }
  virtual double getMeshSizeFactor() const
  {
    return meshAttributes.meshSizeFactor;
  }

  struct {
    mutable GEntity::MeshGenerationStatus status;
    bool refineAllEdges;
    double worst_element_shape, best_element_shape, average_element_shape;
    double smallest_edge_length, longest_edge_length, efficiency_index;
    int nbEdge, nbTriangle;
    int nbGoodQuality, nbGoodLength;
  } meshStatistics;

  // a crude graphical representation using a "cross" represented by points
  // along u and v parameter lines
  std::vector<std::vector<SPoint3> > cross[2];

  // the STL mesh
  std::vector<SPoint2> stl_vertices_uv;
  std::vector<SPoint3> stl_vertices_xyz;
  std::vector<SVector3> stl_normals;
  std::vector<SVector3> stl_curvatures;
  std::vector<int> stl_triangles;

  // a vertex array containing a geometrical representation of the
  // surface
  VertexArray *va_geom_triangles;

  // a array for accessing the transfinite vertices using a pair of
  // indices
  std::vector<std::vector<MVertex *> > transfinite_vertices;

  // FIXME: testing for constrained packing of parallelogram algo
  std::set<MVertex *> constr_vertices;

  // relocate mesh vertices using parametric coordinates
  void relocateMeshVertices();

  std::vector<MTriangle *> triangles;
  std::vector<MQuadrangle *> quadrangles;
  std::vector<MPolygon *> polygons;

  // when a compound of surfaces is created, we keep track of the compound
  // surface
  GFace *compoundSurface;

  void addTriangle(MTriangle *t) { triangles.push_back(t); }
  void addQuadrangle(MQuadrangle *q) { quadrangles.push_back(q); }
  void addPolygon(MPolygon *p) { polygons.push_back(p); }
  void addElement(MElement *e);
  void removeElement(MElement *e, bool del=false);
  void removeElements(bool del=false);

  // get the boundary layer columns
  BoundaryLayerColumns *getColumns() { return &_columns; }

  std::vector<SPoint3> storage1; // sizes and directions storage
  std::vector<SVector3> storage2; // sizes and directions storage
  std::vector<SVector3> storage3; // sizes and directions storage
  std::vector<double> storage4; // sizes and directions storage

  virtual bool reorder(const int elementType,
                       const std::vector<std::size_t> &ordering);

  virtual bool isFullyDiscrete();
};

#endif
