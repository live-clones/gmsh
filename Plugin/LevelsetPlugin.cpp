// $Id: LevelsetPlugin.cpp,v 1.14 2001-08-09 21:15:30 remacle Exp $

#include "LevelsetPlugin.h"
#include "List.h"
#include "Views.h"
#include "Iso.h"

/// Includes are basdly designed, i prefer forward decls.
void prodve (double a[3], double b[3], double c[3]);
void prosca (double a[3], double b[3], double *c);
void norme (double a[3]);
int sys3x3 (double mat[3][3], double b[3], double res[3], double *det);

GMSH_LevelsetPlugin::GMSH_LevelsetPlugin()
{
  processed = 0;
  _ith_field_to_draw_on_the_iso = 0;
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
  int k,i,nb,edtet[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  double Xpi[6],Ypi[6],Zpi[6];
  Post_View *View;

  //   for all scalar simplices 

  if(v->NbSS)
    {
      View = BeginView(1);
      nb = List_Nbr(v->SS) / v->NbSS ;
      for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb)
	{
	  double levels[6],Xp[6],Yp[6],Zp[6],myVals[6];
	  double *X   = (double*)List_Pointer_Fast(v->SS,i);
	  double *Y   = (double*)List_Pointer_Fast(v->SS,i+4);
	  double *Z   = (double*)List_Pointer_Fast(v->SS,i+8);
	  double *VAL = (double*)List_Pointer_Fast(v->SS,i+12);
	  for(int j=0;j<4;j++)levels[j] = levelset(X[j],Y[j],Z[j],VAL[j]);
	  int nx = 0;
	  for(k=0;k<6;k++)
	    {
	      if(levels[edtet[k][0]] * levels[edtet[k][1]] <= 0.0)
		{		  
		  double coef = InterpolateIso(X,Y,Z,levels,0.0,
					       edtet[k][0],edtet[k][1],
					       &Xp[nx],&Yp[nx],&Zp[nx]); 
		  myVals[nx] = what_to_draw (Xp[nx],Yp[nx],Zp[nx],edtet[k][0],edtet[k][1],coef,VAL);
		  nx++;
		}
	    }
	  /*
	  if(nx == 4)
	    {
	      double xx =  Xp[3];
	      double yy =  Yp[3];
	      double zz =  Zp[3];
	      double vv =  myVals[3];
	      Xp[3] = Xp[2]; 
	      Yp[3] = Yp[2]; 
	      Zp[3] = Zp[2];
	      myVals[3] = myVals[2];
	      Xp[2] = xx;
	      Yp[2] = yy;
	      Zp[2] = zz;
	      myVals[2] = vv;
	    }
	  */
	  double v1[3] = {Xp[2]-Xp[0],Yp[2]-Yp[0],Zp[2]-Zp[0]};
	  double v2[3] = {Xp[1]-Xp[0],Yp[1]-Yp[0],Zp[1]-Zp[0]};
	  double gr[3];
	  double n[3],xx;
	  prodve(v1,v2,n);
	  norme(n);
	  gradSimplex(X,Y,Z,VAL,gr);      
	  prosca(gr,n,&xx);
	  
	  if(xx > 0){
	    for(k=0;k<nx;k++){
	      Xpi[k] = Xp[k];
	      Ypi[k] = Yp[k];
	      Zpi[k] = Zp[k];
	    }
	    for(k=0;k<nx;k++){
	      Xp[k] = Xpi[nx-k-1];
	      Yp[k] = Ypi[nx-k-1];
	      Zp[k] = Zpi[nx-k-1];	      
	    }
	  }
	  
	  if(nx == 3 || nx == 4)
	    {
	      for(k=0;k<3;k++)List_Add(View->ST, &Xp[k]);
	      for(k=0;k<3;k++)List_Add(View->ST, &Yp[k]);
	      for(k=0;k<3;k++)List_Add(View->ST, &Zp[k]);
	      for(k=0;k<3;k++)List_Add(View->ST, &myVals[k]);
	      View->NbST++;
	    }
	  if(nx == 4)
	    {	  
	      for(k=1;k<4;k++)List_Add(View->ST, &Xp[k %4]);
	      for(k=1;k<4;k++)List_Add(View->ST, &Yp[k % 4]);
	      for(k=1;k<4;k++)List_Add(View->ST, &Zp[k % 4]);
	      for(k=1;k<4;k++)List_Add(View->ST, &myVals[k %4]);
	      View->NbST++;
	    }
	}
      char name[1024],filename[1024];

      sprintf(name,"cut-%s",v->Name);
      sprintf(filename,"cut-%s",v->FileName);
      EndView(1, filename, name);
      
      Msg(INFO, "Created view '%s' (%d triangles)", name, View->NbST);
      processed = View;
      return View;
    }

  return 0;
}

double  GMSH_LevelsetPlugin::what_to_draw (double x, 
					   double y, 
					   double z, 
					   int p1, 
					   int p2, 
					   double coef, 
					   double *VAL) const
{
  int offset =  _ith_field_to_draw_on_the_iso * 4;
  // TEST JF, this would draw y coord on the iso
  //  return y;
  p2 += offset;
  p1 += offset;
  return coef * (VAL[p2] - VAL[p1]) + VAL[p1]; 
}






