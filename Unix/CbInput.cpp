/* $Id: CbInput.cpp,v 1.10 2000-12-05 18:38:11 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "Draw.h"
#include "Widgets.h"
#include "Context.h"
#include "XContext.h"
#include "Register.h"

#include "CbContext.h"
#include "CbGeneral.h"
#include "CbGeom.h"
#include "CbPost.h"
#include "CbMesh.h"

extern Context_T   CTX ;
extern XContext_T  XCTX ;
extern Widgets_T   WID ;
extern Mesh        M;

static int        Modifier=0;

void KeyboardAccel(XEvent *event){
  XComposeStatus  stat;
  KeySym          keysym;
  char            buf[100];
  double          delay ;

  XLookupString(&event->xkey, buf, sizeof(buf), &keysym, &stat);

  switch(Modifier){

    /* ----------------------------------------------------- */
    /* No modifier or shift is pressed                       */
    /* ----------------------------------------------------- */

  case 0 : 

      /* modifier check and trash */
    switch (keysym) {
    case XK_Control_L : case XK_Control_R : 
      Modifier = 1; 
      break;
    case XK_Alt_L : case XK_Alt_R : 
    case XK_Meta_L : case XK_Meta_R : 
      Modifier = 2; 
      break;

      /* hacks */

      /*
    case XK_Up :
      CTX.clip_plane0[2] = 1. ;
      if(fabs(CTX.clip_plane0[3]-CTX.lc/20. <1.)) CTX.clip_plane0[3] -= CTX.lc/20. ;
      Init(); Draw();
      break;
    case XK_Down :
      CTX.clip_plane0[2] = 1. ;
      if(fabs(CTX.clip_plane0[3]+CTX.lc/20 <1.)) CTX.clip_plane0[3] += CTX.lc/20. ;
      Init(); Draw();
      break;
      */

      /* mesh shortcuts */
    case XK_0 : case XK_KP_0 : 
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_GEOM,NULL); 
      geom_event_handler(GEOM_PARSE);
      break;
    case XK_1 : case XK_KP_1 :
    case XK_F1 : case XK_KP_F1 :
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_MESH,NULL); 
      mesh_event_handler(MESH_1D);
      break;
    case XK_2 : case XK_KP_2 :
    case XK_F2 : case XK_KP_F2 :
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_MESH,NULL);
      mesh_event_handler(MESH_2D);
      break;
    case XK_3 : case XK_KP_3 :
    case XK_F3 : case XK_KP_F3 :
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_MESH,NULL);
      mesh_event_handler(MESH_3D);
      break;

      /* post shortcuts */
    case XK_s: 
      CTX.post.anim_delay += 100000 ;
      delay = CTX.post.anim_delay / 1.e6 ;
      XtVaSetValues(WID.OD.postAnimScale, XmNvalue, (int)(10*delay), NULL);
      XmUpdateDisplay(WID.OD.postAnimScale);
      break ;
    case XK_S: 
      CTX.post.anim_delay -= 100000 ;
      if(CTX.post.anim_delay < 0) CTX.post.anim_delay = 0 ;
      delay = CTX.post.anim_delay / 1.e6 ;
      XtVaSetValues(WID.OD.postAnimScale, XmNvalue, (int)(10*delay), NULL);
      XmUpdateDisplay(WID.OD.postAnimScale);
      break ;

      /* module shortcuts */
    case XK_g :
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_GEOM,NULL); 
      break;
    case XK_m :
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_MESH,NULL); 
      break;
    case XK_p :
      ActualizeContextCb (NULL,(XtPointer)CONTEXT_POST,NULL); 
      break;

      /* options menu shortcuts */
    case XK_G :
      ManageCb(NULL,(XtPointer)WID.OD.geomDialog,NULL); 
      break;
    case XK_M :
      ManageCb(NULL,(XtPointer)WID.OD.meshDialog,NULL); 
      break;
    case XK_P :
      ManageCb(NULL,(XtPointer)WID.OD.postDialog,NULL); 
      break;
    case XK_O :
      ManageCb(NULL,(XtPointer)WID.OD.miscDialog,NULL); 
      break;
    case XK_I :  
      Modifier = 0 ;
      CurrentInfoCb(NULL, (XtPointer)1, NULL); 
      break;
    case XK_V : 
      Modifier = 0 ;
      CurrentViewportCb (NULL, NULL, NULL);
      break;
    }
    break;


    /* ----------------------------------------------------- */
    /* Control is pressed                                    */
    /* ----------------------------------------------------- */

  case 1 :

    switch (keysym) {

      /* file menu shortcuts */
    case XK_q : case XK_Q : 
      exit(1);
    case XK_a : case XK_A : 
    case XK_c : case XK_C : 
      CancelMeshThread();
      break;
    case XK_s :  
      Print_Mesh(&M,NULL, CTX.mesh.format); 
      break; 
    case XK_S : 
      Modifier = 0 ;
      ManageCb(NULL,(XtPointer)WID.FD.saveAsDialog,NULL); 
      break ;
    case XK_o : case XK_O : 
      Modifier = 0 ;
      ManageCb(NULL,(XtPointer)WID.FD.openDialog,NULL); 
      break;
    case XK_m : case XK_M : 
      Modifier = 0 ;
      ManageCb(NULL,(XtPointer)WID.FD.mergeDialog,NULL); 
      break;
    case XK_p : case XK_P : 
      Modifier = 0 ;
      ManageCb(NULL,(XtPointer)WID.FD.printDialog,NULL); 
      break;
    case XK_l : case XK_L : 
      Modifier = 0 ;
      ReloadAllViewsCb(NULL,NULL,NULL); 
      break;
    case XK_r : case XK_R : 
      Modifier = 0 ;
      RemoveAllViewsCb(NULL,NULL,NULL); 
      break;
    }
    break ;
    

    /* ----------------------------------------------------- */
    /* Alt is pressed                                        */
    /* ----------------------------------------------------- */

  case 2 :
    
    /* everything that is not "cascade menu" */
    switch (keysym) {
    case XK_f : case XK_F : 
      CTX.fast = !CTX.fast; 
      XtVaSetValues(WID.OD.miscMiscButt[2], XmNset, CTX.fast, NULL);
      XmUpdateDisplay(WID.OD.miscMiscCheck);
      break;
    case XK_b : case XK_B :
      CTX.post.scales = !CTX.post.scales;
      Init(); Draw();
      break;
    case XK_o : case XK_O :
      CTX.ortho = !CTX.ortho; 
      XtVaSetValues(WID.OD.miscProjButt[0], XmNset, CTX.ortho, NULL);
      XtVaSetValues(WID.OD.miscProjButt[1], XmNset, !CTX.ortho, NULL);
      XmUpdateDisplay(WID.OD.miscProjCheck);
      Init(); Draw();
      break;
    case XK_h : case XK_H :
      CTX.geom.highlight = !CTX.geom.highlight;
      CTX.geom.highlight ? Msg(INFOS, "Highlight Enabled") : 
        Msg(INFOS, "Highlight Disabled");
      break;
    case XK_c : case XK_C :
      if(CTX.color.id==0) Init_Colors(1);
      else if(CTX.color.id==1) Init_Colors(2);
      else Init_Colors(0);
      XtVaSetValues(WID.OD.miscColorSchemeScale,XmNvalue, CTX.color.id, NULL);
      XmUpdateDisplay(WID.OD.miscColorSchemeScale);  
      Init(); Draw();
      break;
    case XK_d : case XK_D :
      if(!CTX.mesh.hidden && !CTX.mesh.shade)
        CTX.mesh.hidden = 1;
      else if(CTX.mesh.hidden && !CTX.mesh.shade)  
        CTX.mesh.shade = 1;
      else{
        CTX.mesh.hidden = 0; CTX.mesh.shade = 0; 
      }
      XtVaSetValues(WID.OD.meshAspectButt[2],XmNset,CTX.mesh.hidden&&CTX.mesh.shade, NULL);
      XtVaSetValues(WID.OD.meshAspectButt[1],XmNset,CTX.mesh.hidden&&!CTX.mesh.shade, NULL);
      XtVaSetValues(WID.OD.meshAspectButt[0],XmNset,!CTX.mesh.hidden&&!CTX.mesh.shade, NULL);
      XmUpdateDisplay(WID.OD.meshAspectCheck);  
      Init(); Draw();
      break;
    case XK_x : case XK_X :
      set_r(0,0.);  set_r(1,90.);set_r(2,0.); Init(); Draw(); 
      break;
    case XK_y : case XK_Y : 
      set_r(0,-90.);set_r(1,0.); set_r(2,0.); Init(); Draw(); 
      break;
    case XK_z : case XK_Z : 
      set_r(0,0.);  set_r(1,0.); set_r(2,0.); Init(); Draw(); 
      break;
    case XK_a :
      CTX.small_axes = !CTX.small_axes;
      XtVaSetValues(WID.OD.miscMiscButt[1], XmNset, CTX.small_axes, NULL);
      XmUpdateDisplay(WID.OD.miscMiscCheck);
      Init(); Draw();
      break;
    case XK_A :
      CTX.axes = !CTX.axes;
      XtVaSetValues(WID.OD.miscMiscButt[0], XmNset, CTX.axes, NULL);
      XmUpdateDisplay(WID.OD.miscMiscCheck);
      Init(); Draw();
      break;
    case XK_p :
      CTX.geom.points = !CTX.geom.points;
      if(!CTX.geom.vis_type){
        XtVaSetValues(WID.OD.geomVisibleButt[0], XmNset, CTX.geom.points, NULL);
        XmUpdateDisplay(WID.OD.geomVisibleButt[0]); 
      }
      Init(); Draw();
      break;
    case XK_P :
      CTX.mesh.points = !CTX.mesh.points;
      if(!CTX.mesh.vis_type){
        XtVaSetValues(WID.OD.meshVisibleButt[0], XmNset, CTX.mesh.points, NULL);
        XmUpdateDisplay(WID.OD.meshVisibleButt[0]); 
      }
      Init(); Draw();
      break;
    case XK_l :
      CTX.geom.lines = !CTX.geom.lines;
      if(!CTX.geom.vis_type){
        XtVaSetValues(WID.OD.geomVisibleButt[1], XmNset, CTX.geom.lines, NULL);
        XmUpdateDisplay(WID.OD.geomVisibleButt[1]); 
      }
      Init(); Draw();
      break;
    case XK_L :
      CTX.mesh.lines = !CTX.mesh.lines;
      if(!CTX.mesh.vis_type){
        XtVaSetValues(WID.OD.meshVisibleButt[1], XmNset, CTX.mesh.lines, NULL);
        XmUpdateDisplay(WID.OD.meshVisibleButt[1]); 
      }
      Init(); Draw();
      break;
    case XK_s :
      CTX.geom.surfaces = !CTX.geom.surfaces;
      if(!CTX.geom.vis_type){
        XtVaSetValues(WID.OD.geomVisibleButt[2], XmNset, CTX.geom.surfaces, NULL);
        XmUpdateDisplay(WID.OD.geomVisibleButt[2]); 
      }
      Init(); Draw();
      break;
    case XK_S :
      CTX.mesh.surfaces = !CTX.mesh.surfaces;
      if(!CTX.mesh.vis_type){
        XtVaSetValues(WID.OD.meshVisibleButt[2], XmNset, CTX.mesh.surfaces, NULL);
        XmUpdateDisplay(WID.OD.meshVisibleButt[2]); 
      }
      Init(); Draw();
      break;
    case XK_v :
      CTX.geom.volumes = !CTX.geom.volumes;
      if(!CTX.geom.vis_type){
        XtVaSetValues(WID.OD.geomVisibleButt[3], XmNset, CTX.geom.volumes, NULL);
        XmUpdateDisplay(WID.OD.geomVisibleButt[3]); 
      }
      Init(); Draw();
      break;
    case XK_V :
      CTX.mesh.volumes = !CTX.mesh.volumes;
      if(!CTX.mesh.vis_type){
        XtVaSetValues(WID.OD.meshVisibleButt[3], XmNset, CTX.mesh.volumes, NULL);
        XmUpdateDisplay(WID.OD.meshVisibleButt[3]); 
      }
      Init(); Draw();
      break;
    case XK_m : case XK_M :
      CTX.mesh.points   = !CTX.mesh.points;
      CTX.mesh.lines    = !CTX.mesh.lines;
      CTX.mesh.surfaces = !CTX.mesh.surfaces;
      CTX.mesh.volumes  = !CTX.mesh.volumes;
      XtVaSetValues(WID.OD.meshVisibleButt[0], XmNset, CTX.mesh.points, NULL);
      XtVaSetValues(WID.OD.meshVisibleButt[1], XmNset, CTX.mesh.lines, NULL);
      XtVaSetValues(WID.OD.meshVisibleButt[2], XmNset, CTX.mesh.surfaces, NULL);
      XtVaSetValues(WID.OD.meshVisibleButt[3], XmNset, CTX.mesh.volumes, NULL);
      XmUpdateDisplay(WID.OD.meshVisibleCheck); 
      Init(); Draw();
      break;
    case XK_t : case XK_T :
      MarkAllViewsChanged(1);
      Init(); Draw();
      break;
    }
    break ;

  }

}


/* ------------------------------------------------------------------------ */
/*  I n p u t                                                               */
/* ------------------------------------------------------------------------ */

void Process_SelectionBuffer(int x, int y, int *n, GLuint *ii, GLuint *jj);
void Filter_SelectionBuffer(int n, GLuint *typ, GLuint *ient, Vertex **thev,
                            Curve **thec, Surface **thes, Mesh *m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2,
            GLdouble Xc1, GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);

void InputCb (Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *cb){
  XEvent         *event;
  XComposeStatus  stat;
  KeySym          keysym;
  GLuint          ii[SELECTION_BUFFER_SIZE], jj[SELECTION_BUFFER_SIZE];
  char            buf[100];
  int             previous_mesh_draw, previous_post_draw ;
  int             width, height ;

  static int      ibut, hits;
  static int      ButtonPressed=0, ZoomClick=0, FirstClick=0;
  static int      x, y, movx, movy;
  static GLdouble xc1, yc1, xc2, yc2, xt1, yt1, xscale1, yscale1;
  static GLdouble xb, yb, xc, yc, xe, ye, xz, yz;
  static GLdouble movzx, movzy;
  static Vertex   *v=NULL, *ov;
  static Curve    *c=NULL, *oc;
  static Surface  *s=NULL, *os;
  
  width  = CTX.viewport[2]-CTX.viewport[0] ;
  height = CTX.viewport[3]-CTX.viewport[1] ;
  
  event = cb->event;
  
  switch(event->type){
    
  /* -------------------------------------------------------------
     K e y s 
     ------------------------------------------------------------- */
    
  case KeyPress :
    KeyboardAccel(event);
    break;
    
  case KeyRelease :
    XLookupString(&event->xkey, buf, sizeof(buf), &keysym, &stat);
    if(keysym == XK_Control_L ||
       keysym == XK_Control_R ||
       keysym == XK_Alt_L ||
       keysym == XK_Alt_R ||
       keysym == XK_Meta_L ||
       keysym == XK_Meta_R) 
      Modifier = 0;
    break;
    
  /* -------------------------------------------------------------
     B u t t o n P r e s s
     ------------------------------------------------------------- */
    
  case ButtonPress :
    ButtonPressed++;
    FirstClick=1;
    ibut = event->xbutton.button;
    x    = event->xbutton.x;
    y    = event->xbutton.y;

    switch(ibut){
    case 1:
      if(!ZoomClick && Modifier){
        xb = CTX.vxmin + ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin);
        yb = CTX.vymax - ((GLdouble) y / height) * (CTX.vymax - CTX.vymin);
        xc1 = xb/CTX.s[0] - CTX.t[0];
        yc1 = yb/CTX.s[1] - CTX.t[1];
        ZoomClick=1;
        movzx = movzy = 0;
        Modifier = 0;
      }
      else if(ZoomClick){
        xe = CTX.vxmin + ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin);
        ye = CTX.vymax - ((GLdouble) y / height) * (CTX.vymax - CTX.vymin);
        xc2 = xe/CTX.s[0] - CTX.t[0];
        yc2 = ye/CTX.s[1] - CTX.t[1];     
        ZoomClick=0;
        if(CTX.overlay){
          glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
          glClearIndex(0);
          glClear(GL_COLOR_BUFFER_BIT);  
          glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
        }
        if(xb!=xe && yb!=ye)
          myZoom(xb,xe,yb,ye,xc1,xc2,yc1,yc2);
      } 
      break;
    case 2:
      if(Modifier && !ZoomClick){
        Modifier = 0;
        set_s(1, CTX.s[0]);
        set_s(2, CTX.s[0]);
        Init();
        Draw();
      }
      else{
        ZoomClick=0;
        if(CTX.overlay){
          glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
          glClearIndex(0);
          glClear(GL_COLOR_BUFFER_BIT);  
          glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
        }
      }
      break;      
    case 3:
      if(Modifier && !ZoomClick){
        Modifier = 0;
	if(CTX.useTrackball){
	  CTX.setQuaternion(0.,0.,0.,0.);
	}
	else{
	  set_r(0,0.); set_r(1,0.); set_r(2,0.); 
	}
        set_t(0,0.); set_t(1,0.); set_t(2,0.);
        set_s(0,1.); set_s(1,1.); set_s(2,1.);
        Init();
        Draw();
      }
      else{
        ZoomClick=0;
        if(CTX.overlay){
          glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
          glClearIndex(0);
          glClear(GL_COLOR_BUFFER_BIT);  
          glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
        }
      }
      break;
    }
    break;

  /* -------------------------------------------------------------
      B u t t o n R e l e a s e
     ------------------------------------------------------------- */

  case ButtonRelease :
    if(ButtonPressed>0){
      ButtonPressed--;
      ibut = event->xbutton.button;
      x    = event->xbutton.x;
      y    = event->xbutton.y;
    }
    if(!ZoomClick){
      Init();
      previous_mesh_draw = CTX.mesh.draw ;
      previous_post_draw = CTX.post.draw ;
      if(ButtonPressed>0){
        if(CTX.fast) CTX.mesh.draw = CTX.post.draw = 0;
      }
      Draw();
      CTX.mesh.draw = previous_mesh_draw ;
      CTX.post.draw = previous_post_draw ;
    }
    break;
      
  /* -------------------------------------------------------------
      E n t e r / L e a v e N o t i f y
     ------------------------------------------------------------- */

  case EnterNotify :
  case LeaveNotify :
    ButtonPressed = 0;
    Modifier = 0;
    break;
    
  /* -------------------------------------------------------------
      M o t i o n N o t i f y 
     ------------------------------------------------------------- */

  case MotionNotify :
    movx = (event->xbutton.x-x);
    movy = (event->xbutton.y-y);

    if(ZoomClick) {

      xz = CTX.vxmin + ((GLdouble) event->xbutton.x / width) *
	(CTX.vxmax - CTX.vxmin);
      yz = CTX.vymax - ((GLdouble) event->xbutton.y / height) * 
	(CTX.vymax - CTX.vymin) ;
      if(CTX.overlay) {
        movzx = xz - xb; movzy = yz - yb;
        InitOv();
        glLineWidth(1.);
        glClearIndex(0);
        glClear(GL_COLOR_BUFFER_BIT);  
        glIndexi((CTX.color.bg<CTX.color.fg)?XCTX.xcolor.ovwhite:XCTX.xcolor.ovblack);
        glBegin(GL_LINE_STRIP);
        glVertex2d(xb,yb);
        glVertex2d(xb+movzx,yb);
        glVertex2d(xb+movzx,yb+movzy);
        glVertex2d(xb,yb+movzy);
        glVertex2d(xb,yb);
        glEnd();

        /* Dessine le plus gd rectangle possible si ortho */

        /*
        if(fabs((double)movzx/(double)movzy) > ((double)width/(double)height)){
          constry = movzy;
          constrx = sign(movzx)*fabs(movzy)*((double)width/(double)height);
        }
        else{
          constrx = movzx;
          constry = sign(movzy)*fabs(movzx)*((double)height/(double)width);
        }
        glIndexi(theRed);
        glBegin(GL_LINE_STRIP);
        glVertex2d(xb+constrx,yb);
        glVertex2d(xb+constrx,yb+constry);
        glVertex2d(xb,yb+constry);
        glEnd();
        */

        glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
      }
      else {
        glPopMatrix();
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        
        if(CTX.db) glDrawBuffer(GL_BACK);
        
        glDisable(GL_DEPTH_TEST);
        /* c'est une maniere de contourner l'absence de XOR, mais ca ne marche 
           evidemment qu'avec un background tout noir ou tout blanc !*/
        glColor3f(1.,1.,1.);
        glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
        glEnable(GL_BLEND);

        glBegin(GL_LINE_STRIP);
        glVertex2d(xb,yb);
        glVertex2d(xb+movzx,yb);
        glVertex2d(xb+movzx,yb+movzy);
        glVertex2d(xb,yb+movzy);
        glVertex2d(xb,yb);
        glEnd();
        movzx = xz - xb; movzy = yz - yb;
        
        glBegin(GL_LINE_STRIP);
        glVertex2d(xb,yb);
        glVertex2d(xb+movzx,yb);
        glVertex2d(xb+movzx,yb+movzy);
        glVertex2d(xb,yb+movzy);
        glVertex2d(xb,yb);
        glEnd();

        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        
        if(CTX.db)
          glXSwapBuffers(XCTX.display,XtWindow(WID.G.glw));
        else
          glFlush();

      }
    }
    else {
      if(ButtonPressed){

        if(CTX.overlay){
          glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
          glClearIndex(0);
          glClear(GL_COLOR_BUFFER_BIT);  
          glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
        }

        if(FirstClick){
          xc1 = ( ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin) 
		  + CTX.vxmin )/CTX.s[0] - CTX.t[0];
          yc1 = ( CTX.vymax - ((GLdouble) y / height) * 
		  (CTX.vymax - CTX.vymin))/CTX.s[1] - CTX.t[1];
          xt1 = CTX.t[0];
          yt1 = CTX.t[1];
          xscale1 = CTX.s[0];
          yscale1 = CTX.s[1];
          FirstClick=0;
        }

        switch(ibut){
        case 1:
	  
	  if(CTX.useTrackball)
	    {
	      CTX.addQuaternion ((2.0*x - width) / width,
				 (height - 2.0*y) / height,
				 (2.0*event->xbutton.x - width) / width,
				 (height - 2.0*event->xbutton.y) / height);
	    }
	  else
	    {
	      set_r(1, CTX.r[1] + ((abs(movx) > abs(movy))?180*(float)movx/(float)width:0));
	      set_r(0, CTX.r[0] + ((abs(movx) > abs(movy))?0:180*(float)movy/(float)height));
	    }
          break;
        case 2:
	  if(!CTX.useTrackball)
	    set_r(2, CTX.r[2] + ((abs(movy) > abs(movx))?0:-180*(float)movx/(float)width));         

          set_s(0, CTX.s[0] * ( (abs(movy) > abs(movx)) ?
                                ( (movy>0) ? (float)(1.04*(abs(movy)+height))/(float)height
                                  : (float)(height)/(float)(1.04*(abs(movy)+height)) )
                                : 1.) );                    
          set_s(1, CTX.s[0]);
          set_s(2, CTX.s[0]);

          if(abs(movy) > abs(movx)){
            set_t(0, xt1*(xscale1/CTX.s[0])-xc1*(1.-(xscale1/CTX.s[0])));
            set_t(1, yt1*(yscale1/CTX.s[1])-yc1*(1.-(yscale1/CTX.s[1])));
          }
          break;
        case 3:
          xc = ( ((GLdouble) x / width) * (CTX.vxmax - CTX.vxmin) + 
		 CTX.vxmin ) / CTX.s[0];
          yc = ( CTX.vymax - ((GLdouble) y / height) *
		 (CTX.vymax - CTX.vymin)) / CTX.s[1];
          set_t(0, xc-xc1);
          set_t(1, yc-yc1);
          set_t(2, 0.);
          break;
        }
        Init();
        previous_mesh_draw = CTX.mesh.draw ;
        previous_post_draw = CTX.post.draw ;
        if(CTX.fast) CTX.mesh.draw = CTX.post.draw = 0;
        Draw();
        CTX.mesh.draw = previous_mesh_draw ;
        CTX.post.draw = previous_post_draw ;
      }
      else{
        Process_SelectionBuffer(event->xbutton.x, event->xbutton.y, &hits, ii, jj);
        ov = v; oc = c; os = s; 
        v = NULL; c = NULL; s = NULL;
        Filter_SelectionBuffer(hits,ii,jj,&v,&c,&s,&M);

        if(CTX.overlay){
          glXMakeCurrent(XtDisplay(WID.G.glo), XtWindow(WID.G.glo), XCTX.glo.context);
          if(ov != v || oc != c || os != s) { 
            glClearIndex(0);
            glClear(GL_COLOR_BUFFER_BIT);  
            glIndexi((CTX.color.bg<CTX.color.fg)?XCTX.xcolor.ovwhite:XCTX.xcolor.ovblack);
            BeginHighlight();
            HighlightEntity(v,c,s,0);
            EndHighlight(0);
          }
          glXMakeCurrent(XtDisplay(WID.G.glw), XtWindow(WID.G.glw), XCTX.glw.context);
        }
        else{
          if(ov != v || oc != c || os != s) { 
            if(CTX.geom.highlight){
              Init();
              Draw();
            }
            BeginHighlight();
            HighlightEntity(v,c,s,0);
            EndHighlight(0);
          }
        }
      }
      x += movx; 
      y += movy; 
    }
    break;
  }
}

