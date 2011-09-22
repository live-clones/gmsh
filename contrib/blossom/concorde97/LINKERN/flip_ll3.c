/***************************************************************************/
/*                                                                         */
/* TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - Linked List w/ Neighbors  */
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
/*       This version should be very slow, since next and prev have to     */
/*   hunt down an orientation node (since each node knows its neighbors    */
/*   but not the direction). Flips will be fast, but there are not enough  */
/*   enough of them to compensate for the next and prevs.                  */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 3  (flip_ll3.c):                                   */
/*                                                                         */
/*     1. Uses linked list with neighbors.                                 */
/*     2. Need to track down a node of known orientation (the extra info   */
/*        in the flips provides this).                                     */
/*     3. The hunt is done by a seqeunce of if tests, moving along the     */
/*        linked list, checking that we reach new nodes).                  */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

typedef struct llnode {
    struct llnode *next;
    struct llnode *prev;
    int            name;
    char           orient;
    char           mark;
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    dump_cycle (void);
static int
    find_orientation (llnode *n);

#else

static void
    dump_cycle ();
static int
    find_orientation ();

#endif

static llnode *lltour = (llnode *) NULL;
static llnode *orientnodes[2];
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
    lltour[cyc[0]].mark = 0;
    lltour[cyc[0]].orient = 0;
    lltour[cyc[0]].next = &(lltour[cyc[1]]);
    lltour[cyc[0]].prev = &(lltour[cyc[ncount - 1]]);
    lltour[cyc[ncount - 1]].name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].mark = 0;
    lltour[cyc[ncount - 1]].orient = 0;
    lltour[cyc[ncount - 1]].next = &(lltour[cyc[0]]);
    lltour[cyc[ncount - 1]].prev = &(lltour[cyc[ncount - 2]]);

    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].name = cyc[i];
        lltour[cyc[i]].mark = 0;
        lltour[cyc[i]].orient = 0;
        lltour[cyc[i]].next = &(lltour[cyc[i + 1]]);
        lltour[cyc[i]].prev = &(lltour[cyc[i - 1]]);
    }
    orientnodes[0] = &(lltour[cyc[0]]);
    orientnodes[1] = &(lltour[cyc[ncount/2]]);
    lltour[cyc[0]].orient = 1;
    lltour[cyc[ncount/2]].orient = 1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int find_orientation (llnode *s)
#else
static int find_orientation (s)
llnode *s;
#endif
{
    /* Returns 0 if next is next and 1 if next is really prev */

    llnode *n, *p;

    if (s->orient)
        return 0;

    p = s;
    n = p->next;

    while (!n->orient) {
        if (n->next == p) {
            p = n;
            n = n->prev;
        } else {
            p = n;
            n = n->next;
        }
    }
    return (p != n->prev);
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    llnode *n, *p, *start;
    int k = 0;

    p = start = &(lltour[0]);
    n = (find_orientation (start) ? start->prev : start->next);

    x[k++] = start->name;

    do {
        x[k++] = n->name;
        if (n->next == p) {
            p = n;
            n = n->prev;
        } else {
            p = n;
            n = n->next;
        }
    } while (n != start);

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
    if (find_orientation (&(lltour[x])))
        return lltour[x].prev->name;
    else
        return lltour[x].next->name;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    if (find_orientation (&(lltour[x])))
        return lltour[x].next->name;
    else
        return lltour[x].prev->name;
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

    if (x == y) {
        return;
    }

    orientnodes[0]->orient = 0;
    orientnodes[1]->orient = 0;
    orientnodes[0] = nxprev;
    orientnodes[1] = nynext;
    nxprev->orient = 1;
    nynext->orient = 1;

    if (nxprev == ny) {
        if (nx->prev == ny) {
            nx->prev = nx->next;
            nx->next = ny;
        }
        if (ny->next == nx) {
            ny->next = ny->prev;
            ny->prev = nx;
        }
    } else {
        if (nxprev->prev == nx)
            nxprev->prev = nxprev->next;
        nxprev->next = ny;

        if (nynext->next == ny)
            nynext->next = nynext->prev;
        nynext->prev = nx;

        if (nx->prev == nxprev)
            nx->prev = nynext;
        else
            nx->next = nynext;

        if (ny->next == nynext)
            ny->next = nxprev;
        else
            ny->prev = nxprev;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    llnode *n, *p;

    if (x == z || x == y) {
        return 1;
    } else {
        lltour[y].mark = 1;
        lltour[z].mark = 1;

        p = &(lltour[x]);
        n = (find_orientation (p) ? p->prev : p->next);

        while (!n->mark) {
            if (n->next == p) {
                p = n;
                n = n->prev;
            } else {
                p = n;
                n = n->next;
            }
        }
        lltour[y].mark = 0;
        lltour[z].mark = 0;

        return (n->name == y);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_cycle (void)
#else
static void dump_cycle ()
#endif
{
    int *getit, i;

    getit = CC_SAFE_MALLOC (cycle_size, int);
    CClinkern_flipper_cycle (getit);

    printf ("TOUR: ");

    for (i = 0; i < cycle_size; i++)
        printf ("%2d ", getit[i]);
    printf ("\n");
    fflush (stdout);

    CC_FREE (getit, int);
}

