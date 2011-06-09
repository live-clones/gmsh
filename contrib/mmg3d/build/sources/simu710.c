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

/* return 1-49 for config */
int MMG_simu710(pMesh mesh,pSol sol,pList list,double crit) {
  pTetra	pt,pt1;
  double	qual[71],caltab[2];
  int		ia,ib,s1,s2,s3,s4,s5,s6,s7;
  int		iadr,*adja,k,adj,iel,iar;
  short  voy;

  for(k=0 ; k<=71 ; k++) qual[k] = -1;
  
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];

  /*find points of polygone*/
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  s1  = pt->v[ MMG_isar[iar][0] ];
  s2  = pt->v[ MMG_isar[iar][1] ]; 

  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];

  s3  = pt1->v[voy];

  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_idir[voy][0]]==s2) {
     k = MMG_idir[voy][0];
  } else if(pt1->v[MMG_idir[voy][1]]==s2) {
     k = MMG_idir[voy][1];
  } else if(pt1->v[MMG_idir[voy][2]]==s2) {
     k = MMG_idir[voy][2];
  } else {
    puts("MMG_simu710: point s2 non existant");
    exit(0);
  }  
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];

  s4   = pt1->v[voy];
  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_idir[voy][0]]==s3) {
     k = MMG_idir[voy][0];
  } else if(pt1->v[MMG_idir[voy][1]]==s3) {
     k = MMG_idir[voy][1];
  } else if(pt1->v[MMG_idir[voy][2]]==s3) {
     k = MMG_idir[voy][2];
  } else {
    printf("MMG_simu710: point s3 non existant %d \n",s3);
    exit(0);
  } 
   
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];

  s5   = pt1->v[voy];
  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_idir[voy][0]]==s4) {
     k = MMG_idir[voy][0];
  } else if(pt1->v[MMG_idir[voy][1]]==s4) {
     k = MMG_idir[voy][1];
  } else if(pt1->v[MMG_idir[voy][2]]==s4) {
     k = MMG_idir[voy][2];
  } else {
    puts("MMG_simu710: point s4 non existant");
    exit(0);
  }   
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s6   = pt1->v[voy]; 
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s7   = pt1->v[voy];
  
 /* printf("polygone : %d %d %d %d %d %d %d\n",s1,s2,s3,s4,s5,s6,s7);
  */
  /*for(k=1 ; k<=7 ; k++) {
    jel = list->tetra[k]/6;
    pt1 =&mesh->tetra[jel];
    printf("tetra %d : %d %d %d %d\n",jel,pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
  }*/
  
  /*cas 1*/
  do {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s3;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("cal 0 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[1] = 0;
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
        //printf("caltab[0] 2 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[3] = 0;
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
        //printf("cal 4 %e %e \n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[5] = 0;
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
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("cal 6 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[7] = 0;
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
      list->qual[7] = qual[7];
      list->qual[8] = qual[8];
           
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("cal 8 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
      list->qual[9]  = qual[9];
      list->qual[10] = qual[10];

     MMG_swpptr = MMG_swap710_1;
  
     return(71);
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
        //printf("2:cal 3 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[3] = 0;
        break;
      }
      qual[3] = caltab[0];
      qual[4] = caltab[1];
    } 
    list->qual[3] = qual[3];
    list->qual[4] = qual[4];
     
    if(!qual[5]) break;
    else if(qual[5] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 5 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[5] = 0;
        break;
      }
      qual[5] = caltab[0];
      qual[6] = caltab[1];
    } 
    list->qual[5] = qual[5];
    list->qual[6] = qual[6];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s5;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
      //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[11] = 0;
      break;
    }
    qual[11] = caltab[0];
    qual[12] = caltab[1];
    list->qual[7] = qual[11];
    list->qual[8] = qual[12];
      
      
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s5;
    pt1->v[2] = s6;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[13] = 0;
      break;
    }
    qual[13] = caltab[0];
    qual[14] = caltab[1];
    list->qual[9] = qual[13];
    list->qual[10] = qual[14];   
    
    MMG_swpptr = MMG_swap710_2;
    return(72);
  } while(0); 
  
  /*cas 3*/
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
        //printf("2:cal 3 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[3] = 0;
        break;
      }
      qual[3] = caltab[0];
      qual[4] = caltab[1];
    } 
    list->qual[3] = qual[3];
    list->qual[4] = qual[4];
   
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[5] = qual[13];
    list->qual[6] = qual[14];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s4;
    pt1->v[2] = s5;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
      //printf("2:cal 15 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[15] = 0;
      break;
    }  
    qual[15] = caltab[0];
    qual[16] = caltab[1];
    list->qual[7] = qual[15];
    list->qual[8] = qual[16];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s4;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
      //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[17] = 0;
      break;
    }
    qual[17] = caltab[0];
    qual[18] = caltab[1];
    list->qual[9]  = qual[17];
    list->qual[10] = qual[18];
         
    MMG_swpptr = MMG_swap710_3;
    return(73);
  } while(0);
  
  /*cas 4*/
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
        //printf("2:cal 3 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[3] = 0;
        break;
      }
      qual[3] = caltab[0];
      qual[4] = caltab[1];
    } 
    list->qual[3] = qual[3];
    list->qual[4] = qual[4];
   
    if(!qual[17]) break;
    else if(qual[17] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 17 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[17] = 0;
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    } 
    list->qual[5] = qual[17];
    list->qual[6] = qual[18];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s4;
    pt1->v[2] = s6;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
      //printf("2:cal 19 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[19] = 0;
      break;
    }  
    qual[19] = caltab[0];
    qual[20] = caltab[1];
    list->qual[7] = qual[19];
    list->qual[8] = qual[20];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s4;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
      //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[21] = 0;
      break;
    }
    qual[21] = caltab[0];
    qual[22] = caltab[1];
    list->qual[9]  = qual[21];
    list->qual[10] = qual[22];
         
    MMG_swpptr = MMG_swap710_4;
    return(74);
  } while(0); 
  
  /*cas 5*/
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
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 3 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[3] = 0;
        break;
      }
      qual[3] = caltab[0];
      qual[4] = caltab[1];
    } 
    list->qual[3] = qual[3];
    list->qual[4] = qual[4];
   
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[5] = qual[9];
    list->qual[6] = qual[10];

    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[7] = qual[21];
    list->qual[8] = qual[22];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s4;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
      //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[23] = 0;
      break;
    }
    qual[23] = caltab[0];
    qual[24] = caltab[1];
    list->qual[9]  = qual[23];
    list->qual[10] = qual[24];
         
    MMG_swpptr = MMG_swap710_5;
    return(75);
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
        //printf("cal 4 %e %e \n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[5] = 0;
        break;
      }
      qual[5] = caltab[0];
      qual[6] = caltab[1];
    }
    list->qual[1] = qual[5];
    list->qual[2] = qual[6];

    if(!qual[7]) break;
    else if(qual[7] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("cal 6 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[7] = 0;
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    } 
    list->qual[3] = qual[7];
    list->qual[4] = qual[8];
   
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("cal 8 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[5] = qual[9];
    list->qual[6] = qual[10];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[25] = 0;
      break;
    }    
    qual[25] = caltab[0];
    qual[26] = caltab[1];
    list->qual[7] = qual[25];
    list->qual[8] = qual[26];
        
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 12 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[27] = 0;
      break;
    }
    qual[27] = caltab[0];
    qual[28] = caltab[1];
    list->qual[9]  = qual[27];
    list->qual[10] = qual[28];
    MMG_swpptr = MMG_swap710_6;
    return(76);
  } while(0);
        
 /*cas 7*/
 do {
   if(!qual[5]) break;
   else if(qual[5] == -1) {
     pt1 = &mesh->tetra[0];
     pt1->v[0] = ia;
     pt1->v[1] = s1;
     pt1->v[2] = s4;
     pt1->v[3] = s5;
     if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
       //printf("2:cal 5 %e %e\n",caltab[0],MMG_voltet(mesh,0));
       memset(pt1,0,sizeof(Tetra));
       qual[5] = 0;
       break;
     }
     qual[5] = caltab[0];
     qual[6] = caltab[1];
    } 
    list->qual[1] = qual[5];
    list->qual[2] = qual[6];
    
    if(!qual[11]) break;
    else if (qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[11] = 0;
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }
    list->qual[3] = qual[11];
    list->qual[4] = qual[12];
   
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[5] = qual[13];
    list->qual[6] = qual[14];
    
    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[7] = qual[25];
    list->qual[8] = qual[26];
    
    if(!qual[27]) break;
    else if(qual[27] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 12 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[27] = 0;
        break;
      }
      qual[27] = caltab[0];
      qual[28] = caltab[1];
    }
    list->qual[9]  = qual[27];
    list->qual[10] = qual[28];
    MMG_swpptr = MMG_swap710_7;
    return(77);    
 } while(0); 
 
 /*cas 8*/
 do {
   if(!qual[13]) break;
   else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[1] = qual[13];
    list->qual[2] = qual[14];
   
    if(!qual[15]) break;
    else if(qual[15] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 15 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[15] = 0;
        break;
      }  
      qual[15] = caltab[0];
      qual[16] = caltab[1];
    }
    list->qual[3] = qual[15];
    list->qual[4] = qual[16];
    
    if(!qual[17]) break;
    else if(qual[17] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 17 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[17] = 0;
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    } 
    list->qual[5] = qual[17];
    list->qual[6] = qual[18];
    
    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[7] = qual[25];
    list->qual[8] = qual[26];
    
    if(!qual[27]) break;
    else if(qual[27] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 12 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[27] = 0;
        break;
      }
      qual[27] = caltab[0];
      qual[28] = caltab[1];
    }
    list->qual[9]  = qual[27];
    list->qual[10] = qual[28];
    MMG_swpptr = MMG_swap710_8;
    return(78);  
 } while(0);	
 
 /*cas 9*/
 do {
    if(!qual[17]) break;
    else if(qual[17] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 17 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[17] = 0;
        break;
      }
      qual[17] = caltab[0];
      qual[18] = caltab[1];
    } 
    list->qual[1] = qual[17];
    list->qual[2] = qual[18];
    
    if(!qual[19]) break;
    else if(qual[19] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 19 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[19] = 0;
        break;
      }  
      qual[19] = caltab[0];
      qual[20] = caltab[1];
    }
    list->qual[3] = qual[19];
    list->qual[4] = qual[20];
   
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[5] = qual[21];
    list->qual[6] = qual[22];
    
    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[7] = qual[25];
    list->qual[8] = qual[26];

    if(!qual[27]) break;
    else if(qual[27] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 12 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[27] = 0;
        break;
      }
      qual[27] = caltab[0];
      qual[28] = caltab[1];
    }
    list->qual[9]  = qual[27];
    list->qual[10] = qual[28];
    MMG_swpptr = MMG_swap710_9;
    return(79);          
 } while(0);
 
 /*cas 10*/
 do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[1] = qual[9];
    list->qual[2] = qual[10];
    
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[3] = qual[21];
    list->qual[4] = qual[22];
    
    if(!qual[23]) break;
    else if(qual[23] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[23] = 0;
        break;
      }
      qual[23] = caltab[0];
      qual[24] = caltab[1];
    }
    list->qual[5]  = qual[23];
    list->qual[6] = qual[24];
    
    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[7] = qual[25];
    list->qual[8] = qual[26];
    
    if(!qual[27]) break;
    else if(qual[27] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 12 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[27] = 0;
        break;
      }
      qual[27] = caltab[0];
      qual[28] = caltab[1];
    }
    list->qual[9]  = qual[27];
    list->qual[10] = qual[28];
    
    MMG_swpptr = MMG_swap710_10;
    memset(pt1,0,sizeof(Tetra));
    return(80);        
 } while(0);
 
 /*cas 11*/
 do {
    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[1] = qual[25];
    list->qual[2] = qual[26];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[29] = 0;
      break;
    }	 
    qual[29] = caltab[0];
    qual[30] = caltab[1];
    list->qual[3] = qual[29];
    list->qual[4] = qual[30];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s6;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[31] = 0;
      break;
    }	 
    qual[31] = caltab[0];
    qual[32] = caltab[1];
    list->qual[5] = qual[31];
    list->qual[6] = qual[32];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[33] = 0;
      break;
    }	 
    qual[33] = caltab[0];
    qual[34] = caltab[1];
    list->qual[7] = qual[33];
    list->qual[8] = qual[34];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[35] = 0;
      break;
    }	 
    qual[35] = caltab[0];
    qual[36] = caltab[1];
    list->qual[9]  = qual[35];
    list->qual[10] = qual[36];       
    
    memset(pt1,0,sizeof(Tetra));
    MMG_swpptr = MMG_swap710_11;
    return(81);
 } while(0);
 
 /*cas 12*/
 do {
    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
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
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[31] = 0;
        break;
      }	 
      qual[31] = caltab[0];
      qual[32] = caltab[1];
    }
    list->qual[3] = qual[31];
    list->qual[4] = qual[32];
    
    if(!qual[33]) break;
    else if(qual[33] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[33] = 0;
        break;
      }	 
      qual[33] = caltab[0];
      qual[34] = caltab[1];
    }
    list->qual[5] = qual[33];
    list->qual[6] = qual[34];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[37] = 0;
      break;
    }	 
    qual[37] = caltab[0];
    qual[38] = caltab[1];
    list->qual[7] = qual[37];
    list->qual[8] = qual[38];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[39] = 0;
      break;
    }	 
    qual[39] = caltab[0];
    qual[40] = caltab[1];
    list->qual[9] = qual[39];
    list->qual[10] = qual[40];
    
    MMG_swpptr = MMG_swap710_12;
    memset(pt1,0,sizeof(Tetra));
    return(82); 
    
 } while(0);
 
 /*cas 13*/
 do {
    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
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
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[31] = 0;
        break;
      }	 
      qual[31] = caltab[0];
      qual[32] = caltab[1];
    }
    list->qual[3] = qual[31];
    list->qual[4] = qual[32];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];    
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[41] = 0;
      break;
    }	 
    qual[41] = caltab[0];
    qual[42] = caltab[1];
    list->qual[7] = qual[41];
    list->qual[8] = qual[42];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s5;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[43] = 0;
      break;
    }	 
    qual[43] = caltab[0];
    qual[44] = caltab[1];
    list->qual[9]  = qual[43];
    list->qual[10] = qual[44];
    MMG_swpptr = MMG_swap710_13;
    memset(pt1,0,sizeof(Tetra));
    return(84); 
 } while(0);
 
 /*cas 15*/
 do {
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[1] = qual[21];
    list->qual[2] = qual[22];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[3] = qual[25];
    list->qual[4] = qual[26];
    
    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[5] = qual[29];
    list->qual[6] = qual[30];
    
    if(!qual[31]) break;
    else if(qual[31] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[31] = 0;
        break;
      }	 
      qual[31] = caltab[0];
      qual[32] = caltab[1];
    }
    list->qual[7] = qual[31];
    list->qual[8] = qual[32];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s4;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[47] = 0;
      break;
    }	 
    qual[47] = caltab[0];
    qual[48] = caltab[1];
    list->qual[9]  = qual[47];
    list->qual[10] = qual[48];
    
    MMG_swpptr = MMG_swap710_15;
    memset(pt1,0,sizeof(Tetra));
    return(85); 
 } while(0);
 
 /*cas 16*/
 do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[1] = qual[9];
    list->qual[2] = qual[10];
    
    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[3] = qual[25];
    list->qual[4] = qual[26];
	
    if(!qual[33]) break;
    else if(qual[33] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[33] = 0;
        break;
      }	 
      qual[33] = caltab[0];
      qual[34] = caltab[1];
    }
    list->qual[5] = qual[33];
    list->qual[6] = qual[34];
    
    if(!qual[35]) break;
    else if(qual[35] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[35] = 0;
        break;
      }	 
      qual[35] = caltab[0];
      qual[36] = caltab[1];
    }
    list->qual[7] = qual[35];
    list->qual[8] = qual[36];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[49] = 0;
      break;
    }  
    qual[49] = caltab[0];
    qual[50] = caltab[1];
    list->qual[9]  = qual[49];
    list->qual[10] = qual[50];
          
    MMG_swpptr = MMG_swap710_16;
    memset(pt1,0,sizeof(Tetra));
    return(86);  
 } while(0);
 
 /*cas 17*/
 do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[1] = qual[9];
    list->qual[2] = qual[10];
    
    if(!qual[33]) break;
    else if(qual[33] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        ////printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[33] = 0;
        break;
      }	 
      qual[33] = caltab[0];
      qual[34] = caltab[1];
    }
    list->qual[3] = qual[33];
    list->qual[4] = qual[34];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];    
    
    if(!qual[39]) break;
    else if(qual[39] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[39] = 0;
        break;
      }	 
      qual[39] = caltab[0];
      qual[40] = caltab[1];
    }
    list->qual[7] = qual[39];
    list->qual[8] = qual[40];
 
    if(!qual[49]) break;
    else if(qual[49] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[49] = 0;
        break;
      }  
      qual[49] = caltab[0];
      qual[50] = caltab[1];
    }
    list->qual[9]  = qual[49];
    list->qual[10] = qual[50];
    
    MMG_swpptr = MMG_swap710_17;
    memset(pt1,0,sizeof(Tetra));
    return(87);   
 } while(0);
 
 /*cas 18*/
 do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[1] = qual[9];
    list->qual[2] = qual[10];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[3] = qual[37];
    list->qual[4] = qual[38];    
 
     if(!qual[41]) break;
    else if(qual[41] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[41] = 0;
        break;
      }	 
      qual[41] = caltab[0];
      qual[42] = caltab[1];
    }
    list->qual[5] = qual[41];
    list->qual[6] = qual[42];
    
    if(!qual[43]) break;
    else if(qual[43] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[43] = 0;
        break;
      }	 
      qual[43] = caltab[0];
      qual[44] = caltab[1];
    }
    list->qual[7] = qual[43];
    list->qual[8] = qual[44];    

    if(!qual[49]) break;
    else if(qual[49] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[49] = 0;
        break;
      }  
      qual[49] = caltab[0];
      qual[50] = caltab[1];
    }
    list->qual[9]  = qual[49];
    list->qual[10] = qual[50];

    MMG_swpptr = MMG_swap710_18;
    memset(pt1,0,sizeof(Tetra));
    return(88);   
 } while(0);
 
 /*cas 19*/
 do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[1] = qual[9];
    list->qual[2] = qual[10];

    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[3] = qual[21];
    list->qual[4] = qual[22];

    if(!qual[41]) break;
    else if(qual[41] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[41] = 0;
        break;
      }	 
      qual[41] = caltab[0];
      qual[42] = caltab[1];
    }
    list->qual[5] = qual[41];
    list->qual[6] = qual[42];

    if(!qual[45]) break;
    else if(qual[45] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[45] = 0;
        break;
      }	 
      qual[45] = caltab[0];
      qual[46] = caltab[1];
    }
    list->qual[7] = qual[45];
    list->qual[8] = qual[46];
    
    if(!qual[49]) break;
    else if(qual[49] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[49] = 0;
        break;
      }  
      qual[49] = caltab[0];
      qual[50] = caltab[1];
    }
    list->qual[9]  = qual[49];
    list->qual[10] = qual[50];
    
  
    MMG_swpptr = MMG_swap710_19;
    memset(pt1,0,sizeof(Tetra));
    return(89);  
 } while(0);
 
 /*cas 20*/
 do {
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[1] = qual[9];
    list->qual[2] = qual[10];

    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[3] = qual[21];
    list->qual[4] = qual[22];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[5] = qual[25];
    list->qual[6] = qual[26];

    if(!qual[47]) break;
    else if(qual[47] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[47] = 0;
        break;
      }	 
      qual[47] = caltab[0];
      qual[48] = caltab[1];
    }
    list->qual[7] = qual[47];
    list->qual[8] = qual[48];    
    if(!qual[49]) break;
    else if(qual[49] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[49] = 0;
        break;
      }  
      qual[49] = caltab[0];
      qual[50] = caltab[1];
    }
    list->qual[9]  = qual[49];
    list->qual[10] = qual[50];
    
    MMG_swpptr = MMG_swap710_20;
    memset(pt1,0,sizeof(Tetra));
    return(90);   
 } while(0);

/*cas 21*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[3] = qual[37];
    list->qual[4] = qual[38]; 

    if(!qual[43]) break;
    else if(qual[43] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[43] = 0;
        break;
      }	 
      qual[43] = caltab[0];
      qual[44] = caltab[1];
    }
    list->qual[5] = qual[43];
    list->qual[6] = qual[44];    

    if(!qual[69]) break;
    else if(qual[69] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[69] = 0;
        break;
      }   
      qual[69] = caltab[0];
      qual[70] = caltab[1];
    }
    list->qual[7] = qual[69];
    list->qual[8] = qual[70];
       
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s3;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[51] = 0;
      break;
    }  
    qual[51] = caltab[0];
    qual[52] = caltab[1];
    list->qual[9]  = qual[51];
    list->qual[10] = qual[52];       

    MMG_swpptr = MMG_swap710_21;
    memset(pt1,0,sizeof(Tetra));
    return(91);   
} while(0);

/*cas 22*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[3] = qual[21];
    list->qual[4] = qual[22];
   
    if(!qual[45]) break;
    else if(qual[45] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[45] = 0;
        break;
      }	 
      qual[45] = caltab[0];
      qual[46] = caltab[1];
    }
    list->qual[5] = qual[45];
    list->qual[6] = qual[46];
    
    if(!qual[51]) break;
    else if(qual[51] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[51] = 0;
        break;
      }   
      qual[51] = caltab[0];
      qual[52] = caltab[1];
    }
    list->qual[7]  = qual[51];
    list->qual[8] = qual[52];    

    if(!qual[69]) break;
    else if(qual[69] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[69] = 0;
        break;
      }   
      qual[69] = caltab[0];
      qual[70] = caltab[1];
    }
    list->qual[9] = qual[69];
    list->qual[10] = qual[70];
        
    MMG_swpptr = MMG_swap710_22;
    memset(pt1,0,sizeof(Tetra));
    return(92);  
} while(0);

/*cas 23*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[19]) break;
    else if(qual[19] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 19 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[19] = 0;
        break;
      }  
      qual[19] = caltab[0];
      qual[20] = caltab[1];
    }
    list->qual[3] = qual[19];
    list->qual[4] = qual[20];
    
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[5] = qual[21];
    list->qual[6] = qual[22];

    if(!qual[51]) break;
    else if(qual[51] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[51] = 0;
        break;
      }   
      qual[51] = caltab[0];
      qual[52] = caltab[1];
    }
    list->qual[7] = qual[51];
    list->qual[8] = qual[52];   
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s4;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[53] = 0;
      break;
    }	
    qual[53] = caltab[0];
    qual[54] = caltab[1];
    
    list->qual[9]  = qual[53];
    list->qual[10] = qual[54];  
           
    MMG_swpptr = MMG_swap710_23;
    memset(pt1,0,sizeof(Tetra));
    return(93);  
} while(0);

/*cas 24*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];
    
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[3] = qual[13];
    list->qual[4] = qual[14];

    if(!qual[15]) break;
    else if(qual[15] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 15 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[15] = 0;
        break;
      }  
      qual[15] = caltab[0];
      qual[16] = caltab[1];
    }
    list->qual[5] = qual[15];
    list->qual[6] = qual[16];
    
    if(!qual[51]) break;
    else if(qual[51] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[51] = 0;
        break;
      }   
      qual[51] = caltab[0];
      qual[52] = caltab[1];
    }
    list->qual[7] = qual[51];
    list->qual[8] = qual[52];   

    if(!qual[53]) break;
    else if(qual[53] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[53] = 0;
        break;
      }	
      qual[53] = caltab[0];
      qual[54] = caltab[1];
    }
    list->qual[9]  = qual[53];
    list->qual[10] = qual[54];  
    
    MMG_swpptr = MMG_swap710_24;
    memset(pt1,0,sizeof(Tetra));
    return(94);  
} while(0);

/*cas 25*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];
    
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[3] = qual[13];
    list->qual[4] = qual[14];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];    

    if(!qual[51]) break;
    else if(qual[51] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[51] = 0;
        break;
      }   
      qual[51] = caltab[0];
      qual[52] = caltab[1];
    }
    list->qual[7] = qual[51];
    list->qual[8] = qual[52];    

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s5;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[55] = 0;
      break;
    }	
    qual[55] = caltab[0];
    qual[56] = caltab[1];
    
    list->qual[9]  = qual[55];
    list->qual[10] = qual[56];    

    MMG_swpptr = MMG_swap710_25;
    memset(pt1,0,sizeof(Tetra));
    return(95);  
} while(0);

/*cas 26*/
do {
    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[1] = qual[29];
    list->qual[2] = qual[30];
    
    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[3] = qual[37];
    list->qual[4] = qual[38];
    
    if(!qual[43]) break;
    else if(qual[43] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[43] = 0;
        break;
      }	 
      qual[43] = caltab[0];
      qual[44] = caltab[1];
    }
    list->qual[5] = qual[43];
    list->qual[6] = qual[44];    

    if(!qual[69]) break;
    else if(qual[69] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[69] = 0;
        break;
      }  
      qual[69] = caltab[0];
      qual[70] = caltab[1];
    }
    list->qual[7] = qual[69];
    list->qual[8] = qual[70];
    
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[57] = 0;
      break;
    }  
    qual[57] = caltab[0];
    qual[58] = caltab[1];
    list->qual[9]  = qual[57];
    list->qual[10] = qual[58];    
            
    MMG_swpptr = MMG_swap710_26;
    memset(pt1,0,sizeof(Tetra));
    return(96);  
} while(0);

/*cas 27*/
do {
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[1] = qual[21];
    list->qual[2] = qual[22];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[3] = qual[29];
    list->qual[4] = qual[30];

    if(!qual[45]) break;
    else if(qual[45] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[45] = 0;
        break;
      }
      qual[45] = caltab[0];
      qual[46] = caltab[1];
    }
    list->qual[5] = qual[45];
    list->qual[6] = qual[46];    

    if(!qual[57]) break;
    else if(qual[57] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[57] = 0;
        break;
      }  
      qual[57] = caltab[0];
      qual[58] = caltab[1];
    }
    list->qual[7] = qual[57];
    list->qual[8] = qual[58];    
            
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s6;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[69] = 0;
      break;
    }  
    qual[69] = caltab[0];
    qual[70] = caltab[1];
    list->qual[9]  = qual[69];
    list->qual[10] = qual[70];    
    MMG_swpptr = MMG_swap710_27;
    memset(pt1,0,sizeof(Tetra));
    return(97);  
} while(0);

/*cas 28*/
do {
    if(!qual[19]) break;
    else if(qual[19] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 19 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[19] = 0;
        break;
      }  
      qual[19] = caltab[0];
      qual[20] = caltab[1];
    }
    list->qual[1] = qual[19];
    list->qual[2] = qual[20];
   
    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
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
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[5] = qual[29];
    list->qual[6] = qual[30];

    if(!qual[53]) break;
    else if(qual[53] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[53] = 0;
        break;
      }	
      qual[53] = caltab[0];
      qual[54] = caltab[1];
    }
    list->qual[7] = qual[53];
    list->qual[8] = qual[54];  

    if(!qual[57]) break;
    else if(qual[57] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[57] = 0;
        break;
      }  
      qual[57] = caltab[0];
      qual[58] = caltab[1];
    }
    list->qual[9] = qual[57];
    list->qual[10] = qual[58];    

    MMG_swpptr = MMG_swap710_28;
    memset(pt1,0,sizeof(Tetra));
    return(98);  
} while(0);

/*cas 29*/
do {
   if(!qual[13]) break;
   else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[1] = qual[13];
    list->qual[2] = qual[14];
   
    if(!qual[15]) break;
    else if(qual[15] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 15 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[15] = 0;
        break;
      }  
      qual[15] = caltab[0];
      qual[16] = caltab[1];
    }
    list->qual[3] = qual[15];
    list->qual[4] = qual[16];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[5] = qual[29];
    list->qual[6] = qual[30];

    if(!qual[53]) break;
    else if(qual[53] == -1) {    
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[53] = 0;
        break;
      }	
      qual[53] = caltab[0];
      qual[54] = caltab[1];
    }
    list->qual[7] = qual[53];
    list->qual[8] = qual[54];  

    if(!qual[57]) break;
    else if(qual[57] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[57] = 0;
        break;
      }  
      qual[57] = caltab[0];
      qual[58] = caltab[1];
    }
    list->qual[9] = qual[57];
    list->qual[10] = qual[58];    

    MMG_swpptr = MMG_swap710_29;
    memset(pt1,0,sizeof(Tetra));
    return(99); 
} while(0);

/*cas 30*/
do {
   if(!qual[13]) break;
   else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[1] = qual[13];
    list->qual[2] = qual[14];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[3] = qual[29];
    list->qual[4] = qual[30];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];    

    if(!qual[55]) break;
    else if(qual[55] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[55] = 0;
        break;
      }	
      qual[55] = caltab[0];
      qual[56] = caltab[1];
    }
    list->qual[8] = qual[55];
    list->qual[9] = qual[56];    
    
    if(!qual[57]) break;
    else if(qual[57] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[57] = 0;
        break;
      }  
      qual[57] = caltab[0];
      qual[58] = caltab[1];
    }
    list->qual[9] = qual[57];
    list->qual[10] = qual[58];    
    
    MMG_swpptr = MMG_swap710_30;
    memset(pt1,0,sizeof(Tetra));
    return(100); 
} while(0);

/*cas 31*/
do {
    if(!qual[19]) break;
    else if(qual[19] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 19 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[19] = 0;
        break;
      }  
      qual[19] = caltab[0];
      qual[20] = caltab[1];
    }
    list->qual[1] = qual[19];
    list->qual[2] = qual[20];

    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[3] = qual[21];
    list->qual[4] = qual[22];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[5] = qual[25];
    list->qual[6] = qual[26];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[7] = qual[29];
    list->qual[8] = qual[30];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s4;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[59] = 0;
      break;
    }  
    qual[59] = caltab[0];
    qual[60] = caltab[1];
    list->qual[9]  = qual[59];
    list->qual[10] = qual[60];
    
    MMG_swpptr = MMG_swap710_31;
    memset(pt1,0,sizeof(Tetra));
    return(101); 
} while(0);

/*cas 32*/
do {
   if(!qual[13]) break;
   else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[1] = qual[13];
    list->qual[2] = qual[14];
   
    if(!qual[15]) break;
    else if(qual[15] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 15 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[15] = 0;
        break;
      }  
      qual[15] = caltab[0];
      qual[16] = caltab[1];
    }
    list->qual[3] = qual[15];
    list->qual[4] = qual[16];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[5] = qual[25];
    list->qual[6] = qual[26];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[7] = qual[29];
    list->qual[8] = qual[30];
    
    if(!qual[59]) break;
    else if(qual[59] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[59] = 0;
        break;
      }  
      qual[59] = caltab[0];
      qual[60] = caltab[1];
    }
    list->qual[9]  = qual[59];
    list->qual[10] = qual[60];
    
    MMG_swpptr = MMG_swap710_32;
    memset(pt1,0,sizeof(Tetra));
    return(102); 
} while(0);

/*cas 33*/
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
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("cal 6 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[7] = 0;
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    } 
    list->qual[3] = qual[7];
    list->qual[4] = qual[8];
   
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("cal 8 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[5] = qual[9];
    list->qual[6] = qual[10];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[7] = qual[37];
    list->qual[8] = qual[38];    

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s3;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[61] = 0;
      break;
    }  
    qual[61] = caltab[0];
    qual[62] = caltab[1];
    list->qual[9]  = qual[61];
    list->qual[10] = qual[62];

    MMG_swpptr = MMG_swap710_33;
    memset(pt1,0,sizeof(Tetra));
    return(103); 
} while(0);

/*cas 34*/
do {
    if(!qual[7]) break;
    else if(qual[7] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("cal 6 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[7] = 0;
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    } 
    list->qual[1] = qual[7];
    list->qual[2] = qual[8];
   
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("cal 8 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[3] = qual[9];
    list->qual[4] = qual[10];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];    

    if(!qual[39]) break;
    else if(qual[39] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[39] = 0;
        break;
      }	 
      qual[39] = caltab[0];
      qual[40] = caltab[1];
    }
    list->qual[7] = qual[39];
    list->qual[8] = qual[40];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[63] = 0;
      break;
    }  
    qual[63] = caltab[0];
    qual[64] = caltab[1];
    list->qual[9]  = qual[63];
    list->qual[10] = qual[64];
    
    MMG_swpptr = MMG_swap710_34;
    memset(pt1,0,sizeof(Tetra));
    return(104); 
} while(0);

/*cas 35*/
do {
    if(!qual[7]) break;
    else if(qual[7] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("cal 6 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[7] = 0;
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
    } 
    list->qual[1] = qual[7];
    list->qual[2] = qual[8];
   
    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("cal 8 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[3] = qual[9];
    list->qual[4] = qual[10];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[5] = qual[25];
    list->qual[6] = qual[26];

    if(!qual[35]) break;
    else if(qual[35] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[35] = 0;
        break;
      }	 
      qual[35] = caltab[0];
      qual[36] = caltab[1];
    }
    list->qual[7] = qual[35];
    list->qual[8] = qual[36];

    if(!qual[63]) break;
    else if(qual[63] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[63] = 0;
        break;
      }  
      qual[63] = caltab[0];
      qual[64] = caltab[1];
    }
    list->qual[9]  = qual[63];
    list->qual[10] = qual[64];
    
    MMG_swpptr = MMG_swap710_35;
    memset(pt1,0,sizeof(Tetra));
    return(105); 
} while(0);

/*cas 36*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[11]) break;
    else if (qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[11] = 0;
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }
    list->qual[3] = qual[11];
    list->qual[4] = qual[12];
    
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[5] = qual[13];
    list->qual[6] = qual[14];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[7] = qual[37];
    list->qual[8] = qual[38];
    
    if(!qual[61]) break;
    else if(qual[61] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[61] = 0;
        break;
      }  
      qual[61] = caltab[0];
      qual[62] = caltab[1];
    }
    list->qual[9]  = qual[61];
    list->qual[10] = qual[62];         
    
    MMG_swpptr = MMG_swap710_36;
    memset(pt1,0,sizeof(Tetra));
    return(106); 
} while(0);

/*cas 37*/
do {
    if(!qual[11]) break;
    else if (qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[11] = 0;
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }
    list->qual[1] = qual[11];
    list->qual[2] = qual[12];
    
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[3] = qual[13];
    list->qual[4] = qual[14];
    
    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];

    if(!qual[39]) break;
    else if(qual[39] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[39] = 0;
        break;
      }	 
      qual[39] = caltab[0];
      qual[40] = caltab[1];
    }
    list->qual[7] = qual[39];
    list->qual[8] = qual[40];

    if(!qual[63]) break;
    else if(qual[63] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[63] = 0;
        break;
      }  
      qual[63] = caltab[0];
      qual[64] = caltab[1];
    }
    list->qual[9]  = qual[63];
    list->qual[10] = qual[64];
    
    MMG_swpptr = MMG_swap710_37;
    memset(pt1,0,sizeof(Tetra));
    return(107); 
} while(0);

/*cas 38*/
do {
    if(!qual[11]) break;
    else if (qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        //printf("2:cal 11 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[11] = 0;
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }
    list->qual[1] = qual[11];
    list->qual[2] = qual[12];
    
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[3] = qual[13];
    list->qual[4] = qual[14];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[5] = qual[25];
    list->qual[6] = qual[26];

    if(!qual[35]) break;
    else if(qual[35] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[35] = 0;
        break;
      }	 
      qual[35] = caltab[0];
      qual[36] = caltab[1];
    }
    list->qual[7] = qual[35];
    list->qual[8] = qual[36];

    if(!qual[63]) break;
    else if(qual[63] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[63] = 0;
        break;
      }  
      qual[63] = caltab[0];
      qual[64] = caltab[1];
    }
    list->qual[9]  = qual[63];
    list->qual[10] = qual[64];
    
    MMG_swpptr = MMG_swap710_38;
    memset(pt1,0,sizeof(Tetra));
    return(108); 
} while(0);

/*cas 39*/
do {
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[1] = qual[13];
    list->qual[2] = qual[14];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[3] = qual[29];
    list->qual[4] = qual[30];
    
    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38];    

    if(!qual[39]) break;
    else if(qual[39] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[39] = 0;
        break;
      }	 
      qual[39] = caltab[0];
      qual[40] = caltab[1];
    }
    list->qual[7] = qual[39];
    list->qual[8] = qual[40];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s5;
    pt1->v[3] = s7;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[65] = 0;
      break;
    }  
    qual[65] = caltab[0];
    qual[66] = caltab[1];  
    list->qual[9]  = qual[65];
    list->qual[10] = qual[66];
        
    MMG_swpptr = MMG_swap710_39;
    memset(pt1,0,sizeof(Tetra));
    return(109); 
} while(0);

/*cas 40*/
do {
    if(!qual[13]) break;
    else if(qual[13] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s5;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 13 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[13] = 0;
        break;
      }
      qual[13] = caltab[0];
      qual[14] = caltab[1];
    } 
    list->qual[1] = qual[13];
    list->qual[2] = qual[14];

    if(!qual[25]) break;
    else if(qual[25] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[25] = 0;
        break;
      }    
      qual[25] = caltab[0];
      qual[26] = caltab[1];
    }
    list->qual[3] = qual[25];
    list->qual[4] = qual[26];

    if(!qual[29]) break;
    else if(qual[29] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[29] = 0;
        break;
      }	 
      qual[29] = caltab[0];
      qual[30] = caltab[1];
    }
    list->qual[5] = qual[29];
    list->qual[6] = qual[30];

    if(!qual[35]) break;
    else if(qual[35] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[35] = 0;
        break;
      }	 
      qual[35] = caltab[0];
      qual[36] = caltab[1];
    }
    list->qual[7] = qual[35];
    list->qual[8] = qual[36];

    if(!qual[65]) break;
    else if(qual[65] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s5;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[65] = 0;
        break;
      }  
      qual[65] = caltab[0];
      qual[66] = caltab[1];  
    }
    list->qual[9]  = qual[65];
    list->qual[10] = qual[66];

    MMG_swpptr = MMG_swap710_40;
    memset(pt1,0,sizeof(Tetra));
    return(110); 
} while(0);

/*cas 41*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[3] = qual[9];
    list->qual[4] = qual[10];

    if(!qual[21]) break;
    else if(qual[21] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s4;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 21 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[21] = 0;
        break;
      }
      qual[21] = caltab[0];
      qual[22] = caltab[1];
    }  
    list->qual[5] = qual[21];
    list->qual[6] = qual[22];

    if(!qual[45]) break;
    else if(qual[45] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[45] = 0;
        break;
      }	 
      qual[45] = caltab[0];
      qual[46] = caltab[1];
    }
    list->qual[7] = qual[45];
    list->qual[8] = qual[46];

    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s3;
    pt1->v[3] = s6;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
      memset(pt1,0,sizeof(Tetra));
      qual[67] = 0;
      break;
    }  
    qual[67] = caltab[0];
    qual[68] = caltab[1];
    list->qual[9]  = qual[67];
    list->qual[10] = qual[68];
    
    MMG_swpptr = MMG_swap710_41;
    memset(pt1,0,sizeof(Tetra));
    return(111); 
} while(0);

/*cas 42*/
do {
    if(!qual[1]) break;
    list->qual[1] = qual[1];
    list->qual[2] = qual[2];

    if(!qual[9]) break;
    else if(qual[9] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s6;
      pt1->v[3] = s7;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)){
        //printf("2:cal 9 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
	qual[9] = 0;
        break;
      }
      qual[9]  = caltab[0];
      qual[10] = caltab[1];
    } 
    list->qual[3] = qual[9];
    list->qual[4] = qual[10];

    if(!qual[37]) break;
    else if(qual[37] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[37] = 0;
        break;
      }	 
      qual[37] = caltab[0];
      qual[38] = caltab[1];
    }
    list->qual[5] = qual[37];
    list->qual[6] = qual[38]; 

    if(!qual[43]) break;
    else if(qual[43] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s5;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[43] = 0;
        break;
      }	 
      qual[43] = caltab[0];
      qual[44] = caltab[1];
    }
    list->qual[7] = qual[43];
    list->qual[8] = qual[44];    

    if(!qual[67]) break;
    else if(qual[67] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s6;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        //printf("2:cal 25 %e %e\n",caltab[0],MMG_voltet(mesh,0));
        memset(pt1,0,sizeof(Tetra));
        qual[67] = 0;
        break;
      }  
      qual[67] = caltab[0];
      qual[68] = caltab[1];
    }
    list->qual[9]  = qual[67];
    list->qual[10] = qual[68];
    
    MMG_swpptr = MMG_swap710_42;
    memset(pt1,0,sizeof(Tetra));
    return(112);
} while(0);
 
 return(0);
}
