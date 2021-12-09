#ifndef _STRUCTURED_BLOCK_
#define _STRUCTURED_BLOCK_
#include <vector>
#include <map>
class MVertex;
class MQuadrangle;
class structured_block_2D {
  int ni,nj;
  std::vector<MVertex*> block;
 public:
  structured_block_2D() : ni(0), nj(0) {}
  void winslow_smooth ();
  void hyperbolic_smooth();
};

void computeStructuredBlocks (const std::vector<MQuadrangle *> &blquads,
			      const std::map<MVertex*,MVertex*> & indices_i,
			      const std::map<MVertex*,int> & indices_j,
			      std::vector<structured_block_2D> &blocks);

#endif
