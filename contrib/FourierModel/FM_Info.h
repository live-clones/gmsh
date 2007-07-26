#ifndef _FM_INFO_H_
#define _FM_INFO_H_

#include <complex>
#include <vector>

class PatchInfo {
 public:
  char type[16];
  int tag;
  int projectionSurfaceTag;
  int nM[2];
  int nModes[2];
  int periodic[2];
  double uMin, uMax, vMin, vMax;
  int hardEdge[4];
  std::vector<std::vector<std::complex<double> > > coeff;

  PatchInfo();
  virtual ~PatchInfo() {}
};

class OverlapInfo {
 public:
  short int doesIntersect;
  int psTag;
  double xMin, xMax;
  double yMin, yMax;
  double zMin, zMax;

  OverlapInfo();
  virtual ~OverlapInfo() {}
};

class IntersectionInfo {
 public:
  int tag;
  double SP[3];
  double EP[3];
  struct {
    int patchTag;
  } intersectingPatches[2];
  int along;
  struct {
    int edgeType;
    double constValue;
    double startValue;
    double endValue;
    bool acrossDiscontinuity;
  } edgeInfo;
  
  IntersectionInfo();
  virtual ~IntersectionInfo() {}
};

#endif
