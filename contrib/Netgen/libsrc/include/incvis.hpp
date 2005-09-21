// libraries for User interface:

/*
#include <tcl8.3.h>
#include <tk8.3.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include "../togl/togl.h"

#include <tix8.1.h>
*/


#include <tcl.h>
#include <tk.h>


#if TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==4
#define tcl_const const
#else
#define tcl_const
#endif


#include <GL/gl.h>
#include <GL/glu.h>
#include "../../togl/togl.h"



// Just the init-call
// #include <tix.h>
