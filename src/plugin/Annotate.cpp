// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshConfig.h"
#include "Annotate.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#include "glMatrix.h"
#endif

GMSH_AnnotatePlugin::GMSH_AnnotatePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "X", nullptr, 50., ""},
                     {GMSH_FULLRC, "Y", nullptr, 30., ""},
                     {GMSH_FULLRC, "Z", nullptr, 0., ""},
                     {GMSH_FULLRC, "ThreeD", nullptr, 0., ""},
                     {GMSH_FULLRC, "FontSize", nullptr, 14., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}},
                    {{GMSH_FULLRC, "Text", nullptr, "My Text", ""},
                     {GMSH_FULLRC, "Font", nullptr, "Helvetica", ""},
                     {GMSH_FULLRC, "Align", nullptr, "Left", ""}})
{
}

double GMSH_AnnotatePlugin::getStyle()
{
  int fontsize = (int)option(4), font = 0, align = 0;
#if defined(HAVE_OPENGL)
  font = drawContext::global()->getFontIndex(optionStr(1).c_str());
  align = drawContext::global()->getFontAlign(optionStr(2).c_str());
#endif
  return (double)((align << 16) | (font << 8) | (fontsize));
}

void GMSH_AnnotatePlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  double X = option(0);
  double Y = option(1);
  double Z = option(2);
  double style = getStyle();
  drawContext *ctx = (drawContext *)context;

  gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  if(option(3)) { // 3D
    ctx->drawString(optionStr(0), X, Y, Z, style);
    // draw 10-pixel marker
    double d = 10 * ctx->pixel_equiv_x / ctx->s[0];
    gmshBegin(GL_LINES);
    gmshVertex3d(X - d, Y, Z);
    gmshVertex3d(X + d, Y, Z);
    gmshVertex3d(X, Y - d, Z);
    gmshVertex3d(X, Y + d, Z);
    gmshVertex3d(X, Y, Z - d);
    gmshVertex3d(X, Y, Z + d);
    gmshEnd();
  }
  else {
    // the matrices are ours, not OpenGL's: a core profile has none to ask for
    double modelview[16], projection[16], px[16];
    for(int i = 0; i < 16; i++) {
      projection[i] = glImmediate::matrix(GMSH_PROJECTION)[i];
      modelview[i] = glImmediate::matrix(GMSH_MODELVIEW)[i];
    }
    gmshMatrixMode(GMSH_PROJECTION);
    glMatrix::ortho(ctx->viewport[0], ctx->viewport[2], ctx->viewport[1],
                    ctx->viewport[3], -1., 1., px);
    gmshLoadMatrix(px);
    gmshMatrixMode(GMSH_MODELVIEW);
    gmshLoadIdentity();
    ctx->fix2dCoordinates(&X, &Y);
    ctx->drawString(optionStr(0), X, Y, 0., style);
    // draw 10-pixel marker
    gmshBegin(GL_LINES);
    gmshVertex2d(X - 10, Y);
    gmshVertex2d(X + 10, Y);
    gmshVertex2d(X, Y - 10);
    gmshVertex2d(X, Y + 10);
    gmshEnd();

    gmshMatrixMode(GMSH_PROJECTION);
    gmshLoadMatrix(projection);
    gmshMatrixMode(GMSH_MODELVIEW);
    gmshLoadMatrix(modelview);
  }
#endif
}

bool GMSH_AnnotatePlugin::optionCallback(int iopt, int num, int action,
                                         double &value)
{
  double lc = CTX::instance()->lc;
  if(iopt < 3) { // the position, in model or screen coordinates
    // not perfect: the change will only take place if we reopen the dialog...
    if(option(3)) return sliderOption(iopt, action, value, lc / 200., -lc, lc);
    return sliderOption(iopt, action, value, 0.5, -100., 100000.);
  }
  switch(iopt) {
  case 3: return sliderOption(iopt, action, value, 1, 0, 1);
  case 4: return sliderOption(iopt, action, value, 1, 5, 100);
  default: return false;
  }
}

bool GMSH_AnnotatePlugin::optionStrCallback(int iopt, int num, int action,
                                            std::string &value)
{
  optionStr(iopt) = value;
  setPreview(this);
  return true;
}

std::string GMSH_AnnotatePlugin::getHelp() const
{
  return "Plugin(Annotate) adds the text string `Text', "
         "in font `Font' and size `FontSize', in the view "
         "`View'. The string is aligned according to `Align'.\n\n"
         "If `ThreeD' is equal to 1, the plugin inserts "
         "the string in model coordinates at the position "
         "(`X',`Y',`Z'). If `ThreeD' is equal to 0, the plugin "
         "inserts the string in screen coordinates at "
         "the position (`X',`Y').\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Annotate) is executed in-place for list-based "
         "datasets or creates a new list-based view for other datasets.";
}

PView *GMSH_AnnotatePlugin::execute(PView *v)
{
  double X = option(0);
  double Y = option(1);
  double Z = option(2);
  int dim3 = (int)option(3);
  int iView = (int)option(5);
  std::string text = optionStr(0);
  double style = getStyle();

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  PView *v2 = v1;
  PViewDataList *data2 = getDataList(v2, false);
  if(!data2) {
    v2 = new PView();
    data2 = getDataList(v2);
  }

  if(dim3)
    data2->addString3D(X, Y, Z, style, {text});
  else
    data2->addString2D(X, Y, style, {text});

  if(v2 != v1) {
    for(int i = 0; i < data1->getNumTimeSteps(); i++)
      data2->addTime(data1->getTime(i));
    data2->setName(data1->getName() + "_Annotate");
    data2->setFileName(data1->getName() + "_Annotate.pos");
  }

  data2->finalize();
  return v2;
}
