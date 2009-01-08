// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <vector>
#include "GmshConfig.h"
#include "Annotate.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include <FL/gl.h>
#include "drawContext.h"
#include "Draw.h"
#include "GUI.h"
#endif

extern Context_T CTX;

StringXNumber AnnotateOptions_Number[] = {
  {GMSH_FULLRC, "X", GMSH_AnnotatePlugin::callbackX, 50.},
  {GMSH_FULLRC, "Y", GMSH_AnnotatePlugin::callbackY, 30.},
  {GMSH_FULLRC, "Z", GMSH_AnnotatePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "ThereD", GMSH_AnnotatePlugin::callback3D, 0.},
  {GMSH_FULLRC, "FontSize", GMSH_AnnotatePlugin::callbackFontSize, 14.},
  {GMSH_FULLRC, "iView", NULL, -1.}
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
#if defined(HAVE_FLTK)
  font = GetFontIndex(AnnotateOptions_String[1].def);
  align = GetFontAlign(AnnotateOptions_String[2].def);
#endif
  return (double)((align<<16)|(font<<8)|(fontsize));
}

void GMSH_AnnotatePlugin::draw(void *context)
{
#if defined(HAVE_FLTK)
  double X = AnnotateOptions_Number[0].def;
  double Y = AnnotateOptions_Number[1].def;
  double Z = AnnotateOptions_Number[2].def;
  double style = getStyle();
  drawContext *ctx = (drawContext*)context;

  glColor4ubv((GLubyte *) & CTX.color.fg);
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
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return 0.;
}

const char *GMSH_AnnotatePlugin::callbackStr(int num, int action, const char *value,
                                             const char **opt)
{
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return NULL;
}

double GMSH_AnnotatePlugin::callbackX(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[0].def,
                  dim3 ? CTX.lc/200. : 0.5, 
                  dim3 ? -CTX.lc : -100., 
                  dim3 ? CTX.lc : 100000.);
}

double GMSH_AnnotatePlugin::callbackY(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[1].def,
                  dim3 ? CTX.lc/200. : 0.5, 
                  dim3 ? -CTX.lc : -100., 
                  dim3 ? CTX.lc : 100000.);
}

double GMSH_AnnotatePlugin::callbackZ(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[2].def,
                  dim3 ? CTX.lc/200. : 0.5, 
                  dim3 ? -CTX.lc : -100., 
                  dim3 ? CTX.lc : 100000.);
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

const char *GMSH_AnnotatePlugin::callbackText(int num, int action, const char *value)
{
  return callbackStr(num, action, value, &AnnotateOptions_String[0].def);
}

const char *GMSH_AnnotatePlugin::callbackFont(int num, int action, const char *value)
{
  return callbackStr(num, action, value, &AnnotateOptions_String[1].def);
}

const char *GMSH_AnnotatePlugin::callbackAlign(int num, int action, const char *value)
{
  return callbackStr(num, action, value, &AnnotateOptions_String[2].def);
}

void GMSH_AnnotatePlugin::getName(char *name) const
{
  strcpy(name, "Annotate");
}

void GMSH_AnnotatePlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(Annotate) adds the text string `Text',\n"
         "in font `Font' and size `FontSize', in the view\n"
         "`iView'. If `ThreeD' is equal to 1, the plugin inserts\n"
         "the string in model coordinates at the position\n"
         "(`X',`Y',`Z'). If `ThreeD' is equal to 0, the plugin\n"
         "inserts the string in screen coordinates at\n"
         "the position (`X',`Y'). The string is aligned\n"
         "according to `Align'. If `iView' < 0, the plugin\n"
         "is run on the current view.\n"
         "\n"
         "Plugin(Annotate) is executed in-place.\n");
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

void GMSH_AnnotatePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Annotate failed...");
}

PView *GMSH_AnnotatePlugin::execute(PView *v)
{
  double X = AnnotateOptions_Number[0].def;
  double Y = AnnotateOptions_Number[1].def;
  double Z = AnnotateOptions_Number[2].def;
  int dim3 = (int)AnnotateOptions_Number[3].def;
  int iView = (int)AnnotateOptions_Number[5].def;
  const char *text = AnnotateOptions_String[0].def;
  double style = getStyle();

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  if(dim3){
    List_Add(data1->T3D, &X);
    List_Add(data1->T3D, &Y);
    List_Add(data1->T3D, &Z);
    List_Add(data1->T3D, &style); 
    double d = List_Nbr(data1->T3C);
    List_Add(data1->T3D, &d); 
    for(int i = 0; i < (int)strlen(text) + 1; i++) 
      List_Add(data1->T3C, (void*)&text[i]); 
    data1->NbT3++;
  }
  else{
    List_Add(data1->T2D, &X);
    List_Add(data1->T2D, &Y);
    List_Add(data1->T2D, &style); 
    double d = List_Nbr(data1->T2C);
    List_Add(data1->T2D, &d); 
    for(int i = 0; i < (int)strlen(text) + 1; i++) 
      List_Add(data1->T2C, (void*)&text[i]); 
    data1->NbT2++;
  }

  return v1;
}
