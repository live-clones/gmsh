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

int MMG_scaleMesh(pMesh mesh,pSol sol) {
  pTetra    pt;
  pPoint    ppt;
  pDispl    pd;
  Info     *info;
  double    dd,d1;
  double    *m,*mold;
  int       i,k,iadr,alloc,ii,jj,kk;
  double	lambda[3],v[3][3];  

  /* mark used vertices */
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    for (i=0; i<4; i++) {
      ppt = &mesh->point[ pt->v[i] ];
      ppt->tag &= ~M_UNUSED;
    }
  }
  
  if (abs(mesh->info.option)==10) {
    return(1);
  }           
  
  /* compute bounding box */
  info = &mesh->info;
  for (i=0; i<3; i++) {
    info->min[i] =  DBL_MAX;
    info->max[i] = -DBL_MAX;
  }

  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED ) continue;
    for (i=0; i<3; i++) {
      if ( ppt->c[i] > info->max[i] )  info->max[i] = ppt->c[i];
      if ( ppt->c[i] < info->min[i] )  info->min[i] = ppt->c[i];
    }
  }
  info->delta = info->max[0]-info->min[0];
  dd = info->max[1]-info->min[1];
  if ( dd > info->delta )
    info->delta = dd;
  dd = info->max[2]-info->min[2];
  if ( dd > info->delta )
    info->delta = dd;
  if ( info->delta < EPS30 ) {
    fprintf(stdout,"  ## Unable to scale mesh.\n");
    return(0);
  }
  /* normalize coordinates */
  alloc = mesh->disp != NULL;
  dd = (double)PRECI / info->delta;
  if ( !alloc ) {
    for (k=1; k<=mesh->np; k++) {
      ppt = &mesh->point[k];
      if ( ppt->tag & M_UNUSED )  continue;
      ppt->c[0] = dd * (ppt->c[0] - info->min[0]);
      ppt->c[1] = dd * (ppt->c[1] - info->min[1]);
      ppt->c[2] = dd * (ppt->c[2] - info->min[2]);
    }
  }
  else {
    pd  = mesh->disp;
    for (k=1; k<=mesh->np; k++) {
      ppt = &mesh->point[k];
      if ( ppt->tag & M_UNUSED )  continue;
      ppt->c[0] = dd * (ppt->c[0] - info->min[0]);
      ppt->c[1] = dd * (ppt->c[1] - info->min[1]);
      ppt->c[2] = dd * (ppt->c[2] - info->min[2]);

      pd->mv[3*(k-1) + 1 + 0] *= dd;
      pd->mv[3*(k-1) + 1 + 1] *= dd;
      pd->mv[3*(k-1) + 1 + 2] *= dd;

      d1 = pd->mv[3*(k-1) + 1 + 0]*pd->mv[3*(k-1) + 1 + 0]
 		 + pd->mv[3*(k-1) + 1 + 1]*pd->mv[3*(k-1) + 1 + 1] \
         + pd->mv[3*(k-1) + 1 + 2]*pd->mv[3*(k-1) + 1 + 2];
      if ( d1 > EPS2 )  ppt->tag  |= M_MOVE;
    }
  }

  /* normalize metric */
  if ( !sol->np ) return(1);
  
  switch (sol->offset) {
  case 1:
    for (k=1; k<=sol->np; k++)  {
      sol->met[k] *= dd;
     }
    break;

  case 6:
    dd = 1.0 / (dd*dd);
    for (k=1; k<=mesh->np; k++) {
      iadr = (k-1)*sol->offset + 1;
      m    = &sol->met[iadr];
      for (i=0; i<sol->offset; i++)  m[i]   *= dd; 
      
      /*calcul du log de M*/                 
      if ( !eigenv(1,m,lambda,v) ) {
         printf("WRONG METRIC AT POINT %d -- \n",k);
	     return(0);
      }
      for (i=0; i<3; i++) { 
        if(lambda[i]<=0) {    
            printf("WRONG METRIC AT POINT %d -- eigenvalue : %e %e %e -- det %e\n",k,lambda[0],lambda[1],lambda[2],
                                                        m[0]*(m[3]*m[5]-m[4]*m[4])-m[1]*(m[1]*m[5]-m[2]*m[4])+
                                                        m[2]*(m[1]*m[4]-m[2]*m[3]));
            printf("WRONG METRIC AT POINT %d -- metric %e %e %e %e %e %e\n",k,m[0],m[1],m[2],m[3],m[4],m[5]);
            return(0);  
        }  
        lambda[i] = log(lambda[i]);
      }
      mold    = &sol->metold[iadr]; 
      kk = 0;
      for (ii=0; ii<3; ii++) {
	for (jj=ii; jj<3; jj++) {
	  mold[kk] = lambda[0]*v[0][ii]*v[0][jj] + 
	    lambda[1]*v[1][ii]*v[1][jj] +
	    lambda[2]*v[2][ii]*v[2][jj]; 
	  kk = kk+1;
	}                     
      }
    }
    break;
  default:
    fprintf(stderr,"  ## SPECIFIC DATA NOT USED.\n");
    exit(2);
  }
  
  /* compute quality */       
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k]; 
    if ( pt->v[0] ) {
      pt->qual = MMG_caltet(mesh,sol,k);   
    }
    else
      pt->qual = 0.0;
  }

  return(1);
}


int MMG_unscaleMesh(pMesh mesh,pSol sol) {
  pPoint     ppt;
  Info      *info;
  double     dd;
  double     *m;
  int        i,k,iadr;

  info = &mesh->info;

  /* de-normalize coordinates */
  dd = info->delta / (double)PRECI;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
    ppt->c[0] = ppt->c[0] * dd + info->min[0];
    ppt->c[1] = ppt->c[1] * dd + info->min[1];
    ppt->c[2] = ppt->c[2] * dd + info->min[2];
  }

  /* de-normalize metric */
  sol->np = mesh->np;
  if ( sol->offset == 1 ) {
    for (k=1; k<=sol->np; k++)  sol->met[k] *= dd;
  }
  else {
    dd = 1.0 / (dd*dd);
    for (k=1; k<=sol->np; k++) {
      iadr = (k-1)*sol->offset + 1;
      m    = &sol->met[iadr];
      for (i=0; i<6; i++)  m[i] *= dd;
    }
  }

  return(1);
}



