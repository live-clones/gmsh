#ifdef NONE

#ifndef FILE_SPARSMAT
#define FILE_SPARSMAT

/* *************************************************************************/
/* File:   sparsmat.hh                                                    */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Oct. 94                                                    */
/* *************************************************************************/


class SparseMatrix;

/** 
  The graph of a sparse matrix.
  The graph is stored for a non-symmetric matrix
*/
class MatrixGraph
{
  /// data structure for one row of matrix
  struct linestruct 
  { 
    /// allocated size
    int allocsize;    
    /// used size
    int size;    
    /// diag element (always allocated)      
    int diag;  
    /// colume numbers  
    INDEX* col;
  };

  /// graph of matrix
  ARRAY<linestruct> lines;
  /// increment of allocated line-memory on overflow
  int increment;
  
public:
  //@{ @name Constructors, Destructor

  /// Height of matrix, increment value for line-overflow
  MatrixGraph (int size, int aincrement = 5);
  /// Allocates graph with elements per row given in ARRAY linesize
  MatrixGraph (const ARRAY<int> & linesize);
  //@}

  
  /// returns position of Element (i, j), 0 for unused
  int GetPosition (INDEX i, INDEX j) const;

  /// returns position of new element
  int CreatePosition (INDEX i, INDEX j); 

  /// Returns height of matrix
  int Size() const { return lines.Size(); }


  friend class SparseMatrix;
  friend class SparseMatrixFlex;
  friend class SparseMatrixFix;
  friend class PointJacobiPrecond;
};






/**
  Base class for sparse matrix.
  Matrix to work with in most applications
  */
class SparseMatrix : public BaseMatrix
{
protected:
  /// graph of matrix
  const MatrixGraph * graph;
  /// pointer to matrix values in each row
  ARRAY<double*> data;

public:

  /// returns reference, fail save but slow
  virtual double & operator() (INDEX i, INDEX j);
  /// returns value, fail save but slow
  virtual double operator() (INDEX i, INDEX j) const;


  /// prod = matrix x v
  virtual void Mult (const Vector & v, Vector & prod) const;
  /// prod = matrix^T x v
  virtual void MultTrans (const Vector & v, Vector & prod) const;
  /// res = b - mat x x
  virtual void Residuum (const Vector & x, const Vector & b, 
			 Vector & res) const;
  /// res = b - mat^T x x
  virtual void ResiduumTrans (const Vector & x, const Vector & b,
			      Vector & res) const;


  /**
    Add element matrix to sparse matrix.
    The graph of the element-matrix must be symmetric.
    Global point numbers are given in pnum.
   */
  virtual void AddElementMatrix (const ARRAY<INDEX> & pnum, const BaseMatrix & elemmat);

  /// for multigrid-extension, should be removed from here
  void GSStepToInner (const Vector & b, Vector & x, double dump,
      const BitArray & inner) const;

  /// for multigrid-extension, should be removed from here
  void GSStepBackToInner (const Vector & b, Vector & x, double dump,
      const BitArray & inner) const;

  /// 
  virtual ostream & Print (ostream & s) const;

  /** Scalar product of i-th row times vector.
    For symmetric matrices only lower left block 
    (including diagonal) is used.
    */
  double RowTimesVector (INDEX i, const Vector & v) const;
  /** Adds s times the i-th row of matrix to vector v.
    For symmetric matrices only lower left block 
    (including diagonal) is used.
    */
  void AddRowToVector (INDEX i, double s, Vector & v) const;

  /** Number of elements in line.
    For symmetric matrices GetDiagPos must be used for
    most purposes.
    */
  int ElementsInLine (INDEX i) const 
    { return graph->lines.Get(i).size; }

  /** Columne index of nr-th non-zero element in row i */
  INDEX GetColIndex (INDEX i, int nr) const
    { return graph->lines.Get(i).col[nr-1]; }

  /** Referece to columne index of nr-th non-zero 
    element in row i */
  const INDEX & GetColIndexRef (INDEX i, int nr) const
    { return graph->lines.Get(i).col[nr-1]; }

  /** Value of nr-th non-zero element in row i */
  double GetData (INDEX i, int nr) const 
    { return data.Get(i)[nr-1]; }

  /** Reference to value of nr-th non-zero element in row i */
  const double & GetDataRef (INDEX i, int nr) const
    { return data.Get(i)[nr-1]; }

  /** Returns value of diagonal element in row i */
  double GetDiag (INDEX i) const 
    { return data.Get(i)[graph->lines.Get(i).diag-1]; }

  /** Which position has diagonal element in row i ? */
  int GetDiagPos (INDEX i) const
    { return graph->lines.Get(i).diag; }

  /** Returns matrix value of row i, col j.
    For symmetric matrices the indices will be sorted in
    this function */
  double Get(INDEX i, INDEX j) const;

  /** Set value of element (i, j) to v.
    For symmetric matrices element (j, i) is set. */
  void Set(INDEX i, INDEX j, double v);

  /** Returns reference to element (i, j).
    For symmetric matrices a reference to (j, i) is returned */
  double & Elem(INDEX i, INDEX j);

  /** Is element (i, j) used ? */
  char Used (INDEX i, INDEX j) const;

protected:
  /// A sparse matrix must not be constructed
  SparseMatrix (INDEX h, INDEX w = 0);
  /// Allocates matrix position
  virtual int CreatePosition (INDEX i, INDEX j) = 0;

private:
  ///
  friend class ScalarBlockJacobiPrecond;
  friend class PointJacobiPrecond;
};




/** Sparse matrix with flexible graph.
  On demand, a matrix position is allocated */
class SparseMatrixFlex : public SparseMatrix
{ 
 /// non-const pointer to graph.
 MatrixGraph * mygraph;

public:
  ///
  SparseMatrixFlex ();
  ///
  SparseMatrixFlex (INDEX h, INDEX w = 0);
  ///
  SparseMatrixFlex (const SparseMatrix & m2);
  ///
  virtual ~SparseMatrixFlex ();

  /// 
  virtual void SetSize (INDEX h, INDEX w = 0);
  ///
  virtual void SetSymmetric (int sym = 1);
  ///
  virtual void ChangeSize (INDEX h, INDEX w = 0);
  ///
  void DeleteElements ();


  ///
  SparseMatrix & operator= (const SparseMatrix & m2);
  ///
  SparseMatrix & operator*= (double v);


  ///
  virtual BaseMatrix * Copy () const;
  ///
  void Delete (INDEX i, int nr);
  ///
  void DeleteElem (INDEX i, INDEX j);

  ///
  void SetLineAllocSize (INDEX i, int j);

protected:
  ///
  virtual int CreatePosition (INDEX i, INDEX j);

};




/** Sparse matrix with fixed graph.
  After construction of the matrix, the graph
  must not be changed. */
class SparseMatrixFix : public SparseMatrix
{
public:
  ///
  SparseMatrixFix (const MatrixGraph & agraph, int asymmetric = 0);
  ///
  virtual ~SparseMatrixFix ();
  
protected:
  /// CreatePosition is not allowed for SparseMatrixFix -> error
  virtual int CreatePosition (INDEX i, INDEX j);
};


#endif

#endif
