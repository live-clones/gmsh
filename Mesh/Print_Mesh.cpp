// $Id: Print_Mesh.cpp,v 1.45 2003-12-07 02:56:34 geuzaine Exp $
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Create.h"
#include "Context.h"

extern Context_T CTX;

static FILE *meshfile;

// M S H   F O R M A T

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

static double MSH_VERSION = 1.0;
static int MSH_VOL_NUM, MSH_SUR_NUM, MSH_LIN_NUM;
static int MSH_NODE_NUM, MSH_ELEMENT_NUM, MSH_3D, MSH_ADD;
static int MSH_PHYSICAL_NUM, MSH_PHYSICAL_ORI;

void print_msh_node(void *a, void *b)
{
  Vertex **V;

  V = (Vertex **) a;

  fprintf(meshfile, "%d %.16g %.16g %.16g\n",
          (*V)->Num,
          (*V)->Pos.X * CTX.mesh.scaling_factor,
          (*V)->Pos.Y * CTX.mesh.scaling_factor,
          (*V)->Pos.Z * CTX.mesh.scaling_factor);
}

void process_msh_nodes(Mesh * M)
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

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "$Nodes\n");
  else
    fprintf(meshfile, "$NOD\n");
  fprintf(meshfile, "%d\n", MSH_NODE_NUM);
  Tree_Action(M->Vertices, print_msh_node);
  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "$ENDNOD\n");
  else
    fprintf(meshfile, "$EndNodes\n");
}

void print_msh_simplex(void *a, void *b)
{
  Simplex **S;
  int i, type, nbn, nbs = 0;

  S = (Simplex **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != (*S)->iEnt))
    return;

  if(MSH_SUR_NUM && (MSH_SUR_NUM != (*S)->iEnt))
    return;

  if(MSH_LIN_NUM && (MSH_LIN_NUM != (*S)->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  if(!(*S)->V[2]) {
    nbn = 2;
    if((*S)->VSUP) {
      type = LINE_2;
      nbs = 1;
    }
    else
      type = LINE;
  }
  else if(!(*S)->V[3]) {
    nbn = 3;
    if((*S)->VSUP) {
      type = TRIANGLE_2;
      nbs = 3;
    }
    else
      type = TRIANGLE;
  }
  else {
    nbn = 4;
    if(!MSH_3D) {
      if((*S)->VSUP) {
        type = QUADRANGLE_2;
        nbs = 4;
      }
      else
        type = QUADRANGLE;
    }
    else if((*S)->VSUP) {
      type = TETRAHEDRON_2;
      nbs = 6;
    }
    else
      type = TETRAHEDRON;
  }

  if(type == TETRAHEDRON) {
    if((*S)->Volume_Simplexe() < 0) {
      Vertex *temp;
      temp = (*S)->V[0];
      (*S)->V[0] = (*S)->V[1];
      (*S)->V[1] = temp;
    }
  }

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "%d %d %d %d 0 %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*S)->iEnt, (*S)->iEnt,
	    nbn + nbs);
  else
    fprintf(meshfile, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*S)->iEnt, (*S)->iEnt,
	    nbn + nbs);

  if(MSH_PHYSICAL_ORI > 0) {
    for(i = 0; i < nbn; i++)
      fprintf(meshfile, " %d", (*S)->V[i]->Num);
    for(i = 0; i < nbs; i++)
      fprintf(meshfile, " %d", (*S)->VSUP[i]->Num);
  }
  else {
    for(i = 0; i < nbn; i++)
      fprintf(meshfile, " %d", (*S)->V[nbn - i - 1]->Num);
    for(i = 0; i < nbs; i++)
      fprintf(meshfile, " %d", (*S)->VSUP[nbs - i - 1]->Num);
  }

  fprintf(meshfile, "\n");
}

void print_msh_hexahedron(void *a, void *b)
{
  Hexahedron **H;
  int i, type, nbn, nbs = 0;

  H = (Hexahedron **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != (*H)->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 8;
  if((*H)->VSUP) {
    type = HEXAHEDRON_2;
    nbs = 12;
  }
  else
    type = HEXAHEDRON;

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "%d %d %d %d 0 %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*H)->iEnt, (*H)->iEnt,
	    nbn + nbs);
  else
    fprintf(meshfile, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*H)->iEnt, (*H)->iEnt,
	    nbn + nbs);

  for(i = 0; i < nbn; i++)
    fprintf(meshfile, " %d", (*H)->V[i]->Num);
  for(i = 0; i < nbs; i++)
    fprintf(meshfile, " %d", (*H)->VSUP[i]->Num);

  fprintf(meshfile, "\n");
}

void print_msh_prism(void *a, void *b)
{
  Prism **P;
  int i, type, nbn, nbs = 0;

  P = (Prism **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != (*P)->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 6;
  if((*P)->VSUP) {
    type = PRISM_2;
    nbs = 9;
  }
  else {
    type = PRISM;
  }

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "%d %d %d %d 0 %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*P)->iEnt, (*P)->iEnt,
	    nbn + nbs);
  else
    fprintf(meshfile, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*P)->iEnt, (*P)->iEnt,
	    nbn + nbs);

  for(i = 0; i < nbn; i++)
    fprintf(meshfile, " %d", (*P)->V[i]->Num);
  for(i = 0; i < nbs; i++)
    fprintf(meshfile, " %d", (*P)->VSUP[i]->Num);

  fprintf(meshfile, "\n");
}

void print_msh_pyramid(void *a, void *b)
{
  Pyramid **P;
  int i, type, nbn, nbs = 0;

  P = (Pyramid **) a;

  if(MSH_VOL_NUM && (MSH_VOL_NUM != (*P)->iEnt))
    return;

  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 5;
  if((*P)->VSUP) {
    type = PYRAMID_2;
    nbs = 8;
  }
  else {
    type = PYRAMID;
  }

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "%d %d %d %d 0 %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*P)->iEnt, (*P)->iEnt,
	    nbn + nbs);
  else
    fprintf(meshfile, "%d %d %d %d %d",
	    MSH_ELEMENT_NUM++, type,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : (*P)->iEnt, (*P)->iEnt,
	    nbn + nbs);

  for(i = 0; i < nbn; i++)
    fprintf(meshfile, " %d", (*P)->V[i]->Num);
  for(i = 0; i < nbs; i++)
    fprintf(meshfile, " %d", (*P)->VSUP[i]->Num);

  fprintf(meshfile, "\n");
}

void print_msh_point(Vertex * V)
{
  if(!MSH_ADD) {
    MSH_ELEMENT_NUM++;
    return;
  }

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "%d %d %d %d 0 1 %d\n",
	    MSH_ELEMENT_NUM++, POINT,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : V->Num, V->Num, V->Num);
  else
    fprintf(meshfile, "%d %d %d %d 1 %d\n",
	    MSH_ELEMENT_NUM++, POINT,
	    MSH_PHYSICAL_NUM ? MSH_PHYSICAL_NUM : V->Num, V->Num, V->Num);
}

void print_msh_elements(Mesh * M)
{
  int i, j, k, Num;

  PhysicalGroup *p;
  Volume *pV;
  Surface *ps, s;
  Curve *pc, c;
  Vertex *pv, v;

  List_T *ListVolumes = Tree2List(M->Volumes);

  for(i = 0; i < List_Nbr(M->PhysicalGroups); i++) {
    List_Read(M->PhysicalGroups, i, &p);
    MSH_PHYSICAL_NUM = p->Num;
    MSH_3D = 0;
    MSH_VOL_NUM = MSH_SUR_NUM = MSH_LIN_NUM = 0;

    switch (p->Typ) {

    case MSH_PHYSICAL_POINT:
      for(j = 0; j < List_Nbr(p->Entities); j++) {
        pv = &v;
        List_Read(p->Entities, j, &Num);
        pv->Num = abs(Num);
        MSH_PHYSICAL_ORI = sign(Num);
        if(Tree_Query(M->Vertices, &pv))
          print_msh_point(pv);
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
            Tree_Action(pV->Simp_Surf, print_msh_simplex);
          }
        }
        break;  //done
      }

      for(j = 0; j < List_Nbr(p->Entities); j++) {
        pc = &c;
        List_Read(p->Entities, j, &Num);
        pc->Num = abs(Num);
        MSH_PHYSICAL_ORI = sign(Num);
        if(Tree_Query(M->Curves, &pc))
          Tree_Action(pc->Simplexes, print_msh_simplex);
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
            Tree_Action(pV->Simp_Surf, print_msh_simplex);
          }
        }
        break;  //done
      }

      for(j = 0; j < List_Nbr(p->Entities); j++) {
        ps = &s;
        List_Read(p->Entities, j, &Num);
        ps->Num = abs(Num);
        MSH_PHYSICAL_ORI = sign(Num);
        if(Tree_Query(M->Surfaces, &ps))
          Tree_Action(ps->Simplexes, print_msh_simplex);
      }
      break;

    case MSH_PHYSICAL_VOLUME:
      for(k = 0; k < List_Nbr(ListVolumes); k++) {
        List_Read(ListVolumes, k, &pV);
        for(j = 0; j < List_Nbr(p->Entities); j++) {
          List_Read(p->Entities, j, &Num);
          MSH_3D = 1;
          MSH_VOL_NUM = abs(Num);
          MSH_PHYSICAL_ORI = sign(Num);
          Tree_Action(pV->Simplexes, print_msh_simplex);
          Tree_Action(pV->Hexahedra, print_msh_hexahedron);
          Tree_Action(pV->Prisms, print_msh_prism);
          Tree_Action(pV->Pyramids, print_msh_pyramid);
        }
      }
      break;

    default:
      Msg(GERROR, "Unknown type of physical group");
      break;
    }

  }

}

void print_all_msh_curves(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  Tree_Action(c->Simplexes, print_msh_simplex);
}

void print_all_msh_surfaces(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  Tree_Action(s->Simplexes, print_msh_simplex);
}

void print_all_msh_simpsurf(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  Tree_Action(v->Simp_Surf, print_msh_simplex);
}

void print_all_msh_volumes(void *a, void *b)
{
  Volume *v = *(Volume **) a;
  Tree_Action(v->Simplexes, print_msh_simplex);
  Tree_Action(v->Hexahedra, print_msh_hexahedron);
  Tree_Action(v->Prisms, print_msh_prism);
  Tree_Action(v->Pyramids, print_msh_pyramid);
}

void print_all_msh_elements(Mesh * M)
{
  MSH_PHYSICAL_NUM = 0;
  MSH_PHYSICAL_ORI = 1;
  MSH_LIN_NUM = MSH_SUR_NUM = MSH_VOL_NUM = 0;

  MSH_3D = 0;
  if(CTX.mesh.oldxtrude) {
    Tree_Action(M->Volumes, print_all_msh_simpsurf);
  }
  else {
    Tree_Action(M->Curves, print_all_msh_curves);
    Tree_Action(M->Surfaces, print_all_msh_surfaces);
  }

  MSH_3D = 1;
  Tree_Action(M->Volumes, print_all_msh_volumes);
}

void process_msh_elements(Mesh * M)
{
  MSH_ADD = 0;
  MSH_ELEMENT_NUM = 1;

  if(!List_Nbr(M->PhysicalGroups) || CTX.mesh.save_all) {
    Msg(INFO, "Saving all elements (discarding physical groups)");
    print_all_msh_elements(M);
  }
  else
    print_msh_elements(M);

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "$Elements\n");
  else
    fprintf(meshfile, "$ELM\n");

  fprintf(meshfile, "%d\n", MSH_ELEMENT_NUM - 1);

  if(MSH_ELEMENT_NUM == 1)
    Msg(WARNING, "No elements to save");

  MSH_ADD = 1;
  MSH_ELEMENT_NUM = 1;
  if(!List_Nbr(M->PhysicalGroups) || CTX.mesh.save_all)
    print_all_msh_elements(M);
  else
    print_msh_elements(M);

  if(MSH_VERSION > 1.0)
    fprintf(meshfile, "$EndElements\n");
  else
    fprintf(meshfile, "$ENDELM\n");
}


//  U N V   F O R M A T

// Numeros des enregistrements IDEAS
#define HEADER       151
#define UNITS        164
#define NODES        2411
#define ELEMENTS     2412
#define RESNODE      55
#define RESELEM      56
#define RESVECT      57
#define GROUPOFNODES 790

// Numeros des elements IDEAS
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

void process_unv_nodes(Mesh * M)
{
  int nbnod;
  double x, y, z;
  int i, idnod;
  Vertex *v;

  List_T *Nodes = Tree2List(M->Vertices);

  fprintf(meshfile, "%6d\n", -1);
  fprintf(meshfile, "%6d\n", NODES);
  nbnod = List_Nbr(Nodes);

  for(i = 0; i < nbnod; i++) {
    List_Read(Nodes, i, &v);
    idnod = v->Num;
    x = v->Pos.X * CTX.mesh.scaling_factor;
    y = v->Pos.Y * CTX.mesh.scaling_factor;
    z = v->Pos.Z * CTX.mesh.scaling_factor;
    fprintf(meshfile, "%10d%10d%10d%10d\n", idnod, 1, 1, 11);
    fprintf(meshfile, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", x, y, z);
  }

  List_Delete(Nodes);
  fprintf(meshfile, "%6d\n", -1);
}

int process_unv_2D_elements(Mesh * m)
{
  List_T *ListSurfaces = Tree2List(m->Surfaces);
  List_T *ListVolumes = Tree2List(m->Volumes);
  List_T *Elements;
  Volume *vol;
  List_T *AllSurfaces = List_Create(2, 2, sizeof(Surface *));
  Simplex *sx;
  Surface *s;
  int i, j, nsup, n, ntot, k, geo, fetyp;

  for(i = 0; i < List_Nbr(ListVolumes); i++) {
    List_Read(ListVolumes, i, &vol);
    for(j = 0; j < List_Nbr(vol->Surfaces); j++) {
      List_Read(vol->Surfaces, j, &s);
      if(Tree_Nbr(s->Simplexes))
        List_Add(AllSurfaces, &s);
    }
  }

  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    if(!List_Search(AllSurfaces, &s, compareSurface)) {
      Elements = Tree2List(s->Simplexes);
      for(j = 0; j < List_Nbr(Elements); j++) {
        List_Read(Elements, j, &sx);
        if(sx->V[3]) {
          if(sx->VSUP) {
            fetyp = QUAD;
            n = 4;
            nsup = 4;
          }
          else {
            fetyp = QUAD;
            n = 4;
            nsup = 0;
          }
        }
        else {
          if(sx->VSUP) {
            fetyp = THINSHLL;
            n = 3;
            nsup = 3;
          }
          else {
            fetyp = THINSHLL;
            nsup = 0;
            n = 3;
          }
        }
        geo = s->Num;
        fprintf(meshfile, "%10d%10d%10d%10d%10d%10d\n",
                /*ELEMENT_ID++ */ abs(sx->Num), fetyp, geo, geo, 7, n + nsup);
        //'abs' since extrusion can tag triangles
        // with a negative number
        ntot = 0;
        for(k = 0; k < n; k++) {
          fprintf(meshfile, "%10d", sx->V[k]->Num);
          if(ntot % 8 == 7)
            fprintf(meshfile, "\n");
          ntot++;
        }
        for(k = 0; k < nsup; k++) {
          fprintf(meshfile, "%10d", sx->VSUP[k]->Num);
          if(ntot % 8 == 7)
            fprintf(meshfile, "\n");
          ntot++;
        }
        if(ntot - 1 % 8 != 7)
          fprintf(meshfile, "\n");
      }
      List_Delete(Elements);
    }
  }
  List_Delete(ListSurfaces);
  List_Delete(ListVolumes);
  List_Delete(AllSurfaces);
  return 0;
}

int process_unv_1D_elements(Mesh * m)
{
  List_T *ListCurves = Tree2List(m->Curves);
  List_T *AllCurves = List_Create(2, 2, sizeof(Surface *));
  List_T *ListSurfaces = Tree2List(m->Surfaces);
  List_T *Elements;
  Simplex *sx;
  Curve *c;
  Surface *surf;
  int k, ntot, i, j, geo, fetyp, n, nsup;

  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &surf);
    for(j = 0; j < List_Nbr(surf->Generatrices); j++) {
      List_Read(surf->Generatrices, j, &c);
      if(Tree_Nbr(c->Simplexes))
        List_Add(AllCurves, &c);
      c = FindCurve(-c->Num, m);
      if(Tree_Nbr(c->Simplexes))
        List_Add(AllCurves, &c);
    }
  }

  for(i = 0; i < List_Nbr(ListCurves); i++) {
    List_Read(ListCurves, i, &c);
    if(!List_Search(AllCurves, &c, compareCurve)) {
      Elements = Tree2List(c->Simplexes);
      for(j = 0; j < List_Nbr(Elements); j++) {
        List_Read(Elements, j, &sx);
        if(sx->VSUP) {
          fetyp = BEAM2;
          n = 2;
          nsup = 2;
        }
        else {
          fetyp = BEAM;
          n = 2;
          nsup = 0;
        }
        geo = c->Num;
        fprintf(meshfile, "%10d%10d%10d%10d%10d%10d\n",
                /*ELEMENT_ID++ */ sx->Num, fetyp, geo, geo, 7, n + nsup);
        ntot = 0;
        fprintf(meshfile, "%10d%10d%10d\n", 0, 0, 0);
        for(k = 0; k < n; k++) {
          fprintf(meshfile, "%10d", sx->V[k]->Num);
          if(ntot % 8 == 7)
            fprintf(meshfile, "\n");
          ntot++;
        }
        for(k = 0; k < nsup; k++) {
          fprintf(meshfile, "%10d", sx->VSUP[k]->Num);
          if(ntot % 8 == 7)
            fprintf(meshfile, "\n");
          ntot++;
        }
        if(ntot - 1 % 8 != 7)
          fprintf(meshfile, "\n");
      }

      List_Delete(Elements);
    }
  }
  List_Delete(AllCurves);
  List_Delete(ListSurfaces);
  List_Delete(ListCurves);
  return 0;
}

int process_unv_3D_elements(Mesh * m)
{
  List_T *ListVolumes = Tree2List(m->Volumes);
  List_T *Elements;
  Simplex *sx;
  Hexahedron *hx;
  Prism *px;
  Volume *v;
  int nb = 0, i, j, nsup, n, ntot, k, geo, fetyp;

  for(i = 0; i < List_Nbr(ListVolumes); i++) {
    List_Read(ListVolumes, i, &v);
    // TETRAEDRON
    Elements = Tree2List(v->Simplexes);
    for(j = 0; j < List_Nbr(Elements); j++) {
      List_Read(Elements, j, &sx);
      if(sx->VSUP) {
        fetyp = SOLIDFEM;
        n = 4;
        nsup = 6;
      }
      else {
        fetyp = SOLIDFEM;
        nsup = 0;
        n = 4;
      }
      if(sx->Volume_Simplexe() < 0) {
        Vertex *temp;
        temp = sx->V[0];
        sx->V[0] = sx->V[1];
        sx->V[1] = temp;
        if(sx->Volume_Simplexe() < 0)
          Msg(WARNING, "Negative volume for simplex %d", sx->Num);
      }
      geo = v->Num;
      fprintf(meshfile, "%10d%10d%10d%10d%10d%10d\n",
              ELEMENT_ID++, fetyp, geo, geo, 7, n + nsup);
      ntot = 0;
      for(k = 0; k < n; k++) {
        fprintf(meshfile, "%10d", sx->V[k]->Num);
        if(ntot % 8 == 7)
          fprintf(meshfile, "\n");
        ntot++;
      }
      for(k = 0; k < nsup; k++) {
        fprintf(meshfile, "%10d", sx->VSUP[k]->Num);
        if(ntot % 8 == 7)
          fprintf(meshfile, "\n");
        ntot++;
      }
      if(ntot - 1 % 8 != 7)
        fprintf(meshfile, "\n");
    }
    List_Delete(Elements);
    nb += Tree_Nbr(v->Simplexes);

    // PRISMS
    Elements = Tree2List(v->Prisms);
    for(j = 0; j < List_Nbr(Elements); j++) {
      List_Read(Elements, j, &px);
      if(px->VSUP) {
        fetyp = WEDGE;
        n = 6;
        nsup = 9;
      }
      else {
        fetyp = WEDGE;
        nsup = 0;
        n = 6;
      }

      geo = v->Num;
      fprintf(meshfile, "%10d%10d%10d%10d%10d%10d\n",
              ELEMENT_ID++, fetyp, geo, geo, 7, n + nsup);
      ntot = 0;
      for(k = 0; k < n; k++) {
        fprintf(meshfile, "%10d", px->V[k]->Num);
        if(ntot % 8 == 7)
          fprintf(meshfile, "\n");
        ntot++;
      }
      for(k = 0; k < nsup; k++) {
        fprintf(meshfile, "%10d", px->VSUP[k]->Num);
        if(ntot % 8 == 7)
          fprintf(meshfile, "\n");
        ntot++;
      }
      if(ntot - 1 % 8 != 7)
        fprintf(meshfile, "\n");
    }
    List_Delete(Elements);
    nb += Tree_Nbr(v->Prisms);

    // HEXAHEDRA
    Elements = Tree2List(v->Hexahedra);
    for(j = 0; j < List_Nbr(Elements); j++) {
      List_Read(Elements, j, &hx);
      if(hx->VSUP) {
        fetyp = BRICK;
        n = 8;
        nsup = 12;
      }
      else {
        fetyp = BRICK;
        nsup = 0;
        n = 8;
      }

      geo = v->Num;
      fprintf(meshfile, "%10d%10d%10d%10d%10d%10d\n",
              ELEMENT_ID++, fetyp, geo, geo, 7, n + nsup);
      ntot = 0;
      for(k = 0; k < n; k++) {
        fprintf(meshfile, "%10d", hx->V[k]->Num);
        if(ntot % 8 == 7)
          fprintf(meshfile, "\n");
        ntot++;
      }
      for(k = 0; k < nsup; k++) {
        fprintf(meshfile, "%10d", hx->VSUP[k]->Num);
        if(ntot % 8 == 7)
          fprintf(meshfile, "\n");
        ntot++;
      }
      if(ntot - 1 % 8 != 7)
        fprintf(meshfile, "\n");
    }
    List_Delete(Elements);
    nb += Tree_Nbr(v->Hexahedra);
  }
  List_Delete(ListVolumes);
  return nb;
}

void add_unv_vertex(void *a, void *b)
{
  Vertex *v;
  v = *(Vertex **) a;
  if(Tree_Search(tree, &v->Num))
    return;
  Tree_Add(tree, &v->Num);
  fprintf(meshfile, "%10d%10d%2d%2d%2d%2d%2d%2d\n", v->Num, 1, 0, 1, 0, 0, 0,
          0);
  fprintf(meshfile, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", 0., 1., 0.);
  fprintf(meshfile, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", 0., 0., 0.);
  fprintf(meshfile, "%10d%10d%10d%10d%10d%10d\n", 0, 0, 0, 0, 0, 0);
}

void add_unv_simplex_vertices(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  if(s->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 4; i++)
    add_unv_vertex(&s->V[i], NULL);
}

void add_unv_hexahedron_vertices(void *a, void *b)
{
  Hexahedron *h = *(Hexahedron **) a;
  if(h->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 8; i++)
    add_unv_vertex(&h->V[i], NULL);
}

void add_unv_prism_vertices(void *a, void *b)
{
  Prism *p = *(Prism **) a;
  if(p->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 6; i++)
    add_unv_vertex(&p->V[i], NULL);
}

void add_unv_pyramid_vertices(void *a, void *b)
{
  Pyramid *p = *(Pyramid **) a;
  if(p->iEnt != UNV_VOL_NUM)
    return;
  for(int i = 0; i < 5; i++)
    add_unv_vertex(&p->V[i], NULL);
}

void process_unv_groups(Mesh * m)
{
  int j, i, k;
  Volume *pV;
  Surface *ps, s;
  Curve *pc, c;
  Vertex *pv, v;
  PhysicalGroup *p;
  List_T *ListVolumes;

  for(i = 0; i < List_Nbr(m->PhysicalGroups); i++) {

    List_Read(m->PhysicalGroups, i, &p);

    fprintf(meshfile, "%6d\n", -1);
    fprintf(meshfile, "%6d\n", GROUPOFNODES);
    fprintf(meshfile, "%10d%10d\n", p->Num, 1);
    fprintf(meshfile, "LOAD SET %2d\n", 1);

    tree = Tree_Create(sizeof(int), fcmp_absint);

    switch (p->Typ) {
    case MSH_PHYSICAL_VOLUME:
      ListVolumes = Tree2List(m->Volumes);
      for(k = 0; k < List_Nbr(ListVolumes); k++) {
        List_Read(ListVolumes, k, &pV);
        for(j = 0; j < List_Nbr(p->Entities); j++) {
          List_Read(p->Entities, j, &UNV_VOL_NUM);
          Tree_Action(pV->Simplexes, add_unv_simplex_vertices);
          Tree_Action(pV->Hexahedra, add_unv_hexahedron_vertices);
          Tree_Action(pV->Prisms, add_unv_prism_vertices);
          Tree_Action(pV->Pyramids, add_unv_pyramid_vertices);
        }
      }
      List_Delete(ListVolumes);
      break;
    case MSH_PHYSICAL_SURFACE:
      for(j = 0; j < List_Nbr(p->Entities); j++) {
        ps = &s;
        List_Read(p->Entities, j, &ps->Num);
        if(Tree_Query(m->Surfaces, &ps))
          Tree_Action(ps->Vertices, add_unv_vertex);
      }
      break;
    case MSH_PHYSICAL_LINE:
      for(j = 0; j < List_Nbr(p->Entities); j++) {
        pc = &c;
        List_Read(p->Entities, j, &pc->Num);
        if(Tree_Query(m->Curves, &pc))
          for(k = 0; k < List_Nbr(pc->Vertices); k++)
            add_unv_vertex(List_Pointer(pc->Vertices, k), NULL);
      }
      break;
    case MSH_PHYSICAL_POINT:
      for(j = 0; j < List_Nbr(p->Entities); j++) {
        pv = &v;
        List_Read(p->Entities, j, &pv->Num);
        if(Tree_Query(m->Vertices, &pv))
          add_unv_vertex(&pv, NULL);
      }
      break;
    }

    Tree_Delete(tree);

    fprintf(meshfile, "%6d\n", -1);
  }
}

//  G R E F   F O R M A T

void ConsecutiveNodes(Mesh * M, Tree_T * ConstecutiveNTree,
                      Tree_T * ConsecutiveETree);

static int compareFrozen(const void *a, const void *b)
{
  Vertex *q, *w;
  q = *(Vertex **) a;
  w = *(Vertex **) b;
  return w->Frozen - q->Frozen;
}

int process_Gref_nodes(FILE * fGref, Mesh * M,
                       Tree_T * ConsecutiveNTree, Tree_T * ConsecutiveETree)
{
  int i, nbtri;
  Vertex *v;
  Surface *s;
  Curve *c;
  List_T *ListSurfaces, *ListCurves, *Nodes;

  ListCurves = Tree2List(M->Curves);
  for(i = 0; i < List_Nbr(ListCurves); i++) {
    List_Read(ListCurves, i, &c);
    Degre2(c->Simplexes, c, NULL);
  }
  List_Delete(ListCurves);

  ListSurfaces = Tree2List(M->Surfaces);
  nbtri = 0;
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Degre2(s->Simplexes, NULL, s);
    nbtri += Tree_Nbr(s->Simplexes);
  }
  List_Delete(ListSurfaces);

  ConsecutiveNodes(M, ConsecutiveNTree, ConsecutiveETree);

  fprintf(fGref, "%d %d %d\n", nbtri, Tree_Nbr(ConsecutiveNTree),
          Tree_Nbr(ConsecutiveNTree) + Tree_Nbr(ConsecutiveETree));

  Nodes = Tree2List(ConsecutiveNTree);
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    fprintf(fGref, "%21.16e ", v->Pos.X * CTX.mesh.scaling_factor);
    if(i % 3 == 2)
      fprintf(fGref, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(fGref, "\n");
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    fprintf(fGref, "%21.16e ", v->Pos.Y * CTX.mesh.scaling_factor);
    if(i % 3 == 2)
      fprintf(fGref, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(fGref, "\n");
  i = Tree_Nbr(ConsecutiveNTree);
  List_Delete(Nodes);
  return i;
}

int find_physicalentity(Vertex * v, Mesh * m)
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

void process_Gref_poundarybonditions(FILE * fGref, Mesh * M,
                                     Tree_T * TRN, Tree_T * TRE)
{
  int i, ent;
  Vertex *v;

  List_T *Nodes = Tree2List(TRN);
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    ent = find_physicalentity(v, M);
    fprintf(fGref, "%d %d ", ent, ent);
    if(i % 3 == 2)
      fprintf(fGref, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(fGref, "\n");
  List_Delete(Nodes);

  Nodes = Tree2List(TRE);
  for(i = 0; i < List_Nbr(Nodes); i++) {
    List_Read(Nodes, i, &v);
    ent = find_physicalentity(v, M);
    fprintf(fGref, "%d %d ", ent, ent);
    if(i % 3 == 2)
      fprintf(fGref, "\n");
  }
  if((List_Nbr(Nodes) - 1) % 3 != 2)
    fprintf(fGref, "\n");
  List_Delete(Nodes);
}

void process_Gref_elements(FILE * fGref, Mesh * M, int nn)
{
  int i, j;
  Simplex *sx;
  Surface *s;
  List_T *Triangles;
  List_T *ListSurfaces;

  ListSurfaces = Tree2List(M->Surfaces);
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Triangles = Tree2List(s->Simplexes);
    for(j = 0; j < List_Nbr(Triangles); j++) {
      List_Read(Triangles, j, &sx);
      if(!sx->V[3])
        fprintf(fGref, "%d %d %d\n", -sx->V[0]->Frozen,
                -sx->V[1]->Frozen, -sx->V[2]->Frozen);
      else
        fprintf(fGref, "%d %d %d %d\n", -sx->V[0]->Frozen,
                -sx->V[1]->Frozen, -sx->V[2]->Frozen, -sx->V[3]->Frozen);

    }
    List_Delete(Triangles);
  }

  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Triangles = Tree2List(s->Simplexes);
    for(j = 0; j < List_Nbr(Triangles); j++) {
      List_Read(Triangles, j, &sx);
      if(!sx->V[3])
        fprintf(fGref, "%d %d %d\n", -sx->VSUP[0]->Frozen - nn,
                -sx->VSUP[1]->Frozen - nn, -sx->VSUP[2]->Frozen - nn);
      else
        fprintf(fGref, "%d %d %d %d\n", -sx->VSUP[0]->Frozen - nn,
                -sx->VSUP[1]->Frozen - nn,
                -sx->VSUP[2]->Frozen - nn, -sx->VSUP[3]->Frozen - nn);
    }
    List_Delete(Triangles);
  }
  // Degres de Liberte
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Triangles = Tree2List(s->Simplexes);
    for(j = 0; j < List_Nbr(Triangles); j++) {
      List_Read(Triangles, j, &sx);
      if(!sx->V[3])
        fprintf(fGref, "%d %d %d %d %d %d %d %d %d %d %d %d\n",
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
      else
        fprintf(fGref, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
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
                -2 * sx->VSUP[2]->Frozen - 1,
                -2 * sx->VSUP[2]->Frozen,
                -2 * sx->V[3]->Frozen - 1,
                -2 * sx->V[3]->Frozen,
                -2 * sx->VSUP[3]->Frozen - 1, -2 * sx->VSUP[3]->Frozen);
    }
    List_Delete(Triangles);
  }
  List_Delete(ListSurfaces);
}

void ConsecutiveNodes(Mesh * M, Tree_T * ConsecutiveNTree,
                      Tree_T * ConsecutiveETree)
{
  int i, j, k;
  Simplex *sx;
  Surface *s;
  List_T *Triangles;
  int nbnod, nbedges, nbdof;
  List_T *ListSurfaces;

  int newnum = 0, N;

  ListSurfaces = Tree2List(M->Surfaces);
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Triangles = Tree2List(s->Simplexes);
    for(j = 0; j < List_Nbr(Triangles); j++) {
      List_Read(Triangles, j, &sx);
      if(!sx->V[3])
        N = 3;
      else
        N = 4;
      for(k = 0; k < N; k++) {
        if(sx->V[k]->Frozen >= 0) {
          sx->V[k]->Frozen = --newnum;
          Tree_Insert(ConsecutiveNTree, &(sx->V[k]));
        }
      }
    }
    List_Delete(Triangles);
  }
  nbnod = -newnum;
  ListSurfaces = Tree2List(M->Surfaces);
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Triangles = Tree2List(s->Simplexes);
    for(j = 0; j < List_Nbr(Triangles); j++) {
      List_Read(Triangles, j, &sx);
      if(!sx->V[3])
        N = 3;
      else
        N = 4;
      for(k = 0; k < N; k++) {
        if(sx->VSUP[k]->Frozen >= 0) {
          sx->VSUP[k]->Frozen = --newnum;
          Tree_Insert(ConsecutiveETree, &(sx->VSUP[k]));
        }
      }
    }
    List_Delete(Triangles);
  }
  nbedges = -newnum - nbnod;
  nbdof = nbnod + nbedges;
  Msg(INFO, "%d Dofs", nbdof);
}

void EndConsecutiveNodes(Mesh * M)
{
  int i, j, k;
  Simplex *sx;
  Surface *s;
  List_T *Triangles;
  List_T *ListSurfaces;
  int N;

  ListSurfaces = Tree2List(M->Surfaces);
  for(i = 0; i < List_Nbr(ListSurfaces); i++) {
    List_Read(ListSurfaces, i, &s);
    Triangles = Tree2List(s->Simplexes);
    for(j = 0; j < List_Nbr(Triangles); j++) {
      List_Read(Triangles, j, &sx);
      if(!sx->V[3])
        N = 3;
      else
        N = 4;
      for(k = 0; k < N; k++)
        sx->V[k]->Frozen = 0;
      for(k = 0; k < N; k++)
        sx->VSUP[k]->Frozen = 0;
    }
    List_Delete(Triangles);
  }
  List_Delete(ListSurfaces);
}

//  V R M L 1   F O R M A T

static List_T *wrlnodes = NULL;

void print_wrl_node(void *a, void *b)
{
  Vertex *V = *(Vertex **) a;
  fprintf(meshfile, "%.16g %.16g %.16g,\n",
          V->Pos.X * CTX.mesh.scaling_factor,
          V->Pos.Y * CTX.mesh.scaling_factor,
          V->Pos.Z * CTX.mesh.scaling_factor);
  List_Add(wrlnodes, &V->Num);
}

void process_wrl_nodes(Mesh * M)
{
  if(!wrlnodes)
    wrlnodes = List_Create(Tree_Size(M->Vertices), 100, sizeof(int));
  else
    List_Reset(wrlnodes);
  fprintf(meshfile, "#VRML V1.0 ascii\n");
  fprintf(meshfile, "#created by Gmsh\n");
  fprintf(meshfile, "Coordinate3 {\n");
  fprintf(meshfile, "  point [\n");
  Tree_Action(M->Vertices, print_wrl_node);
  fprintf(meshfile, "  ]\n");
  fprintf(meshfile, "}\n");
}

void print_wrl_simplex(void *a, void *b)
{
  Simplex *S = *(Simplex **) a;
  int i = 0, j;
  while(S->V[i]) {
    j = List_ISearch(wrlnodes, &S->V[i]->Num, fcmp_int);
    if(j < 0)
      Msg(GERROR, "Unknown node %d in simplex %d", S->V[i]->Num, S->Num);
    else
      fprintf(meshfile, "%d,", j);
    i++;
  }
  fprintf(meshfile, "-1,\n");
}

void print_all_wrl_curves(void *a, void *b)
{
  Curve *c = *(Curve **) a;
  if(c->Num < 0)
    return;
  fprintf(meshfile, "DEF Curve%d IndexedLineSet {\n", c->Num);
  fprintf(meshfile, "  coordIndex [\n");
  Tree_Action(c->Simplexes, print_wrl_simplex);
  fprintf(meshfile, "  ]\n");
  fprintf(meshfile, "}\n");
}

void print_all_wrl_surfaces(void *a, void *b)
{
  Surface *s = *(Surface **) a;
  fprintf(meshfile, "DEF Surface%d IndexedFaceSet {\n", s->Num);
  fprintf(meshfile, "  coordIndex [\n");
  Tree_Action(s->Simplexes, print_wrl_simplex);
  fprintf(meshfile, "  ]\n");
  fprintf(meshfile, "}\n");
}

void process_wrl_elements(Mesh * M)
{
  if(!wrlnodes)
    Msg(GERROR, "VRML node list does not exist");
  else {
    Tree_Action(M->Curves, print_all_wrl_curves);
    Tree_Action(M->Surfaces, print_all_wrl_surfaces);
  }
}


// Public Print_Mesh routine

void Print_Mesh(Mesh * M, char *c, int Type)
{
  char name[256], ext[10]="";

  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }

  CTX.threads_lock = 1;

  strcpy(name, M->name);

  switch(Type){
  case FORMAT_MSH:
    strcpy(ext, ".msh"); 
    break;
  case FORMAT_VRML:
    strcpy(ext, ".wrl"); 
    break;
  case FORMAT_UNV:
    strcpy(ext, ".unv");
    break;
  case FORMAT_GREF: 
    strcpy(ext, ".Gref");
    break;
  default:
    Msg(GERROR, "Unknown mesh file format %d", Type);
    return;
  }
  
  c ? strcpy(name, c) : strcat(name, ext);

  Msg(INFO, "Writing mesh file '%s'", name);

  meshfile = fopen(name, "w");
  if(!meshfile) {
    Msg(GERROR, "Unable to open file '%s'", name);
    CTX.threads_lock = 0;
    return;
  }

  switch(Type){
  case FORMAT_MSH:
    MSH_VERSION = 0.0;
    if(MSH_VERSION > 1.0){
      fprintf(meshfile, "$MeshFormat\n");
      fprintf(meshfile, "%g %d %d\n", MSH_VERSION, LIST_FORMAT_ASCII, sizeof(double));
      fprintf(meshfile, "$EndMeshFormat\n");
    }
    process_msh_nodes(M);
    process_msh_elements(M);
    Msg(INFO, "%d nodes", MSH_NODE_NUM);
    Msg(INFO, "%d elements", MSH_ELEMENT_NUM - 1);
    break;
  case FORMAT_VRML:
    process_wrl_nodes(M);
    process_wrl_elements(M);
    break;
  case FORMAT_UNV:
    process_unv_nodes(M);
    fprintf(meshfile, "%6d\n", -1);
    fprintf(meshfile, "%6d\n", ELEMENTS);
    ELEMENT_ID = 1;
    process_unv_3D_elements(M);
    process_unv_2D_elements(M);
    // process_1D_elements (M);
    fprintf(meshfile, "%6d\n", -1);
    process_unv_groups(M);
    break;
  case FORMAT_GREF:
    Tree_T *TRN = Tree_Create(sizeof(Vertex *), compareFrozen);
    Tree_T *TRE = Tree_Create(sizeof(Vertex *), compareFrozen);
    process_Gref_nodes(meshfile, M, TRN, TRE);
    process_Gref_elements(meshfile, M, Tree_Nbr(TRN));
    process_Gref_poundarybonditions(meshfile, M, TRN, TRE);
    Tree_Delete(TRN);
    Tree_Delete(TRE);
    EndConsecutiveNodes(M);
    break;
  }

  fclose(meshfile);
  Msg(INFO, "Wrote mesh file '%s'", name);
  Msg(STATUS2N, "Wrote '%s'", name);

  CTX.threads_lock = 0;
}
