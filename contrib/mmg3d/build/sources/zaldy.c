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

/* get new point address */
int MMG_newPt(pMesh mesh,double c[3]) {
  pPoint  ppt;
  int     curpt;

  if ( !mesh->npnil )  return(0);

  curpt = mesh->npnil;
  if ( mesh->npnil > mesh->np )  mesh->np = mesh->npnil;
  ppt   = &mesh->point[curpt];
  memcpy(ppt->c,c,3*sizeof(double));
  ppt->tag   &= ~M_UNUSED;
  mesh->npnil = ppt->tmp;
  ppt->tmp    = 0;
  ppt->flag   = mesh->flag;

  return(curpt);
}


void MMG_delPt(pMesh mesh,int ip) {
  pPoint   ppt;
  ppt = &mesh->point[ip];
  memset(ppt,0,sizeof(Point));
  ppt->tag    = M_UNUSED;
  ppt->tmp    = mesh->npnil;
  mesh->npnil = ip;
  if ( ip == mesh->np )  mesh->np--;
}


/* get new elt address */
int MMG_newElt(pMesh mesh) {
  int     curiel;

  if ( !mesh->nenil ) {
    fprintf(stdout,"  ## UNABLE TO ALLOCATE NEW ELEMENT.\n");
    return(0);
  }
  curiel      = mesh->nenil;
  if ( mesh->nenil > mesh->ne )  mesh->ne = mesh->nenil;
  mesh->nenil = mesh->tetra[curiel].v[3];
  mesh->tetra[curiel].v[3] = 0;

  return(curiel);
}


void MMG_delElt(pMesh mesh,int iel) {
  pTetra   pt;
  int      iadr,i;

  pt = &mesh->tetra[iel];
  if ( !pt->v[0] ) {
    fprintf(stdout,"  ## INVALID TETRA.\n");
    return;
  }
  memset(pt,0,sizeof(Tetra));
  pt->v[3] = mesh->nenil;
  pt->qual = 0.0;
  pt->edge = 0;
	iadr = (iel-1)*4 + 1;
  memset(&mesh->adja[iadr],0,4*sizeof(int));

  mesh->nenil = iel;
  if ( iel == mesh->ne )  mesh->ne--;
}


/* check if n elets available */
int MMG_getnElt(pMesh mesh,int n) {
  int     curiel;

  if ( !mesh->nenil )  return(0);
  curiel = mesh->nenil;
  do {
    curiel = mesh->tetra[curiel].v[3];
  }
  while (--n);

  return(n == 0);
}


/* get new elt address */
int MMG_newTria(pMesh mesh) {
  int     curiel;

  if ( !mesh->ntnil ) {
    fprintf(stdout,"  ## UNABLE TO ALLOCATE NEW TRIANGLE.\n");
    return(0);
  }
  curiel      = mesh->ntnil;
  if ( mesh->ntnil > mesh->nt )  mesh->nt = mesh->ntnil;
  mesh->ntnil = mesh->tria[curiel].v[2];
  mesh->tria[curiel].v[2] = 0;

  return(curiel);
}


void MMG_delTria(pMesh mesh,int iel) {
  pTria    pt;

  pt = &mesh->tria[iel];
  if ( !pt->v[0] ) {
    fprintf(stdout,"  ## INVALID TRIANGLE.\n");
    return;
  }
  memset(pt,0,sizeof(Tria));
  pt->v[2]    = mesh->ntnil;
  mesh->ntnil = iel;
  if ( iel == mesh->nt )  mesh->nt--;
}


/* allocate main structure */
int MMG_zaldy(pMesh mesh) {
  int     million = 1048576L;
  int     k,npask;

  if ( mesh->info.memory < 0 ) {
    mesh->npmax = M_MAX(1.5*mesh->np,NPMAX);
    mesh->nemax = M_MAX(1.5*mesh->ne,NEMAX);
    mesh->ntmax = M_MAX(1.5*mesh->nt,NTMAX);
  }
  else {
    /* point+tria+tets+adja+sol+bucket+queue */
    int bytes = sizeof(Point)   + 0.2*sizeof(Tria) \
              + 6*sizeof(Tetra) + 4*sizeof(int) \
	      + sizeof(Sol) + sizeof(Displ) \
	      + sizeof(int) + 5*sizeof(int);

    npask = (double)mesh->info.memory / bytes * million;
    mesh->npmax = M_MAX(1.5*mesh->np,npask);
    mesh->nemax = M_MAX(1.5*mesh->ne,6*npask);
    mesh->ntmax = M_MAX(1.5*mesh->nt,(int)(0.3*npask));
  }

  mesh->point = (pPoint)M_calloc(mesh->npmax+1,sizeof(Point),"MMG_zaldy.point");
  assert(mesh->point);
  mesh->tetra = (pTetra)M_calloc(mesh->nemax+1,sizeof(Tetra),"MMG_zaldy.tetra");
  assert(mesh->tetra);
  mesh->tria  = (pTria)M_calloc(mesh->ntmax+1,sizeof(Tria),"MMG_zaldy.tria");
  assert(mesh->tria);
  mesh->adja = (int*)M_calloc(4*mesh->nemax+5,sizeof(int),"MMG_zaldy.adja");
  assert(mesh->adja);
  mesh->disp = (pDispl)M_calloc(1,sizeof(Displ),"MMG_zaldy.displ");
  assert(mesh->disp);
  mesh->disp->mv = (double*)M_calloc(3*(mesh->npmax + 1),sizeof(double),"MMG_zaldy.displ");
  assert(mesh->disp->mv);
  mesh->disp->alpha = (short*)M_calloc(mesh->npmax+1,sizeof(short),"MMG_zaldy.displ");
  assert(mesh->disp->alpha);

  /* keep track of empty links */
  mesh->npnil = mesh->np + 1;
  mesh->nenil = mesh->ne + 1;

  for (k=mesh->npnil; k<mesh->npmax-1; k++)
    mesh->point[k].tmp  = k+1;

  for (k=mesh->nenil; k<mesh->nemax-1; k++)
    mesh->tetra[k].v[3] = k+1;

  if ( mesh->nt ) {
    mesh->ntnil = mesh->nt + 1;
    for (k=mesh->ntnil; k<mesh->ntmax-1; k++)
      mesh->tria[k].v[2] = k+1;
  }

  return(1);
}


/* sol structure */
int MMG_zaldy3(pSol sol) {
  if ( sol->npmax ) {
    sol->met = (double*)M_calloc(sol->npmax+1,sol->offset*sizeof(double),"MMG_zaldy3");
    assert(sol->met);
    sol->metold = (double*)M_calloc(sol->npmax+1,sol->offset*sizeof(double),"MMG_zaldy3");
    assert(sol->metold);
  }

  return(1);
}


/* edge structure for cavity */
int MMG_zaldy4(pHedge hedg,int size) { 
  int   k;

  hedg->size  = size;
  hedg->hnxt  = size;
  hedg->nhmax = (int)(16*size);
  hedg->item  = (hedge*)M_calloc(hedg->nhmax+1,sizeof(hedge),"MMG_zaldy4");
  //assert(hedg->item);

  for (k=size; k<hedg->nhmax; k++)
    hedg->item[k].nxt = k+1;

  return(1);
}


/* internal edges */
int MMG_zaldy5() {
  return(1);
}

