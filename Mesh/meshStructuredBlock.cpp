#include <set>
#include "meshStructuredBlock.h"
#include "MVertex.h"
#include "MQuadrangle.h"

struct vertexNeigh {
  MVertex *_n[4];
  MVertex* _v;
  quadNeigh (MVertex *v) : _v(v){
    _n[0] = _n[1] = _n[2] = _n[3] = nullptr;
  }
};

void computeStructuredBlocks (const std::vector<MQuadrangle *> &blquads,
			      const std::map<MVertex*,MVertex*> & indices_i,
			      const std::map<MVertex*,int> & indices_j,
			      std::vector<structured_block_2D> &blocks){
  std::set<MQuadrangle*> touched;
  for (auto q : blquads){
    std::set<MQuadrangle*>::iterator it = touched.find(q);
    
    
  }
  
}
