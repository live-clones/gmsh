#ifndef FILE_ALGPRIM
#define FILE_ALGPRIM


/**************************************************************************/
/* File:   algprim.hh                                                     */
/* Author: Joachim Schoeberl                                              */
/* Date:   1. Dez. 95                                                     */
/**************************************************************************/

/*

Quadric Surfaces (Plane, Sphere, Cylinder)
  
*/


/**
   A quadric surface.
   surface defined by
   cxx x^2 + cyy y^2 + czz z^2 + cxy x y + cxz x z + cyz y z +
   cx x + cy y + cz z + c1 = 0.
 **/
class QuadraticSurface : public  OneSurfacePrimitive
{
protected:
  double cxx, cyy, czz, cxy, cxz, cyz, cx, cy, cz, c1;

public:

  virtual double CalcFunctionValue (const Point<3> & point) const;
  virtual void CalcGradient (const Point<3> & point, Vec<3> & grad) const;
  virtual void CalcHesse (const Point<3> & point, Mat<3> & hesse) const;
  /*
  virtual int RootInBox (const Box<3> & box) 
    const { return 0; }
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) 
    const { return DOES_INTERSECT; }
*/
  virtual double HesseNorm () const { return cxx + cyy + czz; }
  virtual Point<3> GetSurfacePoint () const;

  virtual void Print (ostream & ist) const;
  virtual void Read (istream & ist);
  void PrintCoeff (ostream & ost) const;
};


/// A Plane (i.e., the plane and everything behind it).
class Plane : public QuadraticSurface
{
  /// a point in the plane
  Point<3> p;
  /// outward normal vector 
  Vec<3> n;
public:
  ///
  Plane (const Point<3> & ap, Vec<3> an);

  virtual void GetPrimitiveData (char *& classname, 
				 ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);
  static Primitive * CreateDefault ();

  virtual Primitive * Copy () const;
  virtual void Transform (Transformation<3> & trans);


  virtual int IsIdentic (const Surface & s2, int & inv, double eps) const;

  ///
  virtual void DefineTangentialPlane (const Point<3> & ap1, 
				      const Point<3> & ap2);
  ///
  virtual void ToPlane (const Point<3> & p3d, 
			Point<2> & pplane, double h,
			int & zone) const;
  ///
  virtual void FromPlane (const Point<2> & pplane, 
			  Point<3> & p3d, 
			  double h) const;
  ///
  virtual void Project (Point<3> & p) const;

  ///
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;

  ///
  virtual double CalcFunctionValue (const Point<3> & point) const;
  ///
  virtual void CalcGradient (const Point<3> & point, 
			     Vec<3> & grad) const;
  ///
  virtual void CalcHesse (const Point<3> & point, 
			  Mat<3> & hesse) const;
  ///
  virtual double HesseNorm () const;
  ///
  virtual Point<3> GetSurfacePoint () const;
  ///
  virtual void GetTriangleApproximation 
  (TriangleApproximation & tas, 
   const Box<3> & boundingbox, double facets) const;

};

// typedef Plane Plane;


///
class Sphere : public QuadraticSurface
{
  ///
  Point<3> c;
  ///
  double r;
public:
  ///
  Sphere (const Point<3> & ac, double ar);

  virtual void GetPrimitiveData (char *& classname, 
				 ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);
  static Primitive * CreateDefault ();

  virtual Primitive * Copy () const;
  virtual void Transform (Transformation<3> & trans);


  virtual int IsIdentic (const Surface & s2, int & inv, double eps) const;

  ///
  virtual void DefineTangentialPlane (const Point<3> & ap1, 
				      const Point<3> & ap2);
  ///
  virtual void ToPlane (const Point<3> & p3d, 
			Point<2> & pplane, double h,
			int & zone) const;
  ///
  virtual void FromPlane (const Point<2> & pplane, 
			  Point<3> & p, double h) const;
  ///
  virtual void Project (Point<3> & p) const;

  ///
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  ///
  virtual double HesseNorm () const;
  ///
  virtual Point<3> GetSurfacePoint () const;
  ///
  const Point<3> & Center () const { return c; }
  ///
  double Radius () const { return r; }

  ///
  virtual void GetTriangleApproximation (TriangleApproximation & tas, 
					 const Box<3> & bbox, 
					 double facets) const;
};


///
class Cylinder : public QuadraticSurface
{
  ///
  Point<3> a, b;
  ///
  double r;
  ///
  Vec<3> vab;

public:
  Cylinder (const Point<3> & aa, const Point<3> & ab, double ar);

  virtual void GetPrimitiveData (char *& classname, ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);
  static Primitive * CreateDefault ();

  virtual Primitive * Copy () const;
  virtual void Transform (Transformation<3> & trans);

  ///
  virtual int IsIdentic (const Surface & s2, int & inv, double eps) const;
  ///
  virtual void DefineTangentialPlane (const Point<3> & ap1, 
				      const Point<3> & ap2);
  ///
  virtual void ToPlane (const Point<3> & p, 
			Point<2> & pplane, 
			double h,
			int & zone) const;
  ///
  virtual void FromPlane (const Point<2> & pplane, 
			  Point<3> & p, 
			  double h) const;
  ///
  virtual void Project (Point<3> & p) const;

  ///
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  ///
  virtual double HesseNorm () const;
  ///
  virtual Point<3> GetSurfacePoint () const;
  ///
  virtual void GetTriangleApproximation (TriangleApproximation & tas, 
					 const Box<3> & bbox, 
					 double facets) const;
};





///
class EllipticCylinder : public QuadraticSurface
{
private:
  ///
  Point<3> a;
  ///
  Vec<3> vl, vs;
  ///
  Vec<3> vab, t0vec, t1vec;
  ///
  double vabl, t0, t1;
public:
  ///
  EllipticCylinder (const Point<3> & aa,
		    const Vec<3> & avl, const Vec<3> & avs);

  /*
  static Primitive * CreateDefault ();
  virtual void GetPrimitiveData (char *& classname, ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);
  */
  ///
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  ///
  virtual double HesseNorm () const;
  ///
  virtual Point<3> GetSurfacePoint () const;

  virtual void GetTriangleApproximation (TriangleApproximation & tas, 
					 const Box<3> & bbox, 
					 double facets) const;

private:
  void CalcData();
};






///
class Ellipsoid : public QuadraticSurface
{
private:
  ///
  Point<3> a;
  ///
  Vec<3> v1, v2, v3;
  ///
  double rmin;
public:
  ///
  Ellipsoid (const Point<3> & aa,
	     const Vec<3> & av1, 
	     const Vec<3> & av2,
	     const Vec<3> & av3);
  ///
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  ///
  virtual double HesseNorm () const;
  ///
  virtual Point<3> GetSurfacePoint () const;

  virtual void GetTriangleApproximation (TriangleApproximation & tas, 
					 const Box<3> & bbox, 
					 double facets) const;

private:
  void CalcData();
};








///
class Cone : public QuadraticSurface
{
  ///
  Point<3> a, b;
  ///
  double ra, rb, minr;
  ///
  Vec<3> vab, t0vec, t1vec;
  ///
  double vabl, t0, t1;
public:
  ///
  Cone (const Point<3> & aa, const Point<3> & ab, double ara, double arb);
  ///
  static Primitive * CreateDefault ();
  virtual void GetPrimitiveData (char *& classname, ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);

  ///
  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  ///
  virtual double HesseNorm () const;
  ///
  virtual Point<3> GetSurfacePoint () const;

  virtual void GetTriangleApproximation (TriangleApproximation & tas, 
					 const Box<3> & bbox, 
					 double facets) const;

private:
  void CalcData();
};


#endif
