#ifndef _PVIEW_DATA_GMODEL_H_
#define _PVIEW_DATA_GMODEL_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include "PViewData.h"
#include "PViewDataList.h"
#include "GModel.h"
#include "SBoundingBox3d.h"

template<class real>
class stepData{
 private:
  // the file the data was read from (if empty, refer to PViewData)
  std::string _fileName;
  // the index in the file (if negative, refer to PViewData)
  int _fileIndex;
  // the value of the time step and value min/max
  double _time, _min, _max;
  // the number of components in the data (stepData only contain a
  // single field type!)
  int _numComp;
  // the values, indexed by dataIndex in MVertex or MElement
  std::vector<real*> *_data;
 public:
  stepData(int numComp, std::string fileName="", int fileIndex=-1, double time=0.,
	   double min=VAL_INF, double max=-VAL_INF) 
    : _numComp(numComp), _fileName(fileName), _fileIndex(fileIndex), _time(time), 
      _min(min), _max(max), _data(0)
  {
  }
  ~stepData(){ destroyData(); }
  int getNumComp(){ return _numComp; }
  std::string getFileName(){ return _fileName; }
  void setFileName(std::string name){ _fileName = name; }
  int getFileIndex(){ return _fileIndex; }
  void setFileIndex(int index){ _fileIndex = index; }
  double getTime(){ return _time; }
  void setTime(double time){ _time = time; }
  double getMin(){ return _min; }
  void setMin(double min ){ _min = min; }
  double getMax(){ return _max; }
  void setMax(double max){ _max = max; }
  int getNumData()
  {
    if(!_data) return 0;
    return _data->size();
  }
  void resizeData(int n)
  {  
    if(!_data) _data = new std::vector<real*>(n, (real*)0);
    if(n < _data->size()) _data->resize(n, (real*)0);
  }
  real *getData(int index, bool allocIfNeeded=false)
  {
    if(!_data || index >= _data->size()) resizeData(index + 100); // optimize this
    if(allocIfNeeded && !(*_data)[index]) (*_data)[index] = new real[_numComp];
    return (*_data)[index];
  }
  void destroyData()
  {
    if(_data){
      for(unsigned int i = 0; i < _data->size(); i++)
	if((*_data)[i]) delete [] (*_data)[i];
      delete _data;
      _data = 0;
    }
  }
};

// data container using elements from a GModel
class PViewDataGModel : public PViewData {
 private:
  // a pointer to the underlying model
  GModel *_model;
  // the unrolled list of all geometrical entities in the model
  std::vector<GEntity*> _entities;
  // the node- and element-based data
  std::vector<stepData<double>*> _nodeData, _elementData;
  // the global min/max of the view
  double _min, _max;
  // the bounding box of the view (= model bbox for now)
  SBoundingBox3d _bbox;
  // a set of all "partitions" encountered in the input data
  std::set<int> _partitions;
 public:
  PViewDataGModel(GModel *model);
  ~PViewDataGModel();
  bool finalize();
  int getNumTimeSteps();
  double getTime(int step);
  double getMin(int step=-1);
  double getMax(int step=-1);
  SBoundingBox3d getBoundingBox(){ return _bbox; }
  int getNumEntities();
  int getNumElements(int ent=-1);
  int getDimension(int ent, int ele);
  int getNumNodes(int ent, int ele);
  void getNode(int ent, int ele, int nod, double &x, double &y, double &z);
  int getNumComponents(int ent, int ele, int step);
  void getValue(int ent, int ele, int node, int comp, int step, double &val);
  int getNumEdges(int ent, int ele);
  bool skipEntity(int ent);
  bool skipElement(int ent, int ele, int step);
  bool hasTimeStep(int step);
  bool hasPartition(int part);

  // create old-style list-based dataset from this one
  //PViewDataList *convertToPViewDataList();

  // I/O routines
  bool readMSH(std::string fileName, int fileIndex, FILE *fp, bool binary, 
	       bool swap, int timeStep, double time, int partition, 
	       int numComp, int numNodes);
  bool writeMSH(std::string name, bool binary=false);
};

#endif
