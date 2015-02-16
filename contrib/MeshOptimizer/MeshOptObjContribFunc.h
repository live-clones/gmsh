// TODO: Copyright

#ifndef _MESHOPTOBJCONTRIBFUNC_H_
#define _MESHOPTOBJCONTRIBFUNC_H_

#include <string>


class ObjContribFuncSimple
{
protected:
  std::string getNamePrefix() { return ""; }
  void initialize(double vMin, double vMax) {}
  void updateParameters(double vMin, double vMax) {}
  bool targetReached(double vMin, double vMax) { return true; }
  bool stagnated(double vMin, double vMax) { return false; }
  double compute(double v) { return v; }
  double computeDiff(double v) { return 1.; }
};


class ObjContribFuncSimpleTargetMax : public ObjContribFuncSimple
{
public:
  ObjContribFuncSimpleTargetMax();
  void setTarget(double target);

protected:
  static const double STAGTHRESHOLD;                                              // Threshold to consider that measures stagnates
  double _target, _init;
  void updateParameters(double vMin, double vMax);
  bool targetReached(double vMin, double vMax) { return (vMax <= _target); }
  bool stagnated(double vMin, double vMax);
};


class ObjContribFuncBarrier
{
public:
  ObjContribFuncBarrier();
  void setTarget(double target, double opt=1.,
                 double defaultMargin=0.);

protected:
  static const double MARGINCOEFF;                                                // Margin coefficient w.r.t. min. & max. to set barrier
  static const double STAGTHRESHOLD;                                              // Threshold to consider that measures stagnates
  double _opt;                                                                    // Optimal value of measure in barrier function
  double _defaultMargin;                                                          // Default margin value to set barrier w.r.t. of min./max. of measure
  double _barrier, _target;                                                       // Current barrier and target of min./max. of measure
  double _init;                                                                   // Initial value of min./max. of measure
  static double logBarrier(double v, double barrier, double opt);
  static double diffLogBarrier(double v, double barrier, double opt);
};


class ObjContribFuncBarrierMovMin : public ObjContribFuncBarrier
{
protected:
  std::string getNamePrefix() { return "BarrierMovMin"; }
  void initialize(double vMin, double vMax) {}
  void updateParameters(double vMin, double vMax);
  bool targetReached(double vMin, double vMax) { return (vMin >= _target); }
  bool stagnated(double vMin, double vMax);
  double compute(double v);
  double computeDiff(double v);
};


class ObjContribFuncBarrierMovMax : public ObjContribFuncBarrier
{
protected:
  std::string getNamePrefix() { return "BarrierMovMax"; }
  void initialize(double vMin, double vMax) {}
  void updateParameters(double vMin, double vMax);
  bool targetReached(double vMin, double vMax) { return (vMax <= _target); }
  bool stagnated(double vMin, double vMax);
  double compute(double v);
  double computeDiff(double v);
};


class ObjContribFuncBarrierFixMin : public ObjContribFuncBarrier
{
protected:
  std::string getNamePrefix() { return "BarrierFixMin"; }
  void initialize(double vMin, double vMax);
  void updateParameters(double vMin, double vMax) {}
  bool targetReached(double vMin, double vMax) { return (vMin >= _barrier); }
  bool stagnated(double vMin, double vMax) { return false; }
  inline double compute(double v);
  inline double computeDiff(double v);
};


class ObjContribFuncBarrierFixMinMovMax : public ObjContribFuncBarrierMovMax
{
protected:
  std::string getNamePrefix() { return "BarrierFixMinMovMax"; }
  void initialize(double vMin, double vMax);
  inline double compute(double v);
  inline double computeDiff(double v);

protected:
  double _fixedMinBarrier;
};


inline double ObjContribFuncBarrier::logBarrier(double v, double barrier, double opt)
{
  const double l = log((v-barrier) / (opt-barrier));
  const double m = (v - opt);
  return l*l + m*m;
}


inline double ObjContribFuncBarrier::diffLogBarrier(double v, double barrier, double opt)
{
  return 2. * ((v-opt) + log((v-barrier)/(opt-barrier))/(v-barrier));
}


inline double ObjContribFuncBarrierMovMin::compute(double v)
{
  if (v > _barrier) return logBarrier(v, _barrier, _opt);
  else return 1e300;
}


inline double ObjContribFuncBarrierMovMin::computeDiff(double v)
{
  if (v > _barrier) return diffLogBarrier(v, _barrier, _opt);
  else return -1e300;
}


inline double ObjContribFuncBarrierMovMax::compute(double v)
{
  if (v < _barrier) return logBarrier(v, _barrier, _opt);
  else return 1e300;
}


inline double ObjContribFuncBarrierMovMax::computeDiff(double v)
{
  if (v < _barrier) return diffLogBarrier(v, _barrier, _opt);
  else return 1e300;
}


inline double ObjContribFuncBarrierFixMin::compute(double v)
{
  if (v > _barrier) return logBarrier(v, _barrier, _opt);
  else return 1e300;
}


inline double ObjContribFuncBarrierFixMin::computeDiff(double v)
{
  if (v > _barrier) return diffLogBarrier(v, _barrier, _opt);
  else return -1e300;
}


inline double ObjContribFuncBarrierFixMinMovMax::compute(double v)
{
  double obj;
  if (v < _barrier) obj = logBarrier(v, _barrier, _opt);
  else return 1e300;
  if (v > _fixedMinBarrier) {
    obj += logBarrier(v, _fixedMinBarrier, _opt);
    return obj;
  }
  else return 1e300;
}


inline double ObjContribFuncBarrierFixMinMovMax::computeDiff(double v)
{
  double dobj;
  if (v < _barrier) dobj = diffLogBarrier(v, _barrier, _opt);
  else return 1e300;
  if (v > _fixedMinBarrier) {
    dobj += diffLogBarrier(v, _fixedMinBarrier, _opt);
    return dobj;
  }
  else return -1e300;
}


#endif /* _MESHOPTOBJCONTRIBFUNC_H_ */
