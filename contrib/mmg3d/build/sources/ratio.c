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
/*  
ratio = 
tet equi : 1. 
tet rect (1 1 sqrt(2)) : 3.73 vs 1.93 (avec sqrt(lmax/lmin))
tet rect (1 1/sqrt(2) 1/sqrt(2)) : 2.2413 vs 1.49
*/

#include "mesh.h"    

int MMG_gauss(double mat[6][6],double rhs[6],double* met);


/*compute the aniso ratio for an element k*/
double MMG_rao(pMesh mesh,int k,FILE* inm) {     
  pTetra		pt;
  pPoint		ppa,ppb;
  double		edg[6][3],mat[6][6],met[6],rhs[6];   
  double		lambda[3],v[3][3],lmin,lmax,rao;
//  double		bufd[GmfMaxTyp];
  int			i,j;
   
  pt = &mesh->tetra[k];
  
   /*compute the ellipsoide*/	  
  for (i=0 ; i<6 ; i++)
    rhs[i] = 1;
  
  for (i=0 ; i<6 ; i++) {
    ppa = &mesh->point[pt->v[MMG_iare[i][0]]];
    ppb = &mesh->point[pt->v[MMG_iare[i][1]]];
    for (j=0 ; j<3 ; j++) {
  	  edg[i][j] = ppb->c[j] - ppa->c[j];  
    }              
    mat[i][0] = edg[i][0]*edg[i][0];
    mat[i][1] = 2*edg[i][0]*edg[i][1];
    mat[i][2] = 2*edg[i][0]*edg[i][2];
    mat[i][3] = edg[i][1]*edg[i][1];
    mat[i][4] = 2*edg[i][1]*edg[i][2];
    mat[i][5] = edg[i][2]*edg[i][2];
  }	   
  MMG_gauss(mat,rhs,met);  
  
  /*find the eigenvalues of the metric*/	
  if ( !eigenv(1,met,lambda,v) ) {
    for (j=0 ; j<6 ; j++)
  	  printf("%e %e %e %e %e %e\n",mat[j][0],mat[j][1],mat[j][2],mat[j][3],mat[j][4],mat[j][5]);
  	  printf("\n met %e %e %e %e %e %e\n",met[0],met[1],met[2],met[3],met[4],met[5]);
  puts("pbs eigen"); 
     return(0);
  }
  /*calculate the aniso ratio obtained*/ 
  lmin = M_MIN(lambda[0],lambda[1]);
  lmin = M_MIN(lmin,lambda[2]);   
  lmax = M_MAX(lambda[0],lambda[1]);
  lmax = M_MAX(lmax,lambda[2]);
  rao  = sqrt(lmax / lmin);    
  if(inm) {
	  /*for (i=0; i<6; i++)
      bufd[i] = met[i];  

      bufd[2] = met[3];  
	    bufd[3] = met[2];*/  
		  fprintf(inm,"%.15lg \n",rao);
  }
	
  return(rao);	
}


int MMG_avgmet(pSol sol,pTetra pt,double* mm) {
  double	*ma,*mb,*mc,*md,h1,h2,h3,h4,h;
  int		ia,ib,ic,id,j,iadr;

  ia = pt->v[0];
  ib = pt->v[1];
  ic = pt->v[2];
  id = pt->v[3];
  
  if (sol->offset==1) {
	h1 = sol->met[ia];
	h2 = sol->met[ib];
	h3 = sol->met[ic];
	h4 = sol->met[id];
	h  = 0.25*(h1 + h2 + h3 + h4);
	mm[0] = h;	
	mm[1] = 0;	
	mm[2] = 0;	
	mm[3] = h;	
	mm[4] = 0;	
	mm[5] = h;	
  } else {
    
	/* average metric */
	memset(mm,0,6*sizeof(double));
	iadr = (ia-1)*sol->offset + 1;
	ma   = &sol->met[iadr];
	iadr = (ib-1)*sol->offset + 1;
	mb   = &sol->met[iadr];
	iadr = (ic-1)*sol->offset + 1;
	mc   = &sol->met[iadr];
	iadr = (id-1)*sol->offset + 1;
	md   = &sol->met[iadr];
	for (j=0; j<6; j++)
	  mm[j] = 0.25 * (ma[j]+mb[j]+mc[j]+md[j]);
	
  }	
	
  return(1);	
}

/* compute the prescribed and obtained anisotropic ratio
   print histo + save the ratio in a file
*/
int MMG_ratio(pMesh mesh, pSol sol,char* firaoame) {  
  FILE     *inm;
  pTetra		pt;
  double		met[6];   
  double		lambda[3],v[3][3],lmin,lmax,rao;
  int			  k,ne,typ;
  char			*ptr,data[128],chaine[128];  
  double    rapmin,rapmax,rapavg;
  int       his[10],rapnum;
  int       iel,ir,nn,nex,ielreal;
  static double bd[9] = {1.0, 2., 10.0, 50., 100., 200., 500., 1000., 5000. };

  /*save ratio obtained ?*/
  inm = 0;  
  if(firaoame) {
    strcpy(data,firaoame);
    ptr = strstr(data,".meshb");
    if ( ptr )  *ptr = '\0';
    else {
      ptr = strstr(data,".mesh");
      if ( ptr ) {
        *ptr = '\0';
      }
    }
    strcat(data,".sol");
    if( !(inm = fopen(data,"w")) ) {
      fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
      return(0);
    }
    else
      fprintf(stdout,"  %%%% %s OPENED\n",data);
  
    /*entete fichier*/
    strcpy(&chaine[0],"MeshVersionFormatted 2\n"); 
    fprintf(inm,"%s",chaine);
    strcpy(&chaine[0],"\n\nDimension 3\n"); 
    fprintf(inm,"%s ",chaine);

	  typ = 1;
    
	  ne = 0;    
    for(k=1 ; k<=mesh->ne ; k++) {
	    pt = &mesh->tetra[k];
	    if(!pt->v[0]) continue;
	    ne++;
    }
    strcpy(&chaine[0],"\n\nSolAtTetrahedra\n"); 
    fprintf(inm,"%s",chaine);
    fprintf(inm,"%d\n",ne);
    fprintf(inm,"%d %d\n",1,typ);
  
  }

  if ( abs(mesh->info.imprim) > 7 ) {

    /*ratio prescribed*/

    rapmin  =  1.e20;
    rapmax  = -1.e20;
    rapavg  = 0.0;
    rapnum  = 0;
    iel     = 0;
    ielreal = 0;
    nn      = 0;
    nex     = 0;

    for (k=0; k<10; k++)  his[k] = 0;

    for(k=1 ; k<=mesh->ne ; k++) {
	  pt = &mesh->tetra[k];
	  if(!pt->v[0]) {
        nex++;
        continue;
      }
      nn++;
	
	  /*mean metric*/
	  MMG_avgmet(sol,pt,met);
	
      /*find the eigenvalues of the prescribed metric*/	
	  if ( !eigenv(1,met,lambda,v) ) {
   	     puts("pbs eigen"); 
	     return(0);
      }

      /*calculate the aniso ratio */ 
	  lmin = M_MIN(lambda[0],lambda[1]);
	  lmin = M_MIN(lmin,lambda[2]);   
 	  lmax = M_MAX(lambda[0],lambda[1]);
	  lmax = M_MAX(lmax,lambda[2]);
	  rao  = sqrt(lmax / lmin);

	  /*histo prescribed*/  
	  ir   = (int)rao;  
	  if ( rao > rapmax ) {
        rapmax = rao; 
        iel     = k;
        ielreal = k - nex;
      }
      rapavg += rao;
      rapnum++;
      if ( rao < 17e10 ) {
        rapmin = M_MIN(rapmin,rao);
        if (rao < bd[3]) {
	      if (rao > bd[2])       his[3]++;
	      else if (rao > bd[1])  his[2]++;
	      else                   his[1]++;
        }
        else if (rao < bd[5]) {
	      if (rao > bd[4])       his[5]++;
	      else if (rao > bd[3])  his[4]++;
        }
        else if (rao < bd[6])    his[6]++;
        else if (rao < bd[7])    his[7]++;
        else if (rao < bd[8])    his[8]++;
        else                     his[9]++;
      }
    
    }  
    /* print histo ratio obtained*/
    fprintf(stdout,"\n  -- ANISOTROPIC RATIO PRESCRIBED   %d\n",rapnum);
    fprintf(stdout,"      AVERAGE RATIO       %12.4f\n",rapavg / rapnum);
    fprintf(stdout,"     SMALLEST RATIO       %12.4f\n",rapmin);  
    if (rapmax < 1.e4) {
      fprintf(stdout,"      LARGEST RATIO       %12.4f\n",rapmax);     
    } else {
	  fprintf(stdout,"      LARGEST RATIO       %12.4e\n",rapmax);     
    }
    pt = &mesh->tetra[iel];
    fprintf(stdout,"           ELEMENT   %d (%d)   %d %d %d %d\n",
        iel,ielreal,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);

    fprintf(stdout,"\n     HISTOGRAMM\n");
    for (k=1; k<9; k++) {
      if ( his[k] > 0 )
        fprintf(stdout,"   %8.2f < R <%8.2f  %8d   %5.2f %%  \n",
            	bd[k-1],bd[k],his[k],100.*(his[k]/(float)rapnum));
    }
    if ( his[9] )
      fprintf(stdout,"    5000.00 < R            %8d   %5.2f %%  \n",
        his[9],100.*(his[9]/(float)rapnum));

  }
  
  rapmin  =  1.e20;
  rapmax  = -1.e20;
  rapavg  = 0.0;
  rapnum  = 0;
  iel     = 0;
  ielreal = 0;
  nn      = 0;
  nex     = 0;

  for (k=0; k<10; k++)  his[k] = 0;

  for(k=1 ; k<=mesh->ne ; k++) {
	pt = &mesh->tetra[k];
	if(!pt->v[0]) {
      nex++;
      continue;
    }
    nn++;
	
	rao = MMG_rao(mesh,k,inm);
	  
    /*histo obtained*/  
	ir   = (int)rao;  
	if ( rao > rapmax ) {
      rapmax = rao; 
      iel     = k;
      ielreal = k - nex;
    }
    rapavg += rao;
    rapnum++;

    if ( rao < 17e10 ) {
      rapmin = M_MIN(rapmin,rao);
      if (rao < bd[3]) {
	    if (rao > bd[2])       his[3]++;
	    else if (rao > bd[1])  his[2]++;
	    else                   his[1]++;
      }
      else if (rao < bd[5]) {
	    if (rao > bd[4])       his[5]++;
	    else if (rao > bd[3])  his[4]++;
      }
      else if (rao < bd[6])    his[6]++;
      else if (rao < bd[7])    his[7]++;
      else if (rao < bd[8])    his[8]++;
      else                     his[9]++;
    }
    
  }

  if(inm) fclose(inm);
  
  /* print histo ratio obtained*/
  fprintf(stdout,"\n  -- ANISOTROPIC RATIO OBTAINED   %d\n",rapnum);
  fprintf(stdout,"      AVERAGE RATIO       %12.4f\n",rapavg / rapnum);
  fprintf(stdout,"     SMALLEST RATIO       %12.4f\n",rapmin);  
  if (rapmax < 1.e4) {
    fprintf(stdout,"      LARGEST RATIO       %12.4f\n",rapmax);     
  } else {
	fprintf(stdout,"      LARGEST RATIO       %12.4e\n",rapmax);     
  }
  pt = &mesh->tetra[iel];
  fprintf(stdout,"           ELEMENT   %d (%d)   %d %d %d %d\n",
	  iel,ielreal,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);

  if ( abs(mesh->info.imprim) < 5 )  return;

  fprintf(stdout,"\n     HISTOGRAMM\n");
  for (k=1; k<9; k++) {
    if ( his[k] > 0 )
      fprintf(stdout,"   %8.2f < R <%8.2f  %8d   %5.2f %%  \n",
      		bd[k-1],bd[k],his[k],100.*(his[k]/(float)rapnum));
  }
  if ( his[9] )
    fprintf(stdout,"    5000.00 < R            %8d   %5.2f %%  \n",
        his[9],100.*(his[9]/(float)rapnum));
  
  return(1);	
} 

/* solve mat*met = rhs */
int MMG_gauss(double mat[6][6],double rhs[6],double* met) {
  int i,j,l;  
  double tmp,piv; 
  /*printf("begin : \n");
  for (j=0 ; j<6 ; j++)
	  printf("%e %e %e %e %e %e\n",mat[j][0],mat[j][1],mat[j][2],mat[j][3],mat[j][4],mat[j][5]);
  */
  /* triangularisation*/  
  for (i=0 ; i<5 ; i++) {     
	l = i+1;         
    while ( (fabs(mat[i][i]) < 1e-8) && (l<6)){
	  for (j=0 ; j<6 ; j++) {     
		tmp = mat[i][j];
		mat[i][j] = mat[l][j];
		mat[l][j] = tmp;
	  }
	  tmp    = rhs[i];
	  rhs[i] = rhs[l];
	  rhs[l] = tmp;
	       
	  l++;
    }
	if ((fabs(mat[i][i]) < 1e-8)) {
	   //puts("WARNING PIV");
		met[0] = 1;
		met[1] = 0;
		met[2] = 0;
		met[3] = 1e7;
		met[4] = 10;
		met[5] = 1e7; 
		return(1);
	}	  	                                
    for (j=i+1 ; j<6 ; j++) { 
	  piv = mat[j][i];
	  for (l=0 ; l<6 ; l++) {     
 		mat[j][l] -= piv*mat[i][l] / mat[i][i];
	  }                                        
	  rhs[j] -= piv*rhs[i]/ mat[i][i];
    }
  }
  /*remontee*/
  met[5] = rhs[5] / mat[5][5];
  for(j=4 ; j>=0 ; j--){
	met[j] = rhs[j];
	for(l=j+1 ; l<6 ; l++) {
	  met[j] += -mat[j][l]*met[l];
	}
	met[j] /= mat[j][j];  
  }  

  return(1);
}
