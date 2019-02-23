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

/* remove edge iar of iel */
int MMG_swap44_1(pMesh mesh,pSol sol,pList list) {
  pTetra    pt,pt0,pt1;
	Hedge			hed;
  int      *adja,i,k,jel,kel,lel,mel,adj,base,iadr,ia,ib,s1,s2,s3,s4;
  int       old,iarold,kk,adj_a,adj_b,iel,iar,ref,ref_a,ref_b;
  short     voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,13) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP441 IGNORED\n"); 
  }   

  /* face s1 s2 s3 */
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  base = mesh->mark;
  pt   = &mesh->tetra[iel];
  ref  = pt->ref;
  
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  s1  = pt->v[ MMG_isar[iar][0] ];
  s2  = pt->v[ MMG_isar[iar][1] ];
  for(i=0 ; i<6 ; i++) {
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}

  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s3   = pt1->v[voy];

  k    = MMG_isar[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s4   = pt1->v[voy];
 
  /* create 4 new tetra */
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s1;
  pt1->v[2] = s2;
  pt1->v[3] = s3;
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  
  /* 2nd elt */
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s1;
  pt1->v[2] = s3;
  pt1->v[3] = s2;
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s1;
  pt1->v[2] = s3;
  pt1->v[3] = s4;
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  /* 2nd elt */
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s1;
  pt1->v[2] = s4;
  pt1->v[3] = s3;
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  /* external faces*/
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
    if(iadr<0) {puts("aaaaaaaaaaaa");exit(0);}
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;  
  }
  
  for(k=2 ; k<=4 ; k++) {
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
  
	/*bdryinfo*/           
	pt1 = &mesh->tetra[jel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1); 
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	pt1 = &mesh->tetra[kel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	pt1 = &mesh->tetra[lel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	pt1 = &mesh->tetra[mel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	
  /* internal face */
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
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  
  /* remove 4 old tetra */
  for (k=1; k<=4; k++)
    MMG_delElt(mesh,list->tetra[k]/6);
    
  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = 0;
  
	M_free(hed.item);
  return(4);
}


/* remove edge iar of iel */
int MMG_swap44_2(pMesh mesh,pSol sol,pList list) {
  pTetra    pt,pt0,pt1;
	Hedge			hed;
  int      *adja,i,k,jel,kel,lel,mel,adj,base,iadr,ia,ib,s1,s2,s3,s4;
  int       old,iarold,kk,adj_a,adj_b,iel,iar,ref,ref_a,ref_b;
  short     voy,voy_a,voy_b;

  if ( !MMG_zaldy4(&hed,13) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP442 IGNORED\n"); 
  }   

  /* face s1 s2 s3 */
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  base = mesh->mark;
  pt   = &mesh->tetra[iel];
  ref  = pt->ref;
  
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  s1  = pt->v[ MMG_isar[iar][0] ];
  s2  = pt->v[ MMG_isar[iar][1] ];
	for(i=0 ; i<6 ; i++) { 
		//printf("on insere %d %d -- %d\n",pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}

  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][0];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s3   = pt1->v[voy];

  k    = MMG_isar[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s4   = pt1->v[voy];
 
  /* create 4 new tetra */
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s1;
  pt1->v[2] = s2;
  pt1->v[3] = s4;
  pt1->qual = list->qual[1];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  /* 2nd elt */
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s1;
  pt1->v[2] = s4;
  pt1->v[3] = s2;
  pt1->qual = list->qual[2];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s2;
  pt1->v[2] = s3;
  pt1->v[3] = s4;
  pt1->qual = list->qual[3];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;

  /* 2nd elt */
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s2;
  pt1->v[2] = s4;
  pt1->v[3] = s3;
  pt1->qual = list->qual[4];
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
 
  /* external faces*/
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
  
  for(k=2 ; k<=4 ; k++) {
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0 = &mesh->tetra[old];
		for(i=0 ; i<6 ; i++) {
			//printf("2. on insere %d %d -- %d\n",pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
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
    if(old==(adja[MMG_isar[iar][0]]/4)) {  
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[3]  = ref_a;
        
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 3; 
      }
       
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[2]  = ref_b;
        
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 2; 
      }
      
    } else if(old==(adja[MMG_isar[iar][1]]/4)){
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      mesh->tetra[jel].bdryref[2]  = ref_a;
        
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2; 
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[3] = adj_b*4 + voy_b;
      mesh->tetra[kel].bdryref[3]  = ref_b;
        
      if (adj_b){
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 3;
      }
    } else {
      iadr = (lel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a;
      mesh->tetra[lel].bdryref[1]  = ref_a;
        
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = lel*4 + 1; 
      }
      
      iadr = (mel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      mesh->tetra[mel].bdryref[1]  = ref_b;
        
      if (adj_b) {
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = mel*4 + 1;
      }
    }
  
  }
  /*bdryinfo*/           
	pt1 = &mesh->tetra[jel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);   
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	pt1 = &mesh->tetra[kel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	pt1 = &mesh->tetra[lel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	pt1 = &mesh->tetra[mel];
	for(i=0 ; i<6 ; i++) { 
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
		if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	}
	
  /* internal face */
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
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
  
  /* remove 4 old tetra */
  for (k=1; k<=4; k++)
    MMG_delElt(mesh,list->tetra[k]/6);
    
  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = lel;
  list->tetra[4] = mel;
  list->tetra[5] = 0;
  
	M_free(hed.item);
	
  return(4);
}
