#ifndef _STRUCTURED_BLOCK_
#define _STRUCTURED_BLOCK_
#include <vector>
#include <map>
class MVertex;
class MQuadrangle;
class GFace;
class GEdge;
class GVertex;
class structured_block_2D {
public:
  enum BoundaryType {FIXED, FREE, PERIODIC};
  int ni,nj;
  std::vector<MVertex*> block;
  
  BoundaryType boundaries [4];
  structured_block_2D() : ni(0), nj(0) {}
  void winslow_smooth ();
  bool hyperbolic_smooth();
  
  inline int index(int i,int j) const {return i*nj+j;} //j*ni+i;}

  inline std::pair<int,int> ij(int idx) const {
    return std::make_pair(idx/nj,idx%nj); // idx%ni,idx/ni);
  }
  
protected:
  
  GFace* face; //!< underlying face

  bool periodic;
  
  bool getTopology();
  
};

void computeStructuredBlocks (std::vector<MQuadrangle *> &blquads,
			      std::map<MVertex*,MVertex*> & indices_i,
			      std::map<MVertex*,int> & indices_j,
			      std::vector<structured_block_2D> &blocks);

#endif
