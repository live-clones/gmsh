/* $Id: CbGeom.cpp,v 1.2 2000-11-23 14:11:41 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Widgets.h"
#include "Context.h"
#include "Verif.h"
#include "Main.h"

#include "CbGeom.h"

extern Context_T  CTX;
extern Widgets_T  WID;

extern Mesh       M;
extern char       TheFileName[256];

extern char     x_text[100], y_text[100], z_text[100], l_text[100];
extern char     tx_text[100], ty_text[100], tz_text[100];
extern char     px_text[100], py_text[100], pz_text[100], angle_text[100];
extern char     ax_text[100], ay_text[100], az_text[100], angle_text[100];
extern char     dx_text[100], dy_text[100], dz_text[100], df_text[100];

static char     name_text[100], value_text[100];

int SelectContour (int type, int num, List_T *Liste1){
  int      k,ip,i;
  List_T  *Liste2;

  Liste2 = List_Create(1,1,sizeof(int));

  if(!List_Nbr(Liste1)){
    switch(type){
    case ENT_LINE    : k = alledgeslinked (num, Liste1, (List_T*)NULL); break;
    case ENT_SURFACE : k = allfaceslinked (num, Liste1, (List_T*)NULL); break;
    }
  }
  else{
    List_Reset(Liste2);
    for(i=0;i<List_Nbr(Liste1);i++)
      List_Add(Liste2,List_Pointer(Liste1,i));
    List_Reset(Liste1);
    switch(type){
    case ENT_LINE    : k = alledgeslinked (num, Liste1, Liste2); break;
    case ENT_SURFACE : k = allfaceslinked (num, Liste1, Liste2); break;
    }
  }

  for(i=0;i<List_Nbr(Liste1);i++){
    List_Read(Liste1,i,&ip);
    switch(type){
    case ENT_LINE    : highlight_entity_num(0,abs(ip),0,1); break ;
    case ENT_SURFACE : highlight_entity_num(0,0,abs(ip),1); break ;
    }
  }

  List_Delete(Liste2);
  return k;
}


/* ------------------------------------------------------------------------ */
/*  g e o m _ e v e n t _ h a n d l e r                                     */
/* ------------------------------------------------------------------------ */

void geom_event_handler (int event) {
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  static int n=0, p[100];

  int      ib,zone,type;
  List_T  *Liste1, *Liste2;

  if(CTX.threads_lock) return ;

  switch (event) {

  case GEOM_PARSE :
    OpenProblem(TheFileName);
    Init();
    Draw();
    break;

  case GEOM_ELEM_ADD_NEW_POINT :
    add_point(TheFileName);
    ZeroHighlight(&M);
    Replot();
    break;

  case GEOM_ELEM_ADD_NEW_LINE :
  case GEOM_ELEM_ADD_NEW_SPLINE :   
  case GEOM_ELEM_ADD_NEW_BEZIER :
  case GEOM_ELEM_ADD_NEW_BSPLINE :
    n=0;
    while(1){
      Msg(STATUS,"Select Point: (e) to end, (q) to quit");
      ib = SelectEntity(ENT_POINT, &v,&c,&s);
      if(ib == 1){ /* left mouse butt */
	p[n++] = v->Num; 
      }
      if (ib == -1){ /* 'e' */
	if(n >= 2) {
	  switch(event){
	  case GEOM_ELEM_ADD_NEW_LINE   : add_multline(n,p,TheFileName); break;
	  case GEOM_ELEM_ADD_NEW_SPLINE : add_spline  (n,p,TheFileName); break;
	  case GEOM_ELEM_ADD_NEW_BEZIER : add_bezier  (n,p,TheFileName); break;
	  case GEOM_ELEM_ADD_NEW_BSPLINE: add_bspline (n,p,TheFileName); break;
	  }
	}
	n=0;
	ZeroHighlight(&M);
	Replot();
      }
      if(ib == 0){ /* 'q' */
	n=0 ;
	ZeroHighlight(&M);
	Replot();
	break;
      }
    }
    break;

  case GEOM_ELEM_ADD_NEW_CIRCLE :
    n=0;
    while(1){
      if(n == 0) Msg(STATUS,"Select Center: (q) to quit");
      if(n == 1) Msg(STATUS,"Select Starting Point: (q) to quit");
      if(n == 2) Msg(STATUS,"Select Ending Point: (q) to quit");
      ib = SelectEntity(ENT_POINT, &v,&c,&s);
      if(ib == 1) { /* left mouse butt */
	p[n++] = v->Num; 
      }
      if(ib == 0) { /* 'q' */
	n=0 ;
	ZeroHighlight(&M);
	Replot();
	break;
      }
      if(n == 3){
	add_circ(p[1],p[0],p[2],TheFileName); /* begin, center, end */
	ZeroHighlight(&M);
	Replot();
	n=0;
      }
    }
    break;

  case GEOM_ELEM_ADD_NEW_ELLIPSIS :
    n = 0;
    while(1){
      if(n == 0) Msg(STATUS,"Select Center: (q) to quit");
      if(n == 1) Msg(STATUS,"Select an Axis Point: (q) to quit");
      if(n == 2) Msg(STATUS,"Select Starting Point: (q) to quit");
      if(n == 3) Msg(STATUS,"Select Ending Point: (q) to quit");
      ib = SelectEntity(ENT_POINT, &v,&c,&s);
      if(ib == 1) { /* left mouse butt */
	p[n++] = v->Num; 
      }
      if(ib == 0){ /* 'q' */
	n=0 ;
	ZeroHighlight(&M);
	Replot();
	break;
      }
      if(n == 4){
	add_ell(p[3],p[2],p[0],p[1],TheFileName);
	ZeroHighlight(&M);
	Replot();
	n=0;
      }
    }
    break;

  case GEOM_ELEM_ADD_NEW_PLANE_SURF :
  case GEOM_ELEM_ADD_NEW_RULED_SURF :
  case GEOM_ELEM_ADD_NEW_VOLUME :
    Liste1 = List_Create(10,10,sizeof(int));
    Liste2 = List_Create(10,10,sizeof(int));

    if(event == GEOM_ELEM_ADD_NEW_VOLUME)
      type = ENT_SURFACE;
    else
      type = ENT_LINE;      

    while(1){      
      List_Reset(Liste1);
      List_Reset(Liste2);
      
      while(1) {	
	Msg(STATUS,"Select Boundary: (q) to quit");
	ib = SelectEntity(type, &v,&c,&s);
	if(ib <= 0){
	  ZeroHighlight(&M);
	  Replot();
	  goto stopall;
	}  	
	if(SelectContour (type, (type==ENT_LINE)?c->Num:s->Num, Liste1)){
	  if(type==ENT_LINE) 
	    add_loop(Liste1,TheFileName,&zone);
	  else
	    add_vol(Liste1,TheFileName,&zone);
	  List_Reset(Liste1);
	  List_Add(Liste2,&zone);
	  while(1){
	    Msg(STATUS,"Select Holes: (q) to quit");
	    ib = SelectEntity(type, &v,&c,&s); 
	    if(ib <= 0){
	      ZeroHighlight(&M);
	      Replot();
	      break;
	    }
	    List_Reset(Liste1);
	    if(SelectContour (type, (type==ENT_LINE)?c->Num:s->Num, Liste1)){
	      if(type==ENT_LINE) 
		add_loop(Liste1,TheFileName,&zone);
	      else
		add_vol(Liste1,TheFileName,&zone);
	      List_Reset(Liste1);
	      List_Add(Liste2,&zone);
	    }
	  }
	  if(List_Nbr(Liste2)){
	    switch(event){
	    case GEOM_ELEM_ADD_NEW_RULED_SURF : add_surf(Liste2,TheFileName,0,1); break;
	    case GEOM_ELEM_ADD_NEW_PLANE_SURF : add_surf(Liste2,TheFileName,0,2); break;
	    case GEOM_ELEM_ADD_NEW_VOLUME :  add_multvol(Liste2,TheFileName); break;
	    }
	    ZeroHighlight(&M);
	    Replot();
	    break;
	  }
	}
      }
    }
    stopall : ;
    List_Delete(Liste1);
    List_Delete(Liste2);
    break;


  case GEOM_ELEM_ADD_TRANSLATE_POINT :
  case GEOM_ELEM_MOVE_TRANSLATE_POINT :
    while(1){
      Msg(STATUS,"Select Point: (q) to quit");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      translate_pt(event==GEOM_ELEM_ADD_TRANSLATE_POINT?1:0,v->Num,TheFileName);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_TRANSLATE_LINE :
  case GEOM_ELEM_MOVE_TRANSLATE_LINE :
    while(1){
      Msg(STATUS,"Select Line: (q) to quit");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      translate_seg(event==GEOM_ELEM_ADD_TRANSLATE_LINE?1:0,c->Num,TheFileName);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_TRANSLATE_SURF :
  case GEOM_ELEM_MOVE_TRANSLATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface: (q) to quit");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      translate_surf(event==GEOM_ELEM_ADD_TRANSLATE_SURF?1:0,s->Num,TheFileName);
      ZeroHighlight(&M);
      Replot();
    }
    break;


  case GEOM_ELEM_ADD_ROTATE_POINT :
  case GEOM_ELEM_MOVE_ROTATE_POINT :
    while(1){
      Msg(STATUS,"Select Point: (q) to quit");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      rotate(event==GEOM_ELEM_ADD_ROTATE_POINT?1:0,v->Num,TheFileName,"Point");
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_ROTATE_LINE :
  case GEOM_ELEM_MOVE_ROTATE_LINE :
    while(1){
      Msg(STATUS,"Select Line: (q) to quit");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      rotate(event==GEOM_ELEM_ADD_ROTATE_LINE?1:0,c->Num,TheFileName,"Line");
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_ROTATE_SURF :
  case GEOM_ELEM_MOVE_ROTATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface: (q) to quit");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      rotate(event==GEOM_ELEM_ADD_ROTATE_SURF?1:0,s->Num,TheFileName,"Surface");
      ZeroHighlight(&M);
      Replot();
    }
    break;



  case GEOM_ELEM_EXTRUDE_TRANSLATE_POINT :
  case GEOM_ELEM_EXTRUDE_ROTATE_POINT :
    while(1){
      Msg(STATUS,"Select Point: (q) to quit");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot(); 
	break;
      }
      event==GEOM_ELEM_EXTRUDE_TRANSLATE_POINT ? 
	extrude(v->Num,TheFileName, "Point") :
	protude(v->Num,TheFileName, "Point") ;
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_EXTRUDE_TRANSLATE_LINE :
  case GEOM_ELEM_EXTRUDE_ROTATE_LINE :
    while(1){
      Msg(STATUS,"Select Line: (q) to quit");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      event==GEOM_ELEM_EXTRUDE_TRANSLATE_LINE ? 
	extrude(c->Num,TheFileName, "Line") :
	protude(c->Num,TheFileName, "Line") ;
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_EXTRUDE_TRANSLATE_SURF :
  case GEOM_ELEM_EXTRUDE_ROTATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface: (q) to quit");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      event==GEOM_ELEM_EXTRUDE_TRANSLATE_SURF ? 
	extrude(s->Num,TheFileName, "Surface") :
	protude(s->Num,TheFileName, "Surface") ;
      ZeroHighlight(&M);
      Replot();
    }
    break;


  case GEOM_ELEM_ADD_DILATE_POINT :
  case GEOM_ELEM_MOVE_DILATE_POINT :
    while(1){
      Msg(STATUS,"Select Point: (q) to quit");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      dilate(event==GEOM_ELEM_ADD_DILATE_POINT?1:0,v->Num,TheFileName,"Point");
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_DILATE_LINE :
  case GEOM_ELEM_MOVE_DILATE_LINE :
    while(1){
      Msg(STATUS,"Select Line: (q) to quit");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      dilate(event==GEOM_ELEM_ADD_DILATE_LINE?1:0,c->Num,TheFileName,"Line");
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_DILATE_SURF :
  case GEOM_ELEM_MOVE_DILATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface: (q) to quit");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      dilate(event==GEOM_ELEM_ADD_DILATE_SURF?1:0,s->Num,TheFileName,"Surface");
      ZeroHighlight(&M);
      Replot();
    }
    break;




  case GEOM_ELEM_DELETE_POINT :
    while(1){
      Msg(STATUS,"Select Point: (q) to quit");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      del_pnt(v->Num,TheFileName);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_DELETE_LINE :
    while(1){
      Msg(STATUS,"Select Line: (q) to quit");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      del_seg(c->Num,TheFileName);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_DELETE_SURF :
    while(1){
      Msg(STATUS,"Select Point: (q) to quit");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
	ZeroHighlight(&M);
	Replot();
	break;
      }
      del_srf(s->Num,TheFileName);
      ZeroHighlight(&M);
      Replot();
    }
    break;


  case GEOM_ELEM_SKETCH :
    Msg(STATUS,"Verifying Geometry");
    add_infile("Coherence;",TheFileName);
    ZeroHighlight(&M);
    Replot();
    break;

  case GEOM_PHYS_ADD_POINT:
  case GEOM_PHYS_ADD_LINE:
  case GEOM_PHYS_ADD_SURF:
    Liste1 = List_Create(5,5,sizeof(int));
    while(1){
      switch(event){
	case GEOM_PHYS_ADD_POINT:
	  Msg(STATUS,"Select Point: (e) to end, (q) to quit"); 
	  type = 0;
	  break;
	case GEOM_PHYS_ADD_LINE:
	  Msg(STATUS,"Select Line: (e) to end, (q) to quit"); 
	  type = 1;
	  break;
	case GEOM_PHYS_ADD_SURF:
	  Msg(STATUS,"Select Surface: (e) to end, (q) to quit"); 
	  type = 2;
	  break;
      }
      ib = SelectEntity(type, &v,&c,&s);
      if(ib == 1){ /* left mouse */
	switch(event){
	case GEOM_PHYS_ADD_POINT: List_Add(Liste1, &v->Num); break;
	case GEOM_PHYS_ADD_LINE:  List_Add(Liste1, &c->Num); break;
	case GEOM_PHYS_ADD_SURF:  List_Add(Liste1, &s->Num); break;
	}
      }
      if(ib == -1){ /* end */
	if(List_Nbr(Liste1)){
	  add_physical_entity(Liste1,TheFileName,type,&zone);
	  List_Reset(Liste1);
	  ZeroHighlight(&M);
	  Replot();
	}
      }
      if(ib == 0){
	ZeroHighlight(&M);
	Replot();
	break;
      }
    }
    break;

  case GEOM_PHYS_ADD_VOLUME :  
  case GEOM_PHYS_DELETE_POINT :
  case GEOM_PHYS_DELETE_LINE :
  case GEOM_PHYS_DELETE_SURF :
  case GEOM_PHYS_DELETE_VOLUME :
  case GEOM_ELEM_ADD_NEW_NURBS_SURF :
    Msg(WARNING, "Not done interactively yet. Sorry!"); 
    break;

  default :
    Msg(WARNING, "Unknown event in geom_event_handler"); 
    break;

  }

  Msg(STATUS,"Ready");
}


/* ------------------------------------------------------------------------ 
    G e o m C b                                                       
   ------------------------------------------------------------------------ */

void GeomCb (Widget w, XtPointer client_data, XtPointer call_data){

  switch((long int)client_data){

  case GEOM_PARAMETER_ADD   : add_param(name_text,value_text,TheFileName); break;
  case GEOM_PARAMETER_NAME  : strcpy(name_text,XmTextGetString(w)); break;
  case GEOM_PARAMETER_VALUE : strcpy(value_text,XmTextGetString(w)); break;
  case GEOM_POINT_ADD  : geom_event_handler(GEOM_ELEM_ADD_NEW_POINT); Replot(); break;
  case GEOM_POINT_X    : strcpy(x_text,XmTextGetString(w)); break;
  case GEOM_POINT_Y    : strcpy(y_text,XmTextGetString(w)); break;
  case GEOM_POINT_Z    : strcpy(z_text,XmTextGetString(w)); break;
  case GEOM_POINT_L    : strcpy(l_text,XmTextGetString(w)); break;
  case GEOM_TRAN_X     : strcpy(tx_text,XmTextGetString(w)); break;
  case GEOM_TRAN_Y     : strcpy(ty_text,XmTextGetString(w)); break;
  case GEOM_TRAN_Z     : strcpy(tz_text,XmTextGetString(w)); break;
  case GEOM_ROT_PX     : strcpy(px_text,XmTextGetString(w)); break;
  case GEOM_ROT_PY     : strcpy(py_text,XmTextGetString(w)); break;
  case GEOM_ROT_PZ     : strcpy(pz_text,XmTextGetString(w)); break;
  case GEOM_ROT_AX     : strcpy(ax_text,XmTextGetString(w)); break;  
  case GEOM_ROT_AY     : strcpy(ay_text,XmTextGetString(w)); break; 
  case GEOM_ROT_AZ     : strcpy(az_text,XmTextGetString(w)); break;
  case GEOM_ROT_ANGLE  : strcpy(angle_text,XmTextGetString(w)); break;
  case GEOM_DILAT_X    : strcpy(dx_text,XmTextGetString(w)); break;
  case GEOM_DILAT_Y    : strcpy(dy_text,XmTextGetString(w)); break;
  case GEOM_DILAT_Z    : strcpy(dz_text,XmTextGetString(w)); break;
  case GEOM_DILAT_F    : strcpy(df_text,XmTextGetString(w)); break;

  default :
    Msg(WARNING, "Unknown value in GeomCb : %d", (long int)client_data); 
    break;

  }
}

