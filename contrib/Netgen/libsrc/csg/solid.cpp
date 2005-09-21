#include <mystdlib.h>

#include <linalg.hpp>
#include <csg.hpp>


namespace netgen
{
  using namespace netgen;


  /*
  SolidIterator :: SolidIterator ()
  {
    ;
  }

  SolidIterator :: ~SolidIterator ()
  {
    ;
  }
  */



  // int Solid :: cntnames = 0;
  
  Solid :: Solid (Primitive * aprim)
  {
    op = TERM;
    prim = aprim;
    s1 = s2 = NULL;
    maxh = 1e10;
    name = NULL;   
  }

  Solid :: Solid (optyp aop, Solid * as1, Solid * as2)
  {
    op = aop;
    s1 = as1;
    s2 = as2;
    prim = NULL;
    name = NULL;
    maxh = 1e10;
  }

  Solid :: ~Solid ()
  {
    // cout << "delete solid, op = " << int(op) << endl;
    delete [] name;

    switch (op)
      {
      case UNION:
      case SECTION:
	{
	  if (s1->op != ROOT) delete s1;
	  if (s2->op != ROOT) delete s2;
	  break;
	}
      case SUB:
	// case ROOT:
	{
	  if (s1->op != ROOT) delete s1;
	  break;
	}
      case TERM:
	{
	  // cout << "has term" << endl;
	  delete prim;
	  break;
	}
      default:
	break;
      }
  }

  void Solid :: SetName (const char * aname)
  {
    delete [] name;
    name = new char[strlen (aname)+1];
    strcpy (name, aname);
  }


  Solid * Solid :: Copy (CSGeometry & geom) const
  {
    Solid * nsol;
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  Primitive * nprim = prim->Copy();
	  geom.AddSurfaces (nprim);
	  nsol = new Solid (nprim);
	  break;
	}

      case SECTION:
      case UNION:
	{
	  nsol = new Solid (op, s1->Copy(geom), s2->Copy(geom));
	  break;
	}

      case SUB:
	{
	  nsol = new Solid (SUB, s1 -> Copy (geom));
	  break;
	}
      
      case ROOT:
	{
	  nsol = s1->Copy(geom);
	  break;
	}
      }

    return nsol;
  }

 
  void Solid :: Transform (Transformation<3> & trans)
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  prim -> Transform (trans);
	  break;
	}
      case SECTION:
      case UNION:
	{
	  s1 -> Transform (trans);
	  s2 -> Transform (trans);
	  break;
	}

      case SUB:
      case ROOT:
	{
	  s1 -> Transform (trans);
	  break;
	}
      }  
  }



  void Solid :: IterateSolid (SolidIterator & it,
			      bool only_once)
  {
    if (only_once)
      {
	if (visited)
	  return;

	visited = 1; 
      }

    it.Do (this);

    switch (op)
      {
      case SECTION:
	{
	  s1->IterateSolid (it, only_once);
	  s2->IterateSolid (it, only_once);
	  break;
	}
      case UNION:
	{
	  s1->IterateSolid (it, only_once);
	  s2->IterateSolid (it, only_once);
	  break;
	}
      case SUB:
      case ROOT:
	{
	  s1->IterateSolid (it, only_once);
	  break;
	}
      } 
  }




  bool Solid :: IsIn (const Point<3> & p, double eps) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  INSOLID_TYPE ist = prim->PointInSolid (p, eps);
	  return ( (ist == IS_INSIDE) || (ist == DOES_INTERSECT) ) ? 1 : 0;
	}
      case SECTION:
	return s1->IsIn (p, eps) && s2->IsIn (p, eps);
      case UNION:
	return s1->IsIn (p, eps) || s2->IsIn (p, eps);
      case SUB:
	return !s1->IsStrictIn (p, eps);
      case ROOT:
	return s1->IsIn (p, eps);
      }
    return 0;
  }

  bool Solid :: IsStrictIn (const Point<3> & p, double eps) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  INSOLID_TYPE ist = prim->PointInSolid (p, eps);
	  return (ist == IS_INSIDE) ? 1 : 0;
	}
      case SECTION:
	return s1->IsStrictIn(p, eps) && s2->IsStrictIn(p, eps);
      case UNION:
	return s1->IsStrictIn(p, eps) || s2->IsStrictIn(p, eps);
      case SUB:
	return !s1->IsIn (p, eps);
      case ROOT:
	return s1->IsStrictIn (p, eps);
      }
    return 0;
  }

  bool Solid :: VectorIn (const Point<3> & p, const Vec<3> & v, 
			 double eps) const
  {
    Vec<3> hv;
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  INSOLID_TYPE ist = prim->VecInSolid (p, v, eps);
	  return (ist == IS_INSIDE || ist == DOES_INTERSECT) ? 1 : 0;
	}
      case SECTION:
	return s1 -> VectorIn (p, v, eps) && s2 -> VectorIn (p, v, eps);
      case UNION:
	return s1 -> VectorIn (p, v, eps) || s2 -> VectorIn (p, v, eps);
      case SUB:
	return !s1->VectorStrictIn(p, v, eps);
      case ROOT:
	return s1->VectorIn(p, v, eps);
      }
    return 0;
  }

  bool Solid :: VectorStrictIn (const Point<3> & p, const Vec<3> & v,
			       double eps) const
  {
    Vec<3> hv;
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  INSOLID_TYPE ist = prim->VecInSolid (p, v, eps);
	  return (ist == IS_INSIDE) ? 1 : 0;
	}
      case SECTION:
	return s1 -> VectorStrictIn (p, v, eps) && 
	  s2 -> VectorStrictIn (p, v, eps);
      case UNION:
	return s1 -> VectorStrictIn (p, v, eps) || 
	  s2 -> VectorStrictIn (p, v, eps);
      case SUB:
	return !s1->VectorIn(p, v, eps);
      case ROOT:
	return s1->VectorStrictIn(p, v, eps);
      }
    return 0;
  }


  bool Solid::VectorIn2 (const Point<3> & p, const Vec<3> & v1, 
			const Vec<3> & v2, double eps) const
  {
    if (VectorStrictIn (p, v1, eps))
      return 1;
    if (!VectorIn (p, v1, eps))
      return 0;
  
    bool res = VectorIn2Rec (p, v1, v2, eps);
    return res;
  }

  bool Solid::VectorIn2Rec (const Point<3> & p, const Vec<3> & v1, 
			   const Vec<3> & v2, double eps) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	return prim->VecInSolid2 (p, v1, v2, eps);
      case SECTION:
	return s1->VectorIn2Rec (p, v1, v2, eps) && 
	  s2->VectorIn2Rec (p, v1, v2, eps);
      case UNION:
	return s1->VectorIn2Rec (p, v1, v2, eps) ||
	  s2->VectorIn2Rec (p, v1, v2, eps);
      case SUB:
	return !s1->VectorIn2Rec (p, v1, v2, eps);
      case ROOT:
	return s1->VectorIn2Rec (p, v1, v2, eps);
      }
    return 0;  
  }






  void Solid :: Print (ostream & str) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  str << prim->GetSurfaceId(0);
	  for (int i = 1; i < prim->GetNSurfaces(); i++)
	    str << "," << prim->GetSurfaceId(i);
	  break;
	}
      case SECTION:
	{
	  str << "(";
	  s1 -> Print (str);
	  str << " AND ";
	  s2 -> Print (str);
	  str << ")";
	  break;
	}
      case UNION:
	{
	  str << "(";
	  s1 -> Print (str);
	  str << " OR ";
	  s2 -> Print (str);
	  str << ")";
	  break;
	}
      case SUB:
	{
	  str << " NOT ";
	  s1 -> Print (str);
	  break;
	}
      case ROOT:
	{
	  str << " [" << name << "=";
	  s1 -> Print (str);
	  str << "] ";
	  break;
	}
      }
  }



  void Solid :: GetSolidData (ostream & ost, int first) const
  {
    switch (op)
      {
      case SECTION:
	{
	  ost << "(";
	  s1 -> GetSolidData (ost, 0);
	  ost << " AND ";
	  s2 -> GetSolidData (ost, 0);
	  ost << ")";
	  break;
	}
      case UNION:
	{
	  ost << "(";
	  s1 -> GetSolidData (ost, 0);
	  ost << " OR ";
	  s2 -> GetSolidData (ost, 0);
	  ost << ")";
	  break;
	}
      case SUB:
	{
	  ost << "NOT ";
	  s1 -> GetSolidData (ost, 0);
	  break;
	}
      case TERM: case TERM_REF:
	{
	  if (name)
	    ost << name;
	  else
	    ost << "(noname)";
	  break;
	}
      case ROOT:
	{
	  if (first)
	    s1 -> GetSolidData (ost, 0);
	  else
	    ost << name;
	  break;
	}
      }
  }



  static Solid * CreateSolidExpr (istream & ist, const SYMBOLTABLE<Solid*> & solids);
  static Solid * CreateSolidTerm (istream & ist, const SYMBOLTABLE<Solid*> & solids);
  static Solid * CreateSolidPrim (istream & ist, const SYMBOLTABLE<Solid*> & solids);

  static void ReadString (istream & ist, char * str)
  {
    char * hstr = str;
    char ch;

    while (1)
      {
	ist.get(ch);
	if (!ist.good()) break;

	if (!isspace (ch))
	  {
	    ist.putback (ch);
	    break;
	  }
      }

    while (1)
      {
	ist.get(ch);
	if (!ist.good()) break;
	if (isalpha(ch) || isdigit(ch))
	  {
	    *str = ch;
	    str++;
	  }
	else
	  {
	    ist.putback (ch);
	    break;
	  }
      }
    *str = 0;
    //  cout << "Read string (" << hstr << ")" 
    //       << "put back: " << ch << endl;
  }


  Solid * CreateSolidExpr (istream & ist, const SYMBOLTABLE<Solid*> & solids)
  {
    //  cout << "create expr" << endl;

    Solid *s1, *s2;
    char str[100];

    s1 = CreateSolidTerm (ist, solids);
    ReadString (ist, str);
    if (strcmp (str, "OR") == 0)
      {
	//      cout << " OR ";
	s2 = CreateSolidExpr (ist, solids);
	return new Solid (Solid::UNION, s1, s2);
      }

    //  cout << "no OR found, put back string: " << str << endl;
    int i;
    for (i = strlen(str)-1; i >= 0; i--)
      ist.putback (str[i]);

    return s1;
  }

  Solid * CreateSolidTerm (istream & ist, const SYMBOLTABLE<Solid*> & solids)
  {
    //  cout << "create term" << endl;

    Solid *s1, *s2;
    char str[100];

    s1 = CreateSolidPrim (ist, solids);
    ReadString (ist, str);
    if (strcmp (str, "AND") == 0)
      {
	//      cout << " AND ";
	s2 = CreateSolidTerm (ist, solids);
	return new Solid (Solid::SECTION, s1, s2);
      }


    //  cout << "no AND found, put back string: " << str << endl;
    int i;
    for (i = strlen(str)-1; i >= 0; i--)
      ist.putback (str[i]);

    return s1;
  }

  Solid * CreateSolidPrim (istream & ist, const SYMBOLTABLE<Solid*> & solids)
  {
    Solid * s1;
    char ch;
    char str[100];

    ist >> ch;
    if (ch == '(')
      {
	s1 = CreateSolidExpr (ist, solids);
	ist >> ch;  // ')'
	//      cout << "close back " << ch << endl;
	return s1;
      }
    ist.putback (ch);
  
    ReadString (ist, str);
    if (strcmp (str, "NOT") == 0)
      {
	//      cout << " NOT ";
	s1 = CreateSolidPrim (ist, solids);
	return new Solid (Solid::SUB, s1);
      }

    (*testout) << "get terminal " << str << endl;
    s1 = solids.Get(str);
    if (s1)
      {
	//      cout << "primitive: " << str << endl;
	return s1;
      }
    cerr << "syntax error" << endl;

    return NULL;
  }


  Solid * Solid :: CreateSolid (istream & ist, const SYMBOLTABLE<Solid*> & solids)
  {
    Solid * nsol =  CreateSolidExpr (ist, solids);
    nsol = new Solid (ROOT, nsol);
    (*testout) << "Print new sol: ";
    nsol -> Print (*testout);
    (*testout) << endl;
    return nsol;
  }



  void Solid :: Boundaries (const Point<3> & p, ARRAY<int> & bounds) const
  {
    int in, strin;
    bounds.SetSize (0);
    RecBoundaries (p, bounds, in, strin);
  }

  void Solid :: RecBoundaries (const Point<3> & p, ARRAY<int> & bounds,
			       int & in, int & strin) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  /*
	    double val;
	    val = surf->CalcFunctionValue (p);
	    in = (val < 1e-6);
	    strin = (val < -1e-6);
	    if (in && !strin) bounds.Append (id);
	  */
	  if (prim->PointInSolid (p, 1e-6) == DOES_INTERSECT)
	    bounds.Append (prim->GetSurfaceId (1));
	  break;
	}
      case SECTION:
	{
	  int i, in1, in2, strin1, strin2;
	  ARRAY<int> bounds1, bounds2;

	  s1 -> RecBoundaries (p, bounds1, in1, strin1);
	  s2 -> RecBoundaries (p, bounds2, in2, strin2);

	  if (in1 && in2)
	    {
	      for (i = 1; i <= bounds1.Size(); i++)
		bounds.Append (bounds1.Get(i));
	      for (i = 1; i <= bounds2.Size(); i++)
		bounds.Append (bounds2.Get(i));
	    }
	  in = (in1 && in2);
	  strin = (strin1 && strin2);
	  break;
	}
      case UNION:
	{
	  int i, in1, in2, strin1, strin2;
	  ARRAY<int> bounds1, bounds2;

	  s1 -> RecBoundaries (p, bounds1, in1, strin1);
	  s2 -> RecBoundaries (p, bounds2, in2, strin2);

	  if (!strin1 && !strin2)
	    {
	      for (i = 1; i <= bounds1.Size(); i++)
		bounds.Append (bounds1.Get(i));
	      for (i = 1; i <= bounds2.Size(); i++)
		bounds.Append (bounds2.Get(i));
	    }
	  in = (in1 || in2);
	  strin = (strin1 || strin2);
	  break;
	}
      case SUB:
	{
	  int hin, hstrin;
	  s1 -> RecBoundaries (p, bounds, hin, hstrin);
	  in = !hstrin;
	  strin = !hin;
	  break;
	}

      case ROOT:
	{
	  s1 -> RecBoundaries (p, bounds, in, strin);
	  break;
	}
      }
  }



  void Solid :: TangentialSolid (const Point<3> & p, Solid *& tansol) const
  {
    int in, strin;
    RecTangentialSolid (p, tansol, in, strin);
  }

  void Solid :: RecTangentialSolid (const Point<3> & p, Solid *& tansol,
				    int & in, int & strin) const
  {
    tansol = NULL;

    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  /*
	    double val;
	    val = surf->CalcFunctionValue (p);
	    in = (val < 1e-6);
	    strin = (val < -1e-6);
	    if (in && !strin)
	    tansol = new Solid (surf, id);
	  */

	  INSOLID_TYPE ist = prim->PointInSolid(p, 1e-6);

	  in = (ist == IS_INSIDE || ist == DOES_INTERSECT);
	  strin = (ist == IS_INSIDE);

	  if (ist == DOES_INTERSECT)
	    {
	      tansol = new Solid (prim);
	      tansol -> op = TERM_REF;
	    }
	  break;
	}
      case SECTION:
	{
	  int in1, in2, strin1, strin2;
	  Solid * tansol1, * tansol2;

	  s1 -> RecTangentialSolid (p, tansol1, in1, strin1);
	  s2 -> RecTangentialSolid (p, tansol2, in2, strin2);

	  if (in1 && in2)
	    {
	      if (tansol1 && tansol2)
		tansol = new Solid (SECTION, tansol1, tansol2);
	      else if (tansol1)
		tansol = tansol1;
	      else if (tansol2)
		tansol = tansol2;
	    }
	  in = (in1 && in2);
	  strin = (strin1 && strin2);
	  break;
	}
      case UNION:
	{
	  int in1, in2, strin1, strin2;
	  Solid * tansol1, * tansol2;

	  s1 -> RecTangentialSolid (p, tansol1, in1, strin1);
	  s2 -> RecTangentialSolid (p, tansol2, in2, strin2);

	  if (!strin1 && !strin2)
	    {
	      if (tansol1 && tansol2)
		tansol = new Solid (UNION, tansol1, tansol2);
	      else if (tansol1)
		tansol = tansol1;
	      else if (tansol2)
		tansol = tansol2;
	    }
	  in = (in1 || in2);
	  strin = (strin1 || strin2);
	  break;
	}
      case SUB:
	{
	  int hin, hstrin;
	  Solid * tansol1;

	  s1 -> RecTangentialSolid (p, tansol1, hin, hstrin);

	  if (tansol1)
	    tansol = new Solid (SUB, tansol1);
	  in = !hstrin;
	  strin = !hin;
	  break;
	}
      case ROOT:
	{
	  s1 -> RecTangentialSolid (p, tansol, in, strin);
	  break;
	}
      }
  }




  void Solid :: TangentialSolid2 (const Point<3> & p, 
				  const Vec<3> & t,
				  Solid *& tansol) const
  {
    int in, strin;
    RecTangentialSolid2 (p, t, tansol, in, strin);
  }

  void Solid :: RecTangentialSolid2 (const Point<3> & p, const Vec<3> & t,
				     Solid *& tansol,
				     int & in, int & strin) const
  {
    tansol = NULL;

    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  /*
	    double val;
	    val = surf->CalcFunctionValue (p);
	    in = (val < 1e-6);
	    strin = (val < -1e-6);
	    if (in && !strin)
	    tansol = new Solid (surf, id);
	  */

	  INSOLID_TYPE ist = prim->PointInSolid(p, 1e-6);
	  if (ist == DOES_INTERSECT)
	    ist = prim->VecInSolid (p, t, 1e-6);

	  in = (ist == IS_INSIDE || ist == DOES_INTERSECT);
	  strin = (ist == IS_INSIDE);

	  if (ist == DOES_INTERSECT)
	    {
	      tansol = new Solid (prim);
	      tansol -> op = TERM_REF;
	    }
	  break;
	}
      case SECTION:
	{
	  int in1, in2, strin1, strin2;
	  Solid * tansol1, * tansol2;

	  s1 -> RecTangentialSolid2 (p, t, tansol1, in1, strin1);
	  s2 -> RecTangentialSolid2 (p, t, tansol2, in2, strin2);

	  if (in1 && in2)
	    {
	      if (tansol1 && tansol2)
		tansol = new Solid (SECTION, tansol1, tansol2);
	      else if (tansol1)
		tansol = tansol1;
	      else if (tansol2)
		tansol = tansol2;
	    }
	  in = (in1 && in2);
	  strin = (strin1 && strin2);
	  break;
	}
      case UNION:
	{
	  int in1, in2, strin1, strin2;
	  Solid * tansol1, * tansol2;

	  s1 -> RecTangentialSolid2 (p, t, tansol1, in1, strin1);
	  s2 -> RecTangentialSolid2 (p, t, tansol2, in2, strin2);

	  if (!strin1 && !strin2)
	    {
	      if (tansol1 && tansol2)
		tansol = new Solid (UNION, tansol1, tansol2);
	      else if (tansol1)
		tansol = tansol1;
	      else if (tansol2)
		tansol = tansol2;
	    }
	  in = (in1 || in2);
	  strin = (strin1 || strin2);
	  break;
	}
      case SUB:
	{
	  int hin, hstrin;
	  Solid * tansol1;

	  s1 -> RecTangentialSolid2 (p, t, tansol1, hin, hstrin);

	  if (tansol1)
	    tansol = new Solid (SUB, tansol1);
	  in = !hstrin;
	  strin = !hin;
	  break;
	}
      case ROOT:
	{
	  s1 -> RecTangentialSolid2 (p, t, tansol, in, strin);
	  break;
	}
      }
  }




  int Solid :: Edge (const Point<3> & p, const Vec<3> & v) const
  {
    int in, strin, faces;
    RecEdge (p, v, in, strin, faces);
    return faces >= 2;
  }

  int Solid :: OnFace (const Point<3> & p, const Vec<3> & v) const
  {
    int in, strin, faces;
    RecEdge (p, v, in, strin, faces);
    return faces >= 1;
  }


  void Solid :: RecEdge (const Point<3> & p, const Vec<3> & v,
			 int & in, int & strin, int & faces) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  INSOLID_TYPE ist = prim->VecInSolid (p, v, 1e-6);
	  in = (ist == IS_INSIDE || ist == DOES_INTERSECT);
	  strin = (ist == IS_INSIDE);
	  /*
	    in = VectorIn (p, v);
	    strin = VectorStrictIn (p, v);
	  */
	  faces = 0;

	  if (in && ! strin)
	    {
	      //	    faces = 1;
	      int i; 
	      Vec<3> grad;
	      for (i = 0; i < prim->GetNSurfaces(); i++)
		{
		  double val = prim->GetSurface(i).CalcFunctionValue(p);
		  prim->GetSurface(i).CalcGradient (p, grad);
		  if (fabs (val) < 1e-6 && fabs (v * grad) < 1e-6)
		    faces++;
		}
	    }
	  //	else
	  //	  faces = 0;
	  break;
	}
      case SECTION:
	{
	  int in1, in2, strin1, strin2, faces1, faces2;

	  s1 -> RecEdge (p, v, in1, strin1, faces1);
	  s2 -> RecEdge (p, v, in2, strin2, faces2);

	  faces = 0;
	  if (in1 && in2)
	    faces = faces1 + faces2;
	  in = in1 && in2;
	  strin = strin1 && strin2;
	  break;
	}
      case UNION:
	{
	  int in1, in2, strin1, strin2, faces1, faces2;

	  s1 -> RecEdge (p, v, in1, strin1, faces1);
	  s2 -> RecEdge (p, v, in2, strin2, faces2);

	  faces = 0;
	  if (!strin1 && !strin2)
	    faces = faces1 + faces2;
	  in = in1 || in2;
	  strin = strin1 || strin2;
	  break;
	}
      case SUB:
	{
	  int in1, strin1;
	  s1 -> RecEdge (p, v, in1, strin1, faces);
	  in = !strin1;
	  strin = !in1;
	  break;
	}
      case ROOT:
	{
	  s1 -> RecEdge (p, v, in, strin, faces);
	  break;
	}
      }
  }


  void Solid :: CalcSurfaceInverse ()
  {
    CalcSurfaceInverseRec (0);
  }

  void Solid :: CalcSurfaceInverseRec (int inv)
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  int priminv;
	  for (int i = 0; i < prim->GetNSurfaces(); i++)
	    {
	      priminv = prim->SurfaceInverted(i);
	      if (inv) priminv = 1 - priminv;
	      prim->GetSurface(i).SetInverse (priminv);
	    }
	  break;
	}
      case UNION:
      case SECTION:
	{
	  s1 -> CalcSurfaceInverseRec (inv);
	  s2 -> CalcSurfaceInverseRec (inv);
	  break;
	}
      case SUB:
	{
	  s1 -> CalcSurfaceInverseRec (1 - inv);
	  break;
	}
      case ROOT:
	{
	  s1 -> CalcSurfaceInverseRec (inv);
	  break;
	}
      }
  }


  Solid * Solid :: GetReducedSolid (const BoxSphere<3> & box) const
  {
    INSOLID_TYPE in;
    return RecGetReducedSolid (box, in);
  }

  Solid * Solid :: RecGetReducedSolid (const BoxSphere<3> & box, INSOLID_TYPE & in) const
  {
    Solid * redsol = NULL;

    switch (op)
      {
      case TERM: 
      case TERM_REF:
	{
	  in = prim -> BoxInSolid (box);
	  if (in == DOES_INTERSECT)
	    {
	      redsol = new Solid (prim);
	      redsol -> op = TERM_REF;
	    }
	  break;
	}
      case SECTION:
	{
	  INSOLID_TYPE in1, in2;
	  Solid * redsol1, * redsol2;

	  redsol1 = s1 -> RecGetReducedSolid (box, in1);
	  redsol2 = s2 -> RecGetReducedSolid (box, in2);

	  if (in1 == IS_OUTSIDE || in2 == IS_OUTSIDE)
	    {
	      if (in1 == DOES_INTERSECT) delete redsol1;
	      if (in2 == DOES_INTERSECT) delete redsol2;
	      in = IS_OUTSIDE;
	    }
	  else
	    {
	      if (in1 == DOES_INTERSECT || in2 == DOES_INTERSECT) 
		in = DOES_INTERSECT;
	      else 
		in = IS_INSIDE;

	      if (in1 == DOES_INTERSECT && in2 == DOES_INTERSECT)
		redsol = new Solid (SECTION, redsol1, redsol2);
	      else if (in1 == DOES_INTERSECT)
		redsol = redsol1;
	      else if (in2 == DOES_INTERSECT)
		redsol = redsol2;
	    }
	  break;
	}

      case UNION:
	{
	  INSOLID_TYPE in1, in2;
	  Solid * redsol1, * redsol2;

	  redsol1 = s1 -> RecGetReducedSolid (box, in1);
	  redsol2 = s2 -> RecGetReducedSolid (box, in2);

	  if (in1 == IS_INSIDE || in2 == IS_INSIDE)
	    {
	      if (in1 == DOES_INTERSECT) delete redsol1;
	      if (in2 == DOES_INTERSECT) delete redsol2;
	      in = IS_INSIDE;
	    }
	  else
	    {
	      if (in1 == DOES_INTERSECT || in2 == DOES_INTERSECT) in = DOES_INTERSECT;
	      else in = IS_OUTSIDE;

	      if (in1 == DOES_INTERSECT && in2 == DOES_INTERSECT)
		redsol = new Solid (UNION, redsol1, redsol2);
	      else if (in1 == DOES_INTERSECT)
		redsol = redsol1;
	      else if (in2 == DOES_INTERSECT)
		redsol = redsol2;
	    }
	  break;
	}

      case SUB:
	{
	  INSOLID_TYPE in1;
	  Solid * redsol1 = s1 -> RecGetReducedSolid (box, in1);

	  switch (in1)
	    {
	    case IS_OUTSIDE: in = IS_INSIDE; break;
	    case IS_INSIDE:  in = IS_OUTSIDE; break;
	    case DOES_INTERSECT: in = DOES_INTERSECT; break;
	    }

	  if (redsol1)
	    redsol = new Solid (SUB, redsol1);
	  break;
	}
      
      case ROOT:
	{
	  INSOLID_TYPE in1;
	  redsol = s1 -> RecGetReducedSolid (box, in1);
	  in = in1;
	  break;
	}
      }
    return redsol;
  }


  int Solid :: NumPrimitives () const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  return 1;
	}
      case UNION:
      case SECTION:
	{
	  return s1->NumPrimitives () + s2 -> NumPrimitives();
	}
      case SUB:
      case ROOT:
	{
	  return s1->NumPrimitives ();
	}
      }
    return 0;
  }

  void Solid :: GetSurfaceIndices (ARRAY<int> & surfind) const
  {
    surfind.SetSize (0);
    RecGetSurfaceIndices (surfind);
  }

  void Solid :: RecGetSurfaceIndices (ARRAY<int> & surfind) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  /*
	    int i;
	    for (i = 1; i <= surfind.Size(); i++)
	    if (surfind.Get(i) == prim->GetSurfaceId())
	    return;
	    surfind.Append (prim->GetSurfaceId());
	    break;
	  */
	  for (int j = 0; j < prim->GetNSurfaces(); j++)
	    if (prim->SurfaceActive (j))
	      {
		bool found = 0;
		int siprim = prim->GetSurfaceId(j);

		for (int i = 0; i < surfind.Size(); i++)
		  if (surfind[i] == siprim)
		    {
		      found = 1;
		      break;
		    }
		if (!found) surfind.Append (siprim);
	      }
	  break;
	}
      case UNION:
      case SECTION:
	{
	  s1 -> RecGetSurfaceIndices (surfind);
	  s2 -> RecGetSurfaceIndices (surfind);
	  break;
	}
      case SUB:
      case ROOT:
	{
	  s1 -> RecGetSurfaceIndices (surfind);
	  break;
	}
      }
  }



  void Solid :: GetSurfaceIndices (IndexSet & iset) const
  {
    iset.Clear();
    RecGetSurfaceIndices (iset);
  }

  void Solid :: RecGetSurfaceIndices (IndexSet & iset) const
  {
    switch (op)
      {
      case TERM: case TERM_REF:
	{
	  /*
	    int i;
	    for (i = 1; i <= surfind.Size(); i++)
	    if (surfind.Get(i) == prim->GetSurfaceId())
	    return;
	    surfind.Append (prim->GetSurfaceId());
	    break;
	  */
	  for (int j = 0; j < prim->GetNSurfaces(); j++)
	    if (prim->SurfaceActive (j))
	      {
		int siprim = prim->GetSurfaceId(j);
		iset.Add (siprim);
	      }
	  break;
	}
      case UNION:
      case SECTION:
	{
	  s1 -> RecGetSurfaceIndices (iset);
	  s2 -> RecGetSurfaceIndices (iset);
	  break;
	}
      case SUB:
      case ROOT:
	{
	  s1 -> RecGetSurfaceIndices (iset);
	  break;
	}
      }
  }





  BlockAllocator Solid :: ball(sizeof (Solid));
}
