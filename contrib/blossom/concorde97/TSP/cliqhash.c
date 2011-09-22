/***************************************************************************/
/*                                                                         */
/*                  ROUTINES TO HASH CLIQUES                               */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: October 10, 1995                                                 */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCtsp_init_cliquehash (CCtsp_lpcuts *cuts, int size)             */
/*       initializes the clique hash storage in cuts.                      */
/*       int size is an estimate of the number of cliques                  */
/*                                                                         */
/*    int CCtsp_register_clique (CCtsp_lpcuts *cuts, CCtsp_lpclique *c)    */
/*       returns an integer index for c, adding c to cuts if necessary     */
/*       -1 ==> failure                                                    */
/*                                                                         */
/*    void CCtsp_free_cliquehash (CCtsp_lpcuts *cuts)                      */
/*       frees the clique hashtable space                                  */
/*                                                                         */
/*    void CCtsp_unregister_clique (CCtsp_lpcuts *cuts, int c)             */
/*       deletes a reference to clique c, and deletes the clique if no     */
/*       references remain                                                 */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"

#ifdef CC_PROTOTYPE_ANSI

static unsigned int
    hashclique (CCtsp_lpclique *c);

static int
    clique_eq (CCtsp_lpclique *c, CCtsp_lpclique *d);

#else

static unsigned int
    hashclique ();

static int
    clique_eq ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_init_cliquehash (CCtsp_lpcuts *cuts, int size)
#else
int CCtsp_init_cliquehash (cuts, size)
CCtsp_lpcuts *cuts;
int size;
#endif
{
    int i;

    cuts->cliquehashsize = (int) CCutil_nextprime ((unsigned int) size);
    cuts->cliquehash = CC_SAFE_MALLOC (cuts->cliquehashsize, int);
    if (!cuts->cliquehash) {
        cuts->cliquehashsize = 0;
        return 1;
    }
    for (i=0; i<cuts->cliquehashsize; i++) {
        cuts->cliquehash[i] = -1;
    }
    cuts->cliquefree = -1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_free_cliquehash (CCtsp_lpcuts *cuts)
#else
void CCtsp_free_cliquehash (cuts)
CCtsp_lpcuts *cuts;
#endif
{
    CC_IFFREE (cuts->cliquehash, int);
    cuts->cliquehashsize = 0;
}

#ifdef CC_PROTOTYPE_ANSI
static unsigned int hashclique (CCtsp_lpclique *c)
#else
static unsigned int hashclique (c)
CCtsp_lpclique *c;
#endif
{
    unsigned int x = 0;
    int i;

    for (i=0; i<c->segcount; i++) {
        x = x * 65537 + c->nodes[i].lo * 4099 + c->nodes[i].hi;
    }
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static int clique_eq (CCtsp_lpclique *c, CCtsp_lpclique *d)
#else
static int clique_eq (c, d)
CCtsp_lpclique *c;
CCtsp_lpclique *d;
#endif
{
    int i;

    if (c->segcount != d->segcount) return 0;
    for (i=0; i<c->segcount; i++) {
        if (c->nodes[i].lo != d->nodes[i].lo) return 0;
        if (c->nodes[i].hi != d->nodes[i].hi) return 0;
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_register_clique (CCtsp_lpcuts *cuts, CCtsp_lpclique *c)
#else
int CCtsp_register_clique (cuts, c)
CCtsp_lpcuts *cuts;
CCtsp_lpclique *c;
#endif
{
    int x = hashclique (c) % cuts->cliquehashsize;
    int y = cuts->cliquehash[x];
    CCtsp_segment *new = (CCtsp_segment *) NULL;
    int i;

    while (y != -1) {
        if (clique_eq (c, &cuts->cliques[y])) {
            cuts->cliques[y].refcount++;
            return y;
        }
        y = cuts->cliques[y].hashnext;
    }

    new = CC_SAFE_MALLOC (c->segcount, CCtsp_segment);
    if (!new) {
        fprintf (stderr, "out of memory in register_clique\n");
        return -1;
    }

    if (cuts->cliquefree != -1) {
        y = cuts->cliquefree;
        cuts->cliquefree = cuts->cliques[y].hashnext;
    } else {
        if (cuts->cliqueend >= cuts->cliquespace) {
            if (CCutil_reallocrus_scale ((void **) &cuts->cliques,
                          &cuts->cliquespace,
                          cuts->cliqueend + 1, 1.3, sizeof (CCtsp_lpclique))) {
                CC_FREE (new, CCtsp_segment);
                return -1;
            }
        }
        y = cuts->cliqueend++;
    }
    cuts->cliques[y].segcount = c->segcount;
    for (i=0; i<c->segcount; i++) {
        new[i] = c->nodes[i];
    }
    cuts->cliques[y].nodes = new;
    cuts->cliques[y].refcount = 1;
    cuts->cliques[y].hashnext = cuts->cliquehash[x];
    cuts->cliquehash[x] = y;

    return y;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_unregister_clique (CCtsp_lpcuts *cuts, int c)
#else
void CCtsp_unregister_clique (cuts, c)
CCtsp_lpcuts *cuts;
int c;
#endif
{
    int x, y, yprev;

    cuts->cliques[c].refcount--;
    if (cuts->cliques[c].refcount) return;
    x = hashclique (&cuts->cliques[c]) % cuts->cliquehashsize;
    y = cuts->cliquehash[x];
    if (y == c) {
        cuts->cliquehash[x] = cuts->cliques[c].hashnext;
    } else {
        yprev = y;
        y = cuts->cliques[y].hashnext;
        while (y != c && y != -1) {
            yprev = y;
            y = cuts->cliques[y].hashnext;
        }
        if (y == -1) {
            fprintf (stderr, "Couldn't find clique to delete from hash\n");
            return;
        }
        cuts->cliques[yprev].hashnext = cuts->cliques[c].hashnext;
    }
    CC_FREE (cuts->cliques[c].nodes, CCtsp_segment);
    cuts->cliques[c].segcount = -1;
    cuts->cliques[c].hashnext = cuts->cliquefree;
    cuts->cliquefree = c;
}
