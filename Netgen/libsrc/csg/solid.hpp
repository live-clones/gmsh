#ifndef FILE_SOLID
#define FILE_SOLID

/**************************************************************************/
/* File:   solid.hh                                                       */
/* Author: Joachim Schoeberl                                              */
/* Date:   1. Dez. 95                                                     */
/**************************************************************************/

/*

  Constructive Solid Model (csg)
  
*/




class Solid;

class SolidIterator
{
public:
  SolidIterator ();
  virtual ~SolidIterator ();
  virtual void Do (Solid * sol) = 0;
};



class Solid
{
public:
  
  typedef enum optyp1 { TERM, SECTION, UNION, SUB, ROOT, DUMMY } optyp;
  
private:
  char * name;
  Primitive * prim;
  Solid * s1, * s2;
  
  optyp op;
  int visited;
  double maxh;

  static int cntnames;

public:
  Solid (Primitive * aprim);
  Solid (optyp aop, Solid * as1, Solid * as2 = NULL);
  virtual ~Solid ();

  const char * Name () const { return name; }
  void SetName (const char * aname);

  Solid * Copy (class CSGeometry & geom) const;
  void Transform (Transformation<3> & trans);

  
  void IterateSolid (SolidIterator & it, int only_once = 0);

  
  void Boundaries (const Point<3> & p, ARRAY<int> & bounds) const;
  int NumPrimitives () const;
  void GetSurfaceIndices (ARRAY<int> & surfind) const;
  void GetSurfaceIndices (IndexSet & iset) const;

  Primitive * GetPrimitive ()
    { return (op == TERM) ? prim : NULL; }
  const Primitive * GetPrimitive () const
    { return (op == TERM) ? prim : NULL; }

  // geometric tests

  int IsIn (const Point<3> & p, double eps = 1e-6) const;
  int IsStrictIn (const Point<3> & p, double eps = 1e-6) const;
  int VectorIn (const Point<3> & p, const Vec<3> & v, double eps = 1e-6) const;
  int VectorStrictIn (const Point<3> & p, const Vec<3> & v, double eps = 1e-6) const;
  
  int VectorIn2 (const Point<3> & p, const Vec<3> & v1, const Vec<3> & v2,
		 double eps = 1e-6) const;
  int VectorIn2Rec (const Point<3> & p, const Vec<3> & v1, const Vec<3> & v2,
		    double eps = 1e-6) const;


  ///
  void TangentialSolid (const Point<3> & p, Solid *& tansol) const;
  ///
  void TangentialSolid2 (const Point<3> & p, const Vec<3> & t,
			 Solid *& tansol) const;
  ///
  int Edge (const Point<3> & p, const Vec<3> & v) const;
  ///
  int OnFace (const Point<3> & p, const Vec<3> & v) const;
  ///
  virtual void Print (ostream & str) const;
  ///
  void CalcSurfaceInverse ();
  ///
  Solid * GetReducedSolid (const BoxSphere<3> & box) const;
  

  void SetMaxH (double amaxh)
    { maxh = amaxh; }
  double GetMaxH () const
    { return maxh; }

  void GetSolidData (ostream & ost, int first = 1) const;
  static Solid * CreateSolid (istream & ist, const SYMBOLTABLE<Solid*> & solids);


  static BlockAllocator ball;
  void * operator new(size_t);
  void operator delete (void *);

protected:
  ///

  void RecBoundaries (const Point<3> & p, ARRAY<int> & bounds, 
		      int & in, int & strin) const;
  ///
  void RecTangentialSolid (const Point<3> & p, Solid *& tansol, 
			   int & in, int & strin) const;
  ///
  void RecTangentialSolid2 (const Point<3> & p, const Vec<3> & vec, 
			    Solid *& tansol, int & in, int & strin) const;
  ///
  void RecEdge (const Point<3> & p, const Vec<3> & v,
                int & in, int & strin, int & faces) const;
  ///
  void CalcSurfaceInverseRec (int inv);
  ///
  Solid * RecGetReducedSolid (const BoxSphere<3> & box, int & in) const;
  ///
  void RecGetSurfaceIndices (ARRAY<int> & surfind) const;
  void RecGetSurfaceIndices (IndexSet & iset) const;

  friend class SolidIterator;
  friend class ClearVisitedIt;
  friend class RemoveDummyIterator;
  friend class CSGeometry;
};


class ReducePrimitiveIterator : public SolidIterator
{
  const BoxSphere<3> & box;
public:
  ReducePrimitiveIterator (const BoxSphere<3> & abox);
  virtual ~ReducePrimitiveIterator ();
  virtual void Do (Solid * sol);  
};


class UnReducePrimitiveIterator : public SolidIterator
{
public:
  UnReducePrimitiveIterator ();
  virtual ~UnReducePrimitiveIterator ();
  virtual void Do (Solid * sol);  
};

#endif
