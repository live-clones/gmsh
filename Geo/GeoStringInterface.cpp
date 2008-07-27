// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <sstream>
#include "Message.h"
#include "Numeric.h"
#include "MallocUtils.h"
#include "StringUtils.h"
#include "Geo.h"
#include "GeoStringInterface.h"
#include "OpenFile.h"
#include "Context.h"
#include "GModel.h"

#if !defined(HAVE_NO_PARSER)
#include "Parser.h"
#endif

extern Context_T CTX;

double evaluate_scalarfunction(std::string var, double val, std::string funct)
{
#if defined(HAVE_NO_PARSER)
  Msg::Error("Scalar function evaluation not available without Gmsh parser");
  return 0.;
#else
  FILE *tempf = gmsh_yyin;
  if(!(gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "w"))) {
    Msg::Error("Unable to open temporary file '%s'", CTX.tmp_filename_fullpath);
    return 0.;
  }
  // pose "variable = function" and evaluate function
  fprintf(gmsh_yyin, "%s = %.16g ;\n", var.c_str(), val);
  fprintf(gmsh_yyin, "ValeurTemporaire__ = %s ;\n", funct.c_str());
  fclose(gmsh_yyin);
  gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "r");
  while(!feof(gmsh_yyin)) {
    gmsh_yyparse();
  }
  fclose(gmsh_yyin);
  gmsh_yyin = tempf;
  // retreive value
  if(gmsh_yysymbols.count("ValeurTemporaire__")) 
    return gmsh_yysymbols["ValeurTemporaire__"][0];
  return 0.;
#endif
}

void add_infile(std::string text, std::string filename, bool deleted_something)
{
#if defined(HAVE_NO_PARSER)
  Msg::Error("GEO file creation not available without Gmsh parser");
#else
  if(!(gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "w"))) {
    Msg::Error("Unable to open temporary file '%s'", CTX.tmp_filename_fullpath);
    return;
  }

  fprintf(gmsh_yyin, "%s\n", text.c_str());
  Msg::StatusBar(2, true, "%s", text.c_str());
  fclose(gmsh_yyin);
  gmsh_yyin = fopen(CTX.tmp_filename_fullpath, "r");
  while(!feof(gmsh_yyin)) {
    gmsh_yyparse();
  }
  fclose(gmsh_yyin);

  if(deleted_something){
    // we need to start from scratch since the command just parsed
    // could have deleted some entities
    GModel::current()->destroy();
  }
  GModel::current()->importGEOInternals();
  CTX.mesh.changed = ENT_ALL;

  FILE *file;
  if(!(file = fopen(filename.c_str(), "a"))) {
    Msg::Error("Unable to open file '%s'", filename.c_str());
    return;
  }
  
  if(!CTX.expert_mode) {
    char no_ext[256], ext[256], base[256];
    SplitFileName(filename.c_str(), no_ext, ext, base);
    if(strlen(ext) && strcmp(ext, ".geo") && strcmp(ext, ".GEO")){
      char question[1024];
      sprintf(question, 
              "A scripting command is going to be appended to a non-`.geo' file.\n\n"
              "Are you sure you want to proceed?\n\n"
              "(You might want to create a new `.geo' file containing the command\n\n"
              "Merge \"%s\";\n\n"
              "and use that file instead. To disable this warning in the future, select\n"
              "`Enable expert mode' in the option dialog.)", filename.c_str());
      if(!Msg::GetBinaryAnswer(question, "Proceed", "Cancel", false)){
        fclose(file);
        return;
      }
    }
  }

  fprintf(file, "%s\n", text.c_str());
  fclose(file);
#endif
}

void coherence(std::string filename)
{
  add_infile("Coherence;", filename, true);
}

static std::string list2string(List_T *list)
{
  std::ostringstream sstream;
  for(int i = 0; i < List_Nbr(list); i++){
    int num;
    List_Read(list, i, &num);
    if(i) sstream << ", ";
    sstream << num;
  }
  return sstream.str();
}

void delet(List_T *list, std::string filename, std::string what)
{
  std::ostringstream sstream;
  sstream << "Delete {\n  " << what << "{" << list2string(list) << "};\n}";
  add_infile(sstream.str(), filename, true);
}

void add_charlength(List_T *list, std::string filename, std::string lc)
{
  std::ostringstream sstream;
  sstream << "Characteristic Length {" << list2string(list) << "} = " << lc << ";";
  add_infile(sstream.str().c_str(), filename);
}

void add_recosurf(List_T *list, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Recombine Surface {" << list2string(list) << "};";
  add_infile(sstream.str(), filename);
}

void add_trsfline(std::vector<int> &l, std::string filename, std::string type, 
                  std::string typearg, std::string pts)
{
  std::ostringstream sstream;
  sstream << "Transfinite Line {";
  for(unsigned int i = 0; i < l.size(); i++){
    if(i) sstream << ", ";
    sstream << l[i];
  }
  sstream << "} = " << pts;
  if(typearg.size()) sstream << " Using " << type << " " << typearg;
  sstream << ";";
  add_infile(sstream.str(), filename);
}

void add_trsfsurf(std::vector<int> &l, std::string filename, std::string dir)
{
  std::ostringstream sstream;
  sstream << "Transfinite Surface {" << l[0] << "} = {";
  for(unsigned int i = 1; i < l.size(); i++) {
    if(i > 1) sstream << ", ";
    sstream << l[i];
  }
  if(dir == "Left")
    sstream << "};";
  else
    sstream << "} " << dir << ";";
  add_infile(sstream.str(), filename);
}

void add_trsfvol(std::vector<int> &l, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Transfinite Volume{" << l[0] << "} = {";
  for(unsigned int i = 1; i < l.size(); i++) {
    if(i > 1) sstream << ", ";
    sstream << l[i];
  }
  sstream << "};";
  add_infile(sstream.str(), filename);
}

void add_param(std::string par, std::string value, std::string filename)
{
  std::ostringstream sstream;
  sstream << par << " = " << value << ";";
  add_infile(sstream.str(), filename);
}

void add_point(std::string filename, std::string x, std::string y,
	       std::string z, std::string lc)
{
  std::ostringstream sstream;
  sstream << "Point(" << NEWPOINT() << ") = {" << x << ", " << y << ", " 
	  << z << ", " << lc << "};";
  add_infile(sstream.str(), filename);
}

void add_field_option(int field_id, std::string option_name, 
		      std::string option_value, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "]." << option_name << " = " 
	  << option_value << ";";
  add_infile(sstream.str(), filename);
}

void add_field(int field_id, std::string type_name, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "] = " << type_name << ";";
  add_infile(sstream.str(), filename);
}

void delete_field(int field_id, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Delete Field [" << field_id << "];";
  add_infile(sstream.str(), filename);
}

void set_background_field(int field_id, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Background Field = " << field_id << ";";
  add_infile(sstream.str(), filename);
}

void add_multline(std::string type, std::vector<int> &p, std::string filename)
{
  std::ostringstream sstream;
  sstream << type << "(" << NEWLINE() << ") = {";
  for(unsigned int i = 0; i < p.size(); i++) {
    if(i) sstream << ", ";
    sstream << p[i];
  }
  sstream << "};";
  add_infile(sstream.str(), filename);
}

void add_circ(int p1, int p2, int p3, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Circle(" << NEWLINE() << ") = {" << p1 << ", " << p2 << ", "
	  << p3 << "};";
  add_infile(sstream.str(), filename);
}

void add_ell(int p1, int p2, int p3, int p4, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Ellipse(" << NEWLINE() << ") = {" << p1 << ", " << p2 << ", "
	  << p3 << ", " << p4 << "};";
  add_infile(sstream.str(), filename);
}

void add_lineloop(List_T *list, std::string filename, int *numloop)
{
  if(recognize_loop(list, numloop)) return;
  *numloop = NEWLINELOOP();
  std::ostringstream sstream;
  sstream << "Line Loop(" << *numloop << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), filename);
}

void add_surf(std::string type, List_T *list, std::string filename)
{
  std::ostringstream sstream;  
  sstream << type << "(" << NEWSURFACE() << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), filename);
}

void add_surfloop(List_T *list, std::string filename, int *numloop)
{
  if(recognize_surfloop(list, numloop)) return;
  *numloop = NEWSURFACELOOP();
  std::ostringstream sstream;
  sstream << "Surface Loop(" << *numloop << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), filename);
}

void add_vol(List_T *list, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Volume(" << NEWVOLUME() << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), filename);
}

void add_physical(std::string type, List_T *list, std::string filename)
{
  std::ostringstream sstream;
  sstream << "Physical " << type << "(" << NEWPHYSICAL() << ") = {" 
	  << list2string(list) << "};";
  add_infile(sstream.str(), filename);
}

void translate(int add, List_T *list, std::string filename, std::string what,
               std::string tx, std::string ty, std::string tz)
{
  std::ostringstream sstream;
  sstream << "Translate {" << tx << ", " << ty << ", " << tz << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), filename);
}

void rotate(int add, List_T *list, std::string filename, std::string what, 
            std::string ax, std::string ay, std::string az,
            std::string px, std::string py, std::string pz, std::string angle)
{
  std::ostringstream sstream;
  sstream << "Rotate {{" << ax << ", " << ay << ", " << az << "}, {" 
	  << px << ", " << py << ", " << pz << "}, " << angle << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), filename);
}

void dilate(int add, List_T *list, std::string filename, std::string what,
            std::string dx, std::string dy, std::string dz, std::string df)
{
  std::ostringstream sstream;
  sstream << "Dilate {{" << dx << ", " << dy << ", " << dz << "}, " << df << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), filename);
}

void symmetry(int add, List_T *list, std::string filename, std::string what,
              std::string sa, std::string sb, std::string sc, std::string sd)
{
  std::ostringstream sstream;
  sstream << "Symmetry {" << sa << ", " << sb << ", " << sc << ", " << sd << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), filename);
}

void extrude(List_T *list, std::string filename, std::string what, 
             std::string tx, std::string ty, std::string tz)
{
  std::ostringstream sstream;
  sstream << "Extrude {" << tx << ", " << ty << ", " << tz << "} {\n  " << what 
	  << "{" << list2string(list) << "};\n}";
  add_infile(sstream.str(), filename);
}

void protude(List_T *list, std::string filename, std::string what, 
             std::string ax, std::string ay, std::string az,
             std::string px, std::string py, std::string pz, std::string angle)
{
  std::ostringstream sstream;
  sstream << "Extrude {{" << ax << ", " << ay << ", " << az << "}, {" 
	  << px << ", " << py << ", " << pz << "}, " << angle << "} {\n  "
	  << what << "{" << list2string(list) << "};\n}";
  add_infile(sstream.str(), filename);
}
