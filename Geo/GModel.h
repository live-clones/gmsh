#ifndef _GMODEL_H_
#define _GMODEL_H_

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

#include <algorithm>
#include <set>
#include <map>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "SBoundingBox3d.h"
#include "SmoothData.h"

// OCC Internals have to be stored in the model
class OCC_Internals;

// A geometric model. The model is a "not yet" non-manifold B-Rep.
class GModel  
{
 private:
  void deleteOCCInternals();
  OCC_Internals *occ_internals;

 protected:
  std::string modelName;
  std::set<GRegion*, GEntityLessThan> regions;
  std::set<GFace*, GEntityLessThan> faces;
  std::set<GEdge*, GEntityLessThan> edges;
  std::set<GVertex*, GEntityLessThan> vertices;
  std::set<int> meshPartitions;
  std::map<int, std::string> physicalNames;

 public:
  GModel() : modelName("Untitled"), normals(0) {}
  GModel(const std::string &name) : modelName(name), normals(0) {}
  ~GModel(){ deleteOCCInternals(); destroy(); }
  
  typedef std::set<GRegion*, GEntityLessThan>::iterator riter;
  typedef std::set<GFace*, GEntityLessThan>::iterator fiter;
  typedef std::set<GEdge*, GEntityLessThan>::iterator eiter;
  typedef std::set<GVertex*, GEntityLessThan>::iterator viter;
  typedef std::map<int, std::string>::iterator piter;

  // Deletes everything in a GModel 
  void destroy();

  // Returns the geometric tolerance for the entire model.
  double tolerance() const { return 1.e-14; }

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
  GRegion *regionByTag(int n) const;
  GFace *faceByTag(int n) const;
  GEdge *edgeByTag(int n) const;
  GVertex *vertexByTag(int n) const;

  void add(GRegion *r) { regions.insert(r); }
  void add(GFace *f) { faces.insert(f); }
  void add(GEdge *e) { edges.insert(e); }
  void add(GVertex *v) { vertices.insert(v); }

  void remove(GRegion *r) { regions.erase(std::find(firstRegion(), lastRegion(), r)); }
  void remove(GFace *f) { faces.erase(std::find(firstFace(), lastFace(), f)); }
  void remove(GEdge *e) { edges.erase(std::find(firstEdge(), lastEdge(), e)); }
  void remove(GVertex *v) { vertices.erase(std::find(firstVertex(), lastVertex(), v)); }

  // loop over all vertices connected to elements and associate geo entity
  void associateEntityWithVertices();

  // Renumber all the (used) mesh vertices in a continuous sequence
  int renumberMeshVertices(bool saveAll);

  // Deletes all invisble mesh elements
  void removeInvisibleElements();

  // Checks if there are no physical entities in the model
  bool noPhysicalGroups();

  // Returns all physical groups (one map per dimension: 0-D to 3-D)
  void getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4]);

  // Deletes physical groups in the model
  void deletePhysicalGroups();
  void deletePhysicalGroup(int dim, int num);

  // Returns the highest number associated with a physical entity
  int maxPhysicalNumber();

  // Get an iterator on the physical name
  piter firstPhysicalName() { return physicalNames.begin(); }
  piter lastPhysicalName() { return physicalNames.end(); }

  // Get the number of physical names
  int numPhysicalNames(){ return physicalNames.size(); }

  // Associate a name with a physical number (returns new id if number==0)
  int setPhysicalName(std::string name, int number=0);

  // create a new physical name and return the automatic associated number
  std::string getPhysicalName(int number);

  // The bounding box
  SBoundingBox3d bounds();

  // Returns the mesh status for the entire model
  int getMeshStatus(bool countDiscrete=true);

  // Returns the total number of vertices in the mesh
  int numVertices();

  // Returns the total number of elements in the mesh
  int numElements();

  // The list of partitions
  std::set<int> &getMeshPartitions() { return meshPartitions; }
  std::set<int> &recomputeMeshPartitions();

  // Deletes all the partitions
  void deleteMeshPartitions();

  // Performs various coherence tests on the mesh
  void checkMeshCoherence();

  // A container for smooth normals
  smooth_normals *normals;

  // CAD IO
  // =========================================

  // Gmsh native CAD format
  int importTHEM();
  int readGEO(const std::string &name);
  int writeGEO(const std::string &name, bool printLabels=true);

  // Fourier model
  int readFourier(const std::string &name);

  // OCC model
  int readOCCBREP(const std::string &name);
  int readOCCIGES(const std::string &name);
  int readOCCSTEP(const std::string &name);
  void deleleOCCInternals();

  // Mesh IO
  // =========================================

  // Gmsh mesh file format
  int readMSH(const std::string &name);
  int writeMSH(const std::string &name, double version=1.0, bool binary=false,
	       bool saveAll=false, double scalingFactor=1.0);

  // Mesh statistics (as Gmsh post-processing views)
  int writePOS(const std::string &name, 
	       bool saveAll=false, double scalingFactor=1.0);

  // Stereo lithography format
  int readSTL(const std::string &name, double tolerance=1.e-3);
  int writeSTL(const std::string &name, bool binary=false,
	       bool saveAll=false, double scalingFactor=1.0);

  // Inventor/VRML format
  int readVRML(const std::string &name);
  int writeVRML(const std::string &name, 
		bool saveAll=false, double scalingFactor=1.0);

  // I-deas universal mesh format
  int readUNV(const std::string &name);
  int writeUNV(const std::string &name, 
	       bool saveAll=false, double scalingFactor=1.0);

  // Medit (INRIA) mesh format
  int readMESH(const std::string &name);
  int writeMESH(const std::string &name, 
		bool saveAll=false, double scalingFactor=1.0);

  // Nastran Bulk Data File format
  int readBDF(const std::string &name);
  int writeBDF(const std::string &name, int format=0,
	       bool saveAll=false, double scalingFactor=1.0);

  // Plot3D structured mesh format
  int readP3D(const std::string &name);
  int writeP3D(const std::string &name, 
	       bool saveAll=false, double scalingFactor=1.0);

  // CFD General Notation System files
  int readCGNS(const std::string &name);
  int writeCGNS(const std::string &name, double scalingFactor=1.0);

  // Med interface ("Modele d'Echange de Donnees")
  int writeMED(const std::string &name);
};

#endif
