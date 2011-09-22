/**************************************************************************/
/*                                                                        */
/*    OLD SUBTOUR STUFF - all functions and types now start with X        */
/*                      - this stuff is only for testing concorde         */
/*                                                                        */
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  blockptr *blockptralloc ()                                            */
/*  clique *cliquealloc ()                                                */
/*  combhash *combhashalloc ()                                            */
/*  cplane *cplanealloc ()                                                */
/*  cutnodeptr *cutnodeptralloc ()                                        */
/*  cuttree_node *cuttree_nodealloc ()                                    */
/*  edge *edgealloc ()                                                    */
/*  edgeptr *edgeptralloc ()                                              */
/*  intptr *intptralloc ()                                                */
/*  intptrptr *intptrptralloc ()                                          */
/*  void add_intptrptr ()                                                 */
/*  iplane *iplanealloc ()                                                */
/*  node *nodealloc ()                                                    */
/*  nodeptr *nodeptralloc ()                                              */
/*  nodeptrptr *nodeptrptralloc ()                                        */
/*  void add_edgeptr ()                                                   */
/*  void add_extralink ()                                                 */
/*  void add_nodeptr ()                                                   */
/*  void add_nodeptrptr ()                                                */
/*  void blinkfree ()                                                     */
/*  void blockptrfree ()                                                  */
/*  void clinkfree ()                                                     */
/*  void cliquefree ()                                                    */
/*  void combhashfree ()                                                  */
/*  void cplane_list_free ()                                              */
/*  void cplanefree ()                                                    */
/*  void cutnodeptrfree ()                                                */
/*  void cuttree_nodefree ()                                              */
/*  void edgefree ()                                                      */
/*  void edge_list_free ()                                                */
/*  void edgeptr_list_free ()                                             */
/*  void edgeptrfree ()                                                   */
/*  void initialize_ouralloc ()                                           */
/*  void intptr_list_free ()                                              */
/*  void intptrfree ()                                                    */
/*  void intptrptr_list_free ()                                           */
/*  void intptrptr_list_freeall()                                         */
/*  void intptrptrfree ()                                                 */
/*  void iplane_list_free ()                                              */
/*  void iplanefree ()                                                    */
/*  void nodefree ()                                                      */
/*  void nodeptr_list_free ()                                             */
/*  void nodeptrfree ()                                                   */
/*  void nodeptrptr_list_free ()                                          */
/*  void nodeptrptrfree ()                                                */
/*  void union_nodeptr ()                                                 */
/*  void ouralloc_reset ()                                                */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"
#include "Xnecklac.h"

#ifdef CC_PROTOTYPE_ANSI

static Xextralink *Xextralinkalloc (void);
static union size_104 *size_104_alloc (void);
static union size_16 *size_16_alloc (void);
static union size_24 *size_24_alloc (void);
static union size_48 *size_48_alloc (void);
static union size_8 *size_8_alloc (void);
static union size_80 *size_80_alloc (void);
static void Xextralinkfree (Xextralink *);
static void fetch_size_104 (int);
static void fetch_size_16 (int);
static void fetch_size_24 (int);
static void fetch_size_48 (int);
static void fetch_size_8 (int);
static void fetch_size_80 (int);
static void size_104_free (union size_104 *);
static void size_16_free (union size_16 *);
static void size_24_free (union size_24 *);
static void size_48_free (union size_48 *);
static void size_80_free (union size_80 *);
static void size_8_free (union size_8 *);
static void initialize_ouralloc (void);

#else

static Xextralink *Xextralinkalloc ();
static union size_104 *size_104_alloc ();
static union size_16 *size_16_alloc ();
static union size_24 *size_24_alloc ();
static union size_48 *size_48_alloc ();
static union size_8 *size_8_alloc ();
static union size_80 *size_80_alloc ();
static void Xextralinkfree ();
static void fetch_size_104 ();
static void fetch_size_16 ();
static void fetch_size_24 ();
static void fetch_size_48 ();
static void fetch_size_8 ();
static void fetch_size_80 ();
static void size_104_free ();
static void size_16_free ();
static void size_24_free ();
static void size_48_free ();
static void size_80_free ();
static void size_8_free ();
static void initialize_ouralloc ();

#endif

/* fooALLOCCHUNK * sizeof foo + 16 should be <= a power of 2 */

#define CHUNKBASE ((1<<13)-16)

#define INIT_8_ALLOC    (CHUNKBASE / sizeof (union size_8))
#define SIZE_8_CHUNK    (CHUNKBASE / sizeof (union size_8))

#define INIT_16_ALLOC   (CHUNKBASE / sizeof (union size_16))
#define SIZE_16_CHUNK   (CHUNKBASE / sizeof (union size_16))

#define INIT_24_ALLOC   (50)
#define SIZE_24_CHUNK   (CHUNKBASE / sizeof (union size_24))

#define INIT_48_ALLOC   (CHUNKBASE / sizeof (union size_48))
#define SIZE_48_CHUNK   (CHUNKBASE / sizeof (union size_48))

#define INIT_80_ALLOC   (CHUNKBASE / sizeof (union size_80))
#define SIZE_80_CHUNK   (CHUNKBASE / sizeof (union size_80))

#define INIT_104_ALLOC  (CHUNKBASE / sizeof (union size_104))
#define SIZE_104_CHUNK  (CHUNKBASE / sizeof (union size_104))

static int init_ouralloc = 1;

union size_8 {
    Xnodeptr obj_nodeptr;
    Xnodeptrptr obj_nodeptrptr;
    Xedgeptr obj_edgeptr;
    Xneckedgeptr obj_neckedgeptr;
    Xclink obj_clink;
    Xintptr obj_intptr;
    Xintptrptr obj_intptrptr;
    Xcutnodeptr obj_cutnodeptr;
    Xcombhash obj_combhash;
    union size_8 *next;
} *size_8_freelist = (union size_8 *) NULL;

#ifdef CC_PROTOTYPE_ANSI
static void fetch_size_8 (int n)
#else
static void fetch_size_8 (n)
int n;
#endif
{
    union size_8 *x;

    x = CC_SAFE_MALLOC (n, union size_8);
    if (!x) {
        fprintf (stderr, "Out of memory in old fetch\n");
        exit (1);
    }
    x[n - 1].next = size_8_freelist;
    size_8_freelist = x;
    for (n -= 2; n >= 0; n--, x++) {
        x->next = x + 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static union size_8 *size_8_alloc (void)
#else
static union size_8 *size_8_alloc ()
#endif
{
    union size_8 *x;

    if (init_ouralloc) {
        initialize_ouralloc ();
    }
    if (!size_8_freelist) {
        fetch_size_8 (SIZE_8_CHUNK);
    }
    x = size_8_freelist;
    size_8_freelist = x->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void size_8_free (union size_8 *x)
#else
static void size_8_free (x)
union size_8 *x;
#endif
{
    x->next = size_8_freelist;
    size_8_freelist = x;
}

#ifdef CC_PROTOTYPE_ANSI
Xnodeptr *Xnodeptralloc (void)
#else
Xnodeptr *Xnodeptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_nodeptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xnodeptrfree (Xnodeptr *n)
#else
void Xnodeptrfree (n)
Xnodeptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xnodeptr_list_free (Xnodeptr *np)
#else
void Xnodeptr_list_free (np)
Xnodeptr *np;
#endif
{
    Xnodeptr *next;

    while (np) {
        next = np->next;
        Xnodeptrfree (np);
        np = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xadd_nodeptr (Xnodeptr **list, Xnode *n)
#else
void Xadd_nodeptr (list, n)
Xnodeptr **list;
Xnode *n;
#endif
{
    Xnodeptr *temp;

    temp = Xnodeptralloc ();
    temp->this = n;
    temp->next = *list;
    *list = temp;
}

#ifdef CC_PROTOTYPE_ANSI
void Xunion_nodeptr (Xgraph *G, Xnodeptr *a, Xnodeptr *b, Xnodeptr **u)
#else
void Xunion_nodeptr (G, a, b, u)
Xgraph *G;
Xnodeptr *a, *b, **u;
#endif
{
    Xnode *n;
    Xnodeptr *np;

    *u = (Xnodeptr *) NULL;
    G->magicnum++;
    for (np = a; np; np = np->next) {
        n = np->this;
        if (n->magiclabel != G->magicnum) {
            Xadd_nodeptr (u, n);
            n->magiclabel = G->magicnum;
        }
    }
    for (np = b; np; np = np->next) {
        n = np->this;
        if (n->magiclabel != G->magicnum) {
            Xadd_nodeptr (u, n);
            n->magiclabel = G->magicnum;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
Xnodeptrptr *Xnodeptrptralloc (void)
#else
Xnodeptrptr *Xnodeptrptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_nodeptrptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xnodeptrptrfree (Xnodeptrptr *n)
#else
void Xnodeptrptrfree (n)
Xnodeptrptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xnodeptrptr_list_free (Xnodeptrptr *np)
#else
void Xnodeptrptr_list_free (np)
Xnodeptrptr *np;
#endif
{
    Xnodeptrptr *next;

    while (np) {
        next = np->next;
        Xnodeptrptrfree (np);
        np = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xadd_nodeptrptr (Xnodeptrptr **list, Xnodeptr *n)
#else
void Xadd_nodeptrptr (list, n)
Xnodeptrptr **list;
Xnodeptr *n;
#endif
{
    Xnodeptrptr *temp;

    temp = Xnodeptrptralloc ();
    temp->this = n;
    temp->next = *list;
    *list = temp;
}

#ifdef CC_PROTOTYPE_ANSI
Xedgeptr *Xedgeptralloc (void)
#else
Xedgeptr *Xedgeptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_edgeptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xedgeptrfree (Xedgeptr *n)
#else
void Xedgeptrfree (n)
Xedgeptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xedgeptr_list_free (Xedgeptr *ep)
#else
void Xedgeptr_list_free (ep)
Xedgeptr *ep;
#endif
{
    Xedgeptr *next;

    while (ep) {
        next = ep->next;
        Xedgeptrfree (ep);
        ep = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xadd_edgeptr (Xedgeptr **list, Xedge *e)
#else
void Xadd_edgeptr (list, e)
Xedgeptr **list;
Xedge *e;
#endif
{
    Xedgeptr *temp;

    temp = Xedgeptralloc ();
    temp->this = e;
    temp->next = *list;
    *list = temp;
}

#ifdef CC_PROTOTYPE_ANSI
Xneckedgeptr *Xneckedgeptralloc (void)
#else
Xneckedgeptr *Xneckedgeptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_neckedgeptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xneckedgeptrfree (Xneckedgeptr *n)
#else
void Xneckedgeptrfree (n)
Xneckedgeptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xneckedgeptr_list_free (Xneckedgeptr *ep)
#else
void Xneckedgeptr_list_free (ep)
Xneckedgeptr *ep;
#endif
{
    Xneckedgeptr *next;

    while (ep) {
        next = ep->next;
        Xneckedgeptrfree (ep);
        ep = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xadd_neckedgeptr (Xneckedgeptr **list, Xneckedge *e)
#else
void Xadd_neckedgeptr (list, e)
Xneckedgeptr **list;
Xneckedge *e;
#endif
{
    Xneckedgeptr *temp;

    temp = Xneckedgeptralloc ();
    temp->this = e;
    temp->next = *list;
    *list = temp;
}

#ifdef CC_PROTOTYPE_ANSI
Xclink *Xclinkalloc (void)
#else
Xclink *Xclinkalloc ()
#endif
{
    return &(size_8_alloc ()->obj_clink);
}

#ifdef CC_PROTOTYPE_ANSI
void Xclinkfree (Xclink *n)
#else
void Xclinkfree (n)
Xclink *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
Xintptr *Xintptralloc (void)
#else
Xintptr *Xintptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_intptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xintptrfree (Xintptr *n)
#else
void Xintptrfree (n)
Xintptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xintptr_list_free (Xintptr *ip)
#else
void Xintptr_list_free (ip)
Xintptr *ip;
#endif
{
    Xintptr *next;

    while (ip) {
        next = ip->next;
        Xintptrfree (ip);
        ip = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
Xintptrptr *Xintptrptralloc (void)
#else
Xintptrptr *Xintptrptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_intptrptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xintptrptrfree (Xintptrptr *n)
#else
void Xintptrptrfree (n)
Xintptrptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xintptrptr_list_free (Xintptrptr *ip)
#else
void Xintptrptr_list_free (ip)
Xintptrptr *ip;
#endif
{
    Xintptrptr *next;

    while (ip) {
        next = ip->next;
        Xintptrptrfree (ip);
        ip = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xintptrptr_list_freeall(Xintptrptr *ip)
#else
void Xintptrptr_list_freeall(ip)
Xintptrptr *ip;
#endif
{
    Xintptrptr *next;

    while (ip) {
        next = ip->next;
        Xintptr_list_free (ip->this);
        Xintptrptrfree (ip);
        ip = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xadd_intptrptr (Xintptrptr **list, Xintptr *n)
#else
void Xadd_intptrptr (list, n)
Xintptrptr **list;
Xintptr *n;
#endif
{
    Xintptrptr *temp;

    temp = Xintptrptralloc ();
    temp->this = n;
    temp->next = *list;
    *list = temp;
}

#ifdef CC_PROTOTYPE_ANSI
Xcutnodeptr *Xcutnodeptralloc (void)
#else
Xcutnodeptr *Xcutnodeptralloc ()
#endif
{
    return &(size_8_alloc ()->obj_cutnodeptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcutnodeptrfree (Xcutnodeptr *n)
#else
void Xcutnodeptrfree (n)
Xcutnodeptr *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
Xcombhash *Xcombhashalloc (void)
#else
Xcombhash *Xcombhashalloc ()
#endif
{
    return &(size_8_alloc ()->obj_combhash);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcombhashfree (Xcombhash *n)
#else
void Xcombhashfree (n)
Xcombhash *n;
#endif
{
    size_8_free ((union size_8 *) n);
}

union size_16 {
    Xblink obj_blink;
    Xextralink obj_extralink;
    Xblockptr obj_blockptr;
    union size_16 *next;
} *size_16_freelist = (union size_16 *) NULL;

#ifdef CC_PROTOTYPE_ANSI
static void fetch_size_16 (int n)
#else
static void fetch_size_16 (n)
int n;
#endif
{
    union size_16 *x;

    x = CC_SAFE_MALLOC (n, union size_16);
    if (!x) {
        fprintf (stderr, "Out of memory in old fetch\n");
        exit (1);
    }
    x[n - 1].next = size_16_freelist;
    size_16_freelist = x;
    for (n -= 2; n >= 0; n--, x++) {
        x->next = x + 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static union size_16 *size_16_alloc (void)
#else
static union size_16 *size_16_alloc ()
#endif
{
    union size_16 *x;

    if (init_ouralloc) {
        initialize_ouralloc ();
    }
    if (!size_16_freelist) {
        fetch_size_16 (SIZE_16_CHUNK);
    }
    x = size_16_freelist;
    size_16_freelist = x->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void size_16_free (union size_16 *x)
#else
static void size_16_free (x)
union size_16 *x;
#endif
{
    x->next = size_16_freelist;
    size_16_freelist = x;
}

#ifdef CC_PROTOTYPE_ANSI
static Xextralink *Xextralinkalloc (void)
#else
static Xextralink *Xextralinkalloc ()
#endif
{
    return &(size_16_alloc ()->obj_extralink);
}

#ifdef CC_PROTOTYPE_ANSI
static void Xextralinkfree (Xextralink *n)
#else
static void Xextralinkfree (n)
Xextralink *n;
#endif
{
    size_16_free ((union size_16 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xextralink_list_free (Xextralink *ep)
#else
void Xextralink_list_free (ep)
Xextralink *ep;
#endif
{
    Xextralink *next;

    while (ep) {
        next = ep->next;
        Xextralinkfree (ep);
        ep = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xadd_extralink (Xextralink **list, int end0, int end1, int weight)
#else
void Xadd_extralink (list, end0, end1, weight)
Xextralink **list;
int end0, end1, weight;
#endif
{
    Xextralink *temp;

    temp = Xextralinkalloc ();
    temp->ends[0] = end0;
    temp->ends[1] = end1;
    temp->weight = weight;
    temp->next = *list;
    *list = temp;
}

#ifdef CC_PROTOTYPE_ANSI
Xblink *Xblinkalloc (void)
#else
Xblink *Xblinkalloc ()
#endif
{
    return &(size_16_alloc ()->obj_blink);
}

#ifdef CC_PROTOTYPE_ANSI
void Xblinkfree (Xblink *n)
#else
void Xblinkfree (n)
Xblink *n;
#endif
{
    size_16_free ((union size_16 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
Xblockptr *Xblockptralloc (void)
#else
Xblockptr *Xblockptralloc ()
#endif
{
    return &(size_16_alloc ()->obj_blockptr);
}

#ifdef CC_PROTOTYPE_ANSI
void Xblockptrfree (Xblockptr *n)
#else
void Xblockptrfree (n)
Xblockptr *n;
#endif
{
    size_16_free ((union size_16 *) n);
}

union size_24 {
    Xcplane obj_cplane;          /* size really 20 */
    Xiplane obj_iplane;
    Xclique obj_clique;
    Xeqn obj_eqn;
    union size_24 *next;
} *size_24_freelist = (union size_24 *) NULL;

#ifdef CC_PROTOTYPE_ANSI
static void fetch_size_24 (int n)
#else
static void fetch_size_24 (n)
int n;
#endif
{
    union size_24 *x;

    x = CC_SAFE_MALLOC (n, union size_24);
    if (!x) {
        fprintf (stderr, "Out of memory in old fetch\n");
        exit (1);
    }
    x[n - 1].next = size_24_freelist;
    size_24_freelist = x;
    for (n -= 2; n >= 0; n--, x++) {
        x->next = x + 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static union size_24 *size_24_alloc (void)
#else
static union size_24 *size_24_alloc ()
#endif
{
    union size_24 *x;

    if (init_ouralloc) {
        initialize_ouralloc ();
    }
    if (!size_24_freelist) {
        fetch_size_24 (SIZE_24_CHUNK);
    }
    x = size_24_freelist;
    size_24_freelist = x->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void size_24_free (union size_24 *x)
#else
static void size_24_free (x)
union size_24 *x;
#endif
{
    x->next = size_24_freelist;
    size_24_freelist = x;
}

#ifdef CC_PROTOTYPE_ANSI
Xcplane *Xcplanealloc (void)
#else
Xcplane *Xcplanealloc ()
#endif
{
    return &(size_24_alloc ()->obj_cplane);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcplanefree (Xcplane *n)
#else
void Xcplanefree (n)
Xcplane *n;
#endif
{
    size_24_free ((union size_24 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcplane_list_free (Xcplane *ip)
#else
void Xcplane_list_free (ip)
Xcplane *ip;
#endif
{
    Xcplane *next;

    while (ip) {
        next = ip->next;
        Xcplanefree (ip);
        ip = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
Xiplane *Xiplanealloc (void)
#else
Xiplane *Xiplanealloc ()
#endif
{
    return &(size_24_alloc ()->obj_iplane);
}

#ifdef CC_PROTOTYPE_ANSI
void Xiplanefree (Xiplane *n)
#else
void Xiplanefree (n)
Xiplane *n;
#endif
{
    size_24_free ((union size_24 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xiplane_list_free (Xiplane *ip)
#else
void Xiplane_list_free (ip)
Xiplane *ip;
#endif
{
    Xiplane *next;

    while (ip) {
        next = ip->next;
        Xiplanefree (ip);
        ip = next;
    }
}

#ifdef CC_PROTOTYPE_ANSI
Xclique *Xcliquealloc (void)
#else
Xclique *Xcliquealloc ()
#endif
{
    return &(size_24_alloc ()->obj_clique);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcliquefree (Xclique *n)
#else
void Xcliquefree (n)
Xclique *n;
#endif
{
    size_24_free ((union size_24 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
Xeqn *Xeqnalloc (void)
#else
Xeqn *Xeqnalloc ()
#endif
{
    return &(size_24_alloc ()->obj_eqn);
}

#ifdef CC_PROTOTYPE_ANSI
void Xeqnfree (Xeqn *n)
#else
void Xeqnfree (n)
Xeqn *n;
#endif
{
    size_24_free ((union size_24 *) n);
}

union size_48 {
    Xcuttree_node obj_cuttree_node;
    union size_48 *next;
} *size_48_freelist = (union size_48 *) NULL;

#ifdef CC_PROTOTYPE_ANSI
static void fetch_size_48 (int n)
#else
static void fetch_size_48 (n)
int n;
#endif
{
    union size_48 *x = (union size_48 *) NULL;

    x = CC_SAFE_MALLOC (n, union size_48);
    if (!x) {
        fprintf (stderr, "Out of memory in old fetch\n");
        exit (1);
    }
    x[n - 1].next = size_48_freelist;
    size_48_freelist = x;
    for (n -= 2; n >= 0; n--, x++) {
        x->next = x + 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static union size_48 *size_48_alloc (void)
#else
static union size_48 *size_48_alloc ()
#endif
{
    union size_48 *x;

    if (init_ouralloc) {
        initialize_ouralloc ();
    }
    if (!size_48_freelist) {
        fetch_size_48 (SIZE_48_CHUNK);
    }
    x = size_48_freelist;
    size_48_freelist = x->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void size_48_free (union size_48 *x)
#else
static void size_48_free (x)
union size_48 *x;
#endif
{
    x->next = size_48_freelist;
    size_48_freelist = x;
}

#ifdef CC_PROTOTYPE_ANSI
Xcuttree_node *Xcuttree_nodealloc (void)
#else
Xcuttree_node *Xcuttree_nodealloc ()
#endif
{
    return &(size_48_alloc ()->obj_cuttree_node);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcuttree_nodefree (Xcuttree_node *n)
#else
void Xcuttree_nodefree (n)
Xcuttree_node *n;
#endif
{
    size_48_free ((union size_48 *) n);
}

union size_80 {
    Xedge obj_edge;
    union size_80 *next;
} *size_80_freelist = (union size_80 *) NULL;

#ifdef CC_PROTOTYPE_ANSI
static void fetch_size_80 (int n)
#else
static void fetch_size_80 (n)
int n;
#endif
{
    union size_80 *x;

    x = CC_SAFE_MALLOC (n, union size_80);
    if (!x) {
        fprintf (stderr, "Out of memory in old fetch\n");
        exit (1);
    }
    x[n - 1].next = size_80_freelist;
    size_80_freelist = x;
    for (n -= 2; n >= 0; n--, x++) {
        x->next = x + 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static union size_80 *size_80_alloc (void)
#else
static union size_80 *size_80_alloc ()
#endif
{
    union size_80 *x;

    if (init_ouralloc) {
        initialize_ouralloc ();
    }
    if (!size_80_freelist) {
        fetch_size_80 (SIZE_80_CHUNK);
    }
    x = size_80_freelist;
    size_80_freelist = x->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void size_80_free (union size_80 *x)
#else
static void size_80_free (x)
union size_80 *x;
#endif
{
    x->next = size_80_freelist;
    size_80_freelist = x;
}

#ifdef CC_PROTOTYPE_ANSI
Xedge *Xedgealloc (void)
#else
Xedge *Xedgealloc ()
#endif
{
    return &(size_80_alloc ()->obj_edge);
}

#ifdef CC_PROTOTYPE_ANSI
void Xedgefree (Xedge *n)
#else
void Xedgefree (n)
Xedge *n;
#endif
{
    size_80_free ((union size_80 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
void Xedge_list_free (Xedge *e)
#else
void Xedge_list_free (e)
Xedge *e;
#endif
{
    Xedge *next;

    while (e) {
        next = e->next;
        Xedgefree (e);
        e = next;
    }
}

union size_104 {
    Xnode obj_node;
    union size_104 *next;
} *size_104_freelist = (union size_104 *) NULL;

#ifdef CC_PROTOTYPE_ANSI
static void fetch_size_104 (int n)
#else
static void fetch_size_104 (n)
int n;
#endif
{
    union size_104 *x;

    x = CC_SAFE_MALLOC (n, union size_104);
    if (!x) {
        fprintf (stderr, "Out of memory in old fetch\n");
        exit (1);
    }
    x[n - 1].next = size_104_freelist;
    size_104_freelist = x;
    for (n -= 2; n >= 0; n--, x++) {
        x->next = x + 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static union size_104 *size_104_alloc (void)
#else
static union size_104 *size_104_alloc ()
#endif
{
    union size_104 *x;

    if (init_ouralloc) {
        initialize_ouralloc ();
    }
    if (!size_104_freelist) {
        fetch_size_104 (SIZE_104_CHUNK);
    }
    x = size_104_freelist;
    size_104_freelist = x->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void size_104_free (union size_104 *x)
#else
static void size_104_free (x)
union size_104 *x;
#endif
{
    x->next = size_104_freelist;
    size_104_freelist = x;
}

#ifdef CC_PROTOTYPE_ANSI
Xnode *Xnodealloc (void)
#else
Xnode *Xnodealloc ()
#endif
{
    return &(size_104_alloc ()->obj_node);
}

#ifdef CC_PROTOTYPE_ANSI
void Xnodefree (Xnode *n)
#else
void Xnodefree (n)
Xnode *n;
#endif
{
    size_104_free ((union size_104 *) n);
}

#ifdef CC_PROTOTYPE_ANSI
static void initialize_ouralloc (void)
#else
static void initialize_ouralloc ()
#endif
{
    if (init_ouralloc) {
        if (sizeof (union size_8) != 8) {
            fprintf (stderr, "Warning, sizeof (union size_8) == %d\n",
                     (int) sizeof (union size_8));
        }
        if (sizeof (union size_16) != 16) {
            fprintf (stderr, "Warning, sizeof (union size_16) == %d\n",
                     (int) sizeof (union size_16));
        }
        if (sizeof (union size_24) != 24) {
            fprintf (stderr, "Warning, sizeof (union size_24) == %d\n",
                     (int) sizeof (union size_24));
        }
        if (sizeof (union size_48) != 48) {
            fprintf (stderr, "Warning, sizeof (union size_48) == %d\n",
                     (int) sizeof (union size_48));
        }
        if (sizeof (union size_80) != 80) {
            fprintf (stderr, "Warning, sizeof (union size_80) == %d\n",
                     (int) sizeof (union size_80));
        }
        if (sizeof (union size_104) != 104) {
            fprintf (stderr, "Warning, sizeof (union size_104) == %d\n",
                     (int) sizeof (union size_104));
        }
        if (INIT_8_ALLOC) {
            fetch_size_8 (INIT_8_ALLOC);
        }
        if (INIT_16_ALLOC) {
            fetch_size_16 (INIT_16_ALLOC);
        }
        if (INIT_24_ALLOC) {
            fetch_size_24 (INIT_24_ALLOC);
        }
        if (INIT_48_ALLOC) {
            fetch_size_48 (INIT_48_ALLOC);
        }
        if (INIT_80_ALLOC) {
            fetch_size_80 (INIT_80_ALLOC);
        }
        if (INIT_104_ALLOC) {
            fetch_size_104 (INIT_104_ALLOC);
        }
        init_ouralloc = 0;
    }
}
