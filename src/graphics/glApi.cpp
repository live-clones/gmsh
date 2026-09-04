// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdint>

#include "glApi.h"
#include "GmshMessage.h"

namespace glApi {
  void(APIENTRY *GenBuffers)(GLsizei, GLuint *) = nullptr;
  void(APIENTRY *DeleteBuffers)(GLsizei, const GLuint *) = nullptr;
  void(APIENTRY *BindBuffer)(GLenum, GLuint) = nullptr;
  void(APIENTRY *BufferData)(GLenum, GLsizeiptr, const GLvoid *,
                             GLenum) = nullptr;

  static bool _loaded = false, _buffers = false;

#if defined(WIN32)
  static void *address(const char *name)
  {
    PROC p = wglGetProcAddress(name);
    // wglGetProcAddress reports failure with a handful of values, and never
    // returns the OpenGL 1.1 entry points: those live in opengl32.dll itself
    std::intptr_t v = (std::intptr_t)p;
    if(v == 0 || v == 1 || v == 2 || v == 3 || v == -1) {
      HMODULE h = GetModuleHandleA("opengl32.dll");
      p = h ? GetProcAddress(h, name) : nullptr;
    }
    // through a data pointer: casting straight from PROC to the real signature
    // is a cast between incompatible function types, which compilers warn about
    return (void *)p;
  }
#endif

  void load()
  {
    if(_loaded) return;
    _loaded = true;
#if defined(WIN32)
    GenBuffers = (void(APIENTRY *)(GLsizei, GLuint *))address("glGenBuffers");
    DeleteBuffers =
      (void(APIENTRY *)(GLsizei, const GLuint *))address("glDeleteBuffers");
    BindBuffer = (void(APIENTRY *)(GLenum, GLuint))address("glBindBuffer");
    BufferData = (void(APIENTRY *)(GLenum, GLsizeiptr, const GLvoid *,
                                   GLenum))address("glBufferData");
#else
    GenBuffers = ::glGenBuffers;
    DeleteBuffers = ::glDeleteBuffers;
    BindBuffer = ::glBindBuffer;
    BufferData = ::glBufferData;
#endif
    _buffers = GenBuffers && DeleteBuffers && BindBuffer && BufferData;
    Msg::Debug("OpenGL buffer objects are %s",
               _buffers ? "available" : "not available");
  }

  void reset()
  {
    _loaded = _buffers = false;
    GenBuffers = nullptr;
    DeleteBuffers = nullptr;
    BindBuffer = nullptr;
    BufferData = nullptr;
  }

  bool haveBufferObjects()
  {
    load();
    return _buffers;
  }
} // namespace glApi
