#include "hxt_qmbBoundary.h"
#include "hxt_qmbBoundaryLine.h"
#include "hxt_qmbCorner.h"
#include <vector>

Boundary::Boundary()
{
}

Boundary::Boundary(std::vector<Corner> vectCorners, std::vector<BoundaryLine> vectBoundaryLines)
{
  for (uint64_t i=0; i<vectCorners.size(); i++)
    m_Corners.push_back(vectCorners[i]);
  for (uint64_t i=0; i<vectBoundaryLines.size(); i++)
    m_BoundaryLines.push_back(vectBoundaryLines[i]);
}

Boundary::~Boundary()
{

}
