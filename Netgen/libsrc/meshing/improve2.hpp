#ifndef FILE_IMPROVE2
#define FILE_IMPROVE2



///
class MeshOptimize2d
{
  int faceindex;
  int improveedges;
  double metricweight;
  int writestatus;

public:
  ///
  MeshOptimize2d ();
  ///
  void ImproveMesh (Mesh & mesh2d);
  void ImproveMeshJacobian (Mesh & mesh2d);
    
  void EdgeSwapping (Mesh & mesh, int usemetric);
  void CombineImprove (Mesh & mesh);

  void GenericImprove (Mesh & mesh);


  void SetFaceIndex (int fi) { faceindex = fi; }
  void SetImproveEdges (int ie) { improveedges = ie; }
  void SetMetricWeight (double mw) { metricweight = mw; }
  void SetWriteStatus (int ws) { writestatus = ws; }

  ///
  virtual void SelectSurfaceOfPoint (const Point3d & p,
				     const PointGeomInfo & gi);
  ///
  virtual void ProjectPoint (INDEX /* surfind */, Point3d & /* p */) const { };
  ///
  virtual void ProjectPoint2 (INDEX /* surfind */, INDEX /* surfind2 */, Point3d & /* p */) const { };
  /// liefert zu einem 3d-Punkt die geominfo (Dreieck) und liefert 1, wenn erfolgreich, 
  /// 0, wenn nicht (Punkt ausserhalb von chart)
  virtual int CalcPointGeomInfo(PointGeomInfo& gi, const Point3d& /*p3*/) const
    { gi.trignum = 1; return 1;};

  virtual int CalcPointGeomInfo(int surfind, PointGeomInfo& gi, const Point3d& p3) const
    { return CalcPointGeomInfo (gi, p3); }

  ///
  virtual void GetNormalVector(INDEX surfind, const Point3d & p, PointGeomInfo & gi, Vec3d & n) const;
  virtual void GetNormalVector(INDEX surfind, const Point3d & p, Vec3d & n) const;

  void CheckMeshApproximation (Mesh & mesh);


  ///
  friend class Opti2SurfaceMinFunction;
  ///
  friend class Opti2EdgeMinFunction;
  ///
  friend double Opti2FunctionValueGrad (const Vector & x, Vector & grad);
  ///
  friend double Opti2EdgeFunctionValueGrad (const Vector & x, Vector & grad);



};


extern void CalcTriangleBadness (double x2, double x3, double y3, 
				 double metricweight,
				 double h, double & badness, 
				 double & g1x, double & g1y);




extern double CalcTriangleBadness (const Point3d & p1, 
				   const Point3d & p2, 
				   const Point3d & p3,
				   double metricweight,
				   double h);

extern double CalcTriangleBadness (const Point3d & p1, 
				   const Point3d & p2, 
				   const Point3d & p3,
				   const Vec3d & n,
				   double metricweight,
				   double h);

#endif


