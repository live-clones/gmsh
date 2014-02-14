#ifndef _REFERENCESPACEMANAGER_H_
#define _REFERENCESPACEMANAGER_H_

#include "ReferenceSpace.h"

#include "LineReferenceSpace.h"
#include "TriReferenceSpace.h"
#include "QuadReferenceSpace.h"
#include "TetReferenceSpace.h"
#include "PyrReferenceSpace.h"
#include "PriReferenceSpace.h"
#include "HexReferenceSpace.h"

/**
   @class ReferenceSpaceManager
   @brief A way to handel ReferenceSpace%s

   This class implements class method to handel and access ReferenceSpace%s.

   This class uses tags to define the geomtrical type of an element.
   These tags are taken from <a href="http://geuz.org/gmsh/">gmsh</a>.

   Finaly, this class will autmoticaly instanciate a ReferenceSpace for a given
   element type, once this type is first met.
   These instance will remain in memory unless a clear method is used.

   @see
   See also the ReferenceSpace documentation
 */

class ReferenceSpaceManager{
 private:
  static const size_t nSpace;
  static std::vector<ReferenceSpace*> refSpace;

 public:
   ReferenceSpaceManager(void);
  ~ReferenceSpaceManager(void);

  static void clear(void);
  static const ReferenceSpace& getReferenceSpace(int elementType);

  static size_t getNVertex(int elementType);
  static size_t getNEdge(int elementType);
  static size_t getNFace(int elementType);

  static size_t getNOrientation(int elementType);
  static size_t getOrientation(const MElement& element);

  static const std::vector<std::vector<std::vector<size_t> > >&
    getEdgeNodeIndex(int elementType);

  static const std::vector<std::vector<std::vector<size_t> > >&
    getFaceNodeIndex(int elementType);

  static const std::vector<size_t>&
    getNodeIndexFromABCtoUVW(const MElement& element);

  static void mapFromABCtoUVW(const MElement& element,
                              double a, double b, double c, double uvw[3]);

  static void mapFromABCtoXYZ(const MElement& element,
                              double a, double b, double c, double xyz[3]);

  static void mapFromUVWtoABC(const MElement& element,
                              double u, double v, double w, double abc[3]);

  static void mapFromXYZtoABC(const MElement& element,
                              double x, double y, double z, double abc[3]);

  static double getJacobian(const MElement& element,
                            double a, double b, double c,
                            fullMatrix<double>& jac);
 private:
  static void init(int elementType);
};

/**
   @fn ReferenceSpaceManager::ReferenceSpaceManager
   Instanciates a new ReferenceSpaceManager
   (not needed since it got only class methods)
   **

   @fn ReferenceSpaceManager::~ReferenceSpaceManager
   Deletes this ReferenceSpaceManager

   It is worth mentioning that @em no ReferenceSpaceManager::clear() calls
   are done.
   **

   @fn ReferenceSpaceManager::clear
   Clears all the ReferenceSpace%s that where instanciated by
   ReferenceSpaceManager

   @see
   See detailed description for how ReferenceSpace%s are instanciated by
   ReferenceSpaceManager
   **

   @fn ReferenceSpaceManager::getReferenceSpace
   @param elementType A geometrical tag
   @return Returns the ReferenceSpace associated to the given tag
   **

   @fn ReferenceSpaceManager::getNVertex
   @param elementType A geometrical tag
   @return Returns the number of topological vertices for the given
   geomtrical tag
   **

   @fn ReferenceSpaceManager::getNEdge
   @param elementType A geometrical tag
   @return Returns the number of topological edges for the given geometrical tag
   **

   @fn ReferenceSpaceManager::getNFace
   @param elementType A geometrical tag
   @return Returns the number of topological faces for the given geometrical tag
   **

   @fn ReferenceSpaceManager::getNOrientation
   @param elementType A geometrical tag
   @return Returns the number of orientation (that is the number of ABC spaces)
   for the given geomtrical tag
   **

   @fn ReferenceSpaceManager::getOrientation
   @param element A MElement
   @return
   Retruns a natural number defining the orientation (that is its ABC space)
   of the given element
   **

   @fn ReferenceSpaceManager::getEdgeNodeIndex
   @param elementType A geometrical tag
   @return Returns every oriented edge node index for the given geomtrical tag

   @li The first vector represents a particular ABC space
   (see ReferenceSpaceManager::getOrientation())
   @li The second vector represents a particular edge (for the given ABC space)
   @li The last vector represents the vertex indexes of the given edge
   **

   @fn ReferenceSpaceManager::getFaceNodeIndex
   @param elementType A geometrical tag
   @return Returns every oriented face node index for the given geomtrical tag

   @li The first vector represents a particular ABC space
   (see ReferenceSpaceManager::getOrientation())
   @li The second vector represents a particular face (for the given ABC space)
   @li The last vector represents the vertex indexes of the given face
   **

   @fn ReferenceSpaceManager::getNodeIndexFromABCtoUVW
   @param element A MElement

   We call ABC[i] the ID of the ith node in the ABC space of the given element.
   We call UVW[i] the ID of the ith node in the UVW space of the given element.

   @return Returns a vector, called map, such that: ABC[i] = UVW[map[i]]

   Note that this is valid, since ABC spaces and UVW space are defined on the
   same domain. The only difference between those spaces is the node indexing.
   **

   @fn ReferenceSpaceManager::mapFromABCtoUVW
   @param element A MElement
   @param a The 'A' coordinate of a point in the ABC space of the given element
   @param b The 'B' coordinate of a point in the ABC space of the given element
   @param c The 'C' coordinate of a point in the ABC space of the given element
   @param uvw A vector in the UVW space of the given element

   Fills the given vector with the coordinates of the
   (a, b, c) point in the UVW space
   **

   @fn ReferenceSpaceManager::mapFromABCtoXYZ
   @param element A MElement
   @param a The 'A' coordinate of a point in the ABC space of the given element
   @param b The 'B' coordinate of a point in the ABC space of the given element
   @param c The 'C' coordinate of a point in the ABC space of the given element
   @param xyz A vector in the XYZ space of the given element

   Fills the given vector with the coordinates of the
   (a, b, c) point in the XYZ space
   **

   @fn ReferenceSpaceManager::mapFromUVWtoABC
   @param element A MElement
   @param u The 'U' coordinate of a point in the UVW space of the given element
   @param v The 'V' coordinate of a point in the UVW space of the given element
   @param w The 'W' coordinate of a point in the UVW space of the given element
   @param abc A vector in the ABC space of the given element

   Fills the given vector with the coordinates of the
   (u, v, w) point in the ABC space
   **

   @fn ReferenceSpaceManager::mapFromXYZtoABC
   @param element A MElement
   @param x The 'X' coordinate of a point in the XYZ space of the given element
   @param y The 'Y' coordinate of a point in the XYZ space of the given element
   @param z The 'Z' coordinate of a point in the XYZ space of the given element
   @param abc A vector in the ABC space of the given element

   Fills the given vector with the coordinates of the
   (x, y, z) point in the ABC space
   **

   @fn ReferenceSpaceManager::getJacobian
   @param element A MElement
   @param a The 'A' coordinate of a point in the ABC space of the given element
   @param b The 'B' coordinate of a point in the ABC space of the given element
   @param c The 'C' coordinate of a point in the ABC space of the given element
   @param jac A 3 by 3 allocated fullMatrix

   Fills the given matrix with the jacobian, evaluated at (a, b, c),
   of the mapping between the ABC space and the XYZ space

   @return Returns the determinant of the jacobian matrix
   **
 */

////////////////////
// Inline Methods //
////////////////////

inline size_t ReferenceSpaceManager::getNVertex(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getNVertex();
}

inline size_t ReferenceSpaceManager::getNEdge(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getNEdge();
}

inline size_t ReferenceSpaceManager::getNFace(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getNFace();
}

inline
const ReferenceSpace& ReferenceSpaceManager::getReferenceSpace(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return *refSpace[elementType];
}

inline
size_t ReferenceSpaceManager::getNOrientation(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getNOrientation();
}

inline
size_t ReferenceSpaceManager::getOrientation(const MElement& element){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getOrientation(element);
}

inline
const std::vector<std::vector<std::vector<size_t> > >&
ReferenceSpaceManager::getEdgeNodeIndex(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getEdgeNodeIndex();
}

inline
const std::vector<std::vector<std::vector<size_t> > >&
ReferenceSpaceManager::getFaceNodeIndex(int elementType){
  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getFaceNodeIndex();
}

inline
const std::vector<size_t>&
ReferenceSpaceManager::getNodeIndexFromABCtoUVW(const MElement& element){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getNodeIndexFromABCtoUVW(element);
}

inline void ReferenceSpaceManager::mapFromABCtoUVW(const MElement& element,
                                                   double a, double b, double c,
                                                   double uvw[3]){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->mapFromABCtoUVW(element, a, b, c, uvw);
}

inline void ReferenceSpaceManager::mapFromABCtoXYZ(const MElement& element,
                                                   double a, double b, double c,
                                                   double xyz[3]){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->mapFromABCtoXYZ(element, a, b, c, xyz);
}

inline void ReferenceSpaceManager::mapFromUVWtoABC(const MElement& element,
                                                   double u, double v, double w,
                                                   double abc[3]){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->mapFromUVWtoABC(element, u, v, w, abc);
}

inline void ReferenceSpaceManager::mapFromXYZtoABC(const MElement& element,
                                                   double x, double y, double z,
                                                   double abc[3]){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->mapFromXYZtoABC(element, x, y, z, abc);
}

inline double ReferenceSpaceManager::getJacobian(const MElement& element,
                                                 double a, double b, double c,
                                                 fullMatrix<double>& jac){
  const int elementType = element.getType();

  if(!refSpace[elementType])
    init(elementType);

  return refSpace[elementType]->getJacobian(element, a, b, c, jac);
}

#endif
