// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <string.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Options.h"
#include "Geo.h"
#include "GModel.h"
#include "Numeric.h"
#include "Context.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "ReadImg.h"
#include "OS.h"
#include "StringUtils.h"
#include "GeomMeshMatcher.h"
#include "LuaBindings.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_MESH)
#include "HighOrder.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

#if defined(HAVE_FLTK)
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "menuWindow.h"
#include "drawContext.h"
#endif

#define SQU(a)      ((a)*(a))

static void FinishUpBoundingBox()
{
  double range[3];
  for(int i = 0; i < 3; i++) 
    range[i] = CTX::instance()->max[i] - CTX::instance()->min[i];

  if(range[0] < CTX::instance()->geom.tolerance && 
     range[1] < CTX::instance()->geom.tolerance && 
     range[2] < CTX::instance()->geom.tolerance) {
    CTX::instance()->min[0] -= 1.; CTX::instance()->min[1] -= 1.;
    CTX::instance()->max[0] += 1.; CTX::instance()->max[1] += 1.;
  }
  else if(range[0] < CTX::instance()->geom.tolerance && 
          range[1] < CTX::instance()->geom.tolerance) {
    CTX::instance()->min[0] -= range[2]; CTX::instance()->min[1] -= range[2];
    CTX::instance()->max[0] += range[2]; CTX::instance()->max[1] += range[2];
  }
  else if(range[0] < CTX::instance()->geom.tolerance && 
          range[2] < CTX::instance()->geom.tolerance) {
    CTX::instance()->min[0] -= range[1]; CTX::instance()->max[0] += range[1];
  }
  else if(range[1] < CTX::instance()->geom.tolerance && 
          range[2] < CTX::instance()->geom.tolerance) {
    CTX::instance()->min[1] -= range[0]; CTX::instance()->max[1] += range[0];
  }
  else if(range[0] < CTX::instance()->geom.tolerance) {
    double l = sqrt(SQU(range[1]) + SQU(range[2]));
    CTX::instance()->min[0] -= l; CTX::instance()->max[0] += l;
  }
  else if(range[1] < CTX::instance()->geom.tolerance) {
    double l = sqrt(SQU(range[0]) + SQU(range[2]));
    CTX::instance()->min[1] -= l; CTX::instance()->max[1] += l;
  }
}

void SetBoundingBox(double xmin, double xmax,
                    double ymin, double ymax, 
                    double zmin, double zmax)
{
  CTX::instance()->min[0] = xmin; CTX::instance()->max[0] = xmax;
  CTX::instance()->min[1] = ymin; CTX::instance()->max[1] = ymax;
  CTX::instance()->min[2] = zmin; CTX::instance()->max[2] = zmax;
  FinishUpBoundingBox();
  CTX::instance()->lc = sqrt(SQU(CTX::instance()->max[0] - CTX::instance()->min[0]) +
                             SQU(CTX::instance()->max[1] - CTX::instance()->min[1]) + 
                             SQU(CTX::instance()->max[2] - CTX::instance()->min[2]));
  for(int i = 0; i < 3; i++) 
    CTX::instance()->cg[i] = 0.5 * (CTX::instance()->min[i] + CTX::instance()->max[i]);
}

void SetBoundingBox()
{
  if(CTX::instance()->forcedBBox) return;

  SBoundingBox3d bb = GModel::current()->bounds();
  
#if defined(HAVE_POST)
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
  
  CTX::instance()->min[0] = bb.min().x(); CTX::instance()->max[0] = bb.max().x();
  CTX::instance()->min[1] = bb.min().y(); CTX::instance()->max[1] = bb.max().y();
  CTX::instance()->min[2] = bb.min().z(); CTX::instance()->max[2] = bb.max().z();
  FinishUpBoundingBox();
  CTX::instance()->lc = sqrt(SQU(CTX::instance()->max[0] - CTX::instance()->min[0]) +
                             SQU(CTX::instance()->max[1] - CTX::instance()->min[1]) + 
                             SQU(CTX::instance()->max[2] - CTX::instance()->min[2]));
  for(int i = 0; i < 3; i++) 
    CTX::instance()->cg[i] = 0.5 * (CTX::instance()->min[i] + CTX::instance()->max[i]);
}

// FIXME: this is necessary for now to have an approximate
// CTX::instance()->lc *while* parsing input files (it's important
// since some of the geometrical operations use a tolerance that
// depends on CTX::instance()->lc). This will be removed once the new
// database is filled directly during the parsing step
static SBoundingBox3d temp_bb;

void ResetTemporaryBoundingBox()
{
  temp_bb.reset();
}

void AddToTemporaryBoundingBox(double x, double y, double z)
{
  temp_bb += SPoint3(x, y, z);
  if(temp_bb.empty()) return;
  CTX::instance()->lc = sqrt(SQU(temp_bb.max().x() - temp_bb.min().x()) +
                             SQU(temp_bb.max().y() - temp_bb.min().y()) + 
                             SQU(temp_bb.max().z() - temp_bb.min().z()));
  if(CTX::instance()->lc == 0) CTX::instance()->lc = 1.;
  // to get correct cg during interactive point creation
  for(int i = 0; i < 3; i++) CTX::instance()->cg[i] = temp_bb.center()[i];
}

int ParseFile(std::string fileName, bool close, bool warnIfMissing)
{
#if !defined(HAVE_PARSER)
  Msg::Error("Gmsh parser is not compiled in this version");
  return 0;
#else

  // add 'b' for pure Windows programs: opening in text mode messes up
  // fsetpos/fgetpos (used e.g. for user-defined functions)
  FILE *fp;
  if(!(fp = fopen(fileName.c_str(), "rb"))){
    if(warnIfMissing)
      Msg::Warning("Unable to open file '%s'", fileName.c_str());
    return 0;
  }

#if defined(HAVE_POST)
  int numViewsBefore = PView::list.size();
#endif

  std::string old_yyname = gmsh_yyname;
  FILE *old_yyin = gmsh_yyin;
  int old_yyerrorstate = gmsh_yyerrorstate;
  int old_yylineno = gmsh_yylineno;
  int old_yyviewindex = gmsh_yyviewindex;

  gmsh_yyname = fileName;
  gmsh_yyin = fp;
  gmsh_yyerrorstate = 0;
  gmsh_yylineno = 1;
  gmsh_yyviewindex = 0;

  while(!feof(gmsh_yyin)){
    gmsh_yyparse();
    if(gmsh_yyerrorstate > 20){
      Msg::Error("Too many errors: aborting...");
      gmsh_yyflush();
      break;
    }
  }

  if(close) fclose(gmsh_yyin);

  gmsh_yyname = old_yyname;
  gmsh_yyin = old_yyin;
  gmsh_yyerrorstate = old_yyerrorstate;
  gmsh_yylineno = old_yylineno;
  gmsh_yyviewindex = old_yyviewindex;

#if defined(HAVE_FLTK) && defined(HAVE_POST)
  if(FlGui::available())
    FlGui::instance()->updateViews(numViewsBefore != (int)PView::list.size());
#endif

  return 1;
#endif
}

void ParseString(std::string str)
{
  if(str.empty()) return;
  std::string fileName = CTX::instance()->homeDir + CTX::instance()->tmpFileName;
  FILE *fp = fopen(fileName.c_str(), "w");
  if(fp){
    fprintf(fp, "%s\n", str.c_str());
    fclose(fp);
    GModel::readGEO(fileName);
  }
}

int MergeFile(std::string fileName, bool warnIfMissing)
{
  if(GModel::current()->getName() == ""){
    GModel::current()->setFileName(fileName);
    GModel::current()->setName(SplitFileName(fileName)[1]);
  }

#if defined(HAVE_FLTK)
  if(FlGui::available())
    FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
#endif

  // added 'b' for pure Windows programs, since some of these files
  // contain binary data
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    if(warnIfMissing) 
      Msg::Warning("Unable to open file '%s'", fileName.c_str());
    return 0;
  }

  char header[256];
  if(!fgets(header, sizeof(header), fp)) return 0;
  fclose(fp);

  Msg::StatusBar(2, true, "Reading '%s'...", fileName.c_str());

  std::vector<std::string> split = SplitFileName(fileName);
  std::string noExt = split[0] + split[1], ext = split[2];

  if(ext == ".gz") {
    // the real solution would be to rewrite all our I/O functions in
    // terms of gzFile, but until then, this is better than nothing
    std::ostringstream sstream;
    sstream << "File '"<< fileName << "' is in gzip format.\n\n"
            << "Do you want to uncompress it?";
    if(Msg::GetAnswer(sstream.str().c_str(), 0, "Cancel", "Uncompress")){
      if(SystemCall(std::string("gunzip -c ") + fileName + " > " + noExt))
        Msg::Error("Failed to uncompress `%s': check directory permissions", 
                   fileName.c_str());
      GModel::current()->setFileName(noExt);
      return MergeFile(noExt);
    }
  }
  
  CTX::instance()->geom.draw = 0; // don't try to draw the model while reading

#if defined(HAVE_POST)
  int numViewsBefore = PView::list.size();
#endif

  int status = 0;
  if(ext == ".stl" || ext == ".STL"){
    status = GModel::current()->readSTL(fileName, CTX::instance()->geom.tolerance);
  }
  else if(ext == ".brep" || ext == ".rle" || ext == ".brp" || ext == ".BRP"){
    status = GModel::current()->readOCCBREP(fileName);
  }
  else if(ext == ".iges" || ext == ".IGES" || ext == ".igs" || ext == ".IGS"){
    status = GModel::current()->readOCCIGES(fileName);
  }
  else if(ext == ".step" || ext == ".STEP" || ext == ".stp" || ext == ".STP"){
    status = GModel::current()->readOCCSTEP(fileName);
  }
  else if(ext == ".sat" || ext == ".SAT"){
    status = GModel::current()->readACISSAT(fileName);
  }
  else if(ext == ".unv" || ext == ".UNV"){
    status = GModel::current()->readUNV(fileName);
  }
  else if(ext == ".vtk" || ext == ".VTK"){
    status = GModel::current()->readVTK(fileName, CTX::instance()->bigEndian);
  }
  else if(ext == ".wrl" || ext == ".WRL" || ext == ".vrml" || ext == ".VRML" ||
          ext == ".iv" || ext == ".IV"){
    status = GModel::current()->readVRML(fileName);
  }
  else if(ext == ".mesh" || ext == ".MESH"){
    status = GModel::current()->readMESH(fileName);
  }
  else if(ext == ".med" || ext == ".MED" || ext == ".mmed" || ext == ".MMED" ||
          ext == ".rmed" || ext == ".RMED"){
    status = GModel::readMED(fileName);
#if defined(HAVE_POST)
    if(status > 1) status = PView::readMED(fileName);
#endif
  }
  else if(ext == ".bdf" || ext == ".BDF" || ext == ".nas" || ext == ".NAS" ||
          ext == ".dat" || ext == ".DAT"){
    status = GModel::current()->readBDF(fileName);
  }
  else if(ext == ".p3d" || ext == ".P3D"){
    status = GModel::current()->readP3D(fileName);
  }
  else if(ext == ".fm" || ext == ".FM") {
    status = GModel::current()->readFourier(fileName);
  }
#if defined(HAVE_FLTK)
  else if(ext == ".pnm" || ext == ".PNM" || ext == ".pbm" || ext == ".PBM" ||
          ext == ".pgm" || ext == ".PGM" || ext == ".ppm" || ext == ".PPM") {
    status = read_pnm(fileName);
  }
  else if(ext == ".bmp" || ext == ".BMP") {
    status = read_bmp(fileName);
  }
#if defined(HAVE_LIBJPEG)
  else if(ext == ".jpg" || ext == ".JPG" || ext == ".jpeg" || ext == ".JPEG") {
    status = read_jpeg(fileName);
  }
#endif
#if defined(HAVE_LIBPNG)
  else if(ext == ".png" || ext == ".PNG") {
    status = read_png(fileName);
  }
#endif
#endif
#if defined(HAVE_LUA)
  else if(ext == ".lua" || ext == ".LUA") {
    status = binding::instance()->readFile(fileName.c_str());
  }
#endif
  else if(ext == ".ply2"){
    status = GModel::current()->readPLY2(fileName);
  }
  else if(ext == ".ply"){
    status = GModel::current()->readPLY(fileName);
  }
  else {
    CTX::instance()->geom.draw = 1;
    if(!strncmp(header, "$PTS", 4) || !strncmp(header, "$NO", 3) || 
       !strncmp(header, "$PARA", 5) || !strncmp(header, "$ELM", 4) ||
       !strncmp(header, "$MeshFormat", 11) || !strncmp(header, "$Comments", 9)) {
      // mesh matcher
      if(CTX::instance()->geom.matchGeomAndMesh && !GModel::current()->empty()){
	GModel* tmp2 = GModel::current();
        GModel* tmp = new GModel();
        tmp->readMSH(fileName);
        if(GeomMeshMatcher::instance()->match(tmp2, tmp))
	  fileName = "out.msh";
        delete tmp;
      }
      status = GModel::current()->readMSH(fileName);
#if defined(HAVE_POST)
      if(status > 1) status = PView::readMSH(fileName);
#endif
#if defined(HAVE_MESH)
      if(CTX::instance()->mesh.order > 1) 
        SetOrderN(GModel::current(), CTX::instance()->mesh.order,
                  CTX::instance()->mesh.secondOrderLinear, 
                  CTX::instance()->mesh.secondOrderIncomplete);
#endif
    }
#if defined(HAVE_POST)
    else if(!strncmp(header, "$PostFormat", 11) || 
            !strncmp(header, "$View", 5)) {
      status = PView::readPOS(fileName);
    }
#endif
    else {
      status = GModel::readGEO(fileName);
    }
  }

  SetBoundingBox();

  CTX::instance()->geom.draw = 1;
  CTX::instance()->mesh.changed = ENT_ALL;

#if defined(HAVE_FLTK) && defined(HAVE_POST)
  if(FlGui::available()){
    bool newViews = numViewsBefore != (int)PView::list.size();
    if(newViews){
      // go directly to the first non-empty step
      for(unsigned int i = 0; i < PView::list.size(); i++){
        for(int j = 0; j < (int)opt_view_nb_timestep(i, GMSH_GET, 0); j++){
          int step = (int)opt_view_timestep(i, GMSH_GET, 0);
          if(PView::list[i]->getData()->hasTimeStep(step))
            break;
          else
            opt_view_timestep(i, GMSH_SET | GMSH_GUI, step + 1);
        }
      }
    }
    FlGui::instance()->updateViews(newViews);
  }
#endif

  if(!status) Msg::Error("Error loading '%s'", fileName.c_str());
  Msg::StatusBar(2, true, "Done reading '%s'", fileName.c_str());

  // merge the associated option file if there is one
  if(!StatFile(fileName + ".opt"))
    MergeFile(fileName + ".opt");

  return status;
}

void ClearProject()
{
#if defined(HAVE_POST)
  for(int i = PView::list.size() - 1; i >= 0; i--)
    delete PView::list[i];
#endif
#if defined(HAVE_PARSER)
  gmsh_yysymbols.clear();
#endif
  for(int i = GModel::list.size() - 1; i >= 0; i--)
    delete GModel::list[i];
  new GModel();
  GModel::current()->setFileName(CTX::instance()->defaultFileName);
  GModel::current()->setName("");
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    FlGui::instance()->setGraphicTitle(GModel::current()->getFileName());
    FlGui::instance()->resetVisibility();
    FlGui::instance()->updateViews();
    FlGui::instance()->updateFields();
    GModel::current()->setSelection(0);
  }
#endif
}

void OpenProject(std::string fileName)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;

  if(GModel::current()->empty()){
    // if the current model is empty, make sure it's reaaally
    // cleaned-up, and reuse it (don't clear the parser variables: if
    // the model is empty we probably just launched gmsh, and we don't
    // want to delete variables set e.g. using the -string command
    // line option)
    GModel::current()->destroy();
    GModel::current()->getGEOInternals()->destroy();
  }
  else{
    // if the current model is not empty make it invisible, clear the
    // parser variables and add a new model
    GModel::current()->setVisibility(0);
#if defined(HAVE_PARSER)
    gmsh_yysymbols.clear();
#endif
    new GModel();
    GModel::current(GModel::list.size() - 1);
  }

  // temporary hack until we fill the current GModel on the fly during
  // parsing
  ResetTemporaryBoundingBox(); 

  // merge the file
  if(MergeFile(fileName)) {
    if(fileName != CTX::instance()->recentFiles.front())
      CTX::instance()->recentFiles.insert
        (CTX::instance()->recentFiles.begin(), fileName);
    if(CTX::instance()->recentFiles.size() > 5)
      CTX::instance()->recentFiles.resize(5);
#if defined(HAVE_FLTK)
    if(FlGui::available())
      FlGui::instance()->menu->fillRecentHistoryMenu();
#endif
  }
  CTX::instance()->lock = 0;

#if defined(HAVE_FLTK)
  if(FlGui::available()){
    file_watch_cb(0, 0);
    FlGui::instance()->resetVisibility();
    FlGui::instance()->updateViews();
    FlGui::instance()->updateFields();
    GModel::current()->setSelection(0);
  }
#endif
}

void OpenProjectMacFinder(const char *fileName)
{
#if defined(HAVE_FLTK)
  static int first = 1;
  if(first || !FlGui::available()){
    // just copy the filename: it will be opened when the GUI is ready
    // in main()
    GModel::current()->setFileName(fileName);
    first = 0;
  }
  else{
    OpenProject(fileName);
    drawContext::global()->draw();
  }
#endif
}
