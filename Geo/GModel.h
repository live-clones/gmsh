#ifndef _GMODEL_H_
#define _GMODEL_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include <algorithm>
#include <set>
#include <map>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "SBoundingBox3d.h"
#include "SmoothNormals.h"

// A geometric model. The model is a "not yet" non-manifold B-Rep.
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
  GModel(const std::string &name) : modelName(name), normals(0) {}
  virtual ~GModel(){ destroy(); }

  typedef std::set<GRegion*, GEntityLessThan>::iterator riter;
  typedef std::set<GFace*, GEntityLessThan>::iterator fiter;
  typedef std::set<GEdge*, GEntityLessThan>::iterator eiter;
  typedef std::set<GVertex*, GEntityLessThan>::iterator viter;

  // Deletes everything in a GModel 
  virtual void destroy();

  // Imports data into a GModel from an external source
  virtual void import(){}

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

  // Deletes all physical groups in the model
  void deletePhysicalGroups();

  // The bounding box
  virtual SBoundingBox3d bounds();

  // Returns the mesh status for the entire model.
  virtual int getMeshStatus();

  // The list of partitions
  virtual std::set<int> &getMeshPartitions() { return meshPartitions; }
  virtual std::set<int> &recomputeMeshPartitions();

  // deletes all the partitions
  virtual void deleteMeshPartitions();

  // IO for native Gmsh mesh file format
  int readMSH(const std::string &name);
  int writeMSH(const std::string &name, double version=1.0, bool binary=false,
	       bool saveAll=false, double scalingFactor=1.0);

  // IO for mesh statistics (as Gmsh post-processing views)
  int writePOS(const std::string &name, double scalingFactor=1.0);

  // IO for stereo lithography format
  int readSTL(const std::string &name, double tolerance=1.e-3);
  int writeSTL(const std::string &name, bool binary=false, double scalingFactor=1.0);

  // IO for Inventor/VRML format
  int readVRML(const std::string &name);
  int writeVRML(const std::string &name, double scalingFactor=1.0);

  // IO for I-deas universal mesh format
  int readUNV(const std::string &name);
  int writeUNV(const std::string &name, bool saveAll=false, double scalingFactor=1.0);

  // IO for Medit (INRIA) mesh format
  int readMESH(const std::string &name);
  int writeMESH(const std::string &name, double scalingFactor=1.0);

  // IO for Nastran Bulk Data File format (free field with comma separator)
  int readBDF(const std::string &name);
  int writeBDF(const std::string &name, double scalingFactor=1.0);

  // FIXME: this will be removed (and rewritten)
  smooth_normals *normals;
};

#endif
