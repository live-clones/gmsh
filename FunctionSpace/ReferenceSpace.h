#ifndef _REFERENCESPACE_H_
#define _REFERENCESPACE_H_

#include <vector>
#include <list>
#include <string>

class ReferenceSpace{
 protected:
  // Permuation Tree Structure //
  struct node_s{
    unsigned int  depth;    // Depth
    unsigned int* last;     // Last           Choises
    unsigned int  number;   // Number of Next Choise
    unsigned int* possible; // Possible  Next Choise
    node_s*       next;     // Next           Choise
  };

  typedef node_s node;

  // Permutation (Tree + Leaf) //
  unsigned int   nVertex;
  unsigned int   nPerm;
  unsigned int** perm;
  node pTreeRoot;

  mutable std::list<unsigned int*>* lPerm;

  // Edge Permutation //
  unsigned int    nEdge;
  unsigned int**  refEdge;
  std::vector<const std::vector<const std::vector<unsigned int>*>*>* edge;

  // Face Permutation //
  unsigned int    nFace;
  unsigned int**  refFace;
  std::vector<const std::vector<const std::vector<unsigned int>*>*>* face;

 public:
  virtual ~ReferenceSpace(void);

  unsigned int getNReferenceSpace(void) const;
  
  std::vector<const std::vector<const std::vector<unsigned int>*>*>&
    getAllEdge(void) const;
  
  std::vector<const std::vector<const std::vector<unsigned int>*>*>&
    getAllFace(void) const ;

  std::string toString(void) const;

 protected:
  ReferenceSpace(void);

  void init(void);
  void generate(node* pTreeRoot);
  void destroy(node* node);
  
  void getEdge(void);
  void getFace(void);

  const std::vector<unsigned int>* inOrder(unsigned int permutation, 
					   unsigned int a, 
					   unsigned int b);

  const std::vector<unsigned int>* inOrder(unsigned int permutation, 
					   unsigned int a, 
					   unsigned int b,
					   unsigned int c);

  std::string toString(const node* node) const;
};

//////////////////////
// Inline Functions //
//////////////////////

inline 
unsigned int 
ReferenceSpace::getNReferenceSpace(void) const{
  return nPerm;
}
  
inline 
std::vector<const std::vector<const std::vector<unsigned int>*>*>&
ReferenceSpace::getAllEdge(void) const{
  return *edge;
}

inline
std::vector<const std::vector<const std::vector<unsigned int>*>*>&
ReferenceSpace::getAllFace(void) const{
  return *face;
}

#endif
