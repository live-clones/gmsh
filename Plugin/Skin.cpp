// $Id: Skin.cpp,v 1.35 2007-09-11 14:01:55 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Skin.h"
#include "Malloc.h"
#include "Context.h"

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
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Skin) extracts the skin (the boundary) of\n"
	 "the view `iView'. If `iView' < 0, the plugin is run\n"
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

PView *GMSH_SkinPlugin::execute(PView *v)
{
  int iView = (int)SkinOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  _nbTimeStep = data1->getNumTimeSteps();

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
  _list = data2->SL; _nbList = &data2->NbSL; _nbComp = 1;
  skinList(data1->ST, data1->NbST, 3, 3, skinTri);
  skinList(data1->SQ, data1->NbSQ, 4, 4, skinQua);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // vector
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->VL; _nbList = &data2->NbVL; _nbComp = 3;
  skinList(data1->VT, data1->NbVT, 3, 3, skinTri);
  skinList(data1->VQ, data1->NbVQ, 4, 4, skinQua);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // tensor
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->TL; _nbList = &data2->NbTL; _nbComp = 9;
  skinList(data1->TT, data1->NbTT, 3, 3, skinTri);
  skinList(data1->TQ, data1->NbTQ, 4, 4, skinQua);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);

  // Generate triangles
  _nbNod = 3;
  // scalar
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->ST; _nbList = &data2->NbST; _nbComp = 1;
  skinList(data1->SS, data1->NbSS, 4, 4, skinTet);
  skinList(data1->SI, data1->NbSI, 6, 2, skinPri2);
  skinList(data1->SY, data1->NbSY, 5, 4, skinPyr2);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // vector
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->VT; _nbList = &data2->NbVT; _nbComp = 3;
  skinList(data1->VS, data1->NbVS, 4, 4, skinTet);
  skinList(data1->VI, data1->NbVI, 6, 2, skinPri2);
  skinList(data1->VY, data1->NbVY, 5, 4, skinPyr2);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // tensor
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->TT; _nbList = &data2->NbTT; _nbComp = 9;
  skinList(data1->TS, data1->NbTS, 4, 4, skinTet);
  skinList(data1->TI, data1->NbTI, 6, 2, skinPri2);
  skinList(data1->TY, data1->NbTY, 5, 4, skinPyr2);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);

  // Generate quads
  _nbNod = 4;
  // scalar
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->SQ; _nbList = &data2->NbSQ; _nbComp = 1;
  skinList(data1->SH, data1->NbSH, 8, 6, skinHex);
  skinList(data1->SI, data1->NbSI, 6, 3, skinPri1);
  skinList(data1->SY, data1->NbSY, 5, 1, skinPyr1);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // vector
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->VQ; _nbList = &data2->NbVQ; _nbComp = 3;
  skinList(data1->VH, data1->NbVH, 8, 6, skinHex);
  skinList(data1->VI, data1->NbVI, 6, 3, skinPri1);
  skinList(data1->VY, data1->NbVY, 5, 1, skinPyr1);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);
  // tensor
  _skin = Tree_Create(sizeof(Elm), fcmpElm);
  _list = data2->TQ; _nbList = &data2->NbTQ; _nbComp = 9;
  skinList(data1->TH, data1->NbTH, 8, 6, skinHex);
  skinList(data1->TI, data1->NbTI, 6, 3, skinPri1);
  skinList(data1->TY, data1->NbTY, 5, 1, skinPyr1);
  Tree_Action(_skin, addInView);
  Tree_Delete(_skin);

  for(int i = 0; i < List_Nbr(data1->Time); i++)
    List_Add(data2->Time, List_Pointer(data1->Time, i));
  data2->setName(data1->getName() + "_Skin");
  data2->setFileName(data1->getName() + "_Skin.pos");
  data2->finalize();

  return v2;
}
