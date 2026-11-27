// MatGmsh - shell meshes in the PERMAS input format, with thickness groups

#include "MatPermas.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <memory>
#include <sstream>
#include <unordered_map>
#include "Context.h"
#include "GFace.h"
#include "GModel.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "OS.h"
#include "discreteFace.h"
#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataGModel.h"
#endif

namespace matgmsh_native {

namespace {

  // A real as the PERMAS files of the pipeline write it: the shortest
  // decimal that reads back as the same double, with a point ("3.",
  // "1350.") and the exponent as in "1.02E-9"
  std::string real(double x)
  {
    char s[64];
    for(int p = 15; p <= 17; p++) {
      snprintf(s, sizeof(s), "%.*g", p, x);
      if(std::strtod(s, nullptr) == x) break;
    }
    std::string r = s, mantissa = r, exponent;
    const std::size_t e = r.find_first_of("eE");
    if(e != std::string::npos) {
      mantissa = r.substr(0, e);
      exponent = r.substr(e + 1);
    }
    if(mantissa.find_first_of(".ni") == std::string::npos) mantissa += '.';
    if(exponent.empty()) return mantissa;
    const std::size_t digits = exponent.find_first_not_of("+-0");
    return mantissa + 'E' + (exponent[0] == '-' ? "-" : "") +
           (digits == std::string::npos ? "0" : exponent.substr(digits));
  }

  std::string upper(std::string s)
  {
    for(char &c : s) c = (char)std::toupper((unsigned char)c);
    return s;
  }

  // the value after "key =" in a keyword line ("$ELEMENT TYPE = TRIA3 ESET =
  // name"), as written
  std::string keywordValue(const std::string &line, const std::string &key)
  {
    const std::string u = upper(line);
    std::size_t at = 0;
    while((at = u.find(key, at)) != std::string::npos) {
      // a whole word
      if(at && std::isalnum((unsigned char)u[at - 1])) {
        at += key.size();
        continue;
      }
      std::size_t i = u.find_first_not_of(" \t", at + key.size());
      if(i == std::string::npos || u[i] != '=') {
        at += key.size();
        continue;
      }
      i = u.find_first_not_of(" \t", i + 1);
      if(i == std::string::npos) return "";
      const std::size_t end = u.find_first_of(" \t\r", i);
      return line.substr(i, end == std::string::npos ? std::string::npos : end - i);
    }
    return "";
  }

  // the number of decimals of the multiples of the step: 3 (as in
  // thicknesses.py), more if the step needs them
  int decimals(double step)
  {
    int d = 3;
    for(; d < 9; d++) {
      const double scaled = step * std::pow(10., d);
      if(std::fabs(scaled - std::round(scaled)) <= 1e-6 * scaled) break;
    }
    return d;
  }

} // namespace

bool writePermas(GModel *model, const std::string &fileName,
                 const ElementThickness &thickness, const PermasOptions &o,
                 PermasReport &r, std::string &error)
{
  r = PermasReport();
  if(!model) {
    error = "no model";
    return false;
  }
  if(!(o.step > 0.) || !std::isfinite(o.step)) {
    error = "the thickness step must be positive";
    return false;
  }
  if(!(o.defaultThickness > 0.) || !std::isfinite(o.defaultThickness)) {
    error = "the default thickness must be positive";
    return false;
  }

  // the triangles and quadrangles, with the multiple of the step their
  // thickness is rounded up to
  struct Shell {
    bool triangle;
    long k;
    MElement *e;
  };
  std::vector<Shell> shells;
  const bool all = o.saveAll || model->noPhysicalGroups();
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    GFace *gf = *it;
    if(!all && gf->physicals.empty()) continue;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      const int type = e->getType();
      if(type != TYPE_TRI && type != TYPE_QUA) continue;
      if(e->getNumVertices() > e->getNumPrimaryVertices()) r.higherOrder++;
      double t = 0.;
      if(!thickness || !thickness(e, t) || !std::isfinite(t) || !(t > 0.)) {
        t = o.defaultThickness;
        r.withoutThickness++;
      }
      // (a multiple of the step, up to 1e-6 relative, stays in its set: the
      // 1.1 of a float, 1.100000024, is not rounded up to 1.2)
      const double q = t / o.step;
      const long k = std::max(1L, (long)std::ceil(q - 1e-6 * std::max(1., q)));
      shells.push_back({type == TYPE_TRI, k, e});
      if(type == TYPE_TRI)
        r.triangles++;
      else
        r.quadrangles++;
    }
  }
  if(shells.empty()) {
    error = all ? "no triangle or quadrangle in the model" :
                  "no triangle or quadrangle in the physical groups (see "
                  "Mesh.SaveAll)";
    return false;
  }
  // the quadrangles then the triangles, by set, by number
  std::sort(shells.begin(), shells.end(), [](const Shell &a, const Shell &b) {
    if(a.triangle != b.triangle) return b.triangle;
    if(a.k != b.k) return a.k < b.k;
    return a.e->getNum() < b.e->getNum();
  });

  // the sets: name and thickness
  const int d = decimals(o.step);
  std::map<long, std::pair<std::string, double> > sets;
  for(const Shell &s : shells) {
    if(sets.count(s.k)) continue;
    char value[64];
    snprintf(value, sizeof(value), "%.*f", d, s.k * o.step);
    sets[s.k] = {std::string("thick_") + value, std::strtod(value, nullptr)};
  }
  r.sets = sets.size();
  r.minThickness = sets.begin()->second.second;
  r.maxThickness = sets.rbegin()->second.second;

  // the corner nodes, by number
  std::vector<MVertex *> nodes;
  for(const Shell &s : shells)
    for(std::size_t j = 0; j < s.e->getNumPrimaryVertices(); j++)
      nodes.push_back(s.e->getVertex(j));
  std::sort(nodes.begin(), nodes.end(), [](MVertex *a, MVertex *b) {
    return a->getNum() < b->getNum();
  });
  nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());
  r.nodes = nodes.size();

  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    error = "cannot open '" + fileName + "'";
    return false;
  }
  // (the columns of the manual meshes of the pipeline: 12 for a number, 13
  // for a node of an element, 25 for a coordinate, 40 + 25 for a thickness)
  fprintf(fp, "!\n$ENTER COMPONENT NAME = %s\n!\n$STRUCTURE\n$COOR \n",
          o.component.c_str());
  const double f = o.scalingFactor;
  for(MVertex *v : nodes)
    fprintf(fp, "%12zu %24s %24s %24s \n", v->getNum(), real(f * v->x()).c_str(),
            real(f * v->y()).c_str(), real(f * v->z()).c_str());
  for(std::size_t i = 0; i < shells.size(); i++) {
    const Shell &s = shells[i];
    if(!i || s.triangle != shells[i - 1].triangle || s.k != shells[i - 1].k)
      fprintf(fp, "$ELEMENT TYPE = %s ESET = %s\n", s.triangle ? "TRIA3" : "QUAD4",
              sets[s.k].first.c_str());
    fprintf(fp, "%12zu", s.e->getNum());
    for(std::size_t j = 0; j < s.e->getNumPrimaryVertices(); j++)
      fprintf(fp, " %12zu", s.e->getVertex(j)->getNum());
    fprintf(fp, " \n");
  }
  fprintf(fp, "$END STRUCTURE\n!\n$SYSTEM\n!\n$GEODAT SHELL CONT = THICK NODES = ALL\n");
  for(auto &s : sets)
    fprintf(fp, "%-40s %24s \n", s.second.first.c_str(), real(s.second.second).c_str());
  fprintf(fp, "!\n");
  if(!o.material.empty()) {
    fprintf(fp, "$ELPROP\n");
    for(auto &s : sets)
      fprintf(fp, "%-41s GEODAT = %-41s MATERIAL =  %s \n", s.second.first.c_str(),
              s.second.first.c_str(), o.material.c_str());
    fprintf(fp, "!\n");
  }
  fprintf(fp, "$END SYSTEM\n$EXIT COMPONENT\n!\n$FIN\n");
  const bool failed = ferror(fp) != 0;
  if(fclose(fp) || failed) {
    error = "cannot write '" + fileName + "'";
    return false;
  }
  return true;
}

ElementThickness nodalThickness(const std::vector<std::size_t> &nodes,
                                const std::vector<double> &values)
{
  auto at = std::make_shared<std::unordered_map<std::size_t, double> >();
  for(std::size_t i = 0; i < nodes.size() && i < values.size(); i++)
    if(std::isfinite(values[i])) (*at)[nodes[i]] = values[i];
  return [at](MElement *e, double &t) {
    double sum = 0.;
    int n = 0;
    for(std::size_t j = 0; j < e->getNumPrimaryVertices(); j++) {
      auto found = at->find(e->getVertex(j)->getNum());
      if(found == at->end()) continue;
      sum += found->second;
      n++;
    }
    if(!n) return false;
    t = sum / n;
    return true;
  };
}

ElementThickness viewThickness(GModel *model, std::string &name)
{
  name.clear();
#if defined(HAVE_POST)
  PViewDataGModel *chosen = nullptr;
  bool named = false;
  for(PView *v : PView::list) {
    auto *d = dynamic_cast<PViewDataGModel *>(v->getData());
    if(!d || d->getNumTimeSteps() < 1 || !d->hasModel(model, 0)) continue;
    const int type = d->getType();
    if(type != PViewDataGModel::NodeData && type != PViewDataGModel::ElementData &&
       type != PViewDataGModel::ElementNodeData)
      continue;
    stepData<double> *s = d->getStepData(0);
    if(!s || s->getNumComponents() != 1) continue;
    const bool thick = upper(d->getName()).find("THICKNESS") != std::string::npos;
    if(!chosen || (thick && !named)) {
      chosen = d;
      named = thick;
    }
  }
  if(!chosen) return nullptr;
  name = chosen->getName();
  stepData<double> *s = chosen->getStepData(0);
  const int type = chosen->getType();
  return [s, type](MElement *e, double &t) {
    if(type == PViewDataGModel::ElementData) {
      const double *d = s->getData(e->getNum());
      if(!d || !std::isfinite(d[0])) return false;
      t = d[0];
      return true;
    }
    // the mean at the corners
    double sum = 0.;
    int n = 0;
    const double *element =
      type == PViewDataGModel::ElementNodeData ? s->getData(e->getNum()) : nullptr;
    if(type == PViewDataGModel::ElementNodeData && !element) return false;
    for(std::size_t j = 0; j < e->getNumPrimaryVertices(); j++) {
      const double *d = element ? element + j : s->getData(e->getVertex(j)->getNum());
      if(!d || !std::isfinite(*d)) continue;
      sum += *d;
      n++;
    }
    if(!n) return false;
    t = sum / n;
    return true;
  };
#else
  return nullptr;
#endif
}

int writePermasFile(GModel *model, const std::string &fileName)
{
  PermasOptions o;
  o.step = CTX::instance()->mesh.permasThicknessStep;
  o.saveAll = CTX::instance()->mesh.saveAll != 0;
  o.scalingFactor = CTX::instance()->mesh.scalingFactor;
  std::string view;
  const ElementThickness thickness = viewThickness(model, view);
  PermasReport r;
  std::string error;
  if(!writePermas(model, fileName, thickness, o, r, error)) {
    Msg::Error("PERMAS export: %s", error.c_str());
    return 0;
  }
  if(!thickness)
    Msg::Warning("PERMAS export: no view of node or element data on the model "
                 "gives the thickness, every element has the thickness %g",
                 o.defaultThickness);
  else if(r.withoutThickness)
    Msg::Warning("PERMAS export: %zu elements without a value in view \"%s\" "
                 "have the thickness %g",
                 r.withoutThickness, view.c_str(), o.defaultThickness);
  if(r.higherOrder)
    Msg::Warning("PERMAS export: %zu elements of order 2 or more written as "
                 "TRIA3 or QUAD4 (their corner nodes)",
                 r.higherOrder);
  const std::string from = thickness ? ", thickness of view \"" + view + "\"" : "";
  Msg::Info("PERMAS export: %zu nodes, %zu triangles, %zu quadrangles in %zu "
            "sets of thickness %g to %g (step %g%s)",
            r.nodes, r.triangles, r.quadrangles, r.sets, r.minThickness,
            r.maxThickness, o.step, from.c_str());
  return 1;
}

bool isPermasFile(const std::string &fileName)
{
  std::ifstream f(fileName);
  std::string line;
  for(int i = 0; i < 100 && std::getline(f, line); i++) {
    const std::size_t first = line.find_first_not_of(" \t\r");
    if(first == std::string::npos || line[first] == '!') continue;
    const std::string key = upper(line.substr(first));
    return !key.compare(0, 6, "$ENTER") || !key.compare(0, 10, "$STRUCTURE") ||
           !key.compare(0, 7, "$SYSTEM");
  }
  return false;
}

int readPermasFile(GModel *model, const std::string &fileName)
{
  std::ifstream f(fileName);
  if(!f) {
    Msg::Error("Cannot open file '%s'", fileName.c_str());
    return 0;
  }
  enum { Other, Coor, Element, Geodat } section = Other;
  std::unordered_map<std::size_t, MVertex *> vertexOf;
  // the surface of each element set, in the order of the file
  std::vector<std::pair<std::string, discreteFace *> > sets;
  std::map<std::string, std::size_t> setIndex;
  std::map<std::string, double> thicknessOf;
  // the set of each element
  std::vector<std::pair<std::size_t, std::size_t> > elementSet;
  int corners = 0; // 3 (TRIA3), 4 (QUAD4) or 0 (another type)
  std::size_t current = 0, triangles = 0, quadrangles = 0, unknownNodes = 0;
  std::map<std::string, std::size_t> skipped;
  std::string line;
  while(std::getline(f, line)) {
    const std::size_t first = line.find_first_not_of(" \t\r");
    if(first == std::string::npos || line[first] == '!') continue;
    if(line[first] == '$') {
      const std::string key = upper(line.substr(first));
      if(!key.compare(0, 5, "$COOR"))
        section = Coor;
      else if(!key.compare(0, 8, "$ELEMENT")) {
        section = Element;
        const std::string type = upper(keywordValue(line, "TYPE"));
        corners = type == "TRIA3" ? 3 : type == "QUAD4" ? 4 : 0;
        if(!corners) {
          skipped[type]++;
          continue;
        }
        std::string set = keywordValue(line, "ESET");
        if(set.empty()) set = "ESET";
        auto found = setIndex.find(set);
        if(found == setIndex.end()) {
          discreteFace *df =
            new discreteFace(model, model->getMaxElementaryNumber(2) + 1);
          model->add(df);
          found = setIndex.insert({set, sets.size()}).first;
          sets.push_back({set, df});
        }
        current = found->second;
      }
      else if(!key.compare(0, 7, "$GEODAT"))
        section = key.find("SHELL") != std::string::npos ? Geodat : Other;
      else
        section = Other;
      continue;
    }
    std::istringstream in(line);
    if(section == Coor) {
      std::size_t num;
      double x, y, z;
      if(!(in >> num >> x >> y >> z) || vertexOf.count(num)) continue;
      vertexOf[num] = new MVertex(x, y, z, nullptr, num);
    }
    else if(section == Element && corners) {
      std::size_t num, n[4];
      in >> num;
      for(int k = 0; k < corners; k++) in >> n[k];
      if(!in) continue;
      MVertex *v[4];
      bool known = true;
      for(int k = 0; k < corners && known; k++) {
        auto found = vertexOf.find(n[k]);
        known = found != vertexOf.end();
        if(known) v[k] = found->second;
      }
      if(!known) {
        unknownNodes++;
        continue;
      }
      discreteFace *df = sets[current].second;
      for(int k = 0; k < corners; k++) {
        if(v[k]->onWhat()) continue;
        v[k]->setEntity(df);
        df->mesh_vertices.push_back(v[k]);
      }
      if(corners == 3) {
        df->triangles.push_back(new MTriangle(v[0], v[1], v[2], (int)num));
        triangles++;
      }
      else {
        df->quadrangles.push_back(new MQuadrangle(v[0], v[1], v[2], v[3], (int)num));
        quadrangles++;
      }
      elementSet.push_back({num, current});
    }
    else if(section == Geodat) {
      std::string set;
      double t;
      if(in >> set >> t) thicknessOf[set] = t;
    }
  }
  // the nodes of no element
  std::size_t nodes = 0;
  for(auto &v : vertexOf) {
    if(v.second->onWhat())
      nodes++;
    else
      delete v.second;
  }
  // a physical surface per set
  for(auto &s : sets) {
    const int tag = model->getMaxPhysicalNumber(2) + 1;
    s.second->addPhysicalEntity(tag);
    model->setPhysicalName(s.first, 2, tag);
  }
  model->destroyMeshCaches();
  for(auto &s : skipped)
    Msg::Warning("PERMAS: %zu blocks of elements of type %s skipped", s.second,
                 s.first.c_str());
  if(unknownNodes)
    Msg::Warning("PERMAS: %zu elements with unknown nodes skipped", unknownNodes);

  std::size_t withThickness = 0;
#if defined(HAVE_POST)
  if(!thicknessOf.empty()) {
    std::map<int, std::vector<double> > data;
    for(auto &e : elementSet) {
      auto t = thicknessOf.find(sets[e.second].first);
      if(t != thicknessOf.end()) data[(int)e.first] = {t->second};
    }
    withThickness = data.size();
    if(!data.empty()) new PView("PERMAS thickness", "ElementData", model, data, 0., 1);
  }
#endif
  Msg::Info("PERMAS: %zu nodes, %zu triangles, %zu quadrangles in %zu element "
            "sets, %zu elements with a thickness",
            nodes, triangles, quadrangles, sets.size(), withThickness);
  return 1;
}

} // namespace matgmsh_native
