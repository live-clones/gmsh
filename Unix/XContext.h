/* $Id: XContext.h,v 1.3 2000-11-26 15:43:48 geuzaine Exp $ */
#ifndef _XCONTEXT_H_
#define _XCONTEXT_H_

/* 
   X/GLX context
*/

typedef struct {
  Display       *display;       /* the X display */
  int            scrnum, depth; /* the X screen number and depth */
  XtAppContext   AppContext;

  struct {
    XVisualInfo *visinfo ;
    GLXContext   context ;
    Colormap     colormap ;    
  } glw ;

  struct {
    XVisualInfo *visinfo ;
    GLXContext   context ;
    Colormap     colormap ;    
  } glo ;

  struct {
    Visual     *visual ;
    Colormap    colormap ;
  } gui ;

  struct {
    XFontStruct *helve, *fixed ;
    int          helve_h, helve_a, helve_w ; 
    int          fixed_h, fixed_a, fixed_w ; 
  } xfont ;

  struct {
    unsigned long  black, white ;
    unsigned long  red, green, blue ;
    unsigned long  ovblack, ovwhite ;
  } xcolor ;

  struct {
    GC  xgc;
    GC  black, white ;
    GC  red, green, blue ;
  } xgc ;

} XContext_T ;

#define EV_MASK  KeyPressMask|KeyReleaseMask|\
                 ButtonPressMask|ButtonReleaseMask|ButtonMotionMask|\
                 PointerMotionMask|ExposureMask|ResizeRedirectMask|\
                 EnterWindowMask|LeaveWindowMask|ShiftMask|ControlMask|Mod1Mask


#endif
