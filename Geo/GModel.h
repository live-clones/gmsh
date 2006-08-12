#ifndef _GMODEL_H_
#define _GMODEL_H_

#include <algorithm>
#include <set>
#include <map>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "SBoundingBox3d.h"

// A geometric model. The model is a non-manifold B-Rep.

class GModel  
{
 protected:
  std::string modelName;
  std::set<GRegion*, GEntityLessThan> regions;
  std::set<GFace*, GEntityLessThan> faces;
  std::set<GEdge*, GEntityLessThan> edges;
  std::set<GVertex*, GEntityLessThan> vertices;
  std::set<int> meshPartitions;

 public:
  GModel(const std::string &name) : modelName(name) {}
  virtual ~GModel() {}

  virtual void import(){}

  typedef std::set<GRegion*, GEntityLessThan>::iterator riter;
  typedef std::set<GFace*, GEntityLessThan>::iterator fiter;
  typedef std::set<GEdge*, GEntityLessThan>::iterator eiter;
  typedef std::set<GVertex*, GEntityLessThan>::iterator viter;

  // Returns the geometric tolerance for the entire model.
  virtual double tolerance() const { return 1.e-14; }

  // Get the number of regions in this model.
  int numRegion() const { return regions.size(); }
  int numFace() const { return faces.size(); }
  int numEdge() const { return edges.size(); }
  int numVertex() const  { return vertices.size(); }

  // Get an iterator initialized to the first entity in this model.
  riter firstRegion() { return regions.begin(); }
  fiter firstFace() { return faces.begin(); }
  eiter firstEdge() { return edges.begin(); }
  viter firstVertex() { return vertices.begin(); }
  riter lastRegion() { return regions.end(); }
  fiter lastFace() { return faces.end(); }
  eiter lastEdge() { return edges.end(); }
  viter lastVertex() { return vertices.end(); }

  // Find the region with the given tag.
  virtual GRegion *regionByTag(int n) const;
  virtual GFace *faceByTag(int n) const;
  virtual GEdge *edgeByTag(int n) const;
  virtual GVertex *vertexByTag(int n) const;

  void add(GRegion *r) { regions.insert(r); }
  void add(GFace *f) { faces.insert(f); }
  void add(GEdge *e) { edges.insert(e); }
  void add(GVertex *v) { vertices.insert(v); }

  void remove(GRegion *r) { regions.erase(std::find(firstRegion(), lastRegion(), r)); }
  void remove(GFace *f) { faces.erase(std::find(firstFace(), lastFace(), f)); }
  void remove(GEdge *e) { edges.erase(std::find(firstEdge(), lastEdge(), e)); }
  void remove(GVertex *v) { vertices.erase(std::find(firstVertex(), lastVertex(), v)); }

  // Renumber all the mesh vertices in a continuous sequence
  int renumberMeshVertices();

  // Checks if there are no physical entities in the model
  bool noPhysicalGroups();

  // Returns all physical groups (one map per dimension: 0-D to 3-D)
  void getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4]);

  // The bounding box
  virtual SBoundingBox3d bounds();

  // Returns the mesh status for the entire model.
  virtual int getMeshStatus();

  // The list of partitions
  virtual std::set<int> &getMeshPartitions() { return meshPartitions; }
  virtual std::set<int> &recomputeMeshPartitions();

  // IO routines
  int readMSH(const std::string &name);
  int writeMSH(const std::string &name, double version=1.0, bool saveAll=false,
	       double scalingFactor=1.0);
  int writePOS(const std::string &name, double scalingFactor=1.0);
  int readSTL(const std::string &name, double tolerance=1.e-3);
  int writeSTL(const std::string &name, double scalingFactor=1.0);
  int writeVRML(const std::string &name, double scalingFactor=1.0);
  int writeUNV(const std::string &name, double scalingFactor=1.0);
  int readMESH(const std::string &name);
  int writeMESH(const std::string &name, double scalingFactor=1.0);
};

#endif
