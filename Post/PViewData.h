// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PVIEW_DATA_H
#define PVIEW_DATA_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include "SBoundingBox3d.h"

#define VAL_INF 1.e200

class adaptiveData;
class GModel;
class GEntity;
class MElement;
class nameData;
class OctreePost;
template <class scalar> class fullMatrix;

typedef std::map<int, std::vector<fullMatrix<double> *> > interpolationMatrices;

// The abstract interface to post-processing view data.
class PViewData {
private:
  // flag to mark that the data is 'dirty' and should not be displayed
  bool _dirty;
  // name of the view
  std::string _name;
  // name of the file the data was loaded from
  std::string _fileName;
  std::set<std::string> _fileNames;
  // index of the view in the file
  int _fileIndex;
  // octree for rapid search
  OctreePost *_octree;

protected:
  // adaptive visualization data
  adaptiveData *_adaptive;
  // interpolation matrices, indexed by the type of element
  interpolationMatrices _interpolation;
  // global map of "named" interpolation matrices
  static std::map<std::string, interpolationMatrices> _interpolationSchemes;
  // string for the name of the interpolation scheme
  std::string _interpolationSchemeName;

public:
  PViewData();
  virtual ~PViewData();

  // get/set the dirty ("not ready for display") flag
  virtual bool getDirty() { return _dirty; }
  virtual void setDirty(bool val) { _dirty = val; }

  // finalize the view data (compute min/max, etc.)
  virtual bool finalize(bool computeMinMax = true,
                        const std::string &interpolationScheme = "");

  // get/set name
  virtual std::string getName() { return _name; }
  virtual void setName(const std::string &val) { _name = val; }

  // get/set (the main) filename containing the data
  virtual std::string getFileName(int step = -1) { return _fileName; }
  virtual void setFileName(const std::string &val)
  {
    _fileName = val;
    _fileNames.insert(val);
  }
  virtual bool hasFileName(const std::string &val)
  {
    return _fileNames.find(val) != _fileNames.end();
  }

  // get/set index of view data in file
  virtual int getFileIndex() { return _fileIndex; }
  virtual void setFileIndex(int val) { _fileIndex = val; }

  // get number of time steps in the data
  virtual int getNumTimeSteps() = 0;
  virtual int getFirstNonEmptyTimeStep(int start = 0) { return start; }

  // get the time value associated with the step-th time step
  virtual double getTime(int step) { return 0.; }

  // get/set min/max for given step (global over all steps if step=-1)
  virtual double getMin(int step = -1, bool onlyVisible = false,
                        int tensorRep = 0, int forceNumComponents = 0,
                        int componentMap[9] = nullptr) = 0;
  virtual double getMax(int step = -1, bool onlyVisible = false,
                        int tensorRep = 0, int forceNumComponents = 0,
                        int componentMap[9] = nullptr) = 0;
  virtual void setMin(double min) = 0;
  virtual void setMax(double max) = 0;

  // get/set the bounding box
  virtual SBoundingBox3d getBoundingBox(int step = -1) = 0;
  virtual void setBoundingBox(SBoundingBox3d &box) = 0;

  // get the number of elements of a given type, for a given step
  virtual int getNumScalars(int step = -1) { return 0; }
  virtual int getNumVectors(int step = -1) { return 0; }
  virtual int getNumTensors(int step = -1) { return 0; }
  virtual int getNumPoints(int step = -1) { return 0; }
  virtual int getNumLines(int step = -1) { return 0; }
  virtual int getNumTriangles(int step = -1) { return 0; }
  virtual int getNumQuadrangles(int step = -1) { return 0; }
  virtual int getNumPolygons(int step = -1) { return 0; }
  virtual int getNumTetrahedra(int step = -1) { return 0; }
  virtual int getNumHexahedra(int step = -1) { return 0; }
  virtual int getNumPrisms(int step = -1) { return 0; }
  virtual int getNumPyramids(int step = -1) { return 0; }
  virtual int getNumTrihedra(int step = -1) { return 0; }
  virtual int getNumPolyhedra(int step = -1) { return 0; }

  // return the number of geometrical entities in the view
  virtual int getNumEntities(int step = -1) { return 0; }

  // return the number of elements in the ent-th entity, or the total number of
  // elements if ent < 0
  virtual int getNumElements(int step = -1, int ent = -1) { return 0; }

  // return the geometrical dimension of the ele-th element in the ent-th entity
  virtual int getDimension(int step, int ent, int ele) { return 0; }

  // return the number of nodes of the ele-th element in the ent-th entity
  virtual int getNumNodes(int step, int ent, int ele) { return 0; }

  // get/set the coordinates and tag of the nod-th node from the ele-th element
  // in the ent-th entity (if the node has a tag, getNode returns it)
  virtual int getNode(int step, int ent, int ele, int nod, double &x, double &y,
                      double &z)
  {
    return 0;
  }
  virtual void setNode(int step, int ent, int ele, int nod, double x, double y,
                       double z);
  virtual void tagNode(int step, int ent, int ele, int nod, int tag) {}

  // return the number of components available for the ele-th element in the
  // ent-th entity
  virtual int getNumComponents(int step, int ent, int ele) { return 0; }

  // return the number of values available for the ele-th element in the ent-th
  // entity
  virtual int getNumValues(int step, int ent, int ele) { return 0; }

  // get the idx'th value for the ele-th element in the ent-th entity
  virtual void getValue(int step, int ent, int ele, int idx, double &val) {}

  // gets/set the comp-th component (at the step-th time step) associated with
  // the node-th node from the ele-th element in the ent-th entity
  virtual void getValue(int step, int ent, int ele, int nod, int comp,
                        double &val)
  {
  }
  virtual void setValue(int step, int ent, int ele, int nod, int comp,
                        double val);

  // return a scalar value associated with the node-th node from the ele-th
  // element in the ent-th entity: same as value for scalars, norm for vectors,
  // Von-Mises (if tensorRep == 0), max eigenvalue (if tensorRep == 1) or min
  // eigenvalue (if tensorRep == 2) for tensors
  void getScalarValue(int step, int ent, int ele, int nod, double &val,
                      int tensorRep = 0, int forceNumComponents = 0,
                      int componentMap[9] = nullptr);

  // return the number of edges of the ele-th element in the ent-th
  // entity
  virtual int getNumEdges(int step, int ent, int ele) { return 0; }

  // return the type of the ele-th element in the ent-th entity
  virtual int getType(int step, int ent, int ele) { return 0; }

  // return the number of 2D/3D strings in the view
  virtual int getNumStrings2D() { return 0; }
  virtual int getNumStrings3D() { return 0; }

  // return the i-th 2D/3D string in the view
  virtual void getString2D(int i, int step, std::string &str, double &x,
                           double &y, double &style)
  {
  }
  virtual void getString3D(int i, int step, std::string &str, double &x,
                           double &y, double &z, double &style)
  {
  }

  // change the orientation of the ele-th element
  virtual void reverseElement(int step, int ent, int ele) {}

  // check if the view is empty
  virtual bool empty();

  // check if we should skip the given entity/element
  virtual bool skipEntity(int step, int ent) { return false; }
  virtual bool skipElement(int step, int ent, int ele,
                           bool checkVisibility = false, int samplingRate = 1);

  // check if the data has the given step/partition/etc.
  virtual bool hasTimeStep(int step)
  {
    return step >= 0 && step < getNumTimeSteps();
  }
  virtual bool hasPartition(int step, int part) { return false; }
  virtual bool hasMultipleMeshes() { return false; }
  virtual bool hasModel(GModel *model, int step = -1) { return false; }
  virtual bool isNodeData() { return false; }

  // true if data is given at Gauss points (instead of vertices)
  virtual bool useGaussPoints() { return false; }

  // initialize/destroy adaptive data
  void initAdaptiveData(int step, int level, double tol);

  // Routines for
  // - export of adapted views to pvtu file format for parallel visualization
  //   with paraview,
  // - and/or generation of VTK data structure for ParaView plugin.
  void initAdaptiveDataLight(int step, int level, double tol);
  void saveAdaptedViewForVTK(const std::string &guifileName, int useDefaultName,
                             int step, int level, double tol, int npart,
                             bool isBinary);

  void destroyAdaptiveData();

  // return the adaptive data
  adaptiveData *getAdaptiveData() { return _adaptive; }

  // set/get the interpolation matrices for elements with type "type"
  // FIXME : too much overload :(
  void setInterpolationMatrices(int type, const fullMatrix<double> &coefVal,
                                const fullMatrix<double> &expVal);
  void setInterpolationMatrices(int type, const fullMatrix<double> &coefVal,
                                const fullMatrix<double> &expVal,
                                const fullMatrix<double> &coefGeo,
                                const fullMatrix<double> &expGeo);
  int getInterpolationMatrices(int type, std::vector<fullMatrix<double> *> &p);
  bool haveInterpolationMatrices(int type = 0);
  void deleteInterpolationMatrices(int type = 0);

  // access to global interpolation schemes
  static void removeInterpolationScheme(const std::string &name);
  static void removeAllInterpolationSchemes();
  static void addMatrixToInterpolationScheme(const std::string &name, int type,
                                             fullMatrix<double> &mat);
  static int getSizeInterpolationScheme();
  std::string getInterpolationSchemeName() { return _interpolationSchemeName; }
  void setInterpolationSchemeName(std::string name)
  {
    _interpolationSchemeName = name;
  }

  // smooth the data in the view (makes it C0)
  virtual void smooth();

  // combine time steps or elements from multiple datasets
  virtual bool combineTime(nameData &nd);
  virtual bool combineSpace(nameData &nd);

  // set simple X-Y data
  virtual void setXY(std::vector<double> &x, std::vector<double> &y) {}

  // set simple pointwise XYZ data
  virtual void setXYZV(std::vector<double> &x, std::vector<double> &y,
                       std::vector<double> &z, std::vector<double> &v)
  {
  }

  // ask to fill vertex arrays remotely
  virtual bool isRemote() { return false; }
  virtual int fillRemoteVertexArrays(std::string &options) { return 0; }

  // is the view a list-based dataset
  virtual bool isListBased() { return false; }

  // get (approx) memry used by data in Mb
  virtual double getMemoryInMb() { return 0; }

  // get GModel (if view supports it)
  virtual GModel *getModel(int step);

  // get GEntity (if view supports it)
  virtual GEntity *getEntity(int step, int entity);

  // get MElement (if view supports it)
  virtual MElement *getElement(int step, int entity, int element);

  // search for the value of the View at point x, y, z. Values are interpolated
  // using standard first order shape functions in the post element. If several
  // time steps are present, they are all interpolated unless time step is set
  // to a different value than -1.
  bool searchScalar(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchScalarWithTol(double x, double y, double z, double *values,
                           int step = -1, double *size = nullptr,
                           double tol = 1.e-2, int qn = 0, double *qx = nullptr,
                           double *qy = nullptr, double *qz = nullptr,
                           bool grad = false, int dim = -1);
  bool searchVector(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchVectorWithTol(double x, double y, double z, double *values,
                           int step = -1, double *size = nullptr,
                           double tol = 1.e-2, int qn = 0, double *qx = nullptr,
                           double *qy = nullptr, double *qz = nullptr,
                           bool grad = false, int dim = -1);
  bool searchTensor(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchTensorWithTol(double x, double y, double z, double *values,
                           int step = -1, double *size = nullptr,
                           double tol = 1.e-2, int qn = 0, double *qx = nullptr,
                           double *qy = nullptr, double *qz = nullptr,
                           bool grad = false, int dim = -1);

  // I/O routines
  virtual bool writeSTL(const std::string &fileName);
  virtual bool writeTXT(const std::string &fileName);
  virtual bool writePOS(const std::string &fileName, bool binary = false,
                        bool parsed = true, bool append = false);
  virtual bool writeMSH(const std::string &fileName, double version = 2.2,
                        bool binary = false, bool saveMesh = true,
                        bool multipleView = false, int partitionNum = 0,
                        bool saveInterpolationMatrices = true,
                        bool forceNodeData = false,
                        bool forceElementData = false);
  virtual bool writeMED(const std::string &fileName);
  virtual bool toVector(std::vector<std::vector<double> > &vec);
  virtual bool fromVector(const std::vector<std::vector<double> > &vec);
  virtual void importLists(int N[24], std::vector<double> *V[24]);
  virtual void getListPointers(int N[24], std::vector<double> *V[24]);
  virtual void sendToServer(const std::string &name);
};

#endif
