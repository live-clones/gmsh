#ifndef _BASIS_H_
#define _BASIS_H_

#include <string>

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
  bool scalar;

  int order;
  int type;
  int dim;

  int nVertex;
  int nEdge;
  int nFace;
  int nCell;

  int nEdgeClosure;
  int nFaceClosure;

  int size;

 public:
  //! Deletes this Basis
  //!
  virtual ~Basis(void);

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
  int getOrder(void) const;

  //! @return Returns the @em type of the Basis:
  //! @li 0 for 0-form
  //! @li 1 for 1-form
  //! @li 2 for 2-form
  //! @li 3 for 3-form
  int getType(void) const;
  
  //! @return Returns the @em dimension 
  //! (2D or 3D) of the Basis
  int getDim(void) const;

  //! @return Returns the number of @em Vertex
  //! @em Based functions of this Basis
  int getNVertexBased(void) const;

  //! @return Returns the number of @em Edge
  //! @em Based functions of this Basis
  int getNEdgeBased(void) const;

  //! @return Returns the number of @em Face
  //! @em Based functions of this Basis
  int getNFaceBased(void) const;

  //! @return Returns the number of @em Cell
  //! @em Based functions of this Basis
  int getNCellBased(void) const;

  //! @return Returns the number of @em edge
  //! @em closures for this Basis
  int getNEdgeClosure(void) const;

  //! @return Returns the number of @em face
  //! @em closures for this Basis
  int getNFaceClosure(void) const;

  //! @return Returns the number of Polynomial%s 
  //! (or Vector%s of Polynomial%s) in the Basis
  int getSize(void) const;

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

inline bool Basis::isScalar(void) const{
  return scalar;
}

inline int Basis::getOrder(void) const{
  return order;
}

inline int Basis::getType(void) const{
  return type;
}

inline int Basis::getDim(void) const{
  return dim;
}

inline int Basis::getNVertexBased(void) const{
  return nVertex;
}

inline int Basis::getNEdgeBased(void) const{
  return nEdge;
}

inline int Basis::getNFaceBased(void) const{
  return nFace;
}

inline int Basis::getNCellBased(void) const{
  return nCell;
}

inline int Basis::getNEdgeClosure(void) const{
  return nEdgeClosure;
}

inline int Basis::getNFaceClosure(void) const{
  return nFaceClosure;
}

inline int Basis::getSize(void) const{
  return size;
}

#endif
