/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*       init_hash_values ();                                             */
/*                                                                        */
/*    unsigned long                                                       */
/*       cut_hash_value (),                                               */
/*       comb_hash_value (),                                              */
/*       clique_hash_value ();                                            */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"


/*
   This code needs two fields added to a node.  They are unsigned long rand1
   and unsigned long rand2.
*/

static unsigned long hashfunc1[256];
static unsigned long hashfunc2[256];
static unsigned long hashfunc3[256];
static unsigned long hashfunc4[256];

#define TOOTHHASHFUNC(x) (hashfunc1[(x)&0xff] ^ hashfunc2[((x)>>8)&0xff] ^ \
                      hashfunc3[((x)>>16)&0xff] ^ hashfunc4[((x)>>24)&0xff])

#ifdef CC_PROTOTYPE_ANSI
void Xinit_hash_values (Xgraph *G)
#else
void Xinit_hash_values (G)
Xgraph *G;
#endif
{
    int i;

    for (i = 0; i < G->nnodes; i++) {
        G->nodelist[i].rand1 = (int) CCutil_lprand ();
        G->nodelist[i].rand2 = (int) CCutil_lprand ();
    }
    for (i = 0; i < 256; i++) {
        hashfunc1[i] = CCutil_lprand ();
        hashfunc2[i] = CCutil_lprand ();
        hashfunc3[i] = CCutil_lprand ();
        hashfunc4[i] = CCutil_lprand ();
    }
}


#ifdef CC_PROTOTYPE_ANSI
unsigned long Xcut_hash_value (Xnodeptr *h)
#else
unsigned long Xcut_hash_value (h)
Xnodeptr *h;
#endif
{
    Xnodeptr *p;
    unsigned long hashval = 0;

    for (p = h; p; p = p->next)
        hashval ^= p->this->rand1;

    return hashval;
}

#ifdef CC_PROTOTYPE_ANSI
unsigned long Xcomb_hash_value (Xnodeptr *h, Xnodeptrptr *t)
#else
unsigned long Xcomb_hash_value (h, t)
Xnodeptr *h;
Xnodeptrptr *t;
#endif
{
    Xnodeptr *p;
    Xnodeptrptr *q;
    unsigned long hashval = 0;
    unsigned long toothhash;

    for (p = h; p; p = p->next)
        hashval ^= p->this->rand1;
    for (q = t; q; q = q->next) {
        toothhash = 0;
        for (p = q->this; p; p = p->next)
            toothhash ^= p->this->rand2;
        hashval ^= TOOTHHASHFUNC (toothhash);
    }
    return hashval;
}

#ifdef CC_PROTOTYPE_ANSI
unsigned long Xclique_hash_value (Xnodeptrptr *h, Xnodeptrptr *t)
#else
unsigned long Xclique_hash_value (h, t)
Xnodeptrptr *h;
Xnodeptrptr *t;
#endif
{
    Xnodeptr *p;
    Xnodeptrptr *q;
    unsigned long hashval = 0;
    unsigned long toothhash;
    unsigned long handlehash;

    for (q = h; q; q = q->next) {
        handlehash = 0;
        for (p = q->this; p; p = p->next)
            handlehash ^= p->this->rand1;
        hashval ^= TOOTHHASHFUNC (handlehash);
    }
    for (q = t; q; q = q->next) {
        toothhash = 0;
        for (p = q->this; p; p = p->next)
            toothhash ^= p->this->rand2;
        hashval ^= TOOTHHASHFUNC (toothhash);
    }
    return hashval;
}
