#ifndef _PVIEW_DATA_H_
#define _PVIEW_DATA_H_

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

#include <string>
#include <vector>
#include "SBoundingBox3d.h"

class nameData;

// abstract interface to post-processing view data
class PViewData {
 private:
  // flag to mark that the data is 'dirty' and should not be displayed
  bool _dirty;
  // name of the view
  std::string _name;
  // name of the file the data was loaded from
  std::string _filename;
  // index of the view in the file
  int _fileIndex;
 public:
  enum ElementType {
    Point=1,
    Line=2,
    Triangle=3,
    Quadrangle=4,
    Tetrahedron=5,
    Hexahedron=6,
    Prism=7,
    Pyramid=8
  };
  PViewData();
  virtual ~PViewData(){}
  virtual bool getDirty(){ return _dirty; }
  virtual void setDirty(bool val){ _dirty = val; }
  virtual bool finalize(){ _dirty = false; return true; }
  virtual std::string getName(){ return _name; }
  virtual void setName(std::string val){ _name = val; }
  virtual std::string getFileName(){ return _filename; }
  virtual void setFileName(std::string val){ _filename = val; }
  virtual int getFileIndex(){ return _fileIndex; }
  virtual void setFileIndex(int val){ _fileIndex = val; }
  virtual int getNumTimeSteps() = 0;
  virtual double getTime(int step){ return 0.; }
  virtual double getMin(int step=-1) = 0;
  virtual double getMax(int step=-1) = 0;
  virtual SBoundingBox3d getBoundingBox() = 0;
  virtual int getNumScalars(){ return 0; }
  virtual int getNumVectors(){ return 0; }
  virtual int getNumTensors(){ return 0; }
  virtual int getNumElements(int type=0) = 0;
  virtual int getDimension(int ele) = 0;
  virtual int getEntity(int ele){ return 0; }
  virtual int getNumNodes(int ele) = 0;
  virtual void getNode(int ele, int nod, double &x, double &y, double &z) = 0;
  virtual int getNumComponents(int ele) = 0;
  virtual void getValue(int ele, int node, int comp, int step, double &val) = 0;
  virtual int getNumEdges(int ele) = 0;
  virtual int getNumStrings2D(){ return 0; }
  virtual int getNumStrings3D(){ return 0; }
  virtual void getString2D(int i, int step, std::string &str, 
			   double &x, double &y, double &style){}
  virtual void getString3D(int i, int step, std::string &str, 
			   double &x, double &y, double &z, double &style){}
  virtual bool empty();
  virtual void smooth(){}
  virtual bool combineTime(nameData &nd){ return false; }
  virtual bool combineSpace(nameData &nd){ return false; }
  virtual bool isAdaptive(){ return false; }

  // I/O routines
  virtual bool writePOS(std::string name, bool binary=false, bool parsed=true,
			bool append=false){ return false; }
  virtual bool writeSTL(std::string name){ return false; }
  virtual bool writeTXT(std::string name){ return false; }
  virtual bool writeMSH(std::string name){ return false; }
};

class nameData{
 public:
  std::string name;
  std::vector<int> indices;
  std::vector<PViewData*> data;
};

class nameDataLessThan{
 public:
  bool operator()(const nameData &n1, const nameData &n2) const
  {
    return n1.name < n2.name;
  }
};

#endif
