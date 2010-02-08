// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <vector>
#include "GmshConfig.h"
#include "Annotate.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

StringXNumber AnnotateOptions_Number[] = {
  {GMSH_FULLRC, "X", GMSH_AnnotatePlugin::callbackX, 50.},
  {GMSH_FULLRC, "Y", GMSH_AnnotatePlugin::callbackY, 30.},
  {GMSH_FULLRC, "Z", GMSH_AnnotatePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "ThreeD", GMSH_AnnotatePlugin::callback3D, 0.},
  {GMSH_FULLRC, "FontSize", GMSH_AnnotatePlugin::callbackFontSize, 14.},
  {GMSH_FULLRC, "View", NULL, -1.}
};

StringXString AnnotateOptions_String[] = {
  {GMSH_FULLRC, "Text", GMSH_AnnotatePlugin::callbackText, "My Text"},
  {GMSH_FULLRC, "Font", GMSH_AnnotatePlugin::callbackFont, "Helvetica"},
  {GMSH_FULLRC, "Align", GMSH_AnnotatePlugin::callbackAlign, "Left"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnnotatePlugin()
  {
    return new GMSH_AnnotatePlugin();
  }
}

static double getStyle()
{
  int fontsize = (int)AnnotateOptions_Number[4].def, font = 0, align = 0;
#if defined(HAVE_OPENGL)
  font = drawContext::global()->getFontIndex
    (AnnotateOptions_String[1].def.c_str());
  align = drawContext::global()->getFontAlign
    (AnnotateOptions_String[2].def.c_str());
#endif
  return (double)((align<<16)|(font<<8)|(fontsize));
}

void GMSH_AnnotatePlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  double X = AnnotateOptions_Number[0].def;
  double Y = AnnotateOptions_Number[1].def;
  double Z = AnnotateOptions_Number[2].def;
  double style = getStyle();
  drawContext *ctx = (drawContext*)context;

  glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
  if(AnnotateOptions_Number[3].def){ // 3D
    glRasterPos3d(X, Y, Z);
    ctx->drawString(AnnotateOptions_String[0].def, style);
    // draw 10-pixel marker
    double d = 10 * ctx->pixel_equiv_x / ctx->s[0];
    glBegin(GL_LINES);
    glVertex3d(X-d,Y,Z); glVertex3d(X+d,Y,Z);
    glVertex3d(X,Y-d,Z); glVertex3d(X,Y+d,Z);
    glVertex3d(X,Y,Z-d); glVertex3d(X,Y,Z+d);
    glEnd();
  }
  else{
    double modelview[16], projection[16];
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((double)ctx->viewport[0], (double)ctx->viewport[2],
            (double)ctx->viewport[1], (double)ctx->viewport[3], -1., 1.);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    ctx->fix2dCoordinates(&X, &Y);
    glRasterPos2d(X, Y);
    ctx->drawString(AnnotateOptions_String[0].def, style);
    // draw 10-pixel marker
    glBegin(GL_LINES);
    glVertex2d(X-10,Y); glVertex2d(X+10,Y);
    glVertex2d(X,Y-10); glVertex2d(X,Y+10);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(projection);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(modelview);
  }
#endif
}

double GMSH_AnnotatePlugin::callback(int num, int action, double value, double *opt,
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

std::string GMSH_AnnotatePlugin::callbackStr(int num, int action, std::string value,
                                             std::string &opt)
{
  opt = value;
  GMSH_Plugin::setDrawFunction(draw);
  return opt;
}

double GMSH_AnnotatePlugin::callbackX(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[0].def,
                  dim3 ? CTX::instance()->lc/200. : 0.5, 
                  dim3 ? -CTX::instance()->lc : -100., 
                  dim3 ? CTX::instance()->lc : 100000.);
}

double GMSH_AnnotatePlugin::callbackY(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[1].def,
                  dim3 ? CTX::instance()->lc/200. : 0.5, 
                  dim3 ? -CTX::instance()->lc : -100., 
                  dim3 ? CTX::instance()->lc : 100000.);
}

double GMSH_AnnotatePlugin::callbackZ(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[2].def,
                  dim3 ? CTX::instance()->lc/200. : 0.5, 
                  dim3 ? -CTX::instance()->lc : -100., 
                  dim3 ? CTX::instance()->lc : 100000.);
}

double GMSH_AnnotatePlugin::callback3D(int num, int action, double value)
{
  return callback(num, action, value, &AnnotateOptions_Number[3].def,
                  1, 0, 1);
}

double GMSH_AnnotatePlugin::callbackFontSize(int num, int action, double value)
{
  return callback(num, action, value, &AnnotateOptions_Number[4].def,
                  1, 5, 100);
}

std::string GMSH_AnnotatePlugin::callbackText(int num, int action, std::string value)
{
  return callbackStr(num, action, value, AnnotateOptions_String[0].def);
}

std::string GMSH_AnnotatePlugin::callbackFont(int num, int action, std::string value)
{
  return callbackStr(num, action, value, AnnotateOptions_String[1].def);
}

std::string GMSH_AnnotatePlugin::callbackAlign(int num, int action, std::string value)
{
  return callbackStr(num, action, value, AnnotateOptions_String[2].def);
}

std::string GMSH_AnnotatePlugin::getHelp() const
{
  return "Plugin(Annotate) adds the text string `Text',\n"
         "in font `Font' and size `FontSize', in the view\n"
         "`View'. If `ThreeD' is equal to 1, the plugin inserts\n"
         "the string in model coordinates at the position\n"
         "(`X',`Y',`Z'). If `ThreeD' is equal to 0, the plugin\n"
         "inserts the string in screen coordinates at\n"
         "the position (`X',`Y'). The string is aligned\n"
         "according to `Align'. If `View' < 0, the plugin\n"
         "is run on the current view.\n"
         "\n"
         "Plugin(Annotate) is executed in-place for list-based\n"
         "datasets or creates a new view for other datasets.\n";
}

int GMSH_AnnotatePlugin::getNbOptions() const
{
  return sizeof(AnnotateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnnotatePlugin::getOption(int iopt)
{
  return &AnnotateOptions_Number[iopt];
}

int GMSH_AnnotatePlugin::getNbOptionsStr() const
{
  return sizeof(AnnotateOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_AnnotatePlugin::getOptionStr(int iopt)
{
  return &AnnotateOptions_String[iopt];
}

PView *GMSH_AnnotatePlugin::execute(PView *v)
{
  double X = AnnotateOptions_Number[0].def;
  double Y = AnnotateOptions_Number[1].def;
  double Z = AnnotateOptions_Number[2].def;
  int dim3 = (int)AnnotateOptions_Number[3].def;
  int iView = (int)AnnotateOptions_Number[5].def;
  std::string text = AnnotateOptions_String[0].def;
  double style = getStyle();

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();
  
  PView *v2 = v1;
  PViewDataList *data2 = getDataList(v2, false);
  if(!data2){
    v2 = new PView();
    data2 = getDataList(v2);
  }

  if(dim3){
    data2->T3D.push_back(X);
    data2->T3D.push_back(Y);
    data2->T3D.push_back(Z);
    data2->T3D.push_back(style); 
    data2->T3D.push_back(data2->T3C.size()); 
    for(unsigned int i = 0; i < text.size(); i++) 
      data2->T3C.push_back(text[i]);
    data2->T3C.push_back('\0');
    data2->NbT3++;
  }
  else{
    data2->T2D.push_back(X);
    data2->T2D.push_back(Y);
    data2->T2D.push_back(style); 
    data2->T2D.push_back(data2->T2C.size()); 
    for(unsigned int i = 0; i < text.size(); i++) 
      data2->T2C.push_back(text[i]);
    data2->T2C.push_back('\0');
    data2->NbT2++;
  }

  if(v2 != v1){
    for(int i = 0; i < data1->getNumTimeSteps(); i++)
      data2->Time.push_back(data1->getTime(i));
    data2->setName(data1->getName() + "_Annotate");
    data2->setFileName(data1->getName() + "_Annotate.pos");
  }

  data2->finalize();
  return v2;
}
