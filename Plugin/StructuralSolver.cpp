#include "StructuralSolver.h"


#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#include <FL/filename.H>
#endif

extern Mesh *THEM;


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
  Init_Mesh(&m);

  size_t l = name.size();
  char temp[256];
  sprintf(temp, "%s/%s", direct,name.c_str());
  // read the section (msh format)
  FILE *f = fopen (temp,"r");  
  Read_Mesh (&m, f, temp,FORMAT_MSH);
  fclose(f);
  // get rid of the extension
  name.erase(name.find("."));
  printf("%s\n",name.c_str());
  THEM=kk;
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
{
  RegisterBeamSections ();
}
StructuralSolver :: ~StructuralSolver ()
{
  std::list<struct Structural_BeamSection* > :: iterator it  = beam_sections.begin();
  std::list<struct Structural_BeamSection* > :: iterator ite = beam_sections.end();

  for (;it!=ite;++it)
    {
      delete *it;
    }

}

void StructuralSolver ::popupPropertiesForPhysicalEntity (int dim)
{ 
  static Fl_Group *g[10];
  int i;

//   if(context_geometry_window) {
//     for(i = 0; i < 6; i++)
//       g[i]->hide();
//     g[num]->show();
//     context_geometry_window->show();
//     return;
//   }

//   int width = 31 * fontsize;
//   int height = 5 * WB + 9 * BH;

//   context_geometry_window = new Fl_Window(width, height, "Contextual geometry definitions");
//   context_geometry_window->box(WINDOW_BOX);
//   {
//     Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
//     // 0: Parameter
//     {
//       g[0] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Parameter");
//       context_geometry_input[0] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "Name");
//       context_geometry_input[0]->value("lc");
//       context_geometry_input[1] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Value");
//       context_geometry_input[1]->value("1.0");
//       for(i = 0; i < 2; i++) {
//         context_geometry_input[i]->align(FL_ALIGN_RIGHT);
//       }
//       {
//         Fl_Return_Button *o = new Fl_Return_Button(width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
//         o->callback(con_geometry_define_parameter_cb);
//       }
//       g[0]->end();
//     }
//     // 1: Point
//     {
//       g[1] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Point");
//       context_geometry_input[2] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X coordinate");
//       context_geometry_input[2]->value("0.0");
//       context_geometry_input[3] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y coordinate");
//       context_geometry_input[3]->value("0.0");
//       context_geometry_input[4] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z coordinate");
//       context_geometry_input[4]->value("0.0");
//       context_geometry_input[5] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Characteristic length");
//       context_geometry_input[5]->value("1.0");
//       for(i = 2; i < 6; i++) {
//         context_geometry_input[i]->align(FL_ALIGN_RIGHT);
//       }
//       {
//         Fl_Return_Button *o = new Fl_Return_Button(width - BB - 2 * WB, 2 * WB + 7 * BH, BB, BH, "Add");
//         o->callback(con_geometry_define_point_cb);
//       }
//       g[1]->end();
//     }
//     // 2: Translation
//     {
//       g[2] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Translation");
//       context_geometry_input[6] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X component");
//       context_geometry_input[6]->value("0.0");
//       context_geometry_input[7] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y component");
//       context_geometry_input[7]->value("0.0");
//       context_geometry_input[8] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z component");
//       context_geometry_input[8]->value("1.0");
//       for(i = 6; i < 9; i++) {
//         context_geometry_input[i]->align(FL_ALIGN_RIGHT);
//       }
//       g[2]->end();
//     }
//     // 3: Rotation
//     {
//       g[3] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Rotation");
//       context_geometry_input[9] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X coordinate of an axis point");
//       context_geometry_input[9]->value("0.0");
//       context_geometry_input[10] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y coordinate of an axis point");
//       context_geometry_input[10]->value("0.0");
//       context_geometry_input[11] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z coordinate of an axis point");
//       context_geometry_input[11]->value("0.0");
//       context_geometry_input[12] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "X component of direction");
//       context_geometry_input[12]->value("0.0");
//       context_geometry_input[13] = new Fl_Input(2 * WB, 2 * WB + 5 * BH, IW, BH, "Y component of direction");
//       context_geometry_input[13]->value("1.0");
//       context_geometry_input[14] = new Fl_Input(2 * WB, 2 * WB + 6 * BH, IW, BH, "Z component of direction");
//       context_geometry_input[14]->value("0.0");
//       context_geometry_input[15] = new Fl_Input(2 * WB, 2 * WB + 7 * BH, IW, BH, "Angle in radians");
//       context_geometry_input[15]->value("Pi/4");
//       for(i = 9; i < 16; i++) {
//         context_geometry_input[i]->align(FL_ALIGN_RIGHT);
//       }
//       g[3]->end();
//     }
//     // 4: Scale
//     {
//       g[4] = new Fl_Group(WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Scale");
//       context_geometry_input[16] = new Fl_Input(2 * WB, 2 * WB + 1 * BH, IW, BH, "X component of direction");
//       context_geometry_input[16]->value("1.0");
//       context_geometry_input[17] = new Fl_Input(2 * WB, 2 * WB + 2 * BH, IW, BH, "Y component of direction");
//       context_geometry_input[17]->value("0.0");
//       context_geometry_input[18] = new Fl_Input(2 * WB, 2 * WB + 3 * BH, IW, BH, "Z component of direction");
//       context_geometry_input[18]->value("0.0");
//       context_geometry_input[19] = new Fl_Input(2 * WB, 2 * WB + 4 * BH, IW, BH, "Factor");
//       context_geometry_input[19]->value("2.0");
//       for(i = 16; i < 20; i++) {
//         context_geometry_input[i]->align(FL_ALIGN_RIGHT);
//       }
//       g[4]->end();
//     }
}

