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

int MMG_simu56(pMesh mesh,pSol sol,pList list,double crit) {
  pTetra	pt,pt1;
  double	qual[21],caltab[2];
  int		j,ia,ib,s1,s2,s3,s4,s5;
  int		iadr,*adja,k,adj,iel,iar;
  short		voy;
  
  for(j = 0 ; j<21 ; j++) {
    qual[j] = -1;
  }
  
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];

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
  s3   = pt1->v[voy];

  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_idir[voy][0]]==s2) {
     k = MMG_idir[voy][0];
  } else if(pt1->v[MMG_idir[voy][1]]==s2) {
     k = MMG_idir[voy][1];
  } else if(pt1->v[MMG_idir[voy][2]]==s2) {
     k = MMG_idir[voy][2];
  } else {
    puts("MMG_simu56_ani: point non existant");
    exit(0);
  }  
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s4   = pt1->v[voy];
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s5   = pt1->v[voy];
  
  do {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s2;
      pt1->v[3] = s3;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
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
     
     /* set function ptr */
     memset(pt1,0,sizeof(Tetra));
     MMG_swpptr = MMG_swap56_1;
     return(51);
  } while(0);
  
  do {
      if(!qual[1]) break;      
      list->qual[1] = qual[1];
      list->qual[2] = qual[2];
      
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s1;
      pt1->v[2] = s3;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[7] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[7] = caltab[0];
      qual[8] = caltab[1];
      list->qual[3] = qual[7];
      list->qual[4] = qual[8];
 
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s3;
      pt1->v[2] = s4;
      pt1->v[3] = s5;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab))  {
        qual[9] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[9] = caltab[0];
      qual[10] = caltab[1];
      list->qual[5] = qual[9];
      list->qual[6] = qual[10];
     
     /* set function ptr */
     memset(pt1,0,sizeof(Tetra));
     MMG_swpptr = MMG_swap56_3;
     return(53);
  } while(0);
  
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
    list->qual[1] = qual[5];
    list->qual[2] = qual[6];
        
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s3;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[11] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[11] = caltab[0];
    qual[12] = caltab[1];
    list->qual[3] = qual[11];
    list->qual[4] = qual[12];
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s4;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[13] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[13] = caltab[0];
    qual[14] = caltab[1];
    list->qual[5] = qual[13];
    list->qual[6] = qual[14];
     
     /* set function ptr */
     memset(pt1,0,sizeof(Tetra));
     MMG_swpptr = MMG_swap56_4;
     return(54);
  } while(0);
  
  do {
    if(!qual[11]) break;
    else if(qual[11] == -1) {
      pt1 = &mesh->tetra[0];
      pt1->v[0] = ia;
      pt1->v[1] = s2;
      pt1->v[2] = s3;
      pt1->v[3] = s4;
      if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
        qual[11] = 0;
        memset(pt1,0,sizeof(Tetra));
        break;
      }
      qual[11] = caltab[0];
      qual[12] = caltab[1];
    }  
    list->qual[3] = qual[11];
    list->qual[4] = qual[12];


    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[15] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[15] = caltab[0];
    qual[16] = caltab[1];
    list->qual[1] = qual[15];
    list->qual[2] = qual[16];
      
 
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s2;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[17] = 0;
      memset(pt1,0,sizeof(Tetra));
      break;
    }
    qual[17] = caltab[0];
    qual[18] = caltab[1];
    list->qual[5] = qual[17];
    list->qual[6] = qual[18];
     
     /* set function ptr */
     memset(pt1,0,sizeof(Tetra));
     MMG_swpptr = MMG_swap56_2;
     
     return(52);
  } while(0);
  
  if(!qual[15]) return(0);
  else if(qual[15] == -1) {
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s1;
    pt1->v[2] = s2;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[15] = 0;
      memset(pt1,0,sizeof(Tetra));
      return(0);
    }
    qual[15] = caltab[0];
    qual[16] = caltab[1];
  }
  list->qual[1] = qual[15];
  list->qual[2] = qual[16];
  
  if(!qual[9]) return(0);
  else if(qual[9] == -1) {
    pt1 = &mesh->tetra[0];
    pt1->v[0] = ia;
    pt1->v[1] = s3;
    pt1->v[2] = s4;
    pt1->v[3] = s5;
    if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
      qual[9] = 0;
      memset(pt1,0,sizeof(Tetra));
      return(0);
    }
    qual[9] = caltab[0];
    qual[10] = caltab[1];
  }  
  list->qual[5] = qual[9];
  list->qual[6] = qual[10];
  
  pt1 = &mesh->tetra[0];
  pt1->v[0] = ia;
  pt1->v[1] = s2;
  pt1->v[2] = s3;
  pt1->v[3] = s5;
  if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
    qual[19] = 0;
    memset(pt1,0,sizeof(Tetra));
    return(0);
  }
  qual[19] = caltab[0];
  qual[20] = caltab[1];
  list->qual[3] = qual[19];
  list->qual[4] = qual[20];
 


  /* set function ptr */
  memset(pt1,0,sizeof(Tetra));
  MMG_swpptr = MMG_swap56_5;
  return(55);
}
