#ifndef FILE_VECTOR
#define FILE_VECTOR

/* *************************************************************************/
/* File:   vector.hh                                                      */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Oct. 94                                                    */
/* *************************************************************************/


class FlatVector
{
protected:
  int s;
  double *data;
public:
  FlatVector () { ; }
  FlatVector (int as, double * adata)
  { s = as; data = adata; }

  int Size () const
  { return s; }

  FlatVector & operator= (const FlatVector & v) 
  { memcpy (data, v.data, s*sizeof(double)); return *this; }

  FlatVector & operator= (double scal) 
  {
    for (int i = 0; i < s; i++) data[i] = scal; 
    return *this;
  }

  double & operator[] (int i) { return data[i]; }
  const double & operator[] (int i) const { return data[i]; }
  double & operator() (int i) { return data[i]; }
  const double & operator() (int i) const { return data[i]; }

  double & Elem (int i) { return data[i-1]; }
  const double & Get (int i) const { return data[i-1]; }
  void Set (int i, double val) { data[i-1] = val; }

  FlatVector & operator*= (double scal)
  {
    for (int i = 0; i < s; i++) data[i] *= scal;
    return *this;
  }

  FlatVector & Add (double scal, const FlatVector & v2)
  {
    for (int i = 0; i < s; i++) 
      data[i] += scal * v2.data[i];
    return *this;
  }

  FlatVector & Set (double scal, const FlatVector & v2)
  {
    for (int i = 0; i < s; i++) 
      data[i] = scal * v2.data[i];
    return *this;
  }

  FlatVector & Set2 (double scal1, const FlatVector & v1,
		 double scal2, const FlatVector & v2)
  {
    for (int i = 0; i < s; i++) 
      data[i] = scal1 * v1.data[i] + scal2 * v2.data[i];
    return *this;
  }
  
  double L2Norm() const
  {
    double sum = 0;
    for (int i = 0; i < s; i++)
      sum += data[i] * data[i];
    return sqrt (sum);
  }

  friend double operator* (const FlatVector & v1, const FlatVector & v2);
};



class Vector : public FlatVector
{

public:
  Vector () 
  { s = 0; data = 0; }
  Vector (int as)
  { s = as; data = new double[s]; }
  ~Vector ()
  { delete [] data; }

  Vector & operator= (const FlatVector & v) 
  { memcpy (data, &v.Get(1), s*sizeof(double)); return *this; }

  Vector & operator= (double scal) 
  {
    for (int i = 0; i < s; i++) data[i] = scal; 
    return *this;
  }

  void SetSize (int as)
  {
    if (s != as)
      {
	s = as;
	delete [] data;
	data = new double [s];
      }
  }

};


inline double operator* (const FlatVector & v1, const FlatVector & v2)
{
  double sum = 0;
  for (int i = 0; i < v1.s; i++)
    sum += v1.data[i] * v2.data[i];
  return sum;
}




inline ostream & operator<< (ostream & ost, const FlatVector & v)
{
  for (int i = 0; i < v.Size(); i++)
    ost << " " << setw(7) << v[i];
  return ost;
}










#ifdef OLDVEC

class TempVector;
class Vector;
class BlockVector;

/** Data types for vectors.
   
   Every Vector data structure is derived from a BaseVector class.
   A BaseVector provides virtual functions for the scalar-vector
   and vector-vector operations. 
   If the return value of a function is a vector, then there should
   be used a TempVector class. This avoids one additional constructor/
   destructor call.
   Finally, a Vector - class contains the data of a Vector in dense
   form.
   
   Vector - Operations:
   
     Vector ( x )       Constructor empty, with given length or 
                        given vector to copy  
                       
     SetLength () 
     ChangeLength()     Change vector-length with/without destroing the vector
     Length()           return vector-length
     
     Copy()             Construct a vector of same type and contents
     
     operator()         Save vector access
     Set, Get, Elem:    Fast vector access for setting, receiving and reference

     +, -, *, =, +=, -=, *=, /=
     			virtual vector operations
                     
     SupNorm, L2Norm, L1Norm, Min, Max
			Vector operations 
			
     Set (s, v), Add (s, v)
     			Fast scalar-vector operations
     			
     Print ()           stream output of a vector

*/

class BaseVector
{
protected:
  ///
  INDEX length;
  ///
  static double shit;
  
public:
  ///
  BaseVector ();
  ///
  BaseVector (INDEX alength);
  ///
  virtual ~BaseVector () { };
  ///
  virtual void SetSize (INDEX asize) { SetLength(asize); }
  ///
  virtual void SetLength (INDEX alength);
  ///
  virtual void ChangeLength (INDEX alength);
  /// Size should be prefered !!!
  INDEX Length () const { return length; }
  /// 
  INDEX Size() const { return length; }

    // NEW RM ---> in BlockVector
    // rtual void SetBlockLength (INDEX blength) = 0;

  ///
  virtual BaseVector & operator= (const BaseVector & /* v2 */) { return *this; }
  ///
  virtual BaseVector & operator= (double /* scal */) { return *this; }

  ///
  virtual double & operator() (INDEX /* i */) { return shit; }
  ///
  virtual double operator() (INDEX /* i */) const { return 0; }

  ///
  virtual double SupNorm () const = 0;
  ///
  virtual double L2Norm () const = 0;
  ///
  virtual double L1Norm () const = 0;
  ///
  virtual double Min () const = 0;
  ///
  virtual double Max () const = 0;

  ///
  virtual BaseVector & operator+= (const BaseVector & v2) = 0;
  ///
  virtual BaseVector & operator-= (const BaseVector & v2) = 0;
  ///
  virtual BaseVector & operator*= (double scal) = 0;
  ///
  virtual BaseVector & operator/= (double scal);

  ///
  virtual TempVector operator+ (const BaseVector & v2) const;
  ///
  virtual TempVector operator- (const BaseVector & v2) const;
  ///
  virtual TempVector operator- () const;
  ///
  virtual double operator* (const BaseVector & v2) const = 0;
  ///
  friend TempVector operator* (const BaseVector & v1, double scal);
  ///
  friend TempVector operator/ (const BaseVector & v1, double scal);
  ///
  friend TempVector operator* (double scal, const BaseVector & v1);

  ///
  virtual BaseVector & Add (double /* scal */, const BaseVector & /* v2 */) { return *this; }
  ///
  virtual BaseVector & Add2 (double /* scal */, const BaseVector & /* v2 */,
                        double /* scal3 */, const BaseVector & /* v3 */) { return *this; }
  ///
  virtual BaseVector & Set (double /* scal */, const BaseVector & /* v2 */) { return *this; }
  ///
  virtual BaseVector & Set2 (double /* scal */, const BaseVector & /* v2 */,
                        double /* scal3 */, const BaseVector & /* v3 */) { return *this; }

    ///
    virtual void SetRandom () { };

    
    ///
    virtual void GetPart (int /* startpos */, 
			  BaseVector & /* v2*/ ) const { };
    ///
    virtual void SetPart (int /* startpos */,  
			  const BaseVector & /* v2 */) { };
    ///
    virtual void AddPart (int /* startpos */, double /* val */, 
			  const BaseVector & /* v2 */) { };

  ///
  virtual void GetElementVector (const ARRAY<INDEX> & pnum,
				 BaseVector & elvec) const;
  ///
  virtual void SetElementVector (const ARRAY<INDEX> & pnum,
				 const BaseVector & elvec);
  ///
  virtual void AddElementVector (const ARRAY<INDEX> & pnum,
				 const BaseVector & elvec);

  ///
  friend ostream & operator<<(ostream & s, const BaseVector & v);
  ///
  virtual ostream & Print (ostream & s) const { return s; }

  ///
  virtual BaseVector * Copy () const;
  /// 
  virtual int IsVector () const { return 0; }
  ///
  virtual int IsBlockVector () const { return 0; }
  ///
  virtual Vector & CastToVector () { return *(Vector*)this; }
  ///
  virtual const Vector & CastToVector () const { return *(Vector*)this; }
  ///
  virtual BlockVector & CastToBlockVector () { return *(BlockVector*)this; }
  ///
  virtual const BlockVector & CastToBlockVector () const { return *(BlockVector*)this; }
  };


///
class TempVector : public BaseVector
{
  ///
  BaseVector * vec;

  public:
  ///
  TempVector (BaseVector & v1) { vec = & v1; }
  ///
  ~TempVector ();
  ///
  virtual Vector & CastToVector ()
      { return vec->CastToVector(); }
  ///
  virtual const Vector & CastToVector () const
      { return vec->CastToVector(); }
  ///
  virtual BlockVector & CastToBlockVector ()
      { return vec->CastToBlockVector(); }
  ///
  virtual const BlockVector & CastToBlockVector () const
      { return vec->CastToBlockVector(); }


  ///
  virtual BaseVector & operator+= (const BaseVector & /* v2 */) { return *this; }
  ///
  virtual BaseVector & operator-= (const BaseVector & /* v2 */) { return *this; }
  ///
  virtual BaseVector & operator*= (double /* scal */) { return *this; }
  ///
  virtual double operator* (const BaseVector & /* v2 */) const { return 0; }

  ///
  virtual double SupNorm () const { return vec->SupNorm(); }
  ///
  virtual double L2Norm () const { return vec->L2Norm(); }
  ///
  virtual double L1Norm () const { return vec->L1Norm(); }
  ///
  virtual double Min () const { return vec->Min(); }
  ///
  virtual double Max () const { return vec->Max(); }

  ///
  virtual void Swap (BaseVector &) { };
  ///
  virtual BaseVector * Copy () const;


  };


///
class Vector : public BaseVector
{
  ///
  double * data;
  ///
  static double shit;
  
public:
  ///
  Vector ();
  ///
  Vector (INDEX alength);
  ///
  Vector (const Vector & v2);
  ///
  virtual ~Vector ();

  ///
  virtual void SetLength (INDEX alength);
  ///
  virtual void ChangeLength (INDEX alength);
  /// NEW RM
  virtual void SetBlockLength (INDEX blength);

  ///
  virtual BaseVector & operator= (const BaseVector & v2);
  ///
  virtual BaseVector & operator= (const Vector & v2);
  ///
  virtual BaseVector & operator= (double scal);

  ///
  double & operator() (INDEX i);
  ///
  double operator() (INDEX i) const;

  ///
  virtual double SupNorm () const;
  ///
  virtual double L2Norm () const;
  ///
  virtual double L1Norm () const;
  ///
  virtual double Min () const;
  ///
  virtual double Max () const;

  ///
  virtual BaseVector & operator+= (const BaseVector & v2);
  ///
  virtual BaseVector & operator-= (const BaseVector & v2);
  ///
  virtual BaseVector & operator*= (double scal);

  ///
  virtual double operator* (const BaseVector & v2) const;


  ///
  virtual BaseVector & Add (double scal, const BaseVector & v2);
  ///
  virtual BaseVector & Add2 (double scal, const BaseVector & v2,
                        double scal3, const BaseVector & v3);
  ///
  virtual BaseVector & Set (double scal, const BaseVector & v2);
  ///
  virtual BaseVector & Set2 (double scal , const BaseVector & v2,
                        double scal3, const BaseVector & v3);

    ///
    virtual void GetPart (int startpos, BaseVector & v2) const;
    ///
    virtual void SetPart (int startpos, const BaseVector & v2);
    ///
    virtual void AddPart (int startpos, double val, const BaseVector & v2);

  ///
  virtual void SetRandom ();

  ///
  virtual ostream & Print (ostream & s) const;
  ///
  virtual BaseVector * Copy () const;
  ///
  virtual void Swap (BaseVector &);

  ///
  const double & Get (INDEX i) const { return data[i-1]; }
  ///
  void Set (INDEX i, double v) { data[i-1] = v; }
  ///
  double & Elem (INDEX i) { return data[i-1]; }

  ///
  virtual int IsVector () const { return 1; }


  ///
  virtual void GetElementVector (const ARRAY<INDEX> & pnum,
				 BaseVector & elvec) const;
  ///
  virtual void SetElementVector (const ARRAY<INDEX> & pnum,
				 const BaseVector & elvec);
  ///
  virtual void AddElementVector (const ARRAY<INDEX> & pnum,
				 const BaseVector & elvec);
  };

#endif

#endif


