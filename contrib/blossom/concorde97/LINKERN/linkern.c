/***************************************************************************/
/*                                                                         */
/*                    ITERATED LIN-KERNIGHAN                               */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: March 22, 1995                                                   */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*   int CClinkern_tour (int ncount, CCdatagroup *dat, int ecount,         */
/*           int *elist, int stallcount, int repeatcount, int *incycle,    */
/*           int *outcycle, double *val                                    */
/*           int run_silently, double time_bound, double length_bound,     */
/*           char *saveit_name)                                            */
/*    RUNS Chained Lin-Kernighan.                                          */
/*    -ncount (the number of nodes int the graph)                          */
/*    -dat (coordinate dat)                                                */
/*    -ecount (the number of good edges - should not be 0)                 */
/*    -elist (the good edges in end1 end2 format)                          */
/*    -stallcount (the max number of 4-swaps without progress              */
/*    -repeatcount (the number of 4-swap kicks)                            */
/*    -incycle (a starting cycle, in node node node format - can be NULL)  */
/*    -outcycle (returns the cycle - can be NULL)                          */
/*    -run_slightly (if nonzero, then very little info will be printed)    */
/*    -time_bound (if postive, then the search will stop after the kick    */
/*       that puts the running time above this number of seconds)          */
/*    -length_bound (if postive, then the search will stop after the kick  */
/*       that puts the tour at or below this length)                       */
/*    -saveit_name (if non NULL then the tour will be saved to this file   */
/*       after every 10000 kicks - if it has improved)                     */
/*                                                                         */
/*    NOTES: If incycle is NULL, then a random starting cycle is used. If  */
/*     outcycle is not NULL, then it should point to an array of length at */
/*     least ncount. The type of flipper to be used should be defined in   */
/*     linkern.h and added to the makefile).                               */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "linkern.h"

#define MAX_OUTPUT 0       /* Define to 1 to have more output */

#define MAXDEPTH 50        /* Shouldn't be less than 2.  */
#define MAK_MORTON         /* Define to some of the Mak-Morton moves */
#undef  NODE_INSERTIONS    /* Define to use Reinelt's moves */
#undef  FULL_MAK_MORTON    /* Define to use all of the Mak-Morton moves */
#define USE_LESS_OR_EQUAL
#define SUBTRACT_GSTAR
#undef  SWITCH_LATE_DEPTH  /* To give more search freedom before LATE_DEPTH */
#define LATE_DEPTH 10      /* Should be less than MAXDEPTH */

#define GEOM_FOUR_SWAPS    /* Use geometry to find close 4-swap kicks */
#undef  CLOSE_FOUR_SWAPS   /* Use distances to find close 4-swap kicks */
#undef  IMPROVE_FOUR_SWAPS /* Use an LK search as a kick */
#define IMPROVE_SWITCH  0  /* Depth to start using IMPROVE_FOUR_SWAPS  */
#define KICK_MAXDEPTH 50   /* Max # of swaps in an IMPROVE_FOUR_SWAP kick */
#define LONG_KICKER        /* Guides choice of first edge in a kick */

#define ACCEPT_TIES        /* In Chained LK, keep new tours that tie best */
#undef  ACCEPT_BAD_TOURS   /* Define to use a simulated-annealing approach */

#undef  MARK_NEIGHBORS     /* Mark the good-edge neighbors after swaps */
#define USE_LESS_MARKING   /* Do not mark the tour neighbors after swaps */
#define MARK_LEVEL  10     /* Number of tour neighbors after 4-swap kick */

#define BACKTRACK 2
#define MAX_BACK 10        /* Upper bound on the XXX_count entries          */
static int backtrack_count[BACKTRACK] = {10, 5};    /* Breadth of backtrack */
static int weird_backtrack_count[3] = {10, 5, 2};   /* For weird backtrack */

/***************************************************************************/
/***************************************************************************/
/*                                                                         */
/*                      SETTING THE PARAMETERS                             */
/*                                                                         */
/*      At this point (27.8.97), we have not yet made a detailed           */
/*  computational study to choose a good selection of the various          */
/*  parameters that can be set. The default settings appear to work well   */
/*  for large examples, where we want to obtain a good quality tour        */
/*  quickly. For small instances where we may want to get very close to an */
/*  optimal tour, better performance can often be obtained by using random */
/*  four swaps, using a denser set of good edges, and by using a wider     */
/*  (or deeper) search in the backtracking.                                */
/*     The default settings are as follows:                                */
/*                                                                         */
/*        MAXDEPTH 50   (this means that Lin-Kernighan will not consider   */
/*                       sequences of 2-opt moves longer than 50)          */
/*        MAX_MORTON    (this permits the code to perform the "inverse"    */
/*                       moves described in the paper by Mak and Morton.   */
/*        USE_LESS_OR_EQUAL  (this tells the code to consider edges that   */
/*                       have length <= the current gain (it is usually    */
/*                       the case that LK is implemented to allow only     */
/*                       edges that are < the current gain))               */
/*        SUBTRACT_GSTAR   (restricts the freedom of the search to avoid   */
/*                       long sequences of 2-opt moves that do not have    */
/*                       a good chance of improving on the current best    */
/*                       gain (gstar))                                     */
/*        GEOM_FOUR_SWAPS   (uses 4-swap kicks between nodes that are      */
/*                       geometrically close, this is better than random   */
/*                       4-swaps for very large instances)                 */
/*        LONG_KICKER   (choose the initial edge in a 4-swap kick to be    */
/*                       one that is long relative to the length of the    */
/*                       shortest good edge meeting the node (this is an   */
/*                       idea of Andre Rohe))                              */
/*        USE_LESS_MARKING   (do not mark the tour neighbors of the nodes  */
/*                       appearing in an improving swap sequence)          */
/*        BACKTRACK 2   (backtrack at the first two levels of the search)  */
/*        MAX_BACK 10   (do not use more than breadth 10 in a backtrack)   */
/*        backtrack_count[BACKTRACK] = {10, 5}   (to use breadth 10 at the */
/*                       first level and breadth 5 at the second level)    */
/*        weird_backtrack_count[3] = {10, 5, 2}  (in the weird step, use   */
/*                       breadth 10 at first level, 5 at second level)     */
/*                                                                         */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/


#ifdef GEOM_FOUR_SWAPS
#include "kdtree.h"
#endif

#define BIGINT 1000000000
#define BIGDOUBLE 100000000000.0

#define OTHEREND(e,n) (e->ends[0] == n ? e->ends[1] : e->ends[0])
#define SWAP(x,y,temp) {(temp) = (x); (x) = (y); (y) = (temp);}
#define Edgelen(n1, n2)  dist (n1, n2)
/*
#define Edgelen(n1, n2)  CCutil_dat_edgelen (n1, n2, gdat)
*/


#ifdef CC_EXTRA_INFO_FLIP
#define FLIP(aprev, a, b, bnext, numi) {                                   \
    CClinkern_flipper_flip ((aprev), (a), (b), (bnext));                   \
    flipstack[flip_counter].first = (a);                                   \
    flipstack[flip_counter].last = (b);                                    \
    flipstack[flip_counter].firstprev = (aprev);                           \
    flipstack[flip_counter++].lastnext = (bnext);                          \
}
#else
#define FLIP(aprev, a, b, bnext, numi) {                                   \
    CClinkern_flipper_flip ((a), (b));                                     \
    flipstack[flip_counter].first = (a);                                   \
    flipstack[flip_counter++].last = (b);                                  \
}
#endif

#ifdef    CC_NO_UNDO_SEGMENTS_FLIPPER
#define UNFLIP(aprev, a, b, bnext, numi) {                                 \
    flip_counter--;                                                        \
}
#else  /* CC_NO_UNDO_SEGMENTS_FLIPPER */
#ifdef CC_EXTRA_INFO_FLIP
#define UNFLIP(aprev, a, b, bnext, numi) {                                 \
    CClinkern_flipper_flip ((aprev), (b), (a), (bnext));                   \
    flip_counter--;                                                        \
}
#else
#define UNFLIP(aprev, a, b, bnext, numi) {                                 \
    CClinkern_flipper_flip ((b), (a));                                     \
    flip_counter--;                                                        \
}
#endif
#endif /* CC_NO_UNDO_SEGMENTS_FLIPPER */

#define markedge_add(n1, n2)    add_edges[n1 ^ n2] = 1
#define markedge_del(n1, n2)    del_edges[n1 ^ n2] = 1
#define unmarkedge_add(n1, n2)  add_edges[n1 ^ n2] = 0
#define unmarkedge_del(n1, n2)  del_edges[n1 ^ n2] = 0
#define is_it_added(n1, n2)     add_edges[n1 ^ n2]
#define is_it_deleted(n1, n2)   del_edges[n1 ^ n2]

#define ADD_TO_ACTIVE_QUEUE(n, ip) {                                       \
    if (!active[(n)]) {                                                    \
        active[(n)] = 1;                                                   \
        (ip) = intptralloc ();                                             \
        (ip)->this = (n);                                                  \
        (ip)->next = (intptr *) NULL;                                      \
        if (bottom_active_queue)                                           \
            bottom_active_queue->next = (ip);                              \
        else                                                               \
            active_queue = (ip);                                           \
        bottom_active_queue = (ip);                                        \
    }                                                                      \
}

typedef struct edge {
    int other;
    int weight;
} edge;

typedef struct edgelook {
    struct edgelook *next;
    int other;
    int diff;
    int over;
    int seq;
    int side;
#ifdef MAK_MORTON
    int mm;
#endif
#ifdef NODE_INSERTIONS
    int ni;
    int under;
#endif
} edgelook;

typedef struct intptr {
    int this;
    struct intptr *next;
} intptr;

typedef struct flippair {
    int firstprev;
    int first;
    int last;
    int lastnext;
} flippair;


#ifdef CC_PROTOTYPE_ANSI

static void
    look_ahead_noback (int first, int last, int G, edgelook *winner),
    turn (int n),
#ifdef IMPROVE_FOUR_SWAPS
    kickturn (int n),
#endif
    bigturn (int n, int tonext),
#ifdef LONG_KICKER
    first_long_kicker (int ncount, int *t1, int *t2),
#endif
#if defined(CLOSE_FOUR_SWAPS) || defined(GEOM_FOUR_SWAPS)
    find_close_four (int ncount, int *t1, int *t2, int *t3, int *t4,
                                 int *t5, int *t6, int *t7, int *t8),
#endif
    randcycle (int ncount, int *cyc),
    insertedge (int n1, int n2, int w),
    free_graph (int ncount),
    linkern_free_world (void);

static int
    buildgraph (int ncount, int ecount, int *elist),
    repeated_lin_kernighan (int ncount, int *cyc, int stallcount,
                            int repeatcount, double *val, double time_bound,
                            double length_bound,  char *saveit_name),
    lin_kernighan (int ncount, double *val),
    weird_second_step (int G, int t1, int t2),
    step (int level, int G, int *Gstar, int first, int last),
    step_noback (int level, int G, int *Gstar, int first, int last),
#ifdef IMPROVE_FOUR_SWAPS
    kick_step_noback (int level, int G, int *Gstar, int first, int last),
#endif
#ifdef GEOM_FOUR_SWAPS
    find_geometric_four (int ncount, CCkdtree *kdt,
                         int *t1, int *t2, int *t3, int *t4,
                         int *t5, int *t6, int *t7, int *t8),
    random_four_swap (int ncount, CCkdtree *kdt, int *delta),
#else
    random_four_swap (int ncount),
#endif
    initarrays (int ncount),
    initcache (int ncount),
    dist (int i, int j);

static double
    improve_tour (int start),
#ifdef IMPROVE_FOUR_SWAPS
    kick_improve (int ncount),
#endif
    cycle_length (int ncount, int *cyc);

static edgelook
   *look_ahead (int first, int last, int G, int level),
   *weird_look_ahead (int G, int t1, int t2),
   *weird_look_ahead2 (int G, int t2, int t3, int t4),
   *weird_look_ahead3 (int G, int t2, int t3, int t6);

#else

static void
    look_ahead_noback (),
    turn (),
#ifdef IMPROVE_FOUR_SWAPS
    kickturn (),
#endif
    bigturn (),
#ifdef LONG_KICKER
    first_long_kicker (),
#endif
#if defined(CLOSE_FOUR_SWAPS) || defined(GEOM_FOUR_SWAPS)
    find_close_four (),
#endif
    randcycle (),
    insertedge (),
    free_graph (),
    linkern_free_world ();

static int
    buildgraph (),
    repeated_lin_kernighan (),
    lin_kernighan (),
    weird_second_step (),
    step (),
    step_noback (),
#ifdef IMPROVE_FOUR_SWAPS
    kick_step_noback (),
#endif
#ifdef GEOM_FOUR_SWAPS
    find_geometric_four (),
    random_four_swap (),
#else
    random_four_swap (),
#endif
    initarrays (),
    initcache (),
    dist ();

static double
    improve_tour (),
#ifdef IMPROVE_FOUR_SWAPS
    kick_improve (),
#endif
    cycle_length ();

static edgelook
   *look_ahead (),
   *weird_look_ahead (),
   *weird_look_ahead2 (),
   *weird_look_ahead3 ();

#endif

static int  no_output = 0;
static char *add_edges = (char *) NULL;
static char *del_edges = (char *) NULL;
static char *active = (char *) NULL;
static int  *weirdmark = (int *) NULL;
static int  *cacheind = (int *) NULL;
static int  *cacheval = (int *) NULL;
static intptr *active_queue = (intptr *) NULL;
static intptr *bottom_active_queue = (intptr *) NULL;
static int  weirdmagic = 0;
static int  new_tour_time = 0;
#if defined(CC_NO_UNDO_SEGMENTS_FLIPPER) || defined(CC_FULL_SEGMENTS_FLIPPER)
static int  new_tour_cutoff = 1;
#endif
static int  flip_counter = 0;
static flippair *flipstack = (flippair *) NULL;
#ifdef CC_USE_FLIP_CLEANING
static int winstack_max = 0;
static int win_counter = 0;
static flippair *winstack = (flippair *) NULL;
static int      *win_cycle = (int *) NULL;
#endif

static edge **goodlist = (edge **) NULL;
static intptr **fixlist = (intptr **) NULL;
static CCdatagroup *gdat = (CCdatagroup *) NULL;
static edge *edgespace = (edge *) NULL;
static int *degree = (int *) NULL;

CC_PTR_ALLOC_ROUTINE (intptr, intptralloc, intptrchunklist, intptrfreelist)
CC_PTR_FREE_ROUTINE (intptr, intptrfree, intptrfreelist)
CC_PTR_FREE_LIST_ROUTINE (intptr, intptr_list_free, intptrfree)
CC_PTR_FREE_WORLD_ROUTINE (intptr, intptrfree_world, intptrchunklist,
                  intptrfreelist)
CC_PTR_LEAKS_ROUTINE (intptr, intptr_check_leaks, intptrchunklist,
                  intptrfreelist, this, int)

CC_PTR_ALLOC_ROUTINE (edgelook, edgelookalloc, edgelookchunklist,
                  edgelookfreelist)
CC_PTR_FREE_ROUTINE (edgelook, edgelookfree, edgelookfreelist)
CC_PTR_FREE_LIST_ROUTINE(edgelook, edgelook_list_free, edgelookfree)
CC_PTR_FREE_WORLD_ROUTINE( edgelook, edgelookfree_world, edgelookchunklist,
                  edgelookfreelist)
CC_PTR_LEAKS_ROUTINE (edgelook, edgelook_check_leaks, edgelookchunklist,
                  edgelookfreelist, diff, int)


#ifdef CC_PROTOTYPE_ANSI
int CClinkern_tour (int ncount, CCdatagroup *dat, int ecount,
        int *elist, int stallcount, int repeatcount, int *incycle,
        int *outcycle, double *val, int run_silently, double time_bound,
        double length_bound, char *saveit_name)
#else
int CClinkern_tour (ncount, dat, ecount, elist, stallcount, repeatcount,
        incycle, outcycle, val, run_silently, time_bound, length_bound,
        saveit_name)
int ncount;
CCdatagroup *dat;
int ecount;
int *elist;
int stallcount, repeatcount;
int *incycle;
int *outcycle;
double *val;
int run_silently;
double time_bound;
double length_bound;
char *saveit_name;
#endif
{
    int i;
    double startzeit, goodzeit;
    int *tcyc = (int *) NULL;
    intptr *ip;
    int rval = 0;

    if (!run_silently) {
        printf ("linkern with %d nodes ...\n", ncount);
        fflush (stdout);
    }
    startzeit = CCutil_zeit ();

    no_output = run_silently;
    gdat = dat;
    fixlist = (intptr **) NULL;
    active_queue = (intptr *) NULL;
    bottom_active_queue = (intptr *) NULL;
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
    new_tour_time = 0;
#endif
#ifdef CC_FULL_SEGMENTS_FLIPPER
    new_tour_time = 100000;
#endif
#ifdef CC_SEGMENTS_FLIPPER
    new_tour_time = (ncount / 250) + 1;  /* 5.5.95 - 250 now looks okay    */
#endif

#if defined(CC_NO_UNDO_SEGMENTS_FLIPPER) || defined(CC_FULL_SEGMENTS_FLIPPER)
    new_tour_cutoff = 500 + ncount / 50;
#endif

#ifdef NODE_INSERTIONS
    flipstack = CC_SAFE_MALLOC (new_tour_time + 2*MAXDEPTH + 7 + KICK_MAXDEPTH,
                             flippair);
#else
    flipstack = CC_SAFE_MALLOC (new_tour_time + MAXDEPTH + 7 + KICK_MAXDEPTH,
                             flippair);
#endif
    if (!flipstack) {
        rval = 1;
        goto CLEANUP;
    }
#ifdef CC_USE_FLIP_CLEANING
    win_counter = 0;
#ifdef CC_FULL_SEGMENTS_FLIPPER
    winstack_max = 100000;
#else
    winstack_max = (500 + ncount / 50) +
                   (2 * (new_tour_time + MAXDEPTH + 7 + KICK_MAXDEPTH));
#endif
    winstack = CC_SAFE_MALLOC (winstack_max, flippair);
    if (!winstack) {
        rval = 1;
        goto CLEANUP;
    }
#ifndef CC_FULL_SEGMENTS_FLIPPER
    winstack_max -= ( 2 * (new_tour_time + MAXDEPTH + 7 + KICK_MAXDEPTH));
#endif
    win_cycle = CC_SAFE_MALLOC (ncount, int);
    if (!win_cycle) {
        rval = 1;
        goto CLEANUP;
    }
    win_cycle[0] = -1;
#endif  /* CC_USE_FLIP_CLEANING */
    tcyc = CC_SAFE_MALLOC (ncount, int);
    if (!tcyc) {
        rval = 1;
        goto CLEANUP;
    }
    if (initarrays (ncount)) {
        rval = 1;
        goto CLEANUP;
    }
    if (initcache (ncount)) {
        rval = 1;
        goto CLEANUP;
    }

    if (buildgraph (ncount, ecount, elist)) {
        fprintf (stderr, "buildgraph failed\n");
        rval = 1;
        goto CLEANUP;
    }
#ifdef BIG_PROBLEM
    CC_FREE (elist, int);
#endif

    randcycle (ncount, tcyc);        /* init active_queue with random order */
    for (i = 0; i < ncount; i++) {
        ADD_TO_ACTIVE_QUEUE (tcyc[i], ip);
    }

    if (incycle) {
        for (i = 0; i < ncount; i++)
            tcyc[i] = incycle[i];
        *val = cycle_length (ncount, tcyc);
        if (!no_output) {
            printf ("Starting Cycle: %.0f\n", *val);
            fflush (stdout);
        }
    } else {
        goodzeit = CCutil_zeit ();
        randcycle (ncount, tcyc);
        *val = cycle_length (ncount, tcyc);
        if (!no_output) {
            printf ("Random Cycle: %.0f  (Running Time: %.2f seconds)\n",
                    *val, CCutil_zeit () - goodzeit);
            fflush (stdout);
        }
    }
    if (repeated_lin_kernighan (ncount, tcyc, stallcount,
              repeatcount, val, time_bound, length_bound, saveit_name)) {
        fprintf (stderr, "repeated_lin_kernighan failed\n");
        rval = 1;
        goto CLEANUP;
    }

    if (!no_output) {
        printf ("Best cycle length: %.0f\n", *val);
        printf ("Lin-Kernighan Running Time: %.2f\n",
                            CCutil_zeit () - startzeit);
        fflush (stdout);
    }

    if (outcycle) {
        for (i = 0; i < ncount; i++)
            outcycle[i] = tcyc[i];
    }

CLEANUP:

    CC_IFFREE (flipstack, flippair);
    CC_IFFREE (tcyc, int);
    CC_IFFREE (add_edges, char);
    CC_IFFREE (del_edges, char);
    CC_IFFREE (active, char);
    CC_IFFREE (weirdmark, int);
    CC_IFFREE (cacheind, int);
    CC_IFFREE (cacheval, int);
#ifdef CC_USE_FLIP_CLEANING
    CC_IFFREE (winstack, flippair);
    CC_IFFREE (win_cycle, int);
#endif

    free_graph (ncount);
    CClinkern_flipper_free_world ();
    linkern_free_world ();

    return rval;
}

#ifdef ACCEPT_BAD_TOURS
#define HEAT_FACTOR 0.999
#define HEAT_RESET 100000
#define HEAT_MULT  20
#endif

#ifdef CC_PROTOTYPE_ANSI
static int repeated_lin_kernighan (int ncount, int *cyc, int stallcount,
        int count, double *val, double time_bound, double length_bound, 
        char *saveit_name)
#else
static int repeated_lin_kernighan (ncount, cyc, stallcount, count, val,
        time_bound, length_bound, saveit_name)
int ncount;
int *cyc;
int stallcount, count;
double *val;
double time_bound;
double length_bound;
char *saveit_name;
#endif
{
    int round = 0, quitcount, hit;
    double t, best = *val, oldbest = *val;
    int delta;
    double szeit = CCutil_zeit ();
#ifdef ACCEPT_BAD_TOURS
    double heat = *val / (double) (HEAT_MULT * ncount), tdelta;
#endif
#ifdef GEOM_FOUR_SWAPS
    CCkdtree kdt;
#endif

#ifdef GEOM_FOUR_SWAPS
    if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (CCkdtree_build (&kdt, ncount, gdat, (double *) NULL)) {
            fprintf (stderr, "CCkdtree_build failed\n");
            fflush (stdout);
            return 1;
        }
    }
#endif

    quitcount = stallcount;
    if (quitcount > count)
        quitcount = count;

    CClinkern_flipper_init (ncount, cyc);
    flip_counter = 0;
#ifdef CC_USE_FLIP_CLEANING
    win_counter = 0;
    win_cycle[0] = -1;
#endif
    if (lin_kernighan (ncount, &best)) {
        fprintf (stderr, "lin_kernighan failed\n");
#ifdef GEOM_FOUR_SWAPS
        if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE)
            CCkdtree_free (&kdt);
#endif
        return 1;
    }
#ifdef CC_USE_FLIP_CLEANING
#ifdef CC_FULL_SEGMENTS_FLIPPER
    {
        int i;

        if (flip_counter > 0) {
            if (flip_counter < new_tour_cutoff) {
                for (i = 0; i < flip_counter; i++)
                    CClinkern_flipper_flip_perm (flipstack[i].first,
                                       flipstack[i].last);
                CClinkern_flipper_reset_perm (1);
            } else {
                CClinkern_flipper_reset_temp (ncount);
            }
            flip_counter = 0;
        }
    }
#endif   /* CC_FULL_SEGMENTS_FLIPPER */
    win_counter = 0;
    win_cycle[0] = -1;
#else
    CClinkern_flipper_cycle (cyc);
    CClinkern_flipper_finish ();
#endif

    if (!no_output) {
        if (quitcount > 0)
            printf ("%d Steps   Best: %.0f   %.2f seconds\n", round, best,
                                CCutil_zeit () - szeit);
        else
            printf ("LK Cycle: %.0f\n", best);
        fflush (stdout);
    }

    while (round < quitcount) {
        hit = 0;

#ifndef CC_USE_FLIP_CLEANING
        CClinkern_flipper_init (ncount, cyc);
#endif
        flip_counter = 0;

#ifdef IMPROVE_FOUR_SWAPS
        if (round < IMPROVE_SWITCH)
            delta = random_four_swap (ncount);
        else
            delta = kick_improve (ncount);
#else
#ifdef GEOM_FOUR_SWAPS
        if (random_four_swap (ncount, &kdt, &delta)) {
            fprintf (stderr, "random_four_swap failed\n");
            fflush (stdout);
            CCkdtree_free (&kdt);
            return 1;
        }
#else
        delta = random_four_swap (ncount);
#endif /* GEOM_FOUR_SWAPS */
#endif /* IMPROVE_FOUR_SWAPS */

#if defined(CC_NO_UNDO_SEGMENTS_FLIPPER) || defined(CC_FULL_SEGMENTS_FLIPPER)
        {
            int fi;
            CClinkern_flipper_reset_perm (0);  /* For Quick Flips */
            for (fi = 0; fi < flip_counter; fi++) {
                CClinkern_flipper_flip_perm (flipstack[fi].first,
                                   flipstack[fi].last);
            }
            CClinkern_flipper_reset_perm (1);
        }
#endif
        flip_counter = 0;
        t = best + delta;

        if (lin_kernighan (ncount, &t)) {
            fprintf (stderr, "lin_kernighan failed\n");
#ifdef GEOM_FOUR_SWAPS
            if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE)
                CCkdtree_free (&kdt);
#endif
            return 1;
        }

#ifdef ACCEPT_BAD_TOURS
        if (round % HEAT_RESET == HEAT_RESET - 1) {
            heat = oldbest / (HEAT_MULT * ncount);
            printf ("Reset Accept-Probablility\n");
            fflush (stdout);
        }
        tdelta = t - best;
        heat *= HEAT_FACTOR;
        if (t < best || (t > best && exp (-tdelta/heat) >
                   (double) (CCutil_lprand () % ncount) / (double) ncount)) {
#else
#ifdef ACCEPT_TIES
        if (t <= best) {
#else
        if (t < best) {
#endif /* ACCEPT_TIES */
#endif /* ACCEPT_BAD_TOURS */
#ifdef CC_USE_FLIP_CLEANING
#ifdef CC_FULL_SEGMENTS_FLIPPER
            {
                int i;

                if (flip_counter > 0) {
                    if (flip_counter < new_tour_cutoff) {
                        for (i = 0; i < flip_counter; i++)
                            CClinkern_flipper_flip_perm (flipstack[i].first,
                                               flipstack[i].last);
                        CClinkern_flipper_reset_perm (1);
                    } else {
                        CClinkern_flipper_reset_temp (ncount);
                    }
                    flip_counter = 0;
                }
            }
#endif  /* CC_FULL_SEGMENTS_FLIPPER */
            win_counter = 0;
            win_cycle[0] = -1;
#else
            CClinkern_flipper_cycle (cyc);
            CClinkern_flipper_finish ();
#endif
            if (t < best) {
                best = t;
                quitcount = round + stallcount;
                if (quitcount > count)
                    quitcount = count;
                hit++;
            }
#ifdef ACCEPT_BAD_TOURS
            else {
                if (!no_output && t > best) {
                    printf ("%d Steps   Best: %.0f   %.2f seconds (Negative %.0f) (%.0f)\n",
                          round, t, CCutil_zeit () - szeit, t - best, oldbest);
                    fflush (stdout);
                }
                best = t;
            }
#endif
        } else {
#ifdef CC_USE_FLIP_CLEANING
#ifdef CC_FULL_SEGMENTS_FLIPPER
            {
                /* WON'T WORK WITH IMPROVE_FOUR_SWAPS */
                int i;
                for (i = 2; i >= 0; i--) {
                    CClinkern_flipper_flip_perm (winstack[i].last,
                                       winstack[i].first);
                }
            }
            CClinkern_flipper_reset_perm (1);
            win_cycle[0] = -1;
            win_counter = 0;
#else
            if (win_cycle[0] == -1) {
                while (win_counter) {
                    win_counter--;
#ifdef CC_EXTRA_INFO_FLIP
                    CClinkern_flipper_flip (winstack[win_counter].firstprev,
                                  winstack[win_counter].last,
                                  winstack[win_counter].first,
                                  winstack[win_counter].lastnext);
#else
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
                    CClinkern_flipper_flip_perm (winstack[win_counter].last,
                                  winstack[win_counter].first);
#else
                    CClinkern_flipper_flip (winstack[win_counter].last,
                                  winstack[win_counter].first);
#endif
#endif  /* CC_EXTRA_INFO_FLIP */
                }
            } else {
                CClinkern_flipper_finish ();
                CClinkern_flipper_init (ncount, win_cycle);
                while (win_counter) {
                    win_counter--;
#ifdef CC_EXTRA_INFO_FLIP
                    CClinkern_flipper_flip (winstack[win_counter].firstprev,
                                  winstack[win_counter].last,
                                  winstack[win_counter].first,
                                  winstack[win_counter].lastnext);
#else
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
                    CClinkern_flipper_flip_perm (winstack[win_counter].last,
                                  winstack[win_counter].first);
#else
                    CClinkern_flipper_flip (winstack[win_counter].last,
                                  winstack[win_counter].first);
#endif
#endif  /* CC_EXTRA_INFO_FLIP */
                }
                win_cycle[0] = -1;
            }
#ifdef  CC_NO_UNDO_SEGMENTS_FLIPPER
            CClinkern_flipper_reset_perm (1);
#endif
#endif  /* CC_FULL_SEGMENTS_FLIPPER */

#else  /* CC_USE_FLIP_CLEANING */
            CClinkern_flipper_finish ();
#endif
        }

        round++;
        if (!no_output && (hit || (round % 1000 == 999) || MAX_OUTPUT)) {
            printf ("%d Steps   Best: %.0f   %.2f seconds\n", round, best,
                                   CCutil_zeit () - szeit);
            fflush (stdout);
        }

#ifdef BIG_PROBLEM
        if (saveit_name && (round % 10000 == 9999) && best < oldbest) {
#else
        if (saveit_name && (round % 100 == 99) && best < oldbest) {
#endif
            int *ctemp = (int *) NULL;

            ctemp = CC_SAFE_MALLOC (ncount, int);
            if (!ctemp) {
#ifdef GEOM_FOUR_SWAPS
                if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE)
                    CCkdtree_free (&kdt);
#endif
                return 1;
            }
            CClinkern_flipper_cycle (ctemp);
#ifdef BIG_PROBLEM
            if (CCutil_writecycle (ncount, saveit_name, ctemp)) {
#else
            if (CCutil_writecycle_edgelist (ncount, saveit_name, ctemp, gdat)) {
#endif
                fprintf (stderr, "could not write the cycle\n");
                CC_FREE (ctemp, int);
#ifdef GEOM_FOUR_SWAPS
                if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE)
                    CCkdtree_free (&kdt);
#endif
                return 1;
            }
            printf ("Wrote the tour to %s\n", saveit_name);
            fflush (stdout);
            CC_FREE (ctemp, int);
            oldbest = best;
        }

        if (time_bound > 0.0 && (CCutil_zeit () - szeit) > time_bound) {
            if (!no_output) {
                printf ("STOP - timebound reached (%.2f seconds)\n",
                             CCutil_zeit () - szeit);
                fflush (stdout);
            } else {
                printf ("%d Steps\n", round);
                fflush (stdout);
            }
            break;
        }
        if (length_bound > 0.0 && best <= length_bound) {
            if (!no_output) {
                printf ("STOP - length bound reached (%.0f)\n", length_bound);
                fflush (stdout);
            } else {
                printf ("%d Steps\n", round);
                fflush (stdout);
            }
            break;
        }
    }
    if (!no_output && round > 0) {
        printf ("%d Total Steps.\n", round);
        fflush (stdout);
    }

#ifdef CC_USE_FLIP_CLEANING
    CClinkern_flipper_cycle (cyc);
    CClinkern_flipper_finish ();
#endif

    if (saveit_name && best < oldbest) {
#ifdef BIG_PROBLEM
        if (CCutil_writecycle (ncount, saveit_name, cyc)) {
#else
        if (CCutil_writecycle_edgelist (ncount, saveit_name, cyc, gdat)) {
#endif
            fprintf (stderr, "could not write the cycle\n");
#ifdef GEOM_FOUR_SWAPS
            if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE)
                CCkdtree_free (&kdt);
#endif
            return 1;
        }
        printf ("Wrote the last tour to %s\n", saveit_name);
        fflush (stdout);
    }

    t = cycle_length (ncount, cyc);
    if (t != best) {
        printf ("WARNING: LK incremental counter was off by %.0f\n", t - best);
        fflush (stdout);
        best = t;
    }

    *val = best;

#ifdef GEOM_FOUR_SWAPS
    if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE)
        CCkdtree_free (&kdt);
#endif
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int lin_kernighan (int ncount, double *val)
#else
static int lin_kernighan (ncount, val)
int ncount;
double *val;
#endif
{
    int start;
    double win, totalwin = 0.0;
    intptr *ip;

    if (ncount < 0) {
        printf ("Bad ncount: %d\n", ncount);
        return 1;
    }

    while (active_queue) {
        ip = active_queue;
        start = ip->this;
        active_queue = ip->next;
        if (ip == bottom_active_queue)
            bottom_active_queue = (intptr *) NULL;
        intptrfree (ip);
        active[start] = 0;

        win = improve_tour (start);
        if (win > 0.0) {
            totalwin += win;
            if (flip_counter >= new_tour_time) {
#if defined(CC_NO_UNDO_SEGMENTS_FLIPPER) || defined(CC_FULL_SEGMENTS_FLIPPER)
                {
                    int i;

                    if (flip_counter < new_tour_cutoff) {
                        CClinkern_flipper_reset_perm (0);  /* QUICK FLIPS */
                        for (i = 0; i < flip_counter; i++)
                            CClinkern_flipper_flip_perm (flipstack[i].first,
                                               flipstack[i].last);
                        CClinkern_flipper_reset_perm (1);
                    } else {
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
                        CClinkern_flipper_reset_perm (1);
                        for (i = 0; i < flip_counter; i++)
                            CClinkern_flipper_flip (flipstack[i].first,
                                          flipstack[i].last);
#endif
                        CClinkern_flipper_reset_temp (ncount);
                    }
                }
#endif
#ifdef CC_USE_FLIP_CLEANING
                {
                    if (win_counter < winstack_max) {
                        int i;
                        for (i = 0; i < flip_counter; i++) {
                            winstack[win_counter].first = flipstack[i].first;
                            winstack[win_counter].last = flipstack[i].last;
#ifdef CC_EXTRA_INFO_FLIP
                            winstack[win_counter].firstprev =
                                     flipstack[i].firstprev;
                            winstack[win_counter].lastnext =
                                     flipstack[i].lastnext;
#endif
                            win_counter++;
                        }
                    } else if (win_cycle[0] == -1) {
                        int i;
                        for (i = 0; i < flip_counter; i++) {
                            winstack[win_counter].first = flipstack[i].first;
                            winstack[win_counter].last = flipstack[i].last;
#ifdef CC_EXTRA_INFO_FLIP
                            winstack[win_counter].firstprev =
                                     flipstack[i].firstprev;
                            winstack[win_counter].lastnext =
                                     flipstack[i].lastnext;
#endif
                            win_counter++;
                        }
                        CClinkern_flipper_cycle (win_cycle);
                    }
                }
#endif
#ifdef CC_SEGMENTS_FLIPPER
                CClinkern_flipper_reset_temp (ncount);
#endif
                flip_counter = 0;
            }
            if (MAX_OUTPUT && !no_output) {
                printf (".");
                fflush (stdout);
            }
        }
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
          else {
            CClinkern_flipper_reset_perm (0);
        }
#endif
    }

#ifdef CC_USE_FLIP_CLEANING
    {
        if (win_cycle[0] == -1) {
            int i;
            for (i = 0; i < flip_counter; i++) {
                winstack[win_counter].first = flipstack[i].first;
                winstack[win_counter].last = flipstack[i].last;
#ifdef CC_EXTRA_INFO_FLIP
                winstack[win_counter].firstprev = flipstack[i].firstprev;
                winstack[win_counter].lastnext = flipstack[i].lastnext;
#endif
                win_counter++;
            }
        }
    }
#endif

    (*val) -= totalwin;

    if (MAX_OUTPUT && !no_output) {
        printf ("\nCYCLE LENGTH: %.0f\n", *val);
        fflush (stdout);
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static double improve_tour (int t1)
#else
static double improve_tour (t1)
int t1;
#endif
{
    int t2 = CClinkern_flipper_next (t1);
    int G, Gstar = 0;

    G = Edgelen (t1, t2);

    markedge_del (t1, t2);


    if (!step (0, G, &Gstar, t1, t2)) {
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
        CClinkern_flipper_reset_perm (0);
#endif
        Gstar = weird_second_step (G, t1, t2);
    }
    unmarkedge_del (t1, t2);

    if (Gstar) {
        turn (t1);
        turn (t2);
    }
    return (double) Gstar;
}

#ifdef CC_PROTOTYPE_ANSI
static int step (int level, int G, int *Gstar, int first, int last)
#else
static int step (level, G, Gstar, first, last)
int level, G, *Gstar;
int first, last;
#endif
{
    int val, hit = 0, oldG = G;
    int this, newlast;
#if defined(MAK_MORTON) && defined(FULL_MAK_MORTON)
    int newfirst;
#endif
    edgelook *list, *e;

    if (level >= BACKTRACK)
        return step_noback (level, G, Gstar, first, last);

    list = look_ahead (first, last, G, level);
    for (e = list; e; e = e->next) {
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
        if (e != list) {
            int i;
            CClinkern_flipper_reset_perm (0);
            for (i = 0; i < flip_counter; i++)
                CClinkern_flipper_flip (flipstack[i].first, flipstack[i].last);
        }
#endif
#if defined(MAK_MORTON) && defined(FULL_MAK_MORTON)
        if (e->mm) {
            this = e->other;
            newfirst = e->over;

            G = oldG - e->diff;
            val = G - Edgelen (newfirst, last);
            if (val > *Gstar) {
                *Gstar = val;
                hit++;
            }
            FLIP (this, newfirst, first, last, 22220);

            if (level < MAXDEPTH) {
                markedge_add (first, this);
                markedge_del (this, newfirst);
                hit += step (level + 1, G, Gstar, newfirst, last);
                unmarkedge_add (first, this);
                unmarkedge_del (this, newfirst);
            }

            if (!hit) {
                UNFLIP (this, newfirst, first, last, 9910);
            } else {
                turn (this);
                turn (newfirst);
                edgelook_list_free (list);
                return 1;
            }
        } else
#endif
        {
            this = e->other;
            newlast = e->over;

            G = oldG - e->diff;
            val = G - Edgelen (newlast, first);
            if (val > *Gstar) {
                *Gstar = val;
                hit++;
            }

            FLIP (first, last, newlast, this, 2222);

            if (level < MAXDEPTH) {
                markedge_add (last, this);
                markedge_del (this, newlast);
                hit += step (level + 1, G, Gstar, first, newlast);
                unmarkedge_add (last, this);
                unmarkedge_del (this, newlast);
            }

            if (!hit) {
                UNFLIP (first, last, newlast, this, 991);
            } else {
                turn (this);
                turn (newlast);
                edgelook_list_free (list);
                return 1;
            }
        }
    }
    edgelook_list_free (list);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int step_noback (int level, int G, int *Gstar, int first, int last)
#else
static int step_noback (level, G, Gstar, first, last)
int level, G, *Gstar;
int first, last;
#endif
{
    edgelook e;

#ifdef    SUBTRACT_GSTAR
#ifdef    SWITCH_LATE_DEPTH
    if (level < LATE_DEPTH)
        look_ahead_noback (first, last, G - *Gstar, &e);
    else
        look_ahead_noback (first, last, G - *Gstar - level, &e);
#else
    look_ahead_noback (first, last, G - *Gstar - level, &e);
#endif /* SWITCH_LATE_DEPTH */
#else
#ifdef    SWITCH_LATE_DEPTH
    if (level < LATE_DEPTH)
        look_ahead_noback (first, last, G, &e);
    else
        look_ahead_noback (first, last, G - level, &e);
#else
    look_ahead_noback (first, last, G - level, &e);
#endif /* SWITCH_LATE_DEPTH */
#endif /* SUBTRACT_GSTAR */

    if (e.diff < BIGINT) {
#ifdef NODE_INSERTIONS
        if (e.ni) {
            int hit = 0;
            int newlast = e.other;
            int next = e.under;
            int prev = e.over;
            int val;

            G -= e.diff;
            val = G - Edgelen (newlast, first);

            if (val > *Gstar) {
                *Gstar = val;
                hit++;
            }

            FLIP (first, last, newlast, next, 222211);
            FLIP (newlast, prev, last, next, 222212);

            if (level < MAXDEPTH) {
                markedge_add (last, newlast);
                markedge_add (next, prev);
                markedge_del (newlast, prev);
                markedge_del (newlast, next);
                hit += step_noback (level + 1, G, Gstar, first, newlast);
                unmarkedge_add (last, newlast);
                unmarkedge_add (next, prev);
                unmarkedge_del (newlast, prev);
                unmarkedge_del (newlast, next);
            }

            if (!hit) {
                UNFLIP (newlast, prev, last, next, 222214);
                UNFLIP (first, last, newlast, next, 222213);
                return 0;
            } else {
                turn (newlast);
                turn (next);
                turn (prev);
                return 1;
            }
        } else
#endif /* NODE_INSERTIONS */
        {
#ifdef MAK_MORTON
            if (e.mm) {
                int hit = 0;
                int this = e.other;
                int newfirst = e.over;
                int val;

                G -= e.diff;
                val = G - Edgelen (newfirst, last);
                if (val > *Gstar) {
                    *Gstar = val;
                    hit++;
                }
                FLIP (this, newfirst, first, last, 22220);

                if (level < MAXDEPTH) {
                    markedge_add (first, this);
                    markedge_del (this, newfirst);
                    hit += step_noback (level + 1, G, Gstar, newfirst, last);
                    unmarkedge_add (first, this);
                    unmarkedge_del (this, newfirst);
                }

                if (!hit) {
                    UNFLIP (this, newfirst, first, last, 9910);
                    return 0;
                } else {
                    turn (this);
                    turn (newfirst);
                    return 1;
                }
            } else
#endif  /* MAK_MORTON */
            {
                int hit = 0;
                int this = e.other;
                int newlast = e.over;
                int val;

                G -= e.diff;
                val = G - Edgelen (newlast, first);
                if (val > *Gstar) {
                    *Gstar = val;
                    hit++;
                }

                FLIP (first, last, newlast, this, 2222);

                if (level < MAXDEPTH) {
                    markedge_add (last, this);
                    markedge_del (this, newlast);
                    hit += step_noback (level + 1, G, Gstar, first, newlast);
                    unmarkedge_add (last, this);
                    unmarkedge_del (this, newlast);
                }

                if (!hit) {
                    UNFLIP (first, last, newlast, this, 991);
                    return 0;
                } else {
                    turn (this);
                    turn (newlast);
                    return 1;
                }
            }
        }
    } else {
        return 0;
    }
}

#ifdef IMPROVE_FOUR_SWAPS
#ifdef CC_PROTOTYPE_ANSI
static double kick_improve (int ncount)
#else
static double kick_improve (ncount)
int ncount;
#endif
{
    int t1, t2;
    int G, Gstar = 0;
    int hit = 0;

    do {
#ifdef LONG_KICKER
        first_long_kicker (ncount, &t1, &t2);
#else
        t1 = CCutil_lprand () % ncount;
        t2 = CClinkern_flipper_next (t1);
#endif
        G = Edgelen (t1, t2);
        markedge_del (t1, t2);
        hit = kick_step_noback (0, G, &Gstar, t1, t2);
        unmarkedge_del (t1, t2);
    } while (!hit);

    kickturn (t1);
    kickturn (t2);

    return (double) -Gstar;
}

#define G_MULT 1.5

#ifdef CC_PROTOTYPE_ANSI
static int kick_step_noback (int level, int G, int *Gstar, int first, int last)
#else
static int kick_step_noback (level, G, Gstar, first, last)
int level, G, *Gstar;
int first, last;
#endif
{
    edgelook winner;
    int val;
    int this, prev, newlast;
    int lastnext = CClinkern_flipper_next (last);
    int i;
    int cutoff = (int) (G_MULT * (double) G);

    /* NOTE: not set up for fixed edges */

    winner.diff = BIGINT;
    for (i = 0; goodlist[last][i].weight < cutoff; i++) {
        this = goodlist[last][i].other;
        if (!is_it_deleted (last, this) && this != first && this != lastnext) {
            prev = CClinkern_flipper_prev (this);
            if (!is_it_added (this, prev)) {
                val = goodlist[last][i].weight - Edgelen (this, prev);
                if (val < winner.diff) {
                    winner.diff = val;
                    winner.other = this;
                    winner.over = prev;
                }
            }
        }
    }

    if (winner.diff < BIGINT) {
        this = winner.other;
        newlast = winner.over;
        G -= winner.diff;
        *Gstar = G - Edgelen (newlast, first);

        FLIP (first, last, newlast, this, 2222);
        kickturn (this);
        kickturn (newlast);
#ifdef CC_USE_FLIP_CLEANING
        if (win_counter < winstack_max) {
            winstack[win_counter].first = last;
            winstack[win_counter].last = newlast;
#ifdef CC_EXTRA_INFO_FLIP
            winstack[win_counter].firstprev = first;
            winstack[win_counter].lastnext = this;
#endif
            win_counter++;
        }
#endif

        if (level < KICK_MAXDEPTH) {
            markedge_add (last, this);
            markedge_del (this, newlast);
            kick_step_noback (level + 1, G, Gstar, first, newlast);
            unmarkedge_add (last, this);
            unmarkedge_del (this, newlast);
        }
        return 1;
    } else {
        return 0;
    }
}
#endif /* IMPROVE_FOUR_SWAPS */

#ifdef CC_PROTOTYPE_ANSI
static int weird_second_step (int len_t1_t2, int t1, int t2)
#else
static int weird_second_step (len_t1_t2, t1, t2)
int len_t1_t2, t1, t2;
#endif
{
    int t3, t4, t5, t6, t7, t8;
    int oldG, G, tG, Gstar = 0, val, hit;
    int t4next;
    edgelook *e, *f, *h, *list, *list2, *list3;

    list = weird_look_ahead (len_t1_t2, t1, t2);
    for (h = list; h; h = h->next) {
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
        if (h != list) {
            int i;
            CClinkern_flipper_reset_perm (0);
            for (i = 0; i < flip_counter; i++)
                CClinkern_flipper_flip (flipstack[i].first, flipstack[i].last);
        }
#endif
        t3 = h->other;
        t4 = h->over;

        oldG = len_t1_t2 - h->diff;
        t4next = CClinkern_flipper_next (t4);

        markedge_add (t2, t3);
        markedge_del (t3, t4);
        weirdmagic++;
        weirdmark[t1] = weirdmagic;
        weirdmark[t2] = weirdmagic;
        weirdmark[t3] = weirdmagic;
        weirdmark[t4next] = weirdmagic;

        list2 = weird_look_ahead2 (oldG, t2, t3, t4);
        for (e = list2; e; e = e->next) {
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
            if (e != list2) {
                int i;
                CClinkern_flipper_reset_perm (0);
                for (i = 0; i < flip_counter; i++)
                    CClinkern_flipper_flip (flipstack[i].first, flipstack[i].last);
            }
#endif
            t5 = e->other;
            t6 = e->over;

            markedge_add (t4, t5);
            if (e->seq) {
                if (!e->side) {
                    G = oldG - e->diff;
                    val = G - Edgelen (t6, t1);
                    if (val > Gstar)
                        Gstar = val;
                    FLIP (t1, t2, t6, t5, 3);
                    FLIP (t2, t5, t3, t4, 4);

                    markedge_del (t5, t6);
                    hit = step (2, G, &Gstar, t1, t6);
                    unmarkedge_del (t5, t6);

                    if (!hit && Gstar)
                        hit = 1;

                    if (!hit) {
                        UNFLIP (t2, t5, t3, t4, 992);
                        UNFLIP (t1, t2, t6, t5, 993);
                    } else {
                        unmarkedge_add (t2, t3);
                        unmarkedge_del (t3, t4);
                        unmarkedge_add (t4, t5);
                        turn (t3); turn (t4);
                        turn (t5); turn (t6);
                        edgelook_list_free (list);
                        edgelook_list_free (list2);
                        return Gstar;
                    }
                } else {
                    G = oldG - e->diff;
                    val = G - Edgelen (t6, t1);
                    if (val > Gstar)
                        Gstar = val;
                    FLIP (t1, t2, t3, t4, 5000);
                    FLIP (t6, t5, t2, t4, 6);
                    FLIP (t1, t3, t6, t2, 7);

                    markedge_del (t5, t6);
                    hit = step (2, G, &Gstar, t1, t6);
                    unmarkedge_del (t5, t6);

                    if (!hit && Gstar)
                        hit = 1;

                    if (!hit) {
                        UNFLIP (t1, t3, t6, t2, 994);
                        UNFLIP (t6, t5, t2, t4, 995);
                        UNFLIP (t1, t2, t3, t4, 996);
                    } else {
                        unmarkedge_add (t2, t3);
                        unmarkedge_del (t3, t4);
                        unmarkedge_add (t4, t5);
                        turn (t3); turn (t4);
                        turn (t5); turn (t6);
                        edgelook_list_free (list);
                        edgelook_list_free (list2);
                        return Gstar;
                    }
                }
            } else {
                tG = oldG - e->diff;
                markedge_del (t5, t6);
                list3 = weird_look_ahead3 (tG, t2, t3, t6);
                for (f = list3; f; f = f->next) {
#ifdef CC_NO_UNDO_SEGMENTS_FLIPPER
                    if (f != list3) {
                        int i;
                        CClinkern_flipper_reset_perm (0);
                        for (i = 0; i < flip_counter; i++)
                            CClinkern_flipper_flip (flipstack[i].first,
                                          flipstack[i].last);
                    }
#endif
                    t7 = f->other;
                    t8 = f->over;

                    G = tG - f->diff;
                    if (!f->side) {
                        val = G - Edgelen (t8, t1);
                        if (val > Gstar)
                            Gstar = val;
                        FLIP (t1, t2, t8, t7, 8);
                        FLIP (t2, t7, t3, t4, 9);
                        FLIP (t7, t4, t6, t5, 10);

                        markedge_add (t6, t7);
                        markedge_del (t7, t8);
                        hit = step (3, G, &Gstar, t1, t8);
                        unmarkedge_del (t6, t7);
                        unmarkedge_del (t7, t8);

                        if (!hit && Gstar)
                            hit = 1;

                        if (!hit) {
                            UNFLIP (t7, t4, t6, t5, 997);
                            UNFLIP (t2, t7, t3, t4, 998);
                            UNFLIP (t1, t2, t8, t7, 999);
                        } else {
                            unmarkedge_add (t2, t3);
                            unmarkedge_del (t3, t4);
                            unmarkedge_add (t4, t5);
                            unmarkedge_del (t5, t6);
                            turn (t3); turn (t4); turn (t5);
                            turn (t6); turn (t7); turn (t8);
                            edgelook_list_free (list);
                            edgelook_list_free (list2);
                            edgelook_list_free (list3);
                            return Gstar;
                        }
                    } else {
                        val = G - Edgelen (t8, t1);
                        if (val > Gstar)
                            Gstar = val;
                        FLIP (t1, t2, t6, t5, 11);
                        FLIP (t1, t6, t8, t7, 12);
                        FLIP (t3, t4, t2, t5, 13);

                        markedge_add (t6, t7);
                        markedge_del (t7, t8);
                        hit = step (3, G, &Gstar, t1, t8);
                        unmarkedge_add (t6, t7);
                        unmarkedge_del (t7, t8);

                        if (!hit && Gstar)
                            hit = 1;

                        if (!hit) {
                            UNFLIP (t3, t4, t2, t5, 9910);
                            UNFLIP (t1, t6, t8, t7, 9911);
                            UNFLIP (t1, t2, t6, t5, 9912);
                        } else {
                            unmarkedge_add (t2, t3);
                            unmarkedge_del (t3, t4);
                            unmarkedge_add (t4, t5);
                            unmarkedge_del (t5, t6);
                            turn (t3); turn (t4); turn (t5);
                            turn (t6); turn (t7); turn (t8);
                            edgelook_list_free (list);
                            edgelook_list_free (list2);
                            edgelook_list_free (list3);
                            return Gstar;
                        }
                    }
                }
                edgelook_list_free (list3);
                unmarkedge_del (t5, t6);
            }
            unmarkedge_add (t4, t5);
        }
        edgelook_list_free (list2);
        unmarkedge_add (t2, t3);
        unmarkedge_del (t3, t4);
    }
    edgelook_list_free (list);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static edgelook *look_ahead (int first, int last, int G, int level)
#else
static edgelook *look_ahead (first, last, G, level)
int first, last;
int G, level;
#endif
{
    edgelook *list = (edgelook *) NULL, *el;
    int i, val;
    int this, prev;
    int lastnext = CClinkern_flipper_next (last);
    int other[MAX_BACK], save[MAX_BACK];
    int value[MAX_BACK + 1];
#if defined(MAK_MORTON) && defined(FULL_MAK_MORTON)
    int mm[MAX_BACK];
#endif
    int k, ahead = backtrack_count[level];

    for (i = 0; i < ahead; i++) {
        value[i] = BIGINT;
#if defined(MAK_MORTON) && defined(FULL_MAK_MORTON)
        mm[i] = 0;
#endif
    }
    value[ahead] = -BIGINT;

#ifdef USE_LESS_OR_EQUAL
    for (i = 0; goodlist[last][i].weight <= G; i++) {
#else
    for (i = 0; goodlist[last][i].weight < G; i++) {
#endif
        this = goodlist[last][i].other;
        if (!is_it_deleted (last, this) && this != first && this != lastnext) {
            prev = CClinkern_flipper_prev (this);
            if (!is_it_added (this, prev)) {
                val = goodlist[last][i].weight - Edgelen (this, prev);
                if (val < value[0]) {
                    for (k = 0; value[k+1] > val; k++) {
                        value[k] = value[k+1];
                        other[k] = other[k+1];
                        save[k] = save[k+1];
                    }
                    value[k] = val;
                    other[k] = this;
                    save[k] = prev;
                }
            }
        }
    }

#if defined(MAK_MORTON) && defined(FULL_MAK_MORTON)
    {
        int firstprev = CClinkern_flipper_prev (first);
        int next;

#ifdef USE_LESS_OR_EQUAL
        for (i = 0; goodlist[first][i].weight <= G; i++) {
#else
        for (i = 0; goodlist[first][i].weight < G; i++) {
#endif
            this = goodlist[first][i].other;
            if (!is_it_deleted (first, this) && this != last &&
                                                this != firstprev) {
                next = CClinkern_flipper_next (this);
                if (!is_it_added (this, next)) {
                    val = goodlist[first][i].weight - Edgelen (this, next);
                    if (val < value[0]) {
                        for (k = 0; value[k+1] > val; k++) {
                            value[k] = value[k+1];
                            other[k] = other[k+1];
                            save[k] = save[k+1];
                            mm[k] = mm[k+1];
                        }
                        value[k] = val;
                        other[k] = this;
                        save[k] = next;
                        mm[k] = 1;
                    }
                }
            }
        }
    }
#endif

    for (i = 0; i < ahead; i++) {
        if (value[i] < BIGINT) {
            el = edgelookalloc ();
            el->diff = value[i];
            el->other = other[i];
            el->over = save[i];
            el->next = list;
#if defined(MAK_MORTON) && defined(FULL_MAK_MORTON)
            el->mm = mm[i];
#endif
            list = el;
        }
    }

    return list;
}

#ifdef CC_PROTOTYPE_ANSI
static void look_ahead_noback (int first, int last, int G, edgelook *winner)
#else
static void look_ahead_noback (first, last, G, winner)
int first, last;
int G;
edgelook *winner;
#endif
{
    int val;
    int this, prev;
    int lastnext = CClinkern_flipper_next (last);
    int i;
#if defined(MAK_MORTON) || defined(NODE_INSERTIONS)
    int next;
#endif

    winner->diff = BIGINT;
    for (i = 0; goodlist[last][i].weight < G; i++) {
        this = goodlist[last][i].other;
        if (!is_it_deleted (last, this) && this != first && this != lastnext) {
            prev = CClinkern_flipper_prev (this);
            if (!is_it_added (this, prev)) {
                val = goodlist[last][i].weight - Edgelen (this, prev);
                if (val < winner->diff) {
                    winner->diff = val;
                    winner->other = this;
                    winner->over = prev;
#ifdef MAK_MORTON
                    winner->mm = 0;
#endif
#ifdef NODE_INSERTIONS
                    winner->ni = 0;
#endif
                }
#ifdef NODE_INSERTIONS
                next =  CClinkern_flipper_next (this);
                if (!is_it_added (this, next) && !is_it_deleted (prev, next)) {
                    val += (Edgelen (next, prev) - Edgelen (this, next));
                    if (val < winner->diff) {
                        winner->diff = val;
                        winner->other = this;
                        winner->over = prev;
                        winner->under = next;
                        winner->ni = 1;
                    }
                }
#endif
            }
        }
    }
#ifdef MAK_MORTON
    {
        int firstprev = CClinkern_flipper_prev (first);

        for (i = 0; goodlist[first][i].weight < G; i++) {
            this = goodlist[first][i].other;
            if (!is_it_deleted (first, this) && this != last &&
                                                this != firstprev) {
                next = CClinkern_flipper_next (this);
                if (!is_it_added (this, next)) {
                    val = goodlist[first][i].weight - Edgelen (this, next);
                    if (val < winner->diff) {
                        winner->diff = val;
                        winner->other = this;
                        winner->over = next;
                        winner->mm = 1;
#ifdef NODE_INSERTIONS
                        winner->ni = 0;
#endif
                    }
                }
            }
        }
    }
#endif
}

#ifdef CC_PROTOTYPE_ANSI
static edgelook *weird_look_ahead (int G, int t1, int t2)
#else
static edgelook *weird_look_ahead (G, t1, t2)
int G, t1, t2;
#endif
{
    edgelook *list, *el;
    int i, this, next;
    int other[MAX_BACK], save[MAX_BACK];
    int value[MAX_BACK + 1];
    int k, val, ahead;


    list = (edgelook *) NULL;
    ahead = weird_backtrack_count[0];
    for (i = 0; i < ahead; i++)
        value[i] = BIGINT;
    value[ahead] = -BIGINT;

#ifdef USE_LESS_OR_EQUAL
    for (i = 0; goodlist[t2][i].weight <= G; i++) {
#else
    for (i = 0; goodlist[t2][i].weight < G; i++) {
#endif
        this = goodlist[t2][i].other;
        if (this != t1) {
            next = CClinkern_flipper_next (this);
            val = goodlist[t2][i].weight - Edgelen (this, next);
            if (val < value[0]) {
                for (k = 0; value[k+1] > val; k++) {
                    value[k] = value[k+1];
                    other[k] = other[k+1];
                    save[k] = save[k+1];
                }
                value[k] = val;
                other[k] = this;
            save[k] = next;
            }
        }
    }
    for (i = 0; i < ahead; i++) {
        if (value[i] < BIGINT) {
            el = edgelookalloc ();
            el->diff = value[i];
            el->other = other[i];
            el->over = save[i];
            el->next = list;
            list = el;
        }
    }
    return list;
}

#ifdef CC_PROTOTYPE_ANSI
static edgelook *weird_look_ahead2 (int G, int t2, int t3, int t4)
#else
static edgelook *weird_look_ahead2 (G, t2, t3, t4)
int G, t2, t3, t4;
#endif
{
    edgelook *list = (edgelook *) NULL;
    edgelook *el;
    int i, t5, t6;
    int other[MAX_BACK], save[MAX_BACK], seq[MAX_BACK], side[MAX_BACK];
    int value[MAX_BACK + 1];
    int k, val;
    int ahead = weird_backtrack_count[1];

    for (i = 0; i < ahead; i++)
        value[i] = BIGINT;
    value[ahead] = -BIGINT;

#ifdef USE_SEQUENCE_BURST
    CClinkern_flipper_sequence_burst_init (t2, t3);
#endif

#ifdef USE_LESS_OR_EQUAL
    for (i = 0; goodlist[t4][i].weight <= G; i++) {
#else
    for (i = 0; goodlist[t4][i].weight < G; i++) {
#endif
        t5 = goodlist[t4][i].other;
        if (weirdmark[t5] != weirdmagic) {
#ifdef USE_SEQUENCE_BURST
            if (CClinkern_flipper_sequence_burst (t2, t5, t3)) {
#else
            if (CClinkern_flipper_sequence (t2, t5, t3)) {
#endif
                t6 = CClinkern_flipper_prev (t5);
                val = goodlist[t4][i].weight - Edgelen (t5, t6);
                if (val < value[0]) {
                    for (k = 0; value[k+1] > val; k++) {
                        value[k] = value[k+1];
                        other[k] = other[k+1];
                        save[k] = save[k+1];
                        seq[k] = seq[k+1];
                        side[k] = side[k+1];
                    }
                    value[k] = val;
                    other[k] = t5;
                    save[k] = t6;
                    seq[k] = 1;
                    side[k] = 0;
                }
                t6 = CClinkern_flipper_next (t5);
                val = goodlist[t4][i].weight - Edgelen (t5, t6);
                if (val < value[0]) {
                    for (k = 0; value[k+1] > val; k++) {
                        value[k] = value[k+1];
                        other[k] = other[k+1];
                        save[k] = save[k+1];
                        seq[k] = seq[k+1];
                        side[k] = side[k+1];
                    }
                    value[k] = val;
                    other[k] = t5;
                    save[k] = t6;
                    seq[k] = 1;
                    side[k] = 1;
                }
            } else {
                t6 = CClinkern_flipper_prev (t5);
                val = goodlist[t4][i].weight - Edgelen (t5, t6);
                if (val < value[0]) {
                    for (k = 0; value[k+1] > val; k++) {
                        value[k] = value[k+1];
                        other[k] = other[k+1];
                        save[k] = save[k+1];
                        seq[k] = seq[k+1];
                        side[k] = side[k+1];
                    }
                    value[k] = val;
                    other[k] = t5;
                    save[k] = t6;
                    seq[k] = 0;
                    side[k] = 0;
                }
            }
        }
    }

    for (i = 0; i < ahead; i++) {
        if (value[i] < BIGINT) {
            el = edgelookalloc ();
            el->diff = value[i];
            el->other = other[i];
            el->over = save[i];
            el->seq = seq[i];
            el->side = side[i];
            el->next = list;
            list = el;
        }
    }
    return list;
}

#ifdef CC_PROTOTYPE_ANSI
static edgelook *weird_look_ahead3 (int G, int t2, int t3, int t6)
#else
static edgelook *weird_look_ahead3 (G, t2, t3, t6)
int G, t2, t3, t6;
#endif
{
    edgelook *list = (edgelook *) NULL;
    edgelook *el;
    int i, t7, t8;
    int other[MAX_BACK], save[MAX_BACK], side[MAX_BACK];
    int value[MAX_BACK + 1];
    int k, val;
    int ahead = weird_backtrack_count[2];

    for (i = 0; i < ahead; i++)
        value[i] = BIGINT;
    value[ahead] = -BIGINT;

#ifdef USE_SEQUENCE_BURST
    CClinkern_flipper_sequence_burst_init (t2, t3);
#endif

#ifdef USE_LESS_OR_EQUAL
    for (i = 0; goodlist[t6][i].weight <= G; i++) {
#else
    for (i = 0; goodlist[t6][i].weight < G; i++) {
#endif
        t7 = goodlist[t6][i].other;   /* Need t7 != t2, t3, t2next, t3prev */
        if (weirdmark[t7] != weirdmagic &&
#ifdef USE_SEQUENCE_BURST
                             CClinkern_flipper_sequence_burst (t2, t7, t3)) {
#else
                             CClinkern_flipper_sequence (t2, t7, t3)) {
#endif
            t8 = CClinkern_flipper_prev (t7);
            val = goodlist[t6][i].weight - Edgelen (t7, t8);
            if (val < value[0]) {
                for (k = 0; value[k+1] > val; k++) {
                    value[k] = value[k+1];
                    other[k] = other[k+1];
                    save[k] = save[k+1];
                    side[k] = side[k+1];
                }
                value[k] = val;
                other[k] = t7;
                save[k] = t8;
                side[k] = 0;
            }
            t8 = CClinkern_flipper_next (t7);
            val = goodlist[t6][i].weight - Edgelen (t7, t8);
            if (val < value[0]) {
                for (k = 0; value[k+1] > val; k++) {
                    value[k] = value[k+1];
                    other[k] = other[k+1];
                    save[k] = save[k+1];
                    side[k] = side[k+1];
                }
                value[k] = val;
                other[k] = t7;
                save[k] = t8;
                side[k] = 1;
            }
        }
    }

    for (i = 0; i < ahead; i++) {
        if (value[i] < BIGINT) {
            el = edgelookalloc ();
            el->diff = value[i];
            el->other = other[i];
            el->over = save[i];
            el->side = side[i];
            el->next = list;
            list = el;
        }
    }
    return list;
}



/********************* misc ********************/


#ifdef CC_PROTOTYPE_ANSI
static double cycle_length (int ncount, int *cyc)
#else
static double cycle_length (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i;
    double val = 0;

    for (i = 1; i < ncount; i++)
        val += (double) Edgelen (cyc[i - 1], cyc[i]);
    val += (double) Edgelen (cyc[0], cyc[ncount - 1]);

    return val;
}

#ifdef GEOM_FOUR_SWAPS
#ifdef CC_PROTOTYPE_ANSI
static int random_four_swap (int ncount, CCkdtree *kdt, int *delta)
#else
static int random_four_swap (ncount, kdt, delta)
int ncount;
CCkdtree *kdt;
int *delta;
#endif
#else
#ifdef CC_PROTOTYPE_ANSI
static int random_four_swap (int ncount)
#else
static int random_four_swap (ncount)
int ncount;
#endif
#endif
{
    int t1, t2, t3, t4, t5, t6, t7, t8, temp;

#ifdef GEOM_FOUR_SWAPS
    if (((gdat->norm) & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
        if (find_geometric_four (ncount, kdt, &t1, &t2, &t3, &t4,
                                              &t5, &t6, &t7, &t8)) {
            fprintf (stderr, "find_geometric_four failed\n");
            return 1;
        }
    } else {
        find_close_four (ncount, &t1, &t2, &t3, &t4, &t5, &t6, &t7, &t8);
    }
#else
#ifdef CLOSE_FOUR_SWAPS
    find_close_four (ncount, &t1, &t2, &t3, &t4, &t5, &t6, &t7, &t8);
#else

#ifdef LONG_KICKER
    first_long_kicker (ncount, &t1, &t2);
#else
    t1 = CCutil_lprand () % ncount;
    t2 = CClinkern_flipper_next (t1);
#endif

    do {
        t3 = CCutil_lprand () % ncount;
        t4 = CClinkern_flipper_next (t3);
    } while (t3 == t1 || t3 == t2 || t4 == t1);

    do {
        t5 = CCutil_lprand () % ncount;
        t6 = CClinkern_flipper_next (t5);
    } while (t5 == t1 || t5 == t2 || t5 == t3 || t5 == t4 ||
             t6 == t1 || t6 == t3);

    do {
        t7 = CCutil_lprand () % ncount;
        t8 = CClinkern_flipper_next (t7);
    } while (t7 == t1 || t7 == t2 ||
              t7 == t3 || t7 == t4 || t7 == t5 || t7 == t6 || t8 == t1 ||
              t8 == t3 || t8 == t5 );
#endif  /* CLOSE_FOUR_SWAPS */
#endif  /* GEOM_FOUR_SWAPS */

    if (!CClinkern_flipper_sequence (t1, t3, t5)) {
        SWAP (t3, t5, temp);
        SWAP (t4, t6, temp);
    }
    if (!CClinkern_flipper_sequence (t1, t5, t7)) {
        SWAP (t5, t7, temp);
        SWAP (t6, t8, temp);
        if (!CClinkern_flipper_sequence (t1, t3, t5)) {
            SWAP (t3, t5, temp);
            SWAP (t4, t6, temp);
        }
    }
    FLIP (t1, t2, t5, t6, 20);
    FLIP (t4, t3, t7, t8, 21);
    FLIP (t1, t5, t6, t2, 22);

#ifdef CC_USE_FLIP_CLEANING
    if (win_counter < winstack_max) {
        winstack[win_counter].first = t2;
        winstack[win_counter].last = t5;
#ifdef CC_EXTRA_INFO_FLIP
        winstack[win_counter].firstprev = t1;
        winstack[win_counter].lastnext = t6;
#endif
        win_counter++;
    }
    if (win_counter < winstack_max) {
        winstack[win_counter].first = t3;
        winstack[win_counter].last = t7;
#ifdef CC_EXTRA_INFO_FLIP
        winstack[win_counter].firstprev = t4;
        winstack[win_counter].lastnext = t8;
#endif
        win_counter++;
    }
    if (win_counter < winstack_max) {
        winstack[win_counter].first = t5;
        winstack[win_counter].last = t6;
#ifdef CC_EXTRA_INFO_FLIP
        winstack[win_counter].firstprev = t1;
        winstack[win_counter].lastnext = t2;
#endif
        win_counter++;
    }
#endif /* CC_USE_FLIP_CLEANING */

    bigturn (t1, 0);
    bigturn (t2, 1);
    bigturn (t3, 0);
    bigturn (t4, 1);
    bigturn (t5, 0);
    bigturn (t6, 1);
    bigturn (t7, 0);
    bigturn (t8, 1);

#ifdef GEOM_FOUR_SWAPS
    *delta =
           Edgelen (t1, t6) + Edgelen (t2, t5) +
           Edgelen (t3, t8) + Edgelen (t4, t7) -
           Edgelen (t1, t2) - Edgelen (t3, t4) -
           Edgelen (t5, t6) - Edgelen (t7, t8);
    return 0;

#else
    return Edgelen (t1, t6) + Edgelen (t2, t5) +
           Edgelen (t3, t8) + Edgelen (t4, t7) -
           Edgelen (t1, t2) - Edgelen (t3, t4) -
           Edgelen (t5, t6) - Edgelen (t7, t8);
#endif
}

#ifdef LONG_KICKER
#define HUNT_PORTION_LONG 0.001

#ifdef CC_PROTOTYPE_ANSI
static void first_long_kicker (int ncount, int *t1, int *t2)
#else
static void first_long_kicker (ncount, t1, t2)
int ncount;
int *t1, *t2;
#endif
{
    int longcount = (int) ((double) ncount * HUNT_PORTION_LONG) + 10;
    int i, best, try, len, next, prev, nextl, prevl;

    try = CCutil_lprand () % ncount;
    next = CClinkern_flipper_next (try);
    prev = CClinkern_flipper_prev (try);
    nextl = Edgelen (try, next);
    prevl = Edgelen (try, prev);
    if (nextl >= prevl) {
        *t1 = try;
        *t2 = next;
        best = nextl - goodlist[*t1][0].weight;
    } else {
        *t1 = prev;
        *t2 = try;
        best = prevl - goodlist[*t1][0].weight;
    }

    for (i = 0; i < longcount; i++) {
        try = CCutil_lprand () % ncount;
        next = CClinkern_flipper_next (try);
        prev = CClinkern_flipper_prev (try);
        nextl = Edgelen (try, next);
        prevl = Edgelen (try, prev);
        if (nextl >= prevl) {
            len = nextl - goodlist[try][0].weight;
            if (len > best) {
                *t1 = try;
                *t2 = next;
            }
        } else {
            len = prevl - goodlist[try][0].weight;
            if (len > best) {
                *t1 = prev;
                *t2 = try;
            }
        }
    }
}
#endif  /* LONG_KICKER */

#if defined(CLOSE_FOUR_SWAPS) || defined(GEOM_FOUR_SWAPS)
#ifdef BIG_PROBLEM
#define HUNT_PORTION 0.001
#define HUNT_PORTION_LONG 0.001
#else
#define HUNT_PORTION 0.03
#define HUNT_PORTION_LONG 0.001
#endif
#endif

#if defined(CLOSE_FOUR_SWAPS) || defined(GEOM_FOUR_SWAPS)
#define RAND_TRYS 6    /* To find the 3 other edges */

#ifdef CC_PROTOTYPE_ANSI
static void find_close_four (int ncount,
                             int *t1, int *t2, int *t3, int *t4,
                            int *t5, int *t6, int *t7, int *t8)
#else
static void find_close_four (ncount, t1, t2, t3, t4, t5, t6, t7, t8)
int ncount;
int *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8;
#endif
{
    int s1, s2, s3, s4, s5, s6, s7, s8;
    int i, try;
    int count = (int) ((double) ncount * HUNT_PORTION) + 1 + RAND_TRYS;

    /* Not set up for fixed edges */

#ifdef LONG_KICKER
    first_long_kicker (ncount, &s1, &s2);
#else
    s1 = CCutil_lprand () % ncount;
    s2 = CClinkern_flipper_next (s1);
#endif

    {
        int trials[RAND_TRYS + 1];
        int tdist[RAND_TRYS + 1];
        int trydist;
        int k;

        tdist[RAND_TRYS] = -BIGINT;

TRY_AGAIN:

        for (k = 0; k < RAND_TRYS; k++)
            tdist[k] = BIGINT;
        for (i = 0; i < count; i++) {
            try = CCutil_lprand () % ncount;
            trydist = Edgelen (try, s1);
            if (trydist < tdist[0]) {
                for (k = 0; tdist[k + 1] > trydist; k++) {
                    tdist[k] = tdist[k + 1];
                    trials[k] = trials[k + 1];
                }
                tdist[k] = trydist;
                trials[k] = try;
            }
        }

        k = 0;
        do {
            if (k == RAND_TRYS)
                goto TRY_AGAIN;
            s3 = trials[k++];
            s4 = CClinkern_flipper_next (s3);
        } while (s3 == s1 || s3 == s2 || s4 == s1);

        do {
            if (k == RAND_TRYS)
                goto TRY_AGAIN;
            s5 = trials[k++];
            s6 = CClinkern_flipper_next (s5);
        } while (s5 == s1 || s5 == s2 || s5 == s3 ||
                 s5 == s4 || s6 == s1 || s6 == s3);

        do {
            if (k == RAND_TRYS)
                goto TRY_AGAIN;
            s7 = trials[k++];
            s8 = CClinkern_flipper_next (s7);
        } while (s7 == s1 || s7 == s2 || s7 == s3 || s7 == s4 ||
                 s7 == s5 || s7 == s6 || s8 == s1 || s8 == s3 ||
                 s8 == s5);
    }

    *t1 = s1; *t2 = s2; *t3 = s3; *t4 = s4;
    *t5 = s5; *t6 = s6; *t7 = s7; *t8 = s8;
}
#endif /* CLOSE_FOUR_SWAPS */


#ifdef GEOM_FOUR_SWAPS
#define GEO_FACTOR 50
#define GEO_MAX    250

#ifdef CC_PROTOTYPE_ANSI
static int find_geometric_four (int ncount, CCkdtree *kdt,
                                int *t1, int *t2, int *t3, int *t4,
                                int *t5, int *t6, int *t7, int *t8)
#else
static int find_geometric_four (ncount, kdt, t1, t2, t3, t4, t5, t6, t7, t8)
int ncount;
CCkdtree *kdt;
int *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8;
#endif
{
    int neigh[GEO_MAX];
    int temp, i, k, s1, s2, s3, s4, s5, s6, s7, s8;
    int trys;

#ifdef LONG_KICKER
    first_long_kicker (ncount, &s1, &s2);
#else
    s1 = CCutil_lprand () % ncount;
    s2 = CClinkern_flipper_next (s1);
#endif

    trys = ((ncount / 50) + 25 > GEO_MAX ? GEO_MAX : (ncount / 50) + 25);
    if (trys > ncount-1) trys = ncount-1;
    if (CCkdtree_node_k_nearest (kdt, ncount, s1, trys, gdat, (double *) NULL,
                               neigh)) {
        fprintf (stderr, "CCkdtree_node_k_nearest failed\n");
        return 1;
    }

    for (i = trys; i > trys - 9; i--) {
        k = CCutil_lprand () % i;
        SWAP (neigh[i - 1], neigh[k], temp);
    }

    k = trys - 1;
    do {
        s3 = neigh[k--];
        s4 = CClinkern_flipper_next (s3);
    } while (s3 == s2 || s4 == s1);

    do {
        s5 = neigh[k--];
        s6 = CClinkern_flipper_next (s5);
    } while (s5 == s2 || s5 == s4 || s6 == s1 || s6 == s3);

    do {
        s7 = neigh[k--];
        s8 = CClinkern_flipper_next (s7);
    } while (s7 == s2 || s7 == s4 || s7 == s6 || s8 == s1 || s8 == s3 ||
             s8 == s5);


    *t1 = s1; *t2 = s2; *t3 = s3; *t4 = s4;
    *t5 = s5; *t6 = s6; *t7 = s7; *t8 = s8;

    return 0;
}
#endif

#ifdef CC_PROTOTYPE_ANSI
static void turn (int n)
#else
static void turn (n)
int n;
#endif
{
    intptr *ip;

    /* intptralloc will not fail - the initial supply is large enough */

    ADD_TO_ACTIVE_QUEUE (n, ip);

#ifdef MARK_NEIGHBORS
    {
       int i = 0;
       for (i = 0; i < degree[n]; i++) {
           if (lprand () % 2) {
               ADD_TO_ACTIVE_QUEUE (goodlist[n][i].other, ip);
           }
       }
    }
#else
#ifndef USE_LESS_MARKING
    {
        int k;
        k = CClinkern_flipper_next (n);
        ADD_TO_ACTIVE_QUEUE (k, ip);
        k = CClinkern_flipper_next (k);
        ADD_TO_ACTIVE_QUEUE (k, ip);
        k = CClinkern_flipper_prev (n);
        ADD_TO_ACTIVE_QUEUE (k, ip);
        k = CClinkern_flipper_prev (k);
        ADD_TO_ACTIVE_QUEUE (k, ip);
    }
#endif
#endif
}

#ifdef IMPROVE_FOUR_SWAPS
#ifdef CC_PROTOTYPE_ANSI
static void kickturn (int n)
#else
static void kickturn (n)
int n;
#endif
{
    intptr *ip;

    ADD_TO_ACTIVE_QUEUE (n, ip);
    {
        int k;
        k = CClinkern_flipper_next (n);
        ADD_TO_ACTIVE_QUEUE (k, ip);
        k = CClinkern_flipper_next (k);
        ADD_TO_ACTIVE_QUEUE (k, ip);
        k = CClinkern_flipper_prev (n);
        ADD_TO_ACTIVE_QUEUE (k, ip);
        k = CClinkern_flipper_prev (k);
        ADD_TO_ACTIVE_QUEUE (k, ip);
    }
}
#endif

#ifdef CC_PROTOTYPE_ANSI
static void bigturn (int n, int tonext)
#else
static void bigturn (n, tonext)
int n, tonext;
#endif
{
    intptr *ip;
    int i, k;

    /* intptralloc will not fail - the initial supply is large enough */

    ADD_TO_ACTIVE_QUEUE (n, ip);

    if (tonext) {
        for (i = 0, k = n; i < MARK_LEVEL; i++) {
            k = CClinkern_flipper_next (k);
            ADD_TO_ACTIVE_QUEUE (k, ip);
        }
    } else {
        for (i = 0, k = n; i < MARK_LEVEL; i++) {
            k = CClinkern_flipper_prev (k);
            ADD_TO_ACTIVE_QUEUE (k, ip);
        }
    }

    for (i = 0; i < degree[n]; i++) {
        ADD_TO_ACTIVE_QUEUE (goodlist[n][i].other, ip);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void randcycle (int ncount, int *cyc)
#else
static void randcycle (ncount, cyc)
int ncount;
int *cyc;
#endif
{
    int i, k, temp;

    for (i = 0; i < ncount; i++)
        cyc[i] = i;

    for (i = ncount; i > 1; i--) {
        k = CCutil_lprand () % i;
        SWAP (cyc[i - 1], cyc[k], temp);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int buildgraph (int ncount, int ecount, int *elist)
#else
static int buildgraph (ncount, ecount, elist)
int ncount, ecount, *elist;
#endif
{
    int n1, n2, w, i;
    edge *p;

    goodlist = CC_SAFE_MALLOC (ncount, edge *);
    if (!goodlist)
        return 1;
    degree = CC_SAFE_MALLOC (ncount, int);
    if (!degree) {
        CC_FREE (goodlist, edge *);
        return 1;
    }
#if defined(HALF_LOOKS) || defined(LATE_HALF_LOOKS)
    edgespace = CC_SAFE_MALLOC ((2 * ecount) + (2 * ncount), edge);
#else
    edgespace = CC_SAFE_MALLOC ((2 * ecount) + ncount, edge);
#endif
    if (!edgespace) {
        CC_FREE (goodlist, edge *);
        CC_FREE (degree, int);
        return 1;
    }

    for (i = 0; i < ncount; i++) {
#if defined(HALF_LOOKS) || defined(LATE_HALF_LOOKS)
        degree[i] = 2;
#else
        degree[i] = 1;
#endif
    }
    for (i = ecount - 1; i >= 0; i--) {
        degree[elist[2 * i]]++;
        degree[elist[(2 * i) + 1]]++;
    }

    for (i = 0, p = edgespace; i < ncount; i++) {
        goodlist[i] = p;
        p += (degree[i]);
#if defined(HALF_LOOKS) || defined(LATE_HALF_LOOKS)
        goodlist[i][degree[i] - 2].weight = BIGINT;
#endif
        goodlist[i][degree[i] - 1].weight = BIGINT;
        degree[i] = 0;
    }


    for (i = ecount - 1; i >= 0; i--) {
        n1 = elist[2 * i];
        n2 = elist[(2 * i) + 1];
        w = Edgelen (n1, n2);
        insertedge (n1, n2, w);
        insertedge (n2, n1, w);
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void insertedge (int n1, int n2, int w)
#else
static void insertedge (n1, n2, w)
int n1;
int n2;
int w;
#endif
{
    int i;
    edge *e = goodlist[n1];

    for (i = degree[n1] - 1; i >= 0 && e[i].weight >= w; i--) {
        e[i + 1].weight = e[i].weight;
        e[i + 1].other = e[i].other;
    }
    e[i + 1].weight = w;
    e[i + 1].other = n2;
    degree[n1]++;
}


#ifdef CC_PROTOTYPE_ANSI
static void free_graph (int ncount)
#else
static void free_graph (ncount)
int ncount;
#endif
{
    int i;

    if (goodlist)
        CC_FREE (goodlist, edge *);
    if (edgespace)
        CC_FREE (edgespace, edge);
    if (degree)
        CC_FREE (degree, int);
    if (fixlist) {
        for (i = 0; i < ncount; i++) {
            intptr_list_free (fixlist[i]);
        }
        CC_FREE (fixlist, intptr *);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void linkern_free_world (void)
#else
static void linkern_free_world ()
#endif
{
    int total, onlist;

    if (intptr_check_leaks (&total, &onlist)) {
        fprintf (stderr, "WARNING: %d outstanding intptrs\n", total - onlist);
    }
    if (edgelook_check_leaks (&total, &onlist)) {
        fprintf (stderr, "WARNING: %d outstanding edgelooks\n", total - onlist);
    }
    intptrfree_world ();
    edgelookfree_world ();
}


#ifdef CC_PROTOTYPE_ANSI
static int initarrays (int ncount)
#else
static int initarrays (ncount)
int ncount;
#endif
{
    int i, M;

    i = 0;
    while ((1 << i) < ncount)
        i++;
    M = (1 << i);

    add_edges = CC_SAFE_MALLOC (M, char);
    if (!add_edges)
        return 1;
    del_edges = CC_SAFE_MALLOC (M, char);
    if (!del_edges) {
        CC_FREE (add_edges, char);
        return 1;
    }
    for (i = 0; i < M; i++) {
        add_edges[i] = 0;
        del_edges[i] = 0;
    }

    active = CC_SAFE_MALLOC (ncount, char);
    if (!active) {
        CC_FREE (add_edges, char);
        CC_FREE (del_edges, char);
        return 1;
    }
    weirdmark = CC_SAFE_MALLOC (ncount, int);
    if (!weirdmark) {
        CC_FREE (add_edges, char);
        CC_FREE (del_edges, char);
        CC_FREE (active, char);
        return 1;
    }
    for (i = 0; i < ncount; i++) {
        active[i] = 0;
        weirdmark[i] = 0;
    }

    return 0;
}

static int cacheM = 0;

#ifdef CC_PROTOTYPE_ANSI
static int initcache (int ncount)
#else
static int initcache (ncount)
int ncount;
#endif
{
    int i;

#ifndef BENTLEY_CACHE
    i = 0;
    while ((1 << i) < (ncount << 2))
        i++;
    cacheM = (1 << i);
#else
    i = 0;
    while ((1 << i) < ncount)
        i++;
    cacheM = (1 << i);
#endif

    cacheind = CC_SAFE_MALLOC (cacheM, int);
    if (!cacheind) return 1;

    cacheval = CC_SAFE_MALLOC (cacheM, int);
    if (!cacheval) return 1;

    for (i = 0; i < cacheM; i++) {
        cacheind[i] = -1;
    }

#ifndef BENTLEY_CACHE
    cacheM--;
#endif

    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
static int dist (int i, int j)   /* As in Bentley's CCkdtree paper */
#else
static int dist (i, j)
int i, j;
#endif
{
    int ind;

    if (i > j) {
        int temp;
        SWAP (i, j, temp);
    }

#ifndef BENTLEY_CACHE
    ind = (((i << 8) + i + j) & (cacheM));
#else
    ind = i ^ j;
#endif

    if (cacheind[ind] != i) {
        cacheind[ind] = i;
        cacheval[ind] = CCutil_dat_edgelen (i, j, gdat);
    }

    return cacheval[ind];
}
