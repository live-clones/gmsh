// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PVIEW_DATA_GMODEL_H
#define PVIEW_DATA_GMODEL_H

#include <functional>
#include <memory>
#include <algorithm>
#include "PViewData.h"
#include "GModel.h"
#include "SBoundingBox3d.h"

template <class Real> class stepData {
private:
  // a pointer to the underlying model
  GModel *_model;
  // the unrolled list of all geometrical entities in the model
  std::vector<GEntity *> _entities;
  // the bounding box of the view
  SBoundingBox3d _bbox;
  // the number of nodes of the model when the bounding box was computed, and
  // what the entities and the bounding box were last checked against (see
  // updateModelInfo())
  std::size_t _numModelNodes;
  std::vector<std::size_t> _modelSignature;
  // the file the data was read from (if empty, refer to PViewData)
  std::string _fileName;
  // the index in the file (if negative, refer to PViewData)
  int _fileIndex;
  // the value of the time step and value min/max
  double _time, _min, _max;
  // the number of components in the data (one stepData contains only
  // a single field type)
  int _numComp;
  // the values, indexed by MVertex or MElement id numbers (If the
  // numbering is sparse, or if we only have data for high-id
  // entities, the vector has zero entries and is thus not
  // optimal. This is the price to pay if we want 1) rapid access to
  // the data and 2) not to store any additional info in MVertex or
  // MElement)
  //
  // FIXME: we should change this design and store a vector<int> of tags, and do
  // indirect addressing, even if it's a bit slower...
  std::vector<Real *> *_data;
  // the memory the values point into: large arrays, each holding the values of
  // many entities (see allocate())
  std::vector<std::unique_ptr<Real[]>> _pools;
  Real *_poolNext;
  std::size_t _poolLeft, _poolSize;
  // a vector containing the multiplying factor allowing to compute
  // the number of values stored in _data for each index (number of
  // values = getMult() * getNumComponents()). If _mult is empty, a
  // default value of "1" is assumed
  std::vector<int> _mult;
  // a vector, indexed by MSH element type, of Gauss point locations
  // in parametric space
  std::vector<std::vector<double> > _gaussPoints;
  // a set of all "partitions" encountered in the data
  std::set<int> _partitions;

public:
  stepData(GModel *model, int numComp, const std::string &fileName = "",
           int fileIndex = -1, double time = 0., double min = VAL_INF,
           double max = -VAL_INF)
    : _model(model), _numModelNodes(0), _fileName(fileName),
      _fileIndex(fileIndex), _time(time), _min(min), _max(max),
      _numComp(numComp), _data(0), _poolNext(0), _poolLeft(0), _poolSize(128)
  {
  }
  stepData(stepData<Real> &other)
    : _data(0), _poolNext(0), _poolLeft(0), _poolSize(128)
  {
    _model = other._model;
    _entities = other._entities;
    _bbox = other._bbox;
    _numModelNodes = other._numModelNodes;
    _modelSignature = other._modelSignature;
    _fileName = other._fileName;
    _fileIndex = other._fileIndex;
    _time = other._time;
    _min = other._min;
    _max = other._max;
    _numComp = other._numComp;
    if(other._data) {
      std::size_t n = other.getNumData();
      _data = new std::vector<Real *>(n, (Real *)0);
      for(std::size_t i = 0; i < n; i++) {
        Real *d = other.getData(i);
        if(d) {
          std::size_t m = other.getMult(i) * _numComp;
          (*_data)[i] = allocate(m);
          std::copy(d, d + m, (*_data)[i]);
        }
      }
    }
    _mult = other._mult;
    _gaussPoints = other._gaussPoints;
    _partitions = other._partitions;
  }
  ~stepData() { destroyData(); }
  void fillEntities() { _model->getEntities(_entities); }
  void computeBoundingBox() { _bbox = _model->bounds(); }
  // fill the entities and compute the bounding box, unless the model has the
  // same entities and the same number of nodes as when they were last computed
  // (going over all the nodes for each step, or for each block of data read,
  // is slow); and check that only if the signature of the model (values that
  // change with it and are cheap to get) is not the one they were last checked
  // against, here or in another step on the same model (listing the entities
  // and counting the nodes for each block is slow too, with many partitions)
  void updateModelInfo(const std::vector<stepData<Real> *> &steps,
                       const std::vector<std::size_t> &signature)
  {
    if(signature == _modelSignature) return;
    for(auto s : steps) {
      if(s != this && s->_model == _model && s->_modelSignature == signature) {
        _entities = s->_entities;
        _bbox = s->_bbox;
        _numModelNodes = s->_numModelNodes;
        _modelSignature = signature;
        return;
      }
    }
    std::vector<GEntity *> entities;
    _model->getEntities(entities);
    std::size_t numNodes = _model->getNumMeshVertices();
    if(entities != _entities || numNodes != _numModelNodes) {
      _entities.swap(entities);
      computeBoundingBox();
      _numModelNodes = numNodes;
    }
    _modelSignature = signature;
  }
  GModel *getModel() { return _model; }
  SBoundingBox3d getBoundingBox() { return _bbox; }
  int getNumEntities() { return _entities.size(); }
  GEntity *getEntity(int ent) { return _entities[ent]; }
  int getNumComponents() { return _numComp; }
  int getMult(std::size_t index)
  {
    if(index >= _mult.size()) return 1;
    return _mult[index];
  }
  std::string getFileName() { return _fileName; }
  void setFileName(const std::string &name) { _fileName = name; }
  int getFileIndex() { return _fileIndex; }
  void setFileIndex(int index) { _fileIndex = index; }
  double getTime() { return _time; }
  void setTime(double time) { _time = time; }
  double getMin() { return _min; }
  void setMin(double min) { _min = min; }
  double getMax() { return _max; }
  void setMax(double max) { _max = max; }
  std::size_t getNumData()
  {
    if(!_data) return 0;
    return _data->size();
  }
  void resizeData(std::size_t n)
  {
    if(!_data) _data = new std::vector<Real *>(n, (Real *)0);
    if(n > _data->size()) _data->resize(n, (Real *)0);
  }
  // n values owned by the step, uninitialized: taken from the current pool, or
  // from a new one, twice as large as the last up to 64k values (so that a
  // step with a few values stays small), or of their own if they are many
  Real *allocate(std::size_t n)
  {
    if(n > (1 << 14)) {
      _pools.emplace_back(new Real[n]);
      return _pools.back().get();
    }
    if(n > _poolLeft) {
      _poolSize = std::max(n, std::min<std::size_t>(2 * _poolSize, 1 << 16));
      _pools.emplace_back(new Real[_poolSize]);
      _poolNext = _pools.back().get();
      _poolLeft = _poolSize;
    }
    Real *d = _poolNext;
    _poolNext += n;
    _poolLeft -= n;
    return d;
  }
  // point the data of entity index to values allocated with allocate()
  void setData(std::size_t index, Real *d, int mult = 1)
  {
    if(index >= getNumData()) resizeData(index + 1);
    (*_data)[index] = d;
    setMult(index, mult);
  }
  void setMult(std::size_t index, int mult)
  {
    if(mult == getMult(index)) return;
    if(index >= _mult.size()) _mult.resize(index + 1, 1);
    _mult[index] = mult;
  }
  Real *getData(std::size_t index, bool allocIfNeeded = false, int mult = 1)
  {
    if(allocIfNeeded) {
      if(index >= getNumData()) resizeData(index + 1);
      Real *&d = (*_data)[index];
      if(!d || mult > getMult(index)) {
        d = allocate(_numComp * mult);
        std::fill(d, d + _numComp * mult, (Real)0.);
      }
      setMult(index, mult);
    }
    else {
      if(index >= getNumData()) return 0;
    }
    return (*_data)[index];
  }
  void destroyData()
  {
    if(_data) {
      delete _data;
      _data = 0;
    }
    _pools.clear();
    _poolNext = 0;
    _poolLeft = 0;
    _poolSize = 128;
  }
  void renumberData(const std::map<std::size_t, std::size_t> &mapping)
  {
    if(!_data) return;
    std::size_t imax = 0, imin = 0;
    for(auto m : mapping) {
      imax = std::max(imax, m.second);
      imin = std::min(imin, m.second);
    }
    std::vector<Real *> data2(imax + 1, nullptr);
    std::vector<int> mult2(imax + 1, 1);
    for(auto m : mapping) {
      if(m.first < _data->size()) {
        data2[m.second] = (*_data)[m.first];
      }
      else {
        Msg::Warning("Wrong source index %zu in step data renumbering", m.first);
        return;
      }
      if(m.first < _mult.size())
        mult2[m.second] = _mult[m.first];
    }
    *_data = data2;
    _mult = mult2;
  }
  std::vector<double> &getGaussPoints(int msh)
  {
    if((int)_gaussPoints.size() <= msh) _gaussPoints.resize(msh + 1);
    return _gaussPoints[msh];
  }
  std::set<int> &getPartitions() { return _partitions; }
  double getMemoryInMB()
  {
    double b = 0.;
    for(std::size_t i = 0; i < getNumData(); i++) b += getMult(i);
    return b * getNumComponents() * sizeof(Real) / 1024. / 1024.;
  }
};

// The data container using elements from one or more GModel(s).
class PViewDataGModel : public PViewData {
public:
  enum DataType {
    NodeData = 1,
    ElementData = 2,
    ElementNodeData = 3,
    GaussPointData = 4,
    BeamData = 5
  };

private:
  // the data, indexed by time step
  std::vector<stepData<double> *> _steps;
  // the global min/max of the view
  double _min, _max;
  // the type of the dataset
  DataType _type;
  // cache last element to speed up loops
  MElement *_getElement(int step, int ent, int ele);
  // the step, created on the model with numComp components if needed (and
  // those before it); nullptr if it holds data with another number of
  // components
  stepData<double> *_getStep(int step, GModel *model, int numComp);
  MVertex *_getNode(MElement *e, int nod);

public:
  PViewDataGModel(DataType type = NodeData);
  ~PViewDataGModel();
  bool finalize(bool computeMinMax = true,
                const std::string &interpolationScheme = "");
  std::string getFileName(int step = -1);
  int getNumTimeSteps();
  int getFirstNonEmptyTimeStep(int start = 0);
  double getTime(int step);
  double getMin(int step = -1, bool onlyVisible = false, int tensorRep = 0,
                int forceNumComponents = 0, int componentMap[9] = nullptr);
  double getMax(int step = -1, bool onlyVisible = false, int tensorRep = 0,
                int forceNumComponents = 0, int componentMap[9] = nullptr);
  void setMin(double min) { _min = min; }
  void setMax(double max) { _max = max; }
  SBoundingBox3d getBoundingBox(int step = -1);
  void setBoundingBox(SBoundingBox3d &box) {}
  int getNumScalars(int step = -1);
  int getNumVectors(int step = -1);
  int getNumTensors(int step = -1);
  int getNumPoints(int step = -1);
  int getNumLines(int step = -1);
  int getNumTriangles(int step = -1);
  int getNumQuadrangles(int step = -1);
  int getNumPolygons(int step = -1);
  int getNumTetrahedra(int step = -1);
  int getNumHexahedra(int step = -1);
  int getNumPrisms(int step = -1);
  int getNumPyramids(int step = -1);
  int getNumTrihedra(int step = -1);
  int getNumPolyhedra(int step = -1);
  int getNumEntities(int step = -1);
  int getNumElements(int step = -1, int ent = -1);
  // answer without counting the elements of the whole model: stop at the first
  // entity that has any
  bool hasElements()
  {
    if(_steps.empty()) return false;
    // from the end: getEntities() lists the points first and the regions last,
    // and it is the regions that carry the elements of a 3D mesh
    for(int i = _steps[0]->getNumEntities() - 1; i >= 0; i--)
      if(_steps[0]->getEntity(i)->getNumMeshElements()) return true;
    return false;
  }
  int getDimension(int step, int ent, int ele);
  int getNumNodes(int step, int ent, int ele);
  int getNode(int step, int ent, int ele, int nod, double &x, double &y,
              double &z);
  std::size_t getNodeId(int step, int ent, int ele, int nod);
  void setNode(int step, int ent, int ele, int nod, double x, double y,
               double z);
  int getNumComponents(int step, int ent, int ele);
  int getNumValues(int step, int ent, int ele);
  void getValue(int step, int ent, int ele, int idx, double &val);
  void getValue(int step, int ent, int ele, int node, int comp, double &val);
  void setValue(int step, int ent, int ele, int node, int comp, double val);
  int getNumEdges(int step, int ent, int ele);
  int getType(int step, int ent, int ele);
  void reverseElement(int step, int ent, int ele);
  void smooth();
  double getMemoryInMB();
  bool combineTime(nameData &nd);
  bool skipEntity(int step, int ent);
  bool skipElement(int step, int ent, int ele, bool checkVisibility = false,
                   int samplingRate = 1);
  bool isThreadSafe() { return true; }
  bool hasTimeStep(int step);
  // for a view whose steps are on several meshes: call f for each run of
  // consecutive steps on the same mesh, with the first of them, the view
  // holding only those steps while f runs (the others are empty), so that it
  // can be written as a view on a single mesh
  bool forEachMesh(const std::function<bool(int)> &f);
  // read data of a file in the most recent view named name whose data is
  // model-based and accepted, or else in a new view of the given type, kept if
  // the reading succeeds; the data gets the name and the file name
  static bool readInView(const std::string &name, const std::string &fileName,
                         DataType type,
                         const std::function<bool(PViewDataGModel *)> &accept,
                         const std::function<bool(PViewDataGModel *)> &read);
  // can data of this type, with numComp components, be added to the step?
  bool canAddData(DataType type, int step, int numComp);
  bool hasPartition(int step, int part);
  bool hasMultipleMeshes();
  bool hasModel(GModel *model, int step = -1);
  bool isNodeData() { return _type == NodeData; }
  bool useGaussPoints() { return _type == GaussPointData; }
  GModel *getModel(int step) { return _steps[step]->getModel(); }
  GEntity *getEntity(int step, int ent);
  MElement *getElement(int step, int entity, int element);

  // get the data type
  DataType getType() { return _type; }
  // direct access to value by index
  bool getValueByIndex(int step, int dataIndex, int node, int comp,
                       double &val);

  // Add some data "on the fly" (data is stored in a map, indexed by
  // node or element number depending on the type of dataset)
  bool addData(GModel *model, const std::map<int, std::vector<double> > &data,
               int step, double time, int partition, int numComp);

  // Add some data "on the fly", without a map; without computing the range of
  // the values if minMax is false
  bool addData(GModel *model, const std::vector<std::size_t> &tags,
               const std::vector<std::vector<double>> &data, int step,
               double time, int partition, int numComp, bool minMax = true);

  // Add homogeneous data "on the fly", without a map
  bool addData(GModel *model, const std::vector<std::size_t> &tags,
               const std::vector<double> &data, int step, double time,
               int partition, int numComp);

  // Allow to destroy the data
  void destroyData();

  // I/O routines
  // read the records of a data section of an MSH file (after its tags), in the
  // layout of the given version of the format
  bool readMSH(const std::string &viewName, const std::string &fileName,
               int fileIndex, FILE *fp, bool binary, bool swap, int step,
               double time, int partition, int numComp, int numNodes,
               const std::string &interpolationScheme, double version);
  virtual bool writeMSH(const std::string &fileName, double version = 2.2,
                        bool binary = false, bool savemesh = true,
                        bool multipleView = false, int partitionNum = -1,
                        bool saveInterpolationMatrices = true,
                        bool forceNodeData = false,
                        bool forceElementData = false);
  bool readCGNS(const std::pair<std::string, std::string> &solFieldName,
                const std::string &fileName, int fileIndex, int baseIndex,
                const std::vector<std::vector<MVertex *>> &vertPerZone,
                const std::vector<std::vector<MElement *>> &eltPerZone);
  bool readMED(const std::string &fileName, int fileIndex);
  bool writeMED(const std::string &fileName, bool saveMesh = true);

  void importLists(int N[24], std::vector<double> *V[24]);
  stepData<double> *getStepData(int step)
  {
    if(step >= 0 && step < (int)_steps.size()) return _steps[step];
    return nullptr;
  }
  void sendToServer(const std::string &name);
};

#endif
