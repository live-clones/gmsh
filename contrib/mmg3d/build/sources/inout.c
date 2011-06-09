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


extern short	       MMG_imprim;
#define sw 4
#define sd 8

int MMG_swapbin(int sbin)
{
	int inv; 
  char *p_in = (char *) &sbin;
  char *p = (char *)&inv;

 
  p[0] = p_in[3];
  p[1] = p_in[2];
  p[2] = p_in[1];
  p[3] = p_in[0]; 
  
  return(inv);
  /*unsigned char c1, c2, c3, c4;

  c1 = sbin & 255;
  c2 = (sbin >> 8) & 255;
  c3 = (sbin >> 16) & 255;
  c4 = (sbin >> 24) & 255;
  
  return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;   */

}
float MMG_swapf(float sbin)
{ 
  float out;
  char *p_in = (char *) &sbin; 
  char *p_out = (char *) &out; 
  p_out[0] = p_in[3]; 
  p_out[1] = p_in[2]; 
  p_out[2] = p_in[1]; 
  p_out[3] = p_in[0];
  
  return(out);
}
double MMG_swapd(double sbin)
{
  float out;
  char *p_in = (char *) &sbin; 
  char *p_out = (char *) &out; 
  int i;
  
  for(i=0;i<8;i++)
  {
    p_out[i] = p_in[7-i];
  }          
  //printf("CONVERTION DOUBLE\n");
  return(out);
}

/* read mesh data */
int MMG_loadMesh(pMesh mesh,char *filename) {  
  FILE*            inm;
  Hedge    				 hed,hed2;
  pPoint       	   ppt;
  pTetra           pt;
  pTria            pt1;
  int              k,dim,ref,bin,bpos,i,tmp;   
  long             posnp,posnt,posne,posnhex,posnpris,posncor,posned,posnq;
  char            *ptr,data[128],chaine[128];
  int              nhex,npris,netmp,ncor,ned,nq;
  int              p0,p1,p2,p3,p4,p5,p6,p7;  
  int              binch,bdim,iswp,nu1,nu2,nimp,ne;       
  float            fc;
  

  posnp = posnt = posne = posnhex = posnpris = 0;
  netmp = ncor = ned = 0;
  bin = 0;
  iswp = 0;
  mesh->np = mesh->nt = mesh->ne = mesh->ncor = 0; 
  npris = nhex = nq = 0;
  
  strcpy(data,filename);
  ptr = strstr(data,".mesh");  
  if ( !ptr ) {
    strcat(data,".meshb");
    if( !(inm = fopen(data,"rb")) ) {
      ptr = strstr(data,".mesh");
      *ptr = '\0';
      strcat(data,".mesh");
      if( !(inm = fopen(data,"r")) ) {
        fprintf(stderr,"  ** %s  NOT FOUND.\n",data);
        return(0);
      }
    } else {
      bin = 1;
    }
  }
  else {
    ptr = strstr(data,".meshb");
    if( !ptr ) {
      if( !(inm = fopen(data,"r")) ) {
        fprintf(stderr,"  ** %s  NOT FOUND.\n",data);
        return(0);
      }      
    } else {
      bin = 1;
      if( !(inm = fopen(data,"rb")) ) {
        fprintf(stderr,"  ** %s  NOT FOUND.\n",data);
        return(0);
      }
      
    }  
  }

  fprintf(stdout,"  %%%% %s OPENED\n",data);
  if (!bin) {
    strcpy(chaine,"D");     
    while(fscanf(inm,"%s",&chaine[0])!=EOF && strncmp(chaine,"End",strlen("End")) ) { 
      if(!strncmp(chaine,"MeshVersionFormatted",strlen("MeshVersionFormatted"))) {
          fscanf(inm,"%d",&mesh->ver);
          continue;
      } else if(!strncmp(chaine,"Dimension",strlen("Dimension"))) {
          fscanf(inm,"%d",&dim);
          if(dim!=3) {
            fprintf(stdout,"BAD DIMENSION : %d\n",dim);
            return(0);
          }
          continue;
      } else if(!strncmp(chaine,"Vertices",strlen("Vertices"))) {
        fscanf(inm,"%d",&mesh->np); 
        posnp = ftell(inm);
        continue;
      } else if(!strncmp(chaine,"Triangles",strlen("Triangles"))) {
        fscanf(inm,"%d",&mesh->nt); 
        posnt = ftell(inm);
        continue;
      } else if(!strncmp(chaine,"Tetrahedra",strlen("Tetrahedra"))) {
        fscanf(inm,"%d",&mesh->ne); 
        netmp = mesh->ne;
        posne = ftell(inm);
        continue;
      } else if(!strncmp(chaine,"Hexahedra",strlen("Hexahedra"))) { 
        assert(abs(mesh->info.option)==10);  
        fscanf(inm,"%d",&nhex); 
				//nhex=0;
        posnhex = ftell(inm);
        continue;
      } else if(!strncmp(chaine,"Pentahedra",strlen("Pentahedra"))) { 
        assert(abs(mesh->info.option)==10); 
        fscanf(inm,"%d",&npris);
				//npris=0;
        posnpris = ftell(inm);
        continue;
      } else if(!strncmp(chaine,"Corners",strlen("Corners"))) { 
        fscanf(inm,"%d",&ncor); 
        posncor = ftell(inm);
        continue;
      } else if(!strncmp(chaine,"Edges",strlen("Edges"))) { 
	      fscanf(inm,"%d",&ned); 
	      posned = ftell(inm);
	      continue;
	    } else if(abs(mesh->info.option)==10 && !strncmp(chaine,"Quadrilaterals",strlen("Quadrilaterals"))) {
		    fscanf(inm,"%d",&nq); 
		    posnq = ftell(inm);
		    continue;
		  }
    }  
  } else {
    bdim = 0;
    fread(&mesh->ver,sw,1,inm);
    iswp=0;   
    if(mesh->ver==16777216) 
      iswp=1;    
    else if(mesh->ver!=1) {
      fprintf(stdout,"BAD FILE ENCODING\n");
    } 
    fread(&mesh->ver,sw,1,inm); 
    if(iswp) mesh->ver = MMG_swapbin(mesh->ver); 
    while(fread(&binch,sw,1,inm)!=0 && binch!=54 ) {  
      if(iswp) binch=MMG_swapbin(binch);      
      if(binch==54) break;  
      if(!bdim && binch==3) {  //Dimension
        fread(&bdim,sw,1,inm);  //NulPos=>20
        if(iswp) bdim=MMG_swapbin(bdim);
        fread(&bdim,sw,1,inm);  
        if(iswp) bdim=MMG_swapbin(bdim);
        if(bdim!=3) {
          fprintf(stdout,"BAD SOL DIMENSION : %d\n",dim);
          exit(0);
          return(1);
        }
        continue;
      } else if(!mesh->np && binch==4) {  //Vertices
        fread(&bpos,sw,1,inm); //NulPos 
        if(iswp) bpos=MMG_swapbin(bpos);
        fread(&mesh->np,sw,1,inm); 
        if(iswp) mesh->np=MMG_swapbin(mesh->np);
        posnp = ftell(inm);     
        rewind(inm);
        fseek(inm,bpos,SEEK_SET);        
        continue;
      }  else if(!mesh->nt && binch==6) {//Triangles
        fread(&bpos,sw,1,inm); //NulPos 
        if(iswp) bpos=MMG_swapbin(bpos);
        fread(&mesh->nt,sw,1,inm); 
        if(iswp) mesh->nt=MMG_swapbin(mesh->nt);
        posnt = ftell(inm); 
        rewind(inm);
        fseek(inm,bpos,SEEK_SET);        
        continue;
       } else if(!mesh->ne && binch==8) {  
         fread(&bpos,sw,1,inm); //NulPos 
         if(iswp) bpos=MMG_swapbin(bpos);
         fread(&mesh->ne,sw,1,inm); 
         if(iswp) mesh->ne=MMG_swapbin(mesh->ne);
         netmp = mesh->ne;
         posne = ftell(inm);
         rewind(inm);
         fseek(inm,bpos,SEEK_SET);        
         continue;
       } else if(!nhex && binch==10) { 
         assert(abs(mesh->info.option)==10);
         fread(&bpos,sw,1,inm); //NulPos 
         if(iswp) bpos=MMG_swapbin(bpos);
         fread(&nhex,sw,1,inm); 
         if(iswp) nhex=MMG_swapbin(nhex);
         posnhex = ftell(inm);
         rewind(inm);
         fseek(inm,bpos,SEEK_SET);        
         continue;
       } else if(!npris && binch==9) { 
         assert(abs(mesh->info.option)==10);
         fread(&bpos,sw,1,inm); //NulPos 
         if(iswp) bpos=MMG_swapbin(bpos);
         fread(&npris,sw,1,inm); 
         if(iswp) npris=MMG_swapbin(npris);
         posnpris = ftell(inm);
         rewind(inm);
         fseek(inm,bpos,SEEK_SET);        
         continue;
       } else if(!ncor && binch==13) { 
         fread(&bpos,sw,1,inm); //NulPos 
         if(iswp) bpos=MMG_swapbin(bpos);
         fread(&ncor,sw,1,inm);          
         if(iswp) ncor=MMG_swapbin(ncor);
         posncor = ftell(inm);
         rewind(inm);
         fseek(inm,bpos,SEEK_SET);        
         continue;
        } else if(!ned && binch==5) { //Edges
	       fread(&bpos,sw,1,inm); //NulPos 
	       if(iswp) bpos=MMG_swapbin(bpos);
	       fread(&ned,sw,1,inm); 
	       if(iswp) ned=MMG_swapbin(ned);
	       posned = ftell(inm);
	       rewind(inm);
	       fseek(inm,bpos,SEEK_SET);        
	       continue;
	      } else {
         //printf("on traite ? %d\n",binch);
         fread(&bpos,sw,1,inm); //NulPos 
         if(iswp) bpos=MMG_swapbin(bpos);
         //printf("on avance... Nulpos %d\n",bpos);         
         rewind(inm);
         fseek(inm,bpos,SEEK_SET);        
       }     
    }            
    
  }

  if ( abs(mesh->info.option)==10 ) {
    fprintf(stdout,"  -- READING %8d HEXA %8d PRISMS\n",nhex,npris);  
    if(!mesh->ne) netmp = 0;  
    mesh->ne += 6*nhex + 3*npris; 
  }

  if ( abs(mesh->info.imprim) > 5 )
    fprintf(stdout,"  -- READING DATA FILE %s\n",data);

  if ( !mesh->np || !mesh->ne ) {
    fprintf(stdout,"  ** MISSING DATA\n");
    return(0);
  }
  if ( !MMG_zaldy(mesh) )  return(0);

  /* read mesh vertices */
  mesh->npfixe = mesh->np;
  rewind(inm);
  fseek(inm,posnp,SEEK_SET);
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if (mesh->ver < 2) { /*float*/ 
      if (!bin) {
        for (i=0 ; i<3 ; i++) {
          fscanf(inm,"%f",&fc);
          ppt->c[i] = (double) fc;
        } 
        fscanf(inm,"%d",&ppt->ref);
      } else {
        for (i=0 ; i<3 ; i++) {
          fread(&fc,sw,1,inm); 
          if(iswp) fc=MMG_swapf(fc);    
          ppt->c[i] = (double) fc;
        }     
        fread(&ppt->ref,sw,1,inm);         
        if(iswp) ppt->ref=MMG_swapbin(ppt->ref);    
      }
    } else {
      if (!bin) 
        fscanf(inm,"%lf %lf %lf %d",&ppt->c[0],&ppt->c[1],&ppt->c[2],&ppt->ref); 
      else {
        for (i=0 ; i<3 ; i++) { 
          fread(&ppt->c[i],sd,1,inm);
          if(iswp) ppt->c[i]=MMG_swapd(ppt->c[i]); 
        }   
        fread(&ppt->ref,sw,1,inm);         
        if(iswp) ppt->ref=MMG_swapbin(ppt->ref);    
      }  
    }             
    ppt->tag  = M_UNUSED;    
  }

  /* read mesh triangles */
  mesh->ntfixe = mesh->nt;
  rewind(inm);
  fseek(inm,posnt,SEEK_SET);
  for (k=1; k<=mesh->nt; k++) {
    pt1 = &mesh->tria[k]; 
    if (!bin)
      fscanf(inm,"%d %d %d %d",&pt1->v[0],&pt1->v[1],&pt1->v[2],&pt1->ref);
    else {
      for (i=0 ; i<3 ; i++) { 
        fread(&pt1->v[i],sw,1,inm); 
        if(iswp) pt1->v[i]=MMG_swapbin(pt1->v[i]);    
      }
      fread(&pt1->ref,sw,1,inm); 
      if(iswp) pt1->ref=MMG_swapbin(pt1->ref);           
    }  
  }
  /* read mesh quads (option 10)*/ 
	if(abs(mesh->info.option)==10) { 
		fprintf(stdout,"     QUADS READING %d\n",nq);
    mesh->ntfixe += 4*nq;
    rewind(inm);
    fseek(inm,posnq,SEEK_SET);
    for (k=1; k<=nq; k++) {
      if (!bin)
        fscanf(inm,"%d %d %d %d %d",&p0,&p1,&p2,&p3,&ref);
      else {
        fread(&p0,sw,1,inm); 
        if(iswp) p0=MMG_swapbin(p0);    
        fread(&p1,sw,1,inm); 
        if(iswp) p1=MMG_swapbin(p1);    
        fread(&p2,sw,1,inm); 
        if(iswp) p2=MMG_swapbin(p2);    
        fread(&p3,sw,1,inm); 
        if(iswp) p3=MMG_swapbin(p3);    
	      fread(&pt1->ref,sw,1,inm); 
	      if(iswp) ref=MMG_swapbin(ref);           
      } 
      pt1 = &mesh->tria[++mesh->nt]; 
			pt1->v[0] = p0;
			pt1->v[1] = p1;
			pt1->v[2] = p2;
			pt1->ref  = ref;
      pt1 = &mesh->tria[++mesh->nt]; 
			pt1->v[0] = p0;
			pt1->v[1] = p2;
			pt1->v[2] = p3;
			pt1->ref  = ref;
      pt1 = &mesh->tria[++mesh->nt]; 
			pt1->v[0] = p0;
			pt1->v[1] = p1;
			pt1->v[2] = p3;
			pt1->ref  = ref;
      pt1 = &mesh->tria[++mesh->nt]; 
			pt1->v[0] = p1;
			pt1->v[1] = p2;
			pt1->v[2] = p3;
			pt1->ref  = ref;
 
    }
  }

	/*read and store edges*/
  if (ned) {         
	  if ( !MMG_zaldy4(&hed,ned) ) {
      if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EDGES IGNORED\n"); 
			ned = 0;
    }   
		mesh->ned = ned;
    rewind(inm);
    fseek(inm,posned,SEEK_SET); 
    for (k=1; k<=ned; k++) { 
      if (!bin)
        fscanf(inm,"%d %d %d",&nu1,&nu2,&ref);
      else {
        fread(&nu1,sw,1,inm); 
        if(iswp) nu1=MMG_swapbin(nu1);    
        fread(&nu2,sw,1,inm); 
        if(iswp) nu2=MMG_swapbin(nu2);    
        fread(&ref,sw,1,inm); 
        if(iswp) ref=MMG_swapbin(ref);    
      }  
			if(MMG_edgePut(&hed,nu1,nu2,2)>1) {
				fprintf(stdout,"  ## WARNING DOUBLE EDGE : %d %d\n",nu1,nu2);
			}
    }
  }

  /* read mesh tetrahedra */
  mesh->nefixe = mesh->ne;
  rewind(inm);
  fseek(inm,posne,SEEK_SET);
  for (k=1; k<=netmp; k++) { 
    pt = &mesh->tetra[k];
    if (!bin) 
      fscanf(inm,"%d %d %d %d %d",&pt->v[0],&pt->v[1],&pt->v[2],&pt->v[3],&ref); 
    else {                                                                        
	
      for (i=0 ; i<4 ; i++) { 
        fread(&pt->v[i],sw,1,inm); 
        if(iswp) pt->v[i]=MMG_swapbin(pt->v[i]);    
      }
      fread(&ref,sw,1,inm);         
      if(iswp) ref=MMG_swapbin(ref);           
    }  
    pt->ref  = ref;//0;//ref ;  
    for(i=0 ; i<4 ; i++)
      pt->bdryref[i] = -1;  
    
		if (ned) {
	    for(i=0 ; i<6 ; i++) {                         
				nu1 = pt->v[MMG_iare[i][0]];
				nu2 = pt->v[MMG_iare[i][1]];
	      pt->bdryinfo[i] = MMG_edgePoint(&hed,nu1,nu2);
			}  			
			
		} else {
	    for(i=0 ; i<6 ; i++)
	      pt->bdryinfo[i] = 0;  			
		}
  }
  if (ned) M_free(hed.item); 

  /*read corners*/ 
  if (ncor) {
    rewind(inm);
    fseek(inm,posncor,SEEK_SET); 
    mesh->ncor = ncor;
    for (k=1; k<=ncor; k++) { 
      if (!bin)
        fscanf(inm,"%d",&ref);
      else {
        fread(&ref,sw,1,inm); 
        if(iswp) ref=MMG_swapbin(ref);    
      }  
      ppt = &mesh->point[ref];
      ppt->geom = M_CORNER; 
    } 
  }
   
	
  if ( abs(mesh->info.option)==10 ) { 
    if(bin) {
      printf("NOT SUPPORTED\n");
      exit(0);
    } 
	  if ( !MMG_zaldy4(&hed2,3*npris+6*nhex) ) {
      if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : PRISM IGNORED\n"); 
			npris = 0;
			nhex  = 0;
    }   

    /*read hexa and transform to tetra*/
    rewind(inm);
    fseek(inm,posnhex,SEEK_SET);
    for (k=1; k<=nhex; k++) {   
      fscanf(inm,"%d %d %d %d %d %d %d %d %d",&p0,&p1,&p2,&p3,&p4,&p5,&p6,&p7,&ref); 
      //fscanf(inm,"%d %d %d %d %d %d %d %d %d",&p0,&p4,&p2,&p1,&p3,&p5,&p6,&p7,&ref); 
      //printf("hex %d : %d %d %d %d %d %d %d %d\n",k,p0,p1,p2,p3,p4,p5,p6,p7);   
			MMG_cuthex(mesh,&hed2,netmp+(k-1)*6,p0,p1,p2,p3,p4,p5,p6,p7,ref);
    }  
    
    /*read prism and transform to tetra
		---> compatibility pbs ==> hash edge and switch case*/  
    rewind(inm);
    fseek(inm,posnpris,SEEK_SET); 
		nimp = 0; 
		ne = netmp+6*nhex;
    for (k=1; k<=npris; k++) {
      fscanf(inm,"%d %d %d %d %d %d %d",&p0,&p1,&p2,&p3,&p4,&p5,&ref); 
			if(!MMG_cutprism(mesh,&hed2,ne,p0,p1,p2,p3,p4,p5,ref))
			{
				if(mesh->info.imprim < 0 ) fprintf(stdout,"DECOMPOSITION PRISM INVALID \n\n"); 
				mesh->ne += 5;
				ne += 8;
				nimp++; 
				continue;
			}
			ne += 3;
    }
		if(abs(mesh->info.imprim) > 3 )fprintf(stdout,"     %d INVALID DECOMPOSITION\n\n",nimp);
  }
  
  if ( abs(mesh->info.imprim) > 3 ) {
    fprintf(stdout,"     NUMBER OF GIVEN VERTICES   %8d\n",mesh->npfixe);
    if ( mesh->ntfixe )
      fprintf(stdout,"     NUMBER OF GIVEN TRIANGLES  %8d\n",mesh->ntfixe);
    fprintf(stdout,"     NUMBER OF GIVEN TETRAHEDRA %8d\n",mesh->nefixe);
    if ( ncor )
      fprintf(stdout,"     NUMBER OF GIVEN CORNERS    %8d\n",ncor);
    if ( ned )
      fprintf(stdout,"     NUMBER OF GIVEN EDGES      %8d\n",ned);
  }
 fclose(inm);
 return(1);
}


/* load solution (metric) */
int MMG_loadSol(pSol sol,char *filename,int npmax) { 
  FILE       *inm;   
  float       fsol;
  double      tmp;       
  int         binch,bdim,iswp;
  int         k,i,isol,type,bin,dim,btyp,bpos;
  long        posnp;
  char        *ptr,data[128],chaine[128];
  
  posnp = 0; 
  bin   = 0;
  iswp  = 0; 

  strcpy(data,filename);
  ptr = strstr(data,".mesh");
  if ( ptr )  *ptr = '\0';
  strcat(data,".solb");
  if( !(inm = fopen(data,"rb")) ) {
    ptr  = strstr(data,".solb");
    *ptr = '\0';
    strcat(data,".sol");
    if( !(inm = fopen(data,"r")) ) {
      fprintf(stderr,"  ** %s  NOT FOUND.\n",data);
      return(1);
    }
  } else {
    bin = 1;
  }
  fprintf(stdout,"  %%%% %s OPENED\n",data);

   
  if(!bin) {   
    strcpy(chaine,"DDD");
    while(fscanf(inm,"%s",&chaine[0])!=EOF && strncmp(chaine,"End",strlen("End")) ) { 
      if(!strncmp(chaine,"Dimension",strlen("Dimension"))) {
          fscanf(inm,"%d",&dim);
          if(dim!=3) {
            fprintf(stdout,"BAD SOL DIMENSION : %d\n",dim); 
            return(1);
          }
          continue;
      } else if(!strncmp(chaine,"SolAtVertices",strlen("SolAtVertices"))) {
        fscanf(inm,"%d",&sol->np); 
        fscanf(inm,"%d",&type); 
        if(type!=1) {
          fprintf(stdout,"SEVERAL SOLUTION => IGNORED : %d\n",type);
          return(1);
        }
        fscanf(inm,"%d",&btyp);
        posnp = ftell(inm);
        break;
      } 
    }            
  } else {     
    fread(&binch,sw,1,inm); 
    iswp=0;   
    if(binch==16777216) iswp=1;    
    else if(binch!=1) {
      fprintf(stdout,"BAD FILE ENCODING\n");
    } 
    fread(&sol->ver,sw,1,inm); 
    if(iswp) sol->ver = MMG_swapbin(sol->ver); 
    while(fread(&binch,sw,1,inm)!=EOF && binch!=54 ) {
      if(iswp) binch=MMG_swapbin(binch);      
      if(binch==54) break;  
      if(binch==3) {  //Dimension
        fread(&bdim,sw,1,inm);  //NulPos=>20
        if(iswp) bdim=MMG_swapbin(bdim);
        fread(&bdim,sw,1,inm);
        if(iswp) bdim=MMG_swapbin(bdim);
        if(bdim!=3) {
          fprintf(stdout,"BAD SOL DIMENSION : %d\n",dim);
          exit(0);
          return(1);
        }
        continue;
      } else if(binch==62) {  //SolAtVertices
        fread(&binch,sw,1,inm); //NulPos
        if(iswp) binch=MMG_swapbin(binch);
        fread(&sol->np,sw,1,inm); 
        if(iswp) sol->np=MMG_swapbin(sol->np);
        fread(&binch,sw,1,inm); //nb sol
        if(iswp) binch=MMG_swapbin(binch);
        if(binch!=1) {
          fprintf(stdout,"SEVERAL SOLUTION => IGNORED : %d\n",type);
          return(1);
        }
        fread(&btyp,sw,1,inm); //typsol
        if(iswp) btyp=MMG_swapbin(btyp);
        posnp = ftell(inm);
        break;
      } else {
        fread(&bpos,sw,1,inm); //Pos 
        if(iswp) bpos=MMG_swapbin(bpos);
        rewind(inm);
        fseek(inm,bpos,SEEK_SET);        
      } 
    }            
    
  }       
  if ( !sol->np ) {
    fprintf(stdout,"  ** MISSING DATA\n");
    return(1);
  }

  if ( btyp!= 1 && btyp!=3 ) {
    fprintf(stdout,"  ** DATA IGNORED\n");
    sol->np = 0;
    return(1);
  }
  
  sol->offset = (btyp==1) ? 1 : 6;

  if ( abs(MMG_imprim) > 5 )
    fprintf(stdout,"  -- READING DATA FILE %s\n",data);

  if ( !sol->np ) {
    fprintf(stdout,"  ** MISSING DATA\n");
    return(0);
  }
  sol->npfixe = sol->np;
  sol->npmax  = npmax;
  if ( !MMG_zaldy3(sol) )  return(0);

  /* read mesh solutions */
  sol->npfixe = sol->np;
  rewind(inm);
  fseek(inm,posnp,SEEK_SET);  
  for (k=1; k<=sol->np; k++) {
    isol = (k-1) * sol->offset + 1;
    if (sol->ver == 1) { 
      for (i=0; i<sol->offset; i++) {
        if(!bin){
          fscanf(inm,"%f",&fsol);    
          sol->met[isol + i] = (double) fsol;
        } else {
          fread(&fsol,sw,1,inm);             
          if(iswp) fsol=MMG_swapf(fsol);
          sol->met[isol + i] = (double) fsol;
        }
      } 
    } else {
      for (i=0; i<sol->offset; i++) {
        if(!bin){
          fscanf(inm,"%lf",&sol->met[isol + i]); 

        } else {
          fread(&sol->met[isol + i],sd,1,inm);       
          if(iswp) sol->met[isol + i]=MMG_swapd(sol->met[isol + i]);
        } 
      } 
    }             
    /* MMG_swap data */
    if ( sol->offset == 6 ) {
      tmp                = sol->met[isol + 2];
      sol->met[isol + 2] = sol->met[isol + 3];
      sol->met[isol + 3] = tmp;
    }
  }

  if ( abs(MMG_imprim) > 3 )
    fprintf(stdout,"     NUMBER OF GIVEN DATA       %8d\n",sol->npfixe);

  fclose(inm);   
  return(1);  
}


int MMG_loadVect(pMesh mesh,char *filename,int npmax) {
  FILE       *inm;   
  pDispl       pd;
  float       fsol;
  int         binch,bdim,iswp;
  int         k,i,type,bin,dim,btyp,bpos,iadr;
  long        posnp;
  char        *ptr,data[128],chaine[128];
  
  pd = mesh->disp;
  
  posnp = 0; 
  bin   = 0; 
  iswp  = 0;

  strcpy(data,filename);
  ptr = strstr(data,".mesh");
  if ( ptr )  *ptr = '\0';
  strcat(data,".solb");
  if( !(inm = fopen(data,"rb")) ) {
    ptr  = strstr(data,".solb");
    *ptr = '\0';
    strcat(data,".sol");
    if( !(inm = fopen(data,"r")) ) {
      fprintf(stderr,"  ** %s  NOT FOUND.\n",data);
      return(1);
    }
  } else {
    bin = 1;
  }
  fprintf(stdout,"  %%%% %s OPENED\n",data);

   
  if(!bin) {   
    strcpy(chaine,"DDD");
    while(fscanf(inm,"%s",&chaine[0])!=EOF && strncmp(chaine,"End",strlen("End")) ) { 
      if(!strncmp(chaine,"Dimension",strlen("Dimension"))) {
          fscanf(inm,"%d",&dim);
          if(dim!=3) {
            fprintf(stdout,"BAD SOL DIMENSION : %d\n",dim); 
            return(1);
          }
          continue;
      } else if(!strncmp(chaine,"SolAtVertices",strlen("SolAtVertices"))) {
        fscanf(inm,"%d",&pd->np); 
        fscanf(inm,"%d",&type); 
        if(type!=1) {
          fprintf(stdout,"SEVERAL SOLUTION => IGNORED : %d\n",type);
          return(1);
        }
        fscanf(inm,"%d",&btyp);
        posnp = ftell(inm);
        break;
      } 
    }            
  } else {     
    fread(&pd->ver,sw,1,inm); 
    iswp=0;   
    if(pd->ver==16777216) iswp=1;    
    else if(pd->ver!=1) {
      fprintf(stdout,"BAD FILE ENCODING\n");
    } 
    fread(&pd->ver,sw,1,inm); 
    if(iswp) pd->ver = MMG_swapbin(pd->ver); 
    while(fread(&binch,sw,1,inm)!=EOF && binch!=54 ) {
      if(iswp) binch=MMG_swapbin(binch);      
      if(binch==54) break;  
      if(binch==3) {  //Dimension
        fread(&bdim,sw,1,inm);  //Pos=>20
        if(iswp) bdim=MMG_swapbin(bdim);      
        fread(&bdim,sw,1,inm);
        if(iswp) bdim=MMG_swapbin(bdim);      
        if(bdim!=3) {
          fprintf(stdout,"BAD SOL DIMENSION : %d\n",dim);
          exit(0);
          return(1);
        }
        continue;
      } else if(binch==62) {  //SolAtVertices
        fread(&binch,sw,1,inm); //Pos
        if(iswp) binch=MMG_swapbin(binch);      
        fread(&pd->np,sw,1,inm); 
        if(iswp) pd->np=MMG_swapbin(pd->np);      
        fread(&binch,sw,1,inm); //nb sol
        if(iswp) binch=MMG_swapbin(binch);      
        if(binch!=1) {
          fprintf(stdout,"SEVERAL SOLUTION => IGNORED : %d\n",type);
          return(1);
        }
        fread(&btyp,sw,1,inm); //typsol
        if(iswp) btyp=MMG_swapbin(btyp);      
        posnp = ftell(inm);
        break;
      } else {
        fread(&bpos,sw,1,inm); //Pos 
        if(iswp) bpos=MMG_swapbin(bpos);      
        rewind(inm);
        fseek(inm,bpos,SEEK_SET);        
      } 
    }            
    
  }       
  if ( !pd->np ) {
    fprintf(stdout,"  ** MISSING DATA\n");
    return(0);
  }
  else if ( pd->np != mesh->np ) {
    fprintf(stdout,"  ** WRONG DATA\n");
    return(0);
  }

  if ( btyp != 2 ) {
    fprintf(stdout,"  ** DATA IGNORED\n");
    return(0);
  }

  if ( abs(mesh->info.imprim) > 5 )
    fprintf(stdout,"  -- READING DATA FILE %s\n",data);

  /* read mesh solutions */
  rewind(inm);
  fseek(inm,posnp,SEEK_SET);
  for (k=1; k<=pd->np; k++) {
    iadr = (k - 1) * 3 + 1;
    if (pd->ver < 2) { 
      for (i=0; i<3; i++) {
        if(!bin){
          fscanf(inm,"%f",&fsol); 
          pd->mv[iadr + i] = (double) fsol;
        } else {
          fread(&fsol,sw,1,inm);             
          if(iswp) fsol=MMG_swapf(fsol);      
          pd->mv[iadr + i] = (double) fsol;
        }
      } 
    } else {
      for (i=0; i<3; i++) {
        if(!bin){
          fscanf(inm,"%lf",&pd->mv[iadr + i]); 
        } else {
          fread(&pd->mv[iadr + i],sd,1,inm);
          if(iswp) pd->mv[iadr + i]=MMG_swapd(pd->mv[iadr + i]);      
        } 
      } 
    }             
  }

  if ( abs(mesh->info.imprim) > 3 )
    fprintf(stdout,"     NUMBER OF GIVEN DATA       %8d\n",pd->np);

  fclose(inm); 
  return(1);
}


/* save mesh to disk */
int MMG_saveMesh(pMesh mesh,char *filename) {  
  FILE*        inm; 
	Hedge				 hed;
  pPoint       ppt;
  pTria        pt1;
  pTetra       pt;
  int          i,k,np,ne,nc,ned,*cor,*ed,ref,bin,bpos;
  char        *ptr,data[128],chaine[128]; 
  int          binch,nu1,nu2;
  mesh->ver = 2; //double precision
  bin = 0;
  strcpy(data,filename);
  ptr = strstr(data,".mesh");
  if ( !ptr ) {
    strcat(data,".meshb");
    if( !(inm = fopen(data,"wb")) ) {
      ptr  = strstr(data,".mesh");
      *ptr = '\0';
      strcat(data,".mesh");
      if( !(inm = fopen(data,"w")) ) {
        fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
        return(0);
      }
    } else {
      bin = 1;   
    }
  }
  else { 
    ptr = strstr(data,".meshb");
    if( ptr ) bin = 1;
    if( !(inm = fopen(data,"w")) ) {
      fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
      return(0);
    } 
  }
  fprintf(stdout,"  %%%% %s OPENED\n",data);

  /*entete fichier*/
  if(!bin) {
    strcpy(&chaine[0],"MeshVersionFormatted 2\n"); 
    fprintf(inm,"%s",chaine);
    strcpy(&chaine[0],"\n\nDimension 3\n"); 
    fprintf(inm,"%s ",chaine);
  } else {
    binch = 1; //MeshVersionFormatted
    fwrite(&binch,sw,1,inm);
    binch = 2; //version
    fwrite(&binch,sw,1,inm);
    binch = 3; //Dimension
    fwrite(&binch,sw,1,inm);
    bpos = 20; //Pos
    fwrite(&bpos,sw,1,inm);
    binch = 3;
    fwrite(&binch,sw,1,inm);
    
  }

  /* compact vertices */
  if(mesh->ncor) {   
    cor = (int*) M_calloc(mesh->ncor,sizeof(int),"MMG_savemesh");
    assert(cor);   
  }
  if(mesh->ned) {   
	  if ( !MMG_zaldy4(&hed,mesh->ned) ) {
      if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM : EXPORT EDGES IGNORED\n"); 
			mesh->ned = 0;
    }   
    ed = (int*)M_calloc(2*mesh->ned,sizeof(int),"MMG_savemesh");
    assert(ed);   
  }
  np = 0; 
  nc = 0;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;  
		ppt->tmp = ++np;  
    if ( ppt->geom & M_CORNER )  cor[nc++] = ppt->tmp;
  } 
	assert(mesh->ncor==nc);
  if(!bin) {
    strcpy(&chaine[0],"\n\nVertices\n"); 
    fprintf(inm,"%s",chaine);
    fprintf(inm,"%d\n",np);
  } else {
    binch = 4; //Vertices
    fwrite(&binch,sw,1,inm);
    bpos += 12+(1+3*mesh->ver)*4*np; //NullPos
    fwrite(&bpos,sw,1,inm);
    fwrite(&np,sw,1,inm);    
  }
  for(k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;  
		//if(ppt->tmp==52453) printf("point %d --> %d\n",ppt->tmp,k);
    if(!bin) {
      fprintf(inm,"%.15lg %.15lg %.15lg %d\n",ppt->c[0],ppt->c[1],ppt->c[2],ppt->ref);
    } else {
      fwrite((unsigned char*)&ppt->c[0],sd,1,inm);    
      fwrite((unsigned char*)&ppt->c[1],sd,1,inm);    
      fwrite((unsigned char*)&ppt->c[2],sd,1,inm);    
      fwrite((unsigned char*)&ppt->ref,sw,1,inm);    
    }
  }

  /* rebuild triangles tabular and write triangles */ 
  mesh->nt = 0;
  if(MMG_markBdry(mesh)) {
    if(!bin) {
      strcpy(&chaine[0],"\n\nTriangles\n"); 
      fprintf(inm,"%s",chaine);
      fprintf(inm,"%d \n",mesh->nt);
    } else {
      binch = 6; //Triangles
      fwrite(&binch,sw,1,inm);
      bpos += 12+16*mesh->nt; //Pos
      fwrite(&bpos,sw,1,inm);
      fwrite(&mesh->nt,sw,1,inm);    
    }
    for (k=1; k<=mesh->nt; k++) {
      pt1  = &mesh->tria[k];
  	    ref  = pt1->ref;    
      if(!bin) {
        fprintf(inm,"%d %d %d %d\n",mesh->point[pt1->v[0]].tmp,mesh->point[pt1->v[1]].tmp
    							  ,mesh->point[pt1->v[2]].tmp,ref);
      } else {
        fwrite(&mesh->point[pt1->v[0]].tmp,sw,1,inm);    
        fwrite(&mesh->point[pt1->v[1]].tmp,sw,1,inm);    
        fwrite(&mesh->point[pt1->v[2]].tmp,sw,1,inm);    
        fwrite(&ref,sw,1,inm);    
      }
    }
  }   
 
  /* write tetrahedra */
  ne = 0; 
	ned = 0;  
	//printf("avt %d\n",mesh->ned);
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
		if(mesh->ned) {
		  for (i=0 ; i<6 ; i++) {
		  	if (pt->bdryinfo[i]) {
		  		nu1 = pt->v[MMG_iare[i][0]];
		  		nu2 = pt->v[MMG_iare[i][1]];
		  		if (MMG_edgePut(&hed,nu1,nu2,2)<=1) {
		  			ed[2*ned] = (mesh->point[nu1]).tmp;
		  			ed[2*ned + 1] = (mesh->point[nu2]).tmp;
		  			ned++;
		  		} 
		  	}
		  } 
		}
	  ne++;  
  }
	//printf("ned %d\n",ned);
  if(!bin) {
    strcpy(&chaine[0],"\n\nTetrahedra\n"); 
    fprintf(inm,"%s",chaine);
    fprintf(inm,"%d\n",ne);
  } else {
    binch = 8; //Tetra
    fwrite(&binch,sw,1,inm);
    bpos += 12 + 20*ne;//Pos
    fwrite(&bpos,sw,1,inm);
    fwrite((unsigned char*)&ne,sw,1,inm);    
  } 
	ne=0;
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;  
		ne++; 
    ref = pt->ref;    
    if(!bin) {
      fprintf(inm,"%d %d %d %d %d\n",mesh->point[pt->v[0]].tmp,mesh->point[pt->v[1]].tmp
  							   ,mesh->point[pt->v[2]].tmp,mesh->point[pt->v[3]].tmp,ref);
    } else {
      fwrite(&mesh->point[pt->v[0]].tmp,sw,1,inm);    
      fwrite(&mesh->point[pt->v[1]].tmp,sw,1,inm);    
      fwrite(&mesh->point[pt->v[2]].tmp,sw,1,inm);    
      fwrite(&mesh->point[pt->v[3]].tmp,sw,1,inm);    
      fwrite(&ref,sw,1,inm);    
    }
  }  
     
  if(mesh->ned) {
    if(!bin) {
      strcpy(&chaine[0],"\n\nEdges\n"); 
      fprintf(inm,"%s",chaine);
      fprintf(inm,"%d\n",ned);
    } else {
      binch = 5; //Edges
      fwrite(&binch,sw,1,inm);
      bpos += 12 + 3*4*ned;//Pos
      fwrite(&bpos,sw,1,inm);
      fwrite((unsigned char*)&ned,sw,1,inm);    
    } 
  	  for (k=0; k<ned; k++) {
   	    ref = 0;    
  	    if(!bin) {
  	      fprintf(inm,"%d %d %d \n",ed[2*k],ed[2*k+1],ref);
  	    } else {
  	      fwrite(&ed[2*k],sw,1,inm);    
  	      fwrite(&ed[2*k+1],sw,1,inm);    
  	      fwrite(&ref,sw,1,inm);    
  	    }
  	  }
  	  M_free(hed.item);
  }
  
  /* write corners */
  if(!bin) {
    strcpy(&chaine[0],"\n\nCorners\n"); 
    fprintf(inm,"%s",chaine);
    fprintf(inm,"%d\n",mesh->ncor);
  } else {
    binch = 13; //Corners
    fwrite(&binch,sw,1,inm);
    bpos += 12 + 4*mesh->ncor;//Pos  
    fwrite(&bpos,sw,1,inm);
    fwrite((unsigned char*)&mesh->ncor,sw,1,inm);    
  }
  for (k=0; k<mesh->ncor; k++) {
    if(!bin) {
      fprintf(inm,"%d \n",cor[k]);
    } else {
      fwrite(&cor[k],sw,1,inm);    
    }
  }  
  /*fin fichier*/
  if(!bin) {
    strcpy(&chaine[0],"\n\nEnd\n"); 
    fprintf(inm,"%s",chaine);
  } else {
    binch = 54; //End
    fwrite(&binch,sw,1,inm);
  }
  fclose(inm); 
  if(mesh->ncor) M_free(cor);
  if ( mesh->info.imprim ) {
    fprintf(stdout,"     NUMBER OF GIVEN VERTICES   %8d\n",mesh->npfixe);
    if ( mesh->ntfixe )
      fprintf(stdout,"     NUMBER OF GIVEN TRIANGLES  %8d\n",mesh->ntfixe);
    fprintf(stdout,"     NUMBER OF GIVEN ELEMENTS   %8d\n",mesh->nefixe);
    fprintf(stdout,"     TOTAL NUMBER OF VERTICES   %8d\n",np);
    fprintf(stdout,"     TOTAL NUMBER OF TRIANGLES  %8d\n",mesh->nt);
    fprintf(stdout,"     TOTAL NUMBER OF ELEMENTS   %8d\n",ne);
    if ( mesh->ncor )
      fprintf(stdout,"     TOTAL NUMBER OF CORNERS    %8d\n",mesh->ncor);
    if ( mesh->ned )
      fprintf(stdout,"     TOTAL NUMBER OF EDGES      %8d\n",ned);
  }
	//if(ned!=mesh->ned) exit(0);
  return(1);

}


int MMG_saveSol(pMesh mesh,pSol sol,char *filename) {
  FILE*        inm;
  pPoint       ppt;
  float        fsol;
  double       tmp;
  int          i,k,nbl,isol,bin,bpos,typ;
  char        *ptr,data[128],chaine[128]; 
  int          binch;

  if ( !sol->np )  return(1);
  bin = 1;
  strcpy(data,filename);
  ptr = strstr(data,".meshb");
  if ( ptr )  *ptr = '\0';
  else {
    ptr = strstr(data,".mesh");
    if ( ptr ) {
      *ptr = '\0';
      bin  = 0;
    } else {
	    ptr = strstr(data,".solb");
	    if ( ptr ) {
	      *ptr = '\0';
	      bin  = 1;	
      } else {
			  ptr = strstr(data,".sol");
			  if ( ptr ) {
			    *ptr = '\0';
			    bin  = 0;	
			  }
			}
    } 
  }
  if ( bin ) 
    strcat(data,".solb");
  else
    strcat(data,".sol");
  
  sol->ver = 2;
  if( bin && !(inm = fopen(data,"wb")) ) {
    fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
    return(0);
  } else {
    if( !(inm = fopen(data,"w")) ) {
      fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
      return(0);
    }
  }
  fprintf(stdout,"  %%%% %s OPENED\n",data);

  /*entete fichier*/
  if(!bin) {
    strcpy(&chaine[0],"MeshVersionFormatted 2\n"); 
    fprintf(inm,"%s",chaine);
    strcpy(&chaine[0],"\n\nDimension 3\n"); 
    fprintf(inm,"%s ",chaine);
  } else {
    binch = 1; //MeshVersionFormatted
    fwrite(&binch,sw,1,inm);
    binch = 2; //version
    fwrite(&binch,sw,1,inm);
    binch = 3; //Dimension
    fwrite(&binch,sw,1,inm);
    bpos = 20; //Pos
    fwrite(&bpos,sw,1,inm);
    binch = 3;
    fwrite(&binch,sw,1,inm);
    
  }


  switch(sol->offset) {
  case 1:
	 typ = 1;
   break;
  case 6:
	  typ = 3;
    break;
  default:
    fprintf(stdout,"  ** DATA IGNORED\n");
    return(0);
  }

  /* write data */
  nbl = 0;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
	nbl++;
  }
  
  if(!bin) {
    strcpy(&chaine[0],"\n\nSolAtVertices\n"); 
    fprintf(inm,"%s",chaine);
    fprintf(inm,"%d\n",nbl);
    fprintf(inm,"%d %d\n",1,typ);
  } else {
    binch = 62; //Vertices
    fwrite(&binch,sw,1,inm);
    bpos += 20+(sol->offset*sol->ver)*4*nbl; //Pos
    fwrite(&bpos,sw,1,inm);
    fwrite(&nbl,sw,1,inm);    
    binch = 1; //nb sol
    fwrite(&binch,sw,1,inm);
    binch = typ; //typ sol
    fwrite(&binch,sw,1,inm);
  }
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
    isol = (k-1) * sol->offset + 1;
    /* swap data */
    if ( sol->offset == 6 ) {
      tmp                = sol->met[isol + 2];
      sol->met[isol + 2] = sol->met[isol + 3];
      sol->met[isol + 3] = tmp;
    }
    if (sol->ver < 2) {
      if(!bin) { 
        for (i=0; i<sol->offset; i++) {
          fsol = (float) sol->met[isol + i];
          fprintf(inm,"%f ",fsol);
        } 
        fprintf(inm,"\n");  
      } else {
        for (i=0; i<sol->offset; i++) { 
          fsol = (float) sol->met[isol + i];
          fwrite(&fsol,sw,1,inm);
        }    
      }
    } else {
      if(!bin) { 
        for (i=0; i<sol->offset; i++)
          fprintf(inm,"%.15lg ",sol->met[isol + i]); 
        fprintf(inm,"\n");  
      } else {
        for (i=0; i<sol->offset; i++)
          fwrite(&sol->met[isol + i],sd,1,inm);    
      }
      
    }
  }
  
  /*fin fichier*/
  if(!bin) {
    strcpy(&chaine[0],"\n\nEnd\n"); 
    fprintf(inm,"%s",chaine);
  } else {
    binch = 54; //End
    fwrite(&binch,sw,1,inm);
  }
  fclose(inm);
  return(1);
}

/*save the node speed : coornew-coorold/dt*/
int MMG_saveVect(pMesh mesh,char *filename) {
  FILE*        inm;  
  pDispl        pd;
  pPoint       ppt;
  double       dsol,dd;
  int          i,k,nbl,bin,bpos,typ;
  char        *ptr,data[128],chaine[128]; 
  unsigned char binch;

  pd      = mesh->disp;
  pd->ver = 2;

  bin = 0;
  strcpy(data,filename);
  ptr = strstr(data,".meshb");
  if ( ptr )  *ptr = '\0';
  else {
    ptr = strstr(data,".mesh");
    if ( ptr ) {
      *ptr = '\0';
      bin  = 0;
    }
  }
  if ( bin ) 
    strcat(data,".o.solb");
  else
    strcat(data,".o.sol");
  if( bin && !(inm = fopen(data,"wb")) ) {
    fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
    return(0);
  } else {
    if( !(inm = fopen(data,"w")) ) {
      fprintf(stderr,"  ** UNABLE TO OPEN %s.\n",data);
      return(0);
    }
  }
  fprintf(stdout,"  %%%% %s OPENED\n",data);

  /*entete fichier*/
  if(!bin) {
    strcpy(&chaine[0],"MeshVersionFormatted 2\n"); 
    fprintf(inm,"%s",chaine);
    strcpy(&chaine[0],"\n\nDimension 3\n"); 
    fprintf(inm,"%s ",chaine);
  } else {
    binch = 1; //MeshVersionFormatted
    fwrite(&binch,sw,1,inm);
    binch = pd->ver; //version
    fwrite(&binch,sw,1,inm);
    binch = 3; //Dimension
    fwrite(&binch,sw,1,inm);
    bpos = 20; //Pos
    fwrite(&bpos,sw,1,inm);
    binch = 3;
    fwrite(&binch,sw,1,inm);
    
  }
	typ = 2;

  /* write data */
  nbl = 0;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
	nbl++;
  }
  
  if(!bin) {
    strcpy(&chaine[0],"\n\nSolAtVertices\n"); 
    fprintf(inm,"%s",chaine);
    fprintf(inm,"%d\n",nbl);
    fprintf(inm,"%d %d\n",1,typ);
  } else {
    binch = 62; //SolAtVertices
    fwrite(&binch,sw,1,inm);
    bpos += 20+(3*pd->ver)*4*nbl; //Pos
    fwrite(&bpos,sw,1,inm);
    fwrite(&nbl,sw,1,inm);    
    binch = 1; //nb sol
    fwrite(&binch,sw,1,inm);
    binch = typ; //typ sol
    fwrite(&binch,sw,1,inm);
  } 
  
  
  dd = mesh->info.delta / (double)PRECI;  
  fprintf(stdout,"        DT %e\n",mesh->info.dt);
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue; 
    for (i=0 ; i<3 ; i++) {
      dsol = (ppt->c[i] - mesh->disp->cold[3*(k-1) + 1 + i]* dd - mesh->info.min[i])/mesh->info.dt; 
      if(!bin) { 
        fprintf(inm,"%.15lg ",dsol); 
      } else {
        fwrite(&dsol,sd,1,inm);    
      }
    }
    if (!bin) fprintf(inm,"\n");  
  }
  
  
  /*fin fichier*/
  if(!bin) {
    strcpy(&chaine[0],"\n\nEnd\n"); 
    fprintf(inm,"%s",chaine);
  } else {
    binch = 54; //End
    fwrite(&binch,sw,1,inm);
  }
  fclose(inm);

  return(1);
}
