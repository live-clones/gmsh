// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>

#ifndef CAMERA_H
#define CAMERA_H

class Quaternion;

class XYZ {
public:
  XYZ() : x(0.), y(0.), z(0.){};
  ~XYZ(){};
  XYZ(double _x, double _y, double _z);
  double x, y, z;
  void set(const double &_x, const double &_y, const double &_z);
  XYZ(const Quaternion &R);
};

double length(XYZ &p);
void normalize(XYZ &p);
void rotate(const Quaternion &omega, XYZ axe);
XYZ operator*(const double &a, const XYZ &T);
XYZ operator+(const XYZ &L, const XYZ &R);
XYZ operator-(const XYZ &L, const XYZ &R);
XYZ operator-(const XYZ &R);

class Quaternion {
public:
  double x, y, z, w;
  Quaternion();
  Quaternion(const XYZ &R);
  Quaternion(const XYZ &R, const double &A);
  ~Quaternion();
};

double length(Quaternion &quat);
void normalize(Quaternion &quat);
Quaternion conjugate(Quaternion quat);
Quaternion mult(const Quaternion &A, const Quaternion &B);
Quaternion operator*(const Quaternion &A, const Quaternion &B);

class Camera {
public:
  Camera();
  ~Camera();
  bool on;
  XYZ position; /* camera position         */
  XYZ front; /* View direction vector   */
  XYZ up; /* View up direction       */
  XYZ right; /* View right direction    */
  XYZ target; /* center of rotation and screen   */
  double focallength; /* Focal Length along vd   */
  double focallength_ratio;
  double aperture; /* Camera aperture         */
  double eyesep; /* Eye separation          */
  int screenwidth, screenheight;
  double screenratio, distance, ref_distance;
  bool button_left_down, button_middle_down, button_right_down;
  bool stereoEnable;
  double Lc, eye_sep_ratio, closeness, ndfl, glFnear, glFfar, radians, wd2;
  double glFleft, glFright, glFtop, glFbottom;
  void giveViewportDimension(const int &W, const int &H);
  void lookAtCg();
  void init();
  void rotate(double *q);
  //
  void move_and_look(double _movfront, double _movright, double _movup,
                     double _rotfront, double _rotright, double _rotup,
                     double _azimut, double _elevation);
  //
  void moveRight(double &theta);
  void moveUp(double &theta);
  void zoom(double &factor);
  void update();
  void affiche();
  void alongX();
  void alongY();
  void alongZ();
  void upX();
  void upY();
  void upZ();
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
  mouseAndKeyboard(){};
  ~mouseAndKeyboard(){};
};

#endif
