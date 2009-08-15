////////////////////////////////////////////////////////////////////////////////////////////////////
// gmsh2_2gid.c routine to convert gmsh format 2 mesh files into gid mesh file for EBEM programme //
// writes out all the nodes but only writes out the triangular 3 node elements.                   //
//                                   mark smith 2008    piedycat@tiscali.co.uk                    //
//////////////////////////////////////////////////////////////////////////////////////////////////// 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 128
#define MaxNodes 32  // maximum number of nodes per element
#define version "gmsh2_2gid.exe ver 1.00 Oct 2008 Mark Smith\n"
#define debug 0

void jumpline (FILE *stream); //skip a line

FILE *fpGid,*fpGmsh;

int main(int argc, char *argv[])
{
   char buffer[MAXLINE],temp[64];
   long ELEMENTS,NODES,i,N,k=1;       // number of elements and nodes etc
   long n[MaxNodes];
   int elem_type,n_tags,n_nodes=0,tag_1,tag_2,tag_3,j;
   double x,y,z;  //nodal coordinates
   printf(version);
   if(argc<2)
   {
      printf("Gmesh format 2 .msh file to Gid mesh .dat file conversion routine\n");
      printf("writes out all the nodes but only writes out the triangular 3 node elements.\n");
      printf("Usage: gmsh2_2gid.exe in_filename out_filename .\n");
      exit(0);
   }
   if((fpGmsh=fopen(argv[1],"r"))==NULL)
	{
		printf("can't open input gmsh mesh .msh file\n");
		exit(1);
	}	
	if((fpGid=fopen(argv[2],"w"))==NULL)
	{
		printf("can't open output Gid mesh .dat file\n");
		exit(1);           
	}
	strcpy(temp,"$MeshFormat");
	fgets(buffer, MAXLINE, fpGmsh);
	if(!strstr(buffer,temp))
	{
	   printf("input file not correct type!\n");
	   exit(0);
	}
   jumpline(fpGmsh);  //jump over 2 0 8
   jumpline(fpGmsh);  //jump over $EndMeshFormat
   jumpline(fpGmsh);  //jump over $Nodes
	fscanf(fpGmsh,"%ld ",&NODES); //read in the number of nodes
	printf("number of NODES=%ld\n",NODES);
	fprintf(fpGid,"MESH    dimension 3 ElemType Triangle  Nnode 3\nCoordinates\n"); // write out gid header
	for(i=0;i<NODES;i++)
	{
      fscanf(fpGmsh,"%ld %lg %lg %lg ",&N,&x,&y,&z);
      fprintf(fpGid,"%6ld   %15.6e   %15.6e   %15.6e\n",N,x,y,z);      
   }
   fprintf(fpGid,"end coordinates\n\nElements\n");
   jumpline(fpGmsh);  //jump over $EndNodes
   jumpline(fpGmsh);  //jump over $Elements
	fscanf(fpGmsh,"%ld ",&ELEMENTS); //read in the number of elements
	printf("number of ELEMENTS=%ld\n",ELEMENTS);

	for(i=0;i<ELEMENTS;i++)
	{
      //elm-number elm-type number-of-tags < tag > ... node-number-list
      fscanf(fpGmsh,"%ld %d %d ",&N,&elem_type,&n_tags);
      switch(elem_type)
      {
         case 1:n_nodes=2;break;     //2-node line.
         case 2:n_nodes=3;break;     //3-node triangle.
         case 3:n_nodes=4;break;     //4-node quadrangle.
         case 4:n_nodes=4;break;     //4-node tetrahedron.
         case 5:n_nodes=8;break;     //8-node hexahedron.
         case 6:n_nodes=6;break;     //6-node prism.
         case 7:n_nodes=5;break;     //5-node pyramid.
         case 8:n_nodes=3;break;     //3-node second order line (2 nodes associated with the vertices and 1 with the edge).
         case 9:n_nodes=6;break;     //6-node second order triangle (3 nodes associated with the vertices and 3 with the edges).
         case 10:n_nodes=9;break;    //9-node second order quadrangle (4 nodes associated with the vertices, 4 with the edges and 1 with the face).
         case 11:n_nodes=10;break;   //10-node second order tetrahedron (4 nodes associated with the vertices and 6 with the edges).
         case 12:n_nodes=27;break;   //27-node second order hexahedron (8 nodes associated with the vertices, 12 with the edges, 6 with the faces and 1 with the volume).
         case 13:n_nodes=18;break;   //18-node second order prism (6 nodes associated with the vertices, 9 with the edges and 3 with the quadrangular faces).
         case 14:n_nodes=14;break;   //14-node second order pyramid (5 nodes associated with the vertices, 8 with the edges and 1 with the quadrangular face).
         case 15:n_nodes=1;break;    //1-node point.
         case 16:n_nodes=8;break;    //8-node second order quadrangle (4 nodes associated with the vertices and 4 with the edges).
         case 17:n_nodes=20;break;   //20-node second order hexahedron (8 nodes associated with the vertices and 12 with the edges).
         case 18:n_nodes=15;break;   //15-node second order prism (6 nodes associated with the vertices and 9 with the edges).       
      }
      fscanf(fpGmsh,"%d %d %d ",&tag_1,&tag_2,&tag_3);
      // tag_1= the number of the physical entity to which the element belongs
      // tag_2= the number of the elementary geometrical entity to which the element belongs
      // tag_3= the number of a mesh partition to which the element belongs
      for(j=0;j<n_nodes;j++)
      {
         fscanf(fpGmsh,"%ld ",&n[j]);
      }
      if(n_nodes==3) //only write out the 3 node triangular elements
      {
          fprintf(fpGid,"  %6ld    %6ld    %6ld    %6ld    %4d\n",k,n[0],n[1],n[2],tag_1);
          k++; //keep a count of the elements written & renumber starting @ 1
      }
      if(debug)printf("%ld %d %d %d %d %d\n",N,elem_type,n_nodes,tag_1,tag_2,tag_3);    
   }
   fprintf(fpGid,"end elements\n");
   fclose(fpGmsh);			// close all the files
	fclose(fpGid);
	printf("Finished!!");
   return 0;
}

void jumpline (FILE *stream) //skip a line
{
   char buffer[MAXLINE];
   fgets(buffer, MAXLINE, stream);
   if(debug)printf("buffer=%s\n",buffer);
}
