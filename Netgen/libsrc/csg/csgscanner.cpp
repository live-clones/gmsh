#include <mystdlib.h>
#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>


namespace netgen
{
  using namespace netgen;


  enum TOKEN_TYPE
    { 
      LP = '(', RP = ')', EQU = '=', COMMA = ',', SEMICOLON = ';',
      TOK_NUM, TOK_STRING, TOK_NAMED_SOLID, TOK_PRIMITIVE, 
      TOK_OR, TOK_AND, TOK_NOT,
      TOK_SOLID, TOK_RECO, TOK_TLO, TOK_BOUNDINGBOX,
      TOK_END };

  struct kwstruct
  {
    TOKEN_TYPE kw; 
    string name;
  };

  static kwstruct defkw[] =
    {
      { TOK_OR,      "or" },
      { TOK_AND,     "and" },
      { TOKEN_TYPE(0) }
    };

  enum PRIMITIVE_TYPE { TOK_SPHERE, TOK_CYLINDER, TOK_PLANE };

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
  
    void ReadNext();

    void Error (const string & err);
  };


  CSGScanner :: CSGScanner (istream & ascanin)
  {
    int i;

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
      case '=': case ',': case ';':
	{
	  token = TOKEN_TYPE (ch);
	  break;
	}
  
      default:
	{
	  if (isdigit (ch) || ch == '.' || ch == '-')
	    {
	      scanin->putback (ch);
	      (*scanin) >> num_value;
	      token = TOK_NUM;
	      return;
	    }

	  (*scanin).putback (ch);
	  (*scanin) >> string_value;

	  int nr = 0;
	  while (defkw[nr].kw)
	    {
	      if (string_value == defkw[nr].name)
		{
		  token = defkw[nr].kw;
		  return;
		}
	    }
	
	  token = TOK_STRING;
	}
      }
  }

  void CSGScanner :: Error (const string & err)
  {
    stringstream errstr;
    errstr << "Parsing error in line " << linenum << ": " << endl << err << endl;
    /*
    errstr << "input continues with <<<";
    for (int i = 0; i < 50; i++)
      {
	char ch;
	scanin->get(ch);
	errstr << ch;
	if (scanin->eof())
	  {
	    errstr << "(end of file)";
	    break;
	  }
      }
    errstr << endl << ">>> stop parsing" << endl;
    throw Exception (errstr.str());
    */
  }
  


  
  
  void ParseCSG (istream & istr)
  {
    CSGScanner scan(istr);

    do
      {
	scan.ReadNext();
	cout << "token = " << int(scan.GetToken()) << endl;
      }
    while (scan.GetToken() != TOK_END);
  }


};

