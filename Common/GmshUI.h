/* $Id: GmshUI.h,v 1.4 2000-12-29 10:27:00 geuzaine Exp $ */

#if defined(_XMOTIF) /* UNIX with X and Motif */

#include <X11/keysym.h>
#include <Xm/XmAll.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GLwMDrawA.h>

#elif defined(_FLTK) /* FLTK widget set */

#error "Not ready yet for FLTK..."

#elif defined(_WINDOWS) /* Pure Windows */

#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
extern "C"{
#include <GL/glaux.h>
}

#else

#endif
