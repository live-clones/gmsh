// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "OctreePost.h"
#include "CutGrid.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#include "glyphList.h"
#endif

GMSH_CutGridPlugin::GMSH_CutGridPlugin()
  : GMSH_PointGridPlugin({{GMSH_FULLRC, "X0", nullptr, 0., ""},
                          {GMSH_FULLRC, "Y0", nullptr, 0., ""},
                          {GMSH_FULLRC, "Z0", nullptr, 0., ""},
                          {GMSH_FULLRC, "X1", nullptr, 1., ""},
                          {GMSH_FULLRC, "Y1", nullptr, 0., ""},
                          {GMSH_FULLRC, "Z1", nullptr, 0., ""},
                          {GMSH_FULLRC, "X2", nullptr, 0., ""},
                          {GMSH_FULLRC, "Y2", nullptr, 1., ""},
                          {GMSH_FULLRC, "Z2", nullptr, 0., ""},
                          {GMSH_FULLRC, "NumPointsU", nullptr, 20, ""},
                          {GMSH_FULLRC, "NumPointsV", nullptr, 20, ""},
                          {GMSH_FULLRC, "ConnectPoints", nullptr, 1, ""},
                          {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

void GMSH_CutGridPlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  double p[3];
  drawContext *ctx = (drawContext *)context;

  getPoint(0, 0, p);
  ctx->drawString("(X0, Y0, Z0)", p[0], p[1], p[2]);
  if(getNbU() > 1) {
    getPoint(getNbU() - 1, 0, p);
    ctx->drawString("(X1, Y1, Z1)", p[0], p[1], p[2]);
  }
  if(getNbV() > 1) {
    getPoint(0, getNbV() - 1, p);
    ctx->drawString("(X2, Y2, Z2)", p[0], p[1], p[2]);
  }

  if(option(11)) {
    gmshBegin(GL_LINES);
    for(int i = 0; i < getNbU(); ++i) {
      getPoint(i, 0, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV() - 1, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbV(); ++i) {
      getPoint(0, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU() - 1, i, p);
      gmshVertex3d(p[0], p[1], p[2]);
    }
    gmshEnd();
  }
  else {
    glyphList g;
    unsigned int col = glyphCurrentColor();
    g.reserve(GLYPH_SPHERE, getNbU() * getNbV());
    for(int i = 0; i < getNbU(); ++i) {
      for(int j = 0; j < getNbV(); ++j) {
        getPoint(i, j, p);
        g.addSphere(ctx, CTX::instance()->pointSize, p[0], p[1], p[2], col);
      }
    }
    g.draw(ctx, 1);
  }
#endif
}

bool GMSH_CutGridPlugin::optionCallback(int iopt, int num, int action,
                                        double &value)
{
  CTX *c = CTX::instance();
  if(iopt < 9) { // coordinates of the 3 points
    int d = iopt % 3;
    return sliderOption(iopt, action, value, c->lc / 100., c->min[d],
                        c->max[d]);
  }
  switch(iopt) {
  case 9:
  case 10: return sliderOption(iopt, action, value, 1, 1, 200);
  case 11: return sliderOption(iopt, action, value, 1, 0, 1);
  default: return false;
  }
}

std::string GMSH_CutGridPlugin::getHelp() const
{
  return "Plugin(CutGrid) cuts the view `View' with a "
         "rectangular grid defined by the 3 points "
         "(`X0',`Y0',`Z0') (origin), (`X1',`Y1',`Z1') (axis of U) "
         "and (`X2',`Y2',`Z2') (axis of V).\n\n"
         "The number of points along U and V is set with the "
         "options `NumPointsU' and `NumPointsV'.\n\n"
         "If `ConnectPoints' is zero, the plugin creates points; "
         "otherwise, the plugin generates quadrangles, lines or "
         "points depending on the values of `NumPointsU' and "
         "`NumPointsV'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(CutGrid) creates one new list-based view.";
}

void GMSH_CutGridPlugin::addInView(int numsteps, int connect, int nbcomp,
                                   double ***pnts, double ***vals,
                                   std::vector<double> &P, int *nP,
                                   std::vector<double> &L, int *nL,
                                   std::vector<double> &Q, int *nQ)
{
  if(!connect || (getNbU() == 1 && getNbV() == 1)) { // generate points

    for(int i = 0; i < getNbU(); ++i) {
      for(int j = 0; j < getNbV(); ++j) {
        P.push_back(pnts[i][j][0]);
        P.push_back(pnts[i][j][1]);
        P.push_back(pnts[i][j][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k) {
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[i][j][nbcomp * k + l]);
        }
      }
    }
  }
  else { // generate lines or quads

    if(getNbU() == 1) {
      for(int i = 0; i < getNbV() - 1; ++i) {
        L.push_back(pnts[0][i][0]);
        L.push_back(pnts[0][i + 1][0]);
        L.push_back(pnts[0][i][1]);
        L.push_back(pnts[0][i + 1][1]);
        L.push_back(pnts[0][i][2]);
        L.push_back(pnts[0][i + 1][2]);
        (*nL)++;
        for(int k = 0; k < numsteps; ++k) {
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[0][i][nbcomp * k + l]);
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[0][i + 1][nbcomp * k + l]);
        }
      }
    }
    else if(getNbV() == 1) {
      for(int i = 0; i < getNbU() - 1; ++i) {
        L.push_back(pnts[i][0][0]);
        L.push_back(pnts[i + 1][0][0]);
        L.push_back(pnts[i][0][1]);
        L.push_back(pnts[i + 1][0][1]);
        L.push_back(pnts[i][0][2]);
        L.push_back(pnts[i + 1][0][2]);
        (*nL)++;
        for(int k = 0; k < numsteps; ++k) {
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[i][0][nbcomp * k + l]);
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[i + 1][0][nbcomp * k + l]);
        }
      }
    }
    else {
      for(int i = 0; i < getNbU() - 1; ++i) {
        for(int j = 0; j < getNbV() - 1; ++j) {
          Q.push_back(pnts[i][j][0]);
          Q.push_back(pnts[i + 1][j][0]);
          Q.push_back(pnts[i + 1][j + 1][0]);
          Q.push_back(pnts[i][j + 1][0]);
          Q.push_back(pnts[i][j][1]);
          Q.push_back(pnts[i + 1][j][1]);
          Q.push_back(pnts[i + 1][j + 1][1]);
          Q.push_back(pnts[i][j + 1][1]);
          Q.push_back(pnts[i][j][2]);
          Q.push_back(pnts[i + 1][j][2]);
          Q.push_back(pnts[i + 1][j + 1][2]);
          Q.push_back(pnts[i][j + 1][2]);
          (*nQ)++;
          for(int k = 0; k < numsteps; ++k) {
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i][j][nbcomp * k + l]);
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i + 1][j][nbcomp * k + l]);
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i + 1][j + 1][nbcomp * k + l]);
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i][j + 1][nbcomp * k + l]);
          }
        }
      }
    }
  }
}

PView *GMSH_CutGridPlugin::GenerateView(PView *v1, int connect)
{
  if(getNbU() <= 0 || getNbV() <= 0) return v1;

  PViewData *data1 = getPossiblyAdaptiveData(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  OctreePost o(v1);

  int nbs = data1->getNumScalars();
  int nbv = data1->getNumVectors();
  int nbt = data1->getNumTensors();
  int maxcomp = nbt ? 9 : (nbv ? 3 : 1);
  int numsteps = data1->getNumTimeSteps();

  double ***pnts = new double **[getNbU()];
  double ***vals = new double **[getNbU()];
  for(int i = 0; i < getNbU(); i++) {
    pnts[i] = new double *[getNbV()];
    vals[i] = new double *[getNbV()];
    for(int j = 0; j < getNbV(); j++) {
      pnts[i][j] = new double[3];
      vals[i][j] = new double[maxcomp * numsteps];
      getPoint(i, j, pnts[i][j]);
    }
  }

  if(nbs) {
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        o.searchScalar(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], vals[i][j]);
    addInView(numsteps, connect, 1, pnts, vals, data2->SP, &data2->NbSP,
              data2->SL, &data2->NbSL, data2->SQ, &data2->NbSQ);
  }

  if(nbv) {
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        o.searchVector(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], vals[i][j]);
    addInView(numsteps, connect, 3, pnts, vals, data2->VP, &data2->NbVP,
              data2->VL, &data2->NbVL, data2->VQ, &data2->NbVQ);
  }

  if(nbt) {
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        o.searchTensor(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], vals[i][j]);
    addInView(numsteps, connect, 9, pnts, vals, data2->TP, &data2->NbTP,
              data2->TL, &data2->NbTL, data2->TQ, &data2->NbTQ);
  }

  for(int i = 0; i < getNbU(); i++) {
    for(int j = 0; j < getNbV(); j++) {
      delete[] pnts[i][j];
      delete[] vals[i][j];
    }
    delete[] pnts[i];
    delete[] vals[i];
  }
  delete[] pnts;
  delete[] vals;

  for(int i = 0; i < numsteps; i++) data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_CutGrid");
  data2->setFileName(data1->getName() + "_CutGrid.pos");
  data2->finalize();

  return v2;
}

PView *GMSH_CutGridPlugin::execute(PView *v)
{
  int connectPoints = (int)option(11);
  int iView = (int)option(12);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GenerateView(v1, connectPoints);
}
