// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL_IMMEDIATE_H
#define GL_IMMEDIATE_H

#include "glApi.h"

// Immediate mode drawing - a primitive opened with a mode, a run of vertices
// each carrying the colour and the normal that were current when it was given,
// and the primitive closed again - behind functions of our own.
//
// The decorations of the scene are drawn this way: the axes, the scales, the
// graphs, the glyphs, the lasso, everything a plugin draws. Only the mesh and
// the views go through vertex arrays, and they are the exception rather than
// the rule.
//
// A shader pipeline has no immediate mode at all: the calls below are the
// whole of what it has to reproduce, and they are named rather than made
// directly so that there is one place to do it in. For now each of them is the
// OpenGL 1.1 call it is named after, so that going through them changes
// nothing; what a shader pipeline would do instead is collect the vertices,
// with the colour and the normal current at each of them, into a buffer that
// gmshEnd() draws in one call.
//
// The variants are those the drawing code uses, and no others: adding one is
// adding a line here and a line in whichever pipeline is drawing.

// Is the shader pipeline the one drawing? It has no immediate mode, so the
// calls below collect the vertices instead of handing them over one at a time,
// and the state they are drawn with is remembered rather than left to OpenGL.
bool gmshUseShaders();

// True while a primitive is being collected for the shader pipeline. The calls
// below are on the path of every decoration Gmsh draws, so the test is here
// and the collecting itself is not.
extern bool gmshCollecting;

// Hand the shader program the state the fixed function pipeline kept for
// itself: the two matrices, the lighting, the colour, the point size, the
// material and the clipping planes. Everything that draws through the program
// calls this first.
void gmshPushShaderState();

// Draw whatever immediate mode primitives are waiting. Anything that changes
// how they would be drawn - the state, the matrices - and anything that draws
// by another route has to call this first, so that what is on the screen is in
// the order it was asked for.
void gmshFlushImmediate();

// what gmshBegin() and gmshEnd() do when they are collecting; gmshImBegin()
// says whether it took the primitive
bool gmshImBegin(GLenum mode);
void gmshImEnd();
void gmshImVertex(float x, float y, float z);
void gmshImNormal(float x, float y, float z);
void gmshImTexCoord(float s, float t);

inline void gmshBegin(GLenum mode)
{
  if(!gmshImBegin(mode)) glBegin(mode);
}
inline void gmshEnd()
{
  if(gmshCollecting)
    gmshImEnd();
  else
    glEnd();
}

inline void gmshVertex2d(double x, double y)
{
  if(gmshCollecting)
    gmshImVertex((float)x, (float)y, 0.f);
  else
    glVertex2d(x, y);
}
inline void gmshVertex2f(float x, float y)
{
  if(gmshCollecting)
    gmshImVertex(x, y, 0.f);
  else
    glVertex2f(x, y);
}
inline void gmshVertex2i(int x, int y)
{
  if(gmshCollecting)
    gmshImVertex((float)x, (float)y, 0.f);
  else
    glVertex2i(x, y);
}
inline void gmshVertex3d(double x, double y, double z)
{
  if(gmshCollecting)
    gmshImVertex((float)x, (float)y, (float)z);
  else
    glVertex3d(x, y, z);
}
inline void gmshVertex3f(float x, float y, float z)
{
  if(gmshCollecting)
    gmshImVertex(x, y, z);
  else
    glVertex3f(x, y, z);
}
inline void gmshVertex3i(int x, int y, int z)
{
  if(gmshCollecting)
    gmshImVertex((float)x, (float)y, (float)z);
  else
    glVertex3i(x, y, z);
}
inline void gmshVertex3fv(const float *v)
{
  if(gmshCollecting)
    gmshImVertex(v[0], v[1], v[2]);
  else
    glVertex3fv(v);
}

inline void gmshNormal3d(double x, double y, double z)
{
  if(gmshCollecting)
    gmshImNormal((float)x, (float)y, (float)z);
  else
    glNormal3d(x, y, z);
}
inline void gmshNormal3dv(const double *v)
{
  if(gmshCollecting)
    gmshImNormal((float)v[0], (float)v[1], (float)v[2]);
  else
    glNormal3dv(v);
}

// Every colour goes through this one, which remembers it: a shader is handed
// the current colour as a uniform, and there is no fixed function state to ask
// for it in a core profile.
void gmshColor4ub(unsigned char r, unsigned char g, unsigned char b,
                  unsigned char a);
// the colour that is current, as four bytes
const unsigned char *gmshCurrentColor();

inline unsigned char gmshColorByte(double v)
{
  double c = v * 255. + 0.5;
  return (unsigned char)((c < 0.) ? 0. : (c > 255.) ? 255. : c);
}
inline void gmshColor3d(double r, double g, double b)
{
  gmshColor4ub(gmshColorByte(r), gmshColorByte(g), gmshColorByte(b), 255);
}
inline void gmshColor3f(float r, float g, float b)
{
  gmshColor4ub(gmshColorByte(r), gmshColorByte(g), gmshColorByte(b), 255);
}
inline void gmshColor3ub(unsigned char r, unsigned char g, unsigned char b)
{
  gmshColor4ub(r, g, b, 255);
}
inline void gmshColor4f(float r, float g, float b, float a)
{
  gmshColor4ub(gmshColorByte(r), gmshColorByte(g), gmshColorByte(b),
               gmshColorByte(a));
}
inline void gmshColor4dv(const double *c)
{
  gmshColor4ub(gmshColorByte(c[0]), gmshColorByte(c[1]), gmshColorByte(c[2]),
               gmshColorByte(c[3]));
}
// Set the current colour from four bytes, as the object is displayed. During a
// colour picking pass the colour encodes the object being drawn instead, and
// must not be overwritten by the colour it is normally displayed with, so this
// one does nothing at all while such a pass is running: it is what everything
// that draws into the scene uses.
void gmshColor4ubv(const void *col);
// Set the identifier colour of a picking pass, which is the one thing that has
// to be written while such a pass is running. Only drawContext::setPickColor()
// and unsetPickColor() have any business calling this.
inline void gmshPickColor4ubv(const void *col)
{
  // the unconditional setter: it is the one colour a picking pass does write,
  // and the shader is handed it the same way as any other
  const unsigned char *c = (const unsigned char *)col;
  gmshColor4ub(c[0], c[1], c[2], c[3]);
}

inline void gmshTexCoord2f(float s, float t)
{
  if(gmshCollecting)
    gmshImTexCoord(s, t);
  else
    glTexCoord2f(s, t);
}

// What the texture says about the pixels it covers: a string is a picture of
// how much of the current colour each of them gets, an image is the colour
// itself. These are what GL_MODULATE and GL_REPLACE did.
enum gmshTextureMode { GMSH_TEXTURE_NONE = 0, GMSH_TEXTURE_ALPHA = 1,
                       GMSH_TEXTURE_IMAGE = 2 };

// The texture the primitives after this are drawn through, zero for none.
// This is what draws a string: the widget toolkit writes it into a picture,
// and the picture is put on a quad. A shader pipeline is handed the texture
// with the primitives, so it has to be said rather than only bound.
void gmshTexture(unsigned int id, int mode = GMSH_TEXTURE_ALPHA);
unsigned int gmshCurrentTexture();

// The pieces of fixed function state that decide how the primitives above are
// drawn, and that a shader pipeline has to carry itself: whether the vertices
// are lit, how wide a line and how big a point is, the dash pattern of the
// lines, and whether the polygons are filled or drawn as their edges. Each of
// them either has no core profile equivalent at all (the lighting, the
// stipple), or none on OpenGL ES (the polygon mode, the point size).
//
// A few of them are asked for as well as set, to be put back afterwards; the
// query goes through here too, as a core profile cannot answer it either.
void gmshLighting(bool on);
bool gmshLightingEnabled();

// light the back faces as well as the front ones, with the normal flipped:
// what a shader has to do from gl_FrontFacing, and what decides whether a face
// seen from behind comes out lit or dark
void gmshLightTwoSide(bool on);
bool gmshLightTwoSideEnabled();

// The width a line is drawn with. A core profile draws them all one pixel
// wide, so under the shader pipeline this is remembered and a wider line is
// made of triangles instead.
void gmshLineWidth(double w);
double gmshCurrentLineWidth();
void gmshPointSize(double s);
double gmshCurrentPointSize();

// A factor and a 16 bit pattern, as glLineStipple takes them: the pattern
// runs along the line, a bit every factor pixels of it. A core profile has no
// stipple, so a shader is told how far along its line each fragment is and
// throws away the ones the pattern has a hole at.
void gmshLineStipple(int factor, unsigned short pattern);
void gmshLineStippleOff();
// Which pattern is on, if any. A vertex array is drawn straight from its
// buffer instead of being collected, so whoever draws one has to ask for the
// pattern and work out the distances along the line itself.
bool gmshLineStippleEnabled();
int gmshLineStippleFactor();
unsigned short gmshLineStipplePattern();

inline void gmshPolygonFill(bool fill)
{
  if(gmshUseShaders()) gmshFlushImmediate();
  glPolygonMode(GL_FRONT_AND_BACK, fill ? GL_FILL : GL_LINE);
}
inline bool gmshPolygonFilled()
{
  GLint mode[2];
  glGetIntegerv(GL_POLYGON_MODE, mode);
  // the back mode, which is the one the callers put back
  return mode[1] == GL_FILL;
}

// The projection and the modelview matrix, and the stack the drawing code
// saves them on while it draws something in a space of its own - the
// background, the 2D overlay, a glyph in its own frame.
//
// glMatrix already computes the camera transformations; what is left here is
// the state OpenGL was keeping on top of them, which a core profile does not
// keep either: which of the two matrices the calls apply to, the stack, and
// the compositions (translate, scale, rotate) the glyph drawing does. The
// matrices are ours, and are handed to OpenGL as they change; a shader
// pipeline would put them in a uniform instead.
//
// Layout and conventions are those of glMatrix and of OpenGL: column major,
// and a composition multiplies the current matrix on the right, so that it
// applies to the point first.
enum { GMSH_MODELVIEW = 0, GMSH_PROJECTION = 1 };

void gmshMatrixMode(int kind);
int gmshMatrixMode();
void gmshPushMatrix();
void gmshPopMatrix();
void gmshLoadIdentity();
void gmshLoadMatrix(const double m[16]);
void gmshMultMatrix(const double m[16]);
void gmshTranslate(double x, double y, double z);
void gmshScale(double x, double y, double z);
void gmshRotate(double angle, double x, double y, double z);
// the current matrix of either stack
const double *gmshMatrix(int kind);
// The six clipping planes. A plane is given in the coordinates of whatever
// the current modelview matrix is, as glClipPlane() takes it, and is kept in
// eye coordinates, which is where both pipelines clip with it.
void gmshClipPlane(int i, const double plane[4]);
void gmshClipPlaneOn(int i, bool on);
bool gmshClipPlaneEnabled(int i);
// the plane in eye coordinates, which is what a shader is handed
const double *gmshClipPlaneEye(int i);

// forget the stacks and the state above, e.g. because the OpenGL context was
// recreated: it belonged to it
void gmshResetMatrices();

#endif
