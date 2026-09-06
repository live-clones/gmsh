// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <cstring>
#include <utility>

#include "glMatrix.h"

namespace glMatrix {
  static void normalize(double v[3])
  {
    double l = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if(l == 0.) return;
    v[0] /= l;
    v[1] /= l;
    v[2] /= l;
  }

  static void cross(const double a[3], const double b[3], double out[3])
  {
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
  }

  void identity(double m[16])
  {
    std::memset(m, 0, 16 * sizeof(double));
    m[0] = m[5] = m[10] = m[15] = 1.;
  }

  void multiply(const double a[16], const double b[16], double out[16])
  {
    for(int i = 0; i < 4; i++) // column
      for(int j = 0; j < 4; j++) { // row
        double s = 0.;
        for(int k = 0; k < 4; k++) s += a[4 * k + j] * b[4 * i + k];
        out[4 * i + j] = s;
      }
  }

  void transform(const double m[16], const double in[4], double out[4])
  {
    for(int j = 0; j < 4; j++) {
      double s = 0.;
      for(int k = 0; k < 4; k++) s += m[4 * k + j] * in[k];
      out[j] = s;
    }
  }

  bool invert(const double m[16], double out[16])
  {
    // [a | i] reduced to [i | m^-1], in row-major so that the rows the pivoting
    // swaps are contiguous
    double a[4][8];
    for(int j = 0; j < 4; j++) {
      for(int i = 0; i < 4; i++) {
        a[j][i] = m[4 * i + j];
        a[j][4 + i] = (i == j) ? 1. : 0.;
      }
    }
    for(int c = 0; c < 4; c++) {
      int p = c;
      for(int r = c + 1; r < 4; r++)
        if(std::fabs(a[r][c]) > std::fabs(a[p][c])) p = r;
      if(a[p][c] == 0.) return false;
      if(p != c)
        for(int i = 0; i < 8; i++) std::swap(a[p][i], a[c][i]);
      double d = a[c][c];
      for(int i = 0; i < 8; i++) a[c][i] /= d;
      for(int r = 0; r < 4; r++) {
        if(r == c) continue;
        double f = a[r][c];
        if(f == 0.) continue;
        for(int i = 0; i < 8; i++) a[r][i] -= f * a[c][i];
      }
    }
    for(int j = 0; j < 4; j++)
      for(int i = 0; i < 4; i++) out[4 * i + j] = a[j][4 + i];
    return true;
  }

  void translate(double x, double y, double z, double m[16])
  {
    identity(m);
    m[12] = x;
    m[13] = y;
    m[14] = z;
  }

  void scale(double x, double y, double z, double m[16])
  {
    identity(m);
    m[0] = x;
    m[5] = y;
    m[10] = z;
  }

  void rotate(double angle, double x, double y, double z, double m[16])
  {
    identity(m);
    double n = std::sqrt(x * x + y * y + z * z);
    if(n == 0.) return;
    x /= n;
    y /= n;
    z /= n;
    double c = std::cos(angle * M_PI / 180.), s = std::sin(angle * M_PI / 180.);
    double c1 = 1. - c;
    m[0] = x * x * c1 + c;
    m[1] = y * x * c1 + z * s;
    m[2] = x * z * c1 - y * s;
    m[4] = x * y * c1 - z * s;
    m[5] = y * y * c1 + c;
    m[6] = y * z * c1 + x * s;
    m[8] = x * z * c1 + y * s;
    m[9] = y * z * c1 - x * s;
    m[10] = z * z * c1 + c;
  }

  void ortho(double left, double right, double bottom, double top,
             double zNear, double zFar, double m[16])
  {
    identity(m);
    m[0] = 2. / (right - left);
    m[5] = 2. / (top - bottom);
    m[10] = -2. / (zFar - zNear);
    m[12] = -(right + left) / (right - left);
    m[13] = -(top + bottom) / (top - bottom);
    m[14] = -(zFar + zNear) / (zFar - zNear);
  }

  void frustum(double left, double right, double bottom, double top,
               double zNear, double zFar, double m[16])
  {
    std::memset(m, 0, 16 * sizeof(double));
    m[0] = 2. * zNear / (right - left);
    m[5] = 2. * zNear / (top - bottom);
    m[8] = (right + left) / (right - left);
    m[9] = (top + bottom) / (top - bottom);
    m[10] = -(zFar + zNear) / (zFar - zNear);
    m[11] = -1.;
    m[14] = -2. * zFar * zNear / (zFar - zNear);
  }

  void lookAt(const double eye[3], const double center[3], const double up[3],
              double m[16])
  {
    double f[3] = {center[0] - eye[0], center[1] - eye[1], center[2] - eye[2]};
    normalize(f);
    double u[3] = {up[0], up[1], up[2]};
    normalize(u);
    double s[3];
    cross(f, u, s);
    normalize(s);
    cross(s, f, u);

    double r[16];
    identity(r);
    r[0] = s[0]; r[4] = s[1]; r[8] = s[2];
    r[1] = u[0]; r[5] = u[1]; r[9] = u[2];
    r[2] = -f[0]; r[6] = -f[1]; r[10] = -f[2];

    double t[16];
    translate(-eye[0], -eye[1], -eye[2], t);
    multiply(r, t, m);
  }

  void pickRegion(double x, double y, double w, double h, const int viewport[4],
                  double m[16])
  {
    if(w <= 0. || h <= 0.) {
      identity(m);
      return;
    }
    double t[16], s[16];
    translate((viewport[2] - 2. * (x - viewport[0])) / w,
              (viewport[3] - 2. * (y - viewport[1])) / h, 0., t);
    scale(viewport[2] / w, viewport[3] / h, 1., s);
    multiply(t, s, m);
  }

  bool project(const double xyz[3], const double model[16],
               const double proj[16], const int viewport[4], double win[3])
  {
    double in[4] = {xyz[0], xyz[1], xyz[2], 1.}, eye[4], clip[4];
    transform(model, in, eye);
    transform(proj, eye, clip);
    if(clip[3] == 0.) return false;
    clip[0] /= clip[3];
    clip[1] /= clip[3];
    clip[2] /= clip[3];
    win[0] = viewport[0] + viewport[2] * (clip[0] + 1.) / 2.;
    win[1] = viewport[1] + viewport[3] * (clip[1] + 1.) / 2.;
    win[2] = (clip[2] + 1.) / 2.;
    return true;
  }

  bool unProject(const double win[3], const double model[16],
                 const double proj[16], const int viewport[4], double xyz[3])
  {
    double mvp[16], inv[16];
    multiply(proj, model, mvp);
    if(!invert(mvp, inv)) return false;
    double in[4] = {2. * (win[0] - viewport[0]) / viewport[2] - 1.,
                    2. * (win[1] - viewport[1]) / viewport[3] - 1.,
                    2. * win[2] - 1., 1.},
           out[4];
    transform(inv, in, out);
    if(out[3] == 0.) return false;
    xyz[0] = out[0] / out[3];
    xyz[1] = out[1] / out[3];
    xyz[2] = out[2] / out[3];
    return true;
  }
} // namespace glMatrix
