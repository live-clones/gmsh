/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Linked List with Node Bit */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: May 22, 1995                                                     */
/*                                                                         */
/*                                                                         */
/* EXPORTED FUNCTIONS:                                                     */
/*   int CClinkern_flipper_init (int ncount, int *cyc)                     */
/*     initializes flipper1 to an initial cycle given in cyc.              */
/*     returns 0 on success, nonzero on failure.                           */
/*   int CClinkern_flipper_cycle (int *p)                                  */
/*     places the current cycle in p.                                      */
/*     returns the number of segments in current representation.           */
/*   void CClinkern_flipper_finish (void)                                  */
/*     frees up temporary space allocated by CClinkern_flipper_init.       */
/*     every flipper_init should lead to a flipper_finish call.            */
/*   void CClinkern_flipper_free_world (void)                              */
/*     frees up all remaining space (including ptrs)                       */
/*     should be called when we are finished with linkern                  */
/*   int CClinkern_flipper_next (int x)                                    */
/*     returns the successor to x in the current cycle.                    */
/*   int CClinkern_flipper_prev (int x)                                    */
/*     returns the predecessor of x in the current cycle.                  */
/*   void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)      */
/*     flips the portion of the cycle from x to y (inclusive).             */
/*   int CClinkern_flipper_sequence (int * x, int y, int z)                */
/*     returns 1 if xyz occur as an increasing subsequence of the cycle,   */
/*     returns 0 otherwise.                                                */
/*                                                                         */
/* NOTES:                                                                  */
/*       This version is a real dud - the node bit idea takes longer than  */
/*   simply swapping the next and prev fields as in flip_ll0.              */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 1  (flip_ll1.c):                                   */
/*                                                                         */
/*     1. Uses linked list with known prev and next.                       */
/*     2. No reversal bit.                                                 */
/*     3. Node bits to distingish between prev and next.                   */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

typedef struct llnode {
    struct llnode *neigh[2];    /* 0 is next, 1 is prev */
    int            name;
    char           dir;
    char           mark;
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    dump_cycle (void);

#else

static void
    dump_cycle ();

#endif

static llnode *lltour = (llnode *) NULL;
static cycle_size = 0;


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i;

    cycle_size = ncount;
    lltour = CC_SAFE_MALLOC (ncount, llnode);
    if (!lltour)
        return 1;

    lltour[cyc[0]].name = cyc[0];
    lltour[cyc[0]].dir = 0;
    lltour[cyc[0]].mark = 0;
    lltour[cyc[0]].neigh[0] = &(lltour[cyc[1]]);
    lltour[cyc[0]].neigh[1] = &(lltour[cyc[ncount - 1]]);
    lltour[cyc[ncount - 1]].name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].dir = 0;
    lltour[cyc[ncount - 1]].mark = 0;
    lltour[cyc[ncount - 1]].neigh[0] = &(lltour[cyc[0]]);
    lltour[cyc[ncount - 1]].neigh[1] = &(lltour[cyc[ncount - 2]]);

    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].name = cyc[i];
        lltour[cyc[i]].dir = 0;
        lltour[cyc[i]].mark = 0;
        lltour[cyc[i]].neigh[0] = &(lltour[cyc[i + 1]]);
        lltour[cyc[i]].neigh[1] = &(lltour[cyc[i - 1]]);
    }

/*
    dump_cycle ();
*/

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_cycle (void)
#else
static void dump_cycle ()
#endif
{
    llnode *n, *ns;

    printf ("TOUR:\n");


    n = ns = &(lltour[0]);

    do {
        printf ("%2d ", n->name);
        n = n->neigh[(int) n->dir];
    } while (n != ns);

    printf ("\n");
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    llnode *n, *start;
    int k = 0;

    n = start = &(lltour[0]);

    do {
        x[k++] = n->name;
        n = n->neigh[(int) n->dir];
    } while (n != start && k < cycle_size);

    return cycle_size;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_finish (void)
#else
void CClinkern_flipper_finish ()
#endif
{
    if (lltour)
        CC_FREE (lltour, llnode);
}


#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_free_world (void)
#else
void CClinkern_flipper_free_world ()
#endif
{
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    return lltour[x].neigh[(int) lltour[x].dir]->name;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    return lltour[x].neigh[(int) ((lltour[x].dir)^1)]->name;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    llnode *nxprev = &(lltour[xprev]);
    llnode *nynext = &(lltour[ynext]);
    llnode *nx = &(lltour[x]);
    llnode *ny = &(lltour[y]);
    llnode *n;

    if (x == y)
        return;

    n = nx;
    n->dir ^= 1;

    do {
        n = n->neigh[n->dir^1];
        n->dir ^= 1;
    } while (n != ny);

    if (nxprev != ny) {
        ny->neigh[(int) ny->dir^1] = nxprev;
        nx->neigh[(int) nx->dir] = nynext;
        nxprev->neigh[(int) nxprev->dir] = ny;
        nynext->neigh[(int) nynext->dir^1] = nx;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    llnode *n;

    if (x == z) {
        return 1;
    } else {
        lltour[y].mark = 1;
        lltour[z].mark = 1;

        n = &(lltour[x]);

        while (!n->mark) {
            n = n->neigh[(int) n->dir];
        }
        lltour[y].mark = 0;
        lltour[z].mark = 0;

        return (n->name == y);
    }
}
