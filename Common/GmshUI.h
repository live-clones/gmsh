
#ifdef _UNIX

/* UNIX includes */

#include <X11/keysym.h>
#include <Xm/XmAll.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/GLwMDrawA.h>

#else

/* Windows includes */

#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
extern "C"{
#include <GL/glaux.h>
}

#endif
