
//
// A simple example on how to build a GUI frontend to Gmsh using GLUT
//

#if defined(__APPLE__)
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glut.h>
#  include <GL/glu.h>
#endif
#include "Gmsh.h"
#include <stdio.h>
#include "string.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"
#include "drawContext.h"
#include "Trackball.h"
#include "Camera.h"


typedef struct {
  double r,g,b;
} COLOUR;
typedef struct {
  unsigned char r,g,b,a;
} PIXELA;

using namespace std;
drawContext *ctx = 0;
Camera *camera;
mouseAndKeyboard mouseandkeys;


static int xprev = 0, yprev = 0, specialkey = 0;

class drawContextGlut : public drawContextGlobal{
public:
  void draw(){ ctx->draw3d(); ctx->draw2d(); }
  const char *getFontName(int index){ return "Helvetica"; }
  int getFontSize(){ return 12; }
  double getStringWidth(const char *str)
  {
    return glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)str);
  }
  int getStringHeight(){ return 12; }
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

  if (!camera->stereoEnable) {
    glViewport(ctx->viewport[0], ctx->viewport[1],
	       ctx->viewport[2], ctx->viewport[3]);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    camera->giveViewportDimension(ctx->viewport[2],ctx->viewport[3]);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(camera->glFleft,camera->glFright,camera->glFbottom,camera->glFtop,camera->glFnear,camera->glFfar);
    glMatrixMode(GL_MODELVIEW);
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera->position.x, camera->position.y, camera->position.z,
	      camera->target.x, camera->target.y, camera->target.z,
	      camera->up.x, camera->up.y, camera->up.z);
    ctx->draw3d();
    ctx->draw2d();
    glutSwapBuffers();

  }
  else {
    //    cout<<" display3D();"<<endl;
    glViewport(ctx->viewport[0], ctx->viewport[1],
	       ctx->viewport[2], ctx->viewport[3]);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    camera->giveViewportDimension(ctx->viewport[2],ctx->viewport[3]);

     //right eye
    XYZ eye =camera->eyesep / 2.0* camera->right;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double left  = - camera->screenratio * camera->wd2 - 0.5 * camera->eyesep * camera->ndfl;
    double right =   camera->screenratio * camera->wd2 - 0.5 * camera->eyesep * camera->ndfl;
    double top    =   camera->wd2;
    double  bottom = - camera->wd2;
    glFrustum(left,right,bottom,top,camera->glFnear,camera->glFfar);
    glMatrixMode(GL_MODELVIEW);
    glDrawBuffer(GL_BACK_RIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera->position.x+eye.x, camera->position.y+eye.y,  camera->position.z+eye.z,
	      camera->target.x+eye.x,  camera->target.y+eye.y,  camera->target.z+eye.z,
	      camera->up.x,  camera->up.y,  camera->up.z);
    ctx->draw3d();
    ctx->draw2d();

    //left eye
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    left  = - camera->screenratio * camera->wd2 + 0.5 * camera->eyesep * camera->ndfl;
    right =   camera->screenratio * camera->wd2 + 0.5 * camera->eyesep * camera->ndfl;
    top    =   camera->wd2;
    bottom = - camera->wd2;
    glFrustum(left,right,bottom,top,camera->glFnear,camera->glFfar);

    glMatrixMode(GL_MODELVIEW);
    glDrawBuffer(GL_BACK_LEFT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera->position.x-eye.x, camera->position.y-eye.y, camera->position.z-eye.z,
	      camera->target.x-eye.x, camera->target.y-eye.y, camera->target.z-eye.z,
	      camera->up.x, camera->up.y, camera->up.z);
    ctx->draw3d();
    ctx->draw2d();

    glutSwapBuffers();
  }

}


void reshape(int w, int h)
{
  ctx->viewport[2] = w;
  ctx->viewport[3] = h;
  display();
}


void keyboard(unsigned char key, int x, int y) {  display();}


void motion(int x, int y)
{
  int w = (ctx->viewport[2] - ctx->viewport[0]);
  int h = (ctx->viewport[3] - ctx->viewport[1]);
  //rotate
  if (mouseandkeys.button_left_down && (mouseandkeys.mode!= GLUT_ACTIVE_CTRL) ){
    double x_r = 2.*(1.*x - w/2.)/w;
    double y_r = 2.*(-1.*y + h/2.)/h;
    double xprev_r=2.*(1.*xprev - w/2.)/w;
    double yprev_r=2.*(-1.*yprev + h/2.)/h;
    double q[4];
    trackball(q,xprev_r,yprev_r,x_r,y_r);
      camera->rotate(q);
    xprev = x;
    yprev = y;
  }
  //zoom
  if (mouseandkeys.button_middle_down ){
    double dy= y-yprev;
    double factor =( CTX::instance()->zoomFactor * fabs(dy) +(double) h) / (double)h;
    factor = ((dy > 0) ? factor : 1./factor);
    camera->distance=fabs(1./factor*camera->ref_distance);
    camera->position.x=camera->target.x-camera->distance*camera->view.x;
    camera->position.y=camera->target.y-camera->distance*camera->view.y;
    camera->position.z=camera->target.z-camera->distance*camera->view.z;
 }
  // translate
  if (mouseandkeys.button_right_down ){
    double x_r = 2.*(1.*x - w/2.)/w;
    double y_r = 2.*(1.*y - h/2.)/h;
    double xprev_r=2.*(1.*xprev - w/2.)/w;
    double yprev_r=2.*(1.*yprev - h/2.)/h;
    double theta_x=camera->aperture*(x_r-xprev_r)*0.0174532925/2. ;
    double theta_y=camera->aperture*(y_r-yprev_r)*0.0174532925/2. ;
    camera->moveRight(theta_x);
    camera->moveUp(theta_y);
    xprev = x;
    yprev = y;
  }
  if (!mouseandkeys.button_middle_down ){
    xprev = x;
    yprev = y;
  }
  display();
}


void mouse(int button, int state, int x, int y)
{
  specialkey = glutGetModifiers();
  xprev = x;
  yprev = y;
  if (button == GLUT_LEFT_BUTTON) {
    mouseandkeys.button_left_down=!state;
  }
  else if (button == GLUT_MIDDLE_BUTTON) {
    mouseandkeys.button_middle_down=!state;
  }
  else {
    mouseandkeys.button_right_down=!state;
  }
  camera->ref_distance=camera->distance;
}



void processSpecialKeys(int key, int x, int y) {

  mouseandkeys.mode = glutGetModifiers();
  if (mouseandkeys.mode == GLUT_ACTIVE_CTRL)    {
    switch(key){
    case 100 : /* 'left' */
      display();
      camera->focallength=camera->focallength*.99;
      camera->eyesep=(camera->focallength/camera->distance)*camera->distance*camera->screenratio;
      break;
    case 102 :  /* 'right' */
      camera->focallength=camera->focallength*1.01;
      camera->eyesep=(camera->focallength/camera->distance)*camera->distance*camera->screenratio;
      display();
      break;
    }
 }
  else{
    switch(key){
      mouseandkeys.key= key ;
    case 101 : /* 'up' */
      camera->focallength*=1.1;
      break;
    case 103 : /* 'down' */
      camera->focallength*=0.9;
      break;
    case 100 : /* 'left' */
      camera->eyesep*=.9;
      break;
    case 102 :  /* 'right' */
      camera->eyesep*=1.1;
      break;
    }
  }
  camera->update();
  display();

    cout<<"eyesep = "<< camera->eyesep<<" / focallength = "<< camera->focallength<<" / screenratio = ";
    cout<< camera->screenratio<<" / distance = "<< camera->distance<<" / closeness = "<< camera->closeness<<endl;
  mouseandkeys.mode = 0;
}



void processNormalKeys(unsigned char key, int x, int y) {
  double def;

  if (key != 0) {
    mouseandkeys.key= key ;
    mouseandkeys.mode = glutGetModifiers();
    if (mouseandkeys.mode == GLUT_ACTIVE_CTRL && key==17)     exit(0);
  }
  switch(key){
  case 49: GModel::current()->mesh(1); break;  /* '1' */
  case 50: GModel::current()->mesh(2); break;  /* '2' */
  case 51: GModel::current()->mesh(3); break;  /* '3' */
  case 48 :  /* '0' */
    camera->lookAtCg();
    display();
    break;
  case 114 : /* 'R' */
    camera->init();
    display();
    break;
  case 'f' :  /* 'F' */
    camera->screenwidth=ctx->viewport[2];
    camera->screenheight=ctx->viewport[3];
    glutFullScreen();
    display();
    break;
  case 27 : /* 'ech' */
        glutReshapeWindow(camera->screenwidth ,camera->screenheight );
	//glutReshapeWindow(500,500 );
    display();
    break;
  case 100 : ; /* 'D' */
    GmshSetOption("View","VectorType",5.);
    display();
    break;
  case 43 : /* '+' */
    GmshGetOption("View", "DisplacementFactor", def);
    def*=2.;
    GmshSetOption("View","DisplacementFactor",def);
    display();
    break;
  case 45 : ; /* '-' */
    GmshGetOption("View", "DisplacementFactor", def);
    def*=.5;
    GmshSetOption("View","DisplacementFactor",def);
    display();
    break;
  }

}


//*******************************************************
//*******************************************************
//*******************************************************

int main(int argc, char **argv)
{

  GmshInitialize(argc, argv);
  GmshSetOption("General", "Terminal", 1.);
  GmshSetOption("General", "Stereo", 0.);
  GmshSetOption("General", "Camera", 1.);
  GmshSetOption("General", "Orthographic", 0.);
  GmshSetOption("General", "TrackballHyperbolicSheet", 0.);

  if (strstr(argv[1],"-s") != NULL){
   camera->stereoEnable = true;
   cout<<"mode STEREO"<<endl;
   GmshSetOption("General", "Stereo", 1.);
  }

  for(int i = 1; i < argc; i++) GmshMergeFile(argv[i]);

  ctx = new drawContext();
  drawContext::setGlobal(new drawContextGlut);

  camera= &(ctx->camera);
  camera->init();
  glutInit(&argc, argv);
  if (camera->stereoEnable) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STEREO);
  }
  else  {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  }
  glutInitWindowSize(ctx->viewport[2], ctx->viewport[3]);
  glutInitWindowPosition(400,10);
  glutInitWindowSize(800,800);
  glutCreateWindow("GLUT Gmsh Viewer");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMotionFunc(motion);
  glutMouseFunc(mouse);
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);

  cout<<"-------------------------------------"<<endl;
  cout<<"          SHORTCUTS "<<endl;
  cout<<"-------------------------------------"<<endl;
  cout<<" Ctrl+Q               Quit "<<endl;
  cout<<" 1                    mesh line "<<endl;
  cout<<" 2                    mesh surface "<<endl;
  cout<<" 3                    mesh volume "<<endl;
  cout<<" R                    resize "<<endl;
  cout<<" 0                    origine "<<endl;
  cout<<" option -s            stereo on "<<endl;
  cout<<" F                    full screen on "<<endl;
  cout<<" ech                  full screen off"<<endl;
  cout<<" D                    displacement field"<<endl;
  cout<<" +                    deformed +"<<endl;
  cout<<" -                    deformed -"<<endl;
  cout<<" up                   focal length +"<<endl;
  cout<<" down                 focal length -"<<endl;
  cout<<" left                 eye sep -"<<endl;
  cout<<" right                eye sep +"<<endl;
  cout<<"-------------------------------------"<<endl;
  glutMainLoop();
  GmshFinalize();
  return 0;
}
