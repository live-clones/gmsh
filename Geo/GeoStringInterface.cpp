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

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

void add_infile(const std::string &text, const std::string &fileName)
{
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

void add_charlength(List_T *list, const std::string &fileName, const std::string &lc)
{
  std::ostringstream sstream;
  sstream << "Characteristic Length {" << list2string(list) << "} = " << lc << ";";
  add_infile(sstream.str(), fileName);
}

void add_recosurf(List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Recombine Surface {" << list2string(list) << "};";
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

void add_embedded(const std::string &what, std::vector<int> &l,
                  const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Point{";
  for(unsigned int i = 1; i < l.size(); i++) {
    if(i > 1) sstream << ", ";
    sstream << l[i];
  }
  sstream << "} In Surface{" << l[0] << "};";
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
  sstream << "Point(" << NEWPOINT() << ") = {" << x << ", " << y << ", "
          << z ;
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
  sstream << type << "(" << NEWLINE() << ") = {";
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
  sstream << "Circle(" << NEWLINE() << ") = {" << p1 << ", " << p2 << ", "
          << p3 << "};";
  add_infile(sstream.str(), fileName);
}

void add_ellipse_arc(int p1, int p2, int p3, int p4, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Ellipse(" << NEWLINE() << ") = {" << p1 << ", " << p2 << ", "
          << p3 << ", " << p4 << "};";
  add_infile(sstream.str(), fileName);
}

void add_lineloop(List_T *list, const std::string &fileName, int *numloop)
{
  if(RecognizeLineLoop(list, numloop)) return;
  *numloop = NEWLINELOOP();
  std::ostringstream sstream;
  sstream << "Line Loop(" << *numloop << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_surf(const std::string &type, List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << type << "(" << NEWSURFACE() << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_surfloop(List_T *list, const std::string &fileName, int *numloop)
{
  if(RecognizeSurfaceLoop(list, numloop)) return;
  *numloop = NEWSURFACELOOP();
  std::ostringstream sstream;
  sstream << "Surface Loop(" << *numloop << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_vol(List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Volume(" << NEWVOLUME() << ") = {" << list2string(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_physical(const std::string &type, List_T *list, const std::string &fileName,
                  const std::string &name, int forceTag, bool append,
                  const std::string &mode)
{
  std::ostringstream sstream;
  sstream << "Physical " << type << "(";
  if(name.size()){
    sstream << "\"" << name << "\"";
    if(forceTag)
      sstream << ", " << forceTag;
  }
  else{
    sstream << (forceTag ? forceTag : NEWPHYSICAL());
  }
  sstream << ") ";
  if(mode == "Remove")
    sstream << "-";
  else if(append)
    sstream << "+";
  sstream << "= {" << list2string(list) << "};";
  add_infile(sstream.str(), fileName);
}

void add_compound(const std::string &type, List_T *list, const std::string &fileName)
{
  std::ostringstream sstream;
  if(SplitFileName(fileName)[2] != ".geo") sstream << "CreateTopology;\n";
  if (type == "Surface"){
    sstream << "Compound " << type << "(" << NEWSURFACE() << ") = {"
	    << list2string(list) << "};";
  }
  else if (type == "Line"){
    sstream << "Compound " << type << "(" << NEWLINE() << ") = {"
	    << list2string(list) << "};";
  }
  else{
    sstream << "Compound " << type << "(" << NEWREG() << ") = {"
	    << list2string(list) << "};";
  }
  add_infile(sstream.str(), fileName);
}

void add_circle(const std::string &fileName, const std::string &x, const std::string &y,
                const std::string &z, const std::string &r, const std::string &alpha1,
                const std::string &alpha2)
{
  std::ostringstream sstream;
  sstream << "Circle(" << NEWLINE() << ") = {" << x << ", " << y << ", " << z
          << ", " << r;
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
  sstream << "Ellipse(" << NEWLINE() << ") = {" << x << ", " << y << ", " << z
          << ", " << rx << ", " << ry;
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
  sstream << "Disk(" << NEWSURFACE() << ") = {" << x << ", " << y << ", " << z
          << ", " << rx << ", " << ry << "};";
  add_infile(sstream.str(), fileName);
}

void add_rectangle(const std::string &fileName, const std::string &x, const std::string &y,
                   const std::string &z, const std::string &dx, const std::string &dy,
                   const std::string &roundedRadius)
{
  std::ostringstream sstream;
  sstream << "Rectangle(" << NEWSURFACE() << ") = {" << x << ", " << y << ", " << z
          << ", " << dx << ", " << dy;
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
  sstream << "Sphere(" << NEWVOLUME() << ") = {" << x << ", " << y << ", " << z
          << ", " << r;
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
  sstream << "Cylinder(" << NEWVOLUME() << ") = {" << x << ", " << y << ", " << z
          << ", " << dx << ", " << dy << ", " << dz << ", " << r;
  if(alpha.size())
    sstream << ", " << alpha;
  sstream << "};";
  add_infile(sstream.str(), fileName);
}

void add_block(const std::string &fileName, const std::string &x, const std::string &y,
               const std::string &z, const std::string &dx, const std::string &dy,
               const std::string &dz)
{
  std::ostringstream sstream;
  sstream << "Block(" << NEWVOLUME() << ") = {" << x << ", " << y << ", " << z
          << ", " << dx << ", " << dy << ", " << dz << "};";
  add_infile(sstream.str(), fileName);
}

void add_torus(const std::string &fileName, const std::string &x, const std::string &y,
               const std::string &z, const std::string &r1, const std::string &r2,
               const std::string &alpha)
{
  std::ostringstream sstream;
  sstream << "Torus(" << NEWVOLUME() << ") = {" << x << ", " << y << ", " << z
          << ", " << r1 << ", " << r2;
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
  sstream << "Cone(" << NEWVOLUME() << ") = {" << x << ", " << y << ", " << z
          << ", " << dx << ", " << dy << ", " << dz << ", " << r1 << ", " << r2;
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
  sstream << "Wedge(" << NEWVOLUME() << ") = {" << x << ", " << y << ", " << z
          << ", " << dx << ", " << dy << ", " << dz << ", " << ltx << "};";
  add_infile(sstream.str(), fileName);
}

void translate(int add, List_T *list, const std::string &fileName,
               const std::string &what, const std::string &tx,
               const std::string &ty, const std::string &tz)
{
  std::ostringstream sstream;
  sstream << "Translate {" << tx << ", " << ty << ", " << tz << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void rotate(int add, List_T *list, const std::string &fileName,
            const std::string &what, const std::string &ax, const std::string &ay,
            const std::string &az, const std::string &px, const std::string &py,
            const std::string &pz, const std::string &angle)
{
  std::ostringstream sstream;
  sstream << "Rotate {{" << ax << ", " << ay << ", " << az << "}, {"
          << px << ", " << py << ", " << pz << "}, " << angle << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void dilate(int add, List_T *list, const std::string &fileName,
            const std::string &what, const std::string &dx, const std::string &dy,
            const std::string &dz, const std::string &df)
{
  std::ostringstream sstream;
  sstream << "Dilate {{" << dx << ", " << dy << ", " << dz << "}, " << df << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void symmetry(int add, List_T *list, const std::string &fileName,
              const std::string &what, const std::string &sa, const std::string &sb,
              const std::string &sc, const std::string &sd)
{
  std::ostringstream sstream;
  sstream << "Symmetry {" << sa << ", " << sb << ", " << sc << ", " << sd << "} {\n  ";
  if(add) sstream << "Duplicata { ";
  sstream << what << "{" << list2string(list) << "};";
  if(add) sstream << " }";
  sstream << "\n}";
  add_infile(sstream.str(), fileName);
}

void extrude(List_T *list, const std::string &fileName, const std::string &what,
             const std::string &tx, const std::string &ty, const std::string &tz)
{
  std::ostringstream sstream;
  sstream << "Extrude {" << tx << ", " << ty << ", " << tz << "} {\n  " << what
          << "{" << list2string(list) << "};\n}";
  add_infile(sstream.str(), fileName);
}

void protude(List_T *list, const std::string &fileName, const std::string &what,
             const std::string &ax, const std::string &ay, const std::string &az,
             const std::string &px, const std::string &py, const std::string &pz,
             const std::string &angle)
{
  std::ostringstream sstream;
  sstream << "Extrude {{" << ax << ", " << ay << ", " << az << "}, {"
          << px << ", " << py << ", " << pz << "}, " << angle << "} {\n  "
          << what << "{" << list2string(list) << "};\n}";
  add_infile(sstream.str(), fileName);
}

void split_edge(int edge_id, List_T *vertices, const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Split Line(" << edge_id << ") {" << list2string(vertices) << "};";
  add_infile(sstream.str(), fileName);
}

void apply_boolean(const std::string &fileName, const std::string &op,
                   const std::vector<GEntity*> &object,
                   const std::vector<GEntity*> &tool)
{
  std::ostringstream sstream;
  sstream << op << "{ ";
  for(unsigned int i = 0; i < object.size(); i++){
    switch(object[i]->dim()){
    case 3: sstream << "Volume{" << object[i]->tag() << "}; "; break;
    case 2: sstream << "Surface{" << object[i]->tag() << "}; "; break;
    case 1: sstream << "Line{" << object[i]->tag() << "}; "; break;
    }
  }
  sstream << "Delete; }{ ";
  for(unsigned int i = 0; i < tool.size(); i++){
    switch(tool[i]->dim()){
    case 3: sstream << "Volume{" << tool[i]->tag() << "}; "; break;
    case 2: sstream << "Surface{" << tool[i]->tag() << "}; "; break;
    case 1: sstream << "Line{" << tool[i]->tag() << "}; "; break;
    }
  }
  sstream << "Delete; }";
  add_infile(sstream.str(), fileName);
}

void coherence(const std::string &fileName)
{
  add_infile("Coherence;", fileName);
}

void delet(List_T *list, const std::string &fileName, const std::string &what)
{
  std::ostringstream sstream;
  sstream << "Delete {\n  " << what << "{" << list2string(list) << "};\n}";
  add_infile(sstream.str(), fileName);
}
