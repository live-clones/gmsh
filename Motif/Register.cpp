// $Id: Register.cpp,v 1.1 2001-01-08 08:20:11 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "XContext.h"
#include "Widgets.h"
#include "Register.h"
#include "CbOptions.h"
#include "CbContext.h"
#include "CbFile.h"
#include "CbGeom.h"
#include "CbMesh.h"
#include "CbPost.h"

extern Context_T   CTX ;
extern XContext_T  XCTX ;

void RegisterCallbacks_M(Widgets_T *w){
  long int   n ;
  XtPointer  l[5] ;

  register_activate_cb (w->M.fileButt[0],   ManageCb,           w->FD.openDialog);
  register_activate_cb (w->M.fileButt[1],   ManageCb,           w->FD.mergeDialog);
  register_activate_cb (w->M.fileButt[2],   FileCb,             FILE_SAVE_MESH);
  register_activate_cb (w->M.fileButt[3],   ManageCb,           w->FD.saveAsDialog);
  register_activate_cb (w->M.fileButt[4],   ManageCb,           w->FD.saveOptionsAsDialog);
  register_activate_cb (w->M.fileButt[5],   ReloadAllViewsCb,   NULL);
  register_activate_cb (w->M.fileButt[6],   RemoveAllViewsCb,   NULL);
  register_activate_cb (w->M.fileButt[7],   ExitCb,             NULL);

  register_activate_cb (w->M.moduleButt[0], ActualizeContextCb, CONTEXT_GEOM);
  register_activate_cb (w->M.moduleButt[1], ActualizeContextCb, CONTEXT_MESH);
  register_activate_cb (w->M.moduleButt[2], ActualizeContextCb, CONTEXT_POST);

  register_activate_cb (w->M.optionButt[0], ManageCb,           w->OD.geomDialog);
  register_activate_cb (w->M.optionButt[1], ManageCb,           w->OD.meshDialog);
  register_activate_cb (w->M.optionButt[2], ManageCb,           w->OD.postDialog);
  register_activate_cb (w->M.optionButt[3], ManageCb,           w->OD.miscDialog);
  register_activate_cb (w->M.optionButt[4], CurrentViewportCb,  NULL);
  register_activate_cb (w->M.optionButt[5], CurrentInfoCb,      1);

  register_activate_cb (w->M.helpButt[0],   ManageCb,           w->HD.keysDialog);
  register_activate_cb (w->M.helpButt[1],   ManageCb,           w->HD.aboutDialog);

  register_popup_ev    (w->M.modButt,       w->M.modPop);
  register_activate_cb (w->M.geomButt,      ActualizeContextCb, CONTEXT_GEOM);
  register_activate_cb (w->M.meshButt,      ActualizeContextCb, CONTEXT_MESH);
  register_activate_cb (w->M.postButt,      ActualizeContextCb, CONTEXT_POST);
                                                                
  register_activate_cb (w->M.navigButt[0],  PreviousContextCb,  CONTEXT_BACKWARD);
  register_activate_cb (w->M.navigButt[1],  PreviousContextCb,  CONTEXT_FORWARD);

  l[0] = (XtPointer)CurrentViewCb ;
  l[2] = (XtPointer)PostDialogCb ;

  for(n=0 ; n<NB_BUTT_MAX ; n++){
    register_activate_cb (w->M.pushButt[n],   NextContextCb, n+1);
    register_valchg_cb   (w->M.toggleButt[n], SwapViewCb, n+1);
    register_popup_ev    (w->M.toggleButt[n], w->M.popMenu[n]);
    register_activate_cb (w->M.reloadButt[n], ReloadViewCb, n+1);
    register_activate_cb (w->M.removeButt[n], RemoveViewCb, n+1);
    register_activate_cb (w->M.duplicateButt[n], DuplicateViewCb, n+1);

    l[1] = (XtPointer)(n+1) ;
    l[4] = NULL ;
    l[3] = (XtPointer)POST_LIGHT;      register_valchg_cb_list (w->M.lightButt[n],l);
    l[3] = (XtPointer)POST_ELEMENT;    register_valchg_cb_list (w->M.elementButt[n],l);
    l[3] = (XtPointer)POST_OFFSET;     register_activate_cb_list (w->M.offsetButt[n],l);
    l[3] = (XtPointer)POST_TIME_STEP;  register_activate_cb_list (w->M.timeStepButt[n],l);
    l[3] = (XtPointer)POST_SCALE;      register_activate_cb_list (w->M.scaleButt[n],l);
    l[3] = (XtPointer)POST_COLOR;      register_activate_cb_list (w->M.colorButt[n],l);
    l[3] = (XtPointer)POST_VECTOR;     register_activate_cb_list (w->M.vectorButt[n],l);
    l[3] = (XtPointer)POST_TIME_STEP;  register_activate_cb_list (w->M.timeStepButt[n],l);
    l[3] = (XtPointer)POST_EXPORT_BGM; register_activate_cb_list (w->M.exportBGMButt[n],l);
    l[3] = (XtPointer)POST_APPLY_BGM;  register_activate_cb_list (w->M.applyBGMButt[n],l);
  }

}


void RegisterCallbacks_G(Widgets_T *w){

  register_GLexpose_cb   (w->G.glw, ExposeCb, NULL);
  register_GLresize_cb   (w->G.glw, ResizeCb, NULL);
  register_GLinit_cb     (w->G.glw, InitCb,   NULL);
  register_GLinput_cb    (w->G.glw, InputCb,  NULL);

  if(CTX.overlay){
    register_GLexpose_cb (w->G.glo, ExposeCb, NULL);
    register_GLresize_cb (w->G.glo, ResizeCb, NULL);
    register_GLinput_cb  (w->G.glo, InputCb,  NULL);
  }

  register_activate_cb (w->G.Butt[0], OptionsCb, OPTIONS_XVIEW);
  register_activate_cb (w->G.Butt[1], OptionsCb, OPTIONS_YVIEW);
  register_activate_cb (w->G.Butt[2], OptionsCb, OPTIONS_ZVIEW);
  register_activate_cb (w->G.Butt[3], OptionsCb, OPTIONS_CVIEW);
  register_activate_cb (w->G.Butt[4], OptionsCb, OPTIONS_PVIEW);
  register_activate_cb (w->G.Butt[5], OptionsCb, OPTIONS_POST_ANIM_START);
  register_activate_cb (w->G.Butt[6], OptionsCb, OPTIONS_MESH_ABORT);

}

void Set_AnimCallback(Widgets_T *w, int start){
  if(start){
    register_remove_cb (w->G.Butt[5], OptionsCb, OPTIONS_POST_ANIM_STOP);
    register_activate_cb (w->G.Butt[5], OptionsCb, OPTIONS_POST_ANIM_START);
  }
  else{
    register_remove_cb (w->G.Butt[5], OptionsCb, OPTIONS_POST_ANIM_START);
    register_activate_cb (w->G.Butt[5], OptionsCb, OPTIONS_POST_ANIM_STOP);
  }
}


void RegisterCallbacks_C(Widgets_T *w){

}


void RegisterCallbacks_ED(Widgets_T *w){

  register_ok_cb     (w->ED.saveAsDialog, FileCb,   FILE_SAVE_AS_OVERWRITE);

}


void RegisterCallbacks_FD(Widgets_T *w){ 

  register_ok_cb       (w->FD.openDialog,     FileCb,    FILE_LOAD_GEOM);
  register_cancel_cb   (w->FD.openDialog,     ManageCb,  w->FD.openDialog);

  register_ok_cb       (w->FD.mergeDialog,    FileCb,    FILE_LOAD_POST);
  register_cancel_cb   (w->FD.mergeDialog,    ManageCb,  w->FD.mergeDialog);

  register_ok_cb       (w->FD.saveAsDialog,   FileCb,    FILE_SAVE_AS);
  register_cancel_cb   (w->FD.saveAsDialog,   ManageCb,  w->FD.saveAsDialog);
  register_activate_cb (w->FD.saveAsButt[0],  OptionsCb, OPTIONS_SAVE_AUTO);
  register_activate_cb (w->FD.saveAsButt[1],  OptionsCb, OPTIONS_SAVE_GEO);
  register_activate_cb (w->FD.saveAsButt[2],  OptionsCb, OPTIONS_SAVE_MSH);
  register_activate_cb (w->FD.saveAsButt[3],  OptionsCb, OPTIONS_SAVE_UNV);
  register_activate_cb (w->FD.saveAsButt[4],  OptionsCb, OPTIONS_SAVE_GREF);
  register_activate_cb (w->FD.saveAsButt[5],  OptionsCb, OPTIONS_SAVE_EPS_SIMPLE);
  register_activate_cb (w->FD.saveAsButt[6],  OptionsCb, OPTIONS_SAVE_EPS_COMPLEX);
  register_activate_cb (w->FD.saveAsButt[7],  OptionsCb, OPTIONS_SAVE_XPM);
  register_activate_cb (w->FD.saveAsButt[8],  OptionsCb, OPTIONS_SAVE_JPEG);
  register_activate_cb (w->FD.saveAsButt[9],  OptionsCb, OPTIONS_SAVE_GIF);
  register_activate_cb (w->FD.saveAsButt[10], OptionsCb, OPTIONS_SAVE_GIF_DITHERED);
  register_activate_cb (w->FD.saveAsButt[11], OptionsCb, OPTIONS_SAVE_GIF_TRANSPARENT);
  register_activate_cb (w->FD.saveAsButt[12], OptionsCb, OPTIONS_SAVE_PPM);
  register_activate_cb (w->FD.saveAsButt[13], OptionsCb, OPTIONS_SAVE_YUV);

  register_ok_cb       (w->FD.saveOptionsAsDialog,   FileCb,    FILE_SAVE_OPTIONS_AS);
  register_cancel_cb   (w->FD.saveOptionsAsDialog,   ManageCb,  w->FD.saveOptionsAsDialog);
}

void RegisterCallbacks_OD(Widgets_T *w){

  register_ok_cb      (w->OD.geomDialog,         OptionsCb,  OPTIONS_REPLOT);
  register_cancel_cb  (w->OD.geomDialog,         ManageCb,   w->OD.geomDialog); 
  register_valchg_cb  (w->OD.geomVisibleTypeButt[0], OptionsCb,  OPTIONS_GEOM_VISIBILITY_ENTITY);
  register_valchg_cb  (w->OD.geomVisibleTypeButt[1], OptionsCb,  OPTIONS_GEOM_VISIBILITY_NUMBER);
  register_valchg_cb  (w->OD.geomVisibleButt[0], OptionsCb,  OPTIONS_GEOM_POINTS);
  register_valchg_cb  (w->OD.geomVisibleButt[1], OptionsCb,  OPTIONS_GEOM_LINES);
  register_valchg_cb  (w->OD.geomVisibleButt[2], OptionsCb,  OPTIONS_GEOM_SURFACES);
  register_valchg_cb  (w->OD.geomVisibleButt[3], OptionsCb,  OPTIONS_GEOM_VOLUMES);
  register_activate_cb(w->OD.geomVisibleByNumText, OptionsCb,  OPTIONS_GEOM_HIDE_SHOW);
  register_valchg_cb  (w->OD.geomNormalsScale,   OptionsCb,  OPTIONS_GEOM_NORMALS_SCALE);
  register_drag_cb    (w->OD.geomNormalsScale,   OptionsCb,  OPTIONS_GEOM_NORMALS_SCALE);
  register_activate_cb(w->OD.geomNormalsText,    OptionsCb,  OPTIONS_GEOM_NORMALS_TEXT);
  register_valchg_cb  (w->OD.geomTangentsScale,  OptionsCb,  OPTIONS_GEOM_TANGENTS_SCALE);
  register_drag_cb    (w->OD.geomTangentsScale,  OptionsCb,  OPTIONS_GEOM_TANGENTS_SCALE);
  register_activate_cb(w->OD.geomTangentsText,   OptionsCb,  OPTIONS_GEOM_TANGENTS_TEXT);

  register_ok_cb      (w->OD.meshDialog,         OptionsCb,  OPTIONS_REPLOT);
  register_cancel_cb  (w->OD.meshDialog,         ManageCb,   w->OD.meshDialog); 
  register_valchg_cb  (w->OD.meshAlgoButt[0],    OptionsCb,  OPTIONS_MESH_DEGRE2);
  register_valchg_cb  (w->OD.meshAlgoButt[1],    OptionsCb,  OPTIONS_MESH_ANISOTROPIC);
  register_valchg_cb  (w->OD.meshAlgoButt[2],    OptionsCb,  OPTIONS_MESH_INTERACTIVE);
  register_valchg_cb  (w->OD.meshSmoothingScale, OptionsCb,  OPTIONS_MESH_SMOOTHING_SCALE);
  register_drag_cb    (w->OD.meshSmoothingScale, OptionsCb,  OPTIONS_MESH_SMOOTHING_SCALE);
  register_activate_cb(w->OD.meshSmoothingText,  OptionsCb,  OPTIONS_MESH_SMOOTHING_TEXT);
  register_valchg_cb  (w->OD.meshVisibleTypeButt[0], OptionsCb,  OPTIONS_MESH_VISIBILITY_ENTITY);
  register_valchg_cb  (w->OD.meshVisibleTypeButt[1], OptionsCb,  OPTIONS_MESH_VISIBILITY_NUMBER);
  register_valchg_cb  (w->OD.meshVisibleButt[0], OptionsCb,  OPTIONS_MESH_POINTS);
  register_valchg_cb  (w->OD.meshVisibleButt[1], OptionsCb,  OPTIONS_MESH_LINES);
  register_valchg_cb  (w->OD.meshVisibleButt[2], OptionsCb,  OPTIONS_MESH_SURFACES);
  register_valchg_cb  (w->OD.meshVisibleButt[3], OptionsCb,  OPTIONS_MESH_VOLUMES);
  register_valchg_cb  (w->OD.meshVisibleByNumButt[0], OptionsCb,  OPTIONS_MESH_SELECT_ENTITY);
  register_valchg_cb  (w->OD.meshVisibleByNumButt[1], OptionsCb,  OPTIONS_MESH_SELECT_QUALITY);
  register_activate_cb(w->OD.meshVisibleByNumText,    OptionsCb,  OPTIONS_MESH_HIDE_SHOW);
  register_valchg_cb  (w->OD.meshAspectButt[0],  OptionsCb,  OPTIONS_MESH_WIREFRAME);
  register_valchg_cb  (w->OD.meshAspectButt[1],  OptionsCb,  OPTIONS_MESH_HIDDEN_LINES);
  register_valchg_cb  (w->OD.meshAspectButt[2],  OptionsCb,  OPTIONS_MESH_SHADING);
  register_valchg_cb  (w->OD.meshExplodeScale,   OptionsCb,  OPTIONS_MESH_EXPLODE_SCALE);
  register_drag_cb    (w->OD.meshExplodeScale,   OptionsCb,  OPTIONS_MESH_EXPLODE_SCALE);
  register_activate_cb(w->OD.meshExplodeText,    OptionsCb,  OPTIONS_MESH_EXPLODE_TEXT);
  register_valchg_cb  (w->OD.meshNormalsScale,   OptionsCb,  OPTIONS_MESH_NORMALS_SCALE);
  register_drag_cb    (w->OD.meshNormalsScale,   OptionsCb,  OPTIONS_MESH_NORMALS_SCALE);
  register_activate_cb(w->OD.meshNormalsText,    OptionsCb,  OPTIONS_MESH_NORMALS_TEXT);

  register_ok_cb      (w->OD.postDialog,         OptionsCb,  OPTIONS_REPLOT);
  register_cancel_cb  (w->OD.postDialog,         ManageCb,   w->OD.postDialog); 
  register_valchg_cb  (w->OD.postLinkButt[0],    OptionsCb,  OPTIONS_POST_LINK_NONE);
  register_valchg_cb  (w->OD.postLinkButt[1],    OptionsCb,  OPTIONS_POST_LINK_VISIBLE);
  register_valchg_cb  (w->OD.postLinkButt[2],    OptionsCb,  OPTIONS_POST_LINK_ALL);
  register_valchg_cb  (w->OD.postAnimScale,      OptionsCb,  OPTIONS_POST_ANIM_DELAY);
  register_drag_cb    (w->OD.postAnimScale,      OptionsCb,  OPTIONS_POST_ANIM_DELAY);

  register_ok_cb      (w->OD.miscDialog,         OptionsCb,  OPTIONS_REPLOT);
  register_cancel_cb  (w->OD.miscDialog,         ManageCb,   w->OD.miscDialog); 
  register_valchg_cb  (w->OD.miscMiscButt[0],    OptionsCb,  OPTIONS_AXES);
  register_valchg_cb  (w->OD.miscMiscButt[1],    OptionsCb,  OPTIONS_LITTLE_AXES);
  register_valchg_cb  (w->OD.miscMiscButt[2],    OptionsCb,  OPTIONS_FAST_REDRAW);
  register_valchg_cb  (w->OD.miscMiscButt[3],    OptionsCb,  OPTIONS_DISPLAY_LISTS);
  register_valchg_cb  (w->OD.miscMiscButt[4],    OptionsCb,  OPTIONS_ALPHA_BLENDING);
  register_valchg_cb  (w->OD.miscMiscButt[5],    OptionsCb,  OPTIONS_TRACKBALL);
  register_valchg_cb  (w->OD.miscColorSchemeScale, OptionsCb, OPTIONS_COLOR_SCHEME_SCALE);
  register_drag_cb    (w->OD.miscColorSchemeScale, OptionsCb, OPTIONS_COLOR_SCHEME_SCALE);
  register_valchg_cb  (w->OD.miscProjButt[0],    OptionsCb,  OPTIONS_ORTHOGRAPHIC);
  register_valchg_cb  (w->OD.miscProjButt[1],    OptionsCb,  OPTIONS_PERSPECTIVE);
  register_valchg_cb  (w->OD.miscLightScale[0],  OptionsCb,  OPTIONS_LIGHT_X_SCALE);
  register_drag_cb    (w->OD.miscLightScale[0],  OptionsCb,  OPTIONS_LIGHT_X_SCALE);
  register_valchg_cb  (w->OD.miscLightScale[1],  OptionsCb,  OPTIONS_LIGHT_Y_SCALE);
  register_drag_cb    (w->OD.miscLightScale[1],  OptionsCb,  OPTIONS_LIGHT_Y_SCALE);
  register_valchg_cb  (w->OD.miscLightScale[2],  OptionsCb,  OPTIONS_LIGHT_Z_SCALE);
  register_drag_cb    (w->OD.miscLightScale[2],  OptionsCb,  OPTIONS_LIGHT_Z_SCALE);
  register_valchg_cb  (w->OD.miscShineScale,     OptionsCb,  OPTIONS_SHINE_SCALE);
  register_drag_cb    (w->OD.miscShineScale,     OptionsCb,  OPTIONS_SHINE_SCALE);

  register_ok_cb      (w->OD.viewportDialog,         OptionsCb,  OPTIONS_REPLOT);
  register_cancel_cb  (w->OD.viewportDialog,         ManageCb,   w->OD.viewportDialog); 
  register_valchg_cb  (w->OD.viewportText[0][0],     OptionsCb,  OPTIONS_ROTX);
  register_valchg_cb  (w->OD.viewportText[0][1],     OptionsCb,  OPTIONS_ROTY);
  register_valchg_cb  (w->OD.viewportText[0][2],     OptionsCb,  OPTIONS_ROTZ);
  register_valchg_cb  (w->OD.viewportText[1][0],     OptionsCb,  OPTIONS_TRANX);
  register_valchg_cb  (w->OD.viewportText[1][1],     OptionsCb,  OPTIONS_TRANY);
  register_valchg_cb  (w->OD.viewportText[1][2],     OptionsCb,  OPTIONS_TRANZ);
  register_valchg_cb  (w->OD.viewportText[2][0],     OptionsCb,  OPTIONS_SCALEX);
  register_valchg_cb  (w->OD.viewportText[2][1],     OptionsCb,  OPTIONS_SCALEY);
  register_valchg_cb  (w->OD.viewportText[2][2],     OptionsCb,  OPTIONS_SCALEZ);
  register_valchg_cb  (w->OD.viewportLockButt[0][0], OptionsCb,  OPTIONS_ROTX_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[0][1], OptionsCb,  OPTIONS_ROTY_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[0][2], OptionsCb,  OPTIONS_ROTZ_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[1][0], OptionsCb,  OPTIONS_TRANX_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[1][1], OptionsCb,  OPTIONS_TRANY_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[1][2], OptionsCb,  OPTIONS_TRANZ_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[2][0], OptionsCb,  OPTIONS_SCALEX_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[2][1], OptionsCb,  OPTIONS_SCALEY_LOCKED);
  register_valchg_cb  (w->OD.viewportLockButt[2][2], OptionsCb,  OPTIONS_SCALEZ_LOCKED);

  register_ok_cb      (w->OD.infoDialog,         CurrentInfoCb,    0);
  register_cancel_cb  (w->OD.infoDialog,         ManageCb,         w->OD.infoDialog); 

}

void RegisterCallbacks_HD(Widgets_T *w){
  
}

void RegisterCallbacks_GD(Widgets_T *w){
  
  register_ok_cb      (w->GD.paramDialog,    GeomCb,    GEOM_PARAMETER_ADD);
  register_cancel_cb  (w->GD.paramDialog,    ManageCb,  w->GD.paramDialog); 
  register_valchg_cb  (w->GD.paramText[0],   GeomCb,    GEOM_PARAMETER_NAME);
  register_valchg_cb  (w->GD.paramText[1],   GeomCb,    GEOM_PARAMETER_VALUE);

  register_ok_cb      (w->GD.pointDialog,    GeomCb,    GEOM_POINT_ADD);
  register_cancel_cb  (w->GD.pointDialog,    ManageCb,  w->GD.pointDialog); 
  register_valchg_cb  (w->GD.pointText[0],   GeomCb,    GEOM_POINT_X);
  register_valchg_cb  (w->GD.pointText[1],   GeomCb,    GEOM_POINT_Y);
  register_valchg_cb  (w->GD.pointText[2],   GeomCb,    GEOM_POINT_Z);
  register_valchg_cb  (w->GD.pointText[3],   GeomCb,    GEOM_POINT_L);

  register_cancel_cb  (w->GD.rotDialog,      ManageCb,  w->GD.rotDialog); 
  register_valchg_cb  (w->GD.rotText[0],     GeomCb,    GEOM_ROT_PX);
  register_valchg_cb  (w->GD.rotText[1],     GeomCb,    GEOM_ROT_PY);
  register_valchg_cb  (w->GD.rotText[2],     GeomCb,    GEOM_ROT_PZ);
  register_valchg_cb  (w->GD.rotText[3],     GeomCb,    GEOM_ROT_AX);
  register_valchg_cb  (w->GD.rotText[4],     GeomCb,    GEOM_ROT_AY);
  register_valchg_cb  (w->GD.rotText[5],     GeomCb,    GEOM_ROT_AZ);
  register_valchg_cb  (w->GD.rotText[6],     GeomCb,    GEOM_ROT_ANGLE);

  register_cancel_cb  (w->GD.tranDialog,     ManageCb,  w->GD.tranDialog); 
  register_valchg_cb  (w->GD.tranText[0],    GeomCb,    GEOM_TRAN_X);
  register_valchg_cb  (w->GD.tranText[1],    GeomCb,    GEOM_TRAN_Y);
  register_valchg_cb  (w->GD.tranText[2],    GeomCb,    GEOM_TRAN_Z);

  register_cancel_cb  (w->GD.dilatDialog,    ManageCb,  w->GD.dilatDialog); 
  register_valchg_cb  (w->GD.dilatText[0],   GeomCb,    GEOM_DILAT_X);
  register_valchg_cb  (w->GD.dilatText[1],   GeomCb,    GEOM_DILAT_Y);
  register_valchg_cb  (w->GD.dilatText[2],   GeomCb,    GEOM_DILAT_Z);
  register_valchg_cb  (w->GD.dilatText[3],   GeomCb,    GEOM_DILAT_F);

  register_cancel_cb  (w->GD.symmDialog,     ManageCb,  w->GD.symmDialog); 
  register_valchg_cb  (w->GD.symmText[0],    GeomCb,    GEOM_SYMMETRY_A);
  register_valchg_cb  (w->GD.symmText[1],    GeomCb,    GEOM_SYMMETRY_B);
  register_valchg_cb  (w->GD.symmText[2],    GeomCb,    GEOM_SYMMETRY_C);
  register_valchg_cb  (w->GD.symmText[3],    GeomCb,    GEOM_SYMMETRY_D);
}

void RegisterCallbacks_MD(Widgets_T *w){

  register_cancel_cb  (w->MD.charLengthDialog,   ManageCb,  w->MD.charLengthDialog); 
  register_valchg_cb  (w->MD.charLengthText,     MeshCb,    MESH_CHAR_LENGTH);

  register_cancel_cb  (w->MD.trsfLineDialog,     ManageCb,  w->MD.trsfLineDialog); 
  register_valchg_cb  (w->MD.trsfLineText[0],    MeshCb,    MESH_TRSF_LINE_TYPE);
  register_valchg_cb  (w->MD.trsfLineText[1],    MeshCb,    MESH_TRSF_LINE_PTS);

  register_cancel_cb  (w->MD.trsfVolumeDialog,   ManageCb,  w->MD.trsfVolumeDialog); 
  register_valchg_cb  (w->MD.trsfVolumeText,     MeshCb,    MESH_TRSF_VOL_NUM);
  
}

void RegisterCallbacks_PD(Widgets_T *w){

  register_ok_cb       (w->PD.offsetDialog,      OptionsCb, OPTIONS_REPLOT); 
  register_cancel_cb   (w->PD.offsetDialog,      ManageCb,  w->PD.offsetDialog); 
  register_valchg_cb   (w->PD.offsetModeButt[0], PostCb,    POST_OFFSET_TRANSLATE);
  register_valchg_cb   (w->PD.offsetModeButt[1], PostCb,    POST_OFFSET_RAISE);
  register_valchg_cb   (w->PD.offsetScale[0],    PostCb,    POST_OFFSET_X_SCALE);
  register_drag_cb     (w->PD.offsetScale[0],    PostCb,    POST_OFFSET_X_SCALE);
  register_activate_cb (w->PD.offsetText[0],     PostCb,    POST_OFFSET_X_TEXT);
  register_valchg_cb   (w->PD.offsetScale[1],    PostCb,    POST_OFFSET_Y_SCALE);
  register_drag_cb     (w->PD.offsetScale[1],    PostCb,    POST_OFFSET_Y_SCALE);
  register_activate_cb (w->PD.offsetText[1],     PostCb,    POST_OFFSET_Y_TEXT);
  register_valchg_cb   (w->PD.offsetScale[2],    PostCb,    POST_OFFSET_Z_SCALE);
  register_drag_cb     (w->PD.offsetScale[2],    PostCb,    POST_OFFSET_Z_SCALE);
  register_activate_cb (w->PD.offsetText[2],     PostCb,    POST_OFFSET_Z_TEXT);
  
  register_ok_cb       (w->PD.timeStepDialog,    OptionsCb, OPTIONS_REPLOT); 
  register_cancel_cb   (w->PD.timeStepDialog,    ManageCb,  w->PD.timeStepDialog); 
  register_valchg_cb   (w->PD.timeStepScale,     PostCb,    POST_TIME_STEP_SCALE);
  register_drag_cb     (w->PD.timeStepScale,     PostCb,    POST_TIME_STEP_SCALE);
  register_activate_cb (w->PD.timeStepText,      PostCb,    POST_TIME_STEP_TEXT);

  register_ok_cb       (w->PD.scaleDialog,       OptionsCb, OPTIONS_REPLOT); 
  register_cancel_cb   (w->PD.scaleDialog,       ManageCb,  w->PD.scaleDialog); 
  register_valchg_cb   (w->PD.scaleShowButt,     PostCb,    POST_SCALE_SHOW);
  register_valchg_cb   (w->PD.scaleTransButt,    PostCb,    POST_SCALE_TRANSPARENCY);
  register_valchg_cb   (w->PD.scaleTimeButt,     PostCb,    POST_SCALE_TIME);
  register_valchg_cb   (w->PD.scaleText[0],      PostCb,    POST_SCALE_FORMAT);
  register_valchg_cb   (w->PD.scaleText[1],      PostCb,    POST_SCALE_LABEL);
  register_valchg_cb   (w->PD.scaleRangeButt,    PostCb,    POST_SCALE_FORCE_RANGE);
  register_valchg_cb   (w->PD.scaleRangeText[0], PostCb,    POST_SCALE_MIN);
  register_valchg_cb   (w->PD.scaleRangeText[1], PostCb,    POST_SCALE_MAX);
  register_valchg_cb   (w->PD.scaleTypeButt[0],  PostCb,    POST_SCALE_TYPE_LIN);
  register_valchg_cb   (w->PD.scaleTypeButt[1],  PostCb,    POST_SCALE_TYPE_LOG);
  register_valchg_cb   (w->PD.scaleIntervalsButt[0], PostCb, POST_SCALE_INTERVALS_TYPE_ISO);
  register_valchg_cb   (w->PD.scaleIntervalsButt[1], PostCb, POST_SCALE_INTERVALS_TYPE_DISCRETE);
  register_valchg_cb   (w->PD.scaleIntervalsButt[2], PostCb, POST_SCALE_INTERVALS_TYPE_CONTINUOUS);
  register_valchg_cb   (w->PD.scaleIntervalsButt[3], PostCb, POST_SCALE_INTERVALS_TYPE_NUMERIC);
  register_valchg_cb   (w->PD.scaleIntervalsScale,   PostCb, POST_SCALE_INTERVALS_SCALE);
  register_drag_cb     (w->PD.scaleIntervalsScale,   PostCb, POST_SCALE_INTERVALS_SCALE);
  register_activate_cb (w->PD.scaleIntervalsText,    PostCb, POST_SCALE_INTERVALS_TEXT);

  register_ok_cb       (w->PD.colorDialog,        PostCb,    POST_COLOR_REPLOT); 
  register_cancel_cb   (w->PD.colorDialog,        ManageCb,  w->PD.colorDialog); 
  register_expose_cb   (w->PD.colorDrawingArea,   ColorBarExposeCb, NULL);
  register_resize_cb   (w->PD.colorDrawingArea,   ColorBarResizeCb, NULL);
  register_input_cb    (w->PD.colorDrawingArea,   ColorBarInputCb,  NULL);

  register_ok_cb       (w->PD.vectorDialog,       OptionsCb, OPTIONS_REPLOT); 
  register_cancel_cb   (w->PD.vectorDialog,       ManageCb,  w->PD.vectorDialog); 
  register_valchg_cb   (w->PD.vectorTypeButt[0],  PostCb,    POST_VECTOR_TYPE_SEGMENT);
  register_valchg_cb   (w->PD.vectorTypeButt[1],  PostCb,    POST_VECTOR_TYPE_ARROW);
  register_valchg_cb   (w->PD.vectorTypeButt[2],  PostCb,    POST_VECTOR_TYPE_PYRAMID);
  register_valchg_cb   (w->PD.vectorTypeButt[3],  PostCb,    POST_VECTOR_TYPE_CONE);
  register_valchg_cb   (w->PD.vectorTypeButt[4],  PostCb,    POST_VECTOR_TYPE_DISPLACEMENT);
  register_valchg_cb   (w->PD.vectorScaleScale,   PostCb,    POST_VECTOR_SCALE_SCALE);
  register_drag_cb     (w->PD.vectorScaleScale,   PostCb,    POST_VECTOR_SCALE_SCALE);
  register_activate_cb (w->PD.vectorScaleText,    PostCb,    POST_VECTOR_SCALE_TEXT);
  register_valchg_cb   (w->PD.vectorLocationButt[0],PostCb,  POST_VECTOR_LOCATION_COG);
  register_valchg_cb   (w->PD.vectorLocationButt[1],PostCb,  POST_VECTOR_LOCATION_VERTEX);

  register_ok_cb       (w->PD.exportBGMDialog,   PostCb,    POST_EXPORT_BGM_CREATE);
  register_cancel_cb   (w->PD.exportBGMDialog,   ManageCb,  w->PD.exportBGMDialog);
  register_activate_cb (w->PD.exportBGMButt[0],  PostCb,    POST_EXPORT_BGM_METHOD_H_ERROR) ;
  register_activate_cb (w->PD.exportBGMButt[1],  PostCb,    POST_EXPORT_BGM_METHOD_H_ELEMENTS) ;
  register_activate_cb (w->PD.exportBGMButt[2],  PostCb,    POST_EXPORT_BGM_METHOD_P_ERROR) ;
  register_activate_cb (w->PD.exportBGMButt[3],  PostCb,    POST_EXPORT_BGM_METHOD_P_ELEMENTS) ;
  register_valchg_cb   (w->PD.exportBGMText,     PostCb,    POST_EXPORT_BGM_CONSTRAINT) ;

}



void RegisterCallbacks(Widgets_T *w){

  RegisterCallbacks_M(w); /* menu win */   
  RegisterCallbacks_G(w); /* graphic win */
  if(CTX.command_win) RegisterCallbacks_C(w); /* command win */

  RegisterCallbacks_ED(w); /* error dialogs */
  RegisterCallbacks_FD(w); /* file dialogs */
  RegisterCallbacks_OD(w); /* option dialogs */
  RegisterCallbacks_HD(w); /* help dialogs */
  RegisterCallbacks_GD(w); /* geometry dialogs */
  RegisterCallbacks_MD(w); /* mesh dialogs */
  RegisterCallbacks_PD(w); /* post dialogs */

}


