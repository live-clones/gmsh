/* $Id: GmshUI.h,v 1.3 2000-11-23 14:11:28 geuzaine Exp $ */

#ifdef _UNIX

/* UNIX includes */

#include <X11/keysym.h>
#include <Xm/XmAll.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GLwMDrawA.h>

#else

/* Windows includes */

#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
extern "C"{
#include <GL/glaux.h>
}

#endif
