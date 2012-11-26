#ifndef _EVALUATEDBASIS_H_
#define _EVALUATEDBASIS_H_

/**
   @interface EvaluatedBasis
   @brief Common Interface for Evaluated Basis

   This class is the @em common @em interface for all EvaluatedBasis.@n

   An EvaluatedBasis is a @em Basis that has been @em Evaluated at
   some points.@n
 */

class EvaluatedBasis{
 protected:
  bool scalar;

  unsigned int nVertex;
  unsigned int nEdge;
  unsigned int nFace;
  unsigned int nCell;

  unsigned int nEdgeClosure;
  unsigned int nFaceClosure;

  unsigned int nPoint;

 public:
  //! Deletes this EvaluatedBasis
  //!
  virtual ~EvaluatedBasis(void);

  //! @return Returns:
  //! @li @c true, if the evaluated
  //! values are @em scalar  
  //! @li @c false, otherwise  
  bool isScalar(void) const;

  //! @return Returns the number of @em Vertex
  //! @em Based functions of this EvaluatedBasis
  unsigned int getNVertexBased(void) const;

  //! @return Returns the number of @em Edge
  //! @em Based functions of this EvaluatedBasis
  unsigned int getNEdgeBased(void) const;

  //! @return Returns the number of @em Face
  //! @em Based functions of this EvaluatedBasis
  unsigned int getNFaceBased(void) const;

  //! @return Returns the number of @em Cell
  //! @em Based functions of this EvaluatedBasis
  unsigned int getNCellBased(void) const;

  //! @return Returns the number of @em edge
  //! @em closures for this EvaluatedBasis
  unsigned int getNEdgeClosure(void) const;

  //! @return Returns the number of @em face
  //! @em closures for this EvaluatedBasis
  unsigned int getNFaceClosure(void) const;

  //! @return Returns the number of 
  //! evaluation Points
  unsigned int getNPoint(void) const;

 protected:
  //! @internal
  //! Instantiate a new EvaluatedBasis
  //!
  //! @endinternal
  EvaluatedBasis(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline bool EvaluatedBasis::isScalar(void) const{
  return scalar;
}

inline unsigned int EvaluatedBasis::getNVertexBased(void) const{
  return nVertex;
}

inline unsigned int EvaluatedBasis::getNEdgeBased(void) const{
  return nEdge;
}

inline unsigned int EvaluatedBasis::getNFaceBased(void) const{
  return nFace;
}

inline unsigned int EvaluatedBasis::getNCellBased(void) const{
  return nCell;
}

inline unsigned int EvaluatedBasis::getNEdgeClosure(void) const{
  return nEdgeClosure;
}

inline unsigned int EvaluatedBasis::getNFaceClosure(void) const{
  return nFaceClosure;
}

inline unsigned int EvaluatedBasis::getNPoint(void) const{
  return nPoint;
}

#endif
