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
//
// The entry points of OpenGL 2.0 and later are looked up at runtime everywhere,
// not only on Windows: the macOS header is that of OpenGL 2.1 and declares
// neither the shader nor the framebuffer calls of a core profile, although the
// framework exports them. The prototypes and the enums they need are therefore
// spelled out below rather than taken from the system headers.

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

#include <cstddef>

// the Windows OpenGL header stops at 1.1: it declares neither the types nor the
// enums of the buffer objects
#if defined(WIN32) && !defined(GL_ARRAY_BUFFER)
typedef std::ptrdiff_t GLsizeiptr;
typedef std::ptrdiff_t GLintptr;
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_STATIC_DRAW 0x88E4
#endif

#if !defined(APIENTRY)
#define APIENTRY
#endif

// the character type the shader calls use; a plain char everywhere, but only
// the headers that know about shaders give it a name
#if !defined(GL_VERSION_2_0) && !defined(GL_SHADER_TYPE)
typedef char GLchar;
#endif

// The enums the entry points below need, for the headers that stop before the
// version that introduced them. Each is guarded on its own: a 2.1 header has
// the shader enums but not the framebuffer ones.
#if !defined(GL_VERTEX_SHADER)
#define GL_VERTEX_SHADER 0x8B31
#endif
#if !defined(GL_FRAGMENT_SHADER)
#define GL_FRAGMENT_SHADER 0x8B30
#endif
#if !defined(GL_COMPILE_STATUS)
#define GL_COMPILE_STATUS 0x8B81
#endif
#if !defined(GL_LINK_STATUS)
#define GL_LINK_STATUS 0x8B82
#endif
#if !defined(GL_INFO_LOG_LENGTH)
#define GL_INFO_LOG_LENGTH 0x8B84
#endif
#if !defined(GL_SHADING_LANGUAGE_VERSION)
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#endif
#if !defined(GL_TEXTURE0)
#define GL_TEXTURE0 0x84C0
#endif
#if !defined(GL_DYNAMIC_DRAW)
#define GL_DYNAMIC_DRAW 0x88E8
#endif
#if !defined(GL_STREAM_DRAW)
#define GL_STREAM_DRAW 0x88E0
#endif
#if !defined(GL_FRAMEBUFFER)
#define GL_FRAMEBUFFER 0x8D40
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_RENDERBUFFER 0x8D41
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_DEPTH_COMPONENT24 0x81A6
#endif
#if !defined(GL_MAX_DRAW_BUFFERS)
#define GL_MAX_DRAW_BUFFERS 0x8824
#endif
#if !defined(GL_RGBA16F)
#define GL_RGBA16F 0x881A
#define GL_RGBA32F 0x8814
#endif
#if !defined(GL_PROGRAM_POINT_SIZE)
#define GL_PROGRAM_POINT_SIZE 0x8642
#endif
#if !defined(GL_NUM_EXTENSIONS)
#define GL_NUM_EXTENSIONS 0x821D
#endif
#if !defined(GL_CLIP_DISTANCE0)
#define GL_CLIP_DISTANCE0 0x3000
#endif

namespace glApi {
  // buffer objects (OpenGL 1.5)
  extern void(APIENTRY *GenBuffers)(GLsizei n, GLuint *buffers);
  extern void(APIENTRY *DeleteBuffers)(GLsizei n, const GLuint *buffers);
  extern void(APIENTRY *BindBuffer)(GLenum target, GLuint buffer);
  extern void(APIENTRY *BufferData)(GLenum target, GLsizeiptr size,
                                    const GLvoid *data, GLenum usage);
  extern void(APIENTRY *BufferSubData)(GLenum target, GLintptr offset,
                                       GLsizeiptr size, const GLvoid *data);

  // shaders and programs (OpenGL 2.0)
  extern GLuint(APIENTRY *CreateShader)(GLenum type);
  extern void(APIENTRY *ShaderSource)(GLuint shader, GLsizei count,
                                      const GLchar *const *string,
                                      const GLint *length);
  extern void(APIENTRY *CompileShader)(GLuint shader);
  extern void(APIENTRY *GetShaderiv)(GLuint shader, GLenum pname,
                                     GLint *params);
  extern void(APIENTRY *GetShaderInfoLog)(GLuint shader, GLsizei bufSize,
                                          GLsizei *length, GLchar *infoLog);
  extern void(APIENTRY *DeleteShader)(GLuint shader);
  extern GLuint(APIENTRY *CreateProgram)(void);
  extern void(APIENTRY *AttachShader)(GLuint program, GLuint shader);
  extern void(APIENTRY *LinkProgram)(GLuint program);
  extern void(APIENTRY *GetProgramiv)(GLuint program, GLenum pname,
                                      GLint *params);
  extern void(APIENTRY *GetProgramInfoLog)(GLuint program, GLsizei bufSize,
                                           GLsizei *length, GLchar *infoLog);
  extern void(APIENTRY *UseProgram)(GLuint program);
  extern void(APIENTRY *DeleteProgram)(GLuint program);
  extern void(APIENTRY *BindAttribLocation)(GLuint program, GLuint index,
                                            const GLchar *name);
  extern GLint(APIENTRY *GetUniformLocation)(GLuint program,
                                             const GLchar *name);
  extern void(APIENTRY *Uniform1i)(GLint location, GLint v0);
  extern void(APIENTRY *Uniform1f)(GLint location, GLfloat v0);
  extern void(APIENTRY *Uniform1iv)(GLint location, GLsizei count,
                                    const GLint *value);
  extern void(APIENTRY *Uniform1fv)(GLint location, GLsizei count,
                                    const GLfloat *value);
  extern void(APIENTRY *Uniform2fv)(GLint location, GLsizei count,
                                    const GLfloat *value);
  extern void(APIENTRY *Uniform3fv)(GLint location, GLsizei count,
                                    const GLfloat *value);
  extern void(APIENTRY *Uniform4fv)(GLint location, GLsizei count,
                                    const GLfloat *value);
  extern void(APIENTRY *UniformMatrix3fv)(GLint location, GLsizei count,
                                          GLboolean transpose,
                                          const GLfloat *value);
  extern void(APIENTRY *UniformMatrix4fv)(GLint location, GLsizei count,
                                          GLboolean transpose,
                                          const GLfloat *value);

  // vertex attributes (OpenGL 2.0)
  extern void(APIENTRY *EnableVertexAttribArray)(GLuint index);
  extern void(APIENTRY *DisableVertexAttribArray)(GLuint index);
  extern void(APIENTRY *VertexAttribPointer)(GLuint index, GLint size,
                                             GLenum type, GLboolean normalized,
                                             GLsizei stride,
                                             const GLvoid *pointer);

  // vertex array objects (OpenGL 3.0)
  extern void(APIENTRY *GenVertexArrays)(GLsizei n, GLuint *arrays);
  extern void(APIENTRY *DeleteVertexArrays)(GLsizei n, const GLuint *arrays);
  extern void(APIENTRY *BindVertexArray)(GLuint array);

  // framebuffer objects and multiple render targets (OpenGL 3.0)
  extern void(APIENTRY *GenFramebuffers)(GLsizei n, GLuint *framebuffers);
  extern void(APIENTRY *DeleteFramebuffers)(GLsizei n,
                                            const GLuint *framebuffers);
  extern void(APIENTRY *BindFramebuffer)(GLenum target, GLuint framebuffer);
  extern void(APIENTRY *FramebufferTexture2D)(GLenum target, GLenum attachment,
                                              GLenum textarget, GLuint texture,
                                              GLint level);
  extern GLenum(APIENTRY *CheckFramebufferStatus)(GLenum target);
  extern void(APIENTRY *GenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
  extern void(APIENTRY *DeleteRenderbuffers)(GLsizei n,
                                             const GLuint *renderbuffers);
  extern void(APIENTRY *BindRenderbuffer)(GLenum target, GLuint renderbuffer);
  extern void(APIENTRY *RenderbufferStorage)(GLenum target,
                                             GLenum internalformat,
                                             GLsizei width, GLsizei height);
  extern void(APIENTRY *FramebufferRenderbuffer)(GLenum target,
                                                 GLenum attachment,
                                                 GLenum renderbuffertarget,
                                                 GLuint renderbuffer);
  extern void(APIENTRY *DrawBuffers)(GLsizei n, const GLenum *bufs);
  extern void(APIENTRY *BlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1,
                                         GLint srcY1, GLint dstX0, GLint dstY0,
                                         GLint dstX1, GLint dstY1,
                                         GLbitfield mask, GLenum filter);

  // textures (OpenGL 1.3)
  extern void(APIENTRY *ActiveTexture)(GLenum texture);

  // per target blending (OpenGL 4.0, OpenGL ES 3.2): what dual depth peeling
  // needs, and what it has to do without on plain ES 3.0
  extern void(APIENTRY *BlendFunci)(GLuint buf, GLenum src, GLenum dst);
  extern void(APIENTRY *BlendEquationi)(GLuint buf, GLenum mode);

  // Resolve the entry points. An OpenGL context must be current. Does nothing
  // once it has run, until reset() is called.
  void load();
  // Forget the resolved entry points, e.g. because the context was recreated.
  void reset();

  // What the context that is current can do. Each of these calls load(), so
  // they may be asked at any time inside a frame.
  //
  // Are buffer objects usable in the current context?
  bool haveBufferObjects();
  // Can it compile and run shaders, feed them vertex attributes, and keep them
  // in vertex array objects? This is the whole of what the shader pipeline
  // needs to draw a frame.
  bool haveShaders();
  // Can it render to a texture, with several targets at once? This is what
  // depth peeling and the picking pass need.
  bool haveFramebufferObjects();
  // Can the vertex shader clip geometrically, with gl_ClipDistance? OpenGL ES
  // 3.0 cannot, and the fragment shader has to discard instead.
  bool haveClipDistance();
  // Can each draw buffer have its own blend function? Dual depth peeling needs
  // this; without it the passes are those of plain depth peeling.
  bool haveIndexedBlend();
  // the version of the current context, and whether it is an OpenGL ES one
  int versionMajor();
  int versionMinor();
  bool isES();
  // report what was found, once, as debug messages
  void describe();
} // namespace glApi

#endif
