#ifndef BISECT
#define BISECT

class BisectionOptions
{
public:
  const char * outfilename;
  const char * mlfilename;
  const char * refinementfilename;
  const char * femcode;
  int maxlevel;
  int usemarkedelements;
  bool refine_hp;
  BisectionOptions ();
};

class ZRefinementOptions
{
public:
  int minref;
  ZRefinementOptions();
};


/*
extern void BisectTets (Mesh &, const CSGeometry *,
			BisectionOptions & opt);
*/

extern void BisectTetsCopyMesh (Mesh &, const class CSGeometry *,
				BisectionOptions & opt);

extern void ZRefinement (Mesh &, const CSGeometry *,
			 ZRefinementOptions & opt);





class Refinement
{
public:
  Refinement ();
  virtual ~Refinement ();
  
  void Refine (Mesh & mesh, int levels);
  void Bisect (Mesh & mesh, class BisectionOptions & opt);
  void MakeSecondOrder (Mesh & mesh);

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


  void ValidateSecondOrder (Mesh & mesh);
  void ValidateRefinedMesh (Mesh & mesh, 
			    ARRAY<INDEX_2> & parents);

};

#endif
