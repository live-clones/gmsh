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

inline void gmshBegin(GLenum mode) { glBegin(mode); }
inline void gmshEnd() { glEnd(); }

inline void gmshVertex2d(double x, double y) { glVertex2d(x, y); }
inline void gmshVertex2f(float x, float y) { glVertex2f(x, y); }
inline void gmshVertex2i(int x, int y) { glVertex2i(x, y); }
inline void gmshVertex3d(double x, double y, double z) { glVertex3d(x, y, z); }
inline void gmshVertex3f(float x, float y, float z) { glVertex3f(x, y, z); }
inline void gmshVertex3i(int x, int y, int z) { glVertex3i(x, y, z); }
inline void gmshVertex3fv(const float *v) { glVertex3fv(v); }

inline void gmshNormal3d(double x, double y, double z) { glNormal3d(x, y, z); }
inline void gmshNormal3dv(const double *v) { glNormal3dv(v); }

inline void gmshColor3d(double r, double g, double b) { glColor3d(r, g, b); }
inline void gmshColor3f(float r, float g, float b) { glColor3f(r, g, b); }
inline void gmshColor3ub(unsigned char r, unsigned char g, unsigned char b)
{
  glColor3ub(r, g, b);
}
inline void gmshColor4f(float r, float g, float b, float a)
{
  glColor4f(r, g, b, a);
}
inline void gmshColor4dv(const double *c) { glColor4dv(c); }
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
  glColor4ubv((const GLubyte *)col);
}

inline void gmshTexCoord2f(float s, float t) { glTexCoord2f(s, t); }

// The pieces of fixed function state that decide how the primitives above are
// drawn, and that a shader pipeline has to carry itself: whether the vertices
// are lit, how wide a line and how big a point is, the dash pattern of the
// lines, and whether the polygons are filled or drawn as their edges. Each of
// them either has no core profile equivalent at all (the lighting, the
// stipple), or none on OpenGL ES (the polygon mode, the point size).
//
// A few of them are asked for as well as set, to be put back afterwards; the
// query goes through here too, as a core profile cannot answer it either.
inline void gmshLighting(bool on)
{
  if(on)
    glEnable(GL_LIGHTING);
  else
    glDisable(GL_LIGHTING);
}
inline bool gmshLightingEnabled() { return glIsEnabled(GL_LIGHTING) ? true : false; }

// light the back faces as well as the front ones, with the normal flipped:
// what a shader has to do from gl_FrontFacing, and what decides whether a face
// seen from behind comes out lit or dark
inline void gmshLightTwoSide(bool on)
{
  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, on ? GL_TRUE : GL_FALSE);
}
inline bool gmshLightTwoSideEnabled()
{
  GLboolean b = GL_FALSE;
  glGetBooleanv(GL_LIGHT_MODEL_TWO_SIDE, &b);
  return b ? true : false;
}

inline void gmshLineWidth(double w) { glLineWidth((float)w); }
inline void gmshPointSize(double s) { glPointSize((float)s); }

// a factor and a 16 bit pattern, as glLineStipple takes them
inline void gmshLineStipple(int factor, unsigned short pattern)
{
  glLineStipple(factor, pattern);
  glEnable(GL_LINE_STIPPLE);
}
inline void gmshLineStippleOff() { glDisable(GL_LINE_STIPPLE); }

inline void gmshPolygonFill(bool fill)
{
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
// forget the stacks, e.g. because the OpenGL context was recreated
void gmshResetMatrices();

#endif
