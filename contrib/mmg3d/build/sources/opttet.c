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

int    MMG_swaptet(pMesh mesh,pSol sol,pQueue queue, double declic,int iel);

int MMG_opttet(pMesh mesh,pSol sol) {
  pQueue     queue;
  double    declic;
  int      base,nm,ns,it,maxtou,alert,ier,k;
double worst;
double declicw;
int iterworst,nw;
  worst = 1e20;



  /* optim tet */
  alert = 0;
  declic = 1.7 / ALPHAD; //ALPHAD cte pour qualite interne
  maxtou = 10;
  base   = -1;
  it     = 0;

  do {
   ns = 0;
   nm = 0;
   
   iterworst = 0;
   nw = 0;
   declicw = 9./ALPHAD;
   do {
//printf("--------------- iter %d : declicw %e\n",iterworst,declicw*ALPHAD);
//MMG_outqua(mesh,sol);
     if (!mesh->info.noswap) 
     	nw = MMG_opttyp(mesh,sol,declicw,&alert);
   } while((iterworst++ < 0) && nw);
   MMG_outqua(mesh,sol);
   puts("  ");
   
   worst = MMG_priworst(mesh,sol);
   
   /* queueing tetrahedra */
   queue = MMG_kiuini(mesh,mesh->ne,declic,base);
   assert(queue);
   mesh->flag++;
   do {
     k = MMG_kiupop(queue);
     if ( !k )  break;
     /*try MMG_swap*/
     ier = 0;
     if((!mesh->info.noswap)) ier = MMG_swaptet(mesh,sol,queue,declic,k);
     if(ier < 0) {
       alert = 1;
     } else if(ier) {
       ns++;
       continue;
     }
     
     /*try move*/
     if(MMG_optlentet(mesh,sol,queue,declic,base,k)) {
       nm++;
       continue;
     } 
     
     }
   while ( k );
    
   MMG_kiufree(queue);
   base = ++mesh->flag;

   if ( mesh->info.imprim && nm+ns )
     fprintf(stdout,"     %8d MOVED  %8d SWAPPED\n",nm,ns);
  }
  while ( nm > 0.01*mesh->np && ++it < maxtou );

printf("------------------------ on est arrive a maxtou ?: %d %d\n",it,maxtou);
   worst = MMG_priworst(mesh,sol);

// #warning A ENLEVER
//   for(it=1 ; it<=mesh->ne ; it++) {
//     pt = &mesh->tetra[it];
//     if(pt->qual < declic) continue;
//     pt->ref = ALPHAD*pt->qual;
//   } 

  return(1);
}

    
