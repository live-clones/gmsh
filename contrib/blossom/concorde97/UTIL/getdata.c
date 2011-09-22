/***************************************************************************/
/*                                                                         */
/*                   SOME DATA READING ROUTINES                            */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 2, 1995                                                    */
/*  Changes: 17.7.96 (Bico)                                                */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*   int CCutil_getdata (char *datname, char *weightname, int binary_in,   */
/*           int innorm, inusenodeweights, int *ncount, CCdatagroup *dat,  */
/*           double **wcoord)                                              */
/*    RETURNS the data to generate edge lengths in the dat structure.      */
/*            The calling routine should be sure that dat points to        */
/*            a structure. If datname is NULL then random entries will be  */
/*            generated.                                                   */
/*     -datname is the name of the datfile or the matrix file, if NULL     */
/*      then random data will be generated, according to the norm type.    */
/*      For D2 and D3 norms, the coordinates will be uniform between 0 and */
/*      ncount -1 (GEOGRAPHIC norms have x between -90 and 90 and y        */
/*      between -180 and 180). (For D2, the points will be distinct.)      */
/*      For MATRIX norms, the entries will be                              */
/*      uniform between 0 and MATRAND_SCALE * ncount - 1 (currently        */
/*      10*ncount - 1. For CRYSTAL norms, a random matrix and bounds in    */
/*      range of the TSPLIB problems is generated - the wavelength is      */
/*      chosen to be 1.0, 1.35, or 1.70 depending on the ncount (but the   */
/*      problem will not be very close to hitting ncount.).                */
/*     -binary_in should be 1 if the datname file is in binary integers.   */
/*     -innorm is the norm.                                                */
/*     -ncount will return the number of nodes. If datname is NULL, then   */
/*      ncount should be passed in with the number of nodes to be used in  */
/*      the random problem generation.                                     */
/*     -dat will contain the info to call the edgelen function.            */
/*                                                                         */
/*                                                                         */
/*   int CCutil_writemaster (char *mastername, int ncount,                 */
/*           CCdatagroup *dat, int *perm)                                  */
/*    WRITES the dat information and the permutation into a binary file.   */
/*           This is used in the TSP, where the dat file has usually       */
/*           been permuted to but the nodes into tour order.               */
/*     -mastername is the name of the file (cannot be NULL)                */
/*     -ncount is the number of nodes                                      */
/*     -dat contains the edgelen info (e.g. x,y coordinates), it can be    */
/*      NULL                                                               */
/*     -perm contains a permutation of 0 to ncount - 1 (so a tour in       */
/*      node node node format)                                             */
/*                                                                         */
/*   int CCutil_getmaster (char *mastername, int *ncount, CCdatagroup *dat,*/
/*           int *perm)                                                    */
/*    RETURNS the dat information and the permutation from a binary file   */
/*            (written by a call to writemaster). Used by the TSP code.    */
/*     -mastername is the name of the file (cannot be NULL)                */
/*     -ncount returns the number of nodes                                 */
/*     -dat returns the edgelen info (e.g. x,y coordinates), or NULL       */
/*     -perm returns a permutation of 0 to ncount - 1 (so a tour in        */
/*      node node node format)                                             */
/*                                                                         */
/*   int CCutil_getnodeweights (char *weightname, int ncount,              */
/*           int weight_limit, double **wcoord)                            */
/*    RETURNS a list of nonnegative nodesweights (they will be translated  */
/*            if the weightname file has negative entries). If weightname  */
/*            is NULL then random entries (from 0 to ncount - 1 will be    */
/*            generated.                                                   */
/*     -weightname is the name of a file containing nodeweights. It will   */
/*      only be read if inusenodeweights is 1. If NULL, random entries     */
/*      will be generated (between 0 and weight_limit - 1)                 */
/*     -wcoord will contain the nonnegative node weights (it will be       */
/*      here in getnodeweights)                                            */
/*                                                                         */
/*   int CCutil_gettsplib (char *datname, int *ncount, CCdatagroup *dat)   */
/*    READS an xxx.tsp TSPLIB file, and returns the dat structure to       */
/*            generate edge lengths.                                       */
/*     -datname should be the name of a TSPLIB xxx.tsp file.               */
/*     -ncount returns the number of nodes.                                */
/*     -dat returns the data.                                              */
/*                                                                         */
/*   int CCutil_getedgelist (int ncount, char *fname, int *ecount,         */
/*           int **elist, int **elen)                                      */
/*    READS an edgelist in end1 end2 length format.                        */
/*     -fname name of the file                                             */
/*     -ecount returns the number of edges                                 */
/*     -elist returns the edges in end1 end2 format (it will be allocated  */
/*      by getedgelist)                                                    */
/*     -elen returns the length of the edges in len len len format         */
/*                                                                         */
/*   int CCutil_getedgelist_n (int *ncount, char *fname, int *ecount,      */
/*           int **elist, int **elen)                                      */
/*    READS an edgelist in end1 end2 length format.                        */
/*    Like CCutil_getedgelist (), but it also returns ncount.              */
/*                                                                         */
/*   int CCutil_getcycle_edgelist (int ncount, char *cyclename,            */
/*           int *outcycle)                                                */
/*    READS a cycle in end1 end2 length format, and returns the cycle in   */
/*            node node format in the array outcycle.                      */
/*     -outcycle should be allocated by the calling routine (and should be */
/*      be at least ncount long)                                           */
/*                                                                         */
/*   int CCutil_getcycle (int ncount, char *cyclename, int *outcycle)      */
/*    READS a cycle in node node format, and returns the cycle in node     */
/*            node format in the array outcycle.                           */
/*     -outcycle should be allocated by the calling routine                */
/*                                                                         */
/*   int CCutil_getedges_double (int *ncount, char *fname, int *ecount,    */
/*           int **elist, double **elen, int binary_in)                    */
/*    READS the edgelist in end1 end2 length format, where the length      */
/*            is a double (used for x-vectors)                             */
/*     -returns the number of nodes                                        */
/*     -fname is the name of the file to read.                             */
/*     -ecount returns the number of edges.                                */
/*     -elist returns the list of edges in end1 end2 format (it will be    */
/*      allocated by getedges_double).                                     */
/*     -elen returns the lengths of the edges.                             */
/*     -binary_in indicates whether the file should be written in binary   */
/*      or in ascii (1 is binary, 0 is ascii)                              */
/*                                                                         */
/*   int CCutil_writeedges (int ncount, char *outedgename, int ecount,     */
/*           int *elist, CCdatagroup *dat)                                 */
/*    WRITES the edgelist in end1 end2 length format.                      */
/*     -ncount the number of nodes                                         */
/*     -outedgename is the name of the file to write to.                   */
/*     -ecount is the number of edges.                                     */
/*     -elist is the list of edges in end1 end2 format.                    */
/*     -dat contains the data to compute edgelengths.                      */
/*                                                                         */
/*   int CCutil_writecycle_edgelist (int ncount, char *outedgename,        */
/*           int *cycle, CCdatagroup *dat)                                 */
/*    WRITES the cycle int end1 end1 length format.                        */
/*                                                                         */
/*   int CCutil_writecycle (int ncount, char *outcyclename, int *cycle)    */
/*    WRITES the cycle in node node node format.                           */
/*                                                                         */
/*   int CCutil_writeedges_double (int ncount, char *outedgename,          */
/*           int ecount, int *elist, double *elen, int binary_out)         */
/*    WRITES the edgelist in end1 end2 length format, where the length     */
/*            is a double (used for x-vectors)                             */
/*     -ncount the number of nodes                                         */
/*     -outedgename is the name of the file to write to.                   */
/*     -ecount is the number of edges.                                     */
/*     -elist is the list of edges in end1 end2 format.                    */
/*     -elen are the lengths of the edges.                                 */
/*     -binary_out indicates whether the file should be written in binary  */
/*        or in ascii (1 is binary, 0 is ascii)                            */
/*                                                                         */
/*   int CCutil_datagroup_perm (int ncount, CCdatagroup *dat, int *perm)   */
/*    REORDERS the nodes to match the order given in perm.                 */
/*                                                                         */
/*  NOTES:                                                                 */
/*     Functions prototyped in util.h. Functions return 0 when they        */
/*    succeed and nonzero when they fail (usually do to bad filenames or   */
/*    not enough memory).                                                  */
/*     The TSPLIB reader works for all problems in TSPLIB_1.2, but does    */
/*    not include all of the options listed in Reinelt's orginal TSPLIB    */
/*    paper. It returns a failure on linhp318.tsp, since there is no       */
/*    place for fixed edges in our edge length dat structure.              */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

#define MATRAND_SCALE 10  /* Range of edge lengths: [0, MATRAND_SCALE * n) */

#ifdef CC_PROTOTYPE_ANSI

static void
    make_weights_nonnegative (int ncount, double *wcoord);
static int
    read_crystal (char *datname, int *ncount, CCdatagroup *dat);

#else

static void
    make_weights_nonnegative ();
static int
    read_crystal ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int CCutil_getdata (char *datname, int binary_in, int innorm,
             int *ncount, CCdatagroup *dat)
#else
int CCutil_getdata (datname, binary_in, innorm, ncount, dat)
char *datname;
int binary_in, innorm;
int *ncount;
CCdatagroup *dat;
#endif
{
    int i, j;
    int xi, yi, zi;

    dat->x = (double *) NULL;
    dat->y = (double *) NULL;
    dat->z = (double *) NULL;
    dat->adj = (int **) NULL;
    dat->norm = innorm;

    if (datname == (char *) NULL && *ncount == 0) {
        fprintf (stderr, "getdata needs a datfile or a nodecount\n");
        return 1;
    }

    if (innorm == CC_CRYSTAL) {
        return read_crystal (datname, ncount, dat);
    } else if ((innorm & CC_NORM_SIZE_BITS) == CC_D2_NORM_SIZE ||
        (innorm & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
        if (datname != (char *) NULL) {
            if (binary_in) {
                CC_SFILE *f = CCutil_sopen (datname, "r");
                if (f == (CC_SFILE *) NULL)
                    return 1;
                if (CCutil_sread_int (f, (unsigned int *) ncount)) {
                    CCutil_sclose (f);
                    return 1;
                }
                printf ("nnodes = %d\n", *ncount);
                fflush (stdout);
                dat->x = CC_SAFE_MALLOC (*ncount, double);
                if (!dat->x) {
                    if (CCutil_sclose (f))
                        fprintf (stderr, "Could not close file\n");
                    return 1;
                }
                dat->y = CC_SAFE_MALLOC (*ncount, double);
                if (!dat->y) {
                    if (CCutil_sclose (f))
                        fprintf (stderr, "Could not close file\n");
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
                if ((innorm & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
                    dat->z = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->z) {
                        if (CCutil_sclose (f))
                            fprintf (stderr, "Could not close file\n");
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                }
                for (i = 0; i < *ncount; i++) {
                    if (CCutil_sread_int (f, (unsigned int *) &xi)) {
                        CCutil_sclose (f);
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    if (CCutil_sread_int (f, (unsigned int *) &yi)) {
                        CCutil_sclose (f);
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    dat->x[i] = (double) xi;
                    dat->y[i] = (double) yi;
                    if ((innorm & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
                        if (CCutil_sread_int (f, (unsigned int *) &zi)) {
                            CCutil_sclose (f);
                            CCutil_freedatagroup (*ncount, dat);
                            return 1;
                        }
                        dat->z[i] = (double) zi;
                    }
                }
                if (CCutil_sclose (f)) {
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
            } else {
                FILE *datin = fopen (datname, "r");
                if (datin == (FILE *) NULL) {
                    perror (datname);
                    fprintf (stderr, "Unable to open %s for input\n", datname);
                    return 1;
                }
                fscanf (datin, "%d", ncount);
                printf ("nnodes = %d\n", *ncount);
                dat->x = CC_SAFE_MALLOC (*ncount, double);
                if (!dat->x) {
                    fclose (datin);
                    return 1;
                }
                dat->y = CC_SAFE_MALLOC (*ncount, double);
                if (!dat->y) {
                    fclose (datin);
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
                if ((innorm & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
                    dat->z = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->z) {
                        fclose (datin);
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    for (i = 0; i < *ncount; i++) {
                        fscanf (datin, "%lf %lf %lf",
                             &(dat->x[i]), &(dat->y[i]), &(dat->z[i]));
                    }
                } else {
                    for (i = 0; i < *ncount; i++) {
                        fscanf (datin, "%lf %lf", &(dat->x[i]), &(dat->y[i]));
                    }
                }
                fclose (datin);
            }
        } else {
            printf ("Random %d point set\n", *ncount);
            fflush (stdout);
            dat->x = CC_SAFE_MALLOC (*ncount, double);
            if (!dat->x)
                return 1;
            dat->y = CC_SAFE_MALLOC (*ncount, double);
            if (!dat->y) {
                CCutil_freedatagroup (*ncount, dat);
                return 1;
            }
            if ((innorm & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
                dat->z = CC_SAFE_MALLOC (*ncount, double);
                if (!dat->z) {
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
                for (i = 0; i < *ncount; i++) {
                    dat->x[i] = (double) (CCutil_lprand () % (*ncount));
                    dat->y[i] = (double) (CCutil_lprand () % (*ncount));
                    dat->z[i] = (double) (CCutil_lprand () % (*ncount));
                }
            } else if (innorm == CC_GEOGRAPHIC) {
                for (i = 0; i < *ncount; i++) {
                    dat->x[i] = (double) (CCutil_lprand () % 180) - 90.0;
                    dat->y[i] = (double) (CCutil_lprand () % 360) - 180.0;
                }
            } else {
                int **hit = (int **) NULL;
                int *hitcount = (int *) NULL;
                int winner, x, y;

                hit      = CC_SAFE_MALLOC (*ncount, int *);
                hitcount = CC_SAFE_MALLOC (*ncount, int);
                if (!hit || !hitcount) {
                    fprintf (stderr, "out of memory in getdata\n");
                    CC_IFFREE (hit, int *);
                    CC_IFFREE (hitcount, int);
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }

                for (i = 0; i < *ncount; i++) {
                    hit[i] = (int *) NULL;
                    hitcount[i] = 0;
                }

                for (i = 0; i < *ncount; i++) {
                    winner = 0;
                    do {
                        x = CCutil_lprand () % (*ncount);
                        y = CCutil_lprand () % (*ncount);
                        for (j = 0; j < hitcount[x]; j++) {
                            if (hit[x][j] == y) break;
                        }
                        if (j == hitcount[x]) {
                            if (CCutil_reallocrus_count ((void **) &(hit[x]),
                                     hitcount[x] + 1, sizeof (int))) {
                                fprintf (stderr, "reallocrus_count failed\n");
                                for (i = 0; i < *ncount; i++) {
                                    CC_IFFREE (hit[i], int);
                                }
                                CC_IFFREE (hit, int *);
                                CC_IFFREE (hitcount, int);
                                CCutil_freedatagroup (*ncount, dat);
                                return 1;
                            }
                            hit[x][hitcount[x]] = y;
                            hitcount[x]++;
                            winner = 1;
                        }
                        if (!winner) {
                            printf ("X"); fflush (stdout);
                        }
                    } while (!winner);
                    dat->x[i] = (double) x;
                    dat->y[i] = (double) y;
                }
                for (i = 0; i < *ncount; i++) {
                    CC_IFFREE (hit[i], int);
                }
                CC_IFFREE (hit, int *);
                CC_IFFREE (hitcount, int);
            }
        }
    } else if ((innorm & CC_NORM_SIZE_BITS) == CC_MATRIX_NORM_SIZE){
        if (datname != (char *) NULL) {
            /* Matrix is the lower triangle plus the diagonal */
            if (binary_in) {
                CC_SFILE *f = CCutil_sopen (datname, "r");
                if (f == (CC_SFILE *) NULL)
                    return 1;
                if (CCutil_sread_int (f, (unsigned int *) ncount)) {
                    CCutil_sclose (f);
                    return 1;
                }
                printf ("nnodes = %d\n", *ncount);
                fflush (stdout);
                dat->adj = CC_SAFE_MALLOC (*ncount, int *);
                if (!dat->adj) {
                    if (CCutil_sclose (f))
                        fprintf (stderr, "Could not close file\n");
                    return 1;
                }
                for (i = 0; i < *ncount; i++)
                    dat->adj[i] = (int *) NULL;
                for (i = 0; i < *ncount; i++) {
                    dat->adj[i] = CC_SAFE_MALLOC (i + 1, int);
                    if (!dat->adj[i]) {
                        CCutil_freedatagroup (*ncount, dat);
                        if (CCutil_sclose (f))
                            fprintf (stderr, "Could not close file\n");
                        return 1;
                    }
                }
                for (i = 0; i < *ncount; i++) {
                    for (j = 0; j <= i; j++) {
                        if (CCutil_sread_int (f,
                            (unsigned int *) &(dat->adj[i][j]))) {
                            CCutil_sclose (f);
                            CCutil_freedatagroup (*ncount, dat);
                            return 1;
                        }
                    }
                }
                if (CCutil_sclose (f)) {
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
            } else {
                FILE *datin = fopen (datname, "r");
                if (datin == (FILE *) NULL) {
                    perror (datname);
                    fprintf (stderr, "Unable to open %s for input\n", datname);
                    return 1;
                }
                *ncount = CCutil_readint (datin);
                printf ("nnodes = %d\n", *ncount);
                dat->adj = CC_SAFE_MALLOC (*ncount, int *);
                if (!dat->adj) {
                    fclose (datin);
                    return 1;
                }
                for (i = 0; i < *ncount; i++)
                    dat->adj[i] = (int *) NULL;
                for (i = 0; i < *ncount; i++) {
                    dat->adj[i] = CC_SAFE_MALLOC (i + 1, int);
                    if (!dat->adj[i]) {
                        CCutil_freedatagroup (*ncount, dat);
                        fclose (datin);
                        return 1;
                    }
                }
                for (i = 0; i < *ncount; i++) {
                    for (j = 0; j <= i; j++) {
                        dat->adj[i][j] = CCutil_readint (datin);
                    }
                }

                fclose (datin);
            }
        } else {
            printf ("Complete graph with %d nodes and random edge lengths\n",
                    *ncount);
            fflush (stdout);
            dat->adj = CC_SAFE_MALLOC (*ncount, int *);
            if (!dat->adj)
                return 1;
            for (i = 0; i < *ncount; i++)
                dat->adj[i] = (int *) NULL;
            for (i = 0; i < *ncount; i++) {
                dat->adj[i] = CC_SAFE_MALLOC (i + 1, int);
                if (!dat->adj[i]) {
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
            }
            for (i = 0; i < *ncount; i++) {
                for (j = 0; j < i; j++)
                    dat->adj[i][j] =
                        CCutil_lprand () % (MATRAND_SCALE * (*ncount));
                dat->adj[i][i] = 0;
            }
        }
    } else if (innorm == CC_DSJRANDNORM) {
        int maxdist, seed;
        dat->x = CC_SAFE_MALLOC (*ncount, double);
        if (!dat->x)
            return 1;
        for (i = 0; i < *ncount; i++)
            dat->x[i] = 0x12345672*(i+1) + 1;
        if (datname != (char *) NULL) {
            FILE *datin = fopen (datname, "r");
            if (datin == (FILE *) NULL) {
                perror (datname);
                fprintf (stderr, "Unable to open %s for input\n", datname);
                return 1;
            }
            fscanf (datin, "%d", &seed);
            fscanf (datin, "%d", &maxdist);
            fclose (datin);
        } else {
            seed = 1;
            maxdist = 1000000;
        }
        CCutil_dsjrand_init (maxdist, seed);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_writemaster (char *mastername, int ncount, CCdatagroup *dat,
            int *perm)
#else
int CCutil_writemaster (mastername, ncount, dat, perm)
char *mastername;
int ncount;
CCdatagroup *dat;
int *perm;
#endif
{
    CC_SFILE *out = (CC_SFILE *) NULL;
    int i, j;

    if (mastername == (char *) NULL) {
        fprintf (stderr, "writemaster needs a filename\n");
        return 1;
    }

    out = CCutil_sopen (mastername, "w");
    if (out == (CC_SFILE *) NULL) {
        fprintf (stderr, "Unable to open %s for output\n", mastername);
        return 1;
    }

    if (CCutil_swrite_int (out, (unsigned int) ncount)) {
        CCutil_sclose (out);
        return 1;
    }

    if (dat) {
        if (CCutil_swrite_int (out, (unsigned int) CC_MASTER_DAT)) {
            CCutil_sclose (out);
            return 1;
        }
        if (CCutil_swrite_int (out, (unsigned int) dat->norm)) {
            CCutil_sclose (out);
            return 1;
        }

        if (dat->norm == CC_CRYSTAL) {
            for (i = 0; i < ncount; i++) {
                if (CCutil_swrite_double (out, dat->x[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
                if (CCutil_swrite_double (out, dat->y[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
                if (CCutil_swrite_double (out, dat->z[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
            }
        } else if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_D2_NORM_SIZE) {
            for (i = 0; i < ncount; i++) {
                if (CCutil_swrite_double (out, dat->x[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
                if (CCutil_swrite_double (out, dat->y[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
            }
        } else if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
            for (i = 0; i < ncount; i++) {
                if (CCutil_swrite_double (out, dat->x[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
                if (CCutil_swrite_double (out, dat->y[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
                if (CCutil_swrite_double (out, dat->z[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
            }
        } else if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_MATRIX_NORM_SIZE){
            /* Matrix is the lower triangle plus the diagonal */
            for (i = 0; i < ncount; i++) {
                for (j = 0; j <= i; j++) {
                    if (CCutil_swrite_int (out,
                                (unsigned int) dat->adj[i][j])) {
                        CCutil_sclose (out);
                        return 1;
                    }
                }
            }
        } else if (dat->norm == CC_DSJRANDNORM) {
            for (i = 0; i < ncount; i++) {
                if (CCutil_swrite_double (out, dat->x[i])) {
                    CCutil_sclose (out);
                    return 1;
                }
            }
        } else {
            fprintf (stderr, "unknown norm: %d\n", dat->norm);
            return 1;
        }
    } else {
        if (CCutil_swrite_int (out, (unsigned int) CC_MASTER_NO_DAT)) {
            CCutil_sclose (out);
            return 1;
        }
    }

    for (i = 0; i < ncount; i++) {
        if (perm[i] < 0 || perm[i] >= ncount) {
            fprintf (stderr, "permutation in wrong format\n");
            CCutil_sclose (out);
            return 1;
        }
        if (CCutil_swrite_int (out, (unsigned int) perm[i])) {
            CCutil_sclose (out);
            return 1;
        }
    }

    CCutil_sclose (out);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_getmaster (char *mastername, int *ncount, CCdatagroup *dat,
            int **perm)
#else
int CCutil_getmaster (mastername, ncount, dat, perm)
char *mastername;
int *ncount;
CCdatagroup *dat;
int **perm;
#endif
{
    CC_SFILE *in = (CC_SFILE *) NULL;
    int i, j;
    int havedat = 0;

    *ncount = 0;
    dat->x = (double *) NULL;
    dat->y = (double *) NULL;
    dat->z = (double *) NULL;
    dat->adj = (int **) NULL;
    dat->norm = 0;
    *perm = (int *) NULL;

    if (mastername == (char *) NULL) {
        fprintf (stderr, "getmaster needs a filename\n");
        return 1;
    }

    in = CCutil_sopen (mastername, "r");
    if (in == (CC_SFILE *) NULL) {
        fprintf (stderr, "Unable to open %s for input\n", mastername);
        return 1;
    }

    if (CCutil_sread_int (in, (unsigned int *) ncount)) {
        CCutil_sclose (in);
        return 1;
    }

    if (CCutil_sread_int (in, (unsigned int *) &havedat)) {
        CCutil_sclose (in);
        return 1;
    }

    if (havedat == CC_MASTER_DAT) {
        if (CCutil_sread_int (in, (unsigned int *) &(dat->norm))) {
            CCutil_sclose (in);
            return 1;
        }

        if (dat->norm == CC_CRYSTAL) {
            dat->x = CC_SAFE_MALLOC (*ncount, double);
            dat->y = CC_SAFE_MALLOC (*ncount, double);
            dat->z = CC_SAFE_MALLOC (*ncount, double);
            if (!dat->x || !dat->y || !dat->z) {
                fprintf (stderr, "out of memory in getmaster\n");
                goto CLEANUP;
            }
            for (i = 0; i < *ncount; i++) {
                if (CCutil_sread_double (in, &(dat->x[i]))) goto CLEANUP;
                if (CCutil_sread_double (in, &(dat->y[i]))) goto CLEANUP;
                if (CCutil_sread_double (in, &(dat->z[i]))) goto CLEANUP;
            }
        } else if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_D2_NORM_SIZE) {
            dat->x = CC_SAFE_MALLOC (*ncount, double);
            dat->y = CC_SAFE_MALLOC (*ncount, double);
            if (!dat->x || !dat->y) {
                fprintf (stderr, "out of memory in getmaster\n");
                goto CLEANUP;
            }
            for (i = 0; i < *ncount; i++) {
                if (CCutil_sread_double (in, &(dat->x[i]))) goto CLEANUP;
                if (CCutil_sread_double (in, &(dat->y[i]))) goto CLEANUP;
            }
        } else if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_D3_NORM_SIZE) {
            dat->x = CC_SAFE_MALLOC (*ncount, double);
            dat->y = CC_SAFE_MALLOC (*ncount, double);
            dat->z = CC_SAFE_MALLOC (*ncount, double);
            if (!dat->x || !dat->y || !dat->z) {
                fprintf (stderr, "out of memory in getmaster\n");
                goto CLEANUP;
            }
            for (i = 0; i < *ncount; i++) {
                if (CCutil_sread_double (in, &(dat->x[i]))) goto CLEANUP;
                if (CCutil_sread_double (in, &(dat->y[i]))) goto CLEANUP;
                if (CCutil_sread_double (in, &(dat->z[i]))) goto CLEANUP;
            }
        } else if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_MATRIX_NORM_SIZE){
            /* Matrix is the lower triangle plus the diagonal */

            dat->adj = CC_SAFE_MALLOC (*ncount, int *);
            if (!dat->adj) goto CLEANUP;
            for (i = 0; i < *ncount; i++)
                dat->adj[i] = (int *) NULL;

            for (i = 0; i < *ncount; i++) {
                dat->adj[i] = CC_SAFE_MALLOC (i + 1, int);
                if (!dat->adj[i]) goto CLEANUP;
                for (j = 0; j <= i; j++) {
                    if (CCutil_sread_int (in,
                          (unsigned int *) &(dat->adj[i][j]))) {
                        goto CLEANUP;
                    }
                }
            }
        } else if (dat->norm == CC_DSJRANDNORM) {
            dat->x = CC_SAFE_MALLOC (*ncount, double);
            if (!dat->x) {
                fprintf (stderr, "out of memory in getmaster\n");
                goto CLEANUP;
            }
            for (i = 0; i < *ncount; i++) {
                if (CCutil_sread_double (in, &(dat->x[i]))) goto CLEANUP;
            }
        } else {
            fprintf (stderr, "unknown norm: %d\n", dat->norm);
            goto CLEANUP;
        }
    }

    *perm = CC_SAFE_MALLOC (*ncount, int);
    if (!(*perm))  {
        fprintf (stderr, "out of memory in getmaster\n");
        goto CLEANUP;
    }

    for (i = 0; i < *ncount; i++) {
        if (CCutil_sread_int (in, (unsigned int *) &((*perm)[i]))) goto CLEANUP;
    }

    CCutil_sclose (in);
    return 0;

CLEANUP:

    CC_IFFREE (*perm, int);
    CC_IFFREE (dat->x, double);
    CC_IFFREE (dat->y, double);
    CC_IFFREE (dat->z, double);
    if (dat->adj) {
        for (i = 0; i < *ncount; i++) {
            CC_IFFREE (dat->adj[i], int);
        }
        CC_FREE (dat->adj, int *);
    }

    CCutil_sclose (in);
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_getnodeweights (char *weightname, int ncount, int weight_limit,
                    double **wcoord)
#else
int CCutil_getnodeweights (weightname, ncount, weight_limit, wcoord)
char *weightname;
int ncount, weight_limit;
double **wcoord;
#endif
{
    int i, k;

    *wcoord = CC_SAFE_MALLOC (ncount, double);
    if (!(*wcoord))
        return 1;
    if (weightname != (char *) NULL) {
        FILE *weightin = fopen (weightname, "r");
        if (weightin == (FILE *) NULL) {
            perror (weightname);
            fprintf (stderr, "Unable to open %s for input\n", weightname);
            CC_FREE (*wcoord, double);
            return 1;
        }
        fscanf (weightin, "%d", &k);
        if (k != ncount) {
            fprintf (stderr, "Weight file does not match node file\n");
            fclose (weightin);
            CC_FREE (*wcoord, double);
            return 1;
        }
        for (i = 0; i < k; i++) {
            fscanf (weightin, "%lf", &((*wcoord)[i]));
        }
        make_weights_nonnegative (ncount, *wcoord);
        fclose (weightin);
    } else {
        for (i = 0; i < ncount; i++)
            (*wcoord)[i] = (double) (CCutil_lprand () % (weight_limit));
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void make_weights_nonnegative (int ncount, double *wcoord)
#else
static void make_weights_nonnegative (ncount, wcoord)
int ncount;
double *wcoord;
#endif
{
    int i;
    double minx;

    minx = wcoord[0];

    for (i = 1; i < ncount; i++) {
        if (wcoord[i] < minx)
            minx = wcoord[i];
    }
    if (minx < 0.0) {
        printf ("****WARNING**** Adjusting node weights by %f\n", minx);
        for (i = 0; i < ncount; i++)
            wcoord[i] -= minx;
    }
}

#define MATRIX_LOWER_DIAG_ROW  0
#define MATRIX_UPPER_ROW       1
#define MATRIX_UPPER_DIAG_ROW  2
#define MATRIX_FULL_MATRIX     3

#ifdef CC_PROTOTYPE_ANSI
int CCutil_gettsplib (char *datname, int *ncount, CCdatagroup *dat)
#else
int CCutil_gettsplib (datname, ncount, dat)
char *datname;
int *ncount;
CCdatagroup *dat;
#endif
{
    char buf[256], key[256], field[256];
    char *p;
    FILE *in;
    int matrixform = MATRIX_LOWER_DIAG_ROW;

    dat->x = (double *) NULL;
    dat->y = (double *) NULL;
    dat->z = (double *) NULL;
    dat->adj = (int **) NULL;
    dat->norm = -1;
    *ncount = -1;

    if ((in = fopen (datname, "r")) == (FILE *) NULL) {
        perror (datname);
        fprintf (stderr, "Unable to open %s for input\n", datname);
        return 1;
    }

    while (fgets (buf, 254, in) != (char *) NULL) {
        p = buf;
        while (*p != '\0') {
            if (*p == ':')
                *p = ' ';
            p++;
        }
        p = buf;
        if (sscanf (p, "%s", key) != EOF) {
            p += strlen (key);
            while (*p == ' ')
                p++;
            if (!strcmp (key, "NAME")) {
                printf ("Problem Name: %s", p);
            } else if (!strcmp (key, "TYPE")) {
                printf ("Problem Type: %s", p);
                if (sscanf (p, "%s", field) == EOF || strcmp (field, "TSP")) {
                    fprintf (stderr, "Not a TSP problem\n");
                    return 1;
                }
            } else if (!strcmp (key, "COMMENT")) {
                printf ("%s", p);
            } else if (!strcmp (key, "DIMENSION")) {
                if (sscanf (p, "%s", field) == EOF) {
                    fprintf (stderr, "ERROR in DIMENSION line\n");
                    return 1;
                }
                *ncount = atoi (field);
                printf ("Number of Nodes: %d\n", *ncount);
            } else if (!strcmp (key, "EDGE_WEIGHT_TYPE")) {
                if (sscanf (p, "%s", field) == EOF) {
                    fprintf (stderr, "ERROR in EDGE_WEIGHT_TYPE line\n");
                    return 1;
                }
                if (!strcmp (field, "EXPLICIT")) {
                    dat->norm = CC_MATRIXNORM;
                    printf ("Explicit Lengths (CC_MATRIXNORM)\n");
                } else if (!strcmp (field, "EUC_2D")) {
                    dat->norm = CC_EUCLIDEAN;
                    printf ("Rounded Euclidean Norm (CC_EUCLIDEAN)\n");
                } else if (!strcmp (field, "EUC_3D")) {
                    dat->norm = CC_EUCLIDEAN_3D;
                    printf ("Rounded Euclidean 3D Norm (CC_EUCLIDEAN_3D)\n");
                } else if (!strcmp (field, "MAX_2D")) {
                    dat->norm = CC_MAXNORM;
                    printf ("Max Norm (CC_MAXNORM)\n");
                } else if (!strcmp (field, "GEO")) {
                    dat->norm = CC_GEOGRAPHIC;
                    printf ("Geographical Norm (CC_GEOGRAPHIC)\n");
                } else if (!strcmp (field, "ATT")) {
                    dat->norm = CC_ATT;
                    printf ("ATT Norm (ATT)\n");
                } else if (!strcmp (field, "CEIL_2D")) {
                    dat->norm = CC_EUCLIDEAN_CEIL;
                    printf ("Rounded Up Euclidean Norm (CC_EUCLIDEAN_CEIL)\n");
                } else {
                    fprintf (stderr, "ERROR: Not set up for norm %s\n", field);
                    return 1;
                }
            } else if (!strcmp (key, "EDGE_WEIGHT_FORMAT")) {
                if (sscanf (p, "%s", field) == EOF) {
                    fprintf (stderr, "ERROR in EDGE_WEIGHT_FORMAT line\n");
                    return 1;
                }
                if (!strcmp (field, "LOWER_DIAG_ROW")) {
                    matrixform = MATRIX_LOWER_DIAG_ROW;
                } else if (!strcmp (field, "UPPER_ROW")) {
                    matrixform = MATRIX_UPPER_ROW;
                } else if (!strcmp (field, "UPPER_DIAG_ROW")) {
                    matrixform = MATRIX_UPPER_DIAG_ROW;
                } else if (!strcmp (field, "FULL_MATRIX")) {
                    matrixform = MATRIX_FULL_MATRIX;
                } else if (strcmp (field, "FUNCTION")) {
                    fprintf (stderr, "Cannot handle format: %s\n", field);
                    return 1;
                }
            } else if (!strcmp (key, "NODE_COORD_SECTION")) {
                int i;
                if (*ncount <= 0) {
                    fprintf (stderr, "ERROR: Dimension not specified\n");
                    return 1;
                }
                if (dat->x != (double *) NULL) {
                    fprintf (stderr, "ERROR: A second NODE_COORD_SECTION?\n");
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
                if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_D2_NORM_SIZE) {
                    dat->x = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->x) {
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    dat->y = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->y) {
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    for (i = 0; i < *ncount; i++) {
                        fscanf (in, "%*d %lf %lf", &(dat->x[i]), &(dat->y[i]));
                    }
                } else if (((dat->norm) & CC_NORM_SIZE_BITS) ==
                                            CC_D3_NORM_SIZE) {
                    dat->x = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->x) {
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    dat->y = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->y) {
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    dat->z = CC_SAFE_MALLOC (*ncount, double);
                    if (!dat->z) {
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    for (i = 0; i < *ncount; i++) {
                        fscanf (in, "%*d %lf %lf %lf",
                               &(dat->x[i]), &(dat->y[i]), &(dat->z[i]));
                    }
                } else {
                    fprintf (stderr, "ERROR: Node coordinates with norm %d?\n",
                                 dat->norm);
                    return 1;
                }
            } else if (!strcmp (key, "EDGE_WEIGHT_SECTION")) {
                int i, j;
                if (*ncount <= 0) {
                    fprintf (stderr, "ERROR: Dimension not specified\n");
                    return 1;
                }
                if (dat->adj != (int **) NULL) {
                    fprintf (stderr, "ERROR: A second NODE_COORD_SECTION?\n");
                    CCutil_freedatagroup (*ncount, dat);
                    return 1;
                }
                if (((dat->norm) & CC_NORM_SIZE_BITS) == CC_MATRIX_NORM_SIZE) {
                    dat->adj = CC_SAFE_MALLOC (*ncount, int *);
                    if (!dat->adj) {
                        CCutil_freedatagroup (*ncount, dat);
                        return 1;
                    }
                    if (matrixform == MATRIX_LOWER_DIAG_ROW) {
                        for (i = 0; i < *ncount; i++) {
                            dat->adj[i] = CC_SAFE_MALLOC (i + 1, int);
                            if (!dat->adj[i]) {
                                CCutil_freedatagroup (*ncount, dat);
                                return 1;
                            }
                            for (j = 0; j <= i; j++)
                                fscanf (in, "%d", &(dat->adj[i][j]));
                        }
                    } else if (matrixform == MATRIX_UPPER_ROW ||
                               matrixform == MATRIX_UPPER_DIAG_ROW ||
                               matrixform == MATRIX_FULL_MATRIX) {
                        int **tempadj;
                        tempadj = CC_SAFE_MALLOC (*ncount, int *);
                        if (!tempadj) {
                            CCutil_freedatagroup (*ncount, dat);
                            return 1;
                        }
                        for (i = 0; i < *ncount; i++) {
                            tempadj[i] = CC_SAFE_MALLOC (*ncount, int);
                            if (!tempadj[i]) {
                                CCutil_freedatagroup (*ncount, dat);
                                for (j = 0; j < i; j++)
                                    CC_FREE (tempadj[j], int);
                                CC_FREE (tempadj, int *);
                                return 1;
                            }
                            if (matrixform == MATRIX_UPPER_ROW) {
                                tempadj[i][i] = 0;
                                for (j = i + 1; j < *ncount; j++)
                                    fscanf (in, "%d", &(tempadj[i][j]));
                            } else if (matrixform == MATRIX_UPPER_DIAG_ROW) {
                                for (j = i; j < *ncount; j++)
                                    fscanf (in, "%d", &(tempadj[i][j]));
                            } else {
                                for (j = 0; j < *ncount; j++)
                                    fscanf (in, "%d", &(tempadj[i][j]));
                            }
                        }
                        for (i = 0; i < *ncount; i++) {
                            dat->adj[i] = CC_SAFE_MALLOC (i + 1, int);
                            if (!dat->adj[i]) {
                                CCutil_freedatagroup (*ncount, dat);
                                for (j = 0; j < *ncount; j++)
                                    CC_FREE (tempadj[j], int);
                                CC_FREE (tempadj, int *);
                                return 1;
                            }
                            for (j = 0; j <= i; j++)
                                dat->adj[i][j] = tempadj[j][i];
                        }
                        for (i = 0; i < *ncount; i++)
                            CC_FREE (tempadj[i], int);
                        CC_FREE (tempadj, int *);
                    }
                } else {
                    fprintf (stderr, "ERROR: Matrix with norm %d?\n",
                             dat->norm);
                    return 1;
                }
            } else if (!strcmp (key, "FIXED_EDGES_SECTION")) {
                fprintf (stderr, "ERROR: Not set up for fixed edges\n");
                return 1;
            }
        }
    }
    fclose (in);

    if (dat->x == (double *) NULL && dat->adj == (int **) NULL) {
        fprintf (stderr, "ERROR: Didn't find the data\n");
        return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_datagroup_perm (int ncount, CCdatagroup *dat, int *perm)
#else
int CCutil_datagroup_perm (ncount, dat, perm)
int ncount;
CCdatagroup *dat;
int *perm;
#endif
{
    int i, j;

    if (dat->x != (double *) NULL) {
        double *tempx;

        tempx = CC_SAFE_MALLOC (ncount, double);
        if (!tempx)
            return 1;
        for (i = 0; i < ncount; i++) {
            tempx[i] = dat->x[perm[i]];
        }
        CC_FREE (dat->x, double);
        dat->x = tempx;
    }
    if (dat->y != (double *) NULL) {
        double *tempy;

        tempy = CC_SAFE_MALLOC (ncount, double);
        if (!tempy)
            return 1;
        for (i = 0; i < ncount; i++) {
            tempy[i] = dat->y[perm[i]];
        }
        CC_FREE (dat->y, double);
        dat->y = tempy;
    }
    if (dat->z != (double *) NULL) {
        double *tempz;

        tempz = CC_SAFE_MALLOC (ncount, double);
        if (!tempz)
            return 1;
        for (i = 0; i < ncount; i++) {
            tempz[i] = dat->z[perm[i]];
        }
        CC_FREE (dat->z, double);
        dat->z = tempz;
    }
    if (dat->adj != (int **) NULL) {
        int **tempadj;

        tempadj = CC_SAFE_MALLOC (ncount, int *);
        if (!tempadj)
            return 1;

        for (i = 0; i < ncount; i++) {
            tempadj[i] = CC_SAFE_MALLOC (i + 1, int);
            if (!tempadj[i]) {
                for (j = 0; j < i; j++) {
                    CC_FREE (tempadj[j], int);
                }
                CC_FREE (tempadj, int *);
                return 1;
            }
            for (j = 0; j <= i; j++) {
                if (perm[i] <  perm[j])
                    tempadj[i][j] = dat->adj[perm[j]][perm[i]];
                else
                    tempadj[i][j] = dat->adj[perm[i]][perm[j]];
            }
        }
        for (i = 0; i < ncount; i++)
            CC_FREE (dat->adj[i], int);
        CC_FREE (dat->adj, int *);
        dat->adj = tempadj;
    }
    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
int CCutil_getedgelist (int ncount, char *fname, int *ecount, int **elist,
            int **elen)
#else
int CCutil_getedgelist (ncount, fname, ecount, elist, elen)
int ncount;
char *fname;
int *ecount, **elist, **elen;
#endif
{
    int k;

    if (CCutil_getedgelist_n (&k, fname, ecount, elist, elen)) {
        fprintf (stderr, "CCutil_getedgelist_n failed\n");
        return 1;
    }

    if (k != ncount) {
        fprintf (stderr, "Edge file does not match problem\n");
        return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_getedgelist_n (int *ncount, char *fname, int *ecount, int **elist,
                   int **elen)
#else
int CCutil_getedgelist_n (ncount, fname, ecount, elist, elen)
int *ncount;
char *fname;
int *ecount, **elist, **elen;
#endif
{
    FILE *in;
    int i, k;

    *elist = (int *) NULL;
    *elen = (int *) NULL;

    if ((in = fopen (fname, "r")) == (FILE *) NULL) {
        perror (fname);
        fprintf (stderr, "Unable to open %s for input\n", fname);
        return 1;
    }

    k = CCutil_readint (in);
    *ncount = k;
    *ecount = CCutil_readint (in);

    *elist = CC_SAFE_MALLOC(2 * (*ecount), int);
    if (!(*elist)) {
        fprintf (stderr, "out of memory in getedgelist\n");
        fclose (in);
        return 1;
    }
    *elen = CC_SAFE_MALLOC(*ecount, int);
    if (!(*elen)) {
        fprintf (stderr, "out of memory in getedgelist\n");
        CC_FREE (*elist, int);
        fclose (in);
        return 1;
    }

    for (i = 0, k = 0; i < *ecount; i++) {
        (*elist)[k++] = CCutil_readint (in);
        (*elist)[k++] = CCutil_readint (in);
        (*elen)[i] = CCutil_readint (in);
    }

    fclose (in);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_getcycle_edgelist (int ncount, char *cyclename, int *outcycle)
#else
int CCutil_getcycle_edgelist (ncount, cyclename, outcycle)
int ncount;
char *cyclename;
int *outcycle;
#endif
{
    FILE *cycin = fopen (cyclename, "r");
    int *elist = (int *) NULL;
    int i, k;

    if (cycin == (FILE *) NULL) {
        perror (cyclename);
        fprintf (stderr, "Unable to open %s for input\n", cyclename);
        return 1;
    }
    elist = CC_SAFE_MALLOC (2 * ncount, int);
    if (!elist) {
        fclose (cycin);
        return 1;
    }

    fscanf (cycin, "%d %d", &i, &k);
    if (i != ncount || k != ncount) {
        fprintf (stderr, "file is not a cycle-edge file for this problem\n");
        CC_FREE (elist, int);
        fclose (cycin);
        return 1;
    }

    for (i = 0; i < ncount; i++)
        fscanf (cycin, "%d %d %*d", &(elist[2 * i]), &(elist[(2 * i) + 1]));

    if (CCutil_edge_to_cycle (ncount, elist, outcycle)) {
        fprintf (stderr, "CCutil_edge_to_cycle failed\n");
        CC_FREE (elist, int);
        fclose (cycin);
        return 1;
    }

    CC_FREE (elist, int);
    fclose (cycin);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_getcycle (int ncount, char *cyclename, int *outcycle)
#else
int CCutil_getcycle (ncount, cyclename, outcycle)
int ncount;
char *cyclename;
int *outcycle;
#endif
{
    FILE *cycin = fopen (cyclename, "r");
    int i;

    if (cycin == (FILE *) NULL) {
        perror (cyclename);
        fprintf (stderr, "Unable to open %s for input\n", cyclename);
        return 1;
    }

    i = CCutil_readint (cycin);
    if (i != ncount) {
        fprintf (stderr, "Cycle files has wrong number of nodes\n");
        return 1;
    }
    for (i = 0; i < ncount; i++)
        outcycle[i] = CCutil_readint (cycin);

    fclose (cycin);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_getedges_double (int *ncount, char *fname, int *ecount, int **elist,
            double **elen, int binary_in)
#else
int CCutil_getedges_double (ncount, fname, ecount, elist, elen, binary_in)
int *ncount;
char *fname;
int *ecount, **elist;
double **elen;
int binary_in;
#endif
{
    int i, k;

    if (binary_in) {
        CC_SFILE *in;

        *elist = (int *) NULL;
        *elen = (double *) NULL;

        if ((in = CCutil_sopen (fname, "r")) == (CC_SFILE *) NULL) {
            fprintf (stderr, "Unable to open %s for input\n", fname);
            return 1;
        }

        if (CCutil_sread_int (in, (unsigned int *) ncount)) {
            CCutil_sclose (in);
            return 1;
        }

        if (CCutil_sread_int (in, (unsigned int *) ecount)) {
            CCutil_sclose (in);
            return 1;
        }

        *elist = CC_SAFE_MALLOC(2 * (*ecount), int);
        if (!(*elist)) {
            CCutil_sclose (in);
            return 1;
        }
        *elen = CC_SAFE_MALLOC(*ecount, double);
        if (!(*elen)) {
            CC_FREE (*elist, int);
            CCutil_sclose (in);
            return 1;
        }

        for (i = 0, k = 0; i < *ecount; i++) {
            if (CCutil_sread_int (in, (unsigned int *) &((*elist)[k++]))) {
                CCutil_sclose (in);
                return 1;
            }
            if (CCutil_sread_int (in, (unsigned int *) &((*elist)[k++]))) {
                CCutil_sclose (in);
                return 1;
            }
            if (CCutil_sread_double (in, &((*elen)[i]))) {
                CCutil_sclose (in);
                return 1;
            }
        }

        CCutil_sclose (in);
    } else {
        FILE *in;

        *elist = (int *) NULL;
        *elen = (double *) NULL;

        if ((in = fopen (fname, "r")) == (FILE *) NULL) {
            perror (fname);
            fprintf (stderr, "Unable to open %s for input\n", fname);
            return 1;
        }

        *ncount = CCutil_readint (in);
        *ecount = CCutil_readint (in);

        *elist = CC_SAFE_MALLOC(2 * (*ecount), int);
        if (!(*elist)) {
            fclose (in);
            return 1;
        }
        *elen = CC_SAFE_MALLOC(*ecount, double);
        if (!(*elen)) {
            CC_FREE (*elist, int);
            fclose (in);
            return 1;
        }

        for (i = 0, k = 0; i < *ecount; i++) {
            (*elist)[k++] = CCutil_readint (in);
            (*elist)[k++] = CCutil_readint (in);
            if (fscanf (in, "%lf", &((*elen)[i])) != 1) {
                fprintf (stderr, "input file is in the wrong format\n");
                fclose (in);
                return 1;
            }
        }

        fclose (in);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_writeedges (int ncount, char *outedgename, int ecount, int *elist,
            CCdatagroup *dat)
#else
int CCutil_writeedges (ncount, outedgename, ecount, elist, dat)
int ncount;
char *outedgename;
int ecount, *elist;
CCdatagroup *dat;
#endif
{
    FILE *out = fopen (outedgename, "w");
    int i;

    if (out == (FILE *) NULL) {
        perror (outedgename);
        fprintf (stderr, "Unable to open %s for output\n", outedgename);
        return 1;
    }

    fprintf (out, "%d %d\n", ncount, ecount);
    for (i = 0; i < ecount; i++) {
        fprintf (out, "%d %d %d\n", elist[2 * i], elist[(2 * i) + 1],
                CCutil_dat_edgelen (elist[2 * i], elist[(2 * i) + 1], dat));
    }
    fclose (out);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_writecycle_edgelist (int ncount, char *outedgename, int *cycle,
            CCdatagroup *dat)
#else
int CCutil_writecycle_edgelist (ncount, outedgename, cycle, dat)
int ncount;
char *outedgename;
int *cycle;
CCdatagroup *dat;
#endif
{
    FILE *out = fopen (outedgename, "w");
    int i;

    if (out == (FILE *) NULL) {
        perror (outedgename);
        fprintf (stderr, "Unable to open %s for output\n", outedgename);
        return 1;
    }

    fprintf (out, "%d %d\n", ncount, ncount);
    for (i = 1; i < ncount; i++) {
        fprintf (out, "%d %d %d\n", cycle[i - 1], cycle[i],
                    CCutil_dat_edgelen (cycle[i - 1], cycle[i], dat));
    }
    fprintf (out, "%d %d %d\n", cycle[ncount - 1], cycle[0],
                   CCutil_dat_edgelen (cycle[ncount - 1], cycle[0], dat));
    fclose (out);

    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
int CCutil_writecycle (int ncount, char *outcyclename, int *cycle)
#else
int CCutil_writecycle (ncount, outcyclename, cycle)
int ncount;
char *outcyclename;
int *cycle;
#endif
{
    FILE *cycout = fopen (outcyclename, "w");
    int i;

    if (cycout == (FILE *) NULL) {
        perror (outcyclename);
        fprintf (stderr, "Unable to open %s for output\n", outcyclename);
        return 1;
    }

    fprintf (cycout, "%d\n", ncount);
    for (i = 0; i < ncount; i++) {
        fprintf (cycout, "%d ", cycle[i]);
        if (i % 10 == 9)
            fprintf (cycout, "\n");
    }
    if (i % 10)
        fprintf (cycout, "\n");
    fclose (cycout);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_writeedges_double (int ncount, char *outedgename, int ecount,
                int *elist, double *elen, int binary_out)
#else
int CCutil_writeedges_double (ncount, outedgename, ecount, elist, elen, binary_out)
int ncount;
char *outedgename;
int ecount, *elist;
double *elen;
int binary_out;
#endif
{
    int i;

    if (binary_out) {
        CC_SFILE *out = CCutil_sopen (outedgename, "w");

        if (out == (CC_SFILE *) NULL) {
            fprintf (stderr, "Unable to open %s for output\n", outedgename);
            return 1;
        }

        if (CCutil_swrite_int (out, (unsigned int) ncount)) {
            CCutil_sclose (out);
            return 1;
        }
        if (CCutil_swrite_int (out, (unsigned int) ecount)) {
            CCutil_sclose (out);
            return 1;
        }

        for (i = 0; i < ecount; i++) {
            if (CCutil_swrite_int (out, (unsigned int) elist[2 * i])) {
                CCutil_sclose (out);
                return 1;
            }
            if (CCutil_swrite_int (out, (unsigned int) elist[(2 * i) + 1])) {
                CCutil_sclose (out);
                return 1;
            }
            if (CCutil_swrite_double (out, elen[i])) {
                CCutil_sclose (out);
                return 1;
            }
        }
        CCutil_sclose (out);
    } else {
        FILE *out = fopen (outedgename, "w");

        if (out == (FILE *) NULL) {
            perror (outedgename);
            fprintf (stderr, "Unable to open %s for output\n", outedgename);
            return 1;
        }

        fprintf (out, "%d %d\n", ncount, ecount);
        for (i = 0; i < ecount; i++) {
            fprintf (out, "%d %d %f\n", elist[2 * i], elist[(2 * i) + 1],
                                        elen[i]);
        }
        fclose (out);
    }

    return 0;
}



/* The crystal functions are based on David Shallcross's fortran code */

#define CRYSTAL_SCALE 10000

typedef struct three_d {
    double phi;
    double chi;
    double twoth;
} three_d;


#ifdef CC_PROTOTYPE_ANSI

static void
    cry_quicksort (three_d *x, int l, int u),
    cryswap (three_d *x, three_d *y);
static int
    point_compare (three_d *x, three_d *y),
    crygenpts (double orient[3][3], double lambda, int bounds[3][2]),
    cryangles (int h, int k, int l, double orient[3][3], double lambda,
            double omega, double *phi, double *chi, double *twoth);
static double
    userint (double f);

#else

static void
    cry_quicksort (),
    cryswap ();
static int
    point_compare (),
    crygenpts (),
    cryangles ();
static double
    userint ();

#endif


static three_d *crypoints = (three_d *) NULL;
static int ncrypoints = 0;

#define CRY_MIN_ORIENT -0.2    /* For random problems */
#define CRY_MAX_ORIENT  0.2

#define CRY_MIN_BOUND  10
#define CRY_MAX_BOUND  20

#define CRY_1_00_CUTOFF 15000
#define CRY_1_35_CUTOFF 10000

#ifdef CC_PROTOTYPE_ANSI
static int read_crystal (char *datname, int *ncount, CCdatagroup *dat)
#else
static int read_crystal (datname, ncount, dat)
char *datname;
int *ncount;
CCdatagroup *dat;
#endif
{
    FILE *datin;
    double lambda;
    double orient[3][3];
    int bounds[3][2];
    int i, j;

    if (!datname) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                orient[i][j] = CRY_MIN_ORIENT +
                   ((CRY_MAX_ORIENT - CRY_MIN_ORIENT) *
                    ((double) (CCutil_lprand () % 1000) / 1000.0));
            }
        }
        for (i = 0; i < 3; i++) {
            bounds[i][1] = CRY_MIN_BOUND +
                       (CCutil_lprand () % (CRY_MAX_BOUND - CRY_MIN_BOUND + 1));
            bounds[i][0] = -bounds[i][1];
        }

        if (*ncount > CRY_1_00_CUTOFF)
            lambda = 1.0;
        else if (*ncount > CRY_1_35_CUTOFF)
            lambda = 1.35;
        else
            lambda = 1.70;

        printf ("Random crystal problem\n");
        printf ("Note that the number of nodes will not match the request\n");
        printf ("Orient:\n");
        for (i = 0; i < 3; i++)
            printf (" %.4f  %.4f  %.4f\n", orient[i][0], orient[i][1],
                                                         orient[i][2]);
        printf ("Bounds:\n");
        for (i = 0; i < 3; i++)
            printf (" %d %d ", bounds[i][0], bounds[i][1]);
        printf ("\nWavelength:\n");
            printf (" %.2f\n", lambda);
        fflush (stdout);
    } else {
        datin = fopen (datname, "r");
        if (datin == (FILE *) NULL) {
            perror (datname);
            fprintf (stderr, "Unable to open %s for input\n", datname);
            return 1;
        }

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                fscanf (datin, "%lf", &orient[i][j]);
            }
        }
        fscanf (datin, "%lf", &lambda);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 2; j++) {
                fscanf (datin, "%d", &(bounds[i][j]));
            }
        }
        fclose (datin);
    }

    if (crygenpts (orient, lambda, bounds)) {
        fprintf (stderr, "crygenpts failed\n");
        if (crypoints)
            CC_FREE (crypoints, three_d);
        return 1;
    }
    cry_quicksort (crypoints, 0, ncrypoints -1);
    printf ("Number of crystal points: %d\n", ncrypoints);

    dat->x = CC_SAFE_MALLOC (ncrypoints, double);
    if (!dat->x) {
        CC_FREE (crypoints, three_d);
        return 1;
    }
    dat->y = CC_SAFE_MALLOC (ncrypoints, double);
    if (!dat->y) {
        CC_FREE (crypoints, three_d);
        CCutil_freedatagroup (ncrypoints, dat);
        return 1;
    }
    dat->z = CC_SAFE_MALLOC (ncrypoints, double);
    if (!dat->z) {
        CC_FREE (crypoints, three_d);
        CCutil_freedatagroup (ncrypoints, dat);
        return 1;
    }

    for (i = 0; i < ncrypoints; i++) {
        dat->x[i] = userint (crypoints[i].chi * CRYSTAL_SCALE),
        dat->y[i] = userint (crypoints[i].phi * CRYSTAL_SCALE),
        dat->z[i] = userint (crypoints[i].twoth * CRYSTAL_SCALE);
    }
    *ncount = ncrypoints;

    if (crypoints)
        CC_FREE (crypoints, three_d);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int point_compare (three_d *x, three_d *y)
#else
static int point_compare (x, y)
three_d *x;
three_d *y;
#endif
{
    int del;

    del = (int) userint (x->chi * CRYSTAL_SCALE) -
          (int) userint (y->chi * CRYSTAL_SCALE);
    if (del)
        return del;
    del = (int) userint (x->phi * CRYSTAL_SCALE) -
          (int) userint (y->phi * CRYSTAL_SCALE);
    if (del)
        return del;
    del = (int) userint (x->twoth * CRYSTAL_SCALE) -
          (int) userint (y->twoth * CRYSTAL_SCALE);
    return del;
}

#ifdef CC_PROTOTYPE_ANSI
static double userint (double f)
#else
static double userint (f)
double f;
#endif
{
    double t;
    int u;

    if (f > 0.0) {
        u = (int) f;
        t = (double) u;
        return (f - t < 0.5 ? t : t + 1.0);
    } else {
        u = (int) f;
        t = (double) u;
        return (t - f < 0.5 ? t : t - 1.0);
    }
}


/* genpts builds points, the array of accessible points of the lattice */

#ifdef CC_PROTOTYPE_ANSI
static int crygenpts (double orient[3][3], double lambda, int bounds[3][2])
#else
static int crygenpts (orient, lambda, bounds)
double orient[3][3];
double lambda;
int bounds[3][2];
#endif
{
    int h, k, l;
    double p = 0.0, c = 0.0, t = 0.0;
    double minp = 360.0, minc = 180.0, mint = 155.0;
    double maxp = 0.0, maxc = -180.0, maxt = -55.0;

    ncrypoints = 0;

    crypoints = CC_SAFE_MALLOC (100000, three_d);
    if (!crypoints)
        return 1;

    for (h = bounds[0][0]; h <= bounds[0][1]; h++) {
        for (k = bounds[1][0]; k <= bounds[1][1]; k++) {
            for (l = bounds[2][0]; l <= bounds[2][1]; l++) {
                if (cryangles (h, k, l, orient, lambda, 0.0, &p, &c, &t)) {
                    crypoints[ncrypoints].phi = p;
                    crypoints[ncrypoints].chi = c;
                    crypoints[ncrypoints].twoth = t;
                    ncrypoints++;
                    if (p < minp)
                        minp = p;
                    if (p > maxp)
                        maxp = p;
                    if (c < minc)
                        minc = c;
                    if (c > maxc)
                        maxc = c;
                    if (t < mint)
                        mint = t;
                    if (t > maxt)
                        maxt = t;
                }
            }
        }
    }
    return 0;
}

/*
   angles computes positioning information for the detector given the
   miller indices.  (From Matt Small, April 5, 1984)
*/

#ifdef CC_PROTOTYPE_ANSI
static int cryangles (int h, int k, int l, double orient[3][3], double lambda,
                  double omega, double *phi, double *chi, double *twoth)
#else
static int cryangles (h, k, l, orient, lambda, omega, phi, chi, twoth)
int h, k, l;
double lambda, omega;
double orient[3][3];
double *phi, *chi, *twoth;
#endif
{
    /* The original had pi = 3.14159265368979; */
    static double pi = 3.14159265358979;
    double x, y, z, d, dum, cosomg, sinchi, sinphi, cosphi, q, r;
    double rh = h, rk = k, rl = l;
    double t1, t2, t3;

    omega = omega / 180.0 * pi;
    cosomg = cos (omega);

    x = orient[0][0] * rh + orient[0][1] * rk + orient[0][2] * rl;
    y = orient[1][0] * rh + orient[1][1] * rk + orient[1][2] * rl;
    z = orient[2][0] * rh + orient[2][1] * rk + orient[2][2] * rl;
    d = sqrt (x * x + y * y + z * z);
    dum = lambda * d / 2.0;
    if (dum < .000001 || dum >= 1.0) {
        return 0;
    }
    *twoth = asin (dum) * 2.0;
    t1 = x / d;
    t2 = y / d;
    t3 = z / d;
    if ((t3 < 0.0 ? -t3 : t3) >= (cosomg < 0.0 ? -cosomg : cosomg)) {
        return 0;
    }
    sinchi = -t3 / cosomg;
    *chi = asin (sinchi);
    q = sin (omega);
    r = cosomg * cos (*chi);
    cosphi = (q * t1 + r * t2) / (t1 * t1 + t2 * t2);
    sinphi = (r * t1 - q * t2) / (t1 * t1 + t2 * t2);
    if (sinphi <= -.7)
        *phi = -acos (cosphi);
    else if (sinphi >= .7)
        *phi = acos (cosphi);
    else if (cosphi <= 0.0)
        *phi = pi - asin (sinphi);
    else
        *phi = asin (sinphi);
    *phi *= 180.0 / pi;
    *chi *= 180.0 / pi;
    *twoth *= 180.0 / pi;
    *phi /= 1.25;   /* FOR VARYING MORTOR SPEEDS */
    *chi /= 1.5;
    *twoth /= 1.15;
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static void cry_quicksort (three_d *x, int l, int u)
#else
static void cry_quicksort (x, l, u)
three_d *x;
int l, u;
#endif
{
    int i, j;
    three_d *t;

    if (l >= u)
        return;

    cryswap (x + l, x + ((l+u)/2));

    i = l;
    j = u + 1;
    t = x + l;

    while (1) {
        do i++; while (i <= u && (point_compare (x + i, t) < 0));
        do j--; while (point_compare (x + j, t) > 0);
        if (j < i) break;
        cryswap (x + i, x + j);
    }
    cryswap (x + l, x + j);
    cry_quicksort (x, l, j - 1);
    cry_quicksort (x, i, u);
}

#ifdef CC_PROTOTYPE_ANSI
static void cryswap (three_d *x, three_d *y)
#else
static void cryswap (x, y)
three_d *x, *y;
#endif
{
    three_d t;

    t.phi = x->phi;
    t.chi = x->chi;
    t.twoth = x->twoth;

    x->phi = y->phi;
    x->chi = y->chi;
    x->twoth = y->twoth;

    y->phi = t.phi;
    y->chi = t.chi;
    y->twoth = t.twoth;
}
