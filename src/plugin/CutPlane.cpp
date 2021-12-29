// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "CutPlane.h"
#include "Context.h"
#include "fullMatrix.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

int GMSH_CutPlanePlugin::iview = 0;

StringXNumber CutPlaneOptions_Number[] = {
  {GMSH_FULLRC, "A", GMSH_CutPlanePlugin::callbackA, 1.},
  {GMSH_FULLRC, "B", GMSH_CutPlanePlugin::callbackB, 0.},
  {GMSH_FULLRC, "C", GMSH_CutPlanePlugin::callbackC, 0.},
  {GMSH_FULLRC, "D", GMSH_CutPlanePlugin::callbackD, -0.01},
  {GMSH_FULLRC, "ExtractVolume", GMSH_CutPlanePlugin::callbackVol, 0},
  {GMSH_FULLRC, "RecurLevel", GMSH_CutPlanePlugin::callbackRecur, 3},
  {GMSH_FULLRC, "TargetError", GMSH_CutPlanePlugin::callbackTarget, 1e-4},
  {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterCutPlanePlugin() { return new GMSH_CutPlanePlugin(); }
}

void GMSH_CutPlanePlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  int num = (int)CutPlaneOptions_Number[7].def;
  drawContext *ctx = (drawContext *)context;
  if(num < 0) num = iview;
  if(num >= 0 && num < (int)PView::list.size()) {
    glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
    glLineWidth((float)CTX::instance()->lineWidth);
    SBoundingBox3d bb = PView::list[num]->getData()->getBoundingBox();
    ctx->drawPlaneInBoundingBox(
      bb.min().x(), bb.min().y(), bb.min().z(), bb.max().x(), bb.max().y(),
      bb.max().z(), CutPlaneOptions_Number[0].def,
      CutPlaneOptions_Number[1].def, CutPlaneOptions_Number[2].def,
      CutPlaneOptions_Number[3].def);
  }
#endif
}

double GMSH_CutPlanePlugin::callback(int num, int action, double value,
                                     double *opt, double step, double min,
                                     double max)
{
  if(action > 0) iview = num;
  switch(action) { // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
  GMSH_Plugin::setDrawFunction(draw);
  return 0.;
}

double GMSH_CutPlanePlugin::callbackA(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[0].def, 0.01, -1,
                  1);
}

double GMSH_CutPlanePlugin::callbackB(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[1].def, 0.01, -1,
                  1);
}

double GMSH_CutPlanePlugin::callbackC(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[2].def, 0.01, -1,
                  1);
}

double GMSH_CutPlanePlugin::callbackD(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[3].def,
                  CTX::instance()->lc / 200., -CTX::instance()->lc,
                  CTX::instance()->lc);
}

double GMSH_CutPlanePlugin::callbackVol(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[4].def, 1., -1,
                  1);
}

double GMSH_CutPlanePlugin::callbackRecur(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[5].def, 1, 0, 10);
}

double GMSH_CutPlanePlugin::callbackTarget(int num, int action, double value)
{
  return callback(num, action, value, &CutPlaneOptions_Number[6].def, 0.01, 0.,
                  1.);
}

std::string GMSH_CutPlanePlugin::getHelp() const
{
  return "Plugin(CutPlane) cuts the view `View' with "
         "the plane `A'*X + `B'*Y + `C'*Z + `D' = 0.\n\n"
         "If `ExtractVolume' is nonzero, the plugin extracts "
         "the elements on one side of the plane (depending "
         "on the sign of `ExtractVolume').\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(CutPlane) creates one new list-based view.";
}

int GMSH_CutPlanePlugin::getNbOptions() const
{
  return sizeof(CutPlaneOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutPlanePlugin::getOption(int iopt)
{
  return &CutPlaneOptions_Number[iopt];
}

double GMSH_CutPlanePlugin::levelset(double x, double y, double z,
                                     double val) const
{
  return CutPlaneOptions_Number[0].def * x + CutPlaneOptions_Number[1].def * y +
         CutPlaneOptions_Number[2].def * z + CutPlaneOptions_Number[3].def;
}

bool GMSH_CutPlanePlugin::geometricalFilter(
  fullMatrix<double> *node_positions) const
{
  const double l0 = levelset((*node_positions)(0, 0), (*node_positions)(0, 1),
                             (*node_positions)(0, 2), 1);
  for(int i = 1; i < node_positions->size1(); i++)
    if(levelset((*node_positions)(i, 0), (*node_positions)(i, 1),
                (*node_positions)(i, 2), 1) *
         l0 <
       0)
      return true;
  return false;
}

PView *GMSH_CutPlanePlugin::execute(PView *v)
{
  int iView = (int)CutPlaneOptions_Number[7].def;
  _ref[0] = CutPlaneOptions_Number[0].def;
  _ref[1] = CutPlaneOptions_Number[1].def;
  _ref[2] = CutPlaneOptions_Number[2].def;
  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::PLANE;
  _extractVolume = (int)CutPlaneOptions_Number[4].def;
  _recurLevel = (int)CutPlaneOptions_Number[5].def;
  _targetError = CutPlaneOptions_Number[6].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  return GMSH_LevelsetPlugin::execute(v1);
}
