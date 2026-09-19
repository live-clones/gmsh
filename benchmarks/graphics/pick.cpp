// Picking sweep of the graphics tests: opens a case of cases.txt, applies all
// its steps, and picks on a grid of the window, three times at every position
// (what is nearest, then what is behind it, twice), printing what is found.
// Built by build_pick.py against the sources and the build directory, as it
// uses the internals of the GUI; run by run.py --pick.
//
//   pick case shaders outdir suitedir datadir

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <FL/Fl.H>
#include "gmsh.h"
#include "FlGui.h"
#include "openglWindow.h"
#include "drawContext.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MElement.h"
#include "PView.h"

struct testCase {
  std::string name;
  std::vector<std::string> files, numbers, steps;
};

static std::vector<testCase> parseCases(const std::string &path)
{
  std::ifstream in(path);
  std::stringstream ss;
  ss << in.rdbuf();
  std::string text = ss.str(), s;
  // lines ending with a backslash continue on the next one
  for(std::size_t i = 0; i < text.size(); i++) {
    if(text[i] == '\\' && i + 1 < text.size() && text[i + 1] == '\n') {
      s += ' ';
      i++;
    }
    else
      s += text[i];
  }
  std::vector<testCase> cases;
  std::istringstream lines(s);
  std::string line;
  while(std::getline(lines, line)) {
    std::size_t first = line.find_first_not_of(" \t");
    if(first == std::string::npos || line[first] == '#') continue;
    if(first == 0) {
      testCase c;
      std::istringstream w(line);
      w >> c.name;
      std::string word;
      while(w >> word) {
        if(word.find('=') != std::string::npos)
          c.numbers.push_back(word);
        else
          c.files.push_back(word);
      }
      cases.push_back(c);
    }
    else if(cases.size())
      cases.back().steps.push_back(line.substr(first));
  }
  return cases;
}

static std::string find(const std::string &f, const std::string &suite,
                        const std::string &data)
{
  for(auto d : {suite, data}) {
    std::string p = d + "/" + f;
    if(!access(p.c_str(), R_OK)) return p;
  }
  return f;
}

int main(int argc, char **argv)
{
  if(argc < 6) {
    fprintf(stderr, "usage: pick case shaders outdir suitedir datadir\n");
    return 1;
  }
  std::string name(argv[1]), out(argv[3]), suite(argv[4]), data(argv[5]);
  std::vector<testCase> cases = parseCases(suite + "/cases.txt");
  const testCase *c = nullptr;
  for(auto &k : cases)
    if(k.name == name) c = &k;
  if(!c) {
    fprintf(stderr, "no case %s\n", name.c_str());
    return 1;
  }

  std::vector<std::string> args = {"gmsh"};
  for(auto &n : c->numbers) {
    std::size_t e = n.find('=');
    args.push_back("-setnumber");
    args.push_back(n.substr(0, e));
    args.push_back(n.substr(e + 1));
  }
  std::vector<char *> cargs;
  for(auto &a : args) cargs.push_back(&a[0]);
  // the default options, whatever the user has saved
  gmsh::initialize((int)cargs.size(), &cargs[0], false);
  gmsh::option::setNumber("General.Terminal", 0);
  for(std::size_t i = 0; i < c->files.size(); i++) {
    std::string f = find(c->files[i], suite, data);
    if(i)
      gmsh::merge(f);
    else
      gmsh::open(f);
  }
  gmsh::option::setNumber("General.Shaders", atoi(argv[2]));
  gmsh::option::setNumber("General.GraphicsWidth", 600);
  gmsh::option::setNumber("General.GraphicsHeight", 450);
  gmsh::option::setNumber("General.MenuWidth", 200);
  gmsh::option::setNumber("General.MessageHeight", 0);
  gmsh::option::setNumber("General.SmallAxes", 0);
  gmsh::fltk::initialize();
  std::string step = out + "/" + name + "_pick_" + std::to_string(getpid()) +
                     ".geo";
  for(auto &s : c->steps) {
    // a line break after every statement and every loop header, as run.py
    std::string t = std::regex_replace(
      s, std::regex("(For\\s+\\w+\\s+In\\s*\\{[^}]*\\})"), "$1\n");
    t = std::regex_replace(t, std::regex(";"), ";\n");
    FILE *fp = fopen(step.c_str(), "w");
    fprintf(fp, "%s\n", t.c_str());
    fclose(fp);
    gmsh::merge(step);
  }
  unlink(step.c_str());

  // the window settled (shown, sized and placed) before sweeping: a sweep
  // started while it was not found things where there are none
  openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
  int W = -1, H = -1, stable = 0;
  for(int i = 0; i < 200 && stable < 5; i++) {
    Fl::wait(0.01);
    if(gl->w() == W && gl->h() == H && gl->shown())
      stable++;
    else
      stable = 0;
    W = gl->w();
    H = gl->h();
  }
  gmsh::graphics::draw();
  Fl::check();
  drawContext *ctx = gl->getDrawContext();
  for(int y = 15; y < H - 15; y += 30) {
    for(int x = 15; x < W - 15; x += 30) {
      printf("%d %d", x, y);
      for(int pass = 0; pass < 3; pass++) {
        std::vector<GVertex *> v;
        std::vector<GEdge *> e;
        std::vector<GFace *> f;
        std::vector<GRegion *> r;
        std::vector<MElement *> el;
        std::vector<SPoint2> p;
        std::vector<PView *> vw;
        if(pass) ctx->stepPick(1);
        gl->pick(ENT_ALL, true, true, x, y, 5, 5, v, e, f, r, el, p, vw);
        std::string what = "-";
        if(v.size())
          what = "0:" + std::to_string(v[0]->tag());
        else if(e.size())
          what = "1:" + std::to_string(e[0]->tag());
        else if(f.size())
          what = "2:" + std::to_string(f[0]->tag());
        else if(r.size())
          what = "3:" + std::to_string(r[0]->tag());
        if(el.size()) what += "/e" + std::to_string(el[0]->getNum());
        if(vw.size()) what += "/v" + std::to_string(vw[0]->getTag());
        printf(" %s", what.c_str());
      }
      ctx->resetPick();
      printf("\n");
    }
  }
  gmsh::finalize();
  return 0;
}
