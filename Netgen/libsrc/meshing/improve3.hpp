#ifndef FILE_IMPROVE3
#define FILE_IMPROVE3




///
class MeshOptimize3d
{
public:
  void CombineImprove (Mesh & mesh, OPTIMIZEGOAL goal = OPT_QUALITY);
  void SplitImprove (Mesh & mesh, OPTIMIZEGOAL goal = OPT_QUALITY);
  void SwapImprove (Mesh & mesh, OPTIMIZEGOAL goal = OPT_QUALITY);
  void SwapImprove2 (Mesh & mesh, OPTIMIZEGOAL goal = OPT_QUALITY);
};



extern double CalcBad (const Mesh::T_POINTS & points, const Element & elem,
		       double h);

extern double CalcTotalBad (const Mesh::T_POINTS & points, 
			    const Mesh::T_VOLELEMENTS & elements);

extern int WrongOrientation (const Mesh::T_POINTS & points, const Element & el);


/* Functional depending of inner point inside triangular surface */



class PointFunction1 : public MinFunction
{
  Mesh::T_POINTS & points;
  const ARRAY<INDEX_3> & faces;
  double h;
public:
  PointFunction1 (Mesh::T_POINTS & apoints, 
		  const ARRAY<INDEX_3> & afaces,
		  double ah);
  
  virtual double Func (const Vector & x) const;
  virtual double FuncDeriv (const Vector & x, const Vector & dir, double & deriv) const;
  virtual double FuncGrad (const Vector & x, Vector & g) const;
  virtual double GradStopping (const Vector & x) const;
};



#endif
