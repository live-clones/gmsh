#ifndef FILE_EXTRUSION
#define FILE_EXTRUSION

/**************************************************************************/
/* File:   extrusion.hpp                                                  */
/* Author: Joachim Schoeberl                                              */
/* Date:   17. Mar. 2003                                                  */
/**************************************************************************/

/*

extrusion of 2D curve
  
*/


class ExtrusionSurface : public Surface
{
protected:
  BSplineCurve2d * curve;
  int segnr;
  Point<3> p0;
  Vec<3> ex, ey;
public:
  ExtrusionSurface (const Point<3> & ap0,
		    const Vec<3> & aex, 
		    const Vec<3> & aey,
		    BSplineCurve2d * acurve,
		    int asegnr);
  virtual ~ExtrusionSurface ();

  virtual void DefineTangentialPlane (const Point<3> & ap1, 
				      const Point<3> & ap2);

  virtual void ToPlane (const Point<3> & p3d, Point<2> & pplane, 
			double h, int & zone) const;
  
  virtual void FromPlane (const Point<2> & pplane, 
			  Point<3> & p3d, double h) const;
  

  virtual void Project (Point<3> & p) const;


  virtual double CalcFunctionValue (const Point<3> & point) const;

  virtual void CalcGradient (const Point<3> & point, Vec<3> & grad) const;

  virtual Point<3> GetSurfacePoint () const;

  virtual double HesseNorm () const;

  virtual void Print (ostream & str) const;  
  virtual void GetTriangleApproximation (TriangleApproximation & tas, 
					 const Box<3> & boundingbox, 
					 double facets) const;
};


class Extrusion : public Primitive
{
protected:
  Point<3> p0;
  Vec<3> ex, ey;
  BSplineCurve2d curve;
  ARRAY<ExtrusionSurface*> surfs;

public:
  Extrusion (const Point<3> & ap0,
	     const Vec<3> & aex, 
	     const Vec<3> & aey,
	     const ARRAY< Point<2> > & points);
  virtual ~Extrusion ();
  
  

  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  virtual INSOLID_TYPE PointInSolid (const Point<3> & p,
				     double eps) const;
  virtual INSOLID_TYPE VecInSolid (const Point<3> & p,
				   const Vec<3> & v,
				   double eps) const;

  virtual int GetNSurfaces() const { return surfs.Size(); }
  virtual Surface & GetSurface (int i) { return *surfs[i]; }
  virtual const Surface & GetSurface (int i) const { return *surfs[i]; }
};

#endif
