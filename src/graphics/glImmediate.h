// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL_IMMEDIATE_H
#define GL_IMMEDIATE_H

#include "glApi.h"

// Immediate mode drawing (glBegin/glVertex/glEnd and the state that goes
// with it) behind functions of our own. The decorations of the scene (axes,
// scales, graphs, glyphs, lasso, plugins) are drawn this way; only the mesh
// and the views use vertex arrays. With the fixed function pipeline each
// call is the OpenGL 1.1 call it is named after; the shader pipeline, which
// has no immediate mode, collects the vertices with their colour and normal
// and draws them in batches.

// is the shader pipeline drawing? The calls below then collect the vertices
// and remember the state instead of handing them to OpenGL.
bool gmshUseShaders();

// true while a primitive is being collected for the shader pipeline
extern bool gmshCollecting;

// hand the shader program the state the fixed function pipeline kept itself
// (matrices, lighting, colour, point size, material, clipping planes);
// everything that draws through the program calls this first
void gmshPushShaderState();

// draw the pending immediate mode primitives; anything that changes how
// they would be drawn, or that draws by another route, must call this first
void gmshFlushImmediate();

// what gmshBegin() and gmshEnd() do when collecting; gmshImBegin() returns
// false if it did not take the primitive
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

// every colour goes through this one, which remembers it (a core profile
// has no current colour to query)
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
// set the current colour from four bytes; does nothing during a colour
// picking pass, where the colour encodes the object instead
void gmshColor4ubv(const void *col);
// set the identifier colour of a picking pass; only
// drawContext::setPickColor() and unsetPickColor() should call this
inline void gmshPickColor4ubv(const void *col)
{
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

// what a texture means: the alpha of the current colour (a string, as
// GL_MODULATE) or the colour itself (an image, as GL_REPLACE)
enum gmshTextureMode { GMSH_TEXTURE_NONE = 0, GMSH_TEXTURE_ALPHA = 1,
                       GMSH_TEXTURE_IMAGE = 2 };

// the texture the primitives after this are drawn through, zero for none
// (the shader pipeline needs it said, not only bound)
void gmshTexture(unsigned int id, int mode = GMSH_TEXTURE_ALPHA);
unsigned int gmshCurrentTexture();

// The fixed function state that decides how primitives are drawn and that
// the shader pipeline has to carry itself: lighting, line width, point size,
// dash pattern, polygon mode. The queries go through here too, as a core
// profile cannot answer them.
void gmshLighting(bool on);
bool gmshLightingEnabled();

// light the back faces as well, with the normal flipped
void gmshLightTwoSide(bool on);
bool gmshLightTwoSideEnabled();

// the line width; a core profile draws every line one pixel wide, so the
// shader pipeline makes wider lines out of triangles
void gmshLineWidth(double w);
double gmshCurrentLineWidth();
void gmshPointSize(double s);
double gmshCurrentPointSize();

// multiplies the alpha of every colour drawn afterwards (the Transparency
// options; ignored by the fixed function pipeline); filledOnly leaves lines
// and points opaque
void gmshAlphaScale(double s, bool filledOnly);
double gmshCurrentAlphaScale();
// the scale that applies to this primitive, given filledOnly
double gmshAlphaScaleFor(unsigned int primitive);

// a factor and a 16 bit pattern as glLineStipple takes them; a core profile
// has no stipple, so the shader discards the fragments in a hole of the
// pattern from their distance along the line
void gmshLineStipple(int factor, unsigned short pattern);
void gmshLineStippleOff();
// the current pattern, for whoever draws a vertex array and has to compute
// the distances along the line itself
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
  // a compatibility profile answers with two values (front and back), a
  // core profile with one
  GLint mode[2] = {GL_FILL, GL_FILL};
  glGetIntegerv(GL_POLYGON_MODE, mode);
  return mode[0] == GL_FILL;
}

// The projection and modelview matrices and their stacks, kept by us as a
// core profile has no matrix stack: column major as in glMatrix and OpenGL,
// and a composition multiplies the current matrix on the right. The fixed
// function pipeline is handed the matrices as they change, the shader
// pipeline gets them as uniforms.
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
// the six clipping planes, given in the coordinates of the current modelview
// as glClipPlane() takes them, and kept in eye coordinates
void gmshClipPlane(int i, const double plane[4]);
void gmshClipPlaneOn(int i, bool on);
bool gmshClipPlaneEnabled(int i);
// the plane in eye coordinates, which is what a shader is handed
const double *gmshClipPlaneEye(int i);

// forget the stacks and the state above (e.g. after the OpenGL context was
// recreated)
void gmshResetMatrices();

#endif
