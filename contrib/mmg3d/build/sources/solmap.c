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

static int MMG_inxtt[5] = {0,1,2,0,1};


/* compute iso size map */
int MMG_doSol(pMesh mesh,pSol sol) {
  pTetra     pt;
  pTria      ptt;
  pPoint     p1,p2;
  double     ux,uy,uz,dd;
  int        i,k,ia,ib,ipa,ipb;

  /* memory alloc */
  sol->np     = mesh->np;
  sol->npfixe = mesh->npfixe;
  sol->npmax  = mesh->npmax;
  sol->offset = 1;

  if ( !MMG_zaldy3(sol) )  return(0);
  /* boundary edges */
  for (k=1; k<=mesh->nt; k++) {
    ptt = &mesh->tria[k];
    if ( !ptt->v[0] )  continue;

    for (i=0; i<3; i++) {
      ib  = MMG_inxtt[i+1];
      ipa = ptt->v[i];
      ipb = ptt->v[ib];
      p1  = &mesh->point[ipa];
      p2  = &mesh->point[ipb];

      ux  = p1->c[0] - p2->c[0];
      uy  = p1->c[1] - p2->c[1];
      uz  = p1->c[2] - p2->c[2];
      dd  = sqrt(ux*ux + uy*uy + uz*uz);

      sol->met[ipa] += dd;
      p1->mark++;
      sol->met[ipb] += dd;
      p2->mark++;
    }
  }

  /* internal edges */
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;

    /* internal edges */
    for (i=0; i<6; i++) {
      ia  = MMG_iare[i][0];
      ib  = MMG_iare[i][1];
      ipa = pt->v[ia];
      ipb = pt->v[ib];
      p1  = &mesh->point[ipa];
      p2  = &mesh->point[ipb];

      ux  = p1->c[0] - p2->c[0];
      uy  = p1->c[1] - p2->c[1];
      uz  = p1->c[2] - p2->c[2];
      dd  = sqrt(ux*ux + uy*uy + uz*uz);

      //if ( !(p1->tag & M_BDRY) ) {
        sol->met[ipa] += dd;
        p1->mark++;
      //}
      //if ( !(p2->tag & M_BDRY) ) {
        sol->met[ipb] += dd;
        p2->mark++;
      //}
    }
  }

  /* vertex size */
  sol->hmin = 1.e20;
  sol->hmax = 0.0;
  for (k=1; k<=mesh->np; k++) {
    p1 = &mesh->point[k];
    if ( !p1->mark )  continue;

    sol->met[k] = sol->met[k] / (double)p1->mark;
 
    if ( sol->met[k] < sol->hmin )
      sol->hmin = sol->met[k];
    else if ( sol->met[k] > sol->hmax )
      sol->hmax = sol->met[k];

    p1->mark = 0;
  }

  if ( mesh->info.imprim < -4 )
    fprintf(stdout,"     HMIN %f   HMAX %f\n",sol->hmin,sol->hmax);   
    
  /*compute quality*/
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k]; 
    if ( pt->v[0] ) 
      pt->qual = MMG_caltet(mesh,sol,k);
    else
      pt->qual = 0.0;
  }
    
  return(1);
}

/* interpol iso/aniso size map */
int MMG_computeMetric(pMesh mesh,pSol sol,int ip,double * coor) {
  pTetra 	pt;
  pPoint 	ppt;
  double 	cb[4];
  double 	dma[6],mai[6],mi[6];
  double 	*mp,*ma;
  int    	ktet,i,k,base,iadr,ia;
  
  ppt = &mesh->point[ip];
  base = ++mesh->mark;
  ktet = MMG_loctet(mesh,ppt->tmp,base,coor,cb);
  if(!ktet) return(-1);
  assert(ktet < mesh->ne + 1);
  pt = &mesh->tetra[ktet];
  
  if ( sol->offset == 1 ) {
    sol->met[ip] = cb[0] * sol->metold[pt->v[0]];
  
    for(k = 1 ; k < 4 ; k++) {
      sol->met[ip] += cb[k] * sol->metold[pt->v[k]];
    }
  } else {
    iadr = (ip-1)*sol->offset + 1;
    mp   = &sol->met[iadr];
      
    for (i=0; i<6; i++) mi[i] = 0;
    
    for(k = 0 ; k < 4 ; k++) {
      ia   = pt->v[k];
      iadr = (ia-1)*sol->offset + 1;
      ma   = &sol->met[iadr];
      for (i=0; i<6; i++) {
        dma[i] = ma[i];
      }
      
      if ( !MMG_invmat(dma,mai) ) {
        fprintf(stderr,"  ## INVALID METRIC.\n");
        return(0);
      }
  
      for (i=0; i<6; i++)
        mi[i] += cb[k]*mai[i];
    }
    
    if ( !MMG_invmat(mi,mai) ) {
      fprintf(stderr,"  ## INVALID METRIC.\n");
      return(0);
    }
  
    for (i=0; i<6; i++)  mp[i] = mai[i];

  }  
  
  return(1);
}

