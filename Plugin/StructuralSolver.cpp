#include "StructuralSolver.h"
#include "Context.h"
#include "Tools.h"
#include "Draw.h"
#include "Utils.h"
#include "Numeric.h"

extern Mesh *THEM;
extern Context_T CTX;

extern "C"
{
  GMSH_Plugin *GMSH_RegisterStructuralSolverPlugin()
  {
    return new StructuralSolver();
  }
}

Structural_BeamSection:: ~Structural_BeamSection()
{
  Mesh *kk = THEM;
  Init_Mesh(&m);
  THEM=kk;
}

Structural_BeamSection:: Structural_BeamSection( const char *direct, std::string _name )
: name (_name)
{    
  Mesh *kk = THEM;
  m.Vertices = NULL;
  m.Simplexes = NULL;
  m.Points = NULL;
  m.Curves = NULL;
  m.SurfaceLoops = NULL;
  m.EdgeLoops = NULL;
  m.Surfaces = NULL;
  m.Volumes = NULL;
  m.PhysicalGroups = NULL;
  m.Partitions = NULL;
  m.Metric = NULL;
  m.BGM.bgm = NULL;
  m.Grid.init = 0;
  Init_Mesh(&m);

  char temp[256];
  sprintf(temp, "%s/%s", direct,name.c_str());
  // read the section (msh format)
  FILE *f = fopen (temp,"r");  
  Read_Mesh (&m, f, temp,FORMAT_MSH);
  fclose(f);
  // get rid of the extension
  name.erase(name.find("."));
 // compute center of gravity, Area, Iy and Iz
  computeGeometricalProperties();
  CTX.mesh.changed = 0;
  THEM=kk;
}


void Structural_BeamSection :: computeGeometricalProperties ()
{
  xc=yc=area=Iy=Iz=0.0;
  List_T *surfaces = Tree2List (m.Surfaces);

  double M[3][3] = {{1,.5,.5},
		    {.5,1,.5},
		    {.5,.5,1}};

  for (int i=0;i<List_Nbr(surfaces);++i)
    {
      Surface *s;
      List_Read(surfaces,i,&s);
      List_T *triangles = Tree2List(s->Simplexes);
      for(int j=0;j<List_Nbr(triangles);++j)
	{
	  Simplex *simp;
	  List_Read(triangles,j,&simp);
	  Vertex v = (*simp->V[0]+*simp->V[1]+*simp->V[2])*0.333333333333333333;
	  double A = simp->surfsimpl();
	  area+=A;
	  xc += v.Pos.X*A;
	  yc += v.Pos.Y*A;
	}
      xc/=area;
      yc/=area;
      for(int j=0;j<List_Nbr(triangles);++j)
	{
	  Simplex *simp;
	  List_Read(triangles,j,&simp);
	  double A = simp->surfsimpl();
	  {
	    double dy[3] = {simp->V[0]->Pos.Y-yc,simp->V[1]->Pos.Y-yc,simp->V[2]->Pos.Y-yc};
	    Iy+= A *
	      dy[0] * (M[0][0] * dy[0] + M[0][1] * dy[1] + M[0][2] * dy[2]) +
	      dy[1] * (M[1][0] * dy[0] + M[1][1] * dy[1] + M[1][2] * dy[2]) +
	      dy[2] * (M[2][0] * dy[0] + M[2][1] * dy[1] + M[2][2] * dy[2]);
	  }
	  {
	    double dy[3] = {simp->V[0]->Pos.X-xc,simp->V[1]->Pos.X-xc,simp->V[2]->Pos.X-xc};
	    Iz+= A * 
	      dy[0] * (M[0][0] * dy[0] + M[0][1] * dy[1] + M[0][2] * dy[2]) +
	      dy[1] * (M[1][0] * dy[0] + M[1][1] * dy[1] + M[1][2] * dy[2]) +
	      dy[2] * (M[2][0] * dy[0] + M[2][1] * dy[1] + M[2][2] * dy[2]);
	  }
	}
      List_Delete(triangles);
    }
  List_Delete(surfaces);  
  printf("%s %g %g %g %g %g\n",name.c_str(),area,xc,yc,Iy,Iz);
}

void Structural_Texture::setup ()
{

#ifdef HAVE_FLTK  
  Fl_PNG_Image image(filename.c_str());

  // allocate a texture name
  glGenTextures( 1, &tag );
  
  // select our current texture
  glBindTexture( GL_TEXTURE_2D, tag );
   
  // select modulate to mix texture with color for shading
  //  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
  // when texture area is small, bilinear filter the closest mipmap
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
  		   GL_LINEAR_MIPMAP_NEAREST );
  // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
  // if wrap is true, the texture wraps over at the edges (repeat)
  //       ... false, the texture ends at the edges (clamp)
  bool wrap = false;
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
		   wrap ? GL_REPEAT : GL_CLAMP );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
		    wrap ? GL_REPEAT : GL_CLAMP );

  const uchar *data = image.array;
  gluBuild2DMipmaps( GL_TEXTURE_2D, 
		     3, 
		     image.w(), 
		     image.h(),
		     GL_RGB, 
		     GL_UNSIGNED_BYTE, 
		     data );
#endif
}

void Structural_BeamSection ::  GL_DrawBeam (double pinit[3], double dir[3], const double dirz[3], Structural_Texture &texture)
{
#ifdef HAVE_FLTK

  if (texture.tag==0)
    {
      texture.setup();
    }

  double X[3] = {dir[0],dir[1],dir[2]};
  double Z[3] = {dirz[0],dirz[1],dirz[2]};
  double Y[3];
  prodve(X,Z,Y);
  double transl[3] = {pinit[0]-xc,pinit[1]-yc,pinit[2]};
  double rot[3][3] = {{Z[0],Y[0],X[0]},
		      {Z[1],Y[1],X[1]},
		      {Z[2],Y[2],X[2]}};
  
  double invrot[3][3] = {{Z[0],Z[1],Z[2]},
			 {Y[0],Y[1],Y[2]},
			 {X[0],X[1],X[2]}};
  
  List_T *vertices = Tree2List (m.Vertices);
  Vertex *vert;
  for (int i=0;i<List_Nbr(vertices);++i)
    {
      List_Read ( vertices,i,&vert);
      Projette ( vert, rot);
      vert->Pos.X += transl[0];
      vert->Pos.Y += transl[1];
      vert->Pos.Z += transl[2];
    }

  List_T *surfaces = Tree2List (m.Surfaces);
  List_T *curves = Tree2List (m.Curves);
  List_T *points = Tree2List (m.Points);
  glEnable(GL_POLYGON_OFFSET_FILL);
  if(CTX.geom.light) glEnable(GL_LIGHTING);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glEnable( GL_TEXTURE_2D );  
  glBindTexture( GL_TEXTURE_2D, texture.tag );

  for (int i=0;i<List_Nbr(surfaces);++i)
    {
      Surface *s;
      List_Read(surfaces,i,&s);
      List_T *triangles = Tree2List(s->Simplexes);
      //      printf("%g %g %d %d\n",xc,yc,List_Nbr(vertices),List_Nbr(triangles));
      for(int j=0;j<List_Nbr(triangles);++j)
	{
	  Simplex *simp;
	  List_Read(triangles,j,&simp);	
	  glBegin(GL_TRIANGLES);
	  glNormal3d ( -X[0],-X[1],-X[2] );
	  glTexCoord2d(0,0);glVertex3d ( simp->V[0]->Pos.X,simp->V[0]->Pos.Y,simp->V[0]->Pos.Z);
	  glTexCoord2d(0,1);glVertex3d ( simp->V[1]->Pos.X,simp->V[1]->Pos.Y,simp->V[1]->Pos.Z);
	  glTexCoord2d(1,1);glVertex3d ( simp->V[2]->Pos.X,simp->V[2]->Pos.Y,simp->V[2]->Pos.Z);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glNormal3d ( X[0],X[1],X[2] );
	  glTexCoord2d(0,0);glVertex3d ( simp->V[0]->Pos.X+dir[0],simp->V[0]->Pos.Y+dir[1],simp->V[0]->Pos.Z+dir[2]);
	  glTexCoord2d(0,1);glVertex3d ( simp->V[1]->Pos.X+dir[0],simp->V[1]->Pos.Y+dir[1],simp->V[1]->Pos.Z+dir[2]);
	  glTexCoord2d(1,1);glVertex3d ( simp->V[2]->Pos.X+dir[0],simp->V[2]->Pos.Y+dir[1],simp->V[2]->Pos.Z+dir[2]);
	  glEnd();
	}
      List_Delete(triangles);
    }
  for (int i=0;i<List_Nbr(curves);++i)
    {
      Curve *c;
      List_Read(curves,i,&c);
      List_T *lines = Tree2List(c->Simplexes);
      //      printf("%g %g %d %d\n",xc,yc,List_Nbr(vertices),List_Nbr(triangles));
      for(int j=0;j<List_Nbr(lines);++j)
	{
	  Simplex *simp;
	  List_Read(lines,j,&simp);	
	  double dir1[3] = { simp->V[0]->Pos.X-simp->V[1]->Pos.X,
			     simp->V[0]->Pos.Y-simp->V[1]->Pos.Y,
			     simp->V[0]->Pos.Z-simp->V[1]->Pos.Z};
	  double dir2[3];
	  double L1 = sqrt(dir1[0]*dir1[0]+dir1[1]*dir1[1]+dir1[2]*dir1[2]);
	  double L = sqrt(dir[0]*dir[0]+dir[1]*dir[1]+dir[2]*dir[2]);

	  norme(dir1);
	  prodve(dir1,X,dir2);
	  glBegin(GL_POLYGON);
	  glNormal3dv (dir2); 
	  glTexCoord2d(0,0);glVertex3d ( simp->V[0]->Pos.X,simp->V[0]->Pos.Y,simp->V[0]->Pos.Z);
	  glTexCoord2d(0,L1/L);glVertex3d ( simp->V[1]->Pos.X,simp->V[1]->Pos.Y,simp->V[1]->Pos.Z);
	  glTexCoord2d(1,L1/L);glVertex3d ( simp->V[1]->Pos.X+dir[0],simp->V[1]->Pos.Y+dir[1],simp->V[1]->Pos.Z+dir[2]);
	  glTexCoord2d(1,0);glVertex3d ( simp->V[0]->Pos.X+dir[0],simp->V[0]->Pos.Y+dir[1],simp->V[0]->Pos.Z+dir[2]);
	  glEnd();

	}
      List_Delete(lines);
    }
  List_Delete(points);  
  List_Delete(curves);  
  List_Delete(surfaces);  

  for (int i=0;i<List_Nbr(vertices);++i)
    {
      List_Read ( vertices,i,&vert);
      vert->Pos.X -= transl[0];
      vert->Pos.Y -= transl[1];
      vert->Pos.Z -= transl[2];
      Projette ( vert, invrot);
    }
  List_Delete (vertices);
  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
  glDisable( GL_TEXTURE_2D );  
  glColor4ubv((GLubyte *) & CTX.color.geom.line);

#endif
}


void StructuralSolver :: RegisterBeamSections ()
{
#if defined(HAVE_FLTK)
  struct dirent **list;
  char ext[6];

  char *homeplugins = getenv("GMSHPLUGINSHOME");
  if(!homeplugins) 
    return;

  int nbFiles = fl_filename_list(homeplugins, &list);
  if(nbFiles <= 0)
    return;
  for(int i = 0; i < nbFiles; i++) {
    char *name = list[i]->d_name;
    if(strlen(name) > 3) {
      strcpy(ext, name + (strlen(name) - 3));
      if(!strcmp(ext, "msh")) {
	Structural_BeamSection *section = 
	  new Structural_BeamSection ( homeplugins, std::string(name) );
	beam_sections.push_back ( section );
      }
      if(!strcmp(ext, "png")) {
	char temp[256];
	sprintf(temp, "%s/%s", homeplugins,name);
	//	GLuint texture_id = RegisterTexture ( temp );
	std::string aaa (name);
	aaa.erase(aaa.find("."));
	Structural_Texture tt;
	tt.filename=std::string(temp);
	tt.tag=0;
	textures[aaa] = tt;
      }
    }
  }
  for(int i = 0; i < nbFiles; i++)
    free(list[i]);
  free(list);
#endif

}


void StructuralSolver :: RegisterMaterials ()
{
#if defined(HAVE_FLTK)
  char *homeplugins = getenv("GMSHPLUGINSHOME");
  if(!homeplugins) 
    return;

  char temp[256];
  int nbpar;
  sprintf(temp, "%s/%s", homeplugins,"Materials");
  FILE *f = fopen (temp,"r");  
  if (!f) return;
  while(!feof(f))
    {
      Structural_Material material;
      fscanf(f,"%s %d",temp,&nbpar);
      material.name = std::string(temp);
      for (int i=0;i<nbpar;++i)
	{
	  double param;
	  fscanf(f,"%lf",&param);
	  material.par.push_back(param);	  
	}
      materials.push_back(material);
    }
  fclose(f);
  

#endif

}


void StructuralSolver::getName(char *name) const
{
  strcpy(name, "Structural Solver");
}

void StructuralSolver::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Structural Solver  failed...");
}

void StructuralSolver::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Interface to a structural solver\n");
}


StructuralSolver :: StructuralSolver ()
#ifdef HAVE_FLTK 
  : _window(0), MAX_FORCE(0),MAX_DISPLACEMENT(0)
#endif
{
  RegisterBeamSections ();
  RegisterMaterials ();
}

StructuralSolver :: ~StructuralSolver ()
{
  {
    std::list<struct Structural_BeamSection* > :: iterator it  = beam_sections.begin();
    std::list<struct Structural_BeamSection* > :: iterator ite = beam_sections.end();
    
    for (;it!=ite;++it)
      {
	delete *it;
      }
  }
#ifdef HAVE_FLTK 
  if(_window)delete _window;;
  {
    std::map<std::string, struct Structural_Texture > :: iterator it  = textures.begin();
    std::map<std::string, struct Structural_Texture > :: iterator ite = textures.end();      
    for (;it!=ite;++it)
      {
	GLuint texture = it->second.tag;
	glDeleteTextures( 1, &texture );
      }
  }
#endif
}

Structural_BeamSection * StructuralSolver :: GetBeamSection (const std::string & name) const
{
  std::list<struct Structural_BeamSection* > :: const_iterator it  = beam_sections.begin();
  std::list<struct Structural_BeamSection* > :: const_iterator ite = beam_sections.end();

  for (;it!=ite;++it)
    {
      if ((*it)->name == name)
	return *it;
    }
  return 0;
}
Structural_Material StructuralSolver :: GetMaterial (const std::string & name) const 
{
  std::list<struct Structural_Material > :: const_iterator it  = materials.begin();
  std::list<struct Structural_Material > :: const_iterator ite = materials.end();

  for (;it!=ite;++it)
    {
      if ((*it).name == name)
	return *it;
    }
  
  // just to fix the warning...
  return *it;
}


#define BEAM_SECTION_ 3
#define BEAM_MATERIAL_ 4
#define POINT_ALONG_ 0
#define POINT_ACROSS_ 1
#define POINT_AROUND_ 2
#define ANGLE_ 3
#define ALONG_ 0
#define ACROSS_ 1
#define AROUND_ 2

void close_cb(Fl_Widget* w, void* data)
{
  if(data) ((Fl_Window *) data)->hide();
}

void StructuralSolver ::popupPropertiesForPhysicalEntity (int dim)
{ 
#ifdef HAVE_FLTK 
  static Fl_Group *g[10];
  int i;
  int fontsize = CTX.fontsize;

#define WINDOW_BOX FL_FLAT_BOX
#define BH (2*fontsize+1) // button height
#define WB (6)            // window border
#define IW (17*fontsize)  // input field width
#define BB (7*fontsize)   // width of a button with internal label
  
  if(_window) {
    for(i = 0; i < 2; i++)
      g[i]->hide();
    g[dim]->show();
    _window->show();
    return;
  }
  
  int width = 31 * fontsize;
  int height = 5 * WB + 9 * BH;

  _window = new Fl_Window(width, height, "Structural Solver");
  _window->box(WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    // 0: 
    {
      g[0] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Physical Point");
      
      static Fl_Menu_Item _type[] = {
	{"Displacement fixed (mm)", 0, 0, 0},
	{"Load fixed (kN)", 0, 0, 0},
	{0}
      };

      _value[ANGLE_] = new Fl_Value_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Angle of Rotation");
      _value[ANGLE_]->value(90);
      _value[ANGLE_]->align(FL_ALIGN_RIGHT);

      _choice[POINT_ALONG_] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH, IW, BH, "Along the Local Axis");
      _choice[POINT_ALONG_]->menu(_type);
      _choice[POINT_ALONG_]->align(FL_ALIGN_RIGHT);
      
      _value[ALONG_] = new Fl_Value_Input(2 * WB, 2 * WB + 3 * BH, IW, BH,"Value");
      _value[ALONG_]->value(0.0);
      _value[ALONG_]->align(FL_ALIGN_RIGHT);
      
      _choice[POINT_ACROSS_] = new Fl_Choice(2 * WB, 2 * WB + 4 * BH, IW, BH, "Across the Local Axis");
      _choice[POINT_ACROSS_]->menu(_type);
      _choice[POINT_ACROSS_]->align(FL_ALIGN_RIGHT);
      
      _value[ACROSS_] = new Fl_Value_Input(2 * WB, 2 * WB + 5 * BH, IW, BH,"Value");
      _value[ACROSS_]->value(0.0);
      _value[ACROSS_]->align(FL_ALIGN_RIGHT);
      
      
      _choice[POINT_AROUND_] = new Fl_Choice(2 * WB, 2 * WB + 6 * BH, IW, BH, "Around Z axis");
      _choice[POINT_AROUND_]->menu(_type);
      _choice[POINT_AROUND_]->align(FL_ALIGN_RIGHT);
      
      _value[AROUND_] = new Fl_Value_Input(2 * WB, 2 * WB + 7 * BH, IW, BH,       "");
      _value[AROUND_]->value(0.0);
      _value[AROUND_]->align(FL_ALIGN_RIGHT);
      g[0]->end();
    }
    // 2: Physical Line
    {
      g[1] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Physical Line");
      {
	_choice[BEAM_SECTION_] = new Fl_Choice(2 * WB, 2 * WB + 1 * BH, IW, BH, "Beam Section");      
	std::list<struct Structural_BeamSection* > :: iterator it  = beam_sections.begin();
	std::list<struct Structural_BeamSection* > :: iterator ite = beam_sections.end();      
	for (;it!=ite;++it)
	  {
	    _choice[BEAM_SECTION_]->add ((*it)->name.c_str());
	  }
	_choice[BEAM_SECTION_]->align(FL_ALIGN_RIGHT);
      }
      {
	_choice[BEAM_MATERIAL_] = new Fl_Choice(2 * WB, 2 * WB + 2 * BH, IW, BH, "Material");      
	std::list<struct Structural_Material > :: iterator it  = materials.begin();
	std::list<struct Structural_Material > :: iterator ite = materials.end();      
	for (;it!=ite;++it)
	  {
	    _choice[BEAM_MATERIAL_]->add ((*it).name.c_str());
	  }
	_choice[BEAM_MATERIAL_]->align(FL_ALIGN_RIGHT);
      }

      _value[6] = new Fl_Value_Input(2 * WB, 2 * WB + 3 * BH, IW/2, BH,       "");
      _value[6]->value(0.0);
      _value[6]->align(FL_ALIGN_RIGHT);
      _value[7] = new Fl_Value_Input(2 * WB+IW/2, 2 * WB + 3 * BH, IW/2, BH, "X-Load");
      _value[7]->value(0.0);
      _value[7]->align(FL_ALIGN_RIGHT);
      _value[8] = new Fl_Value_Input(2 * WB, 2 * WB + 4 * BH, IW/2, BH,       "");
      _value[8]->value(0.0);
      _value[8]->align(FL_ALIGN_RIGHT);
      _value[9] = new Fl_Value_Input(2 * WB+IW/2, 2 * WB + 4 * BH, IW/2, BH, "Y-Load");
      _value[9]->value(0.0);
      _value[9]->align(FL_ALIGN_RIGHT);
      _value[10] = new Fl_Value_Input(2 * WB, 2 * WB + 5 * BH, IW/2, BH,       "");
      _value[10]->value(0.0);
      _value[10]->align(FL_ALIGN_RIGHT);
      _value[11] = new Fl_Value_Input(2 * WB+IW/2, 2 * WB + 5 * BH, IW/2, BH, "Z-Load");
      _value[11]->value(0.0);
      _value[11]->align(FL_ALIGN_RIGHT);
      
      _value[12] = new Fl_Value_Input(2 * WB, 2 * WB + 6 * BH, IW/3, BH,       "");
      _value[12]->value(0.0);
      _value[12]->align(FL_ALIGN_RIGHT);
      _value[13] = new Fl_Value_Input(2 * WB+IW/3, 2 * WB + 6 * BH, IW/3, BH,       "");
      _value[13]->value(0.0);
      _value[13]->align(FL_ALIGN_RIGHT);
      _value[14] = new Fl_Value_Input(2 * WB+2*IW/3, 2 * WB + 6 * BH, IW/3, BH, "Y-Direction");
      _value[14]->value(1.0);
      _value[14]->align(FL_ALIGN_RIGHT);
      
      g[1]->end();
    }
    o->end();

    {
      Fl_Button *o = new Fl_Button(width - BB - WB, height - BH - WB, BB, BH, "Cancel");
      o->callback(close_cb, (void *)_window);
    }
    
  }
  _window->end();

#endif
}

void StructuralSolver :: addPhysicalLine (int id)
{ 
#ifdef HAVE_FLTK 
  PhysicalLineInfo info;  
  info.section = std::string(_choice[BEAM_SECTION_] ->mvalue()->text);  
  info.material= std::string(_choice[BEAM_MATERIAL_]->mvalue()->text);
  info.dirz[0]  = _value[12]->value();
  info.dirz[1]  = _value[13]->value();
  info.dirz[2]  = _value[14]->value();
  lines[id] = info;
#endif  
}

void StructuralSolver :: addPhysicalPoint (int id)
{ 
#ifdef HAVE_FLTK 
  PhysicalPointInfo info;

  info.angle = _value[ANGLE_]->value();

  info.disp[0] = _choice[POINT_ALONG_] ->value();
  info.disp[1] = _choice[POINT_ACROSS_] ->value();
  info.disp[2] = _choice[POINT_AROUND_] ->value();
  info.val[0] = _value[ALONG_]->value();
  info.val[1] = _value[ACROSS_]->value();
  info.val[2] = _value[AROUND_]->value();

  if (info.disp[0] == 0)
    MAX_FORCE = (MAX_FORCE>info.val[0])?MAX_FORCE:info.val[0];
  if (info.disp[1] == 0)
    MAX_FORCE = (MAX_FORCE>info.val[1])?MAX_FORCE:info.val[1];
  if (info.disp[2] == 0)
    MAX_FORCE = (MAX_FORCE>info.val[2])?MAX_FORCE:info.val[2];

  points[id] = info;
#endif
}

static PhysicalGroup * getPhysical ( int Num , int Dim )
{
  PhysicalGroup *p;
  for(int i = 0; i < List_Nbr(THEM->PhysicalGroups); i++) 
    { 
      List_Read(THEM->PhysicalGroups, i, &p);
      if(p->Typ == MSH_PHYSICAL_POINT    && Dim == 0 && p->Num == Num) return p;
      if(p->Typ == MSH_PHYSICAL_LINE     && Dim == 1 && p->Num == Num) return p;
      if(p->Typ == MSH_PHYSICAL_SURFACE  && Dim == 2 && p->Num == Num) return p;
      if(p->Typ == MSH_PHYSICAL_VOLUME  && Dim == 3 && p->Num == Num) return p;
    }
  return 0;
}

void StructuralSolver :: writeSolverFile ( const char *geom_file ) const
{
  char name[256];
  sprintf(name,"%s.str",geom_file);
  FILE *f = fopen(name,"w");  
  {
    std::map<int,struct PhysicalLineInfo>  :: const_iterator it  = lines.begin();
    std::map<int,struct PhysicalLineInfo > :: const_iterator ite = lines.end();      
    for (;it!=ite;++it)
      {
	const PhysicalLineInfo &i = (*it).second;
	int id = (*it).first;
	if (getPhysical ( id , 1 ))
	  {
	    fprintf(f,"BEAM PHYSICAL %d SECTION %s MATERIAL %s LOADS %g %g %g %g %g %g %g %g %g \n",
		    id,i.section.c_str(),i.material.c_str(),i.fx1,i.fy1,i.fx2,i.fy2,i.fz1,i.fz2,i.dirz[0],i.dirz[1],i.dirz[2]);
	  }
      }
  }
  {
    std::map<int,struct PhysicalPointInfo>  :: const_iterator it  = points.begin();
    std::map<int,struct PhysicalPointInfo > :: const_iterator ite = points.end();      
    for (;it!=ite;++it)
      {
	const PhysicalPointInfo &i = (*it).second;
	int id = (*it).first;
	if (getPhysical ( id , 0 ))
	  {
	    fprintf(f,"NODE %d %g %d %g %d %g %d %g \n",id,i.angle,i.disp[0],i.val[0],i.disp[1],i.val[1],i.disp[2],i.val[2]);
	  }
      }
  }
  fclose(f);  
  sprintf(name,"%s.m",geom_file);
  f = fopen(name,"w");  
  {
    std::map<int,struct PhysicalLineInfo>  :: const_iterator it  = lines.begin();
    std::map<int,struct PhysicalLineInfo > :: const_iterator ite = lines.end();      
    for (;it!=ite;++it)
      {
	const PhysicalLineInfo &i = (*it).second;
	int id = (*it).first;
	if (getPhysical ( id , 1 ))
	  {
	    Structural_BeamSection* bs = GetBeamSection (i.section);
	    Structural_Material    mt = GetMaterial    (i.material);
	    fprintf(f,"111 %d %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g\n",
		    id,                             // physical id
		    bs->area, bs->Iy, bs->Iz, bs->J,// section info
		    mt.par[0],mt.par[1],mt.par[2],// material info
		    i.fx1,i.fy1,i.fx2,i.fy2,i.fz1,i.fz2,// lineic loads
		    i.dirz[0],i.dirz[1],i.dirz[2]); // direction
	  }
      }
  }
  {
    std::map<int,struct PhysicalPointInfo>  :: const_iterator it  = points.begin();
    std::map<int,struct PhysicalPointInfo > :: const_iterator ite = points.end();      
    for (;it!=ite;++it)
      {
	const PhysicalPointInfo &i = (*it).second;
	int id = (*it).first;
	if (getPhysical ( id , 0 ))
	  {
	    fprintf(f,"222 %d %g %d %g %d %g %d %g \n",id,i.angle,i.disp[0],i.val[0],i.disp[1],i.val[1],i.disp[2],i.val[2]);
	  }
      }
  }
  fclose(f);  
}

void StructuralSolver :: readSolverFile ( const char *geom_file ) 
{
  char name[256],line[256],a1[24],a2[24],a3[24],a4[240],a5[24],a6[240],a7[24];
  sprintf(name,"%s.str",geom_file);
  FILE *f = fopen(name,"r");  
  if (!f)return;

  while(!feof(f))
    {
      fgets(line,256,f);
      sscanf (line,"%s",name);
      if (!strcmp(name,"BEAM"))
	{
	  int id;
	  PhysicalLineInfo info;
	  sscanf(line,"%s %s %d %s %s %s %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",
		 a1,a2,&id,a3,a4,a5,a6,a7,&info.fx1,&info.fy1,&info.fx2,&info.fy2,&info.fz1,&info.fz2,&info.dirz[0],&info.dirz[1],&info.dirz[2]);
	  info.material = std::string(a6);
	  info.section  = std::string(a4);
	  lines[id] = info;
	}
      if (!strcmp(name,"NODE"))
	{
	  int id;
	  PhysicalPointInfo info;
	  sscanf(line,"%s %d %lf %d %lf %d %lf %d %lf \n",a1,&id,
		 &info.angle,
		 &info.disp[0],&info.val[0],
		 &info.disp[1],&info.val[1],
		 &info.disp[2],&info.val[2]);
	  points[id] = info;
	  if (info.disp[0] == 1)
	    MAX_FORCE = (MAX_FORCE>fabs(info.val[0]))?MAX_FORCE:fabs(info.val[0]);
	  if (info.disp[1] == 1)
	    MAX_FORCE = (MAX_FORCE>fabs(info.val[1]))?MAX_FORCE:fabs(info.val[1]);
	}
      if (feof(f) )break;
    }
  printf("max force = %g\n",MAX_FORCE);
  fclose(f);
}


void Draw_Kinematic_Constraint ( const int type [3], 
				 const double size, 
				 const double pos[3], 
				 double dir[3])
{
#ifdef HAVE_FLTK

  // presently, it's only 2D , 1st and second component are for dir and dir2 
  // and third one is for rotation around z

  double dir2[3];
  double ez[3]={0,0,1};
  prodve(dir,ez,dir2);

  double size_feature = size*0.5;
  double width_ground = size*0.25;

  if(!type[0] && !type[1] && !type[2]) // clamped
    {
      size_feature = 0.0;
      width_ground = 0.5*size;
    }

  if(type[0] && type[1] && type[2]) // free
    {
      return;
    }

  if(CTX.geom.light) glEnable(GL_LIGHTING);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnable(GL_POLYGON_OFFSET_FILL);
  glColor3f    (0.8,0.8,0.8);
  
  glBegin(GL_QUADS);
  glVertex3d ( pos[0] - size_feature * dir [0] - size * 0.5 * dir2 [0],
	       pos[1] - size_feature * dir [1] - size * 0.5 * dir2 [1],
	       pos[2] - size_feature * dir [2] - size * 0.5 * dir2 [2]);
  glVertex3d ( pos[0] - size_feature * dir [0] + size * 0.5 * dir2 [0],
	       pos[1] - size_feature * dir [1] + size * 0.5 * dir2 [1],
	       pos[2] - size_feature * dir [2] + size * 0.5 * dir2 [2]);
  glVertex3d ( pos[0] - size_feature * dir [0] - width_ground * dir[0] + size * 0.5 * dir2 [0],
	       pos[1] - size_feature * dir [1] - width_ground * dir[1] + size * 0.5 * dir2 [1],
	       pos[2] - size_feature * dir [2] - width_ground * dir[2] + size * 0.5 * dir2 [2]);
  glVertex3d ( pos[0] - size_feature * dir [0] - width_ground * dir[0] - size * 0.5 * dir2 [0],
	       pos[1] - size_feature * dir [1] - width_ground * dir[1] - size * 0.5 * dir2 [1],
	       pos[2] - size_feature * dir [2] - width_ground * dir[2] - size * 0.5 * dir2 [2]);
  glEnd();
  
  
  glColor3f(0,0,0);

  glLineWidth(2);

  if (!type[0])
    {
      glBegin(GL_LINES);
      glVertex3d ( pos[0] - size_feature * dir [0] - size * 0.5 * dir2 [0],
		   pos[1] - size_feature * dir [1] - size * 0.5 * dir2 [1],
		   pos[2] - size_feature * dir [2] - size * 0.5 * dir2 [2]);
      glVertex3d ( pos[0] - size_feature * dir [0] + size * 0.5 * dir2 [0],
		   pos[1] - size_feature * dir [1] + size * 0.5 * dir2 [1],
		   pos[2] - size_feature * dir [2] + size * 0.5 * dir2 [2]);
      glEnd();
    }
  
  if(type[0] || type[1] || type[2]) // everything except clamped
    {
      double radius_circle = size_feature * 0.5;
      double radius_circle2 = size_feature * 0.5;

      if (!type[1]) radius_circle = 0;
      if (!type[2]) radius_circle2 = 0;

      if (!type[0])
	{
	  glBegin(GL_LINES);
	  
	  glVertex3d ( pos[0] - (size_feature-radius_circle) * dir [0] - size * 0.5 * dir2 [0],
		       pos[1] - (size_feature-radius_circle) * dir [1] - size * 0.5 * dir2 [1],
		       pos[2] - (size_feature-radius_circle) * dir [2] - size * 0.5 * dir2 [2]);
	  glVertex3d ( pos[0],pos[1],pos[2] );
	  glEnd();
	  
	  glBegin(GL_LINES);
	  glVertex3d ( pos[0] - (size_feature-radius_circle) * dir [0] + size * 0.5 * dir2 [0],
		       pos[1] - (size_feature-radius_circle) * dir [1] + size * 0.5 * dir2 [1],
		       pos[2] - (size_feature-radius_circle) * dir [2] + size * 0.5 * dir2 [2]);
	  glVertex3d ( pos[0],pos[1],pos[2] );
	  glEnd();
	}

      if (!type[0]){
	glColor4f(1,1,1,1);
	Draw_Disk (radius_circle2*.5*.8, 0.00, pos[0], pos[1], pos[2]+0.01*radius_circle2,CTX.geom.light); 
	glColor4f(0,0,0,1);
	Draw_Disk (radius_circle2*.5, 0.8, pos[0], pos[1], pos[2],CTX.geom.light); 
      }

      if (!type[1] || !type[0]){
	glBegin(GL_LINES);
	glVertex3d ( pos[0] - (size_feature-radius_circle) * dir [0] - size * 0.5 * dir2 [0],
		     pos[1] - (size_feature-radius_circle) * dir [1] - size * 0.5 * dir2 [1],
		     pos[2] - (size_feature-radius_circle) * dir [2] - size * 0.5 * dir2 [2]);
	
	glVertex3d ( pos[0] - (size_feature-radius_circle) * dir [0] + size * 0.5 * dir2 [0],
		     pos[1] - (size_feature-radius_circle) * dir [1] + size * 0.5 * dir2 [1],
		     pos[2] - (size_feature-radius_circle) * dir [2] + size * 0.5 * dir2 [2]);
	glEnd();	
	glColor4f(1,1,1,1);
	Draw_Disk (radius_circle*.5 * .8, 0.0, 
		   pos[0] - (size_feature-radius_circle) * dir [0] - size * 0.5 * dir2 [0] - radius_circle * 0.5 * dir[0] + radius_circle * 0.5 * dir2[0],
		   pos[1] - (size_feature-radius_circle) * dir [1] - size * 0.5 * dir2 [1] - radius_circle * 0.5 * dir[1] + radius_circle * 0.5 * dir2[1],
		   pos[2] - (size_feature-radius_circle) * dir [2] - size * 0.5 * dir2 [2] - radius_circle * 0.5 * dir[2] + radius_circle * 0.5 * dir2[2],
		   CTX.geom.light); 
	Draw_Disk (radius_circle*.5 * .8, 0.0, 
		   pos[0] - (size_feature-radius_circle) * dir [0] + size * 0.5 * dir2 [0] - radius_circle * 0.5 * dir[0] - radius_circle * 0.5 * dir2[0],
		   pos[1] - (size_feature-radius_circle) * dir [1] + size * 0.5 * dir2 [1] - radius_circle * 0.5 * dir[1] - radius_circle * 0.5 * dir2[1],
		   pos[2] - (size_feature-radius_circle) * dir [2] + size * 0.5 * dir2 [2] - radius_circle * 0.5 * dir[2] - radius_circle * 0.5 * dir2[2],
		   CTX.geom.light); 
	Draw_Disk (radius_circle*.5 * .8, 0., 
		   pos[0] - (size_feature-radius_circle) * dir [0] - radius_circle * 0.5 * dir[0],
		   pos[1] - (size_feature-radius_circle) * dir [1] - radius_circle * 0.5 * dir[1],
		   pos[2] - (size_feature-radius_circle) * dir [2] - radius_circle * 0.5 * dir[2],
		   CTX.geom.light); 
	glColor4f(0,0,0,1);
	Draw_Disk (radius_circle*.5, 0.8, 
		   pos[0] - (size_feature-radius_circle) * dir [0] - size * 0.5 * dir2 [0] - radius_circle * 0.5 * dir[0] + radius_circle * 0.5 * dir2[0],
		   pos[1] - (size_feature-radius_circle) * dir [1] - size * 0.5 * dir2 [1] - radius_circle * 0.5 * dir[1] + radius_circle * 0.5 * dir2[1],
		   pos[2] - (size_feature-radius_circle) * dir [2] - size * 0.5 * dir2 [2] - radius_circle * 0.5 * dir[2] + radius_circle * 0.5 * dir2[2],
		   CTX.geom.light); 
	Draw_Disk (radius_circle*.5, 0.8, 
		   pos[0] - (size_feature-radius_circle) * dir [0] + size * 0.5 * dir2 [0] - radius_circle * 0.5 * dir[0] - radius_circle * 0.5 * dir2[0],
		   pos[1] - (size_feature-radius_circle) * dir [1] + size * 0.5 * dir2 [1] - radius_circle * 0.5 * dir[1] - radius_circle * 0.5 * dir2[1],
		   pos[2] - (size_feature-radius_circle) * dir [2] + size * 0.5 * dir2 [2] - radius_circle * 0.5 * dir[2] - radius_circle * 0.5 * dir2[2],
		   CTX.geom.light); 
	Draw_Disk (radius_circle*.5, 0.8, 
		   pos[0] - (size_feature-radius_circle) * dir [0] - radius_circle * 0.5 * dir[0],
		   pos[1] - (size_feature-radius_circle) * dir [1] - radius_circle * 0.5 * dir[1],
		   pos[2] - (size_feature-radius_circle) * dir [2] - radius_circle * 0.5 * dir[2],
		   CTX.geom.light); 
      }

    }


  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
  glColor4ubv((GLubyte *) & CTX.color.geom.point);

#endif  
}


bool StructuralSolver :: GL_enhancePoint ( Vertex *v) 
{
#ifdef HAVE_FLTK  
  PhysicalGroup *p;
  for(int i = 0; i < List_Nbr(THEM->PhysicalGroups); i++) 
    { 
      char Num[100];
      List_Read(THEM->PhysicalGroups, i, &p);
      if(p->Typ == MSH_PHYSICAL_POINT) {
	if(List_Search(p->Entities, &v->Num, fcmp_absint)) { 
	  std::map<int,struct PhysicalPointInfo>::const_iterator it = points.find(p->Num);
	  if (it !=points.end())
	    {	
    
	      double angle = 3.1415926*it->second.angle/180;
	      
	      double size = 0.05*(CTX.max[0]-CTX.min[0]);
	      double dir[3] = {cos(angle),sin(angle),0};
	      double dir2[3];
	      double Z[3]={0,0,1};
	      prodve(dir,Z,dir2);
	      norme(dir);
	      double pos[3] = {v->Pos.X,v->Pos.Y,v->Pos.Z};
	      Draw_Kinematic_Constraint (it->second.disp,size,pos,dir);

	      double dv[3] = {0,0,0};		  
	      
	      if (it->second.disp[0] == 1)
		{
		  dv[0] += dir[0] * it->second.val[0];
		  dv[1] += dir[1] * it->second.val[0];
		}
	      if (it->second.disp[1] == 1)
		{
		  dv[0] += dir2[0] * it->second.val[1];
		  dv[1] += dir2[1] * it->second.val[1];
		}

	      const double offset = 0.3 * CTX.gl_fontsize * CTX.pixel_equiv_x;
	      const double l = sqrt (dv[0]*dv[0]+dv[1]*dv[1]);
	      const double kk = (CTX.max[0]-CTX.min[0])*.1 / (MAX_FORCE);
	      if (l != 0.0)
		{
		  glColor4ubv((GLubyte *) & CTX.color.text);
		  Draw_Vector (CTX.vector_type,  0, CTX.arrow_rel_head_radius, 
			       CTX.arrow_rel_stem_length, 0.5*CTX.arrow_rel_stem_radius,
			       v->Pos.X-dv[0]*kk, v->Pos.Y-dv[1]*kk, v->Pos.Z-dv[2]*kk,
			       dv[0]*kk, dv[1]*kk, dv[2]*kk, NULL, CTX.geom.light);
		  sprintf(Num, "%g kN", l);
		  glRasterPos3d((v->Pos.X + dv[0])+ offset / CTX.s[0],
				(v->Pos.Y + dv[1])+ offset / CTX.s[1],
				(v->Pos.Z + dv[2])+ offset / CTX.s[2]);
		  Draw_String(Num);
		  glColor4ubv((GLubyte *) & CTX.color.geom.line);
		}
	      return true;
	    }
	}
      }
    }
#endif
  return false;
}

bool StructuralSolver :: GL_enhanceLine ( int CurveId, Vertex *v1, Vertex *v2) 
{
#ifdef HAVE_FLTK  
  //  return true;
  PhysicalGroup *p;
  for(int i = 0; i < List_Nbr(THEM->PhysicalGroups); i++) 
    { 
      List_Read(THEM->PhysicalGroups, i, &p);
      if(p->Typ == MSH_PHYSICAL_LINE) {
	if(List_Search(p->Entities, &CurveId, fcmp_absint)) { 
	  std::map<int,struct PhysicalLineInfo>::const_iterator it = lines.find(p->Num);
	  if (it !=lines.end())
	    {	      
	      double pinit [3] = {v1->Pos.X,v1->Pos.Y,v1->Pos.Z};
	      double dir [3] = {v2->Pos.X-v1->Pos.X,v2->Pos.Y-v1->Pos.Y,v2->Pos.Z-v1->Pos.Z};
	      Structural_BeamSection *section =  GetBeamSection (it->second.section);
	      if (section)
		{
		  section -> GL_DrawBeam (pinit,dir,it->second.dirz,textures[it->second.material]);
		  return true;
		}
	    }
	}
      }
    }
#endif
  return false;
}
