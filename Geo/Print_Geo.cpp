// $Id: Print_Geo.cpp,v 1.21 2001-08-27 11:19:18 geuzaine Exp $

#include "Gmsh.h"
#include "Geo.h"
#include "Mesh.h"
#include "Vertex.h"
#include "CAD.h"
#include "Context.h"

FILE *FOUT;

void Print_Point(void *a, void *b){
  Vertex *v;
  v = *(Vertex**)a;
  fprintf(FOUT, "Point(%d) = {%g, %g, %g, %g};\n",
          v->Num,v->Pos.X,v->Pos.Y,v->Pos.Z,v->lc);
}

void Print_Nurbs (Curve *c, FILE *f){
  int i,j;
  Vertex *v;

  fprintf(f,"Nurbs (%d) = {",c->Num);
  for(i=0;i<List_Nbr(c->Control_Points);i++){
    List_Read(c->Control_Points,i,&v);
    if(!i)
      fprintf(FOUT,"%d",v->Num);
    else
      fprintf(FOUT,", %d",v->Num);
    if(i%8 == 7 && i!=List_Nbr(c->Control_Points)-1)fprintf(FOUT,"\n");
  }
  fprintf(f,"}\n");
  fprintf(f,"  Knots {");
  for(j=0;j<List_Nbr(c->Control_Points)+c->degre+1;j++){
    if(!j)fprintf(f,"%g",c->k[j]);
    else fprintf(f,", %g",c->k[j]);
    if(j%5 == 4 && j!=List_Nbr(c->Control_Points)+c->degre)fprintf(FOUT,"\n        ");
  }
  fprintf(f,"}\n");
  fprintf(f,"  Order %d;\n",c->degre);
}

void Print_Curve(void *a, void *b){
  Curve *c;
  Vertex *v;
  int i;
  c = *(Curve**)a;

  if(c->Num < 0 || c->Dirty)return;

  switch(c->Typ){
  case MSH_SEGM_LINE:
    fprintf(FOUT,"Line (%d) = ",c->Num);
    break;
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
    fprintf(FOUT,"Circle (%d) = ",c->Num);
    break;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    fprintf(FOUT,"Ellipsis (%d) = ",c->Num);
    break;
  case MSH_SEGM_NURBS:
    Print_Nurbs(c,FOUT);
    return;
  case MSH_SEGM_SPLN:
    fprintf(FOUT,"CatmullRom (%d) = ",c->Num);
    break;
  case MSH_SEGM_BSPLN:
    fprintf(FOUT,"BSpline (%d) = ",c->Num);
    break;
  case MSH_SEGM_BEZIER:
    fprintf(FOUT,"Bezier (%d) = ",c->Num);
    break;
  default:
    Msg(GERROR, "Unknown Curve type %d", c->Typ);
    return;
  }
  
  for(i=0;i<List_Nbr(c->Control_Points);i++){
    List_Read(c->Control_Points,i,&v);
    if(i)
      fprintf(FOUT,", %d",v->Num);
    else
      fprintf(FOUT,"{%d",v->Num);
    if(i%6 == 7)fprintf(FOUT,"\n");
  }

  switch(c->Typ){
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    fprintf(FOUT,"} Plane{%g, %g, %g};\n",
            c->Circle.n[0],c->Circle.n[1],c->Circle.n[2]);
    break;
  default :
    fprintf(FOUT,"};\n");
    break;
  }
  
}

void Print_Surface(void *a, void *b){
  Curve *c;
  Surface *s;
  Vertex *v;
  int i,j;
  s = *(Surface**)a;

  if(s->Dirty) return;

  int NUMLOOP = s->Num + 1000000;

  if(s->Typ != MSH_SURF_NURBS){
    fprintf(FOUT,"Line Loop (%d) = ",NUMLOOP);
    
    for(i=0;i<List_Nbr(s->Generatrices);i++){
      List_Read(s->Generatrices,i,&c);
      if(i)
        fprintf(FOUT,", %d",c->Num);
      else
        fprintf(FOUT,"{%d",c->Num);
    }
    fprintf(FOUT,"};\n");
  }

  switch(s->Typ){
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC:
    fprintf(FOUT,"Ruled Surface (%d) = {%d};\n",s->Num,NUMLOOP);
    break;
  case MSH_SURF_PLAN:
    fprintf(FOUT,"Plane Surface (%d) = {%d};\n",s->Num,NUMLOOP);
    break;
  case MSH_SURF_TRIMMED:
    fprintf(FOUT,"Trimmed Surface (%d) = %d {%d};\n",s->Num,s->Support->Num,NUMLOOP);
    break;
  case MSH_SURF_NURBS:
    fprintf(FOUT,"Nurbs Surface (%d) = {\n",s->Num);
    for(i=0;i<s->Nv;i++){
      fprintf(FOUT,"  {");
      for(j=0;j<s->Nu;j++){
        List_Read(s->Control_Points,j+s->Nu *i,&v);
        if(!j)
          fprintf(FOUT,"%d",v->Num);
        else
          fprintf(FOUT,", %d",v->Num);
      }
      if(i!=s->Nv-1)
        fprintf(FOUT,"},\n");
      else
        fprintf(FOUT,"}}\n");
    }
    fprintf(FOUT,"  Knots\n  {");
    for(j=0;j<s->Nu+s->OrderU+1;j++){
      if(!j)fprintf(FOUT,"%g",s->ku[j]);
      else fprintf(FOUT,", %g",s->ku[j]);
      if(j%5 == 4 && j!=s->Nu + s->OrderU)fprintf(FOUT,"\n  ");
    }
    fprintf(FOUT,"}\n  {");
    for(j=0;j<s->Nv+s->OrderV+1;j++){
      if(!j)fprintf(FOUT,"%g",s->kv[j]);
      else fprintf(FOUT,", %g",s->kv[j]);
      if(j%5 == 4 && j!=s->Nv + s->OrderV)fprintf(FOUT,"\n  ");
    }
    fprintf(FOUT,"}\n  Order %d %d;\n",s->OrderU,s->OrderV);
    break;
  }
}

void Print_Volume(void *a, void *b){
  Surface *s;
  Volume *vol;
  int i;
  vol = *(Volume**)a;

  if(vol->Dirty) return;

  int NUMLOOP = vol->Num + 1000000;

  fprintf(FOUT,"Surface Loop (%d) = ",NUMLOOP);
    
  for(i=0;i<List_Nbr(vol->Surfaces);i++){
    List_Read(vol->Surfaces,i,&s);
    if(i)
      fprintf(FOUT,", %d",s->Num);
    else
      fprintf(FOUT,"{%d",s->Num);
  }
  fprintf(FOUT,"};\n");

  switch(vol->Typ){
  case MSH_VOLUME:
    fprintf(FOUT,"Volume (%d) = {%d};\n",vol->Num,NUMLOOP);
    break;
  }
}

void Print_PhysicalGroups(void *a, void *b){
  PhysicalGroup *pg ;
  int i, j;

  pg = *(PhysicalGroup**)a;
  
  switch(pg->Typ){
  case MSH_PHYSICAL_POINT :
    fprintf(FOUT,"Physical Point (%d) = ",pg->Num);
    break;
  case MSH_PHYSICAL_LINE :
    fprintf(FOUT,"Physical Line (%d) = ",pg->Num);
    break;
  case MSH_PHYSICAL_SURFACE :
    fprintf(FOUT,"Physical Surface (%d) = ",pg->Num);
    break;
  case MSH_PHYSICAL_VOLUME :
    fprintf(FOUT,"Physical Volume (%d) = ",pg->Num);
    break;
  }

  for(i=0;i<List_Nbr(pg->Entities);i++){
    List_Read(pg->Entities,i,&j);
    if(i)
      fprintf(FOUT,", %d",j);
    else
      fprintf(FOUT,"{%d",j);
  }
  fprintf(FOUT,"};\n");

}

void Print_Geo(Mesh *M, char *filename){

  if(filename){
    FOUT = fopen(filename,"w");
    if(!FOUT){
      Msg(WARNING, "Unable to open file '%s'", filename);
      return;
    }
  }
  else
    FOUT = stdout;

  Tree_Action(M->Points,Print_Point);
  Tree_Action(M->Curves,Print_Curve);
  Tree_Action(M->Surfaces,Print_Surface);
  Tree_Action(M->Volumes,Print_Volume);
  List_Action(M->PhysicalGroups,Print_PhysicalGroups);

  if(filename){
    Msg(INFO, "Geo output complete '%s'", filename);
    Msg(STATUS2, "Wrote '%s'", filename);
    fclose(FOUT);
  }

}

