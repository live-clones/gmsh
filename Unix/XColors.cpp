// $Id: XColors.cpp,v 1.5 2001-01-08 08:03:41 geuzaine Exp $

/*
  Attention. Toutes les couleurs sont crees a partir de la colormap de
  l'interface : XCTX.gui.colormap
*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "Gmsh.h"
#include "GmshUI.h"
#include "XContext.h"

extern XContext_T XCTX ;

#define PF_TRUECOLOR 0
#define PF_XALLOC    1
#define PF_8BIT      2

static int pixelformat;
static unsigned long ctable8[5][9][5];   /* Only for PF_8BIT */
static unsigned long rtable[256], gtable[256], btable[256];  /* PF_TRUECOLOR */

/*
 * Replacement for XAllocColor.  This function should never fail
 * to allocate a color.  When XAllocColor fails we return the nearest
 * matching color.
 */

#define DISTANCE(r1,g1,b1,r2,g2,b2)  ( ((r2)-(r1)) * ((r2)-(r1)) + \
    ((g2)-(g1)) * ((g2)-(g1)) + ((b2)-(b1)) * ((b2)-(b1)) )

Status New_XAllocColor( Display *dpy, Colormap cmap, int cmap_size,
                        XColor *color )
{
   int p, bestmatch;
   double dist, mindist;  /* 3*2^16^2 exceeds long int precision */
   static XColor *allcolors = NULL;
   XColor *acptr;

   if (!XAllocColor(dpy, cmap, color)) {
      /* query whole colormap if not yet done */
      if (!allcolors) {
         allcolors = (XColor *) malloc( cmap_size * sizeof(XColor) );
         for (p = 0;  p < cmap_size;  p++)
           allcolors[p].pixel = p;
         XQueryColors (dpy, cmap, allcolors, cmap_size);
      }
 
      /* find best match */
      bestmatch = -1;
      mindist = 0.0;
      p = cmap_size;
      while (p--) {
         acptr = allcolors + p;
         dist = DISTANCE( (double)color->red, (double)color->green,
                          (double)color->blue, (double)acptr->red,
                          (double)acptr->green, (double)acptr->blue);
         if (bestmatch < 0 || dist < mindist)
           mindist = dist, bestmatch = p;
      }
      color->red   = allcolors[bestmatch].red;
      color->green = allcolors[bestmatch].green;
      color->blue  = allcolors[bestmatch].blue;
      if (!XAllocColor( dpy, cmap, color )) {
         /* this is a real hack but should be good enough */
         color->pixel = bestmatch;
         /*printf("code problem in lui.c\n");*/
      }
   }
   return 1;
}

#undef DISTANCE




/*
 * Given an RGB color, return the corresponding pixel value.
 * Input;  r, g, b - red, green, and blue in [0,255]
 * Return:  a pixel value
 */
unsigned long AllocateColorInt( int r, int g, int b )
{
   XColor xcol;

   switch (pixelformat) {
      case PF_TRUECOLOR:
         return rtable[r] | gtable[g] | btable[b];
      case PF_8BIT:
         return ctable8[r/52][g/31][b/52];
      case PF_XALLOC:
         xcol.red = r << 8;
         xcol.green = g << 8;
         xcol.blue = b << 8;
         New_XAllocColor( XCTX.display, XCTX.gui.colormap, XCTX.gui.visual->map_entries,
                          &xcol );
         return xcol.pixel;
      default:
         Msg(ERROR, "Error in AllocateColorInt %d", pixelformat);
         exit(0);
   }
   return 0;
}




/*
 * Allocate a color specified by red, green, and blue and return a pixel
 * value.  If the color allocation fails, the white pixel will be returned.
 * Input:  red, green, blue - values in [0,1]
 * Return:  a pixel value
 */
unsigned long AllocateColor( float red, float green, float blue )
{
   return AllocateColorInt( (int) (red*255.0), (int) (green*255.0),
                            (int) (blue*255.0) );
}


void XColorInitialize(void) {
  XSetWindowAttributes attr;
  XGCValues gcv;
  unsigned long gc_mask;
  static int initialized = 0;
  static Window DummyWindow;

  if (initialized)
    return;
  else
    initialized = 1;

#if defined(__cplusplus) || defined(c_plusplus)
  if (XCTX.gui.visual->c_class==TrueColor || XCTX.gui.visual->c_class==DirectColor) {
#else
  if (XCTX.gui.visual->class==TrueColor || XCTX.gui.visual->class==DirectColor) {
#endif

    XColor xcol;
    int i;
    xcol.green = 0;
    xcol.blue = 0;
    for (i=0;i<256;i++) {
      xcol.red = i * 0xffff / 0xff;
      XAllocColor( XCTX.display, XCTX.gui.colormap, &xcol );
      rtable[i] = xcol.pixel;
    }
    xcol.red = 0;
    xcol.blue = 0;
    for (i=0;i<256;i++) {
      xcol.green = i * 0xffff / 0xff;
      XAllocColor( XCTX.display, XCTX.gui.colormap, &xcol );
      gtable[i] = xcol.pixel;
    }
    xcol.red = 0;
    xcol.green = 0;
    for (i=0;i<256;i++) {
      xcol.blue = i * 0xffff / 0xff;
      XAllocColor( XCTX.display, XCTX.gui.colormap, &xcol );
      btable[i] = xcol.pixel;
    }
    pixelformat = PF_TRUECOLOR;
  }

#if defined(__cplusplus) || defined(c_plusplus)
  else if (XCTX.gui.visual->c_class==PseudoColor) {
#else
  else if (XCTX.gui.visual->class==PseudoColor) {
#endif
    /* Note: the color allocation scheme must be the same as what's used */
    /* in Mesa to allow colormap sharing! */
    int r, g, b;
    for (r=0;r<5;r++) {
      for (g=0;g<9;g++) {
        for (b=0;b<5;b++) {
          XColor xcol;
          xcol.red   = r * 65535 / 4;
          xcol.green = g * 65535 / 8;
          xcol.blue  = b * 65535 / 4;
          New_XAllocColor( XCTX.display, XCTX.gui.colormap,
                           XCTX.gui.visual->map_entries, &xcol );
          ctable8[r][g][b] = xcol.pixel;
        }
      }
    }
    pixelformat = PF_8BIT;
  }

  else {
    pixelformat = PF_XALLOC;
  }


  /* Create a dummy window.  This is needed because XCreateGC needs a
     drawable of the type which we'll be using in LUI.  Unfortunately,
     the RootWindow may not have the visual we want.  For example,
     on the SGI PI, the default root window is pseudo color but we want
     LUI to use TrueColor if it's available.  In this case using RootWindow
     in XCreateGC will make a GC of the wrong type. */
  attr.border_pixel = 0;
  attr.background_pixel = 255;
  attr.colormap = XCTX.gui.colormap;
  DummyWindow = XCreateWindow( XCTX.display, DefaultRootWindow(XCTX.display),
                               0, 0, 10, 10, 1,
                               XCTX.depth, InputOutput, XCTX.gui.visual,
                               CWBorderPixel | CWBackPixel | CWColormap,
                               &attr );
  
  /*** The basic GC ***/
  gc_mask        = GCForeground | GCBackground | GCFont | GCArcMode;
  gcv.font       = XCTX.xfont.fixed->fid;
  gcv.arc_mode   = ArcChord;
  XCTX.xgc.xgc   = XCreateGC(XCTX.display, DummyWindow, gc_mask, &gcv);
  
  /*** Black ***/
  XCTX.xcolor.black = AllocateColor( 0.0, 0.0, 0.0 );
  gcv.foreground = XCTX.xcolor.black;
  XCTX.xgc.black = XCreateGC(XCTX.display, DummyWindow, gc_mask, &gcv);
  
  /*** White ***/
  XCTX.xcolor.white = AllocateColor( 1.0, 1.0, 1.0 );
  gcv.foreground = XCTX.xcolor.white;
  XCTX.xgc.white = XCreateGC(XCTX.display, DummyWindow, gc_mask, &gcv);
  
  /*** Red (black on monochrome) ***/
  XCTX.xcolor.red = AllocateColor( 1.0, 0.0, 0.0 );
  if (XCTX.xcolor.red == XCTX.xcolor.white) {
    XCTX.xcolor.red = XCTX.xcolor.black;
  }
  gcv.foreground = XCTX.xcolor.red;
  XCTX.xgc.red  = XCreateGC(XCTX.display, DummyWindow, gc_mask, &gcv);
  
  /*** Green ***/
  XCTX.xcolor.green = AllocateColor( 0.0, 1.0, 0.0 );
  gcv.foreground = XCTX.xcolor.green;
  XCTX.xgc.green = XCreateGC( XCTX.display, DummyWindow, gc_mask, &gcv );
  
  /*** Blue ***/
  XCTX.xcolor.blue = AllocateColor( 0.0, 0.5, 1.0 );
  gcv.foreground = XCTX.xcolor.blue;
  XCTX.xgc.blue = XCreateGC( XCTX.display, DummyWindow, gc_mask, &gcv );

}

