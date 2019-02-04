// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _GMODEL_H_
#define _GMODEL_H_

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "SPoint3.h"
#include "SBoundingBox3d.h"

template <class scalar> class simpleFunction;

class GEO_Internals;
class OCC_Internals;
class ACIS_Internals;
class smooth_normals;
class FieldManager;
class CGNSOptions;
class gLevelset;
class discreteFace;
class discreteRegion;
class MElementOctree;

// A geometric model. The model is a "not yet" non-manifold B-Rep.
class GModel {
private:
  std::multimap<std::pair<const std::vector<int>, const std::vector<int> >,
                std::pair<const std::string, const std::vector<int> > >
    _homologyRequests;
  std::set<GRegion *, GEntityLessThan> _chainRegions;
  std::set<GFace *, GEntityLessThan> _chainFaces;
  std::set<GEdge *, GEntityLessThan> _chainEdges;
  std::set<GVertex *, GEntityLessThan> _chainVertices;

  // the maximum vertex and element id number in the mesh
  int _maxVertexNum, _maxElementNum;
  int _checkPointedMaxVertexNum, _checkPointedMaxElementNum;
  // flag set to true when the model is being destroyed
  bool _destroying;

private:
  int _readMSH2(const std::string &name);
  int _writeMSH2(const std::string &name, double version, bool binary,
                 bool saveAll, bool saveParametric, double scalingFactor,
                 int elementStartNum, int saveSinglePartition,
                 bool append, bool renumberVertices);
  int _writePartitionedMSH2(const std::string &baseName, bool binary,
                            bool saveAll, bool saveParametric,
                            double scalingFactor);
  int _readMSH3(const std::string &name);
  int _writeMSH3(const std::string &name, double version, bool binary,
                 bool saveAll, bool saveParametric, double scalingFactor,
                 int elementStartNum, int saveSinglePartition,
                 bool append);
  int _writePartitionedMSH3(const std::string &baseName, double version,
                            bool binary, bool saveAll, bool saveParametric,
                            double scalingFactor);
  int _readMSH4(const std::string &name);
  int _writeMSH4(const std::string &name, double version, bool binary,
                 bool saveAll, bool saveParametric, double scalingFactor,
                 bool append);
  int _writePartitionedMSH4(const std::string &baseName, double version,
                            bool binary, bool saveAll, bool saveParametric,
                            double scalingFactor);

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
  std::map<int, MVertex *> _vertexMapCache;
  std::vector<MElement *> _elementVectorCache;
  std::map<int, MElement *> _elementMapCache;
  std::map<int, int> _elementIndexCache;

  // ghost cell information (stores partitions for each element acting
  // as a ghost cell)
  // /!\ Use only for compatibility with mesh format msh2 and msh3
  std::multimap<MElement *, short> _ghostCells;

  // an octree for fast mesh element lookup
  MElementOctree *_elementOctree;

  // Geo (Gmsh native) model internal data
  GEO_Internals *_geo_internals;
  // OpenCascade model internal data
  OCC_Internals *_occ_internals;
  // ACIS model internal data
  ACIS_Internals *_acis_internals;

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
  std::set<GRegion *, GEntityLessThan> regions;
  std::set<GFace *, GEntityLessThan> faces;
  std::set<GEdge *, GEntityLessThan> edges;
  std::set<GVertex *, GEntityLessThan> vertices;

  // map between the pair <dimension, elementary or physical number>
  // and an optional associated name
  std::map<std::pair<int, int>, std::string> physicalNames, elementaryNames;

  // the set of all used mesh partition numbers
  unsigned int _numPartitions;

protected:
  void _createGEOInternals();
  void _deleteGEOInternals();

  void _deleteOCCInternals();
  void _resetOCCInternals();

  void _deleteACISInternals();

  // CGNS helpers
  int _readCGNSStructured(const std::string &name);
  int _readCGNSUnstructured(const std::string &name);

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
  void _storeVerticesInEntities(std::map<int, MVertex *> &vertices);
  void _storeVerticesInEntities(std::vector<MVertex *> &vertices);

  // store the physical tags in the geometrical entities
  void
  _storePhysicalTagsInEntities(int dim,
                               std::map<int, std::map<int, std::string> > &map);

public:
  // region, face, edge and vertex iterators
  typedef std::set<GRegion *, GEntityLessThan>::iterator riter;
  typedef std::set<GFace *, GEntityLessThan>::iterator fiter;
  typedef std::set<GEdge *, GEntityLessThan>::iterator eiter;
  typedef std::set<GVertex *, GEntityLessThan>::iterator viter;

  typedef std::set<GRegion *, GEntityLessThan>::const_iterator const_riter;
  typedef std::set<GFace *, GEntityLessThan>::const_iterator const_fiter;
  typedef std::set<GEdge *, GEntityLessThan>::const_iterator const_eiter;
  typedef std::set<GVertex *, GEntityLessThan>::const_iterator const_viter;

  // elementary/physical name iterator
  typedef std::map<std::pair<int, int>, std::string>::iterator piter;

  typedef std::set<GVertex *, GEntityLessThan>::size_type size_type;

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
  bool isBeingDestroyed() const { return _destroying; }

  // get/set global vertex/element num
  int getMaxVertexNumber() { return _maxVertexNum; }
  int getMaxElementNumber() { return _maxElementNum; }
  void setMaxVertexNumber(int num) { _maxVertexNum = num; }
  void setMaxElementNumber(int num) { _maxElementNum = num; }
  void checkPointMaxNumbers()
  {
    _checkPointedMaxVertexNum = _maxVertexNum;
    _checkPointedMaxVertexNum = _maxVertexNum;
  }
  void getCheckPointedMaxNumbers(int &maxv, int &maxe)
  {
    maxv = _checkPointedMaxVertexNum;
    maxe = _checkPointedMaxElementNum;
  }

  // renumber mesh vertices and elements in a continuous sequence (this
  // invalidates the mesh caches)
  void renumberMeshVertices();
  void renumberMeshElements();

  // delete all the mesh-related caches (this must be called when the
  // mesh is changed)
  void destroyMeshCaches();
  // delete the mesh stored in entities and call destroMeshCaches
  void deleteMesh(bool onlyDeleteElements = false);

  // remove all mesh vertex associations to geometrical entities and remove
  // vertices from geometrical entities, then _associateEntityWithMeshVertices
  // and _storeVerticesInEntities are called to rebuild the associations
  void pruneMeshVertexAssociations();

  // access internal CAD representations
  GEO_Internals *getGEOInternals() { return _geo_internals; }
  void createOCCInternals();
  OCC_Internals *getOCCInternals() { return _occ_internals; }
  ACIS_Internals *getACISInternals() { return _acis_internals; }

  // access characteristic length (mesh size) fields
  FieldManager *getFields() { return _fields; }

  // get/set the model name
  void setName(const std::string &name) { _name = name; }
  std::string getName() { return _name; }

  // get/set the model file name
  void setFileName(const std::string &fileName);
  std::string getFileName() { return _fileName; }
  bool hasFileName(const std::string &name)
  {
    return _fileNames.find(name) != _fileNames.end();
  }

  // get/set the visibility flag
  char getVisibility() { return _visible; }
  void setVisibility(char val) { _visible = val; }

  // get the number of entities in this model
  int getNumRegions() const { return regions.size(); }
  int getNumFaces() const { return faces.size(); }
  int getNumEdges() const { return edges.size(); }
  size_type getNumVertices() const { return vertices.size(); }

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
  std::set<GRegion *, GEntityLessThan> getRegions() const { return regions; };
  std::set<GFace *, GEntityLessThan> getFaces() const { return faces; };
  std::set<GEdge *, GEntityLessThan> getEdges() const { return edges; };
  std::set<GVertex *, GEntityLessThan> getVertices() const { return vertices; };

  // find the entity with the given tag
  GRegion *getRegionByTag(int n) const;
  GFace *getFaceByTag(int n) const;
  GEdge *getEdgeByTag(int n) const;
  GVertex *getVertexByTag(int n) const;
  GEntity *getEntityByTag(int dim, int n) const;

  // add/remove an entity in the model
  void add(GRegion *r) { regions.insert(r); }
  void add(GFace *f) { faces.insert(f); }
  void add(GEdge *e) { edges.insert(e); }
  void add(GVertex *v) { vertices.insert(v); }
  void remove(GRegion *r);
  void remove(GFace *f);
  void remove(GEdge *e);
  void remove(GVertex *v);
  void remove(int dim, int tag, bool recursive = false);
  void remove(const std::vector<std::pair<int, int> > &dimTags,
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
  const std::map<std::pair<int, int>, std::string> &getPhysicalNames() const
  {
    return physicalNames;
  }
  void setPhysicalNames(const std::map<std::pair<int, int>, std::string> &names)
  {
    physicalNames = names;
  }

  // remove physical groups in the model
  void removePhysicalGroups();
  void removePhysicalGroup(int dim, int num);

  // return the highest number associated with a physical entity of a
  // given dimension (or highest for all dimenions if dim < 0)
  int getMaxPhysicalNumber(int dim);

  // get an iterator on the elementary/physical names
  piter firstPhysicalName() { return physicalNames.begin(); }
  piter lastPhysicalName() { return physicalNames.end(); }
  piter firstElementaryName() { return elementaryNames.begin(); }
  piter lastElementaryName() { return elementaryNames.end(); }

  // get the number of physical names
  int numPhysicalNames() { return physicalNames.size(); }

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
  // deprecated
  std::vector<int> getEdgesByStringTag(const std::string &name)
  {
    return getTagsForPhysicalName(1, name);
  }

  // set physical tags to entities in a given bounding box
  void setPhysicalNumToEntitiesInBox(int EntityDimension, int PhysicalNumber,
                                     std::vector<double> p1,
                                     std::vector<double> p2);
  void setPhysicalNumToEntitiesInBox(int EntityDimension, int PhysicalNumber,
                                     SBoundingBox3d box);

  // get the name (if any) of a given elementary entity of dimension
  // "dim" and id number "num"
  std::string getElementaryName(int dim, int num);

  // get the highest dimension of the GModel
  int getDim() const;

  // set the selection flag on all entities
  void setSelection(int val);

  // the bounding box
  SBoundingBox3d bounds(bool aroundVisible = false);

  // return the mesh status for the entire model
  int getMeshStatus(bool countDiscrete = true);

  // return the total number of elements in the mesh
  int getNumMeshElements(int dim = -1);
  int getNumMeshParentElements();

  // get the number of each type of element in the mesh at the largest
  // dimension and return the dimension
  int getNumMeshElements(unsigned c[6]);

  // access a mesh element by coordinates (using an octree search)
  MElement *getMeshElementByCoord(SPoint3 &p, int dim = -1, bool strict = true);
  std::vector<MElement *> getMeshElementsByCoord(SPoint3 &p, int dim = -1,
                                                 bool strict = true);

  // access a mesh element by tag, using the element cache
  MElement *getMeshElementByTag(int n);

  // access temporary mesh element index
  int getMeshElementIndex(MElement *e);
  void setMeshElementIndex(MElement *e, int index);

  // return the total number of vertices in the mesh
  int getNumMeshVertices(int dim = -1) const;

  // recompute _vertexVectorCache if there is a dense vertex numbering or
  // _vertexMapCache if not.
  void rebuildMeshVertexCache(bool onlyIfNecessary = false);

  // access a mesh vertex by tag, using the vertex cache
  MVertex *getMeshVertexByTag(int n);

  // get all the mesh vertices associated with the physical group
  // of dimension "dim" and id number "num"
  void getMeshVerticesForPhysicalGroup(int dim, int num,
                                       std::vector<MVertex *> &);

  // index all the (used) mesh vertices in a continuous sequence,
  // starting at 1
  int indexMeshVertices(bool all, int singlePartition = 0,
                        bool renumber = true);

  // scale the mesh by the given factor
  void scaleMesh(double factor);

  // set/get entity that is currently being meshed (for error reporting)
  void setCurrentMeshEntity(GEntity *e) { _currentMeshEntity = e; }
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

  // delete all invisble mesh elements
  void removeInvisibleElements();

  // the list of partitions
  unsigned int getNumPartitions() const { return _numPartitions; }
  void setNumPartitions(unsigned int npart) { _numPartitions = npart; }

  // partition the mesh
  int partitionMesh(int num);
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
    _ghostCells.insert(std::pair<MElement *, short>(elm, partition));
  }

  // perform various coherence tests on the mesh
  void checkMeshCoherence(double tolerance);

  // remove duplicate mesh vertices
  int removeDuplicateMeshVertices(double tolerance);

  // create a topology from the mesh if necessary, move the mesh of discrete
  // entities to a geometry container, compute a parametrization for the
  // discrete entities
  void createGeometryOfDiscreteEntities();

  // create topology from mesh
  void createTopologyFromMeshNew();
  void createTopologyFromMesh();
  void makeDiscreteRegionsSimplyConnected();
  void makeDiscreteFacesSimplyConnected();

  // align periodic boundaries
  void alignPeriodicBoundaries();

  // a container for smooth normals
  smooth_normals *normals;

  // mesh the model
  int mesh(int dimension);

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
  int setOrderN(int order, int linear, int incomplete);

  // refine the mesh by splitting all elements
  int refineMesh(int linear);

  // optimize the mesh
  int optimizeMesh(const std::string &how);

  // fill the vertex arrays, given the current option and data
  bool fillVertexArrays();

  // reclassify a mesh i.e. use an angle threshold to tag edges faces and
  // regions
  void classifyFaces(std::set<GFace *> &_faces);

  // classify a mesh for all faces on the current model
  void classifyAllFaces();

  // build a new GModel by cutting the elements crossed by the levelset ls
  // if cutElem is set to false, split the model without cutting the elements
  GModel *buildCutGModel(gLevelset *ls, bool cutElem = true,
                         bool saveTri = false);

  // create a GModel by importing a mesh (vertexMap has a dim equal to the
  // number of vertices and all the other vectors have a dim equal to the number
  // of elements)
  static GModel *createGModel(std::map<int, MVertex *> &vertexMap,
                              std::vector<int> &numElement,
                              std::vector<std::vector<int> > &vertexIndices,
                              std::vector<int> &elementType,
                              std::vector<int> &physical,
                              std::vector<int> &elementary,
                              std::vector<int> &partition);

  // create a GModel from newly created mesh elements (with their own newly
  // created mesh vertices), and let element entities have given physical group
  // tags
  static GModel *
  createGModel(std::map<int, std::vector<MElement *> > &entityToElementsMap,
               std::map<int, std::vector<int> > &entityToPhysicalsMap);

  // for elements cut having new vertices
  void store(std::vector<MVertex *> &vertices, int dim,
             std::map<int, std::vector<MElement *> > &entityMap,
             std::map<int, std::map<int, std::string> > &physicalMap);

  // store mesh elements of a chain in a new elementary and physical entity
  void storeChain(int dim, std::map<int, std::vector<MElement *> > &entityMap,
                  std::map<int, std::map<int, std::string> > &physicalMap);

  // request homology computation
  void addHomologyRequest(const std::string &type,
                          const std::vector<int> &domain,
                          const std::vector<int> &subdomain,
                          const std::vector<int> &dim);
  void computeHomology();

  // "automatic" IO based on Gmsh global functions
  void load(const std::string &fileName);
  void save(const std::string &fileName);

  // Gmsh native CAD format (readGEO is static, since it can create
  // multiple models)
  static int readGEO(const std::string &name);
  int writeGEO(const std::string &name, bool printLabels = true,
               bool onlyPhysicals = false);
  int exportDiscreteGEOInternals();

  // OCC model
  int readOCCBREP(const std::string &name);
  int readOCCSTEP(const std::string &name);
  int readOCCIGES(const std::string &name);
  int writeOCCSTEP(const std::string &name);
  int writeOCCBREP(const std::string &name);
  int importOCCShape(const void *shape);
  GVertex *getVertexForOCCShape(const void *shape);
  GEdge *getEdgeForOCCShape(const void *shape);
  GFace *getFaceForOCCShape(const void *shape);
  GRegion *getRegionForOCCShape(const void *shape);

  // ACIS Model
  int readACISSAT(const std::string &name);

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
               bool saveAll = false, double scalingFactor = 1.0);

  // PLY(2) format (ascii text format)
  int readPLY(const std::string &name);
  int readPLY2(const std::string &name);
  int writePLY2(const std::string &name);

  // Inventor/VRML format
  int readVRML(const std::string &name);
  int writeVRML(const std::string &name, bool saveAll = false,
                double scalingFactor = 1.0);

  // I-deas universal mesh format
  int readUNV(const std::string &name);
  int writeUNV(const std::string &name, bool saveAll = false,
               bool saveGroupsOfNodes = false, double scalingFactor = 1.0);

  // Medit (INRIA) mesh format
  int readMESH(const std::string &name);
  int writeMESH(const std::string &name, int elementTagType = 1,
                bool saveAll = false, double scalingFactor = 1.0);

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
  int readCGNS(const std::string &name);
  int writeCGNS(const std::string &name, int zoneDefinition,
                const CGNSOptions &options, double scalingFactor = 1.0);

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
  int writeTOCHNOG(const std::string &name, bool saveGroupsOfNodes = false,
                   bool saveAll = false, double scalingFactor = 1.0);

  // DIFFPACK format
  int readDIFF(const std::string &name);
  int writeDIFF(const std::string &name, bool binary = false,
                bool saveAll = false, double scalingFactor = 1.0);

  // Abaqus
  int writeINP(const std::string &name, bool saveAll = false,
               bool saveGroupsOfNodes = false, double scalingFactor = 1.0);

  // LSDYNA
  int writeKEY(const std::string &name, int saveAll = 0,
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
  int writeNEU(const std::string &name, bool saveAll, double scalingFactor);
};

#endif
