// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODEL_H
#define GMODEL_H

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <functional>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "MFaceHash.h"
#include "MEdgeHash.h"


template <class scalar> class simpleFunction;

class GEO_Internals;
class OCC_Internals;
class ACIS_Internals;
class Parasolid_Internals;
class smooth_normals;
class FieldManager;
class gLevelset;
class discreteFace;
class discreteRegion;
class MElementOctree;

// A geometric model. The model is a "not yet" non-manifold B-Rep.
class GModel {
public:
  using hashmapMFace = std::unordered_map<MFace, std::size_t, MFaceHash, MFaceEqual>;
  using hashmapMEdge = std::unordered_map<MEdge, std::size_t, MEdgeHash, MEdgeEqual>;
private:

  std::multimap<std::pair<const std::vector<int>, const std::vector<int> >,
                std::pair<const std::string, const std::vector<int> > >
    _homologyRequests;
  std::set<GRegion *, GEntityPtrLessThan> _chainRegions;
  std::set<GFace *, GEntityPtrLessThan> _chainFaces;
  std::set<GEdge *, GEntityPtrLessThan> _chainEdges;
  std::set<GVertex *, GEntityPtrLessThan> _chainVertices;
  hashmapMEdge _mapEdgeNum;
  hashmapMFace _mapFaceNum;
  // the maximum vertex and element id number in the mesh
  std::size_t _maxVertexNum, _maxElementNum;
  std::size_t _checkPointedMaxVertexNum, _checkPointedMaxElementNum;

private:
  int _readMSH2(const std::string &name);
  int _writeMSH2(const std::string &name, double version, bool binary,
                 bool saveAll, bool saveParametric, double scalingFactor,
                 int elementStartNum, int saveSinglePartition, bool append,
                 bool renumberVertices);
  int _writePartitionedMSH2(const std::string &baseName, bool binary,
                            bool saveAll, bool saveParametric,
                            double scalingFactor);
  int _readMSH3(const std::string &name);
  int _writeMSH3(const std::string &name, double version, bool binary,
                 bool saveAll, bool saveParametric, double scalingFactor,
                 int elementStartNum, int saveSinglePartition, bool append);
  int _writePartitionedMSH3(const std::string &baseName, double version,
                            bool binary, bool saveAll, bool saveParametric,
                            double scalingFactor);
  int _readMSH4(const std::string &name);
  int _writeMSH4(const std::string &name, double version, bool binary,
                 bool saveAll, bool saveParametric, double scalingFactor,
                 bool append, int partitionToSave = 0,
                 std::map<GEntity*, SBoundingBox3d> *entityBounds = nullptr);
  int _writePartitionedMSH4(const std::string &baseName, double version,
                            bool binary, bool saveAll, bool saveParametric,
                            double scalingFactor);
  int _writeX3dFile(FILE* fp, bool saveAll,
                    double scalingFactor, int x3dsurfaces, int x3dedges,
                    int x3dvertices, int x3dcolorize,
                    std::vector<GFace *> &customFaces);

protected:
  // the name of the model
  std::string _name;

  // the name of the file the model was read from
  std::string _fileName;
  std::set<std::string> _fileNames;

  // the visibility flag
  char _visible;

  // vertex and element caches to speed-up direct access by tag (mostly
  // used for post-processing I/O)
  std::vector<MVertex *> _vertexVectorCache;
  std::map<std::size_t, MVertex *> _vertexMapCache;
  std::vector<std::pair<MElement *, int> > _elementVectorCache;
  std::map<std::size_t, std::pair<MElement *, int> > _elementMapCache;
  std::map<int, int> _elementIndexCache;

  // ghost cell information (stores partitions for each element acting
  // as a ghost cell)
  // /!\ Use only for compatibility with mesh format msh2 and msh3
  std::multimap<MElement *, short> _ghostCells;

  // an octree for fast mesh element lookup
  MElementOctree *_elementOctree;

  // global cache storage of discrete curvatures
  std::map<MVertex *, std::pair<SVector3, SVector3> > _curvatures;

  // GEO (Gmsh native) model internal data
  GEO_Internals *_geo_internals;
  // OpenCASCADE model internal data
  OCC_Internals *_occ_internals;
  // ACIS model internal data
  ACIS_Internals *_acis_internals;
  // Parasolid model internal data
  Parasolid_Internals *_parasolid_internals;

  // characteristic length (mesh size) fields
  FieldManager *_fields;

  // entity that is currently being meshed (used for error reporting)
  GEntity *_currentMeshEntity;

  // last entities/vertices where a meshing error has been reported
  std::vector<GEntity *> _lastMeshEntityError;
  std::vector<MVertex *> _lastMeshVertexError;

  // index of the current model (in the static list of all loaded
  // models)
  static int _current;

  // the sets of geometrical regions, faces, edges and vertices in the
  // model
  std::set<GRegion *, GEntityPtrLessThan> regions;
  std::set<GFace *, GEntityPtrLessThan> faces;
  std::set<GEdge *, GEntityPtrLessThan> edges;
  std::set<GVertex *, GEntityPtrLessThan> vertices;

  // map between the pair <dimension, elementary or physical number>
  // and an optional associated name
  std::map<std::pair<int, int>, std::string> _physicalNames, _elementaryNames;

  // the set of all used mesh partition numbers
  std::size_t _numPartitions;

  // additional attributes (e.g. stored in extra sections of MSH files)
  std::map<std::string, std::vector<std::string> > _attributes;

protected:
  // store the elements given in the map (indexed by elementary region
  // number) into the model, creating discrete geometrical entities on
  // the fly if needed
  void _storeElementsInEntities(std::map<int, std::vector<MElement *> > &map);

  // store the parent's pointer back into MSubElements (replacing numeric id)
  void _storeParentsInSubElements(std::map<int, std::vector<MElement *> > &map);

  // loop over all vertices connected to elements and associate
  // geometrical entity
  void _associateEntityWithMeshVertices();

  // store the vertices in the geometrical entity they are associated
  // with, and delete those that are not associated with any entity
  void _storeVerticesInEntities(std::map<std::size_t, MVertex *> &vertices);
  void _storeVerticesInEntities(std::vector<MVertex *> &vertices);

  // store the physical tags in the geometrical entities
  void
  _storePhysicalTagsInEntities(int dim,
                               std::map<int, std::map<int, std::string> > &map);

public:
  // region, face, edge and vertex iterators
  typedef std::set<GRegion *, GEntityPtrLessThan>::iterator riter;
  typedef std::set<GFace *, GEntityPtrLessThan>::iterator fiter;
  typedef std::set<GEdge *, GEntityPtrLessThan>::iterator eiter;
  typedef std::set<GVertex *, GEntityPtrLessThan>::iterator viter;

  typedef std::set<GRegion *, GEntityPtrLessThan>::const_iterator const_riter;
  typedef std::set<GFace *, GEntityPtrLessThan>::const_iterator const_fiter;
  typedef std::set<GEdge *, GEntityPtrLessThan>::const_iterator const_eiter;
  typedef std::set<GVertex *, GEntityPtrLessThan>::const_iterator const_viter;

  // elementary/physical name iterator
  typedef std::map<std::pair<int, int>, std::string>::iterator piter;

public:
  GModel(const std::string &name = "");
  virtual ~GModel();
// Required for python bindings on Windows
#ifndef SWIG
  // the static list of all loaded models
  static std::vector<GModel *> list;
#endif

  // return the current model, and sets the current model index if
  // index >= 0
  static GModel *current(int index = -1);

  // sets a model to current
  static int setCurrent(GModel *m);
  int setAsCurrent() { return setCurrent(this); }

  // find a model by name; if fileName is given, return model only if it does
  // *not* have a link to the fileName
  static GModel *findByName(const std::string &name,
                            const std::string &fileName = "");

  // delete everything in a GModel (optionally keep name and fileName)
  void destroy(bool keepName = false);

  // get/set global vertex/element num
  std::size_t getMaxVertexNumber() const { return _maxVertexNum; }
  std::size_t getMaxElementNumber() const { return _maxElementNum; }
  void setMaxVertexNumber(std::size_t num)
  {
#pragma omp atomic write
    _maxVertexNum = _maxVertexNum > num ? _maxVertexNum : num;
  }
  void setMaxElementNumber(std::size_t num)
  {
#pragma omp atomic write
    _maxElementNum = _maxElementNum > num ? _maxElementNum : num;
  }

  // increment and get global vertex/element num
  std::size_t incrementAndGetMaxVertexNumber()
  {
    std::size_t _myVertexNum;
#pragma omp atomic capture
    {
      ++_maxVertexNum;
      _myVertexNum = _maxVertexNum;
    }
    return _myVertexNum;
  }
  std::size_t incrementAndGetMaxElementNumber()
  {
    std::size_t _myElementNum;
#pragma omp atomic capture
    {
      ++_maxElementNum;
      _myElementNum = _maxElementNum;
    }
    return _myElementNum;
  }

  // decrement global vertex num
  void decrementMaxVertexNumber()
  {
#pragma omp atomic update
    --_maxVertexNum;
  }

  void checkPointMaxNumbers()
  {
    _checkPointedMaxVertexNum = _maxVertexNum;
    _checkPointedMaxVertexNum = _maxVertexNum;
  }
  void getCheckPointedMaxNumbers(std::size_t &maxv, std::size_t &maxe) const
  {
    maxv = _checkPointedMaxVertexNum;
    maxe = _checkPointedMaxElementNum;
  }

  // add a mesh edge or face in the global edge or face map with number "num",
  // or number it (starting at 1) if num == 0
  std::size_t addMEdge(MEdge &&edge, std::size_t num = 0);
  std::size_t addMFace(MFace &&face, std::size_t num = 0);

  // get number of edges or faces
  std::size_t getNumMEdges() const { return _mapEdgeNum.size(); };
  std::size_t getNumMFaces() const { return _mapFaceNum.size(); };

  // get the edge of face and its global number given mesh nodes (return 0 if
  // the edge or face does not exist in the edge or face map)
  std::size_t getMEdge(MVertex *v0, MVertex *v1, MEdge &edge);
  std::size_t getMFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
                       MFace &face);
  // iterate on edges and faces
  hashmapMEdge::const_iterator firstMEdge() { return _mapEdgeNum.begin(); }
  hashmapMEdge::const_iterator lastMEdge() { return _mapEdgeNum.end(); }
  hashmapMFace::const_iterator firstMFace() { return _mapFaceNum.begin(); }
  hashmapMFace::const_iterator lastMFace() { return _mapFaceNum.end(); }

  // renumber mesh vertices and elements in a continuous sequence (this
  // invalidates the mesh caches)
  void renumberMeshVertices(const std::map<std::size_t, std::size_t> &mapping =
                            std::map<std::size_t, std::size_t>());
  void renumberMeshElements(const std::map<std::size_t, std::size_t> &mapping =
                            std::map<std::size_t, std::size_t>());

  // delete all the mesh-related caches (this must be called when the
  // mesh is changed)
  void destroyMeshCaches();
  // delete the mesh stored in entities and call destroMeshCaches
  void deleteMesh();
  void deleteMesh(const std::vector<GEntity *> &entities);
  // delete the vertex arrays used for efficient mesh drawing
  void deleteVertexArrays();
  // delete the vertex arrays used for efficient geometry drawing
  void deleteGeometryVertexArrays();

  // remove all mesh vertex associations to geometrical entities and remove
  // vertices from geometrical entities, then _associateEntityWithMeshVertices
  // and _storeVerticesInEntities are called to rebuild the associations
  void pruneMeshVertexAssociations();

  // access internal CAD representations
  void createGEOInternals();
  void createOCCInternals();
  void createACISInternals();
  void createParasolidInternals();
  OCC_Internals *getOCCInternals() { return _occ_internals; }
  GEO_Internals *getGEOInternals() { return _geo_internals; }
  ACIS_Internals *getACISInternals() { return _acis_internals; }
  Parasolid_Internals *getParasolidInternals() { return _parasolid_internals; }
  void deleteGEOInternals();
  void deleteOCCInternals();
  void resetOCCInternals();
  void deleteACISInternals();
  void deleteParasolidInternals();

  // access characteristic length (mesh size) fields
  FieldManager *getFields() { return _fields; }

  // get/set the model name
  void setName(const std::string &name) { _name = name; }
  std::string getName() const { return _name; }

  // get/set the model file name
  void setFileName(const std::string &fileName);
  std::string getFileName() const { return _fileName; }
  bool hasFileName(const std::string &name) const
  {
    return _fileNames.find(name) != _fileNames.end();
  }

  // get/set the visibility flag
  char getVisibility() const { return _visible; }
  void setVisibility(char val) { _visible = val; }

  // get the number of entities in this model
  std::size_t getNumRegions() const { return regions.size(); }
  std::size_t getNumFaces() const { return faces.size(); }
  std::size_t getNumEdges() const { return edges.size(); }
  std::size_t getNumVertices() const { return vertices.size(); }

  // quickly check if the model is empty (i.e., if it contains no
  // entities)
  bool empty() const;

  // get an iterator initialized to the first/last entity in this model
  riter firstRegion() { return regions.begin(); }
  fiter firstFace() { return faces.begin(); }
  eiter firstEdge() { return edges.begin(); }
  viter firstVertex() { return vertices.begin(); }
  riter lastRegion() { return regions.end(); }
  fiter lastFace() { return faces.end(); }
  eiter lastEdge() { return edges.end(); }
  viter lastVertex() { return vertices.end(); }
  const_riter firstRegion() const { return regions.begin(); }
  const_fiter firstFace() const { return faces.begin(); }
  const_eiter firstEdge() const { return edges.begin(); }
  const_viter firstVertex() const { return vertices.begin(); }
  const_riter lastRegion() const { return regions.end(); }
  const_fiter lastFace() const { return faces.end(); }
  const_eiter lastEdge() const { return edges.end(); }
  const_viter lastVertex() const { return vertices.end(); }

  // get the set of entities
  std::set<GRegion *, GEntityPtrLessThan> getRegions() const
  {
    return regions;
  };
  std::set<GFace *, GEntityPtrLessThan> getFaces() const { return faces; };
  std::set<GEdge *, GEntityPtrLessThan> getEdges() const { return edges; };
  std::set<GVertex *, GEntityPtrLessThan> getVertices() const
  {
    return vertices;
  };

  // find the entity with the given tag
  GRegion *getRegionByTag(int n) const;
  GFace *getFaceByTag(int n) const;
  GEdge *getEdgeByTag(int n) const;
  GVertex *getVertexByTag(int n) const;
  GEntity *getEntityByTag(int dim, int n) const;

  // change entity tag (modifies the model entity sets)
  bool changeEntityTag(int dim, int tag, int newTag);

  // add/remove an entity in the model
  bool add(GRegion *r) { return regions.insert(r).second; }
  bool add(GFace *f) { return faces.insert(f).second; }
  bool add(GEdge *e) { return edges.insert(e).second; }
  bool add(GVertex *v) { return vertices.insert(v).second; }
  bool remove(GRegion *r);
  bool remove(GFace *f);
  bool remove(GEdge *e);
  bool remove(GVertex *v);
  void remove(int dim, int tag, std::vector<GEntity*> &removed,
              bool recursive = false);
  void remove(const std::vector<std::pair<int, int> > &dimTags,
              std::vector<GEntity*> &removed,
              bool recursive = false);
  void remove();

  // snap vertices on model edges by using geometry tolerance
  void snapVertices();

  // fill a vector containing all the entities in the model
  void getEntities(std::vector<GEntity *> &entities, int dim = -1) const;

  // fill a vector containing all the entities in a given bounding box
  void getEntitiesInBox(std::vector<GEntity *> &entities,
                        const SBoundingBox3d &box, int dim = -1) const;

  // get tags of entities of the boundary of the given input entities
  bool getBoundaryTags(const std::vector<std::pair<int, int> > &inDimTags,
                       std::vector<std::pair<int, int> > &outDimTags,
                       bool combined, bool oriented = true,
                       bool recursive = false);

  // return the highest number associated with an elementary entity of
  // a given dimension (or the highest overall if dim < 0)
  int getMaxElementaryNumber(int dim);

  // check if there are no physical entities in the model
  bool noPhysicalGroups();

  // return all physical groups (one map per dimension: 0-D to 3-D)
  void
  getPhysicalGroups(std::map<int, std::vector<GEntity *> > groups[4]) const;
  void getPhysicalGroups(int dim,
                         std::map<int, std::vector<GEntity *> > &groups) const;
  void getEntitiesForPhysicalName(const std::string &name,
                                  std::vector<GEntity *> &entities) const;
  const std::map<std::pair<int, int>, std::string> &getPhysicalNames() const
  {
    return _physicalNames;
  }
  void setPhysicalNames(const std::map<std::pair<int, int>, std::string> &names)
  {
    _physicalNames = names;
  }

  // add a physical group (made of elementary entities "tags")
  void addPhysicalGroup(int dim, int tag, const std::vector<int> &tags);

  // remove physical groups
  void removePhysicalGroups();
  void removePhysicalGroup(int dim, int num);

  // return the highest number associated with a physical entity of a
  // given dimension (or highest for all dimenions if dim < 0)
  int getMaxPhysicalNumber(int dim);

  // get an iterator on the elementary/physical names
  piter firstPhysicalName() { return _physicalNames.begin(); }
  piter lastPhysicalName() { return _physicalNames.end(); }
  piter firstElementaryName() { return _elementaryNames.begin(); }
  piter lastElementaryName() { return _elementaryNames.end(); }

  // get the number of physical names
  int numPhysicalNames() const { return (int)_physicalNames.size(); }

  // get iterators to the last physical name of each dimension
  void getInnerPhysicalNamesIterators(std::vector<piter> &iterators);

  // associate a name with a physical entity of dimension "dim" and
  // number "num" (returns a new number id if "num"==0)
  int setPhysicalName(const std::string &name, int dim, int num = 0);
  piter setPhysicalName(piter pos, const std::string &name, int dim,
                        int num = 0);

  // get the name (if any) of a given physical group of dimension
  // "dim" and id number "num"
  std::string getPhysicalName(int dim, int num) const;

  // remove physical name(s)
  void removePhysicalName(const std::string &name);

  // get the number of a given physical group of dimension
  // "dim" and name "name". return -1 if not found
  int getPhysicalNumber(const int &dim, const std::string &name);

  // get all tags of elementary entities associated with a given physical group
  // name
  std::vector<int> getTagsForPhysicalName(int dim, const std::string &name);

  // set physical tags to entities in a given bounding box
  void setPhysicalNumToEntitiesInBox(int EntityDimension, int PhysicalNumber,
                                     std::vector<double> p1,
                                     std::vector<double> p2);
  void setPhysicalNumToEntitiesInBox(int EntityDimension, int PhysicalNumber,
                                     const SBoundingBox3d &box);

  // get the name (if any) of a given elementary entity of dimension
  // "dim" and id number "num"
  std::string getElementaryName(int dim, int tag);
  void setElementaryName(int dim, int tag, const std::string &name)
  {
    _elementaryNames[std::make_pair(dim, tag)] = name;
  }

  // remove elememtary name(s)
  void removeElementaryName(const std::string &name);

  // get the highest dimension of the GModel
  int getDim() const;

  // get the highest dimension of the mesh in the GModel
  int getMeshDim() const;

  // set the selection flag on all entities
  void setSelection(int val);

  // the bounding box
  SBoundingBox3d bounds(bool aroundVisible = false);

  // return the mesh status for the entire model
  int getMeshStatus(bool countDiscrete = true);

  // return the total number of elements in the mesh
  std::size_t getNumMeshElements(int dim = -1) const;
  std::size_t getNumMeshParentElements() const;

  // get the number of each type of element in the mesh at the largest
  // dimension and return the dimension
  std::size_t getNumMeshElements(unsigned c[6]);

  // access a mesh element by coordinates (using an octree search)
  MElement *getMeshElementByCoord(SPoint3 &p, SPoint3 &param, int dim = -1,
                                  bool strict = true);
  std::vector<MElement *> getMeshElementsByCoord(SPoint3 &p, int dim = -1,
                                                 bool strict = true);

  // access a mesh element by tag, using the element cache
  MElement *getMeshElementByTag(std::size_t n)
  {
    int entityTag;
    return getMeshElementByTag(n, entityTag);
  }
  MElement *getMeshElementByTag(std::size_t n, int &entityTag);

  // access temporary mesh element index
  int getMeshElementIndex(MElement *e);
  void setMeshElementIndex(MElement *e, int index);

  // return the total number of vertices in the mesh
  std::size_t getNumMeshVertices(int dim = -1) const;

  // recompute _vertexVectorCache if there is a dense vertex numbering or
  // _vertexMapCache if not.
  void rebuildMeshVertexCache(bool onlyIfNecessary = false);

  // recompute _elementVectorCache if there is a dense element numbering or
  // _elementMapCache if not.
  void rebuildMeshElementCache(bool onlyIfNecessary = false);

  // access a mesh vertex by tag, using the vertex cache
  MVertex *getMeshVertexByTag(std::size_t n);

  // add a mesh vertex to the global mesh vertex cache
  void addMVertexToVertexCache(MVertex* v);

  // get all the mesh vertices associated with the physical group
  // of dimension "dim" and id number "num"
  void getMeshVerticesForPhysicalGroup(int dim, int num,
                                       std::vector<MVertex *> &);

  // index all the (used) mesh vertices in a continuous sequence,
  // starting at 1
  std::size_t indexMeshVertices(bool all, int singlePartition = 0,
                                bool renumber = true);

  // scale the mesh by the given factor
  void scaleMesh(double factor);

  // set/get entity that is currently being meshed (for error reporting)
  void setCurrentMeshEntity(GEntity *e);
  GEntity *getCurrentMeshEntity() { return _currentMeshEntity; }

  // set/get entities/vertices linked meshing errors
  void clearLastMeshEntityError() { _lastMeshEntityError.clear(); }
  void addLastMeshEntityError(GEntity *e) { _lastMeshEntityError.push_back(e); }
  std::vector<GEntity *> getLastMeshEntityError()
  {
    return _lastMeshEntityError;
  }
  void clearLastMeshVertexError() { _lastMeshVertexError.clear(); }
  void addLastMeshVertexError(MVertex *v) { _lastMeshVertexError.push_back(v); }
  std::vector<MVertex *> getLastMeshVertexError()
  {
    return _lastMeshVertexError;
  }

  // delete or reverse all invisble mesh elements
  std::size_t removeInvisibleElements();
  std::size_t reverseInvisibleElements();

  // the list of partitions
  std::size_t getNumPartitions() const { return _numPartitions; }
  void setNumPartitions(std::size_t npart) { _numPartitions = npart; }

  // partition the mesh
  int partitionMesh(int num,
                    std::vector<std::pair<MElement *, int> > elementPartition =
                      std::vector<std::pair<MElement *, int> >());
  // unpartition the mesh
  int unpartitionMesh();
  // import a mesh partitionned by a tag given by element (i.e. the old way we
  // stored partitions) and create the new topology-based partition entitiesx
  int convertOldPartitioningToNewOne();
  // write the partitioned topology file
  int writePartitionedTopology(std::string &name);

  // /!\ Use only for compatibility with mesh format msh2 and msh3
  std::multimap<MElement *, short> &getGhostCells() { return _ghostCells; }
  void addGhostCells(MElement *elm, short partition)
  {
    _ghostCells.insert(std::make_pair(elm, partition));
  }

  // perform various coherence tests on the mesh
  void checkMeshCoherence(double tolerance);

  // remove duplicate mesh vertices
  int removeDuplicateMeshVertices(double tolerance,
                                  const std::vector<GEntity*> &entities =
                                  std::vector<GEntity*>());

  // remove duplicate mesh elements (within an entity)
  int removeDuplicateMeshElements(const std::vector<GEntity*> &entities =
                                  std::vector<GEntity*>());

  // create a geometry (i.e. a parametrization for curves and surfaces) for the
  // given discrete entities (or all of them if dimTags is empty)
  void createGeometryOfDiscreteEntities(
    const std::vector<std::pair<int, int> > &dimTags =
      std::vector<std::pair<int, int> >());

  // make discrete entities simply connected
  void makeDiscreteRegionsSimplyConnected();
  void makeDiscreteFacesSimplyConnected();

  // create topology from mesh
  void createTopologyFromMesh();

  // align periodic boundaries
  void alignPeriodicBoundaries();

  // a container for smooth normals
  smooth_normals *normals;

  // mesh the model
  int mesh(int dimension);

  // adapt 3d mesh
  int adaptMesh();

  // adapt the mesh anisotropically using metrics that are computed from a set
  // of functions f(x,y,z). The algorithm first generate a mesh if no one is
  // available; see the cpp for parameter documentation
  int adaptMesh(std::vector<int> technique,
                std::vector<simpleFunction<double> *> f,
                std::vector<std::vector<double> > parameters, int niter,
                bool meshAll = false);

  // ensure that the Jacobian of all volume elements is positive
  bool setAllVolumesPositive();
  void setAllVolumesPositiveTopology();

  // make the mesh a high order mesh at order N (linear is 1 if the high order
  // points are not placed on the geometry of the model; incomplete is 1 if
  // incomplete basis are used)
  int setOrderN(int order, int linear, int incomplete, int onlyVisible);

  // refine the mesh by splitting all elements
  int refineMesh(int linear, bool splitIntoQuads = false,
                 bool splitIntoHexas = false, bool barycentric = false);

  // optimize the mesh
  int optimizeMesh(const std::string &how, bool force = false, int niter = 1);

  // recombine the mesh
  int recombineMesh();

  // fill the vertex arrays, given the current option and data
  bool fillVertexArrays();

  // reclassify a surface mesh, using an angle threshold to tag edges and faces
  void classifySurfaces(double angleThreshold, bool includeBoundary,
                        bool forReparametrization, double curveAngleThreshold);

  // build a new GModel by cutting the elements crossed by the levelset ls
  // if cutElem is set to false, split the model without cutting the elements
  GModel *buildCutGModel(gLevelset *ls, bool cutElem = true,
                         bool saveTri = false);

  // store mesh elements of a chain in a new elementary and physical entity
  void storeChain(int dim, std::map<int, std::vector<MElement *> > &entityMap,
                  std::map<int, std::map<int, std::string> > &physicalMap);

  // request homology computation
  void addHomologyRequest(const std::string &type,
                          const std::vector<int> &domain,
                          const std::vector<int> &subdomain,
                          const std::vector<int> &dim);
  void clearHomologyRequests();
  void computeHomology(std::vector<std::pair<int, int> > &newPhysicals);

  // mesh size callback
  std::function<double(int, int, double, double, double, double)> lcCallback;

  // compute automatic sizing field from curvature
  void computeSizeField();

  // access global cache of discrete curvatures
  std::map<MVertex *, std::pair<SVector3, SVector3> > &getCurvatures()
  {
    return _curvatures;
  }

  // reverse engineering of extruded shapes
  bool addAutomaticExtrusionConstraints(const std::vector<int> &numElements,
                                        const std::vector<double> &heights,
                                        const bool recombine,
                                        const std::vector<int> &regionTag);

  // get additional attributes
  std::map<std::string, std::vector<std::string> > &getAttributes()
  {
    return _attributes;
  }

  // "automatic" IO based on Gmsh global functions
  void load(const std::string &fileName);
  void save(const std::string &fileName);

  // GEO file interface (readGEO is static, since it can create multiple models)
  static int readGEO(const std::string &name);
  int writeGEO(const std::string &name, bool printLabels = true,
               bool onlyPhysicals = false);
  int exportDiscreteGEOInternals();

  // PY export (mostly a placeholder for now)
  int writePY(const std::string &name, bool printLabels = true,
              bool onlyPhysicals = false);

  // OCC model
  int readOCCBREP(const std::string &name);
  int readOCCXAO(const std::string &name);
  int readOCCSTEP(const std::string &name);
  int readOCCIGES(const std::string &name);
  int writeOCCBREP(const std::string &name);
  int writeOCCXAO(const std::string &name);
  int writeOCCSTEP(const std::string &name);
  int writeOCCIGES(const std::string &name);
  int importOCCShape(const void *shape);
  GVertex *getVertexForOCCShape(const void *shape);
  GEdge *getEdgeForOCCShape(const void *shape);
  GFace *getFaceForOCCShape(const void *shape);
  GRegion *getRegionForOCCShape(const void *shape);

  // ACIS Model
  int readACISSAT(const std::string &name);

  // Parasolid Model
  int readParasolidXMT(const std::string &name);
  int writeParasolidXMT(const std::string &name);
  int readParasolidSTEP(const std::string &name);
  int writeParasolidSTEP(const std::string &name);

  // Gmsh mesh file format
  int readMSH(const std::string &name);
  int writeMSH(const std::string &name, double version = 2.2,
               bool binary = false, bool saveAll = false,
               bool saveParametric = false, double scalingFactor = 1.0,
               int elementStartNum = 0, int saveSinglePartition = 0,
               bool append = false);
  int writePartitionedMSH(const std::string &baseName, double version = 2.2,
                          bool binary = false, bool saveAll = false,
                          bool saveParametric = false,
                          double scalingFactor = 1.0);

  // Iridium file format
  int writeIR3(const std::string &name, int elementTagType, bool saveAll,
               double scalingFactor);

  // mesh statistics (saved as a Gmsh post-processing view)
  int writePOS(const std::string &name, bool printElementary,
               bool printElementNumber, bool printSICN, bool printSIGE,
               bool printGamma, bool printDisto, bool saveAll = false,
               double scalingFactor = 1.0);

  // Stereo lithography format
  int readSTL(const std::string &name, double tolerance = 1.e-3);
  int writeSTL(const std::string &name, bool binary = false,
               bool saveAll = false, double scalingFactor = 1.0,
               int oneSolidPerSurface = 0);


  // NII format is created by Neuroimaging Informatics Technology Initiative. It is commonly used to store magnetic resonance imaging (MRI) data.
  int readNII(const std::string &name, float isolevel = 0.0, int isoDarkMediumBright123 = 2,
	      float reduceFraction = 0.25, int preSmooth = 1, bool onlyLargest = true,
	      bool fillBubbles = false, int postSmooth = 1);

  // X3D (only output from OCCT's triangulation)
  int writeX3D(const std::string &name, bool saveAll = false,
               double scalingFactor = 1.0, int x3dsurfaces = 1,
               int x3dedges = 0, int x3dvertices = 0, int x3dvolumes = 0,
               int x3dcolorize = 0);

  // PLY(2) format (ascii text format)
  int readPLY(const std::string &name);
  int readPLY2(const std::string &name);
  int writePLY2(const std::string &name);

  // Inventor/VRML format
  int readVRML(const std::string &name);
  int writeVRML(const std::string &name, bool saveAll = false,
                double scalingFactor = 1.0);

  // I-deas universal mesh format
  int readUNV(const std::string &name, bool readGroupsOfElements = true);
  int writeUNV(const std::string &name, bool saveAll = false,
               int saveGroupsOfElements = 0, int saveGroupsOfNodes = 0,
               double scalingFactor = 1.0);

  // Medit (INRIA) mesh format
  int readMESH(const std::string &name);
  int writeMESH(const std::string &name, int elementTagType = 1,
                bool saveAll = false, double scalingFactor = 1.0);

  // Object file format (OFF)
  int readOFF(const std::string &name);
  int writeOFF(const std::string &name, bool saveAll = false,
               double scalingFactor = 1.0);

  // Nastran Bulk Data File format
  int readBDF(const std::string &name);
  int writeBDF(const std::string &name, int format = 0, int elementTagType = 1,
               bool saveAll = false, double scalingFactor = 1.0);

  // Actran mesh
  int readACTRAN(const std::string &name);

  // Sameced mesh
  int readSAMCEF(const std::string &name);

  // Plot3D structured mesh format
  int readP3D(const std::string &name);
  int writeP3D(const std::string &name, bool saveAll = false,
               double scalingFactor = 1.0);

  // CFD General Notation System files
  int readCGNS(const std::string &name,
               std::vector<std::vector<MVertex *> > &vertPerZone,
               std::vector<std::vector<MElement *> > &eltPerZone);
  int writeCGNS(const std::string &name, bool saveAll = false,
                double scalingFactor = 1.0, bool structured = false);

  // Med "Modele d'Echange de Donnees" file format (the static routine
  // is allowed to load multiple models/meshes)
  static int readMED(const std::string &name);
  int readMED(const std::string &name, int meshIndex);
  int writeMED(const std::string &name, bool saveAll = false,
               double scalingFactor = 1.0);

  // VTK format
  int readVTK(const std::string &name, bool bigEndian = false);
  int writeVTK(const std::string &name, bool binary = false,
               bool saveAll = false, double scalingFactor = 1.0,
               bool bigEndian = false);

  // Matlab format
  int writeMATLAB(const std::string &name, bool binary = false,
                  bool saveAll = false, double scalingFactor = 1.0,
                  int filetype = 1);

  // Tochnog format
  int writeTOCHNOG(const std::string &name, bool saveAll = false,
                   int saveGroupsOfNodes = 0, double scalingFactor = 1.0);

  // DIFFPACK format
  int readDIFF(const std::string &name);
  int writeDIFF(const std::string &name, bool binary = false,
                bool saveAll = false, double scalingFactor = 1.0);

  // Abaqus
  int writeINP(const std::string &name, bool saveAll = false,
               int saveGroupsOfElements = 0, int saveGroupsOfNodes = 0,
               double scalingFactor = 1.0);

  // LSDYNA
  int writeKEY(const std::string &name, int saveAll = 0,
               int saveGroupsOfNodes = 0, double scalingFactor = 1.0);

  // RADIOSS
  int writeRAD(const std::string &name, int saveAll = 0,
               int saveGroupsOfNodes = 0, double scalingFactor = 1.0);

  // CELUM
  int writeCELUM(const std::string &name, bool saveAll = false,
                 double scalingFactor = 1.0);

  // Geomview mesh
  int readGEOM(const std::string &name);

  // CEA triangulation
  int writeMAIL(const std::string &name, bool saveAll, double scalingFactor);

  // SU2 mesh file
  int writeSU2(const std::string &name, bool saveAll, double scalingFactor);

  // GAMBIT neutral mesh file (.neu)
  int readNEU(const std::string &name);
  int writeNEU(const std::string &name, bool saveAll, double scalingFactor);
};

#endif
