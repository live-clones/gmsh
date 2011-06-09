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

#define EPSVOL    0.001
#define RAPMAX    0.25


/* identify type of element :
  ityp= 0: 4 faces bonnes          (elt ok)
        1: 4 faces bonnes, vol nul (sliver)
        2: 4 faces ok, vol nul+sommet proche face   (chapeau)
        3: 3 faces bonnes, 1 obtuse    (aileron)
        4: 2 faces bonnes, 2 faces aigu => 1 petite arete
        5: 1 face bonne, 3 petites aretes
        6: 2 faces grandes aretes, 2 faces petites iaretes
        7: 4 faces grandes aretes 
   item: bad entity
*/


/* nb face obtuse :    nb faces aigu : 
ityp :  0: 0		0
	1: 0		0
	2: 0		0
	3: 1		0
	4: 0		2
	5: 0		3
	6: 2		2
	7: 0		4
*/
/* nb gde arete :    nb petite arete : 
ityp :  0: 0		0
	1: 0		0
	2: 0		0
	3: 1		0
	4: 0		1
	5: 0		3
	6: 1		1
	7: 0		2
*/

int MMG_typelt(pMesh mesh,int iel,int *item) {
  pTetra    pt;
  pPoint    pa,pb,pc,pd;
  double    abx,aby,abz,acx,acy,acz,adx,ady,adz,v1,v2,v3,vol;
  double    bcx,bcy,bcz,bdx,bdy,bdz,cdx,cdy,cdz,h[6],volchk,ssmall;
  double    s[4],dd,rapmin,rapmax,surmin,surmax;
  int       i,k,ia,ib,ic,id,ityp,isur,isurmax,isurmin,iarmax,iarmin;
  int       nobtus,naigu;
  short     i0,i1,i2;

  ityp = 0;
  pt = &mesh->tetra[iel];
  if ( !pt->v[0] )  return(-1);

  ia = pt->v[0];
  ib = pt->v[1];
  ic = pt->v[2];
  id = pt->v[3];
  pa = &mesh->point[ia];
  pb = &mesh->point[ib];
  pc = &mesh->point[ic];
  pd = &mesh->point[id];

  /* volume */
  abx = pb->c[0] - pa->c[0]; 
  aby = pb->c[1] - pa->c[1]; 
  abz = pb->c[2] - pa->c[2]; 

  acx = pc->c[0] - pa->c[0]; 
  acy = pc->c[1] - pa->c[1]; 
  acz = pc->c[2] - pa->c[2]; 

  adx = pd->c[0] - pa->c[0]; 
  ady = pd->c[1] - pa->c[1]; 
  adz = pd->c[2] - pa->c[2]; 

  v1  = acy*adz - acz*ady;
  v2  = acz*adx - acx*adz;
  v3  = acx*ady - acy*adx;
  vol = abx * v1 + aby * v2 + abz * v3;

  /* max edge */
  h[0] = abx*abx + aby*aby + abz*abz;
  h[1] = acx*acx + acy*acy + acz*acz;
  h[2] = adx*adx + ady*ady + adz*adz;

  bcx = pc->c[0] - pb->c[0];
  bcy = pc->c[1] - pb->c[1];
  bcz = pc->c[2] - pb->c[2];

  bdx = pd->c[0] - pb->c[0];
  bdy = pd->c[1] - pb->c[1];
  bdz = pd->c[2] - pb->c[2];

  cdx = pd->c[0] - pc->c[0];
  cdy = pd->c[1] - pc->c[1];
  cdz = pd->c[2] - pc->c[2];

  h[3] = bcx*bcx + bcy*bcy + bcz*bcz;
  h[4] = bdx*bdx + bdy*bdy + bdz*bdz;
  h[5] = cdx*cdx + cdy*cdy + cdz*cdz;

  /* face areas */
  dd = cdy*bdz - cdz*bdy; 
  s[0] = dd * dd;
  dd = cdz*bdx - cdx*bdz;
  s[0] = s[0] + dd * dd;
  dd = cdx*bdy - cdy*bdx;
  s[0] = s[0] + dd * dd;
  s[0] = sqrt(s[0]);

  s[1] = sqrt(v1*v1 + v2*v2 + v3*v3);

  dd = bdy*adz - bdz*ady;
  s[2] = dd * dd;
  dd = bdz*adx - bdx*adz;
  s[2] = s[2] + dd * dd;
  dd = bdx*ady - bdy*adx;
  s[2] = s[2] + dd * dd;
  s[2] = sqrt(s[2]);

  dd = aby*acz - abz*acy;
  s[3] = dd * dd;
  dd = abz*acx - abx*acz;
  s[3] = s[3] + dd * dd;
  dd = abx*acy - aby*acx;
  s[3] = s[3] + dd * dd;
  s[3] = sqrt(s[3]);

  /* classification */
  rapmin = h[0];
  rapmax = h[0];
  iarmin = 0;
  iarmax = 0;
  for (i=1; i<6; i++) {
    if ( h[i] < rapmin ) {
      rapmin = h[i];
      iarmin = i;
    }
    else if ( h[i] > rapmax ) {
      rapmax = h[i];
      iarmax = i;
    }
  }
  rapmin = sqrt(rapmin);
  rapmax = sqrt(rapmax);
  volchk = EPSVOL * rapmin*rapmin*rapmin;

  /* small volume: types 1,2,3,4 */
  if ( vol < volchk ) {
//puts("volume nul : type 1,2,3,4");
    
    ssmall = 0.4 * (s[0]+s[1]+s[2]+s[3]);
    isur   = 0;
    for (i=0; i<4; i++)
      isur += s[i] > ssmall;

    /* types 2,3 */
    item[0] = iarmax;
    item[1] = MMG_isar[iarmax][0];    
    if ( isur == 1 ) {
      surmin   = s[0];
      isurmin = 0;
      surmax   = s[0];
      isurmax = 0;
      for (i=1; i<4; i++) {
        if ( s[i] < surmin ) {
          surmin  = s[i];
	  isurmin = i;
	}  
        else if ( s[i] > surmax ) {
	  surmax  = s[i];
	  isurmax = i;
	}  
      }
      dd = surmin / surmax;
      if ( dd < RAPMAX ) {
        item[1] = MMG_isar[iarmax][0];
        return(3);
      }
      else {
        item[0] = isurmax;
	item[1] = isurmin;
        return(2);
      }	
    }

    /* types 1 */
    isur = 0;
    if ( s[0]+s[1] > ssmall )  isur = 1;
    if ( s[0]+s[2] > ssmall )  isur++;
    if ( s[0]+s[3] > ssmall )  isur++;

    if ( isur > 2 ) {
      dd = rapmin / rapmax;
      item[0] = iarmin;
      item[1] = MMG_idir[iarmin][0];
      if ( dd < 0.01 )  return(4);
      if ( s[0]+s[1] > ssmall ) {
        item[0] = 0;
        return(1);
      }
      if ( s[0]+s[2] > ssmall ) {
        item[0] = 1;
        return(1);
      }
      if ( s[0]+s[3] > ssmall ) {
        item[0] = 2;
        return(1);
      }
    }
    
//puts("default");
    item[0] = 0;
    return(1);
  }/*end chkvol*/

 dd = rapmin / rapmax;
  /* types 3,6,7 */
 if ( dd < RAPMAX ) { /*ie une arete 4 fois plus gde qu'une autre*/
    
    for (i=0; i<6; i++)  h[i] = sqrt(h[i]);

    nobtus = 0;
    for (k=0; k<4; k++) {
      for (i=0; i<3; i++) {
        i0 = MMG_idir[k][i];
        i1 = MMG_idir[k][MMG_inxt[i]];
        i2 = MMG_idir[k][MMG_inxt[i+1]];
        if ( h[i0]+h[i1] < 1.2*h[i2] ) {/*1.4 ie une face obtus*/
	  nobtus++;
          item[0] = i2;
	  item[1] = MMG_idir[k][MMG_inxt[i+1]];
        }
      }
    }
    
    switch(nobtus){
      case 0 : 
       break;
      case 1: 
       item[0] = iarmax;
       item[1] = MMG_isar[iarmax][0];
       return(3);
      case 2:  
       item[0] = iarmin;
       item[1] = iarmax;
       return(6);
      default:
       item[0] = iarmin;
       item[1] = iarmax;
//printf("default obtus %d\n",nobtus);
       return(7);
    }
  }

  /* type 4,5,7 */
  else if ( dd < 0.7*RAPMAX ) {
    naigu = 0;
    for (k=0; k<4; k++) {
      for (i=0; i<3; i++) {
        i0 = MMG_idir[k][i];
        i1 = MMG_idir[k][MMG_inxt[i]];
        i2 = MMG_idir[k][MMG_inxt[i+1]];
    	if ( h[i0]+h[i1] > 1.5*h[i2] )  naigu++;/*1.5*/
      }
    }
    switch(naigu){
      case 0 : 
       break;
      case 1: 
       break;
      case 2:  
       item[0] = iarmin;
       return(4);
      case 3:
/*#warning definir item*/
       return(5);  
      default:
       item[0] = iarmin;
       item[1] = iarmax;
//printf("default aigu\n");
       return(7);
    }
  }

//   /* types 3,4,5,6,7 */
//   else {
//     isur = 0;
//     for (i=0; i<6; i++) {
//       if ( h[i] < 2.0*rapmin )  isur++;
//     }
// 
//     switch(isur){
//       case 2: 
//        puts("2 aretes tres grande retourne 7");
//        return(7);
//       case 3:  return(5);
//       case 1:
//         for (k=0; k<4; k++) {
//           for (i=0; i<3; i++) {
//             i0 = MMG_idir[k][i];
//             i1 = MMG_idir[k][i+1];
//             i2 = MMG_idir[k][i+2];
//             if ( h[i0]+h[i1] < 1.25*h[i2] )  return(6);
//           }
//         }
// 	puts("on retourne 4 la");
//         return(4);
//     }
//   }
      
//   surmin   = s[0];
//   isurmin = 0;
//   surmax   = s[0];
//   isurmax = 0;
//   for (i=1; i<4; i++) {
//     if ( s[i] < surmin ) {
//       surmin  = s[i];
//       isurmin = i;
//     }  
//     else if ( s[i] > surmax ) {
//       surmax  = s[i];
//       isurmax = i;
//     }  
//   }
// 
//   item[0] = isurmax;
//   item[1] = isurmin;
  item[0] = 0;
  //puts("default");
  return(1);
}
