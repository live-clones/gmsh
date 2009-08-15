
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "globals.h"
#include "stl.h"
#include "mesh.h"
#include "segtri.h"

stl_data stl_in;
msh_data msh_out;

int CreateVoxelMesh(int nx, int ny, int nz)
{
    
    msh_data msh_tmp;
    int *conversion_list;
    
    int i, j, k, n;
    int ind;
    
    float dx, dy, dz;
    float cx, cy, cz;
    
    msh_node v[8];
    
    stl_facet T;
    stl_vertex q;
    stl_vertex r;
    
    char code;
    
    msh_tmp.stats.number_of_nodes = (nx + 1) * (ny + 1) * (nz + 1);  
    msh_tmp.stats.number_of_elements = nx * ny * nz;  
    
    MshAllocate(&msh_tmp);
    
    dx = (stl_in.stats.max.x - stl_in.stats.min.x) / nx;
    dy = (stl_in.stats.max.y - stl_in.stats.min.y) / ny;
    dz = (stl_in.stats.max.z - stl_in.stats.min.z) / nz;
    
    ind = 0;
    
    cz = stl_in.stats.min.z;
    
    for(k = 0; k < nz + 1; k++)
    {   
	
	cy = stl_in.stats.min.y;
	
	for(j = 0; j < ny + 1; j++)
	{   
	    
	    cx = stl_in.stats.min.x;
	    
	    for(i = 0; i < nx + 1; i++)
	    {	
		
		msh_tmp.node_start[ind].x = cx; 
		msh_tmp.node_start[ind].y = cy; 
		msh_tmp.node_start[ind].z = cz; 
		
		ind++;
		
		cx += dx;
		
	    }
	    
	    cy += dy;
	}
	
	cz += dz;
	
    }
    
    ind = 0;
    
    for(k = 0; k < nz; k++)
    {   
	for(j = 0; j < ny; j++)
	{   
	    for(i = 0; i < nx; i++)
	    {
		
		msh_tmp.element_start[ind].node[0] = (i + 0) + (nx + 1) * (j + 0) + (nx + 1) * (ny + 1) * (k + 0);
		msh_tmp.element_start[ind].node[1] = (i + 1) + (nx + 1) * (j + 0) + (nx + 1) * (ny + 1) * (k + 0);
		msh_tmp.element_start[ind].node[2] = (i + 1) + (nx + 1) * (j + 1) + (nx + 1) * (ny + 1) * (k + 0);
		msh_tmp.element_start[ind].node[3] = (i + 0) + (nx + 1) * (j + 1) + (nx + 1) * (ny + 1) * (k + 0);
		
		msh_tmp.element_start[ind].node[4] = (i + 0) + (nx + 1) * (j + 0) + (nx + 1) * (ny + 1) * (k + 1);
		msh_tmp.element_start[ind].node[5] = (i + 1) + (nx + 1) * (j + 0) + (nx + 1) * (ny + 1) * (k + 1);
		msh_tmp.element_start[ind].node[6] = (i + 1) + (nx + 1) * (j + 1) + (nx + 1) * (ny + 1) * (k + 1);
		msh_tmp.element_start[ind].node[7] = (i + 0) + (nx + 1) * (j + 1) + (nx + 1) * (ny + 1) * (k + 1);
		
		ind++;
		
	    }
	}
    }
    
    for (i = 0; i < msh_tmp.stats.number_of_elements; i++)
    {
	
	// printf("Processing element: %d of %d...\n", i + 1, msh_tmp.stats.number_of_elements);
	
	// Create a ray from the center of the element to a distant point
	
	q.x = 0;
	q.y = 0;
	q.z = 0;
	
	for (k = 0; k < 8; k++)
	{
	    v[k] = msh_tmp.node_start[msh_tmp.element_start[i].node[k]];
	    
	    q.x += v[k].x;
	    q.y += v[k].y;
	    q.z += v[k].z;
	}
	
	q.x /= 8; 
	q.y /= 8; 
	q.z /= 8; 
	
	r.x = q.x + 2.91f * stl_in.stats.size.x;
	r.y = q.y + 2.21f * stl_in.stats.size.y;
	r.z = q.z + 2.45f * stl_in.stats.size.z;
	
	n = 0;
	
	for (j = 0; j < stl_in.stats.number_of_facets; j++)
	{
	    
	    T = stl_in.facet_start[j];
	    
	    code = StlSegTriInt(T, q, r);
	    
	    if (code != '0') n++;
	    
	}
	
	if (n % 2 != 0)
	{ 
	    // The element is inside the solid	   
	    msh_tmp.element_start[i].inside = LOGICAL_TRUE;
	}
	else
	{
	    // The element is outside the solid	   
	    msh_tmp.element_start[i].inside = LOGICAL_FALSE;
	}
	
    }
    
    // Remove elements which are outside the solid
    
    msh_out.stats.number_of_nodes = msh_tmp.stats.number_of_nodes;  
    msh_out.stats.number_of_elements = msh_tmp.stats.number_of_elements;  
    
    MshAllocate(&msh_out);
    
    n = 0;
    
    for (i = 0; i < msh_tmp.stats.number_of_elements; i++)
    {
	
	if (msh_tmp.element_start[i].inside == LOGICAL_TRUE)
	{  
	    msh_out.element_start[n] = msh_tmp.element_start[i];
	    n++;	  
	}
	
    }
    
    msh_out.stats.number_of_elements = n;  
    
    // Allocate memory for conversion list
    
    conversion_list = calloc(msh_tmp.stats.number_of_nodes, sizeof(int));
    
    // Remove unused nodes
    
    for (i = 0; i < msh_tmp.stats.number_of_nodes; i++)
    {
	msh_tmp.node_start[i].keep = LOGICAL_FALSE;
    }
    
    for (i = 0; i < msh_out.stats.number_of_elements; i++)
    {	 
	if (msh_out.element_start[i].inside == LOGICAL_TRUE)
	{ 
	    for (k = 0; k < 8; k++)	    
	    {
		msh_tmp.node_start[msh_out.element_start[i].node[k]].keep = LOGICAL_TRUE;
	    }
	}
    }
    
    n = 0;
    
    for (i = 0; i < msh_tmp.stats.number_of_nodes; i++)
    {
	
	if (msh_tmp.node_start[i].keep == LOGICAL_TRUE)
	{  
	    msh_out.node_start[n] = msh_tmp.node_start[i];
	    
	    conversion_list[i] = n;	     
	    
	    n++;
	} 
    }
    
    msh_out.stats.number_of_nodes = n;  
    
    // Renumber elements
    
    for (i = 0; i < msh_out.stats.number_of_elements; i++)
    {
	for (k = 0; k < 8; k++)	    
	{	
	    msh_out.element_start[i].node[k] = conversion_list[msh_out.element_start[i].node[k]];
	}
    }
    
    // Free memory
    
    if (conversion_list != NULL)
    {
	free(conversion_list);
	conversion_list = NULL;
    }
    
    MshReallocate(&msh_out);
    
    // Free memory
    
    MshClose(&msh_tmp);
    
    return LOGICAL_TRUE;
    
}

void Usage()
{
    printf("\nUsage:\n"); 	
    printf("stlToGmsh <file.stl> <nx> <ny> <nz>\n"); 
    
    printf("\n"); 
    printf("nx: number of divisions along x axis\n"); 
    printf("ny: number of divisions along y axis\n"); 
    printf("nz: number of divisions along z axis\n"); 
    
    printf("\nExample:\n"); 	
    printf("stlToGmsh part.stl 20 20 20\n"); 
    printf("\n"); 
    
}

int main(int argc, char *argv[])
{
    
    int nx, ny, nz;
    
    if (argc != 5)
    {
	printf("\nError: %d argument(s) entered when 4 were expected\n", argc - 1);
	Usage();
	exit(0);
    }
    
    StlOpenSTL(&stl_in, argv[1]);
    
    sscanf(argv[2], "%d", &nx);
    sscanf(argv[3], "%d", &ny);
    sscanf(argv[4], "%d", &nz);
    
    printf("Processing...\n");
    
    CreateVoxelMesh(nx, ny, nz);
    
    strncpy(argv[1] + strlen(argv[1]) - 3, "msh", 3);
    MshWriteMSH(&msh_out, argv[1]);
    
    // Free memory
    
    StlClose(&stl_in);
    MshClose(&msh_out);
    
    printf("Done.\n");
    
    return 0;             /* ANSI C requires main to return int. */
}
