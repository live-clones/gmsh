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
  PViewDataRemote(double min, double max, double time, SBoundingBox3d bbox)
    : _numTimeSteps(1), _min(min), _max(max), _bbox(bbox)
  {
    _time.push_back(time);
  }
  ~PViewDataRemote(){}
  bool finalize(){ return false;}
  int getNumTimeSteps(){ return _numTimeSteps; }
  double getMin(int step=-1){ return _min; }
  double getMax(int step=-1){ return _max; }
  SBoundingBox3d getBoundingBox(int step=-1){ return _bbox; }
  double getTime(int step)
  {
    if(step >= 0 && step < (int)_time.size()) return _time[step];
    return 0.; 
  }
  int getNumElements(int step=-1, int ent=-1)
  { 
    // hack so that it does not retrn 0
    return -1; 
  }
  
  void setMin(double min){ _min = min; }
  void setMax(double max){ _min = max; }
  void setBoundingBox(SBoundingBox3d bbox){ _bbox = bbox; }
  void setTime(int step, double time)
  {
    if(step >= (int)_time.size()) _time.resize(step + 1);
    _time[step] = time;
  }
};

#endif
