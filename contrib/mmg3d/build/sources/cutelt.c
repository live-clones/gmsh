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

int MMG_cutadd(pMesh mesh,pHedge hed,int icas,int k,int p0,int p1,int p2,int p3,int p4,int p5, int ref) {
	pTetra		pt;
	pPoint		ppt,pp0,pp1,pp2,pp3,pp4,pp5;

	pp0 = &mesh->point[p0];
	pp1 = &mesh->point[p1];
	pp2 = &mesh->point[p2];
	pp3 = &mesh->point[p3];
	pp4 = &mesh->point[p4];
	pp5 = &mesh->point[p5];
	mesh->np++;
	ppt = &mesh->point[mesh->np]; 
	ppt->c[2] = (1./6.)*(pp0->c[2]+pp1->c[2]+pp2->c[2]+pp3->c[2]+pp4->c[2]+pp5->c[2]);
	ppt->c[1] = (1./6.)*(pp0->c[1]+pp1->c[1]+pp2->c[1]+pp3->c[1]+pp4->c[1]+pp5->c[1]);
	ppt->c[0] = (1./6.)*(pp0->c[0]+pp1->c[0]+pp2->c[0]+pp3->c[0]+pp4->c[0]+pp5->c[0]);
	ppt->ref = pp0->ref;
	//printf("prisme : %d %d %d %d %d %d + %d\n",p0,p1,p2,p3,p4,p5,mesh->np);
	if(icas & 1) {
		//printf("icas %d --> 0 ?\n",icas);
		pt = &mesh->tetra[k + 1];
	  pt->v[0] = p0;
    pt->v[1] = p4;
	  pt->v[2] = p3;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
		pt = &mesh->tetra[k + 2];
	  pt->v[0] = p0;
    pt->v[1] = p1;
	  pt->v[2] = p4;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
	} else {
		if(icas & 4) {
			//printf("icas %d --> 2 ?\n",icas);
			
		} else {
			MMG_edgePut(hed,p1,p3,2);
		}   
		pt = &mesh->tetra[k + 1];
	  pt->v[0] = p0;
    pt->v[1] = p1;
	  pt->v[2] = p3;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
		pt = &mesh->tetra[k + 2];
	  pt->v[0] = p1;
    pt->v[1] = p4;
	  pt->v[2] = p3;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;		
	}
	
	if(icas & 8) {
		//printf("icas %d --> 3 ?\n",icas);
		pt = &mesh->tetra[k + 3];
	  pt->v[0] = p1;
    pt->v[1] = p2;
	  pt->v[2] = p5;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
		pt = &mesh->tetra[k + 4];
	  pt->v[0] = p1;
    pt->v[1] = p5;
	  pt->v[2] = p4;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
	} else {
		if(icas & 32) {
			//printf("icas %d --> 5 ?\n",icas);
			
		} else {
			MMG_edgePut(hed,p2,p4,2);
		}   
		pt = &mesh->tetra[k + 3];
	  pt->v[0] = p1;
    pt->v[1] = p2;
	  pt->v[2] = p4;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
		pt = &mesh->tetra[k + 4];
	  pt->v[0] = p4;
    pt->v[1] = p2;
	  pt->v[2] = p5;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;		
	}

	if(icas & 2) {
		//printf("icas %d --> 1 ?\n",icas);
		pt = &mesh->tetra[k + 5];
	  pt->v[0] = p0;
    pt->v[1] = p5;
	  pt->v[2] = p3;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
		pt = &mesh->tetra[k + 6];
	  pt->v[0] = p0;
    pt->v[1] = p5;
	  pt->v[2] = p2;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
	} else {
		if(icas & 16) {
			//printf("icas %d --> 4 ?\n",icas);
			
		} else {
			MMG_edgePut(hed,p2,p3,2);
		}   
		pt = &mesh->tetra[k + 5];
	  pt->v[0] = p0;
    pt->v[1] = p2;
	  pt->v[2] = p3;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;
		pt = &mesh->tetra[k + 6];
	  pt->v[0] = p2;
    pt->v[1] = p3;
	  pt->v[2] = p5;
	  pt->v[3] = mesh->np;
	  pt->ref  = ref;		
	}

	pt = &mesh->tetra[k + 7];
  pt->v[0] = p3;
  pt->v[1] = p4;
  pt->v[2] = p5;
  pt->v[3] = mesh->np;
  pt->ref  = ref;
	pt = &mesh->tetra[k + 8];
  pt->v[0] = p0;
  pt->v[1] = p1;
  pt->v[2] = p2;
  pt->v[3] = mesh->np;
  pt->ref  = ref;		
	
	return(1);
}           

int MMG_cuthex(pMesh mesh,pHedge hed,int k,int p0,int p1,int p2,int p3,int p4,int p5,int p6,int p7, int ref) { 
	pTetra		pt;
	int				i,nu1,nu2;
	
	
	pt = &mesh->tetra[k+1];
  pt->v[0] = p0;
  pt->v[1] = p1;
  pt->v[2] = p3;
  pt->v[3] = p7;
  pt->ref  = ref;
	for(i=0 ; i<6 ; i++) {
		nu1 = pt->v[MMG_iare[i][0]];
		nu2 = pt->v[MMG_iare[i][1]];
		MMG_edgePut(hed,nu1,nu2,2);
	}
  //if((netmp+(k-1)*6+1 ) == 2924) printf("i) %d tet %d %d %d %d\n",k,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
  pt = &mesh->tetra[k+2];
  pt->v[0] = p7;
  pt->v[1] = p2;
  pt->v[2] = p1;
  pt->v[3] = p6;
  pt->ref  = ref;
	for(i=0 ; i<6 ; i++) {
		nu1 = pt->v[MMG_iare[i][0]];
		nu2 = pt->v[MMG_iare[i][1]];
		MMG_edgePut(hed,nu1,nu2,2);
	}
  //if((netmp+(k-1)*6+1 + 1) == 2924) printf("ii) tet %d %d %d %d\n",pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
  pt = &mesh->tetra[k+3];  
  pt->v[0] = p1;
  pt->v[1] = p4;
  pt->v[2] = p5;
  pt->v[3] = p7; 
	for(i=0 ; i<6 ; i++) {
		nu1 = pt->v[MMG_iare[i][0]];
		nu2 = pt->v[MMG_iare[i][1]];
		MMG_edgePut(hed,nu1,nu2,2);
	}
  //if((netmp+(k-1)*6+1 + 2) == 2924) printf("iii) tet %d %d %d %d\n",pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
  pt->ref  = ref;
  pt = &mesh->tetra[k+4];
  pt->v[0] = p7;
  pt->v[1] = p4;
  pt->v[2] = p0;
  pt->v[3] = p1;
  pt->ref  = ref;
	for(i=0 ; i<6 ; i++) {
		nu1 = pt->v[MMG_iare[i][0]];
		nu2 = pt->v[MMG_iare[i][1]];
		MMG_edgePut(hed,nu1,nu2,2);
	}
  //if((netmp+(k-1)*6+1 + 3) == 2924) printf("iv) tet %d %d %d %d\n",pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
  pt = &mesh->tetra[k+5];
  pt->v[0] = p1;
  pt->v[1] = p6;
  pt->v[2] = p7;
  pt->v[3] = p5;
  pt->ref  = ref;
	for(i=0 ; i<6 ; i++) {
		nu1 = pt->v[MMG_iare[i][0]];
		nu2 = pt->v[MMG_iare[i][1]];
		MMG_edgePut(hed,nu1,nu2,2);
	}
  pt = &mesh->tetra[k+6];
  pt->v[0] = p1;
  pt->v[1] = p3;
  pt->v[2] = p2;
  pt->v[3] = p7;
  pt->ref  = ref;
	for(i=0 ; i<6 ; i++) {
		nu1 = pt->v[MMG_iare[i][0]];
		nu2 = pt->v[MMG_iare[i][1]];
		MMG_edgePut(hed,nu1,nu2,2);
	}
	return(1);
}

int MMG_cutprism(pMesh mesh,pHedge hed,int k,int p0,int p1,int p2,int p3,int p4,int p5,int ref) {
	pTetra 	pt;  
	double	vol;
	int			t0,t1,t2;
	char   	icas; 
	int ddebug;
 
	vol= MMG_quickvol(mesh->point[p0].c,mesh->point[p1].c,mesh->point[p2].c,mesh->point[p3].c);  
	if(vol<0) {
		printf("inversion"); 
		t0 = p0;
		t1 = p1;
		t2 = p2;
		p0 = p3;
		p1 = p4;
		p2 = p5;
		p3 = t0;
		p4 = t1;
		p5 = t2;
	} 
	if(k==606 || k==605 || k==604 || k==609 || k==608 || k==607) ddebug=1; 
	else ddebug=0; 
	ddebug=0;
	if(ddebug) printf("k = %d : %d %d %d %d %d %d\n",k,p0,p1,p2,p3,p4,p5,p5);      
	
	icas = 0;

	//find edge 2 : p1-p3 then edge 0 : 0 4
	if(!MMG_edgePoint(hed,p1,p3)) {
		if(MMG_edgePoint(hed,p0,p4))
			icas |= 1;
	} else {
		icas |= 4;
	}
	//find edge 5 : p2-p4 then edge 3 : 1 5
	if(!MMG_edgePoint(hed,p2,p4)) {
		if(MMG_edgePoint(hed,p1,p5))
			icas |= 8;
	} else {
		icas |= 32;
	}
	//find edge 4 : p2-p3 then edge 1 : 0 5
	if(!MMG_edgePoint(hed,p2,p3)) {
		if(MMG_edgePoint(hed,p0,p5))
		icas |= 2;
	} else {
		icas |= 16;
	}
	if(icas > 55) {
		fprintf(stdout,"grosgros bug %d\n",icas);
		exit(0);
	} 
	if(ddebug) printf("on trouve %d\n",icas);
	
	switch(icas) {
		case 0: 
		  if(ddebug) printf("on rajoute %d %d -- %d %d -- %d %d\n",p0,p4,p1,p5,p0,p5);
	    MMG_edgePut(hed,p2,p4,2);
	    MMG_edgePut(hed,p1,p3,2);
	    MMG_edgePut(hed,p3,p2,2);//MMG_edgePut(hed,p2,p3,2);
		  icas = 52;
	    break;
		case 1:
		  MMG_edgePut(hed,p1,p5,2);
		  MMG_edgePut(hed,p0,p5,2);
			icas = 11;//25;
		  break;
		case 2:
	    MMG_edgePut(hed,p1,p5,2);
	    MMG_edgePut(hed,p0,p4,2);
	    icas = 11;//14
	    break;
		case 3:
		  MMG_edgePut(hed,p1,p5,2);
			icas = 11;//35;
		  break;
		case 4:
	    MMG_edgePut(hed,p2,p4,2);//MMG_edgePut(hed,p1,p5,2);
		  MMG_edgePut(hed,p2,p3,2);//MMG_edgePut(hed,p0,p5,2);
			icas = 52;//14;
		  break;
		case 6:
		  MMG_edgePut(hed,p1,p5,2);
		  icas = 14;
		  break;
		case 8:
		  MMG_edgePut(hed,p0,p5,2);
		  MMG_edgePut(hed,p0,p4,2);
			icas = 11;//14;
		  break;
		case 9:
		  MMG_edgePut(hed,p0,p5,2);
			icas = 11;//25;
		  break;
		case 10:
		  MMG_edgePut(hed,p0,p4,2);
			icas = 11;//14;
		  break;
		case 12:
		  MMG_edgePut(hed,p0,p5,2);
		  icas = 14;
		  break;
		case 16:
		  MMG_edgePut(hed,p2,p4,2);//MMG_edgePut(hed,p1,p5,2);
		  MMG_edgePut(hed,p3,p1,2);//MMG_edgePut(hed,p1,p3,2);
			icas = 52;//28;
		  break;
		case 17:
		  MMG_edgePut(hed,p4,p2,2); 
			icas = 49;//25;
		  break;
		case 20:
		  MMG_edgePut(hed,p2,p4,2);    //MMG_edgePut(hed,p1,p5,2);
			icas = 52;//28;
		  break;
	  case 24:
	    MMG_edgePut(hed,p1,p3,2);
			icas = 28;//25;
	    break;
		case 32:
		  MMG_edgePut(hed,p1,p3,2);//MMG_edgePut(hed,p0,p4,2);
		  MMG_edgePut(hed,p2,p3,2);//MMG_edgePut(hed,p0,p5,2); 
			icas = 52;//35;
		  break;
		case 33:
		  MMG_edgePut(hed,p0,p5,2);
		  icas = 35;
		  break;
		case 34:
		  MMG_edgePut(hed,p0,p4,2);
		  icas = 35;
		  break;
		case 36:
		  MMG_edgePut(hed,p3,p2,2);
		  icas = 52;
		  break;
		case 48:
		  MMG_edgePut(hed,p1,p3,2);//MMG_edgePut(hed,p0,p4,2);
			icas = 52;//49;
		  break;
		default:
			//5,7,11,13,15,18,19,21,22,23,26,27,29,30,31,37,39,40,41,42,43,44,45,46,47,50,51,52,53,54,55: 
		  //printf("icas imposssss %d\n",icas);
		  //exit(0);
		  break;
		    
	} 
	if(ddebug) printf("du coup %d\n",icas);
	switch(icas) {
	  case 14: 
		  pt = &mesh->tetra[k + 1];
		  pt->v[0] = p5;
	    pt->v[1] = p1;
		  pt->v[2] = p2;
		  pt->v[3] = p0;
		  pt->ref  = ref;//1;//ref;
	    pt = &mesh->tetra[k + 2];
	    pt->v[0] = p3;
		  pt->v[1] = p5;
		  pt->v[2] = p1;
		  pt->v[3] = p0;
		  pt->ref  = ref;//1;//ref;
	    pt = &mesh->tetra[k + 3];
	    pt->v[0] = p3;
	    pt->v[1] = p4;
		  pt->v[2] = p1;
		  pt->v[3] = p5;  
			pt->ref  = ref;//1;//ref;
		  break;
	  case 11://25:    //D3  --> bug!     
		if(ddebug) printf("on create %d %d %d %d -- %d %d %d %d -- %d %d %d %d\n",p0,p4,p3,p5,p0,p1,p4,p5,p5,p1,p2,p0);
	   	pt = &mesh->tetra[k + 1];
			pt->v[0] = p0;
		  pt->v[1] = p4;
			pt->v[2] = p3;
			pt->v[3] = p5;
			pt->ref  = ref;//3;//ref;
		  pt = &mesh->tetra[k + 2];
		  pt->v[0] = p0;
			pt->v[1] = p1;
			pt->v[2] = p4;
			pt->v[3] = p5;
			pt->ref  = ref;//3;//ref;
		  pt = &mesh->tetra[k + 3];
		  pt->v[0] = p5;
		  pt->v[1] = p1;
			pt->v[2] = p2;
			pt->v[3] = p0;
			pt->ref  = ref;//3;//ref;
			break;
		case 28:    //D2
		 	pt = &mesh->tetra[k + 1];
			pt->v[0] = p4;
		  pt->v[1] = p5;
			pt->v[2] = p1;
			pt->v[3] = p3;
			pt->ref  = ref;//2;//ref;
		  pt = &mesh->tetra[k + 2];
		  pt->v[0] = p1;
			pt->v[1] = p2;
			pt->v[2] = p5;
			pt->v[3] = p3;
			pt->ref  = ref;//2;//ref;
		  pt = &mesh->tetra[k + 3];
		  pt->v[0] = p2;
		  pt->v[1] = p3;
			pt->v[2] = p1;
			pt->v[3] = p0;
			pt->ref  = ref;//2;//ref;
			break;
		case 35:    //D4 --> ok
		 	pt = &mesh->tetra[k + 1];
			pt->v[0] = p0;
		  pt->v[1] = p4;
			pt->v[2] = p3;
			pt->v[3] = p5;
			pt->ref  = ref;//4;//ref;
		  pt = &mesh->tetra[k + 2];
		  pt->v[0] = p0;
			pt->v[1] = p4;
			pt->v[2] = p5;
			pt->v[3] = p2;
			pt->ref  = ref;//4;//ref;
		  pt = &mesh->tetra[k + 3];  
		  pt->v[0] = p0;
		  pt->v[1] = p2;
			pt->v[2] = p4;
			pt->v[3] = p1;
			pt->ref  = ref;//4;//ref;
			break;
		case 52:    
		 	pt = &mesh->tetra[k + 1];
			pt->v[0] = p2;
		  pt->v[1] = p4;
			pt->v[2] = p5;
			pt->v[3] = p3;
			pt->ref  = ref;//6;//ref;
		  pt = &mesh->tetra[k + 2];
		  pt->v[0] = p2;
			pt->v[1] = p4;
			pt->v[2] = p1;
			pt->v[3] = p3;
			pt->ref  = ref;//6;//ref;
		  pt = &mesh->tetra[k + 3];
		  pt->v[0] = p3;
		  pt->v[1] = p0;
			pt->v[2] = p1;
			pt->v[3] = p2;
			pt->ref  = ref;//6;//ref;
			break;
		case 49:    //D5
   	  pt = &mesh->tetra[k + 1];
		  pt->v[0] = p0;
	    pt->v[1] = p4;
		  pt->v[2] = p3;
		  pt->v[3] = p2;
		  pt->ref  = ref;//5;//ref;
	    pt = &mesh->tetra[k + 2];
	    pt->v[0] = p3;
		  pt->v[1] = p2;
		  pt->v[2] = p4;
		  pt->v[3] = p5;
		  pt->ref  = ref;//5;//ref;
	    pt = &mesh->tetra[k + 3];
	    pt->v[0] = p0;
	    pt->v[1] = p2;
		  pt->v[2] = p1;
		  pt->v[3] = p4;
			pt->ref  = ref;//5;//ref;
			break;
	  default:
			//5,7,11,13,15,18,19,21,22,23,26,27,29,30,31,37,39,40,41,42,43,44,45,46,47,50,51,52,53,54,55:  
		  MMG_cutadd(mesh,hed,icas,k,p0,p1,p2,p3,p4,p5,ref);
		 
		  //printf("icas imposssss %d\n",icas); 
			return(0);
		  //exit(0);
		  break;
	}	  	
	return(1);
}