#ifndef FILE_SOLDATA
#define FILE_SOLDATA



class SolutionData
{
protected:
  std::string name;
  int components;
  bool iscomplex;

  // int dist;
  // int order;
public:
  SolutionData (const std::string & aname, 
		int acomponents = 1, bool aiscomplex = 0)
    : name(aname), components(acomponents), iscomplex(aiscomplex)
  { ; }

  virtual ~SolutionData ()
  { ; }

  int GetComponents() { return components; }
  bool IsComplex() { return iscomplex; }

  virtual bool GetValue (int elnr, 
			 double lam1, double lam2, double lam3,
			 double * values) 
  { return 0; }

  virtual bool GetSurfValue (int selnr,
			     double lam1, double lam2, 
			     double * values)
  { return 0; }

};


#endif

