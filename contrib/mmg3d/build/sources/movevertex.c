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

int MMG_movevertex_ani(pMesh mesh,pSol sol,int k,int ib) {
  pTetra 	pt,pt1;
  pPoint 	ppa,ppb,p1,p2,p3;
  List  	list;
  int    	j,iadr,ipb,iter,maxiter,l,lon,iel,i1,i2,i3;
  double  	*mp,coe;
  double 	ax,ay,az,bx,by,bz,nx,ny,nz,dd,len,qual,oldc[3];    
  assert(k);
  assert(ib<4);
  pt = &mesh->tetra[k];
  ppa  = &mesh->point[pt->v[ib]];
  iadr = (pt->v[ib]-1)*sol->offset + 1;
  mp   = &sol->met[iadr];
  
  /*compute normal*/
  i1 = pt->v[MMG_idir[ib][0]];
  i2 = pt->v[MMG_idir[ib][1]];
  i3 = pt->v[MMG_idir[ib][2]];
  p1 = &mesh->point[i1];
  p2 = &mesh->point[i2];
  p3 = &mesh->point[i3];
  
  ax = p3->c[0] - p1->c[0];
  ay = p3->c[1] - p1->c[1];
  az = p3->c[2] - p1->c[2];

  bx = p2->c[0] - p1->c[0];
  by = p2->c[1] - p1->c[1];
  bz = p2->c[2] - p1->c[2];

  nx = (ay*bz - az*by);
  ny = (az*bx - ax*bz);
  nz = (ax*by - ay*bx);
    
  dd = sqrt(nx*nx+ny*ny+nz*nz);  
  dd = 1./dd;
  nx *=dd;
  ny *=dd;
  nz *=dd;
  len = 0;
  for (j=0; j<3; j++) {
    ipb = pt->v[ MMG_idir[ib][j] ];
    ppb = &mesh->point[ipb];

    ax  = ppb->c[0] - ppa->c[0];
    ay  = ppb->c[1] - ppa->c[1];
    az  = ppb->c[2] - ppa->c[2];

    dd =       mp[0]*ax*ax + mp[3]*ay*ay + mp[5]*az*az \
  	+ 2.0*(mp[1]*ax*ay + mp[2]*ax*az + mp[4]*ay*az);
    assert(dd>0);
    len += sqrt(dd);
  }	
    
  dd  = 1.0 / (double)3.;
  len = 1.0 / len;
  len *= dd;
  memcpy(oldc,ppa->c,3*sizeof(double));
  	    
  lon = MMG_boulep(mesh,k,ib,&list);
  if(mesh->info.imprim < 0 ) if(lon < 4 && lon) printf("lon petit : %d\n",lon);
  if(!lon) return(0);
  
  coe	  = 1.;
  iter    = 0;
  maxiter = 20;
  do {
    ppa->c[0] = oldc[0] + coe * nx * len;
    ppa->c[1] = oldc[1] + coe * ny * len;
    ppa->c[2] = oldc[2] + coe * nz * len;

    for (l=1; l<=lon; l++) {
      iel = list.tetra[l] >> 2;
      pt1 = &mesh->tetra[iel];

      qual = MMG_caltet(mesh,sol,iel);
       if ( !((qual < pt1->qual) || (qual < pt->qual /2.)) )  break;
       list.qual[l] = qual;

     }
     if ( l > lon )  break;
     coe *= 0.5;
   }
   while ( ++iter <= maxiter );
   if ( iter > maxiter) {
     memcpy(ppa->c,oldc,3*sizeof(double));
     return(0);
   }
   
   for (l=1; l<=lon; l++) {
      iel = list.tetra[l] >> 2;
      pt1 = &mesh->tetra[iel];
      pt1->qual = list.qual[l];
//    if ( pt1->qual < declic )
//	MMG_kiudel(queue,iel);
   }
   return(1);
 
}


int MMG_movevertex_iso(pMesh mesh,pSol sol,int k,int ib) {
  pTetra pt,pt1;
  pPoint ppa,ppb,p1,p2,p3;
  List  list;
  int    j,iadr,ipb,iter,maxiter,l,lon,iel,i1,i2,i3;
  double  hp,coe,crit;
  double ax,ay,az,bx,by,bz,nx,ny,nz,dd,len,qual,oldc[3];
  
  assert(k);
  assert(ib<4);
  pt = &mesh->tetra[k];
   
  ppa  = &mesh->point[pt->v[ib]];
  iadr = (pt->v[ib]-1)*sol->offset + 1;
  hp   = sol->met[iadr];
  
  /*compute normal*/
  i1 = pt->v[MMG_idir[ib][0]];
  i2 = pt->v[MMG_idir[ib][1]];
  i3 = pt->v[MMG_idir[ib][2]];
  p1 = &mesh->point[i1];
  p2 = &mesh->point[i2];
  p3 = &mesh->point[i3];
  
  ax = p3->c[0] - p1->c[0];
  ay = p3->c[1] - p1->c[1];
  az = p3->c[2] - p1->c[2];

  bx = p2->c[0] - p1->c[0];
  by = p2->c[1] - p1->c[1];
  bz = p2->c[2] - p1->c[2];

  nx = (ay*bz - az*by);
  ny = (az*bx - ax*bz);
  nz = (ax*by - ay*bx);
    
  dd = sqrt(nx*nx+ny*ny+nz*nz); 
  dd = 1./dd;
  nx *=dd;
  ny *=dd;
  nz *=dd;
  len = 0;
  for (j=0; j<3; j++) {
    ipb = pt->v[ MMG_idir[ib][j] ];
    ppb = &mesh->point[ipb];

    ax  = ppb->c[0] - ppa->c[0];
    ay  = ppb->c[1] - ppa->c[1];
    az  = ppb->c[2] - ppa->c[2];

    dd    =   sqrt(ax*ax +ay*ay +az*az);
    len  +=   dd/hp;
  }	
   
  dd  = 1.0 / (double)3.;
  len *= dd; 
  if(len > 0.) len = 1.0 / len;
  else printf("MMG_movevertex len %e\n",len);

  memcpy(oldc,ppa->c,3*sizeof(double));
  	    
  lon = MMG_boulep(mesh,k,ib,&list);
  if(mesh->info.imprim < 0) if(lon < 4 && lon) printf("lon petit : %d\n",lon);
  if(!lon) return(0);

  /*qual crit*/
  crit = pt->qual;
  for (l=2; l<=lon; l++) {
    iel = list.tetra[l] >> 2;
    pt1 = &mesh->tetra[iel];
    if ( pt1->qual > crit )  crit = pt1->qual;
  }
 /* if ( (crit > 100/ALPHAD) ) {
    crit *= 1.1;
  } else 
   */ crit *= 0.99;
  
  coe	  = 1.;
  iter    = 0;
  maxiter = 20;
  do {

    ppa->c[0] = oldc[0] + coe * nx * len;
    ppa->c[1] = oldc[1] + coe * ny * len;
    ppa->c[2] = oldc[2] + coe * nz * len;
    for (l=1; l<=lon; l++) {
      iel = list.tetra[l] >> 2;
      pt1 = &mesh->tetra[iel];
      qual = MMG_caltet(mesh,sol,iel);
      if ( qual > crit )  break;
       list.qual[l] = qual;

     }
     if ( l > lon )  break;
     coe *= 0.5;
   }
   while ( ++iter <= maxiter );
   if ( iter > maxiter) {
     memcpy(ppa->c,oldc,3*sizeof(double));
     return(-2);
   }
   
   for (l=1; l<=lon; l++) {
      iel = list.tetra[l] >> 2;
      pt1 = &mesh->tetra[iel];
      pt1->qual = list.qual[l];
//    if ( pt1->qual < declic )
//	MMG_kiudel(queue,iel);
   }
   return(1);
 
}


int MMG_movevertexbdry(pMesh mesh,pSol sol,int k,int ib) {
  pTetra 	pt,pt1;
  pPoint 	ppa,ppb,p1,p2,p3;
  List  	list;
  int    	j,ipb,iter,maxiter,l,lon,iel,i1,i2,i3;
  double    coe,crit;
  double 	ax,ay,az,bx,by,bz,nx,ny,nz,dd,len,qual,oldc[3];
  
  assert(k);
  assert(ib<4);
  pt = &mesh->tetra[k];
    
  ppa  = &mesh->point[pt->v[ib]];
  
  /*compute normal*/
  i1 = pt->v[MMG_idir[ib][0]];
  i2 = pt->v[MMG_idir[ib][1]];
  i3 = pt->v[MMG_idir[ib][2]];
  p1 = &mesh->point[i1];
  p2 = &mesh->point[i2];
  p3 = &mesh->point[i3];
  
  ax = p3->c[0] - p1->c[0];
  ay = p3->c[1] - p1->c[1];
  az = p3->c[2] - p1->c[2];

  bx = p2->c[0] - p1->c[0];
  by = p2->c[1] - p1->c[1];
  bz = p2->c[2] - p1->c[2];

  nx = (ay*bz - az*by);
  ny = (az*bx - ax*bz);
  nz = (ax*by - ay*bx);
    
  dd = sqrt(nx*nx+ny*ny+nz*nz);  
  dd = 1./dd;
  nx *=dd;
  ny *=dd;
  nz *=dd;
  len = 0;
  for (j=0; j<3; j++) {
    ipb = pt->v[ MMG_idir[ib][j] ];
    ppb = &mesh->point[ipb];

    ax  = ppb->c[0] - ppa->c[0];
    ay  = ppb->c[1] - ppa->c[1];
    az  = ppb->c[2] - ppa->c[2];

    dd   = ax*ax + ay*ay + az*az;
    len += sqrt(dd);
  }	
    
  dd  = 1.0 / (double)3.;
  len = 1.0 / len;
  len *= dd;
  memcpy(oldc,ppa->c,3*sizeof(double));
  	    
  lon = MMG_boulep(mesh,k,ib,&list);
  if(mesh->info.imprim < 0 ) if(lon < 4 && lon) printf("lon petit : %d\n",lon);
  if(!lon) return(0);
  crit = pt->qual;
  for (l=2; l<=lon; l++) {
    iel = list.tetra[l] >> 2;
    pt1 = &mesh->tetra[iel];
    if ( pt1->qual > crit )  crit = pt1->qual;
  }
  coe	  = 0.5;
  iter    = 0;
  maxiter = 50;
  do {
    ppa->c[0] = oldc[0] + coe * nx * len;
    ppa->c[1] = oldc[1] + coe * ny * len;
    ppa->c[2] = oldc[2] + coe * nz * len;

    for (l=1; l<=lon; l++) {
      iel = list.tetra[l] >> 2;
      pt1 = &mesh->tetra[iel];

      qual = MMG_caltet(mesh,sol,iel);
      if ( !((qual < crit)) )  break;
      list.qual[l] = qual;

    }
    if ( l > lon )  break;
    coe *= 0.5;
  }
  while ( ++iter <= maxiter );
  if ( iter > maxiter) {
    memcpy(ppa->c,oldc,3*sizeof(double));
    return(0);
  }
   
   for (l=1; l<=lon; l++) {
      iel = list.tetra[l] >> 2;
      pt1 = &mesh->tetra[iel];
      pt1->qual = list.qual[l];
//    if ( pt1->qual < declic )
//	MMG_kiudel(queue,iel);
   }
   return(1);
 
}


