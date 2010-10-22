
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <stdio.h>
#include <math.h>
#


typedef struct {
  double x,y,z;
} XYZ;
typedef struct {
  double x,y,z,w;
} quaternion;

XYZ origin = {0.0,0.0,0.0};

class Camera {
public:
  XYZ position;          /* camera position           */
  XYZ view;              /* View direction vector   */
  XYZ up;                /* View up direction       */
  XYZ right;              /* View right direction       */
  XYZ target;   /* center of rotation and screen   */
  double focallength;  /* Focal Length along vd   */
  double aperture;     /* Camera aperture         */
  double eyesep;       /* Eye separation          */
  int screenwidth,screenheight;
  double distance;
  double ref_distance;
  bool button_left_down;
  bool button_middle_down;
  bool button_right_down;
  bool stereoEnable;
  double Lc;
  double ratio;
  double closeness;
  Camera();
  ~Camera();
  void lookAtCg();
  void init();
  void rotate(double* q);
  void moveRight(double theta);
  void moveUp(double theta);
  void update();
private:
};  



class mouseAndKeyboard {
public:
  bool button_left_down;
  bool button_middle_down;
  bool button_right_down;
  int key;
  int mode;
  mouseAndKeyboard() {};
  ~mouseAndKeyboard() {};
};




// Quaternion and XYZ functions
double length(quaternion quat)
{
  return sqrt(quat.x * quat.x + quat.y * quat.y +
              quat.z * quat.z + quat.w * quat.w);
}
double length(XYZ p)
{
  return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
quaternion normalize(quaternion &quat)
{
  double L = length(quat);

  quat.x /= L;
  quat.y /= L;
  quat.z /= L;
  quat.w /= L;

  return quat;
}

XYZ normalize(XYZ &p)
{
  double L = length(p);

  p.x /= L;
  p.y /= L;
  p.z /= L;

  return p;
}
quaternion conjugate(quaternion quat)
{
  quat.x = -quat.x;
  quat.y = -quat.y;
  quat.z = -quat.z;
  return quat;
}
quaternion mult(quaternion A, quaternion B)
{
  quaternion C;

  C.x = A.w*B.x + A.x*B.w + A.y*B.z - A.z*B.y;
  C.y = A.w*B.y - A.x*B.z + A.y*B.w + A.z*B.x;
  C.z = A.w*B.z + A.x*B.y - A.y*B.x + A.z*B.w;
  C.w = A.w*B.w - A.x*B.x - A.y*B.y - A.z*B.z;
  return C;
}

XYZ rotate(quaternion omega,XYZ axe) {
  XYZ new_axe;
  quaternion qaxe,new_qaxe;
  qaxe.x=axe.x;
  qaxe.y=axe.y;
  qaxe.z=axe.z;
  qaxe.w=0.;
  new_qaxe=mult(mult(omega,qaxe),conjugate(omega));
  axe.x=new_qaxe.x ;
  axe.y=new_qaxe.y;
  axe.z=new_qaxe.z;

}









#endif
