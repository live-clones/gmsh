#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <malloc.h>

#include "globals.h"
#include "mesh.h"

int MshAllocate(msh_data *msh)
{
    
    /*  Allocate memory */
    msh->node_start = calloc(msh->stats.number_of_nodes, sizeof(msh_node));
    
    msh->stats.nodes_malloced = msh->stats.number_of_nodes;
    
    if (msh->node_start == NULL) return LOGICAL_FALSE;
    
    msh->element_start = calloc(msh->stats.number_of_elements, sizeof(msh_element));
    
    msh->stats.elements_malloced = msh->stats.number_of_elements;
    
    if (msh->element_start == NULL) return LOGICAL_FALSE;
    
    return LOGICAL_TRUE;
}

int MshReallocate(msh_data *msh)
{
    
    /*  Reallocate more memory */
    
    msh->node_start = realloc(msh->node_start, (msh->stats.number_of_nodes + 1) * sizeof(msh_node));
    
    msh->stats.nodes_malloced = msh->stats.number_of_nodes;
    
    if (msh->node_start == NULL) return LOGICAL_FALSE;
    
    msh->element_start = realloc(msh->element_start, (msh->stats.number_of_elements + 1) * sizeof(msh_element));
    
    msh->stats.elements_malloced = msh->stats.number_of_elements;
    
    if (msh->element_start == NULL) return LOGICAL_FALSE;
    
    return LOGICAL_TRUE;
}

void MshClose(msh_data *msh)
{
    
    
    msh->stats.number_of_nodes = 0;
    msh->stats.number_of_elements = 0;
    
    msh->stats.nodes_malloced = 0;
    msh->stats.elements_malloced = 0;
    
    // Free memory
    
    if(msh->node_start != NULL)
    {
	free(msh->node_start);
	msh->node_start = NULL;
    }
    
    if(msh->element_start != NULL)
    {
	free(msh->element_start);
	msh->element_start = NULL;
    }
    
}
int MshWriteMSH(msh_data *msh, char *file)
{
    
    int i, j;
    
    FILE *fp;
    
    if (msh->node_start == NULL)
	return LOGICAL_FALSE;
    
    if (msh->element_start == NULL)
	return LOGICAL_FALSE;
    
    fp = fopen(file, "w");
    
    if (fp == NULL) return LOGICAL_FALSE;
    
    fprintf(fp, "$NOD\n");
    fprintf(fp, "%d\n", msh->stats.number_of_nodes);
    
    for (i = 0; i < msh->stats.number_of_nodes; i++)
    {
	fprintf(fp, "%d %f %f %f", i + 1, msh->node_start[i].x, msh->node_start[i].y, msh->node_start[i].z);
	fprintf(fp, "\n");
    }
    
    fprintf(fp, "$ENDNOD\n");
    
    fprintf(fp, "$ELM\n");	
    
    fprintf(fp, "%d\n", msh->stats.number_of_elements);
    
    for (i = 0; i < msh->stats.number_of_elements; i++)
    {
	
	fprintf(fp, "%d", i + 1);
	
	fprintf(fp, " %d", 5);
	
	fprintf(fp, " %d", 1);
	fprintf(fp, " %d", 1);
	
	fprintf(fp, " %d", 8);
	
	for (j = 0; j < 8; j++)
	{
	    fprintf(fp, " %d", msh->element_start[i].node[j] + 1);
	}
	
	fprintf(fp, "\n");
	
    }
    
    fprintf(fp, "$ENDELM\n");
    
    fclose(fp);
    
    return LOGICAL_TRUE;
    
}


