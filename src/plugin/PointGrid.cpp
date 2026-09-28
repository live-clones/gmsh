// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "PointGrid.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#include "glyphList.h"
#endif

int GMSH_PointGridPlugin::getNbU() { return (int)option(9); }

int GMSH_PointGridPlugin::getNbV() { return (int)option(10); }

void GMSH_PointGridPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  for(int i = 0; i < 3; i++)
    X[i] = option(i) + u * (option(3 + i) - option(i)) +
           v * (option(6 + i) - option(i));
}

bool GMSH_PointGridPlugin::optionCallback(int iopt, int num, int action,
                                          double &value)
{
  double lc = CTX::instance()->lc;
  if(iopt < 9) // coordinates of the 3 points
    return sliderOption(iopt, action, value, lc / 100., -2 * lc, 2 * lc);
  if(iopt == 9 || iopt == 10)
    return sliderOption(iopt, action, value, 1, 1, 100);
  return false;
}

void GMSH_PointGridPlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  drawContext *ctx = (drawContext *)context;
  double p[3];
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
#endif
}
