#ifndef FILE_TRANSFORM3D
#define FILE_TRANSFORM3D

/* *************************************************************************/
/* File:   transform3d.hh                                                  */
/* Author: Joachim Schoeberl                                               */
/* Date:   22. Mar. 98                                                     */
/* *************************************************************************/

/*
  Affine - Linear mapping in 3D space
 */

class Transformation3d;
ostream & operator<< (ostream & ost, Transformation3d & trans);

class Transformation3d
{
  double lin[3][3];
  double offset[3];
public:
  ///
  Transformation3d ();
  /// Unit tet is mapped to tet descibed by pp
  Transformation3d (const Point3d ** pp);
  /// Unit tet is mapped to tet descibed by pp
  Transformation3d (const Point3d pp[]);
  /// translation
  Transformation3d (const Vec3d & translate);
  /// rotation with ...
  Transformation3d (const Point3d & c, double alpha, double beta, double gamma);
  /// 
  void CalcInverse (Transformation3d & inv) const;
  /// this = ta x tb
  void Combine (const Transformation3d & ta, const Transformation3d & tb);
  /// dir = 1..3 (== x..z)
  void SetAxisRotation (int dir, double alpha);
  ///
  void Transform (const Point3d & from, Point3d & to) const
    {
      for (int i = 1; i <= 3; i++)
	{
	  to.X(i) = offset[i-1] + lin[i-1][0] * from.X(1) + 
	    lin[i-1][1] * from.X(2) + lin[i-1][2] * from.X(3);
	}
    }
  /// transform vector, apply only linear part, not offset
  void Transform (const Vec3d & from, Vec3d & to) const
    {
      for (int i = 1; i <= 3; i++)
	{
	  to.X(i) = lin[i-1][0] * from.X(1) + 
	    lin[i-1][1] * from.X(2) + lin[i-1][2] * from.X(3);
	}
    }
  friend ostream & operator<< (ostream & ost, Transformation3d & trans);
};














template <int D>
class Transformation
{
  Mat<D> m;
  Vec<D> v;
public:
  ///
  Transformation () { m = 0; v = 0; }

  /// Unit tet is mapped to tet descibed by pp
  Transformation (const Point<D> * pp);

  /// translation
  Transformation (const Vec<D> & translate)
  {
    v = translate;
    m = 0;
    for (int i = 0; i < D; i++)
      m(i,i) = 1;
  }

  // rotation with ...
  Transformation (const Point<D> & c, double alpha, double beta, double gamma)
  {
    ;
  }

  /// 
  void CalcInverse (Transformation & inv) const;

  /// this = ta x tb
  void Combine (const Transformation & ta, const Transformation & tb)
  {
    v = ta.v + ta.m * tb.v;
    m = ta.m * tb.m;
  }

  /// dir = 1..3 (== x..z)
  void SetAxisRotation (int dir, double alpha);

  ///
  void Transform (const Point<D> & from, Point<D> & to) const
  {
    to = Point<D> (v + m * Vec<D>(from));
  }

  /// transform vector, apply only linear part, not offset
  void Transform (const Vec<D> & from, Vec<D> & to) const
  {
    to = m * from;
  }
};

template <int D>
ostream & operator<< (ostream & ost, Transformation<D> & trans);




#endif
