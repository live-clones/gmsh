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

#define  LLAMBDA   0.33  /*0.33*/
#define  LMU       0.331   /*0.34*/

int MMG_optlap(pMesh mesh,pSol sol) {
  pTetra    pt,pt1;
  pPoint    ppt,pptb,ppta;
  pDispl    pdisp;
  List      list;
  int       it,i,k,lon,l,iel,ipt;
  int       maxiter,ipta,iptb,ipt0,ipt1,ipt2,ipt3;
  double    vol,ax,ay,az,bx,by,bz;
  double    *nv,res,dd,ox,oy,oz,declic;

  if(!mesh->disp) {
	  mesh->disp = (pDispl)M_calloc(1,sizeof(Displ),"MMG_zaldy.displ");
	  assert(mesh->disp);
	  mesh->disp->mv = (double*)M_calloc(3*(mesh->npmax + 1),sizeof(double),"MMG_zaldy.displ");
	  assert(mesh->disp->mv);
	  mesh->disp->alpha = (short*)M_calloc(mesh->npmax+1,sizeof(short),"MMG_zaldy.displ");
	  assert(mesh->disp->alpha);
  }
  maxiter = 3;  
  nv = (double*)M_calloc(mesh->np+1,3*sizeof(double),"movlap.nv");
  assert(nv);
  
  pdisp         = mesh->disp;	

  it  = 1;
  declic = 3./ALPHAD;
  do {
  
    /*initialisation*/
    for(i = 1 ; i<=mesh->np ; i++) {
      ppt          = &mesh->point[i];
      pdisp->alpha[i] = 0;
      pdisp->mv[3*(i-1) + 1 + 0] = 0.;
      pdisp->mv[3*(i-1) + 1 + 1] = 0.;
      pdisp->mv[3*(i-1) + 1 + 2] = 0.;
      
    }

    /*1st stage : laplacian*/    
    for(k = 1 ; k<=mesh->ne ; k++) {
      pt = &mesh->tetra[k];
      if (!pt->v[0]) continue;
      if (pt->qual > declic) continue;

      for(i=0 ; i<6 ; i++) {
        ipta   = pt->v[MMG_iare[i][0]];
        ppta   = &mesh->point[ipta];
        
		iptb   = pt->v[MMG_iare[i][1]];
        pptb   = &mesh->point[iptb];
	
		if(!(ppta->tag & M_BDRY)) {
	  		pdisp->mv[3*(ipta-1) + 1 + 0] += pptb->c[0];
	  		pdisp->mv[3*(ipta-1) + 1 + 1] += pptb->c[1];
	  		pdisp->mv[3*(ipta-1) + 1 + 2] += pptb->c[2];
	  		pdisp->alpha[ipta]++;
		}
		if(!(pptb->tag & M_BDRY)) {
	  		pdisp->mv[3*(iptb-1) + 1 + 0] += ppta->c[0];
	  		pdisp->mv[3*(iptb-1) + 1 + 1] += ppta->c[1];
	  		pdisp->mv[3*(iptb-1) + 1 + 2] += ppta->c[2];
	  		pdisp->alpha[iptb]++;
		}
      }
    }

    for(i=1 ; i<=mesh->np ; i++) {  
      ppt           = &mesh->point[i];
      if(pdisp->alpha[i]) {
        dd            = 1./(double) pdisp->alpha[i];
        pdisp->mv[3*(i-1) + 1 + 0] *= dd;
        pdisp->mv[3*(i-1) + 1 + 1] *= dd;
        pdisp->mv[3*(i-1) + 1 + 2] *= dd;
        nv[3*(i-1) + 1] = ppt->c[0] + LLAMBDA * (ppt->c[0] - pdisp->mv[3*(i-1) + 1 + 0]);
        nv[3*(i-1) + 2] = ppt->c[1] + LLAMBDA * (ppt->c[1] - pdisp->mv[3*(i-1) + 1 + 1]);
        nv[3*(i-1) + 3] = ppt->c[2] + LLAMBDA * (ppt->c[2] - pdisp->mv[3*(i-1) + 1 + 2]);
      } else {
        nv[3*(i-1) + 1] = ppt->c[0];
        nv[3*(i-1) + 2] = ppt->c[1];
        nv[3*(i-1) + 3] = ppt->c[2];
      
      }
      pdisp->alpha[i] = 0;
      pdisp->mv[3*(i-1) + 1 + 0] = 0.;
      pdisp->mv[3*(i-1) + 1 + 1] = 0.;
      pdisp->mv[3*(i-1) + 1 + 2] = 0.;
      
    }

    /*2nd stage : anti-laplacian*/
    for(k = 1 ; k<=mesh->ne ; k++) {
      pt = &mesh->tetra[k];
      if (!pt->v[0]) continue;
      if (pt->qual > declic) continue;
      
      for(i=0 ; i<6 ; i++) {
        ipta   = pt->v[MMG_iare[i][0]];
        ppta   = &mesh->point[ipta];
       
    	iptb   = pt->v[MMG_iare[i][1]];
        pptb   = &mesh->point[iptb];
	
	if(!(ppta->tag & M_BDRY)) {
	  pdisp->mv[3*(ipta-1) + 1 + 0] += nv[3*(iptb-1) + 1];
	  pdisp->mv[3*(ipta-1) + 1 + 1] += nv[3*(iptb-1) + 2];
	  pdisp->mv[3*(ipta-1) + 1 + 2] += nv[3*(iptb-1) + 3];
	  pdisp->alpha[ipta]++;
	}
	if(!(pptb->tag & M_BDRY)) {
	  pdisp->mv[3*(iptb-1) + 1 + 0] += nv[3*(ipta-1) + 1];
	  pdisp->mv[3*(iptb-1) + 1 + 1] += nv[3*(ipta-1) + 2];
	  pdisp->mv[3*(iptb-1) + 1 + 2] += nv[3*(ipta-1) + 3];
	  pdisp->alpha[iptb]++;
	}
      }
    }
    
    res= 0.;
    for(i=1 ; i<=mesh->np ; i++) {  
      ppt           = &mesh->point[i];
      if(pdisp->alpha[i]) {
        dd            = 1./(double) pdisp->alpha[i];
        pdisp->mv[3*(i-1) + 1 + 0] *= dd;
        pdisp->mv[3*(i-1) + 1 + 1] *= dd;
        pdisp->mv[3*(i-1) + 1 + 2] *= dd;
        ox = nv[3*(i-1) + 1];
        oy = nv[3*(i-1) + 2];
        oz = nv[3*(i-1) + 3];
        nv[3*(i-1) + 1] = nv[3*(i-1) + 1] - LMU * (nv[3*(i-1) + 1] - pdisp->mv[3*(i-1) + 1 + 0]);
        nv[3*(i-1) + 2] = nv[3*(i-1) + 2] - LMU * (nv[3*(i-1) + 2] - pdisp->mv[3*(i-1) + 1 + 1]);
        nv[3*(i-1) + 3] = nv[3*(i-1) + 3] - LMU * (nv[3*(i-1) + 3] - pdisp->mv[3*(i-1) + 1 + 2]);
	
        dd = (nv[3*(i-1) + 1]-ox)*(nv[3*(i-1) + 1]-ox) 
           + (nv[3*(i-1) + 2]-oy)*(nv[3*(i-1) + 2]-oy)
	   + (nv[3*(i-1) + 3]-oz)*(nv[3*(i-1) + 3]-oz);
        res +=dd;     
      
      } 
      
      
      pdisp->alpha[i] = 0;
      pdisp->mv[3*(i-1) + 1 + 0] = 0.;
      pdisp->mv[3*(i-1) + 1 + 1] = 0.;
      pdisp->mv[3*(i-1) + 1 + 2] = 0.;
    }    
/*    printf("---------- iter %d  res %e\r",it,res);
    fflush(stdout); 
*/    
    /*check new coor*/
    for(k = 1 ; k<=mesh->ne ; k++) {
      pt = &mesh->tetra[k];
      if(!pt->v[0]) continue;
      
      for(i=0 ; i<4 ; i++) {
        ipt   = pt->v[i];
        ppt   = &mesh->point[ipt];
    	if(ppt->tag & M_BDRY) continue;
	    if(ppt->tmp2) continue;
	    ppt->tmp2 = 1;
	    lon = MMG_boulep(mesh,k,i,&list);
        for (l=1; l<=lon; l++) {
          iel    = list.tetra[l] >> 2;
          pt1    = &mesh->tetra[iel];
	      ipt0   = 3*(pt1->v[0] - 1);
	      ipt1   = 3*(pt1->v[1] - 1);
	      ipt2   = 3*(pt1->v[2] - 1);
	      ipt3   = 3*(pt1->v[3] - 1);
	  
          ax = nv[ipt2 + 1] - nv[ipt0 + 1];
          ay = nv[ipt2 + 2] - nv[ipt0 + 2];
          az = nv[ipt2 + 3] - nv[ipt0 + 3];
  
          bx = nv[ipt3 + 1] - nv[ipt0 + 1];
          by = nv[ipt3 + 2] - nv[ipt0 + 2];
          bz = nv[ipt3 + 3] - nv[ipt0 + 3];
  
          vol = (nv[ipt1 + 1] - nv[ipt0 + 1]) * (ay*bz - az*by) \
              + (nv[ipt1 + 2] - nv[ipt0 + 2]) * (az*bx - ax*bz) \
              + (nv[ipt1 + 3] - nv[ipt0 + 3]) * (ax*by - ay*bx);
          if(vol < 0) {/*printf("reject1 %e\n",vol);*/break;}
        }
	if(l<=lon) {
	  memcpy(&pdisp->mv[3*(ipt-1) + 1],ppt->c,3*sizeof(double));
          for (l=1; l<=lon; l++) {
            iel    = list.tetra[l] >> 2;
            pt1    = &mesh->tetra[iel];
	    ipt0   = 3*(pt1->v[0] - 1);
	    ipt1   = 3*(pt1->v[1] - 1);
	    ipt2   = 3*(pt1->v[2] - 1);
	    ipt3   = 3*(pt1->v[3] - 1);
	  
            ax = nv[ipt2 + 1] - nv[ipt0 + 1];
            ay = nv[ipt2 + 2] - nv[ipt0 + 2];
            az = nv[ipt2 + 3] - nv[ipt0 + 3];
  
            bx = nv[ipt3 + 1] - nv[ipt0 + 1];
            by = nv[ipt3 + 2] - nv[ipt0 + 2];
            bz = nv[ipt3 + 3] - nv[ipt0 + 3];
  
            vol = (nv[ipt1 + 1] - nv[ipt0 + 1]) * (ay*bz - az*by) \
                + (nv[ipt1 + 2] - nv[ipt0 + 2]) * (az*bx - ax*bz) \
                + (nv[ipt1 + 3] - nv[ipt0 + 3]) * (ax*by - ay*bx);
            if(vol < 0) {/*printf("reject %e\n",vol);*/break;}
          }
	  if(l<=lon) break;
	}
      }
      if(i<4) break;
    }  
    if(k > mesh->ne) { 
      /*update coor*/
      for(i=1 ; i<=mesh->np ; i++) {
        ppt   = &mesh->point[i];
        ppt->c[0] = nv[3*(i-1) + 1];
        ppt->c[1] = nv[3*(i-1) + 2];
        ppt->c[2] = nv[3*(i-1) + 3];
      }
      for(k=1 ; k<=mesh->ne ; k++) {
        pt = &mesh->tetra[k];
	if(!pt->v[0]) continue;
	pt->qual = MMG_caltet(mesh,sol,k);
      }
      if(mesh->info.imprim < 0) fprintf(stdout,"              LAPLACIAN : %8f\n",res);      
    } else {     
      if(mesh->info.imprim < 0) fprintf(stdout,"              NO LAPLACIAN\n");
      break;
    }
    if(res<1e-5) break;
   
  } while(it++ < maxiter);

  M_free(nv);
  return(1);
}
