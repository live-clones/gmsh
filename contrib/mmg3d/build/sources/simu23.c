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

int MMG_simu23(pMesh mesh,pSol sol,int iel,int i,double crit) {
  pTetra     pt,pt1;
  int       *adja,iadr,jel,j,ia,ib,s1,s2,s3;
  if ( !MMG_getnElt(mesh,3) )  return(-1);

  pt = &mesh->tetra[iel];
  if ( !pt->v[0] )  return(0);

  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  if ( !adja[i] || (pt->bdryref[i]!=-1))  return(0);
  jel  = adja[i] / 4;
  j    = adja[i] % 4;
  pt1  = &mesh->tetra[jel];

  ia = pt->v[i];
  ib = pt1->v[j];
  s1 = pt->v[ MMG_idir[i][0] ];
  s2 = pt->v[ MMG_idir[i][1] ];
  s3 = pt->v[ MMG_idir[i][2] ];

  /* quality of new tetras */
  pt1 = &mesh->tetra[0];
  pt1->v[0] = ia;
  pt1->v[1] = ib;
  pt1->v[2] = s1;
  pt1->v[3] = s2;
  if ( MMG_caltet(mesh,sol,0) > crit ) {
    memset(pt1,0,sizeof(Tetra));
    return(0);
  }

  pt1->v[2] = s2;
  pt1->v[3] = s3;
  if ( MMG_caltet(mesh,sol,0) > crit ) {
    memset(pt1,0,sizeof(Tetra));
    return(0);
  }

  pt1->v[2] = s3;
  pt1->v[3] = s1;
  if ( MMG_caltet(mesh,sol,0) > crit ) {
    memset(pt1,0,sizeof(Tetra));
    return(0);
  }

  memset(pt1,0,sizeof(Tetra));
  
  /* set function ptr */
//  MMG_swpptr = MMG_swap23;
  return(1);
}


int MMG_simu32(pMesh mesh,pSol sol,pList list,double crit) {
  pTetra    pt,pt1;
  double    caltab[2];
  int      *adja,k,adj,ia,ib,s1,s2,s3,iadr,iel,iar;
  short     voy;

  /* initial qual */
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

  /* qual 2 elts */
  pt1 = &mesh->tetra[0];
  pt1->v[0] = ia;
  pt1->v[1] = s1;
  pt1->v[2] = s2;
  pt1->v[3] = s3;
  if(!MMG_caltet2(mesh,sol,0,ib,crit,caltab)) {
    memset(pt1,0,sizeof(Tetra));
    return(0);
  }
  list->qual[1] = caltab[0];
  list->qual[2] = caltab[1];

  memset(pt1,0,sizeof(Tetra));

  /* set function ptr */
  MMG_swpptr = MMG_swap32;
  return(1);
}
