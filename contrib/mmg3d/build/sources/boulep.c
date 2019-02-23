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


/* find all tets sharing P
   in:  start : tetrahedron containing p 
        ip    : index of p in start
        list  : dynamic list structure (allocated outside)
   out: list  : list of tets */
int MMG_boulep(pMesh mesh,int start,int ip,pList list) {
  pTetra	pt,pt1;
  pPoint	ppt;
  int		*adja,adj,i,j,indp,iel,iadr,base,ilist,nump;
  int 		vois[4];

  if ( start < 1 )  return(0);
  pt   = &mesh->tetra[start];
  if ( !pt->v[0] )  return(0);
  nump = pt->v[ip];
  ppt  = &mesh->point[nump];
  if ( ppt->tag & M_BDRY || ppt->tag & M_UNUSED )  return(0);

  /* store initial tet */
  base     = ++mesh->mark;
  pt->mark = base;
  ilist    = 1;
  list->tetra[ilist] = 4*start + ip;

  /* store 3 neighbors sharing P */
  iadr = (start-1)*4 + 1;
  adja = &mesh->adja[iadr];
  vois[0]  = adja[0] >> 2;
  vois[1]  = adja[1] >> 2;
  vois[2]  = adja[2] >> 2;
  vois[3]  = adja[3] >> 2;
  for (i=0; i<4; i++) {
    if ( i == ip )  continue;
    adj = vois[i];
    if ( adj ) {
      pt1 = &mesh->tetra[adj];
      if ( pt1->mark != base ) {
				pt1->mark = base;
				for (j=0; j<4; j++)
          if ( pt1->v[j] == nump )  break;
        ilist++;
        list->tetra[ilist] = 4*adj + j;
      }
    }
  }
  if ( ilist < 2 )  return(ilist);

  /* explore list of neighbors */
  indp = 2;
  do {
    iel  = list->tetra[indp] >> 2;
    pt   = &mesh->tetra[iel];
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    vois[0]  = adja[0] >> 2;
    vois[1]  = adja[1] >> 2;
    vois[2]  = adja[2] >> 2;
    vois[3]  = adja[3] >> 2;

    for (i=0; i<4; i++) {
      if ( pt->v[i] == nump )  continue;
      adj = vois[i];
      if ( adj ) {
        pt1 = &mesh->tetra[adj];
        if ( pt1->mark != base ) {
	  			pt1->mark = base;
	  			for (j=0; j<4; j++)
            if ( pt1->v[j] == nump )  break;
	  			ilist++;
          list->tetra[ilist] = 4*adj + j;
       }
      }
    }
    /* overflow */
    if ( ilist > LONMAX-3 )  return(-ilist);
  }
  while ( ++indp <= ilist );

  return(ilist);
}


/* idem boulep for any vertex */
int MMG_bouleg(pMesh mesh,int start,int ip,pList list) {
  pTetra	pt,pt1;
  pPoint	ppt;
  int		*adja,adj,i,j,indp,iel,iadr,base,ilist,nump;
  int		vois[4];
  
  if ( start < 1 )  return(0);
  pt   = &mesh->tetra[start];
  if ( !pt->v[0] )  return(0);
  nump = pt->v[ip];
  ppt  = &mesh->point[nump];
  if ( ppt->tag & M_UNUSED )  return(0);

  /* store initial tet */
  base     = ++mesh->mark;
  pt->mark = base;
  ilist    = 1;
  list->tetra[ilist] = 4*start + ip;

  /* store 3 neighbors sharing P */
  iadr = (start-1)*4 + 1;
  adja = &mesh->adja[iadr];
  vois[0]  = adja[0] >> 2;
  vois[1]  = adja[1] >> 2;
  vois[2]  = adja[2] >> 2;
  vois[3]  = adja[3] >> 2;
  for (i=0; i<4; i++) {
    if ( i == ip )  continue;
    adj = vois[i];
    if ( adj ) {
      pt1 = &mesh->tetra[adj];
      if ( pt1->mark != base ) {
	pt1->mark = base;
	for (j=0; j<4; j++)
          if ( pt1->v[j] == nump )  break;
        ilist++;
        list->tetra[ilist] = 4*adj + j;
      }
    }
  }
  if ( ilist < 2 )  return(ilist);

  /* explore list of neighbors */
  indp = 2;
  do {
    iel  = list->tetra[indp] >> 2;
    pt   = &mesh->tetra[iel];
    iadr = (iel-1)*4 + 1;
    adja = &mesh->adja[iadr];
    vois[0]  = adja[0] >> 2;
    vois[1]  = adja[1] >> 2;
    vois[2]  = adja[2] >> 2;
    vois[3]  = adja[3] >> 2;

    for (i=0; i<4; i++) {
      if ( pt->v[i] == nump )  continue;
      adj = vois[i];
      if ( adj ) {
        pt1 = &mesh->tetra[adj];
        if ( pt1->mark != base ) {
	  pt1->mark = base;
	  for (j=0; j<4; j++)
            if ( pt1->v[j] == nump )  break;
	  ilist++;
          list->tetra[ilist] = 4*adj + j;
       }
      }
    }
    /* overflow */
    if ( ilist > LONMAX-3 )  return(-ilist);
  }
  while ( ++indp <= ilist );

  return(ilist);
}
