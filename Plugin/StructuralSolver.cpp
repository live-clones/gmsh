#include "StructuralSolver.h"
#include "Context.h"
#include "Tools.h"
#include "Draw.h"
#include "Utils.h"
#include "Numeric.h"

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#include <FL/filename.H>
#endif

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
  xc=yc=area=0.0;
  List_T *surfaces = Tree2List (m.Surfaces);
  for (int i=0;i<List_Nbr(surfaces);++i)
    {
      Surface *s;
      List_Read(surfaces,i,&s);
      List_T *triangles = Tree2List(s->Simplexes);
      for(int j=0;j<List_Nbr(triangles);++j)
	{
	  Simplex *simp;
	  List_Read(triangles,j,&simp);
	  Vertex v = *simp->V[0]+*simp->V[1]+*simp->V[2];
	  double A = simp->surfsimpl();
	  area+=A;
	  xc += v.Pos.X*A;
	  yc += v.Pos.Y*A;
	}
      xc/=area;
      yc/=area;
      List_Delete(triangles);
    }
  List_Delete(surfaces);  
  printf("%s %g %g %g\n",name.c_str(),area,xc,yc);
}

void Structural_BeamSection ::  GL_DrawBeam (double pinit[3], double dir[3])
{
#ifdef HAVE_FLTK


  double X[3] = {dir[0],dir[1],dir[2]};
  double Y[3];
  double Z[3] = {0,0,1};
  double nn = norme(X);
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
  if(CTX.geom.light) glEnable(GL_LIGHTING);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
	  glVertex3d ( simp->V[0]->Pos.X,simp->V[0]->Pos.Y,simp->V[0]->Pos.Z);
	  glNormal3d ( -X[0],-X[1],-X[2] );
	  glVertex3d ( simp->V[1]->Pos.X,simp->V[1]->Pos.Y,simp->V[1]->Pos.Z);
	  glNormal3d ( -X[0],-X[1],-X[2] );
	  glVertex3d ( simp->V[2]->Pos.X,simp->V[2]->Pos.Y,simp->V[2]->Pos.Z);
	  glEnd();
	  glBegin(GL_TRIANGLES);
	  glNormal3d ( X[0],X[1],X[2] );
	  glVertex3d ( simp->V[0]->Pos.X+dir[0],simp->V[0]->Pos.Y+dir[1],simp->V[0]->Pos.Z+dir[2]);
	  glNormal3d ( X[0],X[1],X[2] );
	  glVertex3d ( simp->V[1]->Pos.X+dir[0],simp->V[1]->Pos.Y+dir[1],simp->V[1]->Pos.Z+dir[2]);
	  glNormal3d ( X[0],X[1],X[2] );
	  glVertex3d ( simp->V[2]->Pos.X+dir[0],simp->V[2]->Pos.Y+dir[1],simp->V[2]->Pos.Z+dir[2]);
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
	  norme(dir1);
	  prodve(dir1,X,dir2);

	  glBegin(GL_POLYGON);
	  glNormal3dv (dir2); 
	  glVertex3d ( simp->V[0]->Pos.X,simp->V[0]->Pos.Y,simp->V[0]->Pos.Z);
	  glNormal3dv (dir2); 
	  glVertex3d ( simp->V[1]->Pos.X,simp->V[1]->Pos.Y,simp->V[1]->Pos.Z);
	  glNormal3dv (dir2); 
	  glVertex3d ( simp->V[1]->Pos.X+dir[0],simp->V[1]->Pos.Y+dir[1],simp->V[1]->Pos.Z+dir[2]);
	  glNormal3dv (dir2); 
	  glVertex3d ( simp->V[0]->Pos.X+dir[0],simp->V[0]->Pos.Y+dir[1],simp->V[0]->Pos.Z+dir[2]);
	  glEnd();
	}
      List_Delete(lines);
    }
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

#endif
}



void StructuralSolver :: RegisterBeamSections ()
{
#if defined(HAVE_FLTK)
  struct dirent **list;
  char ext[6];

  char *homeplugins = getenv("GMSHPLUGINSHOME");

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
  std::list<struct Structural_BeamSection* > :: iterator it  = beam_sections.begin();
  std::list<struct Structural_BeamSection* > :: iterator ite = beam_sections.end();

  for (;it!=ite;++it)
    {
      delete *it;
    }
#ifdef HAVE_FLTK 
  if(_window)delete _window;;
#endif
}

Structural_BeamSection * StructuralSolver :: GetBeamSection (const std::string & name)
{
  std::list<struct Structural_BeamSection* > :: iterator it  = beam_sections.begin();
  std::list<struct Structural_BeamSection* > :: iterator ite = beam_sections.end();

  for (;it!=ite;++it)
    {
      if ((*it)->name == name)
	return *it;
    }
}


#define BEAM_SECTION_ 3
#define BEAM_MATERIAL_ 4
#define POINT_X_ 0
#define POINT_Y_ 1
#define POINT_Z_ 2
#define X_A_ 0
#define X_B_ 1
#define Y_A_ 2
#define Y_B_ 3
#define Z_A_ 4
#define Z_B_ 5

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
	{"Displacement fixed", 0, 0, 0},
	{"Load fixed", 0, 0, 0},
	{0}
      };
      _choice[POINT_X_] = new Fl_Choice(2 * WB, 2 * WB + 1 * BH, IW, BH, "X-component");
      _choice[POINT_X_]->menu(_type);
      _choice[POINT_X_]->align(FL_ALIGN_RIGHT);
      
      _value[X_A_] = new Fl_Value_Input(2 * WB, 2 * WB + 2 * BH, IW/2, BH,       "");
      _value[X_A_]->align(FL_ALIGN_RIGHT);
      _value[X_B_] = new Fl_Value_Input(2 * WB+IW/2, 2 * WB + 2 * BH, IW/2, BH, "VAL = A * X + B");
      _value[X_B_]->align(FL_ALIGN_RIGHT);
      
      _choice[POINT_Y_] = new Fl_Choice(2 * WB, 2 * WB + 3 * BH, IW, BH, "Y-component");
      _choice[POINT_Y_]->menu(_type);
      _choice[POINT_Y_]->align(FL_ALIGN_RIGHT);
      
      
      _value[Y_A_] = new Fl_Value_Input(2 * WB, 2 * WB + 4 * BH, IW/2, BH,       "");
      _value[Y_A_]->align(FL_ALIGN_RIGHT);
      _value[Y_B_] = new Fl_Value_Input(2 * WB+IW/2, 2 * WB + 4 * BH, IW/2, BH, "VAL = A * X + B");
      _value[Y_B_]->align(FL_ALIGN_RIGHT);
      
      _choice[POINT_Z_] = new Fl_Choice(2 * WB, 2 * WB + 5 * BH, IW, BH, "Z-component (moment)");
      _choice[POINT_Z_]->menu(_type);
      _choice[POINT_Z_]->align(FL_ALIGN_RIGHT);
      
      _value[Z_A_] = new Fl_Value_Input(2 * WB, 2 * WB + 6 * BH, IW/2, BH,       "");
      _value[Z_A_]->align(FL_ALIGN_RIGHT);
      _value[Z_B_] = new Fl_Value_Input(2 * WB+IW/2, 2 * WB + 6 * BH, IW/2, BH, "VAL = A * X + B");
      _value[Z_B_]->align(FL_ALIGN_RIGHT);
      
      
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
      
      g[1]->end();
    }
    o->end();
  }
#endif
}

void StructuralSolver :: addPhysicalLine (int id)
{ 
#ifdef HAVE_FLTK 
  PhysicalLineInfo info;
  info.section = std::string(_choice[BEAM_SECTION_] ->mvalue()->text);  
  info.material= std::string(_choice[BEAM_MATERIAL_]->mvalue()->text); 
  lines[id] = info;
#endif  
}

void StructuralSolver :: addPhysicalPoint (int id)
{ 
#ifdef HAVE_FLTK 
  PhysicalPointInfo info;

  info.disp[0] = _choice[POINT_X_] ->value();
  info.disp[1] = _choice[POINT_Y_] ->value();
  info.disp[2] = _choice[POINT_Z_] ->value();
  info.val[0] = _value[X_A_]->value();
  info.val[1] = _value[X_B_]->value();
  info.val[2] = _value[Y_A_]->value();
  info.val[3] = _value[Y_B_]->value();
  info.val[4] = _value[Z_A_]->value();
  info.val[5] = _value[Z_B_]->value();

  if (info.disp[0] == 0)
    MAX_FORCE = (MAX_FORCE>info.val[0])?MAX_FORCE:info.val[0];
  if (info.disp[1] == 0)
    MAX_FORCE = (MAX_FORCE>info.val[1])?MAX_FORCE:info.val[1];
  if (info.disp[2] == 0)
    MAX_FORCE = (MAX_FORCE>info.val[2])?MAX_FORCE:info.val[2];

  points[id] = info;
#endif
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
	fprintf(f,"BEAM PHYSICAL %d SECTION %s MATERIAL %s LOADS %g %g %g %g\n",id,i.section.c_str(),i.material.c_str(),i.fx1,i.fy1,i.fx2,i.fy2);
      }
  }
  {
    std::map<int,struct PhysicalPointInfo>  :: const_iterator it  = points.begin();
    std::map<int,struct PhysicalPointInfo > :: const_iterator ite = points.end();      
    for (;it!=ite;++it)
      {
	const PhysicalPointInfo &i = (*it).second;
	int id = (*it).first;
	fprintf(f,"NODE PHYSICAL %d DEPLX %d %g %g DEPLY %d %g %g DEPLZ %d %g %g\n",id,i.disp[0],i.val[0],i.val[1],i.disp[1],i.val[2],i.val[3],i.disp[2],i.val[4],i.val[5]);
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
	  sscanf(line,"%s %s %d %s %s %s %s %s %lf %lf %lf %lf\n",a1,a2,&id,a3,a4,a5,a6,a7,&info.fx1,&info.fy1,&info.fx2,&info.fy2);
	  info.material = std::string(a6);
	  info.section  = std::string(a4);
	  lines[id] = info;
	}
      if (!strcmp(name,"NODE"))
	{
	  int id;
	  PhysicalPointInfo info;
	  sscanf(line,"%s %s %d %s %d %lf %lf %s %d %lf %lf %s %d %lf %lf\n",a1,a2,&id,
		 a3,&info.disp[0],&info.val[0],&info.val[1],
		 a4,&info.disp[1],&info.val[2],&info.val[3],
		 a5,&info.disp[2],&info.val[4],&info.val[5]);
	  points[id] = info;
	  if (info.disp[0] == 0)
	    MAX_FORCE = (MAX_FORCE>info.val[0])?MAX_FORCE:info.val[0];
	  if (info.disp[1] == 0)
	    MAX_FORCE = (MAX_FORCE>info.val[1])?MAX_FORCE:info.val[1];
	  if (info.disp[2] == 0)
	    MAX_FORCE = (MAX_FORCE>info.val[2])?MAX_FORCE:info.val[2];

	}
      if (feof(f) )break;
    }
  fclose(f);
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
	      for (int icomp=0;icomp<3;++icomp)
		{
		  double dv[3] = {0,0,0};
		  if (it->second.disp[icomp] == 1)
		    {
		      double offset = 0.5 * CTX.gl_fontsize * CTX.pixel_equiv_x;
		      
		      dv[icomp] =  (CTX.max[0]-CTX.min[0])*it->second.val[1+2*icomp]*.2 / (MAX_FORCE *CTX.s[icomp]);

		      Draw_Vector (CTX.vector_type,  0, CTX.arrow_rel_head_radius, 
				   CTX.arrow_rel_stem_length, CTX.arrow_rel_stem_radius,
				   v->Pos.X, v->Pos.Y, v->Pos.Z,
				   dv[0], dv[1], dv[2], NULL, CTX.geom.light);
		      sprintf(Num, "%g kN", it->second.val[1]);
		      glRasterPos3d((v->Pos.X + dv[0])+ offset / CTX.s[0],
				    (v->Pos.Y + dv[1])+ offset / CTX.s[1],
				    (v->Pos.Z + dv[2])+ offset / CTX.s[2]);
		      Draw_String(Num);
		    } 
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
  PhysicalGroup *p;
  for(int i = 0; i < List_Nbr(THEM->PhysicalGroups); i++) 
    { 
      char Num[100];
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
		  section -> GL_DrawBeam (pinit,dir);
		  return true;
		}
	    }
	}
      }
    }
#endif
  return false;
}
