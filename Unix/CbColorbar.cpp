
#include "Gmsh.h"
#include "GmshUI.h"
#include "Const.h"
#include "XColors.h"
#include "Widgets.h"
#include "Register.h"
#include "Context.h"
#include "XContext.h"
#include "ColorTable.h"

#include "CbColorbar.h"

extern Context_T   CTX ;
extern XContext_T  XCTX ;
extern Widgets_T   WID;

/* RGB/HSV transformation */

#define RETURN_HSV(h,s,v) {*H=h; *S=s; *V=v; return;} 
#define RETURN_RGB(r,g,b) {*R=r; *G=g; *B=b; return;} 
#define UNDEFINED 0
#define EPS       1.e-10

/* rgb on [0, 1], sv returned on [0, 1] and h on [0, 6]. 
   Exception: h is returned UNDEFINED if S==0. */
									     
void RGB_to_HSV(double  R, double  G, double  B,
		double *H, double *S, double *V) { 
  double v, x, f;   
  int i; 
   
  x = DMIN(DMIN(R, G), B);   
  v = DMAX(DMAX(R, G), B);   
  if(v == x) RETURN_HSV(UNDEFINED, 0, v);   
  f = (R == x) ? G - B : ((G == x) ? B - R : R - G);   
  i = (R == x) ? 3 : ((G == x) ? 5 : 1);   
  RETURN_HSV(i - f /(v - x), (v - x)/v, v);   
} 

/* h given on [0, 6] or UNDEFINED. s and v given on [0, 1].      
   rgb each returned on [0, 1]. */

void HSV_to_RGB(double  H, double  S, double  V,
		double *R, double *G, double *B) {     
  double m, n, f;   
  int i; 
      
  if (H == UNDEFINED) RETURN_RGB(V, V, V);
  i = (int)floor(H);
  f = H - i;   
  if ( !(i&1) ) f = 1 - f; /* if i is even */
  m = V * (1 - S);   
  n = V * (1 - S * f); 
  
  switch (i) {         
  case 6:         
  case 0: RETURN_RGB(V, n, m);        
  case 1: RETURN_RGB(n, V, m);         
  case 2: RETURN_RGB(m, V, n);        
  case 3: RETURN_RGB(m, n, V); 	      	      
  case 4: RETURN_RGB(n, m, V);         
  case 5: RETURN_RGB(V, m, n);     
  } 
} 


/* Convert window X coordinate to color table index */

static int x_to_index(ColorBar *cb, int x){
  int index;
  index = (int) (x * (float) cb->ct->size / (float) cb->width );
  if (index<0) 
    index = 0;
  else if (index>=cb->ct->size)
    index = cb->ct->size-1;
  return index;
}

/* Convert color table index to window X coordinate */

static int index_to_x(ColorBar *cb, int index){
  int x;
  x = (int) (index * (float) cb->width / (float)(cb->ct->size-1) );
  if (x>=cb->width)
    x = cb->width - 1;
  return x;
}

/* Convert a color intensity to a window Y coordinate */

static int intensity_to_y(ColorBar *cb, int intensity){
  int y;
  y = (int) (cb->wedge_y - intensity * (float) cb->wedge_y / 255.0 );
  if (y<0)
    y = 0;
  else if (y>=cb->wedge_y)
    y = cb->wedge_y - 1;
  return y;
}

/* Convert a window Y coordinate to a color intensity */

static int y_to_intensity(ColorBar *cb, int y){
  int intensity;
  intensity = (int) ((cb->wedge_y - y ) * 255.0 / (float) cb->wedge_y );
  if (intensity<0)
    intensity = 0;
  else if (intensity>255)
    intensity = 255;
  return intensity;
}


/* Redraw part of a Color Widget (between a and b) */

#define HELP_LINES 9

static void redraw_range(ColorBar *cb, int a, int b){
   Window win;
   int i;
   int x,y, px,py;
   int x1, y1, x2, y2;
   int intensity;
   double H,S,V;
   char rgb_str[] = "RGB", hsv_str[] = "HSV" ;
   char help_str[HELP_LINES][100] = {
     "h           show this message",
     "1 -> 6      choose predefined colormap",
     "m           switch color mode",
     "s/l/c/p/r   save/load/copy/paste/reset",
     "mouse       draw color or alpha",
     "left/right  move or rotate",
     "up/down     color or alpha curvature",
     "i           invert x or y range",
     "b           increase or decrease gamma"
   };

   win = cb->window;

   if (a<0)  a = 0;
   if (b>=cb->ct->size)  b = cb->ct->size-1;

   /* calc region to update */
   x1 = index_to_x( cb, a );
   x2 = index_to_x( cb, b);

   y1 = intensity_to_y( cb, 255 );
   y2 = intensity_to_y( cb, 0 ); 

   /* erase region */
   XFillRectangle( XCTX.display, win, XCTX.xgc.black,
                   x1,y1, x2-x1+1, y2-y1+1 );

   /* redraw region of entries in interval [a,b] */
   if (a>0) a--;
   if (b<cb->ct->size-1)  b++;

   /* draw red or hue levels */
   for (i=a;i<=b;i++) {
      x = index_to_x( cb, i );

      if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_RGB){
	intensity = UNPACK_RED(cb->ct->table[i]);
      }
      else if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_HSV){
	RGB_to_HSV(UNPACK_RED  (cb->ct->table[i])/255., 
		   UNPACK_GREEN(cb->ct->table[i])/255.,
		   UNPACK_BLUE (cb->ct->table[i])/255.,
		   &H,&S,&V);
	intensity = (int) (H/6.*255.+EPS);
      }

      y = intensity_to_y( cb, intensity );
      if (i!=a)
         XDrawLine( XCTX.display, win, XCTX.xgc.red, px, py, x, y );
      px = x;  py = y;
   }

   /* draw green or saturation levels */
   for (i=a;i<=b;i++) {
      x = index_to_x( cb, i );

      if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_RGB){
	intensity = UNPACK_GREEN(cb->ct->table[i]);
      }
      else if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_HSV){
	RGB_to_HSV(UNPACK_RED  (cb->ct->table[i])/255., 
		   UNPACK_GREEN(cb->ct->table[i])/255.,
		   UNPACK_BLUE (cb->ct->table[i])/255.,
		   &H,&S,&V);
	intensity = (int) (S*255.);
      }

      y = intensity_to_y( cb, intensity);
      if (i!=a)
         XDrawLine( XCTX.display, win, XCTX.xgc.green, px,py, x,y );
      px = x;  py = y;
   }

   /* draw blue or value levels */
   for (i=a;i<=b;i++) {
      x = index_to_x( cb, i );

      if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_RGB){
	intensity = UNPACK_BLUE(cb->ct->table[i]);
      }
      else if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_HSV){
	RGB_to_HSV(UNPACK_RED  (cb->ct->table[i])/255., 
		   UNPACK_GREEN(cb->ct->table[i])/255.,
		   UNPACK_BLUE (cb->ct->table[i])/255.,
		   &H,&S,&V);
	intensity = (int) (V*255.);
      }

      y = intensity_to_y( cb, intensity );
      if (i!=a)
         XDrawLine( XCTX.display, win, XCTX.xgc.blue, px,py, x,y );
      px = x;  py = y;
   }

   /* draw alpha levels */   
   for (i=a;i<=b;i++) {
     x = index_to_x( cb, i );
     y = intensity_to_y( cb, UNPACK_ALPHA(cb->ct->table[i]) );
     if (i!=a)
       XDrawLine( XCTX.display, win, XCTX.xgc.white, px,py, x,y );
     px = x;  py = y;
   }

   /* draw the color bar */
   for (x=x1;x<=x2;x++) {
      int r, g, b;
      unsigned int color;
      i = x_to_index( cb, x );
      color = cb->ct->table[i];
      r = UNPACK_RED( color );
      g = UNPACK_GREEN( color );
      b = UNPACK_BLUE( color );
      XSetForeground( XCTX.display, XCTX.xgc.xgc, AllocateColorInt(r,g,b) );
      XDrawLine( XCTX.display, win, XCTX.xgc.xgc, x, cb->wedge_y,
                 x, cb->wedge_y + WEDGE_HEIGHT-1 ); 
   }

   /* print colortable mode and help */

   if (cb->helpflag) {
     for (i=0;i<HELP_LINES;i++) {
       XDrawString( XCTX.display, win, XCTX.xgc.white,
		    10,10+(i+1)*XCTX.xfont.fixed_h,
		    help_str[i], strlen(help_str[i]) );
     }
   }
   else{
     if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_RGB)
       XDrawString( XCTX.display, win, XCTX.xgc.white,
		    10, 10+XCTX.xfont.fixed_h, 
		    rgb_str, strlen(rgb_str) );
     else if(cb->ct->ipar[COLORTABLE_MODE]==COLORTABLE_HSV)
       XDrawString( XCTX.display, win, XCTX.xgc.white,
		    10, 10+XCTX.xfont.fixed_h, 
		    hsv_str, strlen(hsv_str) );
   }
}


/* Redraw the marker and the text */

static void redraw_marker(ColorBar *cb){
   Window win;
   int x, y0, y1;
   char str[50];
   int dir,ascent, descent;
   XCharStruct overall;
   int xpos;
   float val;

   win = cb->window;

   y0 = cb->marker_y;
   y1 = cb->height - 1;
   XFillRectangle( XCTX.display, win, XCTX.xgc.black,
                   0, y0, cb->width, y1-y0+1 );

   /* draw marker below color wedge */
   x = index_to_x( cb, cb->markerpos );
   XDrawLine( XCTX.display, win, XCTX.xgc.white,
              x, cb->marker_y, x, cb->marker_y+MARKER_HEIGHT );
   XDrawLine( XCTX.display, win, XCTX.xgc.white,
              x, cb->marker_y, x-3, cb->marker_y+6 );
   XDrawLine( XCTX.display, win, XCTX.xgc.white,
              x, cb->marker_y, x+3, cb->marker_y+6 );

   /* draw min value */
   sprintf( str, "%.2g", cb->minval );
   XDrawString( XCTX.display, win, XCTX.xgc.white,
                2, cb->label_y, str, strlen(str) );

   /* draw marker value */
   val = cb->minval + (cb->maxval-cb->minval)
                  * ( (float) cb->markerpos / (float) (cb->ct->size-1));
   sprintf(str,"(%.2g)", val );
   XTextExtents(XCTX.xfont.fixed, str, strlen(str), &dir,&ascent,&descent,&overall );
   xpos = (cb->width - overall.width) / 2;
   XDrawString( XCTX.display, win, XCTX.xgc.white,
                xpos, cb->label_y, str, strlen(str) );

   /* draw max value */
   sprintf( str, "%.2g", cb->maxval );
   XTextExtents( XCTX.xfont.fixed, str, strlen(str), &dir,&ascent,&descent,&overall );
   xpos = cb->width - overall.width - 2;
   XDrawString( XCTX.display, win, XCTX.xgc.white,
                xpos, cb->label_y, str, strlen(str) );

}


static void set_size(ColorBar *cb, int width, int height){
   cb->width = width;
   cb->height = height;
   cb->label_y = cb->height - 5; 
   cb->marker_y = cb->label_y + 1 - MARKER_HEIGHT - XCTX.xfont.fixed_h;
   cb->wedge_y = cb->marker_y - WEDGE_HEIGHT;
}




/* creation, manipulation and callbacks functions */

static ColorBar *TheCB=NULL ;
static ColorTable clip;

void ColorBarCopy(ColorTable *ct){
  memcpy(clip.table, ct->table, ct->size * sizeof(unsigned int));
  memcpy(clip.ipar,  ct->ipar,  COLORTABLE_NBMAX_PARAM * sizeof(int));
  memcpy(clip.fpar,  ct->fpar,  COLORTABLE_NBMAX_PARAM * sizeof(float));
}

void ColorBarPaste(ColorTable *ct){
  memcpy(ct->table, clip.table, ct->size * sizeof(unsigned int));
  memcpy(ct->ipar,  clip.ipar,  COLORTABLE_NBMAX_PARAM * sizeof(int));
  memcpy(ct->fpar,  clip.fpar,  COLORTABLE_NBMAX_PARAM * sizeof(float));
}

void ColorBarCreate(Window win, int width, int height){
  static int first=1 ;

  if(!TheCB) TheCB = (ColorBar *) calloc(1, sizeof(ColorBar));
  TheCB->window = win;
  set_size(TheCB, width, height);

  if(first){
    TheCB->helpflag = 1;
    first=0;
  }
}

void ColorBarShow(void){
  XMapWindow(XCTX.display, TheCB->window);
}

void ColorBarHide(void){
  XUnmapWindow(XCTX.display, TheCB->window);
}

void ColorBarRedraw(void){
  if(!TheCB) return;
  redraw_range(TheCB, 0, TheCB->ct->size-1);
  redraw_marker(TheCB);
}

void ColorBarChange(char *label, float min, float max, ColorTable *ct, int rgb){
  strncpy(TheCB->label, label, LABEL_STR_L);
  TheCB->ct     = ct;
  TheCB->minval = min;
  TheCB->maxval = max;
  if (rgb) redraw_range(TheCB, 0, TheCB->ct->size-1);
  redraw_marker(TheCB);
}

void ColorBarResizeCb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *call_data){
  Dimension w1,h1;

  if(!TheCB) return;
  
  XtVaGetValues(WID.PD.colorDrawingArea, 
		XmNwidth, &w1, 
		XmNheight, &h1, 
		NULL);    

  set_size(TheCB, (int)w1, (int)h1);
  XResizeWindow(XCTX.display, TheCB->window, (int)w1, (int)h1);
  ColorBarRedraw();
}

void ColorBarExposeCb(Widget w,XtPointer client_data, XmDrawingAreaCallbackStruct *call_data){
  ColorBarRedraw();
}

#define ANY_MODIFIER (ShiftMask|ControlMask|Mod1Mask)

void ColorBarInputCb (Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *call_data){

  XEvent         *event;
  static int      p1=0, p2=0, p3=0, p4=0; /* red, green, blue, alpha */
  static int      pentry, move_marker;
  int             i, modify, entry, compute;
  char            keybuf[50];
  KeySym          key;
  XComposeStatus  compose;

  event  = call_data->event;   
  modify = 0;
  compute = 0;

  /* touche */
  
  if (event->type==KeyPress) {
    XLookupString(&event->xkey, keybuf, 50, &key, &compose);

    switch(key){
    case XK_1 : color_table_init_param(1, TheCB->ct, 1, 1); compute=1; break;
    case XK_2 : color_table_init_param(2, TheCB->ct, 1, 1); compute=1; break;
    case XK_3 : color_table_init_param(3, TheCB->ct, 1, 1); compute=1; break;
    case XK_4 : color_table_init_param(4, TheCB->ct, 1, 1); compute=1; break;
    case XK_5 : color_table_init_param(5, TheCB->ct, 1, 1); compute=1; break;
    case XK_6 : color_table_init_param(6, TheCB->ct, 1, 1); compute=1; break;
    case XK_7 : color_table_init_param(7, TheCB->ct, 1, 1); compute=1; break;
    case XK_8 : color_table_init_param(8, TheCB->ct, 1, 1); compute=1; break;
    case XK_9 : color_table_init_param(9, TheCB->ct, 1, 1); compute=1; break;
    case XK_0 : color_table_init_param(0, TheCB->ct, 1, 1); compute=1; break;

    case XK_c : case XK_C : ColorBarCopy(TheCB->ct); break;
    case XK_p : case XK_P : ColorBarPaste(TheCB->ct); ColorBarRedraw(); break;
    case XK_s : case XK_S : ManageCb(NULL, (XtPointer)WID.FD.saveDialog, NULL); break;
    case XK_l : case XK_L : ManageCb(NULL, (XtPointer)WID.FD.mergeDialog, NULL); return ;
    case XK_h : case XK_H : TheCB->helpflag = !TheCB->helpflag; ColorBarRedraw(); break;

    case XK_r : 
    case XK_R : 
      color_table_init_param(TheCB->ct->ipar[COLORTABLE_NUMBER], 
			     TheCB->ct, 1, 1); 
      compute=1; break;

    case XK_m : 
    case XK_M : 
      if(TheCB->ct->ipar[COLORTABLE_MODE]==COLORTABLE_RGB)
	TheCB->ct->ipar[COLORTABLE_MODE] = COLORTABLE_HSV;
      else
	TheCB->ct->ipar[COLORTABLE_MODE] = COLORTABLE_RGB;
      ColorBarRedraw(); 
      break;

    case XK_i : 
    case XK_I : 
      if (event->xkey.state&ANY_MODIFIER) {
	TheCB->ct->ipar[COLORTABLE_INVERT] = !TheCB->ct->ipar[COLORTABLE_INVERT]; 
      }
      else{
	TheCB->ct->ipar[COLORTABLE_SWAP] = !TheCB->ct->ipar[COLORTABLE_SWAP]; 	
      }
      compute=1; break;

    case XK_b :
    case XK_B :
      if (event->xkey.state&ANY_MODIFIER) {
	TheCB->ct->fpar[COLORTABLE_BETA] -= 0.05;
	if(TheCB->ct->fpar[COLORTABLE_BETA]<-1.0) 
	  TheCB->ct->fpar[COLORTABLE_BETA] = -1.0;
      }
      else{
	TheCB->ct->fpar[COLORTABLE_BETA] += 0.05;
	if(TheCB->ct->fpar[COLORTABLE_BETA]>1.0) 
	  TheCB->ct->fpar[COLORTABLE_BETA] = 1.0;
      }
      compute = 1; break;

    case XK_Left  : 
      if (event->xkey.state&ANY_MODIFIER) {
	TheCB->ct->ipar[COLORTABLE_ROTATE] += 5;
	if(TheCB->ct->ipar[COLORTABLE_ROTATE] > TheCB->ct->size-1) 
	  TheCB->ct->ipar[COLORTABLE_ROTATE] -= TheCB->ct->size-1;
      }
      else {
	TheCB->ct->fpar[COLORTABLE_BIAS] -= 0.05; 
      }
      compute = 1; break;

    case XK_Right : 
      if (event->xkey.state&ANY_MODIFIER) {
	TheCB->ct->ipar[COLORTABLE_ROTATE] -= 5;
	if(TheCB->ct->ipar[COLORTABLE_ROTATE]<-(TheCB->ct->size-1)) 
	  TheCB->ct->ipar[COLORTABLE_ROTATE] += TheCB->ct->size-1;
      }
      else{
	TheCB->ct->fpar[COLORTABLE_BIAS] += 0.05; 
      }
      compute = 1; break;

    case XK_Up :
      if (event->xkey.state&ANY_MODIFIER) {
	TheCB->ct->fpar[COLORTABLE_ALPHAPOW] -= 0.05;
	if (TheCB->ct->fpar[COLORTABLE_ALPHAPOW]<0.0)
	  TheCB->ct->fpar[COLORTABLE_ALPHAPOW] = 0.0;
      }
      else {
	TheCB->ct->fpar[COLORTABLE_CURVE] -= 0.05;
      }
      compute = 1; break;

    case XK_Down :
      if (event->xkey.state&ANY_MODIFIER)
	TheCB->ct->fpar[COLORTABLE_ALPHAPOW] += 0.05;
      else
	TheCB->ct->fpar[COLORTABLE_CURVE] += 0.05;
      compute = 1; break;      

    }

    if(compute){
      color_table_recompute(TheCB->ct, 1, 1);
      ColorBarRedraw();
    }

  }

  /* souris enfoncee */

  else if (event->type==ButtonPress) {

    if(TheCB->helpflag){
      TheCB->helpflag = 0;
      ColorBarRedraw();
    }

    if (event->xbutton.y<TheCB->wedge_y) {
      /* change color function */
      move_marker = 0;
    }
    else {
      /* change marker position */
      move_marker = 1;
    }
    /* determine which curve to modify */
    if (event->xbutton.state&ANY_MODIFIER) {
      p4 = 1;
    }
    else {
      if (event->xbutton.button==Button1)  p1 = 1;
      if (event->xbutton.button==Button2)  p2 = 1;
      if (event->xbutton.button==Button3)  p3 = 1;
    }
    pentry = x_to_index(TheCB, event->xbutton.x);
    modify = 1;
  }

  /* souris relachee */

  else if (event->type==ButtonRelease) {
    if (event->xbutton.button==Button1)  p1 = 0;
    if (event->xbutton.button==Button2)  p2 = 0;
    if (event->xbutton.button==Button3)  p3 = 0;
    p4 = 0;
  }

  /* bouger */

  else if (event->type==MotionNotify) {
    /* Flush extra MotionNotify events */
    while (QLength(XCTX.display)>0) {
      XEvent next;
      XPeekEvent(XCTX.display, &next);
      if (next.type!=MotionNotify)
	break;
      XNextEvent(XCTX.display, event);
    }
    modify = 1;
  }

  /* Modify one or more of the color curves */
  
   if (modify && (p1 || p2 || p3 || p4)) {
      /* calculate which entry in color table to change */
      entry = x_to_index(TheCB, event->xbutton.x);
      /* update */
      if (move_marker) {
         /* changing marker position */
         TheCB->markerpos = entry;
         redraw_marker(TheCB);
      }
      else {
         /* changing color graph */
         int a, b, value;

         value = y_to_intensity(TheCB, event->xbutton.y);

         if (pentry<=entry) {
            a = pentry;
            b = entry;
         }
         else {
            a = entry;
            b = pentry;
         }

         /* update entries from 'pentry' to 'entry' */
         for (i=a; i<=b; i++) {
            int red, green, blue, alpha;
	    double R,G,B,H,S,V;

	    red   = UNPACK_RED  (TheCB->ct->table[i]);
	    green = UNPACK_GREEN(TheCB->ct->table[i]);
	    blue  = UNPACK_BLUE (TheCB->ct->table[i]);
	    alpha = UNPACK_ALPHA(TheCB->ct->table[i]);
	    
	    if(TheCB->ct->ipar[COLORTABLE_MODE]==COLORTABLE_RGB){
	      if (p1) { red = value; }
	      if (p2) { green = value; }
	      if (p3) { blue = value; }
	      if (p4) { alpha = value; }
	    }	   
	    else if(TheCB->ct->ipar[COLORTABLE_MODE]==COLORTABLE_HSV){
	      RGB_to_HSV((double)red/255.,(double)green/255.,(double)blue/255.,
			 &H,&S,&V);
	      if (p1) { H = 6.*(double)value/255.+EPS ; }
	      if (p2) { S = (double)value/255.; }
	      if (p3) { V = (double)value/255.; }
	      if (p4) { alpha = value; }	      
	      HSV_to_RGB(H, S, V, &R,&G,&B);
	      red   = (int)(255 * R);
	      green = (int)(255 * G);
	      blue  = (int)(255 * B);
	    }

            TheCB->ct->table[i] = PACK_COLOR(red,green,blue,alpha);
         } 

         /* redraw the color curves */
         if (pentry<entry)
           redraw_range(TheCB, pentry-1, entry+1);
         else
           redraw_range(TheCB, entry-1, pentry+1);

         pentry = entry;
	 
      }
   }
   
   
}

