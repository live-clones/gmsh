// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "OctreePost.h"
#include "CutBox.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

StringXNumber CutBoxOptions_Number[] = {
  {GMSH_FULLRC, "X0", GMSH_CutBoxPlugin::callbackX0, 0.},
  {GMSH_FULLRC, "Y0", GMSH_CutBoxPlugin::callbackY0, 0.},
  {GMSH_FULLRC, "Z0", GMSH_CutBoxPlugin::callbackZ0, 0.},
  {GMSH_FULLRC, "X1", GMSH_CutBoxPlugin::callbackX1, 1.},
  {GMSH_FULLRC, "Y1", GMSH_CutBoxPlugin::callbackY1, 0.},
  {GMSH_FULLRC, "Z1", GMSH_CutBoxPlugin::callbackZ1, 0.},
  {GMSH_FULLRC, "X2", GMSH_CutBoxPlugin::callbackX2, 0.},
  {GMSH_FULLRC, "Y2", GMSH_CutBoxPlugin::callbackY2, 1.},
  {GMSH_FULLRC, "Z2", GMSH_CutBoxPlugin::callbackZ2, 0.},
  {GMSH_FULLRC, "X3", GMSH_CutBoxPlugin::callbackX3, 0.},
  {GMSH_FULLRC, "Y3", GMSH_CutBoxPlugin::callbackY3, 0.},
  {GMSH_FULLRC, "Z3", GMSH_CutBoxPlugin::callbackZ3, 1.},
  {GMSH_FULLRC, "NumPointsU", GMSH_CutBoxPlugin::callbackU, 20},
  {GMSH_FULLRC, "NumPointsV", GMSH_CutBoxPlugin::callbackV, 20},
  {GMSH_FULLRC, "NumPointsW", GMSH_CutBoxPlugin::callbackW, 20},
  {GMSH_FULLRC, "ConnectPoints", GMSH_CutBoxPlugin::callbackConnect, 1},
  {GMSH_FULLRC, "Boundary", GMSH_CutBoxPlugin::callbackBoundary, 1},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutBoxPlugin()
  {
    return new GMSH_CutBoxPlugin();
  }
}

void GMSH_CutBoxPlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  double p[3];
  drawContext *ctx = (drawContext*)context;

  getPoint(0, 0, 0, p);
  glRasterPos3d(p[0], p[1], p[2]);
  ctx->drawString("(X0, Y0, Z0)");
  if(getNbU() > 1){
    getPoint(getNbU() - 1, 0, 0, p);
    glRasterPos3d(p[0], p[1], p[2]);
    ctx->drawString("(X1, Y1, Z1)");
  }
  if(getNbV() > 1){
    getPoint(0, getNbV() - 1, 0, p);
    glRasterPos3d(p[0], p[1], p[2]);
    ctx->drawString("(X2, Y2, Z2)");
  }
  if(getNbW() > 1){
    getPoint(0, 0, getNbW() - 1, p);
    glRasterPos3d(p[0], p[1], p[2]);
    ctx->drawString("(X3, Y3, Z3)");
  }

  if(CutBoxOptions_Number[15].def){
    glBegin(GL_LINES);
    //UV
    for(int i = 0; i < getNbU(); ++i){
      getPoint(i, 0, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV()-1, 0, p);
      glVertex3d(p[0], p[1], p[2]);

      getPoint(i, 0, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV()-1, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbV(); ++i){
      getPoint(0, i, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, i, 0, p);
      glVertex3d(p[0], p[1], p[2]);

      getPoint(0, i, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, i, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
    }
    // UW
    for(int i = 0; i < getNbU(); ++i){
      getPoint(i, 0, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(i, 0, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
 
      getPoint(i, getNbV()-1, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(i, getNbV()-1, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbW(); ++i){
      getPoint(0, 0, i, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, 0, i, p);
      glVertex3d(p[0], p[1], p[2]); 

      getPoint(0, getNbV()-1, i, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, getNbV()-1, i, p);
      glVertex3d(p[0], p[1], p[2]); 
    }
    // VW
    for(int i = 0; i < getNbV(); ++i){
      getPoint(0, i, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(0, i, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);

      getPoint(getNbU()-1, i, 0, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, i, getNbW()-1, p);
      glVertex3d(p[0], p[1], p[2]);
    }
    for(int i = 0; i < getNbW(); ++i){
      getPoint(0, 0, i, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(0, getNbV()-1, i, p);
      glVertex3d(p[0], p[1], p[2]); 

      getPoint(getNbU()-1, 0, i, p);
      glVertex3d(p[0], p[1], p[2]);
      getPoint(getNbU()-1, getNbV()-1, i, p);
      glVertex3d(p[0], p[1], p[2]); 
    }

    glEnd();
  }
  else{
    for(int i = 0; i < getNbU(); ++i){
      for(int j = 0; j < getNbV(); ++j){
        getPoint(i, j, 0, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
        getPoint(i, j, getNbW()-1, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
      }
    }
    for(int i = 0; i < getNbU(); ++i){
      for(int j = 0; j < getNbW(); ++j){
        getPoint(i, 0, j, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
        getPoint(i, getNbV()-1, j, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
      }
    }
    for(int i = 0; i < getNbV(); ++i){
      for(int j = 0; j < getNbW(); ++j){
        getPoint(0, i, j, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
        getPoint(getNbU()-1, i, j, p);
        ctx->drawSphere(CTX::instance()->pointSize, p[0], p[1], p[2], 1);
      }
    }
  }
#endif
}

double GMSH_CutBoxPlugin::callback(int num, int action, double value, double *opt,
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

double GMSH_CutBoxPlugin::callbackX0(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[0].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[0],
                  CTX::instance()->max[0]);
}

double GMSH_CutBoxPlugin::callbackY0(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[1].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[1],
                  CTX::instance()->max[1]);
}

double GMSH_CutBoxPlugin::callbackZ0(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[2].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[2],
                  CTX::instance()->max[2]);
}

double GMSH_CutBoxPlugin::callbackX1(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[3].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[0],
                  CTX::instance()->max[0]);
}

double GMSH_CutBoxPlugin::callbackY1(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[4].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[1],
                  CTX::instance()->max[1]);
}

double GMSH_CutBoxPlugin::callbackZ1(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[5].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[2],
                  CTX::instance()->max[2]);
}

double GMSH_CutBoxPlugin::callbackX2(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[6].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[0],
                  CTX::instance()->max[0]);
}

double GMSH_CutBoxPlugin::callbackY2(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[7].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[1],
                  CTX::instance()->max[1]);
}

double GMSH_CutBoxPlugin::callbackZ2(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[8].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[2],
                  CTX::instance()->max[2]);
}

double GMSH_CutBoxPlugin::callbackX3(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[9].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[0],
                  CTX::instance()->max[0]);
}

double GMSH_CutBoxPlugin::callbackY3(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[10].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[1],
                  CTX::instance()->max[1]);
}

double GMSH_CutBoxPlugin::callbackZ3(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[11].def,
                  CTX::instance()->lc / 100., CTX::instance()->min[2],
                  CTX::instance()->max[2]);
}

double GMSH_CutBoxPlugin::callbackU(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[12].def,
                  1, 1, 200);
}

double GMSH_CutBoxPlugin::callbackV(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[13].def,
                  1, 1, 200);
}

double GMSH_CutBoxPlugin::callbackW(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[14].def,
                  1, 1, 200);
}


double GMSH_CutBoxPlugin::callbackConnect(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[15].def,
                  1, 0, 1);
}

double GMSH_CutBoxPlugin::callbackBoundary(int num, int action, double value)
{
  return callback(num, action, value, &CutBoxOptions_Number[16].def,
                  1, 0, 1);
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
    "the box; otherwise the plugin interpolates the view at its boundary.\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(CutBox) creates one new view.";
}

int GMSH_CutBoxPlugin::getNbOptions() const
{
  return sizeof(CutBoxOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutBoxPlugin::getOption(int iopt)
{
  return &CutBoxOptions_Number[iopt];
}

int GMSH_CutBoxPlugin::getNbU()
{
  return (int)CutBoxOptions_Number[12].def;
}

int GMSH_CutBoxPlugin::getNbV()
{
  return (int)CutBoxOptions_Number[13].def;
}

int GMSH_CutBoxPlugin::getNbW()
{
  return (int)CutBoxOptions_Number[14].def;
}


void GMSH_CutBoxPlugin::getPoint(int iU, int iV, int iW, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  double w = getNbW() > 1 ? (double)iW / (double)(getNbW() - 1.) : 0.;

  X[0] = CutBoxOptions_Number[0].def + 
    u  * (CutBoxOptions_Number[3].def-CutBoxOptions_Number[0].def) +
    v  * (CutBoxOptions_Number[6].def-CutBoxOptions_Number[0].def) + 
    w  * (CutBoxOptions_Number[9].def-CutBoxOptions_Number[0].def) ;
  X[1] = CutBoxOptions_Number[1].def + 
    u  * (CutBoxOptions_Number[4].def-CutBoxOptions_Number[1].def) +
    v  * (CutBoxOptions_Number[7].def-CutBoxOptions_Number[1].def) +
    w  * (CutBoxOptions_Number[10].def-CutBoxOptions_Number[1].def) ;
  X[2] = CutBoxOptions_Number[2].def + 
    u  * (CutBoxOptions_Number[5].def-CutBoxOptions_Number[2].def) +
    v  * (CutBoxOptions_Number[8].def-CutBoxOptions_Number[2].def) +
    w  * (CutBoxOptions_Number[11].def-CutBoxOptions_Number[2].def) ;
}

void GMSH_CutBoxPlugin::addInView( int connect, int boundary, int numsteps, int nbcomp, 
                                   double ****pnts, double ****vals, 
                                   std::vector<double> &P, int *nP, 
                                   std::vector<double> &L, int *nL, 
                                   std::vector<double> &Q, int *nQ,
                                   std::vector<double> &H, int *nH)
{
  if(!connect || (getNbU() == 1 && getNbV() == 1 && getNbW() == 1)){ // generate points    
    if(!boundary)
      for(int i = 0; i < getNbU(); ++i){
        for(int j = 0; j < getNbV(); ++j){
          for(int m = 0; m < getNbW(); ++m){
            P.push_back(pnts[i][j][m][0]);
            P.push_back(pnts[i][j][m][1]);
            P.push_back(pnts[i][j][m][2]);
            (*nP)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                P.push_back(vals[i][j][m][nbcomp*k+l]);
            }
          }
        }
      }
    else{
      for(int i = 0; i < getNbU(); ++i){
        for(int j = 0; j < getNbV(); ++j){
          P.push_back(pnts[i][j][0][0]);
          P.push_back(pnts[i][j][0][1]);
          P.push_back(pnts[i][j][0][2]);
          (*nP)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              P.push_back(vals[i][j][0][nbcomp*k+l]);
          }
          P.push_back(pnts[i][j][getNbW()-1][0]);
          P.push_back(pnts[i][j][getNbW()-1][1]);
          P.push_back(pnts[i][j][getNbW()-1][2]);
          (*nP)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              P.push_back(vals[i][j][getNbW()-1][nbcomp*k+l]);
          }
        }
      }// end UV planes
      for(int i = 0; i < getNbU(); ++i){
        for(int j = 0; j < getNbW(); ++j){
          P.push_back(pnts[i][0][j][0]);
          P.push_back(pnts[i][0][j][1]);
          P.push_back(pnts[i][0][j][2]);
          (*nP)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              P.push_back(vals[i][0][j][nbcomp*k+l]);
          }
          P.push_back(pnts[i][getNbV()-1][j][0]);
          P.push_back(pnts[i][getNbV()-1][j][1]);
          P.push_back(pnts[i][getNbV()-1][j][2]);
          (*nP)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              P.push_back(vals[i][getNbV()-1][j][nbcomp*k+l]);
          }
        }
      }// end UW planes
      for(int i = 0; i < getNbV(); ++i){
        for(int j = 0; j < getNbW(); ++j){
          P.push_back(pnts[0][i][j][0]);
          P.push_back(pnts[0][i][j][1]);
          P.push_back(pnts[0][i][j][2]);
          (*nP)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              P.push_back(vals[0][i][j][nbcomp*k+l]);
          }
          P.push_back(pnts[getNbU()-1][i][j][0]);
          P.push_back(pnts[getNbU()-1][i][j][1]);
          P.push_back(pnts[getNbU()-1][i][j][2]);
          (*nP)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              P.push_back(vals[getNbU()-1][i][j][nbcomp*k+l]);
          }
        }
      }//end VW planes
    }
  }
  else{ // generate lines or quads
    if ( getNbU() == 1 && getNbV() == 1 ){
      if(!boundary)
        for(int i = 0; i < getNbW()-1; ++i){
          L.push_back(pnts[0][0][i][0]); L.push_back(pnts[0][0][i+1][0]);
          L.push_back(pnts[0][0][i][1]); L.push_back(pnts[0][0][i+1][1]);
          L.push_back(pnts[0][0][i][2]); L.push_back(pnts[0][0][i+1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][0][i  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][0][i+1][nbcomp*k+l]);
          }
        }
      else{
        P.push_back(pnts[0][0][0][0]);
        P.push_back(pnts[0][0][0][1]);
        P.push_back(pnts[0][0][0][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[0][0][0][nbcomp*k+l]);
        }
        P.push_back(pnts[0][0][getNbW()-1][0]);
        P.push_back(pnts[0][0][getNbW()-1][1]);
        P.push_back(pnts[0][0][getNbW()-1][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[0][0][getNbW()-1][nbcomp*k+l]);
        }
      }
    }
    else if (getNbU() == 1 && getNbW() == 1){
      if(!boundary)
        for(int i = 0; i < getNbV()-1; ++i){
          L.push_back(pnts[0][i][0][0]); L.push_back(pnts[0][i+1][0][0]);
          L.push_back(pnts[0][i][0][1]); L.push_back(pnts[0][i+1][0][1]);
          L.push_back(pnts[0][i][0][2]); L.push_back(pnts[0][i+1][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i  ][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i+1][0][nbcomp*k+l]);
          }
        }
      else{
        P.push_back(pnts[0][0][0][0]);
        P.push_back(pnts[0][0][0][1]);
        P.push_back(pnts[0][0][0][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[0][0][0][nbcomp*k+l]);
        }
        P.push_back(pnts[0][getNbV()-1][0][0]);
        P.push_back(pnts[0][getNbV()-1][0][1]);
        P.push_back(pnts[0][getNbV()-1][0][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[0][getNbV()-1][0][nbcomp*k+l]);
        }
      }
    }
    else if (getNbV() == 1 && getNbW() == 1){
      if(!boundary)
      for(int i = 0; i < getNbU()-1; ++i){
        L.push_back(pnts[i][0][0][0]); L.push_back(pnts[i+1][0][0][0]);
        L.push_back(pnts[i][0][0][1]); L.push_back(pnts[i+1][0][0][1]);
        L.push_back(pnts[i][0][0][2]); L.push_back(pnts[i+1][0][0][2]);
        (*nL)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[i  ][0][0][nbcomp*k+l]);
          for(int l = 0; l < nbcomp; ++l)
            L.push_back(vals[i+1][0][0][nbcomp*k+l]);
        }
      }
      else{
        P.push_back(pnts[0][0][0][0]);
        P.push_back(pnts[0][0][0][1]);
        P.push_back(pnts[0][0][0][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[0][0][0][nbcomp*k+l]);
        }
        P.push_back(pnts[getNbU()-1][0][0][0]);
        P.push_back(pnts[getNbU()-1][0][0][1]);
        P.push_back(pnts[getNbU()-1][0][0][2]);
        (*nP)++;
        for(int k = 0; k < numsteps; ++k){
          for(int l = 0; l < nbcomp; ++l)
            P.push_back(vals[getNbU()-1][0][0][nbcomp*k+l]);
        }
      }
    }
    else if(getNbU() == 1){
      if(!boundary)
        for(int i = 0; i < getNbV()-1; ++i){
          for(int j = 0; j < getNbW()-1; ++j){
            Q.push_back(pnts[0][i  ][j  ][0]); Q.push_back(pnts[0][i+1][j  ][0]);
            Q.push_back(pnts[0][i+1][j+1][0]); Q.push_back(pnts[0][i  ][j+1][0]);
            Q.push_back(pnts[0][i  ][j  ][1]); Q.push_back(pnts[0][i+1][j  ][1]);
            Q.push_back(pnts[0][i+1][j+1][1]); Q.push_back(pnts[0][i  ][j+1][1]);
            Q.push_back(pnts[0][i  ][j  ][2]); Q.push_back(pnts[0][i+1][j  ][2]);
            Q.push_back(pnts[0][i+1][j+1][2]); Q.push_back(pnts[0][i  ][j+1][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i  ][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i+1][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i+1][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i  ][j+1][nbcomp*k+l]);
            }
          }
        }
      else{
        for(int i = 0; i < getNbV()-1; ++i){
          L.push_back(pnts[0][i][0][0]); L.push_back(pnts[0][i+1][0][0]);
          L.push_back(pnts[0][i][0][1]); L.push_back(pnts[0][i+1][0][1]);
          L.push_back(pnts[0][i][0][2]); L.push_back(pnts[0][i+1][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i  ][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i+1][0][nbcomp*k+l]);
          }
          L.push_back(pnts[0][i][getNbW()-1][0]); L.push_back(pnts[0][i+1][getNbW()-1][0]);
          L.push_back(pnts[0][i][getNbW()-1][1]); L.push_back(pnts[0][i+1][getNbW()-1][1]);
          L.push_back(pnts[0][i][getNbW()-1][2]); L.push_back(pnts[0][i+1][getNbW()-1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i  ][getNbW()][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i+1][getNbW()][nbcomp*k+l]);
          }
        }
        for(int i = 0; i < getNbW()-1; ++i){
          L.push_back(pnts[0][0][i][0]); L.push_back(pnts[0][0][i+1][0]);
          L.push_back(pnts[0][0][i][1]); L.push_back(pnts[0][0][i+1][1]);
          L.push_back(pnts[0][0][i][2]); L.push_back(pnts[0][0][i+1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][0][i  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][0][i+1][nbcomp*k+l]);
          }
          L.push_back(pnts[0][getNbV()-1][i][0]); L.push_back(pnts[0][getNbV()-1][i+1][0]);
          L.push_back(pnts[0][getNbV()-1][i][1]); L.push_back(pnts[0][getNbV()-1][i+1][1]);
          L.push_back(pnts[0][getNbV()-1][i][2]); L.push_back(pnts[0][getNbV()-1][i+1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][getNbV()-1][i  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][getNbV()-1][i+1][nbcomp*k+l]);
          }
        }
      }
    }
    else if(getNbV() == 1){
      if(!boundary)
        for(int i = 0; i < getNbU()-1; ++i){
          for(int j = 0; j < getNbW()-1; ++j){
            Q.push_back(pnts[i  ][0][j  ][0]); Q.push_back(pnts[i+1][0][j  ][0]);
            Q.push_back(pnts[i+1][0][j+1][0]); Q.push_back(pnts[i  ][0][j+1][0]);
            Q.push_back(pnts[i  ][0][j  ][1]); Q.push_back(pnts[i+1][0][j  ][1]);
            Q.push_back(pnts[i+1][0][j+1][1]); Q.push_back(pnts[i  ][0][j+1][1]);
            Q.push_back(pnts[i  ][0][j  ][2]); Q.push_back(pnts[i+1][0][j  ][2]);
            Q.push_back(pnts[i+1][0][j+1][2]); Q.push_back(pnts[i  ][0][j+1][2]);          
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][0][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][0][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][0][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][0][j+1][nbcomp*k+l]);
            }
          }
        }
      else{
        for(int i = 0; i < getNbU()-1; ++i){
          L.push_back(pnts[i][0][0][0]); L.push_back(pnts[i+1][0][0][0]);
          L.push_back(pnts[i][0][0][1]); L.push_back(pnts[i+1][0][0][1]);
          L.push_back(pnts[i][0][0][2]); L.push_back(pnts[i+1][0][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i  ][0][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i+1][0][0][nbcomp*k+l]);
          }
          L.push_back(pnts[i][0][getNbW()-1][0]); L.push_back(pnts[i+1][0][getNbW()-1][0]);
          L.push_back(pnts[i][0][getNbW()-1][1]); L.push_back(pnts[i+1][0][getNbW()-1][1]);
          L.push_back(pnts[i][0][getNbW()-1][2]); L.push_back(pnts[i+1][0][getNbW()-1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i  ][0][getNbW()-1][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i+1][0][getNbW()-1][nbcomp*k+l]);
          }
        }
        for(int i = 0; i < getNbW()-1; ++i){
          L.push_back(pnts[0][0][i][0]); L.push_back(pnts[0][0][i+1][0]);
          L.push_back(pnts[0][0][i][1]); L.push_back(pnts[0][0][i+1][1]);
          L.push_back(pnts[0][0][i][2]); L.push_back(pnts[0][0][i+1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][0][i  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][0][i+1][nbcomp*k+l]);
          }
          L.push_back(pnts[getNbU()-1][0][i][0]); L.push_back(pnts[getNbU()-1][0][i+1][0]);
          L.push_back(pnts[getNbU()-1][0][i][1]); L.push_back(pnts[getNbU()-1][0][i+1][1]);
          L.push_back(pnts[getNbU()-1][0][i][2]); L.push_back(pnts[getNbU()-1][0][i+1][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[getNbU()-1][0][i  ][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[getNbU()-1][0][i+1][nbcomp*k+l]);
          }
        }
      }
    }
    else if(getNbW() == 1){
      if(!boundary)
        for(int i = 0; i < getNbU()-1; ++i){
          for(int j = 0; j < getNbV()-1; ++j){
            Q.push_back(pnts[i  ][j  ][0][0]); Q.push_back(pnts[i+1][j  ][0][0]);
            Q.push_back(pnts[i+1][j+1][0][0]); Q.push_back(pnts[i  ][j+1][0][0]);
            Q.push_back(pnts[i  ][j  ][0][1]); Q.push_back(pnts[i+1][j  ][0][1]);
            Q.push_back(pnts[i+1][j+1][0][1]); Q.push_back(pnts[i  ][j+1][0][1]);
            Q.push_back(pnts[i  ][j  ][0][2]); Q.push_back(pnts[i+1][j  ][0][2]);
            Q.push_back(pnts[i+1][j+1][0][2]); Q.push_back(pnts[i  ][j+1][0][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][j  ][0][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][j  ][0][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][j+1][0][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][j+1][0][nbcomp*k+l]);
            }  
          }
        }
      else{
        for(int i = 0; i < getNbU()-1; ++i){
          L.push_back(pnts[i][0][0][0]); L.push_back(pnts[i+1][0][0][0]);
          L.push_back(pnts[i][0][0][1]); L.push_back(pnts[i+1][0][0][1]);
          L.push_back(pnts[i][0][0][2]); L.push_back(pnts[i+1][0][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i  ][0][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i+1][0][0][nbcomp*k+l]);
          }
          L.push_back(pnts[i][getNbV()-1][0][0]); L.push_back(pnts[i+1][getNbV()-1][0][0]);
          L.push_back(pnts[i][getNbV()-1][0][1]); L.push_back(pnts[i+1][getNbV()-1][0][1]);
          L.push_back(pnts[i][getNbV()-1][0][2]); L.push_back(pnts[i+1][getNbV()-1][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i  ][getNbV()-1][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[i+1][getNbV()-1][0][nbcomp*k+l]);
          }
        }
        for(int i = 0; i < getNbV()-1; ++i){
          L.push_back(pnts[0][i][0][0]); L.push_back(pnts[0][i+1][0][0]);
          L.push_back(pnts[0][i][0][1]); L.push_back(pnts[0][i+1][0][1]);
          L.push_back(pnts[0][i][0][2]); L.push_back(pnts[0][i+1][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i  ][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[0][i+1][0][nbcomp*k+l]);
          }
          L.push_back(pnts[getNbU()-1][i][0][0]); L.push_back(pnts[getNbU()-1][i+1][0][0]);
          L.push_back(pnts[getNbU()-1][i][0][1]); L.push_back(pnts[getNbU()-1][i+1][0][1]);
          L.push_back(pnts[getNbU()-1][i][0][2]); L.push_back(pnts[getNbU()-1][i+1][0][2]);
          (*nL)++;
          for(int k = 0; k < numsteps; ++k){
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[getNbU()-1][i  ][0][nbcomp*k+l]);
            for(int l = 0; l < nbcomp; ++l)
              L.push_back(vals[getNbU()-1][i+1][0][nbcomp*k+l]);
          }
        }
      }
    }
    // from here, general case
    else{
      if (!boundary){ //Hexaedra in the box
        for(int i = 0; i < getNbU()-1; ++i){
          for(int j = 0; j < getNbV()-1; ++j){
            for(int m = 0; m < getNbW()-1; ++m){
              H.push_back(pnts[i  ][j  ][m  ][0]); H.push_back(pnts[i+1][j  ][m  ][0]);
              H.push_back(pnts[i+1][j+1][m  ][0]); H.push_back(pnts[i  ][j+1][m  ][0]);
              H.push_back(pnts[i  ][j  ][m+1][0]); H.push_back(pnts[i+1][j  ][m+1][0]);
              H.push_back(pnts[i+1][j+1][m+1][0]); H.push_back(pnts[i  ][j+1][m+1][0]);

              H.push_back(pnts[i  ][j  ][m  ][1]); H.push_back(pnts[i+1][j  ][m  ][1]);
              H.push_back(pnts[i+1][j+1][m  ][1]); H.push_back(pnts[i  ][j+1][m  ][1]);
              H.push_back(pnts[i  ][j  ][m+1][1]); H.push_back(pnts[i+1][j  ][m+1][1]);
              H.push_back(pnts[i+1][j+1][m+1][1]); H.push_back(pnts[i  ][j+1][m+1][1]);

              H.push_back(pnts[i  ][j  ][m  ][2]); H.push_back(pnts[i+1][j  ][m  ][2]);
              H.push_back(pnts[i+1][j+1][m  ][2]); H.push_back(pnts[i  ][j+1][m  ][2]);
              H.push_back(pnts[i  ][j  ][m+1][2]); H.push_back(pnts[i+1][j  ][m+1][2]);
              H.push_back(pnts[i+1][j+1][m+1][2]); H.push_back(pnts[i  ][j+1][m+1][2]);
              (*nH)++;

              for(int k = 0; k < numsteps; ++k){
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i  ][j  ][m  ][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i+1][j  ][m  ][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i+1][j+1][m  ][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i  ][j+1][m  ][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i  ][j  ][m+1][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i+1][j  ][m+1][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i+1][j+1][m+1][nbcomp*k+l]);
                for(int l = 0; l < nbcomp; ++l)
                  H.push_back(vals[i  ][j+1][m+1][nbcomp*k+l]);
              }         
            }
          }
        }
      }
      else{//Quadrangles at boundary of the box + forcing exterior normals
        for(int i = 0; i < getNbU()-1; ++i){
          for(int j = 0; j < getNbV()-1; ++j){
            Q.push_back(pnts[i  ][j  ][0][0]); Q.push_back(pnts[i  ][j+1][0][0]);
            Q.push_back(pnts[i+1][j+1][0][0]); Q.push_back(pnts[i+1][j  ][0][0]);
            Q.push_back(pnts[i  ][j  ][0][1]); Q.push_back(pnts[i  ][j+1][0][1]);
            Q.push_back(pnts[i+1][j+1][0][1]); Q.push_back(pnts[i+1][j  ][0][1]);
            Q.push_back(pnts[i  ][j  ][0][2]); Q.push_back(pnts[i  ][j+1][0][2]);
            Q.push_back(pnts[i+1][j+1][0][2]); Q.push_back(pnts[i+1][j  ][0][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][j  ][0][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][j+1][0][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][j+1][0][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][j  ][0][nbcomp*k+l]);
            }          
            Q.push_back(pnts[i  ][j  ][getNbW()-1][0]); Q.push_back(pnts[i+1][j  ][getNbW()-1][0]);
            Q.push_back(pnts[i+1][j+1][getNbW()-1][0]); Q.push_back(pnts[i  ][j+1][getNbW()-1][0]);
            Q.push_back(pnts[i  ][j  ][getNbW()-1][1]); Q.push_back(pnts[i+1][j  ][getNbW()-1][1]);
            Q.push_back(pnts[i+1][j+1][getNbW()-1][1]); Q.push_back(pnts[i  ][j+1][getNbW()-1][1]);
            Q.push_back(pnts[i  ][j  ][getNbW()-1][2]); Q.push_back(pnts[i+1][j  ][getNbW()-1][2]);
            Q.push_back(pnts[i+1][j+1][getNbW()-1][2]); Q.push_back(pnts[i  ][j+1][getNbW()-1][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][j  ][getNbW()-1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][j  ][getNbW()-1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][j+1][getNbW()-1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][j+1][getNbW()-1][nbcomp*k+l]);
            }
          }
        }
        for(int i = 0; i < getNbU()-1; ++i){
          for(int j = 0; j < getNbW()-1; ++j){
            Q.push_back(pnts[i  ][0][j  ][0]); Q.push_back(pnts[i+1][0][j  ][0]);
            Q.push_back(pnts[i+1][0][j+1][0]); Q.push_back(pnts[i  ][0][j+1][0]);
            Q.push_back(pnts[i  ][0][j  ][1]); Q.push_back(pnts[i+1][0][j  ][1]);
            Q.push_back(pnts[i+1][0][j+1][1]); Q.push_back(pnts[i  ][0][j+1][1]);
            Q.push_back(pnts[i  ][0][j  ][2]); Q.push_back(pnts[i+1][0][j  ][2]);
            Q.push_back(pnts[i+1][0][j+1][2]); Q.push_back(pnts[i  ][0][j+1][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][0][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][0][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][0][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][0][j+1][nbcomp*k+l]);
            }          
            Q.push_back(pnts[i  ][getNbV()-1][j  ][0]); Q.push_back(pnts[i  ][getNbV()-1][j+1][0]);
            Q.push_back(pnts[i+1][getNbV()-1][j+1][0]); Q.push_back(pnts[i+1][getNbV()-1][j  ][0]);
            Q.push_back(pnts[i  ][getNbV()-1][j  ][1]); Q.push_back(pnts[i  ][getNbV()-1][j+1][1]);
            Q.push_back(pnts[i+1][getNbV()-1][j+1][1]); Q.push_back(pnts[i+1][getNbV()-1][j  ][1]);
            Q.push_back(pnts[i  ][getNbV()-1][j  ][2]); Q.push_back(pnts[i  ][getNbV()-1][j+1][2]);
            Q.push_back(pnts[i+1][getNbV()-1][j+1][2]); Q.push_back(pnts[i+1][getNbV()-1][j  ][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][getNbV()-1][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i  ][getNbV()-1][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][getNbV()-1][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[i+1][getNbV()-1][j  ][nbcomp*k+l]);
            }
          }
        }
        
        for(int i = 0; i < getNbV()-1; ++i){
          for(int j = 0; j < getNbW()-1; ++j){
            Q.push_back(pnts[0][i  ][j  ][0]); Q.push_back(pnts[0][i  ][j+1][0]);
            Q.push_back(pnts[0][i+1][j+1][0]); Q.push_back(pnts[0][i+1][j  ][0]);
            Q.push_back(pnts[0][i  ][j  ][1]); Q.push_back(pnts[0][i  ][j+1][1]);
            Q.push_back(pnts[0][i+1][j+1][1]); Q.push_back(pnts[0][i+1][j  ][1]);
            Q.push_back(pnts[0][i  ][j  ][2]); Q.push_back(pnts[0][i  ][j+1][2]);
            Q.push_back(pnts[0][i+1][j+1][2]); Q.push_back(pnts[0][i+1][j  ][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i  ][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i  ][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i+1][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[0][i+1][j  ][nbcomp*k+l]);
            }          
            Q.push_back(pnts[getNbU()-1][i  ][j  ][0]); Q.push_back(pnts[getNbU()-1][i+1][j  ][0]);
            Q.push_back(pnts[getNbU()-1][i+1][j+1][0]); Q.push_back(pnts[getNbU()-1][i  ][j+1][0]);
            Q.push_back(pnts[getNbU()-1][i  ][j  ][1]); Q.push_back(pnts[getNbU()-1][i+1][j  ][1]);
            Q.push_back(pnts[getNbU()-1][i+1][j+1][1]); Q.push_back(pnts[getNbU()-1][i  ][j+1][1]);
            Q.push_back(pnts[getNbU()-1][i  ][j  ][2]); Q.push_back(pnts[getNbU()-1][i+1][j  ][2]);
            Q.push_back(pnts[getNbU()-1][i+1][j+1][2]); Q.push_back(pnts[getNbU()-1][i  ][j+1][2]);
            (*nQ)++;
            for(int k = 0; k < numsteps; ++k){
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[getNbU()-1][i  ][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[getNbU()-1][i+1][j  ][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[getNbU()-1][i+1][j+1][nbcomp*k+l]);
              for(int l = 0; l < nbcomp; ++l)
                Q.push_back(vals[getNbU()-1][i  ][j+1][nbcomp*k+l]);
            }
          }
        }        
      }
    }     
  }
}
    
PView *GMSH_CutBoxPlugin::GenerateView(PView *v1, int connect, int boundary)
{
  if(getNbU() <= 0 || getNbV() <= 0 || getNbW() <= 0)
    return v1;

  PViewData *data1 = getPossiblyAdaptiveData(v1);

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
 
  OctreePost o(v1);

  int nbs = data1->getNumScalars();
  int nbv = data1->getNumVectors();
  int nbt = data1->getNumTensors();
  int maxcomp = nbt ? 9 : (nbv ? 3 : 1);
  int numsteps = data1->getNumTimeSteps();
  
  double ****pnts = new double*** [getNbU()];
  double ****vals = new double*** [getNbU()];
  for(int i = 0; i < getNbU(); i++){
    pnts[i] = new double** [getNbV()];
    vals[i] = new double** [getNbV()];
    for(int j = 0; j < getNbV(); j++){
      pnts[i][j] = new double* [getNbW()];
      vals[i][j] = new double* [getNbW()];
      for(int k = 0; k < getNbW(); k++){
        pnts[i][j][k] = new double[3];
        vals[i][j][k] = new double[maxcomp * numsteps];
        getPoint(i, j, k, pnts[i][j][k]);
      }
    }
  }

  if(nbs){
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        for(int k = 0; k < getNbW(); k++)
          o.searchScalar(pnts[i][j][k][0], pnts[i][j][k][1], pnts[i][j][k][2], vals[i][j][k]);
    addInView(connect, boundary, numsteps, 1, pnts, vals, data2->SP, &data2->NbSP, 
              data2->SL, &data2->NbSL, data2->SQ, &data2->NbSQ, data2->SH, &data2->NbSH);
  }
  
  if(nbv){
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        for(int k = 0; k < getNbW(); k++)
          o.searchVector(pnts[i][j][k][0], pnts[i][j][k][1], pnts[i][j][k][2], vals[i][j][k]);
    addInView(connect, boundary, numsteps, 3, pnts, vals, data2->VP, &data2->NbVP,
              data2->VL, &data2->NbVL, data2->VQ, &data2->NbVQ, data2->VH, &data2->NbVH);
  }
  
  if(nbt){
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
        for(int k = 0; k < getNbW(); k++)
          o.searchTensor(pnts[i][j][k][0], pnts[i][j][k][1], pnts[i][j][k][2], vals[i][j][k]);
    addInView(connect, boundary, numsteps, 9, pnts, vals, data2->TP, &data2->NbTP, 
              data2->TL, &data2->NbTL, data2->TQ, &data2->NbTQ, data2->TH, &data2->NbTH);
  }

  for(int i = 0; i < getNbU(); i++){
    for(int j = 0; j < getNbV(); j++){
      for(int k = 0; k < getNbW(); k++){
        delete [] pnts[i][j][k];
        delete [] vals[i][j][k];
      }
      delete [] pnts[i][j];
      delete [] vals[i][j];
    }
    delete [] pnts[i];
    delete [] vals[i];
  }
  delete [] pnts;
  delete [] vals;
  
  data2->setName(data1->getName() + "_CutBox");
  data2->setFileName(data1->getName() + "_CutBox.pos");
  data2->finalize();

  return v2;
}

PView *GMSH_CutBoxPlugin::execute(PView *v)
{
  int connectPoints = (int)CutBoxOptions_Number[15].def;
  int boundary = (int)CutBoxOptions_Number[16].def;
  int iView = (int)CutBoxOptions_Number[17].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GenerateView(v1, connectPoints, boundary);
}
