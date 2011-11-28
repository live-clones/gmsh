// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GFACE_H_
#define _GFACE_H_

#include <list>
#include <string>
#include <vector>
#include <map>
#include "GEntity.h"
#include "GPoint.h"
#include "GEdgeLoop.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "Pair.h"

class MElement;
class MTriangle;
class MQuadrangle;
class MPolygon;
class ExtrudeParams;
class GFaceCompound;

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
  // edge loops might replace what follows (list of all the edges of
  // the face + directions)
  std::list<GEdge *> l_edges;
  std::list<int> l_dirs;
  GRegion *r1, *r2;
  mean_plane meanPlane;
  std::list<GEdge *> embedded_edges;
  std::list<GVertex *> embedded_vertices;
  GFaceCompound *compound; // this model ede belongs to a compound 

  // replace edges (gor gluing) for specific modelers, we have to
  // re-create internal data
  virtual void replaceEdgesInternal(std::list<GEdge*> &){}

 public: // this will become protected or private
  std::list<GEdgeLoop> edgeLoops;

  // periodic counterparts of edges
  std::map<int,int> edgeCounterparts;

  // an array with additional vertices that are supposed to exist in
  // the final mesh of the model face. This can be used for boundary
  // layer meshes or when using Lloyd-like smoothing algorithms those
  // vertices are classifed on this GFace, their type is MFaceVertex.
  // After mesh generation, those are moved to the mesh_vertices array

 public:
  GFace(GModel *model, int tag);
  virtual ~GFace();

  std::vector<MVertex*> additionalVertices;	
	
  // delete mesh data
  virtual void deleteMesh();

  // add/delete regions that are bounded by the face
  void addRegion(GRegion *r){ r1 ? r2 = r : r1 = r; }
  void delRegion(GRegion *r){ if(r1 == r) r1 = r2; r2 = 0; }
  GRegion* getRegion(int num) const{ if (num==0) return r1; else return r2;  };

  // get number of regions
  int numRegions() const { int num=0; if(r1) num++; if(r2) num++; return num; }

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
  virtual std::list<int> edgeOrientations() const { return l_dirs; }

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
  void XYZtoUV(double X, double Y, double Z, double &U, double &V,
               double relax, bool onSurface=true) const;

  // get the bounding box
  virtual SBoundingBox3d bounds() const;

  // get the oriented bounding box
  virtual SOrientedBoundingBox getOBB();
  
  // retrieve surface params
  virtual surface_params getSurfaceParams() const;

  // compute the genus G of the surface
  // we have the poincare constant CHI = #V-#E+#F
  // where #V #E and #F are the number of vertices, edges
  // and faces of the surface
  // Then, CHI = 2 G + 2 - B
  // where B is the number of boundaries (edge loops) of the
  // surface. This topological constant can be computed using both the
  // geometry and the mesh. Both approaches should give the same result ;-)
  // by default, genus is ZERO
  int poincareMesh();
  int genusMesh() { return (poincareMesh() + edgeLoops.size() - 2) / 2; }
  virtual int genusGeom();
  virtual bool checkTopology() const { return true; }

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
  
  // eigen values are absolute values and sorted from min to max of absolute values
  // eigen vectors are the COLUMNS of eigVec
  virtual void getMetricEigenVectors(const SPoint2 &param, 
                                     double eigVal[2], double eigVec[4]) const;

  // return the parmater location on the face given a point in space
  // that is on the face
  virtual SPoint2 parFromPoint(const SPoint3 &, bool onSurface=true) const;

  // true if the parameter value is interior to the face
  virtual bool containsParam(const SPoint2 &pt) const;

  // return the point on the face closest to the given point
  virtual GPoint closestPoint(const SPoint3 & queryPoint, 
                              const double initialGuess[2]) const;

  // return the normal to the face at the given parameter location
  virtual SVector3 normal(const SPoint2 &param) const;

  // return the first derivate of the face at the parameter location
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const = 0;

  // compute the second derivates of the face at the parameter location
  // the derivates have to be allocated before calling this function
  virtual void secondDer(const SPoint2 &param, 
                         SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const = 0;

  // return the curvature computed as the divergence of the normal
  inline double curvature(const SPoint2 &param) const { return curvatureMax(param); }
  virtual double curvatureDiv(const SPoint2 &param) const;

  // return the maximum curvature at a point
  virtual double curvatureMax(const SPoint2 &param) const;

  // compute the min and max curvatures and the corresponding directions
  // return the max curvature
  // outputs have to be allocated before calling this function
  virtual double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                            double *curvMax, double *curvMin) const;

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // fill the crude representation cross
  virtual bool buildRepresentationCross(bool force=false);

  // build an STL triangulation (or do nothing if it already exists,
  // unless force=true)
  virtual bool buildSTLTriangulation(bool force=false);

  // fill the vertex array using an STL triangulation
  bool fillVertexArray(bool force=false);

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
  int getNumElementTypes() const { return 3; }

  // get total/by-type number of elements in the mesh
  unsigned int getNumMeshElements();
  unsigned int getNumMeshParentElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(unsigned int index);

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  // for periodic faces, move parameters into the range chosen
  // for that face
  void moveToValidRange(SPoint2 &pt) const;

  // compound
  void setCompound(GFaceCompound *gfc) { compound = gfc; }
  GFaceCompound *getCompound() const { return compound; }

  // add points (and optionally normals) in vectors so that two
  // points are at most maxDist apart
  bool fillPointCloud(double maxDist, std::vector<SPoint3> *points,
                      std::vector<SVector3> *normals=0);

  // apply Lloyd's algorithm to the mesh
  void lloyd (int nIter, int infNorm = 0); 

  // replace edges (gor gluing)
  void replaceEdges(std::list<GEdge*> &);
  
  // tells if it's a sphere, and if it is, returns parameters
  virtual bool isSphere (double &radius, SPoint3 &center) const {return false;}

  // add layers of quads
  void addLayersOfQuads (int nLayers, GVertex *start, double hmin, double factor);
  
  struct {
    // do we recombine the triangles of the mesh?
    int recombine;
    // what is the treshold angle for recombination
    double recombineAngle;
    // is this surface meshed using a transfinite interpolation
    char Method;
    // corners of the transfinite interpolation
    std::vector<GVertex*> corners;
    // all diagonals of the triangulation are left (-1), right (1) or
    // alternated (0)
    int transfiniteArrangement;
    // do we smooth (transfinite) mesh? (<0 to use default smoothing)
    int transfiniteSmoothing;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // edge loops
  } meshAttributes ;

  typedef enum {PENDING, DONE, FAILED} meshGenerationStatus;
  struct {
    mutable meshGenerationStatus status;
    double worst_element_shape, best_element_shape, average_element_shape;
    double smallest_edge_length, longest_edge_length, efficiency_index;
    int nbEdge, nbTriangle;
    int nbGoodQuality, nbGoodLength;
  } meshStatistics;

  // a crude graphical representation using a "cross" defined by pairs
  // of start/end points
  std::vector<SPoint3> cross;

  // the STL mesh
  std::vector<SPoint2> stl_vertices;
  std::vector<int> stl_triangles;

  // a vertex array containing a geometrical representation of the
  // surface
  VertexArray *va_geom_triangles;

  // a array for accessing the transfinite vertices using a pair of
  // indices
  std::vector<std::vector<MVertex*> > transfinite_vertices;

  std::vector<MTriangle*> triangles;
  std::vector<MQuadrangle*> quadrangles;
  std::vector<MPolygon*> polygons;

  void addTriangle(MTriangle *t){ triangles.push_back(t); }
  void addQuadrangle(MQuadrangle *q){ quadrangles.push_back(q); }
  void addPolygon(MPolygon *p){ polygons.push_back(p); }
};

#endif
