// $Id: Post.cpp,v 1.33 2002-05-18 07:18:02 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Context.h"
#include "gl2ps.h"

extern Context_T   CTX;

static double      Raise[3][5];
static double      RaiseFactor[3];

// Give Value from Index

double GiveValueFromIndex_Lin(double ValMin, double ValMax, int NbIso, int Iso){
  if(NbIso==1) return (ValMax+ValMin)/2.;
  return ValMin + Iso*(ValMax-ValMin)/(NbIso-1.) ;
}

double GiveValueFromIndex_Log(double ValMin, double ValMax, int NbIso, int Iso){
  if(NbIso==1) return (ValMax+ValMin)/2.;
  if(ValMin <= 0.) return 0. ;
  return pow(10.,log10(ValMin)+Iso*(log10(ValMax)-log10(ValMin))/(NbIso-1.)) ;
}

double GiveValueFromIndex_DoubleLog(double ValMin, double ValMax, int NbIso, int Iso){
  if(NbIso==1) return (ValMax+ValMin)/2.;
  if(ValMin <= 0.) return 0. ;

  double Iso2 = Iso/2.;
  double NbIso2 = NbIso/2.;

  return pow(10.,log10(ValMin)+Iso2*(log10(ValMax)-log10(ValMin))/(NbIso2-1.)) ;

}

// Give Index From Value

int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso, double Val){
  if(ValMin==ValMax) return NbIso/2 ;
  return (int)((Val-ValMin)*(NbIso-1)/(ValMax-ValMin)) ;
}

int GiveIndexFromValue_Log(double ValMin, double ValMax, int NbIso, double Val){
  if(ValMin==ValMax) return NbIso/2 ;  
  if(ValMin <= 0.) return 0 ;
  return (int)((log10(Val)-log10(ValMin))*(NbIso-1)/(log10(ValMax)-log10(ValMin))) ;
}

int GiveIndexFromValue_DoubleLog(double ValMin, double ValMax, int NbIso, double Val){
  if(ValMin==ValMax) return NbIso/2 ;  
  if(ValMin <= 0.) return 0 ;
  return (int)((log10(Val)-log10(ValMin))*(NbIso-1)/(log10(ValMax)-log10(ValMin))) ;
}


// Color Palette

void Palette1(Post_View *v, int nbi, int i){ /* i in [0,nbi-1] */
  int index ;

  index = (nbi==1) ? 
    v->CT.size/2 :
    (int) (i/(double)(nbi-1)*(v->CT.size-1) + 0.5) ;

  glColor4ubv( (GLubyte *) &v->CT.table[index] );
}

void Palette2(Post_View *v,double min, double max, double val){ /* val in [min,max] */
  int index;  

  index = (min==max) ? 
    v->CT.size/2 :
    (int)( (val-min)/(max-min)*(v->CT.size-1) + 0.5);

  glColor4ubv((GLubyte *) &v->CT.table[index]);
}

void RaiseFill(int i, double Val, double ValMin, double Raise[3][5]){
  int j ;
  for(j=0 ; j<3 ; j++) Raise[j][i] = (Val-ValMin) * RaiseFactor[j] ;
}


// Draw Post routines

void Free_DisplayLists(void){
  Post_View     *v;
  for(int iView=0 ; iView<List_Nbr(CTX.post.list) ; iView++){
    v = (Post_View*)List_Pointer(CTX.post.list,iView);
    if(glIsList(v->Num)) glDeleteLists(v->Num,1);
  }
}

void Get_Coords(double Explode, double *Offset, int nbnod, 
		double *x1, double *y1, double *z1, 
		double *x2, double *y2, double *z2){
  int i;
  double xc=0., yc=0., zc=0.;

  if(Explode==1){
    for(i=0; i<nbnod; i++){
      x2[i] = x1[i]+Offset[0];
      y2[i] = y1[i]+Offset[1];
      z2[i] = z1[i]+Offset[2];
    }
  }
  else{
    for(i=0; i<nbnod; i++){
      xc += x1[i];
      yc += y1[i];
      zc += z1[i];
    }
    xc /= (double)nbnod;
    yc /= (double)nbnod;
    zc /= (double)nbnod;
    for(i=0; i<nbnod; i++){
      x2[i] = xc + Explode * (x1[i]-xc) + Offset[0];
      y2[i] = yc + Explode * (y1[i]-yc) + Offset[1];
      z2[i] = zc + Explode * (z1[i]-zc) + Offset[2];
    }
  }
}


void Draw_Post (void) {
  int            iView,i,j,k,nb;
  double         ValMin,ValMax,AbsMax,X[4],Y[4],Z[4];
  Post_View     *v;

  if(!CTX.post.list) return;

  if(!CTX.post.draw){ // draw only the bbox of the visible views
    for(iView=0 ; iView<List_Nbr(CTX.post.list) ; iView++){
      v = (Post_View*)List_Pointer(CTX.post.list,iView);
      if(v->Visible && v->Type==DRAW_POST_3D){ 
	glColor4ubv((GLubyte*)&CTX.color.fg);
	glBegin(GL_LINE_LOOP);
	glVertex3d(v->BBox[0], v->BBox[2], v->BBox[4]);
	glVertex3d(v->BBox[1], v->BBox[2], v->BBox[4]);
	glVertex3d(v->BBox[1], v->BBox[3], v->BBox[4]);
	glVertex3d(v->BBox[0], v->BBox[3], v->BBox[4]);
	glEnd();    
	glBegin(GL_LINE_LOOP);
	glVertex3d(v->BBox[0], v->BBox[2], v->BBox[5]);
	glVertex3d(v->BBox[1], v->BBox[2], v->BBox[5]);
	glVertex3d(v->BBox[1], v->BBox[3], v->BBox[5]);
	glVertex3d(v->BBox[0], v->BBox[3], v->BBox[5]);
	glEnd();    
	glBegin(GL_LINES);
	glVertex3d(v->BBox[0], v->BBox[2], v->BBox[4]);
	glVertex3d(v->BBox[0], v->BBox[2], v->BBox[5]);
	glVertex3d(v->BBox[1], v->BBox[2], v->BBox[4]);
	glVertex3d(v->BBox[1], v->BBox[2], v->BBox[5]);
	glVertex3d(v->BBox[1], v->BBox[3], v->BBox[4]);
	glVertex3d(v->BBox[1], v->BBox[3], v->BBox[5]);
	glVertex3d(v->BBox[0], v->BBox[3], v->BBox[4]);
	glVertex3d(v->BBox[0], v->BBox[3], v->BBox[5]);
	glEnd();    
      }
    }    
    return;
  }
  
  for(iView=0 ; iView<List_Nbr(CTX.post.list) ; iView++){

    v = (Post_View*)List_Pointer(CTX.post.list,iView);

    if(v->Visible && !v->Dirty){ 

      if(CTX.display_lists && !v->Changed && glIsList(v->Num)){

        glCallList(v->Num);

      }
      else{

        if(CTX.display_lists){
          if(glIsList(v->Num)) glDeleteLists(v->Num,1);
          Msg(DEBUG, "New Display List");
          glNewList(v->Num, GL_COMPILE_AND_EXECUTE);
        }

	glPointSize(v->PointSize); 
	gl2psPointSize(v->PointSize * CTX.print.eps_point_size_factor);

	glLineWidth(v->LineWidth); 
	gl2psLineWidth(v->LineWidth * CTX.print.eps_line_width_factor);

        if(v->Light)
          InitShading();
        else
          InitNoShading();

	if(v->ShowElement)
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
        case DRAW_POST_DOUBLELOGARITHMIC : 
          v->GIFV = GiveIndexFromValue_DoubleLog ;
          v->GVFI = GiveValueFromIndex_DoubleLog ;
          break;
        }
        
        AbsMax = DMAX(fabs(ValMin),fabs(ValMax));
        AbsMax = (AbsMax==0.) ? 1. : AbsMax;
        
        for(j=0;j<3;j++){
          RaiseFactor[j] = v->Raise[j] / AbsMax ;
          for(k=0;k<5;k++) Raise[j][k] = 0. ;
        }

	// Points

	if(v->Type==DRAW_POST_3D && v->NbSP && v->DrawPoints && v->DrawScalars){
	  nb = List_Nbr(v->SP) / v->NbSP ;
	  for(i = 0 ; i < List_Nbr(v->SP) ; i+=nb){
	    Get_Coords(1., v->Offset, 1, 
		       (double*)List_Pointer_Fast(v->SP,i), 
		       (double*)List_Pointer_Fast(v->SP,i+1), 
		       (double*)List_Pointer_Fast(v->SP,i+2), 
		       X, Y, Z);
	    Draw_ScalarPoint(v, ValMin, ValMax, Raise, X, Y, Z,
			     (double*)List_Pointer_Fast(v->SP,i+3));
	  }
	}
	if(v->NbVP && v->DrawPoints && v->DrawVectors){
	  nb = List_Nbr(v->VP) / v->NbVP ;
	  for(i = 0 ; i < List_Nbr(v->VP) ; i+=nb){
	    Get_Coords(1., v->Offset, 1, 
		       (double*)List_Pointer_Fast(v->VP,i), 
		       (double*)List_Pointer_Fast(v->VP,i+1), 
		       (double*)List_Pointer_Fast(v->VP,i+2), 
		       X, Y, Z);
	    Draw_VectorPoint(v, ValMin, ValMax, Raise, X, Y, Z,
			     (double*)List_Pointer_Fast(v->VP,i+3));
	  }
	}
	if(v->NbTP && v->DrawPoints && v->DrawTensors){
	  nb = List_Nbr(v->TP) / v->NbTP ;
	  for(i = 0 ; i < List_Nbr(v->TP) ; i+=nb){
	    Get_Coords(1., v->Offset, 1, 
		       (double*)List_Pointer_Fast(v->TP,i), 
		       (double*)List_Pointer_Fast(v->TP,i+1), 
		       (double*)List_Pointer_Fast(v->TP,i+2), 
		       X, Y, Z);
	    Draw_TensorPoint(v, ValMin, ValMax, Raise, X, Y, Z,
			     (double*)List_Pointer_Fast(v->TP,i+3));
	  }
	}

	// Lines
	
	if(v->NbSL && v->DrawLines && v->DrawScalars){
	  nb = List_Nbr(v->SL) / v->NbSL ;
	  for(i = 0 ; i < List_Nbr(v->SL) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 2, 
		       (double*)List_Pointer_Fast(v->SL,i), 
		       (double*)List_Pointer_Fast(v->SL,i+2), 
		       (double*)List_Pointer_Fast(v->SL,i+4), 
		       X, Y, Z);
	    Draw_ScalarLine(v, ValMin, ValMax, Raise, X, Y, Z,
			    (double*)List_Pointer_Fast(v->SL,i+6));
	  }
	}
	if(v->NbVL && v->DrawLines && v->DrawVectors){
	  nb = List_Nbr(v->VL) / v->NbVL ;
	  for(i = 0 ; i < List_Nbr(v->VL) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 2, 
		       (double*)List_Pointer_Fast(v->VL,i),
		       (double*)List_Pointer_Fast(v->VL,i+2),
		       (double*)List_Pointer_Fast(v->VL,i+4),
		       X, Y, Z);
	    Draw_VectorLine(v, ValMin, ValMax, Raise, X, Y, Z,
			    (double*)List_Pointer_Fast(v->VL,i+6));
	  }
	}
	if(v->NbTL && v->DrawLines && v->DrawTensors){
	  nb = List_Nbr(v->TL) / v->NbTL ;
	  for(i = 0 ; i < List_Nbr(v->TL) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 2, 
		       (double*)List_Pointer_Fast(v->TL,i), 
		       (double*)List_Pointer_Fast(v->TL,i+2), 
		       (double*)List_Pointer_Fast(v->TL,i+4), 
		       X, Y, Z);
	    Draw_TensorLine(v, ValMin, ValMax, Raise, X, Y, Z,
			    (double*)List_Pointer_Fast(v->TL,i+6));
	  }
	}
	
	// Triangles
	
	if(v->NbST && v->DrawTriangles && v->DrawScalars){
	  nb = List_Nbr(v->ST) / v->NbST ;
	  if(v->Light && v->SmoothNormals && v->Changed && v->IntervalsType != DRAW_POST_ISO){
	    Msg(DEBUG, "Preprocessing of triangle normals in view %d", v->Num);
	    for(i = 0 ; i < List_Nbr(v->ST) ; i+=nb){
	      Get_Coords(v->Explode, v->Offset, 3, 
			 (double*)List_Pointer_Fast(v->ST,i), 
			 (double*)List_Pointer_Fast(v->ST,i+3), 
			 (double*)List_Pointer_Fast(v->ST,i+6), 
			 X, Y, Z);
	      Draw_ScalarTriangle(v, 1, ValMin, ValMax, Raise, X, Y, Z,
				  (double*)List_Pointer_Fast(v->ST,i+9));
	    }
	  }
	  for(i = 0 ; i < List_Nbr(v->ST) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 3, 
		       (double*)List_Pointer_Fast(v->ST,i), 
		       (double*)List_Pointer_Fast(v->ST,i+3), 
		       (double*)List_Pointer_Fast(v->ST,i+6), 
		       X, Y, Z);
	    Draw_ScalarTriangle(v, 0, ValMin, ValMax, Raise, X, Y, Z,
				(double*)List_Pointer_Fast(v->ST,i+9));
	  }
	}
	if(v->NbVT && v->DrawTriangles && v->DrawVectors){
	  nb = List_Nbr(v->VT) / v->NbVT ;
	  for(i = 0 ; i < List_Nbr(v->VT) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 3, 
		       (double*)List_Pointer_Fast(v->VT,i),
		       (double*)List_Pointer_Fast(v->VT,i+3),
		       (double*)List_Pointer_Fast(v->VT,i+6),
		       X, Y, Z);
	    Draw_VectorTriangle(v, ValMin, ValMax, Raise, X, Y, Z,
				(double*)List_Pointer_Fast(v->VT,i+9));
	  }
	}
	if(v->NbTT && v->DrawTriangles && v->DrawTensors){
	  nb = List_Nbr(v->TT) / v->NbTT ;
	  for(i = 0 ; i < List_Nbr(v->TT) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 3, 
		       (double*)List_Pointer_Fast(v->TT,i), 
		       (double*)List_Pointer_Fast(v->TT,i+3), 
		       (double*)List_Pointer_Fast(v->TT,i+6), 
		       X, Y, Z);
	    Draw_TensorTriangle(v, ValMin, ValMax, Raise, X, Y, Z,
				(double*)List_Pointer_Fast(v->TT,i+9));
	  }
	}
	
	// Tetrahedra
	
	if(v->NbSS && v->DrawTetrahedra && v->DrawScalars){
	  nb = List_Nbr(v->SS) / v->NbSS ;
	  if(v->Light && v->SmoothNormals && v->Changed && v->IntervalsType != DRAW_POST_ISO){
	    Msg(DEBUG, "Preprocessing of tets normals in view %d", v->Num);
	    for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb){
	      Get_Coords(v->Explode, v->Offset, 4, 
			 (double*)List_Pointer_Fast(v->SS,i), 
			 (double*)List_Pointer_Fast(v->SS,i+4), 
			 (double*)List_Pointer_Fast(v->SS,i+8), 
			 X, Y, Z);
	      Draw_ScalarTetrahedron(v, 1, ValMin, ValMax, Raise, X, Y, Z,
				     (double*)List_Pointer_Fast(v->SS,i+12));
	    }
	  }
	  for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 4, 
		       (double*)List_Pointer_Fast(v->SS,i), 
		       (double*)List_Pointer_Fast(v->SS,i+4), 
		       (double*)List_Pointer_Fast(v->SS,i+8), 
		       X, Y, Z);
	    Draw_ScalarTetrahedron(v, 0, ValMin, ValMax, Raise, X, Y, Z,
				   (double*)List_Pointer_Fast(v->SS,i+12));
	  }
	}
	if(v->NbVS && v->DrawTetrahedra && v->DrawVectors){
	  nb = List_Nbr(v->VS) / v->NbVS ;
	  for(i = 0 ; i < List_Nbr(v->VS) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 4,
		       (double*)List_Pointer_Fast(v->VS,i), 
		       (double*)List_Pointer_Fast(v->VS,i+4), 
		       (double*)List_Pointer_Fast(v->VS,i+8), 
		       X, Y, Z);
	    Draw_VectorTetrahedron(v, ValMin, ValMax, Raise, X, Y, Z,
				   (double*)List_Pointer_Fast(v->VS,i+12));
	  }
	}
	if(v->NbTS && v->DrawTetrahedra && v->DrawTensors){
	  nb = List_Nbr(v->TS) / v->NbTS ;
	  for(i = 0 ; i < List_Nbr(v->TS) ; i+=nb){
	    Get_Coords(v->Explode, v->Offset, 4,
		       (double*)List_Pointer_Fast(v->TS,i), 
		       (double*)List_Pointer_Fast(v->TS,i+4), 
		       (double*)List_Pointer_Fast(v->TS,i+8), 
		       X, Y, Z);
	    Draw_TensorTetrahedron(v, ValMin, ValMax, Raise, X, Y, Z,
				   (double*)List_Pointer_Fast(v->TS,i+12));
	  }
	}

	if(v->DrawStrings){
	  glColor4ubv((GLubyte*)&CTX.color.text);
	  Draw_Text2D3D(3, v->TimeStep, v->NbT3, v->T3D, v->T3C);
	}

        if(CTX.display_lists) glEndList();

	v->Changed=0;

	if(v->ShowElement || v->ArrowType == DRAW_POST_DISPLACEMENT)
	  glDisable(GL_POLYGON_OFFSET_FILL) ;
        
      }
      
    }

  }

  // go back to default shading for the scale
  InitNoShading();

}

