/***************************************************************************/
/*                                                                         */
/*            GENERATION OF EDGES FOR THE PRICING ROUTINE                  */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: November 10, 1995                                                */
/*  Last Change: July 10, 1996 (Bico)                                      */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_init_edgegenerator (edgegenerator *eg, int ncount,         */
/*           CCdatagroup *dg, CCtsp_genadj *adj, int nneighbors)           */
/*      SETS UP the edgegenerator structure. Must be called before calls   */
/*      to the other edgegenerator functions.                              */
/*        -eg must point to an edgegenerator struct.                       */
/*        -ncount is the number of nodes.                                  */
/*        -dg will not be copied, only the pointer is recorded.            */
/*        -adj will be used as the edgelist if it is nonnull (in this case */
/*         dg can be NULL).                                                */
/*        -nneighbors is the number of neighbors that will be considered   */
/*         from each node. To consider all edges, this should be set to    */
/*         CCtsp_PRICE_COMPLETE_GRAPH.                                     */
/*    void CCtsp_free_edgegenerator (edgegenerator *eg)                    */
/*      FREES the space used by the structures in eg (but not eg itself).  */
/*    int CCtsp_reset_edgegenerator (edgegenerator *eg, double *node_piest)*/
/*      ADDS the pi values to the eg and records the starting position in  */
/*      the loop through the edges (so we can determine when we have       */
/*      circled through all edges with a single set of pi values). This    */
/*      must be called before the first call to generate_edges.            */
/*        -eg must have been set up with a call to init_edgegenerator.     */
/*        -node_piest is pi values "estimates" on the nodes.               */
/*    int CCtsp_generate_edges (CCtsp_edgegenerator *eg, int nwant,        */
/*           int *pngot, int *elist, int *elen, int *finished)             */
/*      RETURNS a list of edges that have a chance of having negative      */
/*      reduced costs in that len(i,j) - pi[i] - pi[j] is negative. If an  */
/*      entire pass has been made through the edgeset since the last call  */
/*      to reset_edgegenerator, then finished is set to 1 (otherwise 0).   */
/*        -eg must have been initialized with a call to init_edgegenerator */
/*         followed by a call to reset_edgegenerator.                      */
/*        -nwant is the maximum number of edges that should be returned.   */
/*        -pngot returns the number of edges found.                        */
/*        -elist returns the edges in node node format (this must have     */
/*         been allocated by the calling routine and should be at least    */
/*         2*nwant long.                                                   */
/*        -elen returns the lengths of the edges in elist (this must have  */
/*         been allocated by the calling routine and have nwant entries).  */
/*        -finished is set to 1 if an entire loop through the edges has    */
/*         been made since the last call to reset_edgegenerator.           */
/*    int CCtsp_edgelist_to_genadj (int ncount, int ecount, int *elist,    */
/*            int *elen, CCtsp_genadj **adj, CCtsp_genadjobj **adjobjspace)*/
/*      RETURNS the genadj struct corresponding the list of edges.         */
/*        -ncount is the number of nodes.                                  */
/*        -ecount is the number of edges.                                  */
/*        -elist is the array of edges in end1 end2 format.                */
/*        -elen is the array of edge lengths.                              */
/*        -adj is a pointer to an genadj struct address; upon return it    */
/*         will point to the filled in adj struct.                         */
/*        -adjobjspace will return a pointer to the list of genadjobj's    */
/*         used in adj (this can be used to free the objects)              */
/*                                                                         */
/*  NOTES:                                                                 */
/*       All (nonvoid) routines return 0 if successful.                    */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "macrorus.h"
#include "tsp.h"
#include "kdtree.h"
#include "edgegen.h"

#ifdef CC_PROTOTYPE_ANSI

static void
    xprice_free (CCtsp_xnorm_pricer *xp);

static int
    xprice_build (int ncount, CCdatagroup *dat, CCtsp_xnorm_pricer *xp),
    xprice_reset (CCtsp_xnorm_pricer *xp, double *pi, int currentnode),
    xprice_node (CCtsp_xnorm_pricer *xp, int n, int *count, int *nlist);

#else

static void
    xprice_free ();

static int
    xprice_build (),
    xprice_reset (),
    xprice_node ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_init_edgegenerator (CCtsp_edgegenerator *eg, int ncount,
        CCdatagroup *dg, CCtsp_genadj *adj, int nneighbors)
#else
int CCtsp_init_edgegenerator (eg, ncount, dg, adj, nneighbors)
CCtsp_edgegenerator *eg;
int ncount;
CCdatagroup *dg;
CCtsp_genadj *adj;
int nneighbors;
#endif
{
    int rval;

    printf ("CCtsp_init_edgegenerator (%d)\n", nneighbors); fflush (stdout);

    eg->node_piest = (double *) NULL;
    eg->kdtree = (CCkdtree *) NULL;
    eg->xnear = (CCxnear *) NULL;
    eg->xprice = (CCtsp_xnorm_pricer *) NULL;
    eg->supply = (int *) NULL;
    eg->adjobjspace = (CCtsp_genadjobj *) NULL;
    eg->ncount = ncount;
    eg->dg = dg;
    eg->adj = adj;

    if (nneighbors == CCtsp_PRICE_COMPLETE_GRAPH) {
        eg->nneighbors = CCtsp_PRICE_COMPLETE_GRAPH;
        eg->supplyhead = 0;
        eg->start = 0;
        eg->current = 0;
        if (((dg->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) ||
            ((dg->norm & CC_NORM_BITS) == CC_X_NORM_TYPE)) {
            eg->supply = CC_SAFE_MALLOC (ncount, int);
            if (!eg->supply) {
                fprintf (stderr, "out of memory in init_edgegenerator\n");
                return 1;
            }
            eg->xprice = CC_SAFE_MALLOC (1, CCtsp_xnorm_pricer);
            if (!eg->xprice) {
                fprintf (stderr, "out of memory in init_edgegenerator\n");
                return 1;
            }
            rval = xprice_build (ncount, dg, eg->xprice);
            if (rval) {
                fprintf (stderr, "xprice_build failed\n");
                CC_FREE (eg->xprice, CCtsp_xnorm_pricer);
                return rval;
            }
        }
    } else {
        eg->nneighbors = (nneighbors >= ncount - 1 ? ncount - 1 : nneighbors);
        eg->start = 0;
        eg->current = 0;

        if (adj) {
            eg->supplyhead = 0;
            eg->supplycount = 0;
        } else if (eg->nneighbors <= CCtsp_GEN_USE_ADJ) {
            int i, k, ecount;
            int *elist = (int *) NULL;
            CCtsp_genadjobj *padj;

            eg->supplyhead = 0;
            eg->supplycount = 0;

            if ((dg->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
                CCkdtree kt;
                rval = CCkdtree_build (&kt, ncount, dg, (double *) NULL);
                if (rval) {
                    fprintf (stderr, "CCkdtree_build failed\n");
                    return rval;
                }
                rval = CCkdtree_k_nearest (&kt, ncount, eg->nneighbors, dg,
                         (double *) NULL, 1, &ecount, &elist);
                if (rval) {
                    fprintf (stderr, "CCkdtree_k_nearest failed\n");
                    return rval;
                }
                CCkdtree_free (&kt);
            } else if ((dg->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
                rval = CCedgegen_x_k_nearest (ncount, eg->nneighbors, dg,
                         (double *) NULL, 1, &ecount, &elist);
                if (rval) {
                    fprintf (stderr, "CCedgegen_x_k_nearest failed\n");
                    return rval;
                }
            } else {
                rval = CCedgegen_junk_k_nearest (ncount, eg->nneighbors, dg,
                         (double *) NULL, 1, &ecount, &elist);
                if (rval) {
                    fprintf (stderr, "CCedgegen_junk_k_nearest failed\n");
                    return rval;
                }
            }
            eg->adj = CC_SAFE_MALLOC (ncount, CCtsp_genadj);
            if (!eg->adj) {
                fprintf (stderr, "out of memory in init_edgegenerator\n");
                CC_IFFREE (elist, int);
                return 1;
            }
            for (i = 0; i < ncount; i++)
                eg->adj[i].deg = 0;
            for (i = 0; i < ecount; i++) {
                if (elist[2*i] > elist[2*i + 1]) {
                    CC_SWAP (elist[2*i], elist[2*i + 1], k);
                }
                eg->adj[elist[2*i]].deg++;
            }

            eg->adjobjspace = CC_SAFE_MALLOC (ecount, CCtsp_genadjobj);
            if (!eg->adjobjspace) {
                fprintf (stderr, "out of memory in init_edgegenerator\n");
                CC_IFFREE (elist, int);
                CC_IFFREE (eg->adj, CCtsp_genadj);
                return 1;
            }

            padj = eg->adjobjspace;
            for (i = 0; i < ncount; i++) {
                eg->adj[i].list = padj;
                padj += eg->adj[i].deg;
                eg->adj[i].deg = 0;
            }
            for (i = 0; i < ecount; i++) {
                k = elist[2*i];
                eg->adj[k].list[eg->adj[k].deg].end = elist[2*i + 1];
                eg->adj[k].list[eg->adj[k].deg].len =
                        CCutil_dat_edgelen (k, elist[2*i + 1], dg);
                eg->adj[k].deg++;
            }
            CC_IFFREE (elist, int);
        } else {
            eg->supplycount = 0;
            eg->supplyhead = 0;
            eg->supply = CC_SAFE_MALLOC (eg->nneighbors, int);
            if (!eg->supply) {
                fprintf (stderr, "out of memory in init_edgegenerator\n");
                return 1;
            }

            if ((dg->norm & CC_NORM_BITS) == CC_KD_NORM_TYPE) {
                eg->kdtree = CC_SAFE_MALLOC (1, CCkdtree);
                if (!eg->kdtree) {
                    fprintf (stderr, "out of memory in init_edgegenerator\n");
                    CC_FREE (eg->supply, int);
                    return 1;
                }
                rval = CCkdtree_build (eg->kdtree, ncount, dg,
                                       (double *) NULL);
                if (rval) {
                    fprintf (stderr, "CCkdtree_build failed\n");
                    CC_FREE (eg->kdtree, CCkdtree);
                    CC_FREE (eg->supply, int);
                    return rval;
                }
            } else if ((dg->norm & CC_NORM_BITS) == CC_X_NORM_TYPE) {
                eg->xnear = CC_SAFE_MALLOC (1, CCxnear);
                if (!eg->xnear) {
                    fprintf (stderr, "out of memory in init_edgegenerator\n");
                    CC_FREE (eg->supply, int);
                    return 1;
                }
                rval = CCedgegen_xnear_build (ncount, dg, (double *) NULL,
                                              eg->xnear);
                if (rval) {
                    fprintf (stderr, "CCedgegen_xnear_build failed\n");
                    CC_FREE (eg->xnear, CCxnear);
                    CC_FREE (eg->supply, int);
                    return rval;
                }
            }
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_edgegenerator (CCtsp_edgegenerator *eg)
#else
void CCtsp_free_edgegenerator (eg)
CCtsp_edgegenerator *eg;
#endif
{
    printf ("free_edgegenerator\n"); fflush (stdout);

    CC_IFFREE (eg->supply, int);

    if (eg->kdtree)
        CCkdtree_free (eg->kdtree);
    if (eg->xnear)
        CCedgegen_xnear_free (eg->ncount, eg->xnear);
    if (eg->xprice) {
        xprice_free (eg->xprice);
        CC_FREE (eg->xprice, CCtsp_xnorm_pricer);
    }
    if (eg->adjobjspace) {
        CC_FREE (eg->adjobjspace, CCtsp_genadjobj);
        CC_IFFREE (eg->adj, CCtsp_genadj);
    }

    eg->dg = (CCdatagroup *) NULL;
    eg->node_piest = (double *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_reset_edgegenerator (CCtsp_edgegenerator *eg, double *node_piest)
#else
int CCtsp_reset_edgegenerator (eg, node_piest)
CCtsp_edgegenerator *eg;
double *node_piest;
#endif
{
    printf ("reset_edgegenerator\n"); fflush (stdout);

    eg->node_piest = node_piest;
    if (eg->nneighbors == CCtsp_PRICE_COMPLETE_GRAPH) {
        eg->start = eg->current;
        eg->supplyhead = -1;
        if (eg->xprice) {
            if (xprice_reset (eg->xprice, node_piest, eg->current)) {
                fprintf (stderr, "xprice_reset failed\n");
                return 1;
            }
            eg->supplycount = 0;
        }
    } else {
        eg->start = eg->current;
        eg->supplycount = 0;
        eg->supplyhead = -1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_generate_edges (CCtsp_edgegenerator *eg, int nwant, int *pngot,
        int *elist, int *elen, int *finished)
#else
int CCtsp_generate_edges (eg, nwant, pngot, elist, elen, finished)
CCtsp_edgegenerator *eg;
int nwant;
int *pngot;
int *elist;
int *elen;
int *finished;
#endif
{
    int len, end;
    int ngot = 0;
    int rval;

    printf ("generate_edges (%d)\n", nwant); fflush (stdout);

    *finished = 0;
    *pngot = 0;
    if (!eg->node_piest) {
        fprintf (stderr, "generate, but no node_piest\n");
        return 1;
    }

    if (eg->nneighbors == CCtsp_PRICE_COMPLETE_GRAPH) {
        if (eg->xprice) {
            int *supply = eg->supply;
            int supplyhead = eg->supplyhead;
            int supplycount = eg->supplycount;
            int current = eg->current;
            int realcurrent;

            while (ngot < nwant) {
                if (supplyhead == supplycount || supplyhead == -1) {
                    if (supplyhead != -1) {
                        current++;
                        if (current >= eg->ncount)
                            current = 0;
                        if (current == eg->start) {
                            *pngot = ngot;
                            *finished = 1;
                            eg->supplyhead = supplyhead;
                            eg->supplycount = supplycount;
                            eg->current = current;
                            return 0;
                        }
                        if (current == 0) {
                            rval = xprice_reset (eg->xprice, eg->node_piest, 0);
                            if (rval) {
                                fprintf (stderr, "xprice_reset failed\n");
                                return rval;
                            }
                        }
                    }
                    rval = xprice_node (eg->xprice, current, &supplycount,
                                                                  supply);
                    if (rval) {
                        fprintf (stderr, "xprice_node failed\n");
                        return rval;
                    }
                    supplyhead = 0;
                }
                realcurrent = eg->xprice->order[current];
                while (supplyhead < supplycount && ngot < nwant) {
                    len = CCutil_dat_edgelen (realcurrent, supply[supplyhead],
                                              eg->dg);
                    if (((double) len) - eg->node_piest[realcurrent]
                                       - eg->node_piest[supply[supplyhead]] <
                                                  CCtsp_GEN_PRICE_EPSILON) {
                        elist[ngot*2] = realcurrent;
                        elist[ngot*2+1] = supply[supplyhead];
                        elen[ngot] = len;
                        ngot++;
                        if (ngot % 100000 == 0) {
                            printf ("Y[%d]", current);
                            fflush (stdout);
                        }
                    }
                    supplyhead++;
                }
            }
            eg->supplyhead = supplyhead;
            eg->supplycount = supplycount;
            eg->current = current;
        } else {
            int supplyhead = eg->supplyhead;
            int current = eg->current;
            int ncount = eg->ncount;

            while (ngot < nwant) {
                if (supplyhead == ncount || supplyhead == -1) {
                    if (supplyhead != -1) {
                        current++;
                        if (current >= ncount)
                            current = 0;
                        if (current == eg->start) {
                            *pngot = ngot;
                            *finished = 1;
                            eg->supplyhead = supplyhead;
                            eg->current = current;
                            return 0;
                        }
                    }
                    supplyhead = current + 1;
                }
                if (supplyhead < ncount) {
                    if (current == 0 && supplyhead == 15) {
                        printf ("EVALUATE (0,15): \n"); fflush (stdout);
                        len = CCutil_dat_edgelen (current, supplyhead, eg->dg);
                        printf ("  Length: %d\n", len);
                        printf ("  Estimate: %f\n",
                            len - eg->node_piest[current]
                                - eg->node_piest[supplyhead]);
                        if (len - eg->node_piest[current] -
                              eg->node_piest[supplyhead] <
                              CCtsp_GEN_PRICE_EPSILON) {
                            printf ("  TAKE IT\n");
                        } else {
                            printf ("  LEAVE IT\n");
                        }
                        fflush (stdout);
                    }
                    len = CCutil_dat_edgelen (current, supplyhead, eg->dg);
                    if (len - eg->node_piest[current] -
                          eg->node_piest[supplyhead] <
                          CCtsp_GEN_PRICE_EPSILON) {
                        elist[ngot*2] = current;
                        elist[ngot*2+1] = supplyhead;
                        elen[ngot] = len;
                        if (current == 0 && supplyhead == 15) {
                            printf ("    GRAB 0 15: %d\n", ngot);
                            fflush (stdout);
                        }
                        ngot++;
                    }
                    supplyhead++;
                }
            }
            eg->supplyhead = supplyhead;
            eg->current = current;
        }
    } else if (eg->adj) {
        int supplyhead = eg->supplyhead;
        int supplycount = eg->supplycount;
        int current = eg->current;
        CCtsp_genadj *currentadj;

        while (ngot < nwant) {
            if (supplyhead == supplycount || supplyhead == -1) {
                if (supplyhead != -1) {
                    current++;
                    if (current >= eg->ncount)
                        current = 0;
                    if (current == eg->start) {
                        *pngot = ngot;
                        *finished = 1;
                        eg->supplyhead = supplyhead;
                        eg->supplycount = supplycount;
                        eg->current = current;
                        return 0;
                    }
                }
                supplyhead = 0;
                supplycount = eg->adj[current].deg;
            }
            currentadj = &(eg->adj[current]);
            while (supplyhead < supplycount && ngot < nwant) {
                end = currentadj->list[supplyhead].end;
                len = currentadj->list[supplyhead].len;
                if (((double) len) - eg->node_piest[current] -
                        eg->node_piest[end] < CCtsp_GEN_PRICE_EPSILON) {
                    elist[ngot*2] = current;
                    elist[ngot*2+1] = end;
                    elen[ngot] = len;
                    ngot++;
                }
                supplyhead++;
            }
        }
        eg->supplyhead = supplyhead;
        eg->supplycount = supplycount;
        eg->current = current;
    } else {
        int *supply = eg->supply;
        int supplyhead = eg->supplyhead;
        int supplycount = eg->supplycount;
        int current = eg->current;

        while (ngot < nwant) {
            if (supplyhead == supplycount || supplyhead == -1) {
                if (supplyhead != -1) {
                    current++;
                    if (current >= eg->ncount)
                        current = 0;
                    if (current == eg->start) {
                        *pngot = ngot;
                        *finished = 1;
                        eg->supplyhead = supplyhead;
                        eg->supplycount = supplycount;
                        eg->current = current;
                        return 0;
                    }
                }
                if (eg->kdtree) {
                    rval = CCkdtree_node_k_nearest (eg->kdtree, eg->ncount,
                            current, eg->nneighbors, eg->dg, (double *) NULL,
                            supply);
                    if (rval) {
                        fprintf (stderr, "CCkdtree_node_k_nearest failed\n");
                        return rval;
                    }
                } else if (eg->xnear) {
                    rval = CCedgegen_x_node_k_nearest (eg->xnear, current,
                            eg->nneighbors, eg->ncount, supply);
                    if (rval) {
                        fprintf (stderr, "CCedgegen_x_node_k_nearest failed\n");
                        return 1;
                    }
                } else {
                    rval = CCedgegen_junk_node_k_nearest (eg->dg,
                               (double *) NULL, current, eg->nneighbors,
                               eg->ncount, supply);
                    if (rval) {
                        fprintf (stderr, "junk_node_k_nearest failed\n");
                        return 1;
                    }
                }
                supplyhead = 0;
                supplycount = eg->nneighbors;
            }

            if (supply[supplyhead] > current) {
                len = CCutil_dat_edgelen (current, supply[supplyhead], eg->dg);
                if (((double) len) - eg->node_piest[current] -
                   eg->node_piest[supply[supplyhead]] <
                                               CCtsp_GEN_PRICE_EPSILON) {
                    elist[ngot*2] = current;
                    elist[ngot*2+1] = supply[supplyhead];
                    elen[ngot] = len;
                    ngot++;
                }
            }
            supplyhead++;
        }
        eg->supplyhead = supplyhead;
        eg->supplycount = supplycount;
        eg->current = current;
    }

    *pngot = ngot;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int xprice_build (int ncount, CCdatagroup *dat, CCtsp_xnorm_pricer *xp)
#else
static int xprice_build (ncount, dat, xp)
int ncount;
CCdatagroup *dat;
CCtsp_xnorm_pricer *xp;
#endif
{
    int i;

    printf ("xprice_build\n");
    fflush (stdout);

    xp->pi = (double *) NULL;
    xp->order = (int *) NULL;
    xp->xminuspi = (CCtsp_xnorm_pricer_val *) NULL;
    xp->xminuspi_space = (CCtsp_xnorm_pricer_val *) NULL;
    xp->invxminuspi = (int *) NULL;

    if (((dat->norm) & CC_NORM_BITS) != CC_KD_NORM_TYPE &&
        ((dat->norm) & CC_NORM_BITS) != CC_X_NORM_TYPE) {
        fprintf (stderr, "cannot run xprice_build with norm %d\n", dat->norm);
        xprice_free (xp);
        return 1;
    }

    xp->ncount = ncount;
    xp->dat = dat;

    xp->pi = CC_SAFE_MALLOC (ncount, double);
    if (!xp->pi) {
        fprintf (stderr, "out of memory in xprice_build\n");
        xprice_free (xp);
        return 1;
    }

    xp->order = CC_SAFE_MALLOC (ncount, int);
    if (!xp->order) {
        fprintf (stderr, "out of memory in xprice_build\n");
        xprice_free (xp);
        return 1;
    }
    for (i = 0; i < ncount; i++)
        xp->order[i] = i;
    CCutil_double_perm_quicksort (xp->order, dat->x, ncount);

    xp->xminuspi_space = CC_SAFE_MALLOC (ncount + 1, CCtsp_xnorm_pricer_val);
    if (!xp->xminuspi_space) {
        fprintf (stderr, "out of memory in xprice_build\n");
        xprice_free (xp);
        return 1;
    }

    xp->invxminuspi = CC_SAFE_MALLOC (ncount, int);
    if (!xp->invxminuspi) {
        fprintf (stderr, "out of memory in xprice_build\n");
        xprice_free (xp);
        return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int xprice_reset (CCtsp_xnorm_pricer *xp, double *pi, int currentnode)
#else
static int xprice_reset (xp, pi, currentnode)
CCtsp_xnorm_pricer *xp;
double *pi;
int currentnode;
#endif
{
    int i;
    double *xpi = (double *) NULL;
    int *xpiperm = (int *) NULL;
    int count = xp->ncount - currentnode;
    int rval = 0;

    printf ("xprice_reset (%d)\n", currentnode);
    fflush (stdout);

    for (i = 0; i < xp->ncount; i++)
        xp->pi[i] = pi[i];

    xpi = CC_SAFE_MALLOC (count, double);
    xpiperm = CC_SAFE_MALLOC (count, int);
    if (!xpi || !xpiperm) {
        fprintf (stderr, "out of memory in xprice_build\n");
        rval = 1;
        goto CLEANUP;
    }

    if (xp->dat->norm == CC_GEOGRAPHIC) {
        for (i = 0; i < count; i++) {
            xpi[i] =
             (CC_GEOGRAPHIC_SCALE * xp->dat->x[xp->order[i + currentnode]]) -
                                         pi[xp->order[i + currentnode]];
            xpiperm[i] = i;
        }
    } else if (xp->dat->norm == CC_ATT) {
        for (i = 0; i < count; i++) {
            xpi[i] =
             (CC_ATT_SCALE * xp->dat->x[xp->order[i + currentnode]]) -
                                  pi[xp->order[i + currentnode]];
            xpiperm[i] = i;
        }
    } else {
        for (i = 0; i < count; i++) {
            xpi[i] = xp->dat->x[xp->order[i + currentnode]] -
                             pi[xp->order[i + currentnode]];
            xpiperm[i] = i;
        }
    }

    CCutil_double_perm_quicksort (xpiperm, xpi, count);
    for (i = 0; i < count; i++)
        xp->invxminuspi[xp->order[xpiperm[i] + currentnode]] = i;

    for (i = 1; i < count - 1; i++) {
        xp->xminuspi_space[i].val = xpi[xpiperm[i]];
        xp->xminuspi_space[i].index = xp->order[xpiperm[i] + currentnode];
        xp->xminuspi_space[i].next = &(xp->xminuspi_space[i + 1]);
        xp->xminuspi_space[i].prev = &(xp->xminuspi_space[i - 1]);
    }
    xp->xminuspi_space[0].val = xpi[xpiperm[0]];
    xp->xminuspi_space[0].index = xp->order[xpiperm[0] + currentnode];
    xp->xminuspi_space[0].next = &(xp->xminuspi_space[1]);
    xp->xminuspi_space[0].prev = (CCtsp_xnorm_pricer_val *) NULL;
    xp->xminuspi_space[count - 1].val = xpi[xpiperm[count - 1]];
    xp->xminuspi_space[count - 1].index =
     xp->order[xpiperm[count - 1] + currentnode];
    xp->xminuspi_space[count - 1].next = &(xp->xminuspi_space[count]);
    xp->xminuspi_space[count - 1].prev = &(xp->xminuspi_space[count - 2]);
    xp->xminuspi_space[count].val = 1e30;  /* This anchors the linked list */
    xp->xminuspi_space[count].next = (CCtsp_xnorm_pricer_val *) NULL;
    xp->xminuspi_space[count].prev = &(xp->xminuspi_space[count - 1]);
    xp->xminuspi = xp->xminuspi_space;

CLEANUP:

    CC_IFFREE (xpi, double);
    CC_IFFREE (xpiperm, int);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
static int xprice_node (CCtsp_xnorm_pricer *xp, int n, int *count, int *nlist)
#else
static int xprice_node (xp, n, count, nlist)
CCtsp_xnorm_pricer *xp;
int n;
int *count;
int *nlist;
#endif
{
    int k;
    double kval;
    CCtsp_xnorm_pricer_val *xnp;
    double scale;

    if (xp->dat->norm == CC_GEOGRAPHIC)
        scale = CC_GEOGRAPHIC_SCALE;
    else if (xp->dat->norm == CC_ATT)
        scale = CC_ATT_SCALE;
    else
        scale = 1.0;

    *count = 0;

    k = xp->order[n];
    kval = xp->pi[k] + (scale * xp->dat->x[k]);

    xnp = xp->xminuspi_space + xp->invxminuspi[k];  /* Delete node k */
    if (xnp == xp->xminuspi)
        xp->xminuspi = xnp->next;
    else
        xnp->prev->next = xnp->next;
    xnp->next->prev = xnp->prev;

    for (xnp = xp->xminuspi; xnp->val < kval; xnp = xnp->next)
        nlist[(*count)++] = xnp->index;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void xprice_free (CCtsp_xnorm_pricer *xp)
#else
static void xprice_free (xp)
CCtsp_xnorm_pricer *xp;
#endif
{
    if (xp->order)
        CC_FREE (xp->order, int);
    if (xp->pi)
        CC_FREE (xp->pi, double);
    if (xp->xminuspi_space)
        CC_FREE (xp->xminuspi_space, CCtsp_xnorm_pricer_val);
    if (xp->invxminuspi)
        CC_FREE (xp->invxminuspi, int);
    xp->ncount = 0;
    xp->dat = (CCdatagroup *) NULL;
    xp->xminuspi = (CCtsp_xnorm_pricer_val *) NULL;
}


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_edgelist_to_genadj (int ncount, int ecount, int *elist, int *elen,
        CCtsp_genadj **adj, CCtsp_genadjobj **adjobjspace)
#else
int CCtsp_edgelist_to_genadj (ncount, ecount, elist, elen, adj, adjobjspace)
int ncount;
int ecount;
int *elist;
int *elen;
CCtsp_genadj **adj;
CCtsp_genadjobj **adjobjspace;
#endif
{
    int i, k, k1, k2;
    CCtsp_genadj *a;
    CCtsp_genadjobj *p;

    *adj = CC_SAFE_MALLOC (ncount, CCtsp_genadj);
    if (!(*adj)) {
        fprintf (stderr, "out of memory in edgelist_to_genadj\n");
        return 1;
    }
    a = *adj;

    for (i = 0; i < ncount; i++)
        a[i].deg = 0;
    for (i = 0; i < ecount; i++) {
        if (elist[2*i] > elist[2*i + 1])
            a[elist[2*i + 1]].deg++;
        else
            a[elist[2*i]].deg++;
    }

    *adjobjspace = CC_SAFE_MALLOC (ecount, CCtsp_genadjobj);
    if (!(*adjobjspace)) {
        fprintf (stderr, "out of memory in edgelist_to_genadj\n");
        CC_IFFREE (*adj, CCtsp_genadj);
        return 1;
    }

    p = *adjobjspace;
    for (i = 0; i < ncount; i++) {
        a[i].list = p;
        p += a[i].deg;
        a[i].deg = 0;
    }
    for (i = 0; i < ecount; i++) {
        k1 = elist[2*i];
        k2 = elist[2*i + 1];
        if (k1 > k2) {
            CC_SWAP (k1, k2, k);
        }
        a[k1].list[a[k1].deg].end = k2;
        a[k1].list[a[k1].deg].len = elen[i];
        a[k1].deg++;
    }

    return 0;
}
