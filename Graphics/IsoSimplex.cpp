#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Iso.h"
#include "Context.h"
#include "Views.h"
#include "Numeric.h"

extern Context_T   CTX;

// compute the gradient of a linear interpolation in a tetrahedron


void EnhanceSimplexPolygon (Post_View *View,
			    int nb, // nb of points in polygon 
			    double *Xp, // x positions
			    double *Yp, // y positions
			    double *Zp, // z positions
			    double *Valp, // values at points
			    double *X, // x positions of the simplex
			    double *Y, // y positions of the simplex
			    double *Z, // z posistions of the simplex
			    double *Val, // values at simplex points
			    double *norms, // output : normals at points
			    int preproNormals  // do we compute normals or do we get them
			    ){
  /*
    3 possibilities for quads
      -) 0,2,5,3
      -) 0,1,5,4
      -) 1,2,4,3
      in all cases, simply invert the 2 last ones
      for having the quads ordered      
   */
  int i;
  double Xpi[6],Ypi[6],Zpi[6];

  if(nb == 4){
    double xx =  Xp[3];
    double yy =  Yp[3];
    double zz =  Zp[3];
    Xp[3] = Xp[2]; 
    Yp[3] = Yp[2]; 
    Zp[3] = Zp[2];
    Xp[2] = xx;
    Yp[2] = yy;
    Zp[2] = zz;
  }

  /*
    for having a nice isosurface, we should have n . grad v > 0
    n = normal to the polygon
    v = unknown field we wanna draw
   */

  if(!View->Light){
    norms = NULL; // we don't need to compute these
    return;
  }

  double v1[3] = {Xp[2]-Xp[0],Yp[2]-Yp[0],Zp[2]-Zp[0]};
  double v2[3] = {Xp[1]-Xp[0],Yp[1]-Yp[0],Zp[1]-Zp[0]};
  double gr[3];
  double n[3],xx;
  prodve(v1,v2,n);
  //norme(n);  not necessary since GL_NORMALIZE is enabled
  gradSimplex(X,Y,Z,Val,gr);      
  prosca(gr,n,&xx);
  
  if(xx > 0){
    for(i=0;i<nb;i++){
      Xpi[i] = Xp[i];
      Ypi[i] = Yp[i];
      Zpi[i] = Zp[i];
    }
    for(i=0;i<nb;i++){
      Xp[i] = Xpi[nb-i-1];
      Yp[i] = Ypi[nb-i-1];
      Zp[i] = Zpi[nb-i-1];	      
    }
  }
  else{
    n[0] = -n[0];
    n[1] = -n[1];
    n[2] = -n[2];
  }
  
  if(View->SmoothNormals){
    if(preproNormals){
      for(i=0;i<nb;i++){
	View->add_normal(Xp[i],Yp[i],Zp[i],n[0],n[1],n[2]);
      }
      return;
    }
    else{
      for(i=0;i<nb;i++){
	norms[3*i] = n[0];
	norms[3*i+1] = n[1];
	norms[3*i+2] = n[2];
	if(!View->get_normal(Xp[i],Yp[i],Zp[i],norms[3*i],norms[3*i+1],norms[3*i+2])){
	  //Msg(WARNING, "Oups, did not find smoothed normal");
	}	      
      }	  
    }
  }
  else{
    for(i=0;i<nb;i++){
      norms[3*i] = n[0];
      norms[3*i+1] = n[1];
      norms[3*i+2] = n[2];
    }
  }

}


void IsoSimplex( Post_View *View, 
		 int preproNormals,
		 double *X, double *Y, double *Z, double *Val, 
		 double V, double Vmin, double Vmax, 
		 double Raise[3][5]){
  int    nb;
  double Xp[6],Yp[6],Zp[6],PVals[6];
  double norms[12];

  if(V != Vmax){
    nb = 0;
    if((Val[0] > V && Val[1] <= V) || (Val[1] > V && Val[0] <= V)){
      InterpolateIso(X,Y,Z,Val,V,0,1,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[0] > V && Val[2] <= V) || (Val[2] > V && Val[0] <= V)){
      InterpolateIso(X,Y,Z,Val,V,0,2,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[0] > V && Val[3] <= V) || (Val[3] > V && Val[0] <= V)){
      InterpolateIso(X,Y,Z,Val,V,0,3,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[1] > V && Val[2] <= V) || (Val[2] > V && Val[1] <= V)){
      InterpolateIso(X,Y,Z,Val,V,1,2,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[1] > V && Val[3] <= V) || (Val[3] > V && Val[1] <= V)){
      InterpolateIso(X,Y,Z,Val,V,1,3,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[2] > V && Val[3] <= V) || (Val[3] > V && Val[2] <= V)){
      InterpolateIso(X,Y,Z,Val,V,2,3,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
  }
  else{
    nb=0;
    if((Val[0] < V && Val[1] <= V) || (Val[1] < V && Val[0] <= V)){
      InterpolateIso(X,Y,Z,Val,V,0,1,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[0] < V && Val[2] <= V) || (Val[2] < V && Val[0] <= V)){
      InterpolateIso(X,Y,Z,Val,V,0,2,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[0] < V && Val[3] <= V) || (Val[3] < V && Val[0] <= V)){
      InterpolateIso(X,Y,Z,Val,V,0,3,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[1] < V && Val[2] <= V) || (Val[2] < V && Val[1] <= V)){
      InterpolateIso(X,Y,Z,Val,V,1,2,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[1] < V && Val[3] <= V) || (Val[3] < V && Val[1] <= V)){
      InterpolateIso(X,Y,Z,Val,V,1,3,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
    if((Val[2] < V && Val[3] <= V) || (Val[3] < V && Val[2] <= V)){
      InterpolateIso(X,Y,Z,Val,V,2,3,&Xp[nb],&Yp[nb],&Zp[nb]); nb++;
    }
  }

  if(nb < 3)return;

  EnhanceSimplexPolygon (View, nb, Xp, Yp, Zp, PVals, X, Y, Z, Val, norms, preproNormals);

  if(preproNormals)return;

  if(nb == 3) 
    Draw_Triangle(Xp,Yp,Zp,norms,Raise,View->Light);
  else if(nb == 4)
    Draw_Quadrangle(Xp,Yp,Zp,norms,Raise,View->Light);  
}

