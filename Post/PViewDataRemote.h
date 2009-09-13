// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PVIEW_DATA_REMOTE_H_
#define _PVIEW_DATA_REMOTE_H_

#include <vector>
#include <string>
#include "PViewData.h"
#include "SBoundingBox3d.h"

// The container for a remote dataset (does not contain any actual
// data!)
class PViewDataRemote : public PViewData {
 private: 
  int _numTimeSteps;
  double _min, _max;
  std::vector<double> _timeStepMin, _timeStepMax;
  SBoundingBox3d _bbox;
  std::vector<double> _time;
 public:
  PViewDataRemote() : _numTimeSteps(1), _min(0.), _max(2.2)
  {
    _bbox += SPoint3(-1, -1, -1);
    _bbox += SPoint3(1, 1, 1);
  }
  ~PViewDataRemote(){}
  bool finalize(){}
  int getNumTimeSteps(){ return _numTimeSteps; }
  double getMin(int step=-1){ return _min; }
  double getMax(int step=-1){ return _max; }
  SBoundingBox3d getBoundingBox(int step=-1){ return _bbox; }
};

#endif
