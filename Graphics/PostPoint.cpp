
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"

extern Context_T   CTX;
extern double      LC;

int GiveIndexFromValue_Lin(double ValMin, double ValMax, int NbIso, double Val) ;

void Draw_Post_Point(Post_View *View, Post_Point *PP, 
		     double ValMin, double ValMax, double Raise[3][5]){      

  int      i;
  double   d,dx,dy,dz,fact;
	  
  switch(PP->Type){	    

  case DRAW_POST_SCALAR:	    	    
    d = PP->V[View->TimeStep];  
    if(d>=ValMin && d<=ValMax){      
      Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));
      glBegin(GL_POINTS);
      glVertex3d(PP->X, PP->Y, PP->Z);
      glEnd();
    }
    break;
    
  case DRAW_POST_VECTOR:	    

    if(View->ArrowType == DRAW_POST_DISPLACEMENT){
      fact = View->ArrowScale/100. ;
      glColor4ubv((GLubyte*)&CTX.color.fg);
      glBegin(GL_POINTS);
      glVertex3d(fact*PP->V[3*View->TimeStep],
		 fact*PP->V[3*View->TimeStep+1],
		 fact*PP->V[3*View->TimeStep+2]);
      glEnd();
      if(View->TimeStep){
	glBegin(GL_LINE_STRIP);
	for(i=0 ; i<View->TimeStep+1 ; i++)
	  glVertex3d(fact*PP->V[3*(View->TimeStep-i)],
		     fact*PP->V[3*(View->TimeStep-i)+1],
		     fact*PP->V[3*(View->TimeStep-i)+2]);
	glEnd();
      }
      break;
    }

    dx = PP->V[3*View->TimeStep];  
    dy = PP->V[3*View->TimeStep+1];
    dz = PP->V[3*View->TimeStep+2];
    d = sqrt(dx*dx+dy*dy+dz*dz);
    
    if(d!=0.0 && d>=ValMin && d<=ValMax){
      
      Palette(View,View->NbIso,View->GIFV(ValMin,ValMax,View->NbIso,d));

      fact = 2.e-4 * LC * View->ArrowScale/View->Max ;
      
      if(View->ScaleType == DRAW_POST_LOGARITHMIC && ValMin>0){
	dx /= d ; dy /= d ; dz /= d ;
	d = log10(d/ValMin) ; 
	dx *= d ; dy *= d ; dz *= d ;
      }

      RaiseFill(0, d, ValMin, Raise);

      Draw_Vector(View->ArrowType, View->IntervalsType!=DRAW_POST_ISO, 
		  PP->X, PP->Y, PP->Z,
		  fact*d, fact*dx, fact*dy, fact*dz,
		  View->Offset, Raise);
    }
    break;
    
  case DRAW_POST_TENSOR :
    break;
    
  }
}

