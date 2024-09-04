// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>

#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include "Camera.h"
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Trackball.h"
#include "Context.h"
#include "drawContext.h"

Camera::Camera()
  : on(false), stereoEnable(false), Lc(1.), glFnear(0.0001), glFfar(10000)
{
}

Camera::~Camera() {}

void Camera::init()
{
  if(CTX::instance()->fileread) {
    on = true;
  }
  eye_sep_ratio = CTX::instance()->eye_sep_ratio;
  aperture = CTX::instance()->camera_aperture;
  focallength = CTX::instance()->focallength_ratio * 100.;
  alongZ();
  this->lookAtCg();
  eyesep = distance * eye_sep_ratio / 100.;
  ref_distance = distance;
  glFnear = .0001 * distance;
  glFfar = 10000 * distance;
  this->update();
}

void Camera::alongX()
{
  front.set(-1., 0., 0.);
  up.set(0., 0., 1);
  position = target - distance * front;
  this->update();
}

void Camera::alongY()
{
  front.set(0., -1., 0.);
  up.set(1., 0., 0);
  position = target - distance * front;
  this->update();
}

void Camera::alongZ()
{
  front.set(0., 0., -1.);
  up.set(0., 1., 0);
  position = target - distance * front;
  this->update();
}

void Camera::upX()
{
  if(up.x > 0.) {
    if(up.x != 1.) {
      up.set(1., 0., 0.);
    }
    else {
      up.set(-1., 0., 0.);
      right = -right;
    }
  }
  else {
    if(up.x != -1.) {
      up.set(-1., 0., 0.);
    }
    else {
      up.set(1., 0., 0.);
      right = -right;
    }
  }
  front.x = up.y * right.z - up.z * right.y;
  front.y = up.z * right.x - up.x * right.z;
  front.z = up.x * right.y - up.y * right.x;
  target = position + distance * front;
  this->update();
}

void Camera::upY()
{
  if(up.y > 0.) {
    if(up.y != 1.) {
      up.set(0., 1., 0.);
    }
    else {
      up.set(0., -1., 0.);
      right = -right;
    }
  }
  else {
    if(up.y != -1.) {
      up.set(0., -1., 0.);
    }
    else {
      up.set(0., 1., 0.);
      right = -right;
    }
  }
  front.x = up.y * right.z - up.z * right.y;
  front.y = up.z * right.x - up.x * right.z;
  front.z = up.x * right.y - up.y * right.x;
  target = position + distance * front;
  this->update();
}

void Camera::upZ()
{
  if(up.z > 0.) {
    if(up.z != 1.) {
      up.set(0., 0., 1.);
    }
    else {
      up.set(0., 0., -1.);
      right = -right;
    }
  }
  else {
    if(up.z != -1.) {
      up.set(0., 0., -1.);
    }
    else {
      up.set(0., 0., 1.);
      right = -right;
    }
  }
  front.x = up.y * right.z - up.z * right.y;
  front.y = up.z * right.x - up.x * right.z;
  front.z = up.x * right.y - up.y * right.x;
  target = position + distance * front;
  this->update();
}

void Camera::tiltHeadLeft()
{
  up = -1. * right;
  update();
}

void Camera::tiltHeadRight()
{
  up = right;
  update();
}

void Camera::lookAtCg()
{
  target.x = CTX::instance()->cg[0];
  target.y = CTX::instance()->cg[1];
  target.z = CTX::instance()->cg[2];
  double W = CTX::instance()->max[0] - CTX::instance()->min[0];
  double H = CTX::instance()->max[1] - CTX::instance()->min[1];
  double P = CTX::instance()->max[2] - CTX::instance()->min[2];
  Lc = sqrt(1. * W * W + 1. * H * H + 1. * P * P);
  distance = .8 * fabs(.5 * Lc * 4. / 3. / tan(aperture * .01745329 / 2.));
  position = target - distance * front;
  this->update();
  focallength = focallength_ratio * distance;
  ref_distance = distance;
  eyesep = focallength * eye_sep_ratio / 100.;
}

void Camera::giveViewportDimension(const int &W, const int &H)
{
  screenwidth = W;
  screenheight = H;
  screenratio = (double)W / (double)H;
  glFleft = -screenratio * wd2;
  glFright = screenratio * wd2;
  glFtop = wd2;
  glFbottom = -wd2;
}

void Camera::update()
{
  right.x = front.y * up.z - front.z * up.y;
  right.y = front.z * up.x - front.x * up.z;
  right.z = front.x * up.y - front.y * up.x;

  up.x = right.y * front.z - right.z * front.y;
  up.y = right.z * front.x - right.x * front.z;
  up.z = right.x * front.y - right.y * front.x;

  ref_distance = distance;
  normalize(up);
  normalize(right);
  normalize(front);
  aperture = CTX::instance()->camera_aperture;
  focallength_ratio = CTX::instance()->focallength_ratio;
  focallength = focallength_ratio * distance;
  eye_sep_ratio = CTX::instance()->eye_sep_ratio;
  eyesep = focallength * eye_sep_ratio / 100.;
  radians = 0.0174532925 * aperture / 2.;
  wd2 = glFnear * tan(radians);
  ndfl = glFnear / focallength;
}

void Camera::affiche()
{
  std::cout << "  ------------ GENERAL PARAMETERS ------------" << std::endl;
  std::cout << "  CTX aperture " << CTX::instance()->camera_aperture
            << std::endl;
  std::cout << "  CTX eyesep ratio " << CTX::instance()->eye_sep_ratio
            << std::endl;
  std::cout << "  CTX focallength ratio " << CTX::instance()->focallength_ratio
            << std::endl;
  std::cout << "  ------------ CAMERA PARAMETERS ------------" << std::endl;
  std::cout << "  position " << position.x << "," << position.y << ","
            << position.z << std::endl;
  std::cout << "  front " << front.x << "," << front.y << "," << front.z
            << std::endl;
  std::cout << "  up " << up.x << "," << up.y << "," << up.z << std::endl;
  std::cout << "  right " << right.x << "," << right.y << "," << right.z
            << std::endl;
  std::cout << "  target " << target.x << "," << target.y << "," << target.z
            << std::endl;
  std::cout << "  focallength_ratio " << focallength_ratio << std::endl;
  std::cout << "  focallength " << focallength << std::endl;
  std::cout << "  aperture " << aperture << std::endl;
  std::cout << "  eyesep_ratio " << eye_sep_ratio << std::endl;
  std::cout << "  eyesep " << eyesep << std::endl;
  std::cout << "  screenwidth " << screenwidth << std::endl;
  std::cout << "  screenheight " << screenheight << std::endl;
  std::cout << "  distance " << distance << std::endl;
  std::cout << "  ref_distance " << ref_distance << std::endl;
  std::cout << "  button_left_down " << button_left_down << std::endl;
  std::cout << "  button_middle_down " << button_middle_down << std::endl;
  std::cout << "  button_right_down " << button_right_down << std::endl;
  std::cout << "  stereoEnable " << stereoEnable << std::endl;
  std::cout << "  Lc " << Lc << std::endl;
  std::cout << "  eye_sep_ratio " << eye_sep_ratio << std::endl;
  std::cout << "  closeness " << closeness << std::endl;
  std::cout << "  glFnear " << glFnear << std::endl;
  std::cout << "  glFfar " << glFfar << std::endl;
  std::cout << "  radians " << radians << std::endl;
  std::cout << "  wd2 " << wd2 << std::endl;
}

void Camera::moveRight(double &theta)
{
  this->update();
  position = position - distance * tan(theta) * right;
  target = position + distance * front;
  this->update();
}

void Camera::moveUp(double &theta)
{
  this->update();
  position = position + distance * tan(theta) * up;
  target = position + distance * front;
  this->update();
}

void Camera::zoom(double &factor)
{
  distance = fabs(1. / factor * ref_distance);
  position = target - distance * front;
}

void Camera::rotate(double *q)
{
  this->update();
  // rotation projection in global coordinates
  Quaternion omega;
  omega.x = q[0] * right.x + q[1] * up.x - q[2] * front.x;
  omega.y = q[0] * right.y + q[1] * up.y - q[2] * front.y;
  omega.z = q[0] * right.z + q[1] * up.z - q[2] * front.z;
  omega.w = q[3];
  normalize(omega);
  Quaternion conj = conjugate(omega);
  front = omega * front * conj;
  up = omega * up * conj;
  right = omega * right * conj;
  normalize(front);
  normalize(up);
  normalize(right);
  // actualize camera position
  position = target - distance * front;
  this->update();
}

void Camera::move_and_look(double _movfront, double _movright, double _movup,
                           double _thetafront, double _thetaright,
                           double _thetaup, double _azimut, double _elevation)
{
  position = position + _movfront * front + _movright * right + _movup * up;
  Quaternion omega_up;
  omega_up.x = sin(_thetaup) * up.x;
  omega_up.y = sin(_thetaup) * up.y;
  omega_up.z = sin(_thetaup) * up.z;
  omega_up.w = cos(_thetaup);
  normalize(omega_up);
  Quaternion omega_right;
  omega_right.x = sin(_thetaright) * right.x;
  omega_right.y = sin(_thetaright) * right.y;
  omega_right.z = sin(_thetaright) * right.z;
  omega_right.w = cos(_thetaright);
  normalize(omega_right);
  Quaternion omega_front;
  omega_front.x = sin(_thetafront) * front.x;
  omega_front.y = sin(_thetafront) * front.y;
  omega_front.z = sin(_thetafront) * front.z;
  omega_front.w = cos(_thetafront);
  normalize(omega_front);
  Quaternion omega;
  omega = omega_up * omega_right * omega_front;
  normalize(omega);
  Quaternion conj = conjugate(omega);
  front = omega * front * conj;
  up = omega * up * conj;
  right = omega * right * conj;
  normalize(front);
  normalize(up);
  normalize(right);
  this->update();
  // in azimuthal coordinates
  XYZ look, newlook;
  _elevation = std::min(_elevation, 1.57);
  _elevation = std::max(_elevation, -1.57);
  look = cos(_azimut) * front - sin(_azimut) * right;
  newlook = cos(_elevation) * look + sin(_elevation) * up;
  target = position + distance * newlook;
}

////////////////////////////////////////////////////////////////
//                 QUATERNION and XYZ functions
////////////////////////////////////////////////////////////////

double length(Quaternion &q)
{
  return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

double length(XYZ &p) { return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); }

void normalize_axe(Quaternion &q)
{
  double sina = sin(acos(q.w));
  double l;
  if(sina != 0.) {
    l = (q.x * q.x + q.y * q.y + q.z * q.z) / (sina * sina);
    l = sqrt(l);
  }
  else {
    l = 0.;
  }
  if(l != 0.) {
    q.x /= l;
    q.y /= l;
    q.z /= l;
  }
}
void normalize(Quaternion &q)
{
  double L = length(q);
  q.x /= L;
  q.y /= L;
  q.z /= L;
  q.w /= L;
}

void normalize(XYZ &p)
{
  double L = length(p);
  p.x /= L;
  p.y /= L;
  p.z /= L;
}

XYZ::XYZ(const Quaternion &R) : x(R.x), y(R.y), z(R.z) {}

XYZ::XYZ(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

void XYZ::set(const double &_x, const double &_y, const double &_z)
{
  x = _x;
  y = _y;
  z = _z;
}

void rotate(const Quaternion &omega, XYZ axe)
{
  XYZ new_axe;
  Quaternion qaxe, new_qaxe;
  qaxe.x = axe.x;
  qaxe.y = axe.y;
  qaxe.z = axe.z;
  qaxe.w = 0.;
  new_qaxe = mult(mult(omega, qaxe), conjugate(omega));
  axe.x = new_qaxe.x;
  axe.y = new_qaxe.y;
  axe.z = new_qaxe.z;
}

XYZ operator*(const double &a, const XYZ &T)
{
  XYZ res(T);
  res.x *= a;
  res.y *= a;
  res.z *= a;
  return res;
}

XYZ operator+(const XYZ &L, const XYZ &R)
{
  XYZ res(L);
  res.x += R.x;
  res.y += R.y;
  res.z += R.z;
  return res;
}
XYZ operator-(const XYZ &L, const XYZ &R)
{
  XYZ res(L);
  res.x -= R.x;
  res.y -= R.y;
  res.z -= R.z;
  return res;
}
XYZ operator-(const XYZ &R)
{
  XYZ res;
  res.x = -R.x;
  res.y = -R.y;
  res.z = -R.z;
  return res;
}

Quaternion::Quaternion(const XYZ &R) : x(R.x), y(R.y), z(R.z), w(0.) {}

Quaternion::Quaternion(const XYZ &R, const double &A)
{
  x = R.x * sin(A);
  y = R.y * sin(A);
  z = R.z * sin(A);
  w = cos(A);
}
Quaternion::Quaternion() : x(0.), y(0.), z(0.), w(1.) {}

Quaternion::~Quaternion() {}

Quaternion mult(const Quaternion &A, const Quaternion &B)
{
  Quaternion C;
  C.x = A.w * B.x + A.x * B.w + A.y * B.z - A.z * B.y;
  C.y = A.w * B.y - A.x * B.z + A.y * B.w + A.z * B.x;
  C.z = A.w * B.z + A.x * B.y - A.y * B.x + A.z * B.w;
  C.w = A.w * B.w - A.x * B.x - A.y * B.y - A.z * B.z;
  return C;
}

Quaternion operator*(const Quaternion &A, const Quaternion &B)
{
  return mult(A, B);
}

Quaternion conjugate(Quaternion quat)
{
  quat.x = -quat.x;
  quat.y = -quat.y;
  quat.z = -quat.z;
  return quat;
}
