/* $Id: XStatic.h,v 1.2 2000-11-23 14:11:42 geuzaine Exp $ */
#ifndef _XSTATIC_H_
#define _XSTATIC_H_

/* Fenetre OpenGL principale : visual RGBA, simple ou double buffer */

int glw_attrib_sb[] = { 
  GLX_RGBA, 
  GLX_DEPTH_SIZE, 16, 
  GLX_RED_SIZE, 1, 
  GLX_GREEN_SIZE, 1, 
  GLX_BLUE_SIZE, 1,
  None };

int glw_attrib_db[] = { 
  GLX_RGBA, 
  GLX_DOUBLEBUFFER, 
  GLX_DEPTH_SIZE, 16, 
  GLX_RED_SIZE, 1, 
  GLX_GREEN_SIZE, 1, 
  GLX_BLUE_SIZE, 1,
  None };

/* Fenetre OpenGL overlay : visual INDEXE, simple buffer */

int glo_attrib[] = { GLX_LEVEL, 1, None };

/* variables globales */

XContext_T  XCTX ;
Widgets_T   WID ;
Pixmaps_T   PIX ;

GLdouble    vxmin, vxmax, vymin, vymax;

double      ClipPlane[4] = {0.0, 0.0, 0.0, 0.0};

#endif
