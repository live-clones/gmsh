#ifndef FILE_MESHSTLSURF
#define FILE_MESHSTLSURF

/* *************************************************************************/
/* File:   meshstlsurf.hpp                                                 */
/* Author: Johannes Gerstmayr, Joachim Schoeberl                           */
/* Date:   01. Aug. 99                                                     */
/* *************************************************************************/

/*

The interface between mesh generation and stl geometry

*/


/// 
class MeshingSTLSurface : public Meshing2
{
  ///
  STLGeometry & geom;
  ///
  int transformationtrig;
public:
  ///
  MeshingSTLSurface (STLGeometry & ageom);

protected:
  ///
  virtual void DefineTransformation (Point3d & p1, Point3d & p2,
				     const PointGeomInfo * geominfo1,
				     const PointGeomInfo * geominfo2);
  ///
  virtual void TransformToPlain (const Point3d & locpoint, const MultiPointGeomInfo & geominfo,
      Point2d & plainpoint, double h, int & zone);
  ///
  virtual int TransformFromPlain (Point2d & plainpoint,
				  Point3d & locpoint, 
				  PointGeomInfo & gi,
				  double h);
  ///
  virtual int BelongsToActiveChart (const Point3d & p, 
				    const PointGeomInfo & gi);

  ///
  virtual int ComputePointGeomInfo (const Point3d & p, PointGeomInfo & gi);
  ///
  virtual int ChooseChartPointGeomInfo (const MultiPointGeomInfo & mpgi, 
					 PointGeomInfo & pgi);

  ///
  virtual int IsLineVertexOnChart (const Point3d & p1, const Point3d & p2,
				   int endpoint, const PointGeomInfo & gi);

  virtual void GetChartBoundary (ARRAY<Point2d > & points, 
				 ARRAY<Point3d > & poitns3d,
				 ARRAY<INDEX_2> & lines, double h) const;

  ///
  virtual double CalcLocalH (const Point3d & p, double gh) const;

  ///
  virtual double Area () const;
};



///
class MeshOptimizeSTLSurface : public MeshOptimize2d
  {
  ///
    STLGeometry & geom;

public:
    ///
    MeshOptimizeSTLSurface (STLGeometry & ageom); 
   
    ///
    virtual void SelectSurfaceOfPoint (const Point3d & p,
				       const PointGeomInfo & gi);
    ///
    virtual void ProjectPoint (INDEX surfind, Point3d & p) const;
    ///
    virtual void ProjectPoint2 (INDEX surfind, INDEX surfind2, Point3d & p) const;
    ///
    virtual int CalcPointGeomInfo(PointGeomInfo& gi, const Point3d& p3) const;
    ///
    virtual void GetNormalVector(INDEX surfind, const Point3d & p, Vec3d & n) const;
};




class RefinementSTLGeometry : public Refinement
{
  const STLGeometry & geom;

public:
  RefinementSTLGeometry (const STLGeometry & ageom);
  virtual ~RefinementSTLGeometry ();
  
  virtual void PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
			     int surfi, 
			     const PointGeomInfo & gi1, 
			     const PointGeomInfo & gi2,
			     Point3d & newp, PointGeomInfo & newgi);

  virtual void PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
			     int surfi1, int surfi2, 
			     const EdgePointGeomInfo & ap1, 
			     const EdgePointGeomInfo & ap2,
			     Point3d & newp, EdgePointGeomInfo & newgi);

  virtual void ProjectToSurface (Point<3> & p, int surfi);
};



#endif

