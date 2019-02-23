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

#define  EPSLOC   1.00005


int MMG_chkmsh(pMesh mesh,int severe,int base) {
  pPoint	ppt;
  pTetra	pt1,pt2;
  List		list;
  int		*adja,*adja1,adj,adj1,k,kk,l,nk,i,j,ip,iadr,lon,len;
  unsigned char	voy,voy1;

  for (k=1; k<=mesh->ne; k++) {
    pt1 = &mesh->tetra[k];
    if ( !pt1->v[0] )  continue;
    iadr = (k-1)*4 + 1;
    adja = &mesh->adja[iadr];

    for (i=0; i<4; i++) {
      adj = adja[i] / 4;
      voy = adja[i] % 4;
      if ( !adj )  continue;

      if ( adj == k ) {
        fprintf(stdout,"  1. Wrong adjacency %d %d\n",k,adj);
	printf("k %d: %d %d %d %d\n",k,pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
	printf("adj (%d): %d %d %d %d\n",
	       k,adja[0]/4,adja[1]/4,adja[2]/4,adja[3]/4);
	exit(1);
      }
      pt2 = &mesh->tetra[adj];
      if ( !pt2->v[0] ) {
        fprintf(stdout,"  4. Invalid adjacent %d %d\n",adj,k);
	printf("sommets k   %d: %d %d %d %d\n",
	       k,pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
	printf("sommets adj %d: %d %d %d %d\n",
	adj,pt2->v[0],pt2->v[1],pt2->v[2],pt2->v[3]);
	printf("numeros adj %d: %d %d %d %d\n",k,adja[0]/4,adja[1]/4,adja[2]/4,adja[3]/4);
	exit(1);
      }
      iadr  = (adj-1)*4 + 1;
      adja1 = &mesh->adja[iadr];   
      adj1  = adja1[voy] / 4;
      voy1  = adja1[voy] % 4;
      if ( adj1 != k || voy1 != i ) {
        fprintf(stdout,"  2. Wrong adjacency %d %d\n",k,adj1);
	printf("k %d: %d %d %d %d\n",k,pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
	printf("a %d: %d %d %d %d\n",
	       adj,pt2->v[0],pt2->v[1],pt2->v[2],pt2->v[3]);
	printf("adj(%d): %d %d %d %d\n",
	       k,adja[0]/4,adja[1]/4,adja[2]/4,adja[3]/4);
	printf("adj(%d): %d %d %d %d\n",
	      adj,adja1[0]/4,adja1[1]/4,adja1[2]/4,adja1[3]/4);
	exit(1);
      }
    }
  }
  
  /* Delaunay criterion */
/*
  for (k=1; k<=mesh->ne; k++) {
    pt1 = &mesh->tetra[k];
    if ( !pt1->v[0] )  continue;
    iadr = (k-1)*4 + 1; 
    adja = &mesh->adja[iadr];
    if ( !cenrad(mesh,k,c,&ray) )  continue;

    for (i=0; i<4; i++) {
      if ( !adja[i] )  continue;
      adj = adja[i] / 4;
      voy = adja[i] % 4;
      pt2 = &mesh->tetra[adj];

      ppt = &mesh->point[ pt2->v[voy] ];
      dd = (ppt->c[0] - c[0]) * (ppt->c[0] - c[0]) \
         + (ppt->c[1] - c[1]) * (ppt->c[1] - c[1]) \
         + (ppt->c[2] - c[2]) * (ppt->c[2] - c[2]);
      if ( EPSLOC*EPSLOC*dd < ray ) {
        fprintf(stdout,"  ## Non-Delaunay mesh:  %.14f < %.14f\n",dd,ray);
	exit(1);
      }
    }
  }
*/
  
  if ( !severe )  return(1);

  for (k=1; k<=mesh->ne; k++) {
    pt1 = &mesh->tetra[k];
    if ( !pt1->v[0] )  continue;
    else if (pt1->flag < base )  continue;
    iadr = 4*(k-1) + 1;
    adja = &mesh->adja[iadr];

    for (i=0; i<4; i++) {
      adj = (adja[i]-1) / 4 + 1;
      voy = (adja[i]-1) % 4;
      if ( !adj )  continue;

      ip  = pt1->v[i];
      ppt = &mesh->point[ip];
      if ( ppt->tag & M_UNUSED ) {
        fprintf(stdout,"  6. Unused vertex %d  %d\n",k,ip);
	printf("%d %d %d %d\n",pt1->v[0],pt1->v[1],pt1->v[2],pt1->v[3]);
	exit(1);
      }
      lon = MMG_boulep(mesh,k,i,&list);
      for (l=1; l<=lon; l++) {
        kk  = list.tetra[l] / 4;
	nk  = list.tetra[l] % 4;
	pt2 = &mesh->tetra[kk];
	if ( pt2->v[nk] != ip ) {
	  fprintf(stdout,"  5. Wrong ball %d, %d\n",ip,pt2->v[nk]);
	  exit(1);
	}
      }
      if ( lon < 1 )  continue;
      len = 0;
      for (kk=1; kk<=mesh->ne; kk++) {
        pt2 = &mesh->tetra[kk];
	if ( !pt2->v[0] )  continue;
	for (j=0; j<4; j++)
	  if ( pt2->v[j] == ip ) {
	    len++;
	    break;
	  }
      }
      if ( len != lon ) {
        fprintf(stdout,"  7. Incorrect ball %d: %d %d\n",pt1->v[i],lon,len);
        exit(1);
      }
    }
  }

  /*fprintf(stdout,"  ** MESH STRUCTURE IS OK\n");*/
  return(1);
}
