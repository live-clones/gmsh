// $Id: Pixmaps.cpp,v 1.4 2001-01-08 08:03:40 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Widgets.h"
#include "Context.h"
#include "Pixmaps.h"
#include "Bitmaps.h"
#include "XColors.h"

extern Widgets_T  WID;
extern Context_T  CTX;

Pixmap bm_to_px(Widget w, void *bits, int width, int height, int depth, int mode){
  Display  *display ;
  Window    window ;
  int       screen ;
  Pixmap    ret_pixmap;
  Pixel     fg, bg;
  
  display = XtDisplay(w);
  window = XtScreen(WID.M.shell)->root; /* XtWindow(w); */
  screen = DefaultScreen(display);

  if (DisplayCells(display, screen) > 2 && depth > 1) {

    switch (mode) {
    case BM_PX_BW: 
      fg = BlackPixel(display, screen);
      bg = WhitePixel(display, screen);
      break;      
    case BM_PX_BWREV:
      fg = WhitePixel(display, screen);
      bg = BlackPixel(display, screen);
      break;
    case BM_PX_WHITE:
      fg = WhitePixel(display, screen);
      XtVaGetValues(w,XmNbackground, &bg,NULL);
      break;      
    case BM_PX_BLACK:
      fg = BlackPixel(display, screen);
      XtVaGetValues(w,XmNbackground, &bg,NULL);
      break;      
    case BM_PX_RED:
      fg = AllocateColorInt(255,0,0) ;
      XtVaGetValues(w,XmNbackground, &bg,NULL);
      break;      
    case BM_PX_HIGHLIGHT:
      XtVaGetValues(w,XmNhighlightColor, &fg,XmNbackground, &bg,NULL);
      break;      
    case BM_PX_NORMAL:
    default:
      XtVaGetValues(w,XmNforeground, &fg,XmNbackground, &bg,NULL );
      break;
    }
  }
  else {
    fg = BlackPixel(display, screen);
    bg = WhitePixel(display, screen);
  }
  
  ret_pixmap = 
    XCreatePixmapFromBitmapData(display, window, (char*)bits, width, height, fg, bg, depth);
  
  if (ret_pixmap == (Pixmap) NULL){
    Msg(WARNING, "Failing to create pixmap");
    return ((Pixmap) NULL);
  }

  return (ret_pixmap);
}


void Set_AnimPixmap(Widgets_T *w, Pixmaps_T *p, int start){
  if(start)
    XtVaSetValues(w->G.Butt[5], XmNlabelPixmap, p->G.start, NULL);
  else
    XtVaSetValues(w->G.Butt[5], XmNlabelPixmap, p->G.stop, NULL);
}

void CreatePixmaps(Widgets_T *w, Pixmaps_T *p, int depth){

  /* Icons for 3 main windows */

  XtVaSetValues(w->M.shell, 
                XmNiconPixmap, 
                XCreateBitmapFromData(XtDisplay(w->M.shell),XtScreen(w->M.shell)->root,
                                      (char*)g1_bits, g1_width, g1_height), 
                NULL);


  XtVaSetValues(w->G.shell, 
                XmNiconPixmap, 
                XCreateBitmapFromData(XtDisplay(w->G.shell), XtScreen(w->G.shell)->root,
                                      (char*)g2_bits, g2_width, g2_height),
                NULL);

  if(CTX.command_win)
    XtVaSetValues(w->C.shell, 
                  XmNiconPixmap, 
                  XCreateBitmapFromData(XtDisplay(w->C.shell), XtScreen(w->C.shell)->root,
                                        (char*)g3_bits, g3_width, g3_height),
                  NULL);

  /* Graphic window */

  p->G.abort = bm_to_px(w->G.Butt[6], abort_bits, 
                        abort_width, abort_height, depth, BM_PX_RED);
  XtVaSetValues(w->G.Butt[6], XmNlabelPixmap, p->G.abort, NULL);

  p->G.abort_insens = bm_to_px(w->G.Butt[6], abort_bits, 
                               abort_width, abort_height, depth, BM_PX_NORMAL);
  XtVaSetValues(w->G.Butt[6], XmNlabelInsensitivePixmap, p->G.abort_insens, NULL);

  p->G.start = bm_to_px(w->G.Butt[5], start_bits, 
                        start_width, start_height, depth, BM_PX_NORMAL);
  p->G.stop = bm_to_px(w->G.Butt[5], stop_bits, 
                       stop_width, stop_height, depth, BM_PX_NORMAL);
  Set_AnimPixmap(w, p, 1);

  /* About window  */

  p->HD.about = bm_to_px(w->HD.aboutDialog, about_bits, 
                         about_width, about_height, depth, BM_PX_NORMAL);
  XtVaSetValues(w->HD.aboutDialog, XmNsymbolPixmap, p->HD.about, NULL);


}

