//
// A simple example on how to build a GUI frontend to Gmsh using GLUT
//

#if defined(__APPLE__)
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "drawContext.h"

drawContext *ctx = 0;

class drawContextGlut : public drawContextGlobal{
 public:
  void draw(){ ctx->draw3d(); ctx->draw2d(); }
  const char *getFontName(int index){ return "Helvetica"; }
  int getFontSize(){ return 18; }
  double getStringWidth(const char *str)
  {
    return glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)str);
  }
  int getStringHeight(){ return 18; }
  int getStringDescent(){ return 6; }
  void drawString(const char *str)
  {
    for (int i = 0; i < strlen(str); i++) 
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]); 
  }
};

// GLUT callbacks
void display()
{
  glViewport(ctx->viewport[0], ctx->viewport[1],
             ctx->viewport[2], ctx->viewport[3]);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  drawContext::global()->draw();
  glutSwapBuffers(); 
}

void reshape(int w, int h)
{
  ctx->viewport[2] = w;
  ctx->viewport[3] = h;
  display();
}

void keyboard(unsigned char key, int x, int y)
{
  switch(key){
  case '1': GModel::current()->mesh(1); break;
  case '2': GModel::current()->mesh(2); break;
  case '3': GModel::current()->mesh(3); break;
  }
  display();
}

static int xprev = 0, yprev = 0, specialkey = 0;

void motion(int x, int y)
{
  int w = ctx->viewport[2]; 
  int h = ctx->viewport[3];
  if(specialkey == GLUT_ACTIVE_SHIFT){
    double dx = x - xprev;
    double dy = y - yprev;
    if(fabs(dy) > fabs(dx)) {
      double fact = (4. * fabs(dy) + h) / (double)h;
      ctx->s[0] *= ((dy > 0) ? fact : 1. / fact);
      ctx->s[1] = ctx->s[0];
      ctx->s[2] = ctx->s[0];
    }
  }
  else{
    ctx->addQuaternion((2. * xprev - w) / w, (h - 2. * yprev) / h,
                       (2. * x - w) / w, (h - 2. * y) / h);
  }
  xprev = x;
  yprev = y;
  display();
}

void mouse(int button, int state, int x, int y)
{
  specialkey = glutGetModifiers();
  xprev = x;
  yprev = y;
}

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GmshSetOption("General", "Terminal", 1.);
  GmshSetOption("View", "IntervalsType", 1.);
  GmshSetOption("View", "AdaptVisualizationGrid", 1.);
  GmshSetOption("View", "TargetError", 0.00001);
  GmshSetOption("View", "MaxRecursionLevel", 3.); 

  for(int i = 1; i < argc; i++) GmshMergeFile(argv[i]);

  ctx = new drawContext();
  drawContext::setGlobal(new drawContextGlut);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(ctx->viewport[2], ctx->viewport[3]);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("GLUT Gmsh Viewer");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMotionFunc(motion);
  glutMouseFunc(mouse);
  glutMainLoop();

  GmshFinalize();
  return 0;
}
