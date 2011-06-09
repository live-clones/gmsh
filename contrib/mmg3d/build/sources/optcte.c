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

#define  HQCOEF    0.45
#define  HCRIT     0.8

int MMG_optlentmp(pMesh mesh,pSol sol,double declic,int base) {
  pTetra    pt,pt1;
  pPoint    ppa,ppb;
  pQueue    queue;
  List      list;
  double    cal,ctg,cx,cy,cz,ux,uy,uz,cpx,cpy,cpz,coe;
  double    oldc[3],dd,dd1,dd2,len,lmi,lma;
  double    *mp,*mb;
  int       i,j,k,l,iel,lon,nm;
  int       ipa,ipb,nb,nk,npp,iadr,iter,maxtou;

  /* queueing tetrahedra */
  queue = MMG_kiuini(mesh,mesh->ne,declic,base);
  assert(queue);
  mesh->flag++;

  maxtou = 5;
  nm  = 0;
  npp = 0;
  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;

    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;

    for (i=0; i<4; i++) {
      ipa = pt->v[i];
      ppa = &mesh->point[ipa];
      if ( ppa->tag & M_BDRY )  continue;
      else if ( ppa->flag > mesh->flag )  continue;
      npp++;

      lon = MMG_boulep(mesh,k,i,&list);
      if ( lon < 4 )  continue;

      /* optimal point */
      iadr = (ipa-1)*sol->offset + 1;
      mp   = &sol->met[iadr];
      cx  = 0.0;
      cy  = 0.0;
      cz  = 0.0;
      nb  = 0;
      cal = pt->qual;
      lmi = LSHORT;
      lma = LLONG;
      for (l=1; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        if ( pt1->qual > cal )  cal = pt1->qual;

        for (j=0; j<3; j++) {
          ipb = pt1->v[ MMG_idir[nk][j] ];
          ppb = &mesh->point[ipb];

          iadr = (ipb-1)*sol->offset + 1;
          mb   = &sol->met[iadr];

          ux  = ppb->c[0] - ppa->c[0];
          uy  = ppb->c[1] - ppa->c[1];
          uz  = ppb->c[2] - ppa->c[2];

          dd1 =      mp[0]*ux*ux + mp[3]*uy*uy + mp[5]*uz*uz \
              + 2.0*(mp[1]*ux*uy + mp[2]*ux*uz + mp[4]*uy*uz);
          
          dd2 =      mb[0]*ux*ux + mb[3]*uy*uy + mb[5]*uz*uz \
              + 2.0*(mb[1]*ux*uy + mb[2]*ux*uz + mb[4]*uy*uz);
          len = 0.5*(dd1+dd2);
          if ( len < lmi )      lmi = len;
          else if (len > lma )  lma = len;

          /* optimal point */
          len = 1.0 / sqrt(dd1);
          cx += ppa->c[0] + ux * len;
          cy += ppa->c[1] + uy * len;
          cz += ppa->c[2] + uz * len;
          nb++;
        }
      }
      if ( nb < 3 )  continue;
      dd  = 1.0 / (double)nb;
      cpx = cx*dd - ppa->c[0];
      cpy = cy*dd - ppa->c[1];
      cpz = cz*dd - ppa->c[2];

      /* adjust position */
      coe  = HQCOEF;
      iter = 1;
      if ( cal > 10.0 / ALPHAD )
        ctg = cal * HCRIT;
      else if ( cal > 5.0 / ALPHAD )
        ctg = cal * 0.95;
      else
        ctg = cal * 0.975;
      memcpy(oldc,ppa->c,3*sizeof(double));

ctg = 1000. / ALPHAD;

      do {
        ppa->c[0] = oldc[0] + coe * cpx;
        ppa->c[1] = oldc[1] + coe * cpy;
        ppa->c[2] = oldc[2] + coe * cpz;

        for (l=1; l<=lon; l++) {
          iel = list.tetra[l] >> 2;
          nk  = list.tetra[l] % 4;
          pt1 = &mesh->tetra[iel];

          cal = MMG_caltet(mesh,sol,iel);
          if ( cal > ctg )  break;
          list.qual[l] = cal;

          /* check MMG_length */
          for (j=0; j<3; j++) {
            ipb = pt1->v[ MMG_idir[nk][j] ];
            ppb = &mesh->point[ipb];

            iadr = (ipb-1)*sol->offset + 1;
            mb   = &sol->met[iadr];

            ux  = ppb->c[0] - ppa->c[0];
            uy  = ppb->c[1] - ppa->c[1];
            uz  = ppb->c[2] - ppa->c[2];

            dd1 =      mp[0]*ux*ux + mp[3]*uy*uy + mp[5]*uz*uz \
                + 2.0*(mp[1]*ux*uy + mp[2]*ux*uz + mp[4]*uy*uz);
          
            dd2 =      mb[0]*ux*ux + mb[3]*uy*uy + mb[5]*uz*uz \
                + 2.0*(mb[1]*ux*uy + mb[2]*ux*uz + mb[4]*uy*uz);
            len = 0.5*(dd1+dd2);

            if ( len < lmi || len > lma )  break;
          }
          if ( j < 3 )  break;
        }
        if ( l > lon )  break;
        coe *= 0.5;
      }
      while ( ++iter <= maxtou );
      if ( iter > maxtou ) {
        memcpy(ppa->c,oldc,3*sizeof(double));
        continue;
      }

      /* update tetra */
      for (l=1; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        pt1->qual = list.qual[l];
        pt1->flag = mesh->flag;
        /*if ( pt1->qual < declic )
          MMG_kiudel(queue,iel);
        else if ( coe > 0.1 )
          MMG_kiuput(queue,iel); */
      }

      /* interpol metric */
      ppa->flag = mesh->flag + 1;
      nm++;
      break;
    }
  }
  while ( k );

  if ( mesh->info.imprim < -4 )
    fprintf(stdout,"     %7d PROPOSED  %7d MOVED\n",npp,nm);

  MMG_kiufree(queue);
  return(nm);
}





int MMG_optcte(pMesh mesh,pSol sol) {
  double	declicw;
  double	declic;
  int		base,nm,ns,it,maxtou,alert,nw;


  alert  = 0;

  /* optim coquil */
  declic = 1. / ALPHAD;
  maxtou = 10;
  base   = -1;
  it     = 0;

  do {
  
    nw = 0;
    declicw = 5./ALPHAD;
//    if (!mesh->info.noswap) nw = MMG_opttyp(mesh,sol,declicw,&alert);   
    
    nm = MMG_optlentmp(mesh,sol,declic,-1);
//     ns = 0;
//     if ( !alert && !mesh->info.noswap ) {
//       ns = MMG_cendel(mesh,sol,declic,base);
//       if ( ns < 0 ) {
//         alert = 1;
// 	ns    = -ns;
//       }
//     }
//     base = ++mesh->flag;
//     
//     if ( !mesh->disp ) if(it<2) MMG_optlap(mesh,sol);
    
ns = 0;    
    if ( mesh->info.imprim && nm+ns )
      fprintf(stdout,"     %8d MOVED  %8d SWAPPED\n",nm,ns);
  }
  while ( nm > 0.01*mesh->np && ++it < maxtou );
    
 
  MMG_outqua(mesh,sol);
  MMG_prilen(mesh,sol);
  puts("-------- APPEL MMG_optra4");
  MMG_optra4(mesh,sol);
  
  return(1);
}

