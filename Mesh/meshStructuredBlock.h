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

  inline int iP(int i) const {return periodic ? (i+1)%(ni-1)         :std::min(i+1,ni-1);}
  inline int iM(int i) const {return periodic ? ((i-1)+(ni-1))%(ni-1):std::max(0,i-1);}
  inline int dI(int i) const {return periodic ? 2 : iP(i) - iM(i);}
  
  inline int idx(int i,int j)         const {return i*nj+j;}
  inline std::pair<int,int> ij(int k) const {return std::make_pair(k/nj,k%nj);}
  
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
