#include "LevelsetPlugin.h"
#include "List.h"
#include "Views.h"
#include "Iso.h"

// that's the bad part of the story ...
extern Post_View *ActualView;

Post_View *GMSH_LevelsetPlugin::execute (Post_View *v)
{
  /*
    This plugin creates a new view which is the result of
    a cut of the actual view with a levelset.
   */
  int k,i,nb,edtet[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  //   for all scalar simplices 
  if(v->NbSS)
    {
      BeginView(1,0);
      nb = List_Nbr(v->SS) / v->NbSS ;
      for(i = 0 ; i < List_Nbr(v->SS) ; i+=nb)
	{
	  double levels[6],Xp[6],Yp[6],Zp[6],myVals[6];
	  double *X   = (double*)List_Pointer_Fast(v->SS,i);
	  double *Y   = (double*)List_Pointer_Fast(v->SS,i+4);
	  double *Z   = (double*)List_Pointer_Fast(v->SS,i+8);
	  for(int j=0;j<4;j++)levels[j] = levelset(X[j],Y[j],Z[j]);
	  double *VAL = (double*)List_Pointer_Fast(v->SS,i+12);
	  int nx = 0;
	  for(k=0;k<6;k++)
	    {
	      if(levels[edtet[k][0]] * levels[edtet[k][1]] <= 0.0)
		{
		  double coef = InterpolateIso(X,Y,Z,levels,0.0,
					       edtet[k][0],edtet[k][1],
					       &Xp[nx],&Yp[nx],&Zp[nx]); 
		  myVals[nx] = coef * (VAL[edtet[k][1]] - VAL[edtet[k][0]])
		    + VAL[edtet[k][0]]; 
		  nx++;
		}
	    }
	  if(nx == 3 || nx == 4)
	    {
	      for(k=0;k<3;k++)List_Add(ActualView->ST, &Xp[k]);
	      for(k=0;k<3;k++)List_Add(ActualView->ST, &Yp[k]);
	      for(k=0;k<3;k++)List_Add(ActualView->ST, &Zp[k]);
	      for(k=0;k<3;k++)List_Add(ActualView->ST, &myVals[k]);
	      ActualView->NbST++;
	    }
	  if(nx == 4)
	    {
	      double xx =  Xp[3];
	      double yy =  Yp[3];
	      double zz =  Zp[3];
	      Xp[3] = Xp[2]; 
	      Yp[3] = Yp[2]; 
	      Zp[3] = Zp[2];
	      Xp[2] = xx;
	      Yp[2] = yy;
	      Zp[2] = zz;
	      for(k=1;k<4;k++)List_Add(ActualView->ST, &Xp[k %4]);
	      for(k=1;k<4;k++)List_Add(ActualView->ST, &Yp[k % 4]);
	      for(k=1;k<4;k++)List_Add(ActualView->ST, &Zp[k % 4]);
	      for(k=1;k<4;k++)List_Add(ActualView->ST, &myVals[k %4]);
	      ActualView->NbST++;
	    }
	}
      char name[1024],filename[1024];
      sprintf(name,"cut-%s",v->Name);
      sprintf(filename,"cut-%s",v->FileName);
      EndView(1, 0, filename, name);
      return ActualView;
    }
  return 0;
}








