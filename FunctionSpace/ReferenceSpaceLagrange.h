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
  unsigned int nNode;
  unsigned int nNodePerEdge;
  unsigned int nNodePerFace;
  unsigned int nNodePerCell;

  std::vector<const std::vector<unsigned int>*>* node;

 public:
  virtual ~ReferenceSpaceLagrange(void);

  const std::vector<const std::vector<unsigned int>*>&
    getAllLagrangeNode(void) const;

  virtual std::string toString(void) const;

 protected:
  ReferenceSpaceLagrange(void);

  void getLagrangeNode(void);

  static void edgeSeq(std::vector<unsigned int>& vec,
                      unsigned int  startIdx,
                      unsigned int  startVal,
                      unsigned int  stopVal,
                      size_t*       refEdge,
                      const std::vector<unsigned int>& edge);

  static void faceSeq(std::vector<unsigned int>& vec,
                      unsigned int  startIdx,
                      unsigned int  startVal,
                      unsigned int  stopVal,
                      size_t*       refFace,
                      const std::vector<unsigned int>& face,
                      unsigned int  nNodePerEdge);
};


/////////////////////
// Inline Function //
/////////////////////

inline
const std::vector<const std::vector<unsigned int>*>&
ReferenceSpaceLagrange::getAllLagrangeNode(void) const{
  return *node;
}

#endif
