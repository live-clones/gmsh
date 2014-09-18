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
  bool stagnated(double vMin, double vMax) { return false; };
  double compute(double v) { return v; }
  double computeDiff(double v) { return 1.; }
};


class ObjContribFuncBarrier
{
public:
  ObjContribFuncBarrier();
  void setTarget(double target, double opt=1.);

protected:
  static const double BLOWUPVAL = 1.e300, DIFFBLOWUPVAL = 1.e300;                 // Big values to set when function should be infinite
  static const double LOWMARGINMULT = 0.9, UPMARGINMULT = 1.1;                    // Upper and lower margins w.r.t. min. & max. to set barrier
  static const double STAGTHRESHOLD = 0.01;                                       // Threshold to consider that measures stagnates
  double _opt;                                                                    // Optimal value of measure in barrier function
  double _barrier, _target, _init;                                                // Current barrier, target and initial values of min./max. of measure
  static double logBarrier(double v, double barrier, double opt);
  static double diffLogBarrier(double v, double barrier, double opt);
};


class ObjContribFuncBarrierMin : public ObjContribFuncBarrier
{
protected:
  std::string getNamePrefix() { return "BarrierMin"; }
  void initialize(double vMin, double vMax) {}
  void updateParameters(double vMin, double vMax);
  bool targetReached(double vMin, double vMax) { return (vMin >= _target); }
  bool stagnated(double vMin, double vMax);
  double compute(double v);
  double computeDiff(double v);
};


class ObjContribFuncBarrierMax : public ObjContribFuncBarrier
{
protected:
  std::string getNamePrefix() { return "BarrierMax"; }
  void initialize(double vMin, double vMax) {}
  void updateParameters(double vMin, double vMax);
  bool targetReached(double vMin, double vMax) { return (vMax <= _target); }
  bool stagnated(double vMin, double vMax);
  double compute(double v);
  double computeDiff(double v);
};


class ObjContribFuncBarrierMinMax : public ObjContribFuncBarrierMax
{
protected:
  std::string getNamePrefix() { return "BarrierMinMax"; }
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


inline double ObjContribFuncBarrierMin::compute(double v)
{
  if (v > _barrier) return logBarrier(v, _barrier, _opt);
  else return BLOWUPVAL;
}


inline double ObjContribFuncBarrierMin::computeDiff(double v)
{
  if (v > _barrier) return diffLogBarrier(v, _barrier, _opt);
  else return -DIFFBLOWUPVAL;
}


inline double ObjContribFuncBarrierMax::compute(double v)
{
  if (v < _barrier) return logBarrier(v, _barrier, _opt);
  else return BLOWUPVAL;
}


inline double ObjContribFuncBarrierMax::computeDiff(double v)
{
  if (v < _barrier) return diffLogBarrier(v, _barrier, _opt);
  else return DIFFBLOWUPVAL;
}


inline double ObjContribFuncBarrierMinMax::compute(double v)
{
  double obj;
  if (v < _barrier) obj = logBarrier(v, _barrier, _opt);
  else return BLOWUPVAL;
  if (v > _fixedMinBarrier) {
    obj += logBarrier(v, _fixedMinBarrier, _opt);
    return obj;
  }
  else return BLOWUPVAL;
}


inline double ObjContribFuncBarrierMinMax::computeDiff(double v)
{
  double dobj;
  if (v < _barrier) dobj = diffLogBarrier(v, _barrier, _opt);
  else return DIFFBLOWUPVAL;
  if (v > _fixedMinBarrier) {
    dobj += diffLogBarrier(v, _fixedMinBarrier, _opt);
    return dobj;
  }
  else return -DIFFBLOWUPVAL;
}



#endif /* _MESHOPTOBJCONTRIBFUNC_H_ */
