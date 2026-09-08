// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL_SHADER_H
#define GL_SHADER_H

#include "glApi.h"

// The single program the shader pipeline draws with. The fixed function
// computation is one calculation with a few switches (lit or not, colour from
// the array or from a uniform, picking colour), so the switches are uniforms
// rather than separate programs.
//
// It reproduces the fixed function pipeline as Gmsh configured it: colour
// material on ambient and diffuse, grey specular at General.Shininess with
// exponent General.ShininessExponent, global ambient 0.2 (the OpenGL
// default), up to six lights in eye coordinates, an infinite viewer (half
// vector against (0, 0, 1)), two-sided lighting from gl_FrontFacing,
// normalized normals and six clipping planes in eye coordinates.
//
// Clipping differs: gl_ClipDistance is not in OpenGL ES before 3.2, so the
// distance is interpolated and the fragment discarded, which makes the cut
// slightly rasterized rather than geometric.

namespace glShader {
  // attribute locations: the vertex, normal and colour arrays, and the per
  // glyph transform and parameters of instanced drawing
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
    // the far end of a wide line, with its normal and colour
    ATTRIB_VERTEXB = 9,
    ATTRIB_NORMALB = 10,
    ATTRIB_COLORB = 11
  };

  // Compile, link and use the program; false if none can be had, in which
  // case the caller must draw some other way.
  bool use();
  // forget the program and the vertex array object (e.g. after the OpenGL
  // context was recreated)
  void reset();
  // is there a working program? Compiles it if necessary and says why not
  bool available();

  // the two matrices, in the column major layout glMatrix uses
  void setMatrices(const double modelview[16], const double projection[16]);
  // light i, position in eye coordinates; null colours are black, lights
  // that are not set are off
  void setLight(int i, const double position[4], const float ambient[3],
                const float diffuse[3], const float specular[3]);
  void setLightOff(int i);
  // the specular colour and exponent of the material
  void setMaterial(double shine, double shineExponent);
  // the lighting model: 0 the fixed function one, 1 studio
  void setShading(int model);
  // is what is drawn next lit, and are its back faces lit as well?
  void setLighting(bool on, bool twoSide);
  // clip plane i, in eye coordinates; setClipPlaneOff() stops clipping with it
  void setClipPlane(int i, const double plane[4]);
  void setClipPlaneOff(int i);
  // does the colour come from the array, or is it the one colour given here?
  void setColorArray(bool on);
  void setColor(const unsigned char color[4]);
  // the point size, which a core profile takes from the shader
  void setPointSize(double size);
  // multiplies the alpha of everything drawn afterwards (the Transparency
  // options)
  void setAlphaScale(double scale);
  // Upload client arrays into buffers of ours and bind them (a core profile
  // cannot read client memory). Null colours use the current colour.
  void streamArrays(const float *vertices, const unsigned char *colors,
                    int count);
  // Distance along its line of each vertex about to be drawn, in pixels, for
  // the dash pattern; without it the pattern has nothing to measure against.
  void streamDash(const float *dashes, int count);
  // Draw without texture, keeping a valid 1x1 texture bound: a driver
  // validates every sampler of the program at draw time, whether or not its
  // branch is taken.
  void noTexture();

  // Order independent transparency: what is drawn between these two is
  // summed into two buffers (weighted colours, and the log of the light let
  // through) that endTransparent() composites onto the window, so nothing
  // has to be sorted. beginTransparent() returns false if the context cannot
  // do it, and must be called after the opaque geometry, whose depth it
  // copies.
  bool beginTransparent();
  void endTransparent();
  // is the transparent pass being drawn? The drawing code then neither
  // sorts nor sets a blending of its own.
  bool transparentPass();
  // the dash pattern of the lines: a bit every factor pixels along the line,
  // fragments in a hole are discarded
  void setStipple(bool on, int factor, unsigned short pattern);
  // Draw line segments (vertices in pairs) as quads of the given width in
  // pixels, as a core profile draws every line one pixel wide. False if not
  // possible; the caller then draws them thin.
  bool drawWideLines(const float *vertices, const void *normals,
                     GLenum normalType, const unsigned char *colors, int count,
                     double width, bool lit);
  // draw vertices collected from the immediate mode calls, each with its own
  // colour and normal, with whatever state was last set
  void drawImmediate(GLenum mode, const float *vertices, const float *normals,
                     const unsigned char *colors, const float *texCoords,
                     const float *dashes, unsigned int texture, int textureMode,
                     int count);

  // Draw one shape (vertices and normals) once per glyph, each glyph being
  // GLYPH_STRIDE bytes: three rows of four floats of transform, four bytes
  // of colour, two floats of parameters (the radii of a cylinder). taper says
  // the shape is a cylinder; colors takes the colour from the glyphs instead
  // of the current one (picking). False if not possible; the caller then
  // draws the glyphs one at a time.
  enum { GLYPH_STRIDE = 60 };
  bool drawGlyphs(const float *vertices, const float *normals, int numVertices,
                  const void *glyphs, int numGlyphs, bool taper, bool colors);

  // The framebuffer a picking pass draws into: one attachment for the colour
  // encoding the object, one for the depth written as a colour, as OpenGL ES
  // and WebGL cannot read a depth buffer back. bindPickBuffer() returns false
  // if none can be had (the caller then draws into the window);
  // readPickBuffer() returns colours as four bytes and depths as floats in
  // [0, 1]; releasePickBuffer() rebinds the window.
  bool bindPickBuffer(int width, int height);
  void readPickBuffer(int x, int y, int w, int h, unsigned char *colors,
                      float *depths);
  void releasePickBuffer();
} // namespace glShader

#endif
