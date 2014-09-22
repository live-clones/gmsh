// TODO: Copyright

#ifndef _MESHOPTOBJCONTRIB_H_
#define _MESHOPTOBJCONTRIB_H_

#include <string>
#include "ap.h"
#include "MeshOptCommon.h"


class Patch;


class ObjContrib
{
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
  virtual bool addContrib(double &Obj, alglib::real_1d_array &gradObj) = 0;
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


#endif /* _MESHOPTOBJCONTRIB_H_ */
