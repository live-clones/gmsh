/***************************************************************************/
/*                                                                         */
/*                LINEAR SUBTOUR SEPARATION ROUTINES                       */
/*                           preliminary                                   */
/*                                                                         */
/*                              TSP CODE                                   */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: July 25, 1995                                                    */
/*  Thanks: Phil Gibbons, for helpful ideas                                */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCcut_linsub (CCtsp_lpcut_in **cuts, int *cutcount, int ncount,  */
/*            int ecount, int *elist, double *x)                           */
/*      -cuts will return any new cuts found (they will be added to the    */
/*       head of the linked list                                           */
/*      -cutcount will return the number of new cuts added                 */
/*      -ncount is the number of nodes                                     */
/*      -ecount is the number of edges                                     */
/*      -elist contains the LP edges in node node format                   */
/*      -x is an LP solution                                               */
/*                                                                         */
/*  NOTES:                                                                 */
/*      linsub runs in time O(m log n).                                    */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "cut.h"

#define NO_PATHS

typedef struct psh {
    int base;
    int size;
    double *sum;
    double *minpre;
} psh;

#ifdef CC_PROTOTYPE_ANSI

static void
    psh_free (psh *p),
    psh_add (psh *p, int i, double v);

static int
    add_the_cut (int (*doit_fn) (double, int, int, void *),
        void *pass_param, double val, int a, int b),
    psh_init (psh *p, int k),
    psh_minloc (psh *p);

static double
    psh_minval (psh *p);

#else

static void
    psh_free (),
    psh_add ();

static int
    add_the_cut (),
    psh_init (),
    psh_minloc ();

static double
    psh_minval ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCcut_linsub (int ncount, int ecount, int *elist, double *x, double cutoff,
        int (*doit_fn) (double, int, int, void *), void *pass_param)
#else
int CCcut_linsub (ncount, ecount, elist, x, cutoff, doit_fn, pass_param)
int ncount, ecount;
int *elist;
double *x;
double cutoff;
int (*doit_fn) ();
void *pass_param;
#endif
{
    int rval = 0;
    psh p;
    int i, j;
    double v;
    int count = 0;
    int *perm = (int *) NULL;
    int *eperm = (int *) NULL;
    int *ends = (int *) NULL;
    double *xends = (double *) NULL;
#ifdef NO_PATHS
    double sum_next;
#endif
    printf ("linsub ... "); fflush (stdout);

    if (psh_init (&p, ncount)) {
        return -1;
    }

    /*  arrange elist into the array ends (with xends being the x values   */
    /*  so that ends[2*i] is less than ends[2*i+1], and ends is sorted in  */
    /*  increasing  order of ends[2*i]                                     */

    perm = CC_SAFE_MALLOC (ecount, int);
    eperm = CC_SAFE_MALLOC (ecount, int);
    if (!perm || !eperm) {
        fprintf (stderr, "out of memory in linsub\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ecount; i++) {
        eperm[i] = (elist[2*i] < elist[2*i+1] ? elist[2*i] : elist[2*i+1]);
        perm[i] = i;
    }
    CCutil_int_perm_quicksort (perm, eperm, ecount);

    ends = CC_SAFE_MALLOC (2*ecount, int);
    xends = CC_SAFE_MALLOC (ecount, double);
    if (!ends || !xends) {
        fprintf (stderr, "out of memory in linsub\n");
        rval = 1; goto CLEANUP;
    }
    for (i = 0; i < ecount; i++) {
        j = perm[i];
        if (elist[2*j] < elist[2*j+1]) {
            ends[2*i] = elist[2*j];
            ends[2*i+1] = elist[2*j+1];
        } else {
            ends[2*i] = elist[2*j+1];
            ends[2*i+1] = elist[2*j];
        }
        xends[i] = x[j];
    }
    CC_FREE (perm, int);
    CC_FREE (eperm, int);

    for (i = ncount - 1, j = ecount - 1; i > 0; i--) {
#ifdef NO_PATHS
        sum_next = 0.0;
#endif
        while (j >= 0 && ends[2*j] == i) {
            psh_add (&p, ends[2*j+1], -xends[j]);
#ifdef NO_PATHS
            if (ends[2*j+1] == i+1) {
                sum_next += xends[j];
            }
#endif
            j--;
        }
        v = psh_minval (&p);
#ifdef NO_PATHS
        if (sum_next < 0.999999)
#endif
        if (2.0 + v < cutoff) {
            rval = add_the_cut (doit_fn, pass_param, 2.0 + v, i,
                                psh_minloc (&p));
            if (rval) {
                fprintf (stderr, "add_the_cut failed\n"); goto CLEANUP;
            }
            count++;
        }
        psh_add (&p, i, 1.0);
    }

CLEANUP:

    printf ("DONE (found %d cuts)\n", count);
    fflush (stdout);

    psh_free (&p);
    CC_IFFREE (ends, int);
    CC_IFFREE (xends, double);
    CC_IFFREE (perm, int);
    CC_IFFREE (eperm, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int add_the_cut (int (*doit_fn) (double, int, int, void *),
        void *pass_param, double val, int a, int b)
#else
static int add_the_cut (doit_fn, pass_param, val, a, b)
int (*doit_fn) ();
void *pass_param;
double val;
int a, b;
#endif
{
    int rval = 0;

    rval = doit_fn (val, a, b, pass_param);
    if (rval) {
        fprintf (stderr, "doit_fn failed\n"); goto CLEANUP;
    }

CLEANUP:

    return rval;
}

/***************************************************************************/
/*                                                                         */
/*                      PREFIX SUM HEAP ROUTINES                           */
/*                                                                         */
/*                              TSP CODE                                   */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: July 25, 1995                                                    */
/*  Thanks: Phil Gibbons, for the algorithm                                */
/*                                                                         */
/*  These routines implement a heap of prefix sums.  The routines are      */
/*  self-contained, but unlikely to be useful outside of the linear        */
/*  subtour separation code.                                               */
/*                                                                         */
/*  PREFIX SUM HEAP FUNCTIONS:                                             */
/*    int psh_init (psh *p, int k)                                         */
/*      -p should point to a psh struct.                                   */
/*      -k is the number of elements in the psh.                           */
/*      -this initializes the value of all k elements to 0.0.              */
/*      -return value 0 means success, 1 means failure.                    */
/*    void psh_free (psh *p)                                               */
/*      -frees the spaces allocated by psh_init.                           */
/*    void psh_add (psh *p, int i, double v)                               */
/*      -adds v to the value of element i.                                 */
/*    double psh_minval (psh *p)                                           */
/*      -returns min_j sum_{i=0}^j value[i].                               */
/*    int psh_minloc (psh *p)                                              */
/*      -returns the smallest j which achieves psh_minval(p).              */
/*                                                                         */
/*  NOTES:                                                                 */
/*      A k-element heap will malloc 32k bytes of memory. If memory is     */
/*  tight, using integer values (instead of doubles) brings it down to     */
/*  16k bytes.                                                             */
/*      psh_init takes O(k) time.  psh_add and psh_minloc take O(log k)    */
/*  time.  psh_free and psh_minval take O(1) time.                         */
/*                                                                         */
/*      It is likely that using a ternary tree instead of binary would     */
/*  improve performance.  Also, psh_add could take advantage of knowing    */
/*  which child has changed.                                               */
/*      psh_minloc could be changed to return all elements which achieve   */
/*  the min, in time O(log k) per element returned.                        */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#ifdef CC_PROTOTYPE_ANSI
static int psh_init (psh *p, int k)
#else
static int psh_init (p, k)
psh *p;
int k;
#endif
{
    int i;
    int space;

    p->size = k;
    p->base = 1;
    while (p->base < k) p->base *= 2;

    space = p->base*2;

    p->sum = CC_SAFE_MALLOC (space, double);
    if (!p->sum)
        return 1;
    p->minpre = CC_SAFE_MALLOC (space, double);
    if (!p->minpre) {
        CC_FREE (p->sum, double);
        return 1;
    }
    for (i=0; i<space; i++) {
        p->sum[i] = 0.0;
        p->minpre[i] = 0.0;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void psh_free (psh *p)
#else
static void psh_free (p)
psh *p;
#endif
{
    CC_FREE (p->minpre, double);
    CC_FREE (p->sum, double);
    p->size = 0;
    p->base = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void psh_add (psh *p, int i, double v)
#else
static void psh_add (p, i, v)
psh *p;
int i;
double v;
#endif
{
    double *s = p->sum;
    double *m = p->minpre;

    i += p->base;
    s[i] += v;
    m[i] += v;
    i /= 2;
    while (i >= 1) {
        s[i] += v;
        if (m[2*i] < s[2*i] + m[2*i+1]) {
            m[i] = m[2*i];
        } else {
            m[i] = s[2*i] + m[2*i+1];
        }
        i /= 2;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int psh_minloc (psh *p)
#else
static int psh_minloc (p)
psh *p;
#endif
{
    int i = 1;
    double *m = p->minpre;

    while (i < p->base) {
        if (m[i] == m[2*i]) {
            i = 2*i;
        } else {
            i = 2*i+1;
        }
    }
    if (i - p->base < p->size) {
        return i - p->base;
    } else {
        /* we're lost */
        return p->size - 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static double psh_minval (psh *p)
#else
static double psh_minval (p)
psh *p;
#endif
{
    return p->minpre[1];
}
