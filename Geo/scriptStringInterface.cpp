// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
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

static void addInFile(const std::string &text,
                      const std::string &fileNameOrEmpty)
{
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
                 "file. Are\n"
                 "you sure you want to proceed?\n\n"
                 "You probably want to create a new `.geo' file containing the "
                 "command\n"
                 "`Merge \""
              << split[1] + split[2]
              << "\";' and use that file instead.\n\n"
                 "(To disable this warning in the future, select `Enable "
                 "expert mode'\n"
                 "in the option dialog.)";
      int ret = Msg::GetAnswer(sstream.str().c_str(), 2, "Cancel",
                               "Proceed as is", "Create new `.geo' file");
      if(ret == 2) {
        std::string newFileName = split[0] + split[1] + ".geo";
        if(CTX::instance()->confirmOverwrite) {
          if(!StatFile(newFileName)) {
            std::ostringstream sstream;
            sstream << "File '" << newFileName
                    << "' already exists.\n\n"
                       "Do you want to replace it?";
            if(!Msg::GetAnswer(sstream.str().c_str(), 0, "Cancel", "Replace"))
              return;
          }
        }
        FILE *fp = Fopen(newFileName.c_str(), "w");
        if(!fp) {
          Msg::Error("Unable to open file '%s'", newFileName.c_str());
          return;
        }
        fprintf(fp, "Merge \"%s\";\n%s\n", (split[1] + split[2]).c_str(),
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
  else if(text.find("Characteristic") != std::string::npos) {
    // only ask to remesh and re-save
    Msg::SetOnelabChanged(2);
  }
  else {
    // ask to reload the geometry, remesh and re-save
    Msg::SetOnelabChanged(3);
  }
}

static std::string list2String(List_T *list)
{
  std::ostringstream sstream;
  for(int i = 0; i < List_Nbr(list); i++) {
    int num;
    List_Read(list, i, &num);
    if(i) sstream << ", ";
    sstream << num;
  }
  return sstream.str();
}

static std::string vector2String(const std::vector<int> &v)
{
  std::ostringstream sstream;
  for(std::size_t i = 0; i < v.size(); i++) {
    if(i) sstream << ", ";
    sstream << v[i];
  }
  return sstream.str();
}

static std::string dimTags2String(const std::vector<std::pair<int, int> > &l)
{
  std::ostringstream sstream;
  for(std::size_t i = 0; i < l.size(); i++) {
    switch(l[i].first) {
    case 0: sstream << "Point{" << l[i].second << "}; "; break;
    case 1: sstream << "Curve{" << l[i].second << "}; "; break;
    case 2: sstream << "Surface{" << l[i].second << "}; "; break;
    case 3: sstream << "Volume{" << l[i].second << "}; "; break;
    }
  }
  return sstream.str();
}

static void checkOCC(std::ostringstream &sstream)
{
#if defined(HAVE_PARSER)
  if(gmsh_yyfactory != "OpenCASCADE")
    sstream << "SetFactory(\"OpenCASCADE\");\n";
#endif
}

void scriptSetFactory(const std::string &factory, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "SetFactory(\"" << factory << "\");";
  addInFile(sstream.str(), fileName);
}

void scriptSetCharacteristicLength(const std::string &fileName,
                                   const std::vector<int> &l,
                                   const std::string &lc)
{
  std::ostringstream sstream;
  sstream << "Characteristic Length {" << vector2String(l) << "} = " << lc
          << ";";
  addInFile(sstream.str(), fileName);
}

void scriptRecombineSurface(const std::string &fileName,
                            const std::vector<int> &l)
{
  std::ostringstream sstream;
  sstream << "Recombine Surface {" << vector2String(l) << "};";
  addInFile(sstream.str(), fileName);
}

void scriptSetTransfiniteLine(std::vector<int> &l, const std::string &fileName,
                              const std::string &type,
                              const std::string &typearg,
                              const std::string &pts)
{
  std::ostringstream sstream;
  sstream << "Transfinite Curve {";
  for(std::size_t i = 0; i < l.size(); i++) {
    if(i) sstream << ", ";
    sstream << l[i];
  }
  sstream << "} = " << pts;
  if(typearg.size()) sstream << " Using " << type << " " << typearg;
  sstream << ";";
  addInFile(sstream.str(), fileName);
}

void scriptSetTransfiniteSurface(std::vector<int> &l,
                                 const std::string &fileName,
                                 const std::string &dir)
{
  std::ostringstream sstream;
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
  addInFile(sstream.str(), fileName);
}

void scriptSetTransfiniteVolume(std::vector<int> &l,
                                const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Transfinite Volume{" << l[0] << "} = {";
  for(std::size_t i = 1; i < l.size(); i++) {
    if(i > 1) sstream << ", ";
    sstream << l[i];
  }
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptEmbed(const std::string &fileName, const std::string &what,
                 std::vector<int> &l, int dim, int tag)
{
  std::ostringstream sstream;
  sstream << what << "{" << vector2String(l) << "} In ";
  if(dim == 2)
    sstream << "Surface{";
  else
    sstream << "Volume{";
  sstream << tag << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddParameter(const std::string &par, const std::string &value,
                        const std::string &label, const std::string &path,
                        const std::string &fileName)
{
  std::ostringstream sstream;
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
  addInFile(sstream.str(), fileName);
}

void scriptAddPoint(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &lc)
{
  std::ostringstream sstream;
  sstream << "Point(" << GModel::current()->getMaxElementaryNumber(0) + 1
          << ") = {" << x << ", " << y << ", " << z;
  if(lc.size()) sstream << ", " << lc;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddFieldOption(int field_id, const std::string &option_name,
                          const std::string &option_value,
                          const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "]." << option_name << " = "
          << option_value << ";";
  addInFile(sstream.str(), fileName);
}

void scriptAddField(int field_id, const std::string &type_name,
                    const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "] = " << type_name << ";";
  addInFile(sstream.str(), fileName);
}

void scriptDeleteField(int field_id, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Delete Field [" << field_id << "];";
  addInFile(sstream.str(), fileName);
}

void scriptSetBackgroundField(int field_id, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Background Field = " << field_id << ";";
  addInFile(sstream.str(), fileName);
}

void scriptAddCurve(const std::string &type, std::vector<int> &p,
                    const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << type << "(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {";
  for(std::size_t i = 0; i < p.size(); i++) {
    if(i) sstream << ", ";
    sstream << p[i];
  }
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddCircleArc(int p1, int p2, int p3, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Circle(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << p1 << ", " << p2 << ", " << p3 << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddEllipseArc(int p1, int p2, int p3, int p4,
                         const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Ellipse(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << p1 << ", " << p2 << ", " << p3 << ", " << p4 << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddCurveLoop(List_T *list, const std::string &fileName, int *numloop)
{
  if(RecognizeLineLoop(list, numloop)) return;
  *numloop = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    *numloop = std::max(
      *numloop, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  std::ostringstream sstream;
  sstream << "Curve Loop(" << *numloop << ") = {" << list2String(list) << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddSurface(const std::string &type, List_T *list,
                      const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << type << "(" << GModel::current()->getMaxElementaryNumber(2) + 1
          << ") = {" << list2String(list) << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddSurfaceLoop(List_T *list, const std::string &fileName,
                          int *numloop)
{
  if(RecognizeSurfaceLoop(list, numloop)) return;
  *numloop = GModel::current()->getGEOInternals()->getMaxTag(-2) + 1;
  if(GModel::current()->getOCCInternals())
    *numloop = std::max(
      *numloop, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  std::ostringstream sstream;
  sstream << "Surface Loop(" << *numloop << ") = {" << list2String(list)
          << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddVolume(List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Volume(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << list2String(list) << "};";
  addInFile(sstream.str(), fileName);
}

void scriptRemovePhysicalGroup(const std::string &fileName,
                               const std::string &what,
                               const std::vector<int> &l,
                               const std::string &name, int forceTag,
                               bool append, const std::string &mode)
{
  std::ostringstream sstream;
  sstream << "Physical " << what << "(";
  if(name.size()) {
    sstream << "\"" << name << "\"";
    if(forceTag) sstream << ", " << forceTag;
  }
  else {
    sstream << (forceTag ?
                  forceTag :
                  GModel::current()->getGEOInternals()->getMaxPhysicalTag() +
                    1);
  }
  sstream << ") ";
  if(mode == "Remove")
    sstream << "-";
  else if(append)
    sstream << "+";
  sstream << "= {" << vector2String(l) << "};";
  addInFile(sstream.str(), fileName);
}

void scriptSetCompound(const std::string &fileName, const std::string &type,
                       const std::vector<int> &l)
{
  std::ostringstream sstream;
  sstream << "Compound " << type << " {" << vector2String(l) << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddCircle(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Circle(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << r;
  if(alpha1.size()) sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddEllipse(const std::string &fileName, const std::string &x,
                      const std::string &y, const std::string &z,
                      const std::string &rx, const std::string &ry,
                      const std::string &alpha1, const std::string &alpha2)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Ellipse(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << rx << ", " << ry;
  if(alpha1.size()) sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddDisk(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &rx, const std::string &ry)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Disk(" << GModel::current()->getMaxElementaryNumber(2) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << rx << ", " << ry
          << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddRectangle(const std::string &fileName, const std::string &x,
                        const std::string &y, const std::string &z,
                        const std::string &dx, const std::string &dy,
                        const std::string &roundedRadius)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Rectangle(" << GModel::current()->getMaxElementaryNumber(2) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy;
  if(roundedRadius.size()) sstream << ", " << roundedRadius;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddSphere(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2, const std::string &alpha3)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Sphere(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << r;
  if(alpha1.size()) sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
  if(alpha1.size() && alpha2.size() && alpha3.size()) sstream << ", " << alpha3;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddCylinder(const std::string &fileName, const std::string &x,
                       const std::string &y, const std::string &z,
                       const std::string &dx, const std::string &dy,
                       const std::string &dz, const std::string &r,
                       const std::string &alpha)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Cylinder(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy
          << ", " << dz << ", " << r;
  if(alpha.size()) sstream << ", " << alpha;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddBox(const std::string &fileName, const std::string &x,
                  const std::string &y, const std::string &z,
                  const std::string &dx, const std::string &dy,
                  const std::string &dz)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Box(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy
          << ", " << dz << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddTorus(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &r1, const std::string &r2,
                    const std::string &alpha)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Torus(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << r1 << ", " << r2;
  if(alpha.size()) sstream << ", " << alpha;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddCone(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &dx, const std::string &dy,
                   const std::string &dz, const std::string &r1,
                   const std::string &r2, const std::string &alpha)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Cone(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy
          << ", " << dz << ", " << r1 << ", " << r2;
  if(alpha.size()) sstream << ", " << alpha;
  sstream << "};";
  addInFile(sstream.str(), fileName);
}

void scriptAddWedge(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &dx, const std::string &dy,
                    const std::string &dz, const std::string &ltx)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Wedge(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy
          << ", " << dz << ", " << ltx << "};";
  addInFile(sstream.str(), fileName);
}

void scriptTranslate(const std::string &fileName,
                     const std::vector<std::pair<int, int> > &l,
                     const std::string &tx, const std::string &ty,
                     const std::string &tz, bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Translate {" << tx << ", " << ty << ", " << tz << "} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptRotate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &ax, const std::string &ay,
                  const std::string &az, const std::string &px,
                  const std::string &py, const std::string &pz,
                  const std::string &angle, bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Rotate {{" << ax << ", " << ay << ", " << az << "}, {" << px
          << ", " << py << ", " << pz << "}, " << angle << "} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptDilate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &cx, const std::string &cy,
                  const std::string &cz, const std::string &sx,
                  const std::string &sy, const std::string &sz, bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Dilate {{" << cx << ", " << cy << ", " << cz << "}, {" << sx
          << ", " << sy << ", " << sz << "}} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptMirror(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &sa, const std::string &sb,
                  const std::string &sc, const std::string &sd, bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Symmetry {" << sa << ", " << sb << ", " << sc << ", " << sd
          << "} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptExtrude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &tx, const std::string &ty,
                   const std::string &tz, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh)
{
  std::ostringstream sstream;
  sstream << "Extrude {" << tx << ", " << ty << ", " << tz << "} {\n  "
          << dimTags2String(l);
  if(extrudeMesh) {
    sstream << "Layers{" << layers << "}; ";
    if(recombineMesh) sstream << "Recombine;";
  }
  sstream << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptProtude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &ax, const std::string &ay,
                   const std::string &az, const std::string &px,
                   const std::string &py, const std::string &pz,
                   const std::string &angle, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh)
{
  std::ostringstream sstream;
  sstream << "Extrude {{" << ax << ", " << ay << ", " << az << "}, {" << px
          << ", " << py << ", " << pz << "}, " << angle << "} {\n  "
          << dimTags2String(l);
  if(extrudeMesh) {
    sstream << "Layers{" << layers << "}; ";
    if(recombineMesh) sstream << "Recombine;";
  }
  sstream << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptAddPipe(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::vector<int> &l2)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  int wire = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    wire =
      std::max(wire, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  sstream << "Wire(" << wire << ") = {" << vector2String(l2) << "};\n";
  sstream << "Extrude { " << dimTags2String(l) << "} Using Wire {" << wire
          << "}\n";
  addInFile(sstream.str(), fileName);
}

void scriptSplitCurve(int edge_id, List_T *vertices,
                      const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Split Curve(" << edge_id << ") {" << list2String(vertices)
          << "};";
  addInFile(sstream.str(), fileName);
}

void scriptBoolean(const std::string &fileName, const std::string &op,
                   const std::vector<std::pair<int, int> > &object,
                   const std::vector<std::pair<int, int> > &tool,
                   int deleteObject, int deleteTool)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << op << "{ " << dimTags2String(object);
  if(deleteObject) sstream << "Delete; ";
  sstream << "}{ " << dimTags2String(tool);
  if(deleteTool) sstream << "Delete; ";
  sstream << "}";
  addInFile(sstream.str(), fileName);
}

void scriptFillet(const std::string &fileName, const std::vector<int> &regions,
                  const std::vector<int> &edges, const std::string &radius)
{
  std::ostringstream sstream;
  checkOCC(sstream);
  sstream << "Fillet{" << vector2String(regions) << "}{" << vector2String(edges)
          << "}{" << radius << "}";
  addInFile(sstream.str(), fileName);
}

void scriptCoherence(const std::string &fileName)
{
  addInFile("Coherence;", fileName);
}

void scriptDeleteEntities(const std::string &fileName,
                          const std::vector<std::pair<int, int> > &l,
                          bool recursive)
{
  std::ostringstream sstream;
  if(recursive) sstream << "Recursive ";
  sstream << "Delete {\n  " << dimTags2String(l) << "\n}";
  addInFile(sstream.str(), fileName);
}

void scriptSetVisibilityAll(int mode, const std::string &fileName)
{
  if(mode)
    addInFile("Show \"*\";", fileName);
  else
    addInFile("Hide \"*\";", fileName);
}

void scriptSetVisibility(int mode, const std::vector<std::pair<int, int> > &l,
                         const std::string &fileName)
{
  std::ostringstream sstream;
  if(mode)
    sstream << "Show {\n  " << dimTags2String(l) << "\n}";
  else
    sstream << "Hide {\n  " << dimTags2String(l) << "\n}";
  addInFile(sstream.str(), fileName);
}
