
#ifndef _CAMERA_H_
#define _CAMERA_H_


/*
typedef struct {
  double x,y,z,w;
} Quaternion;
*/ 
class Quaternion;

class XYZ {
public: 
  XYZ(){};
  ~XYZ(){};
  XYZ(double _x,double _y,double _z);
  double x,y,z;
  //  double length(XYZ &p);
  //  void normalize(XYZ &p);
  //  void rotate(Quaternion omega,XYZ axe) ; 
  void set(const  double & _x, const double & _y ,const  double & _z);
  XYZ (const Quaternion &R);
};
double length(XYZ &p);
void normalize(XYZ &p);
void rotate(Quaternion omega,XYZ axe) ; 
XYZ operator* (const double &a,const XYZ &T);
XYZ operator+ (const XYZ &L,const XYZ &R);
XYZ operator- (const XYZ &L,const XYZ &R);


class Quaternion{
public:
  double x,y,z,w;
  Quaternion(){}; 
  ~Quaternion(){};
  Quaternion (const XYZ &R);
};

double length(Quaternion &quat);
void normalize(Quaternion &quat);
Quaternion conjugate(Quaternion quat);
Quaternion mult(const Quaternion& A,const Quaternion& B);
Quaternion operator *(const Quaternion &A, const Quaternion &B);


using namespace std; 

class Camera {
public:
  bool on;
  XYZ position;           /* camera position         */
  XYZ view;               /* View direction vector   */
  XYZ up;                 /* View up direction       */
  XYZ right;              /* View right direction    */
  XYZ target;             /* center of rotation and screen   */
  double focallength;     /* Focal Length along vd   */
  double aperture;        /* Camera aperture         */
  double eyesep;          /* Eye separation          */
  int screenwidth,screenheight;
  double screenratio, distance, ref_distance;
  bool button_left_down, button_middle_down, button_right_down;
  bool stereoEnable;
  double Lc, eye_sep_ratio, closeness, ndfl, glFnear, glFfar, radians, wd2;
  double glFleft,glFright,glFtop,glFbottom;
  Camera():stereoEnable(false),on(false){};
  ~Camera();
  void giveViewportDimension(const int& W,const int& H);
  void lookAtCg();
  void init();
  void rotate(double* q);
  void moveRight(double& theta);
  void moveUp(double& theta);
  void zoom(double& factor);
  void update();
  void affiche();
  void alongX();
  void alongY();
  void alongZ();
  void tiltHeadLeft();
  void tiltHeadRight();
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


 
 


#endif
