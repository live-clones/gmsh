/* $Id: dxf2pos.c,v 1.2 2007-09-04 13:47:07 remacle Exp $ */

/* 
   AutoCAD DXF to GMSH .pos Data File Converter

   David.Colignon@AdValvas.be
   
   This is a hack from the Autocad DXF to DKB .Data file translator Version 1.0
   written by Aaron A. Collins (8/13/90) ( http://www.sdsc.edu/~mjb/mae152/dxf.spec.txt )
   and from dxf2geo by Christophe Geuzaine ( http://www.geuz.org/gmsh )

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Tree.h"
#include "Malloc.h"

#define DEG2RAD    3.14159265359/180.
#define BUFSIZE    2048

FILE    *infile, *outfile ;
char    inname[80], outname[80], curobj[80], linbuf[BUFSIZE];
int     i, groupcode, num_p=1 , num_l=1 , num_tt=1 ;
int     cpt_p=1, nb_p, *new_num_pt, cpt_l=1, nb_l, *new_num_l ;
int     nb_tt, sl , *List_Fa_1, *List_Fa_2 , *Test_ori , nbtri=0 , nbqua=0 ;
float   xc[10], yc[10], zc[10], angles[10], baryx=0., baryy=0., baryz=0. ;
float   THETOL=0.0000000001 ;
Tree_T  *Point_T , *Line_T , *Facet_T , *arXfa_T ;

struct Point {
  int num ;
  float x, y, z ;
} ;

int fcmpPoint (const void *a, const void *b)
{
  struct Point *q,*w;
  q = (struct Point*)a;
  w = (struct Point*)b;
  if (fabs(q->x - w->x) < THETOL &&
      fabs(q->y - w->y) < THETOL &&
      fabs(q->z - w->z) < THETOL) return (0) ;
  if(q->x > w->x) return(1);
  if(q->x < w->x) return(-1);
  if(q->y > w->y) return(1);
  if(q->y < w->y) return(-1);
  if(q->z > w->z) return(1);
  if(q->z < w->z) return(-1);
  return (0) ;
}

int AddPoint(struct Point *p)
{
  struct Point *pp ;
  if((pp = (struct Point*)Tree_PQuery(Point_T, p)))
    return pp->num ;
  p->num = num_p++ ;
  Tree_Add(Point_T, p) ;
  baryx += p->x ; baryy += p->y ; baryz += p->z ;
  return p->num ;
}

void RenumPoint(void *a, void *b)
{
  struct Point *p ;
  p = (struct Point *) a ;
  new_num_pt[p->num] = cpt_p ;
  cpt_p++ ;
}

struct Line {
  int num, a, b ; 
} ;

int fcmpLine (const void *a, const void *b)
{
  struct Line *q,*w;
  q = (struct Line*)a;
  w = (struct Line*)b;
  if ( ( q->a == w->a ) && (q->b == w->b ) ) return (0) ;
  if(q->a > w->a) return(1) ;
  if(q->a < w->a) return(-1) ;
  if(q->b > w->b) return(1) ;
  if(q->b < w->b) return(-1) ;
  return (0) ;
}

int AddLine(struct Line *l)
{
  struct Line *ll ;
  if ( l->a == l->b ) printf("!!! Warning : zero-length line added!!!\n");
  int zz ;
  sl = 1 ;
  if ( (l->a) > (l->b) ) {
    zz = l->a ; l->a = l->b ; l->b = zz ; sl = -1 ;
  }
  if((ll = (struct Line*)Tree_PQuery(Line_T, l))) {
    return ll->num ;
  }
  l->num = num_l++ ;
  Tree_Add(Line_T, l) ;
  return l->num ;
}

void RenumLine(void *a, void *b)
{
  struct Line *l ;
  l = (struct Line *) a ;
  new_num_l[l->num] = cpt_l ;
  cpt_l++ ;
}

struct arXfa {
  int num_ar, num_el[3] ; 
} ;

int fcmparXfa (const void *a, const void *b)
{
  struct arXfa *q,*w;
  q = (struct arXfa*)a;
  w = (struct arXfa*)b;
  if(q->num_ar == w->num_ar) return(0);
  if(q->num_ar < w->num_ar) return(-1);
  return(1);
}

int AddarXfa(struct arXfa *aa)
{
  struct arXfa *bb ;
  if((bb = (struct arXfa*)Tree_PQuery(arXfa_T, aa))) {
    ( (bb->num_el[1] ==0) ? (bb->num_el[1]=num_tt) : (bb->num_el[2]=num_tt) ) ;
    return (1) ;
  } else {
    aa->num_el[0] = num_tt ;
    aa->num_el[1] = 0 ;
    aa->num_el[2] = 0 ;
    Tree_Add(arXfa_T, aa) ;
    return (1) ;
  }
  return (0) ;
}

struct Facet {
  int num, nbar, ar[4], s[4], ori ;
  float no[3], x[4], y[4], z[4] ;
} ;

int fcmpFacet (const void *a, const void *b)
{
  struct Facet *q , *w ;
  q = (struct Facet*)a;
  w = (struct Facet*)b;
  if (  q->num == w->num ) return (0) ;
  if(q->num < w->num) return(-1);
  return(1);
}

void AddFacet(struct Facet *t)
{
  t->num = num_tt++ ;
  Tree_Add(Facet_T, t) ;
}


void WriteFacet_tri(void *a, void *b)
{
  struct Facet *tt ;
  int s ;
  tt = (struct Facet *) a ;
  if ( tt->nbar == 3 ) {
    s = tt->ori ;
    fprintf(outfile, "%f %f %f \n", tt->x[0], tt->x[1], tt->x[2]);
    fprintf(outfile, "%f %f %f \n", tt->y[0], tt->y[1], tt->y[2]);
    fprintf(outfile, "%f %f %f \n", tt->z[0], tt->z[1], tt->z[2]);
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));    
  }
}


void WriteFacet_qua(void *a, void *b)
{
  struct Facet *tt ;
  int s ;
  tt = (struct Facet *) a ;
  if ( tt->nbar == 4 ) {
    s = tt->ori ;
    fprintf(outfile, "%f %f %f %f\n", tt->x[0], tt->x[1], tt->x[2], tt->x[3]);
    fprintf(outfile, "%f %f %f %f\n", tt->y[0], tt->y[1], tt->y[2], tt->y[3]);
    fprintf(outfile, "%f %f %f %f\n", tt->z[0], tt->z[1], tt->z[2], tt->z[3]);
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));    
    fprintf(outfile, "%f %f %f \n", s*(tt->no[0]), s*(tt->no[1]), s*(tt->no[2]));    
  }
}

void orienttri_3 ( int Edgs , int Tgl , int Tgll ) 
{
  struct Facet tri_0 , *tri_a , *tri_b ;
  int ii , mm  , numa , numb ;

  tri_0.num = Tgl ;
  tri_a = (struct Facet*)Tree_PQuery(Facet_T, &tri_0) ;
  tri_0.num = Tgll ;
  tri_b = (struct Facet*)Tree_PQuery(Facet_T, &tri_0) ;
  for ( mm=0 ; mm<=3 ; mm++ ) {
    if ( tri_a->ar[mm] == Edgs ) numa = mm ;
    if ( tri_b->ar[mm] == Edgs ) numb = mm ;
  }
  if ( tri_a->s[numa] == tri_b->s[numb ] ) {
    tri_b->ori = -1 ;
    for ( ii=0 ; ii<=3 ; ii++ ) {
      tri_b->s[ii]=(-1)*(tri_b->s[ii]);
    }
  }
}

void orienttri_2 (int N1 )
{
  struct Facet tri_0 , *tri_a ;
  struct arXfa  arXfa_0 , *arXfa_b;
  int I, N2, Tgl, IEdgs, Edgs, Mult, Tgll, nbar;

 flag1:
  N2 = 0 ;
  for ( I=1 ; I<=N1 ; I++ ) {
      Tgl=List_Fa_1[I-1];
      tri_0.num = Tgl ;
      tri_a = (struct Facet*)Tree_PQuery(Facet_T, &tri_0) ;
      nbar = tri_a->nbar ; 
      for (IEdgs=1 ; IEdgs <=nbar ; IEdgs++) { 
	  Edgs = tri_a->ar[IEdgs-1] ; 
	  arXfa_0.num_ar = Edgs ;
	  arXfa_b = (struct arXfa*)Tree_PQuery(arXfa_T, &arXfa_0) ;
	  for (Mult=1 ; Mult<=3 ; Mult++) { 
	      Tgll = arXfa_b->num_el[Mult-1] ;
	      if ( (Tgll!=0) && (Test_ori[Tgll-1] == 0) ) {
		  N2 = N2+1 ;
		  List_Fa_2[N2-1] = Tgll ;
		  orienttri_3( Edgs , Tgl , Tgll ) ; 
		  Test_ori[Tgll-1] = 1 ;
	      }
	  }
      }
  }
  for ( I=1 ; I<=N2 ; I++ ) {
      List_Fa_1[I-1] = List_Fa_2[I-1] ; 
  }
  N1 = N2 ;
  if (N1!=0) goto flag1 ;
  return ;
}

void orienttri_1 (void )
{
  int N1 , ii ;

  for ( ii=1 ; ii<=nb_tt ; ii++ ) {
    Test_ori[ii-1] = 0 ;
  }
  N1 = 1 ;
  List_Fa_1[1-1] = 1 ;
  Test_ori[1-1] = 1 ; 
  orienttri_2(N1) ;
  for ( ii=2 ; ii<=nb_tt ; ii++ ) {
    if ( Test_ori[ii-1] == 0 ) {
      N1 = 1 ; 
      List_Fa_1[1-1] = ii ;
      Test_ori[ii-1] = 1 ; 
      orienttri_2(N1) ;
    }
  }
  return ;
}

void Addobj(void)
{ 
  struct Point      p ; 
  struct Line       l ;
  struct Facet   t ;
  struct arXfa      arXfa_cur ;
  int   ii , nump[4] , numl[4] , sel[4] ;
  float det[4] ; 

  if (strstr(curobj, "POINT")){
    p.x = xc[0] ; p.y = yc[0] ; p.z = zc[0] ; AddPoint(&p) ;

  } else if ( (strstr(curobj, "LINE") && !strstr(curobj, "POLY")) ||
	      strstr(curobj, "3DLINE")){
    if (xc[0]==xc[1] && yc[0]==yc[1] && zc[0]==zc[1]) {
      printf("!!! Warning : zero-length line in (3D)LINE removed !!!\n") ;
      return;
    }
    p.x = xc[0] ; p.y = yc[0] ; p.z = zc[0] ; nump[0] = AddPoint(&p) ;
    p.x = xc[1] ; p.y = yc[1] ; p.z = zc[1] ; nump[1] = AddPoint(&p) ;
    l.a = nump[0] ; l.b = nump[1] ; AddLine(&l) ;

  } else if (strstr(curobj, "3DFACE")){ 

    det[0] =    (((yc[1]-yc[0])*(zc[2]-zc[0]))-((zc[1]-zc[0])*(yc[2]-yc[0]))) ; 
    det[1] = -1*(((xc[1]-xc[0])*(zc[2]-zc[0]))-((zc[1]-zc[0])*(xc[2]-xc[0]))) ; 
    det[2] =    (((xc[1]-xc[0])*(yc[2]-yc[0]))-((yc[1]-yc[0])*(xc[2]-xc[0]))) ; 
    det[3] = sqrt ( det[0]*det[0]+det[1]*det[1]+det[2]*det[2] ) ; 

   if (xc[3] == xc[2] && yc[3] == yc[2] && zc[3] == zc[2]) {
      if ( det[3] == 0. ) {
	printf("!!! WARNING : Degenerate triangular 3DFACE (colinear points) removed !!!\n") ;
	return ;
      }
    } else {

      if (xc[3] == xc[0] && yc[3] == yc[0] && zc[3] == zc[0]) {
	printf("!!! WARNING : Degenerate quadrangular 3DFACE converted in triangle !!!\n") ;
	xc[3] = xc[2] ; yc[3] = yc[2] ; zc[3] = zc[2] ; 
      }
    }
    for ( ii=0 ; ii<=2 ; ii++ ) {
      p.x = xc[ii] ; p.y = yc[ii] ; p.z = zc[ii] ; nump[ii] = AddPoint(&p) ;
      t.no[ii] = det[ii]/det[3] ; 
    }
    l.a = nump[0] ; l.b = nump[1] ; numl[0] = AddLine(&l) ; sel[0] = sl ;
    arXfa_cur.num_ar = numl[0] ; AddarXfa(&arXfa_cur) ;

    if (xc[3] == xc[2] && yc[3] == yc[2] && zc[3] == zc[2]){
      t.nbar = 3 ; nbtri++ ;
      l.a = nump[1] ; l.b = nump[2] ; numl[1] = AddLine(&l) ; sel[1] = sl ;
      arXfa_cur.num_ar = numl[1] ; AddarXfa(&arXfa_cur) ;
      l.a = nump[2] ; l.b = nump[0] ; numl[2] = AddLine(&l) ; sel[2] = sl ;
      arXfa_cur.num_ar = numl[2] ; AddarXfa(&arXfa_cur) ;
      nump[3] = 0 ; numl[3] = 0 ; sel[3] = 0 ; // fausse 4eme arete
    } else {
      t.nbar = 4 ; nbqua++ ;
      p.x = xc[3] ; p.y = yc[3] ; p.z = zc[3] ; nump[3] = AddPoint(&p) ;
      l.a = nump[1] ; l.b = nump[2] ; numl[1] = AddLine(&l) ; sel[1] = sl ;
      arXfa_cur.num_ar = numl[1] ; AddarXfa(&arXfa_cur) ;
      l.a = nump[2] ; l.b = nump[3] ; numl[2] = AddLine(&l) ; sel[2] = sl ;
      arXfa_cur.num_ar = numl[2] ; AddarXfa(&arXfa_cur) ;
      l.a = nump[3] ; l.b = nump[0] ; numl[3] = AddLine(&l) ; sel[3] = sl ;
      arXfa_cur.num_ar = numl[3] ; AddarXfa(&arXfa_cur) ;
    }
    for ( ii=0 ; ii<=3 ; ii++ ) {
      t.ar[ii] = numl[ii] ; 
      t.s[ii] = sel[ii] ;
      t.x[ii] = xc[ii] ; t.y[ii] = yc[ii] ; t.z[ii] = zc[ii] ; 
    }
    t.ori = 1 ; 
    AddFacet(&t) ;
  }
}

int getline(void)
{ 
  fgets(linbuf, BUFSIZE, infile); /* get a line from .DXF */
  if (feof(infile))
    return(1);
  sscanf(linbuf, "%3d", &groupcode);  /* scan out group code */
  fgets(linbuf, BUFSIZE, infile); /* get a line from .DXF */
  if (feof(infile))
    return(1);
  return(0);
}

int main(int argc, char *argv[])
{
  char *index;
  /*
    if (argc < 3){
    printf("Usage: %s file[.dxf] tolerance [rotation] [xoffset] [yoffset] \n", argv[0]);
    exit(1);
    }
    THETOL = atof(argv[2]) ;
  */
  printf("\nAutoCAD DXF to Emc2000Flash .Geom Data File Converter\n") ; 
  printf("by David Colignon ( David.Colignon@AdValvas.be )\n\n") ; 

  strcpy(inname, argv[1]); /* make copy we can mess with */
  if (!strchr(inname, '.')) /* no dot present in filename? */
    strcat(inname, ".dxf");
  if (!(infile = fopen(inname, "r"))){
    printf("Cannot open input file %s\n", inname);
    exit(1);
  }
  strcpy(outname, inname);
  index = strchr(outname, '.'); /* find the dot */
  strcpy(index, ".pos"); /* make new ext.  .geom  ... */

  if (!(outfile = fopen(outname, "w"))){
    printf("Cannot create output file %s\n", outname);
    fclose(infile);
    exit(1);
  }

  curobj[0] = '\0'; /* not working on any object currently */

  Point_T    = Tree_Create(sizeof(struct Point), fcmpPoint) ;
  Line_T     = Tree_Create(sizeof(struct Line), fcmpLine) ;
  Facet_T   = Tree_Create(sizeof(struct Facet), fcmpFacet) ;
  arXfa_T    = Tree_Create(sizeof(struct arXfa), fcmparXfa) ;
  
 find: 
  while (!feof(infile)){ /* run file up to the "ENTITIES" section */
    if (getline()) goto stopit;
    if (groupcode == 0){ /* file section mark */
      if (strstr(linbuf, "EOF")) goto stopit;
      if (strstr(linbuf, "SECTION")){
	if (getline()) goto stopit;
	if (groupcode != 2) continue;
	if (strstr(linbuf, "ENTITIES")) break;
      }
    }
  }

  while (!feof(infile)){ /* scan ENTITIES section */
    if (getline()) /* get a group code and a line */
      break;
    if (groupcode < 10){ /* cardinal group codes */
      switch(groupcode){
      case 0: /* start of entity, table, file sep */
	if (strstr(linbuf, "EOF")){
	  Addobj(); /* dump object */
	  goto stopit;
	}
	if (strstr(linbuf, "ENDSEC")){
	  Addobj(); /* dump object */
	  goto find;
	}
	Addobj(); /* dump old object */
	curobj[0] = '\0'; /* reset object */
	strcpy(curobj, linbuf); /* get new */
	break;
      case 1: /* primary text value for entity (?)*/
	break;
      case 2: /* block name, attribute tag, etc */
      case 3: /* other names */
      case 4:
	break;
      case 5: /* entity handle (hex string) */
	break;
      case 6: /* line type name */
	break;
      case 7: /* text style name */
	break;
      case 8: /* layer name */
	break;
      case 9: /* variable name ID (only in header)*/
	break;
      }
    } else if (groupcode >= 10 && groupcode < 19){ /* Some X coord */
      sscanf(linbuf, "%f", &(xc[groupcode-10]));
    } else if (groupcode >= 20 && groupcode < 29){ /* Some Y coord */
      sscanf(linbuf, "%f", &(yc[groupcode-20]));
    } else if (groupcode >= 30 && groupcode < 38){ /* Some Z coord */
      sscanf(linbuf, "%f", &(zc[groupcode-30]));
    }
  }

 stopit: 
  fclose(infile);

  nb_p  = Tree_Nbr(Point_T) ;
  new_num_pt   = (int*) Malloc ( (nb_p+1) * sizeof(int) ) ;
  baryx /= nb_p ; baryy /= nb_p ; baryz /= nb_p ; 
  nb_l  = Tree_Nbr(Line_T) ;
  new_num_l = (int*) Malloc ( (nb_l+1) * sizeof(int) ) ;
  nb_tt = Tree_Nbr(Facet_T) ;

  printf("\nPoints :  %d \n",nb_p) ;
  printf("Lines  :  %d \n",nb_l) ;
  printf("3Dface :  %d \n\n",nb_tt) ;

  if ( nb_tt != 0 ) {
    List_Fa_1  = (int*) Malloc ( (nb_tt+1) * sizeof(int) ) ;
    List_Fa_2  = (int*) Malloc ( (nb_tt+1) * sizeof(int) ) ;
    Test_ori   = (int*) Malloc ( (nb_tt+1) * sizeof(int) ) ;
    orienttri_1();
  }

  fprintf(outfile, "$PostFormat\n");
  fprintf(outfile, "1.2 0 8\n");
  fprintf(outfile, "$EndPostFormat\n");
  fprintf(outfile, "$View\n");
  fprintf(outfile, "aaaa 1\n");
  fprintf(outfile, "0 0 0\n");
  fprintf(outfile, "0 0 0\n");
  fprintf(outfile, "0 %d 0\n", nbtri );
  fprintf(outfile, "0 %d 0\n", nbqua );
  fprintf(outfile, "0 0 0\n");
  fprintf(outfile, "0 0 0\n");
  fprintf(outfile, "0 0 0\n");
  fprintf(outfile, "0 0 0\n");
  fprintf(outfile, "0 0 0 0\n");
  fprintf(outfile, "1\n");

  Tree_Action(Facet_T, WriteFacet_tri) ;
  Tree_Action(Facet_T, WriteFacet_qua) ;

  fprintf(outfile, "$endView\n");
  fflush(outfile);
  fclose(outfile);
  Tree_Delete(Point_T) ;
  Tree_Delete(Line_T) ;
  Tree_Delete(Facet_T) ;
  Tree_Delete(arXfa_T) ;
  Free(new_num_pt) ;
  Free(new_num_l) ;
  exit(0);
}
