#include "CutPlane.h"
#include "List.h"
#include "Views.h"
#include "Iso.h"
/*
  Plugin Entry : GMSH_RegisterPlugin
 */
extern "C"{
GMSH_Plugin *GMSH_RegisterPlugin ()
{
  return new GMSH_CutPlanePlugin (1.0,0.0,0.0,0.0);
}
}


GMSH_CutPlanePlugin::GMSH_CutPlanePlugin(double A, double B, double C, double D)
  :a(A),b(B),c(C),d(D)
{
}

void GMSH_CutPlanePlugin::getName(char *name) const
{
  strcpy(name,"Cut Plane");
}

void GMSH_CutPlanePlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author,"J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright,"DGR (www.multiphysics.com)");
  strcpy(help_text,"This Plugins cuts a view with a plane a x + b y + c z + d = 0");
}

int GMSH_CutPlanePlugin::getNbOptions() const
{
  return 4;
}

void GMSH_CutPlanePlugin:: GetOption (int iopt, char *optionName, void *optionValue) const
{
  // geuz, t'es le specialiste des options, regarde comment
  // on pourrait faire Plugin.CutPlane.a = 1.0;
}

void GMSH_CutPlanePlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"CutPlane Failed...");
}

Post_View *GMSH_CutPlanePlugin::execute (Post_View *v)
{
  int i,nb,edtet[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  /* for all scalar simplices */
  if(v->NbSS)
    {
      nb = List_Nbr(v->ST) / v->NbST ;
      for(i = 0 ; i < List_Nbr(v->ST) ; i+=nb)
	{
	  double levels[4],Xp[4],Yp[4],Zp[4];
	  double *X   = (double*)List_Pointer_Fast(v->SS,i);
	  double *Y   = (double*)List_Pointer_Fast(v->SS,i+4);
	  double *Z   = (double*)List_Pointer_Fast(v->SS,i+8);
	  for(int j=0;j<4;j++)levels[j] = levelset(X[j],Y[j],Z[j]);
	  double *VAL = (double*)List_Pointer_Fast(v->SS,i+12);
	  int nx = 0;
	  for(int k=0;k<6;k++)
	    {
	      if(levels[edtet[k][0]] * levels[edtet[k][1]] <= 0.0)
		{
		  InterpolateIso(X,Y,Z,levels,0.0,
				 edtet[k][0],edtet[k][1],
				 &Xp[nx],&Yp[nx],&Zp[nx]); 
		  nx++;
		}
	    }
	  if(nx == 3)
	    {
	    }
	}
    }
  return 0;
}

void GMSH_CutPlanePlugin::SetOption (char *optionName, void *optionValue)
{
}

double GMSH_CutPlanePlugin :: levelset (double x, double y, double z)
{
  return a * x + b * y + c * z + d;
}

