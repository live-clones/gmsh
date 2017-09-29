// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
#include "GeoStringInterface.h"
#include "OpenFile.h"
#include "Context.h"
#include "OS.h"
#include "Parser.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

void add_infile(const std::string &text, const std::string &fileNameOrEmpty)
{
  std::string fileName = fileNameOrEmpty;
  if(fileName.empty()){
    std::string base = (getenv("PWD") ? "" : CTX::instance()->homeDir);
    GModel::current()->setFileName(base + CTX::instance()->defaultFileName);
    GModel::current()->setName("");
  }

  Msg::Debug("Adding `%s' to file `%s'", text.c_str(), fileName.c_str());
  std::vector<std::string> split = SplitFileName(fileName);
  std::string noExt = split[0] + split[1], ext = split[2];
#if defined(HAVE_COMPRESSED_IO) && defined(HAVE_LIBZ)
  bool compressed = false;
  if(ext == ".gz"){
    ext = SplitFileName(noExt)[2];
    compressed = true;
  }
#endif
  // make sure we don't add stuff in a non-geo file
  static bool proceed = false;
  if(!CTX::instance()->expertMode && !proceed) {
    if(ext.size() && ext != ".geo" && ext != ".GEO" ){
      std::ostringstream sstream;
      sstream <<
        "A scripting command is going to be appended to a non-`.geo' file. Are\n"
        "you sure you want to proceed?\n\n"
        "You probably want to create a new `.geo' file containing the command\n"
        "`Merge \"" << split[1] + split[2] << "\";' and use that file instead.\n\n"
        "(To disable this warning in the future, select `Enable expert mode'\n"
        "in the option dialog.)";
      int ret = Msg::GetAnswer(sstream.str().c_str(), 2, "Cancel", "Proceed as is",
                               "Create new `.geo' file");
      if(ret == 2){
        std::string newFileName = split[0] + split[1] + ".geo";
        if(CTX::instance()->confirmOverwrite) {
          if(!StatFile(newFileName)){
            std::ostringstream sstream;
            sstream << "File '" << newFileName << "' already exists.\n\n"
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
        fprintf(fp, "Merge \"%s\";\n%s\n", (split[1] + split[2]).c_str(), text.c_str());
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
  std::string tmpFileName = CTX::instance()->homeDir + CTX::instance()->tmpFileName;
  gmshFILE gmsh_yyin_old = gmsh_yyin;
  FILE *tmp_file;
  if(!(tmp_file = Fopen(tmpFileName.c_str(), "w"))) {
    Msg::Error("Unable to open temporary file '%s'", tmpFileName.c_str());
    return;
  }
  fprintf(tmp_file, "%s\n", text.c_str());
  fclose(tmp_file);
  gmsh_yyin = gmshopen(tmpFileName.c_str(), "r");
  while(!gmsheof(gmsh_yyin)) {
    gmsh_yyparse();
  }
  gmshclose(gmsh_yyin);
  gmsh_yyin = gmsh_yyin_old;

  GModel::current()->getGEOInternals()->synchronize(GModel::current());
  if(GModel::current()->getOCCInternals())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  GModel::current()->setName(split[1]);
  CTX::instance()->mesh.changed = ENT_ALL;

  // here we have to be explicit otherwise we append compressed stuff to ascii
  // file!
#if defined(HAVE_COMPRESSED_IO) && defined(HAVE_LIBZ)
  if(compressed){
    gmshFILE fp = gmshopen(fileName.c_str(), "a");
    if(!fp) {
      Msg::Error("Unable to open file '%s'", fileName.c_str());
      return;
    }
    gmshprintf(fp, "//+\n%s\n", text.c_str());
    gmshclose(fp);
  }
  else{
    FILE *fp = Fopen(fileName.c_str(), "a");
    if(!fp) {
      Msg::Error("Unable to open file '%s'", fileName.c_str());
      return;
    }
    fprintf(fp, "//+\n%s\n", text.c_str());
    fclose(fp);
  }
#else
  FILE *fp = Fopen(fileName.c_str(), "a");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return;
  }
  fprintf(fp, "//+\n%s\n", text.c_str());
  fclose(fp);
#endif

#else
  Msg::Error("GEO file creation not available without Gmsh parser");
#endif

  // mark Gmsh data as changed in onelab
  if(text.find("Physical") != std::string::npos){
    // re-import the physical groups in onelab, and only ask to re-save the mesh
    Msg::ImportPhysicalGroupsInOnelab();
    Msg::SetOnelabChanged(1);
  }
  else if(text.find("Characteristic") != std::string::npos){
    // only ask to remesh and re-save
    Msg::SetOnelabChanged(2);
  }
  else{
    // ask to reload the geometry, remesh and re-save
    Msg::SetOnelabChanged(3);
  }
}

static std::string list2String(List_T *list)
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

static std::string vector2String(const std::vector<int> &v)
{
  std::ostringstream sstream;
  for(unsigned int i = 0; i < v.size(); i++){
    if(i) sstream << ", ";
    sstream << v[i];
  }
  return sstream.str();
}

static std::string dimTags2String(const std::vector<std::pair<int, int> > &l)
{
  std::ostringstream sstream;
  for(unsigned int i = 0; i < l.size(); i++){
    switch(l[i].first){
    case 0: sstream << "Point{" << l[i].second << "}; "; break;
    case 1: sstream << "Line{" << l[i].second << "}; "; break;
    case 2: sstream << "Surface{" << l[i].second << "}; "; break;
    case 3: sstream << "Volume{" << l[i].second << "}; "; break;
    }
  }
  return sstream.str();
}

static void check_occ(std::ostringstream &sstream)
{
#if defined(HAVE_PARSER)
  if(gmsh_yyfactory != "OpenCASCADE") sstream << "SetFactory(\"OpenCASCADE\");\n";
#endif
}

void add_charlength(const std::string &fileName, const std::vector<int> &l,
                    const std::string &lc)
{
  std::ostringstream sstream;
  sstream << "Characteristic Length {" << vector2String(l) << "} = " << lc << ";";
  add_infile(sstream.str(), fileName);
}

void add_recosurf(const std::string &fileName, const std::vector<int> &l)
{
  std::ostringstream sstream;
  sstream << "Recombine Surface {" << vector2String(l) << "};";
  add_infile(sstream.str(), fileName);
}

void add_trsfline(std::vector<int> &l, const std::string &fileName,
                  const std::string &type, const std::string &typearg,
                  const std::string &pts)
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
  add_infile(sstream.str(), fileName);
}

void add_trsfsurf(std::vector<int> &l, const std::string &fileName,
                  const std::string &dir)
{
  std::ostringstream sstream;
  sstream << "Transfinite Surface {" << l[0] << "}";
  if(l.size() > 1){
    sstream << " = {";
    for(unsigned int i = 1; i < l.size(); i++) {
      if(i > 1) sstream << ", ";
      sstream << l[i];
    }
    sstream << "}";
  }
  if(dir != "Left")
    sstream << " " << dir;
  sstream << ";";
  add_infile(sstream.str(), fileName);
}

void add_trsfvol(std::vector<int> &l, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Transfinite Volume{" << l[0] << "} = {";
  for(unsigned int i = 1; i < l.size(); i++) {
    if(i > 1) sstream << ", ";
    sstream << l[i];
  }
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_embedded(const std::string &fileName, const std::string &what,
                  std::vector<int> &l, int dim, int tag)
{
  std::ostringstream sstream;
  sstream << what << "{" << vector2String(l) << "} In ";
  if(dim == 2) sstream << "Surface{";
  else sstream << "Volume{";
  sstream << tag << "};";
  add_infile(sstream.str(), fileName);
}

void add_param(const std::string &par, const std::string &value,
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
  add_infile(sstream.str(), fileName);
}

void add_point(const std::string &fileName, const std::string &x, const std::string &y,
               const std::string &z, const std::string &lc)
{
  std::ostringstream sstream;
  sstream << "Point(" << GModel::current()->getMaxElementaryNumber(0) + 1
          << ") = {" << x << ", " << y << ", " << z;
  if(lc.size()) sstream << ", " << lc;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_field_option(int field_id, const std::string &option_name,
                      const std::string &option_value, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "]." << option_name << " = "
          << option_value << ";";
  add_infile(sstream.str(), fileName);
}

void add_field(int field_id, const std::string &type_name, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "] = " << type_name << ";";
  add_infile(sstream.str(), fileName);
}

void delete_field(int field_id, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Delete Field [" << field_id << "];";
  add_infile(sstream.str(), fileName);
}

void set_background_field(int field_id, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Background Field = " << field_id << ";";
  add_infile(sstream.str(), fileName);
}

void add_multline(const std::string &type, std::vector<int> &p,
                  const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << type << "(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {";
  for(unsigned int i = 0; i < p.size(); i++) {
    if(i) sstream << ", ";
    sstream << p[i];
  }
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_circle_arc(int p1, int p2, int p3, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Circle(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << p1 << ", " << p2 << ", " << p3 << "};";
  add_infile(sstream.str(), fileName);
}

void add_ellipse_arc(int p1, int p2, int p3, int p4, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Ellipse(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << p1 << ", " << p2 << ", "
          << p3 << ", " << p4 << "};";
  add_infile(sstream.str(), fileName);
}

void add_lineloop(List_T *list, const std::string &fileName, int *numloop)
{
  if(RecognizeLineLoop(list, numloop)) return;
  *numloop = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    *numloop = std::max
      (*numloop, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  std::ostringstream sstream;
  sstream << "Line Loop(" << *numloop << ") = {" << list2String(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_surf(const std::string &type, List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << type << "(" << GModel::current()->getMaxElementaryNumber(2) + 1
          << ") = {" << list2String(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_surfloop(List_T *list, const std::string &fileName, int *numloop)
{
  if(RecognizeSurfaceLoop(list, numloop)) return;
  *numloop = GModel::current()->getGEOInternals()->getMaxTag(-2) + 1;
  if(GModel::current()->getOCCInternals())
    *numloop = std::max
      (*numloop, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  std::ostringstream sstream;
  sstream << "Surface Loop(" << *numloop << ") = {" << list2String(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_vol(List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Volume(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << list2String(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_remove_physical(const std::string &fileName, const std::string &what,
                         const std::vector<int> &l, const std::string &name,
                         int forceTag, bool append, const std::string &mode)
{
  std::ostringstream sstream;
  sstream << "Physical " << what << "(";
  if(name.size()){
    sstream << "\"" << name << "\"";
    if(forceTag)
      sstream << ", " << forceTag;
  }
  else{
    sstream << (forceTag ? forceTag :
                GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1);
  }
  sstream << ") ";
  if(mode == "Remove")
    sstream << "-";
  else if(append)
    sstream << "+";
  sstream << "= {" << vector2String(l) << "};";
  add_infile(sstream.str(), fileName);
}

void add_compound(const std::string &fileName, const std::string &type,
                  const std::vector<int> &l)
{
  std::ostringstream sstream;
  if(SplitFileName(fileName)[2] != ".geo") sstream << "CreateTopology;\n";
  if (type == "Surface"){
    sstream << "Compound " << type << "("
            << GModel::current()->getMaxElementaryNumber(2) + 1 << ") = {"
	    << vector2String(l) << "};";
  }
  else if (type == "Line"){
    sstream << "Compound " << type << "("
            << GModel::current()->getMaxElementaryNumber(1) + 1 << ") = {"
	    << vector2String(l) << "};";
  }
  else{
    sstream << "Compound " << type << "("
            << GModel::current()->getMaxElementaryNumber(3) + 1 << ") = {"
	    << vector2String(l) << "};";
  }
  add_infile(sstream.str(), fileName);
}

void add_circle(const std::string &fileName, const std::string &x, const std::string &y,
                const std::string &z, const std::string &r, const std::string &alpha1,
                const std::string &alpha2)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Circle(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << r;
  if(alpha1.size())
    sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size())
    sstream << ", " << alpha2;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_ellipse(const std::string &fileName, const std::string &x, const std::string &y,
                 const std::string &z, const std::string &rx, const std::string &ry,
                 const std::string &alpha1, const std::string &alpha2)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Ellipse(" << GModel::current()->getMaxElementaryNumber(1) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << rx << ", " << ry;
  if(alpha1.size())
    sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size())
    sstream << ", " << alpha2;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_disk(const std::string &fileName, const std::string &x, const std::string &y,
                const std::string &z, const std::string &rx, const std::string &ry)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Disk(" << GModel::current()->getMaxElementaryNumber(2) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << rx << ", " << ry << "};";
  add_infile(sstream.str(), fileName);
}

void add_rectangle(const std::string &fileName, const std::string &x, const std::string &y,
                   const std::string &z, const std::string &dx, const std::string &dy,
                   const std::string &roundedRadius)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Rectangle(" << GModel::current()->getMaxElementaryNumber(2) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy;
  if(roundedRadius.size())
    sstream << ", " << roundedRadius;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_sphere(const std::string &fileName, const std::string &x, const std::string &y,
                const std::string &z, const std::string &r, const std::string &alpha1,
                const std::string &alpha2, const std::string &alpha3)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Sphere(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << r;
  if(alpha1.size())
    sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size())
    sstream << ", " << alpha2;
  if(alpha1.size() && alpha2.size() && alpha3.size())
    sstream << ", " << alpha3;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_cylinder(const std::string &fileName, const std::string &x, const std::string &y,
                  const std::string &z, const std::string &dx, const std::string &dy,
                  const std::string &dz, const std::string &r, const std::string &alpha)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Cylinder(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy
          << ", " << dz << ", " << r;
  if(alpha.size())
    sstream << ", " << alpha;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_box(const std::string &fileName, const std::string &x, const std::string &y,
             const std::string &z, const std::string &dx, const std::string &dy,
             const std::string &dz)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Box(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", "
          << dy << ", " << dz << "};";
  add_infile(sstream.str(), fileName);
}

void add_torus(const std::string &fileName, const std::string &x, const std::string &y,
               const std::string &z, const std::string &r1, const std::string &r2,
               const std::string &alpha)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Torus(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << r1 << ", " << r2;
  if(alpha.size())
    sstream << ", " << alpha;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_cone(const std::string &fileName, const std::string &x, const std::string &y,
              const std::string &z, const std::string &dx, const std::string &dy,
              const std::string &dz, const std::string &r1, const std::string &r2,
              const std::string &alpha)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Cone(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", "
          << dy << ", " << dz << ", " << r1 << ", " << r2;
  if(alpha.size())
    sstream << ", " << alpha;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_wedge(const std::string &fileName, const std::string &x, const std::string &y,
               const std::string &z, const std::string &dx, const std::string &dy,
               const std::string &dz, const std::string &ltx)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Wedge(" << GModel::current()->getMaxElementaryNumber(3) + 1
          << ") = {" << x << ", " << y << ", " << z << ", " << dx << ", " << dy
          << ", " << dz << ", " << ltx << "};";
  add_infile(sstream.str(), fileName);
}

void translate(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
               const std::string &tx, const std::string &ty, const std::string &tz,
               bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Translate {" << tx << ", " << ty << ", " << tz << "} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void rotate(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
            const std::string &ax, const std::string &ay, const std::string &az,
            const std::string &px, const std::string &py, const std::string &pz,
            const std::string &angle, bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Rotate {{" << ax << ", " << ay << ", " << az << "}, {"
          << px << ", " << py << ", " << pz << "}, " << angle << "} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void dilate(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
            const std::string &cx, const std::string &cy, const std::string &cz,
            const std::string &sx, const std::string &sy, const std::string &sz,
            bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Dilate {{" << cx << ", " << cy << ", " << cz << "}, {"
          << sx << ", " << sy << ", " << sz << "}} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void symmetry(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
              const std::string &sa, const std::string &sb, const std::string &sc,
              const std::string &sd, bool duplicata)
{
  std::ostringstream sstream;
  sstream << "Symmetry {" << sa << ", " << sb << ", " << sc << ", " << sd << "} {\n  ";
  if(duplicata) sstream << "Duplicata { ";
  sstream << dimTags2String(l);
  if(duplicata) sstream << "}";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void extrude(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
             const std::string &tx, const std::string &ty, const std::string &tz,
             bool extrudeMesh, const std::string &layers, bool recombineMesh)
{
  std::ostringstream sstream;
  sstream << "Extrude {" << tx << ", " << ty << ", " << tz << "} {\n  "
          << dimTags2String(l);
  if(extrudeMesh){
    sstream << "Layers{" << layers << "}; ";
    if(recombineMesh) sstream << "Recombine;";
  }
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void protude(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
             const std::string &ax, const std::string &ay, const std::string &az,
             const std::string &px, const std::string &py, const std::string &pz,
             const std::string &angle, bool extrudeMesh, const std::string &layers,
             bool recombineMesh)
{
  std::ostringstream sstream;
  sstream << "Extrude {{" << ax << ", " << ay << ", " << az << "}, {"
          << px << ", " << py << ", " << pz << "}, " << angle << "} {\n  "
          << dimTags2String(l);
  if(extrudeMesh){
    sstream << "Layers{" << layers << "}; ";
    if(recombineMesh) sstream << "Recombine;";
  }
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void add_pipe(const std::string &fileName, const std::vector<std::pair<int, int> > &l,
              const std::vector<int> &l2)
{
  std::ostringstream sstream;
  check_occ(sstream);
  int wire = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    wire = std::max(wire, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  sstream << "Wire(" << wire << ") = {" << vector2String(l2) << "};\n";
  sstream << "Extrude { " << dimTags2String(l) << "} Using Wire {" << wire << "}\n";
  add_infile(sstream.str(), fileName);
}

void split_edge(int edge_id, List_T *vertices, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Split Line(" << edge_id << ") {" << list2String(vertices) << "};";
  add_infile(sstream.str(), fileName);
}

void apply_boolean(const std::string &fileName, const std::string &op,
                   const std::vector<std::pair<int, int> > &object,
                   const std::vector<std::pair<int, int> > &tool,
                   int deleteObject, int deleteTool)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << op << "{ " << dimTags2String(object);
  if(deleteObject) sstream << "Delete; ";
  sstream << "}{ " << dimTags2String(tool);
  if(deleteTool) sstream << "Delete; ";
  sstream << "}";
  add_infile(sstream.str(), fileName);
}

void apply_fillet(const std::string &fileName, const std::vector<int> &regions,
                  const std::vector<int> &edges, const std::string &radius)
{
  std::ostringstream sstream;
  check_occ(sstream);
  sstream << "Fillet{" << vector2String(regions) << "}{"
          << vector2String(edges) << "}{" << radius << "}";
  add_infile(sstream.str(), fileName);
}

void coherence(const std::string &fileName)
{
  add_infile("Coherence;", fileName);
}

void delete_entities(const std::string &fileName,
                     const std::vector<std::pair<int, int> > &l, bool recursive)
{
  std::ostringstream sstream;
  if(recursive) sstream << "Recursive ";
  sstream << "Delete {\n  " << dimTags2String(l) << "\n}";
  add_infile(sstream.str(), fileName);
}
