// $Id: Read_Mesh.cpp,v 1.54 2003-04-14 22:55:56 geuzaine Exp $
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
#include "Geo.h"
#include "Mesh.h"
#include "3D_Mesh.h"
#include "Create.h"
#include "MinMax.h"
#include "Context.h"

extern Context_T CTX;

// Read mesh in the native MSH format

#define LGN1 1
#define TRI1 2
#define QUA1 3
#define TET1 4
#define HEX1 5
#define PRI1 6
#define PYR1 7
#define LGN2 8
#define TRI2 9
#define QUA2 10
#define TET2 11
#define HEX2 12
#define PRI2 13
#define PYR2 14
#define PNT  15

#define NB_NOD_MAX_ELM 20

int comparePhysicalGroup(const void *a, const void *b)
{
  PhysicalGroup *q, *w;
  int cmp;

  q = *(PhysicalGroup **) a;
  w = *(PhysicalGroup **) b;
  cmp = q->Typ - w->Typ;

  if(cmp)
    return cmp;
  else
    return (q->Num - w->Num);
}

void addPhysicalGroup(Mesh * M, int Type, int Physical, int Elementary)
{
  PhysicalGroup PG, *pg, **ppg;
  pg = &PG;
  pg->Typ = Type;
  pg->Num = Physical;
  if((ppg = (PhysicalGroup **) List_PQuery(M->PhysicalGroups, &pg,
                                           comparePhysicalGroup))) {
    List_Replace((*ppg)->Entities, &Elementary, fcmp_int);
  }
  else {
    List_T *tmp = List_Create(1, 1, sizeof(int));
    List_Add(tmp, &Elementary);
    Add_PhysicalGroup(Physical, Type, tmp, M);
    List_Delete(tmp);
  }
}

/* Note: the 'Dirty' flag only has an influence if one doesn't load
   the geometry along with the mesh (since we make Tree_Insert for the
   geometrical entities). And that's what we want. */

void Read_Mesh_MSH(Mesh * M, FILE * File_GEO)
{
  char String[256];
  int Nbr_Nodes, Nbr_Elements, i_Node, i_Element;
  int Num, Type, Physical, Elementary, i, j;
  double x, y, z, lc1, lc2;
  Vertex *vert, verts[NB_NOD_MAX_ELM], *vertsp[NB_NOD_MAX_ELM], **vertspp;
  Simplex *simp;
  Hexahedron *hex;
  Prism *pri;
  Pyramid *pyr;
  Curve C, *c, **cc;
  Surface S, *s, **ss;
  Volume V, *v, **vv;
  Tree_T *Duplicates = NULL;

  while(1) {
    do {
      fgets(String, sizeof(String), File_GEO);
      if(feof(File_GEO))
        break;
    } while(String[0] != '$');

    if(feof(File_GEO))
      break;

    /*  P T S  */

    if(!strncmp(&String[1], "PTS", 3)) {

      fscanf(File_GEO, "%d", &Nbr_Nodes);
      Msg(INFO, "%d Points", Nbr_Nodes);

      for(i_Node = 0; i_Node < Nbr_Nodes; i_Node++) {
        fscanf(File_GEO, "%d %lf %lf %lf %lf %lf", &Num, &x, &y, &z, &lc1,
               &lc2);
        vert = Create_Vertex(Num, x, y, z, lc1, lc2);
        if(!Tree_Insert(M->Points, &vert)){
	  Msg(GERROR, "Point %d already exists\n", vert->Num);
	  Free_Vertex(&vert, 0);
	}
      }
    }

    /*  N O E  */

    if(!strncmp(&String[1], "NO", 2)) { /* $NOE or $NOD */

      fscanf(File_GEO, "%d", &Nbr_Nodes);
      Msg(INFO, "%d Nodes", Nbr_Nodes);

      if(CTX.mesh.check_duplicates)
        Duplicates = Tree_Create(sizeof(Vertex *), comparePosition);
      for(i_Node = 0; i_Node < Nbr_Nodes; i_Node++) {
        fscanf(File_GEO, "%d %lf %lf %lf", &Num, &x, &y, &z);
        vert = Create_Vertex(Num, x, y, z, 1.0, 0.0);
        if(!Tree_Insert(M->Vertices, &vert)){
	  Msg(GERROR, "Node %d already exists\n", vert->Num);
	  Free_Vertex(&vert, 0);
	}
	else if(CTX.mesh.check_duplicates) {
          if((vertspp = (Vertex **) Tree_PQuery(Duplicates, &vert)))
            Msg(GERROR, "Nodes %d and %d have identical coordinates (%g, %g, %g)",
                Num, (*vertspp)->Num, x, y, z);
          else
            Tree_Add(Duplicates, &vert);
        }
      }
      if(CTX.mesh.check_duplicates)
        Tree_Delete(Duplicates);
    }

    /* ELEMENTS */

    else if(!strncmp(&String[1], "ELM", 3)) {

      fscanf(File_GEO, "%d", &Nbr_Elements);
      Msg(INFO, "%d Elements", Nbr_Elements);

      if(CTX.mesh.check_duplicates)
        Duplicates = Tree_Create(sizeof(Vertex *), comparePosition);

      for(i_Element = 0; i_Element < Nbr_Elements; i_Element++) {

        fscanf(File_GEO, "%d %d %d %d %d",
               &Num, &Type, &Physical, &Elementary, &Nbr_Nodes);
        //jf:  &Num, &Type, &Elementary, &Physical, &Nbr_Nodes) ;

        for(j = 0; j < Nbr_Nodes; j++)
          fscanf(File_GEO, "%d", &verts[j].Num);

        switch (Type) {
        case LGN1:
        case LGN2:
          c = &C;
          c->Num = abs(Elementary);
          if(!(cc = (Curve **) Tree_PQuery(M->Curves, &c))) {
            c = Create_Curve(abs(Elementary), MSH_SEGM_LINE, 0, NULL,
                             NULL, -1, -1, 0., 1.);
            c->Dirty = 1;
            Tree_Add(M->Curves, &c);
            addPhysicalGroup(M, MSH_PHYSICAL_LINE, Physical, abs(Elementary));
          }
          else
            c = *cc;
          break;
        case TRI1:
        case QUA1:
        case TRI2:
        case QUA2:
          s = &S;
          s->Num = Elementary;
          if(!(ss = (Surface **) Tree_PQuery(M->Surfaces, &s))) {
            s = Create_Surface(Elementary, MSH_SURF_PLAN);
            s->Dirty = 1;
            Tree_Add(M->Surfaces, &s);
            addPhysicalGroup(M, MSH_PHYSICAL_SURFACE, Physical, Elementary);
          }
          else
            s = *ss;
          break;
        case TET1:
        case HEX1:
        case PRI1:
        case PYR1:
        case TET2:
        case HEX2:
        case PRI2:
        case PYR2:
          v = &V;
          v->Num = Elementary;
          if(!(vv = (Volume **) Tree_PQuery(M->Volumes, &v))) {
            v = Create_Volume(Elementary, MSH_VOLUME);
            v->Dirty = 1;
            Tree_Add(M->Volumes, &v);
            addPhysicalGroup(M, MSH_PHYSICAL_VOLUME, Physical, Elementary);
          }
          else
            v = *vv;
          break;
        default:
          break;
        }

        for(i = 0; i < Nbr_Nodes; i++) {
          vertsp[i] = &verts[i];
          if(!(vertspp = (Vertex **) Tree_PQuery(M->Vertices, &vertsp[i])))
            Msg(GERROR, "Unknown vertex %d in element %d", verts[i].Num, Num);
          else
            vertsp[i] = *vertspp;
        }

        if(CTX.mesh.check_duplicates) {
          vert = Create_Vertex(Num, 0., 0., 0., 1.0, 0.0);
          for(i = 0; i < Nbr_Nodes; i++) {
            vert->Pos.X += vertsp[i]->Pos.X;
            vert->Pos.Y += vertsp[i]->Pos.Y;
            vert->Pos.Z += vertsp[i]->Pos.Z;
          }
          vert->Pos.X /= (double)Nbr_Nodes;
          vert->Pos.Y /= (double)Nbr_Nodes;
          vert->Pos.Z /= (double)Nbr_Nodes;
          if((vertspp = (Vertex **) Tree_PQuery(Duplicates, &vert)))
            Msg(WARNING, "Elements %d and %d have identical barycenters",
                Num, (*vertspp)->Num);
          else
            Tree_Add(Duplicates, &vert);
        }

        switch (Type) {
        case LGN1:
          simp = Create_Simplex(vertsp[0], vertsp[1], NULL, NULL);
          simp->Num = Num;
          simp->iEnt = Elementary;
          if(!Tree_Insert(c->Simplexes, &simp)){
	    Msg(GERROR, "Line element %d already exists\n", simp->Num);
	    Free_Simplex(&simp, 0);
	  }
          //NO!!! Tree_Insert(M->Simplexes, &simp) ; 
          break;
        case TRI1:
          simp = Create_Simplex(vertsp[0], vertsp[1], vertsp[2], NULL);
          simp->Num = Num;
          simp->iEnt = Elementary;
          if(Tree_Insert(s->Simplexes, &simp) && Tree_Insert(M->Simplexes, &simp)){
            M->Statistics[7]++;
	  }
          else{
	    Msg(GERROR, "Triangle %d already exists\n", simp->Num);
	    Free_Simplex(&simp, 0);
	  }
          break;
        case QUA1:
          simp = Create_Quadrangle(vertsp[0], vertsp[1], vertsp[2], vertsp[3]);
          simp->Num = Num;
          simp->iEnt = Elementary;
          if(Tree_Insert(s->Simplexes, &simp) && Tree_Insert(M->Simplexes, &simp)){
            M->Statistics[7]++; //since s->Simplexes holds quads, too :-(
            M->Statistics[8]++;
          }
	  else{
	    Msg(GERROR, "Quadrangle %d already exists\n", simp->Num);
	    Free_Simplex(&simp, 0);
	  }
          break;
        case TET1:
          simp = Create_Simplex(vertsp[0], vertsp[1], vertsp[2], vertsp[3]);
          simp->Num = Num;
          simp->iEnt = Elementary;
          if(Tree_Insert(v->Simplexes, &simp) && Tree_Insert(M->Simplexes, &simp)){
            M->Statistics[9]++;
	  }
	  else{
	    Msg(GERROR, "Tetrahedron %d already exists\n", simp->Num);
	    Free_Simplex(&simp, 0);
	  }
          break;
        case HEX1:
          hex = Create_Hexahedron(vertsp[0], vertsp[1], vertsp[2], vertsp[3],
                                  vertsp[4], vertsp[5], vertsp[6], vertsp[7]);
          hex->Num = Num;
          hex->iEnt = Elementary;
          if(Tree_Insert(v->Hexahedra, &hex)){
            M->Statistics[10]++;
	  }
	  else{
	    Msg(GERROR, "Hexahedron %d already exists\n", hex->Num);
	    Free_Hexahedron(&hex, 0);
	  }
          break;
        case PRI1:
          pri = Create_Prism(vertsp[0], vertsp[1], vertsp[2],
                             vertsp[3], vertsp[4], vertsp[5]);
          pri->Num = Num;
          pri->iEnt = Elementary;
          if(Tree_Insert(v->Prisms, &pri)){
            M->Statistics[11]++;
	  }
	  else{
	    Msg(GERROR, "Prism %d already exists\n", pri->Num);
	    Free_Prism(&pri, 0);
	  }
          break;
        case PYR1:
          pyr = Create_Pyramid(vertsp[0], vertsp[1], vertsp[2],
                               vertsp[3], vertsp[4]);
          pyr->Num = Num;
          pyr->iEnt = Elementary;
          if(Tree_Insert(v->Pyramids, &pyr)){
            M->Statistics[12]++;
	  }
	  else{
	    Msg(GERROR, "Pyramid %d already exists\n", pri->Num);
	    Free_Pyramid(&pyr, 0);
	  }
          break;
        case PNT:
	  // we need to make a new one: vertices in M->Vertices and
	  // M->Points should never point to the same memory location
	  vert = Create_Vertex(vertsp[0]->Num, vertsp[0]->Pos.X, vertsp[0]->Pos.Y, 
			       vertsp[0]->Pos.Z, vertsp[0]->lc, vertsp[0]->w);
          if(!Tree_Insert(M->Points, &vert)){
	    Msg(GERROR, "Point %d already exists\n", vert->Num);
	    Free_Vertex(&vert, 0);
	  }
          break;
        default:
          Msg(WARNING, "Unknown type of element in Read_Mesh");
          break;
        }
      }

      if(CTX.mesh.check_duplicates) {
        Tree_Action(Duplicates, Free_Vertex);
        Tree_Delete(Duplicates);
      }

    }

    do {
      fgets(String, 256, File_GEO);
      if(feof(File_GEO))
        Msg(GERROR, "Prematured end of mesh file");
    } while(String[0] != '$');

  }

  if(Tree_Nbr(M->Volumes)) {
    M->status = 3;
    M->Statistics[6] = Tree_Nbr(M->Vertices);   //incorrect, mais...
  }
  else if(Tree_Nbr(M->Surfaces)) {
    M->status = 2;
    M->Statistics[5] = Tree_Nbr(M->Vertices);   //incorrect, mais...
  }
  else if(Tree_Nbr(M->Curves)) {
    M->status = 1;
    M->Statistics[4] = Tree_Nbr(M->Vertices);   //incorrect, mais...
  }
  else if(Tree_Nbr(M->Points))
    M->status = 0;
  else
    M->status = -1;
}


// Public Read_Mesh routine

void Read_Mesh_SMS(Mesh * m, FILE * File_GEO);

void Read_Mesh(Mesh * M, FILE * File_GEO, int type)
{
  switch (type) {
  case FORMAT_MSH:
    Read_Mesh_MSH(M, File_GEO);
    break;
  case FORMAT_SMS:
    Read_Mesh_SMS(M, File_GEO);
    break;
  default:
    Msg(WARNING, "Unkown mesh file format to read");
    break;
  }
}
