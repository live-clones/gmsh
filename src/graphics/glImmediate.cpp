// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>

#include "glImmediate.h"
#include "glMatrix.h"
#include "drawContext.h"

void gmshColor4ubv(const void *col)
{
  if(!drawContext::pickColorActive()) glColor4ubv((const GLubyte *)col);
}

namespace {
  // one stack per matrix, each holding at least the matrix itself
  class MatrixStack {
  public:
    std::vector<double> m;
    MatrixStack() : m(16) { glMatrix::identity(&m[0]); }
    double *top() { return &m[m.size() - 16]; }
    void push() { m.insert(m.end(), top(), top() + 16); }
    void pop()
    {
      if(m.size() > 16) m.resize(m.size() - 16);
    }
  };
  MatrixStack _stack[2];
  int _mode = GMSH_MODELVIEW;

  // hand the current matrix to OpenGL, which is where the fixed function
  // pipeline reads it
  void _apply(int kind)
  {
    glMatrixMode(kind == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
    glLoadMatrixd(_stack[kind].top());
    if(kind != _mode)
      glMatrixMode(_mode == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
  }
} // namespace

void gmshMatrixMode(int kind)
{
  _mode = (kind == GMSH_PROJECTION) ? GMSH_PROJECTION : GMSH_MODELVIEW;
  glMatrixMode(_mode == GMSH_PROJECTION ? GL_PROJECTION : GL_MODELVIEW);
}

int gmshMatrixMode() { return _mode; }

void gmshPushMatrix() { _stack[_mode].push(); }

void gmshPopMatrix()
{
  _stack[_mode].pop();
  _apply(_mode);
}

void gmshLoadIdentity()
{
  glMatrix::identity(_stack[_mode].top());
  _apply(_mode);
}

void gmshLoadMatrix(const double m[16])
{
  for(int i = 0; i < 16; i++) _stack[_mode].top()[i] = m[i];
  _apply(_mode);
}

void gmshMultMatrix(const double m[16])
{
  double out[16];
  glMatrix::multiply(_stack[_mode].top(), m, out);
  gmshLoadMatrix(out);
}

void gmshTranslate(double x, double y, double z)
{
  double t[16];
  glMatrix::translate(x, y, z, t);
  gmshMultMatrix(t);
}

void gmshScale(double x, double y, double z)
{
  double s[16];
  glMatrix::scale(x, y, z, s);
  gmshMultMatrix(s);
}

void gmshRotate(double angle, double x, double y, double z)
{
  double r[16];
  glMatrix::rotate(angle, x, y, z, r);
  gmshMultMatrix(r);
}

const double *gmshMatrix(int kind)
{
  return _stack[(kind == GMSH_PROJECTION) ? GMSH_PROJECTION : GMSH_MODELVIEW]
    .top();
}

void gmshResetMatrices()
{
  for(int i = 0; i < 2; i++) {
    _stack[i].m.resize(16);
    glMatrix::identity(&_stack[i].m[0]);
  }
  _mode = GMSH_MODELVIEW;
}
