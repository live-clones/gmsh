/****************************************************************************
Logiciel initial: MMG3D Version 4.0
Co-auteurs : Cecile Dobrzynski et Pascal Frey.
Propriétaires :IPB - UPMC -INRIA.

Copyright © 2004-2005-2006-2007-2008-2009-2010-2011, 
diffusé sous les termes et conditions de la licence publique générale de GNU
Version 3 ou toute version ultérieure.  

Ce fichier est une partie de MMG3D.
MMG3D est un logiciel libre ; vous pouvez le redistribuer et/ou le modifier
suivant les termes de la licence publique générale de GNU
Version 3 ou toute version ultérieure.
MMG3D est distribué dans l'espoir qu'il sera utile, mais SANS 
AUCUNE GARANTIE ; sans même garantie de valeur marchande.  
Voir la licence publique générale de GNU pour plus de détails.
MMG3D est diffusé en espérant qu’il sera utile, 
mais SANS AUCUNE GARANTIE, ni explicite ni implicite, 
y compris les garanties de commercialisation ou 
d’adaptation dans un but spécifique. 
Reportez-vous à la licence publique générale de GNU pour plus de détails.
Vous devez avoir reçu une copie de la licence publique générale de GNU 
en même temps que ce document. 
Si ce n’est pas le cas, aller voir <http://www.gnu.org/licenses/>.
/****************************************************************************
Initial software: MMG3D Version 4.0
Co-authors: Cecile Dobrzynski et Pascal Frey.
Owners: IPB - UPMC -INRIA.

Copyright © 2004-2005-2006-2007-2008-2009-2010-2011, 
spread under the terms and conditions of the license GNU General Public License 
as published Version 3, or (at your option) any later version.

This file is part of MMG3D
MMG3D is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
MMG3D is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with MMG3D. If not, see <http://www.gnu.org/licenses/>.  
****************************************************************************/
#include "mesh.h"

/* return 1-14 for config */
int MMG_simu68(pMesh mesh,pSol sol,pList list,double crit) {
  pTetra pt,pt1;
  int ia,ib,s1,s2,s3,s4,s5,s6;
  int iadr,*adja,k,adj,iel,iar;
  short  voy;
  double caltab[2],qual[41];
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];

  for(k=0 ; k<41 ; k++)
    qual[k] = -1;
    
  /*find points of polygone*/
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  s1  = pt->v[ MMG_isar[iar][0] ];
  s2  = pt->v[ MMG_isar[iar][1] ]; 
  /*printf("s1 %d s2 %d\n",s1,s2);
  */iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
 /* printf("tetra %d : %d %d %d %d\n",adj,pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
  */s3  = pt1->v[voy];
  /*printf("s3 %d \n",s3);
  */iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_idir[voy][0]]==s2) {
     k = MMG_idir[voy][0];
  } else if(pt1->v[MMG_idir[voy][1]]==s2) {
     k = MMG_idir[voy][1];
  } else if(pt1->v[MMG_idir[voy][2]]==s2) {
     k = MMG_idir[voy][2];
  } else {
    puts("MMG_simu56: point s2 non existant");
    exit(0);
  }  
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  /*printf("tetra %d : %d %d %d %d\n",adj,pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
  */s4   = pt1->v[voy];
  /*printf("s4 %d\n",s4);
  */iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_idir[voy][0]]==s3) {
     k = MMG_idir[voy][0];
  } else if(pt1->v[MMG_idir[voy][1]]==s3) {
     k = MMG_idir[voy][1];
  } else if(pt1->v[MMG_idir[voy][2]]==s3) {
     k = MMG_idir[voy][2];
  } else {
    puts("MMG_simu56_ani: point s4 non existant");
    exit(0);
  }  
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s5   = pt1->v[voy]; 
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s6   = pt1->v[voy];
  
  /*cas 1*/
  do {
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s3;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[1] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[1] = caltab[0];
    qual[2] = caltab[1];
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];
   
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s3;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[3] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[3] = caltab[0];
    qual[4] = caltab[1];
    list->qual[3] = qual[3];
    list->qual[4] = qual[4];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[5] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[5] = caltab[0];
    qual[6] = caltab[1];
    list->qual[5] = qual[5];
    list->qual[6] = qual[6];
     
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[7] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[7] = caltab[0];
    qual[8] = caltab[1];
    list->qual[7] = qual[7];
    list->qual[8] = qual[8];
    
    /* set function ptr */
    memset(pt1,0,sizeof(Tetra));
    MMG_swpptr = MMG_swap68_1;
     
    return(1);
  } while(0);
  
  /*cas 2*/
  do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[3]) break;
    else if(qual[3] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[3] = caltab[0];
      qual[4] = caltab[1];
    }  
    list->qual[3] = qual[3];
    list->qual[4] = qual[4];
 
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s4;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[9] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[9]  = caltab[0];
    qual[10] = caltab[1];
    list->qual[5] = qual[9];
    list->qual[6] = qual[10];
   
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s4;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[11] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[11] = caltab[0];
    qual[12] = caltab[1];
    list->qual[7] = qual[11];
    list->qual[8] = qual[12];

   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_2;
   return(2);
  } while(0);
  
  /*cas 3*/
  do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s3;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[13] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[13] = caltab[0];
    qual[14] = caltab[1];
    list->qual[3] = qual[13];
    list->qual[4] = qual[14];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[15] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[15] = caltab[0];
    qual[16] = caltab[1];
    list->qual[5] = qual[15];
    list->qual[6] = qual[16];
   
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[17] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[17] = caltab[0];
    qual[18] = caltab[1];
    list->qual[7] = qual[17];
    list->qual[8] = qual[18];
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_3;
   return(3);
  } while(0);
  
  /*cas 4*/
  do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];
    
    if(!qual[11]) break;
    else if(qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[11] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }
    list->qual[7] = qual[11];
    list->qual[8] = qual[12];
    
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[13] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    }
    list->qual[3] = qual[13];
    list->qual[4] = qual[14];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s4;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[19] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[19] = caltab[0];
    qual[20] = caltab[1];
    list->qual[5] = qual[19];
    list->qual[6] = qual[20];
   
    
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_4;
   return(4);
  } while(0);
  
  /*cas 5*/
  do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[9] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1]; 
    }
    list->qual[5] = qual[9];
    list->qual[6] = qual[10];

    if(!qual[11]) break;
    else if(qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[11] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1]; 
    }
    list->qual[7] = qual[11];
    list->qual[8] = qual[12];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[21] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[21] = caltab[0];
    qual[22] = caltab[1];
    list->qual[1] = qual[21];
    list->qual[2] = qual[22];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[23] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[23] = caltab[0];
    qual[24] = caltab[1];
    list->qual[3] = qual[23];
    list->qual[4] = qual[24];
 
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_5;
   return(5);
  } while(0);
  
  
  /*cas 6*/
  do {
    if(!qual[5]) break;
    else if(qual[5] == -1) { 
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[5] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[5] = caltab[0];
      qual[6] = caltab[1];
    } 
    list->qual[5] = qual[5];
    list->qual[6] = qual[6];

    if(!qual[7]) break;
    else if(qual[7] == -1) {   
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[7] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    }  
    list->qual[7] = qual[7];
    list->qual[8] = qual[8];
    
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[21] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[1] = qual[21];
    list->qual[2] = qual[22];
    
    if(!qual[23]) break;
    else if(qual[23] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[23] = 0;  
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[23] = caltab[0];
      qual[24] = caltab[1];
    }  
    list->qual[3] = qual[23];
    list->qual[4] = qual[24];
 
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_6;
   return(6);
  } while(0);
  
  /*cas 7*/
  do {
    if(!qual[7]) break;
    else if(qual[7] == -1) {   
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[7] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    }  
    list->qual[1] = qual[7];
    list->qual[2] = qual[8];
    
    if(!qual[17]) break;
    else if(qual[17] == -1) { 
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[17] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    }  
    list->qual[7] = qual[17];
    list->qual[8] = qual[18];
     
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[25] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[25] = caltab[0];
    qual[26] = caltab[1];
    list->qual[3] = qual[25];
    list->qual[4] = qual[26];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[27] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[27] = caltab[0];
    qual[28] = caltab[1];
    list->qual[5] = qual[27];
    list->qual[6] = qual[28];
   
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_7;
   return(7);
  } while(0);
  
 /*cas 8*/
 do {
    if(!qual[11]) break;
    else if(qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        qual[11] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }  
    list->qual[7] = qual[11];
    list->qual[8] = qual[12];
    
    if(!qual[19]) break;
    else if(qual[19] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        qual[19] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[19] = caltab[0];
      qual[20] = caltab[1];
    }      
    list->qual[5] = qual[19];
    list->qual[6] = qual[20];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
      qual[29] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[29] = caltab[0];
    qual[30] = caltab[1];
    list->qual[1] = qual[29];
    list->qual[2] = qual[30];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
      qual[31] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[31] = caltab[0];
    qual[32] = caltab[1];
    list->qual[3] = qual[31];
    list->qual[4] = qual[32];
   
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_8;
   return(8);
  } while(0);
  
  /*cas 9*/
  do {  
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[7]) break;
    else if(qual[7] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[7] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    } 
    list->qual[5] = qual[7];
    list->qual[6] = qual[8];
    
    if(!qual[17]) break;
    else if(qual[17] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[17] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    }  
    list->qual[3] = qual[17];
    list->qual[4] = qual[18];
   
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s3;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[33] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[33] = caltab[0];
    qual[34] = caltab[1];
    list->qual[7] = qual[33];
    list->qual[8] = qual[34];
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_9;
   return(9);
  } while(0);
  
  /*cas 10*/
  do {
    if(!qual[7]) break;
    else if(qual[7] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[7] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    }
    list->qual[7] = qual[7];
    list->qual[8] = qual[8];

    if(!qual[21]) break;
    else if(qual[21] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[21] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }
    list->qual[1] = qual[21];
    list->qual[2] = qual[22];
    
    if(!qual[25]) break;
    else if(qual[25] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[25] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[5] = qual[25];
    list->qual[6] = qual[26];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[35] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[35] = caltab[0];
    qual[36] = caltab[1];
    list->qual[3] = qual[35];
    list->qual[4] = qual[36];
 
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_10;
   return(10);
  } while(0);
  
  /*cas 11*/
  do {
    if(!qual[21]) break;
    else if(qual[21] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[21] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }
    list->qual[1] = qual[21];
    list->qual[2] = qual[22];
    
    if(!qual[29]) break;
    else if(qual[29] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[29] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[7] = qual[29];
    list->qual[8] = qual[30];

    if(!qual[35]) break;
    else if(qual[35] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        qual[35] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[35] = caltab[0];
      qual[36] = caltab[1];
    }
    list->qual[3] = qual[35];
    list->qual[4] = qual[36];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[37] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[37] = caltab[0];
    qual[38] = caltab[1];
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];
   
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_11;
   return(11);
  } while(0);
  
  /*cas 12*/
  do {
    if(!qual[17]) break;
    else if(qual[17] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[17] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    }
    list->qual[7] = qual[17];
    list->qual[8] = qual[18];
    
    if(!qual[27]) break;
    else if(qual[27] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[27] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[27] = caltab[0];
      qual[28] = caltab[1];
    }
    list->qual[5] = qual[27];
    list->qual[6] = qual[28];

   if(!qual[29]) break;
    else if(qual[29] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[29] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }

    list->qual[1] = qual[29];
    list->qual[2] = qual[30];
    
    if(!qual[37]) break;
    else if(qual[37] == -1){
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[37] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[3] = qual[37];
    list->qual[4] = qual[38];
    
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_12;
   return(12);
  } while(0);
  
  
  /*cas 13*/
  do {
    if(!qual[15]) break;
    else if(qual[15] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[15] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[15] = caltab[0];
      qual[16] = caltab[1];
    }
    list->qual[5] = qual[15];
    list->qual[6] = qual[16];
   
    if(!qual[17]) break;
    else if(qual[17] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[17] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    }
    list->qual[7] = qual[17];
    list->qual[8] = qual[18];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[29] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[1] = qual[29];
    list->qual[2] = qual[30];
    
    if(!qual[31]) break;
    else if(qual[31] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[31] = 0;
	memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[31] = caltab[0];
      qual[32] = caltab[1];
    }
    list->qual[3] = qual[31];
    list->qual[4] = qual[32];
 
 
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_13;
   return(13);
  } while(0);
  
  /*cas 14*/
  do {
    if(!qual[11]) break;
    else if(qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[11] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }
    list->qual[5] = qual[11];
    list->qual[6] = qual[12];
    
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[21] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }
    list->qual[3] = qual[21];
    list->qual[4] = qual[22];
    
    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[29] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[1] = qual[29];
    list->qual[2] = qual[30];
        
   
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s4;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[39] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[39] = caltab[0];
    qual[40] = caltab[1];
    list->qual[7] = qual[39];
    list->qual[8] = qual[40];
   /* set function ptr */
   memset(pt1,0,sizeof(Tetra));
   MMG_swpptr = MMG_swap68_14;
   return(14);
  } while(0);
  
   return(0);

}
