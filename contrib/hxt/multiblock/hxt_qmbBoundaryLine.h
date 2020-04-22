#ifndef HXT_QMBBOUNDARYLINE_H
#define HXT_QMBBOUNDARYLINE_H
#include <vector>
#include "hxt_qmbCorner.h"
#include <array>

class BoundaryLine
{
 public:
  BoundaryLine();
  BoundaryLine(uint64_t isALoop, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles,
	       Corner *pStartingCorner, Corner *pEndingCorner);
  std::vector<std::array<double,3>> getCoord();
  std::vector<uint64_t> getTriangles();
  ~BoundaryLine();
  
 private:
  uint64_t m_isALoop; //0 not a loop, 1 is loop, 2 is loop starting and ending at singularity
  std::vector<std::array<double,3>> m_nodesCoord;
  std::vector<uint64_t> m_triangles;
  Corner *m_pStartingCorner;
  Corner *m_pEndingCorner;
};

#endif
