#ifndef _CB_COLORBAR_H
#define _CB_COLORBAR_H

typedef struct _colorbar {
  Window window;
  int width, height;           /* size */
  int wedge_y;                 /* top coord of color wedge */
  int marker_y;                /* top coord of marker arrow */
  int label_y;                 /* y coord of text labels */
  char label[32];              /* text label at bottom */
  float minval, maxval;        /* min and max data values */
  int markerpos;               /* position of marker as index into table */
  int helpflag;                /* if nonzero, print help messages */  
  ColorTable *ct;              /* pointer to color table (allocated in Post_View) */
} ColorBar;

#define WEDGE_HEIGHT    12  /* epaisseur de la colorbar */
#define MARKER_HEIGHT   10  /* hauteur de la fleche */

void ColorBarCreate(Window win, int width, int height);
void ColorBarShow(void);
void ColorBarChange(char *label, float min, float max, ColorTable *ct, int rgb);
void ColorBarCopy(ColorTable *ct);
void ColorBarPaste(ColorTable *ct);
void ColorBarResizeCb(Widget w, XtPointer client_data, 
                      XmDrawingAreaCallbackStruct *call_data);
void ColorBarRedraw(void);

#endif
