#ifndef _BASIS_H_
#define _BASIS_H_

/**
   @class Basis
   @brief Mother class of all Basis

   This class is the @em mother (by @em inheritence) of all Basis.@n

   A Basis is @em set of @em linearly @em independent Polynomial%s 
   (or Vector%s of Polynomial%s).@n
 */

class Basis{
 protected:
  bool scalar;

  int order;
  int type;
  int size;
  int nodeNbr;
  int dim;

 public:
  //! Deletes this Basis
  //!
  virtual ~Basis(void);

  //! @return Returns the @em polynomial @em order of the Basis
  int getOrder(void) const;

  //! @return Returns the @em type of the Basis:
  //! @li 0 for 0-form
  //! @li 1 for 1-form
  //! @li 2 for 2-form
  //! @li 3 for 3-form
  //! @todo Check if the 'form numbering' is good
  int getType(void) const;
  
  //! @return Returns the number of Polynomial%s 
  //! (or Vector%s of Polynomial%s) in the Basis
  int getSize(void) const;

  //! @return Returns the node number of 
  //! the @em geometric @em reference @em element
  int getNodeNbr(void) const;

  //! @return Returns the @em dimension 
  //! (1D, 2D or 3D) of the Basis
  int getDim(void) const;

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

 protected:
  //! Instantiate a new Basis
  //! @warning Users can't instantiate a Basis
  Basis(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline int Basis::getOrder(void) const{
  return order;
}

inline int Basis::getType(void) const{
  return type;
}

inline int Basis::getSize(void) const{
  return size;
}

inline int Basis::getNodeNbr(void) const{
  return nodeNbr;
}

inline int Basis::getDim(void) const{
  return dim;
}

inline bool Basis::isScalar(void) const{
  return scalar;
}

#endif
