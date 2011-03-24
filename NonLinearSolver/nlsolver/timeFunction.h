//
// C++ Interface: terms
//
// Description: Derivate class of SimpleFunction to include a time dependency
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef TIMEFUNCTION_H_
#define TIMEFUNCTION_H_
#include "simpleFunction.h"
template<class scalar>
class simpleFunctionTime : public simpleFunction<scalar>{
  protected :
    double time;
    bool timeDependency;
  public :
    simpleFunctionTime(scalar val=0, bool td=true, double t=1.) : simpleFunction<scalar>(val), time(t), timeDependency(td){}; // time=1 by default to avoid set time for Static linear Scheme
    ~simpleFunctionTime(){};
#ifndef SWIG
    virtual scalar operator () (double x, double y, double z) const { if(timeDependency) return time*this->_val; else return this->_val;}
    void setTime(const double t){time=t;}
    void scaleVal(const double fac){this->_val*=fac;}
#endif
};
#ifndef SWIG
template<class scalar>
class simpleFunctionTimeWithConstant : public simpleFunctionTime<scalar>{
  protected:
    scalar _b;
  public:
    simpleFunctionTimeWithConstant(scalar val=0, bool td=true, double t=1.,scalar b=0.) : simpleFunctionTime<scalar>(val,td,t), _b(b){};
    ~simpleFunctionTimeWithConstant(){};
    virtual scalar operator () (double x, double y, double z) const { if(this->timeDependency) return this->time*this->_val+_b; else return this->_val;}

};
#endif
class powerDecreasingFunctionTime : public simpleFunctionTime<double>{
 protected:
// _val = p0  const double p0; // minimal pressure
  const double _p1; // maximal pressure
  const double _a;  // power exponent
  const double _t0; // if t < t0 p = p0
  const double _t1; // if t0 < t < t1 p = p0 + (p1-p0)*(t-t0)/(t1-t0)
  const double _tf; // if t1 < t < tf p = (p1-p0)*(tf-t1)^-a*(tf-t)^a + p0
 public:
  powerDecreasingFunctionTime(double p0, const double p1, const double a, const double t0,
                              const double t1, const double tf) : simpleFunctionTime<double>(p0,true,1.),
                                                                     _p1(p1), _a(a), _t0(t0), _t1(t1), _tf(tf){}
  ~powerDecreasingFunctionTime(){}
  virtual double operator () (double x, double y, double z) const{
    double p0 = _val;
    if((_t0<time) and(time<_t1))
      return p0 + (_p1-p0)*(time-_t0)/(_t1-_t0);
    else if ((_t1<time) and (time<_tf))
      return (_p1-p0)*pow(_tf-_t1,-_a)*pow(_tf-time,_a)+p0;
    else
      return p0;
  }
//  void setTime(const double t){time=t;}
/*  static void registerBindings(binding *b){
    classBinding *cb = b->addClass<powerDecreasingFunctionTime>("powerDecreasingTime");
    cb->setDescription("Function power decreasing in time. Three parts: First one t<t0 value=cste=p0 , Second part t0<t<t1 value= (p1-p0)*(t-t0)/(t1-t0)+p0 Third part value = (p1-p0)*(tf-t1)^-a*(tf-t)^a+p0");
    methodBinding *cm;
    cm = cb->setConstructor<powerDecreasingFunctionTime,double,double,double,double,double,double>();
    cm->setArgNames("p0","p1","a","t0","t1","tf",NULL);
    cm->setDescription("power decresing law. See class description to see how it has to be used");

    // use to validate
//    cm = cb->addMethod("setTime", &powerDecreasingFunctionTime::setTime);
//    cm->setArgNames("t",NULL);
//    cm->setDescription("set time t");
//    cm = cb->addMethod("get", &powerDecreasingFunctionTime::operator());
//    cm->setArgNames("x","y","z",NULL);
//    cm->setDescription("get value");
  }
*/
};
#endif // TIMEFUNCTION

