// $Id: CbGeneral.cpp,v 1.2 2001-01-09 14:24:11 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Context.h"
#include "XContext.h"
#include "Widgets.h"

extern Context_T   CTX;
extern XContext_T  XCTX;
extern Widgets_T   WID;

extern void GetStatistics(double s[50]);

static char label[32];

/* ------------------------------------------------------------------------ 
    E x i t C b                                                             
   ------------------------------------------------------------------------ */

void ExitCb(Widget w, XtPointer cd, XtPointer cb){
  exit(0);
}

/* ------------------------------------------------------------------------ 
    M a n a g e C b                                                         
   ------------------------------------------------------------------------ */

void ManageCb (Widget w, XtPointer client_data, XtPointer call_data){
  XtIsManaged((Widget)client_data) ? 
    XtUnmanageChild((Widget)client_data) : 
    XtManageChild((Widget)client_data) ;
}


/* ------------------------------------------------------------------------ 
    P o p u p H a n d l e r                                                 
   ------------------------------------------------------------------------ */

void PopupHandler (Widget w, Widget pw, XEvent *event, Boolean *ctd ){
  if(((XButtonEvent *)event)->button != Button3) return;

  /* force the pointer to be slightly over the first button */
  ((XButtonEvent *)event)->x_root -= 7 ;
  ((XButtonEvent *)event)->y_root -= 7 ;

  XmMenuPosition(pw, (XButtonEvent *)event);
  XtManageChild(pw);
}



/* ------------------------------------------------------------------------ 
    CurrentInfoCb
   ------------------------------------------------------------------------ */

void CurrentInfoCb (Widget w, XtPointer client_data, XtPointer call_data){
  double  s[50];
  int     i;
  Post_View  *v ;

  if((long int)client_data && XtIsManaged(WID.OD.infoDialog)){
    XtUnmanageChild(WID.OD.infoDialog);
  }
  else{
    GetStatistics(s);

#define VLAB(caca)  WID.OD.infoValueLabel[(caca)], XmNlabelString, \
                    XmStringCreateSimple(label), NULL

    /* info geom */
    sprintf(label, "%g", s[0]);   XtVaSetValues(VLAB(0));
    sprintf(label, "%g", s[1]);   XtVaSetValues(VLAB(1));
    sprintf(label, "%g", s[2]);   XtVaSetValues(VLAB(2));
    sprintf(label, "%g", s[3]);   XtVaSetValues(VLAB(3));
                                                
    /* info mesh */                             
    sprintf(label, "%g", s[4]);   XtVaSetValues(VLAB(4));
    sprintf(label, "%g", s[5]);   XtVaSetValues(VLAB(5));
    sprintf(label, "%g", s[6]);   XtVaSetValues(VLAB(6));

    sprintf(label, "%g", s[7]-s[8]);   XtVaSetValues(VLAB(7));
    sprintf(label, "%g", s[8]);   XtVaSetValues(VLAB(8));
    sprintf(label, "%g", s[9]);   XtVaSetValues(VLAB(9));
    sprintf(label, "%g", s[10]);  XtVaSetValues(VLAB(10));
    sprintf(label, "%g", s[11]);  XtVaSetValues(VLAB(11));

    sprintf(label, "%g", s[12]);  XtVaSetValues(VLAB(12));
    sprintf(label, "%g", s[13]);  XtVaSetValues(VLAB(13));
    sprintf(label, "%g", s[14]);  XtVaSetValues(VLAB(14));

    sprintf(label, "%.4g (%.4g->%.4g)", s[17], s[19], s[18]); XtVaSetValues(VLAB(15));
    sprintf(label, "%.4g (%.4g->%.4g)", s[20], s[22], s[21]); XtVaSetValues(VLAB(16));
    sprintf(label, "%.4g (%.4g->%.4g)", s[23], s[25], s[24]); XtVaSetValues(VLAB(17));

    /* info post */

    s[15] = List_Nbr(Post_ViewList) ;
    sprintf(label, "%g", s[15]);  XtVaSetValues(VLAB(18));

    s[16] = s[17] = s[18] = s[19] = 0 ;
    for(i=0 ; i<List_Nbr(Post_ViewList) ; i++){
      v = (Post_View*)List_Pointer(Post_ViewList, i);
      if(v->Visible){
	s[16] += v->NbSP + v->NbVP + v->NbTP;
	s[17] += v->NbSL + v->NbVL + v->NbTL;
	s[18] += v->NbST + v->NbVT + v->NbTT;
	s[19] += v->NbSS + v->NbVS + v->NbTS;
      }
    }
    sprintf(label, "%g", s[16]); XtVaSetValues(VLAB(19));
    sprintf(label, "%g", s[17]); XtVaSetValues(VLAB(20));
    sprintf(label, "%g", s[18]); XtVaSetValues(VLAB(21));
    sprintf(label, "%g", s[19]); XtVaSetValues(VLAB(22));

#undef VLAB

    if((long int)client_data)
      XtManageChild(WID.OD.infoDialog) ;
    else
      XmUpdateDisplay(WID.OD.infoDialog);
  }
  
}

/* ------------------------------------------------------------------------ 
    set_XXX
   ------------------------------------------------------------------------ */

void set_r(int i, double val){
  if(CTX.useTrackball){
    if(XtIsManaged(WID.OD.viewportDialog)){
      sprintf(label, "---");
      XtVaSetValues(WID.OD.viewportText[0][i], XmNvalue, label, NULL);
      XmUpdateDisplay(WID.OD.viewportText[0][i]);  
    }
  }
  else{
    if(!CTX.rlock[i]){
      CTX.r[i] = val;
      if(XtIsManaged(WID.OD.viewportDialog)){
	sprintf(label, "%.5g", CTX.r[i]);
	XtVaSetValues(WID.OD.viewportText[0][i], XmNvalue, label, NULL);
	XmUpdateDisplay(WID.OD.viewportText[0][i]);  
      }
    }
  }
}

void set_t(int i, double val){
  if(!CTX.tlock[i]){
    CTX.t[i] = val;
    if(XtIsManaged(WID.OD.viewportDialog)){
      sprintf(label, "%.5g", CTX.t[i]);
      XtVaSetValues(WID.OD.viewportText[1][i], XmNvalue, label, NULL);
      XmUpdateDisplay(WID.OD.viewportText[1][i]);  
    }
  }
}

void set_s(int i, double val){
  if(!CTX.slock[i]){
    CTX.s[i] = val;
    if(XtIsManaged(WID.OD.viewportDialog)){
      sprintf(label, "%.5g", CTX.s[i]);
      XtVaSetValues(WID.OD.viewportText[2][i], XmNvalue, label, NULL);
      XmUpdateDisplay(WID.OD.viewportText[2][i]);  
    }
  }
}


/* ------------------------------------------------------------------------ 
    CurrentViewportCb
   ------------------------------------------------------------------------ */

void CurrentViewportCb (Widget w, XtPointer client_data, XtPointer call_data){
  int     i;

  if(XtIsManaged(WID.OD.viewportDialog)){ 
    XtUnmanageChild(WID.OD.viewportDialog);
  }
  else{
    for(i=0 ; i<3 ; i++){
      sprintf(label, "%.5g", CTX.r[i]);
      XtVaSetValues(WID.OD.viewportText[0][i], XmNvalue, label, NULL);
      sprintf(label, "%.5g", CTX.t[i]);
      XtVaSetValues(WID.OD.viewportText[1][i], XmNvalue, label, NULL);
      sprintf(label, "%.5g", CTX.s[i]);
      XtVaSetValues(WID.OD.viewportText[2][i], XmNvalue, label, NULL);
    }    
    XtManageChild(WID.OD.viewportDialog) ;    
  }

}

