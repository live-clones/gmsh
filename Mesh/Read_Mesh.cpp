// $Id: Read_Mesh.cpp,v 1.7 2001-01-12 13:29:00 geuzaine Exp $

#include "Gmsh.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"
#include "MinMax.h"

/* ------------------------------------------------------------------------ */
/*  M S H    F O R M A T                                                    */
/* ------------------------------------------------------------------------ */

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

/* relecture maillage au format MSH */

void Read_Mesh_MSH (Mesh *M, FILE *File_GEO){

  char String[256];
  int  Nbr_Nodes, Nbr_Elements, i_Node, i_Element;
  int  Num, Type, Physical, Elementary, i, j;
  double x , y , z, lc1, lc2 ;
  Vertex *vert , verts[NB_NOD_MAX_ELM] ,*vertsp[NB_NOD_MAX_ELM] , **vertspp;
  Simplex *simp ;
  Hexahedron *hex ;
  Prism *pri ;
  Curve   C , *c , **cc;
  Surface S , *s , **ss;
  Volume  V , *v , **vv;

  while (1) {
    do { 
      fgets(String,sizeof(String), File_GEO) ; 
      if (feof(File_GEO))  break ;
    } while (String[0] != '$') ;  
    
    if (feof(File_GEO))  break ;

    /*  P T S  */

    if (!strncmp(&String[1], "PTS", 3)) {

      fscanf(File_GEO, "%d", &Nbr_Nodes) ;
      Msg(INFO, "%d Points", Nbr_Nodes);

      for (i_Node = 0 ; i_Node < Nbr_Nodes ; i_Node++) {
        fscanf(File_GEO, "%d %lf %lf %lf %lf %lf", &Num, &x, &y, &z, &lc1, &lc2) ;
        vert = Create_Vertex (Num, x, y, z, lc1 , lc2);
        Tree_Replace(M->Points, &vert) ;
      }
    }

    /*  N O E  */

    if (!strncmp(&String[1], "NO", 2)) { /* $NOE or $NOD */

      fscanf(File_GEO, "%d", &Nbr_Nodes) ;
      Msg(INFO, "%d Nodes", Nbr_Nodes);

      for (i_Node = 0 ; i_Node < Nbr_Nodes ; i_Node++) {
        fscanf(File_GEO, "%d %lf %lf %lf", &Num, &x, &y, &z) ;
        vert = Create_Vertex (Num, x, y, z, 1.0 ,0.0);
        Tree_Replace(M->Vertices, &vert) ;
      }
    }

    /* ELEMENTS */

    else if (!strncmp(&String[1], "ELM", 3)) {

      fscanf(File_GEO, "%d", &Nbr_Elements) ;
      Msg(INFO, "%d Elements", Nbr_Elements);

      for (i_Element = 0 ; i_Element < Nbr_Elements ; i_Element++) {
        
        fscanf(File_GEO, "%d %d %d %d %d", 
               &Num, &Type, &Physical, &Elementary, &Nbr_Nodes) ;
        
        for (j = 0 ; j < Nbr_Nodes ; j++)
          fscanf(File_GEO, "%d", &verts[j].Num) ;
        
        switch(Type){
        case LGN1: case LGN2:
          c = &C; c->Num = Elementary;
          if(!(cc = (Curve**)Tree_PQuery(M->Curves, &c))){
            c = Create_Curve(Elementary, MSH_SEGM_LINE, 0, NULL,
                             NULL, 0, 1, 0., 1.);
            Tree_Add(M->Curves, &c);
          }
          else
            c = *cc;
          break;
        case TRI1: case QUA1: case TRI2: case QUA2:
          s = &S; s->Num = Elementary;
          if(!(ss = (Surface**)Tree_PQuery(M->Surfaces, &s))){
            s = Create_Surface(Elementary, MSH_SURF_PLAN, Elementary);
            Tree_Add(M->Surfaces, &s);
          }
          else
            s = *ss;
          break;
        case TET1: case HEX1: case PRI1: case TET2: case HEX2: case PRI2: 
          v = &V; v->Num = Elementary;
          if(!(vv = (Volume**)Tree_PQuery(M->Volumes, &v))){
            v = Create_Volume(Elementary, MSH_VOLUME, Elementary);
            Tree_Add(M->Volumes, &v);
          }
          else
            v = *vv;
          break;
        default :
          break;
        }

        for(i=0 ; i<Nbr_Nodes ; i++) {
          vertsp[i] = &verts[i];
          if(!(vertspp = (Vertex**)Tree_PQuery(M->Vertices, &vertsp[i])))
            Msg(GERROR, "Unknown Vertex %d in Element %d", verts[i].Num, Num);
          else
            vertsp[i] = *vertspp;
        }

        switch(Type){
        case LGN1:
          simp = Create_Simplex(vertsp[0], vertsp[1], NULL , NULL);
          simp->Num = Num ;
          simp->iEnt = Elementary ;
          Tree_Insert(c->Simplexes, &simp) ;
          Tree_Insert(M->Simplexes, &simp) ; 
          break;
        case TRI1:
          simp = Create_Simplex(vertsp[0], vertsp[1], vertsp[2], NULL);
          simp->Num = Num ;
          simp->iEnt = Elementary ;
          Tree_Insert(s->Simplexes, &simp) ;
          Tree_Insert(M->Simplexes, &simp) ;
          break;
        case QUA1:
          simp = Create_Quadrangle(vertsp[0], vertsp[1], vertsp[2], vertsp[3]);
          simp->Num = Num ;
          simp->iEnt = Elementary ;
          Tree_Insert(s->Simplexes, &simp) ;
          Tree_Insert(M->Simplexes, &simp) ;
          break;
        case TET1:
          simp = Create_Simplex(vertsp[0], vertsp[1], vertsp[2], vertsp[3]);
          simp->Num = Num ;
          simp->iEnt = Elementary ;
          Tree_Insert(v->Simplexes, &simp) ;
          Tree_Insert(M->Simplexes, &simp) ;
          break;
        case HEX1:
          hex = Create_Hexahedron(vertsp[0], vertsp[1], vertsp[2], vertsp[3],
                                  vertsp[4], vertsp[5], vertsp[6], vertsp[7]);
          hex->Num = Num ;
          hex->iEnt = Elementary ;
          Tree_Insert(v->Hexahedra, &hex) ;
          break;
        case PRI1:
          pri = Create_Prism(vertsp[0], vertsp[1], vertsp[2], 
                             vertsp[3], vertsp[4], vertsp[5]);
          pri->Num = Num ;
          pri->iEnt = Elementary ;
          Tree_Insert(v->Prisms, &pri) ;
          break;
        case PNT:
          break;
        default :
          Msg(WARNING, "Unknown Type of Element in Read_Mesh");
          break;
        }
      }

    }

    do {
      fgets(String, 256, File_GEO) ;
      if (feof(File_GEO)) Msg(GERROR, "Prematured End of Mesh File");
    } while (String[0] != '$') ;
    
  }   

  if(Tree_Nbr(M->Volumes))
    M->status = 3 ;
  else if(Tree_Nbr(M->Surfaces))
    M->status = 2 ;
  else if(Tree_Nbr(M->Curves))
    M->status = 1 ;
  else if(Tree_Nbr(M->Points))
    M->status = 0 ;
  else
    M->status = -1 ;

  CalculateMinMax(M->Points);
  
}

/* ------------------------------------------------------------------------ */
/*  R e a d _ M e s h                                                       */
/* ------------------------------------------------------------------------ */

void Read_Mesh (Mesh *M, FILE *File_GEO, int type){

  switch(type){
  case FORMAT_MSH : Read_Mesh_MSH(M,File_GEO); break;
  default : Msg(WARNING, "Unkown Mesh File Format to Read"); break;
  }

}
