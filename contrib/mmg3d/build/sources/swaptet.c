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

#define SCRIT    0.95

int MMG_swaptet(pMesh mesh,pSol sol,pQueue queue,double declic,int iel) {
  pTetra pt,pt1;
  List   list;
  double crit;
  int    i,*adja,iadr,lon,ier,adj,j,jel;
  char   tabar,done;
  
  pt = &mesh->tetra[iel];
  if ( !pt->v[0] )  return(0);

  /* mark internal edges */
  tabar = 0;
  iadr  = 4*(iel-1) + 1;
  adja  = &mesh->adja[iadr];
  for (i=0; i<4; i++) {
    adj = adja[i] >> 2;
    if ( !adj || pt->ref != mesh->tetra[adj].ref ) {
      tabar |= 1 << MMG_iarf[i][0];
      tabar |= 1 << MMG_iarf[i][1];
      tabar |= 1 << MMG_iarf[i][2];
    }
  }
  if ( tabar == ALL_BDRY )  return(0);
  
  /* MMG_swap for anisotropy */
  done = 0;
  for (i=0; i<6; i++) {
    if ( tabar & 1<<i )  continue;

    lon  = MMG_coquil(mesh,iel,i,&list);
    if ( lon < 3 || lon > 7 )  continue;

    /* qual crit */
    crit = pt->qual;
    for (j=2; j<=lon; j++) {
      jel  = list.tetra[j] / 6;
      pt1  = &mesh->tetra[jel];
      crit = M_MAX(crit,pt1->qual);
    }
    crit *= SCRIT;

    ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,declic);
    if ( ier > 0 ) {
      return(1);
      break;
    }
    else if ( ier < 0 ) {
      fprintf(stdout,"  ## UNABLE TO MMG_swap.\n");
      return(-1);
    }
    
  }
  
  return(0);
 
}
