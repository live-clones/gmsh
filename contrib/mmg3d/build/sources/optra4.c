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

int MMG_pretreat(pMesh ,pSol ,double ,int *);

int MMG_optra4(pMesh mesh,pSol sol) {
  double	declicw;
  double	declic;
  int		base,nm,ns,it,maxtou,alert,nw,nwold,k;
  
  /* optim coquil */
  alert  = 0;
  maxtou = 20;//0;
  it     = 0;
  
  MMG_caltet = ( sol->offset==6 ) ? MMG_caltet_ani:MMG_caltet_iso;
  MMG_caltet2 = ( sol->offset==6 ) ? MMG_caltet2_ani:MMG_caltet2_iso;
    
  for (k=1; k<=mesh->ne; k++) {
    mesh->tetra[k].flag = mesh->flag;
    mesh->tetra[k].qual = MMG_caltet(mesh,sol,k);
  }
  for (k=1; k<=mesh->np; k++) mesh->point[k].flag = mesh->flag;
  declicw = 5./ALPHAD;
  declic  = 1.5/ ALPHAD;
            
  do {
    base = ++mesh->flag;
//MMG_ratio(mesh,sol,NULL); 
    ns = 0;
    if ( !alert && !mesh->info.noswap ) {
        ns = MMG_cendel(mesh,sol,declic,base);
      if ( ns < 0 ) {
        alert = 1;
    	ns    = -ns;
      }
    }
    nw = 0;
    /*if (!mesh->info.noinsert)  nw = MMG_pretreat(mesh,sol,declicw,&alert);
    */
    /*sur des surfaces courbes, il existe des tetras ayant  4 points de peau avec Q=3*/
    if ( it < 10 )  {
      nwold = nw;
      nw += MMG_opttyp(mesh,sol,declicw,&alert);
	  declicw *= 1.05;
         
    }
	nm = 0;    
    if (!mesh->info.nomove) {          
        nm = MMG_optlen(mesh,sol,declic,base);  
    }
    
    //if(!mesh->info.nomove && it<2) MMG_optlap(mesh,sol);
    if ( mesh->info.imprim < -10 && nw+ns+nm )
      fprintf(stdout,"     %8d IMPROVED  %8d SWAPPED  %8d MOVED\n",nw,ns,nm);     
    }
  //while ( (ns && ((ns > 0.005*mesh->ne /*&& nwold > nw*/) || it < 5)) && ++it < maxtou );
  while ( ns+nm && ++it < maxtou );
 
  return(1);
}

