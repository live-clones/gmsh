// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshMessage.h"
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
#include <FL/fl_ask.H>
#include "GUI.h"
#include "Draw.h"
#endif

extern Context_T CTX;

#define SQU(a)      ((a)*(a))

static void FinishUpBoundingBox()
{
  double range[3];
  for(int i = 0; i < 3; i++) range[i] = CTX.max[i] - CTX.min[i];

  if(range[0] < CTX.geom.tolerance && 
     range[1] < CTX.geom.tolerance && 
     range[2] < CTX.geom.tolerance) {
    CTX.min[0] -= 1.; CTX.min[1] -= 1.;
    CTX.max[0] += 1.; CTX.max[1] += 1.;
  }
  else if(range[0] < CTX.geom.tolerance && 
          range[1] < CTX.geom.tolerance) {
    CTX.min[0] -= range[2]; CTX.min[1] -= range[2];
    CTX.max[0] += range[2]; CTX.max[1] += range[2];
  }
  else if(range[0] < CTX.geom.tolerance && 
          range[2] < CTX.geom.tolerance) {
    CTX.min[0] -= range[1]; CTX.max[0] += range[1];
  }
  else if(range[1] < CTX.geom.tolerance && 
          range[2] < CTX.geom.tolerance) {
    CTX.min[1] -= range[0]; CTX.max[1] += range[0];
  }
  else if(range[0] < CTX.geom.tolerance) {
    double l = sqrt(SQU(range[1]) + SQU(range[2]));
    CTX.min[0] -= l; CTX.max[0] += l;
  }
  else if(range[1] < CTX.geom.tolerance) {
    double l = sqrt(SQU(range[0]) + SQU(range[2]));
    CTX.min[1] -= l; CTX.max[1] += l;
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
  CTX.lc = sqrt(SQU(CTX.max[0] - CTX.min[0]) +
                SQU(CTX.max[1] - CTX.min[1]) + 
                SQU(CTX.max[2] - CTX.min[2]));
  for(int i = 0; i < 3; i++) CTX.cg[i] = 0.5 * (CTX.min[i] + CTX.max[i]);
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
  CTX.lc = sqrt(SQU(CTX.max[0] - CTX.min[0]) +
                SQU(CTX.max[1] - CTX.min[1]) + 
                SQU(CTX.max[2] - CTX.min[2]));
  for(int i = 0; i < 3; i++) CTX.cg[i] = 0.5 * (CTX.min[i] + CTX.max[i]);
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
  if(temp_bb.empty()) return;
  CTX.lc = sqrt(SQU(temp_bb.max().x() - temp_bb.min().x()) +
                SQU(temp_bb.max().y() - temp_bb.min().y()) + 
                SQU(temp_bb.max().z() - temp_bb.min().z()));
  if(CTX.lc == 0) CTX.lc = 1.;
  // to get correct cg during interctive point creation
  for(int i = 0; i < 3; i++) CTX.cg[i] = temp_bb.center()[i];
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
      gmsh_yyflush();
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
  if(GUI::available() && numViewsBefore != (int)PView::list.size())
    GUI::instance()->updateViews();
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

static void SetProjectName(const char *name)
{
  char no_ext[256], ext[256], base[256];
  SplitFileName(name, no_ext, ext, base);

  if(CTX.filename != name) // yes, we mean to compare the pointers
    strncpy(CTX.filename, name, 255);
  strncpy(CTX.no_ext_filename, no_ext, 255);
  strncpy(CTX.base_filename, base, 255);

  GModel::current()->setName(base);
    
#if defined(HAVE_FLTK)
  if(GUI::available())
    GUI::instance()->setGraphicTitle(CTX.filename);
#endif
}

int MergeFile(const char *name, int warn_if_missing)
{
  GModel *model = GModel::current();
  if(!model){
    Msg::Error("No models exists in which to merge data");
    return 0;
  }

  if(model->getName() == "")
    SetProjectName(name);

  // added 'b' for pure Windows programs, since some of these files
  // contain binary data
  FILE *fp = fopen(name, "rb");
  if(!fp){
    if(warn_if_missing) 
      Msg::Warning("Unable to open file '%s'", name);
    return 0;
  }

  char header[256];
  fgets(header, sizeof(header), fp);
  fclose(fp);

  Msg::StatusBar(2, true, "Reading '%s'", name);

  char no_ext[256], ext[256], base[256];
  SplitFileName(name, no_ext, ext, base);

#if defined(HAVE_FLTK)
  if(GUI::available()) {
    if(!strcmp(ext, ".gz")) {
      // the real solution would be to rewrite all our I/O functions in
      // terms of gzFile, but until then, this is better than nothing
      if(fl_choice("File '%s' is in gzip format.\n\nDo you want to uncompress it?", 
                   "Cancel", "Uncompress", NULL, name)){
        char tmp[256];
        sprintf(tmp, "gunzip -c %s > %s", name, no_ext);
        if(SystemCall(tmp))
          Msg::Error("Failed to uncompress `%s': check directory permissions", name);
        SetProjectName(no_ext);
        return MergeFile(no_ext);
      }
    }
  }
#endif

  CTX.geom.draw = 0; // don't try to draw the model while reading

#if !defined(HAVE_NO_POST)
  int numViewsBefore = PView::list.size();
#endif

  int status = 0;
  if(!strcmp(ext, ".stl") || !strcmp(ext, ".STL")){
    status = model->readSTL(name, CTX.geom.tolerance);
  }
  else if(!strcmp(ext, ".brep") || !strcmp(ext, ".rle") ||
          !strcmp(ext, ".brp") || !strcmp(ext, ".BRP")){
    status = model->readOCCBREP(std::string(name));
  }
  else if(!strcmp(ext, ".iges") || !strcmp(ext, ".IGES") ||
          !strcmp(ext, ".igs") || !strcmp(ext, ".IGS")){
    status = model->readOCCIGES(std::string(name));
  }
  else if(!strcmp(ext, ".step") || !strcmp(ext, ".STEP") ||
          !strcmp(ext, ".stp") || !strcmp(ext, ".STP")){
    status = model->readOCCSTEP(std::string(name));
  }
  else if(!strcmp(ext, ".unv") || !strcmp(ext, ".UNV")){
    status = model->readUNV(name);
  }
  else if(!strcmp(ext, ".vtk") || !strcmp(ext, ".VTK")){
    status = model->readVTK(name, CTX.big_endian);
  }
  else if(!strcmp(ext, ".wrl") || !strcmp(ext, ".WRL") || 
          !strcmp(ext, ".vrml") || !strcmp(ext, ".VRML") ||
          !strcmp(ext, ".iv") || !strcmp(ext, ".IV")){
    status = model->readVRML(name);
  }
  else if(!strcmp(ext, ".mesh") || !strcmp(ext, ".MESH")){
    status = model->readMESH(name);
  }
  else if(!strcmp(ext, ".med") || !strcmp(ext, ".MED") ||
	  !strcmp(ext, ".mmed") || !strcmp(ext, ".MMED") ||
	  !strcmp(ext, ".rmed") || !strcmp(ext, ".RMED")){
    status = GModel::readMED(name);
#if !defined(HAVE_NO_POST)
    if(status > 1) status = PView::readMED(name);
#endif
  }
  else if(!strcmp(ext, ".bdf") || !strcmp(ext, ".BDF") ||
          !strcmp(ext, ".nas") || !strcmp(ext, ".NAS")){
    status = model->readBDF(name);
  }
  else if(!strcmp(ext, ".p3d") || !strcmp(ext, ".P3D")){
    status = model->readP3D(name);
  }
  else if(!strcmp(ext, ".fm") || !strcmp(ext, ".FM")) {
    status = model->readFourier(name);
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
       !strncmp(header, "$MeshFormat", 11) || !strncmp(header, "$Comments", 9)) {
      status = model->readMSH(name);
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
      status = model->readGEO(name);
    }
  }

  SetBoundingBox();

  CTX.geom.draw = 1;
  CTX.mesh.changed = ENT_ALL;

#if defined(HAVE_FLTK) && !defined(HAVE_NO_POST)
  if(GUI::available() && numViewsBefore != (int)PView::list.size())
    GUI::instance()->updateViews();
#endif

  if(!status) Msg::Error("Error loading '%s'", name);
  Msg::StatusBar(2, true, "Read '%s'", name);
  return status;
}

void ClearProject(const char *filename)
{
#if !defined(HAVE_NO_POST)
  for(int i = PView::list.size() - 1; i >= 0; i--)
    delete PView::list[i];
#endif
#if !defined(HAVE_NO_PARSER)
  gmsh_yysymbols.clear();
#endif
  for(int i = GModel::list.size() - 1; i >= 0; i--)
    delete GModel::list[i];
  new GModel();
  SetProjectName(filename);
#if defined(HAVE_FLTK)
  if(GUI::available()){
    GUI::instance()->resetVisibility();
    GUI::instance()->updateViews();
    GUI::instance()->updateFields();
    GModel::current()->setSelection(0);
  }
#endif
}

void OpenProject(const char *name)
{
  if(CTX.threads_lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;

  if(!GModel::current()){
    // if there's no model, add a new one and make it the current
    new GModel();
    GModel::current(GModel::list.size() - 1);
  }
  else if(GModel::current()->empty()){
    // if the current model is empty, make sure it's reaaally
    // cleaned-up, and reuse it
    GModel::current()->destroy();
    GModel::current()->getGEOInternals()->destroy();
  }
  else{
    // if the current model is not empty make it invisible, clear the
    // parser variables (if it's empty it probably means we just
    // launched gmsh, and we don't want to delete variables set
    // e.g. using the -string command line option) and add a new model
    GModel::current()->setVisibility(0);
#if !defined(HAVE_NO_PARSER)
    gmsh_yysymbols.clear();
#endif
    new GModel();
    GModel::current(GModel::list.size() - 1);
  }

  // temporary hack until we fill the current GModel on the fly during
  // parsing
  ResetTemporaryBoundingBox();
  MergeFile(name);

  CTX.threads_lock = 0;

#if defined(HAVE_FLTK)
  if(GUI::available()){
    GUI::instance()->resetVisibility();
    GUI::instance()->updateViews();
    GUI::instance()->updateFields();
    GModel::current()->setSelection(0);
  }
#endif
}

void OpenProjectMacFinder(const char *filename)
{
#if defined(HAVE_FLTK)
  static int first = 1;
  if(first || !GUI::available()){
    // just copy the filename: it will be opened when the GUI is ready
    // in main()
    strncpy(CTX.filename, filename, 255);
    first = 0;
  }
  else{
    OpenProject(filename);
    Draw();
  }
#endif
}
