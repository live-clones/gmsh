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

/* print mesh quality histo */
int MMG_outqua(pMesh mesh,pSol sol) {
  pTetra    pt;
  double    coef,rap4,rapl,rapmin,rapmax,rapavg,dcal;
  int       his10[11],his01[33],rapnum,iout;
  int       k,i,j,imax,iel,ir,nn,nex,ielreal,tmp;
  
  iout = 0;
  
  if(mesh->info.imprim < 0) MMG_priworst(mesh,sol);
  
  rapmin  =  1.e20;
  rapmax  = -1.e20;
  rapavg  = 0.0;
  rapnum  = 0;
  iel     = 0;
  ielreal = 0;
  nn      = 0;

  for (k=0; k<=32; k++)  his01[k] = 0;
  for (k=0; k<=10; k++)  his10[k] = 0;

  coef = ALPHAD;
  nex  = 0;
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if( !pt->v[0] ) {
      nex++;
      continue;
    }
    nn++;     
    dcal = MMG_caltet(mesh,sol,k);//(sol->offset==6) ? MMG_caltet_ani(mesh,sol,k) : MMG_caltet_iso(mesh,sol,k);             
    rap4 = coef * dcal; 
    if(dcal == CALLIM) {
      //printf("Wrong elt %d : %d %d %d %d (qual %e %e)\n",k,pt->v[0],pt->v[1],pt->v[2],pt->v[3],rap4,MMG_voltet(mesh,k));
      tmp = pt->v[2];
      pt->v[2] = pt->v[3];
      pt->v[3] = tmp;
      dcal = MMG_caltet(mesh,sol,k);//(sol->offset==6) ? MMG_caltet_ani(mesh,sol,k) : MMG_caltet_iso(mesh,sol,k);             
      rap4 = coef * dcal; 
      if(dcal == CALLIM) {
        printf("Wrong elt %d : %d %d %d %d (qual %e (%e) %13.12f)\n",k,pt->v[0],pt->v[1],pt->v[2],pt->v[3],rap4,rap4/coef,MMG_voltet(mesh,k));
        printf("vextex 0 : %e %e %e\n",mesh->point[pt->v[0]].c[0],mesh->point[pt->v[0]].c[1],mesh->point[pt->v[0]].c[2]);
        printf("vextex 1 : %e %e %e\n",mesh->point[pt->v[1]].c[0],mesh->point[pt->v[1]].c[1],mesh->point[pt->v[1]].c[2]);
        printf("vextex 2 : %e %e %e\n",mesh->point[pt->v[2]].c[0],mesh->point[pt->v[2]].c[1],mesh->point[pt->v[2]].c[2]);
        printf("vextex 3 : %e %e %e\n",mesh->point[pt->v[3]].c[0],mesh->point[pt->v[3]].c[1],mesh->point[pt->v[3]].c[2]);
        //MMG_saveMesh(mesh,"titi.mesh");
        //exit(0); 
        iout += 1;
      }
			if(abs(mesh->info.imprim) > 5) printf("reorient tet %d\n",k);
      //iout += 1;
    }
    //rap4 = M_MIN(rap4,1.0e9);
    ir   = (int)rap4;
    if ( rap4 > rapmax ) {
      rapmax = rap4; 
      iel     = k;
      ielreal = k - nex;
    }
    rapavg += rap4; 
    rapnum++;

    if ( rap4 > 1.0 && rap4 < 17e10 ) {
      rapmin = M_MIN(rapmin,rap4);
      if ( rap4 < 10.0 ) {
        his10[ir] += 1;
	    his01[0]  += 1;
      }
      else if ( rap4 < 17e10 ) {
        rapl = M_MIN(log10(rap4),32.0);
        his01[(int)rapl] += 1;
	    his01[0]  += 1;
      } 
    }
  }

  /* print histo */
  //EMI if(mesh->info.imprim < 0) { 
  fprintf(stdout,"\n  -- MESH QUALITY   %d \n",rapnum);
  if ( (rapavg > 0) && (rapavg / rapnum < 100.0) )
    fprintf(stdout,"     AVERAGE QUALITY        %12.4f\n",rapavg / rapnum);
  fprintf(stdout,"     BEST  ELEMENT QUALITY  %12.4f\n",rapmin);
  if ( rapmax < 1.e7 )
    fprintf(stdout,"     WORST ELEMENT QUALITY  %12.4f\n",rapmax);
  else
    fprintf(stdout,"     WORST ELEMENT QUALITY  %12.4E\n",rapmax);
  pt = &mesh->tetra[iel];
  fprintf(stdout,"     WORST ELEMENT   %d (%d)   %d %d %d %d\n",
	  iel,ielreal,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);

  //EMI if ( abs(mesh->info.imprim) < 5 )  return(0);

  fprintf(stdout,"\n     HISTOGRAMM\n");
  j = 0;
  for (i=1; i<32; i++)
    j += his01[i];

  if(rapmax > 1e+9) 
    imax = 9;
  else 
    imax = M_MIN((int)rapmax,9);  
    
  for (i=M_MAX((int)rapmin,1); i<=imax; i++) {
    fprintf(stdout,"     %5d < Q < %5d   %7d   %6.2f %%\n",
	    i,i+1,his10[i],100.*(his10[i]/(float)his01[0]));
  }

  /* quality per interval */
  if (j != 0) { 
    fprintf(stdout,"\n");
    imax = (int)(M_MIN(3,log10(rapmax)));

    for (i=1; i<=imax; i++) {
      fprintf(stdout,"     %5.0f < Q < %5.0f   %7d   %6.2f %%\n",
	      pow(10.,i),pow(10.,i+1),his01[i],100.*(his01[i]/(float)his01[0]));
    }
    for (i=4; i<=(int)log10(rapmax); i++) {
      fprintf(stdout,"    10**%2d < Q < 10**%2d  %7d   %6.2f %%\n",
	      i,i+1,his01[i],100.*(his01[i]/(float)his01[0]));
    }
    }

  //}

  return(iout);
}

double MMG_priworst(pMesh mesh, pSol sol) { 
  pTetra pt;
  int    k,nbad,nreal,nex;
  double bad;
  
  /*worst quality*/
  bad   = 1.;
  nbad  = 0; 
  nex   = 0;
  nreal = 0;
  for(k=1 ; k<=mesh->ne ; k++) {
    pt = &mesh->tetra[k];
    if(!pt->v[0]) {
      nex++;
      continue;
    }
    if( pt->qual > bad) {
      bad   = pt->qual;
      nbad  = k - nex;
      nreal = k;
    }
  }   
  
  if(nreal) printf("     worst quality %d (%d): %e %e\n",nreal,nbad,bad*ALPHAD,ALPHAC*MMG_calte1(mesh,sol,nreal));

  return((&mesh->tetra[nreal])->qual);
}
/* print mesh quality histo */
int MMG_outquacubic(pMesh mesh,pSol sol) {
  pTetra    pt;
  double    rapmin,rapmax,rapavg,dcal,som;
  int       his10[11],his01[5],rapnum,iout;
  int       k,i,j,iel,ir,nn,nex,ielreal,hismin;
  
  iout = 0;
    
  rapmin  = 0.;
  rapmax  = 1.;
  rapavg  = 0.0;
  rapnum  = 0;
  iel     = 0;
  ielreal = 0;
  nn      = 0;

  for (k=0; k<=5; k++)  his01[k] = 0;
  for (k=0; k<=10; k++)  his10[k] = 0;

  nex  = 0;
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if( !pt->v[0] ) {
      nex++;
      continue;
    }
    nn++;     
    dcal = MMG_caltetcubic(mesh,sol,k); 
    if(dcal > 1) {
      //printf("argggggg %d %e %e\n",k,dcal,MMG_caltet(mesh,sol,k)*ALPHAD);
      dcal = 1.;
    }   
    if(dcal == 0.) {
      printf("Wrong elt %d (qual %e)\n",k,dcal);
      iout += 1;
    }
    ir   = (int)(dcal*10);
    if ( dcal < rapmax ) {
      rapmax = dcal;  
      iel     = k;
      ielreal = k - nex;
    }
    rapavg += dcal;
    rapnum++;

    if ( dcal <= 1.0 && dcal >= 1e-12 ) {
      rapmin = M_MAX(rapmin,dcal);
      if ( dcal > 0.1 ) {
        his10[ir] += 1;
	    his01[0]  += 1;
      }
      else if ( dcal > 1e-12 ) {   
        if(dcal > 0.01) {
          his01[1] += 1;
        } else if  (dcal > 0.001) {
          his01[2] += 1;
        } else if  (dcal > 0.0001) {
          his01[3] += 1;
        } else 
          his01[4] += 1;
	    his01[0]  += 1;
      } 
    }
  }

  /* print histo */
  fprintf(stdout,"\n  -- MESH QUALITY (CUBIC)  %d\n",rapnum);
  if ( rapavg / rapnum > 0.1 )
    fprintf(stdout,"     AVERAGE QUALITY        %12.4f\n",rapavg / rapnum);
  fprintf(stdout,"     BEST  ELEMENT QUALITY  %12.4f\n",rapmin);
  if ( rapmin > 1.e-6 )
    fprintf(stdout,"     WORST ELEMENT QUALITY  %12.4f\n",rapmax);
  else
    fprintf(stdout,"     WORST ELEMENT QUALITY  %12.4E\n",rapmax);
  pt = &mesh->tetra[iel];
  fprintf(stdout,"     WORST ELEMENT   %d (%d)   %d %d %d %d\n",
	  iel,ielreal,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);

  if ( abs(mesh->info.imprim) < 5 )  return(0);

  fprintf(stdout,"\n     HISTOGRAMM\n");
  j = 0;
  for (i=1; i<4; i++)
    j += his01[i];
  hismin = M_MIN((int)(rapmin*10),1);  
  som = 0;   
  if( hismin == 1) { 
    fprintf(stdout,"     0.9   < Q <   1.0   %7d   %6.2f %%\n",
        his10[9]+his10[10],100.*((his10[9]+his10[10])/(float)his01[0]));
    hismin = 9;                          
    som += 100.*((his10[9]+his10[10])/(float)his01[0]);
  }
  for (i=hismin; i>M_MAX((int)(rapmax*10),1); i--) {
    fprintf(stdout,"     0.%d   < Q <   0.%d   %7d   %6.2f %%\n",
	    i-1,i,his10[i-1],100.*(his10[i-1]/(float)his01[0])); 
	som += 100.*(his10[i-1]/(float)his01[0]);        
  } 

  /* quality per interval */
  if (j != 0) {
    fprintf(stdout,"\n"); 
    j -= his01[1];
    if(his01[1]!=0)
      fprintf(stdout,"     0.01   < Q <  0.1   %7d   %6.2f %%\n",
	      his01[1],100.*(his01[1]/(float)his01[0]));
    if(j!=0)
      fprintf(stdout,"     0.001  < Q <  0.01  %7d   %6.2f %%\n",
  	    his01[2],100.*(his01[1]/(float)his01[0]));    
    j -= his01[2];
    if(j!=0)
      fprintf(stdout,"     0.0001 < Q <  0.001 %7d   %6.2f %%\n",
  	    his01[3],100.*(his01[1]/(float)his01[0]));
    j -= his01[3];
    if(j!=0)
        fprintf(stdout,"     0.     < Q    %7d   %6.2f %%\n",
  	      his01[4],100.*(his01[1]/(float)his01[0]));
   }
  return(iout);
}
