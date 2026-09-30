// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OFFSCREEN_CONTEXT_H
#define OFFSCREEN_CONTEXT_H

// An OpenGL context without a window, drawn into through a framebuffer
// object: EGL on Linux and other Unix systems (with or without a GPU: Mesa's
// llvmpipe renders on the CPU, and nothing needs a display server), CGL on
// macOS. EGL is loaded when first needed, so that Gmsh neither links to it
// nor needs it to run.
namespace offscreenContext {
  // make current a context the pipeline asked for (shaders or the fixed
  // function one) can draw with, creating it the first time; false if there
  // is none to be had
  bool makeCurrent(bool shaders);
  // the context made current last, which the objects of glShader are kept
  // for (see glShader::setContext())
  const void *id();
} // namespace offscreenContext

#endif
