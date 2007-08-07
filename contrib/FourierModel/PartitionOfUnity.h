#ifndef _PARTITION_OF_UNITY_H_
#define _PARTITION_OF_UNITY_H_

#include <cmath>

namespace FM {

inline double OneSidedPartitionOfUnity(double t0,
				       double t1,
				       double t)
{
  if (t <= t0) {
    return 1.;
  }
  else if (t >= t1) {
    return 0.;
  } 
  else {
    double x = (t - t0) / (t1 - t0);
    return exp(2.560851702 * exp(-1. / x) / (x - 1.));
  }
}

inline double OneSidedPartitionOfUnityDt(double t0,
					 double t1,
					 double t)
{
  if (t <= t0) {
    return 0.;
  }
  else if (t >= t1) {
    return 0.;
  } 
  else {
    // From Maple
    return (0.2560851702e1 * pow(t - t0, -0.2e1) * (t1 - t0) * 
	    exp(-0.10e1 / (t - t0) * (t1 - t0)) / ((t - t0) / (t1 - t0) - 0.10e1) - 
	    0.2560851702e1 * exp(-0.10e1 / (t - t0) * (t1 - t0)) * 
	    pow((t - t0) / (t1 - t0) - 0.10e1, -0.2e1) / (t1 - t0)) * 
      exp(0.2560851702e1 * exp(-0.10e1 / (t - t0) * (t1 - t0)) / 
	  ((t - t0) / (t1 - t0) - 0.10e1));
  }
}

inline double OneSidedPartitionOfUnityDtDt(double t0,
					   double t1,
					   double t)
{
  if (t <= t0) {
    return 0.;
  }
  else if (t >= t1) {
    return 0.;
  } 
  else {
    // From Maple
    return ((-0.5121703404E1/pow(-t0+t,3.0)*(t1-t0)*exp(-0.1E1/(-t0+t)*(t1-t0))/
	     ((-t0+t)/(t1-t0)-0.1E1)+0.2560851702E1/pow(-t0+t,4.0)*pow(t1-t0,2.0)*
	     exp(-0.1E1/(-t0+t)*(t1-t0))/((-t0+t)/(t1-t0)-0.1E1)-0.5121703404E1/pow(-t0+t,2.0)*
	     exp(-0.1E1/(-t0+t)*(t1-t0))/pow((-t0+t)/(t1-t0)-0.1E1,2.0)+0.5121703404E1*
	     exp(-0.1E1/(-t0+t)*(t1-t0))/pow((-t0+t)/(t1-t0)-0.1E1,3.0)/pow(t1-t0,2.0))*
	    exp(0.2560851702E1*exp(-0.1E1/(-t0+t)*(t1-t0))/((-t0+t)/(t1-t0)-0.1E1))+
	    pow(0.2560851702E1/pow(-t0+t,2.0)*(t1-t0)*
		exp(-0.1E1/(-t0+t)*(t1-t0))/((-t0+t)/(t1-t0)-0.1E1)-0.2560851702E1*
		exp(-0.1E1/(-t0+t)*(t1-t0))/pow((-t0+t)/(t1-t0)-0.1E1,2.0)/(t1-t0),2.0)*
	    exp(0.2560851702E1*exp(-0.1E1/(-t0+t)*(t1-t0))/((-t0+t)/(t1-t0)-0.1E1)));
  }
}

// and we get the two sided POU by multiplying two One sided POUs
inline double PartitionOfUnityInternalCall(double r,
					   double start1, double end1,
					   double end2, double start2)
{
  double leftPart = 1. - OneSidedPartitionOfUnity(start1, end1, r);
  double rightPart = OneSidedPartitionOfUnity(end2, start2, r);
  return leftPart * rightPart;
}

// and we get derivative of the the two sided POU by adding two One sided POUs
inline double PartitionOfUnityDtInternalCall(double r,
					     double start1, double end1,
					     double end2, double start2)
{
  double leftPart = 1. - OneSidedPartitionOfUnity(start1, end1, r);
  double rightPart = OneSidedPartitionOfUnity(end2, start2, r);
  double leftPartDt = OneSidedPartitionOfUnityDt(start1, end1, r);
  double rightPartDt = OneSidedPartitionOfUnityDt(end2, start2, r);
  return leftPart * rightPartDt - rightPart * leftPartDt;
}

// and we get derivative of the the two sided POU by adding two One sided POUs
inline double PartitionOfUnityDtDtInternalCall(double r,
					       double start1, double end1,
					       double end2, double start2)
{
  double leftPart = 1. - OneSidedPartitionOfUnity(start1, end1, r);
  double rightPart = OneSidedPartitionOfUnity(end2, start2, r);
  double leftPartDt = OneSidedPartitionOfUnityDt(start1, end1, r);
  double rightPartDt = OneSidedPartitionOfUnityDt(end2, start2, r);
  double leftPartDtDt = OneSidedPartitionOfUnityDtDt(start1, end1, r);
  double rightPartDtDt = OneSidedPartitionOfUnityDtDt(end2, start2, r);

  return leftPartDt * rightPartDt + leftPart * rightPartDtDt -
    (rightPartDt * leftPartDt + rightPart * leftPartDtDt);
}

// Compute the value of a two sided partition of unity
inline double PartitionOfUnity(double r,
			       double start1, double end1,
			       double end2, double start2)
{
  if(r < start1 || r > start2) { return 0.; }
  if(r > end1 && r < end2) { return 1.; }
  return PartitionOfUnityInternalCall(r, start1, end1, end2, start2);
}

// Compute the derivative of a two sided partition of unity
inline double PartitionOfUnityDt(double r,
				 double start1, double end1,
				 double end2, double start2)
{
  if(r < start1 || r > start2) { return 0.; }
  if(r > end1 && r < end2) { return 0.; }
  return PartitionOfUnityDtInternalCall(r, start1, end1, end2, start2);
}

// Compute the second derivative of a two sided partition of unity
inline double PartitionOfUnityDtDt(double r,
				   double start1, double end1,
				   double end2, double start2)
{
  if(r < start1 || r > start2) { return 0.; }
  if(r > end1 && r < end2) { return 0.; }
  return PartitionOfUnityDtDtInternalCall(r, start1, end1, end2, start2);
}

}

#endif
