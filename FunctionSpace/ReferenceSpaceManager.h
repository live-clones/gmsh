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
   @biref A way to handel ReferenceSpace%s

   This class implements class method to handel and access ReferenceSpace%s
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
