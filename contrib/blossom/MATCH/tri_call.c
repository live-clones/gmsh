/***********************************************************/
/*                                                         */
/*             ROUTINE TO START TRIANGLE CODE              */
/*                                                         */
/*  TRIANGLE is a program to calculte Delaunay             */
/*  trianglulations, it can be found at                    */
/*      http://www.cs.cmu.edu/~quake/triangle.html         */
/*                                                         */
/*  Written by:  A. Rohe                                   */
/*  Date:  July 28, 1997                                   */
/*                                                         */
/*  This program should be compiled with make tri_call     */

/*  This program should be compiled with make tri_call     */
/*                                                         */
/*  It can be used the following way:                      */
/*                                                         */
/*  tri_call  <data-file> <edge-file> <triangle>           */
/*                                                         */
/*  <data-file> is a normal blossom4 x-y input file        */
/*  <edge-file> is a the edgefile-name you would like      */
/*  <triangle>  is the place of and name of the triangle   */
/*              executable                                 */
/*                                                         */
/*  The program will creat a <data-file>.node file and     */
/*  a <data-file>.1.edge file and not delete them !        */
/*                                                         */
/***********************************************************/
/*                                                         */
/*  example:                                               */
/*                                                         */
/*  tri_call 100.dat 100.del ./triangle                    */
/*                                                         */
/*  this reads the file 100.dat, writes the delaunay       */
/*  triangulation to 100.del using the program             */
/*  ./triangle.                                            */
/*  The files 100.dat.node and 100.del.1.edge will         */
/*  be created.                                            */
/*                                                         */
/***********************************************************/
/*                                                         */
/*  Then this data can be used the following way:          */
/*                                                         */
/*  - To get the minimum weight perfect matching in        */
/*    in the complete graph starting with the              */
/*    Delaunay triangulation:                              */
/*        blossom4 -x 100.dat -e 100.del                   */
/*                                                         */
/*  - To get the minimum weight perfect matching in        */
/*    in the Delaunay triangulation:                       */
/*        blossom4 -e 100.del                              */
/*                                                         */
/***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int nodes;
double *x,*y;

 /*
** read_xy, reads the x and y coordinates
*/
#ifdef PROTOTYPE_ANSI
static void read_write_xy (char* name)
#else
static void read_write_xy (name)
char *name;
#endif
{
    int i;
    FILE *fp1,*fp2;
    char name2[200];

    /* OPEN name */
    if ((fp1=fopen(name,"r"))==NULL) {
        printf("Can't open file %s \n",name);
        exit(1);
    }
    /* OPEN name2 */
    sprintf(name2,"%s.node",name);
    if ((fp2=fopen(name2,"w"))==NULL) {
        printf("Can't open file %s \n",name2);
        exit(1);
    }

    /* get #nodes */
    fscanf(fp1,"%i",&nodes);
    fprintf(fp2,"%i 2 0 0\n",nodes);
    printf("Number of nodes: %i\n",nodes);
    printf("Reading from %s and writing to %s\n",name,name2);

    /* initialize the x[]'s */
    if ((x=(double *)malloc(nodes * sizeof(double))) == NULL) {
        printf("Not enough memory to allocate buffer for x\n");
        exit(1);  /* terminate program if out of memory */
    }
    /* initialize the yy[]'s */
    if ((y=(double *)malloc(nodes * sizeof(double))) == NULL) {
        printf("Not enough memory to allocate buffer for y\n");
        exit(1);  /* terminate program if out of memory */
    }

    /* read from fp1 and write to fp2 */
    for (i=0;i<nodes;i++) {
        fscanf(fp1,"%lf %lf",x+i,y+i);
        fprintf(fp2,"%i %lf %lf\n",i,x[i],y[i]);
    }
    fclose(fp1);
    fclose(fp2);
}

 /*
** read_xy, reads the x and y coordinates
*/
#ifdef PROTOTYPE_ANSI
static void read_write_edges (char* name,char* edgefile)
#else
static void read_write_edges (name,edgefile)
char *name;
char *edgefile;
#endif
{
    int i,a,b;
    int edges,dummy;
    FILE *fp1,*fp2;
    char name2[200];

    /* OPEN name */
    if ((fp1=fopen(edgefile,"w"))==NULL) {
        printf("Can't open file %s \n",edgefile);
        exit(1);
    }
    /* OPEN name2 */
    sprintf(name2,"%s.1.edge",name);
    if ((fp2=fopen(name2,"r"))==NULL) {
        printf("Can't open file %s \n",name2);
        exit(1);
    }

    fscanf(fp2,"%i %i",&edges,&dummy);
    fprintf(fp1,"%i %i\n",nodes,edges);
    printf("Number of edges: %i\n",edges);
    printf("Reading from %s and writing to %s\n",name2,edgefile);

    for (i=0;i<edges;i++) {
        fscanf(fp2,"%i %i %i",&dummy,&a,&b);
        fprintf(fp1,"%i %i %i\n",a,b,(int)(0.5 + sqrt( (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]) )));
    }
    fclose(fp1);
    fclose(fp2);
    free(x);
    free(y);
}

/*
** main program
*/
#ifdef PROTOTYPE_ANSI
int  main (int ac, char **av)
#else
int  main (ac, av)
int ac;
char **av;
#endif
{
    char triangle_call[200];

    if (ac<4) {
        printf("\nNot enough parameters:\n%s  <data-file> <edge-file> <triangle>\n",av[0]);
        exit(1);  /* terminate program */
    }

    read_write_xy(av[1]);

    sprintf(triangle_call,"%s -e -B -P -N -E -z %s",av[3],av[1]);
    printf("I'll do the command '%s' \n",triangle_call);
    fflush(stdout);
    system(triangle_call);

    read_write_edges(av[1],av[2]);
    printf("Ready !\n");

}
