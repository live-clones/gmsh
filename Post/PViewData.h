#ifndef _PVIEW_DATA_H_
#define _PVIEW_DATA_H_

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

#include <string>
#include <vector>
#include "SBoundingBox3d.h"

#define VAL_INF 1.e200

class GModel;
class nameData;

// abstract interface to post-processing view data
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
 public:
  PViewData();
  virtual ~PViewData(){}
  virtual bool getDirty(){ return _dirty; }
  virtual void setDirty(bool val){ _dirty = val; }
  virtual bool finalize(){ _dirty = false; return true; }
  virtual std::string getName(){ return _name; }
  virtual void setName(std::string val){ _name = val; }
  virtual std::string getFileName(){ return _fileName; }
  virtual void setFileName(std::string val){ _fileName = val; }
  virtual int getFileIndex(){ return _fileIndex; }
  virtual void setFileIndex(int val){ _fileIndex = val; }
  virtual int getNumTimeSteps() = 0;
  virtual double getTime(int step){ return 0.; }
  virtual double getMin(int step=-1) = 0;
  virtual double getMax(int step=-1) = 0;
  virtual SBoundingBox3d getBoundingBox(int step=-1) = 0;
  virtual int getNumScalars(int step=-1){ return 0; }
  virtual int getNumVectors(int step=-1){ return 0; }
  virtual int getNumTensors(int step=-1){ return 0; }
  virtual int getNumPoints(int step=-1){ return 0; }
  virtual int getNumLines(int step=-1){ return 0; }
  virtual int getNumTriangles(int step=-1){ return 0; }
  virtual int getNumQuadrangles(int step=-1){ return 0; }
  virtual int getNumTetrahedra(int step=-1){ return 0; }
  virtual int getNumHexahedra(int step=-1){ return 0; }
  virtual int getNumPrisms(int step=-1){ return 0; }
  virtual int getNumPyramids(int step=-1){ return 0; }
  // Returns the number of geometrical entities in the view
  virtual int getNumEntities(int step=-1) = 0;
  // Returns the number of elements in the ent-th entity, or the total
  // number of elements if ent < 0
  virtual int getNumElements(int step=-1, int ent=-1) = 0;
  // Returns the geometrical dimension of the ele-th element in the
  // ent-th entity
  virtual int getDimension(int step, int ent, int ele) = 0;
  // Returns the number of nodes of the ele-th element in the ent-th
  // entity
  virtual int getNumNodes(int step, int ent, int ele) = 0;
  // Gets/Sets the coordinates and tag of the nod-th node from the
  // ele-th element in the ent-th entity (if the node has a tag,
  // getNode returns it)
  virtual int getNode(int step, int ent, int ele, int nod, 
		      double &x, double &y, double &z) = 0;
  virtual void setNode(int step, int ent, int ele, int nod,
		       double x, double y, double z);
  virtual void tagNode(int step, int ent, int ele, int nod, int tag){}
  // Returns the number of componts available for the ele-th element
  // in the ent-th entity
  virtual int getNumComponents(int step, int ent, int ele) = 0;
  // Gets/sets the comp-th component (at the step-th time step)
  // associated with the node-th node from the ele-th element in the
  // ent-th entity
  virtual void getValue(int step, int ent, int ele, int nod, int comp, double &val) = 0;
  virtual void setValue(int step, int ent, int ele, int nod, int comp, double val);
  // Returns a scalar value (same as value for scalars, norm for
  // vectors, etc.) associated with the node-th node from the ele-th
  // element in the ent-th entity
  virtual void getScalarValue(int step, int ent, int ele, int nod, double &val);
  // Returns the number of edges of the ele-th element in the ent-th
  // entity
  virtual int getNumEdges(int step, int ent, int ele) = 0;
  virtual int getNumStrings2D(){ return 0; }
  virtual int getNumStrings3D(){ return 0; }
  virtual void getString2D(int i, int step, std::string &str, 
                           double &x, double &y, double &style){}
  virtual void getString3D(int i, int step, std::string &str, 
                           double &x, double &y, double &z, double &style){}
  virtual void revertElement(int step, int ent, int ele){}
  virtual bool empty();
  virtual void smooth(){}
  virtual bool combineTime(nameData &nd){ return false; }
  virtual bool combineSpace(nameData &nd){ return false; }
  virtual bool isAdaptive(){ return false; }
  virtual bool skipEntity(int step, int ent){ return false; }
  virtual bool skipElement(int step, int ent, int ele,
			   bool checkVisibility=false){ return false; }
  virtual bool hasTimeStep(int step){ return step < getNumTimeSteps(); }
  virtual bool hasPartition(int part){ return false; }
  virtual bool hasMultipleMeshes(){ return false; }
  virtual bool hasModel(GModel *model, int step=-1){ return false; }
  virtual bool useGaussPoints(){ return false; }

  // I/O routines
  virtual bool writeSTL(std::string fileName);
  virtual bool writeTXT(std::string fileName);
  virtual bool writePOS(std::string fileName, bool binary=false, bool parsed=true,
                        bool append=false);
  virtual bool writeMSH(std::string fileName, bool binary=false);
  virtual bool writeMED(std::string fileName);
};

class nameData{
 public:
  std::string name;
  std::vector<int> indices;
  std::vector<PViewData*> data;
};

#endif
