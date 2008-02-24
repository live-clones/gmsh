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

// data container using elements from a GModel
class PViewDataGModel : public PViewData {
 private:
  GModel *_model;
  PViewDataList *_cloneToList(); // create old-style data from this
 public:
  PViewDataGModel(GModel *model);
  ~PViewDataGModel();
  int getNumTimeSteps(){ return 1; }
  double getTime(int step);
  double getMin(int step=-1);
  double getMax(int step=-1);
  SBoundingBox3d getBoundingBox(){ return _model->bounds(); }
  int getNumEntities();
  int getNumElements(int ent=-1);
  int getDimension(int ent, int ele);
  int getNumNodes(int ent, int ele);
  void getNode(int ent, int ele, int nod, double &x, double &y, double &z);
  int getNumComponents(int ent, int ele);
  void getValue(int ent, int ele, int node, int comp, int step, double &val);
  int getNumEdges(int ent, int ele);
  bool skipEntity(int ent);
  bool skipElement(int ent, int ele);

  // I/O routines
  bool readMSH(FILE *fp);
  bool writePOS(std::string name, bool binary=false, bool parsed=true,
		bool append=false);
  bool writeSTL(std::string name);
  bool writeTXT(std::string name);
  bool writeMSH(std::string name);
};

#endif
