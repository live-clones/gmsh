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
      TOK_SINGULAR, TOK_EDGE, TOK_POINT, TOK_FACE, TOK_IDENTIFY, TOK_CLOSESURFACES,
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
      { TOK_FACE,     "face" },
      { TOK_POINT,    "point" },
      { TOK_IDENTIFY, "identify" },
      { TOK_CLOSESURFACES, "closesurfaces" },
      { TOK_CLOSEEDGES, "closeedges" },
      { TOK_PERIODIC,  "periodic" },
      { TOK_BOUNDARYCONDITION, "boundarycondition" },
      { TOKEN_TYPE(0) }
    };

  enum PRIMITIVE_TYPE
    {
      TOK_SPHERE = 1, TOK_CYLINDER, TOK_PLANE, TOK_ELLIPTICCYLINDER, 
      TOK_ELLIPSOID, TOK_CONE, 
      TOK_ORTHOBRICK, TOK_POLYHEDRON, 
      
      TOK_TUBE, TOK_GENCYL, TOK_EXTRUSION, TOK_REVOLUTION,    // currently, out of order

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
      { TOK_ORTHOBRICK, "orthobrick" },
      { TOK_POLYHEDRON, "polyhedron" },

      { TOK_TUBE,      "tube" },
      { TOK_GENCYL,    "gencyl" },
      { TOK_EXTRUSION,  "extrusion" },
      { TOK_REVOLUTION, "revolution" },

      { TOK_TRANSLATE, "translate" },
      { TOK_MULTITRANSLATE, "multitranslate" },
      { TOK_ROTATE,   "rotate" },
      { TOK_MULTIROTATE, "multirotate" },
      { PRIMITIVE_TYPE(0) }
    };

  static CSGeometry * geom;


  
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

    /*
    CSGScanner & Parse (char ch);
    CSGScanner & Parse (int & i);
    CSGScanner & Parse (double & d);
    CSGScanner & Parse (Point<3> & p);
    CSGScanner & Parse (Vec<3> & p);
    */
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
  

    // scan whitespaces
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
	      while (isalnum(ch) || ch == '_')
		{
		  string_value += ch;
		  scanin->get(ch);
		}
	      scanin->putback (ch);
	    }

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
    if (scan.GetToken() != TOKEN_TYPE(ch)) 
      scan.Error (string ("token '") + string(1, ch) + string("' expected"));
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

  Vec<3> ParseVector (CSGScanner & scan)
  {
    Vec<3> v;
    v(0) = ParseNumber (scan);
    ParseChar (scan, ',');
    v(1) = ParseNumber (scan);
    ParseChar (scan, ',');
    v(2) = ParseNumber (scan);
    return v;
  }


  CSGScanner & operator>> (CSGScanner & scan, char ch)
  {
    if (scan.GetToken() != TOKEN_TYPE(ch)) 
      scan.Error (string ("token '") + string(1, ch) + string("' expected"));
    scan.ReadNext();
    return scan;
  }

  CSGScanner & operator>> (CSGScanner & scan, double & d)
  {
    d = ParseNumber (scan);
    return scan;
  }

  CSGScanner & operator>> (CSGScanner & scan, int & i)
  {
    i = int (ParseNumber (scan));
    return scan;
  }

  CSGScanner & operator>> (CSGScanner & scan, Point<3> & p)
  {
    scan >> p(0) >> ',' >> p(1) >> ',' >> p(2);
    return scan;
  }

  CSGScanner & operator>> (CSGScanner & scan, Vec<3> & v)
  {
    scan >> v(0) >> ',' >> v(1) >> ',' >> v(2);
    return scan;
  }


  Solid * ParseSolid (CSGScanner & scan);
  Solid * ParseTerm (CSGScanner & scan);
  Solid * ParsePrimary (CSGScanner & scan);
 

  Solid * ParsePrimary (CSGScanner & scan)
  {
    if (scan.GetToken() == TOK_PRIMITIVE)
      {
	switch (scan.GetPrimitiveToken())
	  {
	  case TOK_PLANE:
	    {
	      Point<3> p;
	      Vec<3> v;
	      
	      scan.ReadNext();
	      scan >> '(' >> p >> ';' >> v >> ')';

	      OneSurfacePrimitive * surf = new Plane ( p, v );
	      geom->AddSurfaces (surf);
	      return new Solid (surf);
	    }

	  case TOK_CYLINDER:
	    {
	      Point<3> pa, pb;
	      double r;
	      
	      scan.ReadNext();
	      scan >> '(' >> pa >> ';' >> pb >> ';' >> r >> ')';

	      OneSurfacePrimitive * surf = new Cylinder ( pa, pb, r );
	      geom->AddSurfaces (surf);
	      return new Solid (surf);
	    }

	  case TOK_ELLIPTICCYLINDER:
	    {
	      Point<3> pa;
	      Vec<3> vl, vs;
	      
	      scan.ReadNext();
	      scan >> '(' >> pa >> ';' >> vl >> ';' >> vs >> ')';

	      OneSurfacePrimitive * surf = new EllipticCylinder ( pa, vl, vs);
	      geom->AddSurfaces (surf);
	      return new Solid (surf);
	    }


	  case TOK_ELLIPSOID:
	    {
	      Point<3> pa;
	      Vec<3> v1, v2, v3;
	      
	      scan.ReadNext();
	      scan >> '(' >> pa >> ';' >> v1 >> ';' >> v2 >> ';' >> v3 >> ')';

	      OneSurfacePrimitive * surf = new Ellipsoid ( pa, v1, v2, v3);
	      geom->AddSurfaces (surf);
	      return new Solid (surf);
	    }


	  case TOK_CONE:
	    {
	      Point<3> pa, pb;
	      double ra, rb;
	      
	      scan.ReadNext();
	      scan >> '(' >> pa >> ';' >> ra >> ';' >> pb >> ';' >> rb >> ')';

	      OneSurfacePrimitive * surf = new Cone ( pa, pb, ra, rb );
	      geom->AddSurfaces (surf);
	      return new Solid (surf);
	    }



	  case TOK_SPHERE:
	    {
	      Point<3> p;
	      double r;
	      
	      scan.ReadNext();
	      scan >> '(' >> p >> ';' >> r >> ')';

	      OneSurfacePrimitive * surf = new Sphere ( p, r );
	      geom->AddSurfaces (surf);
	      return new Solid (surf);
	    }

	  case TOK_ORTHOBRICK:
	    {
	      Point<3> pa, pb;
	      
	      scan.ReadNext();
	      scan >> '(' >> pa >> ';' >> pb >> ')';
	      
	      Primitive * nprim = new OrthoBrick (pa, pb);
	      geom->AddSurfaces (nprim);
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
		  p = Point<3> (ParseVector (scan));
		  ParseChar (scan, ';');

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

	      geom->AddSurfaces (polyhedron);
	      return new Solid (polyhedron);
	    }


	  case TOK_EXTRUSION:     // not functional
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

	      // int npseg = 0;
	      // int nseg = 0;
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
	      
	      geom->AddSurfaces (extrusion);
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
	      v = ParseVector (scan);
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

	      scan >> '(' >> v >> ';' >> n >> ';';

	      Solid * sol1 = ParseSolid (scan);
	      
	      scan >> ')';
	      
	      Solid * hsol = sol1;
	      for (int i = 1; i <= n; i++)
		{
		  Solid * nsol = sol1 -> Copy(*geom);
		  Transformation<3> trans(double(i) * v);
		  
		  nsol -> Transform (trans);
		  hsol = new Solid (Solid::UNION, hsol, nsol); 
		}
	      return hsol;
	    }


	  case TOK_MULTIROTATE: 
	    {
	      Point<3> c;
	      Vec<3> v;
	      int n;
	      
	      scan.ReadNext();

	      scan >> '(' >> c >> ';' >> v >> ';' >> n >> ';';
	      Solid * sol1 = ParseSolid (scan);
	      scan >> ')';

	      Transformation<3> trans(c, v(0), v(1), v(2));
	      Transformation<3> multi(Vec<3>(0,0,0));
	      Transformation<3> ht;

	      Solid * hsol = sol1;
	      for (int i = 1; i <= n; i++)
		{
		  Solid * nsol = sol1 -> Copy(*geom);

		  nsol -> Transform (multi);
		  hsol = new Solid (Solid::UNION, hsol, nsol); 

		  ht=multi;
		  multi.Combine (trans, ht);
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
      return 0;

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
		    if (!geom->GetSolid (name))
		      scan.Error ("Top-Level-Object "+name+" not defined");

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

		      const TopLevelObject * domain = 
			geom->GetTopLevelObject (geom->GetSolid(flags.GetStringFlag ("tlo","")));

		      geom->AddIdentification 
			(new CloseSurfaceIdentification 
			 (geom->GetNIdentifications()+1, *geom, 
			  geom->GetSurface (si1[0]), geom->GetSurface (si2[0]),
			  domain,
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

	    else if (scan.GetToken() == TOK_SINGULAR)

	      {
		
		scan.ReadNext();
		switch (scan.GetToken())
		  {
		  case TOK_FACE:
		    {
		      scan.ReadNext();
		      
		      string name1 = scan.GetStringValue();  // tlo
		      scan.ReadNext();
		      
		      string name2 = scan.GetStringValue();
		      scan.ReadNext();
		      
		      Flags flags;
		      ParseFlags (scan, flags);
		      
		      ParseChar (scan, ';');
		      
		      const Solid * sol = geom->GetSolid(name2);

		      for (int i = 0; i < geom->GetNTopLevelObjects(); i++)
			if (name1 == geom->GetTopLevelObject (i)->GetSolid()->Name())
			  geom->singfaces.Append (new SingularFace (i+1, sol));

		      break;
		    }

		  case TOK_EDGE:
		    {
		      scan.ReadNext();
		      
		      string name1 = scan.GetStringValue();
		      scan.ReadNext();
		      
		      string name2 = scan.GetStringValue();
		      scan.ReadNext();
		      
		      Flags flags;
		      ParseFlags (scan, flags);
		      
		      ParseChar (scan, ';');
		      
		      const Solid * s1 = geom->GetSolid(name1);
		      const Solid * s2 = geom->GetSolid(name2);
		      geom->singedges.Append (new SingularEdge (1, s1, s2));
		      break;
		    }

		  case TOK_POINT:
		    {
		      scan.ReadNext();
		      
		      string name1 = scan.GetStringValue();
		      scan.ReadNext();
		      string name2 = scan.GetStringValue();
		      scan.ReadNext();
		      string name3 = scan.GetStringValue();
		      scan.ReadNext();
		      
		      Flags flags;
		      ParseFlags (scan, flags);
		      
		      ParseChar (scan, ';');
		      
		      const Solid * s1 = geom->GetSolid(name1);
		      const Solid * s2 = geom->GetSolid(name2);
		      const Solid * s3 = geom->GetSolid(name3);
		      geom->singpoints.Append (new SingularPoint (1, s1, s2, s3));
		      break;
		    }
		  default:
		    scan.Error ("keyword 'face' or 'edge' or 'point' expected");
		  }
	      }

	    
	    else if (scan.GetToken() == TOK_POINT)
	      {
		Point<3> p;

		scan.ReadNext();
		ParseChar (scan, '(');
		p = Point<3> (ParseVector (scan));
		ParseChar (scan, ')');
		ParseChar (scan, ';');

		geom->AddUserPoint (p);
	      }

	    else if (scan.GetToken() == TOK_BOUNDINGBOX)
	      {
		Point<3> p1, p2;
		
		scan.ReadNext();
		ParseChar (scan, '(');
		p1 = Point<3> (ParseVector (scan));
		ParseChar (scan, ';');
		p2 = Point<3> (ParseVector (scan));
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
	throw NgException (errstr);
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

