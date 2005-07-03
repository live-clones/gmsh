// $Id: Print_Mesh.cpp,v 1.63 2005-07-03 08:02:24 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Create.h"
#include "Context.h"

extern Context_T CTX;

// Write mesh in native MSH format

#define LINE            1
#define TRIANGLE        2
#define QUADRANGLE      3
#define TETRAHEDRON     4
#define HEXAHEDRON      5
#define PRISM           6
#define PYRAMID         7
#define LINE_2          8
#define TRIANGLE_2      9
#define QUADRANGLE_2   10
#define TETRAHEDRON_2  11
#define HEXAHEDRON_2   12
#define PRISM_2        13
#define PYRAMID_2      14
#define POINT          15

static int MSH_VOL_NUM, MSH_SUR_NUM, MSH_LIN_NUM;
static int MSH_NODE_NUM, MSH_ELEMENT_NUM, MSH_ADD;
static int MSH_PHYSICAL_NUM, MSH_PHYSICAL_ORI;
static FILE *MSHFILE;

static void _msh_print_node(void *a, void *b)
{
  Vertex *V = *(Vertex **) a;

  fprintf(MSHFILE, "%d %.16g %.16g %.16g\n",
          V->Num,
          V->Pos.X * CTX.mesh.scaling_factor,
          V->Pos.Y * CTX.mesh.scaling_factor,
          V->Pos.Z * CTX.mesh.scaling_factor);
}

static void _msh_process_nodes(Mesh *M)
{
  int i, j, Num;
  PhysicalGroup *p;
  Vertex *pv, **ppv, v;

  for(i = 0; i < List_Nbr(M->PhysicalGroups); i++) {
    List_Read(M->PhysicalGroups, i, &p);
    if(p->Typ == MSH_PHYSICAL_POINT) {
      for(j = 0; j < List_Nbr(p->Entities); j++) {
        List_Read(p->Entities, j, &Num);
        pv = &v;
        pv->Num = abs(Num);
        if(!Tree_Search(M->Vertices, &pv)) {
          if((ppv = (Vertex **) Tree_PQuery(M->Points, &pv)))
            Tree_Add(M->Vertices, ppv);
        }
      }
    }
  }

  MSH_NODE_NUM = Tree_Nbr(M->Vertices);

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "$Nodes\n");
  else
    fprintf(MSHFILE, "$NOD\n");
  fprintf(MSHFILE, "%d\n", MSH_NODE_NUM);
  Tree_Action(M->Vertices, _msh_print_node);
  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "$EndNodes\n");
  else
    fprintf(MSHFILE, "$ENDNOD\n");
}

static void _msh_print_simplex(void *a, void *b)
{
  int i, type, nbn, nbs = 0;

  SimplexBase *s = *(SimplexBase **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != s->iEnt))
    return;

  if(MSH_SUR_NUM && (MSH_SUR_NUM != s->iEnt))
    return;

  if(MSH_LIN_NUM && (MSH_LIN_NUM != s->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  if(!s->V[2]) {
    nbn = 2;
    if(s->VSUP) {
      type = LINE_2;
      nbs = 1;
    }
    else
      type = LINE;
  }
  else if(!s->V[3]) {
    nbn = 3;
    if(s->VSUP) {
      type = TRIANGLE_2;
      nbs = 3;
    }
    else
      type = TRIANGLE;
  }
  else {
    nbn = 4;
    if(s->VSUP) {
      type = TETRAHEDRON_2;
      nbs = 6;
      if(s->Volume_Simplexe() < 0) {
	Vertex *temp;
	temp = s->V[0];	s->V[0] = s->V[1]; s->V[1] = temp;
	temp = s->VSUP[1]; s->VSUP[1] = s->VSUP[2]; s->VSUP[2] = temp;
	temp = s->VSUP[5]; s->VSUP[5] = s->VSUP[3]; s->VSUP[3] = temp;
      }
    }
    else{
      type = TETRAHEDRON;
      if(s->Volume_Simplexe() < 0) {
	Vertex *temp;
	temp = s->V[0];
	s->V[0] = s->V[1];
	s->V[1] = temp;
      }
    }
  }

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "%d %d 2 %d %d",
	    MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : s->iEnt, 
	    s->iEnt);
  else
    fprintf(MSHFILE, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : s->iEnt, s->iEnt,
	    nbn + nbs);

  if(MSH_PHYSICAL_ORI > 0) {
    for(i = 0; i < nbn; i++)
      fprintf(MSHFILE, " %d", s->V[i]->Num);
    for(i = 0; i < nbs; i++)
      fprintf(MSHFILE, " %d", s->VSUP[i]->Num);
  }
  else {
    for(i = 0; i < nbn; i++)
      fprintf(MSHFILE, " %d", s->V[nbn - i - 1]->Num);
    for(i = 0; i < nbs; i++)
      fprintf(MSHFILE, " %d", s->VSUP[nbs - i - 1]->Num);
  }

  fprintf(MSHFILE, "\n");
}

static void _msh_print_quadrangle(void *a, void *b)
{
  int i, type, nbn, nbs = 0;

  Quadrangle *q = *(Quadrangle **) a;

  if(MSH_SUR_NUM && (MSH_SUR_NUM != q->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 4;
  if(q->VSUP) {
    type = QUADRANGLE_2;
    nbs = 4 + 1;
  }
  else
    type = QUADRANGLE;

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "%d %d 2 %d %d",
	    MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : q->iEnt, 
	    q->iEnt);
  else
    fprintf(MSHFILE, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : q->iEnt, q->iEnt,
	    nbn + nbs);

  if(MSH_PHYSICAL_ORI > 0) {
    for(i = 0; i < nbn; i++)
      fprintf(MSHFILE, " %d", q->V[i]->Num);
    for(i = 0; i < nbs; i++)
      fprintf(MSHFILE, " %d", q->VSUP[i]->Num);
  }
  else {
    for(i = 0; i < nbn; i++)
      fprintf(MSHFILE, " %d", q->V[nbn - i - 1]->Num);
    if(nbs){
      for(i = 0; i < nbs - 1; i++)
	fprintf(MSHFILE, " %d", q->VSUP[nbs - i - 2]->Num);
      fprintf(MSHFILE, " %d", q->VSUP[nbs - 1]->Num);
    }
  }

  fprintf(MSHFILE, "\n");
}

static void _msh_print_hexahedron(void *a, void *b)
{
  int i, type, nbn, nbs = 0;

  Hexahedron *h = *(Hexahedron **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != h->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 8;
  if(h->VSUP) {
    type = HEXAHEDRON_2;
    nbs = 12 + 6 + 1;
  }
  else
    type = HEXAHEDRON;

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "%d %d 2 %d %d",
	    MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : h->iEnt,
	    h->iEnt);
  else
    fprintf(MSHFILE, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : h->iEnt, h->iEnt,
	    nbn + nbs);

  for(i = 0; i < nbn; i++)
    fprintf(MSHFILE, " %d", h->V[i]->Num);
  for(i = 0; i < nbs; i++)
    fprintf(MSHFILE, " %d", h->VSUP[i]->Num);

  fprintf(MSHFILE, "\n");
}

static void _msh_print_prism(void *a, void *b)
{
  int i, type, nbn, nbs = 0;

  Prism *p = *(Prism **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != p->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 6;
  if(p->VSUP) {
    type = PRISM_2;
    nbs = 9 + 3;
  }
  else {
    type = PRISM;
  }

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "%d %d 2 %d %d",
	    MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : p->iEnt,
	    p->iEnt);
  else
    fprintf(MSHFILE, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : p->iEnt, p->iEnt,
	    nbn + nbs);

  for(i = 0; i < nbn; i++)
    fprintf(MSHFILE, " %d", p->V[i]->Num);
  for(i = 0; i < nbs; i++)
    fprintf(MSHFILE, " %d", p->VSUP[i]->Num);

  fprintf(MSHFILE, "\n");
}

static void _msh_print_pyramid(void *a, void *b)
{
  int i, type, nbn, nbs = 0;

  Pyramid *p = *(Pyramid **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != p->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 5;
  if(p->VSUP) {
    type = PYRAMID_2;
    nbs = 8 + 1;
  }
  else {
    type = PYRAMID;
  }

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "%d %d 2 %d %d",
	    MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : p->iEnt,
	    p->iEnt);
  else
    fprintf(MSHFILE, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : p->iEnt, p->iEnt,
	    nbn + nbs);

  for(i = 0; i < nbn; i++)
    fprintf(MSHFILE, " %d", p->V[i]->Num);
  for(i = 0; i < nbs; i++)
    fprintf(MSHFILE, " %d", p->VSUP[i]->Num);

  fprintf(MSHFILE, "\n");
}

static void _msh_print_point(Vertex *V)
{
  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "%d %d 2 %d %d %d\n",
	    MSH_ELEMENT_NUM++, POINT, MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : V->Num, V->Num,
	    V->Num);
  else
    fprintf(MSHFILE, "%d %d %d %d 1 %d\n",
	    MSH_ELEMENT_NUM++, POINT,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : V->Num, V->Num, V->Num);
}

static void _msh_print_elements(Mesh *M)
{
  int i, j, k, Num;

  PhysicalGroup *p;
  Volume *pV;
  Surface *ps;
  Curve *pc;
  Vertex *pv, v;

  List_T *ListCurves = Tree2List(M->Curves);
  List_T *ListSurfaces = Tree2List(M->Surfaces);
  List_T *ListVolumes = Tree2List(M->Volumes);

  for(i = 0; i < List_Nbr(M->PhysicalGroups); i++) {
    List_Read(M->PhysicalGroups, i, &p);
    MSH_PHYSICAL_NUM = p->Num;
    MSH_VOL_NUM = MSH_SUR_NUM = MSH_LIN_NUM = 0;

    switch (p->Typ) {

    case MSH_PHYSICAL_POINT:
      for(j = 0; j < List_Nbr(p->Entities); j++) {
        pv = &v;
        List_Read(p->Entities, j, &Num);
        pv->Num = abs(Num);
        MSH_PHYSICAL_ORI = sign(Num);
        if(Tree_Query(M->Vertices, &pv))
          _msh_print_point(pv);
      }
      break;

    case MSH_PHYSICAL_LINE:
      if(CTX.mesh.oldxtrude) {  //for old extrusion mesh generator
        for(k = 0; k < List_Nbr(ListVolumes); k++) {
          List_Read(ListVolumes, k, &pV);
          for(j = 0; j < List_Nbr(p->Entities); j++) {
            List_Read(p->Entities, j, &Num);
            MSH_LIN_NUM = abs(Num);
            MSH_PHYSICAL_ORI = sign(Num);
            Tree_Action(pV->Lin_Surf, _msh_print_simplex);
          }
        }
      }
      else{
	for(k = 0; k < List_Nbr(ListCurves); k++) {
	  List_Read(ListCurves, k, &pc);
	  for(j = 0; j < List_Nbr(p->Entities); j++) {
	    List_Read(p->Entities, j, &Num);
	    MSH_LIN_NUM = abs(Num);
	    MSH_PHYSICAL_ORI = sign(Num);
	    Tree_Action(pc->Simplexes, _msh_print_simplex);
	    Tree_Action(pc->SimplexesBase, _msh_print_simplex);
	  }
	}
      }
      break;

    case MSH_PHYSICAL_SURFACE:
      if(CTX.mesh.oldxtrude) {  //for old extrusion mesh generator
        for(k = 0; k < List_Nbr(ListVolumes); k++) {
          List_Read(ListVolumes, k, &pV);
          for(j = 0; j < List_Nbr(p->Entities); j++) {
            List_Read(p->Entities, j, &Num);
            MSH_SUR_NUM = abs(Num);
            MSH_PHYSICAL_ORI = sign(Num);
            Tree_Action(pV->Simp_Surf, _msh_print_simplex);
            Tree_Action(pV->Quad_Surf, _msh_print_quadrangle);
          }
        }
      }
      else{
	for(k = 0; k < List_Nbr(ListSurfaces); k++) {
	  List_Read(ListSurfaces, k, &ps);
	  for(j = 0; j < List_Nbr(p->Entities); j++) {
	    List_Read(p->Entities, j, &Num);
	    MSH_SUR_NUM = abs(Num);
	    MSH_PHYSICAL_ORI = sign(Num);
	    Tree_Action(ps->Simplexes, _msh_print_simplex);
	    Tree_Action(ps->SimplexesBase, _msh_print_simplex);
	    Tree_Action(ps->Quadrangles, _msh_print_quadrangle);
	  }
	}
      }
      break;

    case MSH_PHYSICAL_VOLUME:
      for(k = 0; k < List_Nbr(ListVolumes); k++) {
        List_Read(ListVolumes, k, &pV);
        for(j = 0; j < List_Nbr(p->Entities); j++) {
          List_Read(p->Entities, j, &Num);
          MSH_VOL_NUM = abs(Num);
          MSH_PHYSICAL_ORI = sign(Num);
          Tree_Action(pV->Simplexes, _msh_print_simplex);
          Tree_Action(pV->SimplexesBase, _msh_print_simplex);
          Tree_Action(pV->Hexahedra, _msh_print_hexahedron);
          Tree_Action(pV->Prisms, _msh_print_prism);
          Tree_Action(pV->Pyramids, _msh_print_pyramid);
        }
      }
      break;

    default:
      Msg(GERROR, "Unknown type of physical group");
      break;
    }

  }

  List_Delete(ListCurves);
  List_Delete(ListSurfaces);
  List_Delete(ListVolumes);
}

static void _msh_print_all_curves(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  Tree_Action(c->Simplexes, _msh_print_simplex);
  Tree_Action(c->SimplexesBase, _msh_print_simplex);
}

static void _msh_print_all_surfaces(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  Tree_Action(s->Simplexes, _msh_print_simplex);
  Tree_Action(s->SimplexesBase, _msh_print_simplex);
  Tree_Action(s->Quadrangles, _msh_print_quadrangle);
}

static void _msh_print_all_simpsurf(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  Tree_Action(v->Simp_Surf, _msh_print_simplex);
  Tree_Action(v->Quad_Surf, _msh_print_quadrangle);
}

static void _msh_print_all_linsurf(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  Tree_Action(v->Lin_Surf, _msh_print_simplex);
}

static void _msh_print_all_volumes(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  Tree_Action(v->Simplexes, _msh_print_simplex);
  Tree_Action(v->SimplexesBase, _msh_print_simplex);
  Tree_Action(v->Hexahedra, _msh_print_hexahedron);
  Tree_Action(v->Prisms, _msh_print_prism);
  Tree_Action(v->Pyramids, _msh_print_pyramid);
}

static void _msh_print_all_elements(Mesh *M)
{
  MSH_PHYSICAL_NUM = 0;
  MSH_PHYSICAL_ORI = 1;
  MSH_LIN_NUM = MSH_SUR_NUM = MSH_VOL_NUM = 0;

  if(CTX.mesh.oldxtrude) {
    Tree_Action(M->Volumes, _msh_print_all_simpsurf);
    Tree_Action(M->Volumes, _msh_print_all_linsurf);
  }
  else {
    Tree_Action(M->Curves, _msh_print_all_curves);
    Tree_Action(M->Surfaces, _msh_print_all_surfaces);
  }

  Tree_Action(M->Volumes, _msh_print_all_volumes);
}

static void _msh_process_elements(Mesh *M)
{
  MSH_ADD = 0;
  MSH_ELEMENT_NUM = 1;

  if(!List_Nbr(M->PhysicalGroups) || CTX.mesh.save_all) {
    Msg(INFO, "Saving all elements (discarding physical groups)");
    _msh_print_all_elements(M);
  }
  else
    _msh_print_elements(M);

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "$Elements\n");
  else
    fprintf(MSHFILE, "$ELM\n");

  fprintf(MSHFILE, "%d\n", MSH_ELEMENT_NUM - 1);

  if(MSH_ELEMENT_NUM == 1)
    Msg(WARNING, "No elements to save");

  MSH_ADD = 1;
  MSH_ELEMENT_NUM = 1;
  if(!List_Nbr(M->PhysicalGroups) || CTX.mesh.save_all)
    _msh_print_all_elements(M);
  else
    _msh_print_elements(M);

  if(CTX.mesh.msh_file_version == 2.0)
    fprintf(MSHFILE, "$EndElements\n");
  else
    fprintf(MSHFILE, "$ENDELM\n");
}

void Print_Mesh_MSH(Mesh *M, FILE *fp)
{
  MSHFILE = fp;
  if(CTX.mesh.msh_file_version == 1.0){
    // OK, no header
  }
  else if(CTX.mesh.msh_file_version == 2.0){
    fprintf(MSHFILE, "$MeshFormat\n");
    fprintf(MSHFILE, "%g %d %d\n", CTX.mesh.msh_file_version,
	    LIST_FORMAT_ASCII, (int)sizeof(double));
    fprintf(MSHFILE, "$EndMeshFormat\n");
  }
  else{
    Msg(GERROR, "Unknown MSH file version to generate (%g)", 
	CTX.mesh.msh_file_version);
    return;
  }
  _msh_process_nodes(M);
  _msh_process_elements(M);
  Msg(INFO, "%d nodes", MSH_NODE_NUM);
  Msg(INFO, "%d elements", MSH_ELEMENT_NUM - 1);
}

// Write mesh in UNV format

// IDEAS records
#define HEADER       151
#define UNITS        164
#define NODES        2411
#define ELEMENTS     2412
#define RESNODE      55
#define RESELEM      56
#define RESVECT      57
#define GROUPOFNODES 790

// IDEAS elements
#define BEAM         21
#define BEAM2        24
#define THINSHLL     91
#define THINSHLL2    92
#define QUAD         94
#define QUAD2        95 // Ca c'est une impro !!!
#define SOLIDFEM     111
#define WEDGE        112
#define BRICK        115
#define SOLIDFEM2    118

static int ELEMENT_ID;
static Tree_T *tree;
static int UNV_VOL_NUM;
static FILE *UNVFILE;

static void _unv_process_nodes(Mesh *M)
{
  Vertex *v;
  List_T *Nodes = Tree2List(M->Vertices);

  fprintf(UNVFILE, "%6d\n", -1);
  fprintf(UNVFILE, "%6d\n", NODES);
  int nbnod = List_Nbr(Nodes);

  for(int i = 0; i < nbnod; i++) {
    List_Read(Nodes, i, &v);
    int idnod = v->Num;
    double x = v->Pos.X * CTX.mesh.scaling_factor;
    double y = v->Pos.Y * CTX.mesh.scaling_factor;
    double z = v->Pos.Z * CTX.mesh.scaling_factor;
    fprintf(UNVFILE, "%10d%10d%10d%10d\n", idnod, 1, 1, 11);
    char tmp[128];
    // ugly hack to print number with 'D+XX' exponents
    sprintf(tmp, "%25.16E%25.16E%25.16E\n", x, y, z);
    tmp[21] = 'D';
    tmp[46] = 'D';
    tmp[71] = 'D';
    fprintf(UNVFILE, tmp);    
  }

  List_Delete(Nodes);
  fprintf(UNVFILE, "%6d\n", -1);
}

static void _unv_print_record(int num, int fetyp, int geo, int n, int nsup, 
			      Vertex **v, Vertex **vsup)
{
  fprintf(UNVFILE, "%10d%10d%10d%10d%10d%10d\n",
	  num, fetyp, geo, geo, 7, n + nsup);
  if(fetyp == BEAM || fetyp == BEAM2)
    fprintf(UNVFILE, "%10d%10d%10d\n", 0, 0, 0);
  int ntot = 0;
  for(int k = 0; k < n; k++) {
    fprintf(UNVFILE, "%10d", v[k]->Num);
    if(ntot % 8 == 7)
      fprintf(UNVFILE, "\n");
    ntot++;
  }
  for(int k = 0; k < nsup; k++) {
    fprintf(UNVFILE, "%10d", vsup[k]->Num);
    if(ntot % 8 == 7)
      fprintf(UNVFILE, "\n");
    ntot++;
  }
  if(ntot - 1 % 8 != 7)
    fprintf(UNVFILE, "\n");
}

static void _unv_process_1D_elements(Mesh *m)
{
  List_T *ListCurves = Tree2List(m->Curves);
  List_T *AllCurves = List_Create(2, 2, sizeof(Surface *));
  List_T *ListSurfaces = Tree2List(m->Surfaces);
  List_T *Elements;
  SimplexBase *sx;
  Curve *c;
  Surface *surf;

  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &surf);
    for(int j = 0; j < List_Nbr(surf->Generatrices); j++) {
      List_Read(surf->Generatrices, j, &c);
      if(Tree_Nbr(c->Simplexes) || Tree_Nbr(c->SimplexesBase))
        List_Add(AllCurves, &c);
      c = FindCurve(-c->Num, m);
      if(Tree_Nbr(c->Simplexes) || Tree_Nbr(c->SimplexesBase))
        List_Add(AllCurves, &c);
    }
  }

  for(int i = 0; i < List_Nbr(ListCurves); i++) {
    List_Read(ListCurves, i, &c);
    if(!List_Search(AllCurves, &c, compareCurve)) {
      for(int simtype = 0; simtype < 2; simtype ++){
	Elements = (!simtype) ? Tree2List(c->Simplexes) : Tree2List(c->SimplexesBase);
	for(int j = 0; j < List_Nbr(Elements); j++) {
	  List_Read(Elements, j, &sx);
	  if(sx->VSUP)
	    _unv_print_record(sx->Num, BEAM2, c->Num, 2, 2, &sx->V[0], sx->VSUP);
	  else 
	    _unv_print_record(sx->Num, BEAM, c->Num, 2, 0, &sx->V[0], NULL);
	}
	List_Delete(Elements);
      }
    }
  }

  List_Delete(AllCurves);
  List_Delete(ListSurfaces);
  List_Delete(ListCurves);
}

static void _unv_process_2D_elements(Mesh *m)
{
  List_T *ListSurfaces = Tree2List(m->Surfaces);
  List_T *AllSurfaces = List_Create(2, 2, sizeof(Surface *));
  List_T *ListVolumes = Tree2List(m->Volumes);
  List_T *Elements;
  Volume *vol;
  Surface *s;
  SimplexBase *sx;
  Quadrangle *qx;

  for(int i = 0; i < List_Nbr(ListVolumes); i++) {
    List_Read(ListVolumes, i, &vol);
    for(int j = 0; j < List_Nbr(vol->Surfaces); j++) {
      List_Read(vol->Surfaces, j, &s);
      if(Tree_Nbr(s->Simplexes) || Tree_Nbr(s->SimplexesBase) ||
	 Tree_Nbr(s->Quadrangles))
        List_Add(AllSurfaces, &s);
    }
  }

  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    if(!List_Search(AllSurfaces, &s, compareSurface)) {
      
      // triangles
      for(int simtype = 0; simtype < 2; simtype++){
	Elements = (!simtype) ? Tree2List(s->Simplexes) : Tree2List(s->SimplexesBase);
	for(int j = 0; j < List_Nbr(Elements); j++) {
	  List_Read(Elements, j, &sx);
	  if(sx->VSUP)
	    _unv_print_record(abs(sx->Num), THINSHLL, s->Num, 3, 3, &sx->V[0], sx->VSUP);
	  else
	    _unv_print_record(abs(sx->Num), THINSHLL, s->Num, 3, 0, &sx->V[0], NULL);
	}
	List_Delete(Elements);
      }

      // quadrangles
      Elements = Tree2List(s->Quadrangles);
      for(int j = 0; j < List_Nbr(Elements); j++) {
        List_Read(Elements, j, &qx);
	if(qx->VSUP)
	  _unv_print_record(abs(qx->Num), QUAD, s->Num, 4, 4+1, &qx->V[0], qx->VSUP);
	else
	  _unv_print_record(abs(qx->Num), QUAD2, s->Num, 4, 0, &qx->V[0], NULL);
      }
      List_Delete(Elements);
    }
  }
  List_Delete(ListSurfaces);
  List_Delete(ListVolumes);
  List_Delete(AllSurfaces);
}

static void _unv_process_3D_elements(Mesh *m)
{
  List_T *ListVolumes = Tree2List(m->Volumes);
  List_T *Elements;
  SimplexBase *sx;
  Hexahedron *hx;
  Prism *px;
  Volume *v;

  for(int i = 0; i < List_Nbr(ListVolumes); i++) {
    List_Read(ListVolumes, i, &v);

    // Tets
    for(int simtype = 0; simtype < 2; simtype++){
      Elements = (!simtype) ? Tree2List(v->Simplexes) : Tree2List(v->SimplexesBase);
      for(int j = 0; j < List_Nbr(Elements); j++) {
	List_Read(Elements, j, &sx);
	if(sx->Volume_Simplexe() < 0) {
	  Vertex *temp;
	  temp = sx->V[0];
	  sx->V[0] = sx->V[1];
	  sx->V[1] = temp;
	  if(sx->VSUP){
	    temp = sx->VSUP[1];
	    sx->VSUP[1] = sx->VSUP[2];
	    sx->VSUP[2] = temp;
	    temp = sx->VSUP[5];
	    sx->VSUP[5] = sx->VSUP[3];
	    sx->VSUP[3] = temp;
	  }
	}
	if(sx->VSUP)
	  _unv_print_record(ELEMENT_ID++, SOLIDFEM, v->Num, 4, 6, &sx->V[0], sx->VSUP);
	else
	  _unv_print_record(ELEMENT_ID++, SOLIDFEM, v->Num, 4, 0, &sx->V[0], NULL);
      }
      List_Delete(Elements);
    }

    // Prisms
    Elements = Tree2List(v->Prisms);
    for(int j = 0; j < List_Nbr(Elements); j++) {
      List_Read(Elements, j, &px);
      if(px->VSUP)
	_unv_print_record(ELEMENT_ID++, WEDGE, v->Num, 6, 9+3, &px->V[0], px->VSUP);
      else
	_unv_print_record(ELEMENT_ID++, WEDGE, v->Num, 6, 0, &px->V[0], NULL);
    }
    List_Delete(Elements);

    // Hexas
    Elements = Tree2List(v->Hexahedra);
    for(int j = 0; j < List_Nbr(Elements); j++) {
      List_Read(Elements, j, &hx);
      if(hx->VSUP)
	_unv_print_record(ELEMENT_ID++, BRICK, v->Num, 8, 12+6+1, &hx->V[0], hx->VSUP);
      else
	_unv_print_record(ELEMENT_ID++, BRICK, v->Num, 8, 0, &hx->V[0], NULL);
    }
    List_Delete(Elements);
  }
  List_Delete(ListVolumes);
}

static void _unv_add_vertex(void *a, void *b)
{
  Vertex *v = *(Vertex **) a;
  if(Tree_Search(tree, &v->Num))
    return;
  Tree_Add(tree, &v->Num);
  fprintf(UNVFILE, "%10d%10d%2d%2d%2d%2d%2d%2d\n", v->Num, 1, 0, 1, 0, 0, 0, 0);
  fprintf(UNVFILE, "   0.0000000000000000D+00   1.0000000000000000D+00   0.0000000000000000D+00\n");
  fprintf(UNVFILE, "   0.0000000000000000D+00   0.0000000000000000D+00   0.0000000000000000D+00\n");
  fprintf(UNVFILE, "%10d%10d%10d%10d%10d%10d\n", 0, 0, 0, 0, 0, 0);
}

static void _unv_add_simplex_vertices(void *a, void *b)
{
  SimplexBase *s = *(SimplexBase **) a;
  if(s->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 4; i++)
    _unv_add_vertex(&s->V[i], NULL);
}

static void _unv_add_hexahedron_vertices(void *a, void *b)
{
  Hexahedron *h = *(Hexahedron **) a;
  if(h->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 8; i++)
    _unv_add_vertex(&h->V[i], NULL);
}

static void _unv_add_prism_vertices(void *a, void *b)
{
  Prism *p = *(Prism **) a;
  if(p->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 6; i++)
    _unv_add_vertex(&p->V[i], NULL);
}

static void _unv_add_pyramid_vertices(void *a, void *b)
{
  Pyramid *p = *(Pyramid **) a;
  if(p->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 5; i++)
    _unv_add_vertex(&p->V[i], NULL);
}

static void _unv_process_groups(Mesh *m)
{
  Volume *pV;
  Surface *ps, s;
  Curve *pc, c;
  Vertex *pv, v;
  PhysicalGroup *p;
  List_T *ListVolumes;

  for(int i = 0; i < List_Nbr(m->PhysicalGroups); i++) {

    List_Read(m->PhysicalGroups, i, &p);

    fprintf(UNVFILE, "%6d\n", -1);
    fprintf(UNVFILE, "%6d\n", GROUPOFNODES);
    fprintf(UNVFILE, "%10d%10d\n", p->Num, 1);
    fprintf(UNVFILE, "LOAD SET %2d\n", 1);

    tree = Tree_Create(sizeof(int), fcmp_absint);

    switch (p->Typ) {
    case MSH_PHYSICAL_VOLUME:
      ListVolumes = Tree2List(m->Volumes);
      for(int k = 0; k < List_Nbr(ListVolumes); k++) {
        List_Read(ListVolumes, k, &pV);
        for(int j = 0; j < List_Nbr(p->Entities); j++) {
          List_Read(p->Entities, j, &UNV_VOL_NUM);
          Tree_Action(pV->Simplexes, _unv_add_simplex_vertices);
          Tree_Action(pV->SimplexesBase, _unv_add_simplex_vertices);
          Tree_Action(pV->Hexahedra, _unv_add_hexahedron_vertices);
          Tree_Action(pV->Prisms, _unv_add_prism_vertices);
          Tree_Action(pV->Pyramids, _unv_add_pyramid_vertices);
        }
      }
      List_Delete(ListVolumes);
      break;
    case MSH_PHYSICAL_SURFACE:
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        ps = &s;
        List_Read(p->Entities, j, &ps->Num);
        if(Tree_Query(m->Surfaces, &ps))
          Tree_Action(ps->Vertices, _unv_add_vertex);
      }
      break;
    case MSH_PHYSICAL_LINE:
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        pc = &c;
        List_Read(p->Entities, j, &pc->Num);
        if(Tree_Query(m->Curves, &pc))
          for(int k = 0; k < List_Nbr(pc->Vertices); k++)
            _unv_add_vertex(List_Pointer(pc->Vertices, k), NULL);
      }
      break;
    case MSH_PHYSICAL_POINT:
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        pv = &v;
        List_Read(p->Entities, j, &pv->Num);
        if(Tree_Query(m->Vertices, &pv))
          _unv_add_vertex(&pv, NULL);
      }
      break;
    }

    Tree_Delete(tree);

    fprintf(UNVFILE, "%6d\n", -1);
  }
}

void Print_Mesh_UNV(Mesh *M, FILE *fp)
{
  UNVFILE = fp;
  _unv_process_nodes(M);
  fprintf(UNVFILE, "%6d\n", -1);
  fprintf(UNVFILE, "%6d\n", ELEMENTS);
  ELEMENT_ID = 1;
  _unv_process_3D_elements(M);
  _unv_process_2D_elements(M);
  if(0) _unv_process_1D_elements(M);
  fprintf(UNVFILE, "%6d\n", -1);
  _unv_process_groups(M);
}

// Write mesh in Gref format

static FILE *GREFFILE;

static void _gref_consecutive_nodes(Mesh *M, Tree_T *ConsecutiveNTree,
				    Tree_T *ConsecutiveETree)
{
  SimplexBase *sx;
  Quadrangle *qx;
  Surface *s;
  int nbnod, nbedges, nbdof;

  int newnum = 0;

  List_T *ListSurfaces = Tree2List(M->Surfaces);
  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    // triangles
    for(int simtype = 0; simtype < 2; simtype++){
      List_T *Triangles = (!simtype) ? Tree2List(s->Simplexes) : Tree2List(s->SimplexesBase);
      for(int j = 0; j < List_Nbr(Triangles); j++) {
	List_Read(Triangles, j, &sx);
	for(int k = 0; k < 3; k++) {
	  if(sx->V[k]->Frozen >= 0) {
	    sx->V[k]->Frozen = --newnum;
	    Tree_Insert(ConsecutiveNTree, &(sx->V[k]));
	  }
	}
      }
      List_Delete(Triangles);
    }
    // quads
    List_T *Quadrangles = Tree2List(s->Quadrangles);
    for(int j = 0; j < List_Nbr(Quadrangles); j++) {
      List_Read(Quadrangles, j, &qx);
      for(int k = 0; k < 4; k++) {
        if(qx->V[k]->Frozen >= 0) {
          qx->V[k]->Frozen = --newnum;
          Tree_Insert(ConsecutiveNTree, &(qx->V[k]));
        }
      }
    }
    List_Delete(Quadrangles);
  }

  nbnod = -newnum;

  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    // triangles
    for(int simtype = 0; simtype < 2; simtype++){
      List_T *Triangles = (!simtype) ? Tree2List(s->Simplexes) : Tree2List(s->SimplexesBase);
      for(int j = 0; j < List_Nbr(Triangles); j++) {
	List_Read(Triangles, j, &sx);
	for(int k = 0; k < 3; k++) {
	  if(sx->VSUP[k]->Frozen >= 0) {
	    sx->VSUP[k]->Frozen = --newnum;
	    Tree_Insert(ConsecutiveETree, &(sx->VSUP[k]));
	  }
	}
      }
      List_Delete(Triangles);
    }
    // quads
    List_T *Quadrangles = Tree2List(s->Quadrangles);
    for(int j = 0; j < List_Nbr(Quadrangles); j++) {
      List_Read(Quadrangles, j, &qx);
      for(int k = 0; k < 4; k++) {
	if(qx->VSUP[k]->Frozen >= 0) {
	  qx->VSUP[k]->Frozen = --newnum;
	  Tree_Insert(ConsecutiveETree, &(qx->VSUP[k]));
	}
      }
    }
    List_Delete(Quadrangles);
  }

  List_Delete(ListSurfaces);

  nbedges = -newnum - nbnod;
  nbdof = nbnod + nbedges;
  Msg(INFO, "%d Dofs", nbdof);
}

static void _gref_end_consecutive_nodes(Mesh *M)
{
  SimplexBase *sx;
  Quadrangle *qx;
  Surface *s;

  List_T *ListSurfaces = Tree2List(M->Surfaces);
  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    // triangles
    for(int simtype = 0; simtype < 2; simtype++){
      List_T *Triangles = (!simtype) ? Tree2List(s->Simplexes) : Tree2List(s->SimplexesBase);
      for(int j = 0; j < List_Nbr(Triangles); j++) {
	List_Read(Triangles, j, &sx);
	for(int k = 0; k < 3; k++)
	  sx->V[k]->Frozen = 0;
	for(int k = 0; k < 3; k++)
	  sx->VSUP[k]->Frozen = 0;
      }
      List_Delete(Triangles);
    }
    // quads
    List_T *Quadrangles = Tree2List(s->Quadrangles);
    for(int j = 0; j < List_Nbr(Quadrangles); j++) {
      List_Read(Quadrangles, j, &qx);
      for(int k = 0; k < 4; k++)
        qx->V[k]->Frozen = 0;
      for(int k = 0; k < 4; k++)
	qx->VSUP[k]->Frozen = 0;
    }
    List_Delete(Quadrangles);
  }
  List_Delete(ListSurfaces);
}

static int _gref_compare_frozen(const void *a, const void *b)
{
  Vertex *q, *w;
  q = *(Vertex **) a;
  w = *(Vertex **) b;
  return w->Frozen - q->Frozen;
}

static int _gref_process_nodes(Mesh *M, Tree_T *ConsecutiveNTree, 
			       Tree_T *ConsecutiveETree)
{
  int i, nbtriqua;
  Vertex *v;
  Surface *s;
  List_T *Nodes;

  Tree_Action(M->Curves, Degre2_Curve);
  Tree_Action(M->Surfaces, Degre2_Surface);
 
  List_T *ListSurfaces = Tree2List(M->Surfaces);
  nbtriqua = 0;
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    nbtriqua += Tree_Nbr(s->Simplexes) + Tree_Nbr(s->SimplexesBase);
    nbtriqua += Tree_Nbr(s->Quadrangles);
  }
  List_Delete(ListSurfaces);

  _gref_consecutive_nodes(M, ConsecutiveNTree, ConsecutiveETree);

  fprintf(GREFFILE, "%d %d %d\n", nbtriqua, Tree_Nbr(ConsecutiveNTree),
          Tree_Nbr(ConsecutiveNTree) + Tree_Nbr(ConsecutiveETree));

  Nodes = Tree2List(ConsecutiveNTree);
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    fprintf(GREFFILE, "%21.16e ", v->Pos.X * CTX.mesh.scaling_factor);
    if(i % 3 == 2)
      fprintf(GREFFILE, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(GREFFILE, "\n");
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    fprintf(GREFFILE, "%21.16e ", v->Pos.Y * CTX.mesh.scaling_factor);
    if(i % 3 == 2)
      fprintf(GREFFILE, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(GREFFILE, "\n");
  i = Tree_Nbr(ConsecutiveNTree);
  List_Delete(Nodes);
  return i;
}

static int _gref_find_physical(Vertex *v, Mesh *m)
{
  PhysicalGroup *p;
  Curve *c;
  int i, j;
  for(i = 0; i < List_Nbr(m->PhysicalGroups); i++) {
    List_Read(m->PhysicalGroups, i, &p);
    if(p->Typ == MSH_PHYSICAL_POINT) {
      if(List_Search(p->Entities, &v->Num, fcmp_absint)) {
        return p->Num;
      }
    }
  }

  if(v->ListCurves) {
    for(i = 0; i < List_Nbr(m->PhysicalGroups); i++) {
      List_Read(m->PhysicalGroups, i, &p);
      if(p->Typ == MSH_PHYSICAL_LINE) {
        for(j = 0; j < List_Nbr(v->ListCurves); j++) {
          List_Read(v->ListCurves, j, &c);
          if(List_Search(p->Entities, &c->Num, fcmp_absint)) {
            return p->Num;
          }
        }
      }
    }
  }
  return 0;
}

static void _gref_process_boundary_conditions(Mesh *M, Tree_T *TRN, Tree_T *TRE)
{
  int i, ent;
  Vertex *v;

  List_T *Nodes = Tree2List(TRN);
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    ent = _gref_find_physical(v, M);
    fprintf(GREFFILE, "%d %d ", ent, ent);
    if(i % 3 == 2)
      fprintf(GREFFILE, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(GREFFILE, "\n");
  List_Delete(Nodes);

  Nodes = Tree2List(TRE);
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    ent = _gref_find_physical(v, M);
    fprintf(GREFFILE, "%d %d ", ent, ent);
    if(i % 3 == 2)
      fprintf(GREFFILE, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(GREFFILE, "\n");
  List_Delete(Nodes);
}

static void _gref_process_elements(Mesh *M, int nn)
{
  SimplexBase *sx;
  Quadrangle *qx;
  Surface *s;

  List_T *ListSurfaces = Tree2List(M->Surfaces);

  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    // triangles
    for(int simtype = 0; simtype < 2; simtype++){
      List_T *Triangles = (!simtype) ? Tree2List(s->Simplexes) : Tree2List(s->SimplexesBase);
      for(int j = 0; j < List_Nbr(Triangles); j++) {
	List_Read(Triangles, j, &sx);
	fprintf(GREFFILE, "%d %d %d\n", -sx->V[0]->Frozen,
		-sx->V[1]->Frozen, -sx->V[2]->Frozen);
      }
      List_Delete(Triangles);
    }
    // quads
    List_T *Quadrangles = Tree2List(s->Quadrangles);
    for(int j = 0; j < List_Nbr(Quadrangles); j++) {
      List_Read(Quadrangles, j, &qx);
      fprintf(GREFFILE, "%d %d %d %d\n", -qx->V[0]->Frozen,
	      -qx->V[1]->Frozen, -qx->V[2]->Frozen, -qx->V[3]->Frozen);
    }
    List_Delete(Quadrangles);
  }

  // Degres de Liberte
  for(int i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    // triangles
    for(int simtype = 0; simtype < 2; simtype++){
      List_T *Triangles = (!simtype) ? Tree2List(s->Simplexes) : Tree2List(s->SimplexesBase);
      for(int j = 0; j < List_Nbr(Triangles); j++) {
	List_Read(Triangles, j, &sx);
	fprintf(GREFFILE, "%d %d %d %d %d %d %d %d %d %d %d %d\n",
		-2 * sx->V[0]->Frozen - 1,
		-2 * sx->V[0]->Frozen,
		-2 * sx->VSUP[0]->Frozen - 1,
		-2 * sx->VSUP[0]->Frozen,
		-2 * sx->V[1]->Frozen - 1,
		-2 * sx->V[1]->Frozen,
		-2 * sx->VSUP[1]->Frozen - 1,
		-2 * sx->VSUP[1]->Frozen,
		-2 * sx->V[2]->Frozen - 1,
		-2 * sx->V[2]->Frozen,
		-2 * sx->VSUP[2]->Frozen - 1, -2 * sx->VSUP[2]->Frozen);
      }
      List_Delete(Triangles);
    }
    // quads
    List_T *Quadrangles = Tree2List(s->Quadrangles);
    for(int j = 0; j < List_Nbr(Quadrangles); j++) {
      List_Read(Quadrangles, j, &qx);
      fprintf(GREFFILE, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
	      -2 * qx->V[0]->Frozen - 1,
	      -2 * qx->V[0]->Frozen,
	      -2 * qx->VSUP[0]->Frozen - 1,
	      -2 * qx->VSUP[0]->Frozen,
	      -2 * qx->V[1]->Frozen - 1,
	      -2 * qx->V[1]->Frozen,
	      -2 * qx->VSUP[1]->Frozen - 1,
	      -2 * qx->VSUP[1]->Frozen,
	      -2 * qx->V[2]->Frozen - 1,
	      -2 * qx->V[2]->Frozen,
	      -2 * qx->VSUP[2]->Frozen - 1,
	      -2 * qx->VSUP[2]->Frozen,
	      -2 * qx->V[3]->Frozen - 1,
	      -2 * qx->V[3]->Frozen,
	      -2 * qx->VSUP[3]->Frozen - 1, -2 * qx->VSUP[3]->Frozen);
    }
    List_Delete(Quadrangles);
  }
  List_Delete(ListSurfaces);
}

void Print_Mesh_GREF(Mesh *M, FILE *fp)
{
  GREFFILE = fp;
  Tree_T *TRN = Tree_Create(sizeof(Vertex *), _gref_compare_frozen);
  Tree_T *TRE = Tree_Create(sizeof(Vertex *), _gref_compare_frozen);
  _gref_process_nodes(M, TRN, TRE);
  _gref_process_elements(M, Tree_Nbr(TRN));
  _gref_process_boundary_conditions(M, TRN, TRE);
  Tree_Delete(TRN);
  Tree_Delete(TRE);
  _gref_end_consecutive_nodes(M);
}

// Write mesh in VRML 1 format

static List_T *wrlnodes = NULL;
static FILE *WRLFILE;

static void _wrl_print_node(void *a, void *b)
{
  Vertex *V = *(Vertex **) a;
  fprintf(WRLFILE, "%.16g %.16g %.16g,\n",
          V->Pos.X * CTX.mesh.scaling_factor,
          V->Pos.Y * CTX.mesh.scaling_factor,
          V->Pos.Z * CTX.mesh.scaling_factor);
  List_Add(wrlnodes, &V->Num);
}

static void _wrl_process_nodes(Mesh *M)
{
  if(!wrlnodes)
    wrlnodes = List_Create(Tree_Size(M->Vertices), 100, sizeof(int));
  else
    List_Reset(wrlnodes);
  fprintf(WRLFILE, "#VRML V1.0 ascii\n");
  fprintf(WRLFILE, "#created by Gmsh\n");
  fprintf(WRLFILE, "Coordinate3 {\n");
  fprintf(WRLFILE, "  point [\n");
  Tree_Action(M->Vertices, _wrl_print_node);
  fprintf(WRLFILE, "  ]\n");
  fprintf(WRLFILE, "}\n");
}

static void _wrl_print_line(void *a, void *b)
{
  SimplexBase *s = *(SimplexBase **) a;
  for(int i = 0; i < 2; i++){
    if(s->V[i]){
      int j = List_ISearch(wrlnodes, &s->V[i]->Num, fcmp_int);
      if(j < 0)
	Msg(GERROR, "Unknown node %d in line %d", s->V[i]->Num, s->Num);
      else
	fprintf(WRLFILE, "%d,", j);
    }
  }
  fprintf(WRLFILE, "-1,\n");
}

static void _wrl_print_triangle(void *a, void *b)
{
  SimplexBase *s = *(SimplexBase **) a;
  for(int i = 0; i < 3; i++){
    if(s->V[i]){
      int j = List_ISearch(wrlnodes, &s->V[i]->Num, fcmp_int);
      if(j < 0)
	Msg(GERROR, "Unknown node %d in triangle %d", s->V[i]->Num, s->Num);
      else
	fprintf(WRLFILE, "%d,", j);
    }
  }
  fprintf(WRLFILE, "-1,\n");
}

static void _wrl_print_quadrangle(void *a, void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  for(int i = 0; i < 4; i++){
    if(q->V[i]){
      int j = List_ISearch(wrlnodes, &q->V[i]->Num, fcmp_int);
      if(j < 0)
	Msg(GERROR, "Unknown node %d in quadrangle %d", q->V[i]->Num, q->Num);
      else
	fprintf(WRLFILE, "%d,", j);
    }
  }
  fprintf(WRLFILE, "-1,\n");
}

static void _wrl_print_all_curves(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  if(c->Num < 0)
    return;
  fprintf(WRLFILE, "DEF Curve%d IndexedLineSet {\n", c->Num);
  fprintf(WRLFILE, "  coordIndex [\n");
  Tree_Action(c->Simplexes, _wrl_print_line);
  Tree_Action(c->SimplexesBase, _wrl_print_line);
  fprintf(WRLFILE, "  ]\n");
  fprintf(WRLFILE, "}\n");
}

static void _wrl_print_all_surfaces(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  fprintf(WRLFILE, "DEF Surface%d IndexedFaceSet {\n", s->Num);
  fprintf(WRLFILE, "  coordIndex [\n");
  Tree_Action(s->Simplexes, _wrl_print_triangle);
  Tree_Action(s->SimplexesBase, _wrl_print_triangle);
  Tree_Action(s->Quadrangles, _wrl_print_quadrangle);
  fprintf(WRLFILE, "  ]\n");
  fprintf(WRLFILE, "}\n");
}

static void _wrl_process_elements(Mesh *M)
{
  if(!wrlnodes)
    Msg(GERROR, "VRML node list does not exist");
  else {
    Tree_Action(M->Curves, _wrl_print_all_curves);
    Tree_Action(M->Surfaces, _wrl_print_all_surfaces);
  }
}

void Print_Mesh_WRL(Mesh *M, FILE *fp)
{
  WRLFILE = fp;
  _wrl_process_nodes(M);
  _wrl_process_elements(M);
}

// Write surface mesh in STL format

static FILE *STLFILE;

static void _stl_print_triangle(void *a, void *b)
{
  SimplexBase *s = *(SimplexBase **) a;
  
  if(!s->V[2]) return;
  
  double n[3];
  normal3points(s->V[0]->Pos.X, s->V[0]->Pos.Y, s->V[0]->Pos.Z, 
		s->V[1]->Pos.X, s->V[1]->Pos.Y, s->V[1]->Pos.Z, 
		s->V[2]->Pos.X, s->V[2]->Pos.Y, s->V[2]->Pos.Z, n);

  fprintf(STLFILE, "facet normal %g %g %g\n", n[0], n[1], n[2]);
  fprintf(STLFILE, "  outer loop\n");
  fprintf(STLFILE, "    vertex %g %g %g\n", s->V[0]->Pos.X, s->V[0]->Pos.Y, s->V[0]->Pos.Z);
  fprintf(STLFILE, "    vertex %g %g %g\n", s->V[1]->Pos.X, s->V[1]->Pos.Y, s->V[1]->Pos.Z);
  fprintf(STLFILE, "    vertex %g %g %g\n", s->V[2]->Pos.X, s->V[2]->Pos.Y, s->V[2]->Pos.Z);
  fprintf(STLFILE, "  endloop\n");
  fprintf(STLFILE, "endfacet\n");
}

static void _stl_print_quadrangle(void *a, void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  
  double n[3];
  normal3points(q->V[0]->Pos.X, q->V[0]->Pos.Y, q->V[0]->Pos.Z, 
		q->V[1]->Pos.X, q->V[1]->Pos.Y, q->V[1]->Pos.Z, 
		q->V[2]->Pos.X, q->V[2]->Pos.Y, q->V[2]->Pos.Z, n);

  fprintf(STLFILE, "facet normal %g %g %g\n", n[0], n[1], n[2]);
  fprintf(STLFILE, "  outer loop\n");
  fprintf(STLFILE, "    vertex %g %g %g\n", q->V[0]->Pos.X, q->V[0]->Pos.Y, q->V[0]->Pos.Z);
  fprintf(STLFILE, "    vertex %g %g %g\n", q->V[1]->Pos.X, q->V[1]->Pos.Y, q->V[1]->Pos.Z);
  fprintf(STLFILE, "    vertex %g %g %g\n", q->V[2]->Pos.X, q->V[2]->Pos.Y, q->V[2]->Pos.Z);
  fprintf(STLFILE, "  endloop\n");
  fprintf(STLFILE, "endfacet\n");
  fprintf(STLFILE, "facet normal %g %g %g\n", n[0], n[1], n[2]);
  fprintf(STLFILE, "  outer loop\n");
  fprintf(STLFILE, "    vertex %g %g %g\n", q->V[0]->Pos.X, q->V[0]->Pos.Y, q->V[0]->Pos.Z);
  fprintf(STLFILE, "    vertex %g %g %g\n", q->V[2]->Pos.X, q->V[2]->Pos.Y, q->V[2]->Pos.Z);
  fprintf(STLFILE, "    vertex %g %g %g\n", q->V[3]->Pos.X, q->V[3]->Pos.Y, q->V[3]->Pos.Z);
  fprintf(STLFILE, "  endloop\n");
  fprintf(STLFILE, "endfacet\n");
}

static void _stl_print_all_surfaces(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  Tree_Action(s->Simplexes, _stl_print_triangle);
  Tree_Action(s->SimplexesBase, _stl_print_triangle);
  Tree_Action(s->Quadrangles, _stl_print_quadrangle);
}

void Print_Mesh_STL(Mesh *M, FILE *fp)
{
  STLFILE = fp;
  fprintf(STLFILE, "solid Created by Gmsh\n");
  Tree_Action(M->Surfaces, _stl_print_all_surfaces);
  fprintf(STLFILE, "endsolid Created by Gmsh\n");
}

// Write mesh in DMG format

static int _dmg_is_topologic(Vertex *v, List_T *curves)
{
  Curve *c;
  for(int i = 0; i < List_Nbr(curves); i++) {
    List_Read(curves, i, &c);
    if(!compareVertex(&v, &c->beg))
      return 1;
  }
  return 0;
}

void Print_Mesh_DMG(Mesh *m, FILE *fp)
{
  int i, j;
  List_T *ll, *l;
  Vertex *v;
  Curve *c;
  Surface *s;
  int k;

  l = Tree2List(m->Points);
  ll = Tree2List(m->Curves);

  k = 0;
  for(i = 0; i < List_Nbr(l); i++) {
    List_Read(l, i, &v);
    if(_dmg_is_topologic(v, ll)) {
      k++;
    }
  }

  // write first the global infos 

  fprintf(fp, "%d %d %d %d \n", Tree_Nbr(m->Volumes),
          Tree_Nbr(m->Surfaces),
          Tree_Nbr(m->Curves) / 2,     // the 2 is for the reverse curves
          k);

  // then write the bounding box

  m->Grid.min.X = CTX.min[0];
  m->Grid.min.Y = CTX.min[1];
  m->Grid.min.Z = CTX.min[2];
  m->Grid.max.X = CTX.max[0];
  m->Grid.max.Y = CTX.max[1];
  m->Grid.max.Z = CTX.max[2];

  fprintf(fp, "%12.5E %12.5E %12.5E \n", 
	  m->Grid.min.X, m->Grid.min.Y, m->Grid.min.Z);
  fprintf(fp, "%12.5E %12.5E %12.5E \n", 
	  m->Grid.max.X, m->Grid.max.Y, m->Grid.max.Z);

  // write the points
  k = 0;
  for(i = 0; i < List_Nbr(l); i++) {
    List_Read(l, i, &v);
    if(_dmg_is_topologic(v, ll)) {
      v->Frozen = k++;
      fprintf(fp, "%d %12.5E %12.5E %12.5E \n", 
	      v->Frozen, v->Pos.X, v->Pos.Y, v->Pos.Z);
    }
  }
  List_Delete(l);

  // write the curves
  l = ll;
  k = 0;
  for(i = 0; i < List_Nbr(l); i++) {
    List_Read(l, i, &c);
    if(c->Num > 0) {
      c->ipar[3] = k;
      Curve *cinv = FindCurve(-c->Num, m);
      cinv->ipar[3] = k++;
      fprintf(fp, "%d %d %d \n", 
	      c->ipar[3], c->beg->Frozen, c->end->Frozen);
    }
  }

  List_Delete(l);

  // write the surfaces
  l = Tree2List(m->Surfaces);

  for(i = 0; i < List_Nbr(l); i++) {
    List_Read(l, i, &s);

    int numEdgeLoop[2000], iLoop = 0;
    Vertex *beg = NULL;
    numEdgeLoop[iLoop] = 0;
    int deb = 1;
    for(j = 0; j < List_Nbr(s->Generatrices); j++) {
      List_Read(s->Generatrices, j, &c);
      if(deb) {
        beg = c->beg;
        deb = 0;
      }
      Msg(INFO, "beg->%d end->%d", c->beg->Num, c->end->Num);
      (numEdgeLoop[iLoop])++;
      if(c->end == beg) {
        iLoop++;
        numEdgeLoop[iLoop] = 0;
        deb = 1;
      }
    }
    s->ipar[3] = i;
    fprintf(fp, "%d %d\n", i, iLoop);
    int iEdge = 0;
    for(k = 0; k < iLoop; k++) {
      fprintf(fp, "%d ", numEdgeLoop[k]);
      for(j = 0; j < numEdgeLoop[k]; j++) {
        List_Read(s->Generatrices, iEdge++, &c);
        fprintf(fp, "%d %d ", abs(c->ipar[3]), (c->Num > 0) ? 1 : -1);
      }
      fprintf(fp, "\n");
    }
  }
  List_Delete(l);

  // write the volumes (2 b continued...)
}

// Write mesh in Plot3D format, ASCII structured, multi-zone
// FIXME: still need to implement this for extruded grids

static FILE *P3DFILE;

int _p3d_cmp_entities(const void *a, const void *b)
{
  Element **e1 = (Element **) a;
  Element **e2 = (Element **) b;

  return (*e1)->iEnt - (*e2)->iEnt;
}

int _p3d_cmp_surf_num(const void *a, const void *b)
{
  Surface **e1 = (Surface **) a;
  Surface **e2 = (Surface **) b;

  return (*e1)->Num - (*e2)->Num;
}

int _p3d_cmp_vol_num(const void *a, const void *b)
{
  Volume **e1 = (Volume **) a;
  Volume **e2 = (Volume **) b;

  return (*e1)->Num - (*e2)->Num;
}

void _p3d_print_quads(List_T *ListQuads, int Nu, int Nv)
{
  int i = 0, j = 0, c = 1, curQuad = 0;
  double coord;
  Quadrangle *pQ;

  for (c = 0; c < 3; c++) {
    for (j = 0; j < (Nu - 1); j++) {
      for (i = 0; i < (Nv - 1); i++) {
        curQuad = i + (j * (Nv - 1));
        List_Read(ListQuads, curQuad, &pQ);
        coord = (c==0) ? pQ->V[0]->Pos.X : ((c==1) ? pQ->V[0]->Pos.Y : pQ->V[0]->Pos.Z);
        fprintf(P3DFILE, "%g ", coord * CTX.mesh.scaling_factor);
      }
      coord = (c==0) ? pQ->V[3]->Pos.X : ((c==1) ? pQ->V[3]->Pos.Y : pQ->V[3]->Pos.Z);
      fprintf(P3DFILE, "%g\n", coord * CTX.mesh.scaling_factor);
    } j--;
    for (i = 0; i < (Nv - 1); i++) {
      curQuad = i + (j * (Nv - 1));
      List_Read(ListQuads, curQuad, &pQ);
      coord = (c==0) ? pQ->V[1]->Pos.X : ((c==1) ? pQ->V[1]->Pos.Y : pQ->V[1]->Pos.Z);
      fprintf(P3DFILE, "%g ", coord * CTX.mesh.scaling_factor);
    }
    coord = (c==0) ? pQ->V[2]->Pos.X : ((c==1) ? pQ->V[2]->Pos.Y : pQ->V[2]->Pos.Z);
    fprintf(P3DFILE, "%g\n", coord * CTX.mesh.scaling_factor);
  }
}

void _p3d_print_hex(List_T *ListHex, int Nu, int Nv, int Nw)
{
  int i = 0, j = 0, k = 0, c = 0, curHex = 0;
  double coord;
  Hexahedron *pH;

  for (c = 0; c < 3; c++) {
    for (k = 0; k < (Nu - 1); k++) {
      for (j = 0; j < (Nv - 1); j++) {
        for (i = 0; i < (Nw - 1); i++) {
          curHex = i + (j * (Nw - 1)) + (k * (Nw - 1) * (Nv - 1));
          List_Read(ListHex, curHex, &pH);
          coord = (c==0) ? pH->V[0]->Pos.X : ((c==1) ? pH->V[0]->Pos.Y : pH->V[0]->Pos.Z);
          fprintf(P3DFILE, "%g ", coord * CTX.mesh.scaling_factor);
        }
       coord = (c==0) ? pH->V[4]->Pos.X : ((c==1) ? pH->V[4]->Pos.Y : pH->V[4]->Pos.Z);
       fprintf(P3DFILE, "%g\n", coord * CTX.mesh.scaling_factor);
      } j--;
      for (i = 0; i < (Nw - 1); i++) {
        curHex = i + (j * (Nw - 1)) + (k * (Nw - 1) * (Nv - 1));
        List_Read(ListHex, curHex, &pH);
        coord = (c==0) ? pH->V[3]->Pos.X : ((c==1) ? pH->V[3]->Pos.Y : pH->V[3]->Pos.Z);
        fprintf(P3DFILE, "%g ", coord * CTX.mesh.scaling_factor);
      }
      coord = (c==0) ? pH->V[7]->Pos.X : ((c==1) ? pH->V[7]->Pos.Y : pH->V[7]->Pos.Z);
      fprintf(P3DFILE, "%g\n", coord * CTX.mesh.scaling_factor);
    } k--;
    for (j = 0; j < (Nv - 1); j++) {
      for (i = 0; i < (Nw - 1); i++) {
        curHex = i + (j * (Nw - 1)) + (k * (Nw - 1) * (Nv - 1));
        List_Read(ListHex, curHex, &pH);
        coord = (c==0) ? pH->V[1]->Pos.X : ((c==1) ? pH->V[1]->Pos.Y : pH->V[1]->Pos.Z);
        fprintf(P3DFILE, "%g ", coord * CTX.mesh.scaling_factor);
      }
      coord = (c==0) ? pH->V[5]->Pos.X : ((c==1) ? pH->V[5]->Pos.Y : pH->V[5]->Pos.Z);
      fprintf(P3DFILE, "%g\n", coord * CTX.mesh.scaling_factor);
    } j--;
    for (i = 0; i < (Nw - 1); i++) {
      curHex = i + (j * (Nw - 1)) + (k * (Nw - 1) * (Nv - 1));
      List_Read(ListHex, curHex, &pH);
      coord = (c==0) ? pH->V[2]->Pos.X : ((c==1) ? pH->V[2]->Pos.Y : pH->V[2]->Pos.Z);
      fprintf(P3DFILE, "%g ", coord * CTX.mesh.scaling_factor);
    }
    coord = (c==0) ? pH->V[6]->Pos.X : ((c==1) ? pH->V[6]->Pos.Y : pH->V[6]->Pos.Z);
    fprintf(P3DFILE, "%g\n", coord * CTX.mesh.scaling_factor);
  }
}

void _p3d_print_all_elements(Mesh *M)
{
  int i, Nv, Nu, ElemCnt = 0;
  Volume *pV;
  Surface *pS;
  List_T *ListQuads;
  List_T *ListHex;

  List_T *ListSurfaces = Tree2List(M->Surfaces);
  List_T *ListVolumes = Tree2List(M->Volumes);

  List_T *ListStructSurf = List_Create(1,1,sizeof(Surface *));
  List_T *ListStructVol = List_Create(1,1,sizeof(Volume *));

  List_Sort(ListSurfaces, _p3d_cmp_surf_num);
  List_Sort(ListVolumes, _p3d_cmp_vol_num);

  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &pS);
    if (pS->Nu &&
        pS->Nv &&
        (Tree_Nbr(pS->Quadrangles) == (pS->Nu - 1) * (pS->Nv - 1))){
        ElemCnt++;
        List_Add(ListStructSurf, &pS);
    }
  }

  for(i = 0; i < List_Nbr(ListVolumes); i++) {
    List_Read(ListVolumes, i, &pV);
    List_Read(pV->Surfaces, 0, &pS);
    Nu = pS->Nu;
    Nv = pS->Nv;
    List_Read(pV->Surfaces, 1, &pS);
    if (Nu &&
        Nv &&
        pS->Nv &&
        (Tree_Nbr(pV->Hexahedra) == (Nu - 1) * (Nv - 1) * (pS->Nv - 1))){
        ElemCnt++;
        List_Add(ListStructVol, &pV);
    }
  }

  fprintf(P3DFILE, "%d\n", ElemCnt);

  for(i = 0; i < List_Nbr(ListStructSurf); i++) {
    List_Read(ListStructSurf, i, &pS);
    fprintf(P3DFILE, "%d %d 1\n", pS->Nv, pS->Nu);
  }

  for(i = 0; i < List_Nbr(ListStructVol); i++) {
    List_Read(ListStructVol, i, &pV);
    List_Read(pV->Surfaces, 0, &pS);
    Nu = pS->Nu;
    Nv = pS->Nv;
    List_Read(pV->Surfaces, 1, &pS);
    fprintf(P3DFILE, "%d %d %d\n", pS->Nv, Nv, Nu);
  }

  for(i = 0; i < List_Nbr(ListStructSurf); i++) {
    List_Read(ListStructSurf, i, &pS);
    ListQuads = Tree2List(pS->Quadrangles);
    List_Sort(ListQuads, _p3d_cmp_entities);
    _p3d_print_quads(ListQuads, pS->Nu, pS->Nv);
    List_Delete(ListQuads);
  }

  for(i = 0; i < List_Nbr(ListStructVol); i++) {
    List_Read(ListStructVol, i, &pV);
    List_Read(pV->Surfaces, 0, &pS);
    Nu = pS->Nu;
    Nv = pS->Nv;
    List_Read(pV->Surfaces, 1, &pS);
    ListHex = Tree2List(pV->Hexahedra);
    List_Sort(ListHex, _p3d_cmp_entities);
    _p3d_print_hex(ListHex, Nu, Nv, pS->Nv);
    List_Delete(ListHex);
  }

  List_Delete(ListSurfaces);
  List_Delete(ListVolumes);
  List_Delete(ListStructSurf);
  List_Delete(ListStructVol);
}

void _p3d_print_elements(Mesh *M)
{
  // FIXME: to do
}

void Print_Mesh_P3D(Mesh *M, FILE *fp)
{
  P3DFILE = fp;

  if(!List_Nbr(M->PhysicalGroups) || CTX.mesh.save_all) {
    Msg(INFO, "Saving all elements (discarding physical groups)");
    _p3d_print_all_elements(M);
  }
  else{
    Msg(WARNING, "No Plot3d format of physicals yet, saving all elements!");
    //_p3d_print_elements(M);
    _p3d_print_all_elements(M);
  }
}

// Public Print_Mesh routine

void Print_Mesh(Mesh *M, char *c, int Type)
{
  char name[256], ext[10]="";

  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }

  CTX.threads_lock = 1;

  strcpy(name, M->name);

  switch(Type){
  case FORMAT_MSH:  strcpy(ext, ".msh"); break;
  case FORMAT_VRML: strcpy(ext, ".wrl"); break;
  case FORMAT_UNV:  strcpy(ext, ".unv"); break;
  case FORMAT_GREF: strcpy(ext, ".Gref"); break;
  case FORMAT_DMG:  strcpy(ext, ".dmg"); break;
  case FORMAT_STL:  strcpy(ext, ".stl"); break;
  case FORMAT_P3D:  strcpy(ext, ".p3d"); break;
  default:
    Msg(GERROR, "Unknown mesh file format %d", Type);
    return;
  }
  
  c ? strcpy(name, c) : strcat(name, ext);

  Msg(INFO, "Writing mesh file '%s'", name);

  FILE *fp = fopen(name, "w");
  if(!fp) {
    Msg(GERROR, "Unable to open file '%s'", name);
    CTX.threads_lock = 0;
    return;
  }

  switch(Type){
  case FORMAT_MSH:  Print_Mesh_MSH(M, fp); break;
  case FORMAT_VRML: Print_Mesh_WRL(M, fp); break;
  case FORMAT_UNV:  Print_Mesh_UNV(M, fp); break;
  case FORMAT_GREF: Print_Mesh_GREF(M, fp); break;
  case FORMAT_DMG:  Print_Mesh_DMG(M, fp); break;
  case FORMAT_STL:  Print_Mesh_STL(M, fp); break;
  case FORMAT_P3D:  Print_Mesh_P3D(M, fp); break;
  default:
    break;
  }

  fclose(fp);
  Msg(INFO, "Wrote mesh file '%s'", name);
  Msg(STATUS2N, "Wrote '%s'", name);

  CTX.threads_lock = 0;
}
