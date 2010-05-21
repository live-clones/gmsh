// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "OctreePost.h"
#include "CutGrid.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

StringXNumber CutGridOptions_Number[] = {
  {GMSH_FULLRC, "X0", GMSH_CutGridPlugin::callbackX0, 0.},
  {GMSH_FULLRC, "Y0", GMSH_CutGridPlugin::callbackY0, 0.},
  {GMSH_FULLRC, "Z0", GMSH_CutGridPlugin::callbackZ0, 0.},
  {GMSH_FULLRC, "X1", GMSH_CutGridPlugin::callbackX1, 1.},
  {GMSH_FULLRC, "Y1", GMSH_CutGridPlugin::callbackY1, 0.},
  {GMSH_FULLRC, "Z1", GMSH_CutGridPlugin::callbackZ1, 0.},
  {GMSH_FULLRC, "X2", GMSH_CutGridPlugin::callbackX2, 0.},
  {GMSH_FULLRC, "Y2", GMSH_CutGridPlugin::callbackY2, 1.},
  {GMSH_FULLRC, "Z2", GMSH_CutGridPlugin::callbackZ2, 0.},
  {GMSH_FULLRC, "NumPointsU", GMSH_CutGridPlugin::callbackU, 20},
  {GMSH_FULLRC, "NumPointsV", GMSH_CutGridPlugin::callbackV, 20},
  {GMSH_FULLRC, "ConnectPoints", GMSH_CutGridPlugin::callbackConnect, 1},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutGridPlugin()
  {
    return new GMSH_CutGridPlugin();
  }
}

void GMSH_CutGridPlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  double p[3];

  if(CutGridOptions_Number[11].def){
    glBegin(GL_LINES);
    for(int i = 0; i < getNbU(); ++i){
      getPoint(i, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV()-1, p);
      glVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbV(); ++i){
      getPoint(0, i, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, i, p);
      glVertex3d(p[0], p[1], p[2]);
    }
    glEnd();
  }
  else{
    drawContext *ctx = (drawContext*)context;
    for(int i = 0; i < getNbU(); ++i){
      for(int j = 0; j < getNbV(); ++j){
        getPoint(i, j, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
      }
    }
  }
#endif
}

double GMSH_CutGridPlugin::callback(int num, int action, double value, double *opt,
                                    double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
  GMSH_Plugin::setDrawFunction(draw);
  return 0.;
}

double GMSH_CutGridPlugin::callbackX0(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[0].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackY0(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[1].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackZ0(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[2].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackX1(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[3].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackY1(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[4].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc, 
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackZ1(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[5].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc, 
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackX2(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[6].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackY2(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[7].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackZ2(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[8].def,
                  CTX::instance()->lc / 100., -2 * CTX::instance()->lc,
                  2 * CTX::instance()->lc);
}

double GMSH_CutGridPlugin::callbackU(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[9].def,
                  1, 1, 100);
}

double GMSH_CutGridPlugin::callbackV(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[10].def,
                  1, 1, 100);
}

double GMSH_CutGridPlugin::callbackConnect(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[11].def,
                  1, 0, 1);
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
    "Plugin(CutGrid) creates one new view.";
}

int GMSH_CutGridPlugin::getNbOptions() const
{
  return sizeof(CutGridOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutGridPlugin::getOption(int iopt)
{
  return &CutGridOptions_Number[iopt];
}

int GMSH_CutGridPlugin::getNbU()
{
  return (int)CutGridOptions_Number[9].def;
}

int GMSH_CutGridPlugin::getNbV()
{
  return (int)CutGridOptions_Number[10].def;
}

void GMSH_CutGridPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  X[0] = CutGridOptions_Number[0].def + 
    u  * (CutGridOptions_Number[3].def-CutGridOptions_Number[0].def) +
    v  * (CutGridOptions_Number[6].def-CutGridOptions_Number[0].def);
  X[1] = CutGridOptions_Number[1].def + 
    u  * (CutGridOptions_Number[4].def-CutGridOptions_Number[1].def) +
    v  * (CutGridOptions_Number[7].def-CutGridOptions_Number[1].def);
  X[2] = CutGridOptions_Number[2].def + 
    u  * (CutGridOptions_Number[5].def-CutGridOptions_Number[2].def) +
    v  * (CutGridOptions_Number[8].def-CutGridOptions_Number[2].def);
}

void GMSH_CutGridPlugin::addInView(int numsteps, int connect, int nbcomp, 
                                   double ***pnts, double ***vals, 
                                   std::vector<double> &P, int *nP, 
                                   std::vector<double> &L, int *nL, 
                                   std::vector<double> &Q, int *nQ)
{
  if(!connect || (getNbU() == 1 && getNbV() == 1)){ // generate points
    
    for(int i = 0; i < getNbU(); ++i){
      for(int j = 0; j < getNbV(); ++j){
        P.push_back(pnts[i][j][0]);
        P.push_back(pnts[i][j][1]);
        P.push_back(pnts[i][j][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[i][j][nbcomp*k+l]);
        }
      }
    }
    
  }
  else{ // generate lines or quads
    
    if(getNbU() == 1){
      for(int i = 0; i < getNbV()-1; ++i){
        L.push_back(pnts[0][i][0]); L.push_back(pnts[0][i+1][0]);
        L.push_back(pnts[0][i][1]); L.push_back(pnts[0][i+1][1]);
        L.push_back(pnts[0][i][2]); L.push_back(pnts[0][i+1][2]);
        (*nL)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[0][i  ][nbcomp*k+l]);
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[0][i+1][nbcomp*k+l]);
        }
      }
    }
    else if(getNbV() == 1){
      for(int i = 0; i < getNbU()-1; ++i){
        L.push_back(pnts[i][0][0]); L.push_back(pnts[i+1][0][0]);
        L.push_back(pnts[i][0][1]); L.push_back(pnts[i+1][0][1]);
        L.push_back(pnts[i][0][2]); L.push_back(pnts[i+1][0][2]);
        (*nL)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[i  ][0][nbcomp*k+l]);
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[i+1][0][nbcomp*k+l]);
        }
      }
    }
    else{
      for(int i = 0; i < getNbU()-1; ++i){
        for(int j = 0; j < getNbV()-1; ++j){
          Q.push_back(pnts[i  ][j  ][0]); Q.push_back(pnts[i+1][j  ][0]);
          Q.push_back(pnts[i+1][j+1][0]); Q.push_back(pnts[i  ][j+1][0]);
          Q.push_back(pnts[i  ][j  ][1]); Q.push_back(pnts[i+1][j  ][1]);
          Q.push_back(pnts[i+1][j+1][1]); Q.push_back(pnts[i  ][j+1][1]);
          Q.push_back(pnts[i  ][j  ][2]); Q.push_back(pnts[i+1][j  ][2]);
          Q.push_back(pnts[i+1][j+1][2]); Q.push_back(pnts[i  ][j+1][2]);
          (*nQ)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i  ][j  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i+1][j  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i+1][j+1][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              Q.push_back(vals[i  ][j+1][nbcomp*k+l]);
          }
        }
      }
    }
  }     
}

PView *GMSH_CutGridPlugin::GenerateView(PView *v1, int connect)
{
  if(getNbU() <= 0 || getNbV() <= 0)
    return v1;

  PViewData *data1 = v1->getData(true); // get adaptive data if available

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
 
  OctreePost o(v1);

  int nbs = data1->getNumScalars();
  int nbv = data1->getNumVectors();
  int nbt = data1->getNumTensors();
  int maxcomp = nbt ? 9 : (nbv ? 3 : 1);
  int numsteps = data1->getNumTimeSteps();

  double ***pnts = new double** [getNbU()];
  double ***vals = new double** [getNbU()];
  for(int i = 0; i < getNbU(); i++){
    pnts[i] = new double* [getNbV()];
    vals[i] = new double* [getNbV()];
    for(int j = 0; j < getNbV(); j++){
      pnts[i][j] = new double[3];
      vals[i][j] = new double[maxcomp * numsteps];
      getPoint(i, j, pnts[i][j]);
    }
  }
  
  if(nbs){
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        o.searchScalar(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], vals[i][j]);
    addInView(numsteps, connect, 1, pnts, vals, data2->SP, &data2->NbSP, 
              data2->SL, &data2->NbSL, data2->SQ, &data2->NbSQ);
  }

  if(nbv){
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        o.searchVector(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], vals[i][j]);
    addInView(numsteps, connect, 3, pnts, vals, data2->VP, &data2->NbVP,
              data2->VL, &data2->NbVL, data2->VQ, &data2->NbVQ);
  }

  if(nbt){
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        o.searchTensor(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], vals[i][j]);
    addInView(numsteps, connect, 9, pnts, vals, data2->TP, &data2->NbTP, 
              data2->TL, &data2->NbTL, data2->TQ, &data2->NbTQ);
  }

  for(int i = 0; i < getNbU(); i++){
    for(int j = 0; j < getNbV(); j++){
      delete [] pnts[i][j];
      delete [] vals[i][j];
    }
    delete [] pnts[i];
    delete [] vals[i];
  }
  delete [] pnts;
  delete [] vals;

  data2->setName(data1->getName() + "_CutGrid");
  data2->setFileName(data1->getName() + "_CutGrid.pos");
  data2->finalize();

  return v2;
}

PView *GMSH_CutGridPlugin::execute(PView *v)
{
  int connectPoints = (int)CutGridOptions_Number[11].def;
  int iView = (int)CutGridOptions_Number[12].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GenerateView(v1, connectPoints);
}
