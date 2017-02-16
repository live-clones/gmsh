// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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

class FM_Internals;
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
class GModelFactory;

// A geometric model. The model is a "not yet" non-manifold B-Rep.
class GModel
{
 private:
  friend class OCCFactory;
  std::multimap<std::pair<std::vector<int>, std::vector<int> >,
                std::pair<std::string, std::vector<int> > > _homologyRequests;
  std::set<GRegion*, GEntityLessThan> _chainRegions;
  std::set<GFace*, GEntityLessThan> _chainFaces;
  std::set<GEdge*, GEntityLessThan> _chainEdges;
  std::set<GVertex*, GEntityLessThan> _chainVertices;

  int _readMSH2(const std::string &name);
  int _writeMSH2(const std::string &name, double version=2.2, bool binary=false,
                 bool saveAll=false, bool saveParametric=false,
                 double scalingFactor=1.0, int elementStartNum=0,
                 int saveSinglePartition=0, bool multipleView=false,
                 bool renumberVertices=true);
  int _writePartitionedMSH2(const std::string &baseName, bool binary=false,
                            bool saveAll=false, bool saveParametric=false,
                            double scalingFactor=1.0);

  // the maximum vertex and element id number in the mesh
  int _maxVertexNum, _maxElementNum;
  int _checkPointedMaxVertexNum, _checkPointedMaxElementNum;
 protected:
  // the name of the model
  std::string _name;

  // the name of the file the model was read from
  std::string _fileName;
  std::set<std::string> _fileNames;

  // the visibility flag
  char _visible;

  // vertex and element caches to speed-up direct access by tag (only
  // used for post-processing I/O)
  std::vector<MVertex*> _vertexVectorCache;
  std::map<int, MVertex*> _vertexMapCache;
  std::vector<MElement*> _elementVectorCache;
  std::map<int, MElement*> _elementMapCache;
  std::map<int, int> _elementIndexCache;

  // ghost cell information (stores partitions for each element acting
  // as a ghost cell)
  std::multimap<MElement*, short> _ghostCells;

  // an octree for fast mesh element lookup
  MElementOctree *_octree;

  // Geo (Gmsh native) model internal data
  GEO_Internals *_geo_internals;
  void _createGEOInternals();
  void _deleteGEOInternals();

  // OpenCascade model internal data
  OCC_Internals *_occ_internals;
  void _createOCCInternals();
  void _deleteOCCInternals();
  void _resetOCCInternals();

  // ACIS model internal data
  ACIS_Internals *_acis_internals;
  void _deleteACISInternals();

  // Fourier model internal data
  FM_Internals *_fm_internals;
  void _createFMInternals();
  void _deleteFMInternals();

  // CAD creation factory
  GModelFactory *_factory;

  // characteristic length (mesh size) fields
  FieldManager *_fields;

  // store the elements given in the map (indexed by elementary region
  // number) into the model, creating discrete geometrical entities on
  // the fly if needed
  void _storeElementsInEntities(std::map<int, std::vector<MElement*> > &map);

  // store the parent's pointer back into MSubElements (replacing numeric id)
  void _storeParentsInSubElements(std::map< int, std::vector<MElement* > >& map);

  // Discrete Entities have to have their mesh moved to a geometry container
  void _createGeometryOfDiscreteEntities(bool force=false);

  // loop over all vertices connected to elements and associate
  // geometrical entity
  void _associateEntityWithMeshVertices();

  // store the vertices in the geometrical entity they are associated
  // with, and delete those that are not associated with any entity
  void _storeVerticesInEntities(std::map<int, MVertex*> &vertices);
  void _storeVerticesInEntities(std::vector<MVertex*> &vertices);

  // store the physical tags in the geometrical entities
  void _storePhysicalTagsInEntities(int dim,
                                    std::map<int, std::map<int, std::string> > &map);

  // entity that is currently being meshed (used for error reporting)
  GEntity *_currentMeshEntity;

  // index of the current model (in the static list of all loaded
  // models)
  static int _current;

 protected:
  // the sets of geometrical regions, faces, edges and vertices in the
  // model
  std::set<GRegion*, GEntityLessThan> regions;
  std::set<GFace*, GEntityLessThan> faces;
  std::set<GEdge*, GEntityLessThan> edges;
  std::set<GVertex*, GEntityLessThan> vertices;

  // map between the pair <dimension, elementary or physical number>
  // and an optional associated name
  std::map<std::pair<int, int>, std::string> physicalNames, elementaryNames;

  // the set of all used mesh partition numbers
  std::set<int> meshPartitions;
  int partitionSize[2];

 public:
  GModel(std::string name="");
  virtual ~GModel();
// Required for python bindings on Windows
#ifndef SWIG
  // the static list of all loaded models
  static std::vector<GModel*> list;
# endif

  // return the current model, and sets the current model index if
  // index >= 0
  static GModel *current(int index=-1);

  // sets a model to current
  static int setCurrent(GModel *m);
  int setAsCurrent(){ return setCurrent(this); }

  // find a model by name; if fileName is given, return model only if it does
  // *not* have a link to the fileName
  static GModel *findByName(const std::string &name, const std::string &fileName="");

  // delete everything in a GModel (optionally keep name and fileName)
  void destroy(bool keepName=false);

  // get/set global vertex/element num
  int getMaxVertexNumber(){ return _maxVertexNum; }
  int getMaxElementNumber(){ return _maxElementNum; }
  void setMaxVertexNumber(int num){ _maxVertexNum = num; }
  void setMaxElementNumber(int num){ _maxElementNum = num; }
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

  // delete all the mesh-related caches (this must be called when the
  // mesh is changed)
  void destroyMeshCaches();
  //delete the mesh stored in entities and call destroMeshCaches
  void deleteMesh();

  // remove all mesh vertex associations to geometrical entities and remove
  // vertices from geometrical entities, then _associateEntityWithMeshVertices
  // and _storeVerticesInEntities are called to rebuild the associations
  void pruneMeshVertexAssociations();

  // access internal CAD representations
  GEO_Internals *getGEOInternals(){ return _geo_internals; }
  OCC_Internals *getOCCInternals(){ return _occ_internals; }
  FM_Internals *getFMInternals() { return _fm_internals; }
  ACIS_Internals *getACISInternals(){ return _acis_internals; }

  // access characteristic length (mesh size) fields
  FieldManager *getFields(){ return _fields; }

  // get/set the model name
  void setName(std::string name){ _name = name; }
  std::string getName(){ return _name; }

  // get/set the model file name
  void setFileName(std::string fileName);
  std::string getFileName(){ return _fileName; }
  bool hasFileName(const std::string &name)
  {
    return _fileNames.find(name) != _fileNames.end();
  }

  // get/set the visibility flag
  char getVisibility(){ return _visible; }
  void setVisibility(char val){ _visible = val; }

  // set the visibility of compound entities
  void setCompoundVisibility();

  // get the number of entities in this model
  int getNumRegions() const { return regions.size(); }
  int getNumFaces() const { return faces.size(); }
  int getNumEdges() const { return edges.size(); }
  int getNumVertices() const { return vertices.size(); }

  // quickly check if the model is empty (i.e., if it contains no
  // entities)
  bool empty() const;

  // region, face, edge and vertex iterators
  typedef std::set<GRegion*, GEntityLessThan>::iterator riter;
  typedef std::set<GFace*, GEntityLessThan>::iterator fiter;
  typedef std::set<GEdge*, GEntityLessThan>::iterator eiter;
  typedef std::set<GVertex*, GEntityLessThan>::iterator viter;

  // get an iterator initialized to the first/last entity in this model
  riter firstRegion() { return regions.begin(); }
  fiter firstFace() { return faces.begin(); }
  eiter firstEdge() { return edges.begin(); }
  viter firstVertex() { return vertices.begin(); }
  riter lastRegion() { return regions.end(); }
  fiter lastFace() { return faces.end(); }
  eiter lastEdge() { return edges.end(); }
  viter lastVertex() { return vertices.end(); }

  // find the entity with the given tag
  GRegion *getRegionByTag(int n) const;
  GFace *getFaceByTag(int n) const;
  GEdge *getEdgeByTag(int n) const;
  GVertex *getVertexByTag(int n) const;
  std::vector<int> getEdgesByStringTag(const std::string tag);

  // add/remove an entity in the model
  void add(GRegion *r) { regions.insert(r); }
  void add(GFace *f) { faces.insert(f); }
  void add(GEdge *e) { edges.insert(e); }
  void add(GVertex *v) { vertices.insert(v); }
  void remove(GRegion *r);
  void remove(GFace *f);
  void remove(GEdge *e);
  void remove(GVertex *v);

  // snap vertices on model edges by using geometry tolerance
  void snapVertices();

  // fill a vector containing all the entities in the model
  void getEntities(std::vector<GEntity*> &entities, int dim=-1) const;

  // fill a vector containing all the entities in a given bounding box
  void getEntitiesInBox(std::vector<GEntity*> &entities, SBoundingBox3d box,
                        int dim=-1) const;

  // return the highest number associated with an elementary entity of
  // a given dimension (or the highest overall if dim < 0)
  int getMaxElementaryNumber(int dim);

  // check if there are no physical entities in the model
  bool noPhysicalGroups();

  // return all physical groups (one map per dimension: 0-D to 3-D)
  void getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4]) const;
  void getPhysicalGroups(int dim, std::map<int, std::vector<GEntity*> > &groups) const;

  // delete physical groups in the model
  void deletePhysicalGroups();
  void deletePhysicalGroup(int dim, int num);

  // return the highest number associated with a physical entity of a
  // given dimension (or highest for all dimenions if dim < 0)
  int getMaxPhysicalNumber(int dim);

  // elementary/physical name iterator
  typedef std::map<std::pair<int, int>, std::string>::iterator piter;

  // get an iterator on the elementary/physical names
  piter firstPhysicalName() { return physicalNames.begin(); }
  piter lastPhysicalName() { return physicalNames.end(); }
  piter firstElementaryName() { return elementaryNames.begin(); }
  piter lastElementaryName() { return elementaryNames.end(); }

  // get the number of physical names
  int numPhysicalNames(){ return physicalNames.size(); }

  // associate a name with a physical entity of dimension "dim" and
  // number "num" (returns a new number id if "num"==0)
  int setPhysicalName(std::string name, int dim, int num=0);

  // get the name (if any) of a given physical group of dimension
  // "dim" and id number "num"
  std::string getPhysicalName(int dim, int num) const;

  // get the number of a given physical group of dimension
  // "dim" and name "name". return -1 if not found
  int getPhysicalNumber(const int &dim, const std::string & name);

  // set physical tags to entities in a given bounding box
  void setPhysicalNumToEntitiesInBox(int EntityDimension, int PhysicalNumber,
                                     std::vector<double> p1, std::vector<double> p2);
  void setPhysicalNumToEntitiesInBox(int EntityDimension, int PhysicalNumber,
                                     SBoundingBox3d box);

  // get the name (if any) of a given elementary entity of dimension
  // "dim" and id number "num"
  std::string getElementaryName(int dim, int num);

  //get the highest dimension of the GModel
  int getDim() const;

  // set the selection flag on all entities
  void setSelection(int val);

  // the bounding box
  SBoundingBox3d bounds(bool aroundVisible=false);

  // return the mesh status for the entire model
  int getMeshStatus(bool countDiscrete=true);

  // return the total number of elements in the mesh
  int getNumMeshElements();
  int getNumMeshParentElements();

  // get the number of each type of element in the mesh at the largest
  // dimension and return the dimension
  int getNumMeshElements(unsigned c[6]);

  // access a mesh element by coordinates (using an octree search)
  MElement *getMeshElementByCoord(SPoint3 &p, int dim=-1, bool strict=true);
  std::vector<MElement*> getMeshElementsByCoord(SPoint3 &p, int dim=-1, bool strict=true);
  void deleteOctree();

  // access a mesh element by tag, using the element cache
  MElement *getMeshElementByTag(int n);

  // access temporary mesh element index
  int getMeshElementIndex(MElement *e);
  void setMeshElementIndex(MElement *e, int index);

  // return the total number of vertices in the mesh
  int getNumMeshVertices() const;

  // access a mesh vertex by tag, using the vertex cache
  MVertex *getMeshVertexByTag(int n);

  // get all the mesh vertices associated with the physical group
  // of dimension "dim" and id number "num"
  void getMeshVerticesForPhysicalGroup(int dim, int num, std::vector<MVertex*> &);

  // index all the (used) mesh vertices in a continuous sequence,
  // starting at 1
  int indexMeshVertices(bool all, int singlePartition=0, bool renumber=true);

  // scale the mesh by the given factor
  void scaleMesh(double factor);

  // set/get entity that is currently being meshed (for error reporting)
  void setCurrentMeshEntity(GEntity *e){ _currentMeshEntity = e; }
  GEntity *getCurrentMeshEntity(){ return _currentMeshEntity; }

  // delete all invisble mesh elements
  void removeInvisibleElements();

  // the list of partitions
  std::set<int> &getMeshPartitions() { return meshPartitions; }
  void recomputeMeshPartitions();

  // delete all the partitions
  void deleteMeshPartitions();

  // store/recall min and max partitions size
  void setMinPartitionSize(const int pSize) { partitionSize[0] = pSize; }
  void setMaxPartitionSize(const int pSize) { partitionSize[1] = pSize; }
  int getMinPartitionSize() const { return partitionSize[0]; }
  int getMaxPartitionSize() const { return partitionSize[1]; }

  std::multimap<MElement*, short> &getGhostCells(){ return _ghostCells; }

  // perform various coherence tests on the mesh
  void checkMeshCoherence(double tolerance);

  // remove duplicate mesh vertices
  int removeDuplicateMeshVertices(double tolerance);

  // create topology from mesh
  void createTopologyFromMeshNew();
  void createTopologyFromMesh(int ignoreHoles=0);
  void createTopologyFromRegions(std::vector<discreteRegion*> &discRegions);
  void createTopologyFromFaces(std::vector<discreteFace*> &pFaces, int ignoreHoles=0);
  void makeDiscreteRegionsSimplyConnected();
  void makeDiscreteFacesSimplyConnected();

  // align periodic boundaries
  void alignPeriodicBoundaries();

  // a container for smooth normals
  smooth_normals *normals;

  // mesh the model
  int mesh(int dimension);

  // adapt the mesh anisotropically using metrics that are computed from a set of functions f(x,y,z).
  //   For all algorithms
  //           parameters[1] = lcmin (default : in global gmsh options CTX::instance()->mesh.lcMin)
  //           parameters[2] = lcmax (default : in global gmsh options CTX::instance()->mesh.lcMax)
  //   niter is the maximum number of iterations
  //   Available algorithms:
  //    1) Assume that the function is a levelset -> adapt using Coupez technique (technique = 1)
  //           parameters[0] = thickness of the interface (mandatory)
  //    2) Assume that the function is a physical quantity -> adapt using the Hessian (technique = 2)
  //           parameters[0] = N, the final number of elements
  //    3) A variant of 1) by P. Frey (= Coupez + takes curvature function into account)
  //           parameters[0] = thickness of the interface (mandatory)
  //           parameters[3] = the required minimum number of elements to represent a circle - used for curvature-based metric (default: = 15)
  //    4) A variant (3), direct implementation in the metric eigendirections, assuming a level set (ls):
  //        - hmin is imposed in the ls gradient,
  //        - hmax is imposed in the two eigendirections of the ls hessian that are (almost ?) tangent to the iso-zero plane
  //          + the latter eigenvalues (1/hmax^2) are modified if necessary to capture the iso-zero curvature
  //           parameters[0] = thickness of the interface in the positive ls direction (mandatory)
  //           parameters[4] = thickness of the interface in the negative ls direction (=parameters[0] if not specified)
  //           parameters[3] = the required minimum number of elements to represent a circle - used for curvature-based metric (default: = 15)
  //    5) Same as 4, except that the transition in band E uses linear interpolation of h, instead of linear interpolation of metric
  // The algorithm first generate a mesh if no one is available

  // In this first attempt, only the highest dimensional mesh is adapted, which is ok if
  // we assume that boundaries are already adapted.
  // This should be fixed.
  int adaptMesh(std::vector<int> technique,
		std::vector<simpleFunction<double>*> f,
		std::vector<std::vector<double> > parameters,
		int niter, bool meshAll=false);

  // Ensure that the Jacobian of all volume elements is positive
  bool setAllVolumesPositive();
  void setAllVolumesPositiveTopology();

  // make the mesh a high order mesh at order N
  // linear is 1 if the high order points are not placed on the geometry of the model
  // incomplete is 1 if incomplete basis are used
  int setOrderN(int order, int linear, int incomplete);

  // refine the mesh by splitting all elements
  int refineMesh(int linear);

  // optimize the mesh
  int optimizeMesh(const std::string &how);

  // partition the mesh
  int partitionMesh(int num);

  // create partition boundaries
  void createPartitionBoundaries(int createGhostCells, int createAllDims = 0);

  // fill the vertex arrays, given the current option and data
  bool fillVertexArrays();

  // reclassify a mesh i.e. use an angle threshold to tag edges faces and regions
  void classifyFaces(std::set<GFace*> &_faces);

  // glue entities in the model (assume a tolerance eps and merge
  // vertices that are too close, then merge edges, faces and
  // regions). Warning: the gluer changes the geometric model, so that
  // some pointers could become invalid.
  void glue(double eps);

  // change the entity creation factory
  void setFactory(std::string name);

  // create brep geometry entities using the factory
  GVertex *addVertex(double x, double y, double z, double lc);
  GEdge *addLine(GVertex *v1, GVertex *v2);
  GEdge *addCircleArcCenter(double x, double y, double z, GVertex *start, GVertex *end);
  GEdge *addCircleArcCenter(GVertex *start, GVertex *center, GVertex *end);
  GEdge *addCircleArc3Points(double x, double y, double z, GVertex *start, GVertex *end);
  GEdge *addBezier(GVertex *start, GVertex *end, std::vector<std::vector<double> > points);
  GEdge *addBSpline(GVertex *start, GVertex *end, std::vector<std::vector<double> > points);
  GEdge *addNURBS(GVertex *start, GVertex *end,
		  std::vector<std::vector<double> > points,
		  std::vector<double> knots,
		  std::vector<double> weights,
		  std::vector<int> mult);
  GEntity *revolve(GEntity *e, std::vector<double> p1, std::vector<double> p2,
                   double angle);
  GEntity *extrude(GEntity *e, std::vector<double> p1, std::vector<double> p2);
  std::vector<GEntity*> extrudeBoundaryLayer(GEntity *e, int nbLayers, double hLayers,
                                             int dir=1, int view=-1);
  GEntity *addPipe(GEntity *e, std::vector<GEdge *> edges);
  GEntity *addThruSections(std::vector<std::vector<GEdge *> > edges);

  std::vector<GFace *> addRuledFaces(std::vector<std::vector<GEdge *> > edges);
  GFace *addFace(std::vector<GEdge *> edges, std::vector< std::vector<double > > points);
  GFace *addPlanarFace(std::vector<std::vector<GEdge *> > edges);
  GFace *addPlanarFace (std::vector<std::vector<GEdgeSigned> > edges);
  GFace *add2Drect(double x0, double y0, double dx, double dy);
  GFace *add2Dellips(double xc, double yc, double rx, double ry);

  GEdge *addCompoundEdge(std::vector<GEdge*> edges, int num=-1);
  GFace *addCompoundFace(std::vector<GFace*> faces, int type, int split, int num=-1);
  GRegion *addVolume(std::vector<std::vector<GFace*> > faces);

  // create solid geometry primitives using the factory
  GEntity *addSphere(double cx, double cy, double cz, double radius);
  GEntity *addCylinder(std::vector<double> p1, std::vector<double> p2, double radius);
  GEntity *addTorus(std::vector<double> p1, std::vector<double> p2, double radius1,
                    double radius2);
  GEntity *addBlock(std::vector<double> p1, std::vector<double> p2);
  GEntity *add3DBlock(std::vector<double> p1, double dx, double dy , double dz);
  GEntity *addCone(std::vector<double> p1, std::vector<double> p2, double radius1,
                   double radius2);

  // heal geometry using the factory
  void healGeometry(double tolerance = -1);

  // boolean operators acting on 2 models
  GModel *computeBooleanUnion(GModel *tool, int createNewModel=0);
  GModel *computeBooleanIntersection(GModel *tool, int createNewModel=0);
  GModel *computeBooleanDifference(GModel *tool, int createNewModel=0);
  void    salomeconnect();
  void    occconnect();

  void setPeriodicAllFaces(std::vector<double> FaceTranslationVector);
  void setPeriodicPairOfFaces(int numFaceMaster, std::vector<int> EdgeListMaster,
                              int numFaceSlave, std::vector<int> EdgeListSlave);

  // build a new GModel by cutting the elements crossed by the levelset ls
  // if cutElem is set to false, split the model without cutting the elements
  GModel *buildCutGModel(gLevelset *ls, bool cutElem=true, bool saveTri=false);

  // create a GModel by importing a mesh (vertexMap has a dim equal to the
  // number of vertices and all the other vectors have a dim equal to the number
  // of elements)
  static GModel *createGModel(std::map<int, MVertex*> &vertexMap,
                              std::vector<int> &numElement,
                              std::vector<std::vector<int> > &vertexIndices,
                              std::vector<int> &elementType,
                              std::vector<int> &physical,
                              std::vector<int> &elementary,
                              std::vector<int> &partition);

  // create a GModel from newly created mesh elements (with their own newly
  // created mesh vertices), and let element entities have given physical group
  // tags
  static GModel *createGModel
    (std::map<int, std::vector<MElement*> > &entityToElementsMap,
     std::map<int, std::vector<int> > &entityToPhysicalsMap);

  // for elements cut having new vertices
  void store(std::vector<MVertex*> &vertices, int dim,
            std::map<int, std::vector<MElement*> > &entityMap,
            std::map<int, std::map<int, std::string> > &physicalMap);

  // store mesh elements of a chain in a new elementary and physical entity
  void storeChain(int dim,
                  std::map<int, std::vector<MElement*> > &entityMap,
                  std::map<int, std::map<int, std::string> > &physicalMap);

  // request homology computation
  void addHomologyRequest(const std::string &type, std::vector<int> &domain,
                          std::vector<int> &subdomain, std::vector<int> &dim);
  void computeHomology();

  // "automatic" IO based on Gmsh global functions
  void load(std::string fileName);
  void save(std::string fileName);

  // Gmsh native CAD format (readGEO is static, since it can create
  // multiple models)
  static int readGEO(const std::string &name);
  int writeGEO(const std::string &name, bool printLabels=true,
               bool onlyPhysicals=false);
  int importGEOInternals();
  int exportDiscreteGEOInternals();

  // Fourier model
  int readFourier();
  int readFourier(const std::string &name);
  int writeFourier(const std::string &name);

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
  int importOCCInternals();

  // ACIS Model
  int readACISSAT(const std::string &name);

  // Gmsh mesh file format
  int readMSH(const std::string &name);
  int writeMSH(const std::string &name, double version=2.2, bool binary=false,
               bool saveAll=false, bool saveParametric=false,
               double scalingFactor=1.0, int elementStartNum=0,
               int saveSinglePartition=0, bool multipleView=false);
  int writePartitionedMSH(const std::string &baseName, double version=2.2,
                          bool binary=false, bool saveAll=false,
                          bool saveParametric=false, double scalingFactor=1.0);

  // Iridium file format
  int writeIR3(const std::string &name, int elementTagType,
               bool saveAll, double scalingFactor);

  // mesh statistics (saved as a Gmsh post-processing view)
  int writePOS(const std::string &name, bool printElementary,
               bool printElementNumber, bool printSICN, bool printGamma, bool printRho,
               bool printDisto, bool saveAll=false, double scalingFactor=1.0);

  // Stereo lithography format
  int readSTL(const std::string &name, double tolerance=1.e-3);
  int writeSTL(const std::string &name, bool binary=false,
               bool saveAll=false, double scalingFactor=1.0);

  // PLY(2) format (ascii text format)
  int readPLY(const std::string &name);
  int readPLY2(const std::string &name);
  int writePLY2(const std::string &name);

  // Inventor/VRML format
  int readVRML(const std::string &name);
  int writeVRML(const std::string &name,
                bool saveAll=false, double scalingFactor=1.0);

  // I-deas universal mesh format
  int readUNV(const std::string &name);
  int writeUNV(const std::string &name, bool saveAll=false,
               bool saveGroupsOfNodes=false, double scalingFactor=1.0);

  // Medit (INRIA) mesh format
  int readMESH(const std::string &name);
  int writeMESH(const std::string &name, int elementTagType=1,
                bool saveAll=false, double scalingFactor=1.0);

  // Nastran Bulk Data File format
  int readBDF(const std::string &name);
  int writeBDF(const std::string &name, int format=0, int elementTagType=1,
               bool saveAll=false, double scalingFactor=1.0);

  // Actran mesh
  int readACTRAN(const std::string &name);

  // Plot3D structured mesh format
  int readP3D(const std::string &name);
  int writeP3D(const std::string &name,
               bool saveAll=false, double scalingFactor=1.0);

  // CFD General Notation System files
  int readCGNS(const std::string &name);
  int writeCGNS(const std::string &name, int zoneDefinition,
                const CGNSOptions &options, double scalingFactor=1.0);

  // Med "Modele d'Echange de Donnees" file format (the static routine
  // is allowed to load multiple models/meshes)
  static int readMED(const std::string &name);
  int readMED(const std::string &name, int meshIndex);
  int writeMED(const std::string &name,
               bool saveAll=false, double scalingFactor=1.0);

  // VTK format
  int readVTK(const std::string &name, bool bigEndian=false);
  int writeVTK(const std::string &name, bool binary=false,
               bool saveAll=false, double scalingFactor=1.0,
               bool bigEndian=false);

  // Tochnog format
  int writeTOCHNOG(const std::string &name,  bool saveGroupsOfNodes=false,
                   bool saveAll=false, double scalingFactor=1.0);

  // DIFFPACK format
  int readDIFF(const std::string &name);
  int writeDIFF(const std::string &name, bool binary=false,
               bool saveAll=false, double scalingFactor=1.0);

  // Abaqus
  int writeINP(const std::string &name, bool saveAll=false,
               bool saveGroupsOfNodes=false, double scalingFactor=1.0);

  // CELUM
  int writeCELUM(const std::string &name, bool saveAll=false,
                 double scalingFactor=1.0);

  // Geomview mesh
  int readGEOM(const std::string &name);

  // CEA triangulation
  int writeMAIL(const std::string &name, bool saveAll, double scalingFactor);

  // SU2 mesh file
  int writeSU2(const std::string &name, bool saveAll, double scalingFactor);
};

#endif
