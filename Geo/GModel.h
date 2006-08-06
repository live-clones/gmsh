#ifndef _GMODEL_H_
#define _GMODEL_H_

#include <algorithm>
#include <set>
#include <map>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

// A geometric model. The model is a non-manifold B-Rep.

class GModel  
{
public:
  virtual ~GModel() {}

  typedef std::set<GRegion*, EntityLessThan>::iterator riter;
  typedef std::set<GFace*,   EntityLessThan>::iterator fiter;
  typedef std::set<GEdge*,   EntityLessThan>::iterator eiter;
  typedef std::set<GVertex*, EntityLessThan>::iterator viter;

  // Returns the geometric tolerance for the entire model.
  virtual double tolerance() const {return 1.e-14;}

  // Get the number of regions in this model.
  int numRegion() const;
  int numFace  () const;
  int numEdge  () const;
  int numVertex() const;

  // Get an iterator initialized to the first entity in this model.
  riter firstRegion() {return regions.begin();}
  fiter firstFace() {return faces.begin();}
  eiter firstEdge()  {return edges.begin();}
  viter firstVertex() {return vertices.begin();}
  riter lastRegion() {return regions.end();}
  fiter lastFace() {return faces.end();}
  eiter lastEdge() {return edges.end();}
  viter lastVertex() {return vertices.end();}

  // Find the region with the given tag.
  virtual GRegion * regionByTag(int n) const;
  virtual GFace   * faceByTag  (int n) const;
  virtual GEdge   * edgeByTag  (int n) const;
  virtual GVertex * vertexByTag(int n) const;

  void add(GRegion *r){regions.insert(r);}
  void add(GFace *f)  {faces.insert(f);}
  void add(GEdge *e)  {edges.insert(e);}
  void add(GVertex *v){vertices.insert(v);}

  void remove(GRegion *r){regions.erase(std::find(firstRegion(),lastRegion(),r));}
  void remove(GFace *f){faces.erase(std::find(firstFace(),lastFace(),f));}
  void remove(GEdge *e){edges.erase(std::find(firstEdge(),lastEdge(),e));}
  void remove(GVertex *v){vertices.erase(std::find(firstVertex(),lastVertex(),v));}

  // Renumber all the mesh vertices in a continuous sequence
  int renumberMeshVertices();

  // Checks if there are no physical entities in the model
  bool noPhysicals();

  // Returns all physical groups (one map per dimension: 0-D to 3-D)
  void getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4]);

  // IO routines
  int readMSH(const std::string &name);
  int writeMSH(const std::string &name, double version=1.0, bool saveAll=false,
	       double scalingFactor=1.0);
  int writePOS(const std::string &name, double scalingFactor=1.0);
  int writeSTL(const std::string &name, double scalingFactor=1.0);
  int writeVRML(const std::string &name, double scalingFactor=1.0);
  int writeUNV(const std::string &name, double scalingFactor=1.0);

protected:
  std::string modelName;
  GModel(const std::string &name):modelName(name){}
  std::set<GRegion*, EntityLessThan> regions;
  std::set<GFace*, EntityLessThan> faces;
  std::set<GEdge*, EntityLessThan> edges;
  std::set<GVertex*, EntityLessThan> vertices;
};

#endif
