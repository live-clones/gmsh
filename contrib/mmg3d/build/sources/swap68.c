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

/*find points of polygone*/
static int MMG_findpolygone(pMesh mesh,int iel,int iar,int *s) {
  pTetra pt,pt1;
  int ia,ib;
  int iadr,*adja,k,adj;
  int s1,s2,s3,s4,s5,s6;
  short voy;

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
    puts("MMG_simu56_ani: point s2 non existant");
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
  
  /*printf("polygone : %d %d %d %d %d %d\n",s1,s2,s3,s4,s5,s6);*/
  s[0]=s1;
  s[1]=s2;
  s[2]=s3;
  s[3]=s4;
  s[4]=s5;
  s[5]=s6;
  return(1);
}

static int MMG_updatebdryinfo(pMesh mesh,pHedge hed,pList list) { 
	pTetra  pt1;
	int     iel,i,k;
	
	for(k=1 ; k<=8 ; k++) { 
		iel = list->tetra[k];
	  pt1 = &mesh->tetra[iel];
	  for(i=0 ; i<6 ; i++) { 
	  	pt1->bdryinfo[i] = MMG_edgePut(hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
	  	if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	  }
	}
	
	return(1);
}

int MMG_swap68_1(pMesh mesh,pSol sol,pList list) { 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short   voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP661 IGNORED\n"); 
  }   

  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  //printf("nx : %d %d %d %d %d %d %d %d\n",jel,kel,lel,mel,nel,oel,pel,qel);
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4; 
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[1] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 1;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[1] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 1;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      iadr = (pel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[pel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = pel*4 + 2;
      }
      
      iadr = (qel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[qel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = qel*4 + 3;
      }
    } else {
       /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      if(old == adja[j] / 4) {        
         iadr = (lel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[lel].bdryref[1] = ref_a;
          
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = lel*4 + 1; 
         }
      
         iadr = (mel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[mel].bdryref[1] = ref_b;         
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = mel*4 + 1;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1;  
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1; 
         }
      }
      else {
       iadr = (nel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[nel].bdryref[1] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = nel*4 + 1;
       }
      
       iadr = (oel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[oel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = oel*4 + 1; 
       }    
     }
    }
   }
 }
 
  /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  adja[2] = pel*4 + 3;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  adja[3] = qel*4 + 2; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;

  /* remove 6 old tetra */
  for (k=1; k<=6; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;

	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_2(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP662 IGNORED\n"); 
  }   


  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;   
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[1] = ref_a;
        
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 1; 
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[1] = ref_b;
       
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 1; 
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (nel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[nel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = nel*4 + 2;
      }
      
      iadr = (oel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[oel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = oel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (lel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[lel].bdryref[1] = ref_a;
          
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = lel*4 + 1; 
         }
      
         iadr = (mel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[mel].bdryref[1] = ref_b;
          
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = mel*4 + 1; 
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1; 
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[3] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[3] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 3;
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[2] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[2] = ref_b;
        
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 2;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  adja[1] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  adja[1] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_3(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;    

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

    
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[1] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 1;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[1] = ref_b;

      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 1;
      }
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 2; 
      }
      
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[3] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 3;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[2] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 2;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 1; 
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[1] = ref_a;
        
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 1;
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 1;
       }     
     }
    }
   }
  }  

  /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[1] = oel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 1;
  adja[3] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
  adja[2] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 3;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 2;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_4(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP684 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;  
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[1] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 1;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[1] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 1;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[2] = ref_a;
       
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 2;
      }
      
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[3] = ref_b;
       
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[3] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 3;
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[2] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 2; 
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
          
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[3] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[3] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 3;
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[2] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[2] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 2;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[1] = oel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 1;
  adja[1] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
  adja[1] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_5(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP685 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[3] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 3;
      }  
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 2;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (nel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[nel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = nel*4 + 2;
      }
      
      iadr = (oel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[oel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = oel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (jel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[jel].bdryref[1] = ref_a;
         
         if (adj_a){
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = jel*4 + 1;
         }
         
         iadr = (kel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[kel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = kel*4 + 1; 
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
          
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[3] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[3] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 3;
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[2] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[2] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 2;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  adja[1] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  adja[1] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_6(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP686 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;  
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[3] = ref_a;
     
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 3;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 2;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (pel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[pel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = pel*4 + 2;
      }
      
      iadr = (qel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[qel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = qel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (jel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[jel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = jel*4 + 1;
         }
      
         iadr = (kel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[kel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = kel*4 + 1;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
          
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1; 
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (nel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[nel].bdryref[1] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = nel*4 + 1; 
       }
      
       iadr = (oel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[oel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = oel*4 + 1;
       }     
     }
    }
   }
  }  
 
  /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  adja[2] = pel*4 + 3;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  adja[3] = qel*4 + 2; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_7(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP687 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;  
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (nel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[nel].bdryref[3] = ref_a; 
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = nel*4 + 3;
      }
      
      iadr = (oel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[oel].bdryref[2] = ref_b; 
       
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = oel*4 + 2; 
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[2] = ref_a; 
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[3] = ref_b; 
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[3] = ref_a; 
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 3;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[2] = ref_b; 
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 2; 
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (jel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[jel].bdryref[1] = ref_a; 
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = jel*4 + 1; 
         }
      
         iadr = (kel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[kel].bdryref[1] = ref_b; 
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = kel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[1] = ref_a; 
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 1; 
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[1] = ref_b; 
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 1;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = lel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 3;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 2;
  adja[1] = oel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 1;
  adja[1] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
  adja[1] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_8(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP688 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;  
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[3] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 3;    
      }
      
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 2;  
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[3] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 3;
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[2] = ref_b;
          
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 2;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1; 
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[3] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[3] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 3;
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[2] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[2] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 2;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = lel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 1;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
  adja[1] = oel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 1;
  adja[1] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
  adja[1] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_9(pMesh mesh,pSol sol,pList list){
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP689 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a; 
      mesh->tetra[jel].bdryref[1] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 1;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[1] = ref_b;
       
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 1;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (nel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[nel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = nel*4 + 2; 
      }
      
      iadr = (oel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[oel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = oel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (lel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[lel].bdryref[3] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = lel*4 + 3;
         }
      
         iadr = (mel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[mel].bdryref[2] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = mel*4 + 2;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 1;
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 1; 
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (lel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[lel].bdryref[1] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = lel*4 + 1;
       }
      
       iadr = (mel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[mel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = mel*4 + 1; 
       }    
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = qel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = pel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = qel*4 + 1;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = pel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = qel*4 + 3;

  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = nel*4 + 3;
  adja[3] = jel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = oel*4 + 2;
  adja[2] = kel*4 + 3;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_10(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP6810 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;  
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4; 
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[3] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 3;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 2;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (pel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[pel].bdryref[2] = ref_a;
        
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = pel*4 + 2;
      }
      
      iadr = (qel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[qel].bdryref[3] = ref_b;
       
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = qel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (jel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[jel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = jel*4 + 1;
         }
      
         iadr = (kel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[kel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = kel*4 + 1;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 1;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 1; 
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (lel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[lel].bdryref[1] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = lel*4 + 1;
       }
      
       iadr = (mel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[mel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = mel*4 + 1; 
       }    
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  adja[2] = nel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[3] = oel*4 + 1;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = pel*4 + 3;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = qel*4 + 2; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_11(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP6811 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a; 
      mesh->tetra[jel].bdryref[3] = ref_a; 
       
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 3;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[2] = ref_b; 
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 2; 
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (pel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[pel].bdryref[2] = ref_a; 
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = pel*4 + 2;
      }
      
      iadr = (qel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[qel].bdryref[3] = ref_b; 
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = qel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (jel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[jel].bdryref[1] = ref_a; 
        
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = jel*4 + 1;
         }
      
         iadr = (kel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[kel].bdryref[1] = ref_b; 
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = kel*4 + 1; 
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[1] = ref_a; 
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 1;
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[1] = ref_b; 
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (lel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[lel].bdryref[1] = ref_a; 
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = lel*4 + 1;
       }
      
       iadr = (mel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[mel].bdryref[1] = ref_b; 
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = mel*4 + 1;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  adja[2] = pel*4 + 1;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  adja[3] = qel*4 + 1; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_12(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP6812 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3; 
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;  
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (nel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[nel].bdryref[3] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = nel*4 + 3;
      }
      
      iadr = (oel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[oel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = oel*4 + 2;  
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[2] = ref_a;
       
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2; 
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 3;
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[3] = ref_a;
          
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 3;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[2] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 2; 
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (lel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[lel].bdryref[1] = ref_a;
          
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = lel*4 + 1;
         }
      
         iadr = (mel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[mel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = mel*4 + 1;
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[1] = ref_a;
       
       if (adj_a){
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 1;   
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 1;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = lel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 1;
  adja[3] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
  adja[2] = oel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 3;
  adja[1] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 2;
  adja[1] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_13(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP6813 IGNORED\n"); 
  }   


  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4; 
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[3] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 3;
      }
      
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 2;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 3; 
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (pel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[3] = adj_a*4 + voy_a;
         mesh->tetra[pel].bdryref[3] = ref_a;
          
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = pel*4 + 3;
         }
      
         iadr = (qel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[2] = adj_b*4 + voy_b;
         mesh->tetra[qel].bdryref[2] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = qel*4 + 2;  
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 1;
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 1; 
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (pel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_a*4 + voy_a;
       mesh->tetra[pel].bdryref[1] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = pel*4 + 1;
       }
      
       iadr = (qel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[1] = adj_b*4 + voy_b;
       mesh->tetra[qel].bdryref[1] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = qel*4 + 1;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = lel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 1;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
  adja[1] = oel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 1;
  adja[3] = pel*4 + 2;	
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
  adja[2] = qel*4 + 3; 
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 3;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 2;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}

int MMG_swap68_14(pMesh mesh,pSol sol,pList list){ 
  pTetra pt1,pt,pt0;
	Hedge			hed;
  int    i,ia,ib,s[6],j;
  int    jel,kel,lel,mel,nel,oel,pel,qel;
  int    iarold,iadr,*adja,k,adj,adj_a,adj_b,old,kk,iel,iar,ref,ref_a,ref_b;
  short  voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,21) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP6814 IGNORED\n"); 
  }   

  
  /*find points of polygone*/
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  if(!MMG_findpolygone(mesh,iel,iar,s)) return(0);
  
  pt  = &mesh->tetra[iel];  
	for(i=0 ; i<6 ; i++) { 
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  ref = pt->ref;
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
 
  /*create 8 tetras*/
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;

  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->flag = mesh->flag; 
  pt1->ref  = ref;
  
  /*external faces*/
  /*tetra iel*/
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;  
  }
  
  for(k=2 ; k<=6 ; k++) {    
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
	  for(i=0 ; i<6 ; i++) {
	  	MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
	  }
    iarold = list->tetra[k] % 6;
    kk    = MMG_iare[iarold][1];
    if(pt0->v[kk]==ib) {
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;  
      ref_a  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4;
      ref_b  = pt0->bdryref[kk];
    } else /*if(pt0->v[MMG_iare[iarold][0]]==ib)*/{
      adj_b  = adja[kk] / 4;
      voy_b  = adja[kk] % 4; 
      ref_b  = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] / 4;
      voy_a  = adja[kk] % 4;
      ref_a  = pt0->bdryref[kk];
    } 
   
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    /*s[1] appartient a old */
    if(old==(adja[MMG_isar[iar][0]]/4)) {
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[3] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 3;  
      }
      
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[2] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 2;
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      /*s[0] appartient a old*/
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[2] = ref_a;
      
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2; 
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[3] = ref_b;
      
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 3; 
      }
    } else {
      /*old n'est pas un voisin de iel*/
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      j    = MMG_isar[iar][0];
      adj  = adja[j] / 4;
      voy  = adja[j] % 4;
      pt1  = &mesh->tetra[adj];
    
     if(pt1->v[MMG_idir[voy][0]]==s[1]) {
         j = MMG_idir[voy][0];
      } else if(pt1->v[MMG_idir[voy][1]]==s[1]) {
         j = MMG_idir[voy][1];
      } else if(pt1->v[MMG_idir[voy][2]]==s[1]) {
         j = MMG_idir[voy][2];
      }

      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      /*s[2] s[3] appartient a old*/
      if(old == adja[j] / 4) {        
         iadr = (lel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[lel].bdryref[1] = ref_a;
         
         if (adj_a) {
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = lel*4 + 1;
         }
      
         iadr = (mel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[mel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = mel*4 + 1;
         }
      } else {
        iadr = (iel-1)*4 + 1;
        adja = &mesh->adja[iadr];
        j    = MMG_isar[iar][1];
        adj  = adja[j] / 4;
        voy  = adja[j] % 4;
        pt1  = &mesh->tetra[adj];
    
       if(pt1->v[MMG_idir[voy][0]]==s[0]) {
           j = MMG_idir[voy][0];
       } else if(pt1->v[MMG_idir[voy][1]]==s[0]) {
           j = MMG_idir[voy][1];
       } else if(pt1->v[MMG_idir[voy][2]]==s[0]) {
          j = MMG_idir[voy][2];
       }

       iadr = (adj-1)*4 + 1;
       adja = &mesh->adja[iadr];
       /*s[4] s[5] appartient a old*/
       if(old == adja[j] / 4) {   
         iadr = (nel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_a*4 + voy_a;
         mesh->tetra[nel].bdryref[1] = ref_a;
         
         if (adj_a) { 
           iadr = (adj_a-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_a] = nel*4 + 1;
         }
      
         iadr = (oel-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[1] = adj_b*4 + voy_b;
         mesh->tetra[oel].bdryref[1] = ref_b;
         
         if (adj_b) {
           iadr = (adj_b-1)*4 + 1;
           adja = &mesh->adja[iadr];
           adja[voy_b] = oel*4 + 1;   
         }
      }
      else {
      /*s[3] s[4] appartient a old*/
       iadr = (nel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[3] = adj_a*4 + voy_a;
       mesh->tetra[nel].bdryref[3] = ref_a;
       
       if (adj_a) {
         iadr = (adj_a-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_a] = nel*4 + 3;
       }
      
       iadr = (oel-1)*4 + 1;
       adja = &mesh->adja[iadr];
       adja[2] = adj_b*4 + voy_b;
       mesh->tetra[oel].bdryref[2] = ref_b;
       
       if (adj_b) {
         iadr = (adj_b-1)*4 + 1;
         adja = &mesh->adja[iadr];
         adja[voy_b] = oel*4 + 2;
       }     
     }
    }
   }
 }  
 
   /*internal faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = pel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = qel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = qel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 1;

  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 1;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = nel*4 + 2;
  adja[2] = jel*4 + 1;
  adja[3] = lel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = kel*4 + 1;
  adja[2] = mel*4 + 3;
  /* remove 6 old tetra */
  for (k=1; k<=6; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = nel;
  list->tetra[6] = oel;
  list->tetra[7] = pel;
  list->tetra[8] = qel;
  list->tetra[9] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(8);
}
