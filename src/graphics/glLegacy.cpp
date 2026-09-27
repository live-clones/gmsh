// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// WebGL (WebGL 2, OpenGL ES 3.0) has none of the fixed function pipeline and
// no feedback mode: what the inline wrappers of glImmediate.h and the other
// fixed function branches call is left empty, as these are only reached when
// the shader pipeline is off, which a WebGL context never is. The vector
// output of gl2ps, which needs the feedback mode, is not available.

#if defined(__EMSCRIPTEN__)

#include <GL/gl.h>

extern "C" {

void glGetDoublev(GLenum pname, GLdouble *params) {}
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top,
             GLdouble near_val, GLdouble far_val)
{
}
void glRasterPos2d(GLdouble x, GLdouble y) {}
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {}
void glVertex2d(GLdouble x, GLdouble y) {}
void glVertex2i(GLint x, GLint y) {}
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {}
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {}
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {}
void glNormal3dv(const GLdouble *v) {}
void glTexCoord2f(GLfloat s, GLfloat t) {}
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {}
void glEnd(void) {}
void glColorMaterial(GLenum face, GLenum mode) {}
void glColorPointer(GLint size, GLenum type, GLsizei stride,
                    const GLvoid *ptr)
{
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *ptr) {}
void glEnableClientState(GLenum cap) {}
void glDisableClientState(GLenum cap) {}
void glLightModelf(GLenum pname, GLfloat param) {}
void glLightModelfv(GLenum pname, const GLfloat *params) {}
void glLightfv(GLenum light, GLenum pname, const GLfloat *params) {}
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {}
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {}
void glShadeModel(GLenum mode) {}
void glPolygonMode(GLenum face, GLenum mode) {}
void glClipPlane(GLenum plane, const GLdouble *equation) {}
void glLineStipple(GLint factor, GLushort pattern) {}
void glLoadMatrixd(const GLdouble *m) {}
void glPointSize(GLfloat size) {}
void glTexEnvi(GLenum target, GLenum pname, GLint param) {}
void glPushAttrib(GLbitfield mask) {}
void glPopAttrib(void) {}
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) {}
void glPassThrough(GLfloat token) {}
GLint glRenderMode(GLenum mode) { return 0; }

} // extern "C"

#endif
