#ifndef FILE_BASEMAT
#define FILE_BASEMAT

/**************************************************************************/
/* File:   basemat.hh                                                     */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Oct. 94                                                    */
/**************************************************************************/

/* 
   Base type for linear operator
*/

class DenseMatrix;

///
class BaseMatrix
{
protected:
  ///
  INDEX height, width;
  ///
  int symmetric;
  ///
  static double shit;

public:
  ///
  BaseMatrix ();
  ///
  BaseMatrix (INDEX h, INDEX w = 0);
  ///
  virtual ~BaseMatrix () { };

  ///
  INDEX Width () const { return width; }
  ///
  INDEX Height () const { return height; }
  ///
  int Symmetric () const { return symmetric; }

  ///
  virtual void SetSize (INDEX h, INDEX w = 0);
  ///
  virtual void SetSymmetric (int sym = 1);

  ///
  virtual double & operator() (INDEX i, INDEX j);
  ///
  virtual double operator() (INDEX i, INDEX j) const;

  ///
  friend ostream & operator<<(ostream & s, const BaseMatrix & m);
  ///
  virtual ostream & Print (ostream & s) const;

  ///
  TempVector operator* (const BaseVector & v) const;


  ///
  virtual void Mult (const BaseVector & v, BaseVector & prod) const;
  ///
  virtual void MultTrans (const BaseVector & v, BaseVector & prod) const;
  ///
  virtual void Residuum (const BaseVector & x, const BaseVector & b, BaseVector & res) const;
  ///
  virtual void ResiduumTrans (const BaseVector & x, const BaseVector & b, BaseVector & res) const;
  //  virtual double EvaluateBilinearform (const BaseVector & x);

  virtual BaseMatrix * Copy () const;
  ///
  virtual BaseVector * CreateVector () const;

  ///
  virtual void AddElementMatrix (const ARRAY<INDEX> & /* pnum */, 
				 const BaseMatrix & /* elemmat */) { };
  ///
  virtual void MultElementMatrix (const ARRAY<INDEX> & /* pnum */, 
				  const BaseVector & /* x */, BaseVector & /* y */) { };
  ///
  virtual void MultTransElementMatrix (const ARRAY<INDEX> & /* pnum */, 
				       const BaseVector & /* x */, BaseVector & /* y */) { };


  ///
  virtual DenseMatrix * MakeDenseMatrix () const;
  ///
  virtual BaseMatrix * InverseMatrix (const class BitArray * inner = NULL)
    const;

  ///
  virtual void SolveDestroy (const Vector & b, Vector & x);
  ///
  void Solve (const Vector & b, Vector & x) const;
  ///
  virtual Vector SolveDestroyFunc (const Vector & b) const;
  ///
  Vector Solve (const Vector & b) const;
  ///
  virtual void LU_Decomposition (DenseMatrix & l, DenseMatrix & u) const;
};


#endif
