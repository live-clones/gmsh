// $Id: Skin.cpp,v 1.22 2004-02-03 22:36:39 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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

#include "Plugin.h"
#include "Skin.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"

extern Context_T CTX;

List_T *GMSH_SkinPlugin::_list = NULL;
Tree_T *GMSH_SkinPlugin::_skin = NULL;
int *GMSH_SkinPlugin::_nbList = NULL;
int GMSH_SkinPlugin::_nbNod = 0;
int GMSH_SkinPlugin::_nbComp = 0;
int GMSH_SkinPlugin::_nbTimeStep = 0;

StringXNumber SkinOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSkinPlugin()
  {
    return new GMSH_SkinPlugin();
  }
}

GMSH_SkinPlugin::GMSH_SkinPlugin()
{
  ;
}

void GMSH_SkinPlugin::getName(char *name) const
{
  strcpy(name, "Skin");
}

void GMSH_SkinPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Skin) extracts the skin (the boundary) of\n"
	 "the view 'iView'. If 'iView' < 0, the plugin is run\n"
	 "on the current view.\n"
	 "\n"
	 "Plugin(Skin) creates one new view.\n");
}

int GMSH_SkinPlugin::getNbOptions() const
{
  return sizeof(SkinOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SkinPlugin::getOption(int iopt)
{
  return &SkinOptions_Number[iopt];
}

void GMSH_SkinPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Skin failed...");
}

int GMSH_SkinPlugin::fcmpElm(const void *a, const void *b)
{
  Elm *e1 = (Elm *)a, *e2 = (Elm *)b;
  double s1, s2, TOL = CTX.lc * 1.e-12;
  int i;

  s1 = s2 = 0.0;
  for(i = 0; i < _nbNod; i++) {
    s1 += e1->coord[i];
    s2 += e2->coord[i];
  }
  if(s1 - s2 > TOL)
    return 1;
  else if(s1 - s2 < -TOL)
    return -1;
  s1 = s2 = 0.0;
  for(i = 0; i < _nbNod; i++) {
    s1 += e1->coord[_nbNod + i];
    s2 += e2->coord[_nbNod + i];
  }
  if(s1 - s2 > TOL)
    return 1;
  else if(s1 - s2 < -TOL)
    return -1;
  s1 = s2 = 0.0;
  for(i = 0; i < _nbNod; i++) {
    s1 += e1->coord[2 * _nbNod + i];
    s2 += e2->coord[2 * _nbNod + i];
  }
  if(s1 - s2 > TOL)
    return 1;
  else if(s1 - s2 < -TOL)
    return -1;

  return 0;
}

void GMSH_SkinPlugin::addInView(void *a, void *b)
{
  Elm *e = (Elm *)a;

  for(int i = 0; i < 3 * _nbNod; i++)
    List_Add(_list, &e->coord[i]);
  for(int ts = 0; ts < _nbTimeStep; ts++)
    for(int k = 0; k < _nbNod * _nbComp; k++)
      List_Add(_list, &e->val[_nbNod * _nbComp * ts + k]);
  Free(e->val);
  (*_nbList)++;
}

void GMSH_SkinPlugin::skinList(List_T *inList, int inNbList, 
			       int inNbNod, int inNbFac, int fxn[6][4])
{
  if(!inNbList)
    return;

  int nb = List_Nbr(inList) / inNbList;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    double *coord = (double *)List_Pointer_Fast(inList, i);
    double *val = (double *)List_Pointer_Fast(inList, i + 3 * inNbNod);
    for(int j = 0; j < inNbFac; j++) {
      Elm e, *pe;
      for(int k = 0; k < _nbNod; k++) {
	e.coord[k] = coord[fxn[j][k]]; // x
	e.coord[_nbNod + k] = coord[inNbNod + fxn[j][k]]; // y
	e.coord[2 * _nbNod + k] = coord[2 * inNbNod + fxn[j][k]]; // z
      }
      if(!(pe = (Elm *)Tree_PQuery(_skin, &e))) {
	e.val = (double *)Malloc(_nbNod * _nbComp * _nbTimeStep * sizeof(double));
	for(int k = 0; k < _nbNod; k++)
	  for(int ts = 0; ts < _nbTimeStep; ts++)
	    for(int n = 0; n < _nbComp; n++)
	      e.val[_nbNod * _nbComp * ts + _nbComp * k + n] =
		val[inNbNod * _nbComp * ts + _nbComp * fxn[j][k] + n];
        Tree_Add(_skin, &e);
      }
      else {
        Free(pe->val);
        Tree_Suppress(_skin, pe);
      }
    }
  }
}

Post_View *GMSH_SkinPlugin::execute(Post_View * v)
{
  int iView = (int)SkinOptions_Number[0].def;
  Post_View *vv;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(WARNING, "View[%d] does not exist", iView);
      return 0;
    }
  }

  _nbTimeStep = vv->NbTimeStep;

  Post_View *view = BeginView(1);

  int skinTri[6][4] = {{0,1,-1,-1}, {1,2,-1,-1}, {2,0,-1,-1}};
  int skinQua[6][4] = {{0,1,-1,-1}, {1,2,-1,-1}, {2,3,-1,-1}, {3,0,-1,-1}};
  int skinTet[6][4] = {{0,1,3,-1}, {0,2,1,-1}, {0,3,2,-1}, {1,2,3,-1}};
  int skinHex[6][4] = {{0,1,5,4}, {0,3,2,1}, {0,4,7,3},
		       {1,2,6,5}, {2,3,7,6}, {4,5,6,7}};
  int skinPri1[6][4] = {{0,1,4,3}, {0,3,5,2}, {1,2,5,4}};
  int skinPri2[6][4] = {{0,2,1,-1}, {3,4,5,-1}};
  int skinPyr1[6][4] = {{0,3,2,1}};
  int skinPyr2[6][4] = {{0,1,4,-1}, {0,4,3,-1}, {1,2,4,-1}, {2,3,4,-1}};

  // Generate lines
  _nbNod = 2;
  // scalar
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->SL; _nbList = &view->NbSL; _nbComp = 1;
  skinList(vv->ST, vv->NbST, 3, 3, skinTri);
  skinList(vv->SQ, vv->NbSQ, 4, 4, skinQua);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // vector
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->VL; _nbList = &view->NbVL; _nbComp = 3;
  skinList(vv->VT, vv->NbVT, 3, 3, skinTri);
  skinList(vv->VQ, vv->NbVQ, 4, 4, skinQua);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // tensor
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->TL; _nbList = &view->NbTL; _nbComp = 9;
  skinList(vv->TT, vv->NbTT, 3, 3, skinTri);
  skinList(vv->TQ, vv->NbTQ, 4, 4, skinQua);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);

  // Generate triangles
  _nbNod = 3;
  // scalar
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->ST; _nbList = &view->NbST; _nbComp = 1;
  skinList(vv->SS, vv->NbSS, 4, 4, skinTet);
  skinList(vv->SI, vv->NbSI, 6, 2, skinPri2);
  skinList(vv->SY, vv->NbSY, 5, 4, skinPyr2);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // vector
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->VT; _nbList = &view->NbVT; _nbComp = 3;
  skinList(vv->VS, vv->NbVS, 4, 4, skinTet);
  skinList(vv->VI, vv->NbVI, 6, 2, skinPri2);
  skinList(vv->VY, vv->NbVY, 5, 4, skinPyr2);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // tensor
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->TT; _nbList = &view->NbTT; _nbComp = 9;
  skinList(vv->TS, vv->NbTS, 4, 4, skinTet);
  skinList(vv->TI, vv->NbTI, 6, 2, skinPri2);
  skinList(vv->TY, vv->NbTY, 5, 4, skinPyr2);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);

  // Generate quads
  _nbNod = 4;
  // scalar
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->SQ; _nbList = &view->NbSQ; _nbComp = 1;
  skinList(vv->SH, vv->NbSH, 8, 6, skinHex);
  skinList(vv->SI, vv->NbSI, 6, 3, skinPri1);
  skinList(vv->SY, vv->NbSY, 5, 1, skinPyr1);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // vector
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->VQ; _nbList = &view->NbVQ; _nbComp = 3;
  skinList(vv->VH, vv->NbVH, 8, 6, skinHex);
  skinList(vv->VI, vv->NbVI, 6, 3, skinPri1);
  skinList(vv->VY, vv->NbVY, 5, 1, skinPyr1);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // tensor
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = view->TQ; _nbList = &view->NbTQ; _nbComp = 9;
  skinList(vv->TH, vv->NbTH, 8, 6, skinHex);
  skinList(vv->TI, vv->NbTI, 6, 3, skinPri1);
  skinList(vv->TY, vv->NbTY, 5, 1, skinPyr1);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);

  if(view->empty()) {
    RemoveViewByNumber(view->Num);
  }
  else{
    // copy time data
    for(int i = 0; i < List_Nbr(vv->Time); i++)
      List_Add(view->Time, List_Pointer(vv->Time, i));
    // finalize
    char name[1024], filename[1024];
    sprintf(name, "skin-%s", vv->Name);
    sprintf(filename, "skin-%s", vv->FileName);
    EndView(view, 1, filename, name);
  }

  return 0;
}
