// $Id: Skin.cpp,v 1.13 2002-05-18 07:56:51 geuzaine Exp $
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

#include "Plugin.h"
#include "Skin.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"

extern Context_T CTX;

StringXNumber SkinOptions_Number[] = {
  { GMSH_FULLRC, "iView" , NULL , -1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSkinPlugin ()
  {
    return new GMSH_SkinPlugin();
  }
}

GMSH_SkinPlugin::GMSH_SkinPlugin()
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
	 "Gets the skin (i.e. the boundary) of a view,\n"
	 "eliminating all interior drawing.\n"
	 "Script name: Plugin(Skin).\n");
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


static List_T * List;
static int    * NbList, NbNod, NbComp, NbTime;

typedef struct{
  double Coord[9];
  double *Val;
} Elm;

static int fcmpElm(const void *a, const void *b){
  Elm *e1=(Elm*)a, *e2=(Elm*)b;
  double s1, s2, TOL=CTX.lc*1.e-12;
  int i;
  
  s1 = s2 = 0.0 ;  
  for(i=0;i<NbNod-1;i++){ s1 += e1->Coord[i]; s2 += e2->Coord[i]; }
  if(s1-s2 > TOL) return 1; else if(s1-s2 < -TOL) return -1;
  s1 = s2 = 0.0 ;
  for(i=0;i<NbNod-1;i++){ s1 += e1->Coord[NbNod-1+i]; s2 += e2->Coord[NbNod-1+i]; }
  if(s1-s2 > TOL) return 1; else if(s1-s2 < -TOL) return -1;
  s1 = s2 = 0.0 ;
  for(i=0;i<NbNod-1;i++){ s1 += e1->Coord[2*(NbNod-1)+i]; s2 += e2->Coord[2*(NbNod-1)+i]; }
  if(s1-s2 > TOL) return 1; else if(s1-s2 < -TOL) return -1;

  return 0;
}

static void getElm(int *Nod, double *Coord, double *Val, Elm *Elm){
  int i, j, k;
  Elm->Val = (double*)Malloc((NbNod-1)*NbComp*NbTime*sizeof(double));
  for(i=0; i<NbNod-1; i++) Elm->Coord[i] = Coord[Nod[i]]; //x
  for(i=0; i<NbNod-1; i++) Elm->Coord[NbNod-1+i] = Coord[NbNod + Nod[i]]; //y
  for(i=0; i<NbNod-1; i++) Elm->Coord[2*(NbNod-1)+i] = Coord[2*NbNod + Nod[i]]; //z
  for(i=0; i<NbTime; i++)
    for(j=0; j<NbNod-1; j++) 
      for(k=0; k<NbComp; k++)
	Elm->Val[(NbNod-1)*NbComp*i+NbComp*j+k] = 
	  Val[NbNod*NbComp*i+NbComp*Nod[j]+k];
}

static void addInView(void *a, void *b){
  int i, k;
  Elm *e = (Elm*)a;
  for(i=0; i<3*(NbNod-1); i++) List_Add(List, &e->Coord[i]);
  for(i=0; i<NbTime; i++)
    for(k=0;k<(NbNod-1)*NbComp;k++)
      List_Add(List, &e->Val[(NbNod-1)*NbComp*i+k]);
  Free(e->Val);
  (*NbList)++;
}

static void skinSimplex(List_T *Simp, int NbSimp){
  double *Coords, *Vals;
  int i, j;
  int FacesTet[4][3] = {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};
  int EdgesTri[3][2] = {{0,1},{1,2},{2,0}};
  Elm e, *pe;

  Tree_T * Skin = Tree_Create(sizeof(Elm), fcmpElm);
  for(i = 0 ; i < List_Nbr(Simp) ; i+=NbSimp){
    Coords = (double*)List_Pointer_Fast(Simp,i);
    Vals = (double*)List_Pointer_Fast(Simp,i+3*NbNod);
    for(j=0 ; j<NbNod ; j++){
      getElm(NbNod == 4 ? FacesTet[j] : EdgesTri[j],Coords,Vals,&e);
      if(!(pe=(Elm*)Tree_PQuery(Skin, &e)))
	Tree_Add(Skin, &e);
      else{
	Free(pe->Val);
	Free(e.Val);
	Tree_Suppress(Skin, &e);
      }
    }
  }
  Tree_Action(Skin, addInView);
  Tree_Delete(Skin);
}

Post_View *GMSH_SkinPlugin::execute (Post_View *v)
{
  Post_View *vv, *View;

  int iView = (int)SkinOptions_Number[0].def;

  if(v && iView < 0)
    vv = v;
  else{
    if(!v && iView < 0) iView = 0;
    if(!(vv = (Post_View*)List_Pointer_Test(CTX.post.list,iView))){
      Msg(WARNING,"View[%d] does not exist",iView);
      return 0;
    }
  }

  if(vv->NbSS || vv->NbVS || vv->NbST || vv->NbVT){
    View = BeginView(1);
    NbTime = vv->NbTimeStep;
    if(vv->NbSS){
      List = View->ST; NbList = &View->NbST; NbNod = 4; NbComp = 1;
      skinSimplex(vv->SS, List_Nbr(vv->SS) / vv->NbSS);
    }
    if(vv->NbVS){
      List = View->VT; NbList = &View->NbVT; NbNod = 4; NbComp = 3;
      skinSimplex(vv->VS, List_Nbr(vv->VS) / vv->NbVS) ;
    }
    if(vv->NbST){
      List = View->SL; NbList = &View->NbSL; NbNod = 3; NbComp = 1;
      skinSimplex(vv->ST, List_Nbr(vv->ST) / vv->NbST);
    }
    if(vv->NbVT){
      List = View->VL; NbList = &View->NbVL; NbNod = 3; NbComp = 3;
      skinSimplex(vv->VT, List_Nbr(vv->VT) / vv->NbVT) ;
    }
    if(View->NbST || View->NbVT || View->NbSL || View->NbVL){
      char name[1024], filename[1024];
      sprintf(name,"skin-%s",vv->Name);
      sprintf(filename,"skin-%s",vv->FileName);
      EndView(View, 1, filename, name);
      Msg(INFO, "Created view '%s'", name);
      return View;
    }
    else
      FreeView(View->Index);
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
