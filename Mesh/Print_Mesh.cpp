// $Id: Print_Mesh.cpp,v 1.11 2001-01-09 19:40:56 remacle Exp $

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Create.h"
#include "Context.h"

extern Context_T CTX ;

/* ------------------------------------------------------------------------ */
/*  M S H    F O R M A T                                                    */
/* ------------------------------------------------------------------------ */

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

static FILE *mshfile;
static int MSH_NODE_NUM;
static int MSH_VOL_NUM, MSH_ELEMENT_NUM, MSH_ADD;
static int MSH_PHYSICAL_NUM, MSH_PHYSICAL_ORI;

void print_msh_node (void *a, void *b){
  Vertex **V;

  V = (Vertex **) a;

  fprintf (mshfile, "%d %.16g %.16g %.16g\n",
           (*V)->Num, 
           (*V)->Pos.X * CTX.mesh.scaling_factor, 
           (*V)->Pos.Y * CTX.mesh.scaling_factor, 
           (*V)->Pos.Z * CTX.mesh.scaling_factor);
}

void process_msh_nodes (Mesh * M){
  MSH_NODE_NUM = Tree_Nbr (M->Vertices) + Tree_Nbr (M->VertexEdges);

  fprintf (mshfile, "$NOD\n");
  fprintf (mshfile, "%d\n", MSH_NODE_NUM);
  Tree_Action (M->Vertices, print_msh_node);
  Tree_Action (M->VertexEdges, print_msh_node);
  fprintf (mshfile, "$ENDNOD\n");
}

void add_msh_simplex (void *a, void *b){
  Simplex **S;
  int i, type, nbn, nbs = 0;

  S = (Simplex **) a;

  if (MSH_VOL_NUM && (MSH_VOL_NUM != (*S)->iEnt))
    return;

  if (!MSH_ADD){
    MSH_ELEMENT_NUM++;
    return;
  }

  if (!(*S)->V[2]){
    nbn = 2;
    if ((*S)->VSUP){
      type = LINE_2;
      nbs = 1;
    }
    else
      type = LINE;
  }
  else if (!(*S)->V[3]){
    nbn = 3;
    if ((*S)->VSUP){
      type = TRIANGLE_2;
      nbs = 3;
    }
    else
      type = TRIANGLE;
  }
  else{
    nbn = 4;
    if (!MSH_VOL_NUM){
      if ((*S)->VSUP){
        type = QUADRANGLE_2;
        nbs = 5;
      }
      else
        type = QUADRANGLE;
    }
    else if ((*S)->VSUP){
      type = TETRAHEDRON_2;
      nbs = 1;
    }
    else
      type = TETRAHEDRON;
  }
  
  fprintf (mshfile, "%d %d %d %d %d",
           MSH_ELEMENT_NUM++, type,MSH_PHYSICAL_NUM,(*S)->iEnt, nbn + nbs);

  if (MSH_PHYSICAL_ORI > 0){
    for (i = 0; i < nbn; i++)
      fprintf (mshfile, " %d", (*S)->V[i]->Num);
    for (i = 0; i < nbs; i++)
      fprintf (mshfile, " %d", (*S)->VSUP[i]->Num);
  }
  else{
    for (i = 0; i < nbn; i++)
      fprintf (mshfile, " %d", (*S)->V[nbn - i - 1]->Num);
    for (i = 0; i < nbs; i++)
      fprintf (mshfile, " %d", (*S)->VSUP[nbs - i - 1]->Num);
  }

  fprintf (mshfile, "\n");
}

void add_msh_hexahedron (void *a, void *b){
  Hexahedron **H;
  int i, type, nbn, nbs = 0;

  H = (Hexahedron **) a;

  if (MSH_VOL_NUM && (MSH_VOL_NUM != (*H)->iEnt))
    return;

  if (!MSH_ADD){
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 8;
  if ((*H)->VSUP){
    type = HEXAHEDRON_2;
    nbs = 19;
  }
  else
    type = HEXAHEDRON;

  fprintf (mshfile, "%d %d %d %d %d",
           MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM, (*H)->iEnt, nbn + nbs);

  for (i = 0; i < nbn; i++)
    fprintf (mshfile, " %d", (*H)->V[i]->Num);
  for (i = 0; i < nbs; i++)
    fprintf (mshfile, " %d", (*H)->VSUP[i]->Num);

  fprintf (mshfile, "\n");
}

void add_msh_prism (void *a, void *b){
  Prism **P;
  int i, type, nbn, nbs = 0;

  P = (Prism **) a;

  if (MSH_VOL_NUM && (MSH_VOL_NUM != (*P)->iEnt))
    return;

  if (!MSH_ADD){
    MSH_ELEMENT_NUM++;
    return;
  }

  nbn = 6;
  if ((*P)->VSUP){
    type = PRISM_2;
    nbs = 12;
  }
  else{
    type = PRISM;
  }

  fprintf (mshfile, "%d %d %d %d %d",
           MSH_ELEMENT_NUM++, type, MSH_PHYSICAL_NUM, (*P)->iEnt, nbn + nbs);

  for (i = 0; i < nbn; i++)
    fprintf (mshfile, " %d", (*P)->V[i]->Num);
  for (i = 0; i < nbs; i++)
    fprintf (mshfile, " %d", (*P)->VSUP[i]->Num);

  fprintf (mshfile, "\n");
}

void add_msh_point (Vertex * V){

  if (!MSH_ADD){
    MSH_ELEMENT_NUM++;
    return;
  }

  fprintf (mshfile, "%d %d %d %d 1 %d\n",
           MSH_ELEMENT_NUM++, POINT, MSH_PHYSICAL_NUM, V->Num, V->Num);
}

void add_msh_elements (Mesh * M){
  int i, j, k, Num;

  PhysicalGroup *p;
  Volume *pV;
  Surface *ps, s;
  Curve *pc, c;
  Vertex *pv, v;

  List_T *ListVolumes = Tree2List (M->Volumes);

  for (i = 0; i < List_Nbr (M->PhysicalGroups); i++){
    List_Read (M->PhysicalGroups, i, &p);
    MSH_PHYSICAL_NUM = p->Num;
    MSH_VOL_NUM = 0;

    switch (p->Typ){

    case MSH_PHYSICAL_POINT:
      for (j = 0; j < List_Nbr (p->Entities); j++){
        pv = &v;
        List_Read (p->Entities, j, &Num);
        pv->Num = abs (Num);
        MSH_PHYSICAL_ORI = sign (Num);
        if (Tree_Query (M->Vertices, &pv))
          add_msh_point (pv);
      }
      break;

    case MSH_PHYSICAL_LINE:
      for (j = 0; j < List_Nbr (p->Entities); j++){
        pc = &c;
        List_Read (p->Entities, j, &Num);
        pc->Num = abs (Num);
        MSH_PHYSICAL_ORI = sign (Num);
        if (Tree_Query (M->Curves, &pc))
          Tree_Action (pc->Simplexes, add_msh_simplex);
      }
      break;

    case MSH_PHYSICAL_SURFACE:
      for (j = 0; j < List_Nbr (p->Entities); j++){
        ps = &s;
        List_Read (p->Entities, j, &Num);
        ps->Num = abs (Num);
        MSH_PHYSICAL_ORI = sign (Num);
        if (Tree_Query (M->Surfaces, &ps)){
          Tree_Action (ps->Simplexes, add_msh_simplex);
	}
      }
      break;

    case MSH_PHYSICAL_VOLUME:
      for (k = 0; k < List_Nbr (ListVolumes); k++){
        List_Read (ListVolumes, k, &pV);
        for (j = 0; j < List_Nbr (p->Entities); j++){
          List_Read (p->Entities, j, &Num);
          MSH_VOL_NUM = abs (Num);
          MSH_PHYSICAL_ORI = sign (Num);
          Tree_Action (pV->Simplexes, add_msh_simplex);
          Tree_Action (pV->Hexahedra, add_msh_hexahedron);
          Tree_Action (pV->Prisms, add_msh_prism);
        }
      }
      break;
      
    default :
      Msg(GERROR, "Unknown Type of Physical Group");
      break;
    }

  }

}

void process_msh_elements (Mesh * M){
  MSH_ADD = 0;
  MSH_ELEMENT_NUM = 1;
  add_msh_elements (M);
  fprintf (mshfile, "$ELM\n");
  fprintf (mshfile, "%d\n", MSH_ELEMENT_NUM - 1);

  if (MSH_ELEMENT_NUM == 1)
    Msg (WARNING, "No Elements (Did You Forget to Define Physical Entities?)");

  MSH_ADD = 1;
  MSH_ELEMENT_NUM = 1;
  add_msh_elements (M);
  fprintf (mshfile, "$ENDELM\n");
}


/* ------------------------------------------------------------------------ */
/*  U N V   F O R M A T                                                     */
/* ------------------------------------------------------------------------ */

/* Numeros des enregistrements IDEAS */
#define HEADER       151
#define UNITS        164
#define NODES        2411
#define ELEMENTS     2412
#define RESNODE      55
#define RESELEM      56
#define RESVECT      57
#define GROUPOFNODES 790

/* Numeros des elements IDEAS */
#define BEAM         21
#define BEAM2        24
#define THINSHLL     91
#define THINSHLL2    92
#define QUAD         94
#define QUAD2        95         /* Ca c'est une impro !!! */
#define SOLIDFEM     111
#define WEDGE        112
#define BRICK        115
#define SOLIDFEM2    118

void process_nodes (FILE * funv, Mesh * M){
  int nbnod;
  double x, y, z;
  int i, idnod;
  Vertex *v;

  List_T *Nodes = Tree2List (M->Vertices);

  fprintf (funv, "%6d\n", -1);
  fprintf (funv, "%6d\n", NODES);
  nbnod = List_Nbr (Nodes);

  for (i = 0; i < nbnod; i++){
    List_Read (Nodes, i, &v);
    idnod = v->Num;
    x = v->Pos.X * CTX.mesh.scaling_factor;
    y = v->Pos.Y * CTX.mesh.scaling_factor;
    z = v->Pos.Z * CTX.mesh.scaling_factor;
    fprintf (funv, "%10d%10d%10d%10d\n", idnod, 1, 1, 11);
    fprintf (funv, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", x, y, z);
  }

  List_Delete (Nodes);
  Nodes = Tree2List (M->VertexEdges);
  nbnod = List_Nbr (Nodes);

  for (i = 0; i < nbnod; i++){
    List_Read (Nodes, i, &v);
    idnod = v->Num;
    x = v->Pos.X * CTX.mesh.scaling_factor;
    y = v->Pos.Y * CTX.mesh.scaling_factor;
    z = v->Pos.Z * CTX.mesh.scaling_factor;
    fprintf (funv, "%10d%10d%10d%10d\n", idnod, 1, 1, 11);
    fprintf (funv, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", x, y, z);
  }
  
  fprintf (funv, "%6d\n", -1);
}

static int ELEMENT_ID;

int process_2D_elements (FILE * funv, Mesh * m){
  List_T *ListSurfaces = Tree2List (m->Surfaces);
  List_T *ListVolumes = Tree2List (m->Volumes);
  List_T *Elements;
  Volume *vol;
  List_T *AllSurfaces = List_Create (2, 2, sizeof (Surface *));
  Simplex *sx;
  Surface *s;
  int nbtri = 0, i, j, nsup, n, ntot, k, geo, fetyp;

  for (i = 0; i < List_Nbr (ListVolumes); i++){
    List_Read (ListVolumes, i, &vol);
    for (j = 0; j < List_Nbr (vol->Surfaces); j++){
      List_Read (vol->Surfaces, j, &s);
      if (Tree_Nbr (s->Simplexes))
        List_Add (AllSurfaces, &s);
    }
  }

  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    if (!List_Search (AllSurfaces, &s, compareSurface)){
      Elements = Tree2List (s->Simplexes);
      for (j = 0; j < List_Nbr (Elements); j++){
        List_Read (Elements, j, &sx);
        if (sx->V[3]){
          if (sx->VSUP){
            fetyp = QUAD;
            n = 4;
            nsup = 4;
          }
          else{
            fetyp = QUAD;
            n = 4;
            nsup = 0;
          }
        }
        else{
          if (sx->VSUP){
            fetyp = THINSHLL;
            n = 3;
            nsup = 3;
          }
          else{
            fetyp = THINSHLL;
            nsup = 0;
            n = 3;
          }
        }
        geo = s->Num;
        fprintf (funv, "%10d%10d%10d%10d%10d%10d\n", 
                 /*ELEMENT_ID++ */ sx->Num, fetyp, geo, geo, 7, n + nsup);
        ntot = 0;
        for (k = 0; k < n; k++){
          fprintf (funv, "%10d", sx->V[k]->Num);
          if (ntot % 8 == 7)
            fprintf (funv, "\n");
          ntot++;
        }
        for (k = 0; k < nsup; k++){
          fprintf (funv, "%10d", sx->VSUP[k]->Num);
          if (ntot % 8 == 7)
            fprintf (funv, "\n");
          ntot++;
        }
        if (ntot - 1 % 8 != 7)
          fprintf (funv, "\n");
      }
      List_Delete (Elements);
      nbtri += Tree_Nbr (s->Simplexes);
    }
  }
  List_Delete (ListSurfaces);
  List_Delete (ListVolumes);
  List_Delete (AllSurfaces);
  return 0;
}

int process_1D_elements (FILE * funv, Mesh * m){
  List_T *ListCurves = Tree2List (m->Curves);
  List_T *AllCurves = List_Create (2, 2, sizeof (Surface *));
  List_T *ListSurfaces = Tree2List (m->Surfaces);
  List_T *Elements;
  Simplex *sx;
  Curve *c;
  Surface *surf;
  int nblig = 0, k, ntot, i, j, geo, fetyp, n, nsup;

  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &surf);
    for (j = 0; j < List_Nbr (surf->s.Generatrices); j++){
      List_Read (surf->s.Generatrices, j, &c);
      if (Tree_Nbr (c->Simplexes))
        List_Add (AllCurves, &c);
      c = FindCurve (-c->Num, m);
      if (Tree_Nbr (c->Simplexes))
        List_Add (AllCurves, &c);
    }
  }

  for (i = 0; i < List_Nbr (ListCurves); i++){
    List_Read (ListCurves, i, &c);
    if (!List_Search (AllCurves, &c, compareCurve)){
      Elements = Tree2List (c->Simplexes);
      for (j = 0; j < List_Nbr (Elements); j++){
        nblig++;
        List_Read (Elements, j, &sx);
        if (sx->VSUP){
          fetyp = BEAM2;
          n = 2;
          nsup = 2;
        }
        else{
          fetyp = BEAM;
          n = 2;
          nsup = 0;
        }
        geo = c->Num;
        fprintf (funv, "%10d%10d%10d%10d%10d%10d\n", 
                 /*ELEMENT_ID++ */ sx->Num, fetyp, geo, geo, 7, n + nsup);
        ntot = 0;
        fprintf (funv, "%10d%10d%10d\n", 0, 0, 0);
        for (k = 0; k < n; k++){
          fprintf (funv, "%10d", sx->V[k]->Num);
          if (ntot % 8 == 7)
            fprintf (funv, "\n");
          ntot++;
        }
        for (k = 0; k < nsup; k++){
          fprintf (funv, "%10d", sx->VSUP[k]->Num);
          if (ntot % 8 == 7)
            fprintf (funv, "\n");
          ntot++;
        }
        if (ntot - 1 % 8 != 7)
          fprintf (funv, "\n");
      }
      
      List_Delete (Elements);
    }
  }
  List_Delete (AllCurves);
  List_Delete (ListSurfaces);
  List_Delete (ListCurves);
  return 0;
}

int process_3D_elements (FILE * funv, Mesh * m){
  List_T *ListVolumes = Tree2List (m->Volumes);
  List_T *Elements;
  Simplex *sx;
  Hexahedron *hx;
  Prism *px;
  Volume *v;
  int nb = 0, i, j, nsup, n, ntot, k, geo, fetyp;

  for (i = 0; i < List_Nbr (ListVolumes); i++){
    List_Read (ListVolumes, i, &v);
    // TETRAEDRON
    Elements = Tree2List (v->Simplexes);
    for (j = 0; j < List_Nbr (Elements); j++){
      List_Read (Elements, j, &sx);
      if (sx->VSUP){
        fetyp = SOLIDFEM;
        n = 4;
        nsup = 6;
      }
      else{
        fetyp = SOLIDFEM;
        nsup = 0;
        n = 4;
      }
      if (sx->Volume_Simplexe () < 0){
        Vertex *temp;
        temp = sx->V[0];
        sx->V[0] = sx->V[1];
        sx->V[1] = temp;
        if (sx->Volume_Simplexe () < 0)
          Msg(WARNING, "Negative Volume for Simplex %d", sx->Num);
      }
      geo = v->Num;
      fprintf (funv, "%10d%10d%10d%10d%10d%10d\n",
               ELEMENT_ID++, fetyp, geo, geo, 7, n + nsup);
      ntot = 0;
      for (k = 0; k < n; k++){
        fprintf (funv, "%10d", sx->V[k]->Num);
        if (ntot % 8 == 7)
          fprintf (funv, "\n");
        ntot++;
      }
      for (k = 0; k < nsup; k++){
        fprintf (funv, "%10d", sx->VSUP[k]->Num);
        if (ntot % 8 == 7)
          fprintf (funv, "\n");
        ntot++;
      }
      if (ntot - 1 % 8 != 7)
        fprintf (funv, "\n");
    }
    List_Delete (Elements);
    nb += Tree_Nbr (v->Simplexes);
    
    // PRISMS
    Elements = Tree2List (v->Prisms);
    for (j = 0; j < List_Nbr (Elements); j++){
      List_Read (Elements, j, &px);
      if (px->VSUP){
        fetyp = WEDGE;
        n = 6;
        nsup = 9;
      }
      else{
        fetyp = WEDGE;
        nsup = 0;
        n = 6;
      }
      
      geo = v->Num;
      fprintf (funv, "%10d%10d%10d%10d%10d%10d\n", 
               ELEMENT_ID++, fetyp, geo, geo, 7, n + nsup);
      ntot = 0;
      for (k = 0; k < n; k++){
        fprintf (funv, "%10d", px->V[k]->Num);
        if (ntot % 8 == 7)
          fprintf (funv, "\n");
        ntot++;
      }
      for (k = 0; k < nsup; k++){
        fprintf (funv, "%10d", px->VSUP[k]->Num);
        if (ntot % 8 == 7)
          fprintf (funv, "\n");
        ntot++;
      }
      if (ntot - 1 % 8 != 7)
        fprintf (funv, "\n");
    }
    List_Delete (Elements);
    nb += Tree_Nbr (v->Prisms);
    
    // HEXAHEDRONS
    Elements = Tree2List (v->Hexahedra);
    for (j = 0; j < List_Nbr (Elements); j++){
      List_Read (Elements, j, &hx);
      if (hx->VSUP){
        fetyp = BRICK;
        n = 8;
        nsup = 12;
      }
      else{
        fetyp = BRICK;
        nsup = 0;
        n = 8;
      }
      
      geo = v->Num;
      fprintf (funv, "%10d%10d%10d%10d%10d%10d\n", 
               ELEMENT_ID++, fetyp, geo, geo, 7, n + nsup);
      ntot = 0;
      for (k = 0; k < n; k++){
        fprintf (funv, "%10d", hx->V[k]->Num);
        if (ntot % 8 == 7)
          fprintf (funv, "\n");
        ntot++;
      }
      for (k = 0; k < nsup; k++){
        fprintf (funv, "%10d", hx->VSUP[k]->Num);
        if (ntot % 8 == 7)
          fprintf (funv, "\n");
        ntot++;
      }
      if (ntot - 1 % 8 != 7)
        fprintf (funv, "\n");
    }
    List_Delete (Elements);
    nb += Tree_Nbr (v->Hexahedra);
  }
  List_Delete (ListVolumes);
  return nb;
}

FILE *unvfile;
Tree_T *tree;

void AddVertex (void *a, void *b){
  Vertex *v;
  v = *(Vertex **) a;
  if (Tree_Search (tree, &v->Num))
    return;
  Tree_Add (tree, &v->Num);
  fprintf (unvfile, "%10d%10d%2d%2d%2d%2d%2d%2d\n", v->Num, 1, 0, 1, 0, 0, 0, 0);
  fprintf (unvfile, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", 0., 1., 0.);
  fprintf (unvfile, "%21.16fD+00 %21.16fD+00 %21.16fD+00\n", 0., 0., 0.);
  fprintf (unvfile, "%10d%10d%10d%10d%10d%10d\n", 0, 0, 0, 0, 0, 0);
}

void PrintGroups (Mesh * m){
  int  nb, j, i, k;
  Surface *ps, s;
  Curve *pc, c;
  Vertex *pv, v;
  PhysicalGroup *p;

  for (i = 0; i < List_Nbr (m->PhysicalGroups); i++){

    List_Read (m->PhysicalGroups, i, &p);
    if (p->Typ == MSH_PHYSICAL_SURFACE){
      tree = Tree_Create (sizeof (int), fcmp_absint);
      fprintf (unvfile, "%6d\n", -1);
      fprintf (unvfile, "%6d\n", GROUPOFNODES);
      fprintf (unvfile, "%10d%10d\n", p->Num, 1);
      fprintf (unvfile, "LOAD SET %2d\n", 1);
      nb = List_Nbr (p->Entities);
      for (j = 0; j < nb; j++){
        ps = &s;
        List_Read (p->Entities, j, &ps->Num);
        if (Tree_Query (m->Surfaces, &ps))
          Tree_Action (ps->Vertices, AddVertex);
      }
      fprintf (unvfile, "%6d\n", -1);
      //Tree_Delete(tree);
      //free(tree);
    }
    if (p->Typ == MSH_PHYSICAL_LINE){
      tree = Tree_Create (sizeof (int), fcmp_absint);
      fprintf (unvfile, "%6d\n", -1);
      fprintf (unvfile, "%6d\n", GROUPOFNODES);
      fprintf (unvfile, "%10d%10d\n", p->Num, 1);
      fprintf (unvfile, "LOAD SET %2d\n", 1);
      nb = List_Nbr (p->Entities);
      for (j = 0; j < nb; j++){
        pc = &c;
        List_Read (p->Entities, j, &pc->Num);
        if (Tree_Query (m->Curves, &pc))
          for (k = 0; k < List_Nbr (pc->Vertices); k++)
            AddVertex (List_Pointer (pc->Vertices, k), NULL);
      }
      fprintf (unvfile, "%6d\n", -1);
      //Tree_Delete(tree);
    }
    if (p->Typ == MSH_PHYSICAL_POINT){
      tree = Tree_Create (sizeof (int), fcmp_absint);
      fprintf (unvfile, "%6d\n", -1);
      fprintf (unvfile, "%6d\n", GROUPOFNODES);
      fprintf (unvfile, "%10d%10d\n", p->Num, 1);
      fprintf (unvfile, "LOAD SET %2d\n", 1);
      nb = List_Nbr (p->Entities);
      for (j = 0; j < nb; j++){
        pv = &v;
        List_Read (p->Entities, j, &pv->Num);
        if (Tree_Query (m->Vertices, &pv))
          AddVertex (&pv, NULL);
      }
      fprintf (unvfile, "%6d\n", -1);
      //Tree_Delete(tree);
    }
  }
}

/* ------------------------------------------------------------------------ */
/*  G R E F   F O R M A T                                                   */
/* ------------------------------------------------------------------------ */

void ConsecutiveNodes (Mesh * M, Tree_T * ConstecutiveNTree, Tree_T * ConsecutiveETree);

static int compareFrozen (const void *a, const void *b){
  Vertex *q, *w;
  q = *(Vertex **) a;
  w = *(Vertex **) b;
  return w->Frozen - q->Frozen;
}

int process_Gref_nodes (FILE * fGref, Mesh * M,
                        Tree_T * ConsecutiveNTree, Tree_T * ConsecutiveETree){
  int i, nbtri;
  Vertex *v;
  Surface *s;
  Curve *c;
  List_T *ListSurfaces, *ListCurves, *Nodes;

  ListCurves = Tree2List (M->Curves);
  for (i = 0; i < List_Nbr (ListCurves); i++){
    List_Read (ListCurves, i, &c);
    Degre2 (M->Vertices, M->VertexEdges, c->Simplexes, c, NULL);
  }
  List_Delete (ListCurves);

  ListSurfaces = Tree2List (M->Surfaces);
  nbtri = 0;
  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Degre2 (M->Vertices, M->VertexEdges, s->Simplexes, NULL, s);
    nbtri += Tree_Nbr (s->Simplexes);
  }
  List_Delete (ListSurfaces);

  ConsecutiveNodes (M, ConsecutiveNTree, ConsecutiveETree);

  fprintf (fGref, "%d %d %d\n", nbtri, Tree_Nbr (ConsecutiveNTree),
           Tree_Nbr (ConsecutiveNTree) + Tree_Nbr (ConsecutiveETree));

  Nodes = Tree2List (ConsecutiveNTree);
  for (i = 0; i < List_Nbr (Nodes); i++){
    List_Read (Nodes, i, &v);
    fprintf (fGref, "%21.16e ", v->Pos.X * CTX.mesh.scaling_factor);
    if (i % 3 == 2)
      fprintf (fGref, "\n");
  }
  if ((List_Nbr (Nodes) - 1) % 3 != 2)
    fprintf (fGref, "\n");
  for (i = 0; i < List_Nbr (Nodes); i++){
    List_Read (Nodes, i, &v);
    fprintf (fGref, "%21.16e ", v->Pos.Y * CTX.mesh.scaling_factor);
    if (i % 3 == 2)
      fprintf (fGref, "\n");
  }
  if ((List_Nbr (Nodes) - 1) % 3 != 2)
    fprintf (fGref, "\n");
  i = Tree_Nbr (ConsecutiveNTree);
  List_Delete (Nodes);
  return i;
}

int find_physicalentity (Vertex * v, Mesh * m){
  PhysicalGroup *p;
  Curve *c;
  int i, j;
  for (i = 0; i < List_Nbr (m->PhysicalGroups); i++){
    List_Read (m->PhysicalGroups, i, &p);
    if (p->Typ == MSH_PHYSICAL_POINT){
      if (List_Search (p->Entities, &v->Num, fcmp_absint)){
        return p->Num;
      }
    }
  }
  
  if (v->ListCurves){
    for (i = 0; i < List_Nbr (m->PhysicalGroups); i++){
      List_Read (m->PhysicalGroups, i, &p);
      if (p->Typ == MSH_PHYSICAL_LINE){
        for (j = 0; j < List_Nbr (v->ListCurves); j++){
          List_Read (v->ListCurves, j, &c);
          if (List_Search (p->Entities, &c->Num, fcmp_absint)){
            return p->Num;
          }
        }
      }
    }
  }
  return 0;
}

void process_Gref_poundarybonditions (FILE * fGref, Mesh * M,
                                      Tree_T * TRN, Tree_T * TRE){
  int i, ent;
  Vertex *v;

  List_T *Nodes = Tree2List (TRN);
  for (i = 0; i < List_Nbr (Nodes); i++){
    List_Read (Nodes, i, &v);
    ent = find_physicalentity (v, M);
    fprintf (fGref, "%d %d ", ent, ent);
    if (i % 3 == 2)
      fprintf (fGref, "\n");
  }
  if ((List_Nbr (Nodes) - 1) % 3 != 2)
    fprintf (fGref, "\n");
  List_Delete (Nodes);

  Nodes = Tree2List (TRE);
  for (i = 0; i < List_Nbr (Nodes); i++){
    List_Read (Nodes, i, &v);
    ent = find_physicalentity (v, M);
    fprintf (fGref, "%d %d ", ent, ent);
    if (i % 3 == 2)
      fprintf (fGref, "\n");
  }
  if ((List_Nbr (Nodes) - 1) % 3 != 2)
    fprintf (fGref, "\n");
  List_Delete (Nodes);
}

void process_Gref_elements (FILE * fGref, Mesh * M, int nn){
  int i, j;
  Simplex *sx;
  Surface *s;
  List_T *Triangles;
  List_T *ListSurfaces;

  ListSurfaces = Tree2List (M->Surfaces);
  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Triangles = Tree2List (s->Simplexes);
    for (j = 0; j < List_Nbr (Triangles); j++){
      List_Read (Triangles, j, &sx);
      if (!sx->V[3])
        fprintf (fGref, "%d %d %d\n", -sx->V[0]->Frozen, 
                 -sx->V[1]->Frozen, -sx->V[2]->Frozen);
      else
        fprintf (fGref, "%d %d %d %d\n", -sx->V[0]->Frozen,
                 -sx->V[1]->Frozen,
                 -sx->V[2]->Frozen,
                 -sx->V[3]->Frozen);
      
    }
    List_Delete (Triangles);
  }

  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Triangles = Tree2List (s->Simplexes);
    for (j = 0; j < List_Nbr (Triangles); j++){
      List_Read (Triangles, j, &sx);
      if (!sx->V[3])
        fprintf (fGref, "%d %d %d\n", -sx->VSUP[0]->Frozen - nn,
                 -sx->VSUP[1]->Frozen - nn,
                 -sx->VSUP[2]->Frozen - nn);
      else
        fprintf (fGref, "%d %d %d %d\n", -sx->VSUP[0]->Frozen - nn,
                 -sx->VSUP[1]->Frozen - nn,
                 -sx->VSUP[2]->Frozen - nn,
                 -sx->VSUP[3]->Frozen - nn);
    }
    List_Delete (Triangles);
  }
  // Degres de Liberte
  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Triangles = Tree2List (s->Simplexes);
    for (j = 0; j < List_Nbr (Triangles); j++){
      List_Read (Triangles, j, &sx);
      if (!sx->V[3])
        fprintf (fGref, "%d %d %d %d %d %d %d %d %d %d %d %d\n",
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
                 -2 * sx->VSUP[2]->Frozen);
      else
        fprintf (fGref, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
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
                 -2 * sx->VSUP[3]->Frozen - 1,
                 -2 * sx->VSUP[3]->Frozen);
    }
    List_Delete (Triangles);
  }
  List_Delete (ListSurfaces);
}

FILE *Greffile;

void ConsecutiveNodes (Mesh * M, Tree_T * ConsecutiveNTree, Tree_T * ConsecutiveETree){
  int i, j, k;
  Simplex *sx;
  Surface *s;
  List_T *Triangles;
  int nbnod, nbedges, nbdof;
  List_T *ListSurfaces;

  int newnum = 0, N;

  ListSurfaces = Tree2List (M->Surfaces);
  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Triangles = Tree2List (s->Simplexes);
    for (j = 0; j < List_Nbr (Triangles); j++){
      List_Read (Triangles, j, &sx);
      if (!sx->V[3])
        N = 3;
      else
        N = 4;
      for (k = 0; k < N; k++){
        if (sx->V[k]->Frozen >= 0){
          sx->V[k]->Frozen = --newnum;
          Tree_Insert (ConsecutiveNTree, &(sx->V[k]));
        }
      }
    }
    List_Delete (Triangles);
  }
  nbnod = -newnum;
  ListSurfaces = Tree2List (M->Surfaces);
  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Triangles = Tree2List (s->Simplexes);
    for (j = 0; j < List_Nbr (Triangles); j++){
      List_Read (Triangles, j, &sx);
      if (!sx->V[3])
        N = 3;
      else
        N = 4;
      for (k = 0; k < N; k++){
        if (sx->VSUP[k]->Frozen >= 0){
          sx->VSUP[k]->Frozen = --newnum;
          Tree_Insert (ConsecutiveETree, &(sx->VSUP[k]));
        }
      }
    }
    List_Delete (Triangles);
  }
  nbedges = -newnum - nbnod;
  nbdof = nbnod + nbedges;
  Msg(INFOS, "%d Dofs", nbdof);
}

void EndConsecutiveNodes (Mesh * M){
  int i, j, k;
  Simplex *sx;
  Surface *s;
  List_T *Triangles;
  List_T *ListSurfaces;
  int N;

  ListSurfaces = Tree2List (M->Surfaces);
  for (i = 0; i < List_Nbr (ListSurfaces); i++){
    List_Read (ListSurfaces, i, &s);
    Triangles = Tree2List (s->Simplexes);
    for (j = 0; j < List_Nbr (Triangles); j++){
      List_Read (Triangles, j, &sx);
      if (!sx->V[3])
        N = 3;
      else
        N = 4;
      for (k = 0; k < N; k++)
        sx->V[k]->Frozen = 0;
      for (k = 0; k < N; k++)
        sx->VSUP[k]->Frozen = 0;
    }
    List_Delete (Triangles);
  }
  List_Delete (ListSurfaces);
}

/* ------------------------------------------------------------------------ */
/*  P r i n t _ M e s h                                                     */
/* ------------------------------------------------------------------------ */

void Print_Mesh (Mesh * M, char *c, int Type){
  char name[256];
  strcpy (name, M->name);

  if (Type == FORMAT_MSH){
    c ? strcpy (name, c) : strcat (name, ".msh");
    mshfile = fopen (name, "w");
    if (!mshfile){
      Msg(WARNING, "Unable to Open File '%s'", name);
      return;
    }
    Msg (INFOS, "Writing File '%s'", name);
    process_msh_nodes (M);
    process_msh_elements (M);
    Msg (INFOS, "Msh Ouput Complete '%s' (%d Nodes, %d Elements)",
         name, MSH_NODE_NUM, MSH_ELEMENT_NUM - 1);
    Msg (INFO, "Wrote File '%s'", name);
    fclose (mshfile);
  }
  else if (Type == FORMAT_UNV){
    c ? strcpy (name, c) : strcat (name, ".unv");
    unvfile = fopen (name, "w");
    if (!unvfile){
      Msg(WARNING, "Unable to Open File '%s'", name);
      return;
    }
    Msg (INFOS, "Writing File '%s'", name);
    process_nodes (unvfile, M);
    fprintf (unvfile, "%6d\n", -1);
    fprintf (unvfile, "%6d\n", ELEMENTS);
    ELEMENT_ID = 1;
    process_3D_elements (unvfile, M);
    process_2D_elements (unvfile, M);
    process_1D_elements (unvfile, M);
    fprintf (unvfile, "%6d\n", -1);
    PrintGroups (M);
    fclose (unvfile);
    Msg (INFOS, "Unv Ouput Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
  }
  else if (Type == FORMAT_GREF){
    c ? strcpy (name, c) : strcat (name, ".Gref");
    Tree_T *TRN = Tree_Create (sizeof (Vertex *), compareFrozen);
    Tree_T *TRE = Tree_Create (sizeof (Vertex *), compareFrozen);
    Greffile = fopen (name, "w");
    if (!Greffile){
      Msg(WARNING, "Unable to Open File '%s'", name);
      return;
    }
    Msg (INFOS, "Writing File '%s'", name);
    process_Gref_nodes (Greffile, M, TRN, TRE);
    process_Gref_elements (Greffile, M, Tree_Nbr (TRN));
    process_Gref_poundarybonditions (Greffile, M, TRN, TRE);
    fclose (Greffile);
    Tree_Delete (TRN);
    Tree_Delete (TRE);
    EndConsecutiveNodes (M);
    Msg (INFOS, "Gref Ouput Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
  }
}
