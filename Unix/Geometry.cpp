/* $Id: Geometry.cpp,v 1.4 2000-12-08 10:56:51 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "XContext.h"
#include "Widgets.h"

extern Context_T   CTX ;
extern XContext_T  XCTX ;

#define WINDOW_SHADOW   1
#define SHADOW          2
#define IN_FRAME_TYPE   XmSHADOW_ETCHED_IN
#define IN_FRAME_SHADOW 2
#define TITLE_SPACE     0
#define TITLE_ALIGN     XmALIGNMENT_WIDGET_TOP
#define DIALOG_W        6
#define DIALOG_H        4


/* 
   XmNchildVerticalAlignment : 
   CENTER, WIDGET_TOP, WIDGET_BOTTOM, BASELINE_BOTTOM, BASELINE_TOP  

   XmNshadowType :
   ETCHED_IN, ETCHED_OUT, IN, OUT
*/

/* ------------------------------------------------------------------------ 
    MENU WINDOW
   ------------------------------------------------------------------------ */

void ForceGeometry_M (Widgets_T *w){
  int     n;

  XtVaSetValues(w->M.containerWin,
                XmNmenuBar, w->M.menuBar,
                NULL);

  XtVaSetValues(w->M.menuBar,
                XmNmenuHelpWidget, w->M.helpCascade, 
                NULL);

  XtVaSetValues(w->M.menuFrame,
                XmNshadowType, XmSHADOW_OUT,
                XmNshadowThickness, WINDOW_SHADOW,
                NULL);

  XtVaSetValues(w->M.menuForm,
                XmNfractionBase, 100,
                XmNmarginWidth, 3,
                XmNmarginHeight, 3,
                NULL);

  XtVaSetValues(w->M.modButt,
                XmNmarginHeight, 5,
                XmNmarginWidth, 2,
                XmNtopAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_WIDGET,
                XmNleftWidget, w->M.navigButt[0],
                XmNrightAttachment, XmATTACH_WIDGET,
                XmNrightWidget, w->M.navigButt[1],
                NULL);

  XtVaSetValues(w->M.navigButt[0],
                XmNshadowThickness, 0,
                XmNwidth, 20,
                XmNleftAttachment, XmATTACH_FORM,
                NULL);

  XtVaSetValues(w->M.navigButt[1],
                XmNshadowThickness, 0,
                XmNwidth, 20,
                XmNrightAttachment, XmATTACH_FORM,
                NULL);

  XtVaSetValues(w->M.defaultButt,
                XmNmarginHeight, 5,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNtopWidget, w->M.modButt,
                XmNleftAttachment, XmATTACH_FORM,
                XmNrightAttachment, XmATTACH_FORM,
                NULL);

  XtVaSetValues(w->M.pushButt[0],
                XmNshadowThickness, SHADOW,
                XmNmarginHeight, 5,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNtopWidget, w->M.modButt,
                XmNleftAttachment, XmATTACH_FORM,
                XmNrightAttachment, XmATTACH_FORM,
                NULL);
  
  XtVaSetValues(w->M.toggleButt[0],
                XmNshadowThickness, SHADOW,
                XmNmarginHeight, 3,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNtopWidget, w->M.modButt,
                XmNleftAttachment, XmATTACH_FORM,
                XmNrightAttachment, XmATTACH_FORM,
                NULL);

  for(n=1 ; n<NB_BUTT_MAX ; n++){
    XtVaSetValues(w->M.pushButt[n],
                  XmNtopAttachment, XmATTACH_WIDGET,
                  XmNtopWidget, w->M.pushButt[n-1],
                  XmNleftAttachment, XmATTACH_FORM,
                  XmNrightAttachment, XmATTACH_FORM,
                  XmNshadowThickness, SHADOW,
                  XmNmarginHeight, 5,
                  NULL);

    XtVaSetValues(w->M.toggleButt[n],
                  XmNtopAttachment, XmATTACH_WIDGET,
                  XmNtopWidget, w->M.toggleButt[n-1],
                  XmNleftAttachment, XmATTACH_FORM,
                  XmNrightAttachment, XmATTACH_FORM,
                  XmNshadowThickness, SHADOW,
                  XmNmarginHeight, 3,
                  NULL);
  }

}

/* ------------------------------------------------------------------------ 
    GRAPHIC WINDOW
   ------------------------------------------------------------------------ */

void ForceGeometry_G (Widgets_T *w){
  int  i;

  XtVaSetValues(w->G.glw,
                XmNtopAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_FORM,
                XmNrightAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_WIDGET,
                XmNbottomWidget, w->G.bottomForm,
                NULL);

  if(CTX.overlay)
    XtVaSetValues(w->G.glo,
                  XmNtopAttachment, XmATTACH_FORM,
                  XmNleftAttachment, XmATTACH_FORM,
                  XmNrightAttachment, XmATTACH_FORM,
                  XmNbottomAttachment, XmATTACH_WIDGET,
                  XmNbottomWidget, w->G.bottomForm,
                  NULL);

  XtVaSetValues(w->G.bottomForm,
                XmNleftAttachment, XmATTACH_FORM,
                XmNrightAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNmarginHeight, 2,
                XmNmarginWidth, 1,
                XmNshadowThickness, WINDOW_SHADOW,
                XmNfractionBase, 100,
                NULL);

  XtVaSetValues(w->G.Butt[0],
                XmNtopAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_FORM,
                XmNshadowThickness, 0,
                XmNmarginHeight, 1,
                NULL);

  for(i=1 ; i<7 ; i++) {
    XtVaSetValues(w->G.Butt[i],
                  XmNtopAttachment, XmATTACH_FORM,
                  XmNbottomAttachment, XmATTACH_FORM,
                  XmNleftAttachment, XmATTACH_WIDGET,
                  XmNleftWidget, w->G.Butt[i-1],
                  XmNshadowThickness, 0,
                  XmNmarginHeight, 1,
                  NULL);
  }

  XtVaSetValues(w->G.textForm,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNtopAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_WIDGET,
                XmNleftWidget, w->G.Butt[6],
                XmNrightAttachment, XmATTACH_FORM,
                XmNfractionBase, 300,
                NULL);

  XtVaSetValues(w->G.selectLabel,
                XmNtopAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNleftPosition, 2,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNrightPosition, 90,
                XmNmarginHeight, 0,
                NULL);

  XtVaSetValues(w->G.infoLabel,
                XmNtopAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNleftPosition, 92,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNrightPosition, 180,
                XmNmarginHeight, 0,
                NULL);

  XtVaSetValues(w->G.statusLabel,
                XmNtopAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNleftPosition, 182,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNrightPosition, 298,
                XmNmarginHeight, 0,
                NULL);


}

/* ------------------------------------------------------------------------ 
    COMMAND WINDOW
   ------------------------------------------------------------------------ */

void ForceGeometry_C (Widgets_T *w){
  
  XtVaSetValues(w->C.command,
                XmNshadowThickness, WINDOW_SHADOW,
                XmNshadowType, XmSHADOW_OUT,
                XmNmarginHeight, 2,
                XmNmarginWidth, 2,
                NULL);

  XtVaSetValues(w->C.commandList,
                XmNshadowThickness, SHADOW,
                XmNmarginHeight, 0,
                NULL);

  XtVaSetValues(w->C.commandText,
                XmNshadowThickness, SHADOW,
                XmNmarginHeight, 4,
                NULL);
}

/* ------------------------------------------------------------------------ 
    DIALOGS
   ------------------------------------------------------------------------ */

void ForceGeometry_ED (Widgets_T *w){
}

void ForceGeometry_FD (Widgets_T *w){

  XtVaSetValues(w->FD.openDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->FD.mergeDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->FD.saveAsDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->FD.saveAsFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->FD.saveAsFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->FD.saveAsRowCol,
                XmNmarginWidth, 0,
                NULL);

  XtVaSetValues(w->FD.printDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->FD.printFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->FD.printFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->FD.printRowCol,
                XmNmarginWidth, 0,
                NULL);

}

void ForceGeometry_OD (Widgets_T *w){
  int  i,j;

  XtVaSetValues(w->OD.geomDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->OD.geomVisibleFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.geomVisibleFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.geomVisibleByNumFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.geomVisibleByNumFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.geomNormalsFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.geomNormalsFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.geomTangentsFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.geomTangentsFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.meshDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->OD.meshAlgoFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshAlgoFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);
  
  XtVaSetValues(w->OD.meshSmoothingFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshSmoothingFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.meshVisibleFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshVisibleFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.meshVisibleByNumFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshVisibleByNumFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.meshAspectFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshAspectFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.meshExplodeFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshExplodeFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.meshNormalsFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.meshNormalsFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.postDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->OD.postLinkFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.postLinkFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.postAnimFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.postAnimFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.miscDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->OD.miscMiscFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.miscMiscFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.miscColorSchemeFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.miscColorSchemeFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);
  
  XtVaSetValues(w->OD.miscProjFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.miscProjFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.miscLightFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.miscLightFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.miscShineFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->OD.miscShineFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->OD.viewportDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);
  
  for(i=0 ; i<3 ; i++){
    XtVaSetValues(w->OD.viewportFrame[0][i],    
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);
                  
    XtVaSetValues(w->OD.viewportFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);

    for(j=0 ; j<3 ; j++){
      XtVaSetValues(w->OD.viewportLockButt[j][i],
                    XmNmarginHeight, 0,
                    NULL);
    }
  }

  XtVaSetValues(w->OD.infoDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<3 ; i++){
    XtVaSetValues(w->OD.infoFrame[0][i],    
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);
                  
    XtVaSetValues(w->OD.infoFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }

}

void ForceGeometry_HD (Widgets_T *w){

  XtVaSetValues(w->HD.keysDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);
}

void ForceGeometry_GD (Widgets_T *w){
  int  i;

  XtVaSetValues(w->GD.paramDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<2 ; i++){
    XtVaSetValues(w->GD.paramFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);

    XtVaSetValues(w->GD.paramFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }


  XtVaSetValues(w->GD.pointDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<2 ; i++){
    XtVaSetValues(w->GD.pointFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);

    XtVaSetValues(w->GD.pointFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }

  XtVaSetValues(w->GD.rotDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<3 ; i++){
    XtVaSetValues(w->GD.rotFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);

    XtVaSetValues(w->GD.rotFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }

  XtVaSetValues(w->GD.tranDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->GD.tranFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->GD.tranFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->GD.dilatDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<2 ; i++){
    XtVaSetValues(w->GD.dilatFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);

    XtVaSetValues(w->GD.dilatFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }

}

void ForceGeometry_MD (Widgets_T *w){
  int  i;

  XtVaSetValues(w->MD.charLengthDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->MD.charLengthFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->MD.charLengthFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->MD.trsfLineDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<2 ; i++){
    XtVaSetValues(w->MD.trsfLineFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);
    XtVaSetValues(w->MD.trsfLineFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }
  
  XtVaSetValues(w->MD.trsfVolumeDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->MD.trsfVolumeFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->MD.trsfVolumeFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

}

void ForceGeometry_PD (Widgets_T *w){
  int  i;
  

  XtVaSetValues(w->PD.offsetDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<4 ; i++){
    XtVaSetValues(w->PD.offsetFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);
    XtVaSetValues(w->PD.offsetFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }
  
  XtVaSetValues(w->PD.timeStepDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->PD.timeStepFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);
  XtVaSetValues(w->PD.timeStepFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->PD.scaleDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<3 ; i++){
    XtVaSetValues(w->PD.scaleFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);
    XtVaSetValues(w->PD.scaleFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }


  XtVaSetValues(w->PD.colorDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);
  XtVaSetValues(w->PD.colorFrame[0][0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);
  XtVaSetValues(w->PD.colorFrame[1][0],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);
  XtVaSetValues(w->PD.colorDrawingArea,
                XmNtopAttachment, XmATTACH_FORM,
                XmNleftAttachment, XmATTACH_FORM,
                XmNrightAttachment, XmATTACH_FORM,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNwidth, 255,
                XmNheight, 200,
                NULL);


  XtVaSetValues(w->PD.vectorDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  for(i=0 ; i<3 ; i++){
    XtVaSetValues(w->PD.vectorFrame[0][i],
                  XmNshadowType, IN_FRAME_TYPE,
                  XmNshadowThickness, IN_FRAME_SHADOW,
                  NULL);
    XtVaSetValues(w->PD.vectorFrame[1][i],
                  XmNchildHorizontalSpacing, TITLE_SPACE,
                  XmNchildVerticalAlignment, TITLE_ALIGN,
                  NULL);
  }

  XtVaSetValues(w->PD.exportBGMDialog,
                XmNmarginHeight, DIALOG_H,
                XmNmarginWidth, DIALOG_W,
                NULL);

  XtVaSetValues(w->PD.exportBGMFrame[0],
                XmNshadowType, IN_FRAME_TYPE,
                XmNshadowThickness, IN_FRAME_SHADOW,
                NULL);

  XtVaSetValues(w->PD.exportBGMFrame[1],
                XmNchildHorizontalSpacing, TITLE_SPACE,
                XmNchildVerticalAlignment, TITLE_ALIGN,
                NULL);

  XtVaSetValues(w->PD.exportBGMText,
                XmNmarginHeight, 2,
                NULL);

}


/* ------------------------------------------------------------------------ 
    F o r c e G e o m e t r y
   ------------------------------------------------------------------------ */

void ForceGeometry (Widgets_T *w){  
  ForceGeometry_M(w) ; /* menu win */
  ForceGeometry_G(w) ; /* graphic win */
  if(CTX.command_win) ForceGeometry_C(w) ; /* command win */

  ForceGeometry_ED(w); /* error dialogs */
  ForceGeometry_FD(w); /* file dialogs */
  ForceGeometry_OD(w); /* option dialogs */
  ForceGeometry_HD(w); /* help dialogs */
  ForceGeometry_GD(w); /* geometry dialogs */
  ForceGeometry_MD(w); /* mesh dialogs */
  ForceGeometry_PD(w); /* post dialogs */
}

