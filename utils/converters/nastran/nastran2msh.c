/* Auteur: Jean Vis (---.magotteaux.com) */

/*Include Linux:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define VERSION "0.01: 01 dec 2005"


struct noeuds {
 float x,y,z;
 long int no;
} noeudsl[1000000];

struct elem {
  long int type,n,grp,n1,n2,n3,n4,n5,n6,n7,n8;
} elemsl[1000000];

long int nbN,nbE;
double xf,yf,zf;
double cfx,cfy,gl,frot;
float xb=425.0,yb=0.0;
float xm,ym;
char basedata[256],outdata[300],version[17]=VERSION,enregistre[246];

/*#############################################################*/
/*#############################################################*/
int datain()
{
 FILE *ft;
 long int i,j,nonoe,ts,tts,noelem,ngrp,n1,n2,n3,n4,n5,n6,n7,n8;
 double n,x,y,z;
 char typeitm[16],comm[256],ligne[256],comm2[256],f3[30];
 char xtxt[20],ytxt[20],ztxt[20];

 printf("Fichier de donnees:");
 gets(basedata);


/*Lecture fichier in */
/*********************/

 printf("\nLecture des Noeuds: \n");
 ft=fopen(basedata,"r");
 if (ft==NULL) return (-1);
 nbN=0;
 nbE=0;
 while (!feof(ft))
 {
   fgets(ligne,sizeof ligne,ft);
   if (strncmp(ligne,"$",1)){
      if (!strncmp(ligne,"GRID",4)){
/* ici on a une ligne qui commence par "GRID" cad un noeud*/      
      
/*printf("ligne:%i ->%s",i,ligne);*/

         ts=sscanf(ligne,"%s %ld %24s",comm,&nonoe,f3);
/*printf("ligne:%i (ts:%i)->no=%i (%s) 3f=%s\n",i,ts,nonoe,comm,f3);*/
         strncpy(xtxt,f3,7);
         strncpy(ytxt,f3+8,8);
         strncpy(ztxt,f3+16,8);
/*printf ("x: %s y: %s z: %s\n",xtxt,ytxt,ztxt);*/
         x=atof(xtxt);
         y=atof(ytxt);
         z=atof(ztxt);
/*printf ("x: %f y: %f z: %f\n\n",x,y,z);*/
         noeudsl[nbN].x=x;
         noeudsl[nbN].y=y;
         noeudsl[nbN].z=z;
         noeudsl[nbN].no=nonoe;
         nbN++;
      }

      if (!strncmp(ligne,"CTRIA3",6)){
/*printf("ligne:%i ->%s",i,ligne);*/
         ts=sscanf(ligne,"%s %d %d %d %d %d",comm,&noelem,&ngrp,&n1,&n2,&n3);
         elemsl[nbE].type=2;
         elemsl[nbE].n=noelem;
         elemsl[nbE].grp=ngrp;
         elemsl[nbE].n1=n1;
         elemsl[nbE].n2=n2;
         elemsl[nbE].n3=n3;
         nbE++;
      }

      if (!strncmp(ligne,"CTETRA",6)){
/*printf("ligne:%i ->%s",i,ligne);*/
         ts=sscanf(ligne,"%s %d %d %d %d %d %d",comm,&noelem,&ngrp,&n1,&n2,&n3,&n4);
         elemsl[nbE].type=4;
         elemsl[nbE].n=noelem;
         elemsl[nbE].grp=ngrp;
         elemsl[nbE].n1=n1;
         elemsl[nbE].n2=n2;
         elemsl[nbE].n3=n3;
         elemsl[nbE].n4=n4;
         nbE++;
      }
      
   }
   i++;
 }
 
 fclose(ft);

 return (0);
}
/*#############################################################*/

/*#############################################################*/
int dataout()
{

/*################################################
  #                                              #
  #  Goal: write a 1.0 Version .msh file of gmsh #
  #                                              #
  ################################################
*/

 FILE *ft;
 long int i;

/*Construction nom de fichier gmsh */
 strcpy(outdata,basedata);
 strcat(outdata,".msh");

 ft=fopen(outdata,"w");
 
/* Ecriture des noeuds 
######################*/

 fprintf (ft,"$NOD\n");
 fprintf (ft,"%ld\n",nbN);

 i=0;
 while (i <nbN)
 {
    fprintf (ft,"%ld %f %f %f \n",noeudsl[i].no,noeudsl[i].x,noeudsl[i].y,noeudsl[i].z);
    i++;
 }
 fprintf (ft,"$ENDNOD\n");

/* Ecriture des elements 
########################*/
 fprintf (ft,"$ELM\n");
 fprintf (ft,"%ld\n",nbE);
 
 i=0;
 while (i <nbE)
 {
    if (elemsl[i].type == 2 ){
       fprintf (ft,"%ld %ld %ld 1 3 %ld %ld %ld  \n",elemsl[i].n,elemsl[i].type,elemsl[i].grp,elemsl[i].n1,elemsl[i].n2,elemsl[i].n3);
    }
    else if (elemsl[i].type == 4 ){
       fprintf (ft,"%ld %ld %ld %ld 4 %ld %ld %ld  %ld\n",elemsl[i].n,elemsl[i].type,elemsl[i].grp,elemsl[i].grp,elemsl[i].n1,elemsl[i].n2,elemsl[i].n3,elemsl[i].n4);
    }
    i++;
 }
 
 fprintf (ft,"$ENDELM\n");
 
 fclose(ft);
 printf ("Fichier Gmsh:%s ecrit !!\n",outdata);

 return 0;
}
/*#############################################################*/

/*#############################################################*/
int main(int argc,char *argv[])
{

 datain();

 dataout();

 return 0;
}
