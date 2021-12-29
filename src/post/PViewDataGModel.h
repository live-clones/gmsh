// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PVIEW_DATA_GMODEL_H
#define PVIEW_DATA_GMODEL_H

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
    : _model(model), _fileName(fileName), _fileIndex(fileIndex), _time(time),
      _min(min), _max(max), _numComp(numComp), _data(0)
  {
  }
  stepData(stepData<Real> &other) : _data(0)
  {
    _model = other._model;
    _entities = other._entities;
    _bbox = other._bbox;
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
          int m = other.getMult(i) * _numComp;
          (*_data)[i] = new Real[m];
          for(int j = 0; j < m; j++) (*_data)[i][j] = d[j];
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
  GModel *getModel() { return _model; }
  SBoundingBox3d getBoundingBox() { return _bbox; }
  int getNumEntities() { return _entities.size(); }
  GEntity *getEntity(int ent) { return _entities[ent]; }
  int getNumComponents() { return _numComp; }
  int getMult(int index)
  {
    if(index < 0 || index >= (int)_mult.size()) return 1;
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
  void resizeData(int n)
  {
    if(!_data) _data = new std::vector<Real *>(n, (Real *)0);
    if(n > (int)_data->size()) _data->resize(n, (Real *)0);
  }
  Real *getData(int index, bool allocIfNeeded = false, int mult = 1)
  {
    if(index < 0) return 0;
    if(allocIfNeeded) {
      if(index >= (int)getNumData()) resizeData(index + 100); // optimize this
      if(!(*_data)[index]) {
        (*_data)[index] = new Real[_numComp * mult];
        for(int i = 0; i < _numComp * mult; i++) (*_data)[index][i] = 0.;
      }
      if(mult > 1) {
        if(index >= (int)_mult.size())
          _mult.resize(index + 100, 1); // optimize this
        _mult[index] = mult;
      }
    }
    else {
      if(index >= (int)getNumData()) return 0;
    }
    return (*_data)[index];
  }
  void destroyData()
  {
    if(_data) {
      for(unsigned int i = 0; i < _data->size(); i++)
        if((*_data)[i]) delete[](*_data)[i];
      delete _data;
      _data = 0;
    }
  }
  void renumberData(const std::map<int, int> &mapping)
  {
    if(!_data) return;
    int imax = 0, imin = 0;
    for(auto m : mapping) {
      imax = std::max(imax, m.second);
      imin = std::min(imin, m.second);
    }
    if(imin < 0) {
      Msg::Warning("Wrong destination index %d in step data renumbering", imin);
      return;
    }
    std::vector<Real *> data2(imax + 1, nullptr);
    std::vector<int> mult2(imax + 1, 1);
    for(auto m : mapping) {
      if(m.first >= 0 && m.first < (int)_data->size()) {
        data2[m.second] = (*_data)[m.first];
      }
      else {
        Msg::Warning("Wrong source index %d in step data renumbering", m.first);
        return;
      }
      if(m.first >= 0 && m.first < (int)_mult.size())
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
  double getMemoryInMb()
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
  int getDimension(int step, int ent, int ele);
  int getNumNodes(int step, int ent, int ele);
  int getNode(int step, int ent, int ele, int nod, double &x, double &y,
              double &z);
  void setNode(int step, int ent, int ele, int nod, double x, double y,
               double z);
  void tagNode(int step, int ent, int ele, int nod, int tag);
  int getNumComponents(int step, int ent, int ele);
  int getNumValues(int step, int ent, int ele);
  void getValue(int step, int ent, int ele, int idx, double &val);
  void getValue(int step, int ent, int ele, int node, int comp, double &val);
  void setValue(int step, int ent, int ele, int node, int comp, double val);
  int getNumEdges(int step, int ent, int ele);
  int getType(int step, int ent, int ele);
  void reverseElement(int step, int ent, int ele);
  void smooth();
  double getMemoryInMb();
  bool combineTime(nameData &nd);
  bool skipEntity(int step, int ent);
  bool skipElement(int step, int ent, int ele, bool checkVisibility = false,
                   int samplingRate = 1);
  bool hasTimeStep(int step);
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

  // Add some data "on the fly", without a map
  bool addData(GModel *model, const std::vector<std::size_t> &tags,
               const std::vector<std::vector<double> > &data, int step,
               double time, int partition, int numComp);

  // Add homogeneous data "on the fly", without a map
  bool addData(GModel *model, const std::vector<std::size_t> &tags,
               const std::vector<double> &data, int step, double time,
               int partition, int numComp);

  // Allow to destroy the data
  void destroyData();

  // I/O routines
  bool readMSH(const std::string &viewName, const std::string &fileName,
               int fileIndex, FILE *fp, bool binary, bool swap, int step,
               double time, int partition, int numComp, int numNodes,
               const std::string &interpolationScheme);
  virtual bool writeMSH(const std::string &fileName, double version = 2.2,
                        bool binary = false, bool savemesh = true,
                        bool multipleView = false, int partitionNum = -1,
                        bool saveInterpolationMatrices = true,
                        bool forceNodeData = false,
                        bool forceElementData = false);
  bool readCGNS(const std::pair<std::string, std::string> &solFieldName,
                const std::string &fileName, int index, int fileIndex,
                int baseIndex,
                const std::vector<std::vector<MVertex *> > &vertPerZone,
                const std::vector<std::vector<MElement *> > &eltPerZone);
  bool readMED(const std::string &fileName, int fileIndex);
  bool writeMED(const std::string &fileName);
  bool readPCH(const std::string &fileName, int fileIndex);

  void importLists(int N[24], std::vector<double> *V[24]);
  stepData<double> *getStepData(int step)
  {
    if(step >= 0 && step < (int)_steps.size()) return _steps[step];
    return nullptr;
  }
  void sendToServer(const std::string &name);
};

#endif
