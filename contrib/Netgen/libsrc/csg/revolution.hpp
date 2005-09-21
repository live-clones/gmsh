#ifndef FILE_REVOLUTION
#define FILE_REVOLUTION


/**************************************************************************/
/* File:   revolution.hh                                                  */
/* Author: Joachim Schoeberl                                              */
/* Date:   12. Oct. 2000                                                  */
/**************************************************************************/

/*

  Primitive of revolution
  
*/


#ifdef NONE

class Revolution : public Primitive
{
  Point<3> p1, p2;
  Vec<3> v12;
  Polygon2d polygon;
  ARRAY<Cone*> faces;
  ARRAY<int> invsurf;
public:
  Revolution (const Point<3> & ap1, const Point<3> & ap2);
  ~Revolution ();
  static Primitive * CreateDefault ();

  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  virtual INSOLID_TYPE PointInSolid (const Point<3> & p,
				     double eps) const;
  virtual INSOLID_TYPE VecInSolid (const Point<3> & p,
				   const Vec<3> & v,
				   double eps) const;

  virtual int GetNSurfaces() const 
    { return faces.Size(); }
  virtual Surface & GetSurface (int i) 
    { return *faces.Elem(i); }
  virtual const Surface & GetSurface (int i = 1) const
    { return *faces.Get(i); }

  virtual int SurfaceInverted (int i = 1) const
  { return invsurf.Get(i); }

  virtual void GetPrimitiveData (char *& classname, ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);

  virtual void Reduce (const BoxSphere<3> & box);
  virtual void UnReduce ();

  int AddPoint (const Point<2> & p);
  void Finish ();
protected:
  //  int FaceBoxIntersection (int fnr, const BoxSphere<3> & box) const;
  //  void CalcData();
};


#endif

#endif
