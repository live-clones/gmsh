// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <array>
#include <functional>
#include "GmshConfig.h"
#include "OctreePost.h"
#include "CutBox.h"
#include "Context.h"
#include "glyphList.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_CutBoxPlugin::GMSH_CutBoxPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "X0", nullptr, 0., ""},
                     {GMSH_FULLRC, "Y0", nullptr, 0., ""},
                     {GMSH_FULLRC, "Z0", nullptr, 0., ""},
                     {GMSH_FULLRC, "X1", nullptr, 1., ""},
                     {GMSH_FULLRC, "Y1", nullptr, 0., ""},
                     {GMSH_FULLRC, "Z1", nullptr, 0., ""},
                     {GMSH_FULLRC, "X2", nullptr, 0., ""},
                     {GMSH_FULLRC, "Y2", nullptr, 1., ""},
                     {GMSH_FULLRC, "Z2", nullptr, 0., ""},
                     {GMSH_FULLRC, "X3", nullptr, 0., ""},
                     {GMSH_FULLRC, "Y3", nullptr, 0., ""},
                     {GMSH_FULLRC, "Z3", nullptr, 1., ""},
                     {GMSH_FULLRC, "NumPointsU", nullptr, 20, ""},
                     {GMSH_FULLRC, "NumPointsV", nullptr, 20, ""},
                     {GMSH_FULLRC, "NumPointsW", nullptr, 20, ""},
                     {GMSH_FULLRC, "ConnectPoints", nullptr, 1, ""},
                     {GMSH_FULLRC, "Boundary", nullptr, 1, ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

void GMSH_CutBoxPlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  double p[3];
  drawContext *ctx = (drawContext *)context;

  getPoint(0, 0, 0, p);
  ctx->drawString("(X0, Y0, Z0)", p[0], p[1], p[2]);
  if(getNbU() > 1) {
    getPoint(getNbU() - 1, 0, 0, p);
    ctx->drawString("(X1, Y1, Z1)", p[0], p[1], p[2]);
  }
  if(getNbV() > 1) {
    getPoint(0, getNbV() - 1, 0, p);
    ctx->drawString("(X2, Y2, Z2)", p[0], p[1], p[2]);
  }
  if(getNbW() > 1) {
    getPoint(0, 0, getNbW() - 1, p);
    ctx->drawString("(X3, Y3, Z3)", p[0], p[1], p[2]);
  }

  if(option(15)) {
    gmshBegin(GL_LINES);
    // UV
    for(int i = 0; i < getNbU(); ++i) {
      getPoint(i, 0, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV() - 1, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);

      getPoint(i, 0, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV() - 1, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbV(); ++i) {
      getPoint(0, i, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, i, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);

      getPoint(0, i, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, i, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    // UW
    for(int i = 0; i < getNbU(); ++i) {
      getPoint(i, 0, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(i, 0, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);

      getPoint(i, getNbV() - 1, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV() - 1, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbW(); ++i) {
      getPoint(0, 0, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, 0, i, p);
      gmshVertex3d(p[0], p[1], p[2]);

      getPoint(0, getNbV() - 1, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, getNbV() - 1, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    // VW
    for(int i = 0; i < getNbV(); ++i) {
      getPoint(0, i, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(0, i, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);

      getPoint(getNbU() - 1, i, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, i, getNbW() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbW(); ++i) {
      getPoint(0, 0, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(0, getNbV() - 1, i, p);
      gmshVertex3d(p[0], p[1], p[2]);

      getPoint(getNbU() - 1, 0, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, getNbV() - 1, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }

    gmshEnd();
  }
  else {
    glyphList g;
    unsigned int col = glyphCurrentColor();
    double ps = CTX::instance()->pointSize;
    g.reserve(GLYPH_SPHERE, 2 * (getNbU() * getNbV() + getNbU() * getNbW() +
                                 getNbV() * getNbW()));
    for(int i = 0; i < getNbU(); ++i) {
      for(int j = 0; j < getNbV(); ++j) {
        getPoint(i, j, 0, p);
        g.addSphere(ctx, ps, p[0], p[1], p[2], col);
        getPoint(i, j, getNbW() - 1, p);
        g.addSphere(ctx, ps, p[0], p[1], p[2], col);
      }
    }
    for(int i = 0; i < getNbU(); ++i) {
      for(int j = 0; j < getNbW(); ++j) {
        getPoint(i, 0, j, p);
        g.addSphere(ctx, ps, p[0], p[1], p[2], col);
        getPoint(i, getNbV() - 1, j, p);
        g.addSphere(ctx, ps, p[0], p[1], p[2], col);
      }
    }
    for(int i = 0; i < getNbV(); ++i) {
      for(int j = 0; j < getNbW(); ++j) {
        getPoint(0, i, j, p);
        g.addSphere(ctx, ps, p[0], p[1], p[2], col);
        getPoint(getNbU() - 1, i, j, p);
        g.addSphere(ctx, ps, p[0], p[1], p[2], col);
      }
    }
    g.draw(ctx, 1);
  }
#endif
}

bool GMSH_CutBoxPlugin::optionCallback(int iopt, int num, int action,
                                       double &value)
{
  CTX *c = CTX::instance();
  if(iopt < 12) { // coordinates of the 4 points
    int d = iopt % 3;
    return sliderOption(iopt, action, value, c->lc / 100., c->min[d],
                        c->max[d]);
  }
  switch(iopt) {
  case 12:
  case 13:
  case 14: return sliderOption(iopt, action, value, 1, 1, 200);
  case 15:
  case 16: return sliderOption(iopt, action, value, 1, 0, 1);
  default: return false;
  }
}

std::string GMSH_CutBoxPlugin::getHelp() const
{
  return "Plugin(CutBox) cuts the view `View' with a "
         "rectangular box defined by the 4 points "
         "(`X0',`Y0',`Z0') (origin), (`X1',`Y1',`Z1') (axis of U), "
         "(`X2',`Y2',`Z2') (axis of V) and (`X3',`Y3',`Z3') (axis of W).\n\n"
         "The number of points along U, V, W is set with the "
         "options `NumPointsU', `NumPointsV' and `NumPointsW'.\n\n"
         "If `ConnectPoints' is zero, the plugin creates points; "
         "otherwise, the plugin generates hexahedra, quadrangles, lines or "
         "points depending on the values of `NumPointsU', "
         "`NumPointsV' and `NumPointsW'.\n\n"
         "If `Boundary' is zero, the plugin interpolates the view inside "
         "the box; otherwise the plugin interpolates the view at its "
         "boundary.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(CutBox) creates one new list-based view.";
}

int GMSH_CutBoxPlugin::getNbU() { return (int)option(12); }

int GMSH_CutBoxPlugin::getNbV() { return (int)option(13); }

int GMSH_CutBoxPlugin::getNbW() { return (int)option(14); }

void GMSH_CutBoxPlugin::getPoint(int iU, int iV, int iW, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  double w = getNbW() > 1 ? (double)iW / (double)(getNbW() - 1.) : 0.;

  X[0] = option(0) + u * (option(3) - option(0)) + v * (option(6) - option(0)) +
         w * (option(9) - option(0));
  X[1] = option(1) + u * (option(4) - option(1)) + v * (option(7) - option(1)) +
         w * (option(10) - option(1));
  X[2] = option(2) + u * (option(5) - option(2)) + v * (option(8) - option(2)) +
         w * (option(11) - option(2));
}

void GMSH_CutBoxPlugin::addInView(int connect, int boundary, int numsteps,
                                  int nbcomp, double ****pnts, double ****vals,
                                  std::vector<double> &P, int *nP,
                                  std::vector<double> &L, int *nL,
                                  std::vector<double> &Q, int *nQ,
                                  std::vector<double> &H, int *nH)
{
  typedef std::array<int, 3> ijk;
  // an element on the grid points p: all the x, the y, the z, then the values
  // of each step, node after node
  auto add = [&](std::vector<double> &list, int *n,
                 const std::vector<ijk> &p) {
    for(int c = 0; c < 3; c++)
      for(auto &q : p) list.push_back(pnts[q[0]][q[1]][q[2]][c]);
    for(int k = 0; k < numsteps; ++k)
      for(auto &q : p)
        for(int l = 0; l < nbcomp; ++l)
          list.push_back(vals[q[0]][q[1]][q[2]][nbcomp * k + l]);
    (*n)++;
  };
  int nu = getNbU(), nv = getNbV(), nw = getNbW();
  int u = nu - 1, v = nv - 1, w = nw - 1; // the last points

  if(!connect || (nu == 1 && nv == 1 && nw == 1)) { // points
    if(!boundary) {
      for(int i = 0; i < nu; ++i)
        for(int j = 0; j < nv; ++j)
          for(int m = 0; m < nw; ++m) add(P, nP, {{i, j, m}});
      return;
    }
    for(int i = 0; i < nu; ++i) {
      for(int j = 0; j < nv; ++j) {
        add(P, nP, {{i, j, 0}});
        add(P, nP, {{i, j, w}});
      }
    }
    for(int i = 0; i < nu; ++i) {
      for(int j = 0; j < nw; ++j) {
        add(P, nP, {{i, 0, j}});
        add(P, nP, {{i, v, j}});
      }
    }
    for(int i = 0; i < nv; ++i) {
      for(int j = 0; j < nw; ++j) {
        add(P, nP, {{0, i, j}});
        add(P, nP, {{u, i, j}});
      }
    }
    return;
  }

  // a line of points along one direction: lines, or its 2 ends
  auto line = [&](int n, const std::function<ijk(int)> &q) {
    if(!boundary)
      for(int i = 0; i < n - 1; ++i) add(L, nL, {q(i), q(i + 1)});
    else {
      add(P, nP, {q(0)});
      add(P, nP, {q(n - 1)});
    }
  };
  if(nu == 1 && nv == 1) return line(nw, [](int i) { return ijk{0, 0, i}; });
  if(nu == 1 && nw == 1) return line(nv, [](int i) { return ijk{0, i, 0}; });
  if(nv == 1 && nw == 1) return line(nu, [](int i) { return ijk{i, 0, 0}; });

  // a plane of points along two directions (a, b): quadrangles, or the lines
  // of its boundary
  auto plane = [&](int na, int nb, const std::function<ijk(int, int)> &q) {
    if(!boundary) {
      for(int i = 0; i < na - 1; ++i)
        for(int j = 0; j < nb - 1; ++j)
          add(Q, nQ, {q(i, j), q(i + 1, j), q(i + 1, j + 1), q(i, j + 1)});
      return;
    }
    for(int i = 0; i < na - 1; ++i) {
      add(L, nL, {q(i, 0), q(i + 1, 0)});
      add(L, nL, {q(i, nb - 1), q(i + 1, nb - 1)});
    }
    for(int i = 0; i < nb - 1; ++i) {
      add(L, nL, {q(0, i), q(0, i + 1)});
      add(L, nL, {q(na - 1, i), q(na - 1, i + 1)});
    }
  };
  if(nu == 1) return plane(nv, nw, [](int i, int j) { return ijk{0, i, j}; });
  if(nv == 1) return plane(nu, nw, [](int i, int j) { return ijk{i, 0, j}; });
  if(nw == 1) return plane(nu, nv, [](int i, int j) { return ijk{i, j, 0}; });

  if(!boundary) { // hexahedra in the box
    for(int i = 0; i < u; ++i)
      for(int j = 0; j < v; ++j)
        for(int m = 0; m < w; ++m)
          add(H, nH,
              {{i, j, m}, {i + 1, j, m}, {i + 1, j + 1, m}, {i, j + 1, m},
               {i, j, m + 1}, {i + 1, j, m + 1}, {i + 1, j + 1, m + 1},
               {i, j + 1, m + 1}});
    return;
  }
  // quadrangles on the boundary of the box, with exterior normals
  for(int i = 0; i < u; ++i) {
    for(int j = 0; j < v; ++j) {
      add(Q, nQ, {{i, j, 0}, {i, j + 1, 0}, {i + 1, j + 1, 0}, {i + 1, j, 0}});
      add(Q, nQ, {{i, j, w}, {i + 1, j, w}, {i + 1, j + 1, w}, {i, j + 1, w}});
    }
  }
  for(int i = 0; i < u; ++i) {
    for(int j = 0; j < w; ++j) {
      add(Q, nQ, {{i, 0, j}, {i + 1, 0, j}, {i + 1, 0, j + 1}, {i, 0, j + 1}});
      add(Q, nQ, {{i, v, j}, {i, v, j + 1}, {i + 1, v, j + 1}, {i + 1, v, j}});
    }
  }
  for(int i = 0; i < v; ++i) {
    for(int j = 0; j < w; ++j) {
      add(Q, nQ, {{0, i, j}, {0, i, j + 1}, {0, i + 1, j + 1}, {0, i + 1, j}});
      add(Q, nQ, {{u, i, j}, {u, i + 1, j}, {u, i + 1, j + 1}, {u, i, j + 1}});
    }
  }
}

PView *GMSH_CutBoxPlugin::GenerateView(PView *v1, int connect, int boundary)
{
  if(getNbU() <= 0 || getNbV() <= 0 || getNbW() <= 0) return v1;

  PViewData *data1 = getPossiblyAdaptiveData(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  OctreePost o(v1);

  int nbs = data1->getNumScalars();
  int nbv = data1->getNumVectors();
  int nbt = data1->getNumTensors();
  int maxcomp = nbt ? 9 : (nbv ? 3 : 1);
  int numsteps = data1->getNumTimeSteps();

  double ****pnts = new double ***[getNbU()];
  double ****vals = new double ***[getNbU()];
  for(int i = 0; i < getNbU(); i++) {
    pnts[i] = new double **[getNbV()];
    vals[i] = new double **[getNbV()];
    for(int j = 0; j < getNbV(); j++) {
      pnts[i][j] = new double *[getNbW()];
      vals[i][j] = new double *[getNbW()];
      for(int k = 0; k < getNbW(); k++) {
        pnts[i][j][k] = new double[3];
        vals[i][j][k] = new double[maxcomp * numsteps];
        getPoint(i, j, k, pnts[i][j][k]);
      }
    }
  }

  // the values at the points: only those on the boundary of the grid are
  // used with Boundary; searched in parallel
  int nu = getNbU(), nv = getNbV(), nw = getNbW();
  auto search = [&](int numComp) {
    o.prepareThreads();
    int n = nu * nv * nw;
    int nthreads = CTX::instance()->numThreadsFor(n, 1000);
#pragma omp parallel for num_threads(nthreads) schedule(dynamic, 256)
    for(int p = 0; p < n; p++) {
      int i = p / (nv * nw), j = (p / nw) % nv, k = p % nw;
      if(boundary && i > 0 && i < nu - 1 && j > 0 && j < nv - 1 && k > 0 &&
         k < nw - 1)
        continue;
      double *x = pnts[i][j][k], *val = vals[i][j][k];
      if(numComp == 1)
        o.searchScalar(x[0], x[1], x[2], val);
      else if(numComp == 3)
        o.searchVector(x[0], x[1], x[2], val);
      else
        o.searchTensor(x[0], x[1], x[2], val);
    }
  };
  if(nbs) {
    search(1);
    addInView(connect, boundary, numsteps, 1, pnts, vals, data2->SP,
              &data2->NbSP, data2->SL, &data2->NbSL, data2->SQ, &data2->NbSQ,
              data2->SH, &data2->NbSH);
  }
  if(nbv) {
    search(3);
    addInView(connect, boundary, numsteps, 3, pnts, vals, data2->VP,
              &data2->NbVP, data2->VL, &data2->NbVL, data2->VQ, &data2->NbVQ,
              data2->VH, &data2->NbVH);
  }
  if(nbt) {
    search(9);
    addInView(connect, boundary, numsteps, 9, pnts, vals, data2->TP,
              &data2->NbTP, data2->TL, &data2->NbTL, data2->TQ, &data2->NbTQ,
              data2->TH, &data2->NbTH);
  }

  for(int i = 0; i < getNbU(); i++) {
    for(int j = 0; j < getNbV(); j++) {
      for(int k = 0; k < getNbW(); k++) {
        delete[] pnts[i][j][k];
        delete[] vals[i][j][k];
      }
      delete[] pnts[i][j];
      delete[] vals[i][j];
    }
    delete[] pnts[i];
    delete[] vals[i];
  }
  delete[] pnts;
  delete[] vals;

  for(int i = 0; i < numsteps; i++) data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_CutBox");
  data2->setFileName(data1->getName() + "_CutBox.pos");
  data2->finalize();

  return v2;
}

PView *GMSH_CutBoxPlugin::execute(PView *v)
{
  int connectPoints = (int)option(15);
  int boundary = (int)option(16);
  int iView = (int)option(17);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GenerateView(v1, connectPoints, boundary);
}
