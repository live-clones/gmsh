#ifndef FILE_POLYHEDRA
#define FILE_POLYHEDRA


/**************************************************************************/
/* File:   polyhedra.hh                                                   */
/* Author: Joachim Schoeberl                                              */
/* Date:   19. Mar. 2000                                                  */
/**************************************************************************/

/*

  Polyhedral primitive
  
*/

class Polyhedra : public Primitive
{
  class Face {
  public:
    int pnums[3];
    int planenr;

    Box<3> bbox;
    //    Point<3> center;
    Vec<3> v1, v2;   // edges
    Vec<3> w1, w2;   // pseudo-inverse
    Vec<3> n;        // normal to face
    Vec<3> nn;       // normed normal

    Face () { ; }
    Face (int pi1, int pi2, int pi3, const ARRAY<Point<3> > & points);
  };

  ARRAY<Point<3> > points;
  ARRAY<Face> faces;
  ARRAY<Plane*> planes;

public:
  Polyhedra ();
  virtual ~Polyhedra ();
  static Primitive * CreateDefault ();

  virtual INSOLID_TYPE BoxInSolid (const BoxSphere<3> & box) const;
  virtual INSOLID_TYPE PointInSolid (const Point<3> & p,
				     double eps) const;
  virtual INSOLID_TYPE VecInSolid (const Point<3> & p,
				   const Vec<3> & v,
				   double eps) const;

  virtual int GetNSurfaces() const 
    { return planes.Size(); }
  virtual Surface & GetSurface (int i) 
    { return *planes[i]; }
  virtual const Surface & GetSurface (int i) const
    { return *planes[i]; }

  virtual void GetPrimitiveData (char *& classname, ARRAY<double> & coeffs) const;
  virtual void SetPrimitiveData (ARRAY<double> & coeffs);

  virtual void Reduce (const BoxSphere<3> & box);
  virtual void UnReduce ();

  int AddPoint (const Point<3> & p);
  int AddFace (int pi1, int pi2, int pi3);
  
protected:
  int FaceBoxIntersection (int fnr, const BoxSphere<3> & box) const;
  //  void CalcData();
};

#endif
