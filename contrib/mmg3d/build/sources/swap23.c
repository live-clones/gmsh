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

int MMG_swap23(pMesh mesh,pSol sol,pQueue q, int iel,int iar, double declic) {
  pTetra pt,pt_a,pt1,pt2,pt3;
  int jel,*adja,*adja_a,i_a,v,v_a,voy_a,a0,a1,a2;
  int iadr,kel,lel,*adja1,adj0,adj1,adj2;
  int s[3],n0,n1,n2,ref;

  pt   = &mesh->tetra[iel];
  ref  = pt->ref;
  iadr = 4*(iel-1) + 1;
  adja = &mesh->adja[iadr];
  v    = pt->v[iar];
  
  i_a = adja[iar] >> 2;
  assert(i_a);
  voy_a = adja[iar] % 4;
  pt_a = &mesh->tetra[i_a];
  v_a = pt_a->v[voy_a];
  iadr = 4*(i_a-1) + 1;
  adja_a = &mesh->adja[iadr];
  
  /*check iel and i_a in the same SD*/
	if(pt->ref != pt_a->ref) return(0);
	
  n0 = MMG_idir[iar][0];
  n1 = MMG_idir[iar][1];
  n2 = MMG_idir[iar][2];

  s[0] = pt->v[n0];
  s[1] = pt->v[n1];
  s[2] = pt->v[n2];
    
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[1] = v_a;
  pt1->v[0] = v;
  pt1->v[2] = s[0];
  pt1->v[3] = s[1];
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->flag = mesh->flag;
  pt1->ref  = ref;
  if ( pt1->qual >= declic )  MMG_kiuput(q,jel);
  
  kel = MMG_newElt(mesh);
  pt2 = &mesh->tetra[kel];
  pt2->v[1] = v_a;
  pt2->v[0] = v;
  pt2->v[2] = s[1];
  pt2->v[3] = s[2]; 
  pt2->qual = MMG_caltet(mesh,sol,kel);
  pt2->flag = mesh->flag;
  pt2->ref  = ref;
  if ( pt2->qual >= declic )  MMG_kiuput(q,kel);

  lel = MMG_newElt(mesh);
  pt3 = &mesh->tetra[lel];
  pt3->v[1] = v_a;
  pt3->v[0] = v;
  pt3->v[2] = s[2];
  pt3->v[3] = s[0];   
  pt3->qual = MMG_caltet(mesh,sol,lel);
  pt3->flag = mesh->flag;
  pt3->ref  = ref;
  if ( pt3->qual >= declic )  MMG_kiuput(q,lel);

//printf("qual %e %e %e\n",pt1->qual,pt2->qual,pt3->qual);
  /*neighboors*/
  a0 = n0;
  a1 = n1;
  a2 = n2;
  
  if(pt->v[MMG_idir[n0][0]] == v) {
    if(pt->v[MMG_idir[n0][1]] == s[0]
       || pt->v[MMG_idir[n0][2]] == s[0]) {
       if(pt->v[MMG_idir[n0][1]] == s[1]
       || pt->v[MMG_idir[n0][2]] == s[1])
         a0 = n0;
       else {
         assert(pt->v[MMG_idir[n0][1]] == s[2]
        	|| pt->v[MMG_idir[n0][2]] == s[2]);
         a2 = n0;
       }	   
     } else {
       a1 = n0;
     }   
  } else if(pt->v[MMG_idir[n0][1]] == v){
    if(pt->v[MMG_idir[n0][0]] == s[0]
       || pt->v[MMG_idir[n0][2]] == s[0]) {
       if(pt->v[MMG_idir[n0][0]] == s[1]
       || pt->v[MMG_idir[n0][2]] == s[1])
         a0 = n0;
       else {
         assert(pt->v[MMG_idir[MMG_idir[iar][0]][0]] == s[2]
        	|| pt->v[MMG_idir[MMG_idir[iar][0]][2]] == s[2]);
         a2 = n0;
       }	   
     } else {
       a1 = n0;
     }   
  } else {
    assert(pt->v[MMG_idir[n0][2]] == v);
    if(pt->v[MMG_idir[n0][1]] == s[0]
       || pt->v[MMG_idir[n0][0]] == s[0]) {
       if(pt->v[MMG_idir[n0][1]] == s[1]
       || pt->v[MMG_idir[n0][0]] == s[1])
         a0 = n0;
       else {
         assert(pt->v[MMG_idir[n0][1]] == s[2]
        	|| pt->v[MMG_idir[n0][0]] == s[2]);
         a2 = n0;
       }	   
     } else {
       a1 = n0;
     }     
  }

  if(pt->v[MMG_idir[MMG_idir[iar][1]][0]] == v) {
    if(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == s[0]
       || pt->v[MMG_idir[MMG_idir[iar][1]][2]] == s[0]) {
       if(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == s[1]
       || pt->v[MMG_idir[MMG_idir[iar][1]][2]] == s[1])
         a0 = MMG_idir[iar][1];
       else {
         assert(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == s[2]
        	|| pt->v[MMG_idir[MMG_idir[iar][1]][2]] == s[2]);
         a2 = MMG_idir[iar][1];
       }	   
     } else {
       a1 = MMG_idir[iar][1];
     }   
  } else if(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == v){
    if(pt->v[MMG_idir[MMG_idir[iar][1]][0]] == s[0]
       || pt->v[MMG_idir[MMG_idir[iar][1]][2]] == s[0]) {
       if(pt->v[MMG_idir[MMG_idir[iar][1]][0]] == s[1]
       || pt->v[MMG_idir[MMG_idir[iar][1]][2]] == s[1])
         a0 = MMG_idir[iar][1];
       else {
         assert(pt->v[MMG_idir[MMG_idir[iar][1]][0]] == s[2]
        	|| pt->v[MMG_idir[MMG_idir[iar][1]][2]] == s[2]);
         a2 = MMG_idir[iar][1];
       }	   
     } else {
       a1 = MMG_idir[iar][1];
     }   
  } else {
    assert(pt->v[MMG_idir[MMG_idir[iar][1]][2]] == v);
    if(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == s[0]
       || pt->v[MMG_idir[MMG_idir[iar][1]][0]] == s[0]) {
       if(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == s[1]
       || pt->v[MMG_idir[MMG_idir[iar][1]][0]] == s[1])
         a0 = MMG_idir[iar][1];
       else {
         assert(pt->v[MMG_idir[MMG_idir[iar][1]][1]] == s[2]
        	|| pt->v[MMG_idir[MMG_idir[iar][1]][0]] == s[2]);
         a2 = MMG_idir[iar][1];
       }	   
     } else {
       a1 = MMG_idir[iar][1];
     }     
  }

 if(pt->v[MMG_idir[n2][0]] == v) {
    if(pt->v[MMG_idir[n2][1]] == s[0]
       || pt->v[MMG_idir[n2][2]] == s[0]) {
       if(pt->v[MMG_idir[n2][1]] == s[1]
       || pt->v[MMG_idir[n2][2]] == s[1])
         a0 = n2;
       else {
         assert(pt->v[MMG_idir[n2][1]] == s[2]
        	|| pt->v[MMG_idir[n2][2]] == s[2]);
         a2 = n2;
       }	   
     } else {
       a1 = n2;
     }   
  } else if(pt->v[MMG_idir[n2][1]] == v){
    if(pt->v[MMG_idir[n2][0]] == s[0]
       || pt->v[MMG_idir[n2][2]] == s[0]) {
       if(pt->v[MMG_idir[n2][0]] == s[1]
       || pt->v[MMG_idir[n2][2]] == s[1])
         a0 = n2;
       else {
         assert(pt->v[MMG_idir[n2][0]] == s[2]
        	|| pt->v[MMG_idir[n2][2]] == s[2]);
         a2 = n2;
       }	   
     } else {
       a1 = n2;
     }   
  } else {
    assert(pt->v[MMG_idir[n2][2]] == v);
    if(pt->v[MMG_idir[MMG_idir[iar][2]][1]] == s[0]
       || pt->v[MMG_idir[MMG_idir[iar][2]][0]] == s[0]) {
       if(pt->v[MMG_idir[MMG_idir[iar][2]][1]] == s[1]
       || pt->v[MMG_idir[MMG_idir[iar][2]][0]] == s[1])
         a0 = MMG_idir[iar][2];
       else {
         assert(pt->v[MMG_idir[MMG_idir[iar][2]][1]] == s[2]
        	|| pt->v[MMG_idir[MMG_idir[iar][2]][0]] == s[2]);
         a2 = MMG_idir[iar][2];
       }	   
     } else {
       a1 = MMG_idir[iar][2];
     }     
  }

  adj0 = MMG_idir[voy_a][0];
  adj1 = MMG_idir[voy_a][1];
  adj2 = MMG_idir[voy_a][2];

  if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == v_a) {
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == s[1])
         adj0 = MMG_idir[voy_a][0];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == s[2]);
         adj2 = MMG_idir[voy_a][0];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][0];
     }   
  } else if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == v_a){
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == s[1])
         adj0 = MMG_idir[voy_a][0];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == s[2]);
         adj2 = MMG_idir[voy_a][0];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][0];
     }   
  } else {
    assert(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][2]] == v_a);
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == s[1])
         adj0 = MMG_idir[voy_a][0];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][0]][1]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][0]][0]] == s[2]);
         adj2 = MMG_idir[voy_a][0];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][0];
     }     
  }

  if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == v_a) {
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == s[1])
         adj0 = MMG_idir[voy_a][1];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == s[2]);
         adj2 = MMG_idir[voy_a][1];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][1];
     }   
  } else if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == v_a){
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == s[1])
         adj0 = MMG_idir[voy_a][1];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == s[2]);
         adj2 = MMG_idir[voy_a][1];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][1];
     }   
  } else {
    assert(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][2]] == v_a);
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == s[1])
         adj0 = MMG_idir[voy_a][1];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][1]][1]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][1]][0]] == s[2]);
         adj2 = MMG_idir[voy_a][1];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][1];
     }     
  }

 if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == v_a) {
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == s[1])
         adj0 = MMG_idir[voy_a][2];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == s[2]);
         adj2 = MMG_idir[voy_a][2];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][2];
     }   
  } else if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == v_a){
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == s[1])
         adj0 = MMG_idir[voy_a][2];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == s[2]);
         adj2 = MMG_idir[voy_a][2];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][2];
     }   
  } else {
    assert(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][2]] == v_a);
    if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == s[0]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == s[0]) {
       if(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == s[1]
       || pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == s[1])
         adj0 = MMG_idir[voy_a][2];
       else {
         assert(pt_a->v[MMG_idir[MMG_idir[voy_a][2]][1]] == s[2]
        	|| pt_a->v[MMG_idir[MMG_idir[voy_a][2]][0]] == s[2]);
         adj2 = MMG_idir[voy_a][2];
       }	   
     } else {
       adj1 = MMG_idir[voy_a][2];
     }     
  }
  
  iadr = 4*(jel-1) + 1;
  adja1 = &mesh->adja[iadr];
  adja1[1] = adja[a0];
  adja1[0] = adja_a[adj0];
  adja1[2] = 4*kel + 3;
  adja1[3] = 4*lel + 2;   
	pt1->bdryref[0] = pt_a->bdryref[adj0];
	pt1->bdryref[1] = pt->bdryref[a0];
	pt1->bdryref[2] = -1;
	pt1->bdryref[3] = -1;
	
  
  
  if ((adja[a0]>>2)) {
    iadr = 4*((adja[a0]>>2)-1) + 1;
    adja1 = &mesh->adja[iadr];
    adja1[adja[a0]%4] = 4*jel + 1;
  }
  
  if (adja_a[adj0]>>2) {
    iadr = 4*((adja_a[adj0]>>2)-1) + 1;
    adja1 = &mesh->adja[iadr];
    adja1[adja_a[adj0]%4] = 4*jel ;
  }
  
  iadr = 4*(kel-1) + 1;
  adja1 = &mesh->adja[iadr];
  adja1[1] = adja[a1];
  adja1[0] = adja_a[adj1];
  adja1[2] = 4*lel + 3;
  adja1[3] = 4*jel + 2;
	pt2->bdryref[0] = pt_a->bdryref[adj1];
	pt2->bdryref[1] = pt->bdryref[a1];
	pt2->bdryref[2] = -1;
	pt2->bdryref[3] = -1;
  
  if ((adja[a1]>>2)) {
    iadr = 4*((adja[a1]>>2)-1) + 1;
    adja1 = &mesh->adja[iadr];
    adja1[adja[a1]%4] = 4*kel + 1; 
  }
    
  if ((adja_a[adj1]>>2)) {
    iadr = 4*((adja_a[adj1]>>2)-1) + 1;
    adja1 = &mesh->adja[iadr];
    adja1[adja_a[adj1]%4] = 4*kel ; 
  }
    
  iadr = 4*(lel-1) + 1;
  adja1 = &mesh->adja[iadr];
  adja1[1] = adja[a2];
  adja1[0] = adja_a[adj2];
  adja1[2] = 4*jel + 3;
  adja1[3] = 4*kel + 2;
	pt3->bdryref[0] = pt_a->bdryref[adj2];
	pt3->bdryref[1] = pt->bdryref[a2];
	pt3->bdryref[2] = -1;
	pt3->bdryref[3] = -1;
  
  if ((adja[a2]>>2)) {
    iadr = 4*((adja[a2]>>2)-1) + 1;
    adja1 = &mesh->adja[iadr];
    adja1[adja[a2]%4] = 4*lel + 1; 
  }
   
  if ((adja_a[adj2]>>2)) {
    iadr = 4*((adja_a[adj2]>>2)-1) + 1;
    adja1 = &mesh->adja[iadr];
    adja1[adja_a[adj2]%4] = 4*lel; 
  }
    
  /*del*/
  MMG_delElt(mesh,iel);
  MMG_delElt(mesh,i_a);
  MMG_kiudel(q,iel);
  MMG_kiudel(q,i_a);


  return(1);
}


/* remove edge AB */
int MMG_swap32(pMesh mesh,pSol sol,pList list) {
  pTetra    pt,pt1,pt2,pt0;   
	Hedge			hed;
  int      *adja,k,i,jel,kel,adj,iadr,ia,ib,s1,s2,s3;
  int       old,iarold,kk,adj_a,adj_b,iel,iar,ref,ref_a,ref_b;   
  short     voy,voy_a,voy_b;
  
  if ( !MMG_zaldy4(&hed,10) ) {
    if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES UPDATE SWAP32 IGNORED\n"); 
  }   

  /* face s1 s2 s3 */
  iel  = list->tetra[1] / 6;
  iar  = list->tetra[1] % 6;
  pt   = &mesh->tetra[iel];
  ref  = pt->ref;
  
  ia  = pt->v[ MMG_iare[iar][0] ];
  ib  = pt->v[ MMG_iare[iar][1] ];
  s1  = pt->v[ MMG_isar[iar][0] ];
  s2  = pt->v[ MMG_isar[iar][1] ];
	for(i=0 ; i<6 ; i++) {
		//printf("1. insere %d %d -- %d\n",pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
		MMG_edgePut(&hed,pt->v[MMG_iare[i][0]],pt->v[MMG_iare[i][1]],pt->bdryinfo[i]);
	}
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_isar[iar][0];
  adj  = adja[k] >> 2;
  voy  = adja[k] % 4;
  pt1  = &mesh->tetra[adj];
  s3   = pt1->v[voy];

  /* create 2 new tetra */ 
  /*edge : ias1 -- ias2 -- ias3 -- s1s2 -- s1s3 -- s2s3*/
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
  /*edge : ibs2 -- ibs1 -- ibs3 -- s2s1 -- s2s3 -- s2s3*/
  kel = MMG_newElt(mesh);
  pt2 = &mesh->tetra[kel];
  pt2->v[0] = ib;
  pt2->v[1] = s2;
  pt2->v[2] = s1;
  pt2->v[3] = s3;
  pt2->qual = list->qual[2];
  pt2->flag = mesh->flag;
  pt2->ref  = ref;

  /* external faces */
  for (k=2; k<=3; k++) {
    old  = list->tetra[k] / 6;
    iadr = (old-1)*4 + 1;
    adja = &mesh->adja[iadr];

    pt0    = &mesh->tetra[old]; 
		for(i=0 ; i<6 ; i++) {    
			//printf("2. insere %d %d -- %d\n",pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
			MMG_edgePut(&hed,pt0->v[MMG_iare[i][0]],pt0->v[MMG_iare[i][1]],pt0->bdryinfo[i]);
		}
    iarold = list->tetra[k] % 6;
    kk     = MMG_iare[iarold][1];
    if( pt0->v[kk] == ib ) {
      adj_a  = adja[kk] >> 2;
      voy_a = adja[kk] % 4;
      ref_a = pt0->bdryref[kk];
      kk    = MMG_iare[iarold][0];
      adj_b  = adja[kk] >> 2;
      voy_b  = adja[kk] % 4;
      ref_b = pt0->bdryref[kk]; 
    } 
    else /*if ( pt0->v[MMG_iare[iarold][0]] == ib ) */{
      adj_b  = adja[kk] >> 2;
      voy_b  = adja[kk] % 4;   
      ref_b  = pt0->bdryref[kk];  
      kk    = MMG_iare[iarold][0];
      adj_a  = adja[kk] >> 2;
      voy_a  = adja[kk] % 4;  
      ref_a  = pt0->bdryref[kk];  
    }

    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    if ( old == (adja[MMG_isar[iar][0]]>>2) ) {  
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_a*4 + voy_a;
      pt1->bdryref[1] = ref_a;   
			
      if (adj_a) {        
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 1;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_b*4 + voy_b;
      pt2->bdryref[2] = ref_b;
      if (adj_b) {        
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 2; 
      }
    } 
    else if ( old == (adja[MMG_isar[iar][1]]>>2) ) {
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[2] = adj_a*4 + voy_a;
      pt1->bdryref[2] = ref_a;  
        
      if (adj_a) {
        iadr = (adj_a-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_a] = jel*4 + 2;
      }
      
      iadr = (kel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[1] = adj_b*4 + voy_b;
      pt2->bdryref[1] = ref_b; 
      
      if (adj_b) {        
        iadr = (adj_b-1)*4 + 1;
        adja = &mesh->adja[iadr];
        adja[voy_b] = kel*4 + 1;
      }
    }
 
  }

  /* du tetra 1 de la liste pour ia */
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][1];
  adj  = adja[k] >> 2;
  voy  = adja[k] % 4;
   
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  pt1->bdryref[3] = pt->bdryref[k];
    
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = jel*4 + 3;  
  }

  /* du tetra 1 de la liste pour ib */
  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  k    = MMG_iare[iar][0];
  adj  = adja[k] >> 2;
  voy  = adja[k] % 4;
  
  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[3] = adj*4 + voy;
  pt2->bdryref[3] = pt->bdryref[k];
  
  if (adj) {
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adja[voy] = kel*4 + 3; 
  }

  /* internal face */
  iadr = (jel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = kel*4 + 0;

  iadr = (kel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adja[0] = jel*4 + 0;
  
	for(i=0 ; i<6 ; i++) {
		pt1->bdryinfo[i] = MMG_edgePut(&hed,pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]],1); 
		//printf("pas trouve %d %d\n",pt1->v[MMG_iare[i][0]],pt1->v[MMG_iare[i][1]]);
		assert(pt1->bdryinfo[i]!=1);
		pt2->bdryinfo[i] = MMG_edgePut(&hed,pt2->v[MMG_iare[i][0]],pt2->v[MMG_iare[i][1]],1);
		assert(pt2->bdryinfo[i]!=1);
	}

  /* remove 3 old tetra */
  for (k=1; k<=3; k++)
    MMG_delElt(mesh,list->tetra[k]/6);

  list->tetra[1] = jel;
  list->tetra[2] = kel;
  list->tetra[3] = 0;
  
	M_free(hed.item);
  return(2);
}

