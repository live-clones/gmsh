// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include "GmshConfig.h"
#include "OctreePost.h"
#include "CutParametric.h"
#include "Context.h"
#include "mathEvaluator.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#include "glyphList.h"
#endif

GMSH_CutParametricPlugin::GMSH_CutParametricPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "MinU", nullptr, 0., ""},
                     {GMSH_FULLRC, "MaxU", nullptr, 2 * 3.1416, ""},
                     {GMSH_FULLRC, "NumPointsU", nullptr, 180., ""},
                     {GMSH_FULLRC, "MinV", nullptr, 0., ""},
                     {GMSH_FULLRC, "MaxV", nullptr, 2 * 3.1416, ""},
                     {GMSH_FULLRC, "NumPointsV", nullptr, 180., ""},
                     {GMSH_FULLRC, "ConnectPoints", nullptr, 0., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}},
                    {{GMSH_FULLRC, "X", nullptr, "2 * Cos(u) * Sin(v)", ""},
                     {GMSH_FULLRC, "Y", nullptr, "4 * Sin(u) * Sin(v)", ""},
                     {GMSH_FULLRC, "Z", nullptr, "0.1 + 0.5 * Cos(v)", ""}})
{
}

double GMSH_CutParametricPlugin::getU(int i)
{
  double minU = option(0);
  double maxU = option(1);
  int nbU = (int)option(2);

  if(nbU == 1)
    return minU;
  else
    return minU + (double)(i) / (double)(nbU - 1) * (maxU - minU);
}

double GMSH_CutParametricPlugin::getV(int i)
{
  double minV = option(3);
  double maxV = option(4);
  int nbV = (int)option(5);

  if(nbV == 1)
    return minV;
  else
    return minV + (double)(i) / (double)(nbV - 1) * (maxV - minV);
}

int GMSH_CutParametricPlugin::fillXYZ()
{
  std::vector<std::string> expressions(3), variables(2);
  for(int i = 0; i < 3; i++) expressions[i] = optionStr(i);
  variables[0] = "u";
  variables[1] = "v";
  mathEvaluator f(expressions, variables);

  // always as many points as the options ask for, which drawPreview() relies
  // on
  int nbU = std::max(0, (int)option(2));
  int nbV = std::max(0, (int)option(5));
  x.assign(nbU * nbV, 0.);
  y.assign(nbU * nbV, 0.);
  z.assign(nbU * nbV, 0.);
  std::vector<double> val(2), res(3);
  for(int i = 0; i < nbU; ++i) {
    val[0] = getU(i);
    for(int j = 0; j < nbV; ++j) {
      val[1] = getV(j);
      if(!f.eval(val, res)) return 0; // do not report the error at each point
      x[i * nbV + j] = res[0];
      y[i * nbV + j] = res[1];
      z[i * nbV + j] = res[2];
    }
  }
  return 1;
}

void GMSH_CutParametricPlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  if(_recompute) {
    fillXYZ();
    _recompute = false;
  }
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  int nbU = option(2);
  int nbV = option(5);
  if((int)x.size() != nbU * nbV) return;
  if(option(6) && x.size() > 1) {
    if(nbU == 1 || nbV == 1) {
      gmshBegin(GL_LINES);
      for(std::size_t i = 1; i < x.size(); ++i) {
        gmshVertex3d(x[i - 1], y[i - 1], z[i - 1]);
        gmshVertex3d(x[i], y[i], z[i]);
      }
      gmshEnd();
    }
    else {
      gmshBegin(GL_TRIANGLES);
      for(int i = 0; i < nbU - 1; ++i) {
        for(int j = 0; j < nbV - 1; ++j) {
          int v = i * nbV + j;
          gmshVertex3d(x[v], y[v], z[v]);
          gmshVertex3d(x[v + 1], y[v + 1], z[v + 1]);
          gmshVertex3d(x[v + 1 + nbV], y[v + 1 + nbV], z[v + 1 + nbV]);

          gmshVertex3d(x[v], y[v], z[v]);
          gmshVertex3d(x[v + nbV], y[v + nbV], z[v + nbV]);
          gmshVertex3d(x[v + 1 + nbV], y[v + 1 + nbV], z[v + 1 + nbV]);
        }
      }
      gmshEnd();
    }
  }
  else {
    drawContext *ctx = (drawContext *)context;
    glyphList g;
    unsigned int col = glyphCurrentColor();
    g.reserve(GLYPH_SPHERE, x.size());
    for(std::size_t i = 0; i < x.size(); ++i)
      g.addSphere(ctx, CTX::instance()->pointSize, x[i], y[i], z[i], col);
    g.draw(ctx, 1);
  }
#endif
}

bool GMSH_CutParametricPlugin::optionCallback(int iopt, int num, int action,
                                              double &value)
{
  if(action == 0) _recompute = true;
  switch(iopt) {
  case 0:
  case 1:
  case 3:
  case 4: return sliderOption(iopt, action, value, 0.01, 0., 10.);
  case 2:
  case 5: return sliderOption(iopt, action, value, 1, 1, 1000);
  case 6: return sliderOption(iopt, action, value, 1, 0, 1);
  default: return false;
  }
}

bool GMSH_CutParametricPlugin::optionStrCallback(int iopt, int num, int action,
                                                 std::string &value)
{
  optionStr(iopt) = value;
  _recompute = true;
  setPreview(this);
  return true;
}

std::string GMSH_CutParametricPlugin::getHelp() const
{
  return "Plugin(CutParametric) cuts the view `View' with "
         "the parametric function (`X'(u,v), `Y'(u,v), `Z'(u,v)), "
         "using `NumPointsU' values of the parameter u in "
         "[`MinU', `MaxU'] and `NumPointsV' values of the parameter v in "
         "[`MinV', `MaxV'].\n\n"
         "If `ConnectPoints' is set, the plugin creates surface or line "
         "elements; otherwise, the plugin generates points.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(CutParametric) creates one new list-based view.";
}

static void addInView(int connect, int i, int nbcomp, int nbtime, double x0,
                      double y0, double z0, double *res0, double x, double y,
                      double z, double *res, std::vector<double> &P, int *nP,
                      std::vector<double> &L, int *nL)
{
  if(connect) {
    if(i) {
      L.push_back(x0);
      L.push_back(x);
      L.push_back(y0);
      L.push_back(y);
      L.push_back(z0);
      L.push_back(z);
      for(int k = 0; k < nbtime; ++k) {
        for(int l = 0; l < nbcomp; ++l) L.push_back(res0[nbcomp * k + l]);
        for(int l = 0; l < nbcomp; ++l) L.push_back(res[nbcomp * k + l]);
      }
      (*nL)++;
    }
  }
  else {
    P.push_back(x);
    P.push_back(y);
    P.push_back(z);
    for(int k = 0; k < nbtime; ++k)
      for(int l = 0; l < nbcomp; ++l) P.push_back(res[nbcomp * k + l]);
    (*nP)++;
  }
}

static void addInView(int nbcomp, int nbtime, double x0, double y0, double z0,
                      double *res0, double x1, double y1, double z1,
                      double *res1, double x2, double y2, double z2,
                      double *res2, double x3, double y3, double z3,
                      double *res3, std::vector<double> &Q, int *nQ)
{
  Q.push_back(x0);
  Q.push_back(x1);
  Q.push_back(x2);
  Q.push_back(x3);
  Q.push_back(y0);
  Q.push_back(y1);
  Q.push_back(y2);
  Q.push_back(y3);
  Q.push_back(z0);
  Q.push_back(z1);
  Q.push_back(z2);
  Q.push_back(z3);
  for(int k = 0; k < nbtime; ++k) {
    for(int l = 0; l < nbcomp; ++l) Q.push_back(res0[nbcomp * k + l]);
    for(int l = 0; l < nbcomp; ++l) Q.push_back(res1[nbcomp * k + l]);
    for(int l = 0; l < nbcomp; ++l) Q.push_back(res2[nbcomp * k + l]);
    for(int l = 0; l < nbcomp; ++l) Q.push_back(res3[nbcomp * k + l]);
  }
  (*nQ)++;
}

PView *GMSH_CutParametricPlugin::execute(PView *v)
{
  int iView = (int)option(7);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  if(!fillXYZ()) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);

  int numSteps = data1->getNumTimeSteps();
  int nbU = (int)option(2);
  int nbV = (int)option(5);
  int connect = (int)option(6);
  if(nbU < 2 && nbV < 2) connect = 0;

  OctreePost o(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  double x0 = 0., y0 = 0., z0 = 0., x1 = 0., y1 = 0., z1 = 0.;

  if(nbU == 1 || nbV == 1 || !connect) {
    // the values at the previous point, for each kind of field
    std::vector<double> prev[3], cur[3];
    for(int f = 0; f < 3; f++) {
      prev[f].resize(9 * numSteps, 0.);
      cur[f].resize(9 * numSteps, 0.);
    }
    for(std::size_t i = 0; i < x.size(); ++i) {
      x1 = x[i];
      y1 = y[i];
      z1 = z[i];
      if(data1->getNumScalars()) {
        o.searchScalar(x1, y1, z1, &cur[0][0]);
        addInView(connect, i, 1, numSteps, x0, y0, z0, &prev[0][0], x1, y1,
                  z1, &cur[0][0], data2->SP, &data2->NbSP, data2->SL,
                  &data2->NbSL);
      }
      if(data1->getNumVectors()) {
        o.searchVector(x1, y1, z1, &cur[1][0]);
        addInView(connect, i, 3, numSteps, x0, y0, z0, &prev[1][0], x1, y1,
                  z1, &cur[1][0], data2->VP, &data2->NbVP, data2->VL,
                  &data2->NbVL);
      }
      if(data1->getNumTensors()) {
        o.searchTensor(x1, y1, z1, &cur[2][0]);
        addInView(connect, i, 9, numSteps, x0, y0, z0, &prev[2][0], x1, y1,
                  z1, &cur[2][0], data2->TP, &data2->NbTP, data2->TL,
                  &data2->NbTL);
      }
      x0 = x1;
      y0 = y1;
      z0 = z1;
      for(int f = 0; f < 3; f++) prev[f].swap(cur[f]);
    }
  }
  else {
    // the values at each point of the grid, searched once and in parallel,
    // then written for each quadrangle it is a corner of
    o.prepareThreads();
    int n = x.size();
    int nthreads = CTX::instance()->numThreadsFor(n, 1000);
    const int numComp[3] = {1, 3, 9};
    std::vector<double> *lists[3] = {&data2->SQ, &data2->VQ, &data2->TQ};
    int *counts[3] = {&data2->NbSQ, &data2->NbVQ, &data2->NbTQ};
    bool has[3] = {data1->getNumScalars() > 0, data1->getNumVectors() > 0,
                   data1->getNumTensors() > 0};
    for(int f = 0; f < 3; f++) {
      if(!has[f]) continue;
      int nc = numComp[f] * numSteps;
      std::vector<double> val(n * nc);
#pragma omp parallel for num_threads(nthreads) schedule(dynamic, 256)
      for(int p = 0; p < n; p++) {
        if(f == 0)
          o.searchScalar(x[p], y[p], z[p], &val[nc * p]);
        else if(f == 1)
          o.searchVector(x[p], y[p], z[p], &val[nc * p]);
        else
          o.searchTensor(x[p], y[p], z[p], &val[nc * p]);
      }
      for(int i = 0; i < nbU - 1; ++i) {
        for(int j = 0; j < nbV - 1; ++j) {
          int q[4] = {i * nbV + j, i * nbV + j + 1, (i + 1) * nbV + j + 1,
                      (i + 1) * nbV + j};
          addInView(numComp[f], numSteps, x[q[0]], y[q[0]], z[q[0]],
                    &val[nc * q[0]], x[q[1]], y[q[1]], z[q[1]], &val[nc * q[1]],
                    x[q[2]], y[q[2]], z[q[2]], &val[nc * q[2]], x[q[3]],
                    y[q[3]], z[q[3]], &val[nc * q[3]], *lists[f], counts[f]);
        }
      }
    }
  }

  for(int i = 0; i < numSteps; i++) data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_CutParametric");
  data2->setFileName(data1->getName() + "_CutParametric.pos");
  data2->finalize();

  return v2;
}
