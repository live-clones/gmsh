/* $Id: Volume.cpp,v 1.2 2000-11-23 14:11:32 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Interpolation.h"
#include "Context.h"

extern Context_T   CTX;

int TheVolume;

extern Mesh      *THEM;

void Draw_Curve_For_Volume (void *a, void *b){
  int     i,N;
  Curve  *c;
  Vertex  v;

  glLineWidth(2.);

  c = *(Curve**)a;

  if(CTX.render_mode == GMSH_SELECT){
    glLoadName(3);
    glPushName(TheVolume);
  }

  if(c->Typ == MSH_SEGM_LINE)
    N = List_Nbr(c->Control_Points);
  else
    N = 10;

  glBegin(GL_LINE_STRIP);
  for(i=0;i<N;i++){
    v = InterpolateCurve(c,0.2*(double)i/(double)(N-1),0);
    glVertex3d(v.Pos.X,v.Pos.Y,v.Pos.Z);
  }
  glEnd();

  glBegin(GL_LINE_STRIP);
  for(i=N-1;i>=0;i--){
    v = InterpolateCurve(c,1.-0.2*(double)i/(double)(N-1),0);
    glVertex3d(v.Pos.X,v.Pos.Y,v.Pos.Z);
  }
  glEnd();


  if(CTX.render_mode == GMSH_SELECT){
    glPopName ();
  }

  if((c)->ipar[3]){
    glLineWidth(1.);
  }

}


void DrawVolumes (Mesh *m){


}



