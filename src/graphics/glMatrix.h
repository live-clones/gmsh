// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL_MATRIX_H
#define GL_MATRIX_H

// The camera transformations, computed here instead of being asked of OpenGL
// and GLU. None of this needs a context: the matrices can be built and used
// before, during or after a frame, and the same code gives the window
// coordinates of a point whether or not there is anything to draw on.
//
// The matrices are 4x4 and stored in the OpenGL column-major layout, i.e.
// m[4 * column + row], so that they can be handed to glLoadMatrixd() as they
// are. Viewports are {x, y, width, height}.

namespace glMatrix {
  void identity(double m[16]);
  // out = a * b, i.e. applied to a point, b first and then a; out may alias
  // neither a nor b
  void multiply(const double a[16], const double b[16], double out[16]);
  // out = m * in, on a homogeneous point
  void transform(const double m[16], const double in[4], double out[4]);
  // Gauss-Jordan with partial pivoting; false if m is singular
  bool invert(const double m[16], double out[16]);
  // The cofactors of a 3x3 matrix, laid out as its inverse transpose is (which
  // they are once divided by the determinant, returned): what transforms the
  // normals when a transforms the points.
  double cofactors(const double a[9], double c[9]);

  void translate(double x, double y, double z, double m[16]);
  void scale(double x, double y, double z, double m[16]);
  // the rotation of angle degrees about the axis (x, y, z), which does not
  // have to be a unit vector
  void rotate(double angle, double x, double y, double z, double m[16]);
  // the rotation taking the z axis to the unit vector v
  void rotateZTo(const double v[3], double m[16]);
  void ortho(double left, double right, double bottom, double top, double zNear,
             double zFar, double m[16]);
  void frustum(double left, double right, double bottom, double top,
               double zNear, double zFar, double m[16]);
  void lookAt(const double eye[3], const double center[3], const double up[3],
              double m[16]);
  // object coordinates to window coordinates and back; false if the point
  // cannot be mapped
  bool project(const double xyz[3], const double model[16],
               const double proj[16], const int viewport[4], double win[3]);
  bool unProject(const double win[3], const double model[16],
                 const double proj[16], const int viewport[4], double xyz[3]);
} // namespace glMatrix

#endif
