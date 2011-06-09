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

/* compute aniso edge MMG_length */
double MMG_long_ani(double *ca,double *cb,double *sa,double *sb) {
  double   ux,uy,uz,dd1,dd2,len;

  ux = cb[0] - ca[0];
  uy = cb[1] - ca[1];
  uz = cb[2] - ca[2];

  dd1 =      sa[0]*ux*ux + sa[3]*uy*uy + sa[5]*uz*uz \
      + 2.0*(sa[1]*ux*uy + sa[2]*ux*uz + sa[4]*uy*uz);
  if ( dd1 <= 0.0 )  dd1 = 0.0;

  dd2 =      sb[0]*ux*ux + sb[3]*uy*uy + sb[5]*uz*uz \
      + 2.0*(sb[1]*ux*uy + sb[2]*ux*uz + sb[4]*uy*uz);
  if ( dd2 <= 0.0 )  dd2 = 0.0;
  
  /*longueur approchee*/   
  /*precision a 3.5 10e-3 pres*/
  if(fabs(dd1-dd2) < 0.05 ) {
    //printf("bonne precision %e \n",sqrt(0.5*(dd1+dd2)) - (sqrt(dd1)+sqrt(dd2)+4.0*sqrt(0.5*(dd1+dd2))) / 6.0 );
    len = sqrt(0.5*(dd1+dd2));
    return(len);
  }
  len = (sqrt(dd1)+sqrt(dd2)+4.0*sqrt(0.5*(dd1+dd2))) / 6.0;

  return(len);
}

double MMG_long_ani_init(double *ca,double *cb,double *sa,double *sb) {
  double   ux,uy,uz,dd1,dd2,len;

  ux = cb[0] - ca[0];
  uy = cb[1] - ca[1];
  uz = cb[2] - ca[2];

  dd1 =      sa[0]*ux*ux + sa[3]*uy*uy + sa[5]*uz*uz \
      + 2.0*(sa[1]*ux*uy + sa[2]*ux*uz + sa[4]*uy*uz);
  if ( dd1 <= 0.0 )  dd1 = 0.0;

  dd2 =      sb[0]*ux*ux + sb[3]*uy*uy + sb[5]*uz*uz \
      + 2.0*(sb[1]*ux*uy + sb[2]*ux*uz + sb[4]*uy*uz);
  if ( dd2 <= 0.0 )  dd2 = 0.0;
  
  len = (sqrt(dd1)+sqrt(dd2)+4.0*sqrt(0.5*(dd1+dd2))) / 6.0;

  return(len);
}

/* compute iso edge MMG_length */
double MMG_long_iso(double *ca,double *cb,double *ma,double *mb) {
  double   ux,uy,uz,dd,rap,len;
  double   sa,sb;

  sa   = *ma;
  sb   = *mb;
  
  ux = cb[0] - ca[0];
  uy = cb[1] - ca[1];
  uz = cb[2] - ca[2];
  dd = sqrt(ux*ux + uy*uy + uz*uz);

  rap = (sb - sa) / sa;
  if ( fabs(rap) < EPS1 )
    /*len = dd * (2.0-EPS1) / (2.0*sa);*/
    len = dd / sa;
  else
    /*len = max(dd/sa,dd/sb);*/
    len = dd * (1.0/sa + 1.0/sb + 8.0 / (sa+sb)) / 6.0;


  return(len);
}


/* print histo of edge lengths */
int MMG_prilen(pMesh mesh,pSol sol) {
  pTetra      pt;
  double      lavg,len,ecart,som,lmin,lmax,*ca,*cb,*ma,*mb;
  int         k,l,lon,navg,ia,ipa,ipb,iamin,ibmin,iamax,ibmax,dep,hl[10];
  int	      iadr;
  List        list;
  static double bd[9] = {0.0, 0.2, 0.5, 0.7071, 0.9, 1.111, 1.4142, 2.0, 5.0 };
  navg  = 0;
  lavg  = 0.0;
  lmin  = 1.e20;
  lmax  = 0.0;
  som   = 0.0;
  dep   = 1;
  iamin = 0;
  ibmin = 0;
  iamax = 0;
  ibmax = 0;

  for (k=1; k<10; k++)  hl[k] = 0;

  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;

    for (ia=0; ia<6; ia++) {
      lon = MMG_coquil(mesh,k,ia,&list);
      if ( lon < 2 )  continue;
      for (l=2; l<=lon; l++)
        if ( list.tetra[l] < 6*k )  break;

 	      if ( l <= lon )  continue;
        
        ipa = MMG_iare[ia][0];
        ipb = MMG_iare[ia][1];
        ca  = &mesh->point[pt->v[ipa]].c[0];
        cb  = &mesh->point[pt->v[ipb]].c[0];

        iadr = (pt->v[ipa]-1)*sol->offset + 1;
        ma   = &sol->met[iadr];
        iadr = (pt->v[ipb]-1)*sol->offset + 1;
        mb   = &sol->met[iadr];  
        if(sol->offset==6)
          len = MMG_long_ani_init(ca,cb,ma,mb);  
        else
          len = MMG_length(ca,cb,ma,mb);  
        navg++;
        ecart = len; 
        lavg += len;
        /* update efficiency index */
	      if ( ecart > 1.0 )  ecart = 1.0 / ecart; 

        som  += (ecart - 1.0); 
      
        /* find largest, smallest edge */
        if (len < lmin) {
	        lmin  = len;
		      iamin = pt->v[ipa];
		      ibmin = pt->v[ipb];
        }
        else if (len > lmax) {
		      lmax  = len;
          iamax = pt->v[ipa];
          ibmax = pt->v[ipb];
        }

        /* update histogram */
        if (len < bd[3]) {
		      if (len > bd[2])       hl[3]++;
		      else if (len > bd[1])  hl[2]++;
		      else                   hl[1]++;
        }
        else if (len < bd[5]) {
		      if (len > bd[4])       hl[5]++;
		      else if (len > bd[3])  hl[4]++;
        }
        else if (len < bd[6])    hl[6]++;
        else if (len < bd[7])    hl[7]++;
        else if (len < bd[8])    hl[8]++;
        else                     hl[9]++;
      }
      /*    /if ( dep < 0 )  break;*/
  }

  fprintf(stdout,"\n  -- RESULTING EDGE LENGTHS  %d\n",navg);
  fprintf(stdout,"     AVERAGE LENGTH         %12.4f\n",lavg / (double)navg);
  fprintf(stdout,"     SMALLEST EDGE LENGTH   %12.4f   %6d %6d\n",
  	  lmin,iamin,ibmin);
  fprintf(stdout,"     LARGEST  EDGE LENGTH   %12.4f   %6d %6d \n",
  	  lmax,iamax,ibmax);
  fprintf(stdout,"     EFFICIENCY INDEX       %12.4f\n",exp(som/(double)navg));
  if ( hl[4]+hl[5]+hl[6] )
    fprintf(stdout,"   %6.2f < L <%5.2f  %8d   %5.2f %%  \n",
      bd[3],bd[6],hl[4]+hl[5]+hl[6],100.*(hl[4]+hl[5]+hl[6])/(double)navg);

  if ( abs(mesh->info.imprim) > 4 ) {
    fprintf(stdout,"\n     HISTOGRAMM\n");
    if ( hl[1] )
      fprintf(stdout,"     0.00 < L < 0.20  %8d   %5.2f %%  \n",
	      hl[1],100.*(hl[1]/(float)navg));
    if ( lmax > 0.2 ) {
      for (k=2; k<9; k++) {
        if ( hl[k] > 0 )
  	  fprintf(stdout,"   %6.2f < L <%5.2f  %8d   %5.2f %%  \n",
		  bd[k-1],bd[k],hl[k],100.*(hl[k]/(float)navg));
      }
      if ( hl[9] )
        fprintf(stdout,"     5.   < L         %8d   %5.2f %%  \n",
	        hl[9],100.*(hl[9]/(float)navg));
    }
  }

  return(1);
}
