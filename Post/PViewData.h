// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PVIEW_DATA_H_
#define _PVIEW_DATA_H_

#include <string>
#include <vector>
#include <map>
#include "SBoundingBox3d.h"
#include "fullMatrix.h"

#define VAL_INF 1.e200

class adaptiveData;
class GModel;
class GEntity;
class MElement;
class nameData;
class binding;

// The abstract interface to post-processing view data.
class PViewData {
 private:
  // flag to mark that the data is 'dirty' and should not be displayed
  bool _dirty;
  // name of the view
  std::string _name;
  // name of the file the data was loaded from
  std::string _fileName;
  // index of the view in the file
  int _fileIndex;

 protected:
  // adaptive visualization data
  adaptiveData *_adaptive;
  // interpolation matrices, indexed by the type of element
  std::map<int, std::vector<fullMatrix<double>*> > _interpolation;

 public:
  PViewData();
  virtual ~PViewData();

  // get/set the dirty ("not ready for display") flag
  virtual bool getDirty(){ return _dirty; }
  virtual void setDirty(bool val){ _dirty = val; }

  // finalize the view data (compute min/max, etc.)
  virtual bool finalize(bool computeMinMax=true);

  // get/set name
  virtual std::string getName(){ return _name; }
  virtual void setName(std::string val){ _name = val; }

  // get/set (the main) filename containing the data
  virtual std::string getFileName(int step=-1){ return _fileName; }
  virtual void setFileName(std::string val){ _fileName = val; }

  // get/set index of view data in file
  virtual int getFileIndex(){ return _fileIndex; }
  virtual void setFileIndex(int val){ _fileIndex = val; }

  // get number of time steps in the data
  virtual int getNumTimeSteps() = 0;

  // get the time value associated with the step-th time step
  virtual double getTime(int step){ return 0.; }

  // get/set min/max for given step (global over all steps if step=-1)
  virtual double getMin(int step=-1) = 0;
  virtual double getMax(int step=-1) = 0;
  virtual void setMin(double min) = 0;
  virtual void setMax(double max) = 0;

  // get/set the bounding box
  virtual SBoundingBox3d getBoundingBox(int step=-1) = 0;
  virtual void setBoundingBox(SBoundingBox3d& box) = 0;

  // get the number of elements of a given type, for a given step
  virtual int getNumScalars(int step=-1){ return 0; }
  virtual int getNumVectors(int step=-1){ return 0; }
  virtual int getNumTensors(int step=-1){ return 0; }
  virtual int getNumPoints(int step=-1){ return 0; }
  virtual int getNumLines(int step=-1){ return 0; }
  virtual int getNumTriangles(int step=-1){ return 0; }
  virtual int getNumQuadrangles(int step=-1){ return 0; }
  virtual int getNumPolygons(int step=-1){ return 0; }
  virtual int getNumTetrahedra(int step=-1){ return 0; }
  virtual int getNumHexahedra(int step=-1){ return 0; }
  virtual int getNumPrisms(int step=-1){ return 0; }
  virtual int getNumPyramids(int step=-1){ return 0; }
  virtual int getNumPolyhedra(int step=-1){ return 0; }

  // return the number of geometrical entities in the view
  virtual int getNumEntities(int step=-1){ return 0; }

  // return the number of elements in the ent-th entity, or the total
  // number of elements if ent < 0
  virtual int getNumElements(int step=-1, int ent=-1){ return 0; }

  // return the geometrical dimension of the ele-th element in the
  // ent-th entity
  virtual int getDimension(int step, int ent, int ele){ return 0; }

  // return the number of nodes of the ele-th element in the ent-th
  // entity
  virtual int getNumNodes(int step, int ent, int ele){ return 0; }

  // get/set the coordinates and tag of the nod-th node from the
  // ele-th element in the ent-th entity (if the node has a tag,
  // getNode returns it)
  virtual int getNode(int step, int ent, int ele, int nod, 
                      double &x, double &y, double &z){ return 0; }
  virtual void setNode(int step, int ent, int ele, int nod,
                       double x, double y, double z);
  virtual void tagNode(int step, int ent, int ele, int nod, int tag){}

  // return the number of componts available for the ele-th element in
  // the ent-th entity
  virtual int getNumComponents(int step, int ent, int ele){ return 0; }

  // return the number of values available for the ele-th element in
  // the ent-th entity
  virtual int getNumValues(int step, int ent, int ele){ return 0; }

  // get the idx'th value for the ele-th element in the ent-th entity
  virtual void getValue(int step, int ent, int ele, int idx, double &val){}

  // gets/set the comp-th component (at the step-th time step)
  // associated with the node-th node from the ele-th element in the
  // ent-th entity
  virtual void getValue(int step, int ent, int ele, int nod, int comp, double &val){}
  virtual void setValue(int step, int ent, int ele, int nod, int comp, double val);

  double getValueBinding(int step, int ent, int ele, int nod, int comp);
  void getAllValuesForElementBinding(int step, int ent, int ele, fullMatrix<double> &m);
  void getAllNodesForElementBinding(int step, int ent, int ele, fullMatrix<double> &m);

  // return a scalar value (same as value for scalars, norm for
  // vectors, etc.) associated with the node-th node from the ele-th
  // element in the ent-th entity
  void getScalarValue(int step, int ent, int ele, int nod, double &val);

  // return the number of edges of the ele-th element in the ent-th
  // entity
  virtual int getNumEdges(int step, int ent, int ele){ return 0; }

  // return the type of the ele-th element in the ent-th entity
  virtual int getType(int step, int ent, int ele){ return 0; }

  // return the number of 2D/3D strings in the view
  virtual int getNumStrings2D(){ return 0; }
  virtual int getNumStrings3D(){ return 0; }

  // return the i-th 2D/3D string in the view
  virtual void getString2D(int i, int step, std::string &str, 
                           double &x, double &y, double &style){}
  virtual void getString3D(int i, int step, std::string &str, 
                           double &x, double &y, double &z, double &style){}

  // change the orientation of the ele-th element
  virtual void revertElement(int step, int ent, int ele){}

  // check if the view is empty
  virtual bool empty();

  // check if we should skip the given entity/element
  virtual bool skipEntity(int step, int ent){ return false; }
  virtual bool skipElement(int step, int ent, int ele, bool checkVisibility=false,
                           int samplingRate=1);

  // check if the data has the given step/partition/etc.
  virtual bool hasTimeStep(int step){ return step >= 0 && step < getNumTimeSteps(); }
  virtual bool hasPartition(int step, int part){ return false; }
  virtual bool hasMultipleMeshes(){ return false; }
  virtual bool hasModel(GModel *model, int step=-1){ return false; }

  // true if data is given at Gauss points (instead of vertices)
  virtual bool useGaussPoints(){ return false; }

  // check if the view is adaptive
  bool isAdaptive(){ return _adaptive ? true : false; }

  // initialize/destroy adaptive data
  void initAdaptiveData(int step, int level, double tol);
  void destroyAdaptiveData();

  // return the adaptive data
  adaptiveData *getAdaptiveData(){ return _adaptive; }

  // set/get the interpolation matrices for elements with type "type"
  void setInterpolationMatrices(int type, 
                                const fullMatrix<double> &coefVal,
                                const fullMatrix<double> &expVal);
  void setInterpolationMatrices(int type, 
                                const fullMatrix<double> &coefVal,
                                const fullMatrix<double> &expVal,
                                const fullMatrix<double> &coefGeo, 
                                const fullMatrix<double> &expGeo);
  int getInterpolationMatrices(int type, std::vector<fullMatrix<double>*> &p);
  inline bool haveInterpolationMatrices(){ return !_interpolation.empty(); }

  // smooth the data in the view (makes it C0)
  virtual void smooth();

  // combine time steps or elements from multiple datasets
  virtual bool combineTime(nameData &nd);
  virtual bool combineSpace(nameData &nd);
  
  // ask to fill vertex arrays remotely
  virtual bool isRemote(){ return false; }
  virtual int fillRemoteVertexArrays(std::string &options){ return 0; }

  // I/O routines
  virtual bool writeSTL(std::string fileName);
  virtual bool writeTXT(std::string fileName);
  virtual bool writePOS(std::string fileName, bool binary=false, bool parsed=true,
                        bool append=false);
  virtual bool writeMSH(std::string fileName, bool binary=false);
  virtual bool writeMED(std::string fileName);
  //
  virtual MElement *getElement (int step, int entity, int element);
  static void registerBindings(binding *b);
};

class nameData{
 public:
  std::string name;
  std::vector<int> indices;
  std::vector<PViewData*> data;
};

#endif
