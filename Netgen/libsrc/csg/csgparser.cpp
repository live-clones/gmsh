#include <mystdlib.h>
#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>


namespace netgen
{
  using namespace netgen;


  enum TOKEN_TYPE
    { 
      TOK_MINUS = '-', TOK_LP = '(', OK_RP = ')', TOK_LSP = '[', TOK_RSP = ']',
      TOK_EQU = '=', TOK_COMMA = ',', TOK_SEMICOLON = ';',
      TOK_NUM = 100, TOK_STRING, TOK_NAMED_SOLID, TOK_PRIMITIVE, 
      TOK_OR, TOK_AND, TOK_NOT, 
      TOK_SINGULAR, TOK_EDGE, TOK_POINT, TOK_IDENTIFY, TOK_CLOSESURFACES,
      TOK_CLOSEEDGES, TOK_PERIODIC,
      TOK_SOLID, TOK_RECO, TOK_TLO, TOK_BOUNDINGBOX, TOK_BOUNDARYCONDITION,
      TOK_END };

  struct kwstruct
  {
    TOKEN_TYPE kw; 
    char * name;
  };

  static kwstruct defkw[] =
    {
      { TOK_RECO,    "algebraic3d" },
      { TOK_SOLID,   "solid" },
      { TOK_TLO,     "tlo" },
      { TOK_BOUNDINGBOX, "boundingbox" },
      { TOK_OR,      "or" },
      { TOK_AND,     "and" },
      { TOK_NOT,     "not" },
      { TOK_SINGULAR, "singular" },
      { TOK_EDGE,     "edge" },
      { TOK_POINT,    "point" },
      { TOK_IDENTIFY, "identify" },
      { TOK_CLOSESURFACES, "closesurfaces" },
      { TOK_CLOSEEDGES, "closeedges" },
      { TOK_PERIODIC,  "periodic" },
      { TOK_BOUNDARYCONDITION, "boundarycondition" },
      { TOKEN_TYPE(0) }
    };

  enum PRIMITIVE_TYPE
    { TOK_SPHERE = 1, TOK_CYLINDER, TOK_PLANE, TOK_ELLIPTICCYLINDER, 
      TOK_ELLIPSOID,
      TOK_CONE, TOK_TUBE,
      TOK_GENCYL, TOK_ORTHOBRICK, TOK_POLYHEDRON, TOK_EXTRUSION, TOK_REVOLUTION,
      TOK_TRANSLATE, TOK_MULTITRANSLATE, TOK_ROTATE, TOK_MULTIROTATE
    };

  struct primstruct
  {
    PRIMITIVE_TYPE kw; 
    char * name;
  };

  static primstruct defprim[] =
    {
      { TOK_PLANE,     "plane" },
      { TOK_SPHERE,    "sphere" },
      { TOK_CYLINDER,  "cylinder" },
      { TOK_CONE,      "cone" },
      { TOK_ELLIPTICCYLINDER, "ellipticcylinder" },
      { TOK_ELLIPSOID, "ellipsoid" },
      { TOK_TUBE,      "tube" },
      { TOK_GENCYL,    "gencyl" },
      { TOK_ORTHOBRICK, "orthobrick" },
      { TOK_POLYHEDRON, "polyhedron" },
      { TOK_EXTRUSION,  "extrusion" },
      { TOK_REVOLUTION, "revolution" },

      { TOK_TRANSLATE, "translate" },
      { TOK_MULTITRANSLATE, "multitranslate" },
      { TOK_ROTATE,   "rotate" },
      { TOK_MULTIROTATE, "multirotate" },
      { PRIMITIVE_TYPE(0) }
    };



  static CSGeometry * geom;

  /*
%token <solidtype> TOK_SPHERE TOK_CYLINDER TOK_CONE TOK_PLAIN TOK_TUBE TOK_GENCYL TOK_ORTHOBRICK TOK_POLYHEDRON TOK_REVOLUTION
%left <solidtype> TOK_OR TOK_AND TOK_NOT
%token <solidtype> TOK_TRANSLATE TOK_MULTITRANSLATE TOK_ROTATE TOK_MULTIROTATE
%type <solidtype> solid solidprimitive 
%type <void> splinesegmentlist splinesegment readbspline bsplinepointlist
%type <chptr> anyident
%token TOK_SINGULAR TOK_EDGE TOK_POINT
%token TOK_IDENTIFY TOK_CLOSESURFACES TOK_CLOSEEDGES TOK_PERIODIC
%token TOK_BOUNDARYCONDITION
%type <void> polyhedronpoints polyhedronfaces polyhedronpoint polyhedronface
%type <void> revolutionpoints revolutionpoint
  */


  
  class CSGScanner
  {
    TOKEN_TYPE token;
    PRIMITIVE_TYPE prim_token;
    double num_value;
    string string_value;
    
    int linenum;
    istream * scanin;

  public:

    CSGScanner (istream & ascanin);

    TOKEN_TYPE GetToken() const
    { return token; }

    double GetNumValue() const
    { return num_value; }

    const string & GetStringValue() const
    { return string_value; }

    char GetCharValue() const
    { return string_value[0]; }

    PRIMITIVE_TYPE GetPrimitiveToken() const
    { return prim_token; }
  
    void ReadNext();
    void Error (const string & err);
  };


  CSGScanner :: CSGScanner (istream & ascanin)
  {
    scanin = &ascanin;
    token = TOK_END;
    num_value = 0;
    linenum = 1;
  }


  void CSGScanner :: ReadNext ()
  {
    char ch;
  

    // whitespaces ueberspringen
    do
      { 
	scanin->get(ch);

	if (ch == '\n') 
	  linenum++;

	// end of file reached
	if (scanin->eof())
	  {
	    token = TOK_END;
	    return;
	  }

	// skip comment line
	if (ch == '#')
	  {
	    while (ch != '\n')
	      {
		scanin->get(ch);
		if (scanin->eof())
		  {
		    token = TOK_END;
		    return;
		  }
	      }
	    linenum++;
	  }	
      }
    while (isspace(ch));
  
    switch (ch)
      {
      case '(': case ')': 
      case '[': case ']': 
      case '-':
      case '=': case ',': case ';':
	{
	  token = TOKEN_TYPE (ch);
	  break;
	}
  
      default:
	{
	  if (isdigit (ch) || ch == '.')
	    {
	      scanin->putback (ch);
	      (*scanin) >> num_value;
	      token = TOK_NUM;
	      return;
	    }

	  if (isalpha (ch))
	    {
	      string_value = string (1, ch);
	      scanin->get(ch);
	      while (isalnum(ch))
		{
		  string_value += ch;
		  scanin->get(ch);
		}
	      scanin->putback (ch);
	    }
	  /*
	  (*scanin).putback (ch);
	  (*scanin) >> string_value;
	  */
	  int nr = 0;
	  while (defkw[nr].kw)
	    {
	      if (string_value == defkw[nr].name)
		{
		  token = defkw[nr].kw;
		  return;
		}
	      nr++;
	    }

	  nr = 0;
	  while (defprim[nr].kw)
	    {
	      if (string_value == defprim[nr].name)
		{
		  token = TOK_PRIMITIVE;
		  prim_token = defprim[nr].kw;
		  return;
		}
	      nr++;
	    }

	  token = TOK_STRING;
	}
      }
  }

  void CSGScanner :: Error (const string & err)
  {
    stringstream errstr;
    errstr << "Parsing error in line " << linenum << ": " << endl << err << endl;
    throw string(errstr.str());
  }


  /*
    Solid = Term { OR Term }
    Term  = Primary { AND Primary }
    Primary = PRIM | IDENT | ( Solid ) | NOT Primary
   */

  void ParseChar (CSGScanner & scan, char ch)
  {
    char str[2];
    str[0] = ch;
    str[1] = 0;
    if (scan.GetToken() != TOKEN_TYPE(ch)) 
      scan.Error (string ("token '") + string(str) + string("' expected"));
    scan.ReadNext();
  }
  
  double ParseNumber(CSGScanner & scan)
  {
    if (scan.GetToken() == '-')
      {
	scan.ReadNext();
	return -ParseNumber (scan);
      }
    if (scan.GetToken() != TOK_NUM) scan.Error ("number expected");
    double val = scan.GetNumValue();
    scan.ReadNext();
    return val;
  }


  Solid * ParseSolid (CSGScanner & scan);
  Solid * ParseTerm (CSGScanner & scan);
  Solid * ParsePrimary (CSGScanner & scan);
 

  Solid * ParsePrimary (CSGScanner & scan)
  {
    if (scan.GetToken() == TOK_PRIMITIVE)
      {
	//	cout << "prim token = " << int (scan.GetPrimitiveToken()) << endl;
	switch (scan.GetPrimitiveToken())
	  {
	  case TOK_PLANE:
	    {
	      Point<3> p;
	      Vec<3> v;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      p(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      p(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      p(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      v(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v(2) = ParseNumber (scan);
	      ParseChar (scan, ')');

	      // cout << "define plane, p = " << p << "; v = " << v << endl;
	      OneSurfacePrimitive * surf = new Plane ( p, v );

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	    }
	  case TOK_CYLINDER:
	    {
	      Point<3> pa, pb;
	      double r;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      pa(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      pb(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pb(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pb(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      r = ParseNumber (scan);
	      ParseChar (scan, ')');
	      
	      OneSurfacePrimitive * surf = new Cylinder ( pa, pb, r );

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	    }

	  case TOK_ELLIPTICCYLINDER:
	    {
	      Point<3> pa;
	      Vec<3> vl, vs;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      pa(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      vl(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      vl(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      vl(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      vs(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      vs(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      vs(2) = ParseNumber (scan);
	      ParseChar (scan, ')');
	      
	      OneSurfacePrimitive * surf = new EllipticCylinder ( pa, vl, vs);

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	    }


	  case TOK_ELLIPSOID:
	    {
	      Point<3> pa;
	      Vec<3> v1, v2, v3;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      pa(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      v1(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v1(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v1(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      v2(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v2(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v2(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      v3(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v3(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v3(2) = ParseNumber (scan);
	      ParseChar (scan, ')');
	      
	      OneSurfacePrimitive * surf = new Ellipsoid ( pa, v1, v2, v3);

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	    }


	  case TOK_CONE:
	    {
	      Point<3> pa, pb;
	      double ra, rb;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      pa(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      ra = ParseNumber (scan);
	      ParseChar (scan, ';');
	      pb(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pb(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pb(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      rb = ParseNumber (scan);
	      ParseChar (scan, ')');
	      
	      OneSurfacePrimitive * surf = new Cone ( pa, pb, ra, rb);

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	    }




	  case TOK_SPHERE:
	    {
	      Point<3> p;
	      double r;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      p(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      p(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      p(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      r = ParseNumber (scan);
	      ParseChar (scan, ')');
	      
	      // cout << "define sphere, c = " << p << ", rad = " << r << endl;
	      OneSurfacePrimitive * surf = new Sphere ( p, r );

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	    }

	  case TOK_ORTHOBRICK:
	    {
	      Point<3> pa, pb;
	      
	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      pa(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pa(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      pb(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pb(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      pb(2) = ParseNumber (scan);
	      ParseChar (scan, ')');
	      
	      // cout << "define orthobrick, p1 = " << pa << "; p2 = " << pb << endl;

	      Primitive * nprim = new OrthoBrick (pa, pb);
	      
	      for (int j = 0; j < nprim->GetNSurfaces(); j++)
		{
		  geom->AddSurface (&nprim->GetSurface(j));
		  nprim->SetSurfaceId (j, geom->GetNSurf()-1);
		}
	      return new Solid (nprim);
	    } 


	    

	  case TOK_POLYHEDRON:
	    {
	      // Added by Dalibor Lukas, October 15, 2003

	      Point<3> p;
	      int pi1, pi2, pi3, pi4;
	      
	      scan.ReadNext();
	      ParseChar (scan, '(');
	      
	      Polyhedra * polyhedron = new Polyhedra;

	      // scanning the points
	      while (1)
		{
		  p(0) = ParseNumber (scan);
		  ParseChar (scan, ',');
		  p(1) = ParseNumber (scan);
		  ParseChar (scan, ',');
		  p(2) = ParseNumber (scan);
		  ParseChar (scan, ';');

		  // cout << "point = " << p << endl;

		  polyhedron->AddPoint(p);

		  if (scan.GetToken() == ';')
		    {
		      scan.ReadNext();
		      break;
		    }
		}

	      // scanning the faces
	      while (1)
		{
		  pi1 = (int) (ParseNumber (scan));
		  ParseChar (scan, ',');
		  pi2 = (int) (ParseNumber (scan));
		  ParseChar (scan, ',');
		  pi3 = (int) (ParseNumber (scan));

		  polyhedron->AddFace(pi1-1,pi2-1,pi3-1);

		  if (scan.GetToken() == TOK_COMMA)
		    {
		      ParseChar (scan, ',');
		      pi4 = (int) (ParseNumber (scan));
		      polyhedron->AddFace(pi1-1,pi3-1,pi4-1);
		    }

		  if (scan.GetToken() == ')')
		    {
		      scan.ReadNext();
		      break;
		    }
		  scan.ReadNext();
		}
	      
	      for (int j = 0; j < polyhedron->GetNSurfaces(); j++)
		{
		  geom->AddSurface (&polyhedron->GetSurface(j));
		  polyhedron->SetSurfaceId (j, geom->GetNSurf()-1);
		}

	      return new Solid (polyhedron);
	    }


	  case TOK_EXTRUSION:
	    {
	      Point<3> p0;
	      Vec<3> ex, ey;
	      ARRAY<Point<2> > points;

	      scan.ReadNext();
	      
	      ParseChar (scan, '(');
	      p0(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      p0(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      p0(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      ex(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      ex(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      ex(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      ey(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      ey(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      ey(2) = ParseNumber (scan);
	      ParseChar (scan, ';');

	      cout << "p0 = " << p0 << endl;

	      int npseg = 0;
	      int nseg = 0;
	      while (1)
		{
		  Point<2> p1, p2, p3;

		  p1(0) = ParseNumber(scan);
		  ParseChar (scan, ',');
		  p1(1) = ParseNumber(scan);
		  points.Append (p1);
		  if (scan.GetToken() == ')')
		    {
		      scan.ReadNext();
		      break;
		    }
		  scan.ReadNext();
		}


	      /*
	      while (1)
		{
		  Point<2> p1, p2, p3;
		  
		  p3 = p2;
		  p2 = p1;
		  p1(0) = ParseNumber(scan);
		  ParseChar (scan, ',');
		  p1(1) = ParseNumber(scan);
		  npseg++;
		  
		  cout << "p1 = " << p1 << endl;

		  if (scan.GetToken() == ';' || scan.GetToken() == ')')
		    {
		      if (npseg == 2)
			{
			  p3 = p2;
			  p2 = Center (p1, p3);
			}
		      if (nseg == 0)
			points.Append (p3);
		      points.Append (p2);
		      points.Append (p1);
		      npseg = 1;
		      nseg++;

		      cout << "p1, = " << p1 << ", p2 = " << p2 << ", p3 = " << p3 << endl;
		    }
		  
		  if (scan.GetToken() == ')')
		    {
		      scan.ReadNext();
		      break;
		    }
		  if (scan.GetToken() == ';' || scan.GetToken() == ',')
		    {
		      scan.ReadNext();
		    }
		}
	      */
	      cout << "p0 = " << p0 << endl;
	      cout << ", ex = " << ex << ", ey = " << ey << endl;
	      cout << "points = " << points << endl;
	      
	      Extrusion * extrusion = new Extrusion (p0, ex, ey, points);
	      
	      for (int i = 0; i < extrusion->GetNSurfaces(); i++)
		{
		  geom->AddSurface (&extrusion->GetSurface(i));
		  extrusion->SetSurfaceId(i, geom->GetNSurf()-1);
		}
	      return new Solid (extrusion);
		    
	      /*
	      // cout << "define cylinder, pa = " << pa << "; pb = " << pb
	      // << ", rad = " << r << endl;
	      OneSurfacePrimitive * surf = new Cylinder ( pa, pb, r );

	      geom->AddSurface (surf);
	      surf->SetSurfaceId (0, geom->GetNSurf()-1);

	      return new Solid (surf);
	      */
	    }





	  case TOK_TRANSLATE: 
	    {
	      Vec<3> v;
	      scan.ReadNext();
	      ParseChar (scan, '(');
	      v(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      
	      Solid * sol1 = ParseSolid (scan);

	      ParseChar (scan, ')');

	      Solid * nsol = sol1 -> Copy(*geom);
	      Transformation<3> trans(v);
	      nsol -> Transform (trans);
	      return nsol;
	    }


	  case TOK_MULTITRANSLATE: 
	    {
	      Vec<3> v;
	      int n;
	      
	      scan.ReadNext();
	      ParseChar (scan, '(');
	      v(0) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v(1) = ParseNumber (scan);
	      ParseChar (scan, ',');
	      v(2) = ParseNumber (scan);
	      ParseChar (scan, ';');
	      
	      n = int (ParseNumber (scan));
	      ParseChar (scan, ';');
	      
	      Solid * sol1 = ParseSolid (scan);
	      
	      ParseChar (scan, ')');
	      
	      int i;
	      Solid * hsol = sol1;
	      for (i = 1; i <= n; i++)
		{
		  Solid * nsol = sol1 -> Copy(*geom);
		  Transformation<3> trans(double(i) * v);
		  
		  nsol -> Transform (trans);
		  hsol = new Solid (Solid::UNION, hsol, nsol); 
		}
	      return hsol;
	    }


	  default:
	    {
	      scan.Error (string ("unknown primary ") + scan.GetStringValue());
	    }

	  }
      }

    else if (scan.GetToken() == TOK_STRING &&
	     geom->GetSolid(scan.GetStringValue()))

      {
	Solid * sol = const_cast<Solid*> (geom->GetSolid(scan.GetStringValue()));
	scan.ReadNext();
	return sol;
      }

    else if (scan.GetToken() == TOK_NOT)

      {
	scan.ReadNext();
	Solid * sol1 = ParsePrimary (scan);
	return new Solid (Solid::SUB, sol1);
      }

    else if (scan.GetToken() == '(')

      {
	scan.ReadNext();
	Solid * sol1 = ParseSolid (scan);
	scan.ReadNext();
	return sol1;
      }

    scan.Error (string ("not a primary, name = ")+
		scan.GetStringValue());
    return 0;
  }


  Solid * ParseTerm (CSGScanner & scan)
  {
    Solid * sol = ParsePrimary(scan);
    while (scan.GetToken() == TOK_AND)
      {
	scan.ReadNext();
	Solid * sol2 = ParsePrimary(scan);
	sol = new Solid (Solid::SECTION, sol, sol2);
      }
    return sol;
  }

  Solid * ParseSolid (CSGScanner & scan)
  {
    Solid * sol = ParseTerm(scan);
    while (scan.GetToken() == TOK_OR)
      {
	scan.ReadNext();
	Solid * sol2 = ParseTerm(scan);
	sol = new Solid (Solid::UNION, sol, sol2);
      }
    return sol;
  }



  void ParseFlags (CSGScanner & scan, Flags & flags)
  {
    while (scan.GetToken() == '-')
      {
	scan.ReadNext();
	string name = scan.GetStringValue();
	scan.ReadNext();
	if (scan.GetToken() == '=')
	  {
	    scan.ReadNext();
	    if (scan.GetToken() == TOK_STRING)
	      {
		flags.SetFlag (name.c_str(), scan.GetStringValue().c_str());
		scan.ReadNext();
	      }
	    else if (scan.GetToken() == '[')
	      {
		scan.ReadNext();
		ARRAY<double> vals;
		vals.Append (ParseNumber(scan));
		while (scan.GetToken() == ',')
		  {
		    scan.ReadNext();
		    vals.Append (ParseNumber(scan));
		  }
		ParseChar (scan, ']');
		flags.SetFlag (name.c_str(), vals);
	      }
	    else if (scan.GetToken() == TOK_NUM)
	      {
		flags.SetFlag (name.c_str(), scan.GetNumValue());
		scan.ReadNext();
	      }
	  }
	else
	  {
	    flags.SetFlag (name.c_str());
	  }
      }
  }


  /*
    Main parsing function for CSG geometry
   */
  CSGeometry * ParseCSG (istream & istr)
  {
    CSGScanner scan(istr);
    
    geom = new CSGeometry;

    scan.ReadNext();
    if (scan.GetToken() != TOK_RECO)  // keyword 'algebraic3d'
      {
	return 0;
      }
    scan.ReadNext();

    try
      {
	while (1)
	  {
	    if (scan.GetToken() == TOK_END) break;
	    
	    if (scan.GetToken() == TOK_SOLID)
	      {
		scan.ReadNext();
		if (scan.GetToken() != TOK_STRING)
		  scan.Error ("name identifier expected");
		string solidname = scan.GetStringValue();

		scan.ReadNext();

		ParseChar (scan, '=');
		Solid * solid = ParseSolid (scan);

		Flags flags;
		ParseFlags (scan, flags);

		geom->SetSolid (solidname.c_str(), new Solid (Solid::ROOT, solid)); 
		geom->SetFlags (solidname.c_str(), flags); 
		
		ParseChar (scan, ';');
		
		PrintMessage (4, "define solid ", solidname);
	      }

	    else if (scan.GetToken() == TOK_TLO)

	      { // a TopLevelObject definition

		scan.ReadNext();
		
		string name = scan.GetStringValue();
		scan.ReadNext();

		if (scan.GetToken() != TOK_STRING)

		  { // a solid TLO

		    Flags flags;
		    ParseFlags (scan, flags);
		    
		    ParseChar (scan, ';');

		    int tlonr = 
		      geom->SetTopLevelObject ((Solid*)geom->GetSolid(name));
		    TopLevelObject * tlo = geom->GetTopLevelObject (tlonr);
		    if (flags.NumListFlagDefined ("col"))
		      {
			const ARRAY<double> & col =
			  flags.GetNumListFlag ("col");
			tlo->SetRGB (col[0], col[1], col[2]);
		      }

		    if (flags.GetDefineFlag ("transparent"))
		      tlo->SetTransparent (1);

		    tlo->SetMaterial (flags.GetStringFlag ("material", ""));
		    tlo->SetLayer (int(flags.GetNumFlag ("layer", 1)));
		    if (flags.NumFlagDefined ("maxh"))
		      tlo->SetMaxH (flags.GetNumFlag("maxh", 1e10));
		  }

		else
		  
		  { // a surface TLO

		    string surfname = scan.GetStringValue();
		    scan.ReadNext();

		    Flags flags;
		    ParseFlags (scan, flags);
		    
		    ParseChar (scan, ';');

		    ARRAY<int> si;
		    geom->GetSolid(surfname)->GetSurfaceIndices(si);
		    int tlonr = 
		      geom->SetTopLevelObject ((Solid*)geom->GetSolid(name),
					       (Surface*)geom->GetSurface(si.Get(1)));
		    TopLevelObject * tlo = geom->GetTopLevelObject (tlonr);
		    if (flags.NumListFlagDefined ("col"))
		      {
			const ARRAY<double> & col = flags.GetNumListFlag ("col");
			tlo->SetRGB (col.Get(1), col.Get(2), col.Get(3));
		      }
		    if (flags.GetDefineFlag ("transparent"))
		      tlo->SetTransparent (1);

		    if (flags.NumFlagDefined ("maxh"))
		      tlo->SetMaxH (flags.GetNumFlag("maxh", 1e10));
		    tlo->SetLayer (int(flags.GetNumFlag ("layer", 1)));
		    tlo->SetBCProp (int(flags.GetNumFlag ("bc", -1)));
		  }
	      }
	    
	    else if (scan.GetToken() == TOK_IDENTIFY)

	      {
		
		scan.ReadNext();
		switch (scan.GetToken())
		  {
		  case TOK_CLOSESURFACES:
		    {
		      scan.ReadNext();
		      
		      string name1 = scan.GetStringValue();
		      scan.ReadNext();
		      
		      string name2 = scan.GetStringValue();
		      scan.ReadNext();
		      
		      Flags flags;
		      ParseFlags (scan, flags);
		      
		      ParseChar (scan, ';');
		      
		      
		      ARRAY<int> si1, si2;
		      geom->GetSolid(name1)->GetSurfaceIndices(si1);
		      geom->GetSolid(name2)->GetSurfaceIndices(si2);
		      
		      geom->AddIdentification 
			(new CloseSurfaceIdentification 
			 (geom->GetNIdentifications()+1, *geom, 
			  geom->GetSurface (si1[0]), geom->GetSurface (si2[0]),
			  flags));
		      break;
		    }
		    
		  case TOK_PERIODIC:
		    {
		      scan.ReadNext();
		      
		      string name1 = scan.GetStringValue();
		      scan.ReadNext();

		      string name2 = scan.GetStringValue();
		      scan.ReadNext();

		      ParseChar (scan, ';');

		      
		      ARRAY<int> si1, si2;
		      geom->GetSolid(name1)->GetSurfaceIndices(si1);
		      geom->GetSolid(name2)->GetSurfaceIndices(si2);
		      
		      geom->AddIdentification 
			(new PeriodicIdentification 
			 (geom->GetNIdentifications()+1,
			  *geom,
			  geom->GetSurface (si1.Get(1)),
			  geom->GetSurface (si2.Get(1))));
		      break;
		    }

		  default:
		    scan.Error ("keyword 'closesurfaces' or 'periodic' expected");
		  }
		
	      }
	    
	    else if (scan.GetToken() == TOK_POINT)
	      {
		Point<3> p;

		scan.ReadNext();
		ParseChar (scan, '(');
		p(0) = ParseNumber (scan);
		ParseChar (scan, ',');
		p(1) = ParseNumber (scan);
		ParseChar (scan, ',');
		p(2) = ParseNumber (scan);
		ParseChar (scan, ')');
		ParseChar (scan, ';');

		geom->AddUserPoint (p);
	      }

	    else if (scan.GetToken() == TOK_BOUNDINGBOX)
	      {
		Point<3> p1, p2;
		
		scan.ReadNext();
		ParseChar (scan, '(');
		p1(0) = ParseNumber (scan);
		ParseChar (scan, ',');
		p1(1) = ParseNumber (scan);
		ParseChar (scan, ',');
		p1(2) = ParseNumber (scan);
		ParseChar (scan, ';');
		p2(0) = ParseNumber (scan);
		ParseChar (scan, ',');
		p2(1) = ParseNumber (scan);
		ParseChar (scan, ',');
		p2(2) = ParseNumber (scan);
		ParseChar (scan, ')');
		ParseChar (scan, ';');

		geom->SetBoundingBox (Box<3> (p1, p2));
	      }

	    else if (scan.GetToken() == TOK_BOUNDARYCONDITION)
	      {
		scan.ReadNext();
		
		string name1 = scan.GetStringValue();
		scan.ReadNext();
		
		string name2 = scan.GetStringValue();
		scan.ReadNext();
		
		int num = int (ParseNumber (scan));
		ParseChar (scan, ';');


		CSGeometry::BCModification bcm;
		ARRAY<int> si;
		
		geom->GetSolid(name1)->GetSurfaceIndices(si);
	
		bcm.tlonr = -1;
		int i;	
		for (i = 0; i < geom->GetNTopLevelObjects(); i++)
		  if (string (geom->GetTopLevelObject(i)->GetSolid()->Name())
		      == name2)
		    {
		      bcm.tlonr = i;
		      break;
		    }
		
		bcm.bcnr = num;
		for (i = 0; i < si.Size(); i++)
		  {
		    bcm.si = si[i];
		    geom->bcmodifications.Append (bcm);
		  }
	      }

	    else
	      {
		cout << "read unidentified token " << scan.GetToken() 
		     << " string = " << scan.GetStringValue() << endl;
		scan.ReadNext();
	      }
	  }
      }
    catch (string errstr)
      {
	cout << "caught error " << errstr << endl;
      }


    return geom;
    /*
    do
      {
	scan.ReadNext();
	if (scan.GetToken() == TOK_STRING)
	  cout << "found string " << scan.GetStringValue() << endl;
	else
	  cout << "token = " << int(scan.GetToken()) << endl;
      }
    while (scan.GetToken() != TOK_END);
    */
  }


};

