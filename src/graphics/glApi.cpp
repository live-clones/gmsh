// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdint>
#include <cstdio>
#include <cstring>

#if !defined(WIN32)
#include <dlfcn.h>
#endif

#include "glApi.h"
#include "GmshMessage.h"

namespace glApi {
  void(APIENTRY *GenBuffers)(GLsizei, GLuint *) = nullptr;
  void(APIENTRY *DeleteBuffers)(GLsizei, const GLuint *) = nullptr;
  void(APIENTRY *BindBuffer)(GLenum, GLuint) = nullptr;
  void(APIENTRY *BufferData)(GLenum, GLsizeiptr, const GLvoid *,
                             GLenum) = nullptr;
  void(APIENTRY *BufferSubData)(GLenum, GLintptr, GLsizeiptr,
                                const GLvoid *) = nullptr;

  GLuint(APIENTRY *CreateShader)(GLenum) = nullptr;
  void(APIENTRY *ShaderSource)(GLuint, GLsizei, const GLchar *const *,
                               const GLint *) = nullptr;
  void(APIENTRY *CompileShader)(GLuint) = nullptr;
  void(APIENTRY *GetShaderiv)(GLuint, GLenum, GLint *) = nullptr;
  void(APIENTRY *GetShaderInfoLog)(GLuint, GLsizei, GLsizei *,
                                   GLchar *) = nullptr;
  void(APIENTRY *DeleteShader)(GLuint) = nullptr;
  GLuint(APIENTRY *CreateProgram)(void) = nullptr;
  void(APIENTRY *AttachShader)(GLuint, GLuint) = nullptr;
  void(APIENTRY *LinkProgram)(GLuint) = nullptr;
  void(APIENTRY *GetProgramiv)(GLuint, GLenum, GLint *) = nullptr;
  void(APIENTRY *GetProgramInfoLog)(GLuint, GLsizei, GLsizei *,
                                    GLchar *) = nullptr;
  void(APIENTRY *UseProgram)(GLuint) = nullptr;
  void(APIENTRY *DeleteProgram)(GLuint) = nullptr;
  void(APIENTRY *BindAttribLocation)(GLuint, GLuint, const GLchar *) = nullptr;
  GLint(APIENTRY *GetUniformLocation)(GLuint, const GLchar *) = nullptr;
  void(APIENTRY *Uniform1i)(GLint, GLint) = nullptr;
  void(APIENTRY *Uniform1f)(GLint, GLfloat) = nullptr;
  void(APIENTRY *Uniform1iv)(GLint, GLsizei, const GLint *) = nullptr;
  void(APIENTRY *Uniform1fv)(GLint, GLsizei, const GLfloat *) = nullptr;
  void(APIENTRY *Uniform2fv)(GLint, GLsizei, const GLfloat *) = nullptr;
  void(APIENTRY *Uniform3fv)(GLint, GLsizei, const GLfloat *) = nullptr;
  void(APIENTRY *Uniform4fv)(GLint, GLsizei, const GLfloat *) = nullptr;
  void(APIENTRY *UniformMatrix3fv)(GLint, GLsizei, GLboolean,
                                   const GLfloat *) = nullptr;
  void(APIENTRY *UniformMatrix4fv)(GLint, GLsizei, GLboolean,
                                   const GLfloat *) = nullptr;

  void(APIENTRY *EnableVertexAttribArray)(GLuint) = nullptr;
  void(APIENTRY *DisableVertexAttribArray)(GLuint) = nullptr;
  void(APIENTRY *VertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei,
                                      const GLvoid *) = nullptr;

  void(APIENTRY *GenVertexArrays)(GLsizei, GLuint *) = nullptr;
  void(APIENTRY *DeleteVertexArrays)(GLsizei, const GLuint *) = nullptr;
  void(APIENTRY *BindVertexArray)(GLuint) = nullptr;

  void(APIENTRY *GenFramebuffers)(GLsizei, GLuint *) = nullptr;
  void(APIENTRY *DeleteFramebuffers)(GLsizei, const GLuint *) = nullptr;
  void(APIENTRY *BindFramebuffer)(GLenum, GLuint) = nullptr;
  void(APIENTRY *FramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint,
                                       GLint) = nullptr;
  GLenum(APIENTRY *CheckFramebufferStatus)(GLenum) = nullptr;
  void(APIENTRY *GenRenderbuffers)(GLsizei, GLuint *) = nullptr;
  void(APIENTRY *DeleteRenderbuffers)(GLsizei, const GLuint *) = nullptr;
  void(APIENTRY *BindRenderbuffer)(GLenum, GLuint) = nullptr;
  void(APIENTRY *RenderbufferStorage)(GLenum, GLenum, GLsizei,
                                      GLsizei) = nullptr;
  void(APIENTRY *FramebufferRenderbuffer)(GLenum, GLenum, GLenum,
                                          GLuint) = nullptr;
  void(APIENTRY *DrawBuffers)(GLsizei, const GLenum *) = nullptr;
  void(APIENTRY *BlitFramebuffer)(GLint, GLint, GLint, GLint, GLint, GLint,
                                  GLint, GLint, GLbitfield, GLenum) = nullptr;

  void(APIENTRY *ActiveTexture)(GLenum) = nullptr;

  void(APIENTRY *BlendFunci)(GLuint, GLenum, GLenum) = nullptr;
  void(APIENTRY *BlendEquationi)(GLuint, GLenum) = nullptr;

  static bool _loaded = false, _buffers = false, _shaders = false;
  static bool _framebuffers = false, _clipDistance = false;
  static bool _indexedBlend = false, _es = false;
  static int _major = 0, _minor = 0;

  static void *address(const char *name)
  {
#if defined(WIN32)
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
#else
    // the GL library the program is linked against exports what the driver
    // implements, whether or not the header declared it
    return dlsym(RTLD_DEFAULT, name);
#endif
  }

  // read the "major.minor" a GL_VERSION string starts with; an OpenGL ES
  // string starts with "OpenGL ES " instead
  static void parseVersion(const char *s, int &major, int &minor, bool &es)
  {
    major = minor = 0;
    es = false;
    if(!s) return;
    if(!strncmp(s, "OpenGL ES", 9)) {
      es = true;
      while(*s && (*s < '0' || *s > '9')) s++;
    }
    if(sscanf(s, "%d.%d", &major, &minor) != 2) major = minor = 0;
  }

  static bool haveExtension(const char *name)
  {
    // the core profile dropped the one string that listed them all, and hands
    // them out one at a time instead
    const char *all = (const char *)glGetString(GL_EXTENSIONS);
    if(all) {
      std::size_t n = strlen(name);
      for(const char *p = strstr(all, name); p; p = strstr(p + 1, name)) {
        // a name is a match only if it is a whole word
        if((p == all || p[-1] == ' ') && (p[n] == ' ' || p[n] == '\0'))
          return true;
      }
      return false;
    }
    return false;
  }

  // is the current context at least this version? The two numberings are
  // separate, so this is only ever asked together with isES()
  static bool atLeast(int major, int minor)
  {
    return _major > major || (_major == major && _minor >= minor);
  }

  void load()
  {
    if(_loaded) return;
    _loaded = true;

    GenBuffers = (void(APIENTRY *)(GLsizei, GLuint *))address("glGenBuffers");
    DeleteBuffers =
      (void(APIENTRY *)(GLsizei, const GLuint *))address("glDeleteBuffers");
    BindBuffer = (void(APIENTRY *)(GLenum, GLuint))address("glBindBuffer");
    BufferData = (void(APIENTRY *)(GLenum, GLsizeiptr, const GLvoid *,
                                   GLenum))address("glBufferData");
    BufferSubData = (void(APIENTRY *)(GLenum, GLintptr, GLsizeiptr,
                                      const GLvoid *))address("glBufferSubData");

    CreateShader = (GLuint(APIENTRY *)(GLenum))address("glCreateShader");
    ShaderSource =
      (void(APIENTRY *)(GLuint, GLsizei, const GLchar *const *,
                        const GLint *))address("glShaderSource");
    CompileShader = (void(APIENTRY *)(GLuint))address("glCompileShader");
    GetShaderiv =
      (void(APIENTRY *)(GLuint, GLenum, GLint *))address("glGetShaderiv");
    GetShaderInfoLog = (void(APIENTRY *)(GLuint, GLsizei, GLsizei *,
                                         GLchar *))address("glGetShaderInfoLog");
    DeleteShader = (void(APIENTRY *)(GLuint))address("glDeleteShader");
    CreateProgram = (GLuint(APIENTRY *)(void))address("glCreateProgram");
    AttachShader = (void(APIENTRY *)(GLuint, GLuint))address("glAttachShader");
    LinkProgram = (void(APIENTRY *)(GLuint))address("glLinkProgram");
    GetProgramiv =
      (void(APIENTRY *)(GLuint, GLenum, GLint *))address("glGetProgramiv");
    GetProgramInfoLog =
      (void(APIENTRY *)(GLuint, GLsizei, GLsizei *,
                        GLchar *))address("glGetProgramInfoLog");
    UseProgram = (void(APIENTRY *)(GLuint))address("glUseProgram");
    DeleteProgram = (void(APIENTRY *)(GLuint))address("glDeleteProgram");
    BindAttribLocation = (void(APIENTRY *)(GLuint, GLuint, const GLchar *))
      address("glBindAttribLocation");
    GetUniformLocation = (GLint(APIENTRY *)(GLuint, const GLchar *))
      address("glGetUniformLocation");
    Uniform1i = (void(APIENTRY *)(GLint, GLint))address("glUniform1i");
    Uniform1f = (void(APIENTRY *)(GLint, GLfloat))address("glUniform1f");
    Uniform1iv =
      (void(APIENTRY *)(GLint, GLsizei, const GLint *))address("glUniform1iv");
    Uniform1fv =
      (void(APIENTRY *)(GLint, GLsizei, const GLfloat *))address("glUniform1fv");
    Uniform2fv =
      (void(APIENTRY *)(GLint, GLsizei, const GLfloat *))address("glUniform2fv");
    Uniform3fv =
      (void(APIENTRY *)(GLint, GLsizei, const GLfloat *))address("glUniform3fv");
    Uniform4fv =
      (void(APIENTRY *)(GLint, GLsizei, const GLfloat *))address("glUniform4fv");
    UniformMatrix3fv = (void(APIENTRY *)(GLint, GLsizei, GLboolean,
                                         const GLfloat *))
      address("glUniformMatrix3fv");
    UniformMatrix4fv = (void(APIENTRY *)(GLint, GLsizei, GLboolean,
                                         const GLfloat *))
      address("glUniformMatrix4fv");

    EnableVertexAttribArray =
      (void(APIENTRY *)(GLuint))address("glEnableVertexAttribArray");
    DisableVertexAttribArray =
      (void(APIENTRY *)(GLuint))address("glDisableVertexAttribArray");
    VertexAttribPointer =
      (void(APIENTRY *)(GLuint, GLint, GLenum, GLboolean, GLsizei,
                        const GLvoid *))address("glVertexAttribPointer");

    GenVertexArrays =
      (void(APIENTRY *)(GLsizei, GLuint *))address("glGenVertexArrays");
    DeleteVertexArrays = (void(APIENTRY *)(GLsizei, const GLuint *))
      address("glDeleteVertexArrays");
    BindVertexArray = (void(APIENTRY *)(GLuint))address("glBindVertexArray");

    GenFramebuffers =
      (void(APIENTRY *)(GLsizei, GLuint *))address("glGenFramebuffers");
    DeleteFramebuffers = (void(APIENTRY *)(GLsizei, const GLuint *))
      address("glDeleteFramebuffers");
    BindFramebuffer =
      (void(APIENTRY *)(GLenum, GLuint))address("glBindFramebuffer");
    FramebufferTexture2D =
      (void(APIENTRY *)(GLenum, GLenum, GLenum, GLuint,
                        GLint))address("glFramebufferTexture2D");
    CheckFramebufferStatus =
      (GLenum(APIENTRY *)(GLenum))address("glCheckFramebufferStatus");
    GenRenderbuffers =
      (void(APIENTRY *)(GLsizei, GLuint *))address("glGenRenderbuffers");
    DeleteRenderbuffers = (void(APIENTRY *)(GLsizei, const GLuint *))
      address("glDeleteRenderbuffers");
    BindRenderbuffer =
      (void(APIENTRY *)(GLenum, GLuint))address("glBindRenderbuffer");
    RenderbufferStorage = (void(APIENTRY *)(GLenum, GLenum, GLsizei, GLsizei))
      address("glRenderbufferStorage");
    FramebufferRenderbuffer =
      (void(APIENTRY *)(GLenum, GLenum, GLenum,
                        GLuint))address("glFramebufferRenderbuffer");
    DrawBuffers =
      (void(APIENTRY *)(GLsizei, const GLenum *))address("glDrawBuffers");
    BlitFramebuffer =
      (void(APIENTRY *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint,
                        GLbitfield, GLenum))address("glBlitFramebuffer");

    ActiveTexture = (void(APIENTRY *)(GLenum))address("glActiveTexture");

    BlendFunci =
      (void(APIENTRY *)(GLuint, GLenum, GLenum))address("glBlendFunci");
    BlendEquationi = (void(APIENTRY *)(GLuint, GLenum))address("glBlendEquationi");

    parseVersion((const char *)glGetString(GL_VERSION), _major, _minor, _es);

    // An entry point being there says nothing about the context being able to
    // run it: the macOS framework exports the whole of the core profile
    // whatever version the current context is, so every capability below is
    // the version the feature became core in, and the pointers on top of it.
    _buffers = GenBuffers && DeleteBuffers && BindBuffer && BufferData &&
               atLeast(1, 5);
    // what it takes to draw a frame with shaders: the programs themselves
    // (OpenGL 2.0), the vertex attributes they read (2.0), and the vertex
    // array objects a core profile makes compulsory (3.0). Asking for 3.2
    // rather than 3.0 is asking for the profile macOS gives, which is the
    // oldest one it has with shaders in it
    _shaders = CreateShader && ShaderSource && CompileShader && CreateProgram &&
               AttachShader && LinkProgram && UseProgram &&
               GetUniformLocation && VertexAttribPointer &&
               EnableVertexAttribArray && GenVertexArrays && BindVertexArray &&
               _buffers && (_es ? atLeast(3, 0) : atLeast(3, 2));
    _framebuffers = GenFramebuffers && BindFramebuffer &&
                    FramebufferTexture2D && CheckFramebufferStatus &&
                    DrawBuffers && atLeast(3, 0);
    // gl_ClipDistance is core desktop OpenGL from 3.0, and only an extension on
    // OpenGL ES, where it arrived in 3.2
    _clipDistance = _es ? (atLeast(3, 2) ||
                           haveExtension("GL_EXT_clip_cull_distance")) :
                          atLeast(3, 0);
    // per target blending is OpenGL 4.0, and OpenGL ES 3.2
    _indexedBlend = BlendFunci && BlendEquationi &&
                    (_es ? (atLeast(3, 2) ||
                            haveExtension("GL_EXT_draw_buffers_indexed")) :
                           atLeast(4, 0));
  }

  void reset()
  {
    _loaded = _buffers = _shaders = false;
    _framebuffers = _clipDistance = _indexedBlend = _es = false;
    _major = _minor = 0;

    GenBuffers = nullptr;
    DeleteBuffers = nullptr;
    BindBuffer = nullptr;
    BufferData = nullptr;
    BufferSubData = nullptr;

    CreateShader = nullptr;
    ShaderSource = nullptr;
    CompileShader = nullptr;
    GetShaderiv = nullptr;
    GetShaderInfoLog = nullptr;
    DeleteShader = nullptr;
    CreateProgram = nullptr;
    AttachShader = nullptr;
    LinkProgram = nullptr;
    GetProgramiv = nullptr;
    GetProgramInfoLog = nullptr;
    UseProgram = nullptr;
    DeleteProgram = nullptr;
    BindAttribLocation = nullptr;
    GetUniformLocation = nullptr;
    Uniform1i = nullptr;
    Uniform1f = nullptr;
    Uniform1iv = nullptr;
    Uniform1fv = nullptr;
    Uniform2fv = nullptr;
    Uniform3fv = nullptr;
    Uniform4fv = nullptr;
    UniformMatrix3fv = nullptr;
    UniformMatrix4fv = nullptr;

    EnableVertexAttribArray = nullptr;
    DisableVertexAttribArray = nullptr;
    VertexAttribPointer = nullptr;

    GenVertexArrays = nullptr;
    DeleteVertexArrays = nullptr;
    BindVertexArray = nullptr;

    GenFramebuffers = nullptr;
    DeleteFramebuffers = nullptr;
    BindFramebuffer = nullptr;
    FramebufferTexture2D = nullptr;
    CheckFramebufferStatus = nullptr;
    GenRenderbuffers = nullptr;
    DeleteRenderbuffers = nullptr;
    BindRenderbuffer = nullptr;
    RenderbufferStorage = nullptr;
    FramebufferRenderbuffer = nullptr;
    DrawBuffers = nullptr;
    BlitFramebuffer = nullptr;

    ActiveTexture = nullptr;

    BlendFunci = nullptr;
    BlendEquationi = nullptr;
  }

  bool haveBufferObjects()
  {
    load();
    return _buffers;
  }

  bool haveShaders()
  {
    load();
    return _shaders;
  }

  bool haveFramebufferObjects()
  {
    load();
    return _framebuffers;
  }

  bool haveClipDistance()
  {
    load();
    return _clipDistance;
  }

  bool haveIndexedBlend()
  {
    load();
    return _indexedBlend;
  }

  int versionMajor()
  {
    load();
    return _major;
  }

  int versionMinor()
  {
    load();
    return _minor;
  }

  bool isES()
  {
    load();
    return _es;
  }

  void describe()
  {
    load();
    const char *v = (const char *)glGetString(GL_VERSION);
    const char *r = (const char *)glGetString(GL_RENDERER);
    const char *s = (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION);
    Msg::Debug("OpenGL %s on %s", v ? v : "?", r ? r : "?");
    Msg::Debug("OpenGL shading language %s", s ? s : "none");
    Msg::Debug("OpenGL has buffer objects: %s, shaders: %s, framebuffer "
               "objects: %s, clip distances: %s, per target blending: %s",
               _buffers ? "yes" : "no", _shaders ? "yes" : "no",
               _framebuffers ? "yes" : "no", _clipDistance ? "yes" : "no",
               _indexedBlend ? "yes" : "no");
  }
} // namespace glApi
