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

/* create bucket structure and store initial vertices */
pBucket MMG_newBucket(pMesh mesh,int nmax) {
  pPoint	ppt;
  pBucket	bucket;
  double	dd;
  int		k,ic,ii,jj,kk;

  /* memory alloc */
  bucket = (Bucket*)M_malloc(sizeof(Bucket),"newBucket");
  assert(bucket);
  bucket->size = nmax;
  bucket->head = (int*)M_calloc(nmax*nmax*nmax+1,sizeof(int),"newBucket.head");
  assert(bucket->head);
  bucket->link = (int*)M_calloc(mesh->npmax+1,sizeof(int),"newBucket.link");
  assert(bucket->link);

  /* insert vertices */
  dd = nmax / (double)PRECI;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
    ii = M_MAX(0,(int)(dd * ppt->c[0])-1);
    jj = M_MAX(0,(int)(dd * ppt->c[1])-1);
    kk = M_MAX(0,(int)(dd * ppt->c[2])-1);
    ic = (kk*nmax + jj)*nmax + ii;

    if ( !bucket->head[ic] )
      bucket->head[ic] = k;
    else {
      bucket->link[k]  = bucket->head[ic];
      bucket->head[ic] = k;
    }
  }

  return(bucket);
}


void MMG_freeBucket(pBucket bucket) {
  M_free(bucket->head);
  M_free(bucket->link);
  M_free(bucket);
}


/* check and eventually insert vertex */
int MMG_buckin_ani(pMesh mesh,pSol sol,pBucket bucket,int ip) {
  pPoint	ppt,pp1;
  double	dd,d2,det,ux,uy,uz,dmi,m1,m2,m3,dx,dy,dz;
  double	*ma,*mb;
  int		i,j,k,ii,jj,kk,ic,icc,siz,ip1;
  int 		iadr,imin,imax,jmin,jmax,kmin,kmax;

  ppt = &mesh->point[ip];
  siz = bucket->size;
  dd  = siz / (double)PRECI;

  iadr = (ip-1)*sol->offset + 1;
  ma   = &sol->met[iadr];
  dmi  = LFILT*LFILT;

  ii = M_MAX(0,(int)(dd * ppt->c[0])-1);
  jj = M_MAX(0,(int)(dd * ppt->c[1])-1);
  kk = M_MAX(0,(int)(dd * ppt->c[2])-1);
  ic = (kk*siz + jj)*siz + ii;

  /* check current cell */
  if ( bucket->head[ic] ) {
    ip1 = bucket->head[ic];
    pp1 = &mesh->point[ip1];
    ux = pp1->c[0] - ppt->c[0];
    uy = pp1->c[1] - ppt->c[1];
    uz = pp1->c[2] - ppt->c[2];
    d2 =      ma[0]*ux*ux + ma[3]*uy*uy + ma[5]*uz*uz \
       + 2.0*(ma[1]*ux*uy + ma[2]*ux*uz + ma[4]*uy*uz);
    if ( d2 < dmi ) {
      iadr = (ip1-1)*sol->offset + 1;
      mb = &sol->met[iadr];
      d2 =      mb[0]*ux*ux + mb[3]*uy*uy + mb[5]*uz*uz \
         + 2.0*(mb[1]*ux*uy + mb[2]*ux*uz + mb[4]*uy*uz);
      if ( d2 < dmi )  return(0);
    }

    while ( bucket->link[ip1] ) {
      ip1 = bucket->link[ip1];
      pp1 = &mesh->point[ip1];
      ux = pp1->c[0] - ppt->c[0];
      uy = pp1->c[1] - ppt->c[1];
      uz = pp1->c[2] - ppt->c[2];
      d2 =      ma[0]*ux*ux + ma[3]*uy*uy + ma[5]*uz*uz \
         + 2.0*(ma[1]*ux*uy + ma[2]*ux*uz + ma[4]*uy*uz);
      if ( d2 < dmi ) {
        iadr = (ip1-1)*sol->offset + 1;
        mb = &sol->met[iadr];
        d2 =      mb[0]*ux*ux + mb[3]*uy*uy + mb[5]*uz*uz \
           + 2.0*(mb[1]*ux*uy + mb[2]*ux*uz + mb[4]*uy*uz);
        if ( d2 < dmi )  return(0);
      }
    }
  }

  /* bounding box */
  det = ma[0] * (ma[3]*ma[5] - ma[4]*ma[4]) \
      - ma[1] * (ma[1]*ma[5] - ma[2]*ma[4]) \
      + ma[2] * (ma[1]*ma[4] - ma[3]*ma[2]);
  det = 1.0 / det;
  m1 = ma[3]*ma[5] - ma[4]*ma[4];
  m2 = ma[0]*ma[5] - ma[2]*ma[2];
  m3 = ma[0]*ma[3] - ma[1]*ma[1];
  if ( det < 0.0 || m1 < 0.0 )
    return(1);
  else {
    dx = LFILT * sqrt(m1 * det) ;
    dy = LFILT * sqrt(m2 * det) ;
    dz = LFILT * sqrt(m3 * det) ;
  }

  imin = (int)(dd * (ppt->c[0]-dx))-1;
  jmin = (int)(dd * (ppt->c[1]-dy))-1;
  kmin = (int)(dd * (ppt->c[2]-dz))-1;
  imax = (int)(dd * (ppt->c[0]+dx))-1;
  jmax = (int)(dd * (ppt->c[1]+dy))-1;
  kmax = (int)(dd * (ppt->c[2]+dz))-1;

  imin = M_MAX(0,M_MIN(imin,siz-1));
  imax = M_MIN(siz-1,M_MAX(0,imax));
  jmin = M_MAX(0,M_MIN(jmin,siz-1));
  jmax = M_MIN(siz-1,M_MAX(0,jmax));
  kmin = M_MAX(0,M_MIN(kmin,siz-1));
  kmax = M_MIN(siz-1,M_MAX(0,kmax));
  if ( imin == imax && jmin == jmax && kmin == kmax )  return(1);

  /* explore neighbours */
  for (k=kmin; k<=kmax; k++)
    for (j=jmin; j<=jmax; j++) 
      for (i=imin; i<=imax; i++) {
        icc = (k*siz + j)*siz + i;
        ip1 = bucket->head[icc];
        if ( !ip1 )  continue;
        pp1 = &mesh->point[ip1];
        ux = pp1->c[0] - ppt->c[0];
        uy = pp1->c[1] - ppt->c[1];
        uz = pp1->c[2] - ppt->c[2];
        d2 =      ma[0]*ux*ux + ma[3]*uy*uy + ma[5]*uz*uz \
           + 2.0*(ma[1]*ux*uy + ma[2]*ux*uz + ma[4]*uy*uz);
        if ( d2 < dmi ) {
          iadr = (ip1-1)*sol->offset + 1;
          mb = &sol->met[iadr];
          d2 =      mb[0]*ux*ux + mb[3]*uy*uy + mb[5]*uz*uz \
             + 2.0*(mb[1]*ux*uy + mb[2]*ux*uz + mb[4]*uy*uz);
          if ( d2 < dmi )  return(0);
        }

        while ( bucket->link[ip1] ) {
          ip1 = bucket->link[ip1];
          pp1 = &mesh->point[ip1];
          ux = pp1->c[0] - ppt->c[0];
          uy = pp1->c[1] - ppt->c[1];
          uz = pp1->c[2] - ppt->c[2];
          d2 =      ma[0]*ux*ux + ma[3]*uy*uy + ma[5]*uz*uz \
             + 2.0*(ma[1]*ux*uy + ma[2]*ux*uz + ma[4]*uy*uz);
          if ( d2 < dmi ) {
            iadr = (ip1-1)*sol->offset + 1;
            mb = &sol->met[iadr];
            d2 =      mb[0]*ux*ux + mb[3]*uy*uy + mb[5]*uz*uz \
               + 2.0*(mb[1]*ux*uy + mb[2]*ux*uz + mb[4]*uy*uz);
            if ( d2 < dmi )  return(0);
          }
        }
      }

  return(1);
}


int MMG_buckin_iso(pMesh mesh,pSol sol,pBucket bucket,int ip) {
  pPoint	ppt,pp1;
  double	dd,d2,ux,uy,uz,hpi,hp1,hp2;
  int		i,j,k,ii,jj,kk,ic,icc,siz,ip1;
  int 		imin,imax,jmin,jmax,kmin,kmax;

  ppt = &mesh->point[ip];
  siz = bucket->size;
  dd  = siz / (double)PRECI;
  hpi = LFILT * sol->met[ip];
  hp1 = hpi*hpi;

  ii = M_MAX(0,(int)(dd * ppt->c[0])-1);
  jj = M_MAX(0,(int)(dd * ppt->c[1])-1);
  kk = M_MAX(0,(int)(dd * ppt->c[2])-1);
  ic = (kk*siz + jj)*siz + ii;

  /* check current cell */
  if ( bucket->head[ic] ) {
    ip1 = bucket->head[ic];
    pp1 = &mesh->point[ip1];
    hp2 = LFILT * sol->met[ip1];
    ux = pp1->c[0] - ppt->c[0];
    uy = pp1->c[1] - ppt->c[1];
    uz = pp1->c[2] - ppt->c[2];
    d2 = ux*ux + uy*uy + uz*uz;
    if ( d2 < hp1 || d2 < hp2*hp2 )  {
//printf("filtre current %d : %e %e %e %e\n",ip1,d2,hp1,d2,hp2*hp2);
      return(0);
    }

    while ( bucket->link[ip1] ) {
      ip1 = bucket->link[ip1];
      pp1 = &mesh->point[ip1];
      hp2 = LFILT * sol->met[ip1];
      ux = pp1->c[0] - ppt->c[0];
      uy = pp1->c[1] - ppt->c[1];
      uz = pp1->c[2] - ppt->c[2];
      d2 = ux*ux + uy*uy + uz*uz;
      if ( d2 < hp1 || d2 < hp2*hp2 )  {
//printf("filtre link %d : %e %e %e %e\n",ip1,d2,hp1,d2,hp2*hp2);
        return(0);
      }
    }
  }

  /* explore neighbors */
  imin = (int)(dd * (ppt->c[0]-hpi))-1;
  jmin = (int)(dd * (ppt->c[1]-hpi))-1;
  kmin = (int)(dd * (ppt->c[2]-hpi))-1;
  imax = (int)(dd * (ppt->c[0]+hpi))-1;
  jmax = (int)(dd * (ppt->c[1]+hpi))-1;
  kmax = (int)(dd * (ppt->c[2]+hpi))-1;

  imin = M_MAX(0,M_MIN(imin,siz-1));
  imax = M_MIN(siz-1,M_MAX(0,imax));
  jmin = M_MAX(0,M_MIN(jmin,siz-1));
  jmax = M_MIN(siz-1,M_MAX(0,jmax));
  kmin = M_MAX(0,M_MIN(kmin,siz-1));
  kmax = M_MIN(siz-1,M_MAX(0,kmax));
  if ( imin == imax && jmin == jmax && kmin == kmax )  return(1);

  for (k=kmin; k<=kmax; k++)
    for (j=jmin; j<=jmax; j++) 
      for (i=imin; i<=imax; i++) {
        icc = (k*siz + j)*siz + i;
        ip1 = bucket->head[icc];
        if ( !ip1 )  continue;
        pp1 = &mesh->point[ip1];
        hp2 = LFILT * sol->met[ip1];
        ux = pp1->c[0] - ppt->c[0];
        uy = pp1->c[1] - ppt->c[1];
        uz = pp1->c[2] - ppt->c[2];
        d2 = ux*ux + uy*uy + uz*uz;
        if ( d2 < hp1 || d2 < hp2*hp2 ) {
/*	 printf("other cell %d %e < %e -- %e < %e \n",ip1,d2,MMG_length(mesh,sol,ip,ip1),d2,hp2*hp2);
	 printf("on filtre avec %d : %e %e %e\n",ip1,pp1->c[0],pp1->c[1],pp1->c[2]);
	*/ return(0);
	}

        while ( bucket->link[ip1] ) {
          ip1 = bucket->link[ip1];
          pp1 = &mesh->point[ip1];
          hp2 = LFILT * sol->met[ip1];
          ux = pp1->c[0] - ppt->c[0];
          uy = pp1->c[1] - ppt->c[1];
          uz = pp1->c[2] - ppt->c[2];
          d2 = ux*ux + uy*uy + uz*uz;
          if ( d2 < hp1 || d2 < hp2*hp2 )  {
//	    printf("link cell %d %e < %e -- %e < %e \n",ip1,d2,hp1,d2,hp2*hp2);
	    return(0);
	  }
        }
      }

  return(1);
}


int MMG_addBucket(pMesh mesh,pBucket bucket,int ip) {
  pPoint	ppt;
  double	dd;
  int		ic,ii,jj,kk,siz;

  ppt = &mesh->point[ip];
  siz = bucket->size;
  dd  = siz / (double)PRECI;

  ii = M_MAX(0,(int)(dd * ppt->c[0])-1);
  jj = M_MAX(0,(int)(dd * ppt->c[1])-1);
  kk = M_MAX(0,(int)(dd * ppt->c[2])-1);
  ic = (kk*siz + jj)*siz + ii;

  /* store new point */
  if ( !bucket->head[ic] ) {
    bucket->head[ic] = ip;
    bucket->link[ip] = 0;
  }
  else {
    bucket->link[ip] = bucket->head[ic];
    bucket->head[ic] = ip;
    assert(ip!=bucket->link[ip]);
  }

  return(1);
}


int MMG_delBucket(pMesh mesh,pBucket bucket,int ip) {
  pPoint	ppt;
  double	dd;
  int		ic,ii,jj,kk,siz,ip1;

  ppt = &mesh->point[ip];
  siz = bucket->size;
  dd  = siz / (double)PRECI;

  ii = M_MAX(0,(int)(dd * ppt->c[0])-1);
  jj = M_MAX(0,(int)(dd * ppt->c[1])-1);
  kk = M_MAX(0,(int)(dd * ppt->c[2])-1);
  ic = (kk*siz + jj)*siz + ii;

  /* remove vertex from cell */
  if ( bucket->head[ic] ) {
    if ( bucket->head[ic] == ip ) {
      bucket->head[ic] = bucket->link[ip];
      bucket->link[ip] = 0;
    }
    else {
      ip1 = bucket->head[ic];
      while ( ip1 && bucket->link[ip1] != ip ) {
        ip1 = bucket->link[ip1];
      }
      if ( bucket->link[ip1] == ip ) {
        bucket->link[ip1] = bucket->link[ip];
        bucket->link[ip] = 0;
      }
    }
  }

  return(1);
}

