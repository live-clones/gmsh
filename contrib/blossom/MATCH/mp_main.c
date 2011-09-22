/***************************************************************************/
/*                                                                         */
/*                TEST PROGRAM FOR PRICING MATCHINGS                       */
/*                                                                         */
/*  Written by:  D. Applegate, W. Cook, and A. Rohe                        */
/*  Date: August 1, 1996                                                   */
/*                                                                         */
/*  SEE short decsribtion in usage ().                                     */
/*                                                                         */
/*  Link with:                                                             */
/*     (see Makefile)                                                      */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/*     The dual file is a binary file that contains 3/2 ncount records.    */
/*   Each record is an int followed by a double. Each record corresponds   */
/*   to either a node, or a blossom, or wasted space. The node records     */
/*   are the initial ncount entries; the blossom and wasted records are    */
/*   mixed in the remaint ncount/2 records. The first entry of a record    */
/*   gives the index of the parent of the node or blossom in the nesting   */
/*   structure; it is -1 if there is no parent. The second entry is the    */
/*   dual value of the node or blossom. To determine which records are     */
/*   blossoms and which are wasted, you can trace the parent pointers of   */
/*   the node records to find the remaining records that are hit.          */
/*                                                                         */
/*     If a matching file is given, then the complementary slackness       */
/*   conditions will be checked. A matching file has the format of a       */
/*   standard edge file.                                                   */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "concorde.h"
#include "matprice.h"

static int norm = CC_EUCLIDEAN;
static char *dualfilename = (char *) NULL;
static char *datfilename = (char *) NULL;
static char *matfilename = (char *) NULL;
static char *badfilename = (char *) NULL;
static int binary_in = 0;
static int tsplib_in = 0;
static int seed = 0;

#ifdef  CC_PROTOTYPE_ANSI

int
    main (int ac, char **av);

static void
    usage (char *f);

static int
    parseargs (int ac, char **av),
    read_matching (char *fname, int ncount, int **matchlist,
                       CCdatagroup *dat),
    read_blossom_tree (char* blossom_tree_file, int ncount, double **pi,
                       int **parent);

#else  /* CC_PROTOTYPE_ANSI */

int
    main ();

static void
    usage ();

static int
    parseargs (),
    read_matching (),
    read_blossom_tree ();

#endif /* CC_PROTOTYPE_ANSI */


#ifdef  CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    double szeit;
    int ncount;
    double *pi = (double *) NULL;
    int *parent = (int *) NULL;
    CCdatagroup dat;
    int csbad = 0;
    int badcount = 0;
    int *badlist = (int *) NULL;
    int *badlen = (int *) NULL;
    int *matchlist = (int *) NULL;
    double penalty;
    int rval = 0;
    long l;
#ifdef  CC_PROTOTYPE_ANSI
    extern long time (long *);
#else
    extern long time ();
#endif

    seed = time (&l);
    if (parseargs (ac, av)) 
        return 0;
    CCutil_sprand (seed);

    if (datfilename == (char *) NULL || dualfilename == (char *) NULL) {
        usage (av[0]);
        return 0;
    }
    ncount = 0;

    szeit = CCutil_zeit ();
    if (tsplib_in) {
        if (CCutil_gettsplib (datfilename, &ncount, &dat)) {
            fprintf (stderr, "could not read the TSPLIB file\n");
            rval = 1;
            goto CLEANUP;
        }
        norm = dat.norm;
    } else {
        if (CCutil_getdata (datfilename, binary_in, norm, &ncount, &dat)) {
            fprintf (stderr, "Could not create data set\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (CCutil_init_dat_edgelen (&dat)) {
        fprintf (stderr, "init_dat_edgelen failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Number of nodes: %d\n", ncount);
    fflush (stdout);
                  
    if (read_blossom_tree (dualfilename, ncount, &pi, &parent)) {
        fprintf (stderr, "read_blossom_tree failed\n");
        rval = 1;
        goto CLEANUP;
    }

    if (matfilename) {
        if (read_matching (matfilename, ncount, &matchlist, &dat)) {
            fprintf (stderr, "read_matching failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    printf ("Hello !\n");
    if (matching_price (ncount, &dat, pi, parent, 
                        &badcount, &badlist, &badlen, &penalty, NULL, NULL)) {
        fprintf (stderr, "matching_price failed\n");
        rval = 1;
        goto CLEANUP;
    }

    printf ("Found %d bad edges, with total penalty %f\n", badcount, penalty);
    fflush (stdout);

    if (badcount) {
        if (badfilename) {
            if (CCutil_writeedges (ncount, badfilename, badcount, badlist, &dat)) {
                fprintf (stderr, "CCutil_writeedges failed\n");
                rval = 1;
                goto CLEANUP;
            }
        } else {
            printf ("Writing bad edges to dump.edges\n");
            fflush (stdout);
            if (CCutil_writeedges (ncount, "dump.edges", badcount, badlist, &dat)) {
                fprintf (stderr, "CCutil_writeedges failed\n");
                rval = 1;
                goto CLEANUP;
            }
        }
    }
  
    if (matfilename) {
        int *mlen = CC_SAFE_MALLOC (ncount/2, int);
        int i;

        for (i = 0; i < ncount/2; i++ ) 
            mlen[i] = CCutil_dat_edgelen (matchlist[2*i],matchlist[2*i+1], &dat);
        
        if ( matching_check (ncount, pi, parent, matchlist, mlen, &csbad)) {
            fprintf (stderr, "matching_check failed\n");
            rval = 1;
            goto CLEANUP;
        }
    }

    if (csbad) {
        printf ("COMPLEMENTARY SLACKNESS CONDITIONS ARE VIOLATED\n");
        fflush (stdout);
    }

    printf ("Total Running Time: %.2f (seconds)\n", CCutil_zeit () - szeit);
    fflush (stdout);

CLEANUP:

    CC_IFFREE (badlist, int);
    CC_IFFREE (badlen, int);
    CC_IFFREE (pi, double);
    CC_IFFREE (parent, int);
    CC_IFFREE (matchlist, int);
    CCutil_freedatagroup (ncount, &dat);
    if (CCutil_bigchunk_free_world ()) {
        fprintf (stderr, "ERROR: bigchunk_free_world failed\n");
        return 1;
    }

    return rval;
}

#ifdef  CC_PROTOTYPE_ANSI
static int parseargs (int ac, char **av)
#else
static int parseargs (ac, av)
int ac;
char **av;
#endif
{
    int c;

    while ((c = CCutil_bix_getopt (ac, av, "bd:m:n:o:s:T0123456789")) != EOF)
	switch (c) {
        case 'b':
            binary_in = 1;
            break;
        case 'd':
            dualfilename = CCutil_bix_optarg;
            break;
        case 'm':
            matfilename = CCutil_bix_optarg;
            break;
        case 'n':
            datfilename = CCutil_bix_optarg;
            break;
        case 'o':
            badfilename = CCutil_bix_optarg;
            break;
        case 's':
            seed = atoi (CCutil_bix_optarg);
            break;
        case 'T':
            tsplib_in = 1;
            break;
        case '0':
            norm = CC_MAXNORM;
            break;
        case '1':
            norm = CC_EUCLIDEAN_CEIL;
            break;
        case '2':
            norm = CC_EUCLIDEAN;
            break;
        case '3':
            norm = CC_EUCLIDEAN_3D;
            break;
        case '4':
            norm = CC_IBM;
            break;
        case '5':
            norm = CC_ATT;
            break;
        case '6':
            norm = CC_GEOGRAPHIC;
            break;
        case '7':
            norm = CC_MATRIXNORM;
            break;
        case '8':
            norm = CC_DSJRANDNORM;
            break;
        case '9':
            norm = CC_CRYSTAL;
            break;
        case CC_BIX_GETOPT_UNKNOWN:
        case '?':
	default:
	    usage (av[0]);
            return 1;
	}
    if (CCutil_bix_optind != ac) {
	usage (av[0]);
        return 1;
    }
    return 0;
}

#ifdef  CC_PROTOTYPE_ANSI
static void usage (char *f)
#else
static void usage (f)
char *f;
#endif
{
    fprintf (stderr, "Usage: %s [-see below-]\n", f);
    fprintf (stderr, "   -b    datfile in integer binary format\n");
    fprintf (stderr, "   -d f  dual file - MUST be specified\n");
    fprintf (stderr, "   -m f  matching file (to check complementary slackness\n");
    fprintf (stderr, "   -n f  dat file - MUST be specified\n");
    fprintf (stderr, "   -o f  output file for bad edges (default: dump.edges)\n");
    fprintf (stderr, "   -s #  random seed\n");
    fprintf (stderr, "   -T    the dat file is a TSPLIB file\n");
    fprintf (stderr, "   -0    price out using MAX norm\n");
    fprintf (stderr, "   -1    price out using JOHNSON norm\n");
    fprintf (stderr, "   -2    price out using EUCLIDEAN norm (default)\n");
    fprintf (stderr, "   -3    price out using Rounded Euclidean 3D norm\n");
    fprintf (stderr, "   -(4 5 6 7 8 9) IBM ATT GEO MATRIX DSJRAND CRYSTAL norm\n");
}

#ifdef CC_PROTOTYPE_ANSI
static int read_matching (char *fname, int ncount, int **matchlist,
                          CCdatagroup *dat) 
#else
static int read_matching (fname, ncount, matchlist, dat) 
char *fname;
int ncount;
int **matchlist;
CCdatagroup *dat;
#endif
{
    int *matlen = (int *) NULL;
    int i, mcount, len;

    if (CCutil_getedgelist (ncount, fname, &mcount, matchlist, &matlen)) {
        fprintf (stderr, "getedgelist failed\n");
        return 1;
    }

    if (mcount != ncount / 2) {
        fprintf (stderr, "matching file %s has wrong format\n", fname);
        CC_IFFREE (matlen, int);
        return 1;
    }

    for (i = 0; i < mcount; i++) {
        len = CCutil_dat_edgelen ((*matchlist)[2*i], (*matchlist)[2*i+1], dat);
        if (matlen[i] != len) {
            fprintf (stderr, "length of (%d,%d) is %d not %d\n",
                  (*matchlist)[2*i], (*matchlist)[2*i+1], len, matlen[i]);
            CC_IFFREE (matlen, int);
            return 1;
        }
    }

    CC_IFFREE (matlen, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int read_blossom_tree (char* blossom_tree_file, int ncount,
                              double **pi, int **parent) 
#else
static int read_blossom_tree (blossom_tree_file, ncount, pi, parent) 
char *blossom_tree_file;
int ncount;
double **pi;
int **parent;
#endif
{
    int i,j;
    FILE* f;
    int *mark = (int *) NULL;
    int c1 = 0, c2 = 0;
    int bcount = 3 * ncount/2;
    double szeit;

    *pi = CC_SAFE_MALLOC (bcount + 1, double);
    *parent = CC_SAFE_MALLOC (bcount + 1, int);
    mark = CC_SAFE_MALLOC (bcount + 1, int);
    if (!(*pi) || !(*parent) || !mark) {
        fprintf (stderr, "out of memory in read_blossom_tree\n");
        CC_IFFREE (*pi, double);
        CC_IFFREE (*parent, int);
        CC_IFFREE (mark, int);
        return 1;
    }

    printf("Reading %s ...",blossom_tree_file);
    fflush(stdout);
    szeit = CCutil_zeit();
    if ((f = fopen(blossom_tree_file,"r"))==NULL) {
	fprintf(stderr," Error: Can't open file %s\n",blossom_tree_file);
        CC_IFFREE (*pi, double);
        CC_IFFREE (*parent, int);
        CC_IFFREE (mark, int);
        return 1;
    }
    for (i = 0; i < bcount; i++) {
	fread ((*parent)+i, sizeof(int), 1, f);
	fread ((*pi)+i, sizeof(double), 1, f);
    }
    fclose (f);
    printf(" ... in %.2f sec\n",CCutil_zeit () - szeit);
    fflush(stdout);

    for (i = 0; i < bcount; i++) 
	mark[i]=0;

    for (i = 0; i < ncount; i++) {
	j=i;
	while (j != -1 && mark[j] == 0) {
	    mark[j] = 1;
	    j = (*parent)[j];
	}
    }

    for (i = ncount; i < bcount; i++) {
	if (mark[i]) {
	    c1++;
	    if ((*pi)[i] == 0.0) 
		c2++;
	}
    }

    printf ("Number of blossoms: %d (with %d at 0 value)\n", c1, c2);
    fflush(stdout);

    CC_IFFREE(mark, int);
    return 0;
}
