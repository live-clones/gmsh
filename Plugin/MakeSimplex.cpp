// $Id: MakeSimplex.cpp,v 1.2 2007-09-04 13:47:05 remacle Exp $
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

#include "Plugin.h"
#include "MakeSimplex.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber MakeSimplexOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMakeSimplexPlugin()
  {
    return new GMSH_MakeSimplexPlugin();
  }
}

GMSH_MakeSimplexPlugin::GMSH_MakeSimplexPlugin()
{
  ;
}

void GMSH_MakeSimplexPlugin::getName(char *name) const
{
  strcpy(name, "Make Simplex");
}

void GMSH_MakeSimplexPlugin::getInfos(char *author, char *copyright,
				      char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(MakeSimplex) decomposes all non-\n"
	 "simplectic elements (quadrangles, prisms,\n"
	 "hexahedra, pyramids) in the view `iView' into\n"
	 "simplices (triangles, tetrahedra). If `iView' < 0,\n"
	 "the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(MakeSimplex) is executed\n"
	 "in-place.\n");
}

int GMSH_MakeSimplexPlugin::getNbOptions() const
{
  return sizeof(MakeSimplexOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MakeSimplexPlugin::getOption(int iopt)
{
  return &MakeSimplexOptions_Number[iopt];
}

void GMSH_MakeSimplexPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "MakeSimplex failed...");
}

static void decomposeList(Post_View *v, int nbNod, int nbComp,
			  List_T **listIn, int *nbIn, List_T *listOut, int *nbOut)
{
  double xNew[4], yNew[4], zNew[4];
  double *valNew = new double[v->NbTimeStep * nbComp * nbNod];
  MakeSimplex dec(nbNod, nbComp, v->NbTimeStep);

  if(!(*nbIn))
    return;

  v->Changed = 1;

  int nb = List_Nbr(*listIn) / (*nbIn);
  for(int i = 0; i < List_Nbr(*listIn); i += nb){
    double *x = (double *)List_Pointer(*listIn, i);
    double *y = (double *)List_Pointer(*listIn, i + nbNod);
    double *z = (double *)List_Pointer(*listIn, i + 2 * nbNod);
    double *val = (double *)List_Pointer(*listIn, i + 3 * nbNod); 
    for(int j = 0; j < dec.numSimplices(); j++){
      dec.decompose(j, x, y, z, val, xNew, yNew, zNew, valNew);
      for(int k = 0; k < dec.numSimplexNodes(); k++)
	List_Add(listOut, &xNew[k]);
      for(int k = 0; k < dec.numSimplexNodes(); k++)
	List_Add(listOut, &yNew[k]);
      for(int k = 0; k < dec.numSimplexNodes(); k++)
	List_Add(listOut, &zNew[k]);
      for(int k = 0; k < dec.numSimplexNodes()*v->NbTimeStep*nbComp; k++)
	List_Add(listOut, &valNew[k]);
      (*nbOut)++;
    }
  }

  delete [] valNew;

  List_Reset(*listIn);
  *nbIn = 0;
}

Post_View *GMSH_MakeSimplexPlugin::execute(Post_View * v)
{
  int iView = (int)MakeSimplexOptions_Number[0].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  // Bail out if the view is an alias or if other views duplicate it
  if(v1->AliasOf || v1->Links) {
    Msg(GERROR, "MakeSimplex cannot be applied to an aliased view");
    return 0;
  }

  // quads
  decomposeList(v1, 4, 1, &v1->SQ, &v1->NbSQ, v1->ST, &v1->NbST);
  decomposeList(v1, 4, 3, &v1->VQ, &v1->NbVQ, v1->VT, &v1->NbVT);
  decomposeList(v1, 4, 9, &v1->TQ, &v1->NbTQ, v1->TT, &v1->NbTT);
		          
  // hexas	          
  decomposeList(v1, 8, 1, &v1->SH, &v1->NbSH, v1->SS, &v1->NbSS);
  decomposeList(v1, 8, 3, &v1->VH, &v1->NbVH, v1->VS, &v1->NbVS);
  decomposeList(v1, 8, 9, &v1->TH, &v1->NbTH, v1->TS, &v1->NbTS);
		          
  // prisms	          
  decomposeList(v1, 6, 1, &v1->SI, &v1->NbSI, v1->SS, &v1->NbSS);
  decomposeList(v1, 6, 3, &v1->VI, &v1->NbVI, v1->VS, &v1->NbVS);
  decomposeList(v1, 6, 9, &v1->TI, &v1->NbTI, v1->TS, &v1->NbTS);
		          
  // pyramids	          
  decomposeList(v1, 5, 1, &v1->SY, &v1->NbSY, v1->SS, &v1->NbSS);
  decomposeList(v1, 5, 3, &v1->VY, &v1->NbVY, v1->VS, &v1->NbVS);
  decomposeList(v1, 5, 9, &v1->TY, &v1->NbTY, v1->TS, &v1->NbTS);

  return v1;
}

// Utility class 

MakeSimplex::MakeSimplex(int numNodes, int numComponents, int numTimeSteps)
  : _numNodes(numNodes), _numComponents(numComponents), _numTimeSteps(numTimeSteps) 
{
  ; 
}

int MakeSimplex::numSimplices()
{
  switch(_numNodes) {
  case 4: return 2; // quad -> 2 tris
  case 5: return 2; // pyramid -> 2 tets
  case 6: return 3; // prism -> 3 tets
  case 8: return 6; // hexa -> 6 tets
  }
  return 0;
}

int MakeSimplex::numSimplexNodes()
{
  if(_numNodes == 4)
    return 3; // quad -> tris
  else
    return 4; // all others -> tets
}

void MakeSimplex::reorder(int map[4], int n,
			  double *x, double *y, double *z, double *val,
			  double *xn, double *yn, double *zn, double *valn)
{
  for(int i = 0; i < n; i++) {
    xn[i] = x[map[i]];
    yn[i] = y[map[i]];
    zn[i] = z[map[i]];
  }

  int map2[4] = {map[0], map[1], map[2], map[3]};
#if 0
  // make sure to create tets with positive volume?
  if(n == 4){ // tets
    double mat[3][3];
    mat[0][0] = xn[1] - xn[0]; mat[0][1] = xn[2] - xn[0]; mat[0][2] = xn[3] - xn[0];
    mat[1][0] = yn[1] - yn[0]; mat[1][1] = yn[2] - yn[0]; mat[1][2] = yn[3] - yn[0];
    mat[2][0] = zn[1] - zn[0]; mat[2][1] = zn[2] - zn[0]; mat[2][2] = zn[3] - zn[0];
    if(det3x3(mat) < 0.){
      map2[0] = map[1];
      map2[1] = map[0];
      xn[0] = x[map2[0]];
      yn[0] = y[map2[0]];
      zn[0] = z[map2[0]];
      xn[1] = x[map2[1]];
      yn[1] = y[map2[1]];
      zn[1] = z[map2[1]];
    }
  }
#endif

  for(int ts = 0; ts < _numTimeSteps; ts++)
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < _numComponents; j++)
	valn[ts*n*_numComponents + i*_numComponents + j] = 
	  val[ts*_numNodes*_numComponents + map2[i]*_numComponents + j];
  }
}

void MakeSimplex::decompose(int num, 
			    double *x, double *y, double *z, double *val,
			    double *xn, double *yn, double *zn, double *valn)
{
  int quadTri[2][4] = {{0,1,2,-1}, {0,2,3,-1}};
  int hexaTet[6][4] = {{0,1,3,7}, {0,4,1,7}, {1,4,5,7}, {1,2,3,7}, {1,6,2,7}, {1,5,6,7}};
  int prisTet[3][4] = {{0,1,2,4}, {0,2,4,5}, {0,3,4,5}};
  int pyraTet[2][4] = {{0,1,3,4}, {1,2,3,4}};

  if(num < 0 || num > numSimplices()-1) {
    Msg(GERROR, "Invalid decomposition");
    num = 0;
  }
    
  switch(_numNodes) {
  case 4: reorder(quadTri[num], 3, x, y, z, val, xn, yn, zn, valn); break ;
  case 8: reorder(hexaTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  case 6: reorder(prisTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  case 5: reorder(pyraTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  }
}
