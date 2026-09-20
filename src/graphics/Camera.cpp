// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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

// The camera moved to look along an axis, from the side the model is seen
// from: 0, 1, 2 for x, y, z. Up is the next axis round.
void Camera::alongAxis(int axis)
{
  double f[3] = {0., 0., 0.}, u[3] = {0., 0., 0.};
  f[axis] = -1.;
  u[(axis + 2) % 3] = 1.;
  front.set(f[0], f[1], f[2]);
  up.set(u[0], u[1], u[2]);
  position = target - distance * front;
  update();
}

// Up turned to an axis: to its positive end, unless it is already exactly
// there, in which case it turns over and takes the right hand with it. The
// camera then looks along what the two span.
void Camera::upAxis(int axis)
{
  const double u[3] = {up.x, up.y, up.z};
  double sign = (u[axis] > 0.) ? 1. : -1.;
  bool over = (u[axis] == sign);
  if(over) {
    sign = -sign;
    right = -right;
  }
  double n[3] = {0., 0., 0.};
  n[axis] = sign;
  up.set(n[0], n[1], n[2]);
  front.x = up.y * right.z - up.z * right.y;
  front.y = up.z * right.x - up.x * right.z;
  front.z = up.x * right.y - up.y * right.x;
  target = position + distance * front;
  update();
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

// the turn of an angle about an axis, as a quaternion
static Quaternion turn(double theta, const XYZ &axis)
{
  Quaternion q;
  q.x = sin(theta) * axis.x;
  q.y = sin(theta) * axis.y;
  q.z = sin(theta) * axis.z;
  q.w = cos(theta);
  normalize(q);
  return q;
}

void Camera::move_and_look(double _movfront, double _movright, double _movup,
                           double _thetafront, double _thetaright,
                           double _thetaup, double _azimut, double _elevation)
{
  position = position + _movfront * front + _movright * right + _movup * up;
  Quaternion omega = turn(_thetaup, up) * turn(_thetaright, right) *
                     turn(_thetafront, front);
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
