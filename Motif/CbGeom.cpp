// $Id: CbGeom.cpp,v 1.2 2001-01-10 08:41:07 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Widgets.h"
#include "Context.h"
#include "Verif.h"
#include "OpenFile.h"

#include "CbGeom.h"

extern Context_T  CTX;
extern Widgets_T  WID;
extern Mesh       M;
	     
static char  name_text[100], value_text[100];

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
    case ENT_LINE    : HighlightEntityNum(0,abs(ip),0,1); break ;
    case ENT_SURFACE : HighlightEntityNum(0,0,abs(ip),1); break ;
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
    OpenProblem(CTX.filename);
    Init();
    Draw();
    break;

  case GEOM_ELEM_ADD_NEW_POINT :
    add_point(CTX.filename);
    ZeroHighlight(&M);
    Replot();
    break;

  case GEOM_ELEM_ADD_NEW_LINE :
  case GEOM_ELEM_ADD_NEW_SPLINE :   
  case GEOM_ELEM_ADD_NEW_BEZIER :
  case GEOM_ELEM_ADD_NEW_BSPLINE :
    n=0;
    while(1){
      Msg(STATUS,"Select Point ('e'=end, 'q'=quit)");
      ib = SelectEntity(ENT_POINT, &v,&c,&s);
      if(ib == 1){ /* left mouse butt */
        p[n++] = v->Num; 
      }
      if (ib == -1){ /* 'e' */
        if(n >= 2) {
          switch(event){
          case GEOM_ELEM_ADD_NEW_LINE   : add_multline(n,p,CTX.filename); break;
          case GEOM_ELEM_ADD_NEW_SPLINE : add_spline  (n,p,CTX.filename); break;
          case GEOM_ELEM_ADD_NEW_BEZIER : add_bezier  (n,p,CTX.filename); break;
          case GEOM_ELEM_ADD_NEW_BSPLINE: add_bspline (n,p,CTX.filename); break;
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
      if(n == 0) Msg(STATUS,"Select Center ('q'=quit)");
      if(n == 1) Msg(STATUS,"Select Starting Point ('q'=quit)");
      if(n == 2) Msg(STATUS,"Select Ending Point ('q'=quit)");
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
        add_circ(p[1],p[0],p[2],CTX.filename); /* begin, center, end */
        ZeroHighlight(&M);
        Replot();
        n=0;
      }
    }
    break;

  case GEOM_ELEM_ADD_NEW_ELLIPSIS :
    n = 0;
    while(1){
      if(n == 0) Msg(STATUS,"Select Center ('q'=quit)");
      if(n == 1) Msg(STATUS,"Select an Axis Point ('q'=quit)");
      if(n == 2) Msg(STATUS,"Select Starting Point ('q'=quit)");
      if(n == 3) Msg(STATUS,"Select Ending Point ('q'=quit)");
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
        add_ell(p[3],p[2],p[0],p[1],CTX.filename);
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
        Msg(STATUS,"Select Boundary ('q'=quit)");
        ib = SelectEntity(type, &v,&c,&s);
        if(ib <= 0){
          ZeroHighlight(&M);
          Replot();
          goto stopall;
        }       
        if(SelectContour (type, (type==ENT_LINE)?c->Num:s->Num, Liste1)){
          if(type==ENT_LINE) 
            add_loop(Liste1,CTX.filename,&zone);
          else
            add_vol(Liste1,CTX.filename,&zone);
          List_Reset(Liste1);
          List_Add(Liste2,&zone);
          while(1){
            Msg(STATUS,"Select Holes ('q'=quit)");
            ib = SelectEntity(type, &v,&c,&s); 
            if(ib <= 0){
              ZeroHighlight(&M);
              Replot();
              break;
            }
            if(SelectContour (type, (type==ENT_LINE)?c->Num:s->Num, Liste1)){
              if(type==ENT_LINE) 
                add_loop(Liste1,CTX.filename,&zone);
              else
                add_vol(Liste1,CTX.filename,&zone);
              List_Reset(Liste1);
              List_Add(Liste2,&zone);
            }
          }
          if(List_Nbr(Liste2)){
            switch(event){
            case GEOM_ELEM_ADD_NEW_RULED_SURF : add_surf(Liste2,CTX.filename,0,1); break;
            case GEOM_ELEM_ADD_NEW_PLANE_SURF : add_surf(Liste2,CTX.filename,0,2); break;
            case GEOM_ELEM_ADD_NEW_VOLUME :  add_multvol(Liste2,CTX.filename); break;
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
      Msg(STATUS,"Select Point ('q'=quit)");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      translate_pt(event==GEOM_ELEM_ADD_TRANSLATE_POINT?1:0,v->Num,CTX.filename);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_TRANSLATE_LINE :
  case GEOM_ELEM_MOVE_TRANSLATE_LINE :
    while(1){
      Msg(STATUS,"Select Line ('q'=quit)");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      translate_seg(event==GEOM_ELEM_ADD_TRANSLATE_LINE?1:0,c->Num,CTX.filename);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_TRANSLATE_SURF :
  case GEOM_ELEM_MOVE_TRANSLATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface ('q'=quit)");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      translate_surf(event==GEOM_ELEM_ADD_TRANSLATE_SURF?1:0,s->Num,CTX.filename);
      ZeroHighlight(&M);
      Replot();
    }
    break;


  case GEOM_ELEM_ADD_ROTATE_POINT :
  case GEOM_ELEM_MOVE_ROTATE_POINT :
    while(1){
      Msg(STATUS,"Select Point ('q'=quit)");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      rotate(event==GEOM_ELEM_ADD_ROTATE_POINT?1:0,v->Num,CTX.filename,"Point");
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_ROTATE_LINE :
  case GEOM_ELEM_MOVE_ROTATE_LINE :
    while(1){
      Msg(STATUS,"Select Line ('q'=quit)");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      rotate(event==GEOM_ELEM_ADD_ROTATE_LINE?1:0,c->Num,CTX.filename,"Line");
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_ROTATE_SURF :
  case GEOM_ELEM_MOVE_ROTATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface ('q'=quit)");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      rotate(event==GEOM_ELEM_ADD_ROTATE_SURF?1:0,s->Num,CTX.filename,"Surface");
      ZeroHighlight(&M);
      Replot();
    }
    break;



  case GEOM_ELEM_EXTRUDE_TRANSLATE_POINT :
  case GEOM_ELEM_EXTRUDE_ROTATE_POINT :
    while(1){
      Msg(STATUS,"Select Point ('q'=quit)");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot(); 
        break;
      }
      event==GEOM_ELEM_EXTRUDE_TRANSLATE_POINT ? 
        extrude(v->Num,CTX.filename, "Point") :
        protude(v->Num,CTX.filename, "Point") ;
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_EXTRUDE_TRANSLATE_LINE :
  case GEOM_ELEM_EXTRUDE_ROTATE_LINE :
    while(1){
      Msg(STATUS,"Select Line ('q'=quit)");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      event==GEOM_ELEM_EXTRUDE_TRANSLATE_LINE ? 
        extrude(c->Num,CTX.filename, "Line") :
        protude(c->Num,CTX.filename, "Line") ;
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_EXTRUDE_TRANSLATE_SURF :
  case GEOM_ELEM_EXTRUDE_ROTATE_SURF :
    while(1){
      Msg(STATUS,"Select Surface ('q'=quit)");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      event==GEOM_ELEM_EXTRUDE_TRANSLATE_SURF ? 
        extrude(s->Num,CTX.filename, "Surface") :
        protude(s->Num,CTX.filename, "Surface") ;
      ZeroHighlight(&M);
      Replot();
    }
    break;


  case GEOM_ELEM_ADD_DILATE_POINT :
  case GEOM_ELEM_MOVE_DILATE_POINT :
  case GEOM_ELEM_ADD_SYMMETRY_POINT :
  case GEOM_ELEM_MOVE_SYMMETRY_POINT :
    while(1){
      Msg(STATUS,"Select Point ('q'=quit)");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      switch(event){
      case GEOM_ELEM_ADD_DILATE_POINT :
	dilate(1,v->Num,CTX.filename,"Point");
	break;
      case GEOM_ELEM_MOVE_DILATE_POINT :
	dilate(0,v->Num,CTX.filename,"Point");
	break;
      case GEOM_ELEM_ADD_SYMMETRY_POINT :
	symmetry(1,v->Num,CTX.filename,"Point");
	break;
      case GEOM_ELEM_MOVE_SYMMETRY_POINT :
	symmetry(0,v->Num,CTX.filename,"Point");
	break;
      }
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_DILATE_LINE :
  case GEOM_ELEM_MOVE_DILATE_LINE :
  case GEOM_ELEM_ADD_SYMMETRY_LINE :
  case GEOM_ELEM_MOVE_SYMMETRY_LINE :
    while(1){
      Msg(STATUS,"Select Line ('q'=quit)");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      switch(event){
      case GEOM_ELEM_ADD_DILATE_LINE :
	dilate(1,c->Num,CTX.filename,"Line");
	break;
      case GEOM_ELEM_MOVE_DILATE_LINE :
	dilate(0,c->Num,CTX.filename,"Line");
	break;
      case GEOM_ELEM_ADD_SYMMETRY_LINE :
	symmetry(1,c->Num,CTX.filename,"Line");
	break;
      case GEOM_ELEM_MOVE_SYMMETRY_LINE :
	symmetry(0,c->Num,CTX.filename,"Line");
	break;
      }
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_ADD_DILATE_SURF :
  case GEOM_ELEM_MOVE_DILATE_SURF :
  case GEOM_ELEM_ADD_SYMMETRY_SURF :
  case GEOM_ELEM_MOVE_SYMMETRY_SURF :
    while(1){
      Msg(STATUS,"Select Surface ('q'=quit)");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      switch(event){
      case GEOM_ELEM_ADD_DILATE_SURF :
	dilate(1,s->Num,CTX.filename,"Surface");
	break;
      case GEOM_ELEM_MOVE_DILATE_SURF :
	dilate(0,s->Num,CTX.filename,"Surface");
	break;
      case GEOM_ELEM_ADD_SYMMETRY_SURF :
	symmetry(1,s->Num,CTX.filename,"Surface");
	break;
      case GEOM_ELEM_MOVE_SYMMETRY_SURF :
	symmetry(0,s->Num,CTX.filename,"Surface");
	break;
      }
      ZeroHighlight(&M);
      Replot();
    }
    break;




  case GEOM_ELEM_DELETE_POINT :
    while(1){
      Msg(STATUS,"Select Point ('q'=quit)");
      if(!SelectEntity(ENT_POINT, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      del_pnt(v->Num,CTX.filename);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_DELETE_LINE :
    while(1){
      Msg(STATUS,"Select Line ('q'=quit)");
      if(!SelectEntity(ENT_LINE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      del_seg(c->Num,CTX.filename);
      ZeroHighlight(&M);
      Replot();
    }
    break;
  case GEOM_ELEM_DELETE_SURF :
    while(1){
      Msg(STATUS,"Select Point ('q'=quit)");
      if(!SelectEntity(ENT_SURFACE, &v,&c,&s)){
        ZeroHighlight(&M);
        Replot();
        break;
      }
      del_srf(s->Num,CTX.filename);
      ZeroHighlight(&M);
      Replot();
    }
    break;


  case GEOM_ELEM_SKETCH :
    Msg(STATUS,"Verifying Geometry");
    add_infile("Coherence;",CTX.filename);
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
          Msg(STATUS,"Select Point ('e'=end, 'q'=quit)"); 
          type = ENT_POINT;
          break;
        case GEOM_PHYS_ADD_LINE:
          Msg(STATUS,"Select Line ('e'=end, 'q'=quit)"); 
          type = ENT_LINE;
          break;
        case GEOM_PHYS_ADD_SURF:
          Msg(STATUS,"Select Surface ('e'=end, 'q'=quit)"); 
          type = ENT_SURFACE;
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
          add_physical_entity(Liste1,CTX.filename,type,&zone);
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
    Msg(WARNING, "Add Physical Volume not done Interactively (Please Edit File Manually)"); 
    break;

  case GEOM_PHYS_DELETE_POINT :
  case GEOM_PHYS_DELETE_LINE :
  case GEOM_PHYS_DELETE_SURF :
  case GEOM_PHYS_DELETE_VOLUME :
    Msg(WARNING, "Deletetion of Physical Entities not Done"); 
    break;

  case GEOM_ELEM_ADD_NEW_NURBS_SURF :
    Msg(WARNING, "Add NURBS not not done Interactively (Please Edit File Manually)"); 
    break;

  default :
    Msg(WARNING, "Unknown Event in geom_event_handler"); 
    break;

  }

  Msg(STATUS,"Ready");
}


/* ------------------------------------------------------------------------ 
    G e o m C b                                                       
   ------------------------------------------------------------------------ */

void GeomCb (Widget w, XtPointer client_data, XtPointer call_data){

  switch((long int)client_data){

  case GEOM_PARAMETER_ADD   : add_param(name_text,value_text,CTX.filename); break;
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
  case GEOM_SYMMETRY_A : strcpy(sa_text,XmTextGetString(w)); break;
  case GEOM_SYMMETRY_B : strcpy(sb_text,XmTextGetString(w)); break;
  case GEOM_SYMMETRY_C : strcpy(sc_text,XmTextGetString(w)); break;
  case GEOM_SYMMETRY_D : strcpy(sd_text,XmTextGetString(w)); break;
  default :
    Msg(WARNING, "Unknown Value in GeomCb (%d)", (long int)client_data); 
    break;

  }
}

