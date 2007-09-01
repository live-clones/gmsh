#ifndef _PVIEW_DATA_GMODEL_H_
#define _PVIEW_DATA_GMODEL_H_

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

#include "PViewData.h"
#include "PViewDataList.h"
#include "GModel.h"
#include "SBoundingBox3d.h"

// data container using elements from a GModel
class PViewDataGModel : public PViewData {
 private:
  GModel *_model;
  PViewDataList *_cloneToList(); // create old-style data from this
 public:
  PViewDataGModel(){}
  ~PViewDataGModel(){}
  int getNumTimeSteps(){ return 1; }
  double getMin(int step=-1){ return 0.; }
  double getMax(int step=-1){ return 1.; }
  SBoundingBox3d getBoundingBox(){ return SBoundingBox3d(); }
  int getNumElements(){ return _model->numElements(); }
  int getDimension(int ele){ return 0; }
  int getNumNodes(int ele){ return 0; }
  void getNode(int ele, int nod, double &x, double &y, double &z){}
  int getNumComponents(int ele){ return 1; }
  void getValue(int ele, int node, int comp, int step, double &val){}
  int getNumEdges(int ele){ return 0; }
};

#endif
