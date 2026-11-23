// The programs written next to a script for General.ScriptingLanguages, as
// the graphical user interface builds it (see scriptStringInterface.h): a
// model is built with the commands of each kernel, and the C and C++
// programs are compiled (syntax only) with the compilers of the build, given
// at compile time as TEST_CC and TEST_CXX, against the API headers of
// TEST_API_DIR. Usage: script_programs [directory] (default:
// script_programs_test, made in the current directory); returns 77 (skipped) if
// a compiler does not run.

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include "gmsh.h"
#include "ListUtils.h"
#include "Field.h"
#include "OS.h"
#include "scriptStringInterface.h"

#if !defined(TEST_CC) || !defined(TEST_CXX) || !defined(TEST_API_DIR)
#error "TEST_CC, TEST_CXX and TEST_API_DIR must be defined"
#endif

static int fails = 0;

static void check(bool ok, const std::string &what)
{
  printf("%s %s\n", ok ? "ok  " : "FAIL", what.c_str());
  if(!ok) fails++;
}

static bool exists(const std::string &f)
{
  std::ifstream in(f.c_str());
  return in.good();
}

// a new empty script, opened
static std::string newScript(const std::string &dir, const std::string &name)
{
  std::string f = dir + "/" + name + ".geo";
  scriptRemovePrograms(f);
  FILE *fp = fopen(f.c_str(), "w");
  if(fp) fclose(fp);
  gmsh::clear();
  gmsh::open(f);
  return f;
}

static void builtIn(const std::string &f)
{
  scriptAddPoint(f, "0", "0", "0", "0.1");
  scriptAddPoint(f, "1", "0", "0", "0.1");
  scriptAddPoint(f, "1", "1", "0", "0.1");
  scriptAddPoint(f, "0", "1", "0", "0.1");
  for(int i = 1; i <= 4; i++) {
    std::vector<int> p = {i, i % 4 + 1};
    scriptAddCurve("Line", p, f);
  }
  List_T *curves = List_Create(4, 1, sizeof(int));
  for(int i = 1; i <= 4; i++) List_Add(curves, &i);
  int loop = 0;
  scriptFindLoop(1, curves, &loop);
  scriptAddLoop(1, curves, loop, f);
  List_Delete(curves);
  List_T *loops = List_Create(1, 1, sizeof(int));
  List_Add(loops, &loop);
  scriptAddSurface("Plane Surface", loops, f);
  List_Delete(loops);
  std::vector<int> lines = {1, 2, 3, 4}, surfaces = {1};
  scriptSetTransfiniteLine(lines, f, "Progression", "1", "10");
  scriptSetTransfiniteSurface(surfaces, f, "Left");
  scriptRecombineSurface(f, surfaces);
  scriptSetMeshSize(f, {1, 2}, "0.05");
  scriptAddRemovePhysicalGroup(f, "Surface", surfaces, "plate $1", 0, false,
                               "Add");
  scriptSetColor(0xff0000ff, {{2, 1}}, f);
  scriptTranslate(f, {{0, 1}}, "0", "0", "0.5", true);
  scriptRotate(f, {{1, 1}}, "0", "0", "1", "0", "0", "0", "Pi/4", true);
  scriptExtrude(f, {{2, 1}}, "0", "0", "1", true, "5", true);
  scriptAddField(1, "Distance", f);
  scriptAddFieldOption(1, "CurvesList", "{1}", FIELD_OPTION_LIST, f);
  scriptSetBackgroundField(1, f);
  scriptSetVisibility(0, {{1, 2}}, f);
}

// the largest tag of the entities of dimension dim
static int lastTag(int dim)
{
  std::vector<std::pair<int, int>> e;
  gmsh::model::getEntities(e, dim);
  int t = 0;
  for(auto &p : e) t = std::max(t, p.second);
  return t;
}

static void openCASCADE(const std::string &f)
{
  scriptSetFactory("OpenCASCADE", f);
  scriptAddBox(f, "0", "0", "0", "1", "1", "1");
  scriptAddSphere(f, "1", "1", "1", "0.5", "", "", "");
  scriptBoolean(f, "BooleanDifference", {{3, 1}}, {{3, 2}}, 1, 1);
  scriptAddBox(f, "2", "0", "0", "1", "1", "1");
  int box = lastTag(3);
  // (a curve of a face of the box)
  std::vector<std::pair<int, int>> faces, curves;
  gmsh::model::getBoundary({{3, box}}, faces, false, false, false);
  gmsh::model::getBoundary({faces[0]}, curves, false, false, false);
  std::vector<int> edges = {std::abs(curves[0].second)};
  scriptFillet(f, {box}, edges, "0.1");
  scriptAddCylinder(f, "4", "0", "0", "0", "0", "1", "0.3", "");
  int cylinder = lastTag(3);
  scriptMirror(f, {{3, cylinder}}, "1", "0", "0", "0", true);
  scriptDilate(f, {{3, cylinder}}, "0", "0", "0", "2", "2", "2", false);
  scriptAddRectangle(f, "0", "3", "0", "1", "1", "0.1");
  scriptAddDisk(f, "3", "3", "0", "0.5", "0.3");
  int disk = lastTag(2);
  scriptAddRemovePhysicalGroup(f, "Volume", {cylinder}, "", 10, false, "Add");
  scriptSetColor(0x00ff00ff, {{3, cylinder}}, f);
  scriptDeleteEntities(f, {{2, disk}}, true);
}

static void discrete(const std::string &f)
{
  scriptSetFactory("Discrete", f);
  scriptAddBox(f, "0", "0", "0", "1", "1", "1");
  scriptAddSphere(f, "1", "1", "1", "0.5", "", "", "");
  scriptAddCylinder(f, "3", "0", "0", "0", "0", "1", "0.3", "");
  scriptAddCone(f, "5", "0", "0", "0", "0", "1", "0.3", "0.1", "");
  scriptAddTorus(f, "7", "0", "0", "0.5", "0.1", "");
  scriptBoolean(f, "BooleanDifference", {{3, 1}}, {{3, 2}}, 1, 1);
  scriptDeleteEntities(f, {{3, 3}}, true);
  scriptAddRectangle(f, "0", "3", "0", "1", "1", "");
  scriptAddDisk(f, "3", "3", "0", "0.5", "0.5");
}

// the command compiles the program, the compiler running
static bool compiles(const std::string &command, const std::string &program)
{
  std::string c = command + " -fsyntax-only -I\"" + TEST_API_DIR + "\" \"" +
                  program + "\" > /dev/null 2>&1";
  return system(c.c_str()) == 0;
}

int main(int argc, char **argv)
{
  std::string dir = "script_programs_test";
  for(int i = 1; i < argc; i++)
    if(argv[i][0] != '-') dir = argv[i];
  CreateSingleDir(dir);

  // the compilers of the build run (a C and a C++ program that do nothing)
  std::string c = dir + "/nothing.c";
  {
    std::ofstream out(c.c_str());
    out << "int main(void) { return 0; }\n";
  }
  if(system(
       (std::string(TEST_CC) + " -fsyntax-only \"" + c + "\" > /dev/null 2>&1")
         .c_str()) ||
     system((std::string(TEST_CXX) + " -x c++ -fsyntax-only \"" + c +
             "\" > /dev/null 2>&1")
              .c_str())) {
    printf("The compilers %s and %s do not run: skipped\n", TEST_CC, TEST_CXX);
    return 77;
  }

  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::option::setString("General.ScriptingLanguages", "geo,py,jl,c,cpp");

  struct test {
    std::string name;
    void (*build)(const std::string &);
  };
  const test tests[] = {
    {"built_in", builtIn}, {"occ", openCASCADE}, {"discrete", discrete}};
  for(const test &t : tests) {
    std::string f = newScript(dir, t.name);
    t.build(f);
    for(const char *lang : {"py", "jl", "c", "cpp"})
      check(exists(scriptProgram(f, lang)),
            t.name + ": the " + lang + " program is written");
    check(compiles(TEST_CC, scriptProgram(f, "c")),
          t.name + ": the C program compiles");
    check(compiles(TEST_CXX, scriptProgram(f, "cpp")),
          t.name + ": the C++ program compiles");
  }

  // ("$" interpolates in Julia strings)
  std::ifstream jl(scriptProgram(dir + "/built_in.geo", "jl").c_str());
  std::string text((std::istreambuf_iterator<char>(jl)),
                   std::istreambuf_iterator<char>());
  check(text.find("\"plate \\$1\"") != std::string::npos,
        "built_in: the $ of a name is escaped in the Julia program");

  gmsh::finalize();
  printf("%d failure(s)\n", fails);
  return fails ? 1 : 0;
}
