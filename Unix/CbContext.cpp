/* $Id: CbContext.cpp,v 1.4 2000-11-25 15:26:12 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Widgets.h"
#include "Context.h"
#include "XContext.h"
#include "CbContext.h"
#include "CbGeom.h"
#include "CbMesh.h"

extern Context_T   CTX;
extern XContext_T  XCTX;
extern Widgets_T   WID; 
extern Mesh        M;
extern List_T     *Post_ViewList;

static char *txt_new [] = 
  { "Parameter", "Point", "Line", "Spline", "Bezier", "BSpline", "Circle", "Ellipsis", 
    "Plane Surface", "Ruled Surface", "Nurbs Surface", "Volume", NULL };  

static char *txt_translate_rotate_dilate_symmetry_delete [] = 
  { "Point", "Line", "Surface", NULL };  

static char *txt_add [] = 
  { "Create", "Translate", "Rotate", "Dilate", "Symmetry", NULL };  

static char *txt_move [] = 
  { "Translate", "Rotate", "Dilate", "Symmetry", NULL };  

static char *txt_elem [] = 
  { "Add", "Move", "Extrude", "Delete", "Coherence", NULL };  

static char *txt_phys [] = 
  { "Add", "Delete", NULL };  

static char *txt_phys_add [] = 
  { "Point", "Line", "Surface", "Volume", NULL };  

static char *txt_geom [] = 
  { "Elementary", "Physical", "Reload", NULL };  

static char *txt_mesh [] = 
  { "Define", "1D", "2D", "3D", NULL };  

static char *txt_mesh_define [] = 
  { "Length", "Recombine", "Transfinite Line", "Transfinite Surface", 
    "Transfinite Volume", NULL };  

static char *txt_post[NB_BUTT_MAX] = 
  {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

static long int   actual_context, actual_global_context;

void UpdatePostButtons(void){
  Post_View  *v;
  int         i;

  for(i = 0 ; i < NB_BUTT_MAX ; i++) {
    
    if(txt_post[i]){
      
      v = (Post_View*)List_Pointer(Post_ViewList,i);

      /* defaultButt[i] */
      if(i==0 && XtIsManaged(WID.M.defaultButt)) XtUnmanageChild(WID.M.defaultButt);

      /* pushButt[i] */
      if(XtIsManaged(WID.M.pushButt[i])) XtUnmanageChild(WID.M.pushButt[i]);

      /* toggleButt[i] */
      XtVaSetValues(WID.M.toggleButt[i],
		    XmNlabelString, XmStringCreateSimple(txt_post[i]),
		    XmNset, v->Visible?True:False,
		    NULL);      
      XtManageChild(WID.M.toggleButt[i]);

      /* timeStepButt[i] */
      XtSetSensitive(WID.M.timeStepButt[i], (v->NbTimeStep>1)?1:0);
      XtManageChild(WID.M.timeStepButt[i]);

      /* vectorButt[i] */
      XtSetSensitive(WID.M.vectorButt[i], v->ScalarOnly?0:1);
      XtManageChild(WID.M.vectorButt[i]);

      /* exportBGMButt[i] */
      XtSetSensitive(WID.M.exportBGMButt[i], v->ScalarOnly?1:0);
      XtManageChild(WID.M.exportBGMButt[i]);

      /* applyBGMButtXXX */
      XtSetSensitive(WID.M.applyBGMButt[i], v->ScalarOnly?1:0);
      XtManageChild(WID.M.applyBGMButt[i]);
    }
    else{
      if(XtIsManaged(WID.M.pushButt[i])) XtUnmanageChild(WID.M.pushButt[i]);
      if(XtIsManaged(WID.M.toggleButt[i])) XtUnmanageChild(WID.M.toggleButt[i]);
      if(i==0) XtManageChild(WID.M.defaultButt);      
    }
  }

}


#define NB_HISTORY_MAX 100

void ActualizeContextCb (Widget w, XtPointer client_data, XtPointer call_data){
  char         **ButtonText;
  int            i, last;
  static int     last_context[NB_HISTORY_MAX], numc = 0, numf = 0;

  if((long int)client_data == CONTEXT_BACKWARD){
    if(numc > 1){
      numc--;
      numf++;
      actual_context = last_context[numc-1];
    }
    else return;
  }
  else if((long int)client_data == CONTEXT_FORWARD){
    if(numf > 0){
      numc++;
      numf--;
      actual_context = last_context[numc-1];
    }
    else return;
  }
  else{
    actual_context = (long int)client_data;
    if(last_context[numc-1] != actual_context){
      last_context[numc] = actual_context;
      numc++;
    }
    numf = 0;
  }

  if(numc > NB_HISTORY_MAX-1) numc = 1; /* Il faudrait faire un truc circulaire */

  switch (actual_context){

  case CONTEXT_GEOM :
    actual_global_context = CONTEXT_GEOM;
    XtVaSetValues(WID.M.modButt, XmNlabelString, XmStringCreateSimple("Geometry"), NULL);
    CTX.geom.level = ELEMENTARY;
    //if(M.status>0) mesh_event_handler(MESH_DELETE);
    Msg(INFO, "");
    ButtonText = txt_geom;
    break;

  case CONTEXT_GEOM_ELEM :
    actual_global_context = CONTEXT_GEOM;
    CTX.geom.level = ELEMENTARY;
    Msg(INFO, "Elementary");
    ButtonText = txt_elem;
    break;

  case CONTEXT_GEOM_ELEM_ADD :       
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Add");
    ButtonText = txt_add;
    break;

  case CONTEXT_GEOM_ELEM_ADD_NEW :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Add Create");
    ButtonText = txt_new;
    break;

  case CONTEXT_GEOM_ELEM_ADD_TRANSLATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Add Translate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_ADD_ROTATE : 
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Add Rotate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_ADD_DILATE : 
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Add Dilate"); 
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_ADD_SYMMETRY :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Add Symmetry");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_MOVE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Move");
    ButtonText = txt_move;
    break;

  case CONTEXT_GEOM_ELEM_MOVE_TRANSLATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Move Translate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_MOVE_ROTATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Move Rotate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_MOVE_DILATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Move Dilate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_MOVE_SYMMETRY :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Move Symmetry");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Extrude");
    ButtonText = txt_move;
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE_TRANSLATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Extrude Translate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE_ROTATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Extrude Rotate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE_DILATE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Extrude Dilate");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE_SYMMETRY :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Extrude Symmetry");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_ELEM_DELETE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Elementary Delete");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_GEOM_PHYS :
    actual_global_context = CONTEXT_GEOM;
    CTX.geom.level = PHYSICAL;
    Msg(INFO, "Physical");
    ButtonText = txt_phys;
    break;

  case CONTEXT_GEOM_PHYS_ADD :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Physical Add");
    ButtonText = txt_phys_add;
    break;

  case CONTEXT_GEOM_PHYS_DELETE :
    actual_global_context = CONTEXT_GEOM;
    Msg(INFO, "Physical Delete");
    ButtonText = txt_translate_rotate_dilate_symmetry_delete;
    break;

  case CONTEXT_MESH :
    actual_global_context = CONTEXT_MESH;
    XtVaSetValues(WID.M.modButt, XmNlabelString, XmStringCreateSimple("Mesh"), NULL); 
    Msg(INFO,"");
    ButtonText = txt_mesh;
    break;

  case CONTEXT_MESH_DEFINE :
    actual_global_context = CONTEXT_MESH;
    Msg(INFO,"Define");
    ButtonText = txt_mesh_define;
    break;

  case CONTEXT_POST :
    actual_global_context = CONTEXT_POST;
    XtVaSetValues(WID.M.modButt, XmNlabelString, XmStringCreateSimple("Post Processing"), NULL);
    Msg(INFO,"");
    UpdatePostButtons();
    return;    

  default :
    Msg(WARNING, "Unknown Event in ActualizeContextCb (%d)", actual_context); 
    return;

  }

  last = 0;

  if(XtIsManaged(WID.M.defaultButt)) XtUnmanageChild(WID.M.defaultButt);

  for(i=0 ; i < NB_BUTT_MAX ; i++){

    if(!last && ButtonText[i] != NULL){
      if(XtIsManaged(WID.M.toggleButt[i])) XtUnmanageChild(WID.M.toggleButt[i]);
      XtVaSetValues(WID.M.pushButt[i], 
		    XmNlabelString,XmStringCreateSimple(ButtonText[i]),
		    NULL);
      XtManageChild(WID.M.pushButt[i]);
    }
    else {
      last = 1 ;
      if(XtIsManaged(WID.M.pushButt[i])) XtUnmanageChild(WID.M.pushButt[i]);
      if(XtIsManaged(WID.M.toggleButt[i])) XtUnmanageChild(WID.M.toggleButt[i]);
    }
  }
}  

#undef NB_HISTORY_MAX


void PreviousContextCb (Widget w, XtPointer client_data, XtPointer call_data){
  ActualizeContextCb(w,client_data,call_data);
}

void NextContextCb (Widget w, XtPointer client_data, XtPointer call_data){

  switch(actual_context){

  case CONTEXT_GEOM :
    switch((long int)client_data){
    case 1: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM,call_data); break;
    case 2: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_PHYS,call_data); break;
    case 3: geom_event_handler(GEOM_PARSE); break;
    }
    break;

  case CONTEXT_GEOM_ELEM :
    switch((long int)client_data){
    case 1: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_ADD,call_data); break;
    case 2: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_MOVE,call_data); break;
    case 3: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_EXTRUDE,call_data); break;
    case 4: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_DELETE,call_data); break;
    case 5: geom_event_handler(GEOM_ELEM_SKETCH); break;
    }
    break;

  case CONTEXT_GEOM_ELEM_ADD :
    switch((long int)client_data){
    case 1: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_ADD_NEW,call_data); break;
    case 2: 
      XtManageChild(WID.GD.tranDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_ADD_TRANSLATE,call_data);
      break;
    case 3:
      XtManageChild(WID.GD.rotDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_ADD_ROTATE,call_data);
      break;
    case 4:
      XtManageChild(WID.GD.dilatDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_ADD_DILATE,call_data);
      break;
    case 5: 
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_ADD_SYMMETRY,call_data); 
      break;
    }
    break;    

  case CONTEXT_GEOM_ELEM_ADD_NEW :
    switch((long int)client_data){
    case 1: XtManageChild(WID.GD.paramDialog); break ;
    case 2: XtManageChild(WID.GD.pointDialog); break ;
    case 3: geom_event_handler(GEOM_ELEM_ADD_NEW_LINE); break;
    case 4: geom_event_handler(GEOM_ELEM_ADD_NEW_SPLINE); break;
    case 5: geom_event_handler(GEOM_ELEM_ADD_NEW_BEZIER); break;
    case 6: geom_event_handler(GEOM_ELEM_ADD_NEW_BSPLINE); break;
    case 7: geom_event_handler(GEOM_ELEM_ADD_NEW_CIRCLE); break;
    case 8: geom_event_handler(GEOM_ELEM_ADD_NEW_ELLIPSIS); break;
    case 9: geom_event_handler(GEOM_ELEM_ADD_NEW_PLANE_SURF); break;
    case 10:geom_event_handler(GEOM_ELEM_ADD_NEW_RULED_SURF); break;
    case 11:geom_event_handler(GEOM_ELEM_ADD_NEW_NURBS_SURF); break;
    case 12:geom_event_handler(GEOM_ELEM_ADD_NEW_VOLUME); break;
    }
    break;

  case CONTEXT_GEOM_ELEM_ADD_TRANSLATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_ADD_TRANSLATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_ADD_TRANSLATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_ADD_TRANSLATE_SURF); break ;
    }
    break;

  case CONTEXT_GEOM_ELEM_ADD_ROTATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_ADD_ROTATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_ADD_ROTATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_ADD_ROTATE_SURF); break ;
    }
    break;

  case CONTEXT_GEOM_ELEM_ADD_DILATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_ADD_DILATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_ADD_DILATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_ADD_DILATE_SURF); break ;
    case 4: break ;
    }
    break;

  case CONTEXT_GEOM_ELEM_ADD_SYMMETRY :
    Msg(WARNING, "Add Symmetry not done yet"); 
    break;
     
  case CONTEXT_GEOM_ELEM_MOVE :
    switch((long int)client_data){
    case 1:
      XtManageChild(WID.GD.tranDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_MOVE_TRANSLATE,call_data);
      break;
    case 2:
      XtManageChild(WID.GD.rotDialog);
      ActualizeContextCb(w,(XtPointer) CONTEXT_GEOM_ELEM_MOVE_ROTATE,call_data);
      break;
    case 3:
      XtManageChild(WID.GD.dilatDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_MOVE_DILATE,call_data);
      break;
    case 4:
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_MOVE_SYMMETRY,call_data);
      break;
    }
    break;    

  case CONTEXT_GEOM_ELEM_MOVE_TRANSLATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_MOVE_TRANSLATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_MOVE_TRANSLATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_MOVE_TRANSLATE_SURF); break ;
    }
    break;

  case CONTEXT_GEOM_ELEM_MOVE_ROTATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_MOVE_ROTATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_MOVE_ROTATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_MOVE_ROTATE_SURF); break ;
    }
    break;
    
  case CONTEXT_GEOM_ELEM_MOVE_DILATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_MOVE_DILATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_MOVE_DILATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_MOVE_DILATE_SURF); break ;
    case 4: break ;
    }
    break;

  case CONTEXT_GEOM_ELEM_MOVE_SYMMETRY :
    Msg(WARNING, "Move Symmetry not done yet"); 
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE :
    switch((long int)client_data){
    case 1:
      XtManageChild(WID.GD.tranDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_EXTRUDE_TRANSLATE,call_data);
      break;
    case 2:
      XtManageChild(WID.GD.rotDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_EXTRUDE_ROTATE,call_data);
      break;
    case 3:
      XtManageChild(WID.GD.dilatDialog);
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_EXTRUDE_DILATE,call_data);
      break;
    case 4:
      ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_ELEM_EXTRUDE_SYMMETRY,call_data);
      break;
    }
    break;    

  case CONTEXT_GEOM_ELEM_EXTRUDE_TRANSLATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_EXTRUDE_TRANSLATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_EXTRUDE_TRANSLATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_EXTRUDE_TRANSLATE_SURF); break ;
    }
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE_ROTATE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_EXTRUDE_ROTATE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_EXTRUDE_ROTATE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_EXTRUDE_ROTATE_SURF); break ;
    }
    break;
    
  case CONTEXT_GEOM_ELEM_EXTRUDE_DILATE :
    Msg(WARNING, "Extrude Dilate not done yet!"); 
    break;

  case CONTEXT_GEOM_ELEM_EXTRUDE_SYMMETRY :
    Msg(WARNING, "Extrude Symmetry not done yet!"); 
    break;
     
  case CONTEXT_GEOM_ELEM_DELETE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_ELEM_DELETE_POINT); break ;
    case 2: geom_event_handler(GEOM_ELEM_DELETE_LINE); break ;
    case 3: geom_event_handler(GEOM_ELEM_DELETE_SURF); break ;
    }
    break;

  case CONTEXT_GEOM_PHYS :
    switch((long int)client_data){
    case 1: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_PHYS_ADD,call_data); break;
    case 2: ActualizeContextCb(w,(XtPointer)CONTEXT_GEOM_PHYS_DELETE,call_data); break;
    }
    break;

  case CONTEXT_GEOM_PHYS_ADD :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_PHYS_ADD_POINT); break ;
    case 2: geom_event_handler(GEOM_PHYS_ADD_LINE); break ;
    case 3: geom_event_handler(GEOM_PHYS_ADD_SURF); break ;
    case 4: geom_event_handler(GEOM_PHYS_ADD_VOLUME); break ;
    }
    break;

  case CONTEXT_GEOM_PHYS_DELETE :
    switch((long int)client_data){
    case 1: geom_event_handler(GEOM_PHYS_DELETE_POINT); break ;
    case 2: geom_event_handler(GEOM_PHYS_DELETE_LINE); break ;
    case 3: geom_event_handler(GEOM_PHYS_DELETE_SURF); break ;
    case 4: geom_event_handler(GEOM_PHYS_DELETE_VOLUME); break ;
    }
    break;
    
  case CONTEXT_MESH :

    switch((long int)client_data){
    case 1: ActualizeContextCb(w,(XtPointer)CONTEXT_MESH_DEFINE,call_data); break;
    case 2: mesh_event_handler(MESH_1D); break;
    case 3: mesh_event_handler(MESH_2D); break;
    case 4: mesh_event_handler(MESH_3D); break;
    }
    break;

  case CONTEXT_MESH_DEFINE :
    switch((long int)client_data){
    case 1: 
      XtManageChild(WID.MD.charLengthDialog);      
      mesh_event_handler(MESH_DEFINE_CHAR_LENGTH); break;
    case 2: 
      mesh_event_handler(MESH_DEFINE_RECOMBINE); break;
    case 3: 
      XtManageChild(WID.MD.trsfLineDialog);
      mesh_event_handler(MESH_DEFINE_TRSF_LINE); break;
    case 4: 
      mesh_event_handler(MESH_DEFINE_TRSF_SURFACE); break;
    case 5: 
      XtManageChild(WID.MD.trsfVolumeDialog);
      mesh_event_handler(MESH_DEFINE_TRSF_VOLUME); break;
    }
    break;

  default :
    Msg(WARNING, "Unknown Context in NextContextCb (%d)", actual_global_context); 
    break;
    
  }
}


int AddViewInUI(int i, char *Name, int Num){
  //char tmp[20];

  if(i > NB_BUTT_MAX -1) return 1;

  txt_post[i-1] = (char*)Malloc(NAME_STR_L*sizeof(char));
  strncpy(txt_post[i-1],Name,NAME_STR_L);

  //sprintf(tmp, " (%d)", Num);
  //strncat(txt_post[i-1],tmp,NAME_STR_L);

  if(actual_global_context == CONTEXT_POST)
    ActualizeContextCb(NULL,(XtPointer)actual_global_context,NULL);

  return 0;
}

void RemoveViewCb(Widget w, XtPointer client_data, XtPointer call_data){
  Post_View      *v;
  int            i;
  
  i = (long int)client_data ;

  v = (Post_View*)List_Pointer(Post_ViewList,(long int)client_data-1);

  while(txt_post[i]){
    strncpy(txt_post[i-1], txt_post[i], NAME_STR_L);
    i++;
  }
  Free(txt_post[i-1]);
  txt_post[i-1] = NULL;

  FreeView(v);

  if(!List_Suppress(Post_ViewList, v, fcmpPostViewNum))
    Msg(ERROR, "Could Not Suppress View from List");

  if(actual_global_context == CONTEXT_POST)
    ActualizeContextCb(NULL,(XtPointer)actual_global_context,NULL);  

  Init();
  Draw();
}

