// MeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#ifndef OBJ_CONTRIB_H
#define OBJ_CONTRIB_H

#include <vector>
#include <string>
#include "MeshOptCommon.h"

class Patch;

class ObjContrib {
public:
  ObjContrib(std::string mesName, std::string name);
  virtual ~ObjContrib() {}
  virtual ObjContrib *copy() const = 0;
  const double getMin() { return _min; }
  const double getMax() { return _max; }
  const std::string &getName() const { return _name; }
  const std::string &getMeasureName() const { return _measureName; }
  virtual void initialize(Patch *mesh) = 0;
  virtual bool fail() = 0;
  virtual bool addContrib(double &Obj, std::vector<double> &gradObj) = 0;
  virtual void updateParameters() = 0;
  virtual bool targetReached() = 0;
  virtual bool stagnated() = 0;
  virtual void updateMinMax() = 0;
  void updateResults();

protected:
  static const double BIGVAL;
  ObjContrib *_parent;
  std::string _measureName, _name;
  double _min, _max;
};

#endif
