#ifndef _GFACE_H_
#define _GFACE_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "GEntity.h"
#include "GPoint.h"
#include "GEdgeLoop.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "Pair.h"

class MTriangle;
class MQuadrangle;
class ExtrudeParams;

struct mean_plane
{
  double plan[3][3];
  double a, b, c, d;
  double x, y, z;
};

struct graphics_point
{
  float xyz[3];
  float n[3];
};

struct surface_params
{
  double radius, radius2, height, cx, cy, cz;
};

class GRegion;

// A model face. 
class GFace : public GEntity 
{
 private:
  // a graphical representation for topologically simple surfaces: a
  // 2D array of points/normals
  std::vector<std::vector<graphics_point> > _graphicsRep;

 protected: 
  // edge loops, will replace what follows list of al the edges of the
  // face
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
  // builds a STL triangulation and fill the vertex array
  // va_geom_triangles (by default, do nothing)
  virtual bool buildSTLTriangulation () { return false; }
 public:
  GFace(GModel *model, int tag);
  virtual ~GFace();

  std::list<GEdgeLoop> edgeLoops;

  void addRegion(GRegion *r){ r1 ? r2 = r : r1 = r; }
  void delRegion(GRegion *r){ if(r1 == r) r1 = r2; r2 = 0; }

  // edge orientations.
  virtual std::list<int> orientations() const { return l_dirs; }

  // Edges that bound this entity or that this entity bounds.
  virtual std::list<GEdge*> edges() const { return l_edges; }

  // Edges that are embedded in this face.
  virtual std::list<GEdge*> embeddedEdges() const { return embedded_edges; }

  // Vertices that bound this entity or that this entity bounds.
  virtual std::list<GVertex*> vertices() const;

  virtual int dim() const { return 2; }
  virtual void setVisibility(char val, bool recursive=false);

  // compute the parameters UV from a point XYZ
  void XYZtoUV(const double X, const double Y, const double Z, 
	       double &U, double &V, const double relax, 
	       const bool onSurface=true) const;

  // The bounding box
  virtual SBoundingBox3d bounds() const; 

  // retrieve surface params 
  virtual surface_params getSurfaceParams() const { throw; }

  // Return the point on the face corresponding to the given parameter.
  virtual GPoint point(double par1, double par2) const = 0;
  virtual GPoint point(const SPoint2 &pt) const { return point(pt.x(), pt.y()); }

  // If the mapping is a conforming mapping, i.e. a mapping that
  // conserves angles, this function returns the eigenvalue of the
  // metric at a given point this is a special feature for
  // stereographic mappings of the sphere that is used in 2D mesh
  // generation !
  virtual double getMetricEigenvalue(const SPoint2 &){ throw; }

  // Return the parmater location on the face given a point in space
  // that is on the face.
  virtual SPoint2 parFromPoint(const SPoint3 &) const;

  // True if the parameter value is interior to the face.
  virtual int containsParam(const SPoint2 &pt) const = 0;

  // Return the point on the face closest to the given point.
  virtual GPoint closestPoint(const SPoint3 & queryPoint) const { throw; }

  // Return the normal to the face at the given parameter location.
  virtual SVector3 normal(const SPoint2 &param) const = 0;

  // Return the first derivate of the face at the parameter location.
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const = 0;

  // Return the curvature i.e. the divergence of the normal
  virtual double curvature(const SPoint2 &param) const;
  
  // Recompute the mesh partitions defined on this face.
  void recomputeMeshPartitions();

  // Delete the mesh partitions defined on this face.
  void deleteMeshPartitions();

  // Returns a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // Recompute the mean plane of the surface from a list of points
  void computeMeanPlane(const std::vector<MVertex*> &points);
  void computeMeanPlane(const std::vector<SPoint3> &points);

  // Recompute the mean plane of the surface from its bounding vertices
  void computeMeanPlane();

  // Get the mean plane info
  void getMeanPlaneData(double VX[3], double VY[3], 
			double &x, double &y, double &z) const;
  void getMeanPlaneData(double plan[3][3]) const;

  // Resets the mesh attributes to default values
  virtual void resetMeshAttributes();

  struct {
    // do we recombine the triangles of the mesh ?
    int recombine;
    // what is the treshold angle for recombination
    double recombineAngle;
    // is this surface meshed using a transfinite interpolation
    int Method;
    // corners of the transfinite interpolation
    std::vector<GVertex*> corners;
    // all diagonals of the triangulation are left (1), right (2) or
    // alternated (3)
    int transfiniteArrangement;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // edge loops
  } meshAttributes ;

  typedef enum {PENDING,DONE,FAILED} meshGenerationStatus;
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

  // fill the graphics representation
  void computeGraphicsRep(int nu, int nv);

  // fill the graphics representation
  std::vector<std::vector<graphics_point> > &getGraphicsRep(){ return _graphicsRep;}

  // a array for accessing the transfinite vertices using a pair of
  // indices
  std::vector<std::vector<MVertex*> > transfinite_vertices;

  std::vector<MTriangle*> triangles;
  std::vector<MQuadrangle*> quadrangles;

  // Vertex array to draw the geometry efficiently
  VertexArray *va_geom_triangles;
};

#endif
