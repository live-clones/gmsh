// $Id: Post.cpp,v 1.13 2001-02-04 10:23:56 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Context.h"

extern Context_T   CTX;

static double      Raise[3][5];
static double      RaiseFactor[3];

/* ------------------------------------------------------------------------
    Give Value from Index
   ------------------------------------------------------------------------ */

double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso, int Iso){
  if(NbIso==1) return (ValMax+ValMin)/2.;
  return ValMin + Iso*(ValMax-ValMin)/(NbIso-1.) ;
}

double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso, int Iso){
  if(NbIso==1) return (ValMax+ValMin)/2.;
  if(ValMin <= 0.) return 0. ;
  return pow(10.,log10(ValMin)+Iso*(log10(ValMax)-log10(ValMin))/(NbIso-1.)) ;
}


/* ------------------------------------------------------------------------
    Give Index From Value
   ------------------------------------------------------------------------ */

int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso, double Val){
  if(ValMin==ValMax) return NbIso/2 ;
  return (int)((Val-ValMin)*(NbIso-1)/(ValMax-ValMin)) ;
}

int GiveIndexFromValue_Log(double ValMin, double ValMax, int NbIso, double Val){
  if(ValMin==ValMax) return NbIso/2 ;  
  if(ValMin <= 0.) return 0 ;
  return (int)((log10(Val)-log10(ValMin))*(NbIso-1)/(log10(ValMax)-log10(ValMin))) ;
}


/* ------------------------------------------------------------------------
    Color Palette
   ------------------------------------------------------------------------ */

void Palette(Post_View *v, int nbi, int i){ /* i in [0,nbi-1] */
  int index ;

  index = (nbi==1) ? 
    v->CT.size/2 :
    (int) (i/(double)(nbi-1)*(v->CT.size-1) + 0.5) ;

  glColor4ubv( (GLubyte *) &v->CT.table[index] );
}

void Palette2(Post_View *v,double min, double max, double val){ /* val in [min,max] */
  int index;  

  index = (int)( (val-min)/(max-min)*(v->CT.size-1) + 0.5);

  glColor4ubv((GLubyte *) &v->CT.table[index]);
}

void RaiseFill(int i, double Val, double ValMin, double Raise[3][5]){
  int j ;
  for(j=0 ; j<3 ; j++) Raise[j][i] = (Val-ValMin) * RaiseFactor[j] ;
}


/* ------------------------------------------------------------------------ 
    D r a w _ P o s t                                                       
   ------------------------------------------------------------------------ */

void Draw_Post (void) {
  int            iView,i,j,k,nb;
  double         ValMin,ValMax,AbsMax;
  Post_View     *v;

  if(!Post_ViewList) return;
  
  for(iView=0 ; iView<List_Nbr(Post_ViewList) ; iView++){

    v = (Post_View*)List_Pointer(Post_ViewList,iView);

    if(v->Visible){ 

      if(CTX.display_lists && !v->Changed && glIsList(v->Num)){

        glCallList(v->Num);

      }
      else{

        if(CTX.display_lists){
          if(glIsList(v->Num)) glDeleteLists(v->Num,1);
          // Msg(STATUS2, "New Display List");
          glNewList(v->Num, GL_COMPILE_AND_EXECUTE);
        }

        if(v->Light && v->IntervalsType != DRAW_POST_ISO){
          InitShading();
        }
        else{
          InitNoShading();
        }

	if(v->ShowElement || v->ArrowType == DRAW_POST_DISPLACEMENT)
	  glEnable(GL_POLYGON_OFFSET_FILL) ;

        // force this
        if(v->IntervalsType == DRAW_POST_CONTINUOUS){
          glShadeModel(GL_SMOOTH); 
	  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        }
	else{// there is a bug in CutTriangle2D!! See Iso.cpp
	  glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	}

        switch(v->RangeType){
        case DRAW_POST_DEFAULT : ValMin = v->Min ; ValMax = v->Max ; break;
        case DRAW_POST_CUSTOM  : ValMin = v->CustomMin ; ValMax = v->CustomMax ; break;
        }
        
        switch(v->ScaleType){
        case DRAW_POST_LINEAR : 
          v->GIFV = GiveIndexFromValue_Lin ;
          v->GVFI = GiveValueFromIndex_Lin ;
          break;
        case DRAW_POST_LOGARITHMIC : 
          v->GIFV = GiveIndexFromValue_Log ;
          v->GVFI = GiveValueFromIndex_Log ;
          break;
        }
        
        AbsMax = DMAX(fabs(ValMin),fabs(ValMax));
        AbsMax = (AbsMax==0.) ? 1. : AbsMax;
        
        for(j=0;j<3;j++){
          RaiseFactor[j] = v->Raise[j] / AbsMax ;
          for(k=0;k<5;k++) Raise[j][k] = 0. ;
        }

	// Points

	if(v->NbSP){
	  nb = List_Nbr(v->SP) / v->NbSP ;
	  for(i = 0 ; i < List_Nbr(v->SP) ; i+=nb)
	    Draw_ScalarPoint(v, ValMin, ValMax, Raise,
			     (double*)List_Pointer_Fast(v->SP,i),
			     (double*)List_Pointer_Fast(v->SP,i+1),
			     (double*)List_Pointer_Fast(v->SP,i+2),
			     (double*)List_Pointer_Fast(v->SP,i+3));
	}
	if(v->NbVP){
	  nb = List_Nbr(v->VP) / v->NbVP ;
	  for(i = 0 ; i < List_Nbr(v->VP) ; i+=nb)
	    Draw_VectorPoint(v, ValMin, ValMax, Raise,
			     (double*)List_Pointer_Fast(v->VP,i),
			     (double*)List_Pointer_Fast(v->VP,i+1),
			     (double*)List_Pointer_Fast(v->VP,i+2),
			     (double*)List_Pointer_Fast(v->VP,i+3));
	}
	if(v->NbTP){
	  nb = List_Nbr(v->TP) / v->NbTP ;
	  for(i = 0 ; i < List_Nbr(v->TP) ; i+=nb)
	    Draw_TensorPoint(v, ValMin, ValMax, Raise,
			     (double*)List_Pointer_Fast(v->TP,i),
			     (double*)List_Pointer_Fast(v->TP,i+1),
			     (double*)List_Pointer_Fast(v->TP,i+2),
			     (double*)List_Pointer_Fast(v->TP,i+3));
	}

	// Lines
	
	if(v->NbSL){
	  nb = List_Nbr(v->SL) / v->NbSL ;
	  for(i = 0 ; i < List_Nbr(v->SL) ; i+=nb)
	    Draw_ScalarLine(v, ValMin, ValMax, Raise,
			    (double*)List_Pointer_Fast(v->SL,i),
			    (double*)List_Pointer_Fast(v->SL,i+2),
			    (double*)List_Pointer_Fast(v->SL,i+4),
			    (double*)List_Pointer_Fast(v->SL,i+6));
	}
	if(v->NbVL){
	  nb = List_Nbr(v->VL) / v->NbVL ;
	  for(i = 0 ; i < List_Nbr(v->VL) ; i+=nb)
	    Draw_VectorLine(v, ValMin, ValMax, Raise,
			    (double*)List_Pointer_Fast(v->VL,i),
			    (double*)List_Pointer_Fast(v->VL,i+2),
			    (double*)List_Pointer_Fast(v->VL,i+4),
			    (double*)List_Pointer_Fast(v->VL,i+6));
	}
	if(v->NbTL){
	  nb = List_Nbr(v->TL) / v->NbTL ;
	  for(i = 0 ; i < List_Nbr(v->TL) ; i+=nb)
	    Draw_VectorLine(v, ValMin, ValMax, Raise,
			    (double*)List_Pointer_Fast(v->TL,i),
			    (double*)List_Pointer_Fast(v->TL,i+2),
			    (double*)List_Pointer_Fast(v->TL,i+4),
			    (double*)List_Pointer_Fast(v->TL,i+6));
	}
	
	// Triangles
	
	if(v->NbST){
	  nb = List_Nbr(v->ST) / v->NbST ;
	  for(i = 0 ; i < List_Nbr(v->ST) ; i+=nb)
	    Draw_ScalarTriangle(v, ValMin, ValMax, Raise,
				(double*)List_Pointer_Fast(v->ST,i),
				(double*)List_Pointer_Fast(v->ST,i+3),
				(double*)List_Pointer_Fast(v->ST,i+6),
				(double*)List_Pointer_Fast(v->ST,i+9));
	}
	if(v->NbVT){
	  nb = List_Nbr(v->VT) / v->NbVT ;
	  for(i = 0 ; i < List_Nbr(v->VT) ; i+=nb)
	    Draw_VectorTriangle(v, ValMin, ValMax, Raise,
				(double*)List_Pointer_Fast(v->VT,i),
				(double*)List_Pointer_Fast(v->VT,i+3),
				(double*)List_Pointer_Fast(v->VT,i+6),
				(double*)List_Pointer_Fast(v->VT,i+9));
	}
	if(v->NbTT){
	  nb = List_Nbr(v->TT) / v->NbTT ;
	  for(i = 0 ; i < List_Nbr(v->TT) ; i+=nb)
	    Draw_TensorTriangle(v, ValMin, ValMax, Raise,
				(double*)List_Pointer_Fast(v->TT,i),
				(double*)List_Pointer_Fast(v->TT,i+3),
				(double*)List_Pointer_Fast(v->TT,i+6),
				(double*)List_Pointer_Fast(v->TT,i+9));
	}
	
	// Tetrahedra

	/*
	  Modif Jf :
	  
	     IsoSurfaces are really better rendered with smooth shading.
	     My idea is first to transform the scalar simplex map on a
	     scalar triangle map. This map has to be changed each time 
	     the number of iso-surfaces is changed.
	 */
	
	if(v->NbSS){
	  nb = List_Nbr(v->SS) / v->NbSS ;
	  for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb)
	    Draw_ScalarTetrahedron(v, 1, ValMin, ValMax, Raise,
				   (double*)List_Pointer_Fast(v->SS,i),
				   (double*)List_Pointer_Fast(v->SS,i+4),
				   (double*)List_Pointer_Fast(v->SS,i+8),
				   (double*)List_Pointer_Fast(v->SS,i+12));
	  for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb)
	    Draw_ScalarTetrahedron(v, 0, ValMin, ValMax, Raise,
				   (double*)List_Pointer_Fast(v->SS,i),
				   (double*)List_Pointer_Fast(v->SS,i+4),
				   (double*)List_Pointer_Fast(v->SS,i+8),
				   (double*)List_Pointer_Fast(v->SS,i+12));
	}
	if(v->NbVS){
	  nb = List_Nbr(v->VS) / v->NbVS ;
	  for(i = 0 ; i < List_Nbr(v->VS) ; i+=nb)
	    Draw_VectorTetrahedron(v, ValMin, ValMax, Raise,
				   (double*)List_Pointer_Fast(v->VS,i),
				   (double*)List_Pointer_Fast(v->VS,i+4),
				   (double*)List_Pointer_Fast(v->VS,i+8),
				   (double*)List_Pointer_Fast(v->VS,i+12));
	}
	if(v->NbTS){
	  nb = List_Nbr(v->TS) / v->NbTS ;
	  for(i = 0 ; i < List_Nbr(v->TS) ; i+=nb)
	    Draw_TensorTetrahedron(v, ValMin, ValMax, Raise,
				   (double*)List_Pointer_Fast(v->TS,i),
				   (double*)List_Pointer_Fast(v->TS,i+4),
				   (double*)List_Pointer_Fast(v->TS,i+8),
				   (double*)List_Pointer_Fast(v->TS,i+12));
	}


        if(CTX.display_lists){
          glEndList();
          v->Changed=0;
        }

	if(v->ShowElement || v->ArrowType == DRAW_POST_DISPLACEMENT)
	  glDisable(GL_POLYGON_OFFSET_FILL) ;
        
      }
      
    }

  }

  /* revenir au shading par defaut, pour l'echelle */
  InitNoShading();

}

