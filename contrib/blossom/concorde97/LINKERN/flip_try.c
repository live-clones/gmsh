/***************************************************************************/
/*                                                                         */
/*    TOUR MAINTANENCE ROUTINES FOR LIN-KERNIGHAN - 3-Level Linked List    */
/*                (Contains debugging information)                         */
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
/*       This version should be the best of the linked lists so far.       */
/*   It combines the oneway approach, with three levels for an express     */
/*   lane and a superexpress lane. Note that all superexpress nodes are    */
/*   also express nodes.                                                   */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

/***************************************************************************/
/*                                                                         */
/* LINKDED LIST FLIPPER 8  (flip_ll8.c):                                   */
/*                                                                         */
/*     1. Uses three levels, the top having n**(1/3) nodes.                */
/*     2. The top level has explicit next and prevs, the other levels      */
/*        consist of two "oneway" cycles.                                  */
/*                                                                         */
/***************************************************************************/

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define FORWARD_TOUR  0
#define BACKWARD_TOUR 1

static int test_cycle_size = 0;
static int test_reversed = 0;
static int test_short_size = 0;
static int *test_flip_cyc = (int *) NULL;
static int *test_flip_cyc_inv = (int *) NULL;

#ifdef CC_PROTOTYPE_ANSI

static int
    test_flipper_init (int ncount, int *cyc),
    test_flipper_next (int x),
    test_flipper_prev (int x),
    test_flipper_cycle (int *x),
    test_flipper_sequence (int x, int y, int z);
static void
    test_flipper_flip (int x, int y),
    test_flipper_finish (void),
    test_flipper_free_world (void);

#else

static int
    test_flipper_init (),
    test_flipper_next (),
    test_flipper_prev (),
    test_flipper_cycle (),
    test_flipper_sequence ();
static void
    test_flipper_flip (),
    test_flipper_finish (),
    test_flipper_free_world ();

#endif

typedef struct oneway {
    struct oneway *next;
    int            name;
    char           mark;
    char           level;
} oneway;

typedef struct llnode {
    struct oneway  actual_fwd;
    struct oneway  actual_bwd;
    struct oneway  actual_fwd_express;
    struct oneway  actual_bwd_express;
    struct oneway  *fwd;
    struct oneway  *bwd;
    struct oneway  *fwd_express;
    struct oneway  *bwd_express;
    struct llnode  *next_super;
    struct llnode  *prev_super;
} llnode;

#ifdef CC_PROTOTYPE_ANSI

static void
    express_flip (int aprev, int a, int b, int bnext),
    super_flip (int a, int b),
    dump_raw_cycle (void),
    dump_cycle (void);
static int
    express_flipper_sequence (int x, int y, int z),
    find_orientation (int s);

#else

static void
    express_flip (),
    super_flip (),
    dump_raw_cycle (),
    dump_cycle ();
static int
    express_flipper_sequence (),
    find_orientation ();

#endif

static llnode *lltour = (llnode *) NULL;
static int cycle_size = 0;
static int reversed = 0;


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_init (int ncount, int *cyc)
#else
int CClinkern_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, j;
    int groupsize, supergroupsize;

    if (test_flipper_init (ncount, cyc)) {
        printf ("the test code failed\n");
        fflush (stdout);
        return 1;
    }

    cycle_size = ncount;
    reversed = 0;

    lltour = CC_SAFE_MALLOC (ncount, llnode);
    if (!lltour)
        return 1;

    lltour[cyc[0]].actual_fwd.name = cyc[0];
    lltour[cyc[0]].actual_fwd.mark = 0;
    lltour[cyc[0]].actual_fwd.level = 0;
    lltour[cyc[0]].actual_fwd.next = &(lltour[cyc[1]].actual_fwd);
    lltour[cyc[0]].fwd = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[0]].actual_bwd.name = cyc[0];
    lltour[cyc[0]].actual_bwd.mark = 0;
    lltour[cyc[0]].actual_bwd.level = 0;
    lltour[cyc[0]].actual_bwd.next = &(lltour[cyc[ncount - 1]].actual_bwd);
    lltour[cyc[0]].bwd = &(lltour[cyc[0]].actual_bwd);
    lltour[cyc[ncount - 1]].actual_fwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_fwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_fwd.level = 0;
    lltour[cyc[ncount - 1]].actual_fwd.next = &(lltour[cyc[0]].actual_fwd);
    lltour[cyc[ncount - 1]].fwd = &(lltour[cyc[ncount - 1]].actual_fwd);
    lltour[cyc[ncount - 1]].actual_bwd.name = cyc[ncount - 1];
    lltour[cyc[ncount - 1]].actual_bwd.mark = 0;
    lltour[cyc[ncount - 1]].actual_bwd.level = 0;
    lltour[cyc[ncount - 1]].actual_bwd.next =
                        &(lltour[cyc[ncount - 2]].actual_bwd);
    lltour[cyc[ncount - 1]].bwd = &(lltour[cyc[ncount - 1]].actual_bwd);


    for (i = ncount - 2; i; i--) {
        lltour[cyc[i]].actual_fwd.name = cyc[i];
        lltour[cyc[i]].actual_fwd.mark = 0;
        lltour[cyc[i]].actual_fwd.level = 0;
        lltour[cyc[i]].actual_fwd.next = &(lltour[cyc[i + 1]].actual_fwd);
        lltour[cyc[i]].fwd = &(lltour[cyc[i]].actual_fwd);
        lltour[cyc[i]].actual_bwd.name = cyc[i];
        lltour[cyc[i]].actual_bwd.mark = 0;
        lltour[cyc[i]].actual_bwd.level = 0;
        lltour[cyc[i]].actual_bwd.next = &(lltour[cyc[i - 1]].actual_bwd);
        lltour[cyc[i]].bwd = &(lltour[cyc[i]].actual_bwd);
    }

    groupsize = (int) cbrt ((double) ncount);
    supergroupsize = groupsize * groupsize;
    printf ("groupsize = %d  supersize = %d\n", groupsize, supergroupsize);
    fflush (stdout);
    lltour[cyc[0]].actual_fwd.level = 1;
    lltour[cyc[0]].actual_bwd.level = 1;
    lltour[cyc[0]].fwd_express = &(lltour[cyc[0]].actual_fwd_express);
    lltour[cyc[0]].bwd_express = &(lltour[cyc[0]].actual_bwd_express);
    lltour[cyc[0]].actual_fwd_express.mark = 0;
    lltour[cyc[0]].actual_bwd_express.mark = 0;
    lltour[cyc[0]].actual_fwd_express.level = 1;
    lltour[cyc[0]].actual_bwd_express.level = 1;
    lltour[cyc[0]].actual_fwd_express.name = cyc[0];
    lltour[cyc[0]].actual_bwd_express.name = cyc[0];
    lltour[cyc[0]].actual_fwd_express.next =
                          &(lltour[cyc[groupsize]].actual_fwd_express);
    i = groupsize;
    j = ncount - groupsize;
    while (i < j) {
        lltour[cyc[i]].actual_fwd.level = 1;
        lltour[cyc[i]].actual_bwd.level = 1;
        lltour[cyc[i]].fwd_express = &(lltour[cyc[i]].actual_fwd_express);
        lltour[cyc[i]].bwd_express = &(lltour[cyc[i]].actual_bwd_express);
        lltour[cyc[i]].actual_fwd_express.mark = 0;
        lltour[cyc[i]].actual_bwd_express.mark = 0;
        lltour[cyc[i]].actual_fwd_express.level = 1;
        lltour[cyc[i]].actual_bwd_express.level = 1;
        lltour[cyc[i]].actual_fwd_express.name = cyc[i];
        lltour[cyc[i]].actual_bwd_express.name = cyc[i];
        lltour[cyc[i]].actual_fwd_express.next =
                          &(lltour[cyc[i + groupsize]].actual_fwd_express);
        lltour[cyc[i]].actual_bwd_express.next =
                          &(lltour[cyc[i - groupsize]].actual_bwd_express);
        i += groupsize;
    }

    lltour[cyc[i]].actual_fwd.level = 1;
    lltour[cyc[i]].actual_bwd.level = 1;
    lltour[cyc[i]].fwd_express = &(lltour[cyc[i]].actual_fwd_express);
    lltour[cyc[i]].bwd_express = &(lltour[cyc[i]].actual_bwd_express);
    lltour[cyc[i]].actual_fwd_express.mark = 0;
    lltour[cyc[i]].actual_bwd_express.mark = 0;
    lltour[cyc[i]].actual_fwd_express.level = 1;
    lltour[cyc[i]].actual_bwd_express.level = 1;
    lltour[cyc[i]].actual_fwd_express.name = cyc[i];
    lltour[cyc[i]].actual_bwd_express.name = cyc[i];
    lltour[cyc[i]].actual_fwd_express.next =
                          &(lltour[cyc[0]].actual_fwd_express);
    lltour[cyc[i]].actual_bwd_express.next =
                          &(lltour[cyc[i - groupsize]].actual_bwd_express);
    lltour[cyc[0]].actual_bwd_express.next =
                          &(lltour[cyc[i]].actual_bwd_express);

    lltour[cyc[0]].actual_fwd.level = 2;
    lltour[cyc[0]].actual_bwd.level = 2;
    lltour[cyc[0]].actual_fwd_express.level = 2;
    lltour[cyc[0]].actual_bwd_express.level = 2;
    lltour[cyc[0]].next_super = &(lltour[cyc[supergroupsize]]);
    i = supergroupsize;
    j = ncount - supergroupsize;
    while (i < j) {
        lltour[cyc[i]].actual_fwd.level = 2;
        lltour[cyc[i]].actual_bwd.level = 2;
        lltour[cyc[i]].actual_fwd_express.level = 2;
        lltour[cyc[i]].actual_bwd_express.level = 2;
        lltour[cyc[i]].prev_super = &(lltour[cyc[i - supergroupsize]]);
        lltour[cyc[i]].next_super = &(lltour[cyc[i + supergroupsize]]);
        i += supergroupsize;
    }
    lltour[cyc[i]].actual_fwd.level = 2;
    lltour[cyc[i]].actual_bwd.level = 2;
    lltour[cyc[i]].actual_fwd_express.level = 2;
    lltour[cyc[i]].actual_bwd_express.level = 2;
    lltour[cyc[i]].next_super = &(lltour[cyc[0]]);
    lltour[cyc[i]].prev_super = &(lltour[cyc[i - supergroupsize]]);
    lltour[cyc[0]].prev_super = &(lltour[cyc[i]]);

/*
    dump_raw_cycle ();
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
    int *getit, i;

    printf ("dump_cycle ...\n"); fflush (stdout);

    getit = CC_SAFE_MALLOC (cycle_size, int);
    CClinkern_flipper_cycle (getit);

    printf ("TOUR: ");
    fflush (stdout);

    for (i = 0; i < cycle_size; i++)
        printf ("%2d ", getit[i]);
    printf ("\n");
    fflush (stdout);

    {
        oneway *p, *start;

        printf ("Express TOUR: ");
        fflush (stdout);
        p = (find_orientation (getit[0]) ? lltour[getit[0]].bwd :
                                           lltour[getit[0]].fwd);
        while (!p->level)
            p = p->next;
        if (p == lltour[p->name].fwd)
            p = lltour[p->name].fwd_express;
        else
            p = lltour[p->name].bwd_express;

        i = 0;
        start = p;
        do {
            printf ("%d ", p->name);
            p = p->next;
            i++;
        } while (p != start && i < 2 * cycle_size);
        printf ("\n");
        fflush (stdout);
    }

    {
        llnode *n, *start;
        oneway *p;

        printf ("SUPER TOUR: ");
        fflush (stdout);
        p = (find_orientation (getit[0]) ? lltour[getit[0]].bwd :
                                           lltour[getit[0]].fwd);
        while (!p->level)
            p = p->next;
        p = lltour[p->name].fwd_express;
        while (p->level != 2)
            p = p->next;

        n = start = &(lltour[p->name]);
        if (reversed) {
            do {
                printf ("%d ", n->fwd->name);
                n = n->prev_super;
            } while (n != start);

        } else {
            do {
                printf ("%d ", n->fwd->name);
                n = n->next_super;
            } while (n != start);
        }
        printf ("\n");
        fflush (stdout);
    }

    CC_FREE (getit, int);

    printf ("Next-Prev test ... "); fflush (stdout);
    for (i = 0; i < cycle_size; i++) {
        CClinkern_flipper_prev (i);
        CClinkern_flipper_next (i);
    }
    printf ("OK\n"); fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
static int find_orientation (int s)
#else
static int find_orientation (s)
int s;
#endif
{
    /* Returns 0 if next is fwd and 1 if next is bwd */

    oneway *n = lltour[s].fwd;

    while (!n->level)
        n = n->next;

    if (lltour[n->name].fwd == n)
        n = lltour[n->name].fwd_express;
    else
        n = lltour[n->name].bwd_express;

    while (n->level != 2)
        n = n->next;

    if (reversed)
        return (n != lltour[n->name].bwd_express);
    else
        return (n != lltour[n->name].fwd_express);
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_cycle (int *x)
#else
int CClinkern_flipper_cycle (x)
int *x;
#endif
{
    int *xtest;
    oneway *start, *n;
    int k = 0;

    xtest = CC_SAFE_MALLOC (cycle_size, int);
    test_flipper_cycle (xtest);

    start = (find_orientation (xtest[0]) ? lltour[xtest[0]].bwd :
                                           lltour[xtest[0]].fwd);
    n = start;
    do {
        x[k++] = n->name;
        n = n->next;
    } while (n != start);

#ifndef NDEBUG
    for (k = 0; k < cycle_size; k++) {
        assert (x[k] == xtest[k]);
    }
#endif

    CC_FREE (xtest, int);
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

    test_flipper_finish ();
}


#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_free_world (void)
#else
void CClinkern_flipper_free_world ()
#endif
{
    test_flipper_free_world ();
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_next (int x)
#else
int CClinkern_flipper_next (x)
int x;
#endif
{
    int temp;

    if (find_orientation (x))
        temp = lltour[x].bwd->next->name;
    else
        temp = lltour[x].fwd->next->name;

    assert (temp == test_flipper_next (x));

    return temp;
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_prev (int x)
#else
int CClinkern_flipper_prev (x)
int x;
#endif
{
    int temp;

    if (find_orientation (x))
        temp = lltour[x].fwd->next->name;
    else
        temp = lltour[x].bwd->next->name;

    assert (temp == test_flipper_prev (x));

    return temp;
}

#ifdef CC_PROTOTYPE_ANSI
void CClinkern_flipper_flip (int xprev, int x, int y, int ynext)
#else
void CClinkern_flipper_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    oneway *o, *p, *oprev, *pnext;

/*
    printf ("flipper_flip (%d, %d, %d, %d)\n",  xprev, x, y, ynext);
    fflush (stdout);
*/

    assert (xprev == CClinkern_flipper_prev (x));
    assert (ynext == CClinkern_flipper_next (y));

    if (x == y)
        return;

    if (lltour[x].bwd->next->name == xprev)
        o = lltour[x].fwd;
    else
        o = lltour[x].bwd;

    while (!o->level && o->name != y)
        o = o->next;

    if (o->level) {
        if (lltour[o->name].fwd == o)
            oprev = lltour[o->name].bwd->next;
        else
            oprev = lltour[o->name].fwd->next;
        while (!oprev->level)
            oprev = oprev->next;
        if (lltour[y].fwd->next->name == ynext)
            p = lltour[y].bwd;
        else
            p = lltour[y].fwd;
        while (!p->level)
            p = p->next;
        if (lltour[p->name].fwd == p)
            pnext = lltour[p->name].bwd->next;
        else
            pnext = lltour[p->name].fwd->next;
        while (!pnext->level)
            pnext = pnext->next;
        express_flip (oprev->name, o->name, p->name, pnext->name);
    }

    if (x != ynext && xprev != ynext) {
        if (lltour[ynext].fwd->next->name == y) {
            if (lltour[x].fwd->next->name == xprev) {
                lltour[x].fwd->next = lltour[ynext].bwd;
                lltour[ynext].fwd->next = lltour[x].bwd;
            } else {
                lltour[x].bwd->next = lltour[ynext].bwd;
                lltour[ynext].fwd->next = lltour[x].fwd;
            }
        } else {
            if (lltour[x].fwd->next->name == xprev) {
                lltour[x].fwd->next = lltour[ynext].fwd;
                lltour[ynext].bwd->next = lltour[x].bwd;
            } else {
                lltour[x].bwd->next = lltour[ynext].fwd;
                lltour[ynext].bwd->next = lltour[x].fwd;
            }
        }

        if (lltour[xprev].fwd->next->name == x) {
            if (lltour[y].fwd->next->name == ynext) {
                lltour[y].fwd->next = lltour[xprev].bwd;
                lltour[xprev].fwd->next = lltour[y].bwd;
            } else {
                lltour[y].bwd->next = lltour[xprev].bwd;
                lltour[xprev].fwd->next = lltour[y].fwd;
            }
        } else {
            if (lltour[y].fwd->next->name == ynext) {
                lltour[y].fwd->next = lltour[xprev].fwd;
                lltour[xprev].bwd->next = lltour[y].bwd;
            } else {
                lltour[y].bwd->next = lltour[xprev].fwd;
                lltour[xprev].bwd->next = lltour[y].fwd;
            }
        }
    } else if (x != ynext) {
        oneway *otemp;
        if (lltour[xprev].fwd->level) {
            SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
        }
    }

    test_flipper_flip (x, y);

/*
    dump_raw_cycle ();
    dump_cycle ();
*/
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_raw_cycle (void)
#else
static void dump_raw_cycle ()
#endif
{
    int i;

    printf ("Raw Cycle:\n");
    for (i = 0; i < cycle_size; i++) {
        printf ("Node %d: %d%c %d%c [%d] ", lltour[i].fwd->name,
              lltour[i].fwd->next->name,
              (lltour[i].fwd->next ==
               lltour[lltour[i].fwd->next->name].fwd ? 'F' : 'B'),
              lltour[i].bwd->next->name,
              (lltour[i].bwd->next ==
               lltour[lltour[i].bwd->next->name].fwd ? 'F' : 'B'),
              (int) lltour[i].fwd->level);
        if (lltour[i].fwd->level)
            printf ("X-fwd: %d%c   X->bwd: %d%c  ",
              lltour[i].fwd_express->next->name,
              (lltour[i].fwd_express->next ==
               lltour[lltour[i].fwd_express->next->name].fwd ? 'F' : 'B'),
              lltour[i].bwd_express->next->name,
              (lltour[i].bwd_express->next ==
               lltour[lltour[i].bwd_express->next->name].fwd ? 'F' : 'B'));
        if (lltour[i].fwd->level == 2)
            printf ("S-next: %d   S->prev: %d\n",
                    lltour[i].next_super->fwd->name,
                    lltour[i].prev_super->fwd->name);
        else
            printf ("\n");
        fflush (stdout);
    }
    if (reversed)
        printf ("REVERSED\n");
    fflush (stdout);
}


#ifdef CC_PROTOTYPE_ANSI
static void express_flip (int xprev, int x, int y, int ynext)
#else
static void express_flip (xprev, x, y, ynext)
int xprev, x, y, ynext;
#endif
{
    oneway *o, *p, *otemp;

/*
    printf ("express_flip (%d, %d, %d, %d)\n",  xprev, x, y, ynext);
    printf ("really (%d, %d, %d, %d)\n",  lltour[xprev].bwd_express->name,
                                          lltour[x].bwd_express->name,
                                          lltour[y].bwd_express->name,
                                          lltour[ynext].bwd_express->name);
    fflush (stdout);
*/


    if (x == y) {
        SWAP (lltour[x].fwd, lltour[x].bwd, otemp);
        return;
    } else if (xprev == ynext) {
        SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
        reversed ^= 1;
        return;
    }

    if (lltour[x].bwd_express->next->name == xprev) {
        o = lltour[x].fwd_express;
    } else {
        o = lltour[x].bwd_express;
    }

    while (o->level != 2 && o->name != y)
        o = o->next;

    if (o->level == 2) {
        if (lltour[y].fwd_express->next->name == ynext)
            p = lltour[y].bwd_express;
        else
            p = lltour[y].fwd_express;
        while (p->level != 2)
            p = p->next;
        super_flip (o->name, p->name);
    }


    if (x != ynext && xprev != ynext) {
        if (lltour[ynext].fwd_express->next->name == y) {
            if (lltour[x].fwd_express->next->name == xprev) {
                lltour[x].fwd_express->next = lltour[ynext].bwd_express;
                lltour[ynext].fwd_express->next = lltour[x].bwd_express;
            } else {
                lltour[x].bwd_express->next = lltour[ynext].bwd_express;
                lltour[ynext].fwd_express->next = lltour[x].fwd_express;
            }
        } else {
            if (lltour[x].fwd_express->next->name == xprev) {
                lltour[x].fwd_express->next = lltour[ynext].fwd_express;
                lltour[ynext].bwd_express->next = lltour[x].bwd_express;
            } else {
                lltour[x].bwd_express->next = lltour[ynext].fwd_express;
                lltour[ynext].bwd_express->next = lltour[x].fwd_express;
            }
        }

        if (lltour[xprev].fwd_express->next->name == x) {
            if (lltour[y].fwd_express->next->name == ynext) {
                lltour[y].fwd_express->next = lltour[xprev].bwd_express;
                lltour[xprev].fwd_express->next = lltour[y].bwd_express;
            } else {
                lltour[y].bwd_express->next = lltour[xprev].bwd_express;
                lltour[xprev].fwd_express->next = lltour[y].fwd_express;
            }
        } else {
            if (lltour[y].fwd_express->next->name == ynext) {
                lltour[y].fwd_express->next = lltour[xprev].fwd_express;
                lltour[xprev].bwd_express->next = lltour[y].bwd_express;
            } else {
                lltour[y].bwd_express->next = lltour[xprev].fwd_express;
                lltour[xprev].bwd_express->next = lltour[y].fwd_express;
            }
        }
    } else if (x != ynext) {
        printf ("Here we are\n"); fflush (stdout);
        if (lltour[xprev].fwd_express->level != 2)
            SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
/*
        if (lltour[xprev].fwd_express->level == 2) {
            SWAP (lltour[xprev].fwd_express, lltour[xprev].bwd_express, otemp);
            SWAP (lltour[xprev].fwd, lltour[xprev].bwd, otemp);
        }
*/
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void super_flip (int ix, int iy)
#else
static void super_flip (ix, iy)
int ix, iy;
#endif
{
    llnode *x = &(lltour[ix]);
    llnode *y = &(lltour[iy]);
    llnode *xprev, *ynext;
    llnode *n, *next, *prev;
    oneway *otemp;

/*
    printf ("super_flip (%d, %d) ...\n", ix, iy);
    fflush (stdout);
*/

    if (x == y) {
        SWAP (x->fwd_express, x->bwd_express, otemp);
        SWAP (x->fwd, x->bwd, otemp);
        return;
    }

    if (reversed) {
        xprev = x->next_super;
        ynext = y->prev_super;

        next = x->prev_super;
        prev = xprev->next_super;

        while (next != y && prev != ynext) {
            next = next->prev_super;
            prev = prev->next_super;
        }

        if (next == y) {
            next = x->prev_super;
            x->prev_super = x->next_super;
            x->next_super = next;
            SWAP (x->fwd_express, x->bwd_express, otemp);
            SWAP (x->fwd, x->bwd, otemp);

            do {
                n = next;
                next = n->prev_super;
                n->prev_super = n->next_super;
                n->next_super = next;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != y);

            if (xprev != y) {
                y->next_super = xprev;
                x->prev_super = ynext;
                xprev->prev_super = y;
                ynext->next_super = x;
            }
        } else {
            prev = xprev->next_super;
            xprev->next_super = xprev->prev_super;
            xprev->prev_super = prev;
            SWAP (xprev->fwd_express, xprev->bwd_express, otemp);
            SWAP (xprev->fwd, xprev->bwd, otemp);

            do {
                n = prev;
                prev = n->next_super;
                n->next_super = n->prev_super;
                n->prev_super = prev;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != ynext);

            if (xprev != y) {
                y->prev_super = xprev;
                x->next_super = ynext;
                xprev->next_super = y;
                ynext->prev_super = x;
            }
            reversed = 0;
        }
    } else {
        xprev = x->prev_super;
        ynext = y->next_super;

        next = x->next_super;
        prev = xprev->prev_super;

        while (next != y && prev != ynext) {
            next = next->next_super;
            prev = prev->prev_super;
        }

        if (next == y) {
            next = x->next_super;
            x->next_super = x->prev_super;
            x->prev_super = next;
            SWAP (x->fwd_express, x->bwd_express, otemp);
            SWAP (x->fwd, x->bwd, otemp);

            do {
                n = next;
                next = n->next_super;
                n->next_super = n->prev_super;
                n->prev_super = next;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != y);

            if (xprev != y) {
                y->prev_super = xprev;
                x->next_super = ynext;
                xprev->next_super = y;
                ynext->prev_super = x;
            }
        } else {
            prev = xprev->prev_super;
            xprev->prev_super = xprev->next_super;
            xprev->next_super = prev;
            SWAP (xprev->fwd_express, xprev->bwd_express, otemp);
            SWAP (xprev->fwd, xprev->bwd, otemp);

            do {
                n = prev;
                prev = n->prev_super;
                n->prev_super = n->next_super;
                n->next_super = prev;
                SWAP (n->fwd_express, n->bwd_express, otemp);
                SWAP (n->fwd, n->bwd, otemp);
            } while (n != ynext);

            if (xprev != y) {
                y->next_super = xprev;
                x->prev_super = ynext;
                xprev->prev_super = y;
                ynext->next_super = x;
            }
            reversed = 1;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CClinkern_flipper_sequence (int x, int y, int z)
#else
int CClinkern_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    int control, temp;
    oneway *next, *prev;
    int war = 0;

    if (x == z || x == y) {
        temp = 1;
    } else {

        {
            oneway *px, *py, *pz;

            if (find_orientation (x))
                px = lltour[x].bwd;
            else
                px = lltour[x].fwd;
            while (!px->level && px->name != y && px->name != z)
                px = px->next;
            if (px->name == y) {
                temp = 1;
                war = 1;
                goto GET_OUT;
            } else if (px->name == z) {
                temp = 0;
                war = 2;
                goto GET_OUT;
            }

            if (find_orientation (z))
                pz = lltour[z].fwd;
            else
                pz = lltour[z].bwd;
            while (!pz->level && pz->name != x && pz->name != y)
                pz = pz->next;
            if (pz->name == y) {
                temp = 1;
                war = 3;
                goto GET_OUT;
            } else if (pz->name == x) {
                temp = 0;
                war = 4;
                goto GET_OUT;
            } else if (px == pz) {
                temp = 0;
                war = 5;
                goto GET_OUT;
            }

            if (find_orientation (y))
                py = lltour[y].bwd;
            else
                py = lltour[y].fwd;
            while (!py->level && py->name != x && py->name != z)
                py = py->next;
            if (py->name == z) {
                temp = 1;
                war = 6;
                goto GET_OUT;
            } else if (py->name == x) {
                temp = 0;
                war = 7;
                goto GET_OUT;
            } else if (py == pz) {
                temp = 1;
                war = 8;
                goto GET_OUT;
            } else if (py == px) {
                temp = 0;
                war = 9;
                goto GET_OUT;
            } else {
                temp = express_flipper_sequence (px->name, py->name, pz->name);
                war = 10;
                goto GET_OUT;
            }
        }
    }


/*
        lltour[y].fwd->mark = 1;
        lltour[y].bwd->mark = 1;
        lltour[z].fwd->mark = 1;
        lltour[z].bwd->mark = 1;

        if (find_orientation (x)) {
            next = lltour[x].bwd;
            prev = lltour[x].fwd;
        } else {
            next = lltour[x].fwd;
            prev = lltour[x].bwd;
        }

        while (!next->mark && !prev->mark) {
            next = next->next;
            prev = prev->next;
        }

        if (next->mark) {
            lltour[y].fwd->mark = 0;
            lltour[y].bwd->mark = 0;
            lltour[z].fwd->mark = 0;
            lltour[z].bwd->mark = 0;
            temp = (next->name == y);
        } else {
            lltour[y].fwd->mark = 0;
            lltour[y].bwd->mark = 0;
            lltour[z].fwd->mark = 0;
            lltour[z].bwd->mark = 0;
            temp = (prev->name == z);
        }
    }
*/

GET_OUT:

    assert (temp == test_flipper_sequence (x, y, z));
    return temp;
}

#ifdef CC_PROTOTYPE_ANSI
static int express_flipper_sequence (int x, int y, int z)
#else
static int express_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    oneway *next, *prev;

    lltour[y].fwd_express->mark = 1;
    lltour[y].bwd_express->mark = 1;
    lltour[z].fwd_express->mark = 1;
    lltour[z].bwd_express->mark = 1;

    if (find_orientation (x)) {
        next = lltour[x].bwd_express;
        prev = lltour[x].fwd_express;
    } else {
        next = lltour[x].fwd_express;
        prev = lltour[x].bwd_express;
    }

    while (!next->mark && !prev->mark) {
        next = next->next;
        prev = prev->next;
    }

    if (next->mark) {
        lltour[y].fwd_express->mark = 0;
        lltour[y].bwd_express->mark = 0;
        lltour[z].fwd_express->mark = 0;
        lltour[z].bwd_express->mark = 0;
        return (next->name == y);
    } else {
        lltour[y].fwd_express->mark = 0;
        lltour[y].bwd_express->mark = 0;
        lltour[z].fwd_express->mark = 0;
        lltour[z].bwd_express->mark = 0;
        return (prev->name == z);
    }
}


/************* TEST CODE **************/


#ifdef CC_PROTOTYPE_ANSI
static int test_flipper_init (int ncount, int *cyc)
#else
static int test_flipper_init (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i;

    test_flip_cyc = CC_SAFE_MALLOC (ncount, int);
    if (!test_flip_cyc)
        return 1;
    test_flip_cyc_inv = CC_SAFE_MALLOC (ncount, int);
    if (!test_flip_cyc_inv) {
        CC_FREE (cyc, int);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
        test_flip_cyc[i] = cyc[i];
        test_flip_cyc_inv[cyc[i]] = i;
    }
    test_cycle_size = ncount;
    test_short_size = ncount/2;
    test_reversed = 0;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int test_flipper_cycle (int *x)
#else
static int test_flipper_cycle (x)
int *x;
#endif
{
    int *p;

    if (test_reversed) {
        p = test_flip_cyc + test_cycle_size;
        while (p > test_flip_cyc) {
            *x++ = *--p;
        }
    } else {
        p = test_flip_cyc + test_cycle_size;
        x += test_cycle_size;
        while (p > test_flip_cyc) {
            *--x = *--p;
        }
    }
    return test_cycle_size;
}

#ifdef CC_PROTOTYPE_ANSI
static void test_flipper_finish (void)
#else
static void test_flipper_finish ()
#endif
{
    if (test_flip_cyc)
        CC_FREE (test_flip_cyc, int);
    if (test_flip_cyc_inv)
        CC_FREE (test_flip_cyc_inv, int);
    test_cycle_size = 0;
    test_short_size = 0;
    test_reversed = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void test_flipper_free_world (void)
#else
static void test_flipper_free_world ()
#endif
{
    return;
}

#ifdef CC_PROTOTYPE_ANSI
static int test_flipper_next (int x)
#else
static int test_flipper_next (x)
int x;
#endif
{
    int y;

    if (test_reversed) {
        y = test_flip_cyc_inv[x] - 1;
        return (y >= 0) ? test_flip_cyc[y] : test_flip_cyc[test_cycle_size-1];
    } else {
        y = test_flip_cyc_inv[x] + 1;
        return (y < test_cycle_size) ? test_flip_cyc[y] : test_flip_cyc[0];
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int test_flipper_prev (int x)
#else
static int test_flipper_prev (x)
int x;
#endif
{
    int y;

    if (test_reversed) {
        y = test_flip_cyc_inv[x] + 1;
        return (y < test_cycle_size) ? test_flip_cyc[y] : test_flip_cyc[0];
    } else {
        y = test_flip_cyc_inv[x] - 1;
        return (y >= 0) ? test_flip_cyc[y] : test_flip_cyc[test_cycle_size-1];
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void test_flipper_flip (int x, int y)
#else
static void test_flipper_flip (x, y)
int x,y;
#endif
{
    int xloc = test_flip_cyc_inv[x];
    int yloc = test_flip_cyc_inv[y];
    int temp;
    int gap;

    if (test_reversed) {
        SWAP (xloc, yloc, temp);
    }
    gap = yloc - xloc;
    if (gap < 0) gap += test_cycle_size;
    if (gap > test_short_size) {
        SWAP (xloc, yloc, temp);
        test_reversed ^= 1;
        xloc++;
        if (xloc >= test_cycle_size)
            xloc = 0;
        yloc--;
        if (yloc < 0)
            yloc = test_cycle_size - 1;
        gap = test_cycle_size - gap - 2;
    }
    if (xloc > yloc) {
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = test_flip_cyc[xloc];
            y = test_flip_cyc[yloc];
            test_flip_cyc[xloc] = y;
            test_flip_cyc[yloc] = x;
            test_flip_cyc_inv[x] = yloc--;
            test_flip_cyc_inv[y] = xloc++;
            if (xloc >= test_cycle_size)
                xloc = 0;
            if (yloc < 0)
                yloc = test_cycle_size - 1;
        }
    } else {
        gap++;
        gap /= 2;
        for (; gap; gap--) {
            x = test_flip_cyc[xloc];
            y = test_flip_cyc[yloc];
            test_flip_cyc[xloc] = y;
            test_flip_cyc[yloc] = x;
            test_flip_cyc_inv[x] = yloc--;
            test_flip_cyc_inv[y] = xloc++;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int test_flipper_sequence (int x, int y, int z)
#else
static int test_flipper_sequence (x, y, z)
int x, y, z;
#endif
{
    int xloc = test_flip_cyc_inv[x];
    int yloc = test_flip_cyc_inv[y];
    int zloc = test_flip_cyc_inv[z];

    if (test_reversed) {
        if (xloc >= yloc)
            return yloc >= zloc || zloc >= xloc;
        else
            return yloc >= zloc && zloc >= xloc;
    } else {
        if (xloc <= yloc)
            return yloc <= zloc || zloc <= xloc;
        else
            return yloc <= zloc && zloc <= xloc;
    }
}
