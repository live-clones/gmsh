// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <sstream>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "Numeric.h"
#include "StringUtils.h"
#include "Geo.h"
#include "scriptStringInterface.h"
#include "OpenFile.h"
#include "Context.h"
#include "OS.h"
#include "Parser.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

static void scriptAddCommand(const std::string &text,
                             const std::string &fileNameOrEmpty,
                             const std::string &lang)
{
  if(lang != "geo") {
    if(!text.empty()) printf("%s: %s\n", lang.c_str(), text.c_str());
    return;
  }

  const std::string &fileName = fileNameOrEmpty;
  if(fileName.empty()) {
    std::string base = (getenv("PWD") ? "" : CTX::instance()->homeDir);
    GModel::current()->setFileName(base + CTX::instance()->defaultFileName);
    GModel::current()->setName("");
  }

  Msg::Debug("Adding `%s' to file `%s'", text.c_str(), fileName.c_str());
  std::vector<std::string> split = SplitFileName(fileName);
  std::string noExt = split[0] + split[1], ext = split[2];
  // make sure we don't add stuff in a non-geo file
  static bool proceed = false;
  if(!CTX::instance()->expertMode && !proceed) {
    if(ext.size() && ext != ".geo" && ext != ".GEO") {
      std::ostringstream sstream;
      sstream << "A scripting command is going to be appended to a non-`.geo' "
                 "file. Are\nyou sure you want to proceed?\n\n"
                 "You probably want to create a new `.geo' file containing the "
                 "command\n`Merge \""
              << split[1] + split[2]
              << "\";' and use that file instead.\n\n"
                 "(To disable this warning in the future, select `Enable "
                 "expert mode'\nin the option dialog.)";
      int ret = Msg::GetAnswer(sstream.str().c_str(), 2, "Cancel",
                               "Proceed as is", "Create new `.geo' file");
      if(ret == 2) {
        std::string newFileName = split[0] + split[1] + ".geo";
        if(CTX::instance()->confirmOverwrite) {
          if(!StatFile(newFileName)) {
            std::ostringstream sstream;
            sstream << "File '" << newFileName
                    << "' already exists.\n\nDo you want to replace it?";
            if(!Msg::GetAnswer(sstream.str().c_str(), 0, "Cancel", "Replace"))
              return;
          }
        }
        FILE *fp = Fopen(newFileName.c_str(), "w");
        if(!fp) {
          Msg::Error("Unable to open file '%s'", newFileName.c_str());
          return;
        }
        fprintf(fp, "Merge \"%s\";\n//+\n%s\n", (split[1] + split[2]).c_str(),
                text.c_str());
        fclose(fp);
        OpenProject(newFileName);
        return;
      }
      else if(ret == 1)
        proceed = true;
      else if(ret == 0)
        return;
    }
  }

#if defined(HAVE_PARSER)
  std::string tmpFileName =
    CTX::instance()->homeDir + CTX::instance()->tmpFileName;
  FILE *gmsh_yyin_old = gmsh_yyin;
  FILE *tmp_file;
  if(!(tmp_file = Fopen(tmpFileName.c_str(), "w"))) {
    Msg::Error("Unable to open temporary file '%s'", tmpFileName.c_str());
    return;
  }
  fprintf(tmp_file, "%s\n", text.c_str());
  fclose(tmp_file);
  gmsh_yyin = Fopen(tmpFileName.c_str(), "r");
  while(!feof(gmsh_yyin)) { gmsh_yyparse(); }
  fclose(gmsh_yyin);
  gmsh_yyin = gmsh_yyin_old;

  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  if(GModel::current()->getOCCInternals())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  GModel::current()->setName(split[1]);
  CTX::instance()->mesh.changed = ENT_ALL;

  FILE *fp = Fopen(fileName.c_str(), "a");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return;
  }
  fprintf(fp, "//+\n%s\n", text.c_str());
  fclose(fp);
#else
  Msg::Error("GEO file creation not available without Gmsh parser");
#endif

  // mark Gmsh data as changed in onelab
  if(text.find("Physical") != std::string::npos) {
    // re-import the physical groups in onelab, and only ask to re-save the mesh
    Msg::ImportPhysicalGroupsInOnelab();
    Msg::SetOnelabChanged(1);
  }
  else if(text.find("MeshSize") != std::string::npos) {
    // only ask to remesh and re-save
    Msg::SetOnelabChanged(2);
  }
  else {
    // ask to reload the geometry, remesh and re-save
    Msg::SetOnelabChanged(3);
  }
}

void scriptRemoveLastCommand(const std::string &fileName)
{
  if(StatFile(fileName)) return;
  // FIXME: make this work with compressed files
  std::ifstream t;
  t.open(fileName.c_str(), std::ifstream::in);
  std::stringstream buffer;
  buffer << t.rdbuf();
  std::string s(buffer.str());
  int found = (int)s.rfind("//+");
  if(found != (int)std::string::npos) { s.erase(found); }
  else {
    Msg::Warning("Could not find last command in script `%s'",
                 fileName.c_str());
    return;
  }
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(fp) {
    fprintf(fp, "%s", s.c_str());
    fclose(fp);
  }
  else {
    Msg::Error("Could not open file `%s'", fileName.c_str());
  }
  OpenProject(fileName);
}

static std::string list2String(List_T *list, const std::string &lang)
{
  std::ostringstream sstream;
  if(lang == "py" || lang == "jl")
    sstream << "[";
  else if(lang == "geo" || lang == "cpp")
    sstream << "{";
  for(int i = 0; i < List_Nbr(list); i++) {
    int num;
    List_Read(list, i, &num);
    if(i) sstream << ", ";
    sstream << num;
  }
  if(lang == "py" || lang == "jl")
    sstream << "]";
  else if(lang == "geo" || lang == "cpp")
    sstream << "}";
  return sstream.str();
}

static std::string vector2String(const std::vector<int> &v,
                                 const std::string &lang)
{
  std::ostringstream sstream;
  if(lang == "py" || lang == "jl")
    sstream << "[";
  else if(lang == "geo" || lang == "cpp")
    sstream << "{";
  for(std::size_t i = 0; i < v.size(); i++) {
    if(i) sstream << ", ";
    sstream << v[i];
  }
  if(lang == "py" || lang == "jl")
    sstream << "]";
  else if(lang == "geo" || lang == "cpp")
    sstream << "}";
  return sstream.str();
}

static std::string dimTags2String(const std::vector<std::pair<int, int> > &l,
                                  const std::string &lang)
{
  std::ostringstream sstream;
  if(lang == "py" || lang == "jl")
    sstream << "[";
  else if(lang == "cpp")
    sstream << "{";

  for(std::size_t i = 0; i < l.size(); i++) {
    if(lang == "geo") {
      switch(l[i].first) {
      case 0: sstream << "Point{" << l[i].second << "}; "; break;
      case 1: sstream << "Curve{" << l[i].second << "}; "; break;
      case 2: sstream << "Surface{" << l[i].second << "}; "; break;
      case 3: sstream << "Volume{" << l[i].second << "}; "; break;
      }
    }
    else if(lang == "py" || lang == "jl") {
      if(i) sstream << ", ";
      sstream << "(" << l[i].first << ", " << l[i].second << ")";
    }
    else if(lang == "cpp") {
      if(i) sstream << ", ";
      sstream << "{" << l[i].first << ", " << l[i].second << "}";
    }
    else {
      Msg::Error("Unhandled language ('%s') in script generator", lang.c_str());
    }
  }

  if(lang == "py" || lang == "jl")
    sstream << "]";
  else if(lang == "cpp")
    sstream << "}";
  return sstream.str();
}

static std::string currentFactory = "geo";

static void checkOCC(std::ostringstream &sstream, const std::string &lang)
{
  currentFactory = "occ";
#if defined(HAVE_PARSER)
  if(lang == "geo" && gmsh_yyfactory != "OpenCASCADE") {
    sstream << "SetFactory(\"OpenCASCADE\");\n";
    return;
  }
#endif
}

void scriptSetFactory(const std::string &factory, const std::string &fileName)
{
  if(factory == "OpenCASCADE")
    currentFactory = "occ";
  else
    currentFactory = "geo";
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "SetFactory(\"" << factory << "\");";
      scriptAddCommand(sstream.str(), fileName, lang);
    }
  }
}

static std::string api(const std::string &name, const std::string &args,
                       const std::string &lang)
{
  if(lang == "py" || lang == "jl")
    return ReplaceSubString("/", ".", name) + "(" + args + ")";
  else if(lang == "cpp")
    return ReplaceSubString("/", "::", name) + "(" + args + ");";

  Msg::Error("Unhandled language ('%s') in script generator", lang.c_str());
  return "";
}

void scriptSetMeshSize(const std::string &fileName, const std::vector<int> &l,
                       const std::string &lc)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "MeshSize " << vector2String(l, lang) << " = " << lc << ";";
    }
    else {
      std::vector<std::pair<int, int> > dimTags;
      for(auto t : l) dimTags.push_back(std::pair<int, int>(0, t));
      sstream << api("gmsh/model/mesh/setSize",
                     dimTags2String(dimTags, lang) + ", " + lc, lang);
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptRecombineSurface(const std::string &fileName,
                            const std::vector<int> &l)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo")
      sstream << "Recombine Surface " << vector2String(l, lang) << ";";
    else if(currentFactory == "geo")
      sstream << api("gmsh/model/geo/mesh/setRecombine", vector2String(l, lang),
                     lang);
    else
      sstream << api("gmsh/model/occ/synchronize", "", lang) << "\n"
              << api("gmsh/model/mesh/setRecombine", vector2String(l, lang),
                     lang);
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSetTransfiniteLine(std::vector<int> &l, const std::string &fileName,
                              const std::string &type,
                              const std::string &typearg,
                              const std::string &pts)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Transfinite Curve {";
      for(std::size_t i = 0; i < l.size(); i++) {
        if(i) sstream << ", ";
        sstream << l[i];
      }
      sstream << "} = " << pts;
      if(typearg.size()) sstream << " Using " << type << " " << typearg;
      sstream << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSetTransfiniteSurface(std::vector<int> &l,
                                 const std::string &fileName,
                                 const std::string &dir)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Transfinite Surface {" << l[0] << "}";
      if(l.size() > 1) {
        sstream << " = {";
        for(std::size_t i = 1; i < l.size(); i++) {
          if(i > 1) sstream << ", ";
          sstream << l[i];
        }
        sstream << "}";
      }
      if(dir != "Left") sstream << " " << dir;
      sstream << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSetTransfiniteVolume(std::vector<int> &l,
                                const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Transfinite Volume{" << l[0] << "} = {";
      for(std::size_t i = 1; i < l.size(); i++) {
        if(i > 1) sstream << ", ";
        sstream << l[i];
      }
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptEmbed(const std::string &fileName, const std::string &what,
                 std::vector<int> &l, int dim, int tag)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << what << "" << vector2String(l, lang) << " In ";
      if(dim == 2)
        sstream << "Surface{";
      else
        sstream << "Volume{";
      sstream << tag << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddParameter(const std::string &par, const std::string &value,
                        const std::string &label, const std::string &path,
                        const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << par << " = DefineNumber[ " << value;
      sstream << ", Name \"";
      if(path.size() && label.size())
        sstream << path << "/" << label;
      else if(path.size())
        sstream << path << "/" << par;
      else if(label.size())
        sstream << label;
      else
        sstream << par;
      sstream << "\" ];";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddPoint(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &lc)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Point(" << GModel::current()->getMaxElementaryNumber(0) + 1
              << ") = {" << x << ", " << y << ", " << z;
      if(lc.size()) sstream << ", " << lc;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddFieldOption(int field_id, const std::string &option_name,
                          const std::string &option_value,
                          const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Field[" << field_id << "]." << option_name << " = "
              << option_value << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddField(int field_id, const std::string &type_name,
                    const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Field[" << field_id << "] = " << type_name << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptDeleteField(int field_id, const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") { sstream << "Delete Field [" << field_id << "];"; }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSetBackgroundField(int field_id, const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") { sstream << "Background Field = " << field_id << ";"; }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddCurve(const std::string &type, std::vector<int> &p,
                    const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << type << "(" << GModel::current()->getMaxElementaryNumber(1) + 1
              << ") = {";
      for(std::size_t i = 0; i < p.size(); i++) {
        if(i) sstream << ", ";
        sstream << p[i];
      }
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddCircleArc(int p1, int p2, int p3, const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Circle(" << GModel::current()->getMaxElementaryNumber(1) + 1
              << ") = {" << p1 << ", " << p2 << ", " << p3 << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddEllipseArc(int p1, int p2, int p3, int p4,
                         const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Ellipse(" << GModel::current()->getMaxElementaryNumber(1) + 1
              << ") = {" << p1 << ", " << p2 << ", " << p3 << ", " << p4
              << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddCurveLoop(List_T *list, const std::string &fileName, int *numloop)
{
  if(RecognizeLineLoop(list, numloop)) return;
  *numloop = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    *numloop = std::max(
      *numloop, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);

  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Curve Loop(" << *numloop << ") = " << list2String(list, lang)
              << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddSurface(const std::string &type, List_T *list,
                      const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << type << "(" << GModel::current()->getMaxElementaryNumber(2) + 1
              << ") = " << list2String(list, lang) << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddSurfaceLoop(List_T *list, const std::string &fileName,
                          int *numloop)
{
  if(RecognizeSurfaceLoop(list, numloop)) return;
  *numloop = GModel::current()->getGEOInternals()->getMaxTag(-2) + 1;
  if(GModel::current()->getOCCInternals())
    *numloop = std::max(
      *numloop, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);

  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Surface Loop(" << *numloop
              << ") = " << list2String(list, lang) << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddVolume(List_T *list, const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Volume(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = " << list2String(list, lang) << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddRemovePhysicalGroup(const std::string &fileName,
                                  const std::string &what,
                                  const std::vector<int> &l,
                                  const std::string &name, int forceTag,
                                  bool append, const std::string &mode)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Physical " << what << "(";
      if(name.size()) {
        sstream << "\"" << name << "\"";
        if(forceTag) sstream << ", " << forceTag;
      }
      else {
        sstream
          << (forceTag ?
                forceTag :
                GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1);
      }
      sstream << ") ";
      if(mode == "Remove")
        sstream << "-";
      else if(append)
        sstream << "+";
      sstream << "= " << vector2String(l, lang) << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSetCompound(const std::string &fileName, const std::string &type,
                       const std::vector<int> &l)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Compound " << type << " " << vector2String(l, lang) << ";";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddCircle(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Circle(" << GModel::current()->getMaxElementaryNumber(1) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << r;
      if(alpha1.size()) sstream << ", " << alpha1;
      if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddEllipse(const std::string &fileName, const std::string &x,
                      const std::string &y, const std::string &z,
                      const std::string &rx, const std::string &ry,
                      const std::string &alpha1, const std::string &alpha2)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Ellipse(" << GModel::current()->getMaxElementaryNumber(1) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << rx << ", "
              << ry;
      if(alpha1.size()) sstream << ", " << alpha1;
      if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddDisk(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &rx, const std::string &ry)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Disk(" << GModel::current()->getMaxElementaryNumber(2) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << rx << ", "
              << ry << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddRectangle(const std::string &fileName, const std::string &x,
                        const std::string &y, const std::string &z,
                        const std::string &dx, const std::string &dy,
                        const std::string &roundedRadius)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Rectangle("
              << GModel::current()->getMaxElementaryNumber(2) + 1 << ") = {"
              << x << ", " << y << ", " << z << ", " << dx << ", " << dy;
      if(roundedRadius.size()) sstream << ", " << roundedRadius;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddSphere(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2, const std::string &alpha3)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Sphere(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << r;
      if(alpha1.size()) sstream << ", " << alpha1;
      if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
      if(alpha1.size() && alpha2.size() && alpha3.size())
        sstream << ", " << alpha3;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddCylinder(const std::string &fileName, const std::string &x,
                       const std::string &y, const std::string &z,
                       const std::string &dx, const std::string &dy,
                       const std::string &dz, const std::string &r,
                       const std::string &alpha)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Cylinder(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", "
              << dy << ", " << dz << ", " << r;
      if(alpha.size()) sstream << ", " << alpha;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddBox(const std::string &fileName, const std::string &x,
                  const std::string &y, const std::string &z,
                  const std::string &dx, const std::string &dy,
                  const std::string &dz)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Box(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", "
              << dy << ", " << dz << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddTorus(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &r1, const std::string &r2,
                    const std::string &alpha)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Torus(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << r1 << ", "
              << r2;
      if(alpha.size()) sstream << ", " << alpha;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddCone(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &dx, const std::string &dy,
                   const std::string &dz, const std::string &r1,
                   const std::string &r2, const std::string &alpha)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Cone(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", "
              << dy << ", " << dz << ", " << r1 << ", " << r2;
      if(alpha.size()) sstream << ", " << alpha;
      sstream << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddWedge(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &dx, const std::string &dy,
                    const std::string &dz, const std::string &ltx)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Wedge(" << GModel::current()->getMaxElementaryNumber(3) + 1
              << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", "
              << dy << ", " << dz << ", " << ltx << "};";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptTranslate(const std::string &fileName,
                     const std::vector<std::pair<int, int> > &l,
                     const std::string &tx, const std::string &ty,
                     const std::string &tz, bool duplicata)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Translate {" << tx << ", " << ty << ", " << tz << "} {\n  ";
      if(duplicata) sstream << "Duplicata { ";
      sstream << dimTags2String(l, lang);
      if(duplicata) sstream << "}";
      sstream << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptRotate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &ax, const std::string &ay,
                  const std::string &az, const std::string &px,
                  const std::string &py, const std::string &pz,
                  const std::string &angle, bool duplicata)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Rotate {{" << ax << ", " << ay << ", " << az << "}, {" << px
              << ", " << py << ", " << pz << "}, " << angle << "} {\n  ";
      if(duplicata) sstream << "Duplicata { ";
      sstream << dimTags2String(l, lang);
      if(duplicata) sstream << "}";
      sstream << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptDilate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &cx, const std::string &cy,
                  const std::string &cz, const std::string &sx,
                  const std::string &sy, const std::string &sz, bool duplicata)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Dilate {{" << cx << ", " << cy << ", " << cz << "}, {" << sx
              << ", " << sy << ", " << sz << "}} {\n  ";
      if(duplicata) sstream << "Duplicata { ";
      sstream << dimTags2String(l, lang);
      if(duplicata) sstream << "}";
      sstream << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptMirror(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &sa, const std::string &sb,
                  const std::string &sc, const std::string &sd, bool duplicata)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Symmetry {" << sa << ", " << sb << ", " << sc << ", " << sd
              << "} {\n  ";
      if(duplicata) sstream << "Duplicata { ";
      sstream << dimTags2String(l, lang);
      if(duplicata) sstream << "}";
      sstream << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptExtrude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &tx, const std::string &ty,
                   const std::string &tz, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Extrude {" << tx << ", " << ty << ", " << tz << "} {\n  "
              << dimTags2String(l, lang);
      if(extrudeMesh) {
        sstream << "Layers {" << layers << "}; ";
        if(recombineMesh) sstream << "Recombine;";
      }
      sstream << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptProtude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &ax, const std::string &ay,
                   const std::string &az, const std::string &px,
                   const std::string &py, const std::string &pz,
                   const std::string &angle, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Extrude {{" << ax << ", " << ay << ", " << az << "}, {" << px
              << ", " << py << ", " << pz << "}, " << angle << "} {\n  "
              << dimTags2String(l, lang);
      if(extrudeMesh) {
        sstream << "Layers{" << layers << "}; ";
        if(recombineMesh) sstream << "Recombine;";
      }
      sstream << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptAddPipe(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::vector<int> &l2)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      int wire = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
      if(GModel::current()->getOCCInternals())
        wire = std::max(
          wire, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
      sstream << "Wire(" << wire << ") = " << vector2String(l2, lang) << ";\n";
      sstream << "Extrude { " << dimTags2String(l, lang) << "} Using Wire {"
              << wire << "}\n";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSplitCurve(int edge_id, List_T *vertices,
                      const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      sstream << "Split Curve {" << edge_id << "} Point "
              << list2String(vertices, lang) << ";";
      scriptAddCommand(sstream.str(), fileName, lang);
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptBoolean(const std::string &fileName, const std::string &op,
                   const std::vector<std::pair<int, int> > &object,
                   const std::vector<std::pair<int, int> > &tool,
                   int deleteObject, int deleteTool)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << op << "{ " << dimTags2String(object, lang);
      if(deleteObject) sstream << "Delete; ";
      sstream << "}{ " << dimTags2String(tool, lang);
      if(deleteTool) sstream << "Delete; ";
      sstream << "}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptFillet(const std::string &fileName, const std::vector<int> &regions,
                  const std::vector<int> &edges, const std::string &radius)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    checkOCC(sstream, lang);
    if(lang == "geo") {
      sstream << "Fillet " << vector2String(regions, lang)
              << vector2String(edges, lang) << "{" << radius << "}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptCoherence(const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    if(lang == "geo") { scriptAddCommand("Coherence;", fileName, lang); }
    else {
      // TODO
    }
  }
}

void scriptDeleteEntities(const std::string &fileName,
                          const std::vector<std::pair<int, int> > &l,
                          bool recursive)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      if(recursive) sstream << "Recursive ";
      sstream << "Delete {\n  " << dimTags2String(l, lang) << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}

void scriptSetVisibilityAll(int mode, const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    if(lang == "geo") {
      if(mode)
        scriptAddCommand("Show \"*\";", fileName, lang);
      else
        scriptAddCommand("Hide \"*\";", fileName, lang);
    }
    else {
      // TODO
    }
  }
}

void scriptSetVisibility(int mode, const std::vector<std::pair<int, int> > &l,
                         const std::string &fileName)
{
  for(auto &lang : CTX::instance()->scriptLang) {
    std::ostringstream sstream;
    if(lang == "geo") {
      if(mode)
        sstream << "Show {\n  " << dimTags2String(l, lang) << "\n}";
      else
        sstream << "Hide {\n  " << dimTags2String(l, lang) << "\n}";
    }
    else {
      // TODO
    }
    scriptAddCommand(sstream.str(), fileName, lang);
  }
}
