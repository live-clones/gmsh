// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "Message.h"
#include "Geo.h"
#include "GModel.h"
#include "Numeric.h"
#include "Context.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "ReadImg.h"
#include "OS.h"
#include "StringUtils.h"

#if !defined(HAVE_NO_PARSER)
#include "Parser.h"
#endif

#if !defined(HAVE_NO_POST)
#include "PView.h"
#include "PViewData.h"
#endif

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#include "SelectBuffer.h"
#include "GUI.h"
extern GUI *WID;
#endif

extern Context_T CTX;

#define SQU(a)      ((a)*(a))

static void FinishUpBoundingBox()
{
  double range[3];

  for(int i = 0; i < 3; i++){
    CTX.cg[i] = 0.5 * (CTX.min[i] + CTX.max[i]);
    range[i] = CTX.max[i] - CTX.min[i];
  }

  if(range[0] < CTX.geom.tolerance && 
     range[1] < CTX.geom.tolerance && 
     range[2] < CTX.geom.tolerance) {
    CTX.min[0] -= 1.; CTX.min[1] -= 1.;
    CTX.max[0] += 1.; CTX.max[1] += 1.;
    CTX.lc = 1.;
  }
  else if(range[0] < CTX.geom.tolerance && 
          range[1] < CTX.geom.tolerance) {
    CTX.lc = range[2];
    CTX.min[0] -= CTX.lc; CTX.min[1] -= CTX.lc;
    CTX.max[0] += CTX.lc; CTX.max[1] += CTX.lc;
  }
  else if(range[0] < CTX.geom.tolerance && 
          range[2] < CTX.geom.tolerance) {
    CTX.lc = range[1];
    CTX.min[0] -= CTX.lc; CTX.max[0] += CTX.lc;
  }
  else if(range[1] < CTX.geom.tolerance && 
          range[2] < CTX.geom.tolerance) {
    CTX.lc = range[0];
    CTX.min[1] -= CTX.lc; CTX.max[1] += CTX.lc;
  }
  else if(range[0] < CTX.geom.tolerance) {
    CTX.lc = sqrt(SQU(range[1]) + SQU(range[2]));
    CTX.min[0] -= CTX.lc; CTX.max[0] += CTX.lc;
  }
  else if(range[1] < CTX.geom.tolerance) {
    CTX.lc = sqrt(SQU(range[0]) + SQU(range[2]));
    CTX.min[1] -= CTX.lc; CTX.max[1] += CTX.lc;
  }
  else if(range[2] < CTX.geom.tolerance) {
    CTX.lc = sqrt(SQU(range[0]) + SQU(range[1]));
  }
  else {
    CTX.lc = sqrt(SQU(range[0]) + SQU(range[1]) + SQU(range[2]));
  }
}

void SetBoundingBox(double xmin, double xmax,
                    double ymin, double ymax, 
                    double zmin, double zmax)
{
  CTX.min[0] = xmin; CTX.max[0] = xmax;
  CTX.min[1] = ymin; CTX.max[1] = ymax;
  CTX.min[2] = zmin; CTX.max[2] = zmax;
  FinishUpBoundingBox();
}

void SetBoundingBox()
{
  if(CTX.forced_bbox) return;

  SBoundingBox3d bb = GModel::current()->bounds();
  
#if !defined(HAVE_NO_POST)
  if(bb.empty()) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(!PView::list[i]->getData()->getBoundingBox().empty())
        bb += PView::list[i]->getData()->getBoundingBox();
  }
#endif
  
  if(bb.empty()){
    bb += SPoint3(-1., -1., -1.);
    bb += SPoint3(1., 1., 1.);
  }
  
  CTX.min[0] = bb.min().x(); CTX.max[0] = bb.max().x();
  CTX.min[1] = bb.min().y(); CTX.max[1] = bb.max().y();
  CTX.min[2] = bb.min().z(); CTX.max[2] = bb.max().z();
  FinishUpBoundingBox();
}

// FIXME: this is necessary for now to have an approximate CTX.lc
// *while* parsing input files (it's important since some of the
// geometrical operations use a tolerance that depends on
// CTX.lc). This will be removed once the new database is filled
// directly during the parsing step
static SBoundingBox3d temp_bb;

void ResetTemporaryBoundingBox()
{
  temp_bb.reset();
}

void AddToTemporaryBoundingBox(double x, double y, double z)
{
  temp_bb += SPoint3(x, y, z);
  CTX.min[0] = temp_bb.min().x(); CTX.max[0] = temp_bb.max().x();
  CTX.min[1] = temp_bb.min().y(); CTX.max[1] = temp_bb.max().y();
  CTX.min[2] = temp_bb.min().z(); CTX.max[2] = temp_bb.max().z();
  FinishUpBoundingBox();
}

int ParseFile(const char *f, int close, int warn_if_missing)
{
#if defined(HAVE_NO_PARSER)
  Msg::Error("Gmsh parser is not compiled in this version");
  return 0;
#else
  char yyname_old[256], tmp[256];
  FILE *yyin_old, *fp;
  int yylineno_old, yyerrorstate_old, yyviewindex_old;

  // add 'b' for pure Windows programs: opening in text mode messes up
  // fsetpos/fgetpos (used e.g. for user-defined functions)
  if(!(fp = fopen(f, "rb"))){
    if(warn_if_missing) Msg::Warning("Unable to open file '%s'", f);
    return 0;
  }

#if !defined(HAVE_NO_POST)
  int numViewsBefore = PView::list.size();
#endif

  strncpy(yyname_old, gmsh_yyname, 255);
  yyin_old = gmsh_yyin;
  yyerrorstate_old = gmsh_yyerrorstate;
  yylineno_old = gmsh_yylineno;
  yyviewindex_old = gmsh_yyviewindex;

  strncpy(gmsh_yyname, f, 255);
  gmsh_yyin = fp;
  gmsh_yyerrorstate = 0;
  gmsh_yylineno = 1;
  gmsh_yyviewindex = 0;

  fpos_t position;
  fgetpos(gmsh_yyin, &position);
  fgets(tmp, sizeof(tmp), gmsh_yyin);
  fsetpos(gmsh_yyin, &position);

  while(!feof(gmsh_yyin)){
    gmsh_yyparse();
    if(gmsh_yyerrorstate > 20){
      Msg::Error("Too many errors: aborting...");
      force_yyflush();
      break;
    }
  }

  if(close) fclose(gmsh_yyin);

  strncpy(gmsh_yyname, yyname_old, 255);
  gmsh_yyin = yyin_old;
  gmsh_yyerrorstate = yyerrorstate_old;
  gmsh_yylineno = yylineno_old;
  gmsh_yyviewindex = yyviewindex_old;

#if defined(HAVE_FLTK) && !defined(HAVE_NO_POST)
  if(!CTX.batch && numViewsBefore != (int)PView::list.size())
    WID->update_views();
#endif

  return 1;
#endif
}

void ParseString(const char *str)
{
  if(!str) return;
  FILE *fp;
  if((fp = fopen(CTX.tmp_filename_fullpath, "w"))) {
    fprintf(fp, str);
    fprintf(fp, "\n");
    fclose(fp);
    ParseFile(CTX.tmp_filename_fullpath, 1);
    GModel::current()->importGEOInternals();
  }
}

void SetProjectName(const char *name)
{
  char no_ext[256], ext[256], base[256];
  SplitFileName(name, no_ext, ext, base);

  if(CTX.filename != name) // yes, we mean to compare the pointers
    strncpy(CTX.filename, name, 255);
  strncpy(CTX.no_ext_filename, no_ext, 255);
  strncpy(CTX.base_filename, base, 255);

  GModel::current()->setName(base);
    
#if defined(HAVE_FLTK)
  if(!CTX.batch) WID->set_title(CTX.filename);
#endif
}

int MergeFile(const char *name, int warn_if_missing)
{
  // added 'b' for pure Windows programs, since some of these files
  // contain binary data
  FILE *fp = fopen(name, "rb");
  if(!fp){
    if(warn_if_missing) Msg::Warning("Unable to open file '%s'", name);
    return 0;
  }

  char header[256];
  fgets(header, sizeof(header), fp);
  fclose(fp);

  Msg::StatusBar(2, true, "Reading '%s'", name);

  char no_ext[256], ext[256], base[256];
  SplitFileName(name, no_ext, ext, base);

#if defined(HAVE_FLTK)
  if(!CTX.batch) {
    if(!strcmp(ext, ".gz")) {
      // the real solution would be to rewrite all our I/O functions in
      // terms of gzFile, but until then, this is better than nothing
      if(fl_choice("File '%s' is in gzip format.\n\nDo you want to uncompress it?", 
                   "Cancel", "Uncompress", NULL, name)){
        char tmp[256];
        sprintf(tmp, "gunzip -c %s > %s", name, no_ext);
        if(SystemCall(tmp))
          Msg::Error("Failed to uncompress `%s': check directory permissions", name);
        if(!strcmp(CTX.filename, name)) // this is the project file
          SetProjectName(no_ext);
        return MergeFile(no_ext);
      }
    }
  }
#endif

  CTX.geom.draw = 0; // don't try to draw the model while reading

  GModel *m = GModel::current();

  // FIXME: We need to decide what do do for CAD entities, meshes,
  // etc.  For meshes we should definitely create one new model per
  // merge (and reset current() to the previous value after the
  // merge). This will make multi-step multi-meshes post-pro views
  // work out of the box.
  // GModel *m = new GModel;

#if !defined(HAVE_NO_POST)
  int numViewsBefore = PView::list.size();
#endif

  int status = 0;
  if(!strcmp(ext, ".stl") || !strcmp(ext, ".STL")){
    status = m->readSTL(name, CTX.geom.tolerance);
  }
  else if(!strcmp(ext, ".brep") || !strcmp(ext, ".rle") ||
          !strcmp(ext, ".brp") || !strcmp(ext, ".BRP")){
    status = m->readOCCBREP(std::string(name));
  }
  else if(!strcmp(ext, ".iges") || !strcmp(ext, ".IGES") ||
          !strcmp(ext, ".igs") || !strcmp(ext, ".IGS")){
    status = m->readOCCIGES(std::string(name));
  }
  else if(!strcmp(ext, ".step") || !strcmp(ext, ".STEP") ||
          !strcmp(ext, ".stp") || !strcmp(ext, ".STP")){
    status = m->readOCCSTEP(std::string(name));
  }
  else if(!strcmp(ext, ".unv") || !strcmp(ext, ".UNV")){
    status = m->readUNV(name);
  }
  else if(!strcmp(ext, ".wrl") || !strcmp(ext, ".WRL") || 
          !strcmp(ext, ".vrml") || !strcmp(ext, ".VRML") ||
          !strcmp(ext, ".iv") || !strcmp(ext, ".IV")){
    status = m->readVRML(name);
  }
  else if(!strcmp(ext, ".mesh") || !strcmp(ext, ".MESH")){
    status = m->readMESH(name);
  }
#if !defined(HAVE_NO_POST)
  else if(!strcmp(ext, ".med") || !strcmp(ext, ".MED") ||
	  !strcmp(ext, ".mmed") || !strcmp(ext, ".MMED") ||
	  !strcmp(ext, ".rmed") || !strcmp(ext, ".RMED")){
    status = GModel::readMED(name);
    if(status > 1) status = PView::readMED(name);
  }
#endif
  else if(!strcmp(ext, ".bdf") || !strcmp(ext, ".BDF") ||
          !strcmp(ext, ".nas") || !strcmp(ext, ".NAS")){
    status = m->readBDF(name);
  }
  else if(!strcmp(ext, ".p3d") || !strcmp(ext, ".P3D")){
    status = m->readP3D(name);
  }
  else if(!strcmp(ext, ".fm") || !strcmp(ext, ".FM")) {
    status = m->readFourier(name);
  }
#if defined(HAVE_FLTK)
  else if(!strcmp(ext, ".pnm") || !strcmp(ext, ".PNM") ||
          !strcmp(ext, ".pbm") || !strcmp(ext, ".PBM") ||
          !strcmp(ext, ".pgm") || !strcmp(ext, ".PGM") ||
          !strcmp(ext, ".ppm") || !strcmp(ext, ".PPM")) {
    status = read_pnm(name);
  }
  else if(!strcmp(ext, ".bmp") || !strcmp(ext, ".BMP")) {
    status = read_bmp(name);
  }
#if defined(HAVE_LIBJPEG)
  else if(!strcmp(ext, ".jpg") || !strcmp(ext, ".JPG") ||
          !strcmp(ext, ".jpeg") || !strcmp(ext, ".JPEG")) {
    status = read_jpeg(name);
  }
#endif
#if defined(HAVE_LIBPNG)
  else if(!strcmp(ext, ".png") || !strcmp(ext, ".PNG")) {
    status = read_png(name);
  }
#endif
#endif
  else {
    CTX.geom.draw = 1;
    if(!strncmp(header, "$PTS", 4) || !strncmp(header, "$NO", 3) || 
       !strncmp(header, "$PARA", 5) || !strncmp(header, "$ELM", 4) ||
       !strncmp(header, "$MeshFormat", 11)) {
      status = m->readMSH(name);
#if !defined(HAVE_NO_POST)
      if(status > 1) status = PView::readMSH(name);
#endif
    }
#if !defined(HAVE_NO_POST)
    else if(!strncmp(header, "$PostFormat", 11) || 
            !strncmp(header, "$View", 5)) {
      status = PView::readPOS(name);
    }
#endif
    else {
      status = m->readGEO(name);
    }
  }

  SetBoundingBox();

  CTX.geom.draw = 1;
  CTX.mesh.changed = ENT_ALL;

#if defined(HAVE_FLTK) && !defined(HAVE_NO_POST)
  if(!CTX.batch && numViewsBefore != (int)PView::list.size())
    WID->update_views();
#endif

  Msg::StatusBar(2, true, "Read '%s'", name);
  return status;
}

void OpenProject(const char *name)
{
  if(CTX.threads_lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;

  // FIXME: this will change once we clarify Open/Merge/Clear
#if !defined(HAVE_NO_POST)
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(PView::list[i]->getData()->hasModel(GModel::current()))
      delete PView::list[i];
#endif
  GModel::current()->destroy();
  GModel::current()->getGEOInternals()->destroy();

  // temporary hack until we fill the current GModel on the fly during
  // parsing
  ResetTemporaryBoundingBox();

  SetProjectName(name);
  MergeFile(name);

  CTX.threads_lock = 0;

#if defined(HAVE_FLTK)
  if(!CTX.batch){
    WID->reset_visibility();
    WID->update_views();
  }
  ZeroHighlight();
#endif
}

void OpenProjectMacFinder(const char *filename)
{
  static int first = 1;
  if(first || CTX.batch){
    // just copy the filename: it will be opened when the GUI is ready
    // in main()
    strncpy(CTX.filename, filename, 255);
    first = 0;
  }
  else{
    OpenProject(filename);
#if defined(HAVE_FLTK)
    Draw();
#endif
  }
}
