#ifndef _COLORBAR_WINDOW_H
#define _COLORBAR_WINDOW_H

#include "ColorTable.h"

typedef struct _colorbar {
  int width, height;           /* size */
  int wedge_y;                 /* top coord of color wedge */
  int marker_y;                /* top coord of marker arrow */
  int label_y;                 /* y coord of text labels */
  char label[LABEL_STR_L];     /* text label at bottom */
  float minval, maxval;        /* min and max data values */
  int markerpos;               /* position of marker as index into table */
  int helpflag;                /* if nonzero, print help messages */  
  ColorTable *ct;              /* pointer to color table (allocated in Post_View) */
} ColorBar;

#define WEDGE_HEIGHT    12  /* epaisseur de la colorbar */
#define MARKER_HEIGHT   10  /* hauteur de la fleche */

#endif
