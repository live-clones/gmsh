// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "GmshConfig.h"
#include "StreamLines.h"
#include "OctreePost.h"
#include "Context.h"
#include "PViewOptions.h"

#if defined(HAVE_FLTK)
#include <FL/gl.h>
#include "drawContext.h"
#include "Draw.h"
#endif

StringXNumber StreamLinesOptions_Number[] = {
  {GMSH_FULLRC, "X0", GMSH_StreamLinesPlugin::callbackX0, 0.},
  {GMSH_FULLRC, "Y0", GMSH_StreamLinesPlugin::callbackY0, 0.},
  {GMSH_FULLRC, "Z0", GMSH_StreamLinesPlugin::callbackZ0, 0.},
  {GMSH_FULLRC, "X1", GMSH_StreamLinesPlugin::callbackX1, 1.},
  {GMSH_FULLRC, "Y1", GMSH_StreamLinesPlugin::callbackY1, 0.},
  {GMSH_FULLRC, "Z1", GMSH_StreamLinesPlugin::callbackZ1, 0.},
  {GMSH_FULLRC, "X2", GMSH_StreamLinesPlugin::callbackX2, 0.},
  {GMSH_FULLRC, "Y2", GMSH_StreamLinesPlugin::callbackY2, 1.},
  {GMSH_FULLRC, "Z2", GMSH_StreamLinesPlugin::callbackZ2, 0.},
  {GMSH_FULLRC, "nPointsU", GMSH_StreamLinesPlugin::callbackU, 10},
  {GMSH_FULLRC, "nPointsV", GMSH_StreamLinesPlugin::callbackV, 1},
  {GMSH_FULLRC, "MaxIter", NULL, 100},
  {GMSH_FULLRC, "DT", NULL, .1},
  {GMSH_FULLRC, "TimeStep", NULL, 0},
  {GMSH_FULLRC, "dView", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterStreamLinesPlugin()
  {
    return new GMSH_StreamLinesPlugin();
  }
}

void GMSH_StreamLinesPlugin::draw(void *context)
{
#if defined(HAVE_FLTK)
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  drawContext *ctx = (drawContext*)context;
  double p[3];
  for(int i = 0; i < getNbU(); ++i){
    for(int j = 0; j < getNbV(); ++j){
      getPoint(i, j, p);
      ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
    }
  }
#endif
}

double GMSH_StreamLinesPlugin::callback(int num, int action, double value, double *opt,
                                        double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return 0.;
}

double GMSH_StreamLinesPlugin::callbackX0(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[0].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackY0(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[1].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackZ0(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[2].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackX1(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[3].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackY1(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[4].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackZ1(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[5].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackX2(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[6].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackY2(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[7].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackZ2(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[8].def,
                  CTX::instance()->lc/100., -2*CTX::instance()->lc, 2*CTX::instance()->lc);
}

double GMSH_StreamLinesPlugin::callbackU(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[9].def,
                  1, 1, 100);
}

double GMSH_StreamLinesPlugin::callbackV(int num, int action, double value)
{
  return callback(num, action, value, &StreamLinesOptions_Number[10].def,
                  1, 1, 100);
}

void GMSH_StreamLinesPlugin::getName(char *name) const
{
  strcpy(name, "Stream Lines");
}

void GMSH_StreamLinesPlugin::getInfos(char *author, char *copyright,
                                      char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(StreamLines) computes stream lines\n"
         "from the `TimeStep'-th time step of a vector\n"
         "view `iView' and optionally interpolates the\n"
         "scalar view `dView' on the resulting stream\n"
         "lines. The plugin takes as input a grid defined\n"
         "by the 3 points (`X0',`Y0',`Z0') (origin),\n"
         "(`X1',`Y1',`Z1') (axis of U) and (`X2',`Y2',`Z2')\n"
         "(axis of V). The number of points that are to\n"
         "be transported along U and V is set with the\n"
         "options `nPointsU' and `nPointsV'. The equation\n"
         "DX(t)/dt=V(x,y,z) is then solved with the initial\n"
         "condition X(t=0) chosen as the grid and with V(x,y,z)\n"
         "interpolated on the vector view. The time stepping\n"
         "scheme is a RK44 with step size `DT' and `MaxIter'\n"
         "maximum number of iterations. If `iView' < 0, the\n"
         "plugin is run on the current view. If `TimeStep' < 0,\n"
         "the plugin tries to compute streamlines of the unsteady\n"
         "flow.\n"
         "\n"
         "Plugin(StreamLines) creates one new view. This\n"
         "view contains multi-step vector points if `dView'\n"
         "< 0, or single-step scalar lines if `dView' >= 0.\n");
}

int GMSH_StreamLinesPlugin::getNbOptions() const
{
  return sizeof(StreamLinesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_StreamLinesPlugin::getOption(int iopt)
{
  return &StreamLinesOptions_Number[iopt];
}

void GMSH_StreamLinesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "StreamLines failed...");
}

int GMSH_StreamLinesPlugin::getNbU()
{
  return (int)StreamLinesOptions_Number[9].def;
}

int GMSH_StreamLinesPlugin::getNbV()
{
  return (int)StreamLinesOptions_Number[10].def;
}

void GMSH_StreamLinesPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  X[0] = StreamLinesOptions_Number[0].def + 
    u  * (StreamLinesOptions_Number[3].def-StreamLinesOptions_Number[0].def) +
    v  * (StreamLinesOptions_Number[6].def-StreamLinesOptions_Number[0].def);
  X[1] = StreamLinesOptions_Number[1].def + 
    u  * (StreamLinesOptions_Number[4].def-StreamLinesOptions_Number[1].def) +
    v  * (StreamLinesOptions_Number[7].def-StreamLinesOptions_Number[1].def);
  X[2] = StreamLinesOptions_Number[2].def + 
    u  * (StreamLinesOptions_Number[5].def-StreamLinesOptions_Number[2].def) +
    v  * (StreamLinesOptions_Number[8].def-StreamLinesOptions_Number[2].def);
}

PView *GMSH_StreamLinesPlugin::execute(PView *v)
{
  int maxIter = (int)StreamLinesOptions_Number[11].def;
  double DT = StreamLinesOptions_Number[12].def;
  int timeStep = (int)StreamLinesOptions_Number[13].def;
  int dView = (int)StreamLinesOptions_Number[14].def;
  int iView = (int)StreamLinesOptions_Number[15].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  PView *v2 = (dView < 0) ? 0 : getView(dView, v);
  PViewData *data2 = v2 ? v2->getData() : 0;

  // sanity checks
  if(timeStep > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in view[%d]", v1->getIndex());
    return v;
  }

  OctreePost o1(v1);
  double *val2 = 0;
  OctreePost *o2 = 0;
  if(data2){
    val2 = new double[data2->getNumTimeSteps()];
    o2 = new OctreePost(v2);
  }

  PView *v3 = new PView(true);
  PViewDataList *data3 = getDataList(v3);

  const double b1 = 1. / 3., b2 = 2. / 3., b3 = 1. / 3., b4 = 1. / 6.;
  const double a1 = 0.5, a2 = 0.5, a3 = 1., a4 = 1.;
  double XINIT[3], X[3], DX[3], X1[3], X2[3], X3[3], X4[3];

  for(int i = 0; i < getNbU(); ++i){
    for(int j = 0; j < getNbV(); ++j){
      getPoint(i, j, XINIT);
      getPoint(i, j, X);
          
      if(data2){
        o2->searchScalar(X[0], X[1], X[2], val2, -1);
      }
      else{
        data3->NbVP++;
        List_Add(data3->VP, &X[0]);
        List_Add(data3->VP, &X[1]);
        List_Add(data3->VP, &X[2]);            
      }

      int currentTimeStep = 0;

      for(int iter = 0; iter < maxIter; iter++){

        double XPREV[3] = {X[0], X[1], X[2]};

        if(timeStep < 0){
          double T0 = data1->getTime(0);
          double currentT = T0 + DT * iter;
          List_Add(data3->Time, &currentT);
          for(; currentTimeStep < data1->getNumTimeSteps() - 1 && 
                currentT > 0.5 * (data1->getTime(currentTimeStep) + 
                                  data1->getTime(currentTimeStep + 1));
              currentTimeStep++);
        }
        else{
          currentTimeStep = timeStep;
        }

        // dX/dt = V
        // X1 = X + a1 * DT * V(X)
        // X2 = X + a2 * DT * V(X1)
        // X3 = X + a3 * DT * V(X2)
        // X4 = X + a4 * DT * V(X3)
        // X = X + b1 X1 + b2 X2 + b3 X3 + b4 x4
	double val[3];
        o1.searchVector(X[0], X[1], X[2], val, currentTimeStep);
        for(int k = 0; k < 3; k++) X1[k] = X[k] + DT * val[k] * a1;
        o1.searchVector(X1[0], X1[1], X1[2], val, currentTimeStep);
        for(int k = 0; k < 3; k++) X2[k] = X[k] + DT * val[k] * a2;
        o1.searchVector(X2[0], X2[1], X2[2], val, currentTimeStep);
        for(int k = 0; k < 3; k++) X3[k] = X[k] + DT * val[k] * a3;
        o1.searchVector(X3[0], X3[1], X3[2], val, currentTimeStep);
        for(int k = 0; k < 3; k++) X4[k] = X[k] + DT * val[k] * a4;

        for(int k = 0; k < 3; k++) 
          X[k] += (b1 * (X1[k] - X[k]) + b2 * (X2[k] - X[k]) + 
                   b3 * (X3[k] - X[k]) + b4 * (X4[k] - X[k]));
        for(int k = 0; k < 3; k++) DX[k] = X[k] - XINIT[k];

        if(data2){
          data3->NbSL++;
          List_Add(data3->SL, &XPREV[0]);
          List_Add(data3->SL, &X[0]);
          List_Add(data3->SL, &XPREV[1]);
          List_Add(data3->SL, &X[1]);
          List_Add(data3->SL, &XPREV[2]);
          List_Add(data3->SL, &X[2]);
          for(int k = 0; k < data2->getNumTimeSteps(); k++)
            List_Add(data3->SL, &val2[k]);
          o2->searchScalar(X[0], X[1], X[2], val2, -1);
          for(int k = 0; k < data2->getNumTimeSteps(); k++)
            List_Add(data3->SL, &val2[k]);
        }
        else{
          List_Add(data3->VP, &DX[0]);
          List_Add(data3->VP, &DX[1]);
          List_Add(data3->VP, &DX[2]);         
        }
      }
    }
  }

  if(data2){
    delete [] val2;
    delete o2;
  }
  else{
    v3->getOptions()->vectorType = PViewOptions::Displacement;
  }

  data3->setName(data1->getName() + "_StreamLines");
  data3->setFileName(data1->getName() + "_StreamLines.pos");
  data3->finalize();

  return v3;
}
