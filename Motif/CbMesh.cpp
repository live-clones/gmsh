// $Id: CbMesh.cpp,v 1.2 2001-01-11 07:32:35 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "CbMesh.h"
#include "Context.h"
#include "Widgets.h"

extern Widgets_T  WID;
extern Context_T  CTX;
extern Mesh       M;

/* ------------------------------------------------------------------------ */
/*  m e s h _ e v e n t _ h a n d l e r                                     */
/* ------------------------------------------------------------------------ */

#ifdef _USETHREADS

#include <pthread.h>

int               MeshDim ;
pthread_t         MeshThread ;
//pthread_mutex_t   MeshMutex ;

void* StartMeshThread(void * data){

  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  //  pthread_mutex_unlock(&MeshMutex);

  mai3d(&M,MeshDim);
  Msg(STATUS,"Ready");
  CTX.mesh.draw = 1;
  CTX.threads_lock = 0;
  XtSetSensitive(WID.G.Butt[6], 0);
  Init();
  Draw();
  pthread_exit(NULL);
  return NULL ;
}

void CancelMeshThread(void){
  if(CTX.threads){
    //  pthread_mutex_lock(&MeshMutex);
    //  pthread_join(MeshThread,NULL);
    //  pthread_detach(MeshThread);
    
    pthread_cancel(MeshThread);
    CTX.mesh.draw = 1;
    CTX.threads_lock = 0;
    XtSetSensitive(WID.G.Butt[6], 0);    
    Msg(INFO,"Mesh Aborted");
    mesh_event_handler(MESH_DELETE);
    Msg(STATUS,"Ready");
    Init();
    Draw();
  }
}

#else

void CancelMeshThread(void){
  
}

#endif



void mesh_event_handler (int event) {
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int       ib;
  static int n=0, p[100];

  if(CTX.threads_lock) return ;

  switch (event) {    

  case MESH_DELETE : 
    mai3d(&M, 0); 
    break;
    
  case MESH_1D : 
#ifdef _USETHREADS
    if(CTX.threads){
      XtSetSensitive(WID.G.Butt[6], 1);
      CTX.mesh.draw = 0; CTX.threads_lock = 1 ; MeshDim = 1 ; 
      //      pthread_mutex_init(&MeshMutex,NULL);
      //      pthread_mutex_lock(&MeshMutex);
      pthread_create(&MeshThread, NULL, StartMeshThread, NULL);
    }
    else
#endif
      mai3d(&M, 1); 
    break;
    
  case MESH_2D : 
#ifdef _USETHREADS
    if(CTX.threads){
      XtSetSensitive(WID.G.Butt[6], 1);
      CTX.mesh.draw = 0; CTX.threads_lock = 1 ; MeshDim = 2 ; 
      //      pthread_mutex_init(&MeshMutex,NULL);
      //      pthread_mutex_lock(&MeshMutex);
      pthread_create(&MeshThread, NULL, StartMeshThread, NULL);
    }
    else
#endif
      mai3d(&M, 2);
    break;    

  case MESH_3D : 
#ifdef _USETHREADS
    if(CTX.threads){
      XtSetSensitive(WID.G.Butt[6], 1);
      CTX.mesh.draw = 0; CTX.threads_lock = 1 ; MeshDim = 3 ; 
      //      pthread_mutex_init(&MeshMutex,NULL);
      //      pthread_mutex_lock(&MeshMutex);
      pthread_create(&MeshThread, NULL, StartMeshThread, NULL);
    }
    else
#endif
      mai3d(&M, 3); 
    break;


  case MESH_DEFINE_CHAR_LENGTH :
    n=0;
    while(1){
      Msg(STATUS,"Select Point ('e'=end, 'q'=quit)");
      ib = SelectEntity(ENT_POINT, &v,&c,&s);
      if(ib == 1){ /* left mouse butt */
        p[n++] = v->Num; 
      }
      if (ib == -1){ /* 'e' */
        if(n >= 1) {
          add_charlength(n,p,CTX.filename); break;
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
    break ;

  case MESH_DEFINE_RECOMBINE :
    n=0;
    while(1){
      Msg(STATUS,"Select Surface ('e'=end, 'q'=quit)");
      ib = SelectEntity(ENT_SURFACE, &v,&c,&s);
      if(ib == 1){ /* left mouse butt */
        p[n++] = s->Num; 
      }
      if (ib == -1){ /* 'e' */
        if(n >= 1) {
          add_recosurf(n,p,CTX.filename); break;
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
    break ;

  case MESH_DEFINE_TRSF_LINE :
  case MESH_DEFINE_TRSF_SURFACE :
  case MESH_DEFINE_TRSF_VOLUME :
    n=0;
    while(1){
      switch (event) {    
      case MESH_DEFINE_TRSF_LINE :
        Msg(STATUS,"Select Line ('e'=end, 'q'=quit)");
        ib = SelectEntity(ENT_LINE, &v,&c,&s);
        break ;
      case MESH_DEFINE_TRSF_SURFACE :
        Msg(STATUS,"Select Surface ('e'=end, 'q'=quit)");
        ib = SelectEntity(ENT_SURFACE, &v,&c,&s);
        break;
      case MESH_DEFINE_TRSF_VOLUME :
        ib = 1;
        break;
      }
      if(ib == 1){ /* left mouse butt */
        switch (event) {    
        case MESH_DEFINE_TRSF_LINE : p[n++] = c->Num ; break ;
        case MESH_DEFINE_TRSF_SURFACE : p[n++] = s->Num;
        case MESH_DEFINE_TRSF_VOLUME :
          while(1){
            Msg(STATUS,"Select Point ('e'=end, 'q'=quit)");
            ib = SelectEntity(ENT_POINT, &v,&c,&s);
            if(ib == 1){ /* left mouse butt */
              p[n++] = v->Num ;
            }
            if (ib == -1){ /* 'e' */
              switch (event) {    
              case MESH_DEFINE_TRSF_SURFACE :
                if(n == 3+1 || n == 4+1)
                  add_trsfsurf(n,p,CTX.filename); 
                else
                  Msg(INFO, "Wrong Number of Points for Transfinite Surface");
                break;
              case MESH_DEFINE_TRSF_VOLUME :
                if(n == 6 || n == 8)
                  add_trsfvol(n,p,CTX.filename);
                else
                  Msg(INFO, "Wrong Number of Points for Transfinite Volume");
                break;
              }
              n=0;
              ZeroHighlight(&M);
              Replot();
              break;
            }
            if(ib == 0){ /* 'q' */
              n=0 ;
              ZeroHighlight(&M);
              Replot();
              break;
            }
          }
          break ;
        }
      }
      if (ib == -1){ /* 'e' */
        if (event == MESH_DEFINE_TRSF_LINE){ 
          if(n >= 1) add_trsfline(n,p,CTX.filename);
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
    break ;

  case MESH_DEFINE_ATTRACTOR_POINT :
  case MESH_DEFINE_ATTRACTOR_LINE :
  case MESH_DEFINE_ATTRACTOR_SURFACE :
    Msg(WARNING, "Interactive Attractor Definition not done yet"); 
    break ;

  default : 
    Msg(WARNING, "Unkown Event in mesh_event_handler"); 
    break;
  }

  if(!CTX.threads){
    Msg(STATUS,"Ready");
    Init();
    Draw();
  }
}

/* ------------------------------------------------------------------------ 
    M e s h C b                                                       
   ------------------------------------------------------------------------ */

void MeshCb (Widget w, XtPointer client_data, XtPointer call_data){

  switch((long int)client_data){

  case MESH_TRSF_LINE_PTS  : strcpy(trsf_pts_text,XmTextGetString(w)); break;
  case MESH_TRSF_LINE_TYPE : strcpy(trsf_type_text,XmTextGetString(w)); break;
  case MESH_TRSF_VOL_NUM   : strcpy(trsf_vol_text,XmTextGetString(w)); break;
  case MESH_CHAR_LENGTH    : strcpy(char_length_text,XmTextGetString(w)); break;
  case MESH_ATTRACTOR_X    : strcpy(attrx_text,XmTextGetString(w)); break;
  case MESH_ATTRACTOR_Y    : strcpy(attry_text,XmTextGetString(w)); break;
  case MESH_ATTRACTOR_Z    : strcpy(attrz_text,XmTextGetString(w)); break;
  default :
    Msg(WARNING, "Unknown Event in MeshCb (%d)", (long int)client_data); 
    break;

  }
}
