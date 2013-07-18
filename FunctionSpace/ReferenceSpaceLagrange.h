#ifndef _REFERENCESPACELAGRANGE_H_
#define _REFERENCESPACELAGRANGE_H_

#include "ReferenceSpace.h"

/**
   @interface ReferenceSpaceLagrange
   @brief Base interface for all Lagrange ReferenceSpace%s

   This class is a particular ReferenceSpace for
   @em Lagrange Basis.@n

   This class adds the notion of Lagrange points and
   their permutations depending on the orientation
   of a MElement.@n

   Lagrange points are ordered in a way such that
   Lagrange function must be taken in that order in order
   to have an oriented basis.@n

   Because the number of Lagrange Points depends on
   the the order of the Lagrange Basis,
   a ReferenceSpaceLagrange shall depend on the order.
 */

class ReferenceSpaceLagrange: public ReferenceSpace{
 protected:
  // Lagrange Node Permutation //
  size_t nNode;
  size_t nNodePerEdge;
  size_t nNodePerFace;
  size_t nNodePerCell;

  std::vector<const std::vector<size_t>*>* node;

 public:
  virtual ~ReferenceSpaceLagrange(void);

  const std::vector<const std::vector<size_t>*>&
    getAllLagrangeNode(void) const;

  virtual std::string toString(void) const;

 protected:
  ReferenceSpaceLagrange(void);

  void getLagrangeNode(void);

  static void edgeSeq(std::vector<size_t>& vec,
                      size_t  startIdx,
                      size_t  startVal,
                      size_t  stopVal,
                      size_t* refEdge,
                      const std::vector<size_t>& edge);

  static void faceSeq(std::vector<size_t>& vec,
                      size_t  startIdx,
                      size_t  startVal,
                      size_t  stopVal,
                      size_t* refFace,
                      const std::vector<size_t>& face,
                      size_t  nNodePerEdge);
};


/////////////////////
// Inline Function //
/////////////////////

inline
const std::vector<const std::vector<size_t>*>&
ReferenceSpaceLagrange::getAllLagrangeNode(void) const{
  return *node;
}

#endif
