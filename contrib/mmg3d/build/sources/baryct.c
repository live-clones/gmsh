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

#define EPST    -1.e-14
#define EPSR     1.e+14


/* compute barycentrics */
int MMG_baryct(pMesh mesh,pTetra pt,double p[3],double cb[4]) {
  pPoint	p0,p1,p2,p3;
  double	bx,by,bz,cx,cy,cz,dx,dy,dz,vx,vy,vz,apx,apy,apz;
  double	epsra,vol1,vol2,vol3,vol4,dd; 

  p0 = &mesh->point[pt->v[0]];
  p1 = &mesh->point[pt->v[1]];
  p2 = &mesh->point[pt->v[2]];
  p3 = &mesh->point[pt->v[3]];

  /* barycentric */
  bx  = p1->c[0] - p0->c[0];
  by  = p1->c[1] - p0->c[1];
  bz  = p1->c[2] - p0->c[2];
  cx  = p2->c[0] - p0->c[0];
  cy  = p2->c[1] - p0->c[1];
  cz  = p2->c[2] - p0->c[2];
  dx  = p3->c[0] - p0->c[0];
  dy  = p3->c[1] - p0->c[1];
  dz  = p3->c[2] - p0->c[2];

  /* test volume */
  vx  = cy*dz - cz*dy;
  vy  = cz*dx - cx*dz;
  vz  = cx*dy - cy*dx;

  epsra = EPST*(bx*vx + by*vy + bz*vz);
  apx = p[0] - p0->c[0];
  apy = p[1] - p0->c[1];
  apz = p[2] - p0->c[2];

  /* p in 2 */
  vol2  = apx*vx + apy*vy + apz*vz;
  if ( epsra > vol2 )  return(0);

  /* p in 3 */
  vx  = by*apz - bz*apy;
  vy  = bz*apx - bx*apz;
  vz  = bx*apy - by*apx;
  vol3 = dx*vx + dy*vy + dz*vz;
  if ( epsra > vol3 )  return(0);
    
  /* p in 4 */
  vol4 = -cx*vx - cy*vy - cz*vz;
  if ( epsra > vol4 )  return(0);
  
  /* p in 1 */
  vol1 = -epsra * EPSR - vol2 - vol3 - vol4;
  if ( epsra > vol1 )  return(0);

  dd = vol1+vol2+vol3+vol4;
  if ( dd != 0.0 )  dd = 1.0 / dd;
  cb[0] = vol1 * dd;
  cb[1] = vol2 * dd;
  cb[2] = vol3 * dd;
  cb[3] = vol4 * dd; 

  return(1);
}

