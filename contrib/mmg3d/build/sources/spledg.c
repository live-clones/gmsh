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

#define QCOEF   0.995


int MMG_spledg(pMesh mesh,pSol sol,pQueue queue,pList list,int lon,double crit,double declic) {
  pTetra    pt,pt0,pt1;
  pPoint    pa,pb;
  double     cal;
  double    *ca,*cb,c[3],*ma,*mb,*mip,mp[6];
  int       l,ipa,ipb,ip,jel,na,nbt,iel,iar,ret,iadr;
  short     ia,ib;
    
  iel = list->tetra[1] / 6;
  iar = list->tetra[1] % 6;
  ia  = MMG_iare[iar][0];
  ib  = MMG_iare[iar][1];

  pt  = &mesh->tetra[iel];
  ipa = pt->v[ia];
  ipb = pt->v[ib];
  pa  = &mesh->point[ipa];
  pb  = &mesh->point[ipb];
  
  ca  = &mesh->point[ipa].c[0];
  cb  = &mesh->point[ipb].c[0];
       
  iadr = (ipa-1)*sol->offset + 1;
  ma  = &sol->met[iadr];

  iadr = (ipb-1)*sol->offset + 1;
  mb  = &sol->met[iadr];
    
  /* metric interpolation */
  if ( !MMG_interp(ma,mb,mp,0.5) ) return(0);
	
  c[0] = 0.5*(ca[0] + cb[0]);
  c[1] = 0.5*(ca[1] + cb[1]);
  c[2] = 0.5*(ca[2] + cb[2]);
  ip   = MMG_newPt(mesh,c);
  if ( ip < 1 ) return(0);
  iadr = (ip-1)*sol->offset + 1;
  mip  = &sol->met[iadr];	  
  memcpy(mip,mp,sol->offset*sizeof(double));
    
  /* eval coquille */
  pt0  = &mesh->tetra[0];
  nbt  = 0;
  for (l=1; l<=lon; l++) {
    jel = list->tetra[l] / 6;
    na  = list->tetra[l] % 6;
    pt1 = &mesh->tetra[jel];

    memcpy(pt0->v,pt1->v,4*sizeof(int));
    ipb = MMG_iare[na][0];
    pt0->v[ipb] = ip;
    cal = MMG_caltet(mesh,sol,0);
    if ( cal > crit ) {
      MMG_delPt(mesh,ip);
      return(0);
    }

    memcpy(pt0->v,pt1->v,4*sizeof(int));
    ipb = MMG_iare[na][1];
    pt0->v[ipb] = ip;
    cal = MMG_caltet(mesh,sol,0);
    if ( cal > crit ) {
      MMG_delPt(mesh,ip);
      return(0);
    }
  }

  /* update */
  for (l=1; l<=lon; l++) {
    list->tetra[l] = list->tetra[l] / 6;
    mesh->tetra[list->tetra[l]].mark = mesh->mark;
  }
  ret = MMG_delons(mesh,sol,queue,ip,list,lon,declic);
  if ( ret <= 0 ) {
    MMG_delPt(mesh,ip);
    return(0);
  }
  else {  
    return(ip);  
  }
}

