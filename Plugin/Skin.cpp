// $Id: Skin.cpp,v 1.5 2001-08-06 11:00:26 geuzaine Exp $

#include "Plugin.h"
#include "Skin.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber SkinOptions_Number[] = {
  { GMSH_FULLRC, "iView" , NULL , -1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSkinPlugin ()
  {
    return new GMSH_SkinPlugin ((int)SkinOptions_Number[0].def);
  }
}


GMSH_SkinPlugin::GMSH_SkinPlugin(int a)
  :iView(a)
{
}

void GMSH_SkinPlugin::getName(char *name) const
{
  strcpy(name,"Skin");
}

void GMSH_SkinPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text, 
	 "Gets the skin of a 3D view (eliminates all interior drawing).\n"
	 "Script name: Plugin(Skin).");
}

int GMSH_SkinPlugin::getNbOptions() const
{
  return sizeof(SkinOptions_Number)/sizeof(StringXNumber);
}

StringXNumber *GMSH_SkinPlugin:: GetOption (int iopt)
{
  return &SkinOptions_Number[iopt];
}

void GMSH_SkinPlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"Skin failed...");
}

extern List_T *Post_ViewList;

struct elm{
  int nbnod;
  double coord[9];
  double val[3];
};

int fcmp_elm(const void *a, const void *b){
  struct elm *e1, *e2 ;
  double s1, s2, TOL=CTX.lc*1.e-6 ;
  int i;
  
  e1 = (struct elm*)a; e2 = (struct elm*)b;

  s1 = s2 = 0.0 ;  
  for(i=0;i<e1->nbnod;i++){ s1 += e1->coord[i]; s2 += e2->coord[i]; }
  if(s1-s2 > TOL) return 1; else if(s1-s2 < -TOL) return -1;

  s1 = s2 = 0.0 ;
  for(i=0;i<e1->nbnod;i++){ s1 += e1->coord[e1->nbnod+i]; s2 += e2->coord[e1->nbnod+i]; }
  if(s1-s2 > TOL) return 1; else if(s1-s2 < -TOL) return -1;

  s1 = s2 = 0.0 ;
  for(i=0;i<e1->nbnod;i++){ s1 += e1->coord[2*e1->nbnod+i]; s2 += e2->coord[2*e1->nbnod+i]; }
  if(s1-s2 > TOL) return 1; else if(s1-s2 < -TOL) return -1;

  return 0;
}

void get_face(int *nod, int nbnod, int nbcomp, 
	      double *C, double *V, double Cp[9], double Vp[3]){
  int i, j;
  for(i=0; i<nbnod; i++) Cp[i] = C[nod[i]]; //x
  for(i=0; i<nbnod; i++) Cp[nbnod+i] = C[(nbnod+1) + nod[i]]; //y
  for(i=0; i<nbnod; i++) Cp[2*nbnod+i] = C[2*(nbnod+1) + nod[i]]; //z
  for(i=0; i<nbnod; i++) 
    for(j=0; j<nbcomp; j++) Vp[nbcomp*i+j] = V[nbcomp*nod[i]+j]; //vals
}

static Post_View *View;

void addSTinView(void *a, void *b){
  int k;
  struct elm *elm = (struct elm*)a;
  for(k=0;k<9;k++)List_Add(View->ST, &elm->coord[k]);
  for(k=0;k<3;k++)List_Add(View->ST, &elm->val[k]);
  View->NbST++;
}

Post_View *GMSH_SkinPlugin::execute (Post_View *v)
{
  Post_View *vv;
  double *C, *V;
  int faces_tet[4][3] = {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};
  int i, j, nb;
  struct elm elm;
  int iView = (int)SkinOptions_Number[0].def;

  if(v && iView < 0)
    vv = v;
  else{
    if(!v && iView < 0) iView = 0;
    if(!(vv = (Post_View*)List_Pointer_Test(Post_ViewList,iView))){
      Msg(WARNING,"View[%d] does not exist",iView);
      return 0;
    }
  }

  if(vv->NbSS){
    View = BeginView(1);
    Tree_T * skin = Tree_Create(sizeof(struct elm), fcmp_elm);
    nb = List_Nbr(vv->SS) / vv->NbSS ;

    for(i = 0 ; i < List_Nbr(vv->SS) ; i+=nb){
      C = (double*)List_Pointer_Fast(vv->SS,i);
      V = (double*)List_Pointer_Fast(vv->SS,i+12);
      
      for(j=0 ; j<4 ; j++){//for each face
	get_face(faces_tet[j],3,1,C,V,elm.coord,elm.val);
	elm.nbnod = 3;
	if(!Tree_PQuery(skin, &elm))
	  Tree_Add(skin, &elm);
	else
	  Tree_Suppress(skin, &elm);
      }
    }

    Tree_Action(skin, addSTinView);
    Tree_Delete(skin);
    char name[1024],filename[1024];
    sprintf(name,"skin-%s",vv->Name);
    sprintf(filename,"skin-%s",vv->FileName);
    EndView(1, filename, name);
    Msg(INFO, "Created view '%s' (%d triangles)", name, View->NbST);
    return View;
  }

  return 0;
}

void GMSH_SkinPlugin::Run ()
{
  execute(0);
}

void GMSH_SkinPlugin::Save ()
{
}
