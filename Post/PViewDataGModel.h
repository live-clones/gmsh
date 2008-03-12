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
 public:
  // the file the data was read from
  std::string fileName;
  // the index in the file
  int fileIndex;
  // the value of the time step and associated min/max
  double time, min, max;
  // the vector of data, indexed by dataIndex
  std::vector<std::vector<real> > values;
  stepData() : fileIndex(-1), time(0.), min(VAL_INF), max(-VAL_INF){}
  ~stepData() {}
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
