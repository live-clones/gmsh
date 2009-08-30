//
// A simple example on how to build a GUI frontend to Gmsh using GLUT
// and libAntTweakBar
//

#if defined(__APPLE__)
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <AntTweakBar.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/drawContext.h>

drawContext *ctx = 0;

class drawContextTw : public drawContextGlobal{
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
  TwDraw();
  glutSwapBuffers(); 
  glutPostRedisplay();
}

void reshape(int w, int h)
{
  ctx->viewport[2] = w;
  ctx->viewport[3] = h;
  TwWindowSize(w, h);
}

void keyboard(unsigned char key, int x, int y)
{
  static bool fullScreen = false;
  static int oldw = 10, oldh = 10;
  if(TwEventKeyboardGLUT(key, x, y)) return;
  switch(key){
  case '1': GModel::current()->mesh(1); break;
  case '2': GModel::current()->mesh(2); break;
  case '3': GModel::current()->mesh(3); break;
  case 'f': 
    if(fullScreen){ glutReshapeWindow(oldw, oldh); }
    else{ oldw = ctx->viewport[2]; oldh = ctx->viewport[3]; glutFullScreen(); }
    fullScreen = !fullScreen;
  }
  glutPostRedisplay();
}

static mousePosition clickPos, prevPos;
static int specialKey = 0;

void mouseMotion(int x, int y)
{
  if(TwEventMouseMotionGLUT(x, y)) return;
  int w = ctx->viewport[2]; 
  int h = ctx->viewport[3];

  mousePosition currPos;
  currPos.set(ctx, x, y);

  if(specialKey == GLUT_ACTIVE_SHIFT){
    double dx = currPos.win[0] - prevPos.win[0];
    double dy = currPos.win[1] - prevPos.win[1];
    if(fabs(dy) > fabs(dx)) {
      double fact = (4. * fabs(dy) + h) / (double)h;
      ctx->s[0] *= ((dy > 0) ? fact : 1. / fact);
      ctx->s[1] = ctx->s[0];
      ctx->s[2] = ctx->s[0];
      clickPos.recenter(ctx);
    }
  }
  else if(specialKey == GLUT_ACTIVE_ALT){
    ctx->t[0] += (currPos.wnr[0] - clickPos.wnr[0]);
    ctx->t[1] += (currPos.wnr[1] - clickPos.wnr[1]);
    ctx->t[2] = 0.;
  }
  else{
    ctx->addQuaternion
      ((2. * prevPos.win[0] - w) / w, (h - 2. * prevPos.win[1]) / h,
       (2. * currPos.win[0] - w) / w, (h - 2. * currPos.win[1]) / h);
  }

  prevPos.set(ctx, x, y);
  glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y)
{
  if(TwEventMouseButtonGLUT(button, state, x, y)) return;
  specialKey = glutGetModifiers();
  clickPos.set(ctx, x, y);
  prevPos.set(ctx, x, y);
}

// AntTweakBar callbacks
void TW_CALL SetLightDirCB(const void *value, void *clientData)
{
  const double *dir = (const double *)(value);
  GmshSetOption("General", "Light0X", -dir[0]);
  GmshSetOption("General", "Light0Y", -dir[1]);
  GmshSetOption("General", "Light0Z", -dir[2]);
}

void TW_CALL GetLightDirCB(void *value, void *clientData)
{
  double *dir = (double*)(value);
  GmshGetOption("General", "Light0X", dir[0]);
  GmshGetOption("General", "Light0Y", dir[1]);
  GmshGetOption("General", "Light0Z", dir[2]);
  dir[0] *= -1; dir[1] *= -1; dir[2] *= -1;
}

void TW_CALL SetInt32CB(const void *value, void *clientData)
{
  int b = *(const int*)(value);
  std::string s((const char *)clientData);
  int idot = s.find_first_of('.');
  GmshSetOption(s.substr(0, idot), s.substr(idot + 1), (double)b);
}

void TW_CALL GetInt32CB(void *value, void *clientData)
{
  std::string s((const char *)clientData);
  int idot = s.find_first_of('.');
  double tmp;
  GmshGetOption(s.substr(0, idot), s.substr(idot + 1), tmp);
  *(int*)(value) = (int)tmp;
}

void TW_CALL SetDoubleCB(const void *value, void *clientData)
{
  double b = *(const double*)(value);
  std::string s((const char *)clientData);
  int idot = s.find_first_of('.');
  GmshSetOption(s.substr(0, idot), s.substr(idot + 1), b);
}

void TW_CALL GetDoubleCB(void *value, void *clientData)
{
  std::string s((const char *)clientData);
  int idot = s.find_first_of('.');
  GmshGetOption(s.substr(0, idot), s.substr(idot + 1), *(double*)(value));
}

void TW_CALL SetColorCB(const void *value, void *clientData)
{
  unsigned int b = *(const unsigned int*)(value);
  std::string s((const char *)clientData);
  int idot = s.find_first_of('.');
  GmshSetOption(s.substr(0, idot), s.substr(idot + 1), b);
}

void TW_CALL GetColorCB(void *value, void *clientData)
{
  std::string s((const char *)clientData);
  int idot = s.find_first_of('.');
  GmshGetOption(s.substr(0, idot), s.substr(idot + 1), *(unsigned int*)(value));
}

void TW_CALL MenuCB(void *clientData)
{
  printf("menu '%s'\n", (const char*)clientData);
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
  drawContext::setGlobal(new drawContextTw);

  if(!TwInit(TW_OPENGL, NULL)){
    printf("AntTweakBar initialization failed: %s\n", TwGetLastError());
    return 1;
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(ctx->viewport[2], ctx->viewport[3]);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Gmsh Viewer");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouseButton);
  glutMotionFunc(mouseMotion);
  glutPassiveMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc((GLUTspecialfun)TwEventSpecialGLUT);
  TwGLUTModifiersFunc(glutGetModifiers);

  TwBar *bar = TwNewBar("Options");
  TwDefine("Options size='200 400' color='50 50 50' alpha=128");
  {
    TwEnumVal axesEV[6] = { {0, "None"}, {1, "Simple axes"}, {2, "Box"}, 
                            {3, "Full grid"}, {4, "Open grid"}, {5, "Ruler"} };
    TwType axesType = TwDefineEnum("AxesType", axesEV, 6);
    TwAddVarCB(bar, "Axes", axesType, SetInt32CB, GetInt32CB, 
               (void*)"General.Axes", "group='General' help='Change axes.' ");
    TwAddVarCB(bar, "LightDir", TW_TYPE_DIR3D, SetLightDirCB, GetLightDirCB, 
               0, "group='General' label='Light direction' close help='Change "
               "light direction.' ");
    {
      TwAddVarCB(bar, "Background", TW_TYPE_COLOR32, SetColorCB, GetColorCB,
                 (void*)"General.Background", "group='GeneralColor' "
                 "label='Background color' ");
      TwAddVarCB(bar, "BackgroundGradient", TW_TYPE_COLOR32, SetColorCB, GetColorCB,
                 (void*)"General.BackgroundGradient", "group='GeneralColor' "
                 "label='Background gradient color' ");
      TwDefine("Options/GeneralColor  label='Colors' close group='General' ");
    }
    TwDefine("Options/General close ");
  }
  {
    TwAddVarCB(bar, "Points", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Geometry.Points", "group='Geometry' help='Draw points.' ");
    TwAddVarCB(bar, "Lines", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Geometry.Lines", "group='Geometry' help='Draw lines.' ");
    TwAddVarCB(bar, "Surfaces", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB,
               (void*)"Geometry.Surfaces", "group='Geometry' help='Draw surfaces.' ");
    TwAddVarCB(bar, "Volumes", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Geometry.Volumes", "group='Geometry' help='Draw volumes.' ");
  }
  {
    TwAddVarCB(bar, "Vertices", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Mesh.Points", "group='Mesh' help='Draw mesh vertices.' ");
    TwAddVarCB(bar, "MeshLines", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Mesh.Lines", "group='Mesh' label='Lines' help='Draw line mesh.' ");
    TwAddVarCB(bar, "SurfaceEdges", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Mesh.SurfaceEdges", "group='Mesh' label='Surface edges' "
               "help='Draw surface mesh edges.' ");
    TwAddVarCB(bar, "SurfaceFaces", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Mesh.SurfaceFaces", "group='Mesh' label='Surface faces' "
               "help='Draw surface mesh faces.' ");
    TwAddVarCB(bar, "VolumeEdges", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Mesh.VolumeEdges", "group='Mesh' label='Volume edges' "
               "help='Draw volume mesh edges.' ");
    TwAddVarCB(bar, "VolumeFaces", TW_TYPE_BOOL32, SetInt32CB, GetInt32CB, 
               (void*)"Mesh.VolumeFaces", "group='Mesh' label='Volume faces' "
               "help='Draw volume mesh faces.' ");
    TwAddVarCB(bar, "Explode", TW_TYPE_DOUBLE, SetDoubleCB, GetDoubleCB,
               (void*)"Mesh.Explode", "group='Mesh' label='Explode factor' "
               "min=0 max=1 step=0.01 help='Explode mesh.' ");
    TwAddVarCB(bar, "SizeFactor", TW_TYPE_DOUBLE, SetDoubleCB, GetDoubleCB, 
               (void*)"Mesh.CharacteristicLengthFactor", "group='Mesh' "
               "label='Element size factor' min=0.01 max=100 step=0.01 ");
  }

  TwBar *menubar = TwNewBar("Menu");
  TwDefine("Menu size='200 400' position='500 30' iconified='true' ");
  TwAddButton(menubar, "Elementary entities", MenuCB, (void*)"Elementary", 0);
  TwAddButton(menubar, "Physical groups", MenuCB, (void*)"Physical", 0);
  TwAddButton(menubar, "Edit", MenuCB, (void*)"Edit", 0);
  TwAddButton(menubar, "Reload", MenuCB, (void*)"Reload", 0);

  glutMainLoop();

  GmshFinalize();
  return 0;
}
