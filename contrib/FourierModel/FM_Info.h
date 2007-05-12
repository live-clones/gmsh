#ifndef _FM_INFO_H_
#define _FM_INFO_H_

#include <complex>
#include <vector>

class PatchInfo {
 public:
  char type[16];
  char projection[16];
  int tag;
  int nModes[2];
  int periodic[2];
  double normal[3];
  double origin[3];
  double tangent[3];
  double scale[2];
  std::vector<std::vector<std::complex<double> > > coeff;

  PatchInfo() {}
  virtual ~PatchInfo() {}
};

class IntersectionInfo {
 public:
  int tag;
  double SP[3];
  double EP[3];
  struct {
    int patchTag;
  } intersectingPatches[2];
  int edgeNumber;
  
  IntersectionInfo() : tag(-1), edgeNumber(-1) {}
  virtual ~IntersectionInfo() {}
};

#endif
