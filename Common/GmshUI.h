#ifndef _GMSH_UI_H_
#define _GMSH_UI_H_

#if _XMOTIF // X11 Motif for Unix

#include <X11/keysym.h>
#include <Xm/XmAll.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GLwMDrawA.h>

#elif _FLTK // FLTK for both Unix and Windows

#include <FL/Fl.H>
#include <GL/gl.h>
#include <GL/glu.h>

#endif

#endif
