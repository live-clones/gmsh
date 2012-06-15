// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "GmshConfig.h"
#include "OctreePost.h"
#include "CutParametric.h"
#include "Context.h"
#include "mathEvaluator.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

StringXNumber CutParametricOptions_Number[] = {
  {GMSH_FULLRC, "MinU", GMSH_CutParametricPlugin::callbackMinU, 0.},
  {GMSH_FULLRC, "MaxU", GMSH_CutParametricPlugin::callbackMaxU, 2 * 3.1416},
  {GMSH_FULLRC, "NumPointsU", GMSH_CutParametricPlugin::callbackNU, 180.},
  {GMSH_FULLRC, "MinV", GMSH_CutParametricPlugin::callbackMinV, 0.},
  {GMSH_FULLRC, "MaxV", GMSH_CutParametricPlugin::callbackMaxV, 2 * 3.1416},
  {GMSH_FULLRC, "NumPointsV", GMSH_CutParametricPlugin::callbackNV, 180.},
  {GMSH_FULLRC, "ConnectPoints", GMSH_CutParametricPlugin::callbackConnect, 0.},
  {GMSH_FULLRC, "View", NULL, -1.}
};

StringXString CutParametricOptions_String[] = {
  {GMSH_FULLRC, "X", GMSH_CutParametricPlugin::callbackX, "2 * Cos(u) * Sin(v)"},
  {GMSH_FULLRC, "Y", GMSH_CutParametricPlugin::callbackY, "4 * Sin(u) * Sin(v)"},
  {GMSH_FULLRC, "Z", GMSH_CutParametricPlugin::callbackZ, "0.1 + 0.5 * Cos(v)"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutParametricPlugin()
  {
    return new GMSH_CutParametricPlugin();
  }
}

static double getU(int i)
{
  double minU = CutParametricOptions_Number[0].def;
  double maxU = CutParametricOptions_Number[1].def;
  int nbU = (int)CutParametricOptions_Number[2].def;

  if(nbU == 1)
    return minU;
  else
    return minU + (double)(i)/(double)(nbU-1) * (maxU - minU);
}

static double getV(int i)
{
  double minV = CutParametricOptions_Number[3].def;
  double maxV = CutParametricOptions_Number[4].def;
  int nbV = (int)CutParametricOptions_Number[5].def;

  if(nbV == 1)
    return minV;
  else
    return minV + (double)(i)/(double)(nbV-1) * (maxV - minV);
}

int GMSH_CutParametricPlugin::recompute = 1;
std::vector<double> GMSH_CutParametricPlugin::x;
std::vector<double> GMSH_CutParametricPlugin::y;
std::vector<double> GMSH_CutParametricPlugin::z;

int GMSH_CutParametricPlugin::fillXYZ()
{
  std::vector<std::string> expressions(3), variables(2);
  for(int i = 0; i < 3; i++)
    expressions[i] = CutParametricOptions_String[i].def;
  variables[0] = "u";
  variables[1] = "v";
  mathEvaluator f(expressions, variables);
  if(expressions.empty()) return 0;

  int nbU = (int)CutParametricOptions_Number[2].def;
  int nbV = (int)CutParametricOptions_Number[5].def;
  x.resize(nbU * nbV);
  y.resize(nbU * nbV);
  z.resize(nbU * nbV);
  std::vector<double> val(2), res(3);
  for(int i = 0; i < nbU; ++i){
    val[0] = getU(i);
    for(int j = 0; j < nbV; ++j){
      val[1] = getV(j);
      if(f.eval(val, res)){
        x[i * nbV + j] = res[0];
        y[i * nbV + j] = res[1];
        z[i * nbV + j] = res[2];
      }
    }
  }
  return 1;
}

void GMSH_CutParametricPlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  if(recompute){
    fillXYZ();
    recompute = 0;
  }
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  int nbU = CutParametricOptions_Number[2].def;
  int nbV = CutParametricOptions_Number[5].def;
  if(CutParametricOptions_Number[6].def && x.size() > 1){
    if(nbU == 1 || nbV == 1){
      glBegin(GL_LINES);
      for(unsigned int i = 1; i < x.size(); ++i){
        glVertex3d(x[i-1], y[i-1], z[i-1]);
        glVertex3d(x[i], y[i], z[i]);
      }
      glEnd();
    }
    else{
      glBegin(GL_TRIANGLES);
      for(int i = 0; i < nbU - 1; ++i){
        for(int j = 0; j < nbV - 1; ++j){
          int v = i * nbV + j;
          glVertex3d(x[v], y[v], z[v]);
          glVertex3d(x[v+1], y[v+1], z[v+1]);
          glVertex3d(x[v+1+nbV], y[v+1+nbV], z[v+1+nbV]);

          glVertex3d(x[v], y[v], z[v]);
          glVertex3d(x[v+nbV], y[v+nbV], z[v+nbV]);
          glVertex3d(x[v+1+nbV], y[v+1+nbV], z[v+1+nbV]);
        }
      }
      glEnd();
    }
  }
  else{
    drawContext *ctx = (drawContext*)context;
    for(unsigned int i = 0; i < x.size(); ++i)
      ctx->drawSphere(CTX::instance()->pointSize, x[i], y[i], z[i], 1);
  }
#endif
}

double GMSH_CutParametricPlugin::callback(int num, int action, double value, double *opt,
                                          double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
  recompute = 1;
  GMSH_Plugin::setDrawFunction(draw);
  return 0.;
}

std::string GMSH_CutParametricPlugin::callbackStr(int num, int action, std::string value,
                                                  std::string &opt)
{
  opt = value;
  recompute = 1;
  GMSH_Plugin::setDrawFunction(draw);
  return opt;
}

double GMSH_CutParametricPlugin::callbackMinU(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[0].def,
                  0.01, 0., 10.);
}

double GMSH_CutParametricPlugin::callbackMaxU(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[1].def,
                  0.01, 0., 10.);
}

double GMSH_CutParametricPlugin::callbackNU(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[2].def,
                  1, 1, 1000);
}

double GMSH_CutParametricPlugin::callbackMinV(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[3].def,
                  0.01, 0., 10.);
}

double GMSH_CutParametricPlugin::callbackMaxV(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[4].def,
                  0.01, 0., 10.);
}

double GMSH_CutParametricPlugin::callbackNV(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[5].def,
                  1, 1, 1000);
}

double GMSH_CutParametricPlugin::callbackConnect(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[6].def,
                  1, 0, 1);
}

std::string GMSH_CutParametricPlugin::callbackX(int num, int action, std::string value)
{
  return callbackStr(num, action, value, CutParametricOptions_String[0].def);
}

std::string GMSH_CutParametricPlugin::callbackY(int num, int action, std::string value)
{
  return callbackStr(num, action, value, CutParametricOptions_String[1].def);
}

std::string GMSH_CutParametricPlugin::callbackZ(int num, int action, std::string value)
{
  return callbackStr(num, action, value, CutParametricOptions_String[2].def);
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
    "Plugin(CutParametric) creates one new view.";
}

int GMSH_CutParametricPlugin::getNbOptions() const
{
  return sizeof(CutParametricOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutParametricPlugin::getOption(int iopt)
{
  return &CutParametricOptions_Number[iopt];
}

int GMSH_CutParametricPlugin::getNbOptionsStr() const
{
  return sizeof(CutParametricOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_CutParametricPlugin::getOptionStr(int iopt)
{
  return &CutParametricOptions_String[iopt];
}

static void addInView(int connect, int i, int nbcomp, int nbtime,
                      double x0, double y0, double z0, double *res0,
                      double x, double y, double z, double *res,
                      std::vector<double> &P, int *nP,
                      std::vector<double> &L, int *nL)
{
  if(connect){
    if(i){
      L.push_back(x0); L.push_back(x);
      L.push_back(y0); L.push_back(y);
      L.push_back(z0); L.push_back(z);
      for(int k = 0; k < nbtime; ++k){
        for(int l = 0; l < nbcomp; ++l)
          L.push_back(res0[nbcomp * k + l]);
        for(int l = 0; l < nbcomp; ++l)
          L.push_back(res[nbcomp * k + l]);
      }
      (*nL)++;
    }
  }
  else{
    P.push_back(x);
    P.push_back(y);
    P.push_back(z);
    for(int k = 0; k < nbtime; ++k)
      for(int l = 0; l < nbcomp; ++l)
        P.push_back(res[nbcomp * k + l]);
    (*nP)++;
  }
}

static void addInView(int nbcomp, int nbtime,
                      double x0, double y0, double z0, double *res0,
                      double x1, double y1, double z1, double *res1,
                      double x2, double y2, double z2, double *res2,
                      double x3, double y3, double z3, double *res3,
                      std::vector<double> &Q, int *nQ)
{
  Q.push_back(x0); Q.push_back(x1); Q.push_back(x2); Q.push_back(x3);
  Q.push_back(y0); Q.push_back(y1); Q.push_back(y2); Q.push_back(y3);
  Q.push_back(z0); Q.push_back(z1); Q.push_back(z2); Q.push_back(z3);
  for(int k = 0; k < nbtime; ++k){
    for(int l = 0; l < nbcomp; ++l)
      Q.push_back(res0[nbcomp * k + l]);
    for(int l = 0; l < nbcomp; ++l)
      Q.push_back(res1[nbcomp * k + l]);
    for(int l = 0; l < nbcomp; ++l)
      Q.push_back(res2[nbcomp * k + l]);
    for(int l = 0; l < nbcomp; ++l)
      Q.push_back(res3[nbcomp * k + l]);
  }
  (*nQ)++;
}

PView *GMSH_CutParametricPlugin::execute(PView *v)
{
  int iView = (int)CutParametricOptions_Number[7].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  if(!fillXYZ()) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);

  int numSteps = data1->getNumTimeSteps();
  int nbU = (int)CutParametricOptions_Number[2].def;
  int nbV = (int)CutParametricOptions_Number[5].def;
  int connect = (int)CutParametricOptions_Number[6].def;
  if(nbU < 2 && nbV < 2) connect = 0;

  OctreePost o(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  double *res0 = new double[9 * numSteps];
  double *res1 = new double[9 * numSteps];
  double *res2 = new double[9 * numSteps];
  double *res3 = new double[9 * numSteps];
  double x0 = 0., y0 = 0., z0 = 0., x1 = 0., y1 = 0., z1 = 0.;
  double x2 = 0., y2 = 0., z2 = 0., x3 = 0., y3 = 0., z3 = 0.;

  for(int k = 0; k < 9 * numSteps; ++k) res0[k] = res1[k] = 0.;

  if(nbU == 1 || nbV == 1 || !connect){
    for(unsigned int i = 0; i < x.size(); ++i){
      if(i && connect){
        x0 = x1;
        y0 = y1;
        z0 = z1;
        for(int k = 0; k < 9 * numSteps; ++k) res0[k] = res1[k];
      }

      x1 = x[i];
      y1 = y[i];
      z1 = z[i];

      if(data1->getNumScalars()){
        o.searchScalar(x1, y1, z1, res1);
        addInView(connect, i, 1, numSteps, x0, y0, z0, res0, x1, y1, z1, res1,
                  data2->SP, &data2->NbSP, data2->SL, &data2->NbSL);
      }
      if(data1->getNumVectors()){
        o.searchVector(x1, y1, z1, res1);
        addInView(connect, i, 3, numSteps, x0, y0, z0, res0, x1, y1, z1, res1,
                  data2->VP, &data2->NbVP, data2->VL, &data2->NbVL);
      }
      if(data1->getNumTensors()){
        o.searchTensor(x1, y1, z1, res1);
        addInView(connect, i, 9, numSteps, x0, y0, z0, res0, x1, y1, z1, res1,
                  data2->TP, &data2->NbTP, data2->TL, &data2->NbTL);
      }
    }
  }
  else{
    for(int i = 0; i < nbU - 1; ++i){
      for(int j = 0; j < nbV - 1; ++j){
        int v = i * nbV + j;
        x0 = x[v];       y0 = y[v];       z0 = z[v];
        x1 = x[v+1];     y1 = y[v+1];     z1 = z[v+1];
        x2 = x[v+nbV+1]; y2 = y[v+nbV+1]; z2 = z[v+nbV+1];
        x3 = x[v+nbV];   y3 = y[v+nbV];   z3 = z[v+nbV];

        if(data1->getNumScalars()){
          o.searchScalar(x0, y0, z0, res0);
          o.searchScalar(x1, y1, z1, res1);
          o.searchScalar(x2, y2, z2, res2);
          o.searchScalar(x3, y3, z3, res3);
          addInView(1, numSteps, x0, y0, z0, res0, x1, y1, z1, res1,
                    x2, y2, z2, res2, x3, y3, z3, res3,
                    data2->SQ, &data2->NbSQ);
        }
        if(data1->getNumVectors()){
          o.searchVector(x0, y0, z0, res0);
          o.searchVector(x1, y1, z1, res1);
          o.searchVector(x2, y2, z2, res2);
          o.searchVector(x3, y3, z3, res3);
          addInView(3, numSteps, x0, y0, z0, res0, x1, y1, z1, res1,
                    x2, y2, z2, res2, x3, y3, z3, res3,
                    data2->VQ, &data2->NbVQ);
        }
        if(data1->getNumTensors()){
          o.searchTensor(x0, y0, z0, res0);
          o.searchTensor(x1, y1, z1, res1);
          o.searchTensor(x2, y2, z2, res2);
          o.searchTensor(x3, y3, z3, res3);
          addInView(9, numSteps, x0, y0, z0, res0, x1, y1, z1, res1,
                    x2, y2, z2, res2, x3, y3, z3, res3,
                    data2->TQ, &data2->NbTQ);
        }
      }
    }
  }

  delete [] res0;
  delete [] res1;
  delete [] res2;
  delete [] res3;

  data2->setName(data1->getName() + "_CutParametric");
  data2->setFileName(data1->getName() + "_CutParametric.pos");
  data2->finalize();

  return v2;
}
