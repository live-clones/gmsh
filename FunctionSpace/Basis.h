#ifndef _BASIS_H_
#define _BASIS_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @interface Basis
   @brief Common Interface of all Basis

   This class is the @em common @em interface for all Basis.@n

   A Basis is @em set of @em linearly @em independent Polynomial%s 
   (or Vector%s of Polynomial%s).@n

   @note
   A Basis is an @em interface, so it @em can't be instanciated
 */

class Basis{
 protected:
  const ReferenceSpace* refSpace;
  unsigned int    nRefSpace;
  bool            scalar;

  unsigned int order;
  unsigned int type;
  unsigned int dim;

  unsigned int nVertex;
  unsigned int nEdge;
  unsigned int nFace;
  unsigned int nCell;

  unsigned int nFunction;

 public:
  //! Deletes this Basis
  //!
  virtual ~Basis(void);

  //! @return Returns the ReferenceSpace of this Basis
  const ReferenceSpace& getReferenceSpace(void) const;

  //! @return Returns:
  //! @li @c true, if this is a 
  //! @em scalar Basis (BasisScalar)
  //! @li @c false, if this is a
  //! @em vectorial Basis (BasisVector)
  //!
  //! @note
  //! Scalar basis are sets of 
  //! Polynomial%s@n
  //! Vectorial basis are sets of 
  //! Vector%s of Polynomial%s  
  bool isScalar(void) const;

  //! @return Returns the @em polynomial @em order of the Basis
  unsigned int getOrder(void) const;

  //! @return Returns the @em type of the Basis:
  //! @li 0 for 0-form
  //! @li 1 for 1-form
  //! @li 2 for 2-form
  //! @li 3 for 3-form
  unsigned int getType(void) const;
  
  //! @return Returns the @em dimension 
  //! (1D, 2D or 3D) of the Basis
  unsigned int getDim(void) const;

  //! @return Returns the number of @em Vertex
  //! @em Based functions of this Basis
  unsigned int getNVertexBased(void) const;

  //! @return Returns the number of @em Edge
  //! @em Based functions of this Basis
  unsigned int getNEdgeBased(void) const;

  //! @return Returns the number of @em Face
  //! @em Based functions of this Basis
  unsigned int getNFaceBased(void) const;

  //! @return Returns the number of @em Cell
  //! @em Based functions of this Basis
  unsigned int getNCellBased(void) const;

  //! @return Returns the number of Polynomial%s 
  //! (or Vector%s of Polynomial%s) Functions 
  //! in this Basis
  unsigned int getNFunction(void) const;

  //! @return Returns the Basis String
  virtual std::string toString(void) const = 0;

 protected:
  //! @internal
  //! Instantiate a new Basis
  //!
  //! @endinternal
  Basis(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline const ReferenceSpace& 
Basis::getReferenceSpace(void) const{
  return *refSpace;
}

inline bool Basis::isScalar(void) const{
  return scalar;
}

inline unsigned int Basis::getOrder(void) const{
  return order;
}

inline unsigned int Basis::getType(void) const{
  return type;
}

inline unsigned int Basis::getDim(void) const{
  return dim;
}

inline unsigned int Basis::getNVertexBased(void) const{
  return nVertex;
}

inline unsigned int Basis::getNEdgeBased(void) const{
  return nEdge;
}

inline unsigned int Basis::getNFaceBased(void) const{
  return nFace;
}

inline unsigned int Basis::getNCellBased(void) const{
  return nCell;
}

inline unsigned int Basis::getNFunction(void) const{
  return nFunction;
}

#endif
