#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <malloc.h>

#include "globals.h"
#include "stl.h"

#if !defined(SEEK_SET)
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif


int StlGetLittleInt(FILE *fp)
{
    int value;
    value  =  fgetc(fp) & 0xFF;
    value |= (fgetc(fp) & 0xFF) << 0x08;
    value |= (fgetc(fp) & 0xFF) << 0x10;
    value |= (fgetc(fp) & 0xFF) << 0x18;
    return(value);
}

float StlGetLittleFloat(FILE *fp)
{
    union 
    {
	int   int_value;
	float float_value;
    } value;
    
    value.int_value  =  fgetc(fp) & 0xFF;
    value.int_value |= (fgetc(fp) & 0xFF) << 0x08;
    value.int_value |= (fgetc(fp) & 0xFF) << 0x10;
    value.int_value |= (fgetc(fp) & 0xFF) << 0x18;
    return(value.float_value);
}

void StlPutLittleInt(FILE *fp, int value_in)
{
    
    int new_value;
    union 
    {
	int  int_value;
	char char_value[4];
    } value;
    
    value.int_value = value_in;
    
    new_value  = value.char_value[0] & 0xFF;
    new_value |= (value.char_value[1] & 0xFF) << 0x08;
    new_value |= (value.char_value[2] & 0xFF) << 0x10;
    new_value |= (value.char_value[3] & 0xFF) << 0x18;
    
    fwrite(&new_value, sizeof(int), 1, fp);
}

void StlPutLittleFloat(FILE *fp, float value_in)
{
    
    int new_value;
    union 
    {
	float float_value;
	char  char_value[4];
    } value;
    
    value.float_value = value_in;
    
    new_value  = value.char_value[0] & 0xFF;
    new_value |= (value.char_value[1] & 0xFF) << 0x08;
    new_value |= (value.char_value[2] & 0xFF) << 0x10;
    new_value |= (value.char_value[3] & 0xFF) << 0x18;
    
    fwrite(&new_value, sizeof(int), 1, fp);
}

int StlCheckIfFileExists(char *file)
{
    
    FILE *fp;
    
    fp = fopen(file, "rb");
    if(fp == NULL)
    {  	  
	return LOGICAL_FALSE;
    }
    else
    {
	fclose(fp);
	return LOGICAL_TRUE;
    }
}

int StlInitialize(stl_data *stl, char *file)
{
    
    long           file_size;
    int            header_num_facets;
    int            num_facets;
    int            i, j;
    unsigned char  chtest[128];
    unsigned char  fhtest[5];
    int            num_lines = 1;
    
    stl->stats.volume = -1.0;
    
    /* Open the file */
    stl->fp = fopen(file, "rb");
    
    if(stl->fp == NULL)
	return LOGICAL_FALSE;
    
    /* Find size of file */
    fseek(stl->fp, 0, SEEK_END);
    file_size = ftell(stl->fp);
    
    stl->stats.file_size = file_size;
    
    /* Check for binary or ASCII file */
    fseek(stl->fp, HEADER_SIZE, SEEK_SET);
    fread(chtest, sizeof(chtest), 1, stl->fp);
    stl->stats.type = ASCII;
    
    for(i = 0; i < sizeof(chtest); i++)
    {
	if(chtest[i] > 127)
	{
	    stl->stats.type = BINARY;
	    break;
	}
    }
    
    rewind(stl->fp);
    
    /* Get the header and the number of facets in the .STL file */
    /* If the .STL file is binary, then do the following */
    if(stl->stats.type == BINARY)
    {
	/* Test if the STL file has the right size  */
	if(((file_size - HEADER_SIZE) % SIZEOF_STL_FACET != 0)
	    || (file_size < STL_MIN_FILE_SIZE))
	    return LOGICAL_FALSE;
	
	num_facets = (file_size - HEADER_SIZE) / SIZEOF_STL_FACET;
	
	/* Read the header */
	strcpy(stl->stats.header, "");
	fread(stl->stats.header, LABEL_SIZE, 1, stl->fp);
	stl->stats.header[80] = '\0';
	
	/* Read the int following the header.  This should contain # of facets */
	header_num_facets = StlGetLittleInt(stl->fp);
	
	//if(num_facets != header_num_facets)
	//"Warning: File size doesn't match number of facets in the header"
	
    }
    /* Otherwise, if the .STL file is ASCII, then do the following */
    else
    {
	
	/* Get the header */
	for(i = 0; (i < 80) && (chtest[i] = getc(stl->fp)) != '\n'; i++);
	
	fscanf(stl->fp, "%s", &fhtest);
	
	if (strcmp(fhtest, "facet") != 0)
	    return LOGICAL_FALSE;
	
	rewind(stl->fp);
	
	/* Find the number of facets */
	j = 0;
	for(i = 0; i < file_size ; i++)
	{
	    j++;
	    if(getc(stl->fp) == '\n')
	    {
		if(j > 4) /* don't count short lines */
		{
		    num_lines++;
		}
		j = 0;
		
	    }
	    
	}
	
	rewind(stl->fp);
	
	/* Get the header */
	strcpy(stl->stats.header, "");
	for(i = 0; (i < 80) && (stl->stats.header[i] = getc(stl->fp)) != '\n'; i++);
	
	num_facets = num_lines / ASCII_LINES_PER_FACET;
	
    }
    
    stl->stats.number_of_facets += num_facets;
    
    /* Successful exit */
    return LOGICAL_TRUE;
    
}

int StlOpenSTL(stl_data *stl, char *file)
{
    
    StlClose(stl);
    
    if (StlInitialize(stl, file) == LOGICAL_TRUE)
    {
	
	if (StlAllocate(stl) == LOGICAL_TRUE)
	    StlReadStl(stl, 0, 1);
	else
	    return LOGICAL_FALSE;
	
    }
    else
	return LOGICAL_FALSE;
    
    return LOGICAL_TRUE;
}

void StlClose(stl_data *stl)
{
    
    stl_index = 0;
    
    stl->stats.number_of_facets = 0;
    
    stl->stats.malloced = 0;
    stl->stats.freed = 0;
    stl->stats.facets_malloced = 0;
    
    stl->stats.file_size = 0;
    strcpy(stl->stats.header, "");
    
    stl->stats.shortest_edge = 0;
    stl->stats.tolerance = 0;
    stl->stats.type = 0;
    
    stl->stats.area = 0;
    stl->stats.volume = 0;
    
    stl->stats.min.x = 0;
    stl->stats.min.y = 0;
    stl->stats.min.z = 0;
    
    stl->stats.max.x = 0;
    stl->stats.max.y = 0;
    stl->stats.max.z = 0;
    
    stl->stats.center.x = 0;
    stl->stats.center.y = 0;
    stl->stats.center.z = 0;
    
    stl->stats.size.x = 0;
    stl->stats.size.y = 0;
    stl->stats.size.z = 0;
    
    stl->stats.bounding_diameter = 0;
    
    // Free memory
    
    if(stl->facet_start != NULL)
    {
	free(stl->facet_start);
	stl->facet_start = NULL;
    }
    
    
}

int StlAllocate(stl_data *stl)
{
    
    /*  Allocate memory for the entire .STL file */
    stl->facet_start = calloc(stl->stats.number_of_facets, sizeof(stl_facet));
    
    stl->stats.facets_malloced = stl->stats.number_of_facets;
    
    if (stl->facet_start == NULL) return LOGICAL_FALSE;
    
    return LOGICAL_TRUE;
}

int StlAddSTL(stl_data *stl, char *file)
{
    
    int first_facet;
    
    first_facet = stl->stats.number_of_facets;
    
    if (StlInitialize(stl, file) == LOGICAL_TRUE)
    {
	
	if (StlReallocate(stl) == LOGICAL_TRUE)
	    StlReadStl(stl, first_facet, 1);
	else
	    return LOGICAL_FALSE;
	
    }
    else
	return LOGICAL_FALSE;
    
    
    return LOGICAL_TRUE;
}

int StlReallocate(stl_data *stl)
{
    
    /*  Reallocate more memory for the .STL file(s) */
    stl->facet_start = realloc(stl->facet_start, (stl->stats.number_of_facets + 1) * sizeof(stl_facet));
    
    stl->stats.facets_malloced = stl->stats.number_of_facets;
    
    if (stl->facet_start == NULL) return LOGICAL_FALSE;
    
    return LOGICAL_TRUE;
}

void StlReadStl(stl_data *stl, int first_facet, int first)
{
    
    stl_facet facet;
    int   i;
    float diff_x;
    float diff_y;
    float diff_z;
    float max_diff;
    
    if (stl->facet_start == NULL)
	return;
    
    if(stl->stats.type == BINARY)
    {
	fseek(stl->fp, HEADER_SIZE, SEEK_SET);
    }
    else
    {
	rewind(stl->fp);
	/* Skip the first line of the file */
	while(getc(stl->fp) != '\n');
    }
    
    for(i = first_facet; i < stl->stats.number_of_facets; i++)
    {
	if(stl->stats.type == BINARY)
	    /* Read a single facet from a binary .STL file */
	{
	    facet.normal.x = StlGetLittleFloat(stl->fp);
	    facet.normal.y = StlGetLittleFloat(stl->fp);
	    facet.normal.z = StlGetLittleFloat(stl->fp);
	    facet.vertex[0].x = StlGetLittleFloat(stl->fp);
	    facet.vertex[0].y = StlGetLittleFloat(stl->fp);
	    facet.vertex[0].z = StlGetLittleFloat(stl->fp);
	    facet.vertex[1].x = StlGetLittleFloat(stl->fp);
	    facet.vertex[1].y = StlGetLittleFloat(stl->fp);
	    facet.vertex[1].z = StlGetLittleFloat(stl->fp);
	    facet.vertex[2].x = StlGetLittleFloat(stl->fp);
	    facet.vertex[2].y = StlGetLittleFloat(stl->fp);
	    facet.vertex[2].z = StlGetLittleFloat(stl->fp);
	    facet.extra[0] = fgetc(stl->fp);
	    facet.extra[1] = fgetc(stl->fp);
	}
	else
	    /* Read a single facet from an ASCII .STL file */
	{
	    fscanf(stl->fp, "%*s %*s %f %f %f\n", &facet.normal.x,
		   &facet.normal.y, &facet.normal.z);
	    fscanf(stl->fp, "%*s %*s");
	    fscanf(stl->fp, "%*s %f %f %f\n", &facet.vertex[0].x,
		   &facet.vertex[0].y,  &facet.vertex[0].z);
	    fscanf(stl->fp, "%*s %f %f %f\n", &facet.vertex[1].x,
		   &facet.vertex[1].y,  &facet.vertex[1].z);
	    fscanf(stl->fp, "%*s %f %f %f\n", &facet.vertex[2].x,
		   &facet.vertex[2].y,  &facet.vertex[2].z);
	    fscanf(stl->fp, "%*s");
	    fscanf(stl->fp, "%*s");
	}
	
	/* Write the facet into memory. */
	stl->facet_start[i] = facet;
	
	/* while we are going through all of the facets, let's find the  */
	/* maximum and minimum values for x, y, and z  */
	
	/* Initialize the max and min values the first time through*/
	if(first)
	{
	    stl->stats.max.x = facet.vertex[0].x;
	    stl->stats.min.x = facet.vertex[0].x;
	    stl->stats.max.y = facet.vertex[0].y;
	    stl->stats.min.y = facet.vertex[0].y;
	    stl->stats.max.z = facet.vertex[0].z;
	    stl->stats.min.z = facet.vertex[0].z;
	    
	    diff_x = ABS(facet.vertex[0].x - facet.vertex[1].x);
	    diff_y = ABS(facet.vertex[0].y - facet.vertex[1].y);
	    diff_z = ABS(facet.vertex[0].z - facet.vertex[1].z);
	    max_diff = MAX(diff_x, diff_y);
	    max_diff = MAX(diff_z, max_diff);
	    stl->stats.shortest_edge = max_diff;
	    
	    first = 0;
	}
	
	/* now find the max and min values */
	stl->stats.max.x = MAX(stl->stats.max.x, facet.vertex[0].x);
	stl->stats.min.x = MIN(stl->stats.min.x, facet.vertex[0].x);
	stl->stats.max.y = MAX(stl->stats.max.y, facet.vertex[0].y);
	stl->stats.min.y = MIN(stl->stats.min.y, facet.vertex[0].y);
	stl->stats.max.z = MAX(stl->stats.max.z, facet.vertex[0].z);
	stl->stats.min.z = MIN(stl->stats.min.z, facet.vertex[0].z);
	
	stl->stats.max.x = MAX(stl->stats.max.x, facet.vertex[1].x);
	stl->stats.min.x = MIN(stl->stats.min.x, facet.vertex[1].x);
	stl->stats.max.y = MAX(stl->stats.max.y, facet.vertex[1].y);
	stl->stats.min.y = MIN(stl->stats.min.y, facet.vertex[1].y);
	stl->stats.max.z = MAX(stl->stats.max.z, facet.vertex[1].z);
	stl->stats.min.z = MIN(stl->stats.min.z, facet.vertex[1].z);
	
	stl->stats.max.x = MAX(stl->stats.max.x, facet.vertex[2].x);
	stl->stats.min.x = MIN(stl->stats.min.x, facet.vertex[2].x);
	stl->stats.max.y = MAX(stl->stats.max.y, facet.vertex[2].y);
	stl->stats.min.y = MIN(stl->stats.min.y, facet.vertex[2].y);
	stl->stats.max.z = MAX(stl->stats.max.z, facet.vertex[2].z);
	stl->stats.min.z = MIN(stl->stats.min.z, facet.vertex[2].z);
    }
    
    stl->stats.size.x = stl->stats.max.x - stl->stats.min.x;
    stl->stats.size.y = stl->stats.max.y - stl->stats.min.y;
    stl->stats.size.z = stl->stats.max.z - stl->stats.min.z;
    
    /*
	stl->stats.bounding_diameter = sqrt(stl->stats.size.x * stl->stats.size.x + stl->stats.size.y * stl->stats.size.y + stl->stats.size.z * stl->stats.size.z);
	
	C_EPS = stl->stats.bounding_diameter / 10000;
	C_EPS *= C_EPS;
	*/
    
    C_EPS = 1E-6f;
    
    StlReallocate(stl);
}

int StlWriteAscii(stl_data *stl, char *file, char *label)
{
    int       i;
    FILE      *fp;
    
    /* Open the file */
    fp = fopen(file, "w");
    if(fp == NULL)
    {
	return LOGICAL_FALSE;
    }
    
    fprintf(fp, "solid %s\n", label);
    
    for(i = 0; i < stl->stats.number_of_facets; i++)
    {
	fprintf(fp, "facet normal %.8E %.8E %.8E\n",
		stl->facet_start[i].normal.x, stl->facet_start[i].normal.y,
		stl->facet_start[i].normal.z);
	fprintf(fp, "outer loop\n");
	fprintf(fp, "vertex %.8E %.8E %.8E\n",
		stl->facet_start[i].vertex[0].x, stl->facet_start[i].vertex[0].y,
		stl->facet_start[i].vertex[0].z);
	fprintf(fp, "vertex %.8E %.8E %.8E\n",
		stl->facet_start[i].vertex[1].x, stl->facet_start[i].vertex[1].y,
		stl->facet_start[i].vertex[1].z);
	fprintf(fp, "vertex %.8E %.8E %.8E\n",
		stl->facet_start[i].vertex[2].x, stl->facet_start[i].vertex[2].y,
		stl->facet_start[i].vertex[2].z);
	fprintf(fp, "endloop\n");
	fprintf(fp, "endfacet\n");
    }
    
    fprintf(fp, "endsolid %s\n", label);
    
    fclose(fp);
    
    return LOGICAL_TRUE;
}

int StlWriteBinary(stl_data *stl, char *file, char *label)
{
    
    FILE      *fp;
    int       i;
    
    if (stl->facet_start == NULL)
	return LOGICAL_FALSE;
    
    /* Open the file */
    fp = fopen(file, "wb");
    if(fp == NULL)
    {
	return LOGICAL_FALSE;
    }
    
    fprintf(fp, "%s", label);
    for(i = strlen(label); i < LABEL_SIZE; i++) putc(0, fp);
    
    fseek(fp, LABEL_SIZE, SEEK_SET);
    
    StlPutLittleInt(fp, stl->stats.number_of_facets);
    
    for(i = 0; i < stl->stats.number_of_facets; i++)
    {
	StlPutLittleFloat(fp, stl->facet_start[i].normal.x);
	StlPutLittleFloat(fp, stl->facet_start[i].normal.y);
	StlPutLittleFloat(fp, stl->facet_start[i].normal.z);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[0].x);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[0].y);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[0].z);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[1].x);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[1].y);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[1].z);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[2].x);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[2].y);
	StlPutLittleFloat(fp, stl->facet_start[i].vertex[2].z);
	
	fputc(stl->facet_start[i].extra[0], fp);
	fputc(stl->facet_start[i].extra[1], fp);
    }
    
    fclose(fp);
    
    return LOGICAL_TRUE;
}


