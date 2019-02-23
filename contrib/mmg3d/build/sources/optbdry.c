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
#define OCRIT    0.99

int MMG_movevertexbdry(pMesh mesh,pSol sol,int k,int ib);
int MMG_colpoi2(pMesh mesh,pSol sol,int iel,int ia,int ib,double coef);

int MMG_optbdry(pMesh mesh,pSol sol,int k) {
  pTetra pt;
  int    ia,ib,i,*adja,iadr,ipb;

  
  
  pt = &mesh->tetra[k];
  iadr = 4*(k-1) + 1;
  adja = &mesh->adja[iadr];
      
  /*essai de collapse du point qui n'est pas sur la peau*/
  for(i=0 ; i<4 ; i++) if(!adja[i]) break;
  
  ib  = i;
  ipb = pt->v[ib];
  if(!mesh->info.noinsert) {
    for(i=1 ; i<4 ; i++) {
      ia = (ib+i)%4;
      if(MMG_colpoi2(mesh,sol,k,ia,ib,QDEGRAD)) {
        MMG_delPt(mesh,ipb);
        break;
      }
    }
  } else {
    i=4;
  }
  
  /*try to move the 4th vertex*/
  if(i==4) {
//if(k==402140) printf("colpoi refused, try move %d %d %d\n",k,ib,pt->v[ib]);
    if(!MMG_movevertexbdry(mesh,sol,k,ib)) return(0);
    return(2);
  }
   
  return(1);
    
}
int MMG_opt2peau(pMesh mesh,pSol sol,pQueue queue,int k,double declic) {
  pTetra    pt,pt1;
  pPoint    pa,pb,pc,pd;
  List      list;
  double    abx,aby,abz,acx,acy,acz,adx,ady,adz,v1,v2,v3,vol;
  double    bcx,bcy,bcz,bdx,bdy,bdz,cdx,cdy,cdz,h[6];
  double     crit;
  double    s[4],dd,rapmin,rapmax;
  int       i,ia,ib,ic,id,iarmax,iarmin;
  int       lon,l,iel,ier;

  ier = 0;
  
  pt = &mesh->tetra[k];
  if ( !pt->v[0] )  return(-1);

  ia = pt->v[0];
  ib = pt->v[1];
  ic = pt->v[2];
  id = pt->v[3];
  pa = &mesh->point[ia];
  pb = &mesh->point[ib];
  pc = &mesh->point[ic];
  pd = &mesh->point[id];

  /* volume */
  abx = pb->c[0] - pa->c[0]; 
  aby = pb->c[1] - pa->c[1]; 
  abz = pb->c[2] - pa->c[2]; 

  acx = pc->c[0] - pa->c[0]; 
  acy = pc->c[1] - pa->c[1]; 
  acz = pc->c[2] - pa->c[2]; 

  adx = pd->c[0] - pa->c[0]; 
  ady = pd->c[1] - pa->c[1]; 
  adz = pd->c[2] - pa->c[2]; 

  v1  = acy*adz - acz*ady;
  v2  = acz*adx - acx*adz;
  v3  = acx*ady - acy*adx;
  vol = abx * v1 + aby * v2 + abz * v3;

  /* max edge */
  h[0] = abx*abx + aby*aby + abz*abz;
  h[1] = acx*acx + acy*acy + acz*acz;
  h[2] = adx*adx + ady*ady + adz*adz;

  bcx = pc->c[0] - pb->c[0];
  bcy = pc->c[1] - pb->c[1];
  bcz = pc->c[2] - pb->c[2];

  bdx = pd->c[0] - pb->c[0];
  bdy = pd->c[1] - pb->c[1];
  bdz = pd->c[2] - pb->c[2];

  cdx = pd->c[0] - pc->c[0];
  cdy = pd->c[1] - pc->c[1];
  cdz = pd->c[2] - pc->c[2];

  h[3] = bcx*bcx + bcy*bcy + bcz*bcz;
  h[4] = bdx*bdx + bdy*bdy + bdz*bdz;
  h[5] = cdx*cdx + cdy*cdy + cdz*cdz;

  /* face areas */
  dd = cdy*bdz - cdz*bdy; 
  s[0] = dd * dd;
  dd = cdz*bdx - cdx*bdz;
  s[0] = s[0] + dd * dd;
  dd = cdx*bdy - cdy*bdx;
  s[0] = s[0] + dd * dd;
  s[0] = sqrt(s[0]);

  s[1] = sqrt(v1*v1 + v2*v2 + v3*v3);

  dd = bdy*adz - bdz*ady;
  s[2] = dd * dd;
  dd = bdz*adx - bdx*adz;
  s[2] = s[2] + dd * dd;
  dd = bdx*ady - bdy*adx;
  s[2] = s[2] + dd * dd;
  s[2] = sqrt(s[2]);

  dd = aby*acz - abz*acy;
  s[3] = dd * dd;
  dd = abz*acx - abx*acz;
  s[3] = s[3] + dd * dd;
  dd = abx*acy - aby*acx;
  s[3] = s[3] + dd * dd;
  s[3] = sqrt(s[3]);

  /* classification */
  rapmin = h[0];
  rapmax = h[0];
  iarmin = 0;
  iarmax = 0;
  for (i=1; i<6; i++) {
    if ( h[i] < rapmin ) {
      rapmin = h[i];
      iarmin = i;
    }
    else if ( h[i] > rapmax ) {
      rapmax = h[i];
      iarmax = i;
    }
  }
  rapmin = sqrt(rapmin);
  rapmax = sqrt(rapmax);
  
  if(mesh->info.imprim < -9) printf("edge : %d %d\n",pt->v[MMG_iare[iarmax][0]],pt->v[MMG_iare[iarmax][1]]);
  /*split edge*/
  lon = MMG_coquil(mesh,k,iarmax,&list);
  if(mesh->info.imprim < 0) {
    //printf("lon %d\n",lon);
    //if(!lon) printf("colle peau, edge peau\n");
  }
  
  if(!lon) {  
   for(i=0 ; i<6 ; i++) {
     lon = MMG_coquil(mesh,k,i,&list);
     if ( lon > 2 ) {
       if ( !MMG_zaldy4(&list.hedg,3*LONMAX) ) {
         fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM MMG_optbdry.\n");
         MMG_kiufree(queue);
         return(0);
       }
       crit = pt->qual;
       for (l=2; l<=lon; l++) {
         iel = list.tetra[l] / 6;
         pt1 = &mesh->tetra[iel];
         if ( pt1->qual > crit )  crit = pt1->qual;
       }
       crit *= OCRIT;
       //crit = min(1000/ALPHAD,crit*1.3);
       ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,1e9);
       if(ier) {/*printf("on a reussi a l'enlever par MMG_swap\n");*/break;}
       if ( ier == 0 && !mesh->info.noinsert) { 
         crit = M_MIN(100./ALPHAD,crit*1.5);
         ier = MMG_spledg(mesh,sol,queue,&list,lon,/*1.8**/crit,declic);
       }
       if(ier) {/*printf("on a reussi a l'enlever par split \n");*/break;}
      
       M_free(list.hedg.item);
      }
    }
    
    //M_free(list.hedg.item);

    if(ier) {
      M_free(list.hedg.item);
      return(1);
    }
    else return(0);
  } else {
 
    if ( !MMG_zaldy4(&list.hedg,3*LONMAX) ) {
      fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM MMG_optbdry.\n");
      MMG_kiufree(queue);
      return(0);
    }
    if ( lon > 2 ) {
      crit = pt->qual;
      for (l=2; l<=lon; l++) {
        iel = list.tetra[l] / 6;
        pt1 = &mesh->tetra[iel];
        if ( pt1->qual > crit )  crit = pt1->qual;
      }
      crit *= OCRIT;
      // crit = min(1000/ALPHAD,crit*1.3);
      ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,1e9);
      if ( ier == 0 && !mesh->info.noinsert) {
        crit = M_MIN(100./ALPHAD,crit*1.5);
        ier = MMG_spledg(mesh,sol,queue,&list,lon,/*1.8**/crit,declic);
      }
    }
   
  
    M_free(list.hedg.item);
    if(ier) return(1);
    else return(0);
 }
  return(1);
    
}
