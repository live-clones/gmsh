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
  // where the vertex, normal and colour arrays are bound, and where the
  // per glyph transform and parameters are when the same shape is being drawn
  // many times over
  enum {
    ATTRIB_VERTEX = 0,
    ATTRIB_NORMAL = 1,
    ATTRIB_COLOR = 2,
    ATTRIB_GLYPH0 = 3,
    ATTRIB_GLYPH1 = 4,
    ATTRIB_GLYPH2 = 5,
    ATTRIB_GLYPH_PARAM = 6,
    ATTRIB_TEXCOORD = 7,
    ATTRIB_DASH = 8,
    // the far end of a line drawn wide, and what it carries
    ATTRIB_VERTEXB = 9,
    ATTRIB_NORMALB = 10,
    ATTRIB_COLORB = 11
  };

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
  // Upload arrays the caller holds itself into a buffer of ours and bind them:
  // a core profile cannot be handed a pointer into client memory. Colours may
  // be null, in which case the current colour is used for every vertex.
  void streamArrays(const float *vertices, const unsigned char *colors,
                    int count);
  // How far along its line every vertex of what is about to be drawn falls,
  // in pixels, for the dash pattern to be measured against. The arrays carry
  // no such thing, so whoever draws them works it out; nothing to hand over
  // leaves the vertices with no distance and the pattern with nothing to bite
  // on.
  void streamDash(const float *dashes, int count);
  // Draw a run of vertices collected from the immediate mode calls, each with
  // the colour and the normal that were current when it was given. The state
  // it is drawn with - the matrices, the lights, the clipping - is whatever
  // was last set.
  // the dash pattern the lines are drawn with: a bit of it every factor
  // pixels along the line, and a fragment where it has a hole is thrown away
  void setStipple(bool on, int factor, unsigned short pattern);
  // Draw a run of line segments - vertices in pairs - as quads of the given
  // width in pixels. A core profile draws every line one pixel wide whatever
  // it is asked for, so a wide one has to be made of triangles. False if this
  // cannot be done, in which case the caller draws them as lines and they
  // come out thin.
  bool drawWideLines(const float *vertices, const void *normals,
                     GLenum normalType, const unsigned char *colors, int count,
                     double width, bool lit);
  void drawImmediate(GLenum mode, const float *vertices, const float *normals,
                     const unsigned char *colors, const float *texCoords,
                     const float *dashes, unsigned int texture, int count);

  // Draw one shape many times over, each of them placed by a glyph of its
  // own: the shape is given as its vertices and normals, and the glyphs as a
  // buffer of sixty bytes each - three rows of a transform, a colour, and the
  // two radii a cylinder is shaped by. False if this cannot be done, in which
  // case the caller has to draw them one shape at a time.
  //
  // taper says the shape is a cylinder, whose corners the radii move; colors
  // says the colour comes from the glyphs rather than from the one that is
  // current, which is what a picking pass wants.
  // How one glyph is laid out in that buffer: three rows of four floats, then
  // four bytes of colour, then two floats of parameters.
  enum { GLYPH_STRIDE = 60 };
  bool drawGlyphs(const float *vertices, const float *normals, int numVertices,
                  const void *glyphs, int numGlyphs, bool taper, bool colors);

  // The buffer a picking pass draws into: one attachment for the colour that
  // encodes the object, one for the depth written as a colour. Reading a depth
  // buffer back is not something OpenGL ES or WebGL will do, which is why the
  // pass does not simply draw into the window.
  //
  // bindPickBuffer() makes a buffer of that size current and asks for both
  // attachments to be drawn into; false if there is none to be had, in which
  // case the caller draws into the window as before. readPickBuffer() takes a
  // region of it, giving the colours as four bytes each and the depths as
  // floats in [0, 1]. releasePickBuffer() puts the window back.
  bool bindPickBuffer(int width, int height);
  void readPickBuffer(int x, int y, int w, int h, unsigned char *colors,
                      float *depths);
  void releasePickBuffer();
} // namespace glShader

#endif
