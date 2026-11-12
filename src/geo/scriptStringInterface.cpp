// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <map>
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
#include "Options.h"
#include "OS.h"
#include "Parser.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

static bool _lastCommandAdded = false;

bool scriptLastCommandAdded() { return _lastCommandAdded; }

// a command appended to the .geo script, once the model has read it without
// errors (see scriptLastCommandAdded())
static void scriptAddCommand(const std::string &text,
                             const std::string &fileNameOrEmpty)
{
  _lastCommandAdded = false;
  // the command changes the model: not during another operation on it, which
  // the GUI processes events of
  if(modelBusy()) return;

  std::string fileName = fileNameOrEmpty;
  if(fileName.empty()) {
    std::string base = (getenv("PWD") ? "" : CTX::instance()->homeDir);
    GModel::current()->setFileName(base + CTX::instance()->defaultFileName);
    GModel::current()->setName("");
    fileName = GModel::current()->getFileName();
  }

  Msg::Debug("Adding `%s' to file `%s'", text.c_str(), fileName.c_str());
  std::vector<std::string> split = SplitFileName(fileName);
  std::string noExt = split[0] + split[1], ext = split[2];
  // make sure we don't add stuff in a non-geo file
  static bool proceed = false;
  if(!CTX::instance()->expertMode && !proceed) {
    if(ext.size() && ext != ".geo" && ext != ".GEO" && ext != ".opt" &&
       ext != ".OPT" && ext != ".vis" && ext != ".VIS") {
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
        if(ext == ".stp" || ext == ".STP" || ext == ".step" || ext == ".STEP" ||
           ext == ".igs" || ext == ".IGS" || ext == ".iges" || ext == ".IGES" ||
           ext == ".brep" || ext == ".BREP") {
          fprintf(fp, "SetFactory(\"OpenCASCADE\");\n");
        }
        fprintf(fp, "Merge \"%s\";\n//+\n%s\n", (split[1] + split[2]).c_str(),
                text.c_str());
        fclose(fp);
        OpenProject(newFileName);
        _lastCommandAdded = true;
        return;
      }
      else if(ret == 1)
        proceed = true;
      else if(ret == 0)
        return;
    }
  }

#if defined(HAVE_PARSER)
  bool failed = false;
  {
    // the parsing and the synchronizations under the lock on the model, which
    // an operation started from the dialogs above may hold
    modelLock lock(modelLock::ifFree);
    if(!lock) return;
    int errors = Msg::GetErrorCount();
    std::string tmpFileName =
      CTX::instance()->homeDir + CTX::instance()->tmpFileName;
    FILE *tmp_file;
    if(!(tmp_file = Fopen(tmpFileName.c_str(), "w"))) {
      Msg::Error("Unable to open temporary file '%s'", tmpFileName.c_str());
      return;
    }
    fprintf(tmp_file, "%s\n", text.c_str());
    fclose(tmp_file);
    // the input of the parser given back however the parsing ends (an error
    // may throw)
    struct parserInput {
      FILE *previous = gmsh_yyin;
      ~parserInput()
      {
        if(gmsh_yyin && gmsh_yyin != previous) fclose(gmsh_yyin);
        gmsh_yyin = previous;
      }
    } input;
    gmsh_yyin = Fopen(tmpFileName.c_str(), "r");
    if(!gmsh_yyin) {
      Msg::Error("Unable to open temporary file '%s'", tmpFileName.c_str());
      return;
    }
    while(!feof(gmsh_yyin)) { gmsh_yyparse(); }

    GModel::current()->getGEOInternals()->synchronize(GModel::current());
    if(GModel::current()->getOCCInternals())
      GModel::current()->getOCCInternals()->synchronize(GModel::current());
    GModel::current()->setName(split[1]);
    CTX::instance()->meshChanged();
    failed = Msg::GetErrorCount() > errors;
  }

  // a command with errors is not added, which would make the script fail the
  // next time it is read, and the model is read again from the script, as it
  // was before the command
  if(failed) {
    // (reading the script resets the errors: the last is given again)
    std::string error = Msg::GetLastError();
    if(!StatFile(fileName)) OpenProject(fileName);
    Msg::Error("%s (not added to the script)", error.c_str());
    return;
  }

  FILE *fp = Fopen(fileName.c_str(), "a");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return;
  }
  fprintf(fp, "//+\n%s\n", text.c_str());
  fclose(fp);
  _lastCommandAdded = true;
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

// the last command taken out of the .geo script: false if there is none
static bool scriptRemoveLastGeoCommand(const std::string &fileName)
{
  // the project is read again: not during another operation on the model
  if(modelBusy()) return false;
  if(StatFile(fileName)) return false;
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
    return false;
  }
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(fp) {
    fprintf(fp, "%s", s.c_str());
    fclose(fp);
  }
  else {
    Msg::Error("Could not open file `%s'", fileName.c_str());
    return false;
  }
  OpenProject(fileName);
  return true;
}

// The commands in the .geo language, and in the languages of the API
// (General.ScriptingLanguages: py, jl, cpp, c, f90, js): the .geo script is
// always written, as the graphical interface works through it; each command
// accepted there is also written as the calls of the API it amounts to, in a
// runnable program next to the script for each language asked for
// (model.py, model.jl, model.cpp, model.c, model.f90, model.mjs), above the
// lines that close it. The calls have the tags of the .geo command and the
// values of the expressions typed in, as the parser evaluates them.

namespace {

  // an argument of a call of the API
  struct apiArg {
    enum Kind {
      Int,
      Num, // an expression, evaluated
      Str,
      Bool,
      Ints,
      Nums, // expressions
      DimTags,
      OutDimTags, // an output: a variable named by str
      OutDimTagsMap,
      OutInts,
      VarDimTags // the output of an earlier call, by its name
    };
    Kind kind = Int;
    int i = 0;
    std::string str;
    std::vector<int> ints;
    std::vector<std::string> exprs;
    std::vector<std::pair<int, int>> dimTags;
    // the default value, left out at the end of a call where the language
    // allows it
    bool def = false;
    bool output() const
    { return kind == OutDimTags || kind == OutDimTagsMap || kind == OutInts; }
  };

  apiArg aInt(int i, bool def = false)
  {
    apiArg a;
    a.kind = apiArg::Int;
    a.i = i;
    a.def = def;
    return a;
  }
  apiArg aNum(const std::string &expr, bool def = false)
  {
    apiArg a;
    a.kind = apiArg::Num;
    a.str = expr;
    a.def = def;
    return a;
  }
  apiArg aStr(const std::string &s, bool def = false)
  {
    apiArg a;
    a.kind = apiArg::Str;
    a.str = s;
    a.def = def;
    return a;
  }
  apiArg aBool(bool b, bool def = false)
  {
    apiArg a;
    a.kind = apiArg::Bool;
    a.i = b ? 1 : 0;
    a.def = def;
    return a;
  }
  apiArg aInts(const std::vector<int> &v, bool def = false)
  {
    apiArg a;
    a.kind = apiArg::Ints;
    a.ints = v;
    a.def = def;
    return a;
  }
  apiArg aNums(const std::vector<std::string> &v, bool def = false)
  {
    apiArg a;
    a.kind = apiArg::Nums;
    a.exprs = v;
    a.def = def;
    return a;
  }
  apiArg aDimTags(const std::vector<std::pair<int, int>> &v)
  {
    apiArg a;
    a.kind = apiArg::DimTags;
    a.dimTags = v;
    return a;
  }
  apiArg aOut(apiArg::Kind kind, const std::string &name)
  {
    apiArg a;
    a.kind = kind;
    a.str = name;
    return a;
  }
  apiArg aVar(const std::string &name)
  {
    apiArg a;
    a.kind = apiArg::VarDimTags;
    a.str = name;
    return a;
  }

  // a call: the function ("model/geo/addPoint"), its arguments, whether it
  // returns a value (assigned in Fortran), and the output kept in a variable
  // (by languages that return outputs instead of taking them)
  struct apiCall {
    std::string name;
    std::vector<apiArg> args;
    bool returns = false;
    std::string result;
  };

  apiCall call(const std::string &name, const std::vector<apiArg> &args,
               bool returns = false)
  {
    apiCall c;
    c.name = name;
    c.args = args;
    c.returns = returns;
    return c;
  }

  // the kernel of the commands: that of the script as last read
  std::string kernel()
  {
#if defined(HAVE_PARSER)
    if(gmsh_yyfactory == "OpenCASCADE") return "occ";
#endif
    return "geo";
  }

  // the value of an expression of the .geo language, in the model as read
  double evaluate(const std::string &expr)
  {
    std::string e = expr;
    e.erase(0, e.find_first_not_of(" \t"));
    e.erase(e.find_last_not_of(" \t") + 1);
    if(e.empty()) return 0.;
    char *end;
    double v = strtod(e.c_str(), &end);
    if(*end == '\0') return v;
#if defined(HAVE_PARSER)
    const std::string name = "__scriptValue__";
    ParseString(name + " = " + e + ";");
    auto it = gmsh_yysymbols.find(name);
    if(it != gmsh_yysymbols.end()) {
      v = it->second.value.empty() ? 0. : it->second.value[0];
      gmsh_yysymbols.erase(it);
      return v;
    }
#endif
    Msg::Warning("Could not evaluate '%s' for the scripts, written as 0",
                 expr.c_str());
    return 0.;
  }

  // the numbers of a list of the .geo language ("{1, 2}", "1, 2" or "1")
  std::vector<std::string> listOf(const std::string &s)
  {
    std::string t = s;
    for(char &c : t)
      if(c == '{' || c == '}') c = ' ';
    std::vector<std::string> v;
    for(auto &w : SplitString(t, ',', true))
      if(w.find_first_not_of(" \t") != std::string::npos) v.push_back(w);
    return v;
  }

  // --- the languages

  struct language {
    std::string name, ext, comment, indent;
  };

  const language *languageOf(const std::string &name)
  {
    static const std::vector<language> languages = {
      {"py", ".py", "#", ""},      {"jl", ".jl", "#", ""},
      {"cpp", ".cpp", "//", "  "}, {"c", ".c", "//", "  "},
      {"f90", ".f90", "!", ""},    {"js", ".mjs", "//", ""}};
    for(auto &l : languages)
      if(l.name == name) return &l;
    return nullptr;
  }

  std::string number(double v, const std::string &lang)
  {
    char buf[64];
    snprintf(buf, sizeof(buf), "%.16g", v);
    std::string s(buf);
    if(lang != "f90") return s;
    // (a double literal of Fortran)
    std::size_t e = s.find('e');
    if(e != std::string::npos) return s.replace(e, 1, "d");
    return s + "d0";
  }

  std::string quoted(const std::string &s, const std::string &lang)
  {
    std::string q = "\"";
    for(char c : s) {
      if(lang == "f90") {
        q += c;
        if(c == '"') q += c;
      }
      else {
        if(c == '"' || c == '\\') q += '\\';
        q += c;
      }
    }
    return q + "\"";
  }

  std::string join(const std::vector<std::string> &v)
  {
    std::string s;
    for(std::size_t i = 0; i < v.size(); i++) s += (i ? ", " : "") + v[i];
    return s;
  }

  // a vector of numbers or ints, written (in C, with its size)
  std::string vector(const std::vector<std::string> &v, bool doubles,
                     const std::string &lang)
  {
    if(lang == "c")
      return v.empty() ? "NULL, 0" :
                         std::string("(") + (doubles ? "double" : "int") +
                           "[]){" + join(v) + "}, " + std::to_string(v.size());
    if(lang == "cpp") return "{" + join(v) + "}";
    if(lang == "f90" && v.empty())
      return doubles ? "[real(c_double) ::]" : "[integer(c_int) ::]";
    if(lang == "jl" && v.empty()) return doubles ? "Float64[]" : "Int[]";
    return "[" + join(v) + "]";
  }

  std::string dimTags(const std::vector<std::pair<int, int>> &v,
                      const std::string &lang)
  {
    std::vector<std::string> p;
    for(auto &d : v) {
      std::string a = std::to_string(d.first), b = std::to_string(d.second);
      if(lang == "py" || lang == "jl")
        p.push_back("(" + a + ", " + b + ")");
      else if(lang == "js")
        p.push_back("[" + a + ", " + b + "]");
      else if(lang == "cpp")
        p.push_back("{" + a + ", " + b + "}");
      else {
        p.push_back(a);
        p.push_back(b);
      }
    }
    if(lang == "c")
      return v.empty() ?
               "NULL, 0" :
               "(int[]){" + join(p) + "}, " + std::to_string(p.size());
    if(lang == "f90")
      return v.empty() ? "reshape([integer(c_int) ::], [2, 0])" :
                         "reshape([" + join(p) + "], [2, " +
                           std::to_string(v.size()) + "])";
    if(lang == "cpp") return "{" + join(p) + "}";
    if(lang == "jl" && v.empty()) return "Tuple{Int,Int}[]";
    return "[" + join(p) + "]";
  }

  std::string functionName(const std::string &name, const std::string &lang)
  {
    if(lang == "cpp") return "gmsh::" + ReplaceSubString("/", "::", name);
    if(lang == "f90") return "gmsh%" + ReplaceSubString("/", "%", name);
    if(lang == "c") {
      std::string s = "gmsh";
      for(auto &w : SplitString(name, '/')) {
        if(w.empty()) continue;
        s += (char)toupper(w[0]);
        s += w.substr(1);
      }
      return s;
    }
    return "gmsh." + ReplaceSubString("/", ".", name);
  }

  // a call written in a language; the variables of its outputs declared in
  // decls, those to free in frees (C)
  std::string written(const apiCall &c, const std::string &lang,
                      std::vector<std::string> &decls,
                      std::vector<std::string> &frees)
  {
    // the arguments the language takes: the outputs are returned by those of
    // Python, Julia and JavaScript; the defaults at the end left out, but in
    // C
    bool returnsOutputs = (lang == "py" || lang == "jl" || lang == "js");
    std::vector<const apiArg *> args;
    for(auto &a : c.args)
      if(!(returnsOutputs && a.output())) args.push_back(&a);
    if(lang != "c")
      while(args.size() && args.back()->def) args.pop_back();

    std::vector<std::string> w;
    for(const apiArg *a : args) {
      const std::string &n = a->str;
      switch(a->kind) {
      case apiArg::Int: w.push_back(std::to_string(a->i)); break;
      case apiArg::Num: w.push_back(number(evaluate(n), lang)); break;
      case apiArg::Str: w.push_back(quoted(n, lang)); break;
      case apiArg::Bool:
        if(lang == "py")
          w.push_back(a->i ? "True" : "False");
        else if(lang == "c")
          w.push_back(a->i ? "1" : "0");
        else if(lang == "f90")
          w.push_back(a->i ? ".true." : ".false.");
        else
          w.push_back(a->i ? "true" : "false");
        break;
      case apiArg::Ints: {
        std::vector<std::string> v;
        for(int i : a->ints) v.push_back(std::to_string(i));
        w.push_back(vector(v, false, lang));
      } break;
      case apiArg::Nums: {
        std::vector<std::string> v;
        for(auto &e : a->exprs) v.push_back(number(evaluate(e), lang));
        w.push_back(vector(v, true, lang));
      } break;
      case apiArg::DimTags: w.push_back(dimTags(a->dimTags, lang)); break;
      case apiArg::VarDimTags:
        w.push_back(lang == "c" ? n + ", " + n + "_n" : n);
        break;
      case apiArg::OutDimTags:
      case apiArg::OutInts:
        if(lang == "cpp")
          decls.push_back((a->kind == apiArg::OutInts ? "std::vector<int> " :
                                                        "gmsh::vectorpair ") +
                          n + ";");
        else if(lang == "c") {
          decls.push_back("int *" + n + ";");
          decls.push_back("size_t " + n + "_n;");
          frees.push_back("gmshFree(" + n + ");");
        }
        else if(lang == "f90")
          decls.push_back("integer(c_int), allocatable :: " + n +
                          (a->kind == apiArg::OutInts ? "(:)" : "(:,:)"));
        w.push_back(lang == "c" ? "&" + n + ", &" + n + "_n" : n);
        break;
      case apiArg::OutDimTagsMap:
        if(lang == "cpp") {
          decls.push_back("std::vector<gmsh::vectorpair> " + n + ";");
          w.push_back(n);
        }
        else if(lang == "c") {
          decls.push_back("int **" + n + ";");
          decls.push_back("size_t *" + n + "_n, " + n + "_nn;");
          frees.push_back("for(size_t i = 0; i < " + n + "_nn; i++) gmshFree(" +
                          n + "[i]);");
          frees.push_back("gmshFree(" + n + ");");
          frees.push_back("gmshFree(" + n + "_n);");
          w.push_back("&" + n + ", &" + n + "_n, &" + n + "_nn");
        }
        else {
          decls.push_back("integer(c_int), allocatable :: " + n + "(:,:)");
          decls.push_back("integer(c_size_t), allocatable :: " + n + "_n(:)");
          w.push_back(n + ", " + n + "_n");
        }
        break;
      }
    }
    if(lang == "c") w.push_back("&ierr");

    std::string f = functionName(c.name, lang) + "(" + join(w) + ")";
    if(lang == "f90") return (c.returns ? "r = " : "call ") + f;
    if(returnsOutputs && c.result.size())
      f = (lang == "js" ? "const " : "") + c.result + " = " + f;
    if(lang == "py" || lang == "jl") return f;
    return f + ";";
  }

  // Fortran lines of free form are at most 132 characters long
  std::string wrapped(const std::string &line, const std::string &indent)
  {
    if(line.size() <= 100) return indent + line;
    std::string out, cur;
    bool inString = false;
    for(std::size_t i = 0; i < line.size(); i++) {
      cur += line[i];
      if(line[i] == '"') inString = !inString;
      if(!inString && line[i] == ',' && cur.size() > 70) {
        out += indent + cur + " &\n";
        cur = "    ";
      }
    }
    return out + indent + cur;
  }

  // the text of a command in a language: the .geo command as a comment, and
  // its calls, in a block of their own if they have outputs to declare
  std::string commandText(const std::string &geo,
                          const std::vector<apiCall> &calls,
                          const std::string &lang)
  {
    const language *l = languageOf(lang);
    std::vector<std::string> decls, frees, lines;
    for(auto &c : calls) lines.push_back(written(c, lang, decls, frees));
    bool block = !decls.empty() || (lang == "js" && [&] {
      for(auto &c : calls)
        if(c.result.size()) return true;
      return false;
    }());
    std::string in = l->indent + (block ? "  " : "");
    std::string text = l->indent + l->comment + "+\n";
    for(auto &g : SplitString(geo, '\n'))
      if(g.find_first_not_of(" ") != std::string::npos)
        text += l->indent + l->comment + " " + g + "\n";
    if(block) text += l->indent + (lang == "f90" ? "block" : "{") + "\n";
    for(auto &d : decls) text += in + d + "\n";
    for(auto &s : lines)
      text += (lang == "f90" ? wrapped(s, in) : in + s) + "\n";
    for(auto &f : frees) text += in + f + "\n";
    if(block) text += l->indent + (lang == "f90" ? "end block" : "}") + "\n";
    return text;
  }

  // the line above which the commands go, and the parts of a program around
  // them
  std::string endMark(const language *l)
  {
    return l->indent + l->comment +
           " (the commands added by the graphical interface go above this "
           "line)";
  }

  std::string prologue(const language *l, const std::string &geoName,
                       const std::string &model)
  {
    std::string head = l->comment + " Gmsh " +
                       (l->name == "py"  ? "Python" :
                        l->name == "jl"  ? "Julia" :
                        l->name == "cpp" ? "C++" :
                        l->name == "c"   ? "C" :
                        l->name == "f90" ? "Fortran" :
                                           "JavaScript") +
                       " program of the commands of " + geoName + ",\n" +
                       l->comment +
                       " written by the graphical interface (see the "
                       "General.ScriptingLanguages option)\n\n";
    if(l->name == "py")
      return head +
             "import gmsh\nimport sys\n\ngmsh.initialize(sys.argv)\n"
             "gmsh.model.add(" +
             quoted(model, "py") + ")\n\n";
    if(l->name == "jl")
      return head + "import gmsh\n\ngmsh.initialize()\ngmsh.model.add(" +
             quoted(model, "jl") + ")\n\n";
    if(l->name == "cpp")
      return head +
             "#include <set>\n#include <string>\n#include <gmsh.h>\n\n"
             "int main(int argc, char **argv)\n{\n"
             "  gmsh::initialize(argc, argv);\n"
             "  gmsh::model::add(" +
             quoted(model, "cpp") + ");\n\n";
    if(l->name == "c")
      return head +
             "#include <stdio.h>\n#include <string.h>\n"
             "#include <gmshc.h>\n\nint main(int argc, char **argv)\n"
             "{\n  int ierr, i, gui = 1;\n"
             "  gmshInitialize(argc, argv, 1, 0, &ierr);\n"
             "  gmshModelAdd(" +
             quoted(model, "c") + ", &ierr);\n\n";
    if(l->name == "f90")
      return head +
             "program gmsh_program\nuse, intrinsic :: iso_c_binding\n"
             "use gmsh\nimplicit none\ntype(gmsh_t) :: gmsh\n"
             "integer(c_int) :: r\n"
             "character(len=GMSH_API_MAX_STR_LEN) :: cmd\n\n"
             "call gmsh%initialize()\ncall gmsh%model%add(" +
             quoted(model, "f90") + ")\n\n";
    return head +
           "// (run with Node.js, gmsh.mjs and libgmsh.wasm of the web "
           "build of Gmsh next to it)\nimport createGmsh from "
           "'./gmsh.mjs';\n\nconst gmsh = await createGmsh();\n"
           "gmsh.initialize();\ngmsh.model.add(" +
           quoted(model, "js") + ");\n\n";
  }

  std::string epilogue(const language *l, const std::string &kern)
  {
    apiCall sync = call("model/" + kern + "/synchronize", {});
    std::vector<std::string> d, f;
    std::string s = l->indent + written(sync, l->name, d, f) + "\n";
    if(l->name == "py")
      return s + "if '-nopopup' not in sys.argv:\n    gmsh.fltk.run()\n"
                 "gmsh.finalize()\n";
    if(l->name == "jl")
      return s + "if !(\"-nopopup\" in ARGS)\n    gmsh.fltk.run()\nend\n"
                 "gmsh.finalize()\n";
    if(l->name == "cpp")
      return s + "  std::set<std::string> args(argv, argv + argc);\n"
                 "  if(!args.count(\"-nopopup\")) gmsh::fltk::run();\n"
                 "  gmsh::finalize();\n  return 0;\n}\n";
    if(l->name == "c")
      return s + "  for(i = 0; i < argc; i++)\n"
                 "    if(!strcmp(argv[i], \"-nopopup\")) gui = 0;\n"
                 "  if(gui) gmshFltkRun(\"\", &ierr);\n  gmshFinalize(&ierr);\n"
                 "  return 0;\n}\n";
    if(l->name == "f90")
      return s + "call get_command(cmd)\n"
                 "if (index(cmd, \"-nopopup\") == 0) call gmsh%fltk%run()\n"
                 "call gmsh%finalize()\n\nend program gmsh_program\n";
    return s + "gmsh.finalize();\n";
  }

  // the kernel whose changes are not synchronized with the model yet: before
  // the calls on the model, those of the kernel are synchronized ("?" at
  // first, as the programs may have been written before)
  std::string _unsynced = "?";
  std::string _lastKernel;

  // a call that changes a kernel (its meshing constraints too, which its
  // synchronization gives to the model)
  bool kernelCall(const std::string &name, std::string &kern)
  {
    for(const char *k : {"geo", "occ"}) {
      std::string p = std::string("model/") + k + "/";
      if(!name.compare(0, p.size(), p)) {
        kern = k;
        return name != p + "synchronize";
      }
    }
    return false;
  }

  std::vector<apiCall> synchronized(const std::vector<apiCall> &calls)
  {
    std::vector<apiCall> out;
    for(auto &c : calls) {
      std::string kern;
      if(kernelCall(c.name, kern)) {
        if(_unsynced != "?" && _unsynced.size() && _unsynced != kern)
          out.push_back(call("model/" + _unsynced + "/synchronize", {}));
        _unsynced = _lastKernel = kern;
      }
      // (on the model, but the fields, which are not on its entities)
      else if(kern.empty() && !c.name.compare(0, 6, "model/") &&
              c.name.find("/field/") == std::string::npos) {
        if(_unsynced.size()) {
          std::string k = (_unsynced == "?") ? kernel() : _unsynced;
          out.push_back(call("model/" + k + "/synchronize", {}));
          _unsynced.clear();
        }
      }
      out.push_back(c);
    }
    return out;
  }

  // a command added to the program of a language, next to the .geo script
  void addToProgram(const std::string &geoFile, const std::string &lang,
                    const std::string &text)
  {
    const language *l = languageOf(lang);
    if(!l) return;
    std::vector<std::string> split = SplitFileName(geoFile);
    std::string fileName = split[0] + split[1] + l->ext;
    std::string mark = endMark(l), s;
    std::ifstream in(fileName.c_str());
    if(in) {
      std::stringstream b;
      b << in.rdbuf();
      s = b.str();
    }
    std::size_t m = s.find(mark);
    if(m == std::string::npos) {
      // a file of the same name not written here (the user's own program,
      // say): left as it is
      if(s.size()) {
        static std::set<std::string> warned;
        if(warned.insert(fileName).second)
          Msg::Warning("'%s' was not written by the graphical interface: the "
                       "commands are not added to it",
                       fileName.c_str());
        return;
      }
      s = prologue(l, split[1] + split[2], split[1]);
      m = s.size();
    }
    std::string kern = _lastKernel.size() ? _lastKernel : kernel();
    s = s.substr(0, m) + text + mark + "\n" + epilogue(l, kern);
    FILE *fp = Fopen(fileName.c_str(), "w");
    if(!fp) {
      Msg::Error("Unable to write '%s'", fileName.c_str());
      return;
    }
    fprintf(fp, "%s", s.c_str());
    fclose(fp);
  }

  // the last command taken out of the program of a language
  void removeFromProgram(const std::string &geoFile, const language *l)
  {
    std::vector<std::string> split = SplitFileName(geoFile);
    std::string fileName = split[0] + split[1] + l->ext;
    std::ifstream in(fileName.c_str());
    if(!in) return;
    std::stringstream b;
    b << in.rdbuf();
    std::string s = b.str();
    std::size_t m = s.find(endMark(l));
    if(m == std::string::npos) return;
    std::size_t c = s.rfind(l->indent + l->comment + "+\n", m);
    if(c == std::string::npos) return;
    s.erase(c, m - c);
    FILE *fp = Fopen(fileName.c_str(), "w");
    if(!fp) return;
    fprintf(fp, "%s", s.c_str());
    fclose(fp);
  }

} // namespace

// the factory set by the script: as the parser, the maximum tags of its
// kernel raised to those of the other one (the kernel switched from is
// synchronized before, see synchronized())
static std::vector<apiCall> factoryCalls()
{
  std::string k = kernel();
  std::vector<apiCall> c;
  for(int dim = -2; dim <= 3; dim++) {
    int t = (k == "occ" && GModel::current()->getOCCInternals()) ?
              GModel::current()->getOCCInternals()->getMaxTag(dim) :
              GModel::current()->getGEOInternals()->getMaxTag(dim);
    if(t > 0)
      c.push_back(call("model/" + k + "/setMaxTag", {aInt(dim), aInt(t)}));
  }
  return c;
}

// A command: its text in the .geo language, and the calls of the API it
// amounts to (made once the .geo command has been read, as they may need the
// model it gives), written in the other languages asked for
static void scriptAdd(const std::string &geo, const std::string &fileName,
                      std::function<std::vector<apiCall>()> calls = nullptr)
{
  scriptAddCommand(geo, fileName);
  if(!scriptLastCommandAdded() || !calls) return;
  std::vector<std::string> langs;
  for(auto &lang : CTX::instance()->scriptLang) {
    if(lang == "geo") continue;
    if(!languageOf(lang)) {
      Msg::Warning("Unknown scripting language '%s' (General.ScriptingLanguages"
                   ": geo, py, jl, cpp, c, f90, js)",
                   lang.c_str());
      continue;
    }
    langs.push_back(lang);
  }
  if(langs.empty()) return;
  std::vector<apiCall> c;
  if(geo.find("SetFactory(") != std::string::npos) c = factoryCalls();
  for(auto &a : calls()) c.push_back(a);
  c = synchronized(c);
  // (the script given, or the one made for a model that had none)
  std::string geoFile =
    fileName.size() ? fileName : GModel::current()->getFileName();
  for(auto &lang : langs)
    addToProgram(geoFile, lang, commandText(geo, c, lang));
}

const std::vector<scriptLanguage> &scriptLanguages()
{
  static const std::vector<scriptLanguage> languages = {
    {"py", "Python"}, {"jl", "Julia"},    {"cpp", "C++"},
    {"c", "C"},       {"f90", "Fortran"}, {"js", "JavaScript"}};
  return languages;
}

std::string scriptProgram(const std::string &geoFile, const std::string &lang)
{
  const language *l = languageOf(lang);
  if(!l || geoFile.empty()) return "";
  std::vector<std::string> split = SplitFileName(geoFile);
  return split[0] + split[1] + l->ext;
}

bool scriptWritesIn(const std::string &lang)
{
  for(auto &l : CTX::instance()->scriptLang)
    if(l == lang) return true;
  return false;
}

void scriptWriteIn(const std::string &lang, bool on)
{
  // (the .geo script first, as it is always written)
  std::string v = "geo";
  for(auto &l : CTX::instance()->scriptLang)
    if(l != "geo" && l != lang) v += "," + l;
  if(on) v += "," + lang;
  opt_general_scripting_languages(0, GMSH_SET | GMSH_GUI, v);
}

void scriptRemoveLastCommand(const std::string &fileName)
{
  if(!scriptRemoveLastGeoCommand(fileName)) return;
  for(auto &lang : CTX::instance()->scriptLang)
    if(const language *l = languageOf(lang)) removeFromProgram(fileName, l);
}

static std::string list2String(List_T *list)
{
  std::ostringstream sstream;
  sstream << "{";
  for(int i = 0; i < List_Nbr(list); i++) {
    int num;
    List_Read(list, i, &num);
    if(i) sstream << ", ";
    sstream << num;
  }
  sstream << "}";
  return sstream.str();
}

static std::vector<int> listInts(List_T *list)
{
  std::vector<int> v;
  for(int i = 0; i < List_Nbr(list); i++) {
    int num;
    List_Read(list, i, &num);
    v.push_back(num);
  }
  return v;
}

static std::string vector2String(const std::vector<int> &v)
{
  std::ostringstream sstream;
  sstream << "{";
  for(std::size_t i = 0; i < v.size(); i++) {
    if(i) sstream << ", ";
    sstream << v[i];
  }
  sstream << "}";
  return sstream.str();
}

static std::string dimTags2String(const std::vector<std::pair<int, int>> &l)
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

// the next tag of an entity of dimension dim (of a loop or a wire: -dim)
static int nextTag(int dim)
{
  if(dim >= 0) return GModel::current()->getMaxElementaryNumber(dim) + 1;
  int t = GModel::current()->getGEOInternals()->getMaxTag(dim) + 1;
  if(GModel::current()->getOCCInternals())
    t = std::max(t, GModel::current()->getOCCInternals()->getMaxTag(dim) + 1);
  return t;
}

// the shapes of OpenCASCADE: the factory set first in the .geo script if it
// is not already
static std::string occFactory()
{
#if defined(HAVE_PARSER)
  if(gmsh_yyfactory != "OpenCASCADE") return "SetFactory(\"OpenCASCADE\");\n";
#endif
  return "";
}

void scriptSetFactory(const std::string &factory, const std::string &fileName)
{
  // (the calls of the programs follow the factory of the script)
  scriptAdd("SetFactory(\"" + factory + "\");", fileName,
            [] { return std::vector<apiCall>(); });
}

// the meshing constraints of an entity: those of the entities of the
// built-in kernel are set in it (its synchronization would reset those set
// on the model), the others on the model
static bool builtIn(int dim, int tag)
{
  GEntity *e = GModel::current()->getEntityByTag(dim, tag);
  return e && e->getNativeType() == GEntity::GmshModel;
}

static std::string meshCall(int dim, int tag, const std::string &what)
{ return (builtIn(dim, tag) ? "model/geo/mesh/" : "model/mesh/") + what; }

void scriptSetMeshSize(const std::string &fileName, const std::vector<int> &l,
                       const std::string &lc)
{
  scriptAdd("MeshSize " + vector2String(l) + " = " + lc + ";", fileName, [=] {
    std::vector<std::pair<int, int>> geo, other;
    for(int t : l) (builtIn(0, t) ? geo : other).push_back({0, t});
    std::vector<apiCall> c;
    if(geo.size())
      c.push_back(call("model/geo/mesh/setSize", {aDimTags(geo), aNum(lc)}));
    if(other.size())
      c.push_back(call("model/mesh/setSize", {aDimTags(other), aNum(lc)}));
    return c;
  });
}

void scriptRecombineSurface(const std::string &fileName,
                            const std::vector<int> &l)
{
  scriptAdd("Recombine Surface " + vector2String(l) + ";", fileName, [=] {
    std::vector<apiCall> c;
    for(int t : l)
      c.push_back(call(meshCall(2, t, "setRecombine"),
                       {aInt(2), aInt(t), aNum("45", true)}));
    return c;
  });
}

void scriptSetTransfiniteLine(std::vector<int> &l, const std::string &fileName,
                              const std::string &type,
                              const std::string &typearg,
                              const std::string &pts)
{
  std::ostringstream sstream;
  sstream << "Transfinite Curve " << vector2String(l) << " = " << pts;
  if(typearg.size()) sstream << " Using " << type << " " << typearg;
  sstream << ";";
  scriptAdd(sstream.str(), fileName, [=] {
    std::vector<apiCall> c;
    for(int t : l)
      c.push_back(
        call(meshCall(1, t, "setTransfiniteCurve"),
             {aInt(t), aInt((int)std::lround(evaluate(pts))),
              aStr(typearg.size() ? type : "Progression", typearg.empty()),
              aNum(typearg.size() ? typearg : "1", typearg.empty())}));
    return c;
  });
}

void scriptSetTransfiniteSurface(std::vector<int> &l,
                                 const std::string &fileName,
                                 const std::string &dir)
{
  std::ostringstream sstream;
  sstream << "Transfinite Surface {" << l[0] << "}";
  std::vector<int> corners(l.begin() + 1, l.end());
  if(corners.size()) sstream << " = " << vector2String(corners);
  if(dir != "Left") sstream << " " << dir;
  sstream << ";";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call(meshCall(2, l[0], "setTransfiniteSurface"),
           {aInt(l[0]), aStr(dir, dir == "Left"), aInts(corners, true)})};
  });
}

void scriptSetTransfiniteVolume(std::vector<int> &l,
                                const std::string &fileName)
{
  std::ostringstream sstream;
  sstream << "Transfinite Volume{" << l[0] << "}";
  std::vector<int> corners(l.begin() + 1, l.end());
  if(corners.size()) sstream << " = " << vector2String(corners);
  sstream << ";";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{call(meshCall(3, l[0], "setTransfiniteVolume"),
                                     {aInt(l[0]), aInts(corners, true)})};
  });
}

void scriptEmbed(const std::string &fileName, const std::string &what,
                 std::vector<int> &l, int dim, int tag)
{
  std::ostringstream sstream;
  sstream << what << vector2String(l) << " In "
          << (dim == 2 ? "Surface{" : "Volume{") << tag << "};";
  int whatDim = (what == "Point") ? 0 : (what == "Curve") ? 1 : 2;
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{call(
      "model/mesh/embed", {aInt(whatDim), aInts(l), aInt(dim), aInt(tag)})};
  });
}

void scriptAddParameter(const std::string &par, const std::string &value,
                        const std::string &label, const std::string &path,
                        const std::string &fileName)
{
  std::string name;
  if(path.size() && label.size())
    name = path + "/" + label;
  else if(path.size())
    name = path + "/" + par;
  else if(label.size())
    name = label;
  else
    name = par;
  scriptAdd(par + " = DefineNumber[ " + value + ", Name \"" + name + "\" ];",
            fileName, [=] {
              return std::vector<apiCall>{
                call("onelab/setNumber", {aStr(name), aNums({value})})};
            });
}

void scriptAddPoint(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &lc)
{
  int tag = nextTag(0);
  std::ostringstream sstream;
  sstream << "Point(" << tag << ") = {" << x << ", " << y << ", " << z;
  if(lc.size()) sstream << ", " << lc;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/" + kernel() + "/addPoint",
           {aNum(x), aNum(y), aNum(z), aNum(lc.size() ? lc : "0", lc.empty()),
            aInt(tag)},
           true)};
  });
}

void scriptAddFieldOption(int field_id, const std::string &option_name,
                          const std::string &option_value, int option_type,
                          const std::string &fileName)
{
#if defined(HAVE_MESH)
  std::ostringstream sstream;
  sstream << "Field[" << field_id << "]." << option_name << " = "
          << option_value << ";";
  scriptAdd(sstream.str(), fileName, [=] {
    std::vector<apiArg> args = {aInt(field_id), aStr(option_name)};
    std::string f = "model/mesh/field/setNumber";
    switch(option_type) {
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH: {
      // (the value without its quotes, double or single)
      std::string v = option_value;
      if(v.size() >= 2 && (v[0] == '"' || v[0] == '\''))
        v = v.substr(1, v.size() - 2);
      args.push_back(aStr(v));
      f = "model/mesh/field/setString";
    } break;
    case FIELD_OPTION_LIST:
    case FIELD_OPTION_LIST_DOUBLE:
      args.push_back(aNums(listOf(option_value)));
      f = "model/mesh/field/setNumbers";
      break;
    default: args.push_back(aNum(option_value)); break;
    }
    return std::vector<apiCall>{call(f, args)};
  });
#endif
}

void scriptAddField(int field_id, const std::string &type_name,
                    const std::string &fileName)
{
  scriptAdd(
    "Field[" + std::to_string(field_id) + "] = " + type_name + ";", fileName,
    [=] {
      return std::vector<apiCall>{
        call("model/mesh/field/add", {aStr(type_name), aInt(field_id)}, true)};
    });
}

void scriptDeleteField(int field_id, const std::string &fileName)
{
  scriptAdd("Delete Field [" + std::to_string(field_id) + "];", fileName, [=] {
    return std::vector<apiCall>{
      call("model/mesh/field/remove", {aInt(field_id)})};
  });
}

void scriptSetBackgroundField(int field_id, const std::string &fileName)
{
  scriptAdd("Background Field = " + std::to_string(field_id) + ";", fileName,
            [=] {
              return std::vector<apiCall>{
                call("model/mesh/field/setAsBackgroundMesh", {aInt(field_id)})};
            });
}

void scriptAddCurve(const std::string &type, std::vector<int> &p,
                    const std::string &fileName)
{
  int tag = nextTag(1);
  scriptAdd(type + "(" + std::to_string(tag) + ") = " + vector2String(p) + ";",
            fileName, [=] {
              std::string k = kernel(), f = "model/" + k + "/add" + type;
              std::vector<apiArg> args;
              if(type == "Line" && p.size() == 2)
                args = {aInt(p[0]), aInt(p[1]), aInt(tag)};
              else
                args = {aInts(p), aInt(tag)};
              if(k == "occ" && type == "Spline")
                args.push_back(aNums({}, true));
              if(k == "occ" && type == "BSpline") {
                args.push_back(aInt(3, true));
                args.push_back(aNums({}, true));
                args.push_back(aNums({}, true));
                args.push_back(aInts({}, true));
              }
              return std::vector<apiCall>{call(f, args, true)};
            });
}

void scriptAddCircleArc(int p1, int p2, int p3, const std::string &fileName)
{
  int tag = nextTag(1);
  std::ostringstream sstream;
  sstream << "Circle(" << tag << ") = {" << p1 << ", " << p2 << ", " << p3
          << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    std::vector<apiArg> args = {aInt(p1), aInt(p2), aInt(p3), aInt(tag)};
    if(kernel() == "occ")
      args.push_back(aBool(true, true));
    else
      for(int i = 0; i < 3; i++) args.push_back(aNum("0", true));
    return std::vector<apiCall>{
      call("model/" + kernel() + "/addCircleArc", args, true)};
  });
}

void scriptAddEllipseArc(int p1, int p2, int p3, int p4,
                         const std::string &fileName)
{
  int tag = nextTag(1);
  std::ostringstream sstream;
  sstream << "Ellipse(" << tag << ") = {" << p1 << ", " << p2 << ", " << p3
          << ", " << p4 << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    std::vector<apiArg> args = {aInt(p1), aInt(p2), aInt(p3), aInt(p4),
                                aInt(tag)};
    if(kernel() == "geo")
      for(int i = 0; i < 3; i++) args.push_back(aNum("0", true));
    return std::vector<apiCall>{
      call("model/" + kernel() + "/addEllipseArc", args, true)};
  });
}

void scriptAddSurface(const std::string &type, List_T *list,
                      const std::string &fileName)
{
  int tag = nextTag(2);
  std::vector<int> wires = listInts(list);
  scriptAdd(
    type + "(" + std::to_string(tag) + ") = " + list2String(list) + ";",
    fileName, [=] {
      std::string k = kernel();
      if(type == "Plane Surface")
        return std::vector<apiCall>{call("model/" + k + "/addPlaneSurface",
                                         {aInts(wires), aInt(tag)}, true)};
      if(k == "geo")
        return std::vector<apiCall>{
          call("model/geo/addSurfaceFilling",
               {aInts(wires), aInt(tag), aInt(-1, true)}, true)};
      // (OpenCASCADE fills one wire)
      return std::vector<apiCall>{
        call("model/occ/addSurfaceFilling",
             {aInt(wires.empty() ? 0 : wires[0]), aInt(tag), aInts({}, true),
              aInt(2, true), aInt(15, true), aInt(2, true), aBool(false, true),
              aNum("0.00001", true), aNum("0.0001", true), aNum("0.01", true),
              aNum("0.1", true), aInt(8, true), aInt(9, true)},
             true)};
    });
}

bool scriptFindLoop(int dim, List_T *list, int *numloop, int minTag)
{
  if(dim == 1 ? RecognizeLineLoop(list, numloop) :
                RecognizeSurfaceLoop(list, numloop))
    return true;
  *numloop = std::max(nextTag(-dim), minTag);
  return false;
}

void scriptAddLoop(int dim, List_T *list, int numloop,
                   const std::string &fileName)
{
  std::vector<int> l = listInts(list);
  scriptAdd(std::string(dim == 1 ? "Curve Loop(" : "Surface Loop(") +
              std::to_string(numloop) + ") = " + list2String(list) + ";",
            fileName, [=] {
              std::string k = kernel();
              std::vector<apiArg> args = {aInts(l), aInt(numloop)};
              // (reorient of a curve loop of the built-in kernel, sewing of a
              // surface loop of OpenCASCADE)
              if((dim == 1) == (k == "geo")) args.push_back(aBool(false, true));
              return std::vector<apiCall>{call(
                "model/" + k + (dim == 1 ? "/addCurveLoop" : "/addSurfaceLoop"),
                args, true)};
            });
}

void scriptAddVolume(List_T *list, const std::string &fileName)
{
  int tag = nextTag(3);
  std::vector<int> l = listInts(list);
  scriptAdd(
    "Volume(" + std::to_string(tag) + ") = " + list2String(list) + ";",
    fileName, [=] {
      return std::vector<apiCall>{
        call("model/" + kernel() + "/addVolume", {aInts(l), aInt(tag)}, true)};
    });
}

static int dimOf(const std::string &what)
{
  if(what == "Point") return 0;
  if(what == "Curve" || what == "Line") return 1;
  if(what == "Surface") return 2;
  return 3;
}

void scriptAddRemovePhysicalGroup(const std::string &fileName,
                                  const std::string &what,
                                  const std::vector<int> &l,
                                  const std::string &name, int forceTag,
                                  bool append, const std::string &mode)
{
  int dim = dimOf(what);
  int newTag = GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1;
  std::ostringstream sstream;
  sstream << "Physical " << what << "(";
  if(name.size()) {
    sstream << "\"" << name << "\"";
    if(forceTag) sstream << ", " << forceTag;
  }
  else
    sstream << (forceTag ? forceTag : newTag);
  sstream << ") ";
  if(mode == "Remove")
    sstream << "-";
  else if(append)
    sstream << "+";
  sstream << "= " << vector2String(l) << ";";
  scriptAdd(sstream.str(), fileName, [=] {
    // the group as the script made it (a group changed is made again)
    int tag = forceTag;
    if(!tag && name.size())
      tag = GModel::current()->getPhysicalNumber(dim, name);
    if(tag <= 0) tag = newTag;
    std::map<int, std::vector<GEntity *>> groups;
    GModel::current()->getPhysicalGroups(dim, groups);
    std::vector<int> tags;
    for(GEntity *e : groups[tag]) tags.push_back(e->tag());
    std::vector<apiCall> c;
    if(append || mode == "Remove")
      c.push_back(call("model/removePhysicalGroups", {aDimTags({{dim, tag}})}));
    if(tags.size())
      c.push_back(call(
        "model/addPhysicalGroup",
        {aInt(dim), aInts(tags), aInt(tag), aStr(name, name.empty())}, true));
    return c;
  });
}

void scriptSetCompound(const std::string &fileName, const std::string &type,
                       const std::vector<int> &l)
{
  int dim = dimOf(type);
  scriptAdd("Compound " + type + " " + vector2String(l) + ";", fileName, [=] {
    return std::vector<apiCall>{
      call("model/mesh/setCompound", {aInt(dim), aInts(l)})};
  });
}

// the default of an angle of the shapes: 2*Pi, or the value given
static apiArg angle(const std::string &a, const std::string &def)
{ return aNum(a.size() ? a : def, a.empty()); }

void scriptAddCircle(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2)
{
  int tag = nextTag(1);
  std::ostringstream sstream;
  sstream << occFactory() << "Circle(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << r;
  if(alpha1.size()) sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addCircle",
           {aNum(x), aNum(y), aNum(z), aNum(r), aInt(tag), angle(alpha1, "0"),
            angle(alpha1.size() ? alpha2 : "", "2*Pi"), aNums({}, true),
            aNums({}, true)},
           true)};
  });
}

void scriptAddEllipse(const std::string &fileName, const std::string &x,
                      const std::string &y, const std::string &z,
                      const std::string &rx, const std::string &ry,
                      const std::string &alpha1, const std::string &alpha2)
{
  int tag = nextTag(1);
  std::ostringstream sstream;
  sstream << occFactory() << "Ellipse(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << rx << ", " << ry;
  if(alpha1.size()) sstream << ", " << alpha1;
  if(alpha1.size() && alpha2.size()) sstream << ", " << alpha2;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addEllipse",
           {aNum(x), aNum(y), aNum(z), aNum(rx), aNum(ry), aInt(tag),
            angle(alpha1, "0"), angle(alpha1.size() ? alpha2 : "", "2*Pi"),
            aNums({}, true), aNums({}, true)},
           true)};
  });
}

void scriptAddDisk(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &rx, const std::string &ry)
{
  int tag = nextTag(2);
  std::ostringstream sstream;
  sstream << occFactory() << "Disk(" << tag << ") = {" << x << ", " << y << ", "
          << z << ", " << rx << ", " << ry << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addDisk",
           {aNum(x), aNum(y), aNum(z), aNum(rx), aNum(ry), aInt(tag),
            aNums({}, true), aNums({}, true)},
           true)};
  });
}

void scriptAddRectangle(const std::string &fileName, const std::string &x,
                        const std::string &y, const std::string &z,
                        const std::string &dx, const std::string &dy,
                        const std::string &roundedRadius)
{
  int tag = nextTag(2);
  std::ostringstream sstream;
  sstream << occFactory() << "Rectangle(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << dx << ", " << dy;
  if(roundedRadius.size()) sstream << ", " << roundedRadius;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addRectangle",
           {aNum(x), aNum(y), aNum(z), aNum(dx), aNum(dy), aInt(tag),
            angle(roundedRadius, "0")},
           true)};
  });
}

void scriptAddSphere(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2, const std::string &alpha3)
{
  int tag = nextTag(3);
  std::ostringstream sstream;
  sstream << occFactory() << "Sphere(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << r;
  bool a2 = alpha1.size() && alpha2.size();
  bool a3 = a2 && alpha3.size();
  if(alpha1.size()) sstream << ", " << alpha1;
  if(a2) sstream << ", " << alpha2;
  if(a3) sstream << ", " << alpha3;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{call(
      "model/occ/addSphere",
      {aNum(x), aNum(y), aNum(z), aNum(r), aInt(tag), angle(alpha1, "-Pi/2"),
       angle(a2 ? alpha2 : "", "Pi/2"), angle(a3 ? alpha3 : "", "2*Pi")},
      true)};
  });
}

void scriptAddCylinder(const std::string &fileName, const std::string &x,
                       const std::string &y, const std::string &z,
                       const std::string &dx, const std::string &dy,
                       const std::string &dz, const std::string &r,
                       const std::string &alpha)
{
  int tag = nextTag(3);
  std::ostringstream sstream;
  sstream << occFactory() << "Cylinder(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << dx << ", " << dy << ", " << dz << ", " << r;
  if(alpha.size()) sstream << ", " << alpha;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addCylinder",
           {aNum(x), aNum(y), aNum(z), aNum(dx), aNum(dy), aNum(dz), aNum(r),
            aInt(tag), angle(alpha, "2*Pi")},
           true)};
  });
}

void scriptAddBox(const std::string &fileName, const std::string &x,
                  const std::string &y, const std::string &z,
                  const std::string &dx, const std::string &dy,
                  const std::string &dz)
{
  int tag = nextTag(3);
  std::ostringstream sstream;
  sstream << occFactory() << "Box(" << tag << ") = {" << x << ", " << y << ", "
          << z << ", " << dx << ", " << dy << ", " << dz << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addBox",
           {aNum(x), aNum(y), aNum(z), aNum(dx), aNum(dy), aNum(dz), aInt(tag)},
           true)};
  });
}

void scriptAddTorus(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &r1, const std::string &r2,
                    const std::string &alpha)
{
  int tag = nextTag(3);
  std::ostringstream sstream;
  sstream << occFactory() << "Torus(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << r1 << ", " << r2;
  if(alpha.size()) sstream << ", " << alpha;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addTorus",
           {aNum(x), aNum(y), aNum(z), aNum(r1), aNum(r2), aInt(tag),
            angle(alpha, "2*Pi"), aNums({}, true)},
           true)};
  });
}

void scriptAddCone(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &dx, const std::string &dy,
                   const std::string &dz, const std::string &r1,
                   const std::string &r2, const std::string &alpha)
{
  int tag = nextTag(3);
  std::ostringstream sstream;
  sstream << occFactory() << "Cone(" << tag << ") = {" << x << ", " << y << ", "
          << z << ", " << dx << ", " << dy << ", " << dz << ", " << r1 << ", "
          << r2;
  if(alpha.size()) sstream << ", " << alpha;
  sstream << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addCone",
           {aNum(x), aNum(y), aNum(z), aNum(dx), aNum(dy), aNum(dz), aNum(r1),
            aNum(r2), aInt(tag), angle(alpha, "2*Pi")},
           true)};
  });
}

void scriptAddWedge(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &dx, const std::string &dy,
                    const std::string &dz, const std::string &ltx)
{
  int tag = nextTag(3);
  std::ostringstream sstream;
  sstream << occFactory() << "Wedge(" << tag << ") = {" << x << ", " << y
          << ", " << z << ", " << dx << ", " << dy << ", " << dz << ", " << ltx
          << "};";
  scriptAdd(sstream.str(), fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addWedge",
           {aNum(x), aNum(y), aNum(z), aNum(dx), aNum(dy), aNum(dz), aInt(tag),
            angle(ltx, "0"), aNums({}, true)},
           true)};
  });
}

const std::vector<scriptShape> &scriptShapes()
{
  static const std::vector<scriptShape> shapes = {
    {"add_parameter",
     "Parameter",
     2,
     {{"Name", "lc"}, {"Value", "0.1"}, {"Label", ""}, {"Path", "Parameters"}}},
    {"add_point",
     "Point",
     3,
     {{"X", "0"},
      {"Y", "0"},
      {"Z", "0"},
      {"Prescribed mesh size at point", "1.0"}}},
    {"add_circle",
     "Circle",
     4,
     {{"Center X", "0"},
      {"Center Y", "0"},
      {"Center Z", "0"},
      {"Radius", "0.5"},
      {"Angle 1", "0"},
      {"Angle 2", "2*Pi"}}},
    {"add_ellipse",
     "Ellipse",
     5,
     {{"Center X", "0"},
      {"Center Y", "0"},
      {"Center Z", "0"},
      {"Radius X", "0.5"},
      {"Radius Y", "0.25"},
      {"Angle 1", "0"},
      {"Angle 2", "2*Pi"}}},
    {"add_disk",
     "Disk",
     5,
     {{"Center X", "0"},
      {"Center Y", "0"},
      {"Center Z", "0"},
      {"Radius X", "0.5"},
      {"Radius Y", "0.25"}}},
    {"add_rectangle",
     "Rectangle",
     5,
     {{"Corner X", "0"},
      {"Corner Y", "0"},
      {"Corner Z", "0"},
      {"Size X", "1"},
      {"Size Y", "0.5"},
      {"Rounded radius", "0"}}},
    {"add_sphere",
     "Sphere",
     4,
     {{"Center X", "0"},
      {"Center Y", "0"},
      {"Center Z", "0"},
      {"Radius", "0.5"},
      {"Angle 1", "-Pi/2"},
      {"Angle 2", "Pi/2"},
      {"Angle 3", "2*Pi"}}},
    {"add_cylinder",
     "Cylinder",
     7,
     {{"Center base X", "0"},
      {"Center base Y", "0"},
      {"Center base Z", "0"},
      {"Axis DX", "1"},
      {"Axis DY", "0"},
      {"Axis DZ", "0"},
      {"Radius", "0.5"},
      {"Angle", "2*Pi"}}},
    {"add_box",
     "Box",
     6,
     {{"Corner X", "0"},
      {"Corner Y", "0"},
      {"Corner Z", "0"},
      {"Size X", "1"},
      {"Size Y", "1"},
      {"Size Z", "1"}}},
    {"add_torus",
     "Torus",
     5,
     {{"Center X", "0"},
      {"Center Y", "0"},
      {"Center Z", "0"},
      {"Radius 1", "0.5"},
      {"Radius 2", "0.2"},
      {"Angle", "2*Pi"}}},
    {"add_cone",
     "Cone",
     8,
     {{"Center base X", "0"},
      {"Center base Y", "0"},
      {"Center base Z", "0"},
      {"Axis DX", "1"},
      {"Axis DY", "0"},
      {"Axis DZ", "0"},
      {"Radius 1", "0.5"},
      {"Radius 2", "0.1"},
      {"Angle", "2*Pi"}}},
    {"add_wedge",
     "Wedge",
     7,
     {{"Corner X", "0"},
      {"Corner Y", "0"},
      {"Corner Z", "0"},
      {"Size X", "0.5"},
      {"Size Y", "0.5"},
      {"Size Z", "0.5"},
      {"Top size X", "0"}}}};
  return shapes;
}

bool scriptAddShape(const std::string &shape, std::vector<std::string> v,
                    const std::string &f)
{
  const scriptShape *s = nullptr;
  for(auto &t : scriptShapes())
    if(t.name == shape) s = &t;
  if(!s) {
    Msg::Error("Unknown shape '%s'", shape.c_str());
    return false;
  }
  v.resize(std::max<std::size_t>(9, s->fields.size()));
  for(std::size_t i = 0; i < v.size(); i++) {
    // (blank, an optional value is left out, which would write an invalid
    // command in the script if it is required)
    if(v[i].find_first_not_of(" \t") != std::string::npos) continue;
    v[i].clear();
    if((int)i < s->required) {
      Msg::Error("Field '%s' is empty", s->fields[i].first.c_str());
      return false;
    }
  }
  if(shape == "add_parameter") scriptAddParameter(v[0], v[1], v[2], v[3], f);
  else if(shape == "add_point") scriptAddPoint(f, v[0], v[1], v[2], v[3]);
  else if(shape == "add_circle")
    scriptAddCircle(f, v[0], v[1], v[2], v[3], v[4], v[5]);
  else if(shape == "add_ellipse")
    scriptAddEllipse(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
  else if(shape == "add_disk") scriptAddDisk(f, v[0], v[1], v[2], v[3], v[4]);
  else if(shape == "add_rectangle")
    scriptAddRectangle(f, v[0], v[1], v[2], v[3], v[4], v[5]);
  else if(shape == "add_sphere")
    scriptAddSphere(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
  else if(shape == "add_cylinder")
    scriptAddCylinder(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
  else if(shape == "add_box") scriptAddBox(f, v[0], v[1], v[2], v[3], v[4], v[5]);
  else if(shape == "add_torus")
    scriptAddTorus(f, v[0], v[1], v[2], v[3], v[4], v[5]);
  else if(shape == "add_cone")
    scriptAddCone(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
  else
    scriptAddWedge(f, v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
  return scriptLastCommandAdded();
}

bool scriptAddGeo(const std::string &text, const std::string &fileName)
{
  // (no calls for the programs: what the commands amount to in the API is
  // not known)
  scriptAdd(text, fileName);
  return scriptLastCommandAdded();
}

// a transformation: of the entities, or of their copy (Duplicata), whose
// entities the copy gives
static std::vector<apiCall>
transformed(const std::string &what, const std::vector<std::pair<int, int>> &l,
            const std::vector<apiArg> &args, bool duplicata)
{
  std::string k = kernel();
  std::vector<apiCall> c;
  std::vector<apiArg> a;
  if(duplicata) {
    apiCall copy = call("model/" + k + "/copy",
                        {aDimTags(l), aOut(apiArg::OutDimTags, "copied")});
    copy.result = "copied";
    c.push_back(copy);
    a.push_back(aVar("copied"));
  }
  else
    a.push_back(aDimTags(l));
  a.insert(a.end(), args.begin(), args.end());
  c.push_back(call("model/" + k + "/" + what, a));
  return c;
}

static std::string transformText(const std::string &head,
                                 const std::vector<std::pair<int, int>> &l,
                                 bool duplicata)
{
  std::string s = head + " {\n  ";
  if(duplicata) s += "Duplicata { ";
  s += dimTags2String(l);
  if(duplicata) s += "}";
  return s + "\n}";
}

void scriptTranslate(const std::string &fileName,
                     const std::vector<std::pair<int, int> > &l,
                     const std::string &tx, const std::string &ty,
                     const std::string &tz, bool duplicata)
{
  scriptAdd(transformText("Translate {" + tx + ", " + ty + ", " + tz + "}", l,
                          duplicata),
            fileName, [=] {
              return transformed("translate", l, {aNum(tx), aNum(ty), aNum(tz)},
                                 duplicata);
            });
}

void scriptRotate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &ax, const std::string &ay,
                  const std::string &az, const std::string &px,
                  const std::string &py, const std::string &pz,
                  const std::string &angle, bool duplicata)
{
  scriptAdd(transformText("Rotate {{" + ax + ", " + ay + ", " + az + "}, {" +
                            px + ", " + py + ", " + pz + "}, " + angle + "}",
                          l, duplicata),
            fileName, [=] {
              return transformed("rotate", l,
                                 {aNum(px), aNum(py), aNum(pz), aNum(ax),
                                  aNum(ay), aNum(az), aNum(angle)},
                                 duplicata);
            });
}

void scriptDilate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &cx, const std::string &cy,
                  const std::string &cz, const std::string &sx,
                  const std::string &sy, const std::string &sz, bool duplicata)
{
  scriptAdd(transformText("Dilate {{" + cx + ", " + cy + ", " + cz + "}, {" +
                            sx + ", " + sy + ", " + sz + "}}",
                          l, duplicata),
            fileName, [=] {
              return transformed(
                "dilate", l,
                {aNum(cx), aNum(cy), aNum(cz), aNum(sx), aNum(sy), aNum(sz)},
                duplicata);
            });
}

void scriptMirror(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &sa, const std::string &sb,
                  const std::string &sc, const std::string &sd, bool duplicata)
{
  scriptAdd(
    transformText("Symmetry {" + sa + ", " + sb + ", " + sc + ", " + sd + "}",
                  l, duplicata),
    fileName, [=] {
      return transformed("mirror", l, {aNum(sa), aNum(sb), aNum(sc), aNum(sd)},
                         duplicata);
    });
}

// the layers of an extrusion of the mesh ("n", or "{n1, n2}, {h1, h2}"): the
// numbers of elements and the heights, as the API takes them
static void layersOf(const std::string &layers, std::vector<std::string> &n,
                     std::vector<std::string> &h)
{
  std::size_t close = layers.find('}');
  if(close == std::string::npos) {
    n = listOf(layers);
    return;
  }
  n = listOf(layers.substr(0, close + 1));
  std::size_t open = layers.find('{', close);
  if(open != std::string::npos) h = listOf(layers.substr(open));
}

static std::vector<apiArg>
layerArgs(bool extrudeMesh, const std::string &layers, bool recombineMesh)
{
  std::vector<std::string> n, h;
  if(extrudeMesh) layersOf(layers, n, h);
  std::vector<int> ni;
  for(auto &e : n) ni.push_back((int)std::lround(evaluate(e)));
  return {aOut(apiArg::OutDimTags, "extruded"), aInts(ni, ni.empty()),
          aNums(h, h.empty()),
          aBool(extrudeMesh && recombineMesh, !(extrudeMesh && recombineMesh))};
}

void scriptExtrude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &tx, const std::string &ty,
                   const std::string &tz, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh)
{
  std::string s =
    "Extrude {" + tx + ", " + ty + ", " + tz + "} {\n  " + dimTags2String(l);
  if(extrudeMesh) {
    s += "Layers {" + layers + "}; ";
    if(recombineMesh) s += "Recombine;";
  }
  scriptAdd(s + "\n}", fileName, [=] {
    std::vector<apiArg> a = {aDimTags(l), aNum(tx), aNum(ty), aNum(tz)};
    for(auto &b : layerArgs(extrudeMesh, layers, recombineMesh)) a.push_back(b);
    return std::vector<apiCall>{call("model/" + kernel() + "/extrude", a)};
  });
}

void scriptProtude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &ax, const std::string &ay,
                   const std::string &az, const std::string &px,
                   const std::string &py, const std::string &pz,
                   const std::string &angle, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh)
{
  std::string s = "Extrude {{" + ax + ", " + ay + ", " + az + "}, {" + px +
                  ", " + py + ", " + pz + "}, " + angle + "} {\n  " +
                  dimTags2String(l);
  if(extrudeMesh) {
    s += "Layers{" + layers + "}; ";
    if(recombineMesh) s += "Recombine;";
  }
  scriptAdd(s + "\n}", fileName, [=] {
    std::vector<apiArg> a = {aDimTags(l), aNum(px), aNum(py), aNum(pz),
                             aNum(ax),    aNum(ay), aNum(az), aNum(angle)};
    for(auto &b : layerArgs(extrudeMesh, layers, recombineMesh)) a.push_back(b);
    return std::vector<apiCall>{call("model/" + kernel() + "/revolve", a)};
  });
}

void scriptAddPipe(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::vector<int> &l2)
{
  int wire = nextTag(-1);
  std::string s = occFactory() + "Wire(" + std::to_string(wire) +
                  ") = " + vector2String(l2) + ";\nExtrude { " +
                  dimTags2String(l) + "} Using Wire {" + std::to_string(wire) +
                  "}\n";
  scriptAdd(s, fileName, [=] {
    return std::vector<apiCall>{
      call("model/occ/addWire", {aInts(l2), aInt(wire), aBool(false, true)},
           true),
      call("model/occ/addPipe",
           {aDimTags(l), aInt(wire), aOut(apiArg::OutDimTags, "piped"),
            aStr("", true)})};
  });
}

void scriptSplitCurve(int edge_id, List_T *vertices,
                      const std::string &fileName)
{
  std::vector<int> p = listInts(vertices);
  scriptAdd("Split Curve {" + std::to_string(edge_id) + "} Point " +
              list2String(vertices) + ";",
            fileName, [=] {
              return std::vector<apiCall>{call(
                "model/geo/splitCurve",
                {aInt(edge_id), aInts(p), aOut(apiArg::OutInts, "curves")})};
            });
}

void scriptBoolean(const std::string &fileName, const std::string &op,
                   const std::vector<std::pair<int, int> > &object,
                   const std::vector<std::pair<int, int> > &tool,
                   int deleteObject, int deleteTool)
{
  std::string s = occFactory() + op + "{ " + dimTags2String(object);
  if(deleteObject) s += "Delete; ";
  s += "}{ " + dimTags2String(tool);
  if(deleteTool) s += "Delete; ";
  s += "}";
  std::string f = (op == "BooleanUnion")        ? "fuse" :
                  (op == "BooleanIntersection") ? "intersect" :
                  (op == "BooleanDifference")   ? "cut" :
                                                  "fragment";
  scriptAdd(s, fileName, [=] {
    return std::vector<apiCall>{call(
      "model/occ/" + f,
      {aDimTags(object), aDimTags(tool), aOut(apiArg::OutDimTags, "result"),
       aOut(apiArg::OutDimTagsMap, "resultMap"), aInt(-1, true),
       aBool(deleteObject != 0, deleteObject != 0),
       aBool(deleteTool != 0, deleteTool != 0)})};
  });
}

void scriptFillet(const std::string &fileName, const std::vector<int> &regions,
                  const std::vector<int> &edges, const std::string &radius)
{
  scriptAdd(occFactory() + "Fillet " + vector2String(regions) +
              vector2String(edges) + "{" + radius + "}",
            fileName, [=] {
              return std::vector<apiCall>{call(
                "model/occ/fillet",
                {aInts(regions), aInts(edges), aNums({radius}),
                 aOut(apiArg::OutDimTags, "filleted"), aBool(true, true)})};
            });
}

void scriptCoherence(const std::string &fileName)
{
  scriptAdd("Coherence;", fileName, [] {
    return std::vector<apiCall>{
      call("model/" + kernel() + "/removeAllDuplicates", {})};
  });
}

void scriptDeleteEntities(const std::string &fileName,
                          const std::vector<std::pair<int, int> > &l,
                          bool recursive)
{
  std::string s = std::string(recursive ? "Recursive " : "") + "Delete {\n  " +
                  dimTags2String(l) + "\n}";
  scriptAdd(s, fileName, [=] {
    return std::vector<apiCall>{
      call("model/" + kernel() + "/remove",
           {aDimTags(l), aBool(recursive, !recursive)})};
  });
}

void scriptSetVisibilityAll(int mode, const std::string &fileName)
{
  scriptAdd(mode ? "Show \"*\";" : "Hide \"*\";", fileName, [=] {
    // (the entities of the model now)
    std::vector<GEntity *> entities;
    GModel::current()->getEntities(entities);
    std::vector<std::pair<int, int>> all;
    for(GEntity *e : entities) all.push_back({e->dim(), e->tag()});
    return std::vector<apiCall>{
      call("model/setVisibility",
           {aDimTags(all), aInt(mode ? 1 : 0), aBool(false, true)})};
  });
}

void scriptSetVisibility(int mode, const std::vector<std::pair<int, int> > &l,
                         const std::string &fileName)
{
  scriptAdd(std::string(mode ? "Show" : "Hide") + " {\n  " + dimTags2String(l) +
              "\n}",
            fileName, [=] {
              return std::vector<apiCall>{
                call("model/setVisibility",
                     {aDimTags(l), aInt(mode ? 1 : 0), aBool(false, true)})};
            });
}
