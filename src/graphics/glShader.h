// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL_SHADER_H
#define GL_SHADER_H

#include "glApi.h"

// The program the shader pipeline draws everything with, and the state it is
// given.
//
// There is one program rather than one per kind of primitive: what the fixed
// function pipeline did to a vertex is a single computation with a handful of
// switches in it - is it lit, does the colour come from the array or from a
// uniform, is it being drawn in a colour that encodes it for picking - and
// making those switches uniforms costs less than changing programs would.
//
// What it has to reproduce is the fixed function pipeline as Gmsh configured
// it, and nothing more:
//
//  - the material ambient and diffuse colours follow the current colour
//    (GL_COLOR_MATERIAL on GL_AMBIENT_AND_DIFFUSE), the specular colour is
//    grey at General.Shininess and the exponent is General.ShininessExponent;
//  - the global ambient light is 0.2, which is the OpenGL default and which
//    Gmsh never changes;
//  - up to six lights, each with its own ambient, diffuse and specular colour,
//    positional or directional according to the w of its position. The
//    positions are given in eye coordinates: the caller transforms them the
//    way initRenderModel() did, by the scale and the translation alone, so
//    that the lights follow neither the rotation nor the camera;
//  - an infinite viewer, i.e. the half vector is taken against (0, 0, 1)
//    rather than against the direction to the vertex;
//  - two-sided lighting when it is on: a back face is lit with its normal
//    flipped, which is what keeps a face seen from behind from coming out
//    dark. Which side a fragment is on comes from gl_FrontFacing;
//  - the normals are normalized, as GL_NORMALIZE asked;
//  - the six clipping planes, given in eye coordinates.
//
// The one thing it does differently is the clipping: gl_ClipDistance is not in
// OpenGL ES before 3.2, so the distances are interpolated and the fragment is
// discarded. The cut is then rasterized rather than geometric, which shows as
// partial pixels along it, and more so with multisampling.

namespace glShader {
  // where the vertex, normal and colour arrays are bound
  enum { ATTRIB_VERTEX = 0, ATTRIB_NORMAL = 1, ATTRIB_COLOR = 2 };

  // Compile and link the program if that has not been done for this context,
  // and make it current. False if there is no program to be had, in which case
  // nothing has been changed and the caller has to draw some other way.
  bool use();
  // Forget the program and the vertex array object, e.g. because the OpenGL
  // context was recreated. They belong to it.
  void reset();
  // Is there a working program? Compiles it if necessary, and says why not if
  // there is not.
  bool available();

  // the two matrices, in the column major layout glMatrix uses
  void setMatrices(const double modelview[16], const double projection[16]);
  // light i, with its position already in eye coordinates; a null colour is
  // black. Lights that are not set are off.
  void setLight(int i, const double position[4], const float ambient[3],
                const float diffuse[3], const float specular[3]);
  void setLightOff(int i);
  // the specular colour and exponent of the material
  void setMaterial(double shine, double shineExponent);
  // is what is drawn next lit, and are its back faces lit as well?
  void setLighting(bool on, bool twoSide);
  // clip plane i, in eye coordinates; setClipPlaneOff() stops clipping with it
  void setClipPlane(int i, const double plane[4]);
  void setClipPlaneOff(int i);
  // does the colour come from the array, or is it the one colour given here?
  void setColorArray(bool on);
  void setColor(const unsigned char color[4]);
  // the size points are drawn at, which a core profile takes from the shader
  void setPointSize(double size);
} // namespace glShader

#endif
