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

#define  HQCOEF    0.9 
#define  HCRIT     0.98

double MMG_rao(pMesh mesh,int k,int inm);
int MMG_optlen_ani(pMesh mesh,pSol sol,double declic,int base) {
  pTetra    pt,pt1;
  pPoint    ppa,ppb;
  pQueue    queue;
  List      list;
  double    cal,ctg,cx,cy,cz,ux,uy,uz,cpx,cpy,cpz,coe;
  double    oldc[3],dd,dd1,dd2,len,lmi,lma;
  double    *mp,*mb,wcal;
  int       i,j,k,l,iel,lon,nm;
  int       ipa,ipb,nb,nk,npp,iadr,iter,maxtou;

  /* queueing tetrahedra */
  queue = MMG_kiuini(mesh,mesh->ne,declic,base - 1);
  assert(queue);
  
  maxtou = 3;
  nm     = 0;
  npp    = 0;
  wcal   = 5. / ALPHAD;
  
  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;

    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    else if ( pt->flag != base - 1 )  continue;
    
    for (i=0; i<4; i++) {
      ipa = pt->v[i];
      ppa = &mesh->point[ipa];
      if ( ppa->tag & M_BDRY )  continue;
      else if ( ppa->flag != base - 1)  continue;
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
      /*if ( cal > 10.0 / ALPHAD )
        ctg = cal * HCRIT;
      else*/ 
        ctg = cal * HCRIT;//0.975;
      memcpy(oldc,ppa->c,3*sizeof(double));

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

          /* check length */
        /*  for (j=0; j<3; j++) {
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
          if ( j < 3 )  break;*/
        }
        if ( l > lon )  break;
        coe *= 0.5;
      }
      while ( ++iter <= maxtou );
      if ( iter > maxtou ) {
        memcpy(ppa->c,oldc,3*sizeof(double));
	    ppa->flag = base - 2;
        continue;
      }

      /* update tetra */
      for (l=1; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        pt1->qual = list.qual[l];
        pt1->flag = base;
		for(i=0; i<4; i++)  mesh->point[pt1->v[i]].flag = base; 
        if ( pt1->qual < declic )
          MMG_kiudel(queue,iel);
        else if ( coe > 0.1 )
          MMG_kiuput(queue,iel); 
      }

      /* interpol metric */
      ppa->flag = base + 1;
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


/* optimise using heap */
int MMG_optlen_iso(pMesh mesh,pSol sol,double declic,int base) {
  pTetra    pt,pt1;
  pPoint    ppa,ppb;
  pQueue    queue;
  List      list;
  double    oldc[3],cal,ctg,cx,cy,cz,ux,uy,uz,cpx,cpy,cpz,coe,dd,len;
  double    hb,hp,*ca,*cb;
  int       i,j,k,l,iel,lon,nm;
  int       ipa,ipb,nb,nk,npp,iadr,iter,maxtou;
int nrj;    
double tmp1,tmp2,tmp3;
  /* queue on quality */
  queue = MMG_kiuini(mesh,mesh->ne,declic,base - 1);
  assert(queue);

  maxtou = 10;
  nm     = 0;
  npp    = 0;
nrj = 0;  
  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;
    npp++;

    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
   //	else if ( pt->flag != base - 1 ) continue;
    for (i=0; i<4; i++) {
      ipa = pt->v[i];
      ppa = &mesh->point[ipa];
      if ( ppa->tag & M_BDRY )  continue;
    //  else if ( ppa->flag != base - 1 )  continue;

      lon = MMG_boulep(mesh,k,i,&list);
      if ( lon < 4 )  continue;

      /* optimal point */
      ca   = &ppa->c[0];
      iadr = (ipa-1)*sol->offset + 1;
      hp   = sol->met[iadr];
      cx   = 0.0;
      cy   = 0.0;
      cz   = 0.0;
      nb   = 0;
      cal  = pt->qual;
      for (l=1 ; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        if ( pt1->qual > cal )  cal = pt1->qual;
		tmp1 = 0;
		tmp2 = 0;
		tmp3 = 0;
        for (j=0; j<3; j++) {
          ipb  = pt1->v[ MMG_idir[nk][j] ];
          ppb  = &mesh->point[ipb]; 
/*if(ppb->mark < 0) continue;
ppb->mark = -ppb->mark;*/      
//printf("on prend en compte point %d\n",ipb);
	      cb   = &ppb->c[0];
          iadr = (ipb-1)*sol->offset + 1;
          hb   = sol->met[iadr];

          len = MMG_length(ca,cb,&hp,&hb); 

/*len = MMG_length(&(mesh->point[pt1->v[MMG_idir[nk][0]]].c[0]),&(mesh->point[pt1->v[MMG_idir[nk][1]]].c[0]),&hp,&hb); 
len += MMG_length(&(mesh->point[pt1->v[MMG_idir[nk][0]]].c[0]),&(mesh->point[pt1->v[MMG_idir[nk][2]]].c[0]),&hp,&hb); 
len += MMG_length(&(mesh->point[pt1->v[MMG_idir[nk][1]]].c[0]),&(mesh->point[pt1->v[MMG_idir[nk][2]]].c[0]),&hp,&hb); 
len /= 3.;
len = 1./len;
len *=  MMG_length(ca,cb,&hp,&hb); */  	
          /* optimal point */
	      ux  = ppb->c[0] - ppa->c[0];
          uy  = ppb->c[1] - ppa->c[1];
          uz  = ppb->c[2] - ppa->c[2];
          cx += ppa->c[0] + ux*(1. - 1./len);//ux * len;
          cy += ppa->c[1] + uy*(1. - 1./len);//uy * len;
          cz += ppa->c[2] + uz*(1. - 1./len);//uz * len; 
		tmp1 +=ux*(1. - 1./len);
		tmp2 +=uy*(1. - 1./len);
		tmp3 +=uz*(1. - 1./len);
/*memcpy(oldc,ppa->c,3*sizeof(double));
ppa->c[0] = oldc[0] + ux*(1. - 1./len);//ppb->c[0] - (ux/MMG_length(oldc,cb,&hp,&hb))*len;
ppa->c[1] = oldc[1] + uy*(1. - 1./len);//ppb->c[1] - (uy/MMG_length(oldc,cb,&hp,&hb))*len;
ppa->c[2] = oldc[2] + uz*(1. - 1./len);//ppb->c[2] - (uz/MMG_length(oldc,cb,&hp,&hb))*len; 
printf("%d len %e (%e)\n",j,MMG_length(ca,cb,&hp,&hb),len);
memcpy(ppa->c,oldc,3*sizeof(double));            
  */ 	
          nb++;
        }
/*check amelioration*/
/*memcpy(oldc,ppa->c,3*sizeof(double));
ppa->c[0] = oldc[0] + tmp1/3.;
ppa->c[1] = oldc[1] + tmp2/3.;
ppa->c[2] = oldc[2] + tmp3/3.;
if(MMG_caltet(mesh,sol,iel) > pt1->qual) {
	printf("oups %d -- cal of %d ( %d ) %e > %e\n",nb,iel,ipa,pt1->qual,MMG_caltet(mesh,sol,iel)); 

	//exit(0);
	}
else {
//printf("%d -- cal of %d ( %d ) %e > %e\n",nb,iel,ipa,pt1->qual,MMG_caltet(mesh,sol,iel)); 
}
memcpy(ppa->c,oldc,3*sizeof(double));
*/  
      }
/*for (l=1 ; l<=lon; l++) {
  iel = list.tetra[l] >> 2;
  nk  = list.tetra[l] % 4;
  pt1 = &mesh->tetra[iel];

  for (j=0; j<3; j++) {
    ipb  = pt1->v[ MMG_idir[nk][j] ];
    ppb  = &mesh->point[ipb]; 
    ppb->mark = abs(ppb->mark);
  }
} */

      if ( nb < 3 )  continue;
      dd  = 1.0 / (double)nb;
      cpx = cx*dd - ppa->c[0];
      cpy = cy*dd - ppa->c[1];
      cpz = cz*dd - ppa->c[2];

      /* adjust position */
      coe  = HQCOEF;
      iter = 1; 
      if(cal > 100./ALPHAD) {
        ctg  = 0.99 * cal;  
      } else {
        ctg  = cal * HCRIT;   
      }
      memcpy(oldc,ppa->c,3*sizeof(double));
      do {
        ppa->c[0] =/* (1. - coe) * */oldc[0] + coe * cpx;
        ppa->c[1] =/* (1. - coe) * */oldc[1] + coe * cpy;
        ppa->c[2] =/* (1. - coe) * */oldc[2] + coe * cpz;

        for (l=1; l<=lon; l++) {
          iel = list.tetra[l] >> 2;
          nk  = list.tetra[l] % 4;
          pt1 = &mesh->tetra[iel];
        
          cal = MMG_caltet(mesh,sol,iel);
          if ( cal > ctg )  break;
          list.qual[l] = cal;
        }
        if ( l > lon )  break;
        coe *= 0.5;
      }
      while ( ++iter <= maxtou );
      if ( iter > maxtou ) {
        memcpy(ppa->c,oldc,3*sizeof(double));
	    ppa->flag = base - 2;   
	    //if(k==154529) printf("cal(%d) %e %e %e\n",iel,cal,ctg,ctg/0.99);
		/*exit(0);*/ nrj++;	
        continue;
      }

      /* update tetra */
      for (l=1; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        pt1->qual = list.qual[l];
        pt1->flag = base;
	    for(i=0; i<4; i++)  mesh->point[pt1->v[i]].flag = base; 
        //if(iel==154529) printf("on a traite %d (%d) %e %d\n",iel,k,pt1->qual,iter);

        if ( pt1->qual < declic )
          MMG_kiudel(queue,iel);
        else if ( coe > 0.1 )
          MMG_kiuput(queue,iel);
      }

      /* interpol metric */
      ppa->flag = base + 1;
      nm++;
      break;
    }
  }
  while ( k );

  if ( mesh->info.imprim < - 4 )
    fprintf(stdout,"     %7d PROPOSED  %7d MOVED %d REJ \n",npp,nm,nrj);

  MMG_kiufree(queue);
  return(nm);
}

/* optimise using heap : point position on normal*/
int MMG_optlen_iso_new(pMesh mesh,pSol sol,double declic,int base) {
  pTetra    pt,pt1;
  pPoint    ppa,ppb,p1,p2,p3;
  pQueue    queue;
  List      list;
  double    oldc[3],cal,ctg,cx,cy,cz,ux,uy,uz,cpx,cpy,cpz,coe,dd,len;
  double    hb,hp,*ca,ax,ay,az,bx,by,bz,nx,ny,nz;
  int       i,j,k,l,iel,lon,nm;
  int       ipa,ipb,nb,nk,npp,iadr,iter,maxtou;
int nrj,i1,i2,i3; 
//double co1,co2,ddd;
  /* queue on quality */
  queue = MMG_kiuini(mesh,mesh->ne,declic,base - 1);
  assert(queue);

  maxtou = 3;
  nm     = 0;
  npp    = 0;
nrj = 0;  
  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;
    npp++;

    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
   	//else if ( pt->flag != base - 1 ) continue;
    
    for (i=0; i<4; i++) {
      ipa = pt->v[i];
      ppa = &mesh->point[ipa];
      if ( ppa->tag & M_BDRY )  continue;
      //else if ( ppa->flag != base - 1 )  continue;

      lon = MMG_boulep(mesh,k,i,&list);
      if ( lon < 4 )  continue;

      /* optimal point : length 1 sur la normal a la face*/
      ca   = &ppa->c[0];
      iadr = (ipa-1)*sol->offset + 1;
      hp   = sol->met[iadr];
      cx   = 0.0;
      cy   = 0.0;
      cz   = 0.0;
      ux   = 0.0;
      uy   = 0.0;
      uz   = 0.0;
      nb   = 0;
      cal  = pt->qual;  
      for (l=1 ; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        if ( pt1->qual > cal )  cal = pt1->qual;
	
//printf("lon %d cal %e %e\n",kel,pt1->qual,MMG_caltet_iso(mesh,sol,iel));
//printf("boule :   %d : %e %e %e\n",l,pt1->qual,pt1->qual*ALPHAD,MMG_rao(mesh,iel,0));
				
        /*compute normal*/
        i1 = pt->v[MMG_idir[nk][0]];
        i2 = pt->v[MMG_idir[nk][1]];
        i3 = pt->v[MMG_idir[nk][2]];
        p1 = &mesh->point[i1];
        p2 = &mesh->point[i2];
        p3 = &mesh->point[i3];
  
        ax = p3->c[0] - p1->c[0];
        ay = p3->c[1] - p1->c[1];
        az = p3->c[2] - p1->c[2];

        bx = p2->c[0] - p1->c[0];
        by = p2->c[1] - p1->c[1];
        bz = p2->c[2] - p1->c[2];

        nx = (ay*bz - az*by);
        ny = (az*bx - ax*bz);
        nz = (ax*by - ay*bx);
    
        dd = sqrt(nx*nx+ny*ny+nz*nz); 
        dd = 1./dd;
        nx *= dd;
        ny *= dd;
        nz *= dd; 

		len = 0;
        ux  = 0;
        uy  = 0;
        uz  = 0;
        for (j=0; j<3; j++) {
          ipb  = pt1->v[ MMG_idir[nk][j] ];
          ppb  = &mesh->point[ipb];
          iadr = (ipb-1)*sol->offset + 1;
          hb   = sol->met[iadr];  
          
          ax  = ppb->c[0] - ppa->c[0];
          ay  = ppb->c[1] - ppa->c[1];
          az  = ppb->c[2] - ppa->c[2]; 
          
          /* centre de gravite de la face*/
          ux += ppb->c[0];
          uy += ppb->c[1];
          uz += ppb->c[2];          

          dd    =   sqrt(ax*ax +ay*ay +az*az);
          len  +=   dd/hb;
        }
        dd  = 1.0 / (double)3.;
        len *= dd; 
        ux  *= dd;
        uy  *= dd;
        uz  *= dd;
        if(len > 0.) len = 1.0 / len;
        else printf("optlennew len %e\n",len);		
       
        /* optimal point */
        cx += ux + nx * len;
        cy += uy + ny * len;
        cz += uz + nz * len;
        nb++;        

      }
      if ( nb < 3 )  continue;
      dd  = 1.0 / (double)nb;
      cpx = cx*dd;
      cpy = cy*dd;
      cpz = cz*dd;

      /* adjust position */
      coe  = HQCOEF;
      iter = 1;
      if(cal > 100./ALPHAD) {
        ctg  = 0.99 * cal;  
      } else {
        ctg  = cal * HCRIT;   
      }
      maxtou =  10;
	  memcpy(oldc,ppa->c,3*sizeof(double));
      do {
        ppa->c[0] = (1. - coe) *oldc[0] + coe * cpx;
        ppa->c[1] = (1. - coe) *oldc[1] + coe * cpy;
        ppa->c[2] = (1. - coe) *oldc[2] + coe * cpz;

        for (l=1; l<=lon; l++) {
          iel = list.tetra[l] >> 2;
          nk  = list.tetra[l] % 4;
          pt1 = &mesh->tetra[iel];
        
          cal = MMG_caltet(mesh,sol,iel); 
//printf("l %d cal %e %e\n",l,cal,MMG_rao(mesh,iel,0));
          if ( cal > ctg )  break;
          list.qual[l] = cal;
        }
        if ( l > lon )  break;
		coe *= 0.5;
      }
      while ( ++iter <= maxtou );
      if ( iter > maxtou ) {
        memcpy(ppa->c,oldc,3*sizeof(double));
	    ppa->flag = base - 2;   
//printf("arg  cal %e %e %e\n",cal,ctg,ctg/0.98);  
		nrj++;	
        continue;
      }

      /* update tetra */
      for (l=1; l<=lon; l++) {
        iel = list.tetra[l] >> 2;
        nk  = list.tetra[l] % 4;
        pt1 = &mesh->tetra[iel];
        pt1->qual = list.qual[l];
        pt1->flag = base;
	    for(i=0; i<4; i++)  mesh->point[pt1->v[i]].flag = base; 

        if ( pt1->qual < declic )
          MMG_kiudel(queue,iel);
        else if ( coe > 0.1 )
          MMG_kiuput(queue,iel);
      }

      /* interpol metric */
      ppa->flag = base + 1;
      nm++;
      break;
    }
  }
  while ( k );

  if ( mesh->info.imprim < - 4 )
    fprintf(stdout,"     %7d PROPOSED  %7d MOVED %d REJ \n",npp,nm,nrj);

  MMG_kiufree(queue);
  return(nm);
}
