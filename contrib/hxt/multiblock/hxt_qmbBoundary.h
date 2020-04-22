#ifndef HXT_QMBBOUNDARY_H
#define HXT_QMBBOUNDARY_H

#include <vector>
#include "hxt_qmbBoundaryLine.h"
#include "hxt_qmbCorner.h"

class Boundary
{
 public:
  Boundary();
  Boundary(std::vector<Corner> vectCorners, std::vector<BoundaryLine> vectBoundaryLines);
  ~Boundary();
 
  
 private:
  std::vector<Corner> m_Corners;
  std::vector<BoundaryLine> m_BoundaryLines;
  
};

#endif
