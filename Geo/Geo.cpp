/* $Id: Geo.cpp,v 1.4 2000-11-26 15:43:45 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "CAD.h"
#include "DataBase.h"
#include "Parser.h"

#define BUFFSIZE 32000

char x_text[100]  = "0.0", y_text[100]  = "0.0", z_text[100]  = "0.0";
char l_text[100] = "1.0" ;
char tx_text[100] = "0.0", ty_text[100] = "0.0", tz_text[100] = "0.0";
char attrx_text[100] = "1.0", attry_text[100] = "1.0", attrz_text[100] = "1.0" ;
char attrdec_text[100] = "2.0";
char px_text[100] = "0.0", py_text[100] = "0.0", pz_text[100] = "0.0" ;
char angle_text[100] = "3.14159/2" ;
char ax_text[100] = "0.0", ay_text[100] = "0.0", az_text[100] = "1.0";
char dx_text[100] = "0.0", dy_text[100] = "0.0", dz_text[100] = "0.0";
char df_text[100] = "1.0";
char nb_pts[100] ="10", mode_value[100] = "1";
char trsf_pts_text[100] = "2", trsf_type_text[100] = "Power 1.0";
char trsf_vol_text[100] = "1";
char char_length_text[100] = "1.0";

int Mode_Transfinite = 0;

double evaluate_scalarfunction (char *var, double val, char *funct){
  FILE *tempf;
  tempf = yyin;
  yyin = fopen("gmsh.tmp","w");

  /* On pose la variable = la fonction et on evalue la fonction */

  fprintf(yyin,"%s = %g ;\n",var,val);
  fprintf(yyin,"ValeurTemporaire__ = %s ;\n",funct);
  fclose(yyin);
  yyin = fopen("gmsh.tmp","r");
  while(!feof(yyin)){
    yyparse();
  }
  fclose(yyin);
  Symbol TheSymbol;
  TheSymbol.Name = (char*)malloc(100);
  strcpy(TheSymbol.Name,"ValeurTemporaire__");
  yyin = tempf;
  if (!List_Query(Symbol_L, &TheSymbol, CompareSymbols)) {
    free(TheSymbol.Name);
    return 0.0;
  }
  free(TheSymbol.Name);
  return TheSymbol.val;
}

void add_infile(char *text, char *fich){
  FILE *file;

  yyin = fopen("gmsh.tmp","w");
  file = fopen(fich,"a");
  fprintf(yyin,"%s\n",text);
  fclose(yyin);
  yyin = fopen("gmsh.tmp","r");
  while(!feof(yyin)){
    yyparse();
  }
  fclose(yyin);
  fprintf(file,"%s\n",text);
  fclose(file);
  AddALineInTheEditGeometryForm (text);
}

void del_pnt(int p1, char *fich){
  char text[BUFFSIZE];

  sprintf(text,"Delete {\n Point(%d);\n}",p1);
  add_infile(text,fich);
}

void del_seg(int p1, char *fich){
  char text[BUFFSIZE];

  sprintf(text,"Delete {\n Line(%d);\n}",p1);
  add_infile(text,fich);
}

void del_srf(int p1, char *fich){
  char text[BUFFSIZE];

  sprintf(text,"Delete {\n Surface(%d);\n}",p1);
  add_infile(text,fich);
}

void add_trsfsurf (int N, int *l, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  sprintf(text,"Transfinite Surface {%d} = {",l[0]);
  for(i=1;i<N;i++){
    if(i==1)sprintf(text2,"%d ",l[i]);
    else sprintf(text2,",%d ",l[i]);
    strcat(text,text2);
  }
  sprintf(text2,"};");
  strcat(text,text2);
  add_infile(text,fich);
}

void add_ellipticsurf (int N, int *l, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  sprintf(text,"Elliptic Surface {%d} = {",l[0]);
  for(i=1;i<N;i++){
    if(i==1)sprintf(text2,"%d ",l[i]);
    else sprintf(text2,",%d ",l[i]);
    strcat(text,text2);
  }
  sprintf(text2,"};");
  strcat(text,text2);
  add_infile(text,fich);
}

void add_charlength (int N, int *l, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  sprintf(text,"Characteristic Length {");
  for(i=0;i<N;i++){
    if(i==0)sprintf(text2,"%d ",l[i]);
    else sprintf(text2,",%d ",l[i]);
    strcat(text,text2);
  }
  sprintf(text2,"} = %s;", char_length_text);
  strcat(text,text2);
  add_infile(text,fich);
}

void add_recosurf (int N, int *l, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  sprintf(text,"Recombine Surface {");
  for(i=0;i<N;i++){
    if(i==0)sprintf(text2,"%d ",l[i]);
    else sprintf(text2,",%d ",l[i]);
    strcat(text,text2);
  }
  sprintf(text2,"};");
  strcat(text,text2);
  add_infile(text,fich);
}


void add_trsfline (int N, int *l, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;
  sprintf(text,"Transfinite Line {");
  for(i=0;i<N;i++){
    if(!i)sprintf(text2,"%d ",l[i]);
    else sprintf(text2,",%d ",l[i]);
    strcat(text,text2);
  }
  if(Mode_Transfinite == 0)
    sprintf(text2,"} = %s;",nb_pts);
  else if(Mode_Transfinite == 2)
    sprintf(text2,"} = %s Using Bump %s;",nb_pts,mode_value);
  else if(Mode_Transfinite == 1)
   sprintf(text2,"} = %s Using Power %s;",nb_pts,mode_value);
  strcat(text,text2);
  add_infile(text,fich);
}


void add_param (char *par, char *value, char *fich){
  char text[BUFFSIZE];
  sprintf(text,"%s = %s;",par,value);
  add_infile(text,fich);
}

void add_point(char *fich){
  char text[BUFFSIZE];
  int ip;

  ip = NEWPOINT();
  sprintf(text,"Point(%d) = {%s,%s,%s,%s};",ip,x_text,y_text,z_text,l_text);
  add_infile(text,fich);
}

void add_attractor(char *fich, int ip, int typ){
  char text[BUFFSIZE];
  if(typ == 0) {
    sprintf(text,"Attractor Point (%s,%s,%s) = {%d};",
            attrx_text,attry_text,attrdec_text,ip);
  }
  else if(typ == 1){
    sprintf(text,"Attractor Line (%s,%s,%s) = {%d};",
            attrx_text,attry_text,attrdec_text,ip);
  }
  else if(typ == 2) {
    sprintf(text,"Attractor Surface (%s,%s,%s) = {%d};",
            attrx_text,attry_text,attrdec_text,ip);
  }
  add_infile(text,fich);
}


void add_line(int p1, int p2, char *fich){
  char text[BUFFSIZE];
  int iseg;
  List_T *list = List_Create(2,2,sizeof(int));
  List_Add(list,&p1);
  List_Add(list,&p2);
  if((recognize_seg(MSH_SEGM_LINE,list,&iseg))){
    List_Delete(list);
    return;
  }
  List_Delete(list);
  
  sprintf(text,"Line(%d) = {%d,%d};",NEWREG(),p1,p2);
  add_infile(text,fich);
}

void add_circ(int p1, int p2, int p3, char *fich){
  char text[BUFFSIZE];

  sprintf(text,"Circle(%d) = {%d,%d,%d};",NEWREG(),p1,p2,p3);
  add_infile(text,fich);
}

void add_ell(int p1, int p2, int p3, int p4, char *fich){
  char text[BUFFSIZE];

  sprintf(text,"Ellipsis(%d) = {%d,%d,%d,%d};",NEWREG(),p1,p2,p3,p4);
  add_infile(text,fich);
}

void add_spline(int N, int *p, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  sprintf(text,"CatmullRom(%d) = {",NEWREG());
  for(i=0;i<N;i++){
    if(i != N-1)
      sprintf(text2,"%d,",p[i]);
    else
      sprintf(text2,"%d};",p[i]);
    strcat(text,text2);
  }
  add_infile(text,fich);
}

void add_bezier(int N, int *p, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  sprintf(text,"Bezier(%d) = {",NEWREG());
  for(i=0;i<N;i++){
    if(i != N-1)
      sprintf(text2,"%d,",p[i]);
    else
      sprintf(text2,"%d};",p[i]);
    strcat(text,text2);
  }
  add_infile(text,fich);
}


void add_bspline(int N, int *p, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  sprintf(text,"BSpline(%d) = {",NEWREG());
  for(i=0;i<N;i++){
    if(i != N-1)
      sprintf(text2,"%d,",p[i]);
    else
      sprintf(text2,"%d};",p[i]);
    strcat(text,text2);
  }
  add_infile(text,fich);
}

void add_multline(int N, int *p, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i;

  int iseg;
  List_T *list = List_Create(N,2,sizeof(int));
  for(i=0;i<N;i++)
    List_Add(list,&p[i]);
  if((recognize_seg(MSH_SEGM_LINE,list,&iseg))){
    List_Delete(list);
    return;
  }
  List_Delete(list);

  sprintf(text,"Line(%d) = {",NEWREG());
  for(i=0;i<N;i++){
    if(i != N-1)
      sprintf(text2,"%d,",p[i]);
    else
      sprintf(text2,"%d};",p[i]);
    strcat(text,text2);
  }
  add_infile(text,fich);
}


int recognize_zone(int ityp,List_T *list){
  return 0 ;
}

void add_loop(List_T *list, char *fich, int *numloop){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i,seg;

  if((recognize_loop(list,numloop))) return;

  *numloop = NEWREG();
  sprintf(text,"Line Loop(%d) = {",NEWREG());
  for(i=0;i<List_Nbr(list);i++){
      List_Read(list,i,&seg);
    if(i != List_Nbr(list)-1)
      sprintf(text2,"%d,",seg);
    else
      sprintf(text2,"%d};",seg);
    strcat(text,text2);
  }
  add_infile(text,fich);
}


void add_surf(List_T *list, char *fich, int support, int typ){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i,seg;

  if((i = recognize_zone(MSH_SURF_PLAN,list)) != 0)return;
  if((i = recognize_zone(MSH_SURF_REGL,list)) != 0)return;
  if((i = recognize_zone(MSH_SURF_TRIMMED,list)) != 0)return;

  if(typ ==1){
    sprintf(text,"Ruled Surface(%d) = {",NEWREG());
  }
  else if (typ == 2){
    sprintf(text,"Plane Surface(%d) = {",NEWREG());
  }
  else
  {
    sprintf(text,"Trimmed Surface(%d) = %d {",NEWREG(),support);
  }
  for(i=0;i<List_Nbr(list);i++){
      List_Read(list,i,&seg);
    if(i != List_Nbr(list)-1)
      sprintf(text2,"%d,",seg);
    else
      sprintf(text2,"%d};",seg);
    strcat(text,text2);
  }
  add_infile(text,fich);
}

void add_vol(List_T *list, char *fich, int *numvol){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i,seg;

  if((recognize_surfloop(list,numvol))) return;

  *numvol = NEWREG();
  sprintf(text,"Surface Loop(%d) = {",*numvol);
  for(i=0;i<List_Nbr(list);i++){
    List_Read(list,i,&seg);
    if(i != List_Nbr(list)-1)
      sprintf(text2,"%d,",seg);
    else
      sprintf(text2,"%d};",seg);
    strcat(text,text2);
  }
  add_infile(text,fich);
}

void add_multvol(List_T *list, char *fich){
  char text[BUFFSIZE];
  char text2[BUFFSIZE];
  int i,seg;

  if((i= recognize_zone(MSH_VOLUME,list)))return;
  
  sprintf(text,"Complex Volume(%d) = {",NEWREG());
  for(i=0;i<List_Nbr(list);i++){
    List_Read(list,i,&seg);
    if(i != List_Nbr(list)-1)
      sprintf(text2,"%d,",seg);
    else
      sprintf(text2,"%d};",seg);
    strcat(text,text2);
  }
  add_infile(text,fich);
}

void add_trsfvol(int N, int *l, char *fich){
  char text[TEXT_BUFFER_SIZE], text2[TEXT_BUFFER_SIZE];
  int i;

  sprintf(text,"Transfinite Volume{%s} = {", trsf_vol_text);
  for(i=0;i<N;i++){
    if(i==0)sprintf(text2,"%d ",l[i]);
    else sprintf(text2,",%d ",l[i]);
    strcat(text,text2);
  }
  sprintf(text2,"};");
  strcat(text,text2);
  add_infile(text,fich);
}


void add_physical_entity(List_T *list, char *fich, int type, int *num){
  char text[BUFFSIZE], text2[BUFFSIZE];
  int  i, elementary_entity;

  if(((*num) = recognize_zone(MSH_PHYSICAL_LINE,list))) return;
  if(((*num) = recognize_zone(MSH_PHYSICAL_SURFACE,list))) return;
  if(((*num) = recognize_zone(MSH_PHYSICAL_VOLUME,list))) return;

  *num = NEWREG();
  if (type == 1)
    sprintf(text, "Physical Line(%d) = {", *num);
  else if (type == 2)
    sprintf(text, "Physical Surface(%d) = {", *num);
  else if (type == 0)
    sprintf(text, "Physical Point(%d) = {", *num);
  else
    sprintf(text, "Physical Volume(%d) = {", *num);

  for(i=0; i<List_Nbr(list); i++){
    List_Read(list, i, &elementary_entity);
    if(i != List_Nbr(list)-1)
      sprintf(text2, "%d,", elementary_entity);
    else
      sprintf(text2, "%d};", elementary_entity);
    strcat(text, text2);
  }
  add_infile(text, fich);
}

void extrude(int s, char *fich, char *what){
  char text[BUFFSIZE];

  sprintf(text,"Extrude %s (%d, {%s,%s,%s});",what,s,tx_text,ty_text,tz_text);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}
void translate_seg(int add, int s, char *fich){
  char text[BUFFSIZE];

  if(add)
    sprintf(text,"Translate({%s,%s,%s}) {\n  Duplicata { Line(%d); }\n}",
            tx_text,ty_text,tz_text,s);
  else
    sprintf(text,"Translate({%s,%s,%s}) {\n  Line(%d);\n}",
            tx_text,ty_text,tz_text,s);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}


void translate_surf(int add, int s, char *fich){
  char text[BUFFSIZE];

  if(add)
    sprintf(text,"Translate({%s,%s,%s}) {\n  Duplicata { Surface(%d); }\n}",
            tx_text,ty_text,tz_text,s);
  else
    sprintf(text,"Translate({%s,%s,%s}) {\n  Surface(%d);\n}",
            tx_text,ty_text,tz_text,s);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}

void translate_pt(int add, int s, char *fich){
  char text[BUFFSIZE];

  if(add)
    sprintf(text,"Translate({%s,%s,%s}) {\n  Duplicata { Point(%d); }\n}",
            tx_text,ty_text,tz_text,s);
  else
    sprintf(text,"Translate({%s,%s,%s}) {\n  Point(%d);\n}",
            tx_text,ty_text,tz_text,s);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}

void rotate(int add, int s, char *fich, char *quoi){
  char text[BUFFSIZE];

  if(add)
    sprintf(text,"Rotate({%s,%s,%s},{%s,%s,%s},%s) {\n  Duplicata { %s(%d); }\n}",
            ax_text,ay_text,az_text,px_text,py_text,pz_text,angle_text, quoi,s);
  else
    sprintf(text,"Rotate({%s,%s,%s},{%s,%s,%s},%s) {\n   %s(%d);\n  }",
            ax_text,ay_text,az_text,px_text,py_text,pz_text,angle_text, quoi,s);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}

void dilate(int add, int s, char *fich, char *quoi){
  char text[BUFFSIZE];

  if(add)
    sprintf(text,"Dilate({%s,%s,%s},%s) {\n  Duplicata { %s(%d); }\n}",
            dx_text,dy_text,dz_text,df_text, quoi,s);
  else
    sprintf(text,"Dilate({%s,%s,%s},%s) {\n   %s(%d);\n  }",
            dx_text,dy_text,dz_text,df_text, quoi,s);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}


void protude(int s, char *fich, char *what){
  char text[BUFFSIZE];

  sprintf(text,"Extrude %s(%d, {%s,%s,%s}, {%s,%s,%s}, %s);",what,s,ax_text,ay_text,
          az_text,px_text,py_text,pz_text,angle_text);
  add_infile(text,fich);
  add_infile("Coherence;",fich);
}



