// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <string.h>
#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include "GmshMessage.h"
#include "GModelIO_GEO.h"
#include "Options.h"
#include "GModel.h"
#include "Numeric.h"
#include "Context.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "OS.h"
#include "StringUtils.h"
#include "GeomMeshMatcher.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_POPPLER)
#include "gmshPopplerWrapper.h"
#endif

#if defined(HAVE_PARSER)
#include "Parser.h"
#include "FunctionManager.h"
#endif

#if defined(HAVE_MESH)
#include "HighOrder.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_FLTK)
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "onelabGroup.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include "ReadImg.h"
#endif

#if defined(HAVE_3M)
#include "3M.h"
#endif

#define SQU(a) ((a) * (a))

static void FinishUpBoundingBox()
{
  double range[3];
  for(int i = 0; i < 3; i++)
    range[i] = CTX::instance()->max[i] - CTX::instance()->min[i];

  // OCC tolerance is 1e-7
  double tol = std::max(1e-6, CTX::instance()->geom.tolerance);

  if(range[0] < tol && range[1] < tol && range[2] < tol) {
    CTX::instance()->min[0] -= 1.;
    CTX::instance()->min[1] -= 1.;
    CTX::instance()->max[0] += 1.;
    CTX::instance()->max[1] += 1.;
  }
  else if(range[0] < tol && range[1] < tol) {
    CTX::instance()->min[0] -= range[2];
    CTX::instance()->min[1] -= range[2];
    CTX::instance()->max[0] += range[2];
    CTX::instance()->max[1] += range[2];
  }
  else if(range[0] < tol && range[2] < tol) {
    CTX::instance()->min[0] -= range[1];
    CTX::instance()->max[0] += range[1];
  }
  else if(range[1] < tol && range[2] < tol) {
    CTX::instance()->min[1] -= range[0];
    CTX::instance()->max[1] += range[0];
  }
  else if(range[0] < tol) {
    double l = sqrt(SQU(range[1]) + SQU(range[2]));
    CTX::instance()->min[0] -= l;
    CTX::instance()->max[0] += l;
  }
  else if(range[1] < tol) {
    double l = sqrt(SQU(range[0]) + SQU(range[2]));
    CTX::instance()->min[1] -= l;
    CTX::instance()->max[1] += l;
  }

  CTX::instance()->lc =
    sqrt(SQU(CTX::instance()->max[0] - CTX::instance()->min[0]) +
         SQU(CTX::instance()->max[1] - CTX::instance()->min[1]) +
         SQU(CTX::instance()->max[2] - CTX::instance()->min[2]));
  for(int i = 0; i < 3; i++)
    CTX::instance()->cg[i] =
      0.5 * (CTX::instance()->min[i] + CTX::instance()->max[i]);
}

void SetBoundingBox(double xmin, double xmax, double ymin, double ymax,
                    double zmin, double zmax)
{
  CTX::instance()->min[0] = xmin;
  CTX::instance()->max[0] = xmax;
  CTX::instance()->min[1] = ymin;
  CTX::instance()->max[1] = ymax;
  CTX::instance()->min[2] = zmin;
  CTX::instance()->max[2] = zmax;
  FinishUpBoundingBox();
}

void SetBoundingBox(bool aroundVisible)
{
  if(CTX::instance()->forcedBBox) return;

  SBoundingBox3d bb = GModel::current()->bounds(aroundVisible);

#if defined(HAVE_POST)
  if(bb.empty()) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(!PView::list[i]->getData()->getBoundingBox().empty())
        if(!aroundVisible || PView::list[i]->getOptions()->visible)
          bb += PView::list[i]->getData()->getBoundingBox();
  }
#endif
  if(bb.empty()) {
    bb += SPoint3(-1., -1., -1.);
    bb += SPoint3(1., 1., 1.);
  }

  CTX::instance()->min[0] = bb.min().x();
  CTX::instance()->max[0] = bb.max().x();
  CTX::instance()->min[1] = bb.min().y();
  CTX::instance()->max[1] = bb.max().y();
  CTX::instance()->min[2] = bb.min().z();
  CTX::instance()->max[2] = bb.max().z();
  FinishUpBoundingBox();
}

// FIXME: this is necessary for now to have an approximate CTX::instance()->lc
// *while* parsing input files (it's important since some of the geometrical
// operations use a tolerance that depends on CTX::instance()->lc). This will be
// removed once the new database is filled directly during the parsing step
static SBoundingBox3d temp_bb;

void ResetTemporaryBoundingBox() { temp_bb.reset(); }

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

static std::vector<FILE *> openedFiles;

int ParseFile(const std::string &fileName, bool close, bool errorIfMissing)
{
#if !defined(HAVE_PARSER)
  Msg::Error("Gmsh parser is not compiled in this version");
  return 0;
#else

  // add 'b' for pure Windows programs: opening in text mode messes up
  // fsetpos/fgetpos (used e.g. for user-defined functions)
  FILE *fp;
  if(!(fp = Fopen(fileName.c_str(), "rb"))) {
    if(errorIfMissing)
      Msg::Error("Unable to open file '%s'", fileName.c_str());
    return 0;
  }

  Msg::AddOnelabStringChoice("Gmsh/}Input files", "file", fileName, true, true,
                             Msg::GetNumOnelabClients() > 1);

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

  while(!feof(gmsh_yyin)) {
    gmsh_yyparse();
    if(gmsh_yyerrorstate > 20) {
      if(gmsh_yyerrorstate != 999) // 999 is a voluntary exit
        Msg::Error("Too many errors: aborting parser...");
      gmsh_yyflush();
      break;
    }
  }

  if(close) {
    fclose(gmsh_yyin);
    gmsh_yyflush();
  }
  else {
    openedFiles.push_back(gmsh_yyin);
  }

  gmsh_yyname = old_yyname;
  gmsh_yyin = old_yyin;
  gmsh_yyerrorstate = old_yyerrorstate;
  gmsh_yylineno = old_yylineno;
  gmsh_yyviewindex = old_yyviewindex;

#if defined(HAVE_FLTK) && defined(HAVE_POST)
  if(FlGui::available()) {
    FlGui::instance()->updateViews(true, false);
  }
#endif

  return 1;
#endif
}

static bool DoSystemUncompress(const std::string &fileName,
                               const std::string &noExt)
{
  std::ostringstream sstream;
  sstream << "File '" << fileName << "' is in gzip format.\n\n"
          << "Do you want to uncompress it?";
  if(Msg::GetAnswer(sstream.str().c_str(), 0, "Cancel", "Uncompress")) {
    if(SystemCall(std::string("gunzip -c ") + fileName + " > " + noExt, true))
      Msg::Warning(
        "Potentially failed to uncompress `%s': check directory permissions",
        fileName.c_str());
    GModel::current()->setFileName(noExt);
    return true;
  }
  return false;
}

void ParseString(const std::string &str, bool inCurrentModelDir)
{
  if(str.empty()) return;
  std::string fileName;
  if(inCurrentModelDir)
    fileName = FixRelativePath(GModel::current()->getFileName(),
                               CTX::instance()->tmpFileName);
  else
    fileName = CTX::instance()->homeDir + CTX::instance()->tmpFileName;
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(fp) {
    fprintf(fp, "%s\n", str.c_str());
    fclose(fp);
    GModel::readGEO(fileName);
    UnlinkFile(fileName);
  }
}

#if defined(HAVE_ONELAB)
static std::string GetSolverForExtension(const std::string &ext)
{
  for(int i = 0; i < NUM_SOLVERS; i++) {
    if(opt_solver_extension(i, GMSH_GET, "") == ext)
      return opt_solver_name(i, GMSH_GET, "");
  }
  return "";
}

static int DefineSolver(const std::string &name)
{
  int i;
  for(i = 0; i < NUM_SOLVERS; i++) {
    if(opt_solver_name(i, GMSH_GET, "") == name) return i;
  }
  opt_solver_name(i - 1, GMSH_SET | GMSH_GUI, name);
  return i - 1;
}
#endif

int MergeFile(const std::string &fileName, bool errorIfMissing,
              bool setBoundingBox, bool importPhysicalsInOnelab,
              int partitionToRead)
{
  // added 'b' for pure Windows programs, since some of these files
  // contain binary data
  FILE *fp = Fopen(fileName.c_str(), "rb");
  if(!fp) {
    if(errorIfMissing)
      Msg::Error("Unable to open file '%s'", fileName.c_str());
    return 0;
  }

  char header[256];
  if(!fgets(header, sizeof(header), fp)) {
    fclose(fp);
    return 0;
  }
  fclose(fp);

  Msg::StatusBar(true, "Reading '%s'...", fileName.c_str());

  Msg::AddOnelabStringChoice("Gmsh/}Input files", "file", fileName, true, true,
                             Msg::GetNumOnelabClients() > 1);

  std::vector<std::string> split = SplitFileName(fileName);
  std::string noExt = split[0] + split[1], ext = split[2];

  if(ext == ".gz") {
    if(DoSystemUncompress(fileName, noExt)) return MergeFile(noExt, false);
  }

  CTX::instance()->geom.draw = 0; // don't try to draw the model while reading

#if defined(HAVE_FLTK) && defined(HAVE_POST)
  int numViewsBefore = PView::list.size();
#endif
  int status = 0;

#if defined(HAVE_ONELAB)
  std::string solver = GetSolverForExtension(ext);
  if(solver.size()) {
    int num = DefineSolver(solver);
    Msg::SetOnelabString(solver + "/Model name", fileName, true, true, false, 3,
                         "file");
    if(GModel::current()->getName() == "" ||
       Msg::GetOnelabString("Gmsh/Model name").empty()) {
      GModel::current()->setFileName(split[0] + split[1] + ".geo");
      GModel::current()->setName(split[1] + ".geo");
      Msg::SetOnelabChanged(3);
    }
    CTX::instance()->launchSolverAtStartup = num;
    CTX::instance()->geom.draw = 1;
    return 1;
  }
  else if(ext == ".py" || ext == ".PY" || ext == ".m" || ext == ".M" ||
          ext == ".exe" || ext == ".EXE") {
    int num = DefineSolver(split[1]);
    opt_solver_executable(num, GMSH_SET, fileName);
    CTX::instance()->launchSolverAtStartup = num;
    CTX::instance()->geom.draw = 1;
    return 1;
  }
#endif

  if(GModel::current()->getName() == "") {
    GModel::current()->setFileName(fileName);
    GModel::current()->setName(SplitFileName(fileName)[1]);
  }

  if(ext == ".stl" || ext == ".STL") {
    status =
      GModel::current()->readSTL(fileName, CTX::instance()->geom.tolerance);
  }
  else if(ext == ".NII" || ext == ".nii") {
    status =
      GModel::current()->readNII(fileName);
  }
  else if(ext == ".brep" || ext == ".rle" || ext == ".brp" || ext == ".BRP") {
    status = GModel::current()->readOCCBREP(fileName);
  }
  else if(ext == ".xao" || ext == ".XAO") {
    status = GModel::current()->readOCCXAO(fileName);
  }
  else if(ext == ".iges" || ext == ".IGES" || ext == ".igs" || ext == ".IGS") {
    status = GModel::current()->readOCCIGES(fileName);
  }
  else if(ext == ".step" || ext == ".STEP" || ext == ".stp" || ext == ".STP") {
    status = GModel::current()->readOCCSTEP(fileName);
    //status = GModel::current()->readParasolidSTEP(fileName);
  }
  else if(ext == ".sat" || ext == ".SAT") {
    status = GModel::current()->readACISSAT(fileName);
  }
  else if(ext == ".x_t" || ext == ".xmt_txt" ||
          ext == ".x_b" || ext == ".xmt_bin") {
    status = GModel::current()->readParasolidXMT(fileName);
  }
  else if(ext == ".unv" || ext == ".UNV") {
    status = GModel::current()->readUNV
      (fileName, CTX::instance()->mesh.readGroupsOfElements);
  }
  else if(ext == ".vtk" || ext == ".VTK") {
    status = GModel::current()->readVTK(fileName, CTX::instance()->bigEndian);
  }
  else if(ext == ".wrl" || ext == ".WRL" || ext == ".vrml" || ext == ".VRML" ||
          ext == ".iv" || ext == ".IV") {
    status = GModel::current()->readVRML(fileName);
  }
  else if(ext == ".mesh" || ext == ".MESH") {
    status = GModel::current()->readMESH(fileName);
  }
  else if(ext == ".off" || ext == ".OFF") {
    status = GModel::current()->readOFF(fileName);
  }
  else if(ext == ".diff" || ext == ".DIFF") {
    status = GModel::current()->readDIFF(fileName);
  }
  else if(ext == ".med" || ext == ".MED" || ext == ".mmed" || ext == ".MMED" ||
          ext == ".rmed" || ext == ".RMED") {
    if(CTX::instance()->mesh.medSingleModel)
      status = GModel::current()->readMED(fileName, 0);
    else
      status = GModel::readMED(fileName);
#if defined(HAVE_POST)
    if(status > 1) status = PView::readMED(fileName);
#endif
  }
  else if(ext == ".bdf" || ext == ".BDF" || ext == ".nas" || ext == ".NAS") {
    status = GModel::current()->readBDF(fileName);
  }
  else if (ext == ".neu" || ext == ".NEU") {
    status=GModel::current()->readNEU(fileName);
  }
  else if(ext == ".dat" || ext == ".DAT") {
    if(!strncmp(header, "BEGIN ACTRAN", 12))
      status = GModel::current()->readACTRAN(fileName);
    else if(!strncmp(header, "!", 1) || !strncmp(header, ";ECHO", 5) ||
            !strncmp(header, ".NOE", 4))
      status = GModel::current()->readSAMCEF(fileName);
    else
      status = GModel::current()->readBDF(fileName);
  }
  else if(ext == ".p3d" || ext == ".P3D") {
    status = GModel::current()->readP3D(fileName);
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
  else if(ext == ".ply2" || ext == ".PLY2") {
    status = GModel::current()->readPLY2(fileName);
  }
  else if(ext == ".ply" || ext == ".PLY") {
    status = GModel::current()->readPLY(fileName);
  }
  else if(ext == ".geom" || ext == ".GEOM") {
    status = GModel::current()->readGEOM(fileName);
  }
#if defined(HAVE_LIBCGNS)
  else if(ext == ".cgns" || ext == ".CGNS") {
    std::vector<std::vector<MVertex *> > vertPerZone;
    std::vector<std::vector<MElement *> > eltPerZone;
    if(CTX::instance()->geom.matchGeomAndMesh && !GModel::current()->empty()) {
      GModel *tmp2 = GModel::current();
      GModel *tmp = new GModel();
      tmp->readCGNS(fileName, vertPerZone, eltPerZone);
      tmp->scaleMesh(CTX::instance()->geom.matchMeshScaleFactor);
      status = GeomMeshMatcher::instance()->match(tmp2, tmp);
      delete tmp;
      GModel::setCurrent(tmp2);
      tmp2->setVisibility(1);
    }
    else {
      CTX::instance()->geom.matchMeshScaleFactor = 1;
      status = GModel::current()->readCGNS(fileName, vertPerZone, eltPerZone);
    }
#if defined(HAVE_POST)
    if((status > 1) && (CTX::instance()->mesh.cgnsImportIgnoreSolution == 0)) {
      status = PView::readCGNS(vertPerZone, eltPerZone, fileName);
    }
#endif
  }
#endif
#if defined(HAVE_3M)
  else if(ext == ".csv") {
    status = readFile3M(fileName);
  }
#endif
  else {
    CTX::instance()->geom.draw = 1;
    if(!strncmp(header, "$PTS", 4) || !strncmp(header, "$NO", 3) ||
       !strncmp(header, "$PARA", 5) || !strncmp(header, "$ELM", 4) ||
       !strncmp(header, "$MeshFormat", 11) ||
       !strncmp(header, "$Comments", 9)) {
      // mesh matcher
      if(CTX::instance()->geom.matchGeomAndMesh &&
         !GModel::current()->empty()) {
        GModel *tmp2 = GModel::current();
        GModel *tmp = new GModel();
        tmp->readMSH(fileName);
        tmp->scaleMesh(CTX::instance()->geom.matchMeshScaleFactor);
        status = GeomMeshMatcher::instance()->match(tmp2, tmp);
        delete tmp;
        GModel::setCurrent(tmp2);
        tmp2->setVisibility(1);
      }
      else {
        CTX::instance()->geom.matchMeshScaleFactor = 1;
        status = GModel::current()->readMSH(fileName);
      }
#if defined(HAVE_POST)
      if(status > 1) status = PView::readMSH(fileName, -1, partitionToRead);
#endif
    }
#if defined(HAVE_POST)
    else if(ext == ".pch") {
      status = PView::readPCH(fileName);
    }
    else if(!strncmp(header, "$PostFormat", 11) ||
            !strncmp(header, "$View", 5)) {
      status = PView::readPOS(fileName);
    }
#endif
    else {
      status = GModel::readGEO(fileName);
    }
  }

  GModel::current()->getGEOInternals()->setMaxTag(
    0, std::max(GModel::current()->getGEOInternals()->getMaxTag(0),
                GModel::current()->getMaxElementaryNumber(0)));
  GModel::current()->getGEOInternals()->setMaxTag(
    1, std::max(GModel::current()->getGEOInternals()->getMaxTag(1),
                GModel::current()->getMaxElementaryNumber(1)));
  GModel::current()->getGEOInternals()->setMaxTag(
    2, std::max(GModel::current()->getGEOInternals()->getMaxTag(2),
                GModel::current()->getMaxElementaryNumber(2)));
  GModel::current()->getGEOInternals()->setMaxTag(
    3, std::max(GModel::current()->getGEOInternals()->getMaxTag(3),
                GModel::current()->getMaxElementaryNumber(3)));

  if(setBoundingBox) SetBoundingBox();

  CTX::instance()->geom.draw = 1;
  CTX::instance()->mesh.changed = ENT_ALL;

  if(importPhysicalsInOnelab) Msg::ImportPhysicalGroupsInOnelab();

#if defined(HAVE_FLTK) && defined(HAVE_POST)
  if(FlGui::available()) {
    // go directly to the first non-empty step after the one that is requested
    for(std::size_t i = numViewsBefore; i < PView::list.size(); i++)
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        PView::list[i]->getData()->getFirstNonEmptyTimeStep(
                          opt_view_timestep(i, GMSH_GET, 0)));
    FlGui::instance()->updateViews(numViewsBefore != (int)PView::list.size(),
                                   false);
  }
#endif

  if(!status) Msg::Error("Error loading '%s'", fileName.c_str());
  Msg::StatusBar(true, "Done reading '%s'", fileName.c_str());

  CTX::instance()->fileread = true;

  // merge the associated option file if there is one
  if(!StatFile(fileName + ".opt")) MergeFile(fileName + ".opt");
  return status;
}

int MergePostProcessingFile(const std::string &fileName, int showViews,
                            bool showLastStep, bool errorIfMissing)
{
#if defined(HAVE_POST)
  // check if there is a mesh in the file
  FILE *fp = Fopen(fileName.c_str(), "rb");
  if(!fp) {
    if(errorIfMissing)
      Msg::Error("Unable to open file '%s'", fileName.c_str());
    return 0;
  }
  char header[256];
  if(!fgets(header, sizeof(header), fp)) {
    fclose(fp);
    return 0;
  }
  bool haveMesh = false;
  if(!strncmp(header, "$MeshFormat", 11)) {
    while(!feof(fp) && fgets(header, sizeof(header), fp)) {
      if(!strncmp(header, "$Nodes", 6)) {
        haveMesh = true;
        break;
      }
      else if(!strncmp(header, "$NodeData", 9) ||
              !strncmp(header, "$ElementData", 12) ||
              !strncmp(header, "$ElementNodeData", 16)) {
        break;
      }
    }
  }
  fclose(fp);

  // store old step values
  std::size_t n = PView::list.size();
  std::vector<int> steps(n, 0);
  if(showLastStep) {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      steps[i] = (int)opt_view_nb_timestep(i, GMSH_GET, 0);
  }

  // if there is a mesh, create a new model to store it (don't merge elements in
  // the current mesh!)
  GModel *old = GModel::current();
  if(haveMesh) {
    GModel *m = new GModel();
    GModel::setCurrent(m);
  }
  int ret =
    MergeFile(fileName, errorIfMissing, old->bounds().empty() ? true : false);
  GModel::setCurrent(old);
  old->setVisibility(1);

  // hide everything except onelab X-Y graphs and views with attribute
  // "AlwaysVisible"
  if(showViews == 0) {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(PView::list[i]->getData()->getFileName().substr(0, 6) != "ONELAB" &&
         PView::list[i]->getOptions()->attributes.find("AlwaysVisible") ==
         std::string::npos)
        PView::list[i]->getOptions()->visible = 0;
    }
  }
  else if(showViews == 2 && n < PView::list.size()) {
    // if we created new views, assume we only want to see those (and the
    // onelab X-Y graphs)
    for(std::size_t i = 0; i < n; i++) {
      if(PView::list[i]->getData()->getFileName().substr(0, 6) != "ONELAB" &&
         PView::list[i]->getOptions()->attributes.find("AlwaysVisible") ==
         std::string::npos)
        PView::list[i]->getOptions()->visible = 0;
    }
  }

  // if we added steps, and we have more than 2 (to avoid always showing the
  // imaginary part for complex fields), go to the last one
  if(showLastStep) {
    steps.resize(PView::list.size(), 0);
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      int step = (int)opt_view_nb_timestep(i, GMSH_GET, 0);
      if(step > steps[i] && steps[i] > 1)
        opt_view_timestep(i, GMSH_SET | GMSH_GUI, step - 1);
    }
  }

  return ret;
#else
  return 0;
#endif
}

void DeleteAllModelsAndViews()
{
#if defined(HAVE_POST)
  // delete all views
  while(PView::list.size() > 0) delete PView::list[PView::list.size() - 1];
  std::vector<PView *>().swap(PView::list);
  PView::setGlobalTag(0);
  PViewData::removeAllInterpolationSchemes();
#endif

#if defined(HAVE_PARSER)
  // clear parser data
  gmsh_yysymbols.clear();
  gmsh_yystringsymbols.clear();
  gmsh_yyfactory.clear();
  gmsh_yynamespaces.clear();
#endif

  // delete the temp file
  if(!Msg::GetCommRank())
    UnlinkFile(CTX::instance()->homeDir + CTX::instance()->tmpFileName);

  // delete all models
  while(GModel::list.size() > 0) delete GModel::list[GModel::list.size() - 1];
  std::vector<GModel *>().swap(GModel::list);

  // close the files that might have been left open by ParseFile
  if(openedFiles.size()) {
    for(std::size_t i = 0; i < openedFiles.size(); i++) fclose(openedFiles[i]);
    openedFiles.clear();
  }
}

void ClearProject()
{
  Msg::Info("Clearing all models and views...");
  DeleteAllModelsAndViews();
  Msg::Info("Done clearing all models and views");

  new GModel();
  std::string base = (getenv("PWD") ? "" : CTX::instance()->homeDir);
  GModel::current()->setFileName(base + CTX::instance()->defaultFileName);
  GModel::current()->setName("");
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    FlGui::instance()->resetVisibility();
    FlGui::instance()->updateViews(true, true);
    FlGui::instance()->updateFields();
    GModel::current()->setSelection(0);
  }
#endif
  Msg::ResetErrorCounter();
}

void OpenProject(const std::string &fileName, bool errorIfMissing)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;

  Msg::ResetErrorCounter();

  if(GModel::current()->empty()) {
    // if the current model is empty, make sure it's reaaally cleaned-up, and
    // reuse it
    GModel::current()->destroy();
    GModel::current()->getGEOInternals()->destroy();
  }
  else {
    // if the current model is not empty make it invisible and add a new model
    new GModel();
    GModel::current(GModel::list.size() - 1);
  }

  // clear parser variables, but keep -setnumber/-setstrings command line
  // definitions
#if defined(HAVE_PARSER)
  gmsh_yysymbols.clear();
  gmsh_yystringsymbols.clear();
  std::map<std::string, std::vector<double> > cln(Msg::GetCommandLineNumbers());
  for(auto it = cln.begin();
      it != cln.end(); it++)
    gmsh_yysymbols[it->first].value = it->second;
  std::map<std::string, std::string> cls(Msg::GetCommandLineStrings());
  for(auto it = cls.begin();
      it != cls.end(); it++)
    gmsh_yystringsymbols[it->first] = std::vector<std::string>(1, it->second);
  gmsh_yyfactory.clear();
  gmsh_yynamespaces.clear();
  FunctionManager::Instance()->clear();
#endif

  // temporary hack until we fill the current GModel on the fly during parsing
  ResetTemporaryBoundingBox();

  // merge the file
  MergeFile(fileName, errorIfMissing);

  // fill recent opened file list
  std::vector<std::string> tmp = CTX::instance()->recentFiles;
  CTX::instance()->recentFiles.clear();
  CTX::instance()->recentFiles.push_back(fileName);
  for(std::size_t i = 0; i < tmp.size(); i++) {
    if(tmp[i] != fileName) CTX::instance()->recentFiles.push_back(tmp[i]);
  }
  CTX::instance()->recentFiles.resize(10);
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->graph[0]->fillRecentHistoryMenu();
#endif

  // close the files that might have been left open by ParseFile
  if(openedFiles.size()) {
    for(std::size_t i = 0; i < openedFiles.size(); i++) fclose(openedFiles[i]);
    openedFiles.clear();
  }

  CTX::instance()->lock = 0;

  // FIXME: temporary for auto-extrude testing
  if(CTX::instance()->geom.autoExtrude)
    GModel::current()->addAutomaticExtrusionConstraints({10}, {1}, true, {});

#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    file_watch_cb(nullptr, nullptr);
    FlGui::instance()->resetVisibility();
    FlGui::instance()->updateViews(true, false);
    FlGui::instance()->updateFields();
    GModel::current()->setSelection(0);
  }
#endif
}

void OpenProjectMacFinder(const char *fileName)
{
  if(!fileName) return;
  std::string name(fileName);
  if(name == Msg::GetExecutableName()) {
    Msg::Debug("Ignoring macOS file open callback, as the given file name "
               "is the executable name '%s'", name.c_str());
    return;
  }
#if defined(HAVE_FLTK)
  if(!FlGui::available() || !FlGui::getFinishedProcessingCommandLine()) {
    // Gmsh is not ready: will open the file later
    FlGui::setOpenedThroughMacFinder(name);
  }
  else {
    // Gmsh is running
    OpenProject(name);
    drawContext::global()->draw();
    if(CTX::instance()->launchSolverAtStartup >= 0)
      solver_cb(nullptr, (void *)(intptr_t)CTX::instance()->launchSolverAtStartup);
  }
#endif
}
