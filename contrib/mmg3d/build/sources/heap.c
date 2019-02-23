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

#define QUAL      1
#define VECT      2


/* compare functions */
static int MMG_compVector(pMesh mesh,pHeap heap,int i,int j) {
  pTetra   pt,pt1;
  pPoint   pp1,pp2;
  pDispl   pd;
  int      dmin1,dmin2;
  short    k;

  pd    = mesh->disp;
  pt    = &mesh->tetra[i];
  pt1   = &mesh->tetra[j];
  dmin1 = INT_MAX;
  dmin2 = INT_MAX;

  for(k=0; k<4; k++) {
    pp1 = &mesh->point[pt->v[k]];
    if ( pp1->tag & M_MOVE && pd->alpha[pt->v[k]] < dmin1 )
      dmin1 = pd->alpha[pt->v[k]];
    pp2 = &mesh->point[pt1->v[k]];
    if ( pp2->tag & M_MOVE && pd->alpha[pt1->v[k]] < dmin2 )
      dmin2 = pd->alpha[pt1->v[k]];
  }

  return( dmin1 > dmin2 );
  /*return( mesh->tetra[i].move < mesh->tetra[j].move );*/
}

static int MMG_compQuality(pMesh mesh,pHeap heap,int i,int j) {
  return( (mesh->tetra[i].qual > mesh->tetra[j].qual) );
}

static int (*MMG_compare)(pMesh ,pHeap ,int ,int );


/* heap management */
static void MMG_hipup(pMesh mesh,pHeap heap,int k) {
  int     i,j;

  i = k / 2;
  j = heap->cell[k];

  while ( (i > 0) && MMG_compare(mesh,heap,j,heap->cell[i]) ) {
    heap->cell[k] = heap->cell[i];
    heap->link[heap->cell[i]] = k;
    k  = i;
    i /= 2;
  }
  heap->cell[k] = j;
  heap->link[j] = k;
}


static void MMG_hipdown(pMesh mesh,pHeap heap,int k) {
  int      i,j,n;

  i = heap->cell[k];
  n = heap->curc / 2;

  while ( k <= n ) {
    j   = k+k;
    if ( j < heap->curc ) {
      if ( MMG_compare(mesh,heap,heap->cell[j+1],heap->cell[j]) )
        j = j+1;
    }
    if ( MMG_compare(mesh,heap,i,heap->cell[j]) )
      break;
    heap->cell[k] = heap->cell[j];
    heap->link[heap->cell[j]] = k;
    k = j;
  }

  heap->cell[k] = i;
  heap->link[i] = k;
}


int MMG_hippop(pMesh mesh,pHeap heap) {
  int    j;

  if ( heap->curc < 1 )  return(0);
  j = heap->cell[1];
  if ( heap->curc > 1 ) {
    heap->cell[1] = heap->cell[heap->curc];
    heap->link[ heap->cell[heap->curc--] ] = 1;
    MMG_hipdown(mesh,heap,1);
  }
  else
    heap->curc--;

  return(j);
}


int MMG_hipput(pMesh mesh,pHeap heap,int k) {
  if ( heap->curc >= heap->size )  return(0);

  ++heap->curc;
  heap->cell[heap->curc] = k;
  heap->link[k]          = heap->curc;
  MMG_hipup(mesh,heap,heap->curc);

  return(1);
}


void MMG_hiprep(pMesh mesh,pHeap heap,int k) {
  MMG_hipdown(mesh,heap,heap->link[k]);
  MMG_hipup(mesh,heap,heap->link[k]);
}


void MMG_hipdel(pMesh mesh,pHeap heap,int k) {
  if ( heap->link[k] )
    MMG_hipdown(mesh,heap,heap->link[k]);
}


Heap *MMG_hipini(pMesh mesh,int nemax,short cmpfunc,double declic,int base) {
  pTetra   pt;
  pPoint   ppt;
  pDispl   pd;
  pHeap    heap;
  int      i,k,nm,dmin;

  /* mem alloc */
  heap = (Heap*)M_malloc(sizeof(Heap),"hipini");
  assert(heap);
  heap->size = nemax+1;
  heap->cell = (int*)M_calloc(heap->size,sizeof(int),"hipini");
  assert(heap->cell);
  heap->link = (int*)M_calloc(heap->size,sizeof(int),"hipini");
  assert(heap->link);
  heap->curc = 0;

  pd  = mesh->disp;

  /* assign function */
  if ( cmpfunc == QUAL ) {
    MMG_compare = MMG_compQuality;
    for (k=1; k<=mesh->ne; k++) {
      pt = &mesh->tetra[k];
      if ( !pt->v[0] || pt->qual < declic )    continue;
      else if ( base > 0 && pt->flag < base )  continue;
      else if ( !MMG_hipput(mesh,heap,k) )         return(0);
    }
  }
  else {
    MMG_compare = MMG_compVector;
    for (k=1; k<=mesh->ne; k++) {
      pt = &mesh->tetra[k];
      if ( !pt->v[0] )  continue;
      dmin = INT_MAX;
      nm   = 0;
      for (i=0; i<4; i++) {
        ppt = &mesh->point[ pt->v[i] ];
        if ( ppt->tag & M_MOVE ) {
          if ( pd->alpha[ 3*(pt->v[i]-1) + 1 ] < dmin )  dmin = pd->alpha[ 3*(pt->v[i]-1) + 1 ];
          nm++;
        }
      }
      if ( nm ) {
        if ( !MMG_hipput(mesh,heap,k) )  return(0);
      }
    }
  }

  return(heap);
}


void MMG_hipfree(pHeap heap) {
  M_free(heap->cell);
  M_free(heap->link);
  M_free(heap);
  heap = 0;
}
