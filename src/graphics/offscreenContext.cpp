// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdlib>
#include <cstring>
#include <string>
#include "GmshConfig.h"
#include "offscreenContext.h"
#include "GmshMessage.h"
#include "VertexArray.h"
#include "glApi.h"
#include "glImmediate.h"
#include "glShader.h"

#if defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#elif !defined(WIN32) && defined(HAVE_DLOPEN)
#include <dlfcn.h>
#endif

namespace {
  // the context made current last
  const void *_current = nullptr;

  // the buffers, programs and entry points of the context that was current
  // belong to it: a context made current in its place starts from nothing
  void switchTo(const void *id)
  {
    if(id != _current) {
      bool first = !_current;
      VertexArray::invalidateBuffers();
      glApi::reset();
      glShader::reset();
      glImmediate::resetMatrices();
      _current = id;
      if(first) glApi::describe();
    }
    glShader::setContext(id);
  }
} // namespace

#if defined(__APPLE__)

namespace {
  // a context of each pipeline: the fixed function one is only had in a
  // legacy profile, the shaders are best had in a core one
  CGLContextObj _contexts[2] = {nullptr, nullptr};

  CGLContextObj create(bool core)
  {
    CGLPixelFormatAttribute attr[] = {
      kCGLPFAOpenGLProfile,
      (CGLPixelFormatAttribute)(core ? kCGLOGLPVersion_3_2_Core :
                                       kCGLOGLPVersion_Legacy),
      kCGLPFAColorSize,
      (CGLPixelFormatAttribute)24,
      kCGLPFAAlphaSize,
      (CGLPixelFormatAttribute)8,
      kCGLPFADepthSize,
      (CGLPixelFormatAttribute)24,
      kCGLPFAAllowOfflineRenderers,
      (CGLPixelFormatAttribute)0};
    CGLPixelFormatObj pix = nullptr;
    GLint num = 0;
    if(CGLChoosePixelFormat(attr, &pix, &num) != kCGLNoError || !pix)
      return nullptr;
    CGLContextObj ctx = nullptr;
    CGLCreateContext(pix, nullptr, &ctx);
    CGLDestroyPixelFormat(pix);
    return ctx;
  }
} // namespace

namespace offscreenContext {
  bool makeCurrent(bool shaders)
  {
    int k = shaders ? 1 : 0;
    if(!_contexts[k]) _contexts[k] = create(shaders);
    if(!_contexts[k]) {
      Msg::Error("Could not create an OpenGL context without a window");
      return false;
    }
    if(CGLSetCurrentContext(_contexts[k]) != kCGLNoError) return false;
    switchTo(_contexts[k]);
    return true;
  }
} // namespace offscreenContext

#elif !defined(WIN32) && defined(HAVE_DLOPEN)

namespace {
  // the part of EGL used here, declared rather than included so that neither
  // the headers nor the library are needed to build
  typedef void *EGLDisplay;
  typedef void *EGLConfig;
  typedef void *EGLContext;
  typedef void *EGLSurface;
  typedef void *EGLDeviceEXT;
  typedef int EGLint;
  typedef unsigned int EGLBoolean;
  typedef unsigned int EGLenum;
  const EGLint EGL_NONE = 0x3038;
  const EGLint EGL_VENDOR = 0x3053;
  const EGLint EGL_EXTENSIONS = 0x3055;
  const EGLint EGL_RENDERABLE_TYPE = 0x3040;
  const EGLint EGL_OPENGL_BIT = 0x0008;
  const EGLint EGL_CONTEXT_MAJOR_VERSION = 0x3098;
  const EGLint EGL_CONTEXT_MINOR_VERSION = 0x30FB;
  const EGLint EGL_CONTEXT_OPENGL_PROFILE_MASK = 0x30FD;
  const EGLint EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT = 0x1;
  const EGLint EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT = 0x2;
  const EGLenum EGL_OPENGL_API = 0x30A2;
  const EGLenum EGL_PLATFORM_DEVICE_EXT = 0x313F;
  const EGLenum EGL_PLATFORM_SURFACELESS_MESA = 0x31DD;

  struct {
    void *(*GetProcAddress)(const char *);
    const char *(*QueryString)(EGLDisplay, EGLint);
    EGLDisplay (*GetDisplay)(void *);
    EGLBoolean (*Initialize)(EGLDisplay, EGLint *, EGLint *);
    EGLBoolean (*Terminate)(EGLDisplay);
    EGLBoolean (*BindAPI)(EGLenum);
    EGLBoolean (*ChooseConfig)(EGLDisplay, const EGLint *, EGLConfig *,
                               EGLint, EGLint *);
    EGLContext (*CreateContext)(EGLDisplay, EGLConfig, EGLContext,
                                const EGLint *);
    EGLBoolean (*DestroyContext)(EGLDisplay, EGLContext);
    EGLBoolean (*MakeCurrent)(EGLDisplay, EGLSurface, EGLSurface, EGLContext);
    EGLBoolean (*QueryDevicesEXT)(EGLint, EGLDeviceEXT *, EGLint *);
    EGLDisplay (*GetPlatformDisplayEXT)(EGLenum, void *, const EGLint *);
  } egl;
  void *_lib = nullptr;

  EGLDisplay _display = nullptr;
  // a context of each pipeline, as a window has (its context is made again
  // when the pipeline changes): a program left bound by the shaders would be
  // run by the fixed function one. A compatibility profile serves both;
  // failing that, a core one serves the shaders alone.
  EGLContext _contexts[2] = {nullptr, nullptr};
  EGLint _profile = 0;
  bool _tried = false;

  bool hasExtension(const char *list, const char *name)
  {
    if(!list) return false;
    std::size_t n = strlen(name);
    for(const char *p = strstr(list, name); p; p = strstr(p + n, name))
      if((p == list || p[-1] == ' ') && (p[n] == ' ' || p[n] == '\0'))
        return true;
    return false;
  }

  bool load()
  {
    if(_lib) return true;
    const char *names[] = {"libEGL.so.1", "libEGL.so"};
    for(const char *name : names)
      if((_lib = dlopen(name, RTLD_NOW | RTLD_GLOBAL))) break;
    if(!_lib) return false;
#define GET(f) *(void **)(&egl.f) = dlsym(_lib, "egl" #f)
    GET(GetProcAddress);
    GET(QueryString);
    GET(GetDisplay);
    GET(Initialize);
    GET(Terminate);
    GET(BindAPI);
    GET(ChooseConfig);
    GET(CreateContext);
    GET(DestroyContext);
    GET(MakeCurrent);
#undef GET
    if(!egl.GetProcAddress || !egl.QueryString || !egl.Initialize ||
       !egl.BindAPI || !egl.CreateContext || !egl.MakeCurrent) {
      dlclose(_lib);
      _lib = nullptr;
      return false;
    }
    *(void **)(&egl.QueryDevicesEXT) = egl.GetProcAddress("eglQueryDevicesEXT");
    *(void **)(&egl.GetPlatformDisplayEXT) =
      egl.GetProcAddress("eglGetPlatformDisplayEXT");
    return true;
  }

  // a context of the profile asked for (0 for none, the driver's default) of
  // at least OpenGL 3.2
  EGLContext createContext(EGLDisplay d, EGLint profile)
  {
    EGLint cfgAttr[] = {EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT, EGL_NONE};
    EGLConfig cfg = nullptr;
    EGLint num = 0;
    // a context that is never drawn into but through framebuffer objects
    // needs no configuration (EGL_KHR_no_config_context) if none is offered
    if(egl.ChooseConfig) egl.ChooseConfig(d, cfgAttr, &cfg, 1, &num);
    if(num < 1) cfg = nullptr;
    EGLint attr[] = {EGL_CONTEXT_MAJOR_VERSION,
                     3,
                     EGL_CONTEXT_MINOR_VERSION,
                     2,
                     EGL_CONTEXT_OPENGL_PROFILE_MASK,
                     profile,
                     EGL_NONE};
    if(!profile) attr[0] = EGL_NONE;
    return egl.CreateContext(d, cfg, nullptr, attr);
  }

  // the contexts of a display, if it has any: true if it does
  bool tryDisplay(EGLDisplay d)
  {
    if(!d) return false;
    EGLint major = 0, minor = 0;
    if(!egl.Initialize(d, &major, &minor)) return false;
    if(!egl.BindAPI(EGL_OPENGL_API)) {
      egl.Terminate(d);
      return false;
    }
    // the profile the contexts will be made of, found by making one
    const EGLint profiles[3] = {EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT,
                                EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT, 0};
    for(EGLint profile : profiles) {
      EGLContext ctx = createContext(d, profile);
      if(!ctx) continue;
      _profile = profile;
      _contexts[profile == EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT ? 1 : 0] = ctx;
      _display = d;
      const char *vendor = egl.QueryString(d, EGL_VENDOR);
      Msg::Info("EGL %d.%d (%s), %s profile", major, minor,
                vendor ? vendor : "unknown vendor",
                profile == EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT ?
                  "core" :
                  "compatibility");
      return true;
    }
    egl.Terminate(d);
    return false;
  }

  // The display: the first device EGL enumerates that gives a context (the
  // GPUs come first, Mesa's software renderer last), else Mesa's display
  // without a surface, else the default one - which may want an X server.
  // GMSH_EGL_DEVICE picks the device by its number.
  bool open()
  {
    if(_tried) return _display != nullptr;
    _tried = true;
    if(!load()) {
      Msg::Error("Could not load libEGL: no OpenGL without a window");
      return false;
    }
    const char *client = egl.QueryString(nullptr, EGL_EXTENSIONS);
    if(egl.GetPlatformDisplayEXT && egl.QueryDevicesEXT &&
       hasExtension(client, "EGL_EXT_platform_device")) {
      EGLDeviceEXT devices[32];
      EGLint num = 0;
      if(egl.QueryDevicesEXT(32, devices, &num)) {
        int only = -1;
        if(const char *env = getenv("GMSH_EGL_DEVICE")) only = atoi(env);
        for(int i = 0; i < num; i++) {
          if(only >= 0 && i != only) continue;
          if(tryDisplay(egl.GetPlatformDisplayEXT(EGL_PLATFORM_DEVICE_EXT,
                                                  devices[i], nullptr))) {
            Msg::Info("EGL device %d of %d", i, num);
            return true;
          }
        }
      }
    }
    if(egl.GetPlatformDisplayEXT &&
       hasExtension(client, "EGL_MESA_platform_surfaceless") &&
       tryDisplay(egl.GetPlatformDisplayEXT(EGL_PLATFORM_SURFACELESS_MESA,
                                            nullptr, nullptr)))
      return true;
    if(egl.GetDisplay && tryDisplay(egl.GetDisplay(nullptr))) return true;
    Msg::Error("Could not create an OpenGL context through EGL");
    return false;
  }
} // namespace

namespace offscreenContext {
  bool makeCurrent(bool shaders)
  {
    if(!open()) return false;
    int k = shaders ? 1 : 0;
    if(_profile == EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT && !shaders) {
      Msg::Error("The OpenGL context of EGL is of a core profile, which the "
                 "fixed function pipeline cannot draw with");
      return false;
    }
    if(!_contexts[k]) _contexts[k] = createContext(_display, _profile);
    EGLContext ctx = _contexts[k];
    if(!ctx) {
      Msg::Error("Could not create an OpenGL context through EGL");
      return false;
    }
    if(!egl.MakeCurrent(_display, nullptr, nullptr, ctx)) {
      Msg::Error("Could not make the OpenGL context of EGL current");
      return false;
    }
    switchTo(ctx);
    return true;
  }
} // namespace offscreenContext

#else

namespace offscreenContext {
  bool makeCurrent(bool shaders)
  {
    Msg::Error("OpenGL without a window needs EGL (loaded with dlopen) or "
               "CGL (macOS): not available on this system");
    return false;
  }
} // namespace offscreenContext

#endif

namespace offscreenContext {
  const void *id() { return _current; }
} // namespace offscreenContext
