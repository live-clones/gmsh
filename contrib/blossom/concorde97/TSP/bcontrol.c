/***************************************************************************/
/*                                                                         */
/*                  THE CONTROLLER FOR BRANCHING RUNS                      */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: July 21, 1997                                                    */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_init_cutselect (CCtsp_lp *lp, CCtsp_cutselect *s)          */
/*     INITIALIZES the cut selctions                                       */
/*     Note: The lp should be solved before this call.                     */
/*                                                                         */
/*    int CCtsp_cutting_loop (CCtsp_lp *lp, CCtsp_cutselect *sel,          */
/*            int savelp)                                                  */
/*     CALLS the cutting plane and pricing routines.                       */
/*      -sel should be set with the desired cut selection.                 */
/*      -savelp should be set to a nonzero value to write the lps to after */
/*       rounds of cuts                                                    */
/*     Note: It returns a 2 if the lp becomes infeasible                   */
/*                                                                         */
/*  NOTES:                                                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "edgegen.h"
#include "tsp.h"

typedef struct tsp_bbnode {
    int id;
    double lowerbound;
    int status;
    int workstatus;
    struct tsp_bbnode *prev;
    struct tsp_bbnode *next;
    struct tsp_bbnode *parent;
    struct tsp_bbnode *child0;
    struct tsp_bbnode *child1;
} tsp_bbnode;

#define BB_NEEDS_CUTTING   (1)
#define BB_NEEDS_BRANCHING (2)
#define BB_DONE            (3)
#define BB_IDLE            (1)
#define BB_WORKING         (2)


CC_PTR_ALLOC_ROUTINE (tsp_bbnode, tsp_bbnode_alloc, tsp_bbnode_chunklist,
        tsp_bbnode_freelist)
CC_PTR_FREE_WORLD_ROUTINE (tsp_bbnode, tsp_bbnode_free_world,
        tsp_bbnode_chunklist, tsp_bbnode_freelist)
CC_PTR_LEAKS_ROUTINE (tsp_bbnode, tsp_bbnode_check_leaks,
        tsp_bbnode_chunklist, tsp_bbnode_freelist, id, int)
CC_PTR_FREE_ROUTINE (tsp_bbnode, tsp_bbnode_free, tsp_bbnode_freelist)


#ifdef CC_PROTOTYPE_ANSI

static void
    init_bbnode (tsp_bbnode *bbnode),
    insert_bbnode (tsp_bbnode **firstbbnode, tsp_bbnode *bbnode),
    delete_bbnode (tsp_bbnode **firstbbnode, tsp_bbnode *bbnode),
    free_tree (tsp_bbnode **bbnode);

static int
    add_children (tsp_bbnode **firstbbnode, tsp_bbnode *parent,
        int id0, int id1, double val0, double val1, int prune0, int prune1);

static tsp_bbnode
    *select_bbnode (tsp_bbnode *firstbbnode);

#else

static void
    init_bbnode (),
    insert_bbnode (),
    delete_bbnode (),
    free_tree ();

static int
    add_children ();

static tsp_bbnode
    *select_bbnode ();

#endif

#ifdef CC_PROTOTYPE_ANSI
static void init_bbnode (tsp_bbnode *bbnode)
#else
static void init_bbnode (bbnode)
tsp_bbnode *bbnode;
#endif
{
    bbnode->id = 0;
    bbnode->lowerbound = 0.0;
    bbnode->status =     BB_NEEDS_CUTTING;
    bbnode->workstatus = BB_IDLE;
    bbnode->prev = (tsp_bbnode *) NULL;
    bbnode->next = (tsp_bbnode *) NULL;
    bbnode->parent = (tsp_bbnode *) NULL;
    bbnode->child0 = (tsp_bbnode *) NULL;
    bbnode->child1 = (tsp_bbnode *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_bfs_brancher (char *probname, int id, double lowerbound,
        CCtsp_cutselect *sel, double *upbound, int *bbcount, int usecliques,
        CCdatagroup *dat, int *ptour, CCtsp_lpcuts *pool, int ncount,
        int *besttour)
#else
int CCtsp_bfs_brancher (probname, id, lowerbound, sel, upbound, bbcount,
        usecliques, dat, ptour, pool, ncount, besttour)
char *probname;
int id;
double lowerbound;
CCtsp_cutselect *sel;
double *upbound;
int *bbcount;
int usecliques;
CCdatagroup *dat;
int *ptour;
CCtsp_lpcuts *pool;
int ncount;
int *besttour;
#endif
{
    int rval = 0;
    int  max_id = 0;
    int id0, id1, prune, prune0, prune1, foundtour, count = 0;
    double val0, val1, val;
    CCtsp_branchobj *b = (CCtsp_branchobj *) NULL;
    tsp_bbnode *bbnode = (tsp_bbnode *) NULL;
    tsp_bbnode *firstbbnode = (tsp_bbnode *) NULL;
    tsp_bbnode *rootbbnode  = (tsp_bbnode *) NULL;

    *bbcount = 0;

    if (max_id < id) max_id = id;
    rootbbnode = tsp_bbnode_alloc ();
    if (!rootbbnode) {
        fprintf (stderr, "Failed to allocate root node\n");
        rval = 1; goto CLEANUP;
    }

    init_bbnode (rootbbnode);
    rootbbnode->id = id;
    rootbbnode->lowerbound = lowerbound;
    firstbbnode = rootbbnode;
    *bbcount = 1;

    while (firstbbnode) {
        bbnode = select_bbnode (firstbbnode);
        if (!bbnode) {
            fprintf (stderr, "No IDLE bbnodes\n");
            rval = 1; goto CLEANUP;
        }
        printf ("Task %d: %s on node %d\n", count++,
             (bbnode->status == BB_NEEDS_CUTTING ? "Cutting" : "Branching"),
              bbnode->id);
        fflush (stdout);

        switch (bbnode->status) {
        case BB_NEEDS_CUTTING:
            bbnode->workstatus = BB_WORKING;
            rval = CCtsp_bb_cutting (probname, bbnode->id, ncount, dat, ptour,
                         upbound, pool, sel, &val, &prune, &foundtour,
                         besttour);
            if (rval) {
                fprintf (stderr, "CCtsp_bb_cutting failed\n"); goto CLEANUP;
            }
            if (foundtour) {
                printf ("TOUR FOUND - upperbound is %.2f\n", *upbound);
                fflush (stdout);
                rval = CCtsp_dumptour (ncount, dat, ptour, probname, besttour);
                if (rval) {
                    fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
                }
            }
            if (prune) {
                printf ("BBnode can be pruned: upperbound %.2f\n", *upbound);
                fflush (stdout);
                delete_bbnode (&firstbbnode, bbnode);
                rval = CCtsp_prob_file_delete (probname, bbnode->id);
                if (rval) goto CLEANUP;
            } else {
                bbnode->status     = BB_NEEDS_BRANCHING;
                bbnode->workstatus = BB_IDLE;
                bbnode->lowerbound = val;
            }
            break;
        case BB_NEEDS_BRANCHING:
            bbnode->workstatus = BB_WORKING;
            rval = CCtsp_bb_find_branch (probname, bbnode->id, ncount, dat,
                     ptour, upbound, pool, &b, usecliques, &foundtour,
                     besttour);
            if (rval) {
                fprintf (stderr, "CCtsp_bb_find_branch failed\n"); goto CLEANUP;
            }
            if (foundtour) {
                printf ("TOUR FOUND - upperbound is %.2f\n", *upbound);
                fflush (stdout);
                rval = CCtsp_dumptour (ncount, dat, ptour, probname, besttour);
                if (rval) {
                    fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
                }
            } else {
                printf ("Found Branch - split problem into children\n");
                fflush (stdout);
                id0 = ++max_id;
                id1 = ++max_id;
                rval = CCtsp_bb_splitprob (probname, bbnode->id, ncount, dat,
                         ptour, *upbound, pool, &b[0], id0, id1, &val0, &val1,
                         &prune0, &prune1);
                CCtsp_free_branchobj (&b[0]);
                CC_IFFREE (b, CCtsp_branchobj);
                if (rval) {
                    fprintf (stderr, "CCtsp_bb_splitprob failed\n");
                    goto CLEANUP;
                }

                rval = add_children (&firstbbnode, bbnode, id0, id1,
                           val0, val1, prune0, prune1);
                if (rval) {
                    fprintf (stderr, "add_children failed\n"); goto CLEANUP;
                }
                (*bbcount) += 2;
            }
            delete_bbnode (&firstbbnode, bbnode);
            rval = CCtsp_prob_file_delete (probname, bbnode->id);
            if (rval) goto CLEANUP;
            break;
        default:
            printf ("Not working bbnode: %d (status %d)\n", bbnode->id,
                                                            bbnode->status);
            fflush (stdout);
            rval = 1; goto CLEANUP;
        }
    }

CLEANUP:

    CCtsp_free_branchobj (&b[0]);
    CC_IFFREE (b, CCtsp_branchobj);
    free_tree (&rootbbnode);
    tsp_bbnode_free_world ();
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int add_children (tsp_bbnode **firstbbnode, tsp_bbnode *parent,
        int id0, int id1, double val0, double val1, int prune0, int prune1)
#else
static int add_children (firstbbnode, parent, id0, id1, val0, val1,
        prune0, prune1)
tsp_bbnode **firstbbnode;
tsp_bbnode *parent;
int id0, id1;
double val0, val1;
int prune0, prune1;
#endif
{
    int rval = 0;
    tsp_bbnode *child = (tsp_bbnode *) NULL;

    if (val0 == CCtsp_LP_MAXDOUBLE) {
        printf ("Child 0 is infeasible\n"); fflush (stdout);
    } else if (prune0) {
        printf ("Child 0 is pruned\n"); fflush (stdout);
    } else {
        child = tsp_bbnode_alloc ();
        if (!child) {
            fprintf (stderr, "Failed to allocate child 0\n");
            rval = 1; goto CLEANUP;
        }

        init_bbnode (child);
        child->id = id0;
        child->lowerbound = val0;

        parent->child0 = child;
        insert_bbnode (firstbbnode, child);
    }

    if (val1 == CCtsp_LP_MAXDOUBLE) {
        printf ("Child 1 is infeasible\n"); fflush (stdout);
    } else if (prune1) {
        printf ("Child 1 is pruned\n"); fflush (stdout);
    } else {
        child = tsp_bbnode_alloc ();
        if (!child) {
            fprintf (stderr, "Failed to allocate child 0\n");
            rval = 1; goto CLEANUP;
        }

        init_bbnode (child);
        child->id = id1;
        child->lowerbound = val1;

        parent->child1 = child;
        insert_bbnode (firstbbnode, child);
    }

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static void free_tree (tsp_bbnode **bbnode)
#else
static void free_tree (bbnode)
tsp_bbnode **bbnode;
#endif
{
    if (!(*bbnode))  return;
    free_tree (&((*bbnode)->child0));
    free_tree (&((*bbnode)->child1));
    tsp_bbnode_free (*bbnode);
    *bbnode = (tsp_bbnode *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static tsp_bbnode *select_bbnode (tsp_bbnode *firstbbnode)
#else
static tsp_bbnode *select_bbnode (firstbbnode)
tsp_bbnode *firstbbnode;
#endif
{
    double bestbound  = CCtsp_LP_MAXDOUBLE;
    double lowerbound = CCtsp_LP_MAXDOUBLE;
    tsp_bbnode *bestbbnode = (tsp_bbnode *) NULL;
    tsp_bbnode *b;
    int count = 0;

    for (b = firstbbnode; b; b = b->next) {
        if (b->lowerbound < lowerbound) {
            lowerbound = b->lowerbound;
        }
        count++;
    }
    printf ("LOWER BOUND: %f   ACTIVE NODES: %d\n", lowerbound, count);
    fflush (stdout);

    if (firstbbnode) {
        /* Find the best bbnode */
        for (b = firstbbnode; b; b = b->next) {
            if (b->workstatus == BB_IDLE && b->lowerbound < bestbound) {
                bestbound = b->lowerbound;
                bestbbnode = b;
            }
        }
    }

    if (!bestbbnode) {
        printf ("No idle bbnodes\n"); fflush (stdout);
    } else {


        printf ("Selected bbnode:  id %d  lowerbound %.2f\n", 
                bestbbnode->id, bestbound);
        fflush (stdout);
        if (count > 1) {
            printf ("Remaining active bbnodes:\n");
            fflush (stdout);
            for (b = firstbbnode; b; b = b->next) {
                if (b->id != bestbbnode->id) {
                    printf ("  id %d  lowerbound %.2f\n", b->id, b->lowerbound);
                    fflush (stdout);
                }
            }
        }
    }

    return bestbbnode;
}

#ifdef CC_PROTOTYPE_ANSI
static void insert_bbnode (tsp_bbnode **firstbbnode, tsp_bbnode *bbnode)
#else
static void insert_bbnode (firstbbnode, bbnode)
tsp_bbnode **firstbbnode, *bbnode;
#endif
{
    if (!bbnode) return;

    bbnode->prev = (tsp_bbnode *) NULL;
    bbnode->next = *firstbbnode;
    if (*firstbbnode)  (*firstbbnode)->prev = bbnode;
    *firstbbnode = bbnode;
}

#ifdef CC_PROTOTYPE_ANSI
static void delete_bbnode (tsp_bbnode **firstbbnode, tsp_bbnode *bbnode)
#else
static void delete_bbnode (firstbbnode, bbnode)
tsp_bbnode **firstbbnode;
tsp_bbnode *bbnode;
#endif
{
    tsp_bbnode *next, *prev;

    if (!bbnode) return;

    bbnode->status = BB_DONE;
    bbnode->workstatus = BB_IDLE;
    if (*firstbbnode == bbnode) {
        *firstbbnode = bbnode->next;
    }
    prev = bbnode->prev;
    next = bbnode->next;
    if (prev) prev->next = next;
    if (next) next->prev = prev;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_easy_dfs_brancher (CCtsp_lp *lp, CCtsp_cutselect *sel, int depth,
        double *upbound, int *bbcount, int usecliques, int *besttour)
#else
int CCtsp_easy_dfs_brancher (lp, sel, depth, upbound, bbcount, usecliques,
        besttour)
CCtsp_lp *lp;
CCtsp_cutselect *sel;
int depth;
double *upbound;
int *bbcount;
int usecliques;
int *besttour;
#endif
{
    int rval = 0;
    int ngot, prune, i;
    int *cyc = (int *) NULL;
    double val, bnd;
    double oldbound = lp->lowerbound;
    CCtsp_branchobj *b = (CCtsp_branchobj *) NULL;

    if (!lp->full_edges_valid) {
        fprintf (stderr, "CCtsp_easy_dfs_brancher needs valid extra edges\n");
        rval = 1; goto CLEANUP;
    }

    printf ("Node %d\n", *bbcount); fflush (stdout);
    (*bbcount)++;
    CCtsp_print_branchhistory (lp);

    rval = CCtsp_pricing_loop (lp, &bnd);
    if (rval) {
        fprintf (stderr, "CCtsp_pricing_loop failed\n");  goto CLEANUP;
    }
    lp->lowerbound = bnd;
    lp->upperbound = *upbound;

    if (lp->lowerbound >= lp->upperbound - 0.9) {
        rval = CCtsp_verify_lp_prune (lp, &prune);
        if (rval) {
            fprintf (stderr, "CCtsp_verify_lp_prune failed\n"); goto CLEANUP;
        }
        if (prune) {
            printf ("PRUNE SEARCH: upperbound = %f\n", *upbound);
            fflush (stdout);
            rval = 0; goto CLEANUP;
        } else {
            fprintf (stderr, "exact pricing could not prune the search\n");
            rval = 1; goto CLEANUP;
        }
    }

    rval = CCtsp_cutting_loop (lp, sel, 0);
    if (rval == 2) {
        rval = CCtsp_verify_infeasible_lp (lp, &prune);
        if (rval) {
            fprintf (stderr ,"CCtsp_verify_infeasible_lp failed\n");
            goto CLEANUP;
        }
        if (prune) {
            printf ("PRUNE SEARCH - infeasible LP\n"); fflush (stdout);
            rval = 0; goto CLEANUP;
        } else {
            fprintf (stderr, "exact pricing did not verify an infeasible LP\n");
            rval = 1; goto CLEANUP;
        }
    } else if (rval) {
        fprintf (stderr, "CCtsp_cutting_loop failed\n"); goto CLEANUP;
    }

    if (lp->lowerbound < lp->upperbound - 0.9) {
        rval = CCtsp_call_x_heuristic (lp, &val, besttour);
        if (rval) {
            fprintf (stderr, "CCtsp_call_x_heuristic failed\n");
            goto CLEANUP;
        }
        if (val < lp->upperbound) {
            printf ("New upperbound from x-heuristic: %.2f\n", val);
            lp->upperbound = val;
            *upbound = val;
            rval = CCtsp_dumptour (lp->graph.ncount, lp->dat, lp->perm,
                                   lp->name, besttour);
            if (rval) {
                fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
            }
        }
    }

    if (lp->lowerbound >= lp->upperbound - 0.9) {
        rval = CCtsp_verify_lp_prune (lp, &prune);
        if (rval) {
            fprintf (stderr, "CCtsp_verify_lp_prune failed\n"); goto CLEANUP;
        }
        if (prune) {
            printf ("PRUNE SEARCH: upperbound = %f\n", *upbound);
            fflush (stdout);
            rval = 0; goto CLEANUP;
        } else {
            fprintf (stderr, "exact pricing could not prune the search\n");
            rval = 1; goto CLEANUP;
        }
    }

    oldbound = lp->lowerbound;
    printf ("Find branch object ...\n"); fflush (stdout);
    rval = CCtsp_find_branch (lp, 1, &ngot, &b, &val, &cyc, usecliques);
    if (rval) {
        fprintf (stderr, "CCtsp_find_branch failed\n");
        goto CLEANUP;
    }

    if (ngot == 0) {
        printf ("TOUR FOUND: %.2f\n", val); fflush (stdout);
        if (val < *upbound) {
            *upbound = val;
            lp->upperbound = val;
            for (i = 0; i < lp->graph.ncount; i++) {
                besttour[i] = cyc[i];
            }
            rval = CCtsp_dumptour (lp->graph.ncount, lp->dat, lp->perm,
                                   lp->name, besttour);
            if (rval) {
                fprintf (stderr, "CCtsp_dumptour failed\n"); goto CLEANUP;
            }
        }
        CC_IFFREE (cyc, int);
        rval = CCtsp_verify_lp_prune (lp, &prune);
        if (rval) {
            fprintf (stderr, "CCtsp_verify_lp_prune failed\n");
            goto CLEANUP;
        }
        if (prune) {
            printf ("with new tour, the node can be pruned\n"); fflush (stdout);
            rval = 0; goto CLEANUP;
        } else {
            fprintf (stderr, "could not verify the pruning\n");
            rval = 1; goto CLEANUP;
        }
    }


    /**** Down-Side Branch ****/


    if (b[0].ends[0] != -1) {
        printf ("Branch: set edge (%d, %d) to 0 (depth %d)\n",
                     b[0].ends[0], b[0].ends[1], depth);
        b[0].rhs = 0;
    } else {
        printf ("Branch: set clique <= 2 (depth %d)\n", depth);
        b[0].rhs = 2; b[0].sense = 'L';
    }
    fflush (stdout);
    rval = CCtsp_execute_branch (lp, &b[0]);
    if (rval) {
        fprintf (stderr, "CCtsp_execute_branch failed\n");
        rval = 1; goto CLEANUP;
    }

    rval = CCtsp_easy_dfs_brancher (lp, sel, depth + 1, upbound, bbcount,
                                    usecliques, besttour);
    if (rval) {
        fprintf (stderr, "CCtsp_easy_dfs_brancher failed\n"); goto CLEANUP;
    }
    rval = CCtsp_execute_unbranch (lp, (CClpbasis *) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_execute_unbranch failed\n"); goto CLEANUP;
    }
    lp->lowerbound = oldbound;


    /**** Up-Side Branch ****/


    if (b[0].ends[0] != -1) {
        printf ("Branch: set edge (%d, %d) to 1 (depth %d)\n",
                     b[0].ends[0], b[0].ends[1], depth);
        b[0].rhs = 1;
    } else {
        printf ("Branch: set clique >= 4 (depth %d)\n", depth);
        b[0].rhs   = 4; b[0].sense = 'G';
    }
    fflush (stdout);
    rval = CCtsp_execute_branch (lp, &b[0]);
    if (rval) {
        fprintf (stderr, "CCtsp_execute_branch failed\n"); goto CLEANUP;
    }

    rval = CCtsp_easy_dfs_brancher (lp, sel, depth + 1, upbound, bbcount,
                                    usecliques, besttour);
    if (rval) {
        fprintf (stderr, "CCtsp_easy_dfs_brancher failed\n"); goto CLEANUP;
    }
    rval = CCtsp_execute_unbranch (lp, (CClpbasis *) NULL);
    if (rval) {
        fprintf (stderr, "CCtsp_execute_unbranch failed\n"); goto CLEANUP;
    }
    lp->lowerbound = oldbound;

    CCtsp_free_branchobj (&b[0]);
    CC_IFFREE (b, CCtsp_branchobj);

CLEANUP:

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_do_interactive_branch (CCtsp_lp *lp)
#else
int CCtsp_do_interactive_branch (lp)
CCtsp_lp *lp;
#endif
{
    int bend0, bend1, ch0, ch1, tbran, nseg, i;
    CCtsp_branchobj b;
    CCtsp_lpclique *c = (CCtsp_lpclique *) NULL;
    int *slist  = (int *) NULL;
    int rval = 0;

    CCtsp_init_branchobj (&b);

    printf ("Enter the (integer) id's for the two child nodes: ");
    fflush (stdout);
    scanf ("%d %d", &ch0, &ch1);

    printf ("Enter 0 if edge-branch and 1 if clique-branch: ");
    fflush (stdout);
    scanf ("%d", &tbran);

    if (!tbran) {
        printf ("Enter ends of branching edge (use neg if original): ");
        fflush (stdout);
        scanf ("%d %d", &bend0, &bend1);
        if (bend0 < 0) {
            if (bend1 >= 0) {
                fprintf (stderr, "both ends must be from the same order\n");
                rval = 1; goto CLEANUP;
            }
            for (i = 0; i < lp->graph.ncount; i++) {
                if (lp->perm[i] == -bend0) bend0 = i;
                if (lp->perm[i] == -bend1) bend1 = i;
            }
            printf ("Current Names of the Ends: %d %d\n", bend0, bend1);
            fflush (stdout);
        }
        b.ends[0] = bend0;
        b.ends[1] = bend1;
        b.rhs     = 1;
    } else {
        printf ("Enter the number of segments in clique: ");
        fflush (stdout);
        scanf ("%d", &nseg);
        slist = CC_SAFE_MALLOC (2*nseg, int);
        if (!slist) {
            fprintf (stderr, "out of memory\n");
            rval = 1; goto CLEANUP;
        }
        printf ("Enter the ends of the segments: ");
        fflush (stdout);
        for (i = 0; i < nseg; i++) {
            scanf ("%d %d", &slist[2*i], &slist[2*i+1]);
        }
        c = CC_SAFE_MALLOC (1, CCtsp_lpclique);
        if (!c) {
            fprintf (stderr, "out of memory\n");
            CC_IFFREE (slist, int);
            rval = 1; goto CLEANUP;
        }
        rval = CCtsp_seglist_to_lpclique (nseg, slist, c);
        if (rval) {
            fprintf (stderr, "CCtsp_seglist_to_lpclique failed\n");
            goto CLEANUP;
        }
        CC_IFFREE (slist, int);
        b.clique = c;
        b.rhs    = 4;
        b.sense  = 'G';
        CCtsp_print_lpclique (b.clique);
    }

    rval = CCtsp_splitprob (lp, &b, ch0, ch1);
    if (rval) {
        fprintf (stderr, "CCtsp_splitprob failed\n");
        goto CLEANUP;
    }

    CCtsp_free_branchobj (&b);

CLEANUP:

    return rval;
}
