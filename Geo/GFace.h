// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GFACE_H_
#define _GFACE_H_

#include "GEntity.h"
#include "GPoint.h"
#include "GEdgeLoop.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "Pair.h"

class MElement;
class MTriangle;
class MQuadrangle;
class ExtrudeParams;

struct mean_plane
{
  double plan[3][3];
  double a, b, c, d;
  double x, y, z;
};

struct surface_params
{
  double radius, radius2, height, cx, cy, cz;
};

class GRegion;

// A model face.
class GFace : public GEntity
{
 protected:
  // edge loops will replace what follows (list of al the edges of the
  // face + directions)
  std::list<GEdge *> l_edges;
  std::list<int> l_dirs;
  GRegion *r1, *r2;
  mean_plane meanPlane;
  std::list<GEdge *> embedded_edges;
  std::list<GVertex *> embedded_vertices;
  // given a list of GEdges, the function builds a list of wires,
  // i.e. closed edge loops.  the first wire is the one that is the
  // outer contour of the face.
  void resolveWires();

 public: // this will become protected or private
  std::list<GEdgeLoop> edgeLoops;

 public:
  GFace(GModel *model, int tag);
  virtual ~GFace();

  // delete mesh data
  virtual void deleteMesh();

  // add/delete regions that are bounded by the face
  void addRegion(GRegion *r){ r1 ? r2 = r : r1 = r; }
  void delRegion(GRegion *r){ if(r1 == r) r1 = r2; r2 = 0; }

  // add embedded vertices/edges
  void addEmbeddedVertex(GVertex *v){ embedded_vertices.push_back(v); }
  void addEmbeddedEdge(GEdge *e){ embedded_edges.push_back(e); }
  
  // delete the edge from the face (the edge is supposed to be a free
  // edge in the face, not part of any edge loops--use with caution!)
  void delFreeEdge(GEdge *e);

  // edge orientations
  virtual std::list<int> orientations() const { return l_dirs; }

  // edges that bound the face
  virtual std::list<GEdge*> edges() const { return l_edges; }

  // edges that are embedded in the face
  virtual std::list<GEdge*> embeddedEdges() const { return embedded_edges; }

  // edges that are embedded in the face
  virtual std::list<GVertex*> embeddedVertices() const { return embedded_vertices; }

  // vertices that bound the face
  virtual std::list<GVertex*> vertices() const;

  // dimension of the face (2)
  virtual int dim() const { return 2; }

  // set visibility flag
  virtual void setVisibility(char val, bool recursive=false);

  // compute the parameters UV from a point XYZ
  void XYZtoUV(const double X, const double Y, const double Z,
               double &U, double &V, const double relax,
               const bool onSurface=true) const;

  // get the bounding box
  virtual SBoundingBox3d bounds() const;

  // retrieve surface params
  virtual surface_params getSurfaceParams() const;

  // return the point on the face corresponding to the given parameter
  virtual GPoint point(double par1, double par2) const = 0;
  virtual GPoint point(const SPoint2 &pt) const { return point(pt.x(), pt.y()); }

  // compute, in parametric space, the interpolation from pt1 to pt2
  // along a geodesic of the surface
  virtual SPoint2 geodesic(const SPoint2 &pt1, const SPoint2 &pt2, double t);

  // compute the length of a geodesic between two points in parametric
  // space
  virtual double length(const SPoint2 &pt1, const SPoint2 &pt2, int n=4);

  // if the mapping is a conforming mapping, i.e. a mapping that
  // conserves angles, this function returns the eigenvalue of the
  // metric at a given point this is a special feature for
  // stereographic mappings of the sphere that is used in 2D mesh
  // generation !
  virtual double getMetricEigenvalue(const SPoint2 &);

  // return the parmater location on the face given a point in space
  // that is on the face
  virtual SPoint2 parFromPoint(const SPoint3 &) const;

  // true if the parameter value is interior to the face
  virtual bool containsParam(const SPoint2 &pt) const;

  // return the point on the face closest to the given point
  virtual GPoint closestPoint(const SPoint3 & queryPoint, const double initialGuess[2]) const;

  // return the normal to the face at the given parameter location
  virtual SVector3 normal(const SPoint2 &param) const;

  // return the first derivate of the face at the parameter location
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const = 0;

  // return the curvature i.e. the divergence of the n$ormal
  virtual double curvature(const SPoint2 &param) const;

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // fill the crude representation cross
  virtual bool buildRepresentationCross();

  // build a STL triangulation and fills the vertex array
  // va_geom_triangles
  virtual bool buildSTLTriangulation();

  // recompute the mean plane of the surface from a list of points
  void computeMeanPlane(const std::vector<MVertex*> &points);
  void computeMeanPlane(const std::vector<SPoint3> &points);

  // recompute the mean plane of the surface from its bounding vertices
  void computeMeanPlane();

  // get the mean plane info
  void getMeanPlaneData(double VX[3], double VY[3],
                        double &x, double &y, double &z) const;
  void getMeanPlaneData(double plan[3][3]) const;

  // number of types of elements
  int getNumElementTypes() const { return 2; }

  // get total/by-type number of elements in the mesh
  unsigned int getNumMeshElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(unsigned int index);

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  struct {
    // do we recombine the triangles of the mesh?
    int recombine;
    // what is the treshold angle for recombination
    double recombineAngle;
    // is this surface meshed using a transfinite interpolation
    char Method;
    // corners of the transfinite interpolation
    std::vector<GVertex*> corners;
    // all diagonals of the triangulation are left (1), right (2) or
    // alternated (3)
    int transfiniteArrangement;
    // do we smooth (transfinite) mesh? (<0 to use default smoothing)
    int transfiniteSmoothing;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // edge loops
  } meshAttributes ;

  typedef enum {PENDING, DONE, FAILED} meshGenerationStatus;
  struct {
    meshGenerationStatus status;
    double worst_element_shape, best_element_shape, average_element_shape;
    double smallest_edge_length, longest_edge_length, efficiency_index;
    int nbEdge, nbTriangle;
    int nbGoodQuality, nbGoodLength;
  } meshStatistics;

  // a crude graphical representation using a "cross" defined by pairs
  // of start/end points
  std::vector<SPoint3> cross;

  // a vertex array containing an STL representation of the surface
  VertexArray *va_geom_triangles;

  // a array for accessing the transfinite vertices using a pair of
  // indices
  std::vector<std::vector<MVertex*> > transfinite_vertices;

  std::vector<MTriangle*> triangles;
  std::vector<MQuadrangle*> quadrangles;
};

#endif
