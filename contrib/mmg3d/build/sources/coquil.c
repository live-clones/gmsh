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

/* find all tets sharing edge ia of iel */
int MMG_coquil(pMesh mesh,int iel,int ia,pList list) {
  pTetra      pt;
  int        *adja,i,iadr,adj,base,na,nb,ipa,ipb,piv,ilist,kref;

  if ( iel < 1 )  return(0);
  pt   = &mesh->tetra[iel];
  if ( !pt->v[0] )  return(0);

  base     = ++mesh->mark;
  pt->mark = base; 
	kref     = pt->ref;
  ilist = 1;
  list->tetra[ilist] = 6*iel + ia;

  iadr = (iel-1)*4 + 1;
  adja = &mesh->adja[iadr];
  adj  = adja[ MMG_ifar[ia][0] ] >> 2;
  piv  = pt->v[ MMG_ifar[ia][1] ];
  if ( !adj )  return(0);

  na   = pt->v[ MMG_iare[ia][0] ];
  nb   = pt->v[ MMG_iare[ia][1] ];

  while ( adj != iel ) {
    pt = &mesh->tetra[adj];
    pt->mark = base; 
		if (kref!=pt->ref) return(0);
		
    /* identify edge */
    for (i=0; i<6; i++) {
      ipa = MMG_iare[i][0];
      ipb = MMG_iare[i][1];
      if ( (pt->v[ipa] == na && pt->v[ipb] == nb) ||
           (pt->v[ipa] == nb && pt->v[ipb] == na))  break;
    }
    if(i==6) printf("tetra %d : %d %d %d %d -- %e\n",iel,pt->v[0],pt->v[1],pt->v[2],pt->v[3],pt->qual);
    assert(i<6);

    ++ilist;
    if ( ilist > LONMAX-1 )  return(-ilist);
    list->tetra[ilist] = 6*adj + i;

    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    if ( pt->v[ MMG_ifar[i][0] ] == piv ) {
      adj = adja[ MMG_ifar[i][0] ] >> 2;
      piv = pt->v[ MMG_ifar[i][1] ];
    }
    else {
      adj = adja[ MMG_ifar[i][1] ] >> 2;
      piv = pt->v[ MMG_ifar[i][0] ];
    }

    if ( !adj )  return(0);
  }

  return(ilist);
}
