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
static int MMG_findpolygone(pMesh mesh,pList list,int *s) {
  pTetra pt,pt1;
  int ia,ib;
  int j,iadr,*adja,k,adj,iar,iel;
  short voy;
 
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];

  /*find points of polygone*/
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
//  printf("MMG_swap edge %d %d\n",ia,ib);
  s[0]  = pt->v[ MMG_isar[iar][0] ];
  s[1]  = pt->v[ MMG_isar[iar][1] ]; 

  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][0];
  
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  for(j=0 ; j<6 ; j++)
    if((ia == pt1->v[MMG_iare[j][0]] && ib ==pt1->v[MMG_iare[j][1]]) ||
       (ia == pt1->v[MMG_iare[j][1]] && ib ==pt1->v[MMG_iare[j][0]])) break;
  assert(j<6);
  iar = j;
  list->tetra[2] = 6*adj + iar;
       
  s[2]  = pt1->v[voy];

  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_isar[iar][0]] == s[1]) {
    k = MMG_isar[iar][0];
  } else {
    assert(pt1->v[MMG_isar[iar][1]] == s[1]);
    k = MMG_isar[iar][1];
  }
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  for(j=0 ; j<6 ; j++)
    if((ia == pt1->v[MMG_iare[j][0]] && ib ==pt1->v[MMG_iare[j][1]]) ||
       (ia == pt1->v[MMG_iare[j][1]] && ib ==pt1->v[MMG_iare[j][0]])) break;
  assert(j<6);
  iar = j;
  list->tetra[3] = 6*adj + iar;
  
  s[3]   = pt1->v[voy];
  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_isar[iar][0]] == s[2]) {
    k = MMG_isar[iar][0];
  } else {
    assert(pt1->v[MMG_isar[iar][1]] == s[2]);
    k = MMG_isar[iar][1];
  }
     
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  for(j=0 ; j<6 ; j++)
    if((ia == pt1->v[MMG_iare[j][0]] && ib ==pt1->v[MMG_iare[j][1]]) ||
       (ia == pt1->v[MMG_iare[j][1]] && ib ==pt1->v[MMG_iare[j][0]])) break;
  assert(j<6);
  iar = j;
  list->tetra[4] = 6*adj + iar;
  
  s[4]   = pt1->v[voy];
  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_isar[iar][0]] == s[3]) {
    k = MMG_isar[iar][0];
  } else {
    assert(pt1->v[MMG_isar[iar][1]] == s[3]);
    k = MMG_isar[iar][1];
  }
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  for(j=0 ; j<6 ; j++)
    if((ia == pt1->v[MMG_iare[j][0]] && ib ==pt1->v[MMG_iare[j][1]]) ||
       (ia == pt1->v[MMG_iare[j][1]] && ib ==pt1->v[MMG_iare[j][0]])) break;
  assert(j<6);
  iar = j;
  list->tetra[5] = 6*adj + iar;
  
  s[5]   = pt1->v[voy]; 
  
  iadr = (adj-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if(pt1->v[MMG_isar[iar][0]] == s[4]) {
    k = MMG_isar[iar][0];
  } else {
    assert(pt1->v[MMG_isar[iar][1]] == s[4]);
    k = MMG_isar[iar][1];
  }
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  for(j=0 ; j<6 ; j++)
    if((ia == pt1->v[MMG_iare[j][0]] && ib ==pt1->v[MMG_iare[j][1]]) ||
       (ia == pt1->v[MMG_iare[j][1]] && ib ==pt1->v[MMG_iare[j][0]])) break;
  assert(j<6);
  iar = j;
  list->tetra[6] = 6*adj + j;
    
  iar  = list->tetra[1] % 6;  
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][1];
  adj  = adja[k] / 4;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  for(j=0 ; j<6 ; j++)
    if((ia == pt1->v[MMG_iare[j][0]] && ib ==pt1->v[MMG_iare[j][1]]) ||
       (ia == pt1->v[MMG_iare[j][1]] && ib ==pt1->v[MMG_iare[j][0]])) break;
  assert(j<6);
  list->tetra[7] = 6*adj + j;
  
  s[6]   = pt1->v[voy];
  
  return(1);
}

static int MMG_updatebdryinfo(pMesh mesh,pHedge hed,pList list) { 
	pTetra  pt1;
	int     iel,i,k;
	
	for(k=1 ; k<=10 ; k++) { 
		iel = list->tetra[k];
	  pt1 = &mesh->tetra[iel];
	  for(i=0 ; i<6 ; i++) { 
	  	pt1->bdryinfo[i] = MMG_edgePut(hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1);
	  	if(pt1->bdryinfo[i]<2) pt1->bdryinfo[i]=0;
	  }
	}
	
	return(1);
}

int MMG_swap710_1(pMesh mesh,pSol sol,pList list){
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   
  
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
	ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
     
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;  
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;  
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;  
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;  
  mesh->tetra[rel].bdryref[2] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[sel].bdryref[3] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = rel*4 + 3;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;
  adja[3] = sel*4 + 2;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[3] = pel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[2] = qel*4 + 3; 
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;

	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  

}
int MMG_swap710_2(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
	ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
 
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;  
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy; 
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;   
  mesh->tetra[sel].bdryref[3] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;  
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;   
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy; 
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
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
  adja[1] = rel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;
  adja[1] = sel*4 + 3;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = pel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = qel*4 + 1; 
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  

}
int MMG_swap710_3(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;
  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
 
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[rel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[sel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = rel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[3] = sel*4 + 2;
  
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
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = sel*4 + 1;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[3] = lel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[2] = mel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);
  
return(1);
}
int MMG_swap710_4(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;
  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
 
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
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
  adja[1] = pel*4 + 2;
  adja[3] = lel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = qel*4 + 3;
  adja[2] = mel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;
  adja[3] = rel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  adja[2] = sel*4 + 3;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = pel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = qel*4 + 2; 
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);
 
return(1);
}
int MMG_swap710_5(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;
  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
 
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
   iadr = (adj-1)*4 + 1;
   adja = &mesh->adja[iadr];
   adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = rel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
  adja[3] = sel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = nel*4 + 3;
  adja[3] = lel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = oel*4 + 2;
  adja[2] = mel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);
}
int MMG_swap710_6(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;
  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
 
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  } 
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = nel*4 + 3;
  adja[3] = jel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 2;
  adja[2] = kel*4 + 3;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  adja[2] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);
}
int MMG_swap710_7(pMesh mesh,pSol sol,pList list){  
 pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);

  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  adja[2] = sel*4 + 3;
  
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
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);
  
return(1);
}
int MMG_swap710_8(pMesh mesh,pSol sol,pList list){  
 pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);

  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = nel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = oel*4 + 1;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[3] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[2] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = nel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = oel*4 + 2;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);
}
int MMG_swap710_9(pMesh mesh,pSol sol,pList list){
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;
  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   
  
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
  
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;
 
  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;
  
  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[2] = sel*4 + 3;
  
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
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = jel*4 + 3;
  adja[1] = pel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = kel*4 + 2; 
  adja[1] = qel*4 + 3;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

/*printf("new tets %d %d %d %d %d %d %d %d %d %d\n",jel,kel,lel,mel,nel,oel,pel,qel,rel,sel);
  */list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);
        
  return(1);
  
}
int MMG_swap710_10(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[3];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }  
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = nel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = oel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = nel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 1;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = jel*4 + 3;
  adja[3] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = kel*4 + 2;
  adja[2] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
 
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = nel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = oel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  

}
int MMG_swap710_11(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;

  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3; 
  }
  
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  } 

  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1; 
  }
  
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
    
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
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
  adja[3] = rel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 2;
  adja[2] = sel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = pel*4 + 3;
  adja[3] = jel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = qel*4 + 2; 
  adja[2] = kel*4 + 3;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  

}
int MMG_swap710_12(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
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
  adja[3] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 2;
  adja[2] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = nel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = oel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  

}
int MMG_swap710_13(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
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
  adja[3] = pel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
  adja[2] = qel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;
  adja[2] = lel*4 + 3;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[3] = mel*4 + 2;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = pel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = qel*4 + 1; 
  adja[2] = oel*4 + 3;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  

}
int MMG_swap710_14(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
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
  adja[1] = rel*4 + 2;
  adja[2] = nel*4 + 3;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[3] = oel*4 + 2;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = pel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = kel*4 + 3; 
  adja[3] = qel*4 + 1;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  
}
int MMG_swap710_15(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = pel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = qel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;
  adja[3] = rel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  adja[2] = sel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = pel*4 + 3;
  adja[3] = lel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = kel*4 + 3; 
  adja[3] = qel*4 + 2;  
  adja[2] = mel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  
}
int MMG_swap710_16(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
                                            
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = qel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 3;
  adja[3] = lel*4 + 2;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 2;
  adja[2] = mel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = rel*4 + 1;
  adja[3] = pel*4 + 2;
 
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = qel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = nel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = oel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  
}
int MMG_swap710_17(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = rel*4 + 1;
  adja[3] = pel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = qel*4 + 3;
    
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
  adja[2] = lel*4 + 3;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = mel*4 + 2;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = mel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1); 
}
int MMG_swap710_18(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = sel*4 + 3;
  
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
  adja[2] = rel*4 + 1;
  adja[1] = pel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[1] = qel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = nel*4 + 1;
  adja[3] = lel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = oel*4 + 1;
  adja[2] = mel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = nel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = oel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1); 
}
int MMG_swap710_19(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = sel*4 + 3;
  
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
  adja[2] = rel*4 + 1;
  adja[1] = pel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[1] = qel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = nel*4 + 1;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = oel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = nel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = oel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1); 
}

int MMG_swap710_20(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[2] = sel*4 + 3;
  
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
  adja[2] = pel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = rel*4 + 1;
  adja[3] = nel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = sel*4 + 1;
  adja[2] = oel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1); 
}
int MMG_swap710_21(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt = &mesh->tetra[iel];
  assert(  pt->v[k] == ib);
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[rel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[sel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 3;
  adja[3] = lel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
  adja[2] = mel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = oel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[3] = jel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[2] = kel*4 + 3;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_22(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = nel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 1;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = rel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = sel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;
  adja[3] = jel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[2] = kel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = pel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = qel*4 + 1; 
  adja[2] = oel*4 + 3;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1); 
}
int MMG_swap710_23(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = rel*4 + 1;
  adja[3] = nel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = oel*4 + 3;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;
  adja[3] = jel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[2] = kel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = pel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = mel*4 + 3; 
  adja[3] = qel*4 + 1;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_24(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = nel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 1;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = rel*4 + 1;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = sel*4 + 1;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;
  adja[3] = jel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[2] = kel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = nel*4 + 2;
  adja[2] = pel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = oel*4 + 3; 
  adja[3] = qel*4 + 1;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_25(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = rel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = sel*4 + 1;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;
  adja[3] = jel*4 + 2;
 
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[2] = kel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = pel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = mel*4 + 3; 
  adja[3] = qel*4 + 1;  
  adja[2] = oel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_26(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt = &mesh->tetra[iel];
  assert(  pt->v[k] == ib);
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = nel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 2;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 3;
  adja[3] = lel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
  adja[2] = mel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = oel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 1;  
  
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  
}
int MMG_swap710_27(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
     
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[rel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[sel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = nel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = oel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = pel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = qel*4 + 3;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = rel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = sel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;
  adja[2] = lel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;
  adja[3] = mel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[2] = pel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[3] = qel*4 + 1; 
  adja[2] = oel*4 + 3;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);
 
  return(1);
}
int MMG_swap710_28(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = pel*4 + 1;
  adja[3] = lel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = qel*4 + 1;
  adja[2] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 2;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = nel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = oel*4 + 1;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_29(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = pel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = qel*4 + 1;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[1] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = sel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = nel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = oel*4 + 1;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_30(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = pel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = qel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = rel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = sel*4 + 3;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = rel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = sel*4 + 1;
  adja[2] = oel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = lel*4 + 1;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = mel*4 + 1;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_31(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 1;
  adja[3] = lel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = mel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 3;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 2;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = pel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = kel*4 + 3; 
  adja[3] = qel*4 + 1;  
  adja[2] = oel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_32(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[3];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[pel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[qel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 3;
  }
  /*internals faces*/
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
  adja[2] = rel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = kel*4 + 3;
  adja[3] = sel*4 + 1;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[1] = rel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = sel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[2] = pel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = mel*4 + 3; 
  adja[3] = qel*4 + 1;  
  adja[2] = oel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_33(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = nel*4 + 3;
  adja[3] = rel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = oel*4 + 2;
  adja[2] = sel*4 + 3;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[3] = lel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[2] = mel*4 + 3;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = lel*4 + 3;
  adja[3] = jel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = mel*4 + 2;  
  adja[2] = kel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_34(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  adja[2] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
    
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
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_35(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
  int    ia,ib,s[7];
	Hedge			hed;
  int    i,iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = lel*4 + 3;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = mel*4 + 2;
  adja[2] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = jel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = kel*4 + 3;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
 
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[3] = nel*4 + 2;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);
}
int MMG_swap710_36(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = nel*4 + 2;
  adja[3] = rel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[2] = sel*4 + 3;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = lel*4 + 1;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = mel*4 + 1;
 
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = lel*4 + 3;
  adja[3] = jel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = mel*4 + 2;  
  adja[2] = kel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);
}
int MMG_swap710_37(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[2] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
    
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
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);
}
int MMG_swap710_38(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[4];
  pt1->v[3] = s[1];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[rel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = rel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[sel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = sel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[jel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[kel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[1] = lel*4 + 2;
  adja[3] = rel*4 + 2;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[1] = mel*4 + 3;
  adja[2] = sel*4 + 3;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[2] = jel*4 + 1;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[3] = kel*4 + 1;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
 
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 1;
  adja[3] = nel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 1;
  adja[2] = oel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = jel*4 + 3;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = kel*4 + 2;  
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);  
}
int MMG_swap710_39(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;
  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 1;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[1] = rel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[1] = sel*4 + 3;
    
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
  adja[2] = rel*4 + 3;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = sel*4 + 2;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = lel*4 + 1;
  adja[3] = pel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = kel*4 + 3; 
  adja[3] = mel*4 + 1;  
  adja[2] = qel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);   
}
int MMG_swap710_40(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[4];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[4];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[2];
  pt1->v[3] = s[3]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[2];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[1];
  pt1->v[2] = s[4];
  pt1->v[3] = s[6];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[1];
  pt1->v[2] = s[6];
  pt1->v[3] = s[4];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[lel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[mel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 2; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[nel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[oel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 1;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 1;
  
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
  adja[1] = rel*4 + 2;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[1] = sel*4 + 3;
 
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[2] = rel*4 + 3;
  adja[3] = lel*4 + 2;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[3] = sel*4 + 2;
  adja[2] = mel*4 + 3;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = jel*4 + 2;
  adja[2] = nel*4 + 1;
  adja[3] = pel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = kel*4 + 3; 
  adja[3] = oel*4 + 1;  
  adja[2] = qel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
//MMG_chkmsh(mesh,1,0);
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);
  return(1); 
}
int MMG_swap710_41(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);

  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[3];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[3];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[pel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[qel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = sel*4 + 3;
    
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
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[1] = oel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = lel*4 + 3;
  adja[3] = jel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = mel*4 + 2;  
  adja[2] = kel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

  return(1);  
}
int MMG_swap710_42(pMesh mesh,pSol sol,pList list){  
  pTetra pt,pt1,pt0;
	Hedge			hed;
  int    i,ia,ib,s[7];
  int    iadr,iadr2,*adja,*adja2,k,k1,adj,iel,iar;
  int    jel,kel,lel,mel,nel,oel,pel,qel,rel,sel,ref;
  short  voy;

  if ( !MMG_zaldy4(&hed,25) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP663 IGNORED\n"); 
  }   

  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  pt  = &mesh->tetra[iel];
  ref = pt->ref; 
  MMG_findpolygone(mesh,list,s);
    
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[1];
  pt1->v[3] = s[2];
  pt1->qual = list->qual[1];
  pt1->ref  = ref;

  kel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[kel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[1];
  pt1->qual = list->qual[2];
  pt1->ref  = ref;

  lel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[lel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[6]; 
  pt1->qual = list->qual[3];
  pt1->ref  = ref;
  
  mel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[mel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[6];
  pt1->v[3] = s[5];    
  pt1->qual = list->qual[4];
  pt1->ref  = ref;
  
  nel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[nel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[3];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[5];
  pt1->ref  = ref;
  
  oel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[oel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[3];
  pt1->qual = list->qual[6];
  pt1->ref  = ref;
  
  pel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[pel];
  pt1->v[0] = ia;
  pt1->v[1] = s[2];
  pt1->v[2] = s[4];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[7];
  pt1->ref  = ref;
  
  qel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[qel];
  pt1->v[0] = ib;
  pt1->v[1] = s[2];
  pt1->v[2] = s[5];
  pt1->v[3] = s[4];
  pt1->qual = list->qual[8];
  pt1->ref  = ref;
  
  rel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[rel];
  pt1->v[0] = ia;
  pt1->v[1] = s[0];
  pt1->v[2] = s[2];
  pt1->v[3] = s[5];
  pt1->qual = list->qual[9];
  pt1->ref  = ref;

  sel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[sel];
  pt1->v[0] = ib;
  pt1->v[1] = s[0];
  pt1->v[2] = s[5];
  pt1->v[3] = s[2];	    
  pt1->qual = list->qual[10];
  pt1->ref  = ref;

  /*adj of iel*/
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[jel].bdryref[3] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;
  }
  k    = MMG_iare[iar][0];
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[kel].bdryref[2] = pt->bdryref[k]; 

  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 2;
  }
  /*adj list->tetra[2]*/
  iel = list->tetra[2] / 6;
  iar = list->tetra[2] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[jel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[kel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 1; 
  }
  /*adj list->tetra[3]*/
  iel = list->tetra[3] / 6;
  iar = list->tetra[3] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  pt1 = &mesh->tetra[adj];
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[nel].bdryref[3] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 3;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  pt1 = &mesh->tetra[adj];
   
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[oel].bdryref[2] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 2;
  }  
  /*adj list->tetra[4]*/
  iel = list->tetra[4] / 6;
  iar = list->tetra[4] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[nel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = nel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[oel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = oel*4 + 1;
  }
  /*adj list->tetra[5]*/
  iel = list->tetra[5] / 6;
  iar = list->tetra[5] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[pel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = pel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[qel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = qel*4 + 1; 
  }
  /*adj list->tetra[6]*/
  iel = list->tetra[6] / 6;
  pt = &mesh->tetra[iel];
  iar = list->tetra[6] % 6;
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;

  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[lel].bdryref[1] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 1;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[1] = adj*4 + voy;
  mesh->tetra[mel].bdryref[1] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 1;
  }
  /*adj list->tetra[7]*/
  iel = list->tetra[7] / 6;
  iar = list->tetra[7] % 6;
  pt = &mesh->tetra[iel];
  iadr2 = (iel-1)*4 + 1;
  adja2 = &mesh->adja[iadr2];
  k    = MMG_iare[iar][1];
  if(pt->v[k] == ib) 
    k1 = MMG_iare[iar][0];
  else {
    k  = MMG_iare[iar][0];
    k1 = MMG_iare[iar][1];
  }
  adj  = adja2[k] / 4;
  voy  = adja2[k] % 4;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[2] = adj*4 + voy;
  mesh->tetra[lel].bdryref[2] = pt->bdryref[k]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = lel*4 + 2;
  }
  adj  = adja2[k1] / 4;
  voy  = adja2[k1] % 4;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  mesh->tetra[mel].bdryref[3] = pt->bdryref[k1]; 
  if(adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = mel*4 + 3;
  }
  /*internals faces*/
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;
  adja[2] = rel*4 + 3;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  adja[3] = sel*4 + 2;
  
  iadr = (lel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = mel*4 + 0;
  adja[3] = rel*4 + 2;
  
  iadr = (mel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = lel*4 + 0;
  adja[2] = sel*4 + 3;
    
  iadr = (nel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = oel*4 + 0;
  adja[2] = pel*4 + 3;
  
  iadr = (oel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = nel*4 + 0;
  adja[3] = qel*4 + 2;
 
  iadr = (pel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = qel*4 + 0;
  adja[3] = nel*4 + 2;
  adja[2] = rel*4 + 1;

  iadr = (qel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = pel*4 + 0;
  adja[2] = oel*4 + 3;
  adja[3] = sel*4 + 1;

  iadr = (rel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = sel*4 + 0;
  adja[1] = pel*4 + 2;
  adja[2] = lel*4 + 3;
  adja[3] = jel*4 + 2;

  iadr = (sel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = rel*4 + 0;
  adja[1] = qel*4 + 3; 
  adja[3] = mel*4 + 2;  
  adja[2] = kel*4 + 3;
  
  /* remove 7 old tetra */
  for (k=1; k<=7; k++) { 
		pt0 = &mesh->tetra[list->tetra[k]/6];
		for(i=0 ; i<6 ; i++) {
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    MMG_delElt(mesh,list->tetra[k]/6); 
  }

  list->tetra[1]  = jel;
  list->tetra[2]  = kel;
  list->tetra[3]  = lel;
  list->tetra[4]  = mel;
  list->tetra[5]  = nel;
  list->tetra[6]  = oel;
  list->tetra[7]  = pel;
  list->tetra[8]  = qel;
  list->tetra[9]  = rel;
  list->tetra[10] = sel;
  list->tetra[11] = 0;
	MMG_updatebdryinfo(mesh,&hed,list);
	M_free(hed.item);

return(1);
}
