/* $Id: CbPost.cpp,v 1.7 2000-11-27 10:58:59 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "ColorTable.h"
#include "Widgets.h"
#include "Context.h"
#include "XContext.h"
#include "Main.h"

#include "CbPost.h"
#include "CbGeom.h"
#include "CbMesh.h"
#include "CbColorbar.h"

extern Widgets_T  WID ;
extern Context_T  CTX ;
extern XContext_T XCTX ;
extern Mesh       *THEM;
extern List_T     *Post_ViewList;
extern int         Force_ViewNumber;

static double      ADAPTATION_ERROR=10. ;
static int         ADAPTATION_METHOD=3 ;
static int         OFFSET_MODE = 0;
static Post_View  *CurrentView = NULL;
static long int    CurrentViewNumber = -1;
static Post_View  *ViewForDialog[10];

void MarkAllViewsChanged (int action){
  int i;
  char label[256];
  Post_View *v;

  for(i = 0 ; i< List_Nbr(Post_ViewList) ; i++){
    v = (Post_View*)List_Pointer(Post_ViewList, i);
    switch(action){
    case 1: // toggle drawing mode
      if(v->IntervalsType == DRAW_POST_ISO) 
        v->IntervalsType = DRAW_POST_DISCRETE ;
      else if(v->IntervalsType == DRAW_POST_DISCRETE) 
        v->IntervalsType = DRAW_POST_CONTINUOUS ;
      else 
        v->IntervalsType = DRAW_POST_ISO ;
      break;
    case 2: // time step++
      if(v->TimeStep < v->NbTimeStep-1)
        v->TimeStep++ ;
      else
        v->TimeStep = 0 ;
      sprintf(label, "%d", v->TimeStep);
      XtVaSetValues(WID.PD.timeStepScale, XmNvalue, v->TimeStep, NULL);
      XmUpdateDisplay(WID.PD.timeStepScale);
      XtVaSetValues(WID.PD.timeStepText, XmNvalue, label, NULL);
      XmUpdateDisplay(WID.PD.timeStepText);    
      break;
    case 3: // time step--
      if(v->TimeStep > 0)
        v->TimeStep-- ;
      else
        v->TimeStep = v->NbTimeStep-1 ;
      sprintf(label, "%d", v->TimeStep);
      XtVaSetValues(WID.PD.timeStepScale, XmNvalue, v->TimeStep, NULL);
      XmUpdateDisplay(WID.PD.timeStepScale);
      XtVaSetValues(WID.PD.timeStepText, XmNvalue, label, NULL);
      XmUpdateDisplay(WID.PD.timeStepText);    
      break;
    default :
      break;
    }
    
    v->Changed = 1 ;
  }
}

void SwapViewCb (Widget w, XtPointer client_data, XtPointer call_data){
  Post_View  *v ;

  if(!Post_ViewList) return;

  v = (Post_View*)List_Pointer(Post_ViewList,(long int)client_data-1);

  Msg(DEBUG,    "View %d\n"
      DEBUG_NIL "  -> Name '%s'\n"
      DEBUG_NIL "  -> FileName '%s'\n"
      DEBUG_NIL "  -> DuplicateOf %d\n"
      DEBUG_NIL "  -> Links %d",
      v->Num, v->Name, v->FileName, v->DuplicateOf, v->Links);

  v->Visible = !v->Visible;

  Init();
  Draw();
}



void DuplicateViewCb (Widget w, XtPointer client_data, XtPointer call_data){
  Post_View  v, *v1, *v2, *v3 ;
  extern void AddViewInUI(int , char *, int);

  if(!Post_ViewList) return;

  v1 = (Post_View*)List_Pointer(Post_ViewList,(long int)client_data-1);

  BeginView(0);
  EndView(0, 0, v1->FileName, v1->Name, 0., 0., 0.);

  v2 = (Post_View*)List_Pointer(Post_ViewList,List_Nbr(Post_ViewList)-1);

  if(!v1->DuplicateOf){
    v2->DuplicateOf = v1->Num ;
    v1->Links++ ;
  }
  else{
    v.Num = v1->DuplicateOf ;
    if(!(v3 = (Post_View*)List_PQuery(Post_ViewList, &v, fcmpPostViewNum))){
      v2->DuplicateOf = v1->Num ;
      v1->Links++ ;
    }
    else{
      v2->DuplicateOf = v3->Num;
      v3->Links++ ;
    }
  }

  v2->Time        = v1->Time;
  v2->ScalarOnly  = v1->ScalarOnly;
  v2->Min         = v1->Min;       
  v2->Max         = v1->Max;      
  v2->NbTimeStep  = v1->NbTimeStep;

  CopyViewOptions(v1, v2);

  AddViewInUI(List_Nbr(Post_ViewList), v2->Name, v2->Num);
  Init();
  Draw();
}

static int All = 0;

void ReloadViewCb (Widget w, XtPointer client_data, XtPointer call_data){
  Post_View  *v, tmp ;
  char filename[NAME_STR_L];

  if(!Post_ViewList) return;

  v = (Post_View*)List_Pointer(Post_ViewList,(long int)client_data-1);
  strcpy(filename, v->FileName);
  CopyViewOptions(v, &tmp);

  Force_ViewNumber = v->Num ;
  FreeView(v);
  MergeProblem(filename);
  Force_ViewNumber = 0 ;
  
  v = (Post_View*)List_Pointer(Post_ViewList,(long int)client_data-1);
  CopyViewOptions(&tmp, v);

  if(!All){
    Init();
    Draw();
  }
}

void ReloadAllViewsCb(Widget w, XtPointer client_data, XtPointer call_data){
  int i;
  if(!Post_ViewList) return;
  All = 1;
  for(i = 1 ; i<=List_Nbr(Post_ViewList) ; i++)
    ReloadViewCb(NULL, (XtPointer)i, NULL);
  All = 0;
  Init();
  Draw();
}


void SaveColorTable(FILE *fp){
  if(!CurrentView){
    Msg(WARNING, "No View to get Color Information From"); 
  }
  else{
    ColorTable_Save(fp, &CurrentView->CT);
  }
}

/* ------------------------------------------------------------------------ 
   create a post dialog 
   ------------------------------------------------------------------------ */

void CurrentViewCb (Widget w, XtPointer client_data, XtPointer call_data){
  CurrentViewNumber = (long int)client_data;
  CurrentView = (Post_View*)List_Pointer(Post_ViewList, CurrentViewNumber-1);
}

void PostDialogCb (Widget w, XtPointer client_data, XtPointer call_data){
  double       d, sfact;
  char         label[256];
  int          nb, i;
  Post_View   *v;

  v = CurrentView ;

  /* le slider (gradue en interne de -100 a 100) va de -CTX.lc a +CTX.lc  */
  sfact = pow(10.,2.-CTX.lc_order); 

  sprintf(label, "\"%s\" (%ld)", v->Name, CurrentViewNumber);

  switch((long int)client_data){

    /* Toggle Lightning */
  case POST_LIGHT:     
    v->Light = !v->Light;
    v->Changed = 1;
    Init() ;
    Draw() ;
    break;

    /* Toggle Show Elements */
  case POST_ELEMENT:     
    v->ShowElement = !v->ShowElement;
    v->Changed = 1;
    Init() ;
    Draw() ;
    break;

    /* Offset */
  case POST_OFFSET: 
    ViewForDialog[POST_OFFSET] = v;
    XtVaSetValues(WID.PD.offsetDialog, XmNdialogTitle, XmStringCreateSimple(label), NULL);
    XtVaSetValues(WID.PD.offsetModeButt[0], XmNset, (OFFSET_MODE==0)?True:False, NULL);
    XtVaSetValues(WID.PD.offsetModeButt[1], XmNset, (OFFSET_MODE==1)?True:False, NULL);
    for(i=0 ; i<3 ; i++){
      d = (OFFSET_MODE==1)?v->Raise[i]:v->Offset[i] ;
      sprintf(label, "%g", d);
      XtVaSetValues(WID.PD.offsetText[i], XmNvalue, label, NULL);
      XtVaSetValues(WID.PD.offsetScale[i], XmNvalue, THRESHOLD((int)(sfact*d),-100,100), NULL);    
    }
    XtManageChild(WID.PD.offsetDialog);
    break;

    /* Time Step */
  case POST_TIME_STEP: 
    ViewForDialog[POST_TIME_STEP] = v;
    XtVaSetValues(WID.PD.timeStepDialog, XmNdialogTitle, XmStringCreateSimple(label), NULL);
    XtVaSetValues(WID.PD.timeStepScale, XmNmaximum, v->NbTimeStep-1, XmNvalue, v->TimeStep, NULL);
    sprintf(label, "%d", v->TimeStep);
    XtVaSetValues(WID.PD.timeStepText, XmNvalue, label, NULL);
    XtManageChild(WID.PD.timeStepDialog);
    break;

    /* Scale */
  case POST_SCALE: 
    ViewForDialog[POST_SCALE] = v;
    XtVaSetValues(WID.PD.scaleDialog, XmNdialogTitle, XmStringCreateSimple(label), NULL);

    XtVaSetValues(WID.PD.scaleShowButt, XmNset, v->ShowScale?True:False, NULL);
    XtVaSetValues(WID.PD.scaleTransButt, XmNset, v->TransparentScale?True:False, NULL);
    XtVaSetValues(WID.PD.scaleTimeButt, XmNset, v->ShowTime?True:False, NULL);

    XtVaSetValues(WID.PD.scaleText[0], XmNvalue, v->Format, NULL);
    XtSetSensitive(WID.PD.scaleText[0], v->ShowScale?1:0);
    XtVaSetValues(WID.PD.scaleText[1], XmNvalue, v->Name, NULL);
    XtSetSensitive(WID.PD.scaleText[1], v->ShowScale?1:0);

    XtVaSetValues(WID.PD.scaleRangeButt, XmNset, (v->RangeType==DRAW_POST_CUSTOM)?True:False, NULL);
    sprintf(label, v->Format, v->CustomMin);
    XtVaSetValues(WID.PD.scaleRangeText[0], XmNvalue, label, NULL);
    sprintf(label, v->Format, v->CustomMax);
    XtVaSetValues(WID.PD.scaleRangeText[1], XmNvalue, label, NULL);
    XtSetSensitive(WID.PD.scaleRangeText[0], (v->RangeType==DRAW_POST_CUSTOM)?1:0);
    XtSetSensitive(WID.PD.scaleRangeText[1], (v->RangeType==DRAW_POST_CUSTOM)?1:0);

    XtVaSetValues(WID.PD.scaleTypeButt[0], XmNset,(v->ScaleType==DRAW_POST_LINEAR)?True:False, NULL);
    XtVaSetValues(WID.PD.scaleTypeButt[1], XmNset,(v->ScaleType==DRAW_POST_LOGARITHMIC)?True:False, NULL);

    XtVaSetValues(WID.PD.scaleIntervalsButt[0], XmNset,
                  (v->IntervalsType==DRAW_POST_ISO)?True:False, NULL);
    XtVaSetValues(WID.PD.scaleIntervalsButt[1], XmNset,
                  (v->IntervalsType==DRAW_POST_DISCRETE)?True:False, NULL);
    XtVaSetValues(WID.PD.scaleIntervalsButt[2], XmNset,
                  (v->IntervalsType==DRAW_POST_CONTINUOUS)?True:False, NULL);
    XtVaSetValues(WID.PD.scaleIntervalsButt[3], XmNset,
                  (v->IntervalsType==DRAW_POST_NUMERIC)?True:False, NULL);
    XtVaSetValues(WID.PD.scaleIntervalsScale, XmNvalue, THRESHOLD((int)v->NbIso,1,100), NULL);

    sprintf(label, "%d", v->NbIso);
    XtVaSetValues(WID.PD.scaleIntervalsText, XmNvalue, label, NULL);

    XtManageChild(WID.PD.scaleDialog);
    break;

    /* Color */
  case POST_COLOR: 
    ViewForDialog[POST_COLOR] = v;
    XtVaSetValues(WID.PD.colorDialog, XmNdialogTitle, XmStringCreateSimple(label), NULL);
    XtManageChild(WID.PD.colorDialog);

    XSelectInput(XCTX.display, XtWindow(WID.PD.colorDrawingArea), EV_MASK);
    ColorBarCreate(XtWindow(WID.PD.colorDrawingArea),255,200);
    ColorBarChange(v->Name, 
                   (v->RangeType==DRAW_POST_CUSTOM)?v->CustomMin:v->Min, 
                   (v->RangeType==DRAW_POST_CUSTOM)?v->CustomMax:v->Max, 
                   &v->CT, 1);
    ColorBarResizeCb((Widget)NULL, NULL, NULL); // Force resize
    ColorBarShow();
    break;

    /* Vector */
  case POST_VECTOR: 
    ViewForDialog[POST_VECTOR] = v;
    XtVaSetValues(WID.PD.vectorDialog, XmNdialogTitle, XmStringCreateSimple(label), NULL);
    XtVaSetValues(WID.PD.vectorTypeButt[0], XmNset, (v->ArrowType == DRAW_POST_SEGMENT)?True:False, NULL);
    XtVaSetValues(WID.PD.vectorTypeButt[1], XmNset, (v->ArrowType == DRAW_POST_ARROW)?True:False, NULL);
    XtVaSetValues(WID.PD.vectorTypeButt[2], XmNset, (v->ArrowType == DRAW_POST_PYRAMID)?True:False, NULL);
    XtVaSetValues(WID.PD.vectorTypeButt[3], XmNset, (v->ArrowType == DRAW_POST_CONE)?True:False, NULL);  
    XtVaSetValues(WID.PD.vectorTypeButt[4], XmNset, 
                  (v->ArrowType == DRAW_POST_DISPLACEMENT)?True:False, NULL);
    sprintf(label, "%g", v->ArrowScale);
    XtVaSetValues(WID.PD.vectorScaleText, XmNvalue, label, NULL);
    XtVaSetValues(WID.PD.vectorScaleScale, XmNvalue, THRESHOLD((int)v->ArrowScale,0,200), NULL);
    XtVaSetValues(WID.PD.vectorLocationButt[0], XmNset, 
                  (v->ArrowLocation == DRAW_POST_LOCATE_COG)?True:False, NULL);
    XtVaSetValues(WID.PD.vectorLocationButt[1], XmNset, 
                  (v->ArrowLocation == DRAW_POST_LOCATE_VERTEX)?True:False, NULL);
    XtSetSensitive(WID.PD.vectorLocationCheck, v->ArrowType==DRAW_POST_DISPLACEMENT?False:True);
    XtManageChild(WID.PD.vectorDialog);
    break;

    /* Export BGM */
  case POST_EXPORT_BGM:
    ViewForDialog[POST_EXPORT_BGM] = v;
    strcat(label, " : Export as Background Mesh");
    XtVaSetValues(WID.PD.exportBGMDialog, XmNdialogTitle, XmStringCreateSimple(label), NULL);    
    d = ErrorInView(v,&nb) ;
    sprintf(label, "Options (Current: %d elements, error=%g%%)", nb, d); 
    XtVaSetValues(WID.PD.exportBGMFrame[1], XmNlabelString, XmStringCreateSimple(label), NULL);
    XtManageChild(WID.PD.exportBGMDialog);
    break;

    
    /* apply BGM */
  case POST_APPLY_BGM  : 
    ViewForDialog[POST_APPLY_BGM] = v;
    BGMWithView(v); 
    break;

  default:
    Msg(WARNING, "Unknown Event in PostDialogCb (%d)", (long int)client_data); 
    break;
  }
}


/* ------------------------------------------------------------------------ 
   functions in post dialogs  
   ------------------------------------------------------------------------ */

void ChangeViewParam (Post_View *v, XtPointer client_data, XtPointer call_data) ;

void PostCb (Widget w, XtPointer client_data, XtPointer call_data){
  int          j;
  Post_View   *v=NULL;
  double       d;
  char        *c;
  XmString     xms;
  static int   LastTimeStep = 0;

  switch((long int)client_data){

  case POST_EXPORT_BGM_METHOD_H_ERROR    : ADAPTATION_METHOD = 3; break;
  case POST_EXPORT_BGM_METHOD_H_ELEMENTS : ADAPTATION_METHOD = 4; break;
  case POST_EXPORT_BGM_METHOD_P_ERROR    : ADAPTATION_METHOD = 1; break;
  case POST_EXPORT_BGM_METHOD_P_ELEMENTS : ADAPTATION_METHOD = 2; break;
  case POST_EXPORT_BGM_CONSTRAINT : 
    v = ViewForDialog[POST_EXPORT_BGM];
    ADAPTATION_ERROR = atof(XmTextGetString(w)); 
    return ;
  case POST_EXPORT_BGM_CREATE   : 
    v = ViewForDialog[POST_EXPORT_BGM];
    XtVaGetValues(w, XmNtextString, &xms, NULL);
    XmStringGetLtoR(xms, XmSTRING_DEFAULT_CHARSET, &c);
    XmStringFree(xms);
    CreateBGM(v, ADAPTATION_METHOD, 1.0, ADAPTATION_ERROR, &d, c); 
    MergeProblem(c);     
    Init(); 
    Draw();
    return;
  case POST_COLOR_REPLOT : 
    v = ViewForDialog[POST_COLOR];
    ColorBarChange(v->Name, 
                   (v->RangeType==DRAW_POST_CUSTOM)?v->CustomMin:v->Min, 
                   (v->RangeType==DRAW_POST_CUSTOM)?v->CustomMax:v->Max, 
                   &v->CT, 0);
    ColorBarShow();
    if(v->CT.ipar[COLORTABLE_CHANGED]){
      v->Changed = 1;
      if(CTX.post.link){
        ColorTable_Copy(&v->CT);
        for(j=0 ; j< List_Nbr(Post_ViewList) ; j++){
          v = (Post_View*)List_Pointer(Post_ViewList, j);
          if(v->Visible || CTX.post.link>1){
            ColorTable_Paste(&v->CT);
            v->Changed=1;
          }
        }
      }
    }
    Init();
    Draw();
    return;
  }

  if(CTX.post.link){
    for(j=0 ; j< List_Nbr(Post_ViewList) ; j++){
      v = (Post_View*)List_Pointer(Post_ViewList, j);
      if(v->Visible || CTX.post.link>1) ChangeViewParam(v, client_data, call_data);
    }
  }
  else{
    switch((long int)client_data){
    case POST_OFFSET_TRANSLATE: 
    case POST_OFFSET_RAISE: 
    case POST_OFFSET_X_TEXT:       
    case POST_OFFSET_Y_TEXT:       
    case POST_OFFSET_Z_TEXT:       
    case POST_OFFSET_X_SCALE:
    case POST_OFFSET_Y_SCALE:
    case POST_OFFSET_Z_SCALE:
      v = ViewForDialog[POST_OFFSET];
      break;
    case POST_TIME_STEP_TEXT:
    case POST_TIME_STEP_SCALE:
      v = ViewForDialog[POST_TIME_STEP];
      break;
    case POST_SCALE_SHOW: 
    case POST_SCALE_TRANSPARENCY: 
    case POST_SCALE_TIME: 
    case POST_SCALE_FORMAT: 
    case POST_SCALE_LABEL:
    case POST_SCALE_MIN:
    case POST_SCALE_MAX:      
    case POST_SCALE_TYPE_LIN: 
    case POST_SCALE_TYPE_LOG: 
    case POST_SCALE_FORCE_RANGE:   
    case POST_SCALE_INTERVALS_TYPE_ISO : 
    case POST_SCALE_INTERVALS_TYPE_DISCRETE : 
    case POST_SCALE_INTERVALS_TYPE_CONTINUOUS: 
    case POST_SCALE_INTERVALS_TYPE_NUMERIC: 
    case POST_SCALE_INTERVALS_TEXT:    
    case POST_SCALE_INTERVALS_SCALE:   
      v = ViewForDialog[POST_SCALE];
      break;
    case POST_VECTOR_TYPE_SEGMENT:
    case POST_VECTOR_TYPE_ARROW:        
    case POST_VECTOR_TYPE_PYRAMID:      
    case POST_VECTOR_TYPE_CONE:
    case POST_VECTOR_TYPE_DISPLACEMENT:
    case POST_VECTOR_SCALE_TEXT:    
    case POST_VECTOR_SCALE_SCALE:   
    case POST_VECTOR_LOCATION_COG:    
    case POST_VECTOR_LOCATION_VERTEX: 
      v = ViewForDialog[POST_VECTOR];
      break;
    default :
      Msg(WARNING, "Unknown Event in PostCb");
      break;
    }
    ChangeViewParam(v, client_data, call_data);
  }


  if((long int)client_data == POST_TIME_STEP_SCALE){
    if(LastTimeStep != v->TimeStep){
      LastTimeStep = v->TimeStep;
      Init();
      Draw();
    }
  }

}

void ChangeViewParam (Post_View *v, XtPointer client_data, XtPointer call_data){
  double       d, sfact;
  char        *c, label[256];
  int          i;

  /* le slider (gradue en interne de -100 a 100) va de -CTX.lc a +CTX.lc  */
  sfact = pow(10.,2.-CTX.lc_order); 

  switch((long int)client_data){

    /* Offset */
  case POST_OFFSET_TRANSLATE: 
    OFFSET_MODE = 0;
    for(i=0 ; i<3 ; i++){
      sprintf(label, "%g", v->Offset[i]);
      XtVaSetValues(WID.PD.offsetText[i], XmNvalue, label, NULL);
      XtVaSetValues(WID.PD.offsetScale[i], XmNvalue, 
                    THRESHOLD((int)(sfact*v->Offset[i]),-100,100), NULL);    
      XmUpdateDisplay(WID.PD.offsetText[i]);
      XmUpdateDisplay(WID.PD.offsetScale[i]);
    }
    break;
  case POST_OFFSET_RAISE: 
    OFFSET_MODE = 1;
    for(i=0 ; i<3 ; i++){
      sprintf(label, "%g", v->Raise[i]);
      XtVaSetValues(WID.PD.offsetText[i], XmNvalue, label, NULL);
      XtVaSetValues(WID.PD.offsetScale[i], XmNvalue, 
                    THRESHOLD((int)(sfact*v->Raise[i]),-100,100), NULL);    
      XmUpdateDisplay(WID.PD.offsetText[i]);
      XmUpdateDisplay(WID.PD.offsetScale[i]);
    }
    break;
  case POST_OFFSET_X_TEXT:       
    d = atof(XmTextGetString(WID.PD.offsetText[0])); 
    OFFSET_MODE ? (v->Raise[0] = d) : (v->Offset[0] = d);
    XtVaSetValues(WID.PD.offsetScale[0], XmNvalue, THRESHOLD((int)(sfact*d),-100,100), NULL);
    XmUpdateDisplay(WID.PD.offsetScale[0]);
    v->Changed = 1;
    break;
  case POST_OFFSET_Y_TEXT:       
    d = atof(XmTextGetString(WID.PD.offsetText[1])); 
    OFFSET_MODE ? (v->Raise[1] = d) : (v->Offset[1] = d);
    XtVaSetValues(WID.PD.offsetScale[1], XmNvalue, THRESHOLD((int)(sfact*d),-100,100), NULL);
    XmUpdateDisplay(WID.PD.offsetScale[1]);
    v->Changed = 1;
    break;
  case POST_OFFSET_Z_TEXT:       
    d = atof(XmTextGetString(WID.PD.offsetText[2])); 
    OFFSET_MODE ? (v->Raise[2] = d) : (v->Offset[2] = d);
    XtVaSetValues(WID.PD.offsetScale[2], XmNvalue, THRESHOLD((int)(sfact*d),-100,100), NULL);
    XmUpdateDisplay(WID.PD.offsetScale[2]);
    v->Changed = 1;
    break;
  case POST_OFFSET_X_SCALE:
    XmScaleGetValue (WID.PD.offsetScale[0], &i);
    d = i/sfact ;
    sprintf(label, "%g", d);
    OFFSET_MODE ? (v->Raise[0] = d) : (v->Offset[0] = d);
    XtVaSetValues(WID.PD.offsetText[0],XmNvalue, label, NULL);
    XmUpdateDisplay(WID.PD.offsetText[0]);
    v->Changed = 1;
    break;
  case POST_OFFSET_Y_SCALE:
    XmScaleGetValue (WID.PD.offsetScale[1], &i);
    d = i/sfact ;
    sprintf(label, "%g",d);
    OFFSET_MODE ? (v->Raise[1]) = d : (v->Offset[1] = d);
    XtVaSetValues(WID.PD.offsetText[1],XmNvalue, label, NULL);
    XmUpdateDisplay(WID.PD.offsetText[1]);
    v->Changed = 1;
    break;
  case POST_OFFSET_Z_SCALE:
    XmScaleGetValue (WID.PD.offsetScale[2], &i);
    d = i/sfact ;
    sprintf(label, "%g", d);
    OFFSET_MODE ? (v->Raise[2] = d) : (v->Offset[2] = d);
    XtVaSetValues(WID.PD.offsetText[2],XmNvalue, label, NULL);
    XmUpdateDisplay(WID.PD.offsetText[2]);
    v->Changed = 1;
    break;

    /* Time Step */
  case POST_TIME_STEP_TEXT:
    i = atoi(XmTextGetString(WID.PD.timeStepText));
    if(i < 0)
      v->TimeStep = 0;
    else if(i > v->NbTimeStep-1) 
      v->TimeStep = v->NbTimeStep-1;
    else
      v->TimeStep = i;
    XtVaSetValues(WID.PD.timeStepScale, XmNvalue, v->TimeStep, NULL);
    XmUpdateDisplay(WID.PD.timeStepScale);
    v->Changed = 1;
    break;
  case POST_TIME_STEP_SCALE:
    XmScaleGetValue (WID.PD.timeStepScale, &i);
    if(i < 0)
      v->TimeStep = 0;
    else if(i > v->NbTimeStep-1) 
      v->TimeStep = v->NbTimeStep-1;
    else
      v->TimeStep = i;
    sprintf(label, "%d", v->TimeStep);
    XtVaSetValues(WID.PD.timeStepText, XmNvalue, label, NULL);
    XmUpdateDisplay(WID.PD.timeStepText);    
    v->Changed = 1;
    break;


    /* Scale */
  case POST_SCALE_SHOW: 
    v->ShowScale = !v->ShowScale; 
    XtSetSensitive(WID.PD.scaleText[0], v->ShowScale?1:0);
    XtSetSensitive(WID.PD.scaleText[1], v->ShowScale?1:0);
    break;
  case POST_SCALE_TRANSPARENCY: 
    v->TransparentScale = !v->TransparentScale; 
    break;
  case POST_SCALE_TIME: 
    v->ShowTime = !v->ShowTime; 
    break;
  case POST_SCALE_FORMAT: 
    c = XmTextGetString(WID.PD.scaleText[0]); strcpy(v->Format,c); 
    break;
  case POST_SCALE_LABEL:
    c = XmTextGetString(WID.PD.scaleText[1]); strcpy(v->Name,c); 
    break;
  case POST_SCALE_MIN:
    v->CustomMin = atof(XmTextGetString(WID.PD.scaleRangeText[0])); 
    if(v->RangeType==DRAW_POST_CUSTOM) v->Changed = 1;
    break;
  case POST_SCALE_MAX:      
    v->CustomMax = atof(XmTextGetString(WID.PD.scaleRangeText[1])); 
    if(v->RangeType==DRAW_POST_CUSTOM) v->Changed = 1;
    break;
  case POST_SCALE_TYPE_LIN: 
    v->ScaleType = DRAW_POST_LINEAR;  
    v->Changed = 1;
    break;
  case POST_SCALE_TYPE_LOG: 
    v->ScaleType = DRAW_POST_LOGARITHMIC; 
    v->Changed = 1;
    break;
  case POST_SCALE_FORCE_RANGE:   
    (v->RangeType == DRAW_POST_DEFAULT) ? 
      (v->RangeType=DRAW_POST_CUSTOM) : (v->RangeType=DRAW_POST_DEFAULT);
    XtSetSensitive(WID.PD.scaleRangeText[0], (v->RangeType==DRAW_POST_CUSTOM)?1:0);
    XtSetSensitive(WID.PD.scaleRangeText[1], (v->RangeType==DRAW_POST_CUSTOM)?1:0); 
    v->Changed = 1;
    break;
  case POST_SCALE_INTERVALS_TYPE_ISO : 
    v->IntervalsType = DRAW_POST_ISO; 
    v->Changed = 1;
    break;
  case POST_SCALE_INTERVALS_TYPE_DISCRETE : 
    v->IntervalsType = DRAW_POST_DISCRETE; 
    v->Changed = 1;
    break;
  case POST_SCALE_INTERVALS_TYPE_CONTINUOUS: 
    v->IntervalsType = DRAW_POST_CONTINUOUS; 
    v->Changed = 1;
    break;
  case POST_SCALE_INTERVALS_TYPE_NUMERIC: 
    v->IntervalsType = DRAW_POST_NUMERIC; 
    v->Changed = 1;
    break;
  case POST_SCALE_INTERVALS_TEXT:    
    v->NbIso = atoi(XmTextGetString(WID.PD.scaleIntervalsText));
    XtVaSetValues(WID.PD.scaleIntervalsScale, XmNvalue, THRESHOLD((int)v->NbIso,1,100), NULL);
    XmUpdateDisplay(WID.PD.scaleIntervalsScale);
    v->Changed = 1;
    break;
  case POST_SCALE_INTERVALS_SCALE:   
    XmScaleGetValue(WID.PD.scaleIntervalsScale, &v->NbIso);
    sprintf(label, "%d", v->NbIso);
    XtVaSetValues(WID.PD.scaleIntervalsText, XmNvalue, label, NULL);
    XmUpdateDisplay(WID.PD.scaleIntervalsText);
    v->Changed = 1;
    break;

    /* Vector */
  case POST_VECTOR_TYPE_SEGMENT:
    v->ArrowType = DRAW_POST_SEGMENT; 
    XtSetSensitive(WID.PD.vectorLocationCheck, True);
    v->Changed = 1;
    break;
  case POST_VECTOR_TYPE_ARROW:        
    v->ArrowType = DRAW_POST_ARROW; 
    XtSetSensitive(WID.PD.vectorLocationCheck, True);
    v->Changed = 1;
    break;
  case POST_VECTOR_TYPE_PYRAMID:      
    v->ArrowType = DRAW_POST_PYRAMID; 
    XtSetSensitive(WID.PD.vectorLocationCheck, True);
    v->Changed = 1;
    break;
  case POST_VECTOR_TYPE_CONE:
    v->ArrowType = DRAW_POST_CONE; 
    XtSetSensitive(WID.PD.vectorLocationCheck, True);
    v->Changed = 1;
    break;
  case POST_VECTOR_TYPE_DISPLACEMENT:
    v->ArrowType = DRAW_POST_DISPLACEMENT; 
    XtSetSensitive(WID.PD.vectorLocationCheck, False);
    v->Changed = 1;
    break;
  case POST_VECTOR_SCALE_TEXT:    
    v->ArrowScale = atof(XmTextGetString(WID.PD.vectorScaleText));
    XtVaSetValues(WID.PD.vectorScaleScale, XmNvalue, THRESHOLD((int)v->ArrowScale,0,200), NULL);
    XmUpdateDisplay(WID.PD.vectorScaleScale);
    v->Changed = 1;
    break;
  case POST_VECTOR_SCALE_SCALE:   
    XmScaleGetValue(WID.PD.vectorScaleScale, &i);
    v->ArrowScale = (double)i;
    sprintf(label, "%g", v->ArrowScale);
    XtVaSetValues(WID.PD.vectorScaleText, XmNvalue, label, NULL);
    XmUpdateDisplay(WID.PD.vectorScaleText);
    v->Changed = 1;
    break;
  case POST_VECTOR_LOCATION_COG:    
    v->ArrowLocation = DRAW_POST_LOCATE_COG; 
    v->Changed = 1;
    break;
  case POST_VECTOR_LOCATION_VERTEX: 
    v->ArrowLocation = DRAW_POST_LOCATE_VERTEX; 
    v->Changed = 1;
    break;

  default:
    Msg(WARNING, "Unknown Event in PostCb (%d)", (long int)client_data); 
    break;

  }

}

