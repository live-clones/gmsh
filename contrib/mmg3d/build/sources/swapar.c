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

int MMG_swapar(pMesh mesh,pSol sol,pQueue q,List *list,int lon,double crit,double declic) {
  pTetra   pt;
  int      i,l,jel,ncas,ddebug;

  MMG_swpptr = 0;
  ncas   = 0;
  if ( !MMG_getnElt(mesh,10) )  return(-1);
	if(0 && list->tetra[1]/6==144988) ddebug=1;
	else ddebug=0;
	
  switch(lon) {
  case 3:
  	  ncas = MMG_simu32(mesh,sol,list,crit);
    break;
  case 4:
  	  ncas = MMG_simu44(mesh,sol,list,crit); 
    break;
  case 5:
  	  ncas = MMG_simu56(mesh,sol,list,crit);
    break;
  case 6:
  	  ncas = MMG_simu68(mesh,sol,list,crit); 
			if(ddebug) printf("on vient avec %d\n",list->tetra[1]/6);
    break;
  case 7:
    ncas = MMG_simu710(mesh,sol,list,crit);
    break;  
  default:
    return(0);
  }

  if ( ncas && MMG_swpptr ) {
		if(ddebug) MMG_saveMesh(mesh,"avt.mesh");
    for (l=1; l<=lon; l++) {
      jel = list->tetra[l]/6;
      pt  = &mesh->tetra[jel]; 
			if(ddebug) {
				printf("tet %d : %d %d %d %d -- %d %d %d %d %d %d\n",jel,pt->v[0],pt->v[1],pt->v[2],pt->v[3],
					pt->bdryinfo[0],pt->bdryinfo[1],pt->bdryinfo[2],pt->bdryinfo[3],pt->bdryinfo[4],pt->bdryinfo[5]);
			}     
			MMG_kiudel(q,jel);
    }
    lon = MMG_swpptr(mesh,sol,list);
    assert(lon);
    if(!lon) return(0); 
    
    for (l=1; l<=lon; l++) {
      jel = list->tetra[l];
      pt  = &mesh->tetra[jel]; 
      if ( pt->qual >= declic )  MMG_kiuput(q,jel);
      for (i=0; i<4; i++)  mesh->point[pt->v[i]].flag = mesh->flag; 
    }
		if(ddebug) MMG_saveMesh(mesh,"sw.mesh");
    return(1);
  }

  return(0);
}

