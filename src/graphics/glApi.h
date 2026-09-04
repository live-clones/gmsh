// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL_API_H
#define GL_API_H

// The OpenGL headers, together with the entry points that came after OpenGL
// 1.1. Windows only exports OpenGL 1.1 from opengl32.dll, so anything newer has
// to be asked for at runtime, once a context is current; the other platforms
// declare and export them, and the pointers below are simply set to the linked
// symbols. Going through pointers on all platforms keeps the call sites
// identical, and gives one place to ask whether a feature is really there.

#if defined(WIN32)
#include <windows.h>
#undef min
#undef max
#endif

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
// ask the system headers for the prototypes of what came after OpenGL 1.1, in
// particular the buffer objects (OpenGL 1.5)
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glu.h>
#endif

// the Windows OpenGL header stops at 1.1: it declares neither the types nor the
// enums of the buffer objects
#if defined(WIN32) && !defined(GL_ARRAY_BUFFER)
#include <cstddef>
typedef std::ptrdiff_t GLsizeiptr;
typedef std::ptrdiff_t GLintptr;
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_STATIC_DRAW 0x88E4
#endif

#if !defined(APIENTRY)
#define APIENTRY
#endif

namespace glApi {
  // buffer objects (OpenGL 1.5)
  extern void(APIENTRY *GenBuffers)(GLsizei n, GLuint *buffers);
  extern void(APIENTRY *DeleteBuffers)(GLsizei n, const GLuint *buffers);
  extern void(APIENTRY *BindBuffer)(GLenum target, GLuint buffer);
  extern void(APIENTRY *BufferData)(GLenum target, GLsizeiptr size,
                                    const GLvoid *data, GLenum usage);

  // Resolve the entry points. An OpenGL context must be current. Does nothing
  // once it has run, until reset() is called.
  void load();
  // Forget the resolved entry points, e.g. because the context was recreated.
  void reset();
  // Are buffer objects usable in the current context?
  bool haveBufferObjects();
} // namespace glApi

#endif
