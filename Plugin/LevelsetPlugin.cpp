// $Id: LevelsetPlugin.cpp,v 1.24 2002-05-20 18:28:30 geuzaine Exp $
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "LevelsetPlugin.h"
#include "List.h"
#include "Views.h"
#include "Iso.h"
#include "Numeric.h"

GMSH_LevelsetPlugin::GMSH_LevelsetPlugin()
{
  processed = 0;
  _ith_field_to_draw_on_the_iso = 0;
  _orientation = ORIENT_NONE; 
  _ref[0] = _ref[1] = _ref[2] = 0.;
  strcpy (OutputFileName,"levelset.pos");
}

void GMSH_LevelsetPlugin::Save ()
{
  if(processed){
    Msg(INFO, "Writing file '%s'", OutputFileName);
    Write_View(0, processed, OutputFileName);
    Msg(INFO, "Levelset ouput complete '%s'", OutputFileName);
    Msg(STATUS2, "Wrote '%s'", OutputFileName);
  }
}

void GMSH_LevelsetPlugin::Run () 
{ 
  execute (0);
}

Post_View *GMSH_LevelsetPlugin::execute (Post_View *v)
{
  /*
    This plugin creates a new view which is the result of
    a cut of the actual view with a levelset.
   */
  int    k,i,j,nb,edtet[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  double *X, *Y, *Z, *Vals, levels[6], coef;
  double Xp[6], Yp[6], Zp[6], myVals[6];
  double Xpi[6], Ypi[6], Zpi[6], myValsi[6];
  Post_View *View;

  // for all scalar tets

  if(v->NbSS){
    View = BeginView(1);
    nb = List_Nbr(v->SS) / v->NbSS ;
    for(i=0 ; i<List_Nbr(v->SS) ; i+=nb){
      X = (double*)List_Pointer_Fast(v->SS,i);
      Y = (double*)List_Pointer_Fast(v->SS,i+4);
      Z = (double*)List_Pointer_Fast(v->SS,i+8);
      Vals = (double*)List_Pointer_Fast(v->SS,i+12);
      for(j=0 ; j<4 ; j++)
	levels[j] = levelset(X[j],Y[j],Z[j],Vals[j]);
      int nx = 0;
      for(k=0 ; k<6 ; k++){
	if(levels[edtet[k][0]] * levels[edtet[k][1]] <= 0.0){		  
	  coef = InterpolateIso(X,Y,Z,levels,0.0,
				edtet[k][0],edtet[k][1],
				&Xp[nx],&Yp[nx],&Zp[nx]); 
	  myVals[nx] = what_to_draw (Xp[nx],Yp[nx],Zp[nx],
				     edtet[k][0],edtet[k][1],coef,Vals);
	  nx++;
	}
      }
      
      if(nx == 4){
	double xx = Xp[3];
	double yy = Yp[3];
	double zz = Zp[3];
	double vv = myVals[3];
	Xp[3] = Xp[2]; 
	Yp[3] = Yp[2]; 
	Zp[3] = Zp[2];
	myVals[3] = myVals[2];
	Xp[2] = xx;
	Yp[2] = yy;
	Zp[2] = zz;
	myVals[2] = vv;
      }

      if(nx == 3 || nx == 4){      
	double v1[3] = {Xp[2]-Xp[0],Yp[2]-Yp[0],Zp[2]-Zp[0]};
	double v2[3] = {Xp[1]-Xp[0],Yp[1]-Yp[0],Zp[1]-Zp[0]};
	double gr[3];
	double n[3],test;
	prodve(v1,v2,n);

	switch(_orientation){
	case ORIENT_MAP:
	  gradSimplex(X,Y,Z,Vals,gr);      
	  prosca(gr,n,&test);
	  break;
	case ORIENT_PLANE:
	  prosca(n,_ref,&test);
	  break;
	case ORIENT_SPHERE:
	  gr[0] = Xp[0]-_ref[0];
	  gr[1] = Yp[0]-_ref[1];
	  gr[2] = Zp[0]-_ref[2];
	  prosca(gr,n,&test);
	  break;
	default:
	  test = 0.;
	  break;
	}
	
	if(test>0){
	  for(k=0;k<nx;k++){
	    Xpi[k] = Xp[k];
	    Ypi[k] = Yp[k];
	    Zpi[k] = Zp[k];
	    myValsi[k] = myVals[k];
	  }
	  for(k=0;k<nx;k++){
	    Xp[k] = Xpi[nx-k-1];
	    Yp[k] = Ypi[nx-k-1];
	    Zp[k] = Zpi[nx-k-1];	      
	    myVals[k] = myValsi[nx-k-1];	      
	  }
	}
	
	for(k=0 ; k<3 ; k++) List_Add(View->ST, &Xp[k]);
	for(k=0 ; k<3 ; k++) List_Add(View->ST, &Yp[k]);
	for(k=0 ; k<3 ; k++) List_Add(View->ST, &Zp[k]);
	for(k=0 ; k<3 ; k++) List_Add(View->ST, &myVals[k]);
	View->NbST++;

	if(nx == 4){	  
	  for(k=2 ; k<5 ; k++) List_Add(View->ST, &Xp[k % 4]);
	  for(k=2 ; k<5 ; k++) List_Add(View->ST, &Yp[k % 4]);
	  for(k=2 ; k<5 ; k++) List_Add(View->ST, &Zp[k % 4]);
	  for(k=2 ; k<5 ; k++) List_Add(View->ST, &myVals[k % 4]);
	  View->NbST++;
	}
      }
    }

    char name[1024],filename[1024];
    sprintf(name,"cut-%s",v->Name);
    sprintf(filename,"cut-%s",v->FileName);
    EndView(View, 1, filename, name);
    
    Msg(INFO, "Created view '%s' (%d triangles)", name, View->NbST);
    processed = View;
    return View;
  }
  
  return 0;
}

double  GMSH_LevelsetPlugin::what_to_draw (double x, double y, double z, 
					   int p1, int p2, 
					   double coef, double *Vals) const
{
  // This very dangerous, since there is no test to check if enough
  // values are avaiable in the view
  int offset =  _ith_field_to_draw_on_the_iso * 4;

  // TEST JF, this would draw y coord on the iso
  //  return y;

  p2 += offset;
  p1 += offset;
  return coef * (Vals[p2] - Vals[p1]) + Vals[p1]; 
}






