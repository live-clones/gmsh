#ifndef _PIXMAPS_H_
#define _PIXMAPS_H_

#define BM_PX_NORMAL    0        /* normal/normal */
#define BM_PX_HIGHLIGHT 1        /* highlight/normal */
#define BM_PX_WHITE     2        /* white/normal */
#define BM_PX_BLACK     3        /* black/normal */
#define BM_PX_BW        4        /* black/white */
#define BM_PX_BWREV     5        /* white/black */
#define BM_PX_RED       6        /* red/normal */

typedef struct {
  
  struct {
    Pixmap  abort, abort_insens, start, stop ; 
  } G ;

  struct {
    Pixmap  about ; 
  } HD ;
  
} Pixmaps_T ;

void CreatePixmaps(Widgets_T *w, Pixmaps_T *p, int depth);
void Set_AnimCallback(Widgets_T *w, int start) ;
void Set_AnimPixmap(Widgets_T *w, Pixmaps_T *p, int start) ;

#endif
